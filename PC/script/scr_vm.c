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
static struct scrVmGlob_t scrVmGlob; /* scrVmGlob */

void Scr_ClearErrorMessage(void);
void Scr_Settings(int developer, int developer_script, int abort_on_error);
void Scr_Shutdown(void);
void Scr_Abort(void);
void Scr_SetLoading(int bLoading);
unsigned int Scr_GetNumScriptThreads(void);
void Scr_ResetTimeout(void);
static void VM_CancelNotifyInternal(unsigned int notifyListOwnerId, unsigned int notifyListId, unsigned int notifyNameListId, unsigned int stringValue);
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
VariableValue GetEntityFieldValue(unsigned int classnum, int entnum, int offset);
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
    byte *p = *(byte **)imp_scrVarPub;
    *(int *)(p + 0x10) = 0;
    *(int *)0x4ead90 = 0;
    *(int *)(p + 0x14) = 0;
}

/* line 182 */
void Scr_Settings(int developer, int developer_script, int abort_on_error)
{
    byte *p = *(byte **)imp_scrVarPub;
    *(byte *)(p + 0xa) = developer != 0;
    *(byte *)(p + 0xb) = developer_script != 0;
    *(byte *)0x1008215 = abort_on_error != 0;
}

/* line 192 */
__attribute__((naked))
void Scr_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 192 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_scrVarPub, %ebx\n" /* line 194 */
        "cmpb $0, 0x38(%ebx)\n"
        "je .Lf81662_000816ad\n"
        "movb $0, 0x38(%ebx)\n" /* line 196 */
        "movl 0x34(%ebx), %eax\n" /* line 153 */
        "testl %eax, %eax\n"
        "jne .Lf81662_0008168f\n"
        "calll Var_Shutdown\n" /* line 199 */
        "addl $0x14, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SL_Shutdown\n" /* line 200 */
        ".Lf81662_0008168f:\n"
        "movl %eax, (%esp)\n" /* line 155 */
        "calll FreeValue\n"
        "movl $0, 0x34(%ebx)\n" /* line 156 */
        "calll Var_Shutdown\n" /* line 199 */
        "addl $0x14, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SL_Shutdown\n" /* line 200 */
        ".Lf81662_000816ad:\n"
        "addl $0x14, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 204 */
void Scr_Abort(void)
{
    byte *p = *(byte **)imp_scrVarPub;
    *(int *)(p + 0x1c) = 0;
    *(byte *)(p + 0x38) = 0;
}

/* line 211 */
void Scr_SetLoading(int bLoading)
{
    *(int *)0x4ead94 = bLoading;
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
    __asm__ __volatile__ ("rdtsc" : "=a" (tsc_low) : : "edx");
    *(unsigned int *)0x4ead98 = tsc_low >> 2;
}

/* line 2620 */
static __attribute__((naked))
void VM_CancelNotifyInternal(unsigned int notifyListOwnerId, unsigned int notifyListId, unsigned int notifyNameListId, unsigned int stringValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2620 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edx, %ebx\n" /* startLocalId */
        "movl %ecx, -0x20(%ebp)\n"
        "movl 8(%ebp), %esi\n" /* notifyNameListId */
        "movl 0xc(%ebp), %edi\n" /* stringValue */
        "movl %edx, (%esp)\n" /* line 2626 */
        "calll Scr_RemoveThreadNotifyName\n"
        "movl %ebx, 4(%esp)\n" /* line 2629 | startLocalId */
        "movl %esi, (%esp)\n" /* notifyNameListId */
        "calll RemoveObjectVariable\n"
        "movl %esi, (%esp)\n" /* line 2631 | notifyNameListId */
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "je .Lf816f8_00081737\n"
        ".Lf816f8_0008172f:\n"
        "addl $0x2c, %esp\n" /* line 2637 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf816f8_00081737:\n"
        "movl %edi, 4(%esp)\n" /* line 2633 | stringValue */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "movl -0x20(%ebp), %eax\n" /* line 2634 */
        "movl %eax, (%esp)\n"
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "jne .Lf816f8_0008172f\n"
        "movl $0x1fffe, 0xc(%ebp)\n" /* line 2635 | stringValue */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%ebp)\n" /* notifyNameListId */
        "addl $0x2c, %esp\n" /* line 2637 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp RemoveVariable\n" /* line 2635 */
    );
}

/* line 2640 */
__attribute__((naked))
void VM_CancelNotify(unsigned int notifyListOwnerId, unsigned int startLocalId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2640 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* notifyListOwnerId */
        "movl %eax, -0x1c(%ebp)\n" /* notifyListOwnerId */
        "movl 0xc(%ebp), %esi\n" /* startLocalId */
        /* { scope 1 */
        "movl $0x1fffe, 4(%esp)\n" /* line 2646 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, %ebx\n" /* notifyListId */
        "movl %esi, (%esp)\n" /* line 2647 | startLocalId */
        "calll Scr_GetThreadNotifyName\n"
        "movzwl %ax, %edi\n" /* stringValue */
        "movl %edi, 4(%esp)\n" /* line 2649 | stringValue */
        "movl %ebx, (%esp)\n" /* notifyListId */
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %edi, 0xc(%ebp)\n" /* line 2650 | stringValue, startLocalId */
        "movl %eax, 8(%ebp)\n" /* notifyListOwnerId */
        "movl %ebx, %ecx\n" /* notifyListId */
        "movl %esi, %edx\n" /* startLocalId */
        "movl -0x1c(%ebp), %eax\n" /* notifyListOwnerId */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp VM_CancelNotifyInternal\n" /* line 2650 */
    );
}

/* line 2654 */
static __attribute__((naked))
VariableStackBuffer * VM_ArchiveStack(int size, VariableValue *top, unsigned int localVarCount, unsigned int *pLocalId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2654 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl %edx, %edi\n" /* pos */
        "movl %ecx, -0x2c(%ebp)\n"
        /* { scope 1 */
        "leal (%eax, %eax, 4), %esi\n" /* line 2662 */
        "leal 0xb(%esi), %ebx\n" /* bufLen */
        "movl $1, 4(%esp)\n" /* line 2664 */
        "movl %ebx, (%esp)\n" /* bufLen */
        "calll MT_Alloc\n"
        "movl %eax, -0x24(%ebp)\n" /* stackValue */
        "movl 0xc(%ebp), %eax\n" /* line 2669 | pLocalId */
        "movl (%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* localId */
        "movl -0x24(%ebp), %edx\n" /* line 2670 | stackValue */
        "movw %ax, 8(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 2671 */
        "movw %ax, 4(%edx)\n"
        "movw %bx, 6(%edx)\n" /* line 2672 | bufLen */
        "movl %edi, (%edx)\n" /* line 2673 | pos */
        "movl imp_scrVarPub, %eax\n" /* line 2674 */
        "movl 0x18(%eax), %eax\n"
        "movb %al, 0xa(%edx)\n"
        "movl 8(%ebp), %eax\n" /* line 2675 | localVarCount */
        "shll $2, %eax\n"
        "subl %eax, scrVmPub\n"
        "leal 0xb(%edx, %esi), %eax\n" /* line 2678 */
        "movl -0x28(%ebp), %ebx\n" /* line 2681 | bufLen */
        "testl %ebx, %ebx\n" /* bufLen */
        "je .Lf817d2_000818c9\n"
        "movl %eax, %esi\n"
        "leal -4(%eax), %edi\n" /* pos */
        "movl $0, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %ebx\n" /* bufLen */
        "jmp .Lf817d2_0008186f\n"
        ".Lf817d2_0008184f:\n"
        "movl (%ebx), %eax\n" /* line 2694 | bufLen */
        "movl %eax, -4(%esi)\n"
        "movl 4(%ebx), %eax\n" /* line 2699 | bufLen */
        "movb %al, -5(%esi)\n"
        "subl $8, %ebx\n" /* line 2701 | bufLen */
        "addl $1, -0x1c(%ebp)\n"
        "subl $5, %esi\n"
        "subl $5, %edi\n" /* pos */
        "movl -0x28(%ebp), %eax\n" /* line 2681 */
        "cmpl %eax, -0x1c(%ebp)\n"
        "je .Lf817d2_000818c9\n"
        ".Lf817d2_0008186f:\n"
        "cmpl $7, 4(%ebx)\n" /* line 2684 | bufLen */
        "jne .Lf817d2_0008184f\n"
        "subl $1, scrVmPub+8\n" /* line 2686 */
        "movl scrVmPub+12, %edx\n" /* line 2687 */
        "leal -0x18(%edx), %eax\n"
        "movl %eax, scrVmPub+12\n"
        "movl -0x18(%edx), %eax\n" /* line 2688 */
        "movl %eax, (%edi)\n" /* pos */
        "movl scrVmPub+12, %eax\n" /* line 2689 */
        "movl 8(%eax), %eax\n"
        "shll $2, %eax\n"
        "subl %eax, scrVmPub\n"
        "movl -0x20(%ebp), %edx\n" /* line 2690 | localId */
        "movl %edx, (%esp)\n"
        "calll GetParentLocalId\n"
        "movl %eax, -0x20(%ebp)\n" /* localId */
        "movl 4(%ebx), %eax\n" /* line 2699 | bufLen */
        "movb %al, -5(%esi)\n"
        "subl $8, %ebx\n" /* line 2701 | bufLen */
        "addl $1, -0x1c(%ebp)\n"
        "subl $5, %esi\n"
        "subl $5, %edi\n" /* pos */
        "movl -0x28(%ebp), %eax\n" /* line 2681 */
        "cmpl %eax, -0x1c(%ebp)\n"
        "jne .Lf817d2_0008186f\n"
        ".Lf817d2_000818c9:\n"
        "subl $1, scrVmPub+8\n" /* line 2705 */
        "subl $0x18, scrVmPub+12\n" /* line 2706 */
        "movl -0x20(%ebp), %edx\n" /* line 2708 | localId */
        "movl %edx, (%esp)\n"
        "calll AddRefToObject\n"
        "movl -0x20(%ebp), %edx\n" /* line 2709 | localId */
        "movl 0xc(%ebp), %eax\n" /* pLocalId */
        "movl %edx, (%eax)\n"
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 2712 | stackValue */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2815 */
static __attribute__((naked))
void VM_TerminateStack(unsigned int endLocalId, unsigned int startLocalId, VariableStackBuffer *stackValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2815 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl %ecx, -0x44(%ebp)\n"
        /* { scope 1 */
        "movzwl 4(%ecx), %edx\n" /* line 2828 */
        "movzwl %dx, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movzwl 8(%ecx), %esi\n" /* line 2829 | localId */
        "leal (%eax, %eax, 4), %eax\n" /* line 2832 */
        "movl -0x44(%ebp), %ecx\n"
        "leal 0xb(%ecx, %eax), %ebx\n" /* buf */
        "testw %dx, %dx\n" /* line 2834 */
        "je .Lf818f6_00081991\n"
        "movl -0x2c(%ebp), %edi\n" /* size */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf818f6_0008194f\n"
        ".Lf818f6_00081931:\n"
        "movl -0x38(%ebp), %edx\n" /* line 2843 | u */
        "movl %edx, 4(%esp)\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "addl $1, -0x30(%ebp)\n" /* line 2875 */
        "movl -0x30(%ebp), %eax\n" /* line 2834 */
        "cmpl %eax, -0x2c(%ebp)\n"
        "je .Lf818f6_00081991\n"
        ".Lf818f6_0008194f:\n"
        "movl -4(%ebx), %eax\n" /* line 2837 | buf */
        "movl %eax, -0x38(%ebp)\n" /* u */
        "subl $5, %ebx\n" /* line 2838 | buf */
        "movzbl (%ebx), %eax\n" /* line 2839 | buf */
        "subl $1, %edi\n" /* line 2840 | size */
        "cmpb $7, %al\n" /* line 2841 */
        "jne .Lf818f6_00081931\n"
        "movl %esi, (%esp)\n" /* line 2847 | localId */
        "calll GetParentLocalId\n"
        "movl %eax, -0x34(%ebp)\n" /* parentLocalId */
        "movl %esi, (%esp)\n" /* line 2848 | localId */
        "calll Scr_KillThread\n"
        "movl %esi, (%esp)\n" /* line 2849 | localId */
        "calll RemoveRefToObject\n"
        "cmpl %esi, -0x3c(%ebp)\n" /* line 2851 | localId */
        "je .Lf818f6_000819bc\n"
        "movl -0x34(%ebp), %esi\n" /* line 2875 | parentLocalId, localId */
        "addl $1, -0x30(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 2834 */
        "cmpl %eax, -0x2c(%ebp)\n"
        "jne .Lf818f6_0008194f\n"
        ".Lf818f6_00081991:\n"
        "movl %esi, (%esp)\n" /* line 2881 | localId */
        "calll Scr_KillThread\n"
        "movl %esi, (%esp)\n" /* line 2882 | localId */
        "calll RemoveRefToObject\n"
        "movl -0x44(%ebp), %edx\n" /* line 2887 */
        "movzwl 6(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        /* } scope */
        ".Lf818f6_000819b4:\n"
        "addl $0x4c, %esp\n" /* line 2888 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf818f6_000819bc:\n"
        "movb $0, (%ebx)\n" /* line 2861 | buf */
        "movl imp_scrVarPub, %ecx\n" /* line 2864 */
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetThreadWaitTime\n"
        "movl -0x38(%ebp), %ecx\n" /* line 2866 | u */
        "movl -0x44(%ebp), %edx\n"
        "movl %ecx, (%edx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 2867 | parentLocalId */
        "movw %ax, 8(%edx)\n"
        "leal 1(%edi), %eax\n" /* line 2868 | size */
        "movw %ax, 4(%edx)\n"
        "movl $0xa, -0x1c(%ebp)\n" /* line 2870 */
        "movl %edx, -0x20(%ebp)\n" /* line 2871 | tempValue */
        "movl imp_scrVarPub, %edx\n" /* line 2873 */
        "movl 0x18(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll GetNewObjectVariable\n"
        "leal -0x20(%ebp), %edx\n" /* line 2874 | tempValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        "jmp .Lf818f6_000819b4\n"
    );
}

/* line 2949 */
static __attribute__((naked))
void VM_TrimStack(unsigned int startLocalId, VariableStackBuffer *stackValue, Bool fromEndon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2949 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movb %cl, -0x3d(%ebp)\n"
        /* { scope 1 */
        "movl %edx, %eax\n" /* line 2961 */
        "movzwl 4(%edx), %edx\n"
        "movzwl %dx, %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movzwl 8(%eax), %edi\n" /* line 2962 | localId */
        "leal (%ecx, %ecx, 4), %eax\n" /* line 2965 */
        "movl -0x3c(%ebp), %ecx\n"
        "leal 0xb(%ecx, %eax), %esi\n" /* buf */
        "testw %dx, %dx\n" /* line 2967 */
        "je .Lf81a3a_00081ae6\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* size */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf81a3a_00081a95\n"
        ".Lf81a3a_00081a7a:\n"
        "movl %edx, 4(%esp)\n" /* line 2976 */
        "movzbl %al, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "addl $1, -0x30(%ebp)\n" /* line 3008 */
        "movl -0x30(%ebp), %ecx\n" /* line 2967 */
        "cmpl %ecx, -0x2c(%ebp)\n"
        "je .Lf81a3a_00081ae6\n"
        ".Lf81a3a_00081a95:\n"
        "movl -4(%esi), %edx\n" /* line 2970 | buf */
        "subl $5, %esi\n" /* line 2971 | buf */
        "movzbl (%esi), %eax\n" /* line 2972 | buf */
        "subl $1, -0x34(%ebp)\n" /* line 2973 | size */
        "cmpb $7, %al\n" /* line 2974 */
        "jne .Lf81a3a_00081a7a\n"
        "movl %edi, 4(%esp)\n" /* line 2981 | localId */
        "movl imp_scrVarPub, %eax\n"
        "movl 0x20(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindObjectVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf81a3a_00081b32\n"
        "movl %edi, (%esp)\n" /* line 3006 | localId */
        "calll GetParentLocalId\n"
        "movl %eax, %ebx\n" /* parentLocalId */
        "movl %edi, (%esp)\n" /* line 3007 | localId */
        "calll Scr_KillThread\n"
        "movl %edi, (%esp)\n" /* line 3008 | localId */
        "calll RemoveRefToObject\n"
        "movl %ebx, %edi\n" /* parentLocalId, localId */
        "addl $1, -0x30(%ebp)\n"
        "movl -0x30(%ebp), %ecx\n" /* line 2967 */
        "cmpl %ecx, -0x2c(%ebp)\n"
        "jne .Lf81a3a_00081a95\n"
        ".Lf81a3a_00081ae6:\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 3014 */
        "jne .Lf81a3a_00081b1d\n"
        ".Lf81a3a_00081aec:\n"
        "movl -0x38(%ebp), %edx\n" /* line 3017 */
        "movl %edx, (%esp)\n"
        "calll Scr_KillThread\n"
        "movl -0x38(%ebp), %ecx\n" /* line 3018 */
        "movl %ecx, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl -0x3c(%ebp), %edx\n" /* line 3023 */
        "movzwl 6(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        /* } scope */
        ".Lf81a3a_00081b15:\n"
        "addl $0x4c, %esp\n" /* line 3024 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf81a3a_00081b1d:\n"
        "movl $0x1ffff, 4(%esp)\n" /* line 3015 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "jmp .Lf81a3a_00081aec\n"
        ".Lf81a3a_00081b32:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 2988 */
        "movw %di, 8(%edx)\n" /* localId */
        "movl -0x34(%ebp), %eax\n" /* line 2989 | size */
        "addl $1, %eax\n"
        "movw %ax, 4(%edx)\n"
        "movl %edi, (%esp)\n" /* line 2991 | localId */
        "calll Scr_StopThread\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 2993 */
        "jne .Lf81a3a_00081b15\n"
        "movl $0, 4(%esp)\n" /* line 2996 */
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Scr_SetThreadNotifyName\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2997 */
        "movl $0, (%eax)\n"
        "movl $0xa, -0x1c(%ebp)\n" /* line 2999 */
        "movl %eax, -0x20(%ebp)\n" /* line 3000 | tempValue */
        "movl $0x1ffff, 4(%esp)\n" /* line 3002 */
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll GetNewVariable\n"
        "leal -0x20(%ebp), %edx\n" /* tempValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        "jmp .Lf81a3a_00081b15\n"
    );
}

/* line 3139 */
static __attribute__((naked))
void Scr_CancelWaittill(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3139 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %esi\n" /* startLocalId */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 3145 */
        "calll Scr_GetSelf\n"
        "movl %eax, %edi\n" /* selfId */
        "movl %eax, 4(%esp)\n" /* line 3146 */
        "movl imp_scrVarPub, %edx\n"
        "movl 0x20(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindObjectVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, %ebx\n" /* selfNameId */
        "movl %esi, 4(%esp)\n" /* line 3147 | startLocalId */
        "movl %eax, (%esp)\n"
        "calll FindObjectVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetVariableValueAddress\n"
        "movl %esi, 4(%esp)\n" /* line 3148 | startLocalId */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll VM_CancelNotify\n"
        "movl %esi, 4(%esp)\n" /* line 3149 | startLocalId */
        "movl %ebx, (%esp)\n" /* selfNameId */
        "calll RemoveObjectVariable\n"
        "movl %ebx, (%esp)\n" /* line 3150 | selfNameId */
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "jne .Lf81b9e_00081c21\n"
        "movl %edi, 4(%esp)\n" /* line 3151 | selfId */
        "movl imp_scrVarPub, %edx\n"
        "movl 0x20(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveObjectVariable\n"
        /* } scope */
        ".Lf81b9e_00081c21:\n"
        "addl $0x1c, %esp\n" /* line 3152 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3598 */
__attribute__((naked))
void Scr_CancelNotifyList(unsigned int notifyListOwnerId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3598 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* notifyListOwnerId */
        /* { scope 1 */
        ".Lf81c2c_00081c38:\n"
        "movl $0x1fffe, 4(%esp)\n" /* line 3610 */
        "movl %edi, (%esp)\n" /* notifyListOwnerId */
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 3611 */
        "je .Lf81c2c_00081cf2\n"
        ".Lf81c2c_00081c50:\n"
        "movl %eax, (%esp)\n" /* line 3614 */
        "calll FindObject\n"
        "movl %eax, (%esp)\n" /* line 3617 */
        "calll FindNextSibling\n"
        "testl %eax, %eax\n" /* line 3618 */
        "je .Lf81c2c_00081cf2\n"
        "movl %eax, (%esp)\n" /* line 3621 */
        "calll FindObject\n"
        "movl %eax, (%esp)\n" /* line 3624 */
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n" /* selfStartLocalId */
        "testl %eax, %eax\n" /* line 3625 */
        "je .Lf81c2c_00081cf2\n"
        "movl %eax, (%esp)\n" /* line 3628 */
        "calll GetVariableKeyObject\n"
        "movl %eax, %esi\n" /* startLocalId */
        "movl %ebx, (%esp)\n" /* line 3631 | selfStartLocalId */
        "calll GetVarType\n"
        "cmpl $0xa, %eax\n"
        "je .Lf81c2c_00081cfa\n"
        "movl %esi, (%esp)\n" /* line 3639 | startLocalId */
        "calll AddRefToObject\n"
        "movl %esi, %eax\n" /* line 3641 | startLocalId */
        "calll Scr_CancelWaittill\n"
        "movl %esi, (%esp)\n" /* line 3643 | startLocalId */
        "calll Scr_GetSelf\n"
        "movl %eax, (%esp)\n" /* line 3644 */
        "calll GetStartLocalId\n"
        "movl %eax, %ebx\n" /* selfStartLocalId */
        "movl $0x1ffff, 4(%esp)\n" /* line 3645 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 3646 */
        "jne .Lf81c2c_00081d1b\n"
        ".Lf81c2c_00081cca:\n"
        "movl %esi, (%esp)\n" /* line 3655 | startLocalId */
        "calll Scr_KillEndonThread\n"
        "movl %esi, (%esp)\n" /* line 3657 | startLocalId */
        "calll RemoveRefToEmptyObject\n"
        "movl $0x1fffe, 4(%esp)\n" /* line 3610 */
        "movl %edi, (%esp)\n" /* notifyListOwnerId */
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 3611 */
        "jne .Lf81c2c_00081c50\n"
        /* } scope */
        ".Lf81c2c_00081cf2:\n"
        "addl $0x1c, %esp\n" /* line 3660 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf81c2c_00081cfa:\n"
        "movl %ebx, (%esp)\n" /* line 3633 | selfStartLocalId */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %ebx\n" /* selfStartLocalId */
        "movl %esi, %eax\n" /* line 3634 | startLocalId */
        "calll Scr_CancelWaittill\n"
        "xorl %ecx, %ecx\n" /* line 3635 */
        "movl %ebx, %edx\n" /* selfStartLocalId */
        "movl %esi, %eax\n" /* startLocalId */
        "calll VM_TrimStack\n"
        "jmp .Lf81c2c_00081c38\n"
        ".Lf81c2c_00081d1b:\n"
        "movl %eax, (%esp)\n" /* line 3650 */
        "calll GetVariableValueAddress\n"
        "movl $1, %ecx\n" /* line 3652 */
        "movl (%eax), %edx\n"
        "movl %ebx, %eax\n" /* selfStartLocalId */
        "calll VM_TrimStack\n"
        "jmp .Lf81c2c_00081cca\n"
    );
}

/* line 4095 */
void Scr_FreeThread(int handle)
{
    RemoveRefToObject((unsigned short)handle);
}

/* line 4241 */
__attribute__((naked))
void Scr_InitSystem(int sys)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4241 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "calll AllocObject\n" /* line 4258 */
        "movl imp_scrVarPub, %ebx\n"
        "movl %eax, 0x1c(%ebx)\n"
        "calll Scr_AllocArray\n" /* line 4264 */
        "movl %eax, 0x20(%ebx)\n"
        "calll AllocObject\n" /* line 4270 */
        "movl %eax, 0x24(%ebx)\n"
        "calll AllocObject\n" /* line 4276 */
        "movl %eax, 0x2c(%ebx)\n"
        "movl $0, 0x18(%ebx)\n" /* line 4283 */
        "movl $0xffffffff, g_script_error_level\n" /* line 4285 */
        "addl $4, %esp\n" /* line 4294 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4297 */
__attribute__((naked))
void Scr_ShutdownSystem(int sys, int bComplete)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4297 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* bComplete */
        /* { scope 1 */
        "calll Scr_CompileShutdown\n" /* line 4304 */
        "calll Scr_FreeEntityList\n" /* line 4314 */
        "movl imp_scrVarPub, %esi\n" /* line 4316 | stackValue */
        "movl 0x1c(%esi), %eax\n" /* stackValue */
        "testl %eax, %eax\n"
        "jne .Lf81d88_00081db3\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 4385 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf81d88_00081db3:\n"
        "movl %ebx, (%esp)\n" /* line 4324 | parentId */
        "calll Scr_FreeGameVariable\n"
        "movl 0x1c(%esi), %eax\n" /* line 4326 | stackValue */
        "movl %eax, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, -0x1c(%ebp)\n" /* id */
        "testl %eax, %eax\n"
        "je .Lf81d88_00081e04\n"
        "jmp .Lf81d88_00081eac\n"
        ".Lf81d88_00081dd2:\n"
        "movl %eax, (%esp)\n" /* line 4334 */
        "calll FindObject\n"
        "movl %eax, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, (%esp)\n" /* line 4336 */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %ebx\n" /* parentId */
        "movl %ebx, (%esp)\n" /* line 4337 | parentId */
        "calll AddRefToObject\n"
        "movl %ebx, (%esp)\n" /* line 4338 | parentId */
        "calll Scr_CancelNotifyList\n"
        "movl %ebx, (%esp)\n" /* line 4339 | parentId */
        "calll RemoveRefToObject\n"
        ".Lf81d88_00081e04:\n"
        "movl imp_scrVarPub, %ebx\n" /* line 4331 | parentId */
        "movl 0x20(%ebx), %eax\n" /* parentId */
        "movl %eax, (%esp)\n"
        "calll FindNextSibling\n"
        "testl %eax, %eax\n" /* line 4332 */
        "jne .Lf81d88_00081dd2\n"
        "movl 0x24(%ebx), %eax\n" /* line 4343 | parentId */
        "movl %eax, (%esp)\n"
        "calll ClearObject\n"
        "movl 0x24(%ebx), %eax\n" /* line 4347 | parentId */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToEmptyObject\n"
        "movl $0, 0x24(%ebx)\n" /* line 4348 | parentId */
        "movl 0x2c(%ebx), %eax\n" /* line 4351 | parentId */
        "movl %eax, (%esp)\n"
        "calll ClearObject\n"
        "movl 0x2c(%ebx), %eax\n" /* line 4355 | parentId */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToEmptyObject\n"
        "movl $0, 0x2c(%ebx)\n" /* line 4356 | parentId */
        "movl 0x1c(%ebx), %eax\n" /* line 4359 | parentId */
        "movl %eax, (%esp)\n"
        "calll ClearObject\n"
        "movl 0x1c(%ebx), %eax\n" /* line 4363 | parentId */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToEmptyObject\n"
        "movl $0, 0x1c(%ebx)\n" /* line 4364 | parentId */
        "movl 0x20(%ebx), %eax\n" /* line 4371 | parentId */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToEmptyObject\n"
        "movl $0, 0x20(%ebx)\n" /* line 4372 | parentId */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 4385 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_FreeObjects\n" /* line 4376 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf81d88_00081e8e:\n"
        "movl %edi, (%esp)\n" /* line 3689 */
        "calll RemoveRefToObject\n"
        /* } scope */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 4326 | id */
        "movl %eax, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, -0x1c(%ebp)\n" /* id */
        "testl %eax, %eax\n"
        "je .Lf81d88_00081e04\n"
        ".Lf81d88_00081eac:\n"
        "movl %eax, (%esp)\n" /* line 4327 */
        "calll FindObject\n"
        "movl %eax, %edi\n" /* timeId */
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 3672 */
        "calll AddRefToObject\n"
        "jmp .Lf81d88_00081ef3\n"
        ".Lf81d88_00081ec0:\n"
        "movl %eax, (%esp)\n" /* line 3678 */
        "calll GetVariableKeyObject\n"
        "movl %eax, %ebx\n" /* startLocalId */
        "movl %esi, (%esp)\n" /* line 3682 | stackValue */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %esi\n" /* stackValue */
        "movl %ebx, 4(%esp)\n" /* line 3684 | startLocalId */
        "movl %edi, (%esp)\n"
        "calll RemoveObjectVariable\n"
        "movl %ebx, (%esp)\n" /* line 3686 | startLocalId */
        "calll Scr_ClearWaitTime\n"
        "movl %esi, %ecx\n" /* line 3687 | stackValue */
        "movl %ebx, %edx\n" /* startLocalId */
        "movl %ebx, %eax\n" /* startLocalId */
        "calll VM_TerminateStack\n"
        ".Lf81d88_00081ef3:\n"
        "movl %edi, (%esp)\n" /* line 3675 */
        "calll FindNextSibling\n"
        "movl %eax, %esi\n" /* stackValue */
        "testl %eax, %eax\n" /* line 3676 */
        "jne .Lf81d88_00081ec0\n"
        "jmp .Lf81d88_00081e8e\n"
    );
}

/* line 4388 */
int Scr_IsSystemActive(int sys)
{
    return *(int *)(*(byte **)imp_scrVarPub + 0x1c) != 0;
}

/* line 4743 */
unsigned int Scr_GetNumParam(void)
{
    return *(unsigned int *)0x100821c;
}

/* line 4883 */
__attribute__((naked))
void Scr_AddArray(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4883 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl scrVmPub+16, %edx\n" /* line 4895 */
        "leal -8(%edx), %eax\n"
        "movl %eax, scrVmPub+16\n"
        "subl $1, scrVmPub+24\n" /* line 4896 */
        "movl -8(%edx), %eax\n" /* line 4898 */
        "movl %eax, (%esp)\n"
        "calll GetArraySize\n"
        "movl %eax, 4(%esp)\n"
        "movl scrVmPub+16, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetNewArrayVariable\n"
        "movl scrVmPub+16, %edx\n" /* line 4899 */
        "addl $8, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        /* } scope */
        "leave\n" /* line 4904 */
        "retl\n"
    );
}

/* line 4907 */
__attribute__((naked))
void Scr_AddArrayStringIndexed(unsigned int stringValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4907 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl scrVmPub+16, %edx\n" /* line 4912 */
        "leal -8(%edx), %eax\n"
        "movl %eax, scrVmPub+16\n"
        "subl $1, scrVmPub+24\n" /* line 4913 */
        "movl 8(%ebp), %eax\n" /* line 4915 | stringValue */
        "movl %eax, 4(%esp)\n"
        "movl -8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetNewVariable\n"
        "movl scrVmPub+16, %edx\n" /* line 4916 */
        "addl $8, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        /* } scope */
        "leave\n" /* line 4917 */
        "retl\n"
    );
}

/* line 4992 */
__attribute__((naked))
VariableValue GetEntityFieldValue(unsigned int classnum, int entnum, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4992 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $bg_weapClips+536, scrVmPub+16\n" /* line 4997 */
        "movl $0, scrVmGlob+4\n" /* line 4998 */
        "movl 0x10(%ebp), %eax\n" /* line 4999 | offset */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* entnum */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* classnum */
        "movl %eax, (%esp)\n"
        "calll Scr_GetObjectField\n"
        "movl $0, scrVmPub+24\n" /* line 5005 */
        "movl scrVmGlob, %eax\n" /* line 5006 */
        "movl scrVmGlob+4, %edx\n"
        "leave\n" /* line 5007 */
        "retl\n"
    );
}

/* line 5010 */
__attribute__((naked))
void Scr_SetStructField(unsigned int structId, unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5010 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 5022 | index */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* structId */
        "movl %eax, (%esp)\n"
        "calll Scr_GetVariableField\n"
        "movl $0, scrVmPub+24\n" /* line 5025 */
        "movl scrVmPub+16, %edx\n" /* line 5027 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableFieldValue\n"
        "subl $8, scrVmPub+16\n" /* line 5032 */
        /* } scope */
        "leave\n" /* line 5037 */
        "retl\n"
    );
}

/* line 161 */
__attribute__((naked))
void Scr_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 161 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl imp_scrVarPub, %ebx\n" /* line 163 */
        "cmpb $0, 0x38(%ebx)\n"
        "jne .Lf82042_00082155\n"
        "calll SL_Init\n" /* line 166 */
        "calll Var_Init\n" /* line 167 */
        "movl $scrVmPub+17176, scrVmPub+4\n" /* line 103 */
        "movl $scrVmPub+800, scrVmPub+16\n" /* line 104 */
        "movl $0, scrVmPub+8\n" /* line 105 */
        "movl $scrVmPub+32, scrVmPub+12\n" /* line 106 */
        "movl $scrVmGlob+24, scrVmPub\n" /* line 107 */
        "movb $0, 0xc(%ebx)\n" /* line 108 */
        "movb $0, scrVmPub+20\n" /* line 109 */
        "movl $0, 0x10(%ebx)\n" /* line 88 */
        "movl $0, scrVmGlob+16\n" /* line 89 */
        "movl $0, 0x14(%ebx)\n" /* line 90 */
        "movb $0, scrVmPub+22\n" /* line 112 */
        "movl $0, scrVmPub+28\n" /* line 114 */
        "movl $0, scrVmPub+24\n" /* line 115 */
        "calll AllocValue\n" /* line 117 */
        "movl %eax, 0x34(%ebx)\n"
        "movl $0, 0x1c(%ebx)\n" /* line 119 */
        "movl $0, 0x20(%ebx)\n" /* line 120 */
        "movl $0, 0x24(%ebx)\n" /* line 121 */
        "movl $0, 0x28(%ebx)\n" /* line 122 */
        "movl $0, 0x2c(%ebx)\n" /* line 123 */
        "movl $0, 0x30(%ebx)\n" /* line 124 */
        "movl $7, scrVmPub+804\n" /* line 126 */
        "movl $0, scrVmGlob+20\n" /* line 128 */
        "movl imp_scrCompilePub, %eax\n" /* line 170 */
        "movb $0, 0x24(%eax)\n"
        "movl imp_scrAnimPub, %edx\n" /* line 171 */
        "movb $0, 0x418(%edx)\n"
        "movl $0, 0xc(%eax)\n" /* line 172 */
        "movl $0, 8(%eax)\n" /* line 173 */
        "movl $0, (%edx)\n" /* line 174 */
        "movl $0, 0x14(%eax)\n" /* line 175 */
        "movl $0, 0x10(%eax)\n" /* line 176 */
        "movb $1, 0x38(%ebx)\n" /* line 178 */
        ".Lf82042_00082155:\n"
        "addl $4, %esp\n" /* line 179 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5274 */
__attribute__((naked))
void Scr_TraverseScript(const char *pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5274 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* pos */
        ".Lf8215c_00082162:\n"
        "leal 1(%edx), %ecx\n" /* line 5280 */
        "movzbl (%edx), %eax\n" /* line 5282 */
        "cmpl $0x86, %eax\n"
        "ja .Lf8215c_00082176\n"
        "jmpl *.Ljt_8215c_0(, %eax, 4)\n"
        ".Lf8215c_00082176:\n"
        "popl %ebp\n" /* line 5457 */
        "retl\n"
        ".Lf8215c_00082178:\n"
        "addl $5, %edx\n" /* line 157 */
        "jmp .Lf8215c_00082162\n"
        ".Lf8215c_0008217d:\n"
        "addl $3, %edx\n" /* line 144 */
        "jmp .Lf8215c_00082162\n"
        ".Lf8215c_00082182:\n"
        "addl $4, %edx\n"
        "jmp .Lf8215c_00082162\n"
        ".Lf8215c_00082187:\n"
        "addl $2, %edx\n" /* line 5440 */
        "jmp .Lf8215c_00082162\n"
        ".Lf8215c_0008218c:\n"
        "movl %ecx, %edx\n" /* line 5274 | pos */
        "jmp .Lf8215c_00082162\n"
        ".Lf8215c_00082190:\n"
        "movzwl (%ecx), %eax\n" /* line 183 */
        "leal 3(%edx, %eax, 8), %edx\n"
        "jmp .Lf8215c_00082162\n"
        ".Lf8215c_00082199:\n"
        "addl $0xd, %edx\n" /* line 170 */
        "jmp .Lf8215c_00082162\n"
        ".Lf8215c_0008219e:\n"
        "addl $9, %edx\n" /* line 157 */
        "jmp .Lf8215c_00082162\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_8215c_0:\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_00082199\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_00082182\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_00082182\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008219e\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_0008219e\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_0008217d\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082178\n"
        ".long .Lf8215c_00082190\n"
        ".long .Lf8215c_0008218c\n"
        ".long .Lf8215c_00082176\n"
        ".long .Lf8215c_00082176\n"
        ".long .Lf8215c_00082176\n"
        ".long .Lf8215c_00082176\n"
        ".long .Lf8215c_00082176\n"
        ".long .Lf8215c_00082176\n"
        ".long .Lf8215c_00082187\n"
        ".long .Lf8215c_00082187\n"
        ".text\n"
    );
}

/* line 2280 */
__attribute__((naked))
const char * Scr_GetNextCodepos(VariableValue *top, const char *pos, int opcode, int mode, unsigned int *localId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2280 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* pos */
        "movl 0x10(%ebp), %edx\n" /* opcode */
        "movl 0x18(%ebp), %edi\n" /* localId */
        /* { scope 1 */
        "movl scrVmPub+12, %eax\n" /* line 2289 */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%edi)\n" /* localId */
        ".Lf821a4_000821c0:\n"
        "leal 1(%ebx), %esi\n" /* line 2292 | pos */
        "cmpl $2, 0x14(%ebp)\n" /* line 2299 | mode */
        "je .Lf821a4_0008220a\n"
        ".Lf821a4_000821c9:\n"
        "cmpl $0x86, %edx\n" /* line 2339 */
        "ja .Lf821a4_000821d8\n"
        "jmpl *.Ljt_821a4_0(, %edx, 4)\n"
        ".Lf821a4_000821d8:\n"
        "movl imp_scrVarPub, %edx\n"
        ".Lf821a4_000821de:\n"
        "movl $0, 0x10(%edx)\n" /* line 88 */
        "movl $0, scrVmGlob+16\n" /* line 89 */
        "movl $0, 0x14(%edx)\n" /* line 90 */
        "movzbl (%esi), %eax\n" /* line 2609 */
        "movsbl %al, %edx\n"
        "cmpb $0x39, %al\n" /* line 2610 */
        "je .Lf821a4_00082219\n"
        /* } scope */
        ".Lf821a4_00082200:\n"
        "movl %esi, %eax\n" /* line 2617 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf821a4_0008220a:\n"
        "leal -0x4f(%edx), %eax\n" /* line 2301 */
        "cmpl $8, %eax\n"
        "ja .Lf821a4_000821c9\n"
        "jmpl *.Ljt_821a4_1(, %eax, 4)\n"
        ".Lf821a4_00082219:\n"
        "movl %esi, %ebx\n" /* line 2610 | pos */
        "jmp .Lf821a4_000821c0\n"
        ".Lf821a4_0008221d:\n"
        "leal 3(%ebx), %esi\n" /* line 144 */
        "movl imp_scrVarPub, %edx\n"
        "jmp .Lf821a4_000821de\n"
        ".Lf821a4_00082228:\n"
        "movl 8(%ebp), %eax\n" /* line 2305 | top */
        "cmpl $1, 4(%eax)\n"
        "jne .Lf821a4_000821c9\n"
        ".Lf821a4_00082231:\n"
        "cmpl $0x1f, scrVmPub+8\n" /* line 2313 */
        "jg .Lf821a4_000821c9\n"
        "movl $0, (%edi)\n" /* line 2316 | localId */
        "movl (%esi), %esi\n" /* line 215 */
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_00082244:\n"
        "movl 8(%ebp), %eax\n" /* top */
        ".Lf821a4_00082247:\n"
        "cmpl $9, 4(%eax)\n" /* line 2328 */
        "jne .Lf821a4_000821c9\n"
        "cmpl $0x1f, scrVmPub+8\n" /* line 2331 */
        "jg .Lf821a4_000821c9\n"
        "movl $0, (%edi)\n" /* line 2334 | localId */
        "movl (%eax), %esi\n" /* line 2335 */
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_00082268:\n"
        "movl 8(%ebp), %ecx\n" /* line 2321 | top */
        "cmpl $1, -4(%ecx)\n"
        "jne .Lf821a4_000821c9\n"
        "movl %ecx, %eax\n"
        "jmp .Lf821a4_00082247\n"
        ".Lf821a4_00082279:\n"
        "movl 8(%ebp), %ecx\n" /* line 2363 | top */
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %eax, -0x20(%ebp)\n" /* value */
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 246 | value */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddRefToValue\n"
        "leal -0x20(%ebp), %eax\n" /* line 2365 | value */
        "movl %eax, (%esp)\n"
        "calll Scr_CastBool\n"
        /* { scope 2 */
        "movzwl (%esi), %eax\n" /* line 143 */
        "leal 3(%ebx), %esi\n" /* line 144 */
        /* } scope */
        "movl imp_scrVarPub, %edx\n" /* line 2367 */
        "movl 0x10(%edx), %ebx\n" /* pos */
        "testl %ebx, %ebx\n" /* pos */
        "jne .Lf821a4_000821de\n"
        "movl -0x20(%ebp), %ecx\n" /* line 2371 | value */
        "testl %ecx, %ecx\n"
        "je .Lf821a4_00082200\n"
        "addl %eax, %esi\n" /* line 2373 */
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_000822cd:\n"
        "movl (%esi), %eax\n" /* line 2379 */
        "leal 4(%esi, %eax), %esi\n"
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_000822d8:\n"
        "movl (%esi), %eax\n" /* line 2387 */
        "leal 4(%esi, %eax), %eax\n"
        "leal 2(%eax), %esi\n" /* line 144 */
        "movzwl (%eax), %edi\n" /* line 2388 | localId */
        "movzwl %di, %ebx\n" /* localId, pos */
        "movl 8(%ebp), %edx\n" /* line 2394 | top */
        "movl 4(%edx), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lf821a4_0008243b\n"
        "cmpl $6, %eax\n"
        "je .Lf821a4_000823e9\n"
        ".Lf821a4_000822ff:\n"
        "leal (%esi, %ebx, 8), %esi\n" /* line 2410 */
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_00082307:\n"
        "leal 5(%ebx), %esi\n" /* line 157 */
        "movl imp_scrVarPub, %edx\n"
        "jmp .Lf821a4_000821de\n"
        ".Lf821a4_00082315:\n"
        "leal 2(%esi), %edx\n" /* line 2383 */
        "movzwl (%esi), %eax\n"
        "movl %edx, %esi\n"
        "subl %eax, %esi\n"
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_00082324:\n"
        "movl 8(%ebp), %ecx\n" /* line 2347 | top */
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %eax, -0x20(%ebp)\n" /* value */
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 246 | value */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddRefToValue\n"
        "leal -0x20(%ebp), %eax\n" /* line 2349 | value */
        "movl %eax, (%esp)\n"
        "calll Scr_CastBool\n"
        /* { scope 2 */
        "movzwl (%esi), %eax\n" /* line 143 */
        "leal 3(%ebx), %esi\n" /* line 144 */
        /* } scope */
        "movl imp_scrVarPub, %edx\n" /* line 2351 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf821a4_000821de\n"
        "movl -0x20(%ebp), %edi\n" /* line 2355 | value, localId */
        "testl %edi, %edi\n" /* localId */
        "jne .Lf821a4_00082200\n"
        "addl %eax, %esi\n" /* line 2373 */
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_00082378:\n"
        "leal 4(%ebx), %esi\n" /* line 144 */
        "movl imp_scrVarPub, %edx\n"
        "jmp .Lf821a4_000821de\n"
        ".Lf821a4_00082386:\n"
        "leal 0xd(%ebx), %esi\n" /* line 170 */
        "movl imp_scrVarPub, %edx\n"
        "jmp .Lf821a4_000821de\n"
        ".Lf821a4_00082394:\n"
        "movzwl (%esi), %eax\n" /* line 183 */
        "leal 2(%esi, %eax, 8), %esi\n"
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_000823a0:\n"
        "leal 9(%ebx), %esi\n" /* line 157 */
        "movl imp_scrVarPub, %edx\n"
        "jmp .Lf821a4_000821de\n"
        ".Lf821a4_000823ae:\n"
        "cmpl $1, scrVmPub+8\n" /* line 2262 */
        "jg .Lf821a4_000823cc\n"
        ".Lf821a4_000823b7:\n"
        "xorl %esi, %esi\n" /* line 2610 */
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_000823be:\n"
        "leal 2(%ebx), %esi\n" /* line 2530 | pos */
        "movl imp_scrVarPub, %edx\n"
        "jmp .Lf821a4_000821de\n"
        ".Lf821a4_000823cc:\n"
        "movl scrVmPub+12, %eax\n" /* line 2264 */
        "leal -0x18(%eax), %edx\n"
        "movl -0x18(%eax), %esi\n"
        "cmpl $g_EndPos, %esi\n" /* line 2265 */
        "je .Lf821a4_000823b7\n"
        "movl 4(%edx), %eax\n" /* line 2267 */
        "movl %eax, (%edi)\n"
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_000823e9:\n"
        "movl (%edx), %eax\n" /* line 2397 */
        "movl %eax, (%esp)\n"
        "calll IsValidArrayIndex\n"
        "testb %al, %al\n"
        "je .Lf821a4_000822ff\n"
        "movl 8(%ebp), %ecx\n" /* line 2399 | top */
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetInternalVariableIndex\n"
        "movl %eax, -0x2c(%ebp)\n" /* caseValue */
        ".Lf821a4_0008240b:\n"
        "testw %di, %di\n" /* line 2415 | localId */
        "je .Lf821a4_00082200\n"
        "xorl %edx, %edx\n"
        ".Lf821a4_00082416:\n"
        "movl %esi, %eax\n" /* line 2280 */
        /* { scope 2 */
        "movl (%esi), %ecx\n" /* line 156 */
        /* } scope */
        "addl $8, %esi\n" /* line 157 */
        "movl 4(%eax), %eax\n" /* line 215 */
        "cmpl %ecx, -0x2c(%ebp)\n" /* line 2423 | caseValue */
        "je .Lf821a4_00082434\n"
        "addl $1, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2419 | pos */
        "jne .Lf821a4_00082416\n"
        "testl %ecx, %ecx\n" /* line 2433 */
        "jne .Lf821a4_00082200\n"
        ".Lf821a4_00082434:\n"
        "movl %eax, %esi\n"
        "jmp .Lf821a4_00082200\n"
        ".Lf821a4_0008243b:\n"
        "movl (%edx), %eax\n" /* line 2406 */
        "movl %eax, -0x2c(%ebp)\n" /* caseValue */
        "jmp .Lf821a4_0008240b\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_821a4_0:\n"
        ".long .Lf821a4_000823ae\n"
        ".long .Lf821a4_000823ae\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_00082307\n"
        ".long .Lf821a4_00082307\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_00082386\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_00082307\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_00082307\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_00082378\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_00082378\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_00082307\n"
        ".long .Lf821a4_00082307\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_00082307\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823a0\n"
        ".long .Lf821a4_00082307\n"
        ".long .Lf821a4_000823a0\n"
        ".long .Lf821a4_00082307\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_00082324\n"
        ".long .Lf821a4_00082279\n"
        ".long .Lf821a4_00082324\n"
        ".long .Lf821a4_00082279\n"
        ".long .Lf821a4_000822cd\n"
        ".long .Lf821a4_00082315\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000822d8\n"
        ".long .Lf821a4_00082394\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000821d8\n"
        ".long .Lf821a4_000823a0\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_0008221d\n"
        ".long .Lf821a4_000823be\n"
        ".long .Lf821a4_000823be\n"
        ".text\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_821a4_1:\n"
        ".long .Lf821a4_00082231\n"
        ".long .Lf821a4_00082231\n"
        ".long .Lf821a4_00082244\n"
        ".long .Lf821a4_00082228\n"
        ".long .Lf821a4_00082268\n"
        ".long .Lf821a4_00082231\n"
        ".long .Lf821a4_00082244\n"
        ".long .Lf821a4_00082228\n"
        ".long .Lf821a4_00082268\n"
        ".text\n"
    );
}

/* line 3316 */
static __attribute__((naked))
void VM_Notify(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3316 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl %eax, -0x90(%ebp)\n"
        "movl %edx, -0x94(%ebp)\n"
        "movl %ecx, -0x98(%ebp)\n"
        /* { scope 1: selfId, stringValue, notifyListOwnerId, stackValue, ... */
        "movl $0x1fffe, 4(%esp)\n" /* line 3339 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 3340 */
        "jne .Lf82442_0008247f\n"
        /* } scope */
        ".Lf82442_00082474:\n"
        "addl $0xbc, %esp\n" /* line 3535 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: selfId, stringValue, notifyListOwnerId, stackValue, ... */
        ".Lf82442_0008247f:\n"
        "movl %eax, (%esp)\n" /* line 3343 */
        "calll FindObject\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl -0x94(%ebp), %eax\n" /* line 3346 */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 3347 */
        "je .Lf82442_00082474\n"
        "movl %eax, (%esp)\n" /* line 3350 */
        "calll FindObject\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %eax, (%esp)\n" /* line 3353 */
        "calll AddRefToObject\n"
        "movl imp_scrVarPub, %eax\n" /* line 3356 */
        "movb $1, 0xc(%eax)\n"
        "movl -0x40(%ebp), %esi\n" /* bNoStack */
        ".Lf82442_000824c2:\n"
        "movl %esi, (%esp)\n" /* line 3365 | bNoStack */
        "calll FindPrevSibling\n"
        "movl %eax, %esi\n" /* bNoStack */
        "testl %eax, %eax\n" /* line 3366 */
        "je .Lf82442_000825a9\n"
        ".Lf82442_000824d4:\n"
        "movl %eax, (%esp)\n" /* line 3369 */
        "calll GetVariableKeyObject\n"
        "movl %eax, %edi\n" /* startLocalId */
        "movl %eax, (%esp)\n" /* line 3371 */
        "calll Scr_GetSelf\n"
        "movl %eax, -0x78(%ebp)\n" /* selfId */
        "movl %eax, 4(%esp)\n" /* line 3373 */
        "movl imp_scrVarPub, %ecx\n"
        "movl 0x20(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindObjectVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, -0x74(%ebp)\n" /* selfNameId */
        "movl %esi, (%esp)\n" /* line 3375 | bNoStack */
        "calll GetVarType\n"
        "testl %eax, %eax\n"
        "jne .Lf82442_000825c8\n"
        "movl -0x94(%ebp), %ebx\n" /* line 3378 | stackId */
        "movl %ebx, 4(%esp)\n" /* stackId */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl %edi, %edx\n" /* startLocalId */
        "movl -0x90(%ebp), %eax\n"
        "calll VM_CancelNotifyInternal\n"
        "movl %edi, (%esp)\n" /* line 3380 | startLocalId */
        "calll Scr_KillEndonThread\n"
        "movl %edi, 4(%esp)\n" /* line 3383 | startLocalId */
        "movl -0x74(%ebp), %edx\n" /* selfNameId */
        "movl %edx, (%esp)\n"
        "calll RemoveObjectVariable\n"
        "movl -0x74(%ebp), %ecx\n" /* line 3384 | selfNameId */
        "movl %ecx, (%esp)\n"
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "je .Lf82442_00082768\n"
        "movl -0x78(%ebp), %ecx\n" /* line 3256 | selfId */
        "movl %ecx, (%esp)\n"
        "calll GetStartLocalId\n"
        "movl %eax, -0x60(%ebp)\n" /* startLocalId */
        "movl %eax, (%esp)\n" /* line 3257 */
        "calll GetVarType\n"
        "cmpl $0x10, %eax\n"
        "je .Lf82442_0008279f\n"
        ".Lf82442_00082582:\n"
        "cmpl $0x11, %eax\n"
        "je .Lf82442_000829f7\n"
        "cmpl $0xf, %eax\n"
        "je .Lf82442_00082a91\n"
        ".Lf82442_00082594:\n"
        "movl -0x40(%ebp), %esi\n" /* line 3356 | bNoStack */
        ".Lf82442_00082597:\n"
        "movl %esi, (%esp)\n" /* line 3365 | bNoStack */
        "calll FindPrevSibling\n"
        "movl %eax, %esi\n" /* bNoStack */
        "testl %eax, %eax\n" /* line 3366 */
        "jne .Lf82442_000824d4\n"
        ".Lf82442_000825a9:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 3531 */
        "movl %ecx, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl imp_scrVarPub, %eax\n" /* line 3534 */
        "movb $0, 0xc(%eax)\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 3535 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: selfId, stringValue, notifyListOwnerId, stackValue, ... */
        ".Lf82442_000825c8:\n"
        "movl %esi, (%esp)\n" /* line 3394 | bNoStack */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %eax\n" /* line 3395 */
        "movl %eax, -0x88(%ebp)\n" /* stackValue */
        "movl (%eax), %ecx\n" /* line 3397 */
        "cmpb $0x77, -1(%ecx)\n"
        "je .Lf82442_0008289a\n"
        "movl -0x98(%ebp), %ecx\n" /* line 3449 */
        "cmpl $8, 4(%ecx)\n"
        "sete %bl\n" /* stackId */
        "movl %ebx, %esi\n" /* stackId, bNoStack */
        "movl imp_scrVarPub, %eax\n"
        "movl %eax, -0xa0(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lf82442_00082600:\n"
        "movl $0xa, -0x2c(%ebp)\n" /* line 3452 */
        "movl -0x88(%ebp), %edx\n" /* line 3453 | stackValue */
        "movl %edx, -0x30(%ebp)\n" /* tempValue5 */
        "movl 0x18(%ecx), %eax\n" /* line 3455 */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl %edi, 4(%esp)\n" /* startLocalId */
        "movl %eax, (%esp)\n"
        "calll GetNewObjectVariable\n"
        "movl %eax, %ebx\n" /* stackId */
        "leal -0x30(%ebp), %eax\n" /* line 3456 | tempValue5 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* stackId */
        "calll SetNewVariableValue\n"
        "movl %ebx, (%esp)\n" /* line 3458 | stackId */
        "calll GetVariableValueAddress\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x94(%ebp), %ebx\n" /* line 3460 | stackId */
        "movl %ebx, 4(%esp)\n" /* stackId */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl %edi, %edx\n" /* startLocalId */
        "movl -0x90(%ebp), %eax\n"
        "calll VM_CancelNotifyInternal\n"
        "movl %edi, 4(%esp)\n" /* line 3462 | startLocalId */
        "movl -0x74(%ebp), %edx\n" /* selfNameId */
        "movl %edx, (%esp)\n"
        "calll RemoveObjectVariable\n"
        "movl -0x74(%ebp), %ecx\n" /* line 3463 | selfNameId */
        "movl %ecx, (%esp)\n"
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "je .Lf82442_000829da\n"
        ".Lf82442_00082694:\n"
        "movl -0xa0(%ebp), %ecx\n" /* line 3466 */
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* startLocalId */
        "calll Scr_SetThreadWaitTime\n"
        "movl %esi, %ebx\n" /* line 3468 | bNoStack, stackId */
        "testb %bl, %bl\n" /* stackId */
        "jne .Lf82442_00082594\n"
        "movl -0x88(%ebp), %eax\n" /* line 3477 | stackValue */
        "movzwl 4(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl -0x98(%ebp), %edx\n"
        "subl $4, %edx\n"
        "movl -0x98(%ebp), %edi\n" /* startLocalId */
        "movl %eax, %esi\n" /* bNoStack */
        ".Lf82442_000826d1:\n"
        "addl $1, %esi\n" /* line 3483 | bNoStack */
        "subl $8, %edi\n" /* line 3484 | startLocalId */
        "movl (%edx), %eax\n" /* line 3481 */
        "subl $8, %edx\n"
        "cmpl $8, %eax\n"
        "jne .Lf82442_000826d1\n"
        "movl -0x50(%ebp), %edx\n" /* line 3490 */
        "leal (%edx, %edx, 4), %edx\n"
        "movl %edx, -0x9c(%ebp)\n"
        "leal 0xb(%esi, %esi, 4), %ecx\n" /* line 3491 | bNoStack */
        "movl %ecx, -0x7c(%ebp)\n" /* bufLen */
        "movl %ecx, 4(%esp)\n" /* line 3493 */
        "movl -0x88(%ebp), %ebx\n" /* stackValue, stackId */
        "movzwl 6(%ebx), %eax\n" /* stackId */
        "movl %eax, (%esp)\n"
        "calll MT_Realloc\n"
        "testl %eax, %eax\n"
        "je .Lf82442_00082b68\n"
        "movl -0x88(%ebp), %ebx\n" /* stackValue, stackId */
        ".Lf82442_00082718:\n"
        "movw %si, 4(%ebx)\n" /* line 3508 | bNoStack, stackId */
        "movl -0x88(%ebp), %eax\n" /* line 3510 | stackValue */
        "movl -0x9c(%ebp), %edx\n"
        "leal 0xb(%eax, %edx), %ebx\n" /* stackId */
        "subl -0x50(%ebp), %esi\n" /* line 3512 | bNoStack */
        "movl %esi, -0x48(%ebp)\n" /* bNoStack */
        "leal 8(%edi), %esi\n" /* startLocalId, bNoStack */
        "xorl %edi, %edi\n" /* startLocalId */
        ".Lf82442_00082737:\n"
        "movl (%esi), %eax\n" /* line 246 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddRefToValue\n"
        "movl 4(%esi), %eax\n" /* line 3520 | bNoStack */
        "movb %al, (%ebx)\n" /* stackId */
        "movl (%esi), %eax\n" /* line 3522 | bNoStack */
        "movl %eax, 1(%ebx)\n" /* stackId */
        "addl $5, %ebx\n" /* line 3523 | stackId */
        "addl $1, %edi\n" /* startLocalId */
        "addl $8, %esi\n" /* bNoStack */
        "cmpl %edi, -0x48(%ebp)\n" /* line 3515 | startLocalId */
        "jne .Lf82442_00082737\n"
        "movl -0x40(%ebp), %esi\n" /* line 3356 | bNoStack */
        "jmp .Lf82442_00082597\n"
        ".Lf82442_00082768:\n"
        "movl -0x78(%ebp), %ebx\n" /* line 3385 | selfId, stackId */
        "movl %ebx, 4(%esp)\n" /* stackId */
        "movl imp_scrVarPub, %edx\n"
        "movl 0x20(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveObjectVariable\n"
        "movl -0x78(%ebp), %ecx\n" /* line 3256 | selfId */
        "movl %ecx, (%esp)\n"
        "calll GetStartLocalId\n"
        "movl %eax, -0x60(%ebp)\n" /* startLocalId */
        "movl %eax, (%esp)\n" /* line 3257 */
        "calll GetVarType\n"
        "cmpl $0x10, %eax\n"
        "jne .Lf82442_00082582\n"
        /* { scope 2 */
        ".Lf82442_0008279f:\n"
        "movl -0x60(%ebp), %edx\n" /* line 3166 | startLocalId */
        "movl %edx, (%esp)\n"
        "calll Scr_GetThreadNotifyName\n"
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x6c(%ebp)\n" /* stringValue */
        "testw %ax, %ax\n" /* line 3167 */
        "je .Lf82442_00082b30\n"
        "movl -0x60(%ebp), %ebx\n" /* line 3169 | startLocalId, notifyNameListId */
        "movl %ebx, (%esp)\n" /* notifyNameListId */
        "calll Scr_GetSelf\n"
        "movl %eax, -0x70(%ebp)\n" /* selfId */
        "movl %eax, 4(%esp)\n" /* line 3170 */
        "movl imp_scrVarPub, %edx\n"
        "movl 0x20(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindObjectVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, %esi\n" /* selfNameId */
        "movl %ebx, 4(%esp)\n" /* line 3171 | notifyNameListId */
        "movl %eax, (%esp)\n"
        "calll FindObjectVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetVariableValueAddress\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x68(%ebp)\n" /* notifyListOwnerId */
        "movl $0x1fffe, 4(%esp)\n" /* line 3172 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, %edi\n" /* notifyListId */
        "movl -0x6c(%ebp), %ecx\n" /* line 3173 | stringValue */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, %ebx\n" /* notifyNameListId */
        "movl -0x60(%ebp), %eax\n" /* line 3174 | startLocalId */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* notifyNameListId */
        "calll FindObjectVariable\n"
        "movl %eax, (%esp)\n" /* line 3177 */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x64(%ebp)\n" /* stackValue */
        "movl -0x6c(%ebp), %edx\n" /* line 3184 | stringValue */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* notifyNameListId */
        "movl %edi, %ecx\n" /* notifyListId */
        "movl -0x60(%ebp), %edx\n" /* startLocalId */
        "movl -0x68(%ebp), %eax\n" /* notifyListOwnerId */
        "calll VM_CancelNotifyInternal\n"
        "movl -0x60(%ebp), %ecx\n" /* line 3185 | startLocalId */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* selfNameId */
        "calll RemoveObjectVariable\n"
        "movl %esi, (%esp)\n" /* line 3186 | selfNameId */
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "je .Lf82442_00082c1b\n"
        ".Lf82442_00082884:\n"
        "movl -0x64(%ebp), %ecx\n" /* line 3204 | stackValue */
        "movl -0x60(%ebp), %edx\n" /* startLocalId */
        "movl -0x78(%ebp), %eax\n" /* selfId */
        "calll VM_TerminateStack\n"
        "movl -0x40(%ebp), %esi\n" /* selfNameId */
        "jmp .Lf82442_000824c2\n"
        /* } scope */
        ".Lf82442_0008289a:\n"
        "movzbl (%ecx), %edx\n" /* line 3399 */
        "movsbl %dl, %ebx\n" /* stackId */
        "movl %ebx, -0xac(%ebp)\n" /* stackId */
        "movl %eax, %ebx\n" /* line 3403 | stackId */
        "movzwl 4(%eax), %eax\n"
        "subl -0xac(%ebp), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal 0xb(%ebx, %eax), %eax\n" /* stackId */
        "movl %eax, -0x84(%ebp)\n" /* buf */
        "testb %dl, %dl\n" /* line 3406 */
        "je .Lf82442_00082b0a\n"
        "movl -0x98(%ebp), %ebx\n" /* line 3409 | stackId */
        "cmpl $8, 4(%ebx)\n" /* stackId */
        "je .Lf82442_000824c2\n"
        "movl -0xac(%ebp), %eax\n" /* line 3412 */
        "subl $1, %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* size */
        "movl -0x84(%ebp), %ecx\n" /* line 3413 | buf */
        "movzbl (%ecx), %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "cmpb $8, %dl\n" /* line 3415 */
        "je .Lf82442_00082c00\n"
        "subl $4, %ebx\n" /* line 3416 | stackId */
        "movl %ebx, -0x54(%ebp)\n" /* stackId */
        "movl -0x98(%ebp), %ebx\n" /* stackId */
        "movl %ebx, -0x8c(%ebp)\n" /* stackId, currentValue */
        "xorl %ebx, %ebx\n" /* stackId */
        "movl -0x84(%ebp), %edx\n" /* buf */
        "jmp .Lf82442_00082919\n"
        ".Lf82442_00082917:\n"
        "movl %ecx, %edx\n"
        ".Lf82442_00082919:\n"
        "movl -0x80(%ebp), %eax\n" /* line 3316 | size */
        "subl %ebx, %eax\n" /* notifyNameListId */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 1(%edx), %eax\n" /* line 3418 */
        "movl %eax, -0x28(%ebp)\n" /* tempValue3 */
        "addl $5, %edx\n" /* line 3419 */
        "movl %edx, -0x84(%ebp)\n" /* buf */
        "movl %eax, 4(%esp)\n" /* line 246 */
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddRefToValue\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 3423 | currentValue */
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %eax, -0x20(%ebp)\n" /* tempValue2 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 246 | tempValue2 */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddRefToValue\n"
        "leal -0x20(%ebp), %eax\n" /* line 3426 | tempValue2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* tempValue3 */
        "movl %edx, (%esp)\n"
        "calll Scr_EvalEquality\n"
        "movl imp_scrVarPub, %ecx\n" /* line 3428 */
        "movl %ecx, -0xa0(%ebp)\n"
        "movl 0x10(%ecx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf82442_00082c38\n"
        "movl -0x28(%ebp), %eax\n" /* line 3431 | tempValue3 */
        "testl %eax, %eax\n"
        "je .Lf82442_000824c2\n"
        "subl $8, -0x8c(%ebp)\n" /* line 3433 | currentValue */
        "cmpl -0x80(%ebp), %ebx\n" /* line 3406 | size, stackId */
        "je .Lf82442_000829cd\n"
        "movl -0x54(%ebp), %edx\n" /* line 3409 */
        "cmpl $8, (%edx)\n"
        "je .Lf82442_000824c2\n"
        "movl -0x84(%ebp), %ecx\n" /* line 3413 | buf */
        "movzbl (%ecx), %edx\n"
        "movzbl %dl, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "addl $1, %ebx\n" /* stackId */
        "subl $8, -0x54(%ebp)\n"
        "cmpb $8, %dl\n" /* line 3415 */
        "jne .Lf82442_00082917\n"
        ".Lf82442_000829cd:\n"
        "movl -0x88(%ebp), %edx\n" /* stackValue */
        "movl (%edx), %ecx\n"
        "jmp .Lf82442_00082b1b\n"
        ".Lf82442_000829da:\n"
        "movl -0x78(%ebp), %ebx\n" /* line 3464 | selfId, stackId */
        "movl %ebx, 4(%esp)\n" /* stackId */
        "movl -0xa0(%ebp), %edx\n"
        "movl 0x20(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveObjectVariable\n"
        "jmp .Lf82442_00082694\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf82442_000829f7:\n"
        "movl -0x60(%ebp), %eax\n" /* line 3103 | startLocalId */
        "movl %eax, (%esp)\n"
        "calll Scr_GetThreadWaitTime\n"
        "movl %eax, %esi\n" /* time */
        "movl -0x60(%ebp), %edx\n" /* line 3104 | startLocalId */
        "movl %edx, (%esp)\n"
        "calll Scr_ClearWaitTime\n"
        "movl %esi, 4(%esp)\n" /* line 3105 | time */
        "movl imp_scrVarPub, %ecx\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, %ebx\n" /* id */
        "movl -0x60(%ebp), %eax\n" /* line 3106 | startLocalId */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* id */
        "calll FindObjectVariable\n"
        "movl %eax, (%esp)\n" /* line 3109 */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %edi\n" /* stackValue */
        "movl -0x60(%ebp), %edx\n" /* line 3116 | startLocalId */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* id */
        "calll RemoveObjectVariable\n"
        "movl %ebx, (%esp)\n" /* line 3117 | id */
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "jne .Lf82442_00082a7c\n"
        "movl imp_scrVarPub, %ecx\n"
        "cmpl 0x18(%ecx), %esi\n" /* time */
        "je .Lf82442_00082a7c\n"
        "movl %esi, 4(%esp)\n" /* line 3118 | time */
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        ".Lf82442_00082a7c:\n"
        "movl %edi, %ecx\n" /* line 3120 | stackValue */
        "movl -0x60(%ebp), %edx\n" /* startLocalId */
        "movl -0x78(%ebp), %eax\n" /* selfId */
        "calll VM_TerminateStack\n"
        "movl -0x40(%ebp), %esi\n" /* time */
        "jmp .Lf82442_000824c2\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf82442_00082a91:\n"
        "movl scrVmPub+8, %edi\n" /* line 3034 */
        "testl %edi, %edi\n" /* line 3037 */
        "je .Lf82442_00082594\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 3043 */
        "movl scrVmPub+36(, %eax, 8), %edx\n"
        "cmpl %edx, -0x78(%ebp)\n" /* line 3045 | selfId */
        "je .Lf82442_00082bda\n"
        "leal -1(%edi), %eax\n" /* line 3316 | notifyListId */
        "movl %eax, -0x58(%ebp)\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal scrVmPub+32(, %eax, 8), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl %edi, %esi\n" /* notifyListId, selfNameId */
        "movl %edi, %ebx\n" /* notifyListId, notifyNameListId */
        ".Lf82442_00082ac9:\n"
        "subl $1, %esi\n" /* line 3062 */
        "movl %edx, (%esp)\n" /* line 3063 */
        "calll GetSafeParentLocalId\n"
        "testl %eax, %eax\n"
        "cmovel %esi, %ebx\n" /* function_count */
        "movl %edi, %eax\n" /* line 3037 */
        "subl -0x58(%ebp), %eax\n"
        "subl $1, %eax\n"
        "cmpl %esi, %eax\n"
        "je .Lf82442_00082594\n"
        "movl -0x5c(%ebp), %eax\n" /* line 3043 */
        "movl 4(%eax), %edx\n"
        "subl $0x18, %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "cmpl %edx, -0x78(%ebp)\n" /* line 3045 | selfId */
        "jne .Lf82442_00082ac9\n"
        "cmpl %ebx, %esi\n" /* line 3047 | function_count */
        "jle .Lf82442_00082bde\n"
        /* } scope */
        "movl -0x40(%ebp), %esi\n" /* line 3356 | bNoStack */
        "jmp .Lf82442_00082597\n"
        ".Lf82442_00082b0a:\n"
        "movl imp_scrVarPub, %eax\n"
        "movl %eax, -0xa0(%ebp)\n"
        "movl -0x88(%ebp), %edx\n" /* stackValue */
        ".Lf82442_00082b1b:\n"
        "leal 1(%ecx), %eax\n" /* line 3443 */
        "movl %eax, (%edx)\n"
        "movl $1, %esi\n" /* bNoStack */
        "movl -0xa0(%ebp), %ecx\n"
        "jmp .Lf82442_00082600\n"
        /* { scope 2 */
        ".Lf82442_00082b30:\n"
        "movl $0x1ffff, 4(%esp)\n" /* line 3191 */
        "movl -0x60(%ebp), %ecx\n" /* startLocalId */
        "movl %ecx, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n" /* line 3194 */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x64(%ebp)\n" /* stackValue */
        "movl $0x1ffff, 4(%esp)\n" /* line 3201 */
        "movl -0x60(%ebp), %ebx\n" /* startLocalId, notifyNameListId */
        "movl %ebx, (%esp)\n" /* notifyNameListId */
        "calll RemoveVariable\n"
        "jmp .Lf82442_00082884\n"
        /* } scope */
        ".Lf82442_00082b68:\n"
        "movl $1, 4(%esp)\n" /* line 3495 */
        "movl -0x7c(%ebp), %eax\n" /* bufLen */
        "movl %eax, (%esp)\n"
        "calll MT_Alloc\n"
        "movl %eax, %ebx\n" /* stackId */
        "movl -0x7c(%ebp), %edx\n" /* line 3497 | bufLen */
        "movw %dx, 6(%eax)\n"
        "movl -0x88(%ebp), %ecx\n" /* line 3498 | stackValue */
        "movl (%ecx), %eax\n"
        "movl %eax, (%ebx)\n" /* stackId */
        "movzwl 8(%ecx), %eax\n" /* line 3499 */
        "movw %ax, 8(%ebx)\n" /* stackId */
        "leal 0xb(%ebx), %edx\n" /* line 3501 | stackId */
        "movl %ecx, %eax\n"
        "addl $0xb, %eax\n"
        "movl -0x9c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x88(%ebp), %edx\n" /* line 3502 | stackValue */
        "movzwl 6(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        "movl -0x44(%ebp), %ecx\n" /* line 3505 */
        "movl %ebx, (%ecx)\n" /* stackId */
        "movl %ebx, -0x88(%ebp)\n" /* stackId, stackValue */
        "jmp .Lf82442_00082718\n"
        /* { scope 2 */
        ".Lf82442_00082bda:\n"
        "movl %edi, %ebx\n" /* line 3045 | function_count */
        "movl %edi, %esi\n"
        ".Lf82442_00082bde:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 3047 | function_count */
        "leal scrVmPub+32(, %eax, 8), %eax\n"
        ".Lf82442_00082be8:\n"
        "movl $g_EndPos, (%eax)\n" /* line 3055 */
        "subl $1, %ebx\n" /* line 3058 | function_count */
        "subl $0x18, %eax\n"
        "cmpl %esi, %ebx\n" /* line 3047 | function_count */
        "jge .Lf82442_00082be8\n"
        /* } scope */
        "movl -0x40(%ebp), %esi\n" /* line 3356 | bNoStack */
        "jmp .Lf82442_00082597\n"
        ".Lf82442_00082c00:\n"
        "movl imp_scrVarPub, %ecx\n"
        "movl %ecx, -0xa0(%ebp)\n"
        "movl -0x88(%ebp), %ebx\n" /* stackValue, stackId */
        "movl (%ebx), %ecx\n" /* stackId */
        "movl %ebx, %edx\n" /* stackId */
        "jmp .Lf82442_00082b1b\n"
        /* { scope 2 */
        ".Lf82442_00082c1b:\n"
        "movl -0x70(%ebp), %ebx\n" /* line 3187 | selfId, notifyNameListId */
        "movl %ebx, 4(%esp)\n" /* notifyNameListId */
        "movl imp_scrVarPub, %edx\n"
        "movl 0x20(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveObjectVariable\n"
        "jmp .Lf82442_00082884\n"
        /* } scope */
        ".Lf82442_00082c38:\n"
        "movl -0x88(%ebp), %ebx\n" /* line 3437 | stackValue, stackId */
        "movl (%ebx), %edx\n" /* stackId */
        "movl scrVmGlob+16, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movsbl (%edx), %eax\n"
        "subl -0x4c(%ebp), %eax\n"
        "addl $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RuntimeError\n"
        "movl -0xa0(%ebp), %eax\n" /* line 88 */
        "movl $0, 0x10(%eax)\n"
        "movl $0, scrVmGlob+16\n" /* line 89 */
        "movl $0, 0x14(%eax)\n" /* line 90 */
        "jmp .Lf82442_000824c2\n"
    );
}

/* line 5040 */
__attribute__((naked))
void Scr_SetDynamicEntityField(int entnum, int classnum, unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5040 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 5049 | classnum */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* entnum */
        "movl %eax, (%esp)\n"
        "calll Scr_GetEntityId\n"
        /* { scope 2 */
        "movl 0x10(%ebp), %edx\n" /* line 5022 | index */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Scr_GetVariableField\n"
        "movl $0, scrVmPub+24\n" /* line 5025 */
        "movl scrVmPub+16, %edx\n" /* line 5027 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableFieldValue\n"
        "subl $8, scrVmPub+16\n" /* line 5032 */
        /* } scope */
        /* } scope */
        "leave\n" /* line 5057 */
        "retl\n"
    );
}

/* line 4875 */
__attribute__((naked))
void Scr_MakeArray(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4875 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf82cd2_00082d19\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf82cd2_00082d58\n"
        ".Lf82cd2_00082cf0:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $1, 4(%eax)\n" /* line 4878 */
        "movl scrVmPub+16, %ebx\n" /* line 4879 */
        "calll Scr_AllocArray\n"
        "movl %eax, (%ebx)\n"
        "addl $0x14, %esp\n" /* line 4880 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf82cd2_00082d19:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf82cd2_00082d1f:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf82cd2_00082d1f\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf82cd2_00082cf0\n"
        ".Lf82cd2_00082d58:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "jmp .Lf82cd2_00082cf0\n"
    );
}

/* line 3538 */
__attribute__((naked))
void Scr_NotifyNum(int entnum, int classnum, unsigned int stringValue, unsigned int paramcount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3538 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0x14(%ebp), %ebx\n" /* paramcount */
        /* { scope 1 */
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf82d7a_00082dfa\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf82d7a_00082d95:\n"
        "leal (, %ebx, 8), %eax\n" /* line 3564 */
        "movl %edx, %esi\n" /* startTop */
        "subl %eax, %esi\n" /* startTop */
        "movl scrVmPub+24, %edi\n" /* line 3565 */
        "subl %ebx, %edi\n" /* type */
        "movl 0xc(%ebp), %eax\n" /* line 3567 | classnum */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* entnum */
        "movl %eax, (%esp)\n"
        "calll FindEntityId\n"
        "testl %eax, %eax\n" /* line 3568 */
        "jne .Lf82d7a_00082e36\n"
        ".Lf82d7a_00082dbe:\n"
        "movl scrVmPub+16, %edx\n" /* line 3577 */
        "cmpl %edx, %esi\n" /* startTop */
        "je .Lf82d7a_00082dec\n"
        ".Lf82d7a_00082dc8:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 3580 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "cmpl %edx, %esi\n" /* line 3577 | startTop */
        "jne .Lf82d7a_00082dc8\n"
        ".Lf82d7a_00082dec:\n"
        "movl %edi, scrVmPub+24\n" /* line 3583 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3595 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf82d7a_00082dfa:\n"
        "movl scrVmPub+16, %edx\n"
        /* { scope 1 */
        ".Lf82d7a_00082e00:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf82d7a_00082e00\n"
        "jmp .Lf82d7a_00082d95\n"
        ".Lf82d7a_00082e36:\n"
        "movl 4(%esi), %ebx\n" /* line 3570 | startTop, type */
        "movl $8, 4(%esi)\n" /* line 3571 | startTop */
        "movl $0, scrVmPub+24\n" /* line 3572 */
        "movl scrVmPub+16, %ecx\n" /* line 3573 */
        "movl 0x10(%ebp), %edx\n" /* stringValue */
        "calll VM_Notify\n"
        "movl %ebx, 4(%esi)\n" /* line 3574 | type, startTop */
        "jmp .Lf82d7a_00082dbe\n"
    );
}

/* line 4960 */
__attribute__((naked))
Bool SetEntityFieldValue(unsigned int classnum, int entnum, int offset, VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4960 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, scrVmPub+28\n" /* line 4967 */
        "movl 0x14(%ebp), %eax\n" /* line 4968 | value */
        "movl %eax, scrVmPub+16\n"
        "movl 0x10(%ebp), %eax\n" /* line 4969 | offset */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* entnum */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* classnum */
        "movl %eax, (%esp)\n"
        "calll Scr_SetObjectField\n"
        "testl %eax, %eax\n"
        "jne .Lf82e60_00082ea1\n"
        "movl $0, scrVmPub+28\n" /* line 4973 */
        "leave\n" /* line 4989 */
        "retl\n"
        ".Lf82e60_00082ea1:\n"
        "movl scrVmPub+28, %eax\n" /* line 4979 */
        "testl %eax, %eax\n"
        "jne .Lf82e60_00082eb1\n"
        "movl $1, %eax\n" /* line 4985 */
        ".Lf82e60_00082eaf:\n"
        "leave\n" /* line 4989 */
        "retl\n"
        ".Lf82e60_00082eb1:\n"
        "movl scrVmPub+16, %eax\n" /* line 4983 | value */
        /* { scope 1 */
        "movl (%eax), %edx\n" /* line 252 */
        "movl %edx, 4(%esp)\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        /* } scope */
        "subl $8, scrVmPub+16\n" /* line 4984 */
        "movl $0, scrVmPub+28\n" /* line 4985 */
        "movl $1, %eax\n"
        "jmp .Lf82e60_00082eaf\n"
    );
}

/* line 4953 */
__attribute__((naked))
void Scr_ObjectError(const char *error)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4953 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4955 */
        "movl $0xffffffff, 0x14(%ecx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 4922 */
        "testl %eax, %eax\n"
        "je .Lf82ee0_00082f8b\n"
        ".Lf82ee0_00082efe:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf82ee0_00082f0f\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf82ee0_00082f35\n"
        ".Lf82ee0_00082f0f:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf82ee0_00082f33\n"
        ".Lf82ee0_00082f18:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf82ee0_00082f33:\n"
        "leave\n" /* line 4957 */
        "retl\n"
        ".Lf82ee0_00082f35:\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf82ee0_00082f6c\n"
        ".Lf82ee0_00082f3b:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf82ee0_00082f4d\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf82ee0_00082f18\n"
        ".Lf82ee0_00082f4d:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf82ee0_00082f6c:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf82ee0_00082f3b\n"
        ".Lf82ee0_00082f8b:\n"
        "movl 8(%ebp), %eax\n" /* line 4923 | error */
        "movl %eax, 0x10(%ecx)\n"
        "jmp .Lf82ee0_00082efe\n"
    );
}

/* line 4945 */
__attribute__((naked))
void Scr_ParamError(unsigned int index, const char *error)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4945 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4948 */
        "movl 8(%ebp), %eax\n" /* index */
        "addl $1, %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 4922 */
        "testl %eax, %eax\n"
        "je .Lf82f96_00083043\n"
        ".Lf82f96_00082fb6:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf82f96_00082fc7\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf82f96_00082fed\n"
        ".Lf82f96_00082fc7:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf82f96_00082feb\n"
        ".Lf82f96_00082fd0:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf82f96_00082feb:\n"
        "leave\n" /* line 4950 */
        "retl\n"
        ".Lf82f96_00082fed:\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf82f96_00083024\n"
        ".Lf82f96_00082ff3:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf82f96_00083005\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf82f96_00082fd0\n"
        ".Lf82f96_00083005:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf82f96_00083024:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf82f96_00082ff3\n"
        ".Lf82f96_00083043:\n"
        "movl 0xc(%ebp), %eax\n" /* line 4923 | error */
        "movl %eax, 0x10(%ecx)\n"
        "jmp .Lf82f96_00082fb6\n"
    );
}

/* line 4936 */
__attribute__((naked))
void Scr_TerminalError(const char *error)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4936 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll Scr_DumpScriptThreads\n" /* line 4938 */
        "calll Scr_DumpScriptVariables\n" /* line 4939 */
        "movb $1, scrVmPub+22\n" /* line 4940 */
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf8304e_000830fa\n"
        ".Lf8304e_00083076:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf8304e_000830be\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf8304e_000830be\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf8304e_000830db\n"
        ".Lf8304e_0008308d:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf8304e_0008309f\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf8304e_000830be\n"
        ".Lf8304e_0008309f:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf8304e_000830be:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "leave\n" /* line 4942 */
        "retl\n"
        ".Lf8304e_000830db:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf8304e_0008308d\n"
        ".Lf8304e_000830fa:\n"
        "movl 8(%ebp), %eax\n" /* line 4923 | error */
        "movl %eax, 0x10(%ecx)\n"
        "jmp .Lf8304e_00083076\n"
    );
}

/* line 4728 */
__attribute__((naked))
int Scr_GetPointerType(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4728 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "cmpl %ebx, scrVmPub+28\n" /* line 4730 | index */
        "jbe .Lf83106_000831d1\n"
        "leal (, %ebx, 8), %eax\n" /* line 4732 */
        "movl scrVmPub+16, %edx\n"
        "subl %eax, %edx\n"
        "movl 4(%edx), %ecx\n"
        "cmpl $1, %ecx\n"
        "je .Lf83106_00083286\n"
        "movl imp_var_typename, %eax\n" /* line 4735 */
        "movl (%eax, %ecx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cdf4, (%esp)\n" /* "type %s is not a pointer" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf83106_000832ca\n"
        ".Lf83106_00083160:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf83106_00083295\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf83106_00083295\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf83106_0008319c\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf83106_0008319c:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf83106_00083267\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf83106_00083267\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf83106_000831d1:\n"
        "leal 1(%ebx), %eax\n" /* line 4738 | index */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %ebx\n" /* index */
        "testl %ebx, %ebx\n" /* index */
        "je .Lf83106_000832c2\n"
        ".Lf83106_000831f5:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "je .Lf83106_00083227\n"
        ".Lf83106_000831fb:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf83106_0008321f\n"
        ".Lf83106_00083204:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf83106_0008321f:\n"
        "xorl %eax, %eax\n" /* line 4740 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf83106_00083227:\n"
        "movl imp_scrCompilePub, %eax\n" /* line 221 */
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf83106_000831fb\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf83106_00083255\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf83106_00083255:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf83106_00083267\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf83106_00083204\n"
        ".Lf83106_00083267:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf83106_00083286:\n"
        "movl (%edx), %eax\n" /* line 4733 */
        "movl %eax, 8(%ebp)\n" /* index */
        "addl $0x14, %esp\n" /* line 4740 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp GetVarType\n" /* line 4733 */
        ".Lf83106_00083295:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf83106_000831d1\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf83106_000831d1\n"
        ".Lf83106_000832c2:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf83106_000831f5\n"
        ".Lf83106_000832ca:\n"
        "movl %eax, 0x10(%ecx)\n"
        "jmp .Lf83106_00083160\n"
    );
}

/* line 4718 */
__attribute__((naked))
const char * Scr_GetTypeName(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4718 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* index */
        "cmpl %eax, scrVmPub+28\n" /* line 4720 */
        "jbe .Lf832d2_000832fe\n"
        "leal (, %eax, 8), %edx\n" /* line 4721 */
        "movl scrVmPub+16, %eax\n"
        "subl %edx, %eax\n"
        "movl 4(%eax), %edx\n"
        "movl imp_var_typename, %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "leave\n" /* line 4725 */
        "retl\n"
        ".Lf832d2_000832fe:\n"
        "addl $1, %eax\n" /* line 4723 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf832d2_000833af\n"
        ".Lf832d2_00083322:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf832d2_00083387\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf832d2_00083387\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf832d2_00083356\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf832d2_00083356:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf832d2_00083368\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf832d2_00083390\n"
        ".Lf832d2_00083368:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf832d2_00083387:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf832d2_000833ab\n"
        ".Lf832d2_00083390:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf832d2_000833ab:\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 4725 */
        "retl\n"
        ".Lf832d2_000833af:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf832d2_00083322\n"
    );
}

/* line 4708 */
__attribute__((naked))
int Scr_GetType(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4708 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* index */
        "cmpl %eax, scrVmPub+28\n" /* line 4710 */
        "jbe .Lf833b8_000833dc\n"
        "leal (, %eax, 8), %edx\n" /* line 4711 */
        "movl scrVmPub+16, %eax\n"
        "subl %edx, %eax\n"
        "movl 4(%eax), %eax\n"
        "leave\n" /* line 4715 */
        "retl\n"
        ".Lf833b8_000833dc:\n"
        "addl $1, %eax\n" /* line 4713 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf833b8_0008346a\n"
        ".Lf833b8_000833fc:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf833b8_00083444\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf833b8_00083444\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf833b8_0008346f\n"
        ".Lf833b8_00083413:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf833b8_0008348e\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf833b8_0008348e\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf833b8_00083440:\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 4715 */
        "retl\n"
        ".Lf833b8_00083444:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf833b8_00083440\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf833b8_00083440\n"
        ".Lf833b8_0008346a:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf833b8_000833fc\n"
        ".Lf833b8_0008346f:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf833b8_00083413\n"
        ".Lf833b8_0008348e:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
    );
}

/* line 4691 */
__attribute__((naked))
unsigned int Scr_GetObject(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4691 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* index */
        /* { scope 1 */
        "cmpl %ecx, scrVmPub+28\n" /* line 4695 */
        "jbe .Lf834ae_00083666\n"
        "leal (, %ecx, 8), %eax\n" /* line 4697 */
        "movl scrVmPub+16, %edx\n"
        "subl %eax, %edx\n"
        "cmpl $1, 4(%edx)\n" /* line 4698 */
        "je .Lf834ae_000835fe\n"
        "leal 1(%ecx), %esi\n" /* line 4700 */
        "movl imp_scrVarPub, %ebx\n"
        "movl %esi, 0x14(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 4701 */
        "movl imp_var_typename, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ce2c, (%esp)\n" /* "type %s is not an object" */
        "calll va\n"
        "movl 0x10(%ebx), %edx\n" /* line 4922 */
        "testl %edx, %edx\n"
        "je .Lf834ae_00083692\n"
        ".Lf834ae_00083511:\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 221 */
        "jne .Lf834ae_00083607\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf834ae_00083607\n"
        "cmpb $0, 0xa(%ebx)\n" /* line 243 */
        "jne .Lf834ae_0008369a\n"
        ".Lf834ae_00083534:\n"
        "movl scrVmPub+8, %ecx\n" /* line 248 */
        "testl %ecx, %ecx\n"
        "jne .Lf834ae_000835df\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf834ae_000835df\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf834ae_0008356f:\n"
        "movl %esi, 4(%esp)\n" /* line 4703 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf834ae_0008368a\n"
        ".Lf834ae_00083590:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf834ae_00083639\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf834ae_00083639\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf834ae_000835cc\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf834ae_000835cc:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 */
        "testl %ebx, %ebx\n"
        "jne .Lf834ae_000835df\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf834ae_00083642\n"
        ".Lf834ae_000835df:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf834ae_000835fe:\n"
        "movl (%edx), %eax\n" /* line 4699 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 4705 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf834ae_00083607:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf834ae_0008356f\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf834ae_0008356f\n"
        ".Lf834ae_00083639:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf834ae_0008365d\n"
        ".Lf834ae_00083642:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf834ae_0008365d:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 4705 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf834ae_00083666:\n"
        "leal 1(%ecx), %esi\n" /* line 4695 */
        "movl %esi, 4(%esp)\n" /* line 4703 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf834ae_00083590\n"
        ".Lf834ae_0008368a:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf834ae_00083590\n"
        ".Lf834ae_00083692:\n"
        "movl %eax, 0x10(%ebx)\n"
        "jmp .Lf834ae_00083511\n"
        ".Lf834ae_0008369a:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %ebx\n"
        "testl %ebx, %ebx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf834ae_00083534\n"
    );
}

/* line 4664 */
__attribute__((naked))
struct scr_entref_t Scr_GetEntityRef(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4664 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        /* { scope 1 */
        "cmpl %ebx, scrVmPub+28\n" /* line 4670 | index */
        "jbe .Lf836bc_000838df\n"
        "leal (, %ebx, 8), %eax\n" /* line 4672 */
        "movl scrVmPub+16, %esi\n" /* value */
        "subl %eax, %esi\n" /* value */
        "cmpl $1, 4(%esi)\n" /* line 4673 | value */
        "je .Lf836bc_00083797\n"
        "addl $1, %ebx\n" /* index */
        "movl %ebx, -0x1c(%ebp)\n" /* index */
        "movl %ebx, %eax\n" /* index */
        ".Lf836bc_000836f5:\n"
        "movl imp_scrVarPub, %ebx\n" /* line 4681 | index */
        "movl %eax, 0x14(%ebx)\n" /* index */
        "movl 4(%esi), %eax\n" /* line 4682 | value */
        "movl imp_var_typename, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ce48, (%esp)\n" /* "type %s is not an entity" */
        "calll va\n"
        "movl 0x10(%ebx), %edi\n" /* line 4922 | index, id */
        "testl %edi, %edi\n" /* id */
        "je .Lf836bc_000839a9\n"
        ".Lf836bc_00083725:\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 221 */
        "jne .Lf836bc_00083843\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf836bc_00083843\n"
        "cmpb $0, 0xa(%ebx)\n" /* line 243 */
        "je .Lf836bc_00083761\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf836bc_00083761:\n"
        "movl scrVmPub+8, %ecx\n" /* line 248 */
        "testl %ecx, %ecx\n"
        "jne .Lf836bc_00083778\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf836bc_0008384c\n"
        ".Lf836bc_00083778:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf836bc_00083797:\n"
        "movl (%esi), %edi\n" /* line 4675 | value, id */
        "movl %edi, (%esp)\n" /* line 4676 | id */
        "calll GetVarType\n"
        "cmpl $0x15, %eax\n"
        "je .Lf836bc_00083964\n"
        "addl $1, %ebx\n" /* line 4678 | index */
        "movl %ebx, -0x1c(%ebp)\n" /* index */
        "movl imp_scrVarPub, %ebx\n" /* index */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n" /* index */
        "movl %edi, (%esp)\n" /* line 4679 | id */
        "calll GetVarType\n"
        "movl imp_var_typename, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ce48, (%esp)\n" /* "type %s is not an entity" */
        "calll va\n"
        "movl 0x10(%ebx), %ecx\n" /* line 4922 | index */
        "testl %ecx, %ecx\n"
        "je .Lf836bc_000839b1\n"
        ".Lf836bc_000837e8:\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 221 */
        "jne .Lf836bc_00083978\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf836bc_00083978\n"
        "cmpb $0, 0xa(%ebx)\n" /* line 243 */
        "je .Lf836bc_00083824\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf836bc_00083824:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf836bc_00083778\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf836bc_00083778\n"
        "jmp .Lf836bc_00083981\n"
        ".Lf836bc_00083843:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf836bc_0008386c\n"
        ".Lf836bc_0008384c:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf836bc_0008386c:\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n" /* line 4684 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf836bc_00083904\n"
        ".Lf836bc_0008388c:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf836bc_0008389d\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf836bc_00083909\n"
        ".Lf836bc_0008389d:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf836bc_000838c1\n"
        ".Lf836bc_000838a6:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf836bc_000838c1:\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf836bc_000838c5:\n"
        "movl %edx, %eax\n"
        "shll $0x10, %eax\n"
        "andl $0xffff, %ebx\n"
        "orl %eax, %ebx\n"
        "movw %cx, %bx\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 4688 | index */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf836bc_000838df:\n"
        "addl $1, %ebx\n" /* line 4670 | index */
        "movl %ebx, -0x1c(%ebp)\n" /* index */
        "movl %ebx, %eax\n" /* index */
        "movl %eax, 4(%esp)\n" /* line 4684 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf836bc_0008388c\n"
        ".Lf836bc_00083904:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf836bc_0008388c\n"
        ".Lf836bc_00083909:\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf836bc_00083945\n"
        ".Lf836bc_0008390f:\n"
        "movl scrVmPub+8, %esi\n" /* line 248 */
        "testl %esi, %esi\n"
        "jne .Lf836bc_00083778\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf836bc_000838a6\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf836bc_00083945:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edi\n"
        "testl %edi, %edi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf836bc_0008390f\n"
        ".Lf836bc_00083964:\n"
        "movl %edi, (%esp)\n" /* line 4677 | id */
        "calll Scr_GetEntityIdRef\n"
        "movl %eax, %edx\n"
        "shrl $0x10, %edx\n"
        "movl %eax, %ecx\n"
        "jmp .Lf836bc_000838c5\n"
        ".Lf836bc_00083978:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf836bc_000839a1\n"
        ".Lf836bc_00083981:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf836bc_000839a1:\n"
        "movl -0x1c(%ebp), %eax\n"
        "jmp .Lf836bc_000836f5\n"
        ".Lf836bc_000839a9:\n"
        "movl %eax, 0x10(%ebx)\n" /* line 4923 | index */
        "jmp .Lf836bc_00083725\n"
        ".Lf836bc_000839b1:\n"
        "movl %eax, 0x10(%ebx)\n" /* index */
        "jmp .Lf836bc_000837e8\n"
    );
}

/* line 4625 */
__attribute__((naked))
void Scr_GetVector(unsigned int index, float *vectorValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4625 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* index */
        "movl 0xc(%ebp), %ebx\n" /* vectorValue */
        /* { scope 1 */
        "cmpl %ecx, scrVmPub+28\n" /* line 4629 */
        "jbe .Lf839bc_00083b85\n"
        "leal (, %ecx, 8), %eax\n" /* line 4631 */
        "movl scrVmPub+16, %edx\n"
        "subl %eax, %edx\n"
        "cmpl $4, 4(%edx)\n" /* line 4632 */
        "je .Lf839bc_00083b0f\n"
        "leal 1(%ecx), %esi\n" /* line 4637 */
        "movl imp_scrVarPub, %ebx\n" /* vectorValue */
        "movl %esi, 0x14(%ebx)\n" /* vectorValue */
        "movl 4(%edx), %eax\n" /* line 4638 */
        "movl imp_var_typename, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ce64, (%esp)\n" /* "type %s is not a vector" */
        "calll va\n"
        "movl 0x10(%ebx), %edx\n" /* line 4922 | vectorValue */
        "testl %edx, %edx\n"
        "je .Lf839bc_00083bb1\n"
        ".Lf839bc_00083a22:\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 221 */
        "jne .Lf839bc_00083b28\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf839bc_00083b28\n"
        "cmpb $0, 0xa(%ebx)\n" /* line 243 */
        "jne .Lf839bc_00083bb9\n"
        ".Lf839bc_00083a45:\n"
        "movl scrVmPub+8, %ecx\n" /* line 248 */
        "testl %ecx, %ecx\n"
        "jne .Lf839bc_00083af0\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf839bc_00083af0\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf839bc_00083a80:\n"
        "movl %esi, 4(%esp)\n" /* line 4640 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf839bc_00083ba9\n"
        ".Lf839bc_00083aa1:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf839bc_00083b5a\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf839bc_00083b5a\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf839bc_00083add\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf839bc_00083add:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 */
        "testl %ebx, %ebx\n"
        "jne .Lf839bc_00083af0\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf839bc_00083b63\n"
        ".Lf839bc_00083af0:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf839bc_00083b0f:\n"
        "movl (%edx), %edx\n" /* line 4634 | from */
        /* { scope 2 */
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        /* } scope */
        ".Lf839bc_00083b21:\n"
        "addl $0x10, %esp\n" /* line 4641 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf839bc_00083b28:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf839bc_00083a80\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf839bc_00083a80\n"
        ".Lf839bc_00083b5a:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf839bc_00083b21\n"
        ".Lf839bc_00083b63:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 4641 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf839bc_00083b85:\n"
        "leal 1(%ecx), %esi\n" /* line 4629 */
        "movl %esi, 4(%esp)\n" /* line 4640 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf839bc_00083aa1\n"
        ".Lf839bc_00083ba9:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf839bc_00083aa1\n"
        ".Lf839bc_00083bb1:\n"
        "movl %eax, 0x10(%ebx)\n" /* vectorValue */
        "jmp .Lf839bc_00083a22\n"
        ".Lf839bc_00083bb9:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %ebx\n"
        "testl %ebx, %ebx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf839bc_00083a45\n"
    );
}

/* line 4586 */
__attribute__((naked))
const char * Scr_GetDebugString(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4586 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* index */
        /* { scope 1 */
        "cmpl %eax, scrVmPub+28\n" /* line 4590 */
        "jbe .Lf83bde_00083c12\n"
        "shll $3, %eax\n" /* line 4592 */
        "movl scrVmPub+16, %ebx\n" /* value */
        "subl %eax, %ebx\n" /* value */
        "movl %ebx, (%esp)\n" /* line 4593 | value */
        "calll Scr_CastDebugString\n"
        "movl (%ebx), %eax\n" /* line 4595 | value */
        "movl %eax, 8(%ebp)\n" /* index */
        /* } scope */
        "addl $0x14, %esp\n" /* line 4599 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SL_ConvertToString\n" /* line 4595 */
        ".Lf83bde_00083c12:\n"
        "addl $1, %eax\n" /* line 4597 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %ebx\n" /* value */
        "testl %ebx, %ebx\n" /* value */
        "je .Lf83bde_00083cca\n"
        ".Lf83bde_00083c36:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf83bde_00083c47\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf83bde_00083c73\n"
        ".Lf83bde_00083c47:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf83bde_00083c6b\n"
        ".Lf83bde_00083c50:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf83bde_00083c6b:\n"
        "xorl %eax, %eax\n" /* line 4599 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf83bde_00083c73:\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf83bde_00083cab\n"
        ".Lf83bde_00083c79:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 */
        "testl %ebx, %ebx\n"
        "jne .Lf83bde_00083c8c\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf83bde_00083c50\n"
        ".Lf83bde_00083c8c:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf83bde_00083cab:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf83bde_00083c79\n"
        ".Lf83bde_00083cca:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf83bde_00083c36\n"
    );
}

/* line 4477 */
__attribute__((naked))
float Scr_GetFloat(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4477 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ecx\n" /* index */
        /* { scope 1 */
        "cmpl %ecx, scrVmPub+28\n" /* line 4481 */
        "jbe .Lf83cd2_00083d21\n"
        "leal (, %ecx, 8), %eax\n" /* line 4483 */
        "movl scrVmPub+16, %edx\n"
        "subl %eax, %edx\n"
        "movl 4(%edx), %eax\n" /* line 4484 */
        "cmpl $5, %eax\n"
        "je .Lf83cd2_00083d18\n"
        "cmpl $6, %eax\n" /* line 4486 */
        "jne .Lf83cd2_00083dd8\n"
        "cvtsi2ssl (%edx), %xmm0\n" /* line 4487 */
        "movss %xmm0, -0xc(%ebp)\n"
        "flds -0xc(%ebp)\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 4494 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf83cd2_00083d18:\n"
        "flds (%edx)\n" /* line 4485 */
        /* } scope */
        "addl $0x20, %esp\n" /* line 4494 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf83cd2_00083d21:\n"
        "leal 1(%ecx), %ebx\n" /* line 4481 */
        ".Lf83cd2_00083d24:\n"
        "movl %ebx, 4(%esp)\n" /* line 4492 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf83cd2_00083e71\n"
        ".Lf83cd2_00083d45:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf83cd2_00083dab\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf83cd2_00083dab\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf83cd2_00083d79\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf83cd2_00083d79:\n"
        "movl scrVmPub+8, %esi\n" /* line 248 */
        "testl %esi, %esi\n"
        "jne .Lf83cd2_00083d8c\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf83cd2_00083db4\n"
        ".Lf83cd2_00083d8c:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf83cd2_00083dab:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf83cd2_00083dcf\n"
        ".Lf83cd2_00083db4:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf83cd2_00083dcf:\n"
        "fldz\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 4494 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf83cd2_00083dd8:\n"
        "leal 1(%ecx), %ebx\n" /* line 4489 */
        "movl imp_scrVarPub, %esi\n"
        "movl %ebx, 0x14(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 4490 */
        "movl imp_var_typename, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cea0, (%esp)\n" /* "type %s is not a float" */
        "calll va\n"
        "movl 0x10(%esi), %ecx\n" /* line 4922 */
        "testl %ecx, %ecx\n"
        "je .Lf83cd2_00083e98\n"
        ".Lf83cd2_00083e0b:\n"
        "cmpb $0, 0xc(%esi)\n" /* line 221 */
        "je .Lf83cd2_00083e43\n"
        ".Lf83cd2_00083e11:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf83cd2_00083d24\n"
        ".Lf83cd2_00083e1e:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf83cd2_00083d24\n"
        ".Lf83cd2_00083e43:\n"
        "movl imp_scrCompilePub, %eax\n" /* line 221 */
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf83cd2_00083e11\n"
        "cmpb $0, 0xa(%esi)\n" /* line 243 */
        "jne .Lf83cd2_00083e79\n"
        ".Lf83cd2_00083e54:\n"
        "movl scrVmPub+8, %esi\n" /* line 248 */
        "testl %esi, %esi\n"
        "jne .Lf83cd2_00083d8c\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf83cd2_00083d8c\n"
        "jmp .Lf83cd2_00083e1e\n"
        ".Lf83cd2_00083e71:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf83cd2_00083d45\n"
        ".Lf83cd2_00083e79:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf83cd2_00083e54\n"
        ".Lf83cd2_00083e98:\n"
        "movl %eax, 0x10(%esi)\n" /* line 4923 */
        "jmp .Lf83cd2_00083e0b\n"
    );
}

/* line 4394 */
__attribute__((naked))
int Scr_GetInt(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4394 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* index */
        /* { scope 1 */
        "cmpl %ecx, scrVmPub+28\n" /* line 4398 */
        "jbe .Lf83ea0_00084058\n"
        "leal (, %ecx, 8), %eax\n" /* line 4400 */
        "movl scrVmPub+16, %edx\n"
        "subl %eax, %edx\n"
        "cmpl $6, 4(%edx)\n" /* line 4401 */
        "je .Lf83ea0_00083ff0\n"
        "leal 1(%ecx), %esi\n" /* line 4403 */
        "movl imp_scrVarPub, %ebx\n"
        "movl %esi, 0x14(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 4404 */
        "movl imp_var_typename, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ceb8, (%esp)\n" /* "type %s is not an int" */
        "calll va\n"
        "movl 0x10(%ebx), %edx\n" /* line 4922 */
        "testl %edx, %edx\n"
        "je .Lf83ea0_00084084\n"
        ".Lf83ea0_00083f03:\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 221 */
        "jne .Lf83ea0_00083ff9\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf83ea0_00083ff9\n"
        "cmpb $0, 0xa(%ebx)\n" /* line 243 */
        "jne .Lf83ea0_0008408c\n"
        ".Lf83ea0_00083f26:\n"
        "movl scrVmPub+8, %ecx\n" /* line 248 */
        "testl %ecx, %ecx\n"
        "jne .Lf83ea0_00083fd1\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf83ea0_00083fd1\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf83ea0_00083f61:\n"
        "movl %esi, 4(%esp)\n" /* line 4406 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf83ea0_0008407c\n"
        ".Lf83ea0_00083f82:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf83ea0_0008402b\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf83ea0_0008402b\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf83ea0_00083fbe\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf83ea0_00083fbe:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 */
        "testl %ebx, %ebx\n"
        "jne .Lf83ea0_00083fd1\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf83ea0_00084034\n"
        ".Lf83ea0_00083fd1:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf83ea0_00083ff0:\n"
        "movl (%edx), %eax\n" /* line 4402 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 4408 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf83ea0_00083ff9:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf83ea0_00083f61\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf83ea0_00083f61\n"
        ".Lf83ea0_0008402b:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf83ea0_0008404f\n"
        ".Lf83ea0_00084034:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf83ea0_0008404f:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 4408 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf83ea0_00084058:\n"
        "leal 1(%ecx), %esi\n" /* line 4398 */
        "movl %esi, 4(%esp)\n" /* line 4406 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf83ea0_00083f82\n"
        ".Lf83ea0_0008407c:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf83ea0_00083f82\n"
        ".Lf83ea0_00084084:\n"
        "movl %eax, 0x10(%ebx)\n"
        "jmp .Lf83ea0_00083f03\n"
        ".Lf83ea0_0008408c:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %ebx\n"
        "testl %ebx, %ebx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf83ea0_00083f26\n"
    );
}

/* line 332 */
static __attribute__((naked))
unsigned int VM_Execute(struct function_stack_t fs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 332 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl g_script_error_level, %eax\n" /* line 380 */
        "addl $1, %eax\n"
        "movl %eax, g_script_error_level\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 384 */
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll setjmp\n"
        "testl %eax, %eax\n"
        "jne .Lf840ae_00086a6e\n"
        "movl $0, -0x48(%ebp)\n" /* fieldValueId */
        "movl $0, -0x44(%ebp)\n" /* objectId */
        "movl $0, -0x40(%ebp)\n" /* waitTime */
        "movl $0, -0x38(%ebp)\n" /* caseCount */
        "movl $0, -0x34(%ebp)\n" /* caseValue */
        "movl $0, -0x30(%ebp)\n" /* currentCaseValue */
        "movl $0, -0x2c(%ebp)\n" /* currentCodePos */
        "movl $0, -0x3c(%ebp)\n" /* thread_count */
        ".Lf840ae_00084116:\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        ".Lf840ae_00084119:\n"
        "movzbl (%ecx), %edi\n" /* line 401 | opcode */
        "leal 1(%ecx), %esi\n" /* line 402 | builtinIndex */
        "movl %esi, 8(%ebp)\n" /* builtinIndex, fs */
        "cmpl $0x86, %edi\n" /* line 412 | opcode */
        "ja .Lf840ae_00084155\n"
        ".Lf840ae_0008412a:\n"
        "jmpl *.Ljt_840ae_0(, %edi, 4)\n"
        ".Lf840ae_00084131:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1676 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $8, 4(%eax)\n" /* line 1678 */
        "movl 8(%ebp), %ecx\n" /* fs */
        "movzbl (%ecx), %edi\n" /* line 401 | opcode */
        "leal 1(%ecx), %esi\n" /* line 402 | builtinIndex */
        "movl %esi, 8(%ebp)\n" /* builtinIndex, fs */
        "cmpl $0x86, %edi\n" /* line 412 | opcode */
        "jbe .Lf840ae_0008412a\n"
        ".Lf840ae_00084155:\n"
        "movl 0x18(%ebp), %edx\n"
        "jmp .Lf840ae_000849a4\n"
        ".Lf840ae_0008415d:\n"
        "movzbl (%esi), %eax\n" /* line 1011 | builtinIndex */
        "movl %eax, scrVmPub+28\n"
        "addl $1, 8(%ebp)\n" /* line 1012 | fs */
        ".Lf840ae_00084169:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1019 */
        "leal -8(%ecx), %eax\n"
        "movl %eax, scrVmPub+16\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, %esi\n" /* line 1020 | builtinIndex */
        "cmpl $1, 4(%ecx)\n" /* line 1022 */
        "je .Lf840ae_00085c23\n"
        ".Lf840ae_0008418c:\n"
        "movl %ecx, %eax\n"
        ".Lf840ae_0008418e:\n"
        "movl 4(%eax), %ebx\n" /* line 1056 | parentLocalId */
        "movl (%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* result */
        "calll RemoveRefToValue\n"
        "movl imp_scrVarPub, %esi\n" /* line 1058 | builtinIndex */
        "movl $0xffffffff, 0x14(%esi)\n" /* builtinIndex */
        "movl imp_var_typename, %eax\n" /* line 1059 */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cefc, (%esp)\n" /* "%s is not an entity" */
        "calll va\n"
        "movl 0x10(%esi), %edi\n" /* line 4922 | builtinIndex, opcode */
        "testl %edi, %edi\n" /* opcode */
        "je .Lf840ae_000861dd\n"
        ".Lf840ae_000841cf:\n"
        "cmpb $0, 0xc(%esi)\n" /* line 221 */
        "jne .Lf840ae_000841e4\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086184\n"
        ".Lf840ae_000841e4:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_0008420d\n"
        ".Lf840ae_000841ed:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_0008420d:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1064 */
        "movl 4(%eax), %edx\n"
        "cmpl $5, %edx\n"
        "je .Lf840ae_00086101\n"
        "cmpl $6, %edx\n" /* line 1072 */
        "jne .Lf840ae_00086087\n"
        "movl (%eax), %eax\n" /* line 1074 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* waitTime */
        ".Lf840ae_00084230:\n"
        "cmpl $g_effectVisArray+4350, %eax\n" /* line 1082 */
        "ja .Lf840ae_000843dd\n"
        "movl -0x40(%ebp), %edi\n" /* line 1084 | waitTime, opcode */
        "testl %edi, %edi\n" /* opcode */
        "je .Lf840ae_0008424f\n"
        "rdtsc\n" /* line 33 */
        "xorl %edx, %edx\n" /* line 5102 */
        "shrdl $2, %edx, %eax\n"
        "movl %eax, scrVmGlob+24\n"
        ".Lf840ae_0008424f:\n"
        "movl imp_scrVarPub, %ebx\n" /* line 1086 | parentLocalId */
        "movl 0x18(%ebx), %eax\n" /* parentLocalId */
        "addl %eax, -0x40(%ebp)\n" /* waitTime */
        "andl $g_effectVisArray+4351, -0x40(%ebp)\n" /* waitTime */
        "movl 0x14(%ebp), %ecx\n" /* line 1087 */
        "subl $8, %ecx\n"
        "movl %ecx, 0x14(%ebp)\n"
        "movl $0xa, -0x24(%ebp)\n" /* line 1093 */
        "movl %ecx, %eax\n" /* line 1094 */
        "subl 0x18(%ebp), %eax\n"
        "sarl $3, %eax\n"
        "leal 0xc(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "movl 8(%ebp), %edx\n" /* fs */
        "calll VM_ArchiveStack\n"
        "movl %eax, -0x28(%ebp)\n" /* stackValue */
        "movl -0x40(%ebp), %edx\n" /* line 1096 | waitTime */
        "movl %edx, 4(%esp)\n"
        "movl 0x1c(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl 0xc(%ebp), %edx\n" /* line 1098 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll GetNewObjectVariable\n"
        "leal -0x28(%ebp), %edx\n" /* line 1099 | stackValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        "movl -0x40(%ebp), %eax\n" /* line 1101 | waitTime */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetThreadWaitTime\n"
        ".Lf840ae_000842dc:\n"
        "movl 0x18(%ebp), %eax\n" /* line 1865 */
        "movl $0, 0xc(%eax)\n"
        "movl -0x3c(%ebp), %edi\n" /* line 1873 | thread_count, opcode */
        "testl %edi, %edi\n" /* opcode */
        "je .Lf840ae_0008451c\n"
        ".Lf840ae_000842f1:\n"
        "subl $1, -0x3c(%ebp)\n" /* line 1885 | thread_count */
        "movl 0xc(%ebp), %eax\n" /* line 1886 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl scrVmPub+12, %edx\n" /* line 1887 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x10(%ebp)\n"
        "movl 0xc(%edx), %ecx\n"
        "movl %ecx, 0x14(%ebp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x18(%ebp)\n"
        "movl 0x14(%edx), %eax\n" /* line 1888 */
        "movl %eax, 4(%ecx)\n"
        "addl $8, 0x14(%ebp)\n" /* line 1889 */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084335:\n"
        "movzbl (%esi), %eax\n" /* line 928 | builtinIndex */
        "movl %eax, scrVmPub+28\n"
        "addl $1, 8(%ebp)\n" /* line 929 | fs */
        ".Lf840ae_00084341:\n"
        "movl 0x14(%ebp), %eax\n" /* line 936 */
        "movl %eax, scrVmPub+16\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %ecx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl scrVmPub+12, %edx\n" /* line 938 */
        "movl %eax, (%edx)\n"
        "movl imp_scrCompilePub, %eax\n" /* line 946 */
        "calll *0x38(%eax, %ecx, 4)\n"
        ".Lf840ae_00084366:\n"
        "movl scrVmPub+16, %edx\n" /* line 950 */
        "movl %edx, 0x14(%ebp)\n"
        "movl scrVmPub+12, %eax\n" /* line 951 */
        "movl (%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl scrVmPub+28, %esi\n" /* line 952 | builtinIndex */
        "testl %esi, %esi\n" /* builtinIndex */
        "je .Lf840ae_000843bd\n"
        "movl $0, scrVmPub+28\n" /* line 955 */
        "leal (, %esi, 8), %eax\n" /* line 956 */
        "subl %eax, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "xorl %ebx, %ebx\n" /* parentLocalId */
        ".Lf840ae_0008439e:\n"
        "movl 0x14(%ebp), %eax\n" /* line 959 | value */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 252 */
        "movl %edx, 4(%esp)\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        /* } scope */
        "subl $8, 0x14(%ebp)\n" /* line 960 */
        "addl $1, %ebx\n" /* parentLocalId */
        "cmpl %ebx, %esi\n" /* line 957 | parentLocalId, builtinIndex */
        "jne .Lf840ae_0008439e\n"
        ".Lf840ae_000843bd:\n"
        "movl scrVmPub+24, %ebx\n" /* line 964 | parentLocalId */
        "testl %ebx, %ebx\n" /* parentLocalId */
        "je .Lf840ae_0008452e\n"
        "movl $0, scrVmPub+24\n" /* line 967 */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000843dd:\n"
        "movl imp_scrVarPub, %edx\n" /* line 1105 */
        "movl $2, 0x14(%edx)\n"
        "movl -0x40(%ebp), %ebx\n" /* line 1106 | waitTime, parentLocalId */
        "testl %ebx, %ebx\n" /* parentLocalId */
        "js .Lf840ae_00084444\n"
        "movl 0x10(%edx), %ecx\n" /* line 4922 */
        "testl %ecx, %ecx\n"
        "je .Lf840ae_00086492\n"
        ".Lf840ae_000843fc:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00084411\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086263\n"
        ".Lf840ae_00084411:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00086167\n"
        ".Lf840ae_0008441e:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl imp_scrVarPub, %edx\n"
        ".Lf840ae_00084444:\n"
        "movl 0x10(%edx), %edi\n" /* line 4922 | opcode */
        "testl %edi, %edi\n" /* opcode */
        "je .Lf840ae_00086178\n"
        ".Lf840ae_0008444f:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00084464\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_000861e5\n"
        ".Lf840ae_00084464:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_0008448d\n"
        ".Lf840ae_0008446d:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_0008448d:\n"
        "movl $0xa, -0x24(%ebp)\n" /* line 1120 */
        "movl 0x14(%ebp), %ecx\n" /* line 1121 */
        "movl %ecx, %eax\n"
        "subl 0x18(%ebp), %eax\n"
        "sarl $3, %eax\n"
        "leal 0xc(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "movl 8(%ebp), %edx\n" /* fs */
        "calll VM_ArchiveStack\n"
        "movl %eax, -0x28(%ebp)\n" /* stackValue */
        "movl imp_scrVarPub, %ebx\n" /* line 1123 | parentLocalId */
        "movl 0x18(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl 0xc(%ebp), %edx\n" /* line 1125 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll GetNewObjectVariableReverse\n"
        "leal -0x28(%ebp), %edx\n" /* line 1126 | stackValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        "movl 0x18(%ebx), %eax\n" /* line 1128 | parentLocalId */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetThreadWaitTime\n"
        "movl 0x18(%ebp), %eax\n" /* line 1865 */
        "movl $0, 0xc(%eax)\n"
        "movl -0x3c(%ebp), %edi\n" /* line 1873 | thread_count, opcode */
        "testl %edi, %edi\n" /* opcode */
        "jne .Lf840ae_000842f1\n"
        ".Lf840ae_0008451c:\n"
        "subl $1, g_script_error_level\n" /* line 1876 */
        "movl 0xc(%ebp), %eax\n" /* line 1878 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2248 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf840ae_0008452e:\n"
        "movl 0x14(%ebp), %eax\n" /* line 974 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $0, 4(%eax)\n" /* line 975 */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084546:\n"
        "movl imp_scrVarPub, %eax\n" /* line 779 */
        "movl 0x2c(%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        /* { scope 2 */
        ".Lf840ae_00084551:\n"
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, 4(%esp)\n" /* line 788 */
        "movl -0x44(%ebp), %edx\n" /* objectId */
        "movl %edx, (%esp)\n"
        "calll Scr_GetVariableField\n"
        "movl %eax, -0x48(%ebp)\n" /* fieldValueId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084577:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1140 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $8, 4(%eax)\n" /* line 1142 */
        ".Lf840ae_00084587:\n"
        "cmpl $0x1e, scrVmPub+8\n" /* line 1146 */
        "jle .Lf840ae_000862da\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf840ae_000866d2\n"
        ".Lf840ae_000845a5:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_000845ba\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_000865ce\n"
        ".Lf840ae_000845ba:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_000845e3\n"
        ".Lf840ae_000845c3:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_000845e3:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1159 */
        "cmpl $9, 4(%eax)\n"
        "jne .Lf840ae_00084652\n"
        "cmpl $0x1e, scrVmPub+8\n" /* line 1161 */
        "jle .Lf840ae_000865f7\n"
        "movl imp_scrVarPub, %edx\n" /* line 1172 */
        "movl $1, 0x14(%edx)\n"
        "movl 0x10(%edx), %eax\n" /* line 4922 */
        "testl %eax, %eax\n"
        "je .Lf840ae_000869ea\n"
        ".Lf840ae_00084611:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00084626\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086774\n"
        ".Lf840ae_00084626:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_0008464f\n"
        ".Lf840ae_0008462f:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_0008464f:\n"
        "movl 0x14(%ebp), %eax\n"
        ".Lf840ae_00084652:\n"
        "movl 4(%eax), %edx\n" /* line 1176 */
        "movl imp_var_typename, %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cf80, (%esp)\n" /* "%s is not a function pointer" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf840ae_000864ec\n"
        ".Lf840ae_0008467e:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00084693\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086338\n"
        ".Lf840ae_00084693:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_000846bc\n"
        ".Lf840ae_0008469c:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_000846bc:\n"
        "movl 0x14(%ebp), %edx\n" /* line 1179 */
        "cmpl $1, 4(%edx)\n"
        "jne .Lf840ae_00086e60\n"
        "cmpl $0x1e, scrVmPub+8\n" /* line 1181 */
        "jg .Lf840ae_00086e0e\n"
        "movl 0xc(%ebp), %eax\n" /* line 1183 */
        "movl %eax, 4(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AllocChildThread\n"
        "movl %eax, 0xc(%ebp)\n"
        "subl $8, 0x14(%ebp)\n" /* line 1184 */
        ".Lf840ae_000846ee:\n"
        "movl 8(%ebp), %edx\n" /* line 1185 | fs */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "movl scrVmPub+12, %edx\n" /* line 1186 */
        /* { scope 2 */
        /* { scope 3 */
        "movl (%edx), %eax\n" /* line 156 */
        "movl (%eax), %ecx\n"
        "addl $4, %eax\n" /* line 157 */
        "movl %eax, (%edx)\n"
        /* } scope */
        /* } scope */
        "movl %ecx, 8(%ebp)\n" /* line 1186 | fs */
        ".Lf840ae_0008470a:\n"
        "movl 0x10(%ebp), %edx\n" /* line 1856 */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, 8(%eax)\n"
        "movl $0, 0x10(%ebp)\n" /* line 1857 */
        "addl $1, scrVmPub+8\n" /* line 1858 */
        "movl scrVmPub+12, %edx\n" /* line 1859 */
        "addl $0x18, %edx\n"
        "movl %edx, scrVmPub+12\n"
        "movl 0xc(%ebp), %eax\n" /* line 1860 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084740:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 1219 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 0xc(%eax), %edx\n" /* line 1220 */
        "movl imp_var_typename, %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cf80, (%esp)\n" /* "%s is not a function pointer" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf840ae_00086b0f\n"
        ".Lf840ae_00084783:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00086306\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf840ae_00086306\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_000847bf\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_000847bf:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_000847fa:\n"
        "cmpl $0x1e, scrVmPub+8\n" /* line 1223 */
        "jle .Lf840ae_0008649e\n"
        "movl imp_scrVarPub, %edx\n" /* line 1235 */
        "movl $1, 0x14(%edx)\n"
        "movl 0x10(%edx), %ecx\n" /* line 4922 */
        "testl %ecx, %ecx\n"
        "je .Lf840ae_000869b7\n"
        ".Lf840ae_0008481f:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00084834\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_000866e6\n"
        ".Lf840ae_00084834:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_0008485d\n"
        ".Lf840ae_0008483d:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_0008485d:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1239 */
        "cmpl $9, 4(%eax)\n"
        "jne .Lf840ae_000848cc\n"
        "cmpl $0x1e, scrVmPub+8\n" /* line 1241 */
        "jle .Lf840ae_00086651\n"
        "movl imp_scrVarPub, %edx\n" /* line 1255 */
        "movl $1, 0x14(%edx)\n"
        "movl 0x10(%edx), %eax\n" /* line 4922 */
        "testl %eax, %eax\n"
        "je .Lf840ae_00086a56\n"
        ".Lf840ae_0008488b:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_000848a0\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086879\n"
        ".Lf840ae_000848a0:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_000848c9\n"
        ".Lf840ae_000848a9:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_000848c9:\n"
        "movl 0x14(%ebp), %eax\n"
        ".Lf840ae_000848cc:\n"
        "movl 4(%eax), %edx\n" /* line 1259 */
        "movl imp_var_typename, %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cf80, (%esp)\n" /* "%s is not a function pointer" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf840ae_00086649\n"
        ".Lf840ae_000848f8:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_0008490d\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_000864c3\n"
        ".Lf840ae_0008490d:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00084936\n"
        ".Lf840ae_00084916:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00084936:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1262 */
        "cmpl $1, 4(%eax)\n"
        "jne .Lf840ae_00086bf4\n"
        "cmpl $0x1e, scrVmPub+8\n" /* line 1264 */
        "jg .Lf840ae_00086b9b\n"
        "movl (%eax), %eax\n" /* line 1266 */
        "movl %eax, (%esp)\n"
        "calll AllocThread\n"
        "movl %eax, 0xc(%ebp)\n"
        "subl $8, 0x14(%ebp)\n" /* line 1267 */
        ".Lf840ae_00084961:\n"
        "movl 8(%ebp), %edx\n" /* line 1268 | fs */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 1269 */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, 0x10(%eax)\n"
        "movl scrVmPub+12, %edx\n" /* line 1270 */
        /* { scope 2 */
        /* { scope 3 */
        "movl (%edx), %eax\n" /* line 156 */
        "movl (%eax), %ecx\n"
        "addl $4, %eax\n" /* line 157 */
        "movl %eax, (%edx)\n"
        /* } scope */
        /* } scope */
        "movl %ecx, 8(%ebp)\n" /* line 1270 | fs */
        "movl 0x14(%ebp), %ecx\n" /* line 1271 */
        ".Lf840ae_0008498b:\n"
        "movl scrVmPub+12, %ebx\n" /* line 1295 | pos */
        /* { scope 2 */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 156 | result */
        "movl (%eax), %edx\n"
        "addl $4, %eax\n" /* line 157 */
        "movl %eax, (%ebx)\n" /* result */
        /* } scope */
        /* } scope */
        "shll $3, %edx\n" /* line 1295 */
        "subl %edx, %ecx\n"
        "movl %ecx, 0x18(%ebp)\n"
        "movl %ecx, %edx\n"
        ".Lf840ae_000849a4:\n"
        "movl scrVmPub+12, %eax\n" /* line 1840 */
        "movl %edx, 0xc(%eax)\n"
        "movl 4(%edx), %edx\n" /* line 1841 */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, 0x14(%eax)\n"
        "movl 0x18(%ebp), %eax\n" /* line 1842 */
        "movl $8, 4(%eax)\n"
        "addl $1, -0x3c(%ebp)\n" /* line 1843 | thread_count */
        "jmp .Lf840ae_0008470a\n"
        ".Lf840ae_000849ca:\n"
        "movzbl (%esi), %eax\n" /* line 126 */
        "shll $2, %eax\n"
        "movl scrVmPub, %edx\n"
        "subl %eax, %edx\n"
        "movl (%edx), %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* fieldValueId */
        ".Lf840ae_000849dd:\n"
        "leal 2(%ecx), %eax\n" /* line 866 */
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl %eax, %ecx\n"
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000849ea:\n"
        "movl scrVmPub, %ebx\n" /* line 796 | parentLocalId */
        "leal 4(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, scrVmPub\n"
        "addl $1, 0x10(%ebp)\n" /* line 797 */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, 4(%esp)\n" /* line 798 */
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetNewVariable\n"
        "movl %eax, 4(%ebx)\n" /* parentLocalId */
        ".Lf840ae_00084a1a:\n"
        "movl 0x14(%ebp), %eax\n" /* line 803 */
        "cmpl $8, 4(%eax)\n"
        "je .Lf840ae_00084116\n"
        ".Lf840ae_00084a27:\n"
        "movl %eax, 4(%esp)\n" /* line 889 */
        "movl scrVmPub, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        ".Lf840ae_00084a3a:\n"
        "subl $8, 0x14(%ebp)\n" /* line 2136 */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084a46:\n"
        "movl 0xc(%ebp), %eax\n" /* line 756 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetSelf\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "movl %eax, (%esp)\n" /* line 757 */
        "calll IsFieldObject\n"
        "testb %al, %al\n"
        "je .Lf840ae_00086f27\n"
        ".Lf840ae_00084a64:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 769 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, 4(%esp)\n" /* line 771 */
        "movl -0x44(%ebp), %eax\n" /* objectId */
        "movl %eax, (%esp)\n"
        "calll Scr_FindVariableField\n"
        "movl %eax, 8(%ebx)\n" /* parentLocalId */
        "movl %edx, 0xc(%ebx)\n" /* parentLocalId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084a96:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 699 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 701 | fs */
        "movzbl (%eax), %edx\n"
        "shll $2, %edx\n"
        "movl scrVmPub, %eax\n"
        "subl %edx, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalVariable\n"
        "movl %eax, 8(%ebx)\n" /* parentLocalId */
        "movl %edx, 0xc(%ebx)\n" /* parentLocalId */
        "addl $1, 8(%ebp)\n" /* line 702 | fs */
        ".Lf840ae_00084ac3:\n"
        "movl 0x14(%ebp), %edx\n" /* line 706 */
        "leal -8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Scr_EvalArray\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00084ada:\n"
        "movl imp_var_typename, %eax\n" /* line 1465 */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d07c, (%esp)\n" /* "-- must be applied to an int (applied to %s)" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf840ae_00086a4e\n"
        ".Lf840ae_00084b03:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00084b18\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086731\n"
        ".Lf840ae_00084b18:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00084b41\n"
        ".Lf840ae_00084b21:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00084b41:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1468 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalOr\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00084b58:\n"
        "movl 0x14(%ebp), %eax\n" /* line 823 */
        "cmpl $7, 4(%eax)\n"
        "jne .Lf840ae_0008533e\n"
        "movzbl (%esi), %eax\n" /* line 829 | builtinIndex */
        "shll $2, %eax\n"
        "movl scrVmPub, %edx\n"
        "subl %eax, %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ClearVariableValue\n"
        ".Lf840ae_00084b7d:\n"
        "addl $1, 8(%ebp)\n" /* line 830 | fs */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084b89:\n"
        "movl imp_var_typename, %eax\n" /* line 1451 */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d04c, (%esp)\n" /* "++ must be applied to an int (applied to %s)" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %edi\n" /* opcode */
        "testl %edi, %edi\n" /* opcode */
        "je .Lf840ae_00086b2b\n"
        ".Lf840ae_00084bb2:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00084bc7\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086952\n"
        ".Lf840ae_00084bc7:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00084bf0\n"
        ".Lf840ae_00084bd0:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00084bf0:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1455 | pos */
        "leal 8(%ebx), %eax\n" /* pos */
        "movl %eax, 0x14(%ebp)\n"
        "movl -0x48(%ebp), %eax\n" /* line 1457 | fieldValueId */
        "movl %eax, (%esp)\n"
        "calll Scr_EvalVariableField\n"
        "movl %eax, 8(%ebx)\n" /* pos */
        "movl %edx, 0xc(%ebx)\n" /* pos */
        "movl 0x14(%ebp), %eax\n" /* line 1458 */
        "movl 4(%eax), %edx\n"
        "cmpl $6, %edx\n"
        "jne .Lf840ae_00084ada\n"
        "subl $1, (%eax)\n" /* line 1460 */
        "addl $1, 8(%ebp)\n" /* line 1462 | fs */
        ".Lf840ae_00084c20:\n"
        "movl -0x48(%ebp), %edx\n" /* fieldValueId */
        ".Lf840ae_00084c23:\n"
        "movl 0x14(%ebp), %eax\n" /* line 881 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SetVariableFieldValue\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00084c37:\n"
        "movl 0x14(%ebp), %eax\n" /* line 845 */
        "cmpl $8, 4(%eax)\n"
        "je .Lf840ae_000866c3\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf840ae_00086a62\n"
        ".Lf840ae_00084c55:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00084c6a\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_000868bc\n"
        ".Lf840ae_00084c6a:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00084c93\n"
        ".Lf840ae_00084c73:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00084c93:\n"
        "movl scrVmPub, %eax\n" /* line 861 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* fieldValueId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084ca5:\n"
        "movl -0x38(%ebp), %ebx\n" /* line 2212 | caseCount, pos */
        "testl %ebx, %ebx\n" /* pos */
        "je .Lf840ae_00084cd0\n"
        "xorl %ebx, %ebx\n" /* line 2203 | pos */
        /* { scope 2 */
        ".Lf840ae_00084cae:\n"
        "movl 8(%ebp), %eax\n" /* line 156 | fs */
        "movl (%eax), %ecx\n"
        "leal 4(%eax), %edx\n" /* line 157 */
        "movl %edx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %ecx, -0x30(%ebp)\n" /* line 196 | currentCaseValue */
        /* { scope 2 */
        "movl 4(%eax), %edx\n" /* line 156 */
        "addl $8, %eax\n" /* line 157 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, -0x2c(%ebp)\n" /* line 215 | pos, currentCodePos */
        "addl $1, %ebx\n" /* result */
        "cmpl %ebx, -0x38(%ebp)\n" /* line 2212 | pos, caseCount */
        "jne .Lf840ae_00084cae\n"
        ".Lf840ae_00084cd0:\n"
        "movl -0x30(%ebp), %esi\n" /* line 2220 | currentCaseValue, builtinIndex */
        "testl %esi, %esi\n" /* builtinIndex */
        "jne .Lf840ae_00084cdd\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2222 | currentCodePos */
        "movl %edx, 8(%ebp)\n" /* fs */
        ".Lf840ae_00084cdd:\n"
        "movl $0, -0x38(%ebp)\n" /* caseCount */
        ".Lf840ae_00084ce4:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2116 | value */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 252 */
        "movl %edx, 4(%esp)\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "jmp .Lf840ae_00084a3a\n"
        /* } scope */
        ".Lf840ae_00084cfd:\n"
        "movl scrVmGlob+20, %edi\n" /* line 1394 | opcode */
        "testl %edi, %edi\n" /* opcode */
        "jne .Lf840ae_000869f6\n"
        "cmpb $0, scrVmPub+21\n" /* line 1426 */
        "je .Lf840ae_000867b7\n"
        "calll Scr_DumpScriptThreads\n" /* line 4938 */
        "calll Scr_DumpScriptVariables\n" /* line 4939 */
        "movb $1, scrVmPub+22\n" /* line 4940 */
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf840ae_00086b8f\n"
        ".Lf840ae_00084d3a:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00084d4f\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086b45\n"
        ".Lf840ae_00084d4f:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00084d78\n"
        ".Lf840ae_00084d58:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00084d78:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1441 | pos */
        "leal 8(%ebx), %eax\n" /* pos */
        "movl %eax, 0x14(%ebp)\n"
        "movl -0x48(%ebp), %edx\n" /* line 1443 | fieldValueId */
        "movl %edx, (%esp)\n"
        "calll Scr_EvalVariableField\n"
        "movl %eax, 8(%ebx)\n" /* pos */
        "movl %edx, 0xc(%ebx)\n" /* pos */
        "movl 0x14(%ebp), %eax\n" /* line 1444 */
        "movl 4(%eax), %edx\n"
        "cmpl $6, %edx\n"
        "jne .Lf840ae_00084b89\n"
        "addl $1, (%eax)\n" /* line 1446 */
        "addl $1, 8(%ebp)\n" /* line 1448 | fs */
        "movl -0x48(%ebp), %edx\n" /* fieldValueId */
        "jmp .Lf840ae_00084c23\n"
        ".Lf840ae_00084db0:\n"
        "movl -0x48(%ebp), %edx\n" /* fieldValueId */
        ".Lf840ae_00084db3:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 720 | parentLocalId */
        "movl %edx, (%esp)\n"
        "calll Scr_EvalArrayRef\n"
        "movl %ebx, 4(%esp)\n" /* parentLocalId */
        "movl %eax, (%esp)\n"
        "calll Scr_EvalArrayIndex\n"
        "movl %eax, -0x48(%ebp)\n" /* fieldValueId */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00084dd2:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1753 | pos */
        "leal 8(%ebx), %eax\n" /* pos */
        "movl %eax, 0x14(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 156 | fs */
        "movl (%eax), %ecx\n"
        "leal 4(%eax), %edx\n" /* line 157 */
        "movl %edx, 8(%ebp)\n" /* fs */
        "movl 4(%eax), %edx\n" /* line 156 */
        "addl $8, %eax\n" /* line 157 */
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl %ecx, 4(%esp)\n" /* line 1757 */
        "movl %edx, (%esp)\n"
        "calll FindEntityId\n"
        "movl %eax, 8(%ebx)\n" /* pos */
        "movl 0x14(%ebp), %eax\n" /* line 1758 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf840ae_00084e9d\n"
        "movl $0, 4(%eax)\n" /* line 1761 */
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %edi\n" /* opcode */
        "testl %edi, %edi\n" /* opcode */
        "je .Lf840ae_00086b1f\n"
        ".Lf840ae_00084e23:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00085fea\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf840ae_00085fea\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00084e5f\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00084e5f:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00084e9a:\n"
        "movl 0x14(%ebp), %eax\n"
        ".Lf840ae_00084e9d:\n"
        "movl $1, 4(%eax)\n" /* line 1765 */
        "jmp .Lf840ae_00085162\n"
        ".Lf840ae_00084ea9:\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1774 */
        "leal 8(%ecx), %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, 8(%ecx)\n" /* line 1776 */
        "jmp .Lf840ae_00084e9a\n"
        ".Lf840ae_00084ec3:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 1781 | pos */
        "leal 8(%ebx), %eax\n" /* pos */
        "movl %eax, 0x14(%ebp)\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, 4(%esp)\n" /* line 1783 */
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        ".Lf840ae_00084ee7:\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalVariable\n"
        "movl %eax, 8(%ebx)\n" /* pos */
        "movl %edx, 0xc(%ebx)\n" /* pos */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        /* { scope 2 */
        ".Lf840ae_00084efd:\n"
        "movzwl (%esi), %eax\n" /* line 143 */
        "leal 3(%ecx), %edx\n" /* line 144 */
        "movl %edx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %eax, 4(%esp)\n" /* line 1787 */
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, -0x48(%ebp)\n" /* fieldValueId */
        "testl %eax, %eax\n" /* line 1788 */
        "jne .Lf840ae_00084116\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf840ae_00086b03\n"
        ".Lf840ae_00084f31:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_0008604e\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf840ae_0008604e\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00084f6d\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00084f6d:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0, -0x48(%ebp)\n" /* fieldValueId */
        ".Lf840ae_00084fae:\n"
        "addl $1, 8(%ebp)\n" /* line 830 | fs */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084fba:\n"
        "movl 0x14(%ebp), %eax\n" /* line 493 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $6, 4(%eax)\n" /* line 495 */
        "movl 8(%ebp), %eax\n" /* line 496 | fs */
        "movzbl (%eax), %edx\n"
        "movl 0x14(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "addl $1, 8(%ebp)\n" /* line 497 | fs */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00084fe1:\n"
        "movl 0x14(%ebp), %eax\n" /* line 511 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $6, 4(%eax)\n" /* line 513 */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 514 */
        "movl %edx, (%eax)\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_0008500a:\n"
        "movl 0x14(%ebp), %eax\n" /* line 519 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $6, 4(%eax)\n" /* line 521 */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "negl %edx\n" /* line 522 */
        "movl 0x14(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085035:\n"
        "movl 0x14(%ebp), %eax\n" /* line 527 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $6, 4(%eax)\n" /* line 529 */
        /* { scope 2 */
        ".Lf840ae_00085045:\n"
        "movl 8(%ebp), %eax\n" /* line 156 | fs */
        "movl (%eax), %edx\n"
        "addl $4, %eax\n" /* line 157 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 614 */
        "movl %edx, (%eax)\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_0008505d:\n"
        "movl 0x14(%ebp), %eax\n" /* line 535 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $5, 4(%eax)\n" /* line 537 */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 207 | fs */
        "movl (%eax), %edx\n"
        "addl $4, %eax\n" /* line 208 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 538 */
        "movl %edx, (%eax)\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085085:\n"
        "movl 0x14(%ebp), %eax\n" /* line 502 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $6, 4(%eax)\n" /* line 504 */
        "movl 8(%ebp), %eax\n" /* line 505 | fs */
        "movzbl (%eax), %eax\n"
        "negl %eax\n"
        "movl 0x14(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "addl $1, 8(%ebp)\n" /* line 506 | fs */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000850ae:\n"
        "movl 0x14(%ebp), %eax\n" /* line 543 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $2, 4(%eax)\n" /* line 545 */
        /* { scope 2 */
        ".Lf840ae_000850be:\n"
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 555 */
        "movl %edx, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 556 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_AddRefToString\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000850e4:\n"
        "movl 0x14(%ebp), %eax\n" /* line 552 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $3, 4(%eax)\n" /* line 554 */
        "jmp .Lf840ae_000850be\n"
        ".Lf840ae_000850f6:\n"
        "movl 0x14(%ebp), %eax\n" /* line 561 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $4, 4(%eax)\n" /* line 563 */
        "movl 8(%ebp), %edx\n" /* line 169 | fs */
        "leal 0xc(%edx), %eax\n" /* line 170 */
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl 0x14(%ebp), %eax\n" /* line 564 */
        "movl %edx, (%eax)\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_0008511c:\n"
        "movl imp_scrVarPub, %eax\n" /* line 568 */
        "movl 0x24(%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_0008512f:\n"
        "movl imp_scrVarPub, %eax\n" /* line 572 */
        "movl 0x2c(%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085142:\n"
        "movl 0x14(%ebp), %eax\n" /* line 577 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $1, 4(%eax)\n" /* line 579 */
        "movl 0x14(%ebp), %ebx\n" /* line 580 | parentLocalId */
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_GetSelf\n"
        "movl %eax, (%ebx)\n" /* parentLocalId */
        ".Lf840ae_00085162:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1766 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddRefToObject\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085177:\n"
        "movl 0x14(%ebp), %eax\n" /* line 586 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $1, 4(%eax)\n" /* line 588 */
        "movl imp_scrVarPub, %ecx\n" /* line 589 */
        "movl 0x24(%ecx), %edx\n"
        "movl 0x14(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "movl 0x24(%ecx), %eax\n" /* line 590 */
        "movl %eax, (%esp)\n"
        "calll AddRefToObject\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000851a8:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 595 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        "movl imp_scrVarPub, %eax\n" /* line 597 */
        "movl 0x28(%eax), %eax\n"
        "jmp .Lf840ae_00084ee7\n"
        ".Lf840ae_000851be:\n"
        "movl 0x14(%ebp), %eax\n" /* line 602 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $1, 4(%eax)\n" /* line 604 */
        "movl imp_scrVarPub, %ecx\n" /* line 605 */
        "movl 0x2c(%ecx), %edx\n"
        "movl 0x14(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "movl 0x2c(%ecx), %eax\n" /* line 606 */
        "movl %eax, (%esp)\n"
        "calll AddRefToObject\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000851ef:\n"
        "movl 0x14(%ebp), %eax\n" /* line 611 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $0xb, 4(%eax)\n" /* line 613 */
        "jmp .Lf840ae_00085045\n"
        ".Lf840ae_00085204:\n"
        "movl imp_scrVarPub, %eax\n" /* line 618 */
        "movl 0x28(%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* fieldValueId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085217:\n"
        "movl 0x14(%ebp), %eax\n" /* line 623 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $9, 4(%eax)\n" /* line 625 */
        "jmp .Lf840ae_00085045\n"
        ".Lf840ae_0008522c:\n"
        "movl scrVmPub, %ebx\n" /* line 630 | parentLocalId */
        "leal 4(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, scrVmPub\n"
        "addl $1, 0x10(%ebp)\n" /* line 631 */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, 4(%esp)\n" /* line 632 */
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetNewVariable\n"
        "movl %eax, 4(%ebx)\n" /* parentLocalId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085264:\n"
        "movzbl (%esi), %esi\n" /* line 636 | builtinIndex */
        "leal 2(%ecx), %eax\n" /* line 637 */
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl %esi, %eax\n" /* line 638 | builtinIndex */
        "movzbl %al, %edx\n"
        "leal (, %edx, 4), %eax\n"
        "subl %eax, scrVmPub\n"
        "subl %edx, 0x10(%ebp)\n" /* line 639 */
        "movl %esi, %edx\n" /* line 640 | builtinIndex */
        "testb %dl, %dl\n"
        "je .Lf840ae_00084116\n"
        "xorl %ebx, %ebx\n" /* parentLocalId */
        ".Lf840ae_0008528e:\n"
        "movl 0xc(%ebp), %eax\n" /* line 642 */
        "movl %eax, (%esp)\n"
        "calll RemoveNextVariable\n"
        "subb $1, %bl\n" /* parentLocalId */
        "movl %esi, %eax\n" /* line 640 | builtinIndex */
        "addb %bl, %al\n" /* parentLocalId */
        "jne .Lf840ae_0008528e\n"
        "jmp .Lf840ae_00084116\n"
        ".Lf840ae_000852a7:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 649 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        "movl scrVmPub, %eax\n" /* line 651 */
        "movl (%eax), %eax\n"
        "jmp .Lf840ae_00084ee7\n"
        ".Lf840ae_000852bc:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 656 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        "movl scrVmPub, %eax\n" /* line 658 */
        "movl -4(%eax), %eax\n"
        "jmp .Lf840ae_00084ee7\n"
        ".Lf840ae_000852d2:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 870 | parentLocalId */
        /* { scope 2 */
        "movzwl (%esi), %eax\n" /* line 143 */
        "leal 3(%ecx), %edx\n" /* line 144 */
        "movl %edx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %eax, 4(%esp)\n" /* line 870 */
        "movl imp_scrVarPub, %eax\n"
        "movl 0x24(%eax), %eax\n"
        ".Lf840ae_000852ea:\n"
        "movl %eax, (%esp)\n" /* line 885 */
        "calll GetVariable\n"
        "movl %ebx, 4(%esp)\n" /* parentLocalId */
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085303:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1476 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalAnd\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_0008531a:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1480 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalEquality\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085331:\n"
        "movl 0x14(%ebp), %eax\n" /* line 812 */
        "cmpl $8, 4(%eax)\n"
        "je .Lf840ae_000849dd\n"
        ".Lf840ae_0008533e:\n"
        "movl %eax, 4(%esp)\n" /* line 825 */
        "movzbl (%esi), %eax\n" /* builtinIndex */
        "shll $2, %eax\n"
        "movl scrVmPub, %edx\n"
        "subl %eax, %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        "addl $1, 8(%ebp)\n" /* line 826 | fs */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085363:\n"
        "movl 0x14(%ebp), %eax\n" /* line 835 */
        "movl 4(%eax), %edx\n"
        "cmpl $7, %edx\n"
        "je .Lf840ae_00084116\n"
        ".Lf840ae_00085372:\n"
        "movl (%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 838 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 835 */
        "cmpl $7, %edx\n"
        "jne .Lf840ae_00085372\n"
        "jmp .Lf840ae_00084116\n"
        ".Lf840ae_00085396:\n"
        "movl 0xc(%ebp), %eax\n" /* line 783 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetSelf\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, 4(%esp)\n" /* line 788 */
        "movl -0x44(%ebp), %edx\n" /* objectId */
        "movl %edx, (%esp)\n"
        "calll Scr_GetVariableField\n"
        "movl %eax, -0x48(%ebp)\n" /* fieldValueId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000853ca:\n"
        "movl imp_scrVarPub, %eax\n" /* line 775 */
        "movl 0x24(%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, 4(%esp)\n" /* line 788 */
        "movl -0x44(%ebp), %edx\n" /* objectId */
        "movl %edx, (%esp)\n"
        "calll Scr_GetVariableField\n"
        "movl %eax, -0x48(%ebp)\n" /* fieldValueId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000853fb:\n"
        "movl scrVmPub, %eax\n" /* line 710 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* fieldValueId */
        "movl %eax, %edx\n"
        "jmp .Lf840ae_00084db3\n"
        ".Lf840ae_0008540c:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 691 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 693 | fs */
        "movzbl (%eax), %edx\n"
        "shll $2, %edx\n"
        "movl scrVmPub, %eax\n"
        "subl %edx, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalVariable\n"
        "movl %eax, 8(%ebx)\n" /* parentLocalId */
        "movl %edx, 0xc(%ebx)\n" /* parentLocalId */
        "addl $1, 8(%ebp)\n" /* line 694 | fs */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085441:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 663 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        "movl scrVmPub, %eax\n" /* line 665 */
        "movl -8(%eax), %eax\n"
        "jmp .Lf840ae_00084ee7\n"
        ".Lf840ae_00085457:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 670 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        "movl scrVmPub, %eax\n" /* line 672 */
        "movl -0xc(%eax), %eax\n"
        "jmp .Lf840ae_00084ee7\n"
        ".Lf840ae_0008546d:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 677 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        "movl scrVmPub, %eax\n" /* line 679 */
        "movl -0x10(%eax), %eax\n"
        "jmp .Lf840ae_00084ee7\n"
        ".Lf840ae_00085483:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 684 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        "movl scrVmPub, %eax\n" /* line 686 */
        "movl -0x14(%eax), %eax\n"
        "jmp .Lf840ae_00084ee7\n"
        ".Lf840ae_00085499:\n"
        "movl 0xc(%ebp), %eax\n" /* line 735 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetSelf\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "movl %eax, (%esp)\n" /* line 736 */
        "calll IsFieldObject\n"
        "testb %al, %al\n"
        "jne .Lf840ae_00084116\n"
        "jmp .Lf840ae_00086f2f\n"
        ".Lf840ae_000854bc:\n"
        "movl imp_scrVarPub, %eax\n" /* line 741 */
        "movl 0x24(%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        ".Lf840ae_000854c7:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 746 | parentLocalId */
        "leal 8(%ebx), %eax\n" /* parentLocalId */
        "movl %eax, 0x14(%ebp)\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, 4(%esp)\n" /* line 748 */
        "movl -0x44(%ebp), %edx\n" /* objectId */
        "movl %edx, (%esp)\n"
        "calll FindVariable\n"
        "jmp .Lf840ae_00084ee7\n"
        ".Lf840ae_000854f0:\n"
        "movl imp_scrVarPub, %eax\n" /* line 752 */
        "movl 0x2c(%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "jmp .Lf840ae_000854c7\n"
        ".Lf840ae_000854fd:\n"
        "movl 0x14(%ebp), %eax\n" /* line 725 */
        "movl %eax, 4(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* fieldValueId */
        "movl %eax, (%esp)\n"
        "calll ClearArray\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085514:\n"
        "movl 0x14(%ebp), %eax\n" /* line 729 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $1, 4(%eax)\n" /* line 730 */
        "movl 0x14(%ebp), %ebx\n" /* line 731 | parentLocalId */
        "calll Scr_AllocArray\n"
        "movl %eax, (%ebx)\n" /* parentLocalId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085536:\n"
        "movzbl (%esi), %eax\n" /* line 126 */
        "shll $2, %eax\n"
        "movl scrVmPub, %edx\n"
        "subl %eax, %edx\n"
        "movl (%edx), %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* fieldValueId */
        "leal 2(%ecx), %eax\n" /* line 715 */
        "movl %eax, 8(%ebp)\n" /* fs */
        "jmp .Lf840ae_00084db3\n"
        ".Lf840ae_00085554:\n"
        "movl 0x14(%ebp), %eax\n" /* line 485 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl $6, 4(%eax)\n" /* line 487 */
        "movl 0x14(%ebp), %eax\n" /* line 488 */
        "movl $0, (%eax)\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        /* { scope 2 */
        ".Lf840ae_00085575:\n"
        "movzwl (%esi), %eax\n" /* line 143 */
        "leal 3(%ecx), %edx\n" /* line 144 */
        "movl %edx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0x14(%ebp), %edx\n" /* line 792 */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x44(%ebp), %eax\n" /* objectId */
        "movl %eax, (%esp)\n"
        "calll ClearVariableField\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_0008559c:\n"
        "movl (%esi), %eax\n" /* line 1373 | builtinIndex */
        "leal 5(%ecx, %eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl %eax, %ecx\n"
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000855ac:\n"
        "rdtsc\n" /* line 33 */
        "shrl $2, %eax\n" /* line 1377 */
        "subl scrVmGlob+24, %eax\n"
        "cmpl $0xff000000, %eax\n"
        "jl .Lf840ae_00084cfd\n"
        "leal 3(%ecx), %eax\n" /* line 1384 */
        "movzwl (%esi), %edx\n" /* builtinIndex */
        "subl %edx, %eax\n"
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl %eax, %ecx\n"
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000855d4:\n"
        "movl 0xc(%ebp), %eax\n" /* line 449 */
        "movl %eax, (%esp)\n"
        "calll GetSafeParentLocalId\n"
        "movl %eax, %ebx\n" /* parentLocalId */
        "movl 0xc(%ebp), %eax\n" /* line 450 */
        "movl %eax, (%esp)\n"
        "calll Scr_KillThread\n"
        "movl 0x10(%ebp), %eax\n" /* line 451 */
        "shll $2, %eax\n"
        "subl %eax, scrVmPub\n"
        "movl 0x14(%ebp), %ecx\n" /* line 453 */
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %eax, -0x20(%ebp)\n" /* tempValue */
        "movl %edx, -0x1c(%ebp)\n"
        "leal -8(%ecx), %eax\n" /* line 454 */
        "movl %eax, 0x14(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 456 */
        "cmpl $7, %edx\n"
        "je .Lf840ae_00085633\n"
        ".Lf840ae_00085614:\n"
        "movl (%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 459 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 456 */
        "cmpl $7, %edx\n"
        "jne .Lf840ae_00085614\n"
        ".Lf840ae_00085633:\n"
        "subl $1, scrVmPub+8\n" /* line 463 */
        "subl $0x18, scrVmPub+12\n" /* line 464 */
        "testl %ebx, %ebx\n" /* line 465 | parentLocalId */
        "jne .Lf840ae_0008637a\n"
        "movl -0x20(%ebp), %eax\n" /* line 468 | tempValue */
        "movl -0x1c(%ebp), %edx\n"
        "movl 0x14(%ebp), %ecx\n"
        "movl %eax, 8(%ecx)\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl -0x3c(%ebp), %edi\n" /* line 1873 | thread_count, opcode */
        "testl %edi, %edi\n" /* opcode */
        "jne .Lf840ae_000842f1\n"
        "jmp .Lf840ae_0008451c\n"
        ".Lf840ae_00085668:\n"
        "movl 0xc(%ebp), %eax\n" /* line 415 */
        "movl %eax, (%esp)\n"
        "calll GetSafeParentLocalId\n"
        "movl %eax, %ebx\n" /* parentLocalId */
        "movl 0xc(%ebp), %eax\n" /* line 416 */
        "movl %eax, (%esp)\n"
        "calll Scr_KillThread\n"
        "movl 0x10(%ebp), %eax\n" /* line 417 */
        "shll $2, %eax\n"
        "subl %eax, scrVmPub\n"
        "movl 0x14(%ebp), %eax\n" /* line 420 */
        "movl 4(%eax), %edx\n"
        "cmpl $7, %edx\n"
        "je .Lf840ae_000856b6\n"
        ".Lf840ae_00085697:\n"
        "movl (%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 423 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 420 */
        "cmpl $7, %edx\n"
        "jne .Lf840ae_00085697\n"
        ".Lf840ae_000856b6:\n"
        "subl $1, scrVmPub+8\n" /* line 427 */
        "subl $0x18, scrVmPub+12\n" /* line 428 */
        "testl %ebx, %ebx\n" /* line 429 | parentLocalId */
        "je .Lf840ae_000842dc\n"
        "movl 0x14(%ebp), %eax\n" /* line 436 */
        "movl $0, 4(%eax)\n"
        ".Lf840ae_000856d6:\n"
        "movl 0xc(%ebp), %eax\n" /* line 440 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl scrVmPub+12, %edx\n" /* line 442 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl 8(%edx), %eax\n" /* line 444 */
        "movl %eax, 0x10(%ebp)\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 445 | parentLocalId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000856fd:\n"
        "movzbl (%esi), %eax\n" /* line 1319 | builtinIndex */
        "shll $2, %eax\n"
        "movl scrVmPub, %edx\n"
        "subl %eax, %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalVariableObject\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "addl $1, 8(%ebp)\n" /* line 1320 | fs */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085724:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1324 */
        "movl %eax, (%esp)\n"
        "calll Scr_CastBool\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085737:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1328 */
        "movl %eax, (%esp)\n"
        "calll Scr_EvalBoolNot\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_0008574a:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1332 */
        "movl %eax, (%esp)\n"
        "calll Scr_EvalBoolComplement\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_0008575d:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1336 */
        "movl %eax, (%esp)\n"
        "calll Scr_CastBool\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "leal 2(%eax), %ecx\n" /* line 144 */
        "movl %ecx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 1339 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf840ae_00084a3a\n"
        ".Lf840ae_00085781:\n"
        "leal (%ecx, %edx), %eax\n" /* line 1350 */
        "movl %eax, 8(%ebp)\n" /* fs */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_0008578c:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1345 */
        "movl %eax, (%esp)\n"
        "calll Scr_CastBool\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "leal 2(%eax), %ecx\n" /* line 144 */
        "movl %ecx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 1348 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf840ae_00084a3a\n"
        "jmp .Lf840ae_00085781\n"
        ".Lf840ae_000857b2:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1354 */
        "movl %eax, (%esp)\n"
        "calll Scr_CastBool\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "leal 2(%eax), %ecx\n" /* line 144 */
        "movl %ecx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 1357 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf840ae_00084a3a\n"
        ".Lf840ae_000857d6:\n"
        "leal (%ecx, %edx), %eax\n" /* line 1368 */
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl %eax, %ecx\n"
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000857e3:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1363 */
        "movl %eax, (%esp)\n"
        "calll Scr_CastBool\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "leal 2(%eax), %ecx\n" /* line 144 */
        "movl %ecx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 1366 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf840ae_00084a3a\n"
        "jmp .Lf840ae_000857d6\n"
        ".Lf840ae_00085809:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1484 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalInequality\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085820:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1488 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalLess\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085837:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1492 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalGreater\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_0008584e:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1496 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalLessEqual\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085865:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1500 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalGreaterEqual\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_0008587c:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1504 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalShiftLeft\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085893:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1508 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalShiftRight\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_000858aa:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1512 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalPlus\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_000858c1:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1516 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalMinus\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_000858d8:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1520 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalMultiply\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_000858ef:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1524 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalDivide\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085906:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1528 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalMod\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_0008591d:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1532 */
        "movl %eax, (%esp)\n"
        "calll Scr_EvalSizeValue\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085930:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1539 */
        "cmpl $1, 4(%eax)\n"
        "jne .Lf840ae_00086bf4\n"
        "movl (%eax), %eax\n" /* line 1541 */
        "movl %eax, (%esp)\n"
        "calll IsFieldObject\n"
        "testb %al, %al\n"
        "je .Lf840ae_00086dfa\n"
        "movl 0x14(%ebp), %edx\n" /* line 1543 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* tempValue */
        "leal -8(%edx), %eax\n" /* line 1544 */
        "movl %eax, 0x14(%ebp)\n"
        "cmpl $2, 4(%eax)\n" /* line 1546 */
        "jne .Lf840ae_00086f41\n"
        "movl -8(%edx), %esi\n" /* line 1548 | builtinIndex */
        "leal -0x10(%edx), %ecx\n" /* line 1549 */
        "movl %ecx, 0x14(%ebp)\n"
        "movl $0xa, -0x24(%ebp)\n" /* line 1561 */
        "movl %ecx, %eax\n" /* line 1562 */
        "subl 0x18(%ebp), %eax\n"
        "sarl $3, %eax\n"
        "leal 0xc(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "movl 8(%ebp), %edx\n" /* fs */
        "calll VM_ArchiveStack\n"
        "movl %eax, -0x28(%ebp)\n" /* stackValue */
        "movl $0x1fffe, 4(%esp)\n" /* line 1565 */
        "movl -0x20(%ebp), %eax\n" /* tempValue */
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl %esi, 4(%esp)\n" /* builtinIndex */
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl 0xc(%ebp), %edx\n" /* line 1567 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll GetNewObjectVariable\n"
        "leal -0x28(%ebp), %edx\n" /* line 1568 | stackValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        "movl $1, -0x1c(%ebp)\n" /* line 1570 */
        "movl 0xc(%ebp), %ebx\n" /* line 1573 | pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll Scr_GetSelf\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_scrVarPub, %eax\n"
        "movl 0x20(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetObjectVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl %ebx, 4(%esp)\n" /* pos */
        "movl %eax, (%esp)\n"
        "calll GetNewObjectVariable\n"
        "leal -0x20(%ebp), %edx\n" /* tempValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        "movl %esi, 4(%esp)\n" /* line 1575 | builtinIndex */
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetThreadNotifyName\n"
        "jmp .Lf840ae_000842dc\n"
        ".Lf840ae_00085a41:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1590 */
        "cmpl $1, 4(%eax)\n"
        "jne .Lf840ae_00086bf4\n"
        "movl (%eax), %esi\n" /* line 1592 | builtinIndex */
        "movl %esi, (%esp)\n" /* line 1593 | builtinIndex */
        "calll IsFieldObject\n"
        "testb %al, %al\n"
        "je .Lf840ae_00086dfa\n"
        "movl 0x14(%ebp), %edx\n" /* line 1595 */
        "leal -8(%edx), %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "cmpl $2, 4(%eax)\n" /* line 1597 */
        "jne .Lf840ae_00086d9b\n"
        "movl -8(%edx), %ebx\n" /* line 1599 | pos */
        "leal -0x10(%edx), %ecx\n" /* line 1600 */
        "movl %ecx, 0x14(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 1602 | fs */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "movl %ebx, %edx\n" /* line 1603 | pos */
        "movl %esi, %eax\n" /* builtinIndex */
        "calll VM_Notify\n"
        "movl scrVmPub+12, %eax\n" /* line 1604 */
        "movl (%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl %esi, (%esp)\n" /* line 1606 | builtinIndex */
        "calll RemoveRefToObject\n"
        "movl %ebx, (%esp)\n" /* line 1607 | pos */
        "calll SL_RemoveRefToString\n"
        "movl 0x14(%ebp), %eax\n" /* line 1610 */
        "movl 4(%eax), %edx\n"
        "cmpl $8, %edx\n"
        "je .Lf840ae_00084a3a\n"
        ".Lf840ae_00085ab8:\n"
        "movl (%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 1613 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 1610 */
        "cmpl $8, %edx\n"
        "jne .Lf840ae_00085ab8\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085adc:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1630 */
        "cmpl $1, 4(%eax)\n"
        "jne .Lf840ae_00086e60\n"
        "movl (%eax), %eax\n" /* line 1632 */
        "movl %eax, (%esp)\n"
        "calll IsFieldObject\n"
        "testb %al, %al\n"
        "je .Lf840ae_00086ff8\n"
        "movl 0x14(%ebp), %eax\n" /* line 1634 */
        "cmpl $2, -4(%eax)\n"
        "jne .Lf840ae_00086fa6\n"
        "movl -8(%eax), %esi\n" /* line 1636 | builtinIndex */
        "movl 0xc(%ebp), %eax\n" /* line 1639 */
        "movl %eax, (%esp)\n"
        "calll AddRefToObject\n"
        "movl 0xc(%ebp), %eax\n" /* line 1640 */
        "movl %eax, (%esp)\n"
        "calll AllocThread\n"
        "movl %eax, %ebx\n" /* pos */
        "movl $0x1fffe, 4(%esp)\n" /* line 1649 */
        "movl 0x14(%ebp), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl %esi, 4(%esp)\n" /* builtinIndex */
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl %ebx, 4(%esp)\n" /* pos */
        "movl %eax, (%esp)\n"
        "calll GetObjectVariable\n"
        "movl %ebx, (%esp)\n" /* line 1651 | pos */
        "calll RemoveRefToObject\n"
        "movl $1, -0x1c(%ebp)\n" /* line 1653 */
        "movl 0x14(%ebp), %eax\n" /* line 1654 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* tempValue */
        "movl 0xc(%ebp), %eax\n" /* line 1657 */
        "movl %eax, 4(%esp)\n"
        "movl imp_scrVarPub, %eax\n"
        "movl 0x20(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetObjectVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl %ebx, 4(%esp)\n" /* pos */
        "movl %eax, (%esp)\n"
        "calll GetNewObjectVariable\n"
        "leal -0x20(%ebp), %edx\n" /* tempValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        "movl %esi, 4(%esp)\n" /* line 1659 | builtinIndex */
        "movl %ebx, (%esp)\n" /* pos */
        "calll Scr_SetThreadNotifyName\n"
        "subl $0x10, 0x14(%ebp)\n" /* line 1661 */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085bc9:\n"
        "movl $1, scrVmPub+28\n" /* line 903 */
        "jmp .Lf840ae_00084341\n"
        ".Lf840ae_00085bd8:\n"
        "movl $4, scrVmPub+28\n" /* line 918 */
        "jmp .Lf840ae_00084341\n"
        ".Lf840ae_00085be7:\n"
        "movl $5, scrVmPub+28\n" /* line 923 */
        "jmp .Lf840ae_00084341\n"
        ".Lf840ae_00085bf6:\n"
        "movl $1, scrVmPub+28\n" /* line 986 */
        "movl 0x14(%ebp), %ecx\n" /* line 1019 */
        "leal -8(%ecx), %eax\n"
        "movl %eax, scrVmPub+16\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "movzwl (%eax), %edx\n"
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, %esi\n" /* line 1020 | builtinIndex */
        "cmpl $1, 4(%ecx)\n" /* line 1022 */
        "jne .Lf840ae_0008418c\n"
        ".Lf840ae_00085c23:\n"
        "movl (%ecx), %ecx\n" /* line 1024 */
        "movl %ecx, -0x44(%ebp)\n" /* objectId */
        "movl %ecx, (%esp)\n" /* line 1026 */
        "calll GetVarType\n"
        "cmpl $0x15, %eax\n"
        "je .Lf840ae_000862a5\n"
        "movl -0x44(%ebp), %edx\n" /* line 1050 | objectId */
        "movl %edx, (%esp)\n"
        "calll GetVarType\n"
        "movl %eax, %ebx\n" /* parentLocalId */
        "movl -0x44(%ebp), %eax\n" /* line 1051 | objectId */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl imp_scrVarPub, %esi\n" /* line 1052 | builtinIndex */
        "movl $0xffffffff, 0x14(%esi)\n" /* builtinIndex */
        "movl imp_var_typename, %eax\n" /* line 1053 */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cefc, (%esp)\n" /* "%s is not an entity" */
        "calll va\n"
        "movl 0x10(%esi), %ecx\n" /* line 4922 | builtinIndex */
        "testl %ecx, %ecx\n"
        "je .Lf840ae_000866de\n"
        ".Lf840ae_00085c81:\n"
        "cmpb $0, 0xc(%esi)\n" /* line 221 */
        "jne .Lf840ae_00085c96\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_000865a5\n"
        ".Lf840ae_00085c96:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00085cbf\n"
        ".Lf840ae_00085c9f:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00085cbf:\n"
        "movl 0x14(%ebp), %eax\n"
        "jmp .Lf840ae_0008418e\n"
        ".Lf840ae_00085cc7:\n"
        "movl $2, scrVmPub+28\n" /* line 991 */
        "jmp .Lf840ae_00084169\n"
        ".Lf840ae_00085cd6:\n"
        "movl $3, scrVmPub+28\n" /* line 996 */
        "jmp .Lf840ae_00084169\n"
        ".Lf840ae_00085ce5:\n"
        "movl $4, scrVmPub+28\n" /* line 1001 */
        "jmp .Lf840ae_00084169\n"
        ".Lf840ae_00085cf4:\n"
        "movl $2, scrVmPub+28\n" /* line 908 */
        "jmp .Lf840ae_00084341\n"
        ".Lf840ae_00085d03:\n"
        "movl $3, scrVmPub+28\n" /* line 913 */
        "jmp .Lf840ae_00084341\n"
        ".Lf840ae_00085d12:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 885 | parentLocalId */
        /* { scope 2 */
        "movzwl (%esi), %eax\n" /* line 143 */
        "leal 3(%ecx), %edx\n" /* line 144 */
        "movl %edx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %eax, 4(%esp)\n" /* line 885 */
        "movl imp_scrVarPub, %eax\n"
        "movl 0x2c(%eax), %eax\n"
        "jmp .Lf840ae_000852ea\n"
        /* { scope 2 */
        ".Lf840ae_00085d2f:\n"
        "movzwl (%esi), %ebx\n" /* line 143 | result */
        "leal 3(%ecx), %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 875 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetSelf\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "movl %ebx, 4(%esp)\n" /* line 876 | parentLocalId */
        "movl %eax, (%esp)\n"
        "calll Scr_GetVariableField\n"
        "movl %eax, -0x48(%ebp)\n" /* fieldValueId */
        "movl %eax, %edx\n"
        "jmp .Lf840ae_00084c23\n"
        ".Lf840ae_00085d5c:\n"
        "movl 0x14(%ebp), %eax\n" /* line 889 */
        "jmp .Lf840ae_00084a27\n"
        ".Lf840ae_00085d64:\n"
        "movl 0x14(%ebp), %eax\n" /* line 893 */
        "movl %eax, 4(%esp)\n"
        "movzbl (%esi), %edx\n" /* builtinIndex */
        "shll $2, %edx\n"
        "movl scrVmPub, %eax\n"
        "subl %edx, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        "addl $1, 8(%ebp)\n" /* line 894 | fs */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085d8b:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1472 */
        "movl %eax, 4(%esp)\n"
        "subl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalExOr\n"
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085da2:\n"
        "movl (%esi), %eax\n" /* line 1683 | builtinIndex */
        "leal 5(%ecx, %eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* fs */
        /* { scope 2 */
        "movzwl (%eax), %edx\n" /* line 143 */
        "addl $2, %eax\n" /* line 144 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, %ebx\n" /* line 1684 | pos */
        "movzwl %dx, %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* caseCount */
        "movl 0x14(%ebp), %eax\n" /* line 1690 */
        "movl 4(%eax), %edx\n"
        "cmpl $2, %edx\n"
        "je .Lf840ae_00086593\n"
        "cmpl $6, %edx\n"
        "je .Lf840ae_000869c3\n"
        "movl imp_var_typename, %eax\n" /* line 1706 */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d16c, (%esp)\n" /* "cannot switch on %s" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %edi\n" /* opcode */
        "testl %edi, %edi\n" /* opcode */
        "je .Lf840ae_00086afb\n"
        ".Lf840ae_00085dfd:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_0008601c\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf840ae_0008601c\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00085e39\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00085e39:\n"
        "movl scrVmPub+8, %ecx\n" /* line 248 */
        "testl %ecx, %ecx\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00085e74:\n"
        "testw %bx, %bx\n" /* line 1709 | pos */
        "je .Lf840ae_00084a3a\n"
        "xorl %ebx, %ebx\n" /* pos */
        ".Lf840ae_00085e7f:\n"
        "movl -0x38(%ebp), %esi\n" /* line 332 | caseCount */
        "subl %ebx, %esi\n" /* result */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 156 | fs */
        "movl (%eax), %ecx\n"
        "leal 4(%eax), %edx\n" /* line 157 */
        "movl %edx, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %ecx, -0x30(%ebp)\n" /* line 196 | currentCaseValue */
        /* { scope 2 */
        "movl 4(%eax), %edx\n" /* line 156 */
        "addl $8, %eax\n" /* line 157 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, -0x2c(%ebp)\n" /* line 215 | pos, currentCodePos */
        "cmpl %ecx, -0x34(%ebp)\n" /* line 1717 | caseValue */
        "je .Lf840ae_00086a40\n"
        "addl $1, %ebx\n" /* line 1721 | pos */
        "cmpl %ebx, -0x38(%ebp)\n" /* line 1713 | pos, caseCount */
        "jne .Lf840ae_00085e7f\n"
        "testl %ecx, %ecx\n" /* line 1727 */
        "je .Lf840ae_00086943\n"
        "movl $0, -0x38(%ebp)\n" /* line 1729 | caseCount */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085ec3:\n"
        "movzwl (%esi), %esi\n" /* line 1736 | builtinIndex */
        "movl %esi, -0x38(%ebp)\n" /* builtinIndex, caseCount */
        "leal 3(%ecx, %esi, 8), %eax\n" /* line 183 */
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl %eax, %ecx\n"
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085ed7:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1741 */
        "subl $0x10, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl %eax, (%esp)\n" /* line 1742 */
        "calll Scr_CastVector\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00085ef0:\n"
        "subl $1, g_script_error_level\n" /* line 1747 */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2248 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf840ae_00085f01:\n"
        "movl $5, scrVmPub+28\n" /* line 1006 */
        "jmp .Lf840ae_00084169\n"
        ".Lf840ae_00085f10:\n"
        "movl 0x14(%ebp), %edx\n" /* line 1196 */
        "movl 4(%edx), %ecx\n"
        "cmpl $9, %ecx\n"
        "jne .Lf840ae_00084740\n"
        "movl (%edx), %ebx\n" /* line 1198 | parentLocalId */
        "leal -8(%edx), %eax\n" /* line 1199 */
        "movl %eax, 0x14(%ebp)\n"
        "cmpl $1, 4(%eax)\n" /* line 1200 */
        "jne .Lf840ae_00086bf4\n"
        "cmpl $0x1e, scrVmPub+8\n" /* line 1202 */
        "jg .Lf840ae_00086b9b\n"
        "movl 0xc(%ebp), %eax\n" /* line 1204 */
        "movl %eax, 4(%esp)\n"
        "movl -8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AllocChildThread\n"
        "movl %eax, 0xc(%ebp)\n"
        "subl $8, 0x14(%ebp)\n" /* line 1205 */
        "movl 8(%ebp), %edx\n" /* line 1206 | fs */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "movl %ebx, 8(%ebp)\n" /* line 1207 | parentLocalId, fs */
        "jmp .Lf840ae_0008470a\n"
        ".Lf840ae_00085f69:\n"
        "movl 0x14(%ebp), %edx\n" /* line 1282 */
        "movl 4(%edx), %ecx\n"
        "cmpl $9, %ecx\n"
        "jne .Lf840ae_00086395\n"
        "movl (%edx), %ebx\n" /* line 1284 | parentLocalId */
        "leal -8(%edx), %eax\n" /* line 1285 */
        "movl %eax, 0x14(%ebp)\n"
        "cmpl $1, 4(%eax)\n" /* line 1286 */
        "jne .Lf840ae_00086bf4\n"
        "cmpl $0x1e, scrVmPub+8\n" /* line 1288 */
        "jg .Lf840ae_00086b9b\n"
        "movl -8(%edx), %eax\n" /* line 1290 */
        "movl %eax, (%esp)\n"
        "calll AllocThread\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1291 */
        "subl $8, %ecx\n"
        "movl %ecx, 0x14(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 1292 | fs */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 1293 */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, 0x10(%eax)\n"
        "movl %ebx, 8(%ebp)\n" /* line 1294 | parentLocalId, fs */
        "jmp .Lf840ae_0008498b\n"
        ".Lf840ae_00085fcb:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1315 */
        "movl %eax, 4(%esp)\n"
        "movl imp_scrVarPub, %eax\n"
        "movl 0x34(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalFieldObject\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00085fea:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00084e9a\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf840ae_00084e9a\n"
        ".Lf840ae_0008601c:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00085e74\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf840ae_00085e74\n"
        ".Lf840ae_0008604e:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00084b7d\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $0, -0x48(%ebp)\n" /* fieldValueId */
        "jmp .Lf840ae_00084fae\n"
        ".Lf840ae_00086087:\n"
        "movl imp_scrVarPub, %ebx\n" /* line 1078 | parentLocalId */
        "movl $2, 0x14(%ebx)\n" /* parentLocalId */
        "movl 4(%eax), %eax\n" /* line 1079 */
        "movl imp_var_typename, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cea0, (%esp)\n" /* "type %s is not a float" */
        "calll va\n"
        "movl 0x10(%ebx), %ecx\n" /* line 4922 | pos */
        "testl %ecx, %ecx\n"
        "je .Lf840ae_0008638d\n"
        ".Lf840ae_000860bb:\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 221 | result */
        "jne .Lf840ae_000860d0\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086221\n"
        ".Lf840ae_000860d0:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_000860f9\n"
        ".Lf840ae_000860d9:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_000860f9:\n"
        "movl -0x40(%ebp), %eax\n" /* waitTime */
        "jmp .Lf840ae_00084230\n"
        ".Lf840ae_00086101:\n"
        "movss (%eax), %xmm0\n" /* line 1066 */
        "movss %xmm0, -0x4c(%ebp)\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf840ae_00086115\n"
        "jb .Lf840ae_00086167\n"
        ".Lf840ae_00086115:\n"
        "mulss lit4_002ed694, %xmm0\n" /* line 428 | 20.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x50(%ebp)\n"
        "cvttss2si -0x50(%ebp), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* waitTime */
        "testl %eax, %eax\n" /* line 1069 */
        "jne .Lf840ae_00084230\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf840ae_00086156\n"
        "je .Lf840ae_0008663b\n"
        ".Lf840ae_00086156:\n"
        "movl $1, -0x40(%ebp)\n" /* waitTime */
        "movl $1, %eax\n"
        "jmp .Lf840ae_00084230\n"
        ".Lf840ae_00086167:\n"
        "movl imp_scrVarPub, %edx\n"
        "movl 0x10(%edx), %edi\n" /* line 4922 | opcode */
        "testl %edi, %edi\n" /* opcode */
        "jne .Lf840ae_0008444f\n"
        ".Lf840ae_00086178:\n"
        "movl $str_0021cf24, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_0008444f\n"
        ".Lf840ae_00086184:\n"
        "cmpb $0, 0xa(%esi)\n" /* line 243 */
        "je .Lf840ae_000861a7\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_000861a7:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_000841ed\n"
        ".Lf840ae_000861be:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf840ae_000861dd:\n"
        "movl %eax, 0x10(%esi)\n" /* line 4923 | builtinIndex */
        "jmp .Lf840ae_000841cf\n"
        ".Lf840ae_000861e5:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086208\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086208:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_0008446d\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_00086221:\n"
        "cmpb $0, 0xa(%ebx)\n" /* line 243 | result */
        "je .Lf840ae_00086244\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086244:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_000860d9\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_00086263:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086286\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086286:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_0008441e\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_000862a5:\n"
        "movl -0x44(%ebp), %edx\n" /* line 1028 | objectId */
        "movl %edx, (%esp)\n"
        "calll Scr_GetEntityIdRef\n"
        "movl %eax, %ebx\n" /* parentLocalId */
        "movl -0x44(%ebp), %eax\n" /* line 1029 | objectId */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl 8(%ebp), %edx\n" /* line 1031 | fs */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "movl imp_scrCompilePub, %eax\n" /* line 1044 */
        "movl 0x38(%eax, %esi, 4), %eax\n"
        "movl %ebx, (%esp)\n" /* parentLocalId */
        "calll *%eax\n"
        "jmp .Lf840ae_00084366\n"
        ".Lf840ae_000862da:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1148 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetSelf\n"
        "movl %eax, %ebx\n" /* parentLocalId */
        "movl %eax, (%esp)\n" /* line 1149 */
        "calll AddRefToObject\n"
        "movl 0xc(%ebp), %eax\n" /* line 1150 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* parentLocalId */
        "calll AllocChildThread\n"
        "movl %eax, 0xc(%ebp)\n"
        "jmp .Lf840ae_000846ee\n"
        ".Lf840ae_00086306:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_000847fa\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf840ae_000847fa\n"
        ".Lf840ae_00086338:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_0008635b\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_0008635b:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_0008469c\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_0008637a:\n"
        "movl -0x20(%ebp), %eax\n" /* line 473 | tempValue */
        "movl -0x1c(%ebp), %edx\n"
        "movl 0x14(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "jmp .Lf840ae_000856d6\n"
        ".Lf840ae_0008638d:\n"
        "movl %eax, 0x10(%ebx)\n" /* line 4923 | pos */
        "jmp .Lf840ae_000860bb\n"
        ".Lf840ae_00086395:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 1307 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 0xc(%eax), %edx\n" /* line 1308 */
        "movl imp_var_typename, %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cf80, (%esp)\n" /* "%s is not a function pointer" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf840ae_00086b17\n"
        ".Lf840ae_000863d8:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00086463\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf840ae_00086463\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086410\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086410:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_0008644a:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2116 | value */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 252 */
        "movl %edx, 4(%esp)\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "jmp .Lf840ae_00084a3a\n"
        /* } scope */
        ".Lf840ae_00086463:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00084ce4\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf840ae_0008644a\n"
        ".Lf840ae_00086492:\n"
        "movl $str_0021cf10, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_000843fc\n"
        ".Lf840ae_0008649e:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1225 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetSelf\n"
        "movl %eax, %ebx\n" /* parentLocalId */
        "movl %eax, (%esp)\n" /* line 1226 */
        "calll AddRefToObject\n"
        "movl %ebx, (%esp)\n" /* line 1227 | parentLocalId */
        "calll AllocThread\n"
        "movl %eax, 0xc(%ebp)\n"
        "jmp .Lf840ae_00084961\n"
        ".Lf840ae_000864c3:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "jne .Lf840ae_0008670f\n"
        ".Lf840ae_000864cd:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_00084916\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_000864ec:\n"
        "movl %eax, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_0008467e\n"
        ".Lf840ae_000864f4:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1698 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d14c, (%esp)\n" /* "switch index %d out of range" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf840ae_00086b87\n"
        ".Lf840ae_0008651a:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00086b33\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf840ae_00086b33\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086556\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086556:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        ".Lf840ae_00086570:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00086590:\n"
        "movl 0x14(%ebp), %eax\n"
        ".Lf840ae_00086593:\n"
        "movl (%eax), %eax\n" /* line 1701 */
        "movl %eax, -0x34(%ebp)\n" /* caseValue */
        "movl %eax, (%esp)\n" /* line 1702 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf840ae_00085e74\n"
        ".Lf840ae_000865a5:\n"
        "cmpb $0, 0xa(%esi)\n" /* line 243 */
        "jne .Lf840ae_00086921\n"
        ".Lf840ae_000865af:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_00085c9f\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_000865ce:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "jne .Lf840ae_000868ff\n"
        ".Lf840ae_000865d8:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_000845c3\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_000865f7:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1163 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetSelf\n"
        "movl %eax, %ebx\n" /* parentLocalId */
        "movl %eax, (%esp)\n" /* line 1164 */
        "calll AddRefToObject\n"
        "movl 0xc(%ebp), %eax\n" /* line 1165 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* parentLocalId */
        "calll AllocChildThread\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 1166 | fs */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 1167 */
        "movl (%eax), %edx\n"
        "movl %edx, 8(%ebp)\n" /* fs */
        "subl $8, %eax\n" /* line 1168 */
        "movl %eax, 0x14(%ebp)\n"
        "jmp .Lf840ae_0008470a\n"
        ".Lf840ae_0008663b:\n"
        "movl $0, -0x40(%ebp)\n" /* line 1069 | waitTime */
        "xorl %eax, %eax\n"
        "jmp .Lf840ae_00084230\n"
        ".Lf840ae_00086649:\n"
        "movl %eax, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_000848f8\n"
        ".Lf840ae_00086651:\n"
        "movl (%eax), %esi\n" /* line 1243 | builtinIndex */
        "subl $8, %eax\n" /* line 1244 */
        "movl %eax, 0x14(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* line 1245 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetSelf\n"
        "movl %eax, %ebx\n" /* parentLocalId */
        "movl %eax, (%esp)\n" /* line 1246 */
        "calll AddRefToObject\n"
        "movl %ebx, (%esp)\n" /* line 1247 | parentLocalId */
        "calll AllocThread\n"
        "movl %eax, 0xc(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 1248 | fs */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 1249 */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, 0x10(%eax)\n"
        "movl %esi, 8(%ebp)\n" /* line 1250 | builtinIndex, fs */
        "movl 0x14(%ebp), %ecx\n" /* line 1251 */
        "jmp .Lf840ae_0008498b\n"
        ".Lf840ae_00086699:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2149 */
        "movl 4(%eax), %edx\n"
        "cmpl $8, %edx\n"
        "je .Lf840ae_000866c3\n"
        ".Lf840ae_000866a4:\n"
        "movl (%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 2152 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 2149 */
        "cmpl $8, %edx\n"
        "jne .Lf840ae_000866a4\n"
        ".Lf840ae_000866c3:\n"
        "movl $7, 4(%eax)\n" /* line 2155 */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_000866d2:\n"
        "movl $str_0021cf44, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_000845a5\n"
        ".Lf840ae_000866de:\n"
        "movl %eax, 0x10(%esi)\n" /* builtinIndex */
        "jmp .Lf840ae_00085c81\n"
        ".Lf840ae_000866e6:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "jne .Lf840ae_00086995\n"
        ".Lf840ae_000866f0:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_0008483d\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_0008670f:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf840ae_000864cd\n"
        ".Lf840ae_00086731:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086754\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edi\n"
        "testl %edi, %edi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086754:\n"
        "movl scrVmPub+8, %esi\n" /* line 248 */
        "testl %esi, %esi\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_00084b21\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_00086774:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086797\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086797:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_0008462f\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_000867b7:\n"
        "movl $str_0021cfdc, (%esp)\n" /* line 1428 */
        "calll Com_Printf\n"
        "movl $0, 8(%esp)\n" /* line 1429 */
        "movl 8(%ebp), %eax\n" /* fs */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_PrintPrevCodePos\n"
        "rdtsc\n" /* line 33 */
        "xorl %edx, %edx\n" /* line 5102 */
        "shrdl $2, %edx, %eax\n"
        "movl %eax, scrVmGlob+24\n"
        "movl 0xc(%ebp), %eax\n"
        ".Lf840ae_000867ee:\n"
        "movl %eax, (%esp)\n" /* line 1894 */
        "calll GetSafeParentLocalId\n"
        "movl %eax, %ebx\n" /* pos */
        "movl 0xc(%ebp), %eax\n" /* line 1895 */
        "movl %eax, (%esp)\n"
        "calll Scr_KillThread\n"
        "movl 0x10(%ebp), %eax\n" /* line 1896 */
        "shll $2, %eax\n"
        "subl %eax, scrVmPub\n"
        "movl 0x14(%ebp), %eax\n" /* line 1899 */
        "movl 4(%eax), %edx\n"
        "cmpl $7, %edx\n"
        "je .Lf840ae_00086839\n"
        ".Lf840ae_0008681a:\n"
        "movl (%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 1902 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 1899 */
        "cmpl $7, %edx\n"
        "jne .Lf840ae_0008681a\n"
        ".Lf840ae_00086839:\n"
        "subl $1, scrVmPub+8\n" /* line 1906 */
        "subl $0x18, scrVmPub+12\n" /* line 1907 */
        "testl %ebx, %ebx\n" /* line 1908 | pos */
        "je .Lf840ae_000842dc\n"
        "movl 0xc(%ebp), %eax\n" /* line 1916 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl scrVmPub+12, %edx\n" /* line 1919 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl 8(%edx), %eax\n" /* line 1922 */
        "movl %eax, 0x10(%ebp)\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 1923 | pos */
        "subl $8, 0x14(%ebp)\n" /* line 1924 */
        "movl %ebx, %eax\n" /* pos */
        "jmp .Lf840ae_000867ee\n"
        ".Lf840ae_00086879:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_0008689c\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_0008689c:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_000848a9\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_000868bc:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_000868df\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edi\n"
        "testl %edi, %edi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_000868df:\n"
        "movl scrVmPub+8, %esi\n" /* line 248 */
        "testl %esi, %esi\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_00084c73\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_000868ff:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf840ae_000865d8\n"
        ".Lf840ae_00086921:\n"
        "movl $1, %eax\n"
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf840ae_000865af\n"
        ".Lf840ae_00086943:\n"
        "movl %edx, 8(%ebp)\n" /* line 1729 | fs */
        "movl $0, -0x38(%ebp)\n" /* caseCount */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00086952:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086975\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086975:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_00084bd0\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_00086995:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf840ae_000866f0\n"
        ".Lf840ae_000869b7:\n"
        "movl $str_0021cf44, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_0008481f\n"
        ".Lf840ae_000869c3:\n"
        "movl (%eax), %eax\n" /* line 1693 */
        "movl %eax, (%esp)\n"
        "calll IsValidArrayIndex\n"
        "testb %al, %al\n"
        "je .Lf840ae_000864f4\n"
        "movl 0x14(%ebp), %eax\n" /* line 1695 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetInternalVariableIndex\n"
        "movl %eax, -0x34(%ebp)\n" /* caseValue */
        "jmp .Lf840ae_00085e74\n"
        ".Lf840ae_000869ea:\n"
        "movl $str_0021cf44, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_00084611\n"
        ".Lf840ae_000869f6:\n"
        "movl $str_0021cfa0, (%esp)\n" /* line 1404 */
        "calll Com_Printf\n"
        "movl $0, 8(%esp)\n" /* line 1405 */
        "movl 8(%ebp), %eax\n" /* fs */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_PrintPrevCodePos\n"
        "movl 8(%ebp), %edx\n" /* line 143 | fs */
        "leal 2(%edx), %eax\n" /* line 1407 */
        "movzwl (%edx), %edx\n"
        "subl %edx, %eax\n"
        "movl %eax, 8(%ebp)\n" /* fs */
        "rdtsc\n" /* line 33 */
        "xorl %edx, %edx\n" /* line 5102 */
        "shrdl $2, %edx, %eax\n"
        "movl %eax, scrVmGlob+24\n"
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00086a40:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1719 | currentCodePos */
        "movl %eax, 8(%ebp)\n" /* fs */
        "movl %esi, -0x38(%ebp)\n" /* builtinIndex, caseCount */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00086a4e:\n"
        "movl %eax, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_00084b03\n"
        ".Lf840ae_00086a56:\n"
        "movl $str_0021cf44, 0x10(%edx)\n" /* "script stack overflow (too many embedded function calls)" */
        "jmp .Lf840ae_0008488b\n"
        ".Lf840ae_00086a62:\n"
        "movl $str_0021ced0, 0x10(%edx)\n" /* "function called with too many parameters" */
        "jmp .Lf840ae_00084c55\n"
        ".Lf840ae_00086a6e:\n"
        "movl $0, -0x48(%ebp)\n" /* line 384 | fieldValueId */
        "movl $0, -0x44(%ebp)\n" /* objectId */
        "movl $0, -0x40(%ebp)\n" /* waitTime */
        "xorl %edi, %edi\n" /* opcode */
        "movl $0, -0x38(%ebp)\n" /* caseCount */
        "movl $0, -0x34(%ebp)\n" /* caseValue */
        "movl $0, -0x30(%ebp)\n" /* currentCaseValue */
        "movl $0, -0x2c(%ebp)\n" /* currentCodePos */
        "movl $0, -0x3c(%ebp)\n" /* thread_count */
        ".Lf840ae_00086aa8:\n"
        "movl scrVmGlob+16, %eax\n" /* line 2016 */
        "movl %eax, 0xc(%esp)\n"
        "movl imp_scrVarPub, %ebx\n" /* pos */
        "movl 0x10(%ebx), %eax\n" /* pos */
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* pos */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* fs */
        "movl %eax, (%esp)\n"
        "calll RuntimeError\n"
        "movl $0, 0x10(%ebx)\n" /* line 88 */
        "movl $0, scrVmGlob+16\n" /* line 89 */
        "movl $0, 0x14(%ebx)\n" /* line 90 */
        "leal -0x1f(%edi), %eax\n" /* line 2019 | opcode */
        "cmpl $0x65, %eax\n"
        "ja .Lf840ae_00084116\n"
        "jmpl *.Ljt_840ae_1(, %eax, 4)\n"
        ".Lf840ae_00086afb:\n"
        "movl %eax, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_00085dfd\n"
        ".Lf840ae_00086b03:\n"
        "movl $str_0021d190, 0x10(%edx)\n" /* "cannot create a new local variable in the debugger" */
        "jmp .Lf840ae_00084f31\n"
        ".Lf840ae_00086b0f:\n"
        "movl %eax, 0x10(%edx)\n"
        "jmp .Lf840ae_00084783\n"
        ".Lf840ae_00086b17:\n"
        "movl %eax, 0x10(%edx)\n"
        "jmp .Lf840ae_000863d8\n"
        ".Lf840ae_00086b1f:\n"
        "movl $str_0021d180, 0x10(%edx)\n" /* "unknown object" */
        "jmp .Lf840ae_00084e23\n"
        ".Lf840ae_00086b2b:\n"
        "movl %eax, 0x10(%edx)\n"
        "jmp .Lf840ae_00084bb2\n"
        ".Lf840ae_00086b33:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "jne .Lf840ae_00086570\n"
        "jmp .Lf840ae_00086590\n"
        ".Lf840ae_00086b45:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086b68\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086b68:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_00084d58\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_00086b87:\n"
        "movl %eax, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_0008651a\n"
        ".Lf840ae_00086b8f:\n"
        "movl $str_0021d028, 0x10(%edx)\n" /* "potential infinite loop in script" */
        "jmp .Lf840ae_00084d3a\n"
        ".Lf840ae_00086b9b:\n"
        "movl imp_scrVarPub, %edx\n" /* line 1299 */
        "movl $1, 0x14(%edx)\n"
        "movl 0x10(%edx), %eax\n" /* line 4922 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_00086bb6\n"
        "movl $str_0021cf44, 0x10(%edx)\n" /* line 4923 */
        ".Lf840ae_00086bb6:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00086bcb\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_0008700c\n"
        ".Lf840ae_00086bcb:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00086bf4\n"
        ".Lf840ae_00086bd4:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00086bf4:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1937 */
        "movl 4(%eax), %edx\n"
        ".Lf840ae_00086bfa:\n"
        "movl imp_scrVarPub, %eax\n" /* line 1949 */
        "movl $2, 0x14(%eax)\n"
        ".Lf840ae_00086c06:\n"
        "movl imp_var_typename, %eax\n" /* line 1956 */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d1c4, (%esp)\n" /* "%s is not an object" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %esi\n" /* builtinIndex */
        "testl %esi, %esi\n" /* builtinIndex */
        "je .Lf840ae_00086c78\n"
        ".Lf840ae_00086c2b:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00086c3c\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086c7d\n"
        ".Lf840ae_00086c3c:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00086c65\n"
        ".Lf840ae_00086c45:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00086c65:\n"
        "leal -0x21(%edi), %eax\n" /* line 1963 | opcode */
        "cmpl $0x63, %eax\n"
        "ja .Lf840ae_00086aa8\n"
        "jmpl *.Ljt_840ae_2(, %eax, 4)\n"
        ".Lf840ae_00086c78:\n"
        "movl %eax, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_00086c2b\n"
        ".Lf840ae_00086c7d:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086ca0\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %ebx\n" /* result */
        "testl %ebx, %ebx\n" /* result */
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086ca0:\n"
        "movl scrVmPub+8, %ecx\n" /* line 248 */
        "testl %ecx, %ecx\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf840ae_00086c45\n"
        "jmp .Lf840ae_000861be\n"
        ".Lf840ae_00086cbc:\n"
        "movl imp_scrVarPub, %ecx\n" /* line 1993 */
        "movl 0x14(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf840ae_00086aa8\n"
        "movl scrVmPub+28, %eax\n" /* line 1994 */
        "subl %edx, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "jmp .Lf840ae_00086aa8\n"
        ".Lf840ae_00086cdf:\n"
        "movl imp_scrVarPub, %ecx\n" /* line 2007 */
        "movl 0x14(%ecx), %edx\n"
        "cmpl $0, %edx\n"
        "jle .Lf840ae_00086d2c\n"
        "movl scrVmPub+28, %eax\n" /* line 2008 */
        "subl %edx, %eax\n"
        "addl $2, %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "jmp .Lf840ae_00086aa8\n"
        ".Lf840ae_00086cff:\n"
        "movl imp_scrVarPub, %eax\n" /* line 1982 */
        "movl $0, 0x14(%eax)\n"
        "jmp .Lf840ae_00086aa8\n"
        ".Lf840ae_00086d10:\n"
        "movl imp_scrVarPub, %eax\n" /* line 1971 */
        "movl 0x14(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jns .Lf840ae_00086aa8\n"
        "movl $1, 0x14(%eax)\n" /* line 1972 */
        "jmp .Lf840ae_00086aa8\n"
        ".Lf840ae_00086d2c:\n"
        "jge .Lf840ae_00086aa8\n" /* line 2009 */
        "movl $1, 0x14(%ecx)\n" /* line 2010 */
        "jmp .Lf840ae_00086aa8\n"
        ".Lf840ae_00086d3e:\n"
        "movl imp_scrVarPub, %ebx\n" /* line 297 | result */
        "movl 0x34(%ebx), %eax\n" /* result */
        "movl %eax, (%esp)\n"
        "calll ClearVariableValue\n"
        "movl 0x34(%ebx), %ebx\n" /* line 298 | result */
        "movl %ebx, -0x48(%ebp)\n" /* result, fieldValueId */
        "jmp .Lf840ae_00084ce4\n"
        ".Lf840ae_00086d5a:\n"
        "movl 0x14(%ebp), %edx\n" /* line 2141 | value */
        /* { scope 2 */
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 2142 */
        "leal -8(%eax), %edx\n"
        "movl %edx, 0x14(%ebp)\n"
        "movl -8(%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        ".Lf840ae_00086d89:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2144 */
        ".Lf840ae_00086d8c:\n"
        "movl $0, 4(%eax)\n" /* line 2096 */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00086d9b:\n"
        "addl $8, %eax\n" /* line 1619 */
        "movl %eax, 0x14(%ebp)\n"
        "movl imp_scrVarPub, %edx\n" /* line 1620 */
        "movl $1, 0x14(%edx)\n"
        "movl 0x10(%edx), %ecx\n" /* line 4922 */
        "testl %ecx, %ecx\n"
        "jne .Lf840ae_00086dbc\n"
        "movl $str_0021d0e4, 0x10(%edx)\n" /* line 4923 */
        ".Lf840ae_00086dbc:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00086dd1\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086e77\n"
        ".Lf840ae_00086dd1:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00086dfa\n"
        ".Lf840ae_00086dda:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00086dfa:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1941 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVarType\n"
        "movl %eax, %edx\n"
        "jmp .Lf840ae_00086bfa\n"
        ".Lf840ae_00086e0e:\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf840ae_00086e22\n"
        "movl $str_0021cf44, 0x10(%edx)\n" /* line 4923 */
        ".Lf840ae_00086e22:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00086e37\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_00086eb9\n"
        ".Lf840ae_00086e37:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00086e60\n"
        ".Lf840ae_00086e40:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00086e60:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1929 */
        "movl 4(%eax), %edx\n"
        ".Lf840ae_00086e66:\n"
        "movl imp_scrVarPub, %eax\n" /* line 1945 */
        "movl $1, 0x14(%eax)\n"
        "jmp .Lf840ae_00086c06\n"
        ".Lf840ae_00086e77:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086e9a\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086e9a:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        "jmp .Lf840ae_00086dda\n"
        ".Lf840ae_00086eb9:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00086edc\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00086edc:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        "jmp .Lf840ae_00086e40\n"
        ".Lf840ae_00086efc:\n"
        "addl $1, 8(%ebp)\n" /* line 2041 | fs */
        ".Lf840ae_00086f00:\n"
        "movl imp_scrVarPub, %ebx\n" /* line 290 | result */
        "movl 0x34(%ebx), %eax\n" /* result */
        "movl %eax, (%esp)\n"
        "calll ClearVariableValue\n"
        "movl 0x34(%ebx), %eax\n" /* line 291 | result */
        "movl %eax, (%esp)\n"
        "calll GetObjectA\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00086f27:\n"
        "addl $8, 0x14(%ebp)\n" /* line 760 */
        "addl $2, 8(%ebp)\n" /* line 144 | fs */
        ".Lf840ae_00086f2f:\n"
        "movl -0x44(%ebp), %eax\n" /* line 1953 | objectId */
        "movl %eax, (%esp)\n"
        "calll GetVarType\n"
        "movl %eax, %edx\n"
        "jmp .Lf840ae_00086c06\n"
        ".Lf840ae_00086f41:\n"
        "movl %edx, 0x14(%ebp)\n" /* line 1579 */
        "movl imp_scrVarPub, %edx\n" /* line 1580 */
        "movl $3, 0x14(%edx)\n"
        "movl 0x10(%edx), %ebx\n" /* line 4922 | pos */
        "testl %ebx, %ebx\n" /* pos */
        "jne .Lf840ae_00086dbc\n"
        "movl $str_0021d0ac, 0x10(%edx)\n" /* line 4923 */
        "jmp .Lf840ae_00086dbc\n"
        ".Lf840ae_00086f68:\n"
        "movl imp_scrVarPub, %ebx\n" /* line 297 | result */
        "movl 0x34(%ebx), %eax\n" /* result */
        "movl %eax, (%esp)\n"
        "calll ClearVariableValue\n"
        "movl 0x34(%ebx), %ebx\n" /* line 298 | result */
        "movl %ebx, -0x48(%ebp)\n" /* result, fieldValueId */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00086f87:\n"
        "movl scrVmPub+28, %eax\n" /* line 2054 */
        "testl %eax, %eax\n"
        "je .Lf840ae_00084116\n"
        "movl $0, scrVmPub+28\n" /* line 2059 */
        "movl 8(%ebp), %ecx\n" /* fs */
        "jmp .Lf840ae_00084119\n"
        ".Lf840ae_00086fa6:\n"
        "movl imp_scrVarPub, %edx\n" /* line 4922 */
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf840ae_00086fba\n"
        "movl $str_0021d118, 0x10(%edx)\n" /* line 4923 */
        ".Lf840ae_00086fba:\n"
        "cmpb $0, 0xc(%edx)\n" /* line 221 */
        "jne .Lf840ae_00086fcf\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf840ae_0008704f\n"
        ".Lf840ae_00086fcf:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf840ae_00086ff8\n"
        ".Lf840ae_00086fd8:\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf840ae_00086ff8:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1933 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVarType\n"
        "movl %eax, %edx\n"
        "jmp .Lf840ae_00086e66\n"
        ".Lf840ae_0008700c:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_0008702f\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_0008702f:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        "jmp .Lf840ae_00086bd4\n"
        ".Lf840ae_0008704f:\n"
        "cmpb $0, 0xa(%edx)\n" /* line 243 */
        "je .Lf840ae_00087072\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf840ae_00087072:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 | result */
        "testl %ebx, %ebx\n" /* result */
        "jne .Lf840ae_000861be\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf840ae_000861be\n"
        "jmp .Lf840ae_00086fd8\n"
        ".Lf840ae_00087092:\n"
        "movl scrVmPub+28, %edi\n" /* line 2069 | opcode */
        "testl %edi, %edi\n" /* opcode */
        "je .Lf840ae_00084a3a\n"
        ".Lf840ae_000870a0:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2074 | value */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 252 */
        "movl %edx, 4(%esp)\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        /* } scope */
        "movl $0, scrVmPub+28\n" /* line 2075 */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_000870c3:\n"
        "movl scrVmPub+28, %ecx\n" /* line 279 */
        "testl %ecx, %ecx\n"
        "jne .Lf840ae_00087114\n"
        ".Lf840ae_000870cd:\n"
        "movl scrVmPub+16, %eax\n" /* line 2095 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "jmp .Lf840ae_00086d8c\n"
        ".Lf840ae_000870dd:\n"
        "addl $4, 8(%ebp)\n" /* line 157 | fs */
        ".Lf840ae_000870e1:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2167 */
        "movl 4(%eax), %edx\n"
        "cmpl $8, %edx\n"
        "je .Lf840ae_00086d8c\n"
        ".Lf840ae_000870f0:\n"
        "movl (%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 2170 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 2167 */
        "cmpl $8, %edx\n"
        "jne .Lf840ae_000870f0\n"
        "jmp .Lf840ae_00086d8c\n"
        ".Lf840ae_00087114:\n"
        "movl scrVmPub+16, %edx\n" /* line 281 */
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "subl $8, scrVmPub+16\n" /* line 282 */
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf840ae_00087114\n"
        "jmp .Lf840ae_000870cd\n"
        ".Lf840ae_00087145:\n"
        "addl $4, 8(%ebp)\n" /* line 157 | fs */
        /* { scope 2 */
        ".Lf840ae_00087149:\n"
        "movl 8(%ebp), %eax\n" /* line 156 | fs */
        "movl (%eax), %edx\n"
        "addl $4, %eax\n" /* line 157 */
        "movl %eax, 8(%ebp)\n" /* fs */
        /* } scope */
        "movl %edx, %esi\n" /* line 2183 | builtinIndex */
        "testl %edx, %edx\n" /* line 2184 */
        "jne .Lf840ae_000871ed\n"
        ".Lf840ae_0008715e:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2190 */
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "jmp .Lf840ae_00086d8c\n"
        ".Lf840ae_0008716c:\n"
        "movl imp_scrVarPub, %ebx\n" /* line 290 | result */
        "movl 0x34(%ebx), %eax\n" /* result */
        "movl %eax, (%esp)\n"
        "calll ClearVariableValue\n"
        "movl 0x34(%ebx), %eax\n" /* line 291 | result */
        "movl %eax, (%esp)\n"
        "calll GetObjectA\n"
        "movl %eax, -0x44(%ebp)\n" /* objectId */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_00087190:\n"
        "addl $1, 8(%ebp)\n" /* line 2105 | fs */
        ".Lf840ae_00087194:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2110 | value */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 252 */
        "movl %edx, 4(%esp)\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        /* } scope */
        "subl $8, 0x14(%ebp)\n" /* line 2111 */
        "jmp .Lf840ae_00084ce4\n"
        ".Lf840ae_000871b1:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2203 */
        "movl 4(%eax), %edx\n"
        "cmpl $8, %edx\n"
        "je .Lf840ae_00084ce4\n"
        ".Lf840ae_000871c0:\n"
        "movl (%eax), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl 0x14(%ebp), %eax\n" /* line 2206 */
        "subl $8, %eax\n"
        "movl %eax, 0x14(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 2203 */
        "cmpl $8, %edx\n"
        "jne .Lf840ae_000871c0\n"
        "jmp .Lf840ae_00084ce4\n"
        ".Lf840ae_000871e4:\n"
        "addl $2, 8(%ebp)\n" /* line 144 | fs */
        "jmp .Lf840ae_00084a3a\n"
        ".Lf840ae_000871ed:\n"
        "xorl %ebx, %ebx\n" /* line 2184 | pos */
        ".Lf840ae_000871ef:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2186 | value */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 252 */
        "movl %edx, 4(%esp)\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        /* } scope */
        "subl $8, 0x14(%ebp)\n" /* line 2187 */
        "addl $1, %ebx\n" /* pos */
        "cmpl %ebx, %esi\n" /* line 2184 | pos, builtinIndex */
        "jne .Lf840ae_000871ef\n"
        "jmp .Lf840ae_0008715e\n"
        ".Lf840ae_00087213:\n"
        "movl 8(%ebp), %eax\n" /* line 143 | fs */
        "leal 2(%eax), %edx\n" /* line 2101 */
        "movzwl (%eax), %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, 8(%ebp)\n" /* fs */
        "movl %edx, %ecx\n"
        "jmp .Lf840ae_00084119\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_840ae_0:\n"
        ".long .Lf840ae_00085668\n"
        ".long .Lf840ae_000855d4\n"
        ".long .Lf840ae_0008452e\n"
        ".long .Lf840ae_00085554\n"
        ".long .Lf840ae_00084fba\n"
        ".long .Lf840ae_00085085\n"
        ".long .Lf840ae_00084fe1\n"
        ".long .Lf840ae_0008500a\n"
        ".long .Lf840ae_00085035\n"
        ".long .Lf840ae_0008505d\n"
        ".long .Lf840ae_000850ae\n"
        ".long .Lf840ae_000850e4\n"
        ".long .Lf840ae_000850f6\n"
        ".long .Lf840ae_0008511c\n"
        ".long .Lf840ae_0008512f\n"
        ".long .Lf840ae_00085142\n"
        ".long .Lf840ae_00085177\n"
        ".long .Lf840ae_000851a8\n"
        ".long .Lf840ae_000851be\n"
        ".long .Lf840ae_000851ef\n"
        ".long .Lf840ae_00085204\n"
        ".long .Lf840ae_00085217\n"
        ".long .Lf840ae_0008522c\n"
        ".long .Lf840ae_00085264\n"
        ".long .Lf840ae_000852a7\n"
        ".long .Lf840ae_000852bc\n"
        ".long .Lf840ae_00085441\n"
        ".long .Lf840ae_00085457\n"
        ".long .Lf840ae_0008546d\n"
        ".long .Lf840ae_00085483\n"
        ".long .Lf840ae_0008540c\n"
        ".long .Lf840ae_00084a96\n"
        ".long .Lf840ae_00084ac3\n"
        ".long .Lf840ae_000853fb\n"
        ".long .Lf840ae_00085536\n"
        ".long .Lf840ae_00084db0\n"
        ".long .Lf840ae_000854fd\n"
        ".long .Lf840ae_00085514\n"
        ".long .Lf840ae_00085499\n"
        ".long .Lf840ae_000854bc\n"
        ".long .Lf840ae_000854f0\n"
        ".long .Lf840ae_00084a46\n"
        ".long .Lf840ae_00084a64\n"
        ".long .Lf840ae_000853ca\n"
        ".long .Lf840ae_00084546\n"
        ".long .Lf840ae_00085396\n"
        ".long .Lf840ae_00084551\n"
        ".long .Lf840ae_00085575\n"
        ".long .Lf840ae_000849ea\n"
        ".long .Lf840ae_00084a1a\n"
        ".long .Lf840ae_00085331\n"
        ".long .Lf840ae_00084b58\n"
        ".long .Lf840ae_00085363\n"
        ".long .Lf840ae_00084c37\n"
        ".long .Lf840ae_00084c93\n"
        ".long .Lf840ae_000849ca\n"
        ".long .Lf840ae_000852d2\n"
        ".long .Lf840ae_00084c20\n"
        ".long .Lf840ae_00085d12\n"
        ".long .Lf840ae_00085d2f\n"
        ".long .Lf840ae_00085d5c\n"
        ".long .Lf840ae_00085d64\n"
        ".long .Lf840ae_00084341\n"
        ".long .Lf840ae_00085bc9\n"
        ".long .Lf840ae_00085cf4\n"
        ".long .Lf840ae_00085d03\n"
        ".long .Lf840ae_00085bd8\n"
        ".long .Lf840ae_00085be7\n"
        ".long .Lf840ae_00084335\n"
        ".long .Lf840ae_00084169\n"
        ".long .Lf840ae_00085bf6\n"
        ".long .Lf840ae_00085cc7\n"
        ".long .Lf840ae_00085cd6\n"
        ".long .Lf840ae_00085ce5\n"
        ".long .Lf840ae_00085f01\n"
        ".long .Lf840ae_0008415d\n"
        ".long .Lf840ae_0008420d\n"
        ".long .Lf840ae_0008448d\n"
        ".long .Lf840ae_00084131\n"
        ".long .Lf840ae_00084577\n"
        ".long .Lf840ae_00084587\n"
        ".long .Lf840ae_000845e3\n"
        ".long .Lf840ae_000846bc\n"
        ".long .Lf840ae_00085f10\n"
        ".long .Lf840ae_000847fa\n"
        ".long .Lf840ae_0008485d\n"
        ".long .Lf840ae_00084936\n"
        ".long .Lf840ae_00085f69\n"
        ".long .Lf840ae_00084ce4\n"
        ".long .Lf840ae_00085fcb\n"
        ".long .Lf840ae_000856fd\n"
        ".long .Lf840ae_00085724\n"
        ".long .Lf840ae_00085737\n"
        ".long .Lf840ae_0008574a\n"
        ".long .Lf840ae_0008575d\n"
        ".long .Lf840ae_0008578c\n"
        ".long .Lf840ae_000857b2\n"
        ".long .Lf840ae_000857e3\n"
        ".long .Lf840ae_0008559c\n"
        ".long .Lf840ae_000855ac\n"
        ".long .Lf840ae_00084d78\n"
        ".long .Lf840ae_00084bf0\n"
        ".long .Lf840ae_00084b41\n"
        ".long .Lf840ae_00085d8b\n"
        ".long .Lf840ae_00085303\n"
        ".long .Lf840ae_0008531a\n"
        ".long .Lf840ae_00085809\n"
        ".long .Lf840ae_00085820\n"
        ".long .Lf840ae_00085837\n"
        ".long .Lf840ae_0008584e\n"
        ".long .Lf840ae_00085865\n"
        ".long .Lf840ae_0008587c\n"
        ".long .Lf840ae_00085893\n"
        ".long .Lf840ae_000858aa\n"
        ".long .Lf840ae_000858c1\n"
        ".long .Lf840ae_000858d8\n"
        ".long .Lf840ae_000858ef\n"
        ".long .Lf840ae_00085906\n"
        ".long .Lf840ae_0008591d\n"
        ".long .Lf840ae_00085930\n"
        ".long .Lf840ae_00085930\n"
        ".long .Lf840ae_00085a41\n"
        ".long .Lf840ae_00085adc\n"
        ".long .Lf840ae_00084131\n"
        ".long .Lf840ae_00085da2\n"
        ".long .Lf840ae_00085ec3\n"
        ".long .Lf840ae_00085ed7\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00085ef0\n"
        ".long .Lf840ae_00084dd2\n"
        ".long .Lf840ae_00084ea9\n"
        ".long .Lf840ae_00084ec3\n"
        ".long .Lf840ae_00084efd\n"
        ".long .Lf840ae_00084b7d\n"
        ".long .Lf840ae_000849dd\n"
        ".text\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_840ae_1:\n"
        ".long .Lf840ae_00086d5a\n"
        ".long .Lf840ae_00086d5a\n"
        ".long .Lf840ae_00086d3e\n"
        ".long .Lf840ae_00086d3e\n"
        ".long .Lf840ae_00086d3e\n"
        ".long .Lf840ae_00084ce4\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00086f00\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00086d89\n"
        ".long .Lf840ae_00086d89\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00086f68\n"
        ".long .Lf840ae_00086f68\n"
        ".long .Lf840ae_00086f87\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00086699\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00087092\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_000870a0\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_000870c3\n"
        ".long .Lf840ae_00084ce4\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_000870dd\n"
        ".long .Lf840ae_000870dd\n"
        ".long .Lf840ae_000870e1\n"
        ".long .Lf840ae_000870dd\n"
        ".long .Lf840ae_000870e1\n"
        ".long .Lf840ae_00087145\n"
        ".long .Lf840ae_00087149\n"
        ".long .Lf840ae_00087145\n"
        ".long .Lf840ae_00087149\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_0008716c\n"
        ".long .Lf840ae_00086efc\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_000871e4\n"
        ".long .Lf840ae_000871e4\n"
        ".long .Lf840ae_000871e4\n"
        ".long .Lf840ae_000871e4\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00087213\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084a3a\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00087190\n"
        ".long .Lf840ae_00087194\n"
        ".long .Lf840ae_000871b1\n"
        ".long .Lf840ae_00087194\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084ca5\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00084116\n"
        ".long .Lf840ae_00086d3e\n"
        ".text\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_840ae_2:\n"
        ".long .Lf840ae_00086d10\n"
        ".long .Lf840ae_00086d10\n"
        ".long .Lf840ae_00086d10\n"
        ".long .Lf840ae_00086d10\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086cff\n"
        ".long .Lf840ae_00086cff\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086cff\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086cff\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086cff\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086cbc\n"
        ".long .Lf840ae_00086cbc\n"
        ".long .Lf840ae_00086cbc\n"
        ".long .Lf840ae_00086cbc\n"
        ".long .Lf840ae_00086cbc\n"
        ".long .Lf840ae_00086cbc\n"
        ".long .Lf840ae_00086cbc\n"
        ".long .Lf840ae_00086cdf\n"
        ".long .Lf840ae_00086cdf\n"
        ".long .Lf840ae_00086cdf\n"
        ".long .Lf840ae_00086cdf\n"
        ".long .Lf840ae_00086cdf\n"
        ".long .Lf840ae_00086cdf\n"
        ".long .Lf840ae_00086cdf\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086cff\n"
        ".long .Lf840ae_00086cff\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086aa8\n"
        ".long .Lf840ae_00086d10\n"
        ".text\n"
    );
}

/* line 3695 */
static __attribute__((naked))
void VM_Resume(unsigned int timeId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3695 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, -0x54(%ebp)\n"
        /* { scope 1: size */
        "rdtsc\n" /* line 33 */
        "xorl %edx, %edx\n" /* line 5102 */
        "shrdl $2, %edx, %eax\n"
        "movl %eax, scrVmGlob+24\n"
        "movl -0x54(%ebp), %eax\n" /* line 3707 */
        "movl %eax, (%esp)\n"
        "calll AddRefToObject\n"
        "jmp .Lf87228_000872f3\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf87228_00087251:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2721 */
        "movl %eax, (%esp)\n"
        "calll FindPrevSibling\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n"
        "jne .Lf87228_000874a6\n"
        "xorl %ebx, %ebx\n" /* localVarCount */
        /* } scope */
        "movl imp_scrVarPub, %eax\n" /* line 2803 */
        "movzbl 0x18(%eax), %eax\n"
        "movl -0x4c(%ebp), %edx\n" /* stackValue */
        "cmpb 0xa(%edx), %al\n"
        "je .Lf87228_000874df\n"
        ".Lf87228_0008727d:\n"
        "rdtsc\n" /* line 33 */
        "xorl %edx, %edx\n" /* line 5102 */
        "shrdl $2, %edx, %eax\n"
        "movl %eax, scrVmGlob+24\n"
        "movl -0x4c(%ebp), %ecx\n" /* stackValue */
        ".Lf87228_0008728d:\n"
        "movzwl 6(%ecx), %eax\n" /* line 2809 */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "movl %ebx, -0x24(%ebp)\n" /* line 3738 | stackId */
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x44(%ebp), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl $scrVmPub+800, -0x1c(%ebp)\n"
        /* } scope */
        "movl %ecx, (%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* stackId */
        "movl %edx, 0xc(%esp)\n"
        "movl $scrVmPub+800, 0x10(%esp)\n"
        "calll VM_Execute\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl scrVmPub+808, %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl scrVmPub+812, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        ".Lf87228_000872f3:\n"
        "movl -0x54(%ebp), %edx\n" /* line 3722 */
        "movl %edx, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n" /* stackId */
        "testl %eax, %eax\n" /* line 3723 */
        "je .Lf87228_000874e6\n"
        "movl %eax, (%esp)\n" /* line 3725 */
        "calll GetVariableKeyObject\n"
        "movl %eax, -0x50(%ebp)\n" /* startLocalId */
        "movl %ebx, (%esp)\n" /* line 3729 | stackId */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* stackValue */
        "movl -0x50(%ebp), %ecx\n" /* line 3730 | startLocalId */
        "movl %ecx, 4(%esp)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveObjectVariable\n"
        /* { scope 2 */
        "movl -0x4c(%ebp), %ecx\n" /* line 2746 | stackValue */
        "movl (%ecx), %edx\n"
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "addl $1, scrVmPub+8\n" /* line 2747 */
        "addl $0x18, scrVmPub+12\n" /* line 2748 */
        "movzwl 4(%ecx), %eax\n" /* line 2750 */
        "movzwl %ax, %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* size */
        "movl -0x4c(%ebp), %ecx\n" /* line 2751 | stackValue */
        "addl $0xb, %ecx\n"
        "testw %ax, %ax\n" /* line 2754 */
        "jne .Lf87228_00087411\n"
        "movl $scrVmPub+800, -0x40(%ebp)\n"
        ".Lf87228_0008736c:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 2774 | stackValue */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x44(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 2777 | stackValue */
        "movzwl 8(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl -0x50(%ebp), %edx\n" /* line 2780 | startLocalId */
        "movl %edx, (%esp)\n"
        "calll Scr_ClearWaitTime\n"
        "movl scrVmPub+8, %eax\n" /* line 2783 */
        "leal (%eax, %eax, 2), %edx\n" /* line 2786 */
        "movl -0x3c(%ebp), %ecx\n"
        "movl %ecx, scrVmPub+36(, %edx, 8)\n"
        "movl %eax, %edi\n" /* line 2788 */
        "subl $1, %edi\n"
        "jne .Lf87228_0008747b\n"
        ".Lf87228_000873a6:\n"
        "addl $1, %edi\n" /* line 2795 */
        "cmpl scrVmPub+8, %edi\n" /* line 2796 */
        "je .Lf87228_00087251\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 2788 */
        "leal scrVmPub+32(, %eax, 8), %esi\n"
        "jmp .Lf87228_000873d8\n"
        /* { scope 3 */
        ".Lf87228_000873c1:\n"
        "xorl %eax, %eax\n" /* line 2721 */
        /* } scope */
        ".Lf87228_000873c3:\n"
        "movl %eax, 8(%esi)\n" /* line 2798 */
        "addl $1, %edi\n" /* line 2795 */
        "addl $0x18, %esi\n"
        "cmpl scrVmPub+8, %edi\n" /* line 2796 */
        "je .Lf87228_00087251\n"
        /* { scope 3 */
        ".Lf87228_000873d8:\n"
        "movl 4(%esi), %eax\n" /* line 2721 */
        "movl %eax, (%esp)\n"
        "calll FindPrevSibling\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n"
        "je .Lf87228_000873c1\n"
        "xorl %ebx, %ebx\n" /* localVarCount */
        ".Lf87228_000873eb:\n"
        "movl scrVmPub, %edx\n" /* line 2723 */
        "leal 4(%edx), %eax\n"
        "movl %eax, scrVmPub\n"
        "movl %ecx, 4(%edx)\n" /* line 2724 */
        "addl $1, %ebx\n" /* line 2725 | localVarCount */
        "movl %ecx, (%esp)\n" /* line 2721 */
        "calll FindPrevSibling\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n"
        "jne .Lf87228_000873eb\n"
        "movl %ebx, %eax\n" /* localVarCount */
        "jmp .Lf87228_000873c3\n"
        /* } scope */
        ".Lf87228_00087411:\n"
        "movl $scrVmPub+812, %esi\n" /* line 3695 */
        "movl -0x4c(%ebp), %ebx\n" /* stackValue, localVarCount */
        "addl $0xc, %ebx\n" /* localVarCount */
        "xorl %edi, %edi\n"
        "jmp .Lf87228_00087437\n"
        ".Lf87228_00087420:\n"
        "movl 1(%ecx), %eax\n" /* line 2769 */
        "movl %eax, -4(%esi)\n"
        "addl $5, %ecx\n" /* line 2771 */
        "addl $1, %edi\n"
        "addl $8, %esi\n"
        "addl $5, %ebx\n" /* localVarCount */
        "cmpl %edi, -0x48(%ebp)\n" /* line 2754 | size */
        "je .Lf87228_0008746c\n"
        ".Lf87228_00087437:\n"
        "movzbl (%ecx), %edx\n" /* line 2758 */
        "movzbl %dl, %eax\n"
        "movl %eax, (%esi)\n"
        "cmpb $7, %dl\n" /* line 2760 */
        "jne .Lf87228_00087420\n"
        "movl (%ebx), %edx\n" /* line 2763 | localVarCount */
        "movl scrVmPub+12, %eax\n"
        "movl %edx, (%eax)\n"
        "addl $1, scrVmPub+8\n" /* line 2764 */
        "addl $0x18, scrVmPub+12\n" /* line 2765 */
        "addl $5, %ecx\n" /* line 2771 */
        "addl $1, %edi\n"
        "addl $8, %esi\n"
        "addl $5, %ebx\n" /* localVarCount */
        "cmpl %edi, -0x48(%ebp)\n" /* line 2754 | size */
        "jne .Lf87228_00087437\n"
        ".Lf87228_0008746c:\n"
        "leal scrVmPub+800(, %edi, 8), %edi\n"
        "movl %edi, -0x40(%ebp)\n"
        "jmp .Lf87228_0008736c\n"
        ".Lf87228_0008747b:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 2796 */
        "leal scrVmPub+32(, %eax, 8), %ebx\n" /* localVarCount */
        "movl -0x3c(%ebp), %eax\n"
        "xorl %esi, %esi\n"
        ".Lf87228_0008748a:\n"
        "movl %eax, (%esp)\n" /* line 2790 */
        "calll GetParentLocalId\n"
        "movl %eax, 4(%ebx)\n" /* line 2786 | localVarCount */
        "addl $1, %esi\n"
        "subl $0x18, %ebx\n" /* localVarCount */
        "cmpl %esi, %edi\n" /* line 2788 */
        "jne .Lf87228_0008748a\n"
        "xorl %edi, %edi\n"
        "jmp .Lf87228_000873a6\n"
        /* { scope 3 */
        ".Lf87228_000874a6:\n"
        "xorl %ebx, %ebx\n" /* line 2721 | localVarCount */
        ".Lf87228_000874a8:\n"
        "movl scrVmPub, %edx\n" /* line 2723 */
        "leal 4(%edx), %eax\n"
        "movl %eax, scrVmPub\n"
        "movl %ecx, 4(%edx)\n" /* line 2724 */
        "addl $1, %ebx\n" /* line 2725 | localVarCount */
        "movl %ecx, (%esp)\n" /* line 2721 */
        "calll FindPrevSibling\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n"
        "jne .Lf87228_000874a8\n"
        /* } scope */
        "movl imp_scrVarPub, %eax\n" /* line 2803 */
        "movzbl 0x18(%eax), %eax\n"
        "movl -0x4c(%ebp), %edx\n" /* stackValue */
        "cmpb 0xa(%edx), %al\n"
        "jne .Lf87228_0008727d\n"
        ".Lf87228_000874df:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf87228_0008728d\n"
        /* } scope */
        ".Lf87228_000874e6:\n"
        "movl -0x54(%ebp), %eax\n" /* line 3753 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl imp_scrVarPub, %eax\n" /* line 3755 */
        "movl 0x34(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ClearVariableValue\n"
        "movl $scrVmPub+800, scrVmPub+16\n" /* line 3756 */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 3757 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5083 */
__attribute__((naked))
void Scr_RunCurrentThreads(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5083 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_scrVarPub, %ebx\n" /* line 4160 */
        "movl 0x1c(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf87514_0008752e\n"
        ".Lf87514_00087528:\n"
        "addl $0x14, %esp\n" /* line 5097 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf87514_0008752e:\n"
        "movl 0x18(%ebx), %eax\n" /* line 4162 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 4163 */
        "je .Lf87514_00087528\n"
        "movl %eax, (%esp)\n" /* line 4172 */
        "calll FindObject\n"
        "calll VM_Resume\n"
        "movl 0x18(%ebx), %eax\n" /* line 4173 */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SafeRemoveVariable\n"
        "addl $0x14, %esp\n" /* line 5097 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5060 */
__attribute__((naked))
void Scr_IncTime(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5060 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_scrVarPub, %ebx\n" /* line 4160 */
        "movl 0x1c(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf87566_00087599\n"
        ".Lf87566_0008757a:\n"
        "calll Scr_FreeEntityList\n" /* line 5063 */
        "movl imp_scrVarPub, %edx\n" /* line 5067 */
        "movl 0x18(%edx), %eax\n"
        "addl $1, %eax\n"
        "andl $g_effectVisArray+4351, %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "addl $0x14, %esp\n" /* line 5072 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf87566_00087599:\n"
        "movl 0x18(%ebx), %eax\n" /* line 4162 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 4163 */
        "je .Lf87566_0008757a\n"
        "movl %eax, (%esp)\n" /* line 4172 */
        "calll FindObject\n"
        "calll VM_Resume\n"
        "movl 0x18(%ebx), %eax\n" /* line 4173 */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SafeRemoveVariable\n"
        "calll Scr_FreeEntityList\n" /* line 5063 */
        "movl imp_scrVarPub, %edx\n" /* line 5067 */
        "movl 0x18(%edx), %eax\n"
        "addl $1, %eax\n"
        "andl $g_effectVisArray+4351, %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "addl $0x14, %esp\n" /* line 5072 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* overload skip: VM_Execute (0x875ea) */

/* line 3993 */
__attribute__((naked))
void Scr_AddExecThread(scr_func_t handle, unsigned int paramcount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3993 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl imp_scrVarPub, %esi\n" /* line 4000 */
        "movl 0x48(%esi), %ebx\n" /* pos */
        "addl 8(%ebp), %ebx\n" /* handle, pos */
        "movl scrVmPub+8, %eax\n" /* line 4006 */
        "testl %eax, %eax\n"
        "jne .Lf877f8_00087825\n"
        "rdtsc\n" /* line 33 */
        "xorl %edx, %edx\n" /* line 5102 */
        "shrdl $2, %edx, %eax\n"
        "shrl $2, %edx\n"
        "movl %eax, scrVmGlob+24\n"
        ".Lf877f8_00087825:\n"
        "movl 0x24(%esi), %eax\n" /* line 4024 */
        "movl %eax, (%esp)\n"
        "calll AddRefToObject\n"
        "movl 0x24(%esi), %eax\n" /* line 4025 */
        "movl %eax, (%esp)\n"
        "calll AllocThread\n"
        "movl 0xc(%ebp), %ecx\n" /* paramcount */
        "movl %ebx, %edx\n" /* pos */
        "calll VM_Execute\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "addl $1, scrVmPub+28\n" /* line 4031 */
        "subl $1, scrVmPub+24\n" /* line 4032 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 4040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3928 */
__attribute__((naked))
scr_thread_t Scr_ExecEntThreadNum(int entnum, int classnum, scr_func_t handle, unsigned int paramcount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3928 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl imp_scrVarPub, %eax\n" /* line 3937 */
        "movl 0x48(%eax), %esi\n" /* pos */
        "addl 0x10(%ebp), %esi\n" /* handle, pos */
        "movl scrVmPub+8, %ebx\n" /* line 3943 | objId */
        "testl %ebx, %ebx\n" /* objId */
        "jne .Lf87862_0008788c\n"
        "rdtsc\n" /* line 33 */
        "xorl %edx, %edx\n" /* line 5102 */
        "shrdl $2, %edx, %eax\n"
        "movl %eax, scrVmGlob+24\n"
        ".Lf87862_0008788c:\n"
        "movl 0xc(%ebp), %eax\n" /* line 3965 | classnum */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* entnum */
        "movl %eax, (%esp)\n"
        "calll Scr_GetEntityId\n"
        "movl %eax, %ebx\n" /* objId */
        "movl %eax, (%esp)\n" /* line 3966 */
        "calll AddRefToObject\n"
        "movl %ebx, (%esp)\n" /* line 3967 | objId */
        "calll AllocThread\n"
        "movl 0x14(%ebp), %ecx\n" /* paramcount */
        "movl %esi, %edx\n" /* pos */
        "calll VM_Execute\n"
        "movl %eax, %ebx\n" /* objId */
        "movl scrVmPub+16, %edx\n" /* line 3977 | value */
        /* { scope 2 */
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        /* } scope */
        "movl scrVmPub+16, %eax\n" /* line 3978 */
        "movl $0, 4(%eax)\n"
        "subl $8, scrVmPub+16\n" /* line 3979 */
        "subl $1, scrVmPub+24\n" /* line 3980 */
        "movzwl %bx, %ebx\n" /* objId */
        /* } scope */
        "movl %ebx, %eax\n" /* line 3990 | objId */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3865 */
__attribute__((naked))
scr_thread_t Scr_ExecThread(scr_func_t handle, unsigned int paramcount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3865 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl imp_scrVarPub, %esi\n" /* line 3873 */
        "movl 0x48(%esi), %ebx\n" /* pos */
        "addl 8(%ebp), %ebx\n" /* handle, pos */
        "movl scrVmPub+8, %eax\n" /* line 3879 */
        "testl %eax, %eax\n"
        "jne .Lf878fa_00087927\n"
        "rdtsc\n" /* line 33 */
        "xorl %edx, %edx\n" /* line 5102 */
        "shrdl $2, %edx, %eax\n"
        "shrl $2, %edx\n"
        "movl %eax, scrVmGlob+24\n"
        ".Lf878fa_00087927:\n"
        "movl %ebx, (%esp)\n" /* line 3894 | pos */
        "calll Scr_IsInOpcodeMemory\n"
        "movl 0x24(%esi), %eax\n" /* line 3901 */
        "movl %eax, (%esp)\n"
        "calll AddRefToObject\n"
        "movl 0x24(%esi), %eax\n" /* line 3902 */
        "movl %eax, (%esp)\n"
        "calll AllocThread\n"
        "movl 0xc(%ebp), %ecx\n" /* paramcount */
        "movl %ebx, %edx\n" /* pos */
        "calll VM_Execute\n"
        "movl %eax, %ebx\n" /* pos */
        "movl scrVmPub+16, %edx\n" /* line 3912 | value */
        /* { scope 2 */
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        /* } scope */
        "movl scrVmPub+16, %eax\n" /* line 3913 */
        "movl $0, 4(%eax)\n"
        "subl $8, scrVmPub+16\n" /* line 3914 */
        "subl $1, scrVmPub+24\n" /* line 3915 */
        "movzwl %bx, %ebx\n" /* pos */
        /* } scope */
        "movl %ebx, %eax\n" /* line 3925 | pos */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4619 */
__attribute__((naked))
const char * Scr_GetIString(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4619 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edx\n" /* index */
        /* { scope 1 */
        "cmpl scrVmPub+28, %edx\n" /* line 4606 */
        "jae .Lf8798e_00087b52\n"
        "leal (, %edx, 8), %eax\n" /* line 4608 */
        "movl scrVmPub+16, %ecx\n"
        "subl %eax, %ecx\n"
        "cmpl $3, 4(%ecx)\n" /* line 4609 */
        "je .Lf8798e_00087adc\n"
        "leal 1(%edx), %esi\n" /* line 4611 */
        "movl imp_scrVarPub, %ebx\n"
        "movl %esi, 0x14(%ebx)\n"
        "movl 4(%ecx), %eax\n" /* line 4612 */
        "movl imp_var_typename, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021ce7c, (%esp)\n" /* "type %s is not a localized string" */
        "calll va\n"
        "movl 0x10(%ebx), %ecx\n" /* line 4922 */
        "testl %ecx, %ecx\n"
        "je .Lf8798e_00087b7e\n"
        ".Lf8798e_000879f1:\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 221 */
        "jne .Lf8798e_00087aec\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf8798e_00087aec\n"
        "cmpb $0, 0xa(%ebx)\n" /* line 243 */
        "jne .Lf8798e_00087b86\n"
        ".Lf8798e_00087a14:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf8798e_00087abd\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf8798e_00087abd\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf8798e_00087a4e:\n"
        "movl %esi, 4(%esp)\n" /* line 4614 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf8798e_00087b76\n"
        ".Lf8798e_00087a6f:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf8798e_00087b1e\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf8798e_00087b1e\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf8798e_00087aab\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf8798e_00087aab:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf8798e_00087abd\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf8798e_00087b27\n"
        ".Lf8798e_00087abd:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf8798e_00087adc:\n"
        "movl (%ecx), %eax\n" /* line 4610 */
        /* } scope */
        "movl %eax, 8(%ebp)\n" /* line 4621 | index */
        "addl $0x10, %esp\n" /* line 4622 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp SL_ConvertToString\n" /* line 4621 */
        /* { scope 1 */
        ".Lf8798e_00087aec:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf8798e_00087a4e\n"
        "movl imp_scrVarPub, %eax\n" /* line 263 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf8798e_00087a4e\n"
        ".Lf8798e_00087b1e:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf8798e_00087b42\n"
        ".Lf8798e_00087b27:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf8798e_00087b42:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "movl %eax, 8(%ebp)\n" /* line 4621 | index */
        "addl $0x10, %esp\n" /* line 4622 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp SL_ConvertToString\n" /* line 4621 */
        /* { scope 1 */
        ".Lf8798e_00087b52:\n"
        "leal 1(%edx), %esi\n" /* line 4606 */
        "movl %esi, 4(%esp)\n" /* line 4614 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf8798e_00087a6f\n"
        ".Lf8798e_00087b76:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf8798e_00087a6f\n"
        ".Lf8798e_00087b7e:\n"
        "movl %eax, 0x10(%ebx)\n"
        "jmp .Lf8798e_000879f1\n"
        ".Lf8798e_00087b86:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf8798e_00087a14\n"
    );
}

/* line 4411 */
__attribute__((naked))
scr_anim_t Scr_GetAnim(unsigned int index, struct XAnimTree_s *tree)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4411 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 4416 | index */
        "cmpl %eax, scrVmPub+28\n"
        "jbe .Lf87ba8_00087e33\n"
        "shll $3, %eax\n" /* line 4418 */
        "movl scrVmPub+16, %esi\n" /* value */
        "subl %eax, %esi\n" /* value */
        "movl 4(%esi), %edx\n" /* line 4419 | value */
        "cmpl $0xb, %edx\n"
        "je .Lf87ba8_00087d24\n"
        "movl imp_var_typename, %eax\n" /* line 4428 */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d1d8, (%esp)\n" /* "type %s is not an anim" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n"
        "movl %eax, 0x10(%edx)\n"
        ".Lf87ba8_00087bf8:\n"
        "movl (%esi), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl $0, 4(%esi)\n" /* line 4431 | value */
        "movl 8(%ebp), %ebx\n" /* line 4433 | index */
        "addl $1, %ebx\n"
        "movl imp_scrVarPub, %ecx\n"
        "movl %ebx, 0x14(%ecx)\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf87ba8_00087dc1\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf87ba8_00087dc1\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf87ba8_00087c5b\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edi\n"
        "testl %edi, %edi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf87ba8_00087c5b:\n"
        "movl scrVmPub+8, %esi\n" /* line 248 */
        "testl %esi, %esi\n"
        "jne .Lf87ba8_00087d05\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf87ba8_00087d05\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf87ba8_00087c91:\n"
        "movl %ebx, 4(%esp)\n" /* line 4436 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf87ba8_00087e59\n"
        ".Lf87ba8_00087cb2:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf87ba8_00087dee\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf87ba8_00087dee\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf87ba8_00087cee\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edi\n"
        "testl %edi, %edi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf87ba8_00087cee:\n"
        "movl scrVmPub+8, %esi\n" /* line 248 */
        "testl %esi, %esi\n"
        "jne .Lf87ba8_00087d05\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf87ba8_00087df7\n"
        ".Lf87ba8_00087d05:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf87ba8_00087d24:\n"
        "movl (%esi), %eax\n" /* line 4421 | value */
        "movw %ax, -0x1a(%ebp)\n"
        "shrl $0x10, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* line 4422 | tree */
        "testl %edx, %edx\n"
        "je .Lf87ba8_00087e61\n"
        "movzwl %ax, %edi\n"
        "movl %edi, (%esp)\n"
        "calll Scr_GetAnims\n"
        "movl %eax, %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* tree */
        "movl %edx, (%esp)\n"
        "calll XAnimGetAnims\n"
        "cmpl %eax, %ebx\n"
        "je .Lf87ba8_00087e1a\n"
        "movl 0xc(%ebp), %eax\n" /* line 4424 | tree */
        "movl %eax, (%esp)\n"
        "calll XAnimGetAnims\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetAnimTreeDebugName\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edi, (%esp)\n"
        "calll Scr_GetAnims\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetAnimTreeDebugName\n"
        "movl %eax, %ebx\n"
        "movl %edi, (%esp)\n"
        "calll Scr_GetAnims\n"
        "movzwl -0x1a(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimGetAnimDebugName\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d1f0, (%esp)\n" /* "anim '%s' in animtree '%s' does not belong to the entity's a" */
        "calll va\n"
        "movl imp_scrVarPub, %edx\n"
        "movl %eax, 0x10(%edx)\n"
        "jmp .Lf87ba8_00087bf8\n"
        ".Lf87ba8_00087dc1:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf87ba8_00087c91\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf87ba8_00087c91\n"
        ".Lf87ba8_00087dee:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf87ba8_00087e12\n"
        ".Lf87ba8_00087df7:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf87ba8_00087e12:\n"
        "movw $0, -0x1a(%ebp)\n"
        "xorl %edi, %edi\n"
        ".Lf87ba8_00087e1a:\n"
        "shll $0x10, %edi\n"
        "andl $0xffff, %ebx\n"
        "orl %edi, %ebx\n"
        "movw -0x1a(%ebp), %bx\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 4440 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf87ba8_00087e33:\n"
        "movl %eax, %ebx\n" /* line 4416 */
        "addl $1, %ebx\n"
        "movl %ebx, 4(%esp)\n" /* line 4436 */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf87ba8_00087cb2\n"
        ".Lf87ba8_00087e59:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf87ba8_00087cb2\n"
        ".Lf87ba8_00087e61:\n"
        "movzwl %ax, %edi\n"
        "shll $0x10, %edi\n" /* line 263 */
        "andl $0xffff, %ebx\n"
        "orl %edi, %ebx\n"
        "movw -0x1a(%ebp), %bx\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 4440 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4497 */
__attribute__((naked))
unsigned int Scr_GetConstString(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4497 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* index */
        /* { scope 1 */
        "cmpl %esi, scrVmPub+28\n" /* line 4501 | index */
        "ja .Lf87e80_00087eee\n"
        "leal 1(%esi), %ebx\n" /* index, value */
        ".Lf87e80_00087e96:\n"
        "movl %ebx, 4(%esp)\n" /* line 4515 | value */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf87e80_00087f6c\n"
        ".Lf87e80_00087eb7:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "je .Lf87e80_00087f79\n"
        ".Lf87e80_00087ec1:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf87e80_00087ee5\n"
        ".Lf87e80_00087eca:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf87e80_00087ee5:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 4517 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf87e80_00087eee:\n"
        "leal (, %esi, 8), %eax\n" /* line 4503 */
        "movl scrVmPub+16, %ebx\n" /* value */
        "subl %eax, %ebx\n" /* value */
        "movl %ebx, (%esp)\n" /* line 4504 | value */
        "calll Scr_CastString\n"
        "testb %al, %al\n"
        "jne .Lf87e80_00087fe1\n"
        "leal 1(%esi), %ebx\n" /* line 4512 | index, value */
        "movl imp_scrVarPub, %ecx\n"
        "movl %ebx, 0x14(%ecx)\n" /* value */
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "je .Lf87e80_00087fea\n"
        ".Lf87e80_00087f23:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf87e80_00087e96\n"
        ".Lf87e80_00087f30:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl %ebx, 4(%esp)\n" /* line 4515 | value */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf87e80_00087eb7\n"
        ".Lf87e80_00087f6c:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf87e80_00087ec1\n"
        ".Lf87e80_00087f79:\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf87e80_00087ec1\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "je .Lf87e80_00087fab\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %esi\n"
        "testl %esi, %esi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        ".Lf87e80_00087fab:\n"
        "movl scrVmPub+8, %ebx\n" /* line 248 */
        "testl %ebx, %ebx\n"
        "jne .Lf87e80_00087fc2\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf87e80_00087eca\n"
        ".Lf87e80_00087fc2:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf87e80_00087fe1:\n"
        "movl (%ebx), %eax\n" /* line 4510 | value */
        /* } scope */
        "addl $0x10, %esp\n" /* line 4517 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf87e80_00087fea:\n"
        "movl imp_scrCompilePub, %eax\n" /* line 221 */
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf87e80_00087f23\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf87e80_00088017\n"
        ".Lf87e80_00087fff:\n"
        "movl scrVmPub+8, %esi\n" /* line 248 */
        "testl %esi, %esi\n"
        "jne .Lf87e80_00087fc2\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf87e80_00087fc2\n"
        "jmp .Lf87e80_00087f30\n"
        ".Lf87e80_00088017:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf87e80_00087fff\n"
    );
}

/* line 4569 */
__attribute__((naked))
unsigned int Scr_GetConstStringIncludeNull(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4569 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* index */
        "cmpl %ecx, scrVmPub+28\n" /* line 4571 */
        "jbe .Lf88038_0008805b\n"
        "leal (, %ecx, 8), %edx\n" /* line 4573 */
        "movl scrVmPub+16, %eax\n"
        "subl %edx, %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf88038_00088064\n"
        ".Lf88038_0008805b:\n"
        "movl %ecx, 8(%ebp)\n" /* line 4576 | index */
        "popl %ebp\n" /* line 4577 */
        "jmp Scr_GetConstString\n" /* line 4576 */
        ".Lf88038_00088064:\n"
        "xorl %eax, %eax\n" /* line 4577 */
        "popl %ebp\n"
        "retl\n"
    );
}

const char * SL_ConvertToString(unsigned int stringValue);

/* line 4563 */
const char * Scr_GetString(unsigned int index)
{
    return SL_ConvertToString(Scr_GetConstString(index));
}

/* line 4523 */
__attribute__((naked))
unsigned int Scr_GetConstLowercaseString(unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4523 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        /* { scope 1 */
        "cmpl %ebx, scrVmPub+28\n" /* line 4531 | index */
        "ja .Lf88082_0008813e\n"
        "addl $1, %ebx\n" /* index */
        ".Lf88082_000880a0:\n"
        "movl %ebx, 4(%esp)\n" /* line 4558 | index */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %ebx\n" /* index */
        "testl %ebx, %ebx\n" /* index */
        "je .Lf88082_000881db\n"
        ".Lf88082_000880c1:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf88082_0008810d\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf88082_0008810d\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf88082_00088283\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf88082_000880ee\n"
        ".Lf88082_000880e5:\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf88082_00088116\n"
        ".Lf88082_000880ee:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf88082_0008810d:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf88082_00088131\n"
        ".Lf88082_00088116:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf88082_00088131:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x202c, %esp\n" /* line 4560 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf88082_0008813e:\n"
        "leal (, %ebx, 8), %eax\n" /* line 4533 */
        "movl scrVmPub+16, %edi\n" /* value */
        "subl %eax, %edi\n" /* value */
        "movl %edi, (%esp)\n" /* line 4534 | value */
        "calll Scr_CastString\n"
        "testb %al, %al\n"
        "jne .Lf88082_0008820d\n"
        "addl $1, %ebx\n" /* line 4555 | index */
        "movl imp_scrVarPub, %ecx\n"
        "movl %ebx, 0x14(%ecx)\n" /* index */
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf88082_000881e3\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "jne .Lf88082_000881e3\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf88082_000882b2\n"
        ".Lf88082_00088184:\n"
        "movl scrVmPub+8, %esi\n" /* line 248 */
        "testl %esi, %esi\n"
        "jne .Lf88082_000880ee\n"
        "cmpb $0, scrVmPub+20\n"
        "jne .Lf88082_000880ee\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf88082_000881ba:\n"
        "movl %ebx, 4(%esp)\n" /* line 4558 | index */
        "movl $str_0021ce10, (%esp)\n" /* "parameter %d does not exist" */
        "calll va\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %ebx\n" /* index */
        "testl %ebx, %ebx\n" /* index */
        "jne .Lf88082_000880c1\n"
        ".Lf88082_000881db:\n"
        "movl %eax, 0x10(%ecx)\n" /* line 4923 */
        "jmp .Lf88082_000880c1\n"
        ".Lf88082_000881e3:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf88082_000880a0\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf88082_000881ba\n"
        ".Lf88082_0008820d:\n"
        "movl (%edi), %eax\n" /* line 4537 | value */
        "movl %eax, -0x201c(%ebp)\n" /* stringValue */
        "movl %eax, (%esp)\n" /* line 4538 */
        "calll SL_ConvertToString\n"
        "movl %eax, -0x2020(%ebp)\n" /* str */
        "movl $1, %esi\n"
        "movl %eax, %ebx\n" /* index */
        "jmp .Lf88082_00088232\n"
        ".Lf88082_0008822c:\n"
        "movl -0x2020(%ebp), %ebx\n" /* str, index */
        ".Lf88082_00088232:\n"
        "addl %esi, %ebx\n" /* line 4523 | index */
        "movsbl -1(%ebx), %eax\n" /* line 4542 | index */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, -0x2019(%esi, %ebp)\n"
        "addl $1, %esi\n"
        "cmpb $0, -1(%ebx)\n" /* line 4543 | index */
        "jne .Lf88082_0008822c\n"
        "movl $0, 4(%esp)\n" /* line 4548 */
        "leal -0x2018(%ebp), %eax\n" /* newStr */
        "movl %eax, (%esp)\n"
        "calll SL_GetString\n"
        "movl %eax, (%edi)\n" /* value */
        "movl -0x201c(%ebp), %eax\n" /* line 4549 | stringValue */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl (%edi), %eax\n" /* line 4553 | value */
        /* } scope */
        "addl $0x202c, %esp\n" /* line 4560 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf88082_00088283:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "je .Lf88082_000880e5\n"
        "jmp .Lf88082_000880ee\n"
        ".Lf88082_000882b2:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edi\n"
        "testl %edi, %edi\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf88082_00088184\n"
    );
}

/* line 4920 */
__attribute__((naked))
void Scr_Error(const char *error)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4920 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl imp_scrVarPub, %ecx\n" /* line 4922 */
        "movl 0x10(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf882d4_00088378\n"
        ".Lf882d4_000882eb:\n"
        "cmpb $0, 0xc(%ecx)\n" /* line 221 */
        "jne .Lf882d4_000882fc\n"
        "movl imp_scrCompilePub, %eax\n"
        "cmpb $0, 0x24(%eax)\n"
        "je .Lf882d4_00088322\n"
        ".Lf882d4_000882fc:\n"
        "cmpb $0, scrVmPub+22\n" /* line 223 */
        "je .Lf882d4_00088320\n"
        ".Lf882d4_00088305:\n"
        "movl 0x10(%ecx), %eax\n" /* line 263 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf882d4_00088320:\n"
        "leave\n" /* line 4925 */
        "retl\n"
        ".Lf882d4_00088322:\n"
        "cmpb $0, 0xa(%ecx)\n" /* line 243 */
        "jne .Lf882d4_00088359\n"
        ".Lf882d4_00088328:\n"
        "movl scrVmPub+8, %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf882d4_0008833a\n"
        "cmpb $0, scrVmPub+20\n"
        "je .Lf882d4_00088305\n"
        ".Lf882d4_0008833a:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 259 */
        "movl g_script_error_level, %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal g_script_error(, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf882d4_00088359:\n"
        "movl $1, %eax\n" /* line 244 */
        "movl scrVmGlob+20, %edx\n"
        "testl %edx, %edx\n"
        "movzbl scrVmPub+22, %edx\n"
        "cmovel %edx, %eax\n"
        "movb %al, scrVmPub+22\n"
        "jmp .Lf882d4_00088328\n"
        ".Lf882d4_00088378:\n"
        "movl 8(%ebp), %eax\n" /* line 4923 | error */
        "movl %eax, 0x10(%ecx)\n"
        "jmp .Lf882d4_000882eb\n"
    );
}

/* line 4826 */
__attribute__((naked))
void Scr_AddStruct(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4826 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "calll AllocObject\n" /* line 4830 */
        "movl %eax, %ebx\n" /* id */
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf88384_000883dc\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf88384_0008841b\n"
        ".Lf88384_000883a9:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $1, 4(%eax)\n" /* line 4802 */
        "movl scrVmPub+16, %eax\n" /* line 4803 */
        "movl %ebx, (%eax)\n"
        "movl %ebx, (%esp)\n" /* line 4804 */
        "calll AddRefToObject\n"
        "movl %ebx, (%esp)\n" /* line 4832 | id */
        "calll RemoveRefToObject\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 4833 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf88384_000883dc:\n"
        "movl scrVmPub+16, %edx\n"
        /* { scope 1 */
        ".Lf88384_000883e2:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf88384_000883e2\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf88384_000883a9\n"
        ".Lf88384_0008841b:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "jmp .Lf88384_000883a9\n"
    );
}

/* line 4808 */
__attribute__((naked))
void Scr_AddEntityNum(int entnum, int classnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4808 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 4818 | classnum */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* entnum */
        "movl %eax, (%esp)\n"
        "calll Scr_GetEntityId\n"
        "movl %eax, %ebx\n" /* id */
        /* { scope 1 */
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf8843a_00088496\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf8843a_000884d5\n"
        ".Lf8843a_0008846c:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $1, 4(%eax)\n" /* line 4802 */
        "movl scrVmPub+16, %eax\n" /* line 4803 */
        "movl %ebx, (%eax)\n"
        "movl %ebx, 8(%ebp)\n" /* line 4804 | entnum */
        /* } scope */
        "addl $0x14, %esp\n" /* line 4823 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp AddRefToObject\n" /* line 4804 */
        ".Lf8843a_00088496:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf8843a_0008849c:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf8843a_0008849c\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf8843a_0008846c\n"
        ".Lf8843a_000884d5:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "jmp .Lf8843a_0008846c\n"
    );
}

/* line 4749 */
__attribute__((naked))
void Scr_AddBool(int value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4749 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf884f4_00088533\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf884f4_00088572\n"
        ".Lf884f4_00088511:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $6, 4(%eax)\n" /* line 4754 */
        "movl 8(%ebp), %edx\n" /* line 4755 | value */
        "movl scrVmPub+16, %eax\n"
        "movl %edx, (%eax)\n"
        "leave\n" /* line 4756 */
        "retl\n"
        ".Lf884f4_00088533:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf884f4_00088539:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf884f4_00088539\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf884f4_00088511\n"
        ".Lf884f4_00088572:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $6, 4(%eax)\n" /* line 4754 */
        "movl 8(%ebp), %edx\n" /* line 4755 | value */
        "movl scrVmPub+16, %eax\n"
        "movl %edx, (%eax)\n"
        "leave\n" /* line 4756 */
        "retl\n"
    );
}

/* line 4759 */
__attribute__((naked))
void Scr_AddInt(int value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4759 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf885ae_000885ed\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf885ae_0008862c\n"
        ".Lf885ae_000885cb:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $6, 4(%eax)\n" /* line 4762 */
        "movl 8(%ebp), %edx\n" /* line 4763 | value */
        "movl scrVmPub+16, %eax\n"
        "movl %edx, (%eax)\n"
        "leave\n" /* line 4764 */
        "retl\n"
        ".Lf885ae_000885ed:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf885ae_000885f3:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf885ae_000885f3\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf885ae_000885cb\n"
        ".Lf885ae_0008862c:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $6, 4(%eax)\n" /* line 4762 */
        "movl 8(%ebp), %edx\n" /* line 4763 | value */
        "movl scrVmPub+16, %eax\n"
        "movl %edx, (%eax)\n"
        "leave\n" /* line 4764 */
        "retl\n"
    );
}

/* line 4767 */
__attribute__((naked))
void Scr_AddFloat(float value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4767 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf88668_000886a7\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf88668_000886e6\n"
        ".Lf88668_00088685:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $5, 4(%eax)\n" /* line 4770 */
        "movl 8(%ebp), %edx\n" /* line 4771 | value */
        "movl scrVmPub+16, %eax\n"
        "movl %edx, (%eax)\n"
        "leave\n" /* line 4772 */
        "retl\n"
        ".Lf88668_000886a7:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf88668_000886ad:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf88668_000886ad\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf88668_00088685\n"
        ".Lf88668_000886e6:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $5, 4(%eax)\n" /* line 4770 */
        "movl 8(%ebp), %edx\n" /* line 4771 | value */
        "movl scrVmPub+16, %eax\n"
        "movl %edx, (%eax)\n"
        "leave\n" /* line 4772 */
        "retl\n"
    );
}

/* line 4783 */
__attribute__((naked))
void Scr_AddUndefined(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4783 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl scrVmPub+28, %ecx\n" /* line 279 */
        "testl %ecx, %ecx\n"
        "jne .Lf88722_00088758\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf88722_00088797\n"
        ".Lf88722_00088740:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $0, 4(%eax)\n" /* line 4786 */
        "leave\n" /* line 4787 */
        "retl\n"
        ".Lf88722_00088758:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf88722_0008875e:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf88722_0008875e\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf88722_00088740\n"
        ".Lf88722_00088797:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $0, 4(%eax)\n" /* line 4786 */
        "leave\n" /* line 4787 */
        "retl\n"
    );
}

/* line 4790 */
__attribute__((naked))
void Scr_AddObject(unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4790 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* id */
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf887ca_00088815\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf887ca_00088854\n"
        ".Lf887ca_000887eb:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $1, 4(%eax)\n" /* line 4802 */
        "movl scrVmPub+16, %eax\n" /* line 4803 */
        "movl %ebx, (%eax)\n" /* id */
        "movl %ebx, 8(%ebp)\n" /* line 4804 | id */
        "addl $0x14, %esp\n" /* line 4805 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp AddRefToObject\n" /* line 4804 */
        ".Lf887ca_00088815:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf887ca_0008881b:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf887ca_0008881b\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf887ca_000887eb\n"
        ".Lf887ca_00088854:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "jmp .Lf887ca_000887eb\n"
    );
}

/* line 4836 */
__attribute__((naked))
void Scr_AddString(const char *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4836 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf88874_000888c9\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf88874_00088908\n"
        ".Lf88874_00088892:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $2, 4(%eax)\n" /* line 4841 */
        "movl scrVmPub+16, %ebx\n" /* line 4842 */
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "calll SL_GetString\n"
        "movl %eax, (%ebx)\n"
        "addl $0x14, %esp\n" /* line 4843 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf88874_000888c9:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf88874_000888cf:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf88874_000888cf\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf88874_00088892\n"
        ".Lf88874_00088908:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "jmp .Lf88874_00088892\n"
    );
}

/* line 4856 */
__attribute__((naked))
void Scr_AddConstString(unsigned int value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4856 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* value */
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf88928_00088973\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf88928_000889b2\n"
        ".Lf88928_00088949:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $2, 4(%eax)\n" /* line 4861 */
        "movl scrVmPub+16, %eax\n" /* line 4862 */
        "movl %ebx, (%eax)\n" /* value */
        "movl %ebx, 8(%ebp)\n" /* line 4863 | value */
        "addl $0x14, %esp\n" /* line 4864 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SL_AddRefToString\n" /* line 4863 */
        ".Lf88928_00088973:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf88928_00088979:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf88928_00088979\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf88928_00088949\n"
        ".Lf88928_000889b2:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "jmp .Lf88928_00088949\n"
    );
}

/* line 4867 */
__attribute__((naked))
void Scr_AddVector(const float *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4867 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl scrVmPub+28, %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "jne .Lf889d2_00088a1f\n"
        "movl scrVmPub+16, %edx\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "je .Lf889d2_00088a5e\n"
        ".Lf889d2_000889f0:\n"
        "leal 8(%edx), %eax\n" /* line 3769 */
        "movl %eax, scrVmPub+16\n"
        "addl $1, scrVmPub+24\n" /* line 3770 */
        "movl $4, 4(%eax)\n" /* line 4870 */
        "movl scrVmPub+16, %ebx\n" /* line 4871 */
        "movl 8(%ebp), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "calll Scr_AllocVector\n"
        "movl %eax, (%ebx)\n"
        "addl $0x14, %esp\n" /* line 4872 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf889d2_00088a1f:\n"
        "movl scrVmPub+16, %edx\n"
        ".Lf889d2_00088a25:\n"
        "movl (%edx), %eax\n" /* line 252 */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToValue\n"
        "movl scrVmPub+16, %edx\n" /* line 282 */
        "subl $8, %edx\n"
        "movl %edx, scrVmPub+16\n"
        "movl scrVmPub+28, %eax\n" /* line 283 */
        "subl $1, %eax\n"
        "movl %eax, scrVmPub+28\n"
        "testl %eax, %eax\n" /* line 279 */
        "jne .Lf889d2_00088a25\n"
        "cmpl scrVmPub+4, %edx\n" /* line 3766 */
        "jne .Lf889d2_000889f0\n"
        ".Lf889d2_00088a5e:\n"
        "movl $str_0021cdd4, 4(%esp)\n" /* line 3767 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrVmPub+16, %edx\n"
        "jmp .Lf889d2_000889f0\n"
    );
}

