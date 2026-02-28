/* ASM dump from: dvar.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/dvar.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 */

extern int dvar_modifiedFlags; /* 0x0 */
extern dvar_t *sortedDvars; /* 0x0 */
extern int dvarCount; /* 0x0 */
static const dvar_t *dvar_cheats; /* dvar_cheats */
static dvar_t dvarPool[1280]; /* dvarPool */
static dvar_t * dvarHashTable[256]; /* dvarHashTable */
static float dvarVectorPool[12]; /* dvarVectorPool */
static int dvarVectorIndex; /* dvarVectorIndex */
static const char dvarDigitStrings[10][2]; /* dvarDigitStrings */
static const char * dvarOnOffStrings[2]; /* dvarOnOffStrings */
static Bool isDvarSystemActive; /* isDvarSystemActive */
static Bool isLoadingAutoExecGlobalFlag; /* isLoadingAutoExecGlobalFlag */

void Dvar_SetInAutoExec(int inAutoExec);
Bool Dvar_IsSystemActive(void);
Bool Dvar_IsValidName(const char *dvarName);
const char * Dvar_EnumToString(const dvar_t *dvar);
static const char * Dvar_ValueToString(void);
const char * Dvar_DisplayableValue(const dvar_t *dvar);
const char * Dvar_DisplayableResetValue(const dvar_t *dvar);
const char * Dvar_DisplayableLatchedValue(const dvar_t *dvar);
static Bool Dvar_ValuesEqual(DvarValue val0, DvarValue val1);
Bool Dvar_HasLatchedValue(const dvar_t *dvar);
Bool Dvar_IsAtDefaultValue(const dvar_t *dvar);
void Dvar_ClearModified(const dvar_t *dvar);
void Dvar_SetModified(const dvar_t *dvar);
void Dvar_AddFlags(const dvar_t *dvar, int flags);
void Dvar_ResetScriptInfo(void);
const char * Dvar_IndexStringToEnumString(const dvar_t *dvar, const char *indexString);
static void Dvar_StringToColor(void);
static DvarValue Dvar_StringToValue(const DvarLimits domain, const char *string);
void Dvar_GetUnpackedColor(const dvar_t *dvar, long unsigned int (*expandedColor)[16]);
static void Dvar_SetLatchedValue(void);
void Dvar_Shutdown(void);
Bool Dvar_AnyLatchedValues(void);
qboolean Com_SaveDvarsToBuffer(const char * *dvarnames, int numDvars, char *buffer, int bufsize);
void Dvar_GetUnpackedColorByName(const char *dvarName, long unsigned int (*expandedColor)[16]);
const char * Dvar_GetVariantString(const char *dvarName);
const char * Dvar_GetString(const char *dvarName);
float Dvar_GetFloat(const char *dvarName);
int Dvar_GetInt(const char *dvarName);
Bool Dvar_GetBool(const char *dvarName);
const dvar_t * Dvar_FindVar(const char *dvarName);
void Dvar_UpdateEnumDomain(const dvar_t *dvar, const char * *stringTable);
static const char * Dvar_DomainToString_Internal(char *outBuffer, int outBufferLen, int *outLineCount);
const char * Dvar_DomainToString_GetLines(int type, DvarLimits domain, char *outBuffer, int outBufferLen, int *outLineCount);
void Dvar_PrintDomain(int type, DvarLimits domain);
static void Dvar_PerformUnregistration(void);
void Dvar_UnregisterSystem(int sysFlag);
static void Dvar_UpdateResetValue(void);
static void Dvar_MakeExplicitType(int flags, DvarValue resetValue, DvarLimits domain);
void Dvar_ChangeResetValue(const dvar_t *dvar, DvarValue value);
static void Dvar_SetVariant(DvarValue value, DvarSetSource source);
void Dvar_SetCheatState(void);
void Dvar_Reset(const dvar_t *dvar, DvarSetSource setSource);
static void Dvar_SetFromStringFromSource(DvarSetSource source);
void Dvar_SetFromString(const dvar_t *dvar, const char *string);
void Dvar_SetString(const dvar_t *dvar, const char *value);
void Dvar_SetColorFromSource(const dvar_t *dvar, float r, float g, float b, float a, DvarSetSource source);
void Dvar_SetColor(const dvar_t *dvar, float r, float g, float b, float a);
void Dvar_SetFloatFromSource(const dvar_t *dvar, float value, DvarSetSource source);
void Dvar_SetIntFromSource(const dvar_t *dvar, int value, DvarSetSource source);
void Dvar_SetBoolFromSource(const dvar_t *dvar, int value, DvarSetSource source);
static const dvar_t * Dvar_RegisterVariant(const char *dvarName, short unsigned int flags, DvarValue value, DvarLimits domain);
const dvar_t * Dvar_RegisterColor(const char *dvarName, float r, float g, float b, float a, int flags);
const dvar_t * Dvar_RegisterEnum(const char *dvarName, const char * *valueList, int defaultIndex, int flags);
const dvar_t * Dvar_RegisterString(const char *dvarName, const char *value, int flags);
const dvar_t * Dvar_RegisterVec4(const char *dvarName, float x, float y, float z, float w, float min, float max, int flags);
const dvar_t * Dvar_RegisterVec3(const char *dvarName, float x, float y, float z, float min, float max, int flags);
const dvar_t * Dvar_RegisterVec2(const char *dvarName, float x, float y, float min, float max, int flags);
const dvar_t * Dvar_RegisterFloat(const char *dvarName, float value, float min, float max, int flags);
const dvar_t * Dvar_RegisterInt(const char *dvarName, int value, int min, int max, int flags);
const dvar_t * Dvar_RegisterBool(const char *dvarName, int value, int flags);
void Dvar_Init(void);
void Dvar_ResetDvars(unsigned int filter, DvarSetSource setSource);
qboolean Com_LoadDvarsFromBuffer(const char * *dvarnames, int numDvars, const char *buffer, const char *filename);
void Dvar_SetBool(const dvar_t *dvar, int value);
void Dvar_SetFloat(const dvar_t *dvar, float value);
void Dvar_SetInt(const dvar_t *dvar, int value);
void Dvar_SetVec2(const dvar_t *dvar, float x, float y);
void Dvar_SetVec3(const dvar_t *dvar, float x, float y, float z);
void Dvar_SetVec4(const dvar_t *dvar, float x, float y, float z, float w);
void Dvar_SetBoolByName(const char *dvarName, int value);
void Dvar_SetIntByName(const char *dvarName, int value);
void Dvar_SetFloatByName(const char *dvarName, float value);
void Dvar_SetVec2ByName(const char *dvarName, float x, float y);
void Dvar_SetVec3ByName(const char *dvarName, float x, float y, float z);
void Dvar_SetVec4ByName(const char *dvarName, float x, float y, float z, float w);
void Dvar_SetStringByName(const char *dvarName, const char *value);
void Dvar_SetColorByName(const char *dvarName, int r, int g, int b, int a);
const dvar_t * Dvar_SetFromStringByNameFromSource(const char *dvarName, const char *string, DvarSetSource source);
void Dvar_SetCommand(const char *dvarName, const char *string);
void Dvar_SetFromStringByName(const char *dvarName, const char *string);

/* line 45 */
void Dvar_SetInAutoExec(int inAutoExec)
{
    isLoadingAutoExecGlobalFlag = (byte)inAutoExec;
}

/* line 51 */
Bool Dvar_IsSystemActive(void)
{
    return isDvarSystemActive;
}

/* line 85 */
__attribute__((naked))
Bool Dvar_IsValidName(const char *dvarName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 85 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        "testl %eax, %eax\n" /* line 90 */
        "je .Lf51372_000513e4\n"
        "movzbl (%eax), %ebx\n" /* line 93 */
        "testb %bl, %bl\n"
        "je .Lf51372_000513d8\n"
        "movl %eax, %esi\n"
        "jmp .Lf51372_000513b3\n"
        /* { scope 1 */
        ".Lf51372_0005138c:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "testl $0x500, 0x34(%eax, %edx, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lf51372_0005139f:\n"
        "testl %eax, %eax\n" /* line 96 */
        "jne .Lf51372_000513a8\n"
        "cmpb $0x5f, %bl\n"
        "jne .Lf51372_000513e4\n"
        ".Lf51372_000513a8:\n"
        "movzbl 1(%esi), %ebx\n" /* line 93 */
        "addl $1, %esi\n"
        "testb %bl, %bl\n"
        "je .Lf51372_000513d8\n"
        ".Lf51372_000513b3:\n"
        "movsbl %bl, %edx\n" /* line 96 | _c */
        /* { scope 1 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf51372_0005138c\n"
        "movl $0x500, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf51372_0005139f\n"
        /* } scope */
        ".Lf51372_000513d8:\n"
        "movl $1, %eax\n" /* line 96 */
        "addl $0x10, %esp\n" /* line 100 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf51372_000513e4:\n"
        "xorl %eax, %eax\n" /* line 96 */
        "addl $0x10, %esp\n" /* line 100 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 247 */
const char * Dvar_EnumToString(const dvar_t *dvar)
{
    if (!*(int *)((byte *)dvar + 0x14))
        return "";
    return ((const char **)*(void **)((byte *)dvar + 0x18))[*(int *)((byte *)dvar + 8)];
}

/* line 290 */
static __attribute__((naked))
const char * Dvar_ValueToString(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 290 */
        "movl %esp, %ebp\n"
        "subl $0x48, %esp\n"
        "movzbl 6(%eax), %ecx\n" /* line 292 | dvar */
        "cmpl $8, %ecx\n"
        "ja .Lf5140e_0005142f\n"
        "jmpl *dvarDigitStrings+20(, %ecx, 4)\n"
        "movl 0x14(%eax), %ecx\n" /* line 317 | dvar */
        "testl %ecx, %ecx\n"
        "jne .Lf5140e_000515a6\n"
        ".Lf5140e_0005142f:\n"
        "movl $str_002157b8, %ecx\n"
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
        "movl $str_002162ac, %ecx\n" /* line 295 */
        "testb %dl, %dl\n" /* value */
        "movl $str_0021952c, %eax\n" /* dvar */
        "cmovel %eax, %ecx\n" /* dvar */
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
        "movl %edx, %eax\n" /* line 313 | value, dvar */
        "shrl $0x18, %eax\n" /* dvar */
        "cvtsi2ssl %eax, %xmm0\n" /* dvar */
        "movss lit4_002ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 0x1c(%esp)\n"
        "movl %edx, %eax\n" /* value, dvar */
        "shrl $0x10, %eax\n" /* dvar */
        "movzbl %al, %eax\n" /* dvar */
        "cvtsi2ssl %eax, %xmm0\n" /* dvar */
        "mulss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 0x14(%esp)\n"
        "movzbl %dh, %eax\n" /* value, dvar */
        "cvtsi2ssl %eax, %xmm0\n" /* dvar */
        "mulss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 0xc(%esp)\n"
        "movzbl %dl, %eax\n" /* value, dvar */
        "cvtsi2ssl %eax, %xmm0\n" /* dvar */
        "mulss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00219544, (%esp)\n" /* "%g %g %g %g" */
        "calll va\n"
        "movl %eax, %ecx\n" /* dvar */
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
        "movl %edx, 4(%esp)\n" /* line 323 | value */
        "movl $str_00216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "movl %eax, %ecx\n" /* dvar */
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
        "movl %edx, 4(%esp)\n" /* line 298 | value */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, %ecx\n" /* dvar */
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
        "cvtss2sd 0xc(%edx), %xmm0\n" /* line 310 | value */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd 8(%edx), %xmm0\n" /* value */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 4(%edx), %xmm0\n" /* value */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd (%edx), %xmm0\n" /* value */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00219544, (%esp)\n" /* "%g %g %g %g" */
        "calll va\n"
        "movl %eax, %ecx\n" /* dvar */
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
        "cvtss2sd 8(%edx), %xmm0\n" /* line 307 | value */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 4(%edx), %xmm0\n" /* value */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd (%edx), %xmm0\n" /* value */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00219538, (%esp)\n" /* "%g %g %g" */
        "calll va\n"
        "movl %eax, %ecx\n" /* dvar */
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
        "cvtss2sd 4(%edx), %xmm0\n" /* line 304 | value */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd (%edx), %xmm0\n" /* value */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00219530, (%esp)\n" /* "%g %g" */
        "calll va\n"
        "movl %eax, %ecx\n" /* dvar */
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
        "movl %edx, -0xc(%ebp)\n" /* line 301 | value */
        "movss -0xc(%ebp), %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00217c20, (%esp)\n" /* "%g" */
        "calll va\n"
        "movl %eax, %ecx\n" /* dvar */
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
        ".Lf5140e_000515a6:\n"
        "movl 0x18(%eax), %eax\n" /* line 319 | dvar */
        "movl (%eax, %edx, 4), %ecx\n" /* dvar */
        "movl %ecx, %eax\n" /* line 330 | dvar */
        "leave\n"
        "retl\n"
    );
}

/* line 496 */
__attribute__((naked))
const char * Dvar_DisplayableValue(const dvar_t *dvar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 496 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl 8(%eax), %edx\n" /* line 506 */
        "popl %ebp\n" /* line 513 */
        "jmp Dvar_ValueToString\n" /* line 506 */
    );
}

/* line 516 */
__attribute__((naked))
const char * Dvar_DisplayableResetValue(const dvar_t *dvar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 516 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl 0x10(%eax), %edx\n" /* line 526 */
        "popl %ebp\n" /* line 533 */
        "jmp Dvar_ValueToString\n" /* line 526 */
    );
}

/* line 536 */
__attribute__((naked))
const char * Dvar_DisplayableLatchedValue(const dvar_t *dvar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 536 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl 0xc(%eax), %edx\n" /* line 546 */
        "popl %ebp\n" /* line 553 */
        "jmp Dvar_ValueToString\n" /* line 546 */
    );
}

/* line 838 */
static __attribute__((naked))
Bool Dvar_ValuesEqual(DvarValue val0, DvarValue val1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 838 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl %edx, -0xc(%ebp)\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movzbl %al, %eax\n" /* line 840 | type */
        "cmpl $8, %eax\n" /* type */
        "ja .Lf515e0_000515fb\n"
        "jmpl *dvarDigitStrings+56(, %eax, 4)\n"
        ".Lf515e0_000515fb:\n"
        "xorl %eax, %eax\n" /* type */
        "leave\n" /* line 876 */
        "retl\n"
        "movl -0xc(%ebp), %eax\n" /* line 864 */
        "cmpl -0x10(%ebp), %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 876 */
        "retl\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 849 */
        "ucomiss -0x10(%ebp), %xmm0\n"
        "sete %al\n" /* type */
        "setnp %dl\n"
        "andb %dl, %al\n" /* type */
        "movzbl %al, %eax\n" /* type */
        "leave\n" /* line 876 */
        "retl\n"
        "movl -0xc(%ebp), %eax\n" /* line 855 | a */
        "movl -0x10(%ebp), %edx\n" /* b */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 561 */
        "ucomiss (%edx), %xmm0\n"
        "jne .Lf515e0_00051659\n"
        "jp .Lf515e0_00051659\n"
        "movss 4(%eax), %xmm0\n"
        "ucomiss 4(%edx), %xmm0\n"
        "jne .Lf515e0_00051659\n"
        "jp .Lf515e0_00051659\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss 8(%edx), %xmm0\n"
        "jne .Lf515e0_00051659\n"
        "jp .Lf515e0_00051659\n"
        "movss 0xc(%eax), %xmm0\n"
        "ucomiss 0xc(%edx), %xmm0\n"
        "je .Lf515e0_000516d4\n"
        ".Lf515e0_00051659:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf515e0_0005165b:\n"
        "movzbl %al, %eax\n" /* line 869 */
        ".Lf515e0_0005165e:\n"
        "leave\n" /* line 876 */
        "retl\n"
        "movl -0xc(%ebp), %eax\n" /* line 852 | a */
        "movl -0x10(%ebp), %edx\n" /* b */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 310 */
        "ucomiss (%edx), %xmm0\n"
        "jne .Lf515e0_00051659\n"
        "jp .Lf515e0_00051659\n"
        "movss 4(%eax), %xmm0\n"
        "ucomiss 4(%edx), %xmm0\n"
        "jne .Lf515e0_00051659\n"
        "jp .Lf515e0_00051659\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss 8(%edx), %xmm0\n"
        "je .Lf515e0_000516d4\n"
        /* } scope */
        /* { scope 1 */
        "xorl %eax, %eax\n" /* line 561 */
        "jmp .Lf515e0_0005165b\n"
        /* } scope */
        "movzbl -0xc(%ebp), %eax\n" /* line 843 | type */
        "cmpb -0x10(%ebp), %al\n" /* type */
        "sete %al\n" /* type */
        "movzbl %al, %eax\n" /* type */
        "leave\n" /* line 876 */
        "retl\n"
        "movl -0x10(%ebp), %eax\n" /* line 869 */
        "movl %eax, 4(%esp)\n"
        "movl -0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf515e0_0005165e\n"
        "movl -0xc(%ebp), %eax\n" /* line 849 | type */
        "movl -0x10(%ebp), %edx\n"
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 120 */
        "ucomiss (%edx), %xmm0\n"
        "jne .Lf515e0_00051659\n"
        "jp .Lf515e0_00051659\n"
        "movss 4(%eax), %xmm0\n"
        "ucomiss 4(%edx), %xmm0\n"
        "jne .Lf515e0_00051659\n"
        /* } scope */
        /* { scope 1 */
        ".Lf515e0_000516d4:\n"
        "jp .Lf515e0_00051659\n" /* line 561 */
        "movl $1, %eax\n"
        /* } scope */
        "movzbl %al, %eax\n" /* line 869 */
        "jmp .Lf515e0_0005165e\n"
    );
}

/* line 908 */
__attribute__((naked))
Bool Dvar_HasLatchedValue(const dvar_t *dvar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 908 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl 0xc(%eax), %ecx\n" /* line 910 */
        "movl 8(%eax), %edx\n"
        "movzbl 6(%eax), %eax\n"
        "calll Dvar_ValuesEqual\n"
        "testb %al, %al\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 911 */
        "retl\n"
    );
}

/* line 914 */
__attribute__((naked))
Bool Dvar_IsAtDefaultValue(const dvar_t *dvar)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 914 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl 0x10(%eax), %ecx\n" /* line 916 */
        "movl 8(%eax), %edx\n"
        "movzbl 6(%eax), %eax\n"
        "calll Dvar_ValuesEqual\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 917 */
        "retl\n"
    );
}

/* line 1078 */
void Dvar_ClearModified(const dvar_t *dvar)
{
    *(byte *)((byte *)dvar + 7) = 0;
}

/* line 1085 */
void Dvar_SetModified(const dvar_t *dvar)
{
    *(byte *)((byte *)dvar + 7) = 1;
}

/* line 2319 */
void Dvar_AddFlags(const dvar_t *dvar, int flags)
{
    *(unsigned short *)((byte *)dvar + 4) |= (unsigned short)flags;
}

/* line 2388 */
void Dvar_ResetScriptInfo(void)
{
    dvar_t *dvar = dvarPool;
    while (dvar) {
        *(unsigned short *)((byte *)dvar + 4) &= ~0x0400;
        dvar = (dvar_t *)*(int *)((byte *)dvar + 0x1c);
    }
}

/* line 260 */
__attribute__((naked))
const char * Dvar_IndexStringToEnumString(const dvar_t *dvar, const char *indexString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 260 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* dvar */
        /* { scope 1 */
        "movl 0x14(%ebx), %esi\n" /* line 273 | dvar */
        "testl %esi, %esi\n"
        "jne .Lf51768_00051788\n"
        ".Lf51768_0005177b:\n"
        "movl $str_002157b8, %eax\n" /* line 286 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 287 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf51768_00051788:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* indexString */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "testl %ecx, %ecx\n" /* line 277 */
        "jle .Lf51768_000517c2\n"
        "xorl %edx, %edx\n"
        "movl __DefaultRuneLocale, %edi\n"
        ".Lf51768_000517a6:\n"
        "movl 0xc(%ebp), %esi\n" /* line 279 | indexString */
        "movsbl (%esi, %edx), %eax\n" /* _c */
        /* { scope 2 */
        "cmpl $0xff, %eax\n" /* line 231 */
        "ja .Lf51768_0005177b\n"
        "testb $4, 0x35(%edi, %eax, 4)\n"
        "je .Lf51768_0005177b\n"
        /* } scope */
        "addl $1, %edx\n" /* line 277 */
        "cmpl %edx, %ecx\n"
        "jne .Lf51768_000517a6\n"
        ".Lf51768_000517c2:\n"
        "movl 0xc(%ebp), %eax\n" /* line 283 | indexString */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl 0x18(%ebx), %edx\n" /* line 286 | dvar */
        "movl (%edx, %eax, 4), %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 287 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 428 */
static __attribute__((naked))
void Dvar_StringToColor(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 428 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl %edx, %ebx\n" /* color */
        /* { scope 1 */
        "pxor %xmm2, %xmm2\n" /* line 438 */
        "movss %xmm2, -0x18(%ebp)\n" /* colorVec */
        "movss %xmm2, -0x14(%ebp)\n" /* line 439 */
        "movss %xmm2, -0x10(%ebp)\n" /* line 440 */
        "movss %xmm2, -0xc(%ebp)\n" /* line 441 */
        "leal -0x18(%ebp), %ecx\n" /* line 433 | colorVec */
        "leal -0xc(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "leal -0x10(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal -0x14(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl $str_00219544, 4(%esp)\n" /* "%g %g %g %g" */
        "movl %eax, (%esp)\n" /* string */
        "movss %xmm2, -0x38(%ebp)\n"
        "calll sscanf\n"
        "movss -0x18(%ebp), %xmm1\n" /* line 434 | colorVec */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf517dc_00051a21\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 2 */
        ".Lf517dc_0005185d:\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf517dc_00051a11\n"
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        ".Lf517dc_0005186d:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n" /* string */
        "movb %al, (%ebx)\n" /* string, color */
        "leal 1(%ebx), %esi\n" /* line 435 | color */
        "movss -0x14(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf517dc_00051a05\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 2 */
        ".Lf517dc_000518bf:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf517dc_000519f5\n"
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        ".Lf517dc_000518cb:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll floorf\n"
        "fstps -0x20(%ebp)\n"
        "cvttss2si -0x20(%ebp), %eax\n" /* string */
        "movb %al, (%esi)\n" /* string */
        "leal 2(%ebx), %esi\n" /* line 436 | color */
        "movss -0x10(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf517dc_000519e9\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 2 */
        ".Lf517dc_0005191d:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf517dc_000519d9\n"
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        ".Lf517dc_00051929:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll floorf\n"
        "fstps -0x24(%ebp)\n"
        "cvttss2si -0x24(%ebp), %eax\n" /* string */
        "movb %al, (%esi)\n" /* string */
        "addl $3, %ebx\n" /* line 437 | color */
        "movss -0xc(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf517dc_000519d0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 2 */
        ".Lf517dc_00051977:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf517dc_000519a2\n"
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x28(%ebp)\n"
        "cvttss2si -0x28(%ebp), %eax\n" /* string */
        "movb %al, (%ebx)\n" /* string, color */
        /* } scope */
        "addl $0x50, %esp\n" /* line 438 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf517dc_000519a2:\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        /* } scope */
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x28(%ebp)\n"
        "cvttss2si -0x28(%ebp), %eax\n" /* string */
        "movb %al, (%ebx)\n" /* string, color */
        /* } scope */
        "addl $0x50, %esp\n" /* line 438 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf517dc_000519d0:\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "jmp .Lf517dc_00051977\n"
        /* { scope 2 */
        ".Lf517dc_000519d9:\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf517dc_00051929\n"
        /* } scope */
        ".Lf517dc_000519e9:\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "jmp .Lf517dc_0005191d\n"
        /* { scope 2 */
        ".Lf517dc_000519f5:\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf517dc_000518cb\n"
        /* } scope */
        ".Lf517dc_00051a05:\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "jmp .Lf517dc_000518bf\n"
        /* { scope 2 */
        ".Lf517dc_00051a11:\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf517dc_0005186d\n"
        /* } scope */
        ".Lf517dc_00051a21:\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "jmp .Lf517dc_0005185d\n"
    );
}

/* line 441 */
static __attribute__((naked))
DvarValue Dvar_StringToValue(const DvarLimits domain, const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 441 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl %ecx, -0x3c(%ebp)\n"
        /* { scope 1 */
        "movzbl %al, %eax\n" /* line 447 | type */
        "cmpl $8, %eax\n" /* type */
        "ja .Lf51a2e_00051a4c\n"
        "jmpl *dvarDigitStrings+92(, %eax, 4)\n"
        ".Lf51a2e_00051a4c:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 488 | value */
        "movl -0x1c(%ebp), %eax\n" /* value, type */
        /* } scope */
        ".Lf51a2e_00051a56:\n"
        "addl $0x5c, %esp\n" /* line 493 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 336 | string */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "testl %eax, %eax\n" /* line 450 | type */
        "setne -0x1c(%ebp)\n" /* value */
        "movl -0x1c(%ebp), %eax\n" /* value, type */
        "jmp .Lf51a2e_00051a56\n"
        "leal -0x1c(%ebp), %edx\n" /* line 482 | value */
        "movl 8(%ebp), %eax\n" /* string, type */
        "calll Dvar_StringToColor\n"
        "movl -0x1c(%ebp), %eax\n" /* value, type */
        "jmp .Lf51a2e_00051a56\n"
        "movl 8(%ebp), %eax\n" /* line 478 | string, type */
        "movl %eax, -0x1c(%ebp)\n" /* type, value */
        "jmp .Lf51a2e_00051a56\n"
        /* { scope 2 */
        "movl -0x40(%ebp), %edx\n" /* line 402 */
        "movl %edx, -0x2c(%ebp)\n"
        "testl %edx, %edx\n"
        "jg .Lf51a2e_00051cd0\n"
        ".Lf51a2e_00051a9a:\n"
        "movl 8(%ebp), %eax\n" /* line 408 | string */
        "movzbl (%eax), %ecx\n"
        "testb %cl, %cl\n"
        "je .Lf51a2e_00051c73\n"
        "leal -0x30(%ecx), %eax\n" /* line 410 */
        "cmpb $9, %al\n"
        "ja .Lf51a2e_00051ad4\n"
        "movl 8(%ebp), %esi\n" /* string, len */
        "xorl %ebx, %ebx\n" /* stringIndex */
        ".Lf51a2e_00051ab4:\n"
        "leal (%ebx, %ebx, 4), %edx\n" /* line 412 | stringIndex */
        "movsbl %cl, %eax\n"
        "leal -0x30(%eax, %edx, 2), %ebx\n" /* stringIndex */
        "movzbl 1(%esi), %ecx\n" /* line 408 | len */
        "testb %cl, %cl\n"
        "je .Lf51a2e_00051cfc\n"
        "addl $1, %esi\n" /* len */
        "leal -0x30(%ecx), %eax\n" /* line 410 */
        "cmpb $9, %al\n"
        "jbe .Lf51a2e_00051ab4\n"
        ".Lf51a2e_00051ad4:\n"
        "movl $0xfffffac7, %ebx\n" /* line 418 | stringIndex */
        /* } scope */
        ".Lf51a2e_00051ad9:\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 462 | stringIndex, value */
        "movl %ebx, %eax\n" /* stringIndex, type */
        /* } scope */
        ".Lf51a2e_00051ade:\n"
        "addl $0x5c, %esp\n" /* line 493 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 343 | string */
        "movl %edx, (%esp)\n"
        "calll atoi\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 454 | type, value */
        "jmp .Lf51a2e_00051a56\n"
        "movl dvarVectorIndex, %ecx\n" /* line 110 */
        "leal 4(%ecx), %eax\n"
        "cmpl $0xc, %eax\n"
        "jg .Lf51a2e_00051c62\n"
        ".Lf51a2e_00051b0b:\n"
        "leal (, %ecx, 4), %edx\n" /* line 112 */
        "leal dvarVectorPool(%edx), %ebx\n"
        "leal 4(%ecx), %eax\n" /* line 113 */
        "movl %eax, dvarVectorIndex\n"
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 438 */
        "movl %eax, dvarVectorPool(%edx)\n"
        "leal 4(%ebx), %esi\n" /* line 439 | stringIndex, len */
        "movl %eax, 4(%ebx)\n" /* stringIndex */
        "leal 8(%ebx), %ecx\n" /* line 440 | stringIndex */
        "movl %eax, 8(%ebx)\n" /* stringIndex */
        "leal 0xc(%ebx), %edx\n" /* line 441 | stringIndex */
        "movl %eax, 0xc(%ebx)\n" /* type, stringIndex */
        /* } scope */
        "movl %edx, 0x14(%esp)\n" /* line 388 */
        "movl %ecx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* v */
        "movl $str_00219544, 4(%esp)\n" /* "%g %g %g %g" */
        "movl 8(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 470 | stringIndex, value */
        "movl %ebx, %eax\n" /* stringIndex, type */
        "jmp .Lf51a2e_00051a56\n"
        "movl dvarVectorIndex, %ecx\n" /* line 110 */
        "leal 3(%ecx), %eax\n"
        "cmpl $0xc, %eax\n"
        "jg .Lf51a2e_00051c51\n"
        ".Lf51a2e_00051b79:\n"
        "leal (, %ecx, 4), %edx\n" /* line 112 */
        "leal dvarVectorPool(%edx), %ebx\n"
        "addl $3, %ecx\n" /* line 113 */
        "movl %ecx, dvarVectorIndex\n"
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, dvarVectorPool(%edx)\n"
        "leal 4(%ebx), %ecx\n" /* line 184 */
        "movl %eax, 4(%ebx)\n"
        "leal 8(%ebx), %edx\n" /* line 185 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "movl %edx, 0x10(%esp)\n" /* line 375 */
        "movl %ecx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* v */
        "movl $str_00219538, 4(%esp)\n" /* "%g %g %g" */
        "movl 8(%ebp), %edx\n" /* string */
        "movl %edx, (%esp)\n"
        "calll sscanf\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 466 | stringIndex, value */
        "movl %ebx, %eax\n" /* stringIndex, type */
        "jmp .Lf51a2e_00051a56\n"
        "movl dvarVectorIndex, %ecx\n" /* line 110 */
        "leal 2(%ecx), %eax\n"
        "cmpl $0xc, %eax\n"
        "jg .Lf51a2e_00051c43\n"
        ".Lf51a2e_00051bda:\n"
        "leal (, %ecx, 4), %edx\n" /* line 112 */
        "leal dvarVectorPool(%edx), %ebx\n"
        "addl $2, %ecx\n" /* line 113 */
        "movl %ecx, dvarVectorIndex\n"
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 23 */
        "movl %eax, dvarVectorPool(%edx)\n"
        "leal 4(%ebx), %edx\n" /* line 24 */
        "movl %eax, 4(%ebx)\n"
        /* } scope */
        "movl %edx, 0xc(%esp)\n" /* line 362 */
        "movl %ebx, 8(%esp)\n" /* v */
        "movl $str_00219530, 4(%esp)\n" /* "%g %g" */
        "movl 8(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 462 | stringIndex, value */
        "movl %ebx, %eax\n" /* stringIndex, type */
        "jmp .Lf51a2e_00051ade\n"
        "movl 8(%ebp), %eax\n" /* line 350 | string */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x38(%ebp)\n"
        "cvtsd2ss -0x38(%ebp), %xmm0\n" /* line 458 */
        "movss %xmm0, -0x1c(%ebp)\n" /* value */
        "movl -0x1c(%ebp), %eax\n" /* value, type */
        "jmp .Lf51a2e_00051a56\n"
        ".Lf51a2e_00051c43:\n"
        "xorl %ecx, %ecx\n" /* line 111 */
        "movl $0, dvarVectorIndex\n"
        "jmp .Lf51a2e_00051bda\n"
        ".Lf51a2e_00051c51:\n"
        "xorl %ecx, %ecx\n"
        "movl $0, dvarVectorIndex\n"
        "jmp .Lf51a2e_00051b79\n"
        ".Lf51a2e_00051c62:\n"
        "xorl %ecx, %ecx\n"
        "movl $0, dvarVectorIndex\n"
        "jmp .Lf51a2e_00051b0b\n"
        /* { scope 2 */
        ".Lf51a2e_00051c73:\n"
        "xorl %ebx, %ebx\n" /* line 408 | stringIndex */
        ".Lf51a2e_00051c75:\n"
        "cmpl %ebx, -0x2c(%ebp)\n" /* line 414 | stringIndex */
        "jg .Lf51a2e_00051ad9\n"
        ".Lf51a2e_00051c7e:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n" /* type */
        "movl 8(%ebp), %edi\n" /* string */
        "repne scasb %es:(%edi), %al\n" /* type */
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* len */
        "movl -0x2c(%ebp), %edi\n" /* line 418 */
        "testl %edi, %edi\n"
        "jle .Lf51a2e_00051ad4\n"
        "movl -0x3c(%ebp), %edi\n" /* line 420 */
        "xorl %ebx, %ebx\n" /* stringIndex */
        ".Lf51a2e_00051ca0:\n"
        "movl %esi, 8(%esp)\n" /* len */
        "movl (%edi, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* string */
        "movl %edx, (%esp)\n"
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf51a2e_00051ad9\n"
        "addl $1, %ebx\n" /* line 418 | stringIndex */
        "cmpl %ebx, -0x2c(%ebp)\n" /* stringIndex */
        "jne .Lf51a2e_00051ca0\n"
        "movl $0xfffffac7, %ebx\n" /* stringIndex */
        "jmp .Lf51a2e_00051ad9\n"
        ".Lf51a2e_00051cd0:\n"
        "movl -0x3c(%ebp), %esi\n" /* line 404 | len */
        "xorl %ebx, %ebx\n" /* stringIndex */
        ".Lf51a2e_00051cd5:\n"
        "movl (%esi, %ebx, 4), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* string */
        "movl %edx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf51a2e_00051ad9\n"
        "addl $1, %ebx\n" /* line 402 | stringIndex */
        "cmpl %ebx, -0x2c(%ebp)\n" /* stringIndex */
        "jne .Lf51a2e_00051cd5\n"
        "jmp .Lf51a2e_00051a9a\n"
        ".Lf51a2e_00051cfc:\n"
        "testl %ebx, %ebx\n" /* line 414 | stringIndex */
        "js .Lf51a2e_00051c7e\n"
        "jmp .Lf51a2e_00051c75\n"
    );
}

/* line 1249 */
__attribute__((naked))
void Dvar_GetUnpackedColor(const dvar_t *dvar, long unsigned int (*expandedColor)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1249 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl 0xc(%ebp), %ebx\n" /* expandedColor */
        /* { scope 1 */
        "cmpb $8, 6(%eax)\n" /* line 1256 */
        "je .Lf51d0a_00051d79\n"
        "leal -0xc(%ebp), %edx\n" /* line 1259 | color */
        "movl 8(%eax), %eax\n"
        "calll Dvar_StringToColor\n"
        ".Lf51d0a_00051d28:\n"
        "movzbl -0xc(%ebp), %eax\n" /* line 1260 | color */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss lit4_002ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* expandedColor */
        "movzbl -0xb(%ebp), %eax\n" /* line 1261 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%ebx)\n" /* expandedColor */
        "movzbl -0xa(%ebp), %eax\n" /* line 1262 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%ebx)\n" /* expandedColor */
        "movzbl -9(%ebp), %eax\n" /* line 1263 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n" /* expandedColor */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1264 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf51d0a_00051d79:\n"
        "movl 8(%eax), %eax\n" /* line 606 */
        "movl %eax, -0xc(%ebp)\n" /* color */
        "jmp .Lf51d0a_00051d28\n"
    );
}

/* line 879 */
static __attribute__((naked))
void Dvar_SetLatchedValue(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 879 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %esi\n" /* dvar */
        "movl %edx, %ebx\n" /* value */
        "movzbl 6(%eax), %eax\n" /* line 881 */
        "cmpb $3, %al\n"
        "je .Lf51d82_00051dc9\n"
        "jbe .Lf51d82_00051db0\n"
        "cmpb $4, %al\n"
        "je .Lf51d82_00051e79\n"
        "cmpb $7, %al\n"
        "je .Lf51d82_00051de4\n"
        ".Lf51d82_00051da5:\n"
        "movl %ebx, 0xc(%esi)\n" /* line 902 | value, dvar */
        ".Lf51d82_00051da8:\n"
        "addl $0x1c, %esp\n" /* line 905 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf51d82_00051db0:\n"
        "cmpb $2, %al\n" /* line 881 */
        "jne .Lf51d82_00051da5\n"
        "movl 0xc(%esi), %eax\n" /* line 889 | dvar, to */
        /* { scope 1 */
        "movl (%edx), %edx\n" /* line 37 */
        "movl %edx, (%eax)\n"
        "movl 4(%ebx), %edx\n" /* line 38 */
        "movl %edx, 4(%eax)\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 905 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf51d82_00051dc9:\n"
        "movl 0xc(%esi), %edx\n" /* line 893 | dvar, to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 905 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf51d82_00051de4:\n"
        "movl 0xc(%esi), %eax\n" /* line 199 */
        "cmpl 8(%esi), %eax\n"
        "je .Lf51d82_00051e20\n"
        "cmpl 0x10(%esi), %eax\n"
        "je .Lf51d82_00051e20\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "je .Lf51d82_00051e20\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "jne .Lf51d82_00051e08\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf51d82_00051e08\n"
        "cmpb $0x39, %dl\n"
        "jle .Lf51d82_00051e20\n"
        ".Lf51d82_00051e08:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf51d82_00051e20\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf51d82_00051e20\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        ".Lf51d82_00051e20:\n"
        "movl $0, 0xc(%esi)\n" /* line 201 */
        "movl 8(%esi), %edi\n" /* line 226 */
        "testl %edi, %edi\n"
        "je .Lf51d82_00051e42\n"
        "cmpl %edi, %ebx\n"
        "je .Lf51d82_00051e71\n"
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf51d82_00051e71\n"
        ".Lf51d82_00051e42:\n"
        "movl 0x10(%esi), %edi\n" /* line 228 */
        "testl %edi, %edi\n"
        "je .Lf51d82_00051e5d\n"
        "cmpl %edi, %ebx\n"
        "je .Lf51d82_00051e71\n"
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf51d82_00051e71\n"
        ".Lf51d82_00051e5d:\n"
        "movzbl (%ebx), %edx\n" /* line 155 */
        "testb %dl, %dl\n"
        "jne .Lf51d82_00051e9a\n"
        "movl $str_002157b8, %eax\n"
        "movl %eax, 0xc(%esi)\n" /* line 231 */
        "jmp .Lf51d82_00051da8\n"
        ".Lf51d82_00051e71:\n"
        "movl %edi, 0xc(%esi)\n" /* line 229 */
        "jmp .Lf51d82_00051da8\n"
        ".Lf51d82_00051e79:\n"
        "movl 0xc(%esi), %edx\n" /* line 897 | dvar, to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 456 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 905 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf51d82_00051e9a:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* value */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movzbl 1(%ebx), %eax\n" /* line 160 */
        "testb %al, %al\n"
        "jne .Lf51d82_00051edc\n"
        "leal -0x30(%edx), %eax\n" /* line 162 */
        "cmpb $9, %al\n"
        "ja .Lf51d82_00051ecc\n"
        "movsbl %dl, %eax\n" /* line 163 */
        "leal __ZZN16CStringEdPackage9ParseLineEPKchE5C.208+1024(%eax, %eax), %eax\n"
        "movl %eax, 0xc(%esi)\n" /* line 231 */
        "jmp .Lf51d82_00051da8\n"
        ".Lf51d82_00051ecc:\n"
        "movl %ebx, (%esp)\n" /* line 173 */
        "calll CopyStringInternal\n"
        "movl %eax, 0xc(%esi)\n" /* line 231 */
        "jmp .Lf51d82_00051da8\n"
        ".Lf51d82_00051edc:\n"
        "cmpb $0x6f, %dl\n" /* line 165 */
        "jne .Lf51d82_00051ecc\n"
        "cmpl $3, %ecx\n" /* line 167 */
        "je .Lf51d82_00051f02\n"
        "cmpl $2, %ecx\n" /* line 169 */
        "jne .Lf51d82_00051ecc\n"
        "cmpb $0x6e, %al\n"
        "jne .Lf51d82_00051ecc\n"
        "cmpb $0, 2(%ebx)\n"
        "jne .Lf51d82_00051ecc\n"
        "movl dvarOnOffStrings+4, %eax\n" /* line 170 */
        "movl %eax, 0xc(%esi)\n" /* line 231 */
        "jmp .Lf51d82_00051da8\n"
        ".Lf51d82_00051f02:\n"
        "cmpb $0x66, %al\n" /* line 167 */
        "jne .Lf51d82_00051ecc\n"
        "cmpb $0x66, 2(%ebx)\n"
        "jne .Lf51d82_00051ecc\n"
        "cmpb $0, 3(%ebx)\n"
        "jne .Lf51d82_00051ecc\n"
        "movl dvarOnOffStrings, %eax\n" /* line 168 */
        "movl %eax, 0xc(%esi)\n" /* line 231 */
        "jmp .Lf51d82_00051da8\n"
    );
}

/* line 1279 */
__attribute__((naked))
void Dvar_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1279 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl sortedDvars, %ebx\n" /* line 1283 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf51f20_00051f3a\n"
        "jmp .Lf51f20_00051f63\n"
        ".Lf51f20_00051f33:\n"
        "movl 0x1c(%ebx), %ebx\n" /* dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "je .Lf51f20_00051f63\n"
        ".Lf51f20_00051f3a:\n"
        "movzbl 6(%ebx), %eax\n" /* line 1285 | dvar */
        "cmpb $7, %al\n"
        "je .Lf51f20_00051fb4\n"
        "subb $2, %al\n" /* line 1291 */
        "cmpb $2, %al\n"
        "jbe .Lf51f20_0005206a\n"
        ".Lf51f20_00051f4c:\n"
        "testb $0x40, 5(%ebx)\n" /* line 1296 | dvar */
        "je .Lf51f20_00051f33\n"
        "movl (%ebx), %eax\n" /* line 145 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 1283 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf51f20_00051f3a\n"
        ".Lf51f20_00051f63:\n"
        "movl $0, dvarCount\n" /* line 1300 */
        "movl $0, sortedDvars\n" /* line 1301 */
        "movl $0, dvar_cheats\n" /* line 1302 */
        "movl $0, dvar_modifiedFlags\n" /* line 1303 */
        "movb $0, isDvarSystemActive\n" /* line 1304 */
        "movl $0x400, 8(%esp)\n" /* line 1306 */
        "movl $0, 4(%esp)\n"
        "movl $dvarHashTable, (%esp)\n"
        "calll memset\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1307 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf51f20_00051fb4:\n"
        "movl 8(%ebx), %eax\n" /* line 191 */
        "cmpl 0xc(%ebx), %eax\n"
        "je .Lf51f20_00051fea\n"
        "cmpl 0x10(%ebx), %eax\n"
        "je .Lf51f20_00051fea\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "je .Lf51f20_00051fea\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "je .Lf51f20_0005207a\n"
        ".Lf51f20_00051fd2:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf51f20_00051fea\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf51f20_00051fea\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        ".Lf51f20_00051fea:\n"
        "movl $0, 8(%ebx)\n" /* line 193 */
        "movl 0x10(%ebx), %eax\n" /* line 207 */
        "testl %eax, %eax\n"
        "je .Lf51f20_00052026\n"
        "cmpl 0xc(%ebx), %eax\n"
        "je .Lf51f20_00052026\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "je .Lf51f20_00052026\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "je .Lf51f20_0005209d\n"
        ".Lf51f20_0005200e:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf51f20_00052026\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf51f20_00052026\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        ".Lf51f20_00052026:\n"
        "movl $0, 0x10(%ebx)\n" /* line 209 */
        "movl 0xc(%ebx), %eax\n" /* line 199 */
        "cmpl 8(%ebx), %eax\n"
        "je .Lf51f20_0005205e\n"
        "testl %eax, %eax\n"
        "je .Lf51f20_0005205e\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "je .Lf51f20_0005205e\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "je .Lf51f20_00052091\n"
        ".Lf51f20_00052046:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf51f20_0005205e\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf51f20_0005205e\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        ".Lf51f20_0005205e:\n"
        "movl $0, 0xc(%ebx)\n" /* line 201 */
        "jmp .Lf51f20_00051f4c\n"
        ".Lf51f20_0005206a:\n"
        "movl 8(%ebx), %eax\n" /* line 133 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "jmp .Lf51f20_00051f4c\n"
        ".Lf51f20_0005207a:\n"
        "cmpb $0x2f, %dl\n" /* line 181 */
        "jle .Lf51f20_00051fd2\n"
        "cmpb $0x39, %dl\n"
        "jle .Lf51f20_00051fea\n"
        "jmp .Lf51f20_00051fd2\n"
        ".Lf51f20_00052091:\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf51f20_00052046\n"
        "cmpb $0x39, %dl\n"
        "jle .Lf51f20_0005205e\n"
        "jmp .Lf51f20_00052046\n"
        ".Lf51f20_0005209d:\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf51f20_0005200e\n"
        "cmpb $0x39, %dl\n"
        "jle .Lf51f20_00052026\n"
        "jmp .Lf51f20_0005200e\n"
    );
}

/* line 2406 */
__attribute__((naked))
Bool Dvar_AnyLatchedValues(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2406 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        /* { scope 1 */
        "movl sortedDvars, %ebx\n" /* line 2410 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "je .Lf520b6_000520e1\n"
        ".Lf520b6_000520c7:\n"
        "movl 0xc(%ebx), %ecx\n" /* line 910 */
        "movl 8(%ebx), %edx\n"
        "movzbl 6(%ebx), %eax\n"
        "calll Dvar_ValuesEqual\n"
        "testb %al, %al\n"
        "je .Lf520b6_000520e9\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 2410 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf520b6_000520c7\n"
        ".Lf520b6_000520e1:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $4, %esp\n" /* line 2417 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf520b6_000520e9:\n"
        "movl $1, %eax\n" /* line 2410 */
        /* } scope */
        "addl $4, %esp\n" /* line 2417 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2542 */
__attribute__((naked))
qboolean Com_SaveDvarsToBuffer(const char * *dvarnames, int numDvars, char *buffer, int bufsize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2542 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 2553 | numDvars */
        "testl %eax, %eax\n"
        "jle .Lf520f4_00052197\n"
        "movl $0, -0x1c(%ebp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* i */
        ".Lf520f4_00052112:\n"
        "movl 8(%ebp), %edx\n" /* line 2555 | dvarnames */
        "movl (%edx, %eax, 4), %esi\n" /* fname */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        "testl %esi, %esi\n" /* line 68 */
        "je .Lf520f4_000521d3\n"
        ".Lf520f4_00052120:\n"
        "movzbl (%esi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf520f4_000521a4\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf520f4_00052129:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf520f4_0005214d\n"
        ".Lf520f4_00052134:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fname */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf520f4_0005214f\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf520f4_00052134\n"
        ".Lf520f4_0005214d:\n"
        "xorl %ebx, %ebx\n" /* var */
        /* } scope */
        ".Lf520f4_0005214f:\n"
        "movl 8(%ebx), %edx\n" /* line 506 */
        "movl %ebx, %eax\n"
        "calll Dvar_ValueToString\n"
        "movl %eax, 0x10(%esp)\n" /* line 2558 */
        "movl (%ebx), %eax\n" /* var */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_00219570, 8(%esp)\n" /* "%s "%s"
" */
        "movl 0x14(%ebp), %eax\n" /* bufsize */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* buffer */
        "movl %edx, (%esp)\n"
        "calll snprintf\n"
        "testl %eax, %eax\n" /* line 2559 */
        "js .Lf520f4_000521ec\n"
        "addl %eax, 0x10(%ebp)\n" /* line 2561 | buffer */
        "subl %eax, 0x14(%ebp)\n" /* line 2562 | bufsize */
        "addl $1, -0x1c(%ebp)\n" /* line 2553 | i */
        "movl -0x1c(%ebp), %eax\n" /* i */
        "cmpl %eax, 0xc(%ebp)\n" /* numDvars */
        "jne .Lf520f4_00052112\n"
        ".Lf520f4_00052197:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2566 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf520f4_000521a4:\n"
        "xorl %edi, %edi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf520f4_000521ab:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %edi\n" /* hash */
        "movzbl -0x76(%esi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf520f4_000521ab\n"
        "movl %edi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf520f4_00052129\n"
        ".Lf520f4_000521d3:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf520f4_00052120\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf520f4_000521ec:\n"
        "xorl %eax, %eax\n" /* line 2559 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2566 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1267 */
__attribute__((naked))
void Dvar_GetUnpackedColorByName(const char *dvarName, long unsigned int (*expandedColor)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1267 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf521f6_000522f3\n"
        ".Lf521f6_0005220a:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf521f6_0005225e\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf521f6_00052213:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf521f6_00052237\n"
        ".Lf521f6_0005221e:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf521f6_0005228a\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf521f6_0005221e\n"
        /* } scope */
        ".Lf521f6_00052237:\n"
        "movl imp_colorWhite, %edx\n" /* line 456 */
        "movl (%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* expandedColor */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        "addl $0x2c, %esp\n" /* line 1276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf521f6_0005225e:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf521f6_00052265:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf521f6_00052265\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf521f6_00052213\n"
        /* } scope */
        /* } scope */
        ".Lf521f6_0005228a:\n"
        "testl %ebx, %ebx\n" /* line 1272 | var */
        "je .Lf521f6_00052237\n"
        /* { scope 1 */
        "cmpb $8, 6(%ebx)\n" /* line 1256 | var */
        "jne .Lf521f6_0005230c\n"
        "movl 8(%ebx), %eax\n" /* line 606 */
        "movl %eax, -0x1c(%ebp)\n" /* color */
        ".Lf521f6_0005229a:\n"
        "movzbl -0x1c(%ebp), %eax\n" /* line 1260 | color */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss lit4_002ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* expandedColor */
        "movss %xmm0, (%eax)\n"
        "movzbl -0x1b(%ebp), %eax\n" /* line 1261 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movl 0xc(%ebp), %edx\n" /* expandedColor */
        "movss %xmm0, 4(%edx)\n"
        "movzbl -0x1a(%ebp), %eax\n" /* line 1262 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movzbl -0x19(%ebp), %eax\n" /* line 1263 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf521f6_000522f3:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf521f6_0005220a\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        ".Lf521f6_0005230c:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 1259 | color */
        "movl 8(%ebx), %eax\n" /* var */
        "calll Dvar_StringToColor\n"
        "jmp .Lf521f6_0005229a\n"
    );
}

/* line 1226 */
__attribute__((naked))
const char * Dvar_GetVariantString(const char *dvarName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1226 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %esi, %esi\n" /* line 68 */
        "je .Lf5231a_000523a5\n"
        ".Lf5231a_0005232a:\n"
        "movzbl (%esi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf5231a_00052364\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf5231a_00052333:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf5231a_00052357\n"
        ".Lf5231a_0005233e:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5231a_00052390\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf5231a_0005233e\n"
        /* } scope */
        ".Lf5231a_00052357:\n"
        "movl $str_002157b8, %eax\n" /* line 1246 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf5231a_00052364:\n"
        "xorl %edi, %edi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf5231a_0005236b:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %edi\n" /* hash */
        "movzbl -0x76(%esi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf5231a_0005236b\n"
        "movl %edi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf5231a_00052333\n"
        /* } scope */
        /* } scope */
        ".Lf5231a_00052390:\n"
        "testl %ebx, %ebx\n" /* line 1232 | var */
        "je .Lf5231a_00052357\n"
        "movl 8(%ebx), %edx\n" /* line 1239 | var */
        "movl %ebx, %eax\n" /* var */
        "addl $0x1c, %esp\n" /* line 1246 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Dvar_ValueToString\n" /* line 1239 */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf5231a_000523a5:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf5231a_0005232a\n"
    );
}

/* line 1211 */
__attribute__((naked))
const char * Dvar_GetString(const char *dvarName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1211 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf523be_00052449\n"
        ".Lf523be_000523ce:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf523be_00052408\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf523be_000523d7:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf523be_000523fb\n"
        ".Lf523be_000523e2:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf523be_00052434\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf523be_000523e2\n"
        /* } scope */
        ".Lf523be_000523fb:\n"
        "movl $str_002157b8, %eax\n" /* line 254 */
        ".Lf523be_00052400:\n"
        "addl $0x1c, %esp\n" /* line 1223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf523be_00052408:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf523be_0005240f:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf523be_0005240f\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf523be_000523d7\n"
        /* } scope */
        /* } scope */
        ".Lf523be_00052434:\n"
        "testl %ebx, %ebx\n" /* line 1216 | var */
        "je .Lf523be_000523fb\n"
        "cmpb $6, 6(%ebx)\n" /* line 1220 | var */
        "je .Lf523be_00052462\n"
        "movl 8(%ebx), %eax\n" /* line 1222 | var */
        "addl $0x1c, %esp\n" /* line 1223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf523be_00052449:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf523be_000523ce\n"
        /* } scope */
        /* } scope */
        ".Lf523be_00052462:\n"
        "movl 0x14(%ebx), %eax\n" /* line 254 */
        "testl %eax, %eax\n"
        "je .Lf523be_000523fb\n"
        "movl 8(%ebx), %edx\n" /* line 256 */
        "movl 0x18(%ebx), %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "jmp .Lf523be_00052400\n"
    );
}

/* line 1147 */
__attribute__((naked))
float Dvar_GetFloat(const char *dvarName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1147 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf52476_00052519\n"
        ".Lf52476_0005248a:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf52476_000524c1\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf52476_00052493:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf52476_000524b7\n"
        ".Lf52476_0005249e:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf52476_000524ed\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf52476_0005249e\n"
        /* } scope */
        ".Lf52476_000524b7:\n"
        "fldz\n" /* line 1152 */
        ".Lf52476_000524b9:\n"
        "addl $0x3c, %esp\n" /* line 1160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf52476_000524c1:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf52476_000524c8:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf52476_000524c8\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf52476_00052493\n"
        /* } scope */
        /* } scope */
        ".Lf52476_000524ed:\n"
        "testl %ebx, %ebx\n" /* line 1152 | var */
        "je .Lf52476_000524b7\n"
        "cmpb $1, 6(%ebx)\n" /* line 1156 | var */
        "jne .Lf52476_000524fc\n"
        "flds 8(%ebx)\n" /* line 1157 | var */
        "jmp .Lf52476_000524b9\n"
        ".Lf52476_000524fc:\n"
        "movl 8(%ebx), %eax\n" /* line 350 */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x20(%ebp)\n"
        "cvtsd2ss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "flds -0x2c(%ebp)\n"
        "jmp .Lf52476_000524b9\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf52476_00052519:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf52476_0005248a\n"
    );
}

/* line 1131 */
__attribute__((naked))
int Dvar_GetInt(const char *dvarName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1131 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %esi, %esi\n" /* line 68 */
        "je .Lf52532_000525c9\n"
        ".Lf52532_00052546:\n"
        "movzbl (%esi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf52532_0005257d\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf52532_0005254f:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf52532_00052573\n"
        ".Lf52532_0005255a:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf52532_000525a9\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf52532_0005255a\n"
        /* } scope */
        ".Lf52532_00052573:\n"
        "xorl %eax, %eax\n" /* line 1136 */
        ".Lf52532_00052575:\n"
        "addl $0x1c, %esp\n" /* line 1144 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf52532_0005257d:\n"
        "xorl %edi, %edi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf52532_00052584:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %edi\n" /* hash */
        "movzbl -0x76(%esi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf52532_00052584\n"
        "movl %edi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf52532_0005254f\n"
        /* } scope */
        /* } scope */
        ".Lf52532_000525a9:\n"
        "testl %ebx, %ebx\n" /* line 1136 | var */
        "je .Lf52532_00052573\n"
        "movzbl 6(%ebx), %eax\n" /* line 1140 | var */
        "subb $5, %al\n"
        "cmpb $1, %al\n"
        "jbe .Lf52532_000525e2\n"
        "movl 8(%ebx), %eax\n" /* line 343 */
        "movl %eax, 8(%ebp)\n" /* dvarName */
        "addl $0x1c, %esp\n" /* line 1144 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp atoi\n" /* line 343 */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf52532_000525c9:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf52532_00052546\n"
        /* } scope */
        /* } scope */
        ".Lf52532_000525e2:\n"
        "movl 8(%ebx), %eax\n" /* line 1141 | var */
        "jmp .Lf52532_00052575\n"
    );
}

/* line 1115 */
__attribute__((naked))
Bool Dvar_GetBool(const char *dvarName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1115 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf525e8_00052671\n"
        ".Lf525e8_000525f8:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf525e8_0005262f\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf525e8_00052601:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf525e8_00052625\n"
        ".Lf525e8_0005260c:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf525e8_0005265b\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf525e8_0005260c\n"
        /* } scope */
        ".Lf525e8_00052625:\n"
        "xorl %eax, %eax\n" /* line 1120 */
        ".Lf525e8_00052627:\n"
        "addl $0x1c, %esp\n" /* line 1128 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf525e8_0005262f:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf525e8_00052636:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf525e8_00052636\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf525e8_00052601\n"
        /* } scope */
        /* } scope */
        ".Lf525e8_0005265b:\n"
        "testl %ebx, %ebx\n" /* line 1120 | var */
        "je .Lf525e8_00052625\n"
        "cmpb $0, 6(%ebx)\n" /* line 1124 | var */
        "jne .Lf525e8_0005268a\n"
        "movzbl 8(%ebx), %eax\n" /* line 1125 | var */
        "addl $0x1c, %esp\n" /* line 1128 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf525e8_00052671:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf525e8_000525f8\n"
        /* } scope */
        /* } scope */
        ".Lf525e8_0005268a:\n"
        "movl 8(%ebx), %eax\n" /* line 336 */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "testl %eax, %eax\n" /* line 1127 */
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf525e8_00052627\n"
    );
}

/* line 1072 */
__attribute__((naked))
const dvar_t * Dvar_FindVar(const char *dvarName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1072 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf526a0_00052715\n"
        ".Lf526a0_000526b0:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf526a0_000526e9\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf526a0_000526b9:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf526a0_000526dd\n"
        ".Lf526a0_000526c4:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf526a0_000526df\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf526a0_000526c4\n"
        ".Lf526a0_000526dd:\n"
        "xorl %ebx, %ebx\n" /* var */
        /* } scope */
        ".Lf526a0_000526df:\n"
        "movl %ebx, %eax\n" /* line 1075 | var */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf526a0_000526e9:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf526a0_000526f0:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf526a0_000526f0\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf526a0_000526b9\n"
        ".Lf526a0_00052715:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf526a0_000526b0\n"
    );
}

/* line 1092 */
__attribute__((naked))
void Dvar_UpdateEnumDomain(const dvar_t *dvar, const char * *stringTable)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1092 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvar */
        "movl 0xc(%ebp), %edx\n" /* stringTable */
        /* { scope 1 */
        "movl (%edx), %ebx\n" /* line 1103 */
        "testl %ebx, %ebx\n"
        "je .Lf5272c_000528b9\n"
        "xorl %eax, %eax\n"
        ".Lf5272c_00052747:\n"
        "addl $1, %eax\n" /* line 1104 */
        "movl (%edx, %eax, 4), %ecx\n" /* line 1103 */
        "testl %ecx, %ecx\n"
        "jne .Lf5272c_00052747\n"
        ".Lf5272c_00052751:\n"
        "movl %eax, 0x14(%esi)\n" /* line 1108 | dvar */
        "movl %edx, 0x18(%esi)\n" /* line 1109 | dvar */
        "movl 0x14(%esi), %edx\n" /* line 1110 | dvar */
        "movl 0x18(%esi), %ecx\n" /* dvar */
        "movl 0x10(%esi), %eax\n" /* dvar */
        "movl %eax, -0x10(%ebp)\n"
        "movl 8(%esi), %ebx\n" /* dvar */
        "movl %ebx, %edi\n" /* value */
        /* { scope 2 */
        "movzbl 6(%esi), %eax\n" /* line 587 */
        "cmpl $6, %eax\n"
        "ja .Lf5272c_00052786\n"
        "jmpl *dvarDigitStrings+128(, %eax, 4)\n"
        "cmpl %edx, %ebx\n" /* line 595 */
        "jl .Lf5272c_000528d3\n"
        "cmpl %ecx, %ebx\n" /* line 597 */
        "jle .Lf5272c_00052786\n"
        "movl %ecx, %edi\n" /* line 598 */
        /* } scope */
        ".Lf5272c_00052786:\n"
        "movl %edi, 8(%esi)\n" /* line 1110 | value, dvar */
        "movl %edi, 0xc(%esi)\n" /* line 1111 | value, dvar */
        /* } scope */
        "addl $8, %esp\n" /* line 1112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        "testb %bl, %bl\n" /* line 590 */
        "movl %ebx, %eax\n"
        "setne %al\n"
        "movl %eax, %edi\n"
        "jmp .Lf5272c_00052786\n"
        "testl %ebx, %ebx\n" /* line 625 */
        "js .Lf5272c_000527a7\n"
        "cmpl %edx, %ebx\n"
        "jl .Lf5272c_00052786\n"
        ".Lf5272c_000527a7:\n"
        "movl -0x10(%ebp), %edi\n" /* line 627 */
        "jmp .Lf5272c_00052786\n"
        "movl %ecx, -0x14(%ebp)\n" /* line 617 */
        "movss -0x14(%ebp), %xmm1\n" /* min */
        "movaps %xmm1, %xmm2\n" /* min, max */
        "movl %edx, -0x14(%ebp)\n"
        "movss -0x14(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* min */
        "movl $1, %edx\n"
        "leal 4(%ebx), %eax\n"
        /* { scope 3 */
        "movss -4(%eax), %xmm0\n" /* line 562 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf5272c_000527ee\n"
        ".Lf5272c_000527d4:\n"
        "movss %xmm1, -4(%eax)\n" /* line 563 */
        ".Lf5272c_000527d9:\n"
        "addl $1, %edx\n" /* line 565 */
        "addl $4, %eax\n"
        "cmpl $5, %edx\n" /* line 560 */
        "je .Lf5272c_00052786\n"
        "movss -4(%eax), %xmm0\n" /* line 562 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf5272c_000527d4\n"
        ".Lf5272c_000527ee:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 564 */
        "jbe .Lf5272c_000527d9\n"
        "movss %xmm2, -4(%eax)\n" /* line 565 */
        "jmp .Lf5272c_000527d9\n"
        /* } scope */
        "movl %ecx, -0x14(%ebp)\n" /* line 613 */
        "movss -0x14(%ebp), %xmm1\n" /* min */
        "movaps %xmm1, %xmm2\n" /* min, max */
        "movl %edx, -0x14(%ebp)\n"
        "movss -0x14(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* min */
        "movl $1, %edx\n"
        "leal 4(%ebx), %eax\n"
        /* { scope 3 */
        "movss -4(%eax), %xmm0\n" /* line 562 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf5272c_00052840\n"
        ".Lf5272c_00052822:\n"
        "movss %xmm1, -4(%eax)\n" /* line 563 */
        ".Lf5272c_00052827:\n"
        "addl $1, %edx\n" /* line 565 */
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 560 */
        "je .Lf5272c_00052786\n"
        "movss -4(%eax), %xmm0\n" /* line 562 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf5272c_00052822\n"
        ".Lf5272c_00052840:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 564 */
        "jbe .Lf5272c_00052827\n"
        "movss %xmm2, -4(%eax)\n" /* line 565 */
        "jmp .Lf5272c_00052827\n"
        /* } scope */
        "movl %ecx, -0x14(%ebp)\n" /* line 609 */
        "movss -0x14(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm2\n" /* max */
        "movl %edx, -0x14(%ebp)\n"
        "movss -0x14(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* min */
        "movl $1, %edx\n"
        "leal 4(%ebx), %eax\n"
        /* { scope 3 */
        ".Lf5272c_0005286a:\n"
        "movss -4(%eax), %xmm0\n" /* line 562 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf5272c_000528c0\n"
        "movss %xmm1, -4(%eax)\n" /* line 563 */
        ".Lf5272c_00052879:\n"
        "addl $1, %edx\n" /* line 565 */
        "addl $4, %eax\n"
        "cmpl $3, %edx\n" /* line 560 */
        "jne .Lf5272c_0005286a\n"
        "jmp .Lf5272c_00052786\n"
        /* } scope */
        "movl %ebx, -0x14(%ebp)\n" /* line 602 */
        "movss -0x14(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movl %edx, -0x14(%ebp)\n"
        "movss -0x14(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf5272c_000528cc\n"
        "movl %ecx, -0x14(%ebp)\n" /* line 604 */
        "movss -0x14(%ebp), %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf5272c_00052786\n"
        "movl %ecx, %edi\n" /* line 605 */
        "jmp .Lf5272c_00052786\n"
        /* } scope */
        ".Lf5272c_000528b9:\n"
        "xorl %eax, %eax\n" /* line 1103 */
        "jmp .Lf5272c_00052751\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf5272c_000528c0:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 564 */
        "jbe .Lf5272c_00052879\n"
        "movss %xmm2, -4(%eax)\n" /* line 565 */
        "jmp .Lf5272c_00052879\n"
        /* } scope */
        ".Lf5272c_000528cc:\n"
        "movl %edx, %edi\n" /* line 603 */
        "jmp .Lf5272c_00052786\n"
        ".Lf5272c_000528d3:\n"
        "movl %edx, %edi\n" /* line 596 */
        "jmp .Lf5272c_00052786\n"
    );
}

/* line 716 */
static __attribute__((naked))
const char * Dvar_DomainToString_Internal(char *outBuffer, int outBufferLen, int *outLineCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 716 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %edx, %ebx\n" /* outBufferLen, domain */
        "movl %ecx, %esi\n"
        "movl 8(%ebp), %edi\n" /* outBuffer */
        "movl 0xc(%ebp), %edx\n" /* outBufferLen */
        /* { scope 1 */
        "leal (%edx, %edi), %ecx\n" /* line 724 */
        "movl %ecx, -0x1c(%ebp)\n" /* outBufferEnd */
        "movl 0x10(%ebp), %ecx\n" /* line 726 | outLineCount */
        "testl %ecx, %ecx\n"
        "je .Lf528da_00052903\n"
        "movl 0x10(%ebp), %ecx\n" /* line 727 | outLineCount */
        "movl $0, (%ecx)\n"
        ".Lf528da_00052903:\n"
        "movzbl %al, %eax\n" /* line 729 */
        "cmpl $8, %eax\n"
        "ja .Lf528da_00052912\n"
        "jmpl *dvarDigitStrings+156(, %eax, 4)\n"
        ".Lf528da_00052912:\n"
        "movb $0, (%edi)\n" /* line 809 | outBuffer */
        ".Lf528da_00052915:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 812 | outBufferEnd */
        "movb $0, -1(%ecx)\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 815 | outBuffer */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl $str_0021957c, 8(%esp)\n" /* line 732 */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        "movl $str_0021979c, 8(%esp)\n" /* line 803 */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        "movl $str_0021975c, 8(%esp)\n" /* line 782 */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        "movl $str_00219770, 8(%esp)\n" /* line 786 */
        "movl -0x1c(%ebp), %eax\n" /* outBufferEnd */
        "subl %edi, %eax\n" /* outBuffer */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "testl %eax, %eax\n" /* line 787 */
        "js .Lf528da_00052915\n"
        "addl %eax, %edi\n" /* line 789 | outBuffer */
        "movl %ebx, -0x20(%ebp)\n" /* line 790 | stringIndex */
        "testl %ebx, %ebx\n" /* stringIndex */
        "jle .Lf528da_00052915\n"
        "movl 0x10(%ebp), %eax\n" /* line 792 | outLineCount */
        "testl %eax, %eax\n"
        "jne .Lf528da_00052e3a\n"
        "xorl %ebx, %ebx\n" /* line 812 | stringIndex */
        ".Lf528da_0005299b:\n"
        "movl (%esi, %ebx, 4), %eax\n" /* line 792 */
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* stringIndex */
        "movl $str_00219790, 8(%esp)\n" /* "
  %2i: %s" */
        "movl -0x1c(%ebp), %eax\n" /* outBufferEnd */
        "subl %edi, %eax\n" /* outBuffer */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "testl %eax, %eax\n" /* line 793 */
        "js .Lf528da_00052915\n"
        "addl %eax, %edi\n" /* line 797 | outBuffer */
        "addl $1, %ebx\n" /* line 790 | stringIndex */
        "cmpl %ebx, -0x20(%ebp)\n" /* stringIndex */
        "jne .Lf528da_0005299b\n"
        "jmp .Lf528da_00052915\n"
        "cmpl $0x80000000, %ebx\n" /* line 736 | stringIndex */
        "je .Lf528da_00052cbb\n"
        "cmpl $0x7fffffff, %esi\n" /* line 738 */
        "je .Lf528da_00052e04\n"
        "movl %esi, 0x10(%esp)\n" /* line 739 */
        "movl %ebx, 0xc(%esp)\n" /* stringIndex */
        "movl $str_00219590, 8(%esp)\n" /* "Domain is any integer from %i to %i" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        "movl %ebx, -0x2c(%ebp)\n" /* line 699 */
        "movss -0x2c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "ucomiss lit4_002ed680, %xmm2\n" /* -3.4028234663852886e+38f */
        "jp .Lf528da_00052c70\n"
        "jne .Lf528da_00052c70\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 708 */
        "movss -0x2c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss lit4_002ed684, %xmm1\n" /* 3.4028234663852886e+38f */
        "jp .Lf528da_00052a47\n"
        "je .Lf528da_00052d28\n"
        ".Lf528da_00052a47:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 709 */
        "movsd %xmm0, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $str_00219708, 8(%esp)\n" /* "Domain is any %iD vector with components %g or smaller" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        "movl %ebx, -0x2c(%ebp)\n" /* line 699 */
        "movss -0x2c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "ucomiss lit4_002ed680, %xmm2\n" /* -3.4028234663852886e+38f */
        "jp .Lf528da_00052c21\n"
        "jne .Lf528da_00052c21\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 708 */
        "movss -0x2c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss lit4_002ed684, %xmm1\n" /* 3.4028234663852886e+38f */
        "jp .Lf528da_00052aaa\n"
        "je .Lf528da_00052d74\n"
        ".Lf528da_00052aaa:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 709 */
        "movsd %xmm0, 0x10(%esp)\n"
        "movl $3, 0xc(%esp)\n"
        "movl $str_00219708, 8(%esp)\n" /* "Domain is any %iD vector with components %g or smaller" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        "movl %ebx, -0x2c(%ebp)\n" /* line 699 */
        "movss -0x2c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "ucomiss lit4_002ed680, %xmm2\n" /* -3.4028234663852886e+38f */
        "jp .Lf528da_00052bd2\n"
        "jne .Lf528da_00052bd2\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 708 */
        "movss -0x2c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss lit4_002ed684, %xmm1\n" /* 3.4028234663852886e+38f */
        "jp .Lf528da_00052b0d\n"
        "je .Lf528da_00052dc0\n"
        ".Lf528da_00052b0d:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 709 */
        "movsd %xmm0, 0x10(%esp)\n"
        "movl $2, 0xc(%esp)\n"
        "movl $str_00219708, 8(%esp)\n" /* "Domain is any %iD vector with components %g or smaller" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        "movl %ebx, -0x2c(%ebp)\n" /* line 753 | stringIndex */
        "movss -0x2c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss lit4_002ed680, %xmm1\n" /* -3.4028234663852886e+38f */
        "jp .Lf528da_00052b8b\n"
        "jne .Lf528da_00052b8b\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 762 */
        "movss -0x2c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss lit4_002ed684, %xmm1\n" /* 3.4028234663852886e+38f */
        "jp .Lf528da_00052b68\n"
        "je .Lf528da_00052ce4\n"
        ".Lf528da_00052b68:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 763 */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl $str_0021965c, 8(%esp)\n" /* "Domain is any number %g or smaller" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052b8b:\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 755 */
        "movss -0x2c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "ucomiss lit4_002ed684, %xmm2\n" /* 3.4028234663852886e+38f */
        "jp .Lf528da_00052ba5\n"
        "je .Lf528da_00052de1\n"
        ".Lf528da_00052ba5:\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 756 */
        "movsd %xmm1, 0x14(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 0xc(%esp)\n"
        "movl $str_00219614, 8(%esp)\n" /* "Domain is any number from %g to %g" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052bd2:\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 701 */
        "movss -0x2c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "ucomiss lit4_002ed684, %xmm2\n" /* 3.4028234663852886e+38f */
        "jp .Lf528da_00052bec\n"
        "je .Lf528da_00052d95\n"
        ".Lf528da_00052bec:\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 702 */
        "movsd %xmm1, 0x18(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "movl $2, 0xc(%esp)\n"
        "movl $str_00219698, 8(%esp)\n" /* "Domain is any %iD vector with components from %g to %g" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052c21:\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 701 */
        "movss -0x2c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "ucomiss lit4_002ed684, %xmm2\n" /* 3.4028234663852886e+38f */
        "jp .Lf528da_00052c3b\n"
        "je .Lf528da_00052d49\n"
        ".Lf528da_00052c3b:\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 702 */
        "movsd %xmm1, 0x18(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "movl $3, 0xc(%esp)\n"
        "movl $str_00219698, 8(%esp)\n" /* "Domain is any %iD vector with components from %g to %g" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052c70:\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 701 */
        "movss -0x2c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "ucomiss lit4_002ed684, %xmm2\n" /* 3.4028234663852886e+38f */
        "jp .Lf528da_00052c86\n"
        "je .Lf528da_00052cfd\n"
        ".Lf528da_00052c86:\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 702 */
        "movsd %xmm1, 0x18(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $str_00219698, 8(%esp)\n" /* "Domain is any %iD vector with components from %g to %g" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052cbb:\n"
        "cmpl $0x7fffffff, %esi\n" /* line 745 */
        "je .Lf528da_00052e21\n"
        "movl %esi, 0xc(%esp)\n" /* line 746 */
        "movl $str_002195d8, 8(%esp)\n" /* "Domain is any integer %i or smaller" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052ce4:\n"
        "movl $str_00219680, 8(%esp)\n" /* line 765 */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052cfd:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 704 */
        "movsd %xmm0, 0x10(%esp)\n"
        "movl $4, 0xc(%esp)\n"
        "movl $str_002196d0, 8(%esp)\n" /* "Domain is any %iD vector with components %g or bigger" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052d28:\n"
        "movl $4, 0xc(%esp)\n" /* line 711 */
        "movl $str_00219740, 8(%esp)\n" /* "Domain is any %iD vector" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052d49:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 704 */
        "movsd %xmm0, 0x10(%esp)\n"
        "movl $3, 0xc(%esp)\n"
        "movl $str_002196d0, 8(%esp)\n" /* "Domain is any %iD vector with components %g or bigger" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052d74:\n"
        "movl $3, 0xc(%esp)\n" /* line 711 */
        "movl $str_00219740, 8(%esp)\n" /* "Domain is any %iD vector" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052d95:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 704 */
        "movsd %xmm0, 0x10(%esp)\n"
        "movl $2, 0xc(%esp)\n"
        "movl $str_002196d0, 8(%esp)\n" /* "Domain is any %iD vector with components %g or bigger" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052dc0:\n"
        "movl $2, 0xc(%esp)\n" /* line 711 */
        "movl $str_00219740, 8(%esp)\n" /* "Domain is any %iD vector" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052de1:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 758 */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl $str_00219638, 8(%esp)\n" /* "Domain is any number %g or bigger" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052e04:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 741 | stringIndex */
        "movl $str_002195b4, 8(%esp)\n" /* "Domain is any integer %i or bigger" */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052e21:\n"
        "movl $str_002195fc, 8(%esp)\n" /* line 748 */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "jmp .Lf528da_00052915\n"
        ".Lf528da_00052e3a:\n"
        "xorl %ebx, %ebx\n" /* line 792 | stringIndex */
        ".Lf528da_00052e3c:\n"
        "movl (%esi, %ebx, 4), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* stringIndex */
        "movl $str_00219790, 8(%esp)\n" /* "
  %2i: %s" */
        "movl -0x1c(%ebp), %eax\n" /* outBufferEnd */
        "subl %edi, %eax\n" /* outBuffer */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* outBuffer */
        "calll snprintf\n"
        "testl %eax, %eax\n" /* line 793 */
        "js .Lf528da_00052915\n"
        "movl 0x10(%ebp), %edx\n" /* line 796 | outLineCount */
        "addl $1, (%edx)\n"
        "addl %eax, %edi\n" /* line 797 | outBuffer */
        "addl $1, %ebx\n" /* line 790 | stringIndex */
        "cmpl -0x20(%ebp), %ebx\n" /* stringIndex */
        "jne .Lf528da_00052e3c\n"
        "jmp .Lf528da_00052915\n"
    );
}

/* line 824 */
__attribute__((naked))
const char * Dvar_DomainToString_GetLines(int type, DvarLimits domain, char *outBuffer, int outBufferLen, int *outLineCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 824 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* domain */
        "movl 0x10(%ebp), %ecx\n"
        "movzbl 8(%ebp), %eax\n" /* line 827 | type */
        "movl 0x1c(%ebp), %ebx\n" /* outLineCount */
        "movl %ebx, 0x10(%ebp)\n" /* outLineCount */
        "movl 0x18(%ebp), %ebx\n" /* outBufferLen, outLineCount */
        "movl %ebx, 0xc(%ebp)\n" /* outLineCount, domain */
        "movl 0x14(%ebp), %ebx\n" /* outBuffer, outLineCount */
        "movl %ebx, 8(%ebp)\n" /* outLineCount, type */
        "popl %ebx\n" /* line 828 */
        "popl %ebp\n"
        "jmp Dvar_DomainToString_Internal\n" /* line 827 */
    );
}

/* line 831 */
__attribute__((naked))
void Dvar_PrintDomain(int type, DvarLimits domain)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 831 */
        "movl %esp, %ebp\n"
        "subl $0x418, %esp\n"
        /* { scope 1 */
        "movzbl 8(%ebp), %eax\n" /* line 820 | type */
        "movl $0, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x408(%ebp), %edx\n" /* domainBuffer */
        "movl %edx, (%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* domain */
        "movl 0x10(%ebp), %ecx\n"
        "calll Dvar_DomainToString_Internal\n"
        "movl %eax, 4(%esp)\n" /* line 834 */
        "movl $str_002182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "leave\n" /* line 835 */
        "retl\n"
    );
}

/* line 1310 */
static __attribute__((naked))
void Dvar_PerformUnregistration(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1310 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %ebx\n" /* dvar */
        /* { scope 1 */
        "movzwl 4(%eax), %eax\n" /* line 1316 */
        "testb $0x40, %ah\n"
        "je .Lf52eea_00053022\n"
        ".Lf52eea_00052f02:\n"
        "movzbl 6(%ebx), %eax\n" /* line 1321 | dvar */
        "cmpb $7, %al\n"
        "je .Lf52eea_00052fad\n"
        "subb $2, %al\n" /* line 1325 */
        "cmpb $2, %al\n"
        "jbe .Lf52eea_00052fb5\n"
        "movl $0, -0x1c(%ebp)\n" /* vectorMem */
        "movl 0xc(%ebx), %edx\n" /* line 546 */
        "movl %ebx, %eax\n"
        "calll Dvar_ValueToString\n"
        "movl %eax, %esi\n" /* s */
        "movzbl (%eax), %edx\n" /* line 155 */
        "testb %dl, %dl\n"
        "jne .Lf52eea_00052fd2\n"
        ".Lf52eea_00052f36:\n"
        "movl $str_002157b8, %eax\n"
        ".Lf52eea_00052f3b:\n"
        "movl %eax, 8(%ebx)\n" /* line 1330 | dvar */
        "movl %eax, 0xc(%ebx)\n" /* line 1331 | dvar */
        "movl 0x10(%ebx), %edx\n" /* line 526 */
        "movl %ebx, %eax\n"
        "calll Dvar_ValueToString\n"
        "movl %eax, %esi\n" /* s */
        "movl 8(%ebx), %edi\n" /* line 238 */
        "testl %edi, %edi\n"
        "je .Lf52eea_00052f70\n"
        "cmpl %edi, %eax\n"
        "je .Lf52eea_00053001\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf52eea_00053001\n"
        ".Lf52eea_00052f70:\n"
        "movl 0xc(%ebx), %edi\n" /* line 240 */
        "testl %edi, %edi\n"
        "je .Lf52eea_00052f8f\n"
        "cmpl %edi, %esi\n" /* s */
        "je .Lf52eea_00053001\n"
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* s */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf52eea_00053001\n"
        ".Lf52eea_00052f8f:\n"
        "movzbl (%esi), %edx\n" /* line 155 */
        "testb %dl, %dl\n"
        "jne .Lf52eea_00053050\n"
        "movl $str_002157b8, %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* line 243 */
        ".Lf52eea_00052fa2:\n"
        "movb $7, 6(%ebx)\n" /* line 1333 | dvar */
        "movl -0x1c(%ebp), %ebx\n" /* line 1335 | vectorMem, dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf52eea_0005300f\n"
        /* } scope */
        ".Lf52eea_00052fad:\n"
        "addl $0x2c, %esp\n" /* line 1337 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf52eea_00052fb5:\n"
        "movl 8(%ebx), %eax\n" /* line 1326 | dvar */
        "movl %eax, -0x1c(%ebp)\n" /* vectorMem */
        "movl 0xc(%ebx), %edx\n" /* line 546 */
        "movl %ebx, %eax\n"
        "calll Dvar_ValueToString\n"
        "movl %eax, %esi\n" /* s */
        "movzbl (%eax), %edx\n" /* line 155 */
        "testb %dl, %dl\n"
        "je .Lf52eea_00052f36\n"
        /* { scope 2 */
        ".Lf52eea_00052fd2:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        /* } scope */
        "movzbl 1(%esi), %eax\n" /* line 160 | s */
        "testb %al, %al\n"
        "je .Lf52eea_0005303a\n"
        "cmpb $0x6f, %dl\n" /* line 165 */
        "je .Lf52eea_00053097\n"
        ".Lf52eea_00052ff4:\n"
        "movl %esi, (%esp)\n" /* line 173 | s */
        "calll CopyStringInternal\n"
        "jmp .Lf52eea_00052f3b\n"
        ".Lf52eea_00053001:\n"
        "movl %edi, 0x10(%ebx)\n" /* line 241 */
        "movb $7, 6(%ebx)\n" /* line 1333 | dvar */
        "movl -0x1c(%ebp), %ebx\n" /* line 1335 | vectorMem, dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "je .Lf52eea_00052fad\n"
        ".Lf52eea_0005300f:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1336 | vectorMem */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1337 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf52eea_00053022:\n"
        "orb $0x40, %ah\n" /* line 1318 */
        "movw %ax, 4(%ebx)\n" /* dvar */
        "movl (%ebx), %eax\n" /* line 139 */
        "movl %eax, (%esp)\n"
        "calll CopyStringInternal\n"
        "movl %eax, (%ebx)\n" /* line 1319 | dvar */
        "jmp .Lf52eea_00052f02\n"
        ".Lf52eea_0005303a:\n"
        "leal -0x30(%edx), %eax\n" /* line 162 */
        "cmpb $9, %al\n"
        "ja .Lf52eea_00052ff4\n"
        "movsbl %dl, %eax\n" /* line 163 */
        "leal __ZZN16CStringEdPackage9ParseLineEPKchE5C.208+1024(%eax, %eax), %eax\n"
        "jmp .Lf52eea_00052f3b\n"
        /* { scope 2 */
        ".Lf52eea_00053050:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        /* } scope */
        "movzbl 1(%esi), %eax\n" /* line 160 | s */
        "testb %al, %al\n"
        "je .Lf52eea_0005307e\n"
        "cmpb $0x6f, %dl\n" /* line 165 */
        "je .Lf52eea_000530e7\n"
        ".Lf52eea_0005306e:\n"
        "movl %esi, (%esp)\n" /* line 173 | s */
        "calll CopyStringInternal\n"
        "movl %eax, 0x10(%ebx)\n" /* line 243 */
        "jmp .Lf52eea_00052fa2\n"
        ".Lf52eea_0005307e:\n"
        "leal -0x30(%edx), %eax\n" /* line 162 */
        "cmpb $9, %al\n"
        "ja .Lf52eea_0005306e\n"
        "movsbl %dl, %eax\n" /* line 163 */
        "leal __ZZN16CStringEdPackage9ParseLineEPKchE5C.208+1024(%eax, %eax), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* line 243 */
        "jmp .Lf52eea_00052fa2\n"
        ".Lf52eea_00053097:\n"
        "cmpl $3, %ecx\n" /* line 167 */
        "je .Lf52eea_000530c1\n"
        "cmpl $2, %ecx\n" /* line 169 */
        "jne .Lf52eea_00052ff4\n"
        "cmpb $0x6e, %al\n"
        "jne .Lf52eea_00052ff4\n"
        "cmpb $0, 2(%esi)\n" /* s */
        "jne .Lf52eea_00052ff4\n"
        "movl dvarOnOffStrings+4, %eax\n" /* line 170 */
        "jmp .Lf52eea_00052f3b\n"
        ".Lf52eea_000530c1:\n"
        "cmpb $0x66, %al\n" /* line 167 */
        "jne .Lf52eea_00052ff4\n"
        "cmpb $0x66, 2(%esi)\n" /* s */
        "jne .Lf52eea_00052ff4\n"
        "cmpb $0, 3(%esi)\n" /* s */
        "jne .Lf52eea_00052ff4\n"
        "movl dvarOnOffStrings, %eax\n" /* line 168 */
        "jmp .Lf52eea_00052f3b\n"
        ".Lf52eea_000530e7:\n"
        "cmpl $3, %ecx\n" /* line 167 */
        "je .Lf52eea_00053114\n"
        "cmpl $2, %ecx\n" /* line 169 */
        "jne .Lf52eea_0005306e\n"
        "cmpb $0x6e, %al\n"
        "jne .Lf52eea_0005306e\n"
        "cmpb $0, 2(%esi)\n" /* s */
        "jne .Lf52eea_0005306e\n"
        "movl dvarOnOffStrings+4, %eax\n" /* line 170 */
        "movl %eax, 0x10(%ebx)\n" /* line 243 */
        "jmp .Lf52eea_00052fa2\n"
        ".Lf52eea_00053114:\n"
        "cmpb $0x66, %al\n" /* line 167 */
        "jne .Lf52eea_0005306e\n"
        "cmpb $0x66, 2(%esi)\n" /* s */
        "jne .Lf52eea_0005306e\n"
        "cmpb $0, 3(%esi)\n" /* s */
        "jne .Lf52eea_0005306e\n"
        "movl dvarOnOffStrings, %eax\n" /* line 168 */
        "movl %eax, 0x10(%ebx)\n" /* line 243 */
        "jmp .Lf52eea_00052fa2\n"
    );
}

/* line 1364 */
__attribute__((naked))
void Dvar_UnregisterSystem(int sysFlag)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1364 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %esi\n" /* sysFlag */
        /* { scope 1 */
        "movl sortedDvars, %ebx\n" /* line 1369 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "je .Lf5313e_0005317b\n"
        "movl %esi, %edi\n" /* sysFlag */
        "notl %edi\n"
        ".Lf5313e_00053158:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1371 | dvar */
        "testl %esi, %eax\n" /* sysFlag */
        "je .Lf5313e_00053174\n"
        "testb $0x40, %ah\n" /* line 1347 */
        "jne .Lf5313e_00053174\n"
        "movl %edi, %eax\n" /* line 1356 */
        "andw 4(%ebx), %ax\n"
        "movw %ax, 4(%ebx)\n"
        "testb $0x70, %ah\n" /* line 1357 */
        "je .Lf5313e_00053183\n"
        ".Lf5313e_00053174:\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 1369 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf5313e_00053158\n"
        /* } scope */
        ".Lf5313e_0005317b:\n"
        "addl $0xc, %esp\n" /* line 1374 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5313e_00053183:\n"
        "movl %ebx, %eax\n" /* line 1360 */
        "calll Dvar_PerformUnregistration\n"
        "jmp .Lf5313e_00053174\n"
    );
}

/* line 1377 */
static __attribute__((naked))
void Dvar_UpdateResetValue(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1377 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %esi\n" /* dvar */
        "movl %edx, %ebx\n" /* value */
        "movzbl 6(%eax), %eax\n" /* line 1380 */
        "cmpb $3, %al\n"
        "je .Lf5318c_000531d3\n"
        "jbe .Lf5318c_000531ba\n"
        "cmpb $4, %al\n"
        "je .Lf5318c_00053283\n"
        "cmpb $7, %al\n"
        "je .Lf5318c_000531ee\n"
        ".Lf5318c_000531af:\n"
        "movl %ebx, 0x10(%esi)\n" /* line 1400 | value, dvar */
        ".Lf5318c_000531b2:\n"
        "addl $0x1c, %esp\n" /* line 1403 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf5318c_000531ba:\n"
        "cmpb $2, %al\n" /* line 1380 */
        "jne .Lf5318c_000531af\n"
        "movl 0x10(%esi), %eax\n" /* line 1388 | dvar, to */
        /* { scope 1 */
        "movl (%edx), %edx\n" /* line 37 */
        "movl %edx, (%eax)\n"
        "movl 4(%ebx), %edx\n" /* line 38 */
        "movl %edx, 4(%eax)\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1403 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf5318c_000531d3:\n"
        "movl 0x10(%esi), %edx\n" /* line 1392 | dvar, to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1403 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf5318c_000531ee:\n"
        "movl 0x10(%esi), %eax\n" /* line 207 */
        "cmpl 8(%esi), %eax\n"
        "je .Lf5318c_0005322a\n"
        "cmpl 0xc(%esi), %eax\n"
        "je .Lf5318c_0005322a\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "je .Lf5318c_0005322a\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "jne .Lf5318c_00053212\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf5318c_00053212\n"
        "cmpb $0x39, %dl\n"
        "jle .Lf5318c_0005322a\n"
        ".Lf5318c_00053212:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf5318c_0005322a\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf5318c_0005322a\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        ".Lf5318c_0005322a:\n"
        "movl $0, 0x10(%esi)\n" /* line 209 */
        "movl 8(%esi), %edi\n" /* line 238 */
        "testl %edi, %edi\n"
        "je .Lf5318c_0005324c\n"
        "cmpl %edi, %ebx\n"
        "je .Lf5318c_0005327b\n"
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf5318c_0005327b\n"
        ".Lf5318c_0005324c:\n"
        "movl 0xc(%esi), %edi\n" /* line 240 */
        "testl %edi, %edi\n"
        "je .Lf5318c_00053267\n"
        "cmpl %edi, %ebx\n"
        "je .Lf5318c_0005327b\n"
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf5318c_0005327b\n"
        ".Lf5318c_00053267:\n"
        "movzbl (%ebx), %edx\n" /* line 155 */
        "testb %dl, %dl\n"
        "jne .Lf5318c_000532a4\n"
        "movl $str_002157b8, %eax\n"
        "movl %eax, 0x10(%esi)\n" /* line 243 */
        "jmp .Lf5318c_000531b2\n"
        ".Lf5318c_0005327b:\n"
        "movl %edi, 0x10(%esi)\n" /* line 241 */
        "jmp .Lf5318c_000531b2\n"
        ".Lf5318c_00053283:\n"
        "movl 0x10(%esi), %edx\n" /* line 1396 | dvar, to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 456 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1403 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf5318c_000532a4:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movzbl 1(%ebx), %eax\n" /* line 160 */
        "testb %al, %al\n"
        "jne .Lf5318c_000532e6\n"
        "leal -0x30(%edx), %eax\n" /* line 162 */
        "cmpb $9, %al\n"
        "ja .Lf5318c_000532d6\n"
        "movsbl %dl, %eax\n" /* line 163 */
        "leal __ZZN16CStringEdPackage9ParseLineEPKchE5C.208+1024(%eax, %eax), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* line 243 */
        "jmp .Lf5318c_000531b2\n"
        ".Lf5318c_000532d6:\n"
        "movl %ebx, (%esp)\n" /* line 173 */
        "calll CopyStringInternal\n"
        "movl %eax, 0x10(%esi)\n" /* line 243 */
        "jmp .Lf5318c_000531b2\n"
        ".Lf5318c_000532e6:\n"
        "cmpb $0x6f, %dl\n" /* line 165 */
        "jne .Lf5318c_000532d6\n"
        "cmpl $3, %ecx\n" /* line 167 */
        "je .Lf5318c_0005330c\n"
        "cmpl $2, %ecx\n" /* line 169 */
        "jne .Lf5318c_000532d6\n"
        "cmpb $0x6e, %al\n"
        "jne .Lf5318c_000532d6\n"
        "cmpb $0, 2(%ebx)\n"
        "jne .Lf5318c_000532d6\n"
        "movl dvarOnOffStrings+4, %eax\n" /* line 170 */
        "movl %eax, 0x10(%esi)\n" /* line 243 */
        "jmp .Lf5318c_000531b2\n"
        ".Lf5318c_0005330c:\n"
        "cmpb $0x66, %al\n" /* line 167 */
        "jne .Lf5318c_000532d6\n"
        "cmpb $0x66, 2(%ebx)\n"
        "jne .Lf5318c_000532d6\n"
        "cmpb $0, 3(%ebx)\n"
        "jne .Lf5318c_000532d6\n"
        "movl dvarOnOffStrings, %eax\n" /* line 168 */
        "movl %eax, 0x10(%esi)\n" /* line 243 */
        "jmp .Lf5318c_000531b2\n"
    );
}

/* line 1452 */
static __attribute__((naked))
void Dvar_MakeExplicitType(int flags, DvarValue resetValue, DvarLimits domain)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1452 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %esi\n" /* flags, dvar */
        "movl %ecx, %edi\n" /* type */
        "movzwl 8(%ebp), %eax\n" /* flags */
        /* { scope 1 */
        "movb %cl, 6(%esi)\n" /* line 1458 | dvar */
        "movl 0x10(%ebp), %edx\n" /* line 1459 | domain, dvarName */
        "movl 0x14(%ebp), %ecx\n"
        "movl %edx, 0x14(%esi)\n" /* dvarName, dvar */
        "movl %ecx, 0x18(%esi)\n" /* dvar */
        "movl %eax, -0x1c(%ebp)\n" /* line 1461 */
        "testb $0x40, %al\n"
        "jne .Lf5332a_00053370\n"
        "testb %al, %al\n"
        "jns .Lf5332a_00053547\n"
        "movl dvar_cheats, %eax\n"
        "testl %eax, %eax\n"
        "je .Lf5332a_00053547\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf5332a_00053547\n"
        ".Lf5332a_00053370:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1463 | resetValue, castValue */
        ".Lf5332a_00053373:\n"
        "cmpb $7, 6(%esi)\n" /* line 1471 | dvar */
        "je .Lf5332a_000533b0\n"
        "movl 8(%esi), %eax\n" /* line 191 */
        "cmpl 0xc(%esi), %eax\n"
        "je .Lf5332a_000533a9\n"
        "cmpl 0x10(%esi), %eax\n"
        "je .Lf5332a_000533a9\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "je .Lf5332a_000533a9\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "jne .Lf5332a_00053571\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf5332a_00053571\n"
        "cmpb $0x39, %dl\n"
        "jg .Lf5332a_00053571\n"
        ".Lf5332a_000533a9:\n"
        "movl $0, 8(%esi)\n" /* line 193 */
        ".Lf5332a_000533b0:\n"
        "movl 0xc(%esi), %eax\n" /* line 199 */
        "cmpl 8(%esi), %eax\n"
        "je .Lf5332a_000533c8\n"
        "cmpl 0x10(%esi), %eax\n"
        "je .Lf5332a_000533c8\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "jne .Lf5332a_0005351c\n"
        ".Lf5332a_000533c8:\n"
        "movl $0, 0xc(%esi)\n" /* line 201 */
        "movl 0x10(%esi), %eax\n" /* line 207 */
        "cmpl 8(%esi), %eax\n"
        "je .Lf5332a_000533e6\n"
        "testl %eax, %eax\n"
        "je .Lf5332a_000533e6\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "jne .Lf5332a_0005346a\n"
        ".Lf5332a_000533e6:\n"
        "movl $0, 0x10(%esi)\n" /* line 209 */
        "movzbl 6(%esi), %edx\n" /* line 1475 | dvar */
        "leal -2(%edx), %eax\n"
        "cmpb $2, %al\n"
        "jbe .Lf5332a_000534aa\n"
        ".Lf5332a_000533fc:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1477 | resetValue */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_UpdateResetValue\n"
        "movzbl 6(%esi), %eax\n" /* line 1418 */
        "cmpb $3, %al\n"
        "je .Lf5332a_000534e5\n"
        ".Lf5332a_00053412:\n"
        "jbe .Lf5332a_0005343b\n"
        "cmpb $4, %al\n"
        "je .Lf5332a_00053670\n"
        "cmpb $7, %al\n"
        "je .Lf5332a_000535c7\n"
        ".Lf5332a_00053424:\n"
        "movl %ebx, 8(%esi)\n" /* line 1445 */
        ".Lf5332a_00053427:\n"
        "movl %ebx, 0xc(%esi)\n" /* line 1446 */
        "movl -0x1c(%ebp), %eax\n" /* line 1480 */
        "orl %eax, dvar_modifiedFlags\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1481 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5332a_0005343b:\n"
        "cmpb $2, %al\n" /* line 1418 */
        "jne .Lf5332a_00053424\n"
        "movl 8(%esi), %edx\n" /* line 1430 | to */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 37 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 38 */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        "movl 0xc(%esi), %edx\n" /* line 1431 | to */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 37 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 38 */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 1480 */
        "orl %eax, dvar_modifiedFlags\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1481 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5332a_0005346a:\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "je .Lf5332a_000535b0\n"
        ".Lf5332a_00053474:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf5332a_000533e6\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf5332a_000533e6\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x10(%esi)\n" /* line 209 */
        "movzbl 6(%esi), %edx\n" /* line 1475 | dvar */
        "leal -2(%edx), %eax\n"
        "cmpb $2, %al\n"
        "ja .Lf5332a_000533fc\n"
        ".Lf5332a_000534aa:\n"
        "movzbl %dl, %eax\n" /* line 125 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 8(%esi)\n"
        "movzbl 6(%esi), %edx\n" /* line 126 */
        "shll $2, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "addl %edx, %eax\n" /* line 127 */
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%ebp), %edx\n" /* line 1477 | resetValue */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_UpdateResetValue\n"
        "movzbl 6(%esi), %eax\n" /* line 1418 */
        "cmpb $3, %al\n"
        "jne .Lf5332a_00053412\n"
        ".Lf5332a_000534e5:\n"
        "movl 8(%esi), %edx\n" /* line 1435 | to */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0xc(%esi), %edx\n" /* line 1436 | to */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 1480 */
        "orl %eax, dvar_modifiedFlags\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1481 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5332a_0005351c:\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "je .Lf5332a_0005359d\n"
        ".Lf5332a_00053522:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf5332a_000533c8\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf5332a_000533c8\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        "jmp .Lf5332a_000533c8\n"
        ".Lf5332a_00053547:\n"
        "movl 8(%esi), %ebx\n" /* line 1467 | dvar, castValue */
        "movl 0x14(%esi), %edx\n" /* dvar, dvarName */
        "movl 0x18(%esi), %ecx\n" /* dvar */
        "movzbl 6(%esi), %eax\n" /* dvar */
        "movl %ebx, (%esp)\n" /* castValue */
        "calll Dvar_StringToValue\n"
        "movl %eax, %ebx\n" /* castValue */
        "movl %eax, %edx\n" /* line 1468 | value */
        /* { scope 2 */
        "movl %edi, %ecx\n" /* line 587 */
        "movzbl %cl, %eax\n"
        "cmpl $6, %eax\n"
        "jbe .Lf5332a_00053596\n"
        /* } scope */
        ".Lf5332a_0005356a:\n"
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        ".Lf5332a_00053571:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf5332a_000533a9\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf5332a_000533a9\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        "jmp .Lf5332a_000533a9\n"
        /* { scope 2 */
        ".Lf5332a_00053596:\n"
        "jmpl *dvarDigitStrings+192(, %eax, 4)\n" /* line 587 */
        /* } scope */
        ".Lf5332a_0005359d:\n"
        "cmpb $0x2f, %dl\n" /* line 181 */
        "jle .Lf5332a_00053522\n"
        "cmpb $0x39, %dl\n"
        "jle .Lf5332a_000533c8\n"
        "jmp .Lf5332a_00053522\n"
        ".Lf5332a_000535b0:\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf5332a_00053474\n"
        "cmpb $0x39, %dl\n"
        "jle .Lf5332a_000533e6\n"
        "jmp .Lf5332a_00053474\n"
        ".Lf5332a_000535c7:\n"
        "movl 8(%esi), %eax\n" /* line 1421 */
        "cmpl %eax, %ebx\n"
        "je .Lf5332a_00053427\n"
        "cmpl 0xc(%esi), %eax\n" /* line 191 */
        "je .Lf5332a_0005360b\n"
        "cmpl 0x10(%esi), %eax\n"
        "je .Lf5332a_0005360b\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "je .Lf5332a_0005360b\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "jne .Lf5332a_000535f3\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf5332a_000535f3\n"
        "cmpb $0x39, %dl\n"
        "jle .Lf5332a_0005360b\n"
        ".Lf5332a_000535f3:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf5332a_0005360b\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf5332a_0005360b\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        ".Lf5332a_0005360b:\n"
        "movl $0, 8(%esi)\n" /* line 193 */
        "movl 0xc(%esi), %edi\n" /* line 215 */
        "testl %edi, %edi\n"
        "je .Lf5332a_00053635\n"
        "cmpl %edi, %ebx\n"
        "je .Lf5332a_000537af\n"
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf5332a_000537af\n"
        ".Lf5332a_00053635:\n"
        "movl 0x10(%esi), %edi\n" /* line 217 */
        "testl %edi, %edi\n"
        "je .Lf5332a_00053658\n"
        "cmpl %edi, %ebx\n"
        "je .Lf5332a_000537af\n"
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf5332a_000537af\n"
        ".Lf5332a_00053658:\n"
        "movzbl (%ebx), %edx\n" /* line 155 */
        "testb %dl, %dl\n"
        "jne .Lf5332a_00053810\n"
        "movl $str_002157b8, %eax\n"
        "movl %eax, 8(%esi)\n" /* line 220 */
        "jmp .Lf5332a_00053427\n"
        ".Lf5332a_00053670:\n"
        "movl 8(%esi), %edx\n" /* line 1440 | to */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 456 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movl 0xc(%esi), %edx\n" /* line 1441 | to */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 456 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 1480 */
        "orl %eax, dvar_modifiedFlags\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1481 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        "movss 0x14(%ebp), %xmm2\n" /* line 613 | max */
        "movss 0x10(%ebp), %xmm1\n" /* domain, min */
        "movl $1, %ecx\n"
        "leal 4(%ebx), %eax\n"
        /* { scope 3 */
        ".Lf5332a_000536c5:\n"
        "movss -4(%eax), %xmm0\n" /* line 562 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf5332a_000537ca\n"
        "movss %xmm1, -4(%eax)\n" /* line 563 */
        ".Lf5332a_000536d8:\n"
        "addl $1, %ecx\n" /* line 565 */
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 560 */
        "jne .Lf5332a_000536c5\n"
        /* } scope */
        /* } scope */
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        /* { scope 2 */
        "movss 0x14(%ebp), %xmm2\n" /* line 617 | max */
        "movss 0x10(%ebp), %xmm1\n" /* domain, min */
        "movl $1, %ecx\n"
        "leal 4(%ebx), %eax\n"
        /* { scope 3 */
        ".Lf5332a_000536fc:\n"
        "movss -4(%eax), %xmm0\n" /* line 562 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf5332a_000537b7\n"
        "movss %xmm1, -4(%eax)\n" /* line 563 */
        ".Lf5332a_0005370f:\n"
        "addl $1, %ecx\n" /* line 565 */
        "addl $4, %eax\n"
        "cmpl $5, %ecx\n" /* line 560 */
        "jne .Lf5332a_000536fc\n"
        /* } scope */
        /* } scope */
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        /* { scope 2 */
        "movl %ebx, -0x2c(%ebp)\n" /* line 602 */
        "movss -0x2c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss 0x10(%ebp), %xmm1\n" /* domain */
        "jae .Lf5332a_000537e9\n"
        "jp .Lf5332a_000537e9\n"
        "movl 0x10(%ebp), %edx\n" /* line 603 | domain */
        /* } scope */
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        /* { scope 2 */
        "cmpl 0x10(%ebp), %ebx\n" /* line 595 | domain */
        "jge .Lf5332a_000537fd\n"
        "movl 0x10(%ebp), %edx\n" /* line 596 | domain */
        /* } scope */
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        /* { scope 2 */
        "testb %bl, %bl\n" /* line 590 */
        "setne %dl\n"
        /* } scope */
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 625 */
        "js .Lf5332a_00053772\n"
        "cmpl 0x10(%ebp), %ebx\n" /* domain */
        "jl .Lf5332a_0005356a\n"
        ".Lf5332a_00053772:\n"
        "movl 0xc(%ebp), %edx\n" /* line 627 | resetValue */
        /* } scope */
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        /* { scope 2 */
        "movss 0x14(%ebp), %xmm2\n" /* line 609 | max */
        "movss 0x10(%ebp), %xmm1\n" /* domain, min */
        "movl $1, %ecx\n"
        "leal 4(%ebx), %eax\n"
        /* { scope 3 */
        ".Lf5332a_0005378e:\n"
        "movss -4(%eax), %xmm0\n" /* line 562 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf5332a_000537dd\n"
        "movss %xmm1, -4(%eax)\n" /* line 563 */
        ".Lf5332a_0005379d:\n"
        "addl $1, %ecx\n" /* line 565 */
        "addl $4, %eax\n"
        "cmpl $3, %ecx\n" /* line 560 */
        "jne .Lf5332a_0005378e\n"
        /* } scope */
        /* } scope */
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        ".Lf5332a_000537af:\n"
        "movl %edi, 8(%esi)\n" /* line 218 */
        "jmp .Lf5332a_00053427\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf5332a_000537b7:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 564 */
        "jbe .Lf5332a_0005370f\n"
        "movss %xmm2, -4(%eax)\n" /* line 565 */
        "jmp .Lf5332a_0005370f\n"
        /* } scope */
        /* { scope 3 */
        ".Lf5332a_000537ca:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 564 */
        "jbe .Lf5332a_000536d8\n"
        "movss %xmm2, -4(%eax)\n" /* line 565 */
        "jmp .Lf5332a_000536d8\n"
        /* } scope */
        /* { scope 3 */
        ".Lf5332a_000537dd:\n"
        "ucomiss %xmm2, %xmm0\n" /* line 564 */
        "jbe .Lf5332a_0005379d\n"
        "movss %xmm2, -4(%eax)\n" /* line 565 */
        "jmp .Lf5332a_0005379d\n"
        /* } scope */
        ".Lf5332a_000537e9:\n"
        "ucomiss 0x14(%ebp), %xmm0\n" /* line 604 */
        "jbe .Lf5332a_0005356a\n"
        "movl 0x14(%ebp), %edx\n" /* line 605 */
        /* } scope */
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        /* { scope 2 */
        ".Lf5332a_000537fd:\n"
        "cmpl 0x14(%ebp), %ebx\n" /* line 597 */
        "jle .Lf5332a_0005356a\n"
        "movl 0x14(%ebp), %edx\n" /* line 598 */
        /* } scope */
        "movl %edx, %ebx\n" /* line 1468 | value, castValue */
        "jmp .Lf5332a_00053373\n"
        ".Lf5332a_00053810:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movzbl 1(%ebx), %eax\n" /* line 160 */
        "testb %al, %al\n"
        "jne .Lf5332a_00053852\n"
        "leal -0x30(%edx), %eax\n" /* line 162 */
        "cmpb $9, %al\n"
        "ja .Lf5332a_00053842\n"
        "movsbl %dl, %eax\n" /* line 163 */
        "leal __ZZN16CStringEdPackage9ParseLineEPKchE5C.208+1024(%eax, %eax), %eax\n"
        "movl %eax, 8(%esi)\n" /* line 220 */
        "jmp .Lf5332a_00053427\n"
        ".Lf5332a_00053842:\n"
        "movl %ebx, (%esp)\n" /* line 173 */
        "calll CopyStringInternal\n"
        "movl %eax, 8(%esi)\n" /* line 220 */
        "jmp .Lf5332a_00053427\n"
        ".Lf5332a_00053852:\n"
        "cmpb $0x6f, %dl\n" /* line 165 */
        "jne .Lf5332a_00053842\n"
        "cmpl $3, %ecx\n" /* line 167 */
        "je .Lf5332a_00053878\n"
        "cmpl $2, %ecx\n" /* line 169 */
        "jne .Lf5332a_00053842\n"
        "cmpb $0x6e, %al\n"
        "jne .Lf5332a_00053842\n"
        "cmpb $0, 2(%ebx)\n"
        "jne .Lf5332a_00053842\n"
        "movl dvarOnOffStrings+4, %eax\n" /* line 170 */
        "movl %eax, 8(%esi)\n" /* line 220 */
        "jmp .Lf5332a_00053427\n"
        ".Lf5332a_00053878:\n"
        "cmpb $0x66, %al\n" /* line 167 */
        "jne .Lf5332a_00053842\n"
        "cmpb $0x66, 2(%ebx)\n"
        "jne .Lf5332a_00053842\n"
        "cmpb $0, 3(%ebx)\n"
        "jne .Lf5332a_00053842\n"
        "movl dvarOnOffStrings, %eax\n" /* line 168 */
        "movl %eax, 8(%esi)\n" /* line 220 */
        "jmp .Lf5332a_00053427\n"
    );
}

/* line 1406 */
__attribute__((naked))
void Dvar_ChangeResetValue(const dvar_t *dvar, DvarValue value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1406 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl 0xc(%ebp), %edx\n" /* value */
        "popl %ebp\n" /* line 1413 */
        "jmp Dvar_UpdateResetValue\n" /* line 1412 */
    );
}

/* line 925 */
static __attribute__((naked))
void Dvar_SetVariant(DvarValue value, DvarSetSource source)
{
    __asm__ __volatile__ (
        ".Lf538a6_000538a6:\n"
        "pushl %ebp\n" /* line 925 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        "movl %eax, %esi\n" /* dvar */
        "movl %edx, -0x430(%ebp)\n"
        "movl %ecx, -0x420(%ebp)\n"
        "calll Dvar_ValueToString\n" /* line 931 */
        "movl %eax, 8(%esp)\n"
        "movl (%esi), %eax\n" /* dvar */
        "movl %eax, 4(%esp)\n"
        "movl $str_002197cc, (%esp)\n" /* "      dvar set %s %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll Com_PrintMessage\n"
        "movl 0x14(%esi), %ecx\n" /* line 948 | dvar */
        "movl 0x18(%esi), %ebx\n" /* dvar */
        "movzbl 6(%esi), %eax\n" /* dvar */
        "movl %eax, -0x41c(%ebp)\n"
        "movzbl -0x41c(%ebp), %eax\n" /* line 648 */
        "cmpl $8, %eax\n"
        "ja .Lf538a6_00053940\n"
        "jmpl *dvarDigitStrings+220(, %eax, 4)\n"
        "movss -0x430(%ebp), %xmm0\n" /* line 663 */
        "movl %ecx, -0x42c(%ebp)\n"
        "movss -0x42c(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf538a6_00053940\n"
        "movl %ebx, -0x42c(%ebp)\n" /* line 665 */
        "movss -0x42c(%ebp), %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf538a6_00053a0e\n"
        ".Lf538a6_00053940:\n"
        "movl (%esi), %ebx\n" /* line 950 | dvar */
        "movl -0x430(%ebp), %edx\n"
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_ValueToString\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002197e4, (%esp)\n" /* "'%s' is not a valid value for dvar '%s'
" */
        "calll Com_Printf\n"
        "movl 0x14(%esi), %ecx\n" /* line 951 | dvar */
        "movl 0x18(%esi), %ebx\n" /* dvar */
        /* { scope 1 */
        "movzbl 6(%esi), %eax\n" /* line 820 */
        "movl $0, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* domainBuffer */
        "movl %edx, (%esp)\n"
        "movl %ecx, %edx\n"
        "movl %ebx, %ecx\n"
        "calll Dvar_DomainToString_Internal\n"
        "movl %eax, 4(%esp)\n" /* line 834 */
        "movl $str_002182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "cmpb $6, 6(%esi)\n" /* line 952 | dvar */
        "je .Lf538a6_00053bcd\n"
        ".Lf538a6_000539a9:\n"
        "addl $0x43c, %esp\n" /* line 1041 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %ebx, -0x42c(%ebp)\n" /* line 673 */
        "movss -0x42c(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm2\n" /* max */
        "movl %ecx, -0x42c(%ebp)\n"
        "movss -0x42c(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* min */
        "movl $1, %eax\n"
        /* { scope 1 */
        ".Lf538a6_000539db:\n"
        "movl -0x430(%ebp), %edx\n" /* line 576 */
        "movss -4(%edx, %eax, 4), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf538a6_00053bf6\n"
        "ucomiss %xmm2, %xmm0\n" /* line 578 */
        "ja .Lf538a6_00053bf6\n"
        "addl $1, %eax\n"
        "cmpl $3, %eax\n" /* line 574 */
        "jne .Lf538a6_000539db\n"
        /* } scope */
        /* { scope 1 */
        ".Lf538a6_00053a01:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf538a6_00053a06:\n"
        "testb %al, %al\n" /* line 948 */
        "je .Lf538a6_00053940\n"
        ".Lf538a6_00053a0e:\n"
        "movl -0x420(%ebp), %eax\n" /* line 960 */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf538a6_00053a79\n"
        ".Lf538a6_00053a1c:\n"
        "movl 8(%esi), %ebx\n" /* line 999 | dvar */
        "movl -0x430(%ebp), %ecx\n"
        "movl %ebx, %edx\n"
        "movl -0x41c(%ebp), %eax\n"
        "calll Dvar_ValuesEqual\n"
        "testb %al, %al\n"
        "jne .Lf538a6_00053bbf\n"
        "movzwl 4(%esi), %eax\n" /* line 1006 | dvar */
        "orl %eax, dvar_modifiedFlags\n"
        "movzbl 6(%esi), %eax\n" /* line 1008 | dvar */
        "cmpb $3, %al\n"
        "je .Lf538a6_00053d72\n"
        "ja .Lf538a6_00053bfd\n"
        "cmpb $2, %al\n"
        "je .Lf538a6_00053d49\n"
        ".Lf538a6_00053a5e:\n"
        "movl -0x430(%ebp), %eax\n" /* line 1036 */
        "movl %eax, 8(%esi)\n" /* dvar */
        "movl %eax, 0xc(%esi)\n" /* line 1037 | dvar */
        "movb $1, 7(%esi)\n" /* line 1040 | dvar */
        ".Lf538a6_00053a6e:\n"
        "addl $0x43c, %esp\n" /* line 1041 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf538a6_00053a79:\n"
        "movzwl 4(%esi), %edx\n" /* line 962 | dvar */
        "testb $0x40, %dl\n"
        "jne .Lf538a6_00053da7\n"
        "testb $0x10, %dl\n" /* line 968 */
        "jne .Lf538a6_00053dbe\n"
        "cmpl $1, -0x420(%ebp)\n" /* line 974 */
        "je .Lf538a6_00053cda\n"
        ".Lf538a6_00053a9c:\n"
        "andb $0x20, %dl\n" /* line 980 */
        "je .Lf538a6_00053a1c\n"
        "movl -0x430(%ebp), %edx\n" /* line 982 */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetLatchedValue\n"
        "movl 8(%esi), %ebx\n" /* line 983 | dvar */
        "movl 0xc(%esi), %edx\n" /* dvar */
        "movzbl 6(%esi), %eax\n" /* dvar */
        "movl %ebx, %ecx\n"
        "calll Dvar_ValuesEqual\n"
        "testb %al, %al\n"
        "jne .Lf538a6_000539a9\n"
        "movl (%esi), %eax\n" /* line 984 | dvar */
        "movl %eax, 4(%esp)\n"
        "movl $str_00219854, (%esp)\n" /* "%s will be changed upon restarting.
" */
        "calll Com_Printf\n"
        "jmp .Lf538a6_000539a9\n"
        "movl -0x430(%ebp), %eax\n" /* line 670 */
        "testl %eax, %eax\n"
        "js .Lf538a6_00053be8\n"
        "cmpl %ecx, -0x430(%ebp)\n"
        "jge .Lf538a6_00053be8\n"
        ".Lf538a6_00053afc:\n"
        "movl $1, %eax\n"
        "jmp .Lf538a6_00053a06\n"
        "movl %ebx, -0x42c(%ebp)\n" /* line 676 */
        "movss -0x42c(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm2\n" /* max */
        "movl %ecx, -0x42c(%ebp)\n"
        "movss -0x42c(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* min */
        "movl $1, %eax\n"
        /* { scope 1 */
        ".Lf538a6_00053b2d:\n"
        "movl -0x430(%ebp), %edx\n" /* line 576 */
        "movss -4(%edx, %eax, 4), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf538a6_00053bf6\n"
        "ucomiss %xmm2, %xmm0\n" /* line 578 */
        "ja .Lf538a6_00053bf6\n"
        "addl $1, %eax\n"
        "cmpl $4, %eax\n" /* line 574 */
        "jne .Lf538a6_00053b2d\n"
        "jmp .Lf538a6_00053a01\n"
        /* } scope */
        "cmpl %ecx, -0x430(%ebp)\n" /* line 656 */
        "jl .Lf538a6_00053940\n"
        "cmpl %ebx, -0x430(%ebp)\n" /* line 658 */
        "jg .Lf538a6_00053940\n"
        "jmp .Lf538a6_00053a0e\n"
        "movl %ebx, -0x42c(%ebp)\n" /* line 679 */
        "movss -0x42c(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm2\n" /* max */
        "movl %ecx, -0x42c(%ebp)\n"
        "movss -0x42c(%ebp), %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* min */
        "movl $1, %eax\n"
        /* { scope 1 */
        ".Lf538a6_00053b9c:\n"
        "movl -0x430(%ebp), %edx\n" /* line 576 */
        "movss -4(%edx, %eax, 4), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf538a6_00053bf6\n"
        "ucomiss %xmm2, %xmm0\n" /* line 578 */
        "ja .Lf538a6_00053bf6\n"
        "addl $1, %eax\n"
        "cmpl $5, %eax\n" /* line 574 */
        "jne .Lf538a6_00053b9c\n"
        "jmp .Lf538a6_00053a01\n"
        /* } scope */
        ".Lf538a6_00053bbf:\n"
        "movl %ebx, %edx\n" /* line 1001 */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetLatchedValue\n"
        "jmp .Lf538a6_000539a9\n"
        ".Lf538a6_00053bcd:\n"
        "movl 0x10(%esi), %edx\n" /* line 955 | dvar */
        "movl -0x420(%ebp), %ecx\n"
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        "addl $0x43c, %esp\n" /* line 1041 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf538a6_00053be8:\n"
        "movl -0x430(%ebp), %edi\n" /* line 670 */
        "testl %edi, %edi\n"
        "je .Lf538a6_00053afc\n"
        /* { scope 1 */
        ".Lf538a6_00053bf6:\n"
        "xorl %eax, %eax\n" /* line 574 */
        "jmp .Lf538a6_00053a06\n"
        /* } scope */
        ".Lf538a6_00053bfd:\n"
        "cmpb $4, %al\n" /* line 1008 */
        "je .Lf538a6_00053d08\n"
        "cmpb $7, %al\n"
        "jne .Lf538a6_00053a5e\n"
        "movl 8(%esi), %eax\n" /* line 191 */
        "cmpl 0xc(%esi), %eax\n"
        "je .Lf538a6_00053c49\n"
        "cmpl 0x10(%esi), %eax\n"
        "je .Lf538a6_00053c49\n"
        "movzbl (%eax), %edx\n" /* line 179 */
        "testb %dl, %dl\n"
        "je .Lf538a6_00053c49\n"
        "cmpb $0, 1(%eax)\n" /* line 181 */
        "jne .Lf538a6_00053c31\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf538a6_00053c31\n"
        "cmpb $0x39, %dl\n"
        "jle .Lf538a6_00053c49\n"
        ".Lf538a6_00053c31:\n"
        "cmpl dvarOnOffStrings, %eax\n" /* line 183 */
        "je .Lf538a6_00053c49\n"
        "cmpl dvarOnOffStrings+4, %eax\n"
        "je .Lf538a6_00053c49\n"
        "movl %eax, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        ".Lf538a6_00053c49:\n"
        "movl $0, 8(%esi)\n" /* line 193 */
        "movl 0xc(%esi), %ecx\n" /* line 215 */
        "movl %ecx, -0x424(%ebp)\n"
        "testl %ecx, %ecx\n"
        "je .Lf538a6_00053dd5\n"
        "cmpl %ecx, -0x430(%ebp)\n"
        "je .Lf538a6_00053c83\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x430(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf538a6_00053dd5\n"
        ".Lf538a6_00053c83:\n"
        "movl -0x424(%ebp), %edi\n" /* line 216 */
        "movl %edi, 8(%esi)\n"
        "movl %edi, %ebx\n"
        ".Lf538a6_00053c8e:\n"
        "cmpl 8(%esi), %ebx\n" /* line 199 */
        "je .Lf538a6_00053ccb\n"
        "cmpl 0x10(%esi), %ebx\n"
        "je .Lf538a6_00053ccb\n"
        "movzbl (%ebx), %eax\n" /* line 179 */
        "testb %al, %al\n"
        "je .Lf538a6_00053ccb\n"
        "cmpb $0, 1(%ebx)\n" /* line 181 */
        "jne .Lf538a6_00053cad\n"
        "cmpb $0x2f, %al\n"
        "jle .Lf538a6_00053cad\n"
        "cmpb $0x39, %al\n"
        "jle .Lf538a6_00053ccb\n"
        ".Lf538a6_00053cad:\n"
        "movl -0x424(%ebp), %edi\n" /* line 183 */
        "cmpl dvarOnOffStrings, %edi\n"
        "je .Lf538a6_00053ccb\n"
        "cmpl dvarOnOffStrings+4, %edi\n"
        "je .Lf538a6_00053ccb\n"
        "movl %edi, (%esp)\n" /* line 185 */
        "calll Z_FreeInternal\n"
        ".Lf538a6_00053ccb:\n"
        "movl 8(%esi), %eax\n" /* line 1016 | dvar */
        "movl %eax, 0xc(%esi)\n" /* dvar */
        "movb $1, 7(%esi)\n" /* line 1040 | dvar */
        "jmp .Lf538a6_00053a6e\n"
        ".Lf538a6_00053cda:\n"
        "testb %dl, %dl\n" /* line 974 */
        "jns .Lf538a6_00053a9c\n"
        "movl dvar_cheats, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf538a6_00053a9c\n"
        "movl (%esi), %eax\n" /* line 976 | dvar */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021983c, (%esp)\n" /* "%s is cheat protected.
" */
        "calll Com_Printf\n"
        "jmp .Lf538a6_000539a9\n"
        ".Lf538a6_00053d08:\n"
        "movl 8(%esi), %edx\n" /* line 1030 | dvar, to */
        /* { scope 1 */
        "movl -0x430(%ebp), %edi\n" /* line 456 */
        "movl (%edi), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%edi), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movl 0xc(%esi), %edx\n" /* line 1031 | dvar, to */
        /* { scope 1 */
        "movl (%edi), %eax\n" /* line 456 */
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%edi), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movb $1, 7(%esi)\n" /* line 1040 | dvar */
        "jmp .Lf538a6_00053a6e\n"
        ".Lf538a6_00053d49:\n"
        "movl 8(%esi), %edx\n" /* line 1020 | dvar, to */
        /* { scope 1 */
        "movl -0x430(%ebp), %ecx\n" /* line 37 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 38 */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        "movl 0xc(%esi), %edx\n" /* line 1021 | dvar, to */
        /* { scope 1 */
        "movl (%ecx), %eax\n" /* line 37 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 38 */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        "movb $1, 7(%esi)\n" /* line 1040 | dvar */
        "jmp .Lf538a6_00053a6e\n"
        ".Lf538a6_00053d72:\n"
        "movl 8(%esi), %edx\n" /* line 1025 | dvar, to */
        /* { scope 1 */
        "movl -0x430(%ebp), %ebx\n" /* line 199 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0xc(%esi), %edx\n" /* line 1026 | dvar, to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movb $1, 7(%esi)\n" /* line 1040 | dvar */
        "jmp .Lf538a6_00053a6e\n"
        ".Lf538a6_00053da7:\n"
        "movl (%esi), %eax\n" /* line 964 | dvar */
        "movl %eax, 4(%esp)\n"
        "movl $str_00219810, (%esp)\n" /* "%s is read only.
" */
        "calll Com_Printf\n"
        "jmp .Lf538a6_000539a9\n"
        ".Lf538a6_00053dbe:\n"
        "movl (%esi), %eax\n" /* line 970 | dvar */
        "movl %eax, 4(%esp)\n"
        "movl $str_00219824, (%esp)\n" /* "%s is write protected.
" */
        "calll Com_Printf\n"
        "jmp .Lf538a6_000539a9\n"
        ".Lf538a6_00053dd5:\n"
        "movl 0x10(%esi), %ebx\n" /* line 217 */
        "testl %ebx, %ebx\n"
        "je .Lf538a6_00053e08\n"
        "cmpl %ebx, -0x430(%ebp)\n"
        "je .Lf538a6_00053dfa\n"
        "movl %ebx, 4(%esp)\n"
        "movl -0x430(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf538a6_00053e08\n"
        ".Lf538a6_00053dfa:\n"
        "movl %ebx, 8(%esi)\n" /* line 218 */
        "movl -0x424(%ebp), %ebx\n"
        "jmp .Lf538a6_00053c8e\n"
        ".Lf538a6_00053e08:\n"
        "movl -0x430(%ebp), %ecx\n" /* line 155 */
        "movzbl (%ecx), %edx\n"
        "testb %dl, %dl\n"
        "jne .Lf538a6_00053e28\n"
        "movl $str_002157b8, %eax\n"
        ".Lf538a6_00053e1a:\n"
        "movl %eax, 8(%esi)\n" /* line 220 */
        "movl -0x424(%ebp), %ebx\n"
        "jmp .Lf538a6_00053c8e\n"
        ".Lf538a6_00053e28:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x430(%ebp), %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl -0x430(%ebp), %ebx\n" /* line 160 */
        "movzbl 1(%ebx), %eax\n"
        "testb %al, %al\n"
        "jne .Lf538a6_00053e77\n"
        "leal -0x30(%edx), %eax\n" /* line 162 */
        "cmpb $9, %al\n"
        "ja .Lf538a6_00053e5e\n"
        "movsbl %dl, %eax\n" /* line 163 */
        "leal __ZZN16CStringEdPackage9ParseLineEPKchE5C.208+1024(%eax, %eax), %eax\n"
        "jmp .Lf538a6_00053e1a\n"
        ".Lf538a6_00053e5e:\n"
        "movl -0x430(%ebp), %edx\n" /* line 173 */
        "movl %edx, (%esp)\n"
        "calll CopyStringInternal\n"
        "movl 0xc(%esi), %ecx\n"
        "movl %ecx, -0x424(%ebp)\n"
        "jmp .Lf538a6_00053e1a\n"
        ".Lf538a6_00053e77:\n"
        "cmpb $0x6f, %dl\n" /* line 165 */
        "jne .Lf538a6_00053e5e\n"
        "cmpl $3, %ecx\n" /* line 167 */
        "je .Lf538a6_00053ea0\n"
        "cmpl $2, %ecx\n" /* line 169 */
        "jne .Lf538a6_00053e5e\n"
        "cmpb $0x6e, %al\n"
        "jne .Lf538a6_00053e5e\n"
        "movl -0x430(%ebp), %eax\n"
        "cmpb $0, 2(%eax)\n"
        "jne .Lf538a6_00053e5e\n"
        "movl dvarOnOffStrings+4, %eax\n" /* line 170 */
        "jmp .Lf538a6_00053e1a\n"
        ".Lf538a6_00053ea0:\n"
        "cmpb $0x66, %al\n" /* line 167 */
        "jne .Lf538a6_00053e5e\n"
        "movl -0x430(%ebp), %edi\n"
        "cmpb $0x66, 2(%edi)\n"
        "jne .Lf538a6_00053e5e\n"
        "cmpb $0, 3(%edi)\n"
        "jne .Lf538a6_00053e5e\n"
        "movl dvarOnOffStrings, %eax\n" /* line 168 */
        "jmp .Lf538a6_00053e1a\n"
    );
}

/* line 2350 */
__attribute__((naked))
void Dvar_SetCheatState(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2350 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        /* { scope 1 */
        "movl sortedDvars, %ebx\n" /* line 2359 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf53ec0_00053eda\n"
        "jmp .Lf53ec0_00053ef3\n"
        ".Lf53ec0_00053ed3:\n"
        "movl 0x1c(%ebx), %ebx\n" /* var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf53ec0_00053ef3\n"
        ".Lf53ec0_00053eda:\n"
        "cmpb $0, 4(%ebx)\n" /* line 2361 | var */
        "jns .Lf53ec0_00053ed3\n"
        "movl 0x10(%ebx), %edx\n" /* line 2362 | var */
        "xorl %ecx, %ecx\n"
        "movl %ebx, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 2359 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf53ec0_00053eda\n"
        /* } scope */
        ".Lf53ec0_00053ef3:\n"
        "addl $4, %esp\n" /* line 2368 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2327 */
__attribute__((naked))
void Dvar_Reset(const dvar_t *dvar, DvarSetSource setSource)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2327 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl 0xc(%ebp), %ecx\n" /* setSource */
        "movl 0x10(%eax), %edx\n" /* line 2335 */
        "popl %ebp\n" /* line 2340 */
        "jmp Dvar_SetVariant\n" /* line 2335 */
    );
}

/* line 2142 */
static __attribute__((naked))
void Dvar_SetFromStringFromSource(DvarSetSource source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2142 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x82c, %esp\n"
        "movl %eax, %esi\n" /* dvar */
        "movl %ecx, -0x81c(%ebp)\n"
        /* { scope 1: domainBuffer */
        "movl $0x400, 8(%esp)\n" /* line 2151 */
        "movl %edx, 4(%esp)\n" /* string */
        "leal -0x418(%ebp), %edi\n" /* buf */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl 0x14(%esi), %ecx\n" /* line 2152 | dvar */
        "movl 0x18(%esi), %ebx\n" /* dvar */
        "movzbl 6(%esi), %eax\n" /* dvar */
        "movl %edi, (%esp)\n"
        "movl %ecx, %edx\n" /* string */
        "movl %ebx, %ecx\n"
        "calll Dvar_StringToValue\n"
        "cmpb $6, 6(%esi)\n" /* line 2153 | dvar */
        "je .Lf53f0c_00053f70\n"
        ".Lf53f0c_00053f56:\n"
        "movl -0x81c(%ebp), %ecx\n" /* line 2160 */
        "movl %eax, %edx\n" /* string */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x82c, %esp\n" /* line 2165 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: domainBuffer */
        ".Lf53f0c_00053f70:\n"
        "cmpl $0xfffffac7, %eax\n" /* line 2153 */
        "jne .Lf53f0c_00053f56\n"
        "movl (%esi), %eax\n" /* line 2155 | dvar */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $str_002197e4, (%esp)\n" /* "'%s' is not a valid value for dvar '%s'
" */
        "calll Com_Printf\n"
        "movl 0x14(%esi), %ecx\n" /* line 2156 | dvar */
        "movl 0x18(%esi), %ebx\n" /* dvar */
        /* { scope 2 */
        "movzbl 6(%esi), %eax\n" /* line 820 */
        "movl $0, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x818(%ebp), %edx\n" /* domainBuffer */
        "movl %edx, (%esp)\n"
        "movl %ecx, %edx\n"
        "movl %ebx, %ecx\n"
        "calll Dvar_DomainToString_Internal\n"
        "movl %eax, 4(%esp)\n" /* line 834 */
        "movl $str_002182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "movl 0x10(%esi), %eax\n" /* line 2157 | dvar */
        "movl -0x81c(%ebp), %ecx\n" /* line 2160 */
        "movl %eax, %edx\n" /* string */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x82c, %esp\n" /* line 2165 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2168 */
__attribute__((naked))
void Dvar_SetFromString(const dvar_t *dvar, const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2168 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl 0xc(%ebp), %edx\n" /* string */
        "xorl %ecx, %ecx\n" /* line 2170 */
        "popl %ebp\n" /* line 2171 */
        "jmp Dvar_SetFromStringFromSource\n" /* line 2170 */
    );
}

/* line 2130 */
__attribute__((naked))
void Dvar_SetString(const dvar_t *dvar, const char *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2130 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1: domain */
        "movl 8(%ebp), %eax\n" /* line 2036 | dvar */
        "cmpb $7, 6(%eax)\n"
        "je .Lf53ff8_00054124\n"
        "addl $0x14, %eax\n" /* line 2043 */
        "movl %eax, -0x41c(%ebp)\n" /* domain */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %edx\n" /* line 402 | dvar */
        "movl 0x14(%edx), %esi\n" /* len */
        "testl %esi, %esi\n" /* len */
        "jg .Lf53ff8_000540a9\n"
        ".Lf53ff8_00054028:\n"
        "movl 0xc(%ebp), %eax\n" /* line 408 | value */
        "movzbl (%eax), %ecx\n"
        "testb %cl, %cl\n"
        "jne .Lf53ff8_00054076\n"
        "xorl %ebx, %ebx\n" /* stringIndex */
        ".Lf53ff8_00054034:\n"
        "cmpl %ebx, %esi\n" /* line 414 | stringIndex, len */
        "jg .Lf53ff8_0005405f\n"
        ".Lf53ff8_00054038:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* value */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* len */
        "movl -0x41c(%ebp), %edx\n" /* line 418 | domain */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf53ff8_000540e4\n"
        ".Lf53ff8_0005405a:\n"
        "movl $0xfffffac7, %ebx\n" /* stringIndex */
        /* } scope */
        /* } scope */
        ".Lf53ff8_0005405f:\n"
        "movl %ebx, %edx\n" /* line 2043 | stringIndex */
        "xorl %ecx, %ecx\n" /* line 2051 */
        "movl 8(%ebp), %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: domain */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf53ff8_00054076:\n"
        "leal -0x30(%ecx), %eax\n" /* line 410 */
        "cmpb $9, %al\n"
        "ja .Lf53ff8_0005405a\n"
        "movl 0xc(%ebp), %edi\n" /* value */
        "xorl %ebx, %ebx\n" /* stringIndex */
        ".Lf53ff8_00054082:\n"
        "leal (%ebx, %ebx, 4), %edx\n" /* line 412 | stringIndex */
        "movsbl %cl, %eax\n"
        "leal -0x30(%eax, %edx, 2), %ebx\n" /* stringIndex */
        "movzbl 1(%edi), %ecx\n" /* line 408 */
        "testb %cl, %cl\n"
        "je .Lf53ff8_00054158\n"
        "addl $1, %edi\n"
        "leal -0x30(%ecx), %eax\n" /* line 410 */
        "cmpb $9, %al\n"
        "jbe .Lf53ff8_00054082\n"
        "movl $0xfffffac7, %ebx\n" /* line 418 | stringIndex */
        "jmp .Lf53ff8_0005405f\n"
        ".Lf53ff8_000540a9:\n"
        "xorl %ebx, %ebx\n" /* line 402 | stringIndex */
        "movl -0x41c(%ebp), %edx\n" /* domain */
        "jmp .Lf53ff8_000540c6\n"
        ".Lf53ff8_000540b3:\n"
        "addl $1, %ebx\n" /* stringIndex */
        "movl -0x41c(%ebp), %edx\n" /* domain */
        "movl (%edx), %esi\n" /* len */
        "cmpl %esi, %ebx\n" /* len, stringIndex */
        "jge .Lf53ff8_00054028\n"
        ".Lf53ff8_000540c6:\n"
        "movl 4(%edx), %eax\n" /* line 404 */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf53ff8_000540b3\n"
        "jmp .Lf53ff8_0005405f\n"
        ".Lf53ff8_000540e4:\n"
        "xorl %ebx, %ebx\n" /* line 418 | stringIndex */
        ".Lf53ff8_000540e6:\n"
        "movl %esi, 8(%esp)\n" /* line 420 | len */
        "movl -0x41c(%ebp), %edx\n" /* domain */
        "movl 4(%edx), %eax\n"
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf53ff8_0005405f\n"
        "addl $1, %ebx\n" /* line 418 | stringIndex */
        "movl -0x41c(%ebp), %edx\n" /* domain */
        "cmpl (%edx), %ebx\n" /* stringIndex */
        "jl .Lf53ff8_000540e6\n"
        "movl $0xfffffac7, %ebx\n" /* stringIndex */
        "jmp .Lf53ff8_0005405f\n"
        /* } scope */
        /* } scope */
        ".Lf53ff8_00054124:\n"
        "movl $0x400, 8(%esp)\n" /* line 2038 */
        "movl 0xc(%ebp), %edx\n" /* value */
        "movl %edx, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* stringCopy, stringIndex */
        "movl %ebx, (%esp)\n" /* stringIndex */
        "calll I_strncpyz\n"
        "movl %ebx, %edx\n" /* line 2039 | stringIndex */
        "xorl %ecx, %ecx\n" /* line 2051 */
        "movl 8(%ebp), %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: domain */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf53ff8_00054158:\n"
        "testl %ebx, %ebx\n" /* line 414 | stringIndex */
        "js .Lf53ff8_00054038\n"
        "jmp .Lf53ff8_00054034\n"
    );
}

/* line 2059 */
__attribute__((naked))
void Dvar_SetColorFromSource(const dvar_t *dvar, float r, float g, float b, float a, DvarSetSource source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2059 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xe0, %esp\n"
        "xorl %ebx, %ebx\n"
        "movl 8(%ebp), %esi\n" /* dvar */
        "movss 0xc(%ebp), %xmm1\n" /* r */
        "movss 0x10(%ebp), %xmm3\n" /* g */
        /* { scope 1 */
        "cmpb $8, 6(%esi)\n" /* line 2068 | dvar */
        "je .Lf54166_000541e4\n"
        "cvtss2sd 0x18(%ebp), %xmm0\n" /* line 2078 | a */
        "movsd %xmm0, 0x24(%esp)\n"
        "cvtss2sd 0x14(%ebp), %xmm0\n" /* b */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd %xmm3, %xmm3\n"
        "movsd %xmm3, 0x14(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0xc(%esp)\n"
        "movl $str_00219544, 8(%esp)\n" /* "%g %g %g %g" */
        "movl $0x80, 4(%esp)\n"
        "leal -0x88(%ebp), %ebx\n" /* string, newValue */
        "movl %ebx, (%esp)\n" /* newValue */
        "calll Com_sprintf\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 2086 | source */
        "movl %ebx, %edx\n" /* newValue */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0xe0, %esp\n" /* line 2091 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf54166_000541e4:\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54166_00054399\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54166_000543a9\n"
        ".Lf54166_00054215:\n"
        "movaps %xmm2, %xmm0\n"
        ".Lf54166_00054218:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0xa8(%ebp)\n"
        "movss %xmm3, -0xb8(%ebp)\n"
        "calll floorf\n"
        "fstps -0x8c(%ebp)\n"
        "cvttss2si -0x8c(%ebp), %eax\n"
        "movb %al, %bl\n"
        "movss -0xb8(%ebp), %xmm3\n" /* line 45 */
        "movaps %xmm3, %xmm0\n"
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0xa8(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54166_00054404\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        ".Lf54166_0005427e:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54166_000543f4\n"
        "movaps %xmm2, %xmm0\n"
        ".Lf54166_0005428a:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0xa8(%ebp)\n"
        "calll floorf\n"
        "fstps -0x90(%ebp)\n"
        "cvttss2si -0x90(%ebp), %eax\n"
        "movb %al, %bh\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 45 | b */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0xa8(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54166_000543e7\n"
        "movl $0x3f800000, 0x14(%ebp)\n" /* b */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        ".Lf54166_000542e1:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54166_000543d5\n"
        "movaps %xmm2, %xmm0\n"
        ".Lf54166_000542ed:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0xa8(%ebp)\n"
        "calll floorf\n"
        "fstps -0x94(%ebp)\n"
        "cvttss2si -0x94(%ebp), %eax\n"
        "movzbl %al, %eax\n"
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %ebx\n"
        "orl %eax, %ebx\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 45 | a */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0xa8(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54166_000543c8\n"
        "movl $0x3f800000, 0x18(%ebp)\n" /* a */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        ".Lf54166_00054350:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54166_000543b9\n"
        "movaps %xmm2, %xmm0\n"
        ".Lf54166_00054358:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x98(%ebp)\n"
        "cvttss2si -0x98(%ebp), %eax\n"
        "shll $0x18, %eax\n"
        "andl $g_effectVisArray+4351, %ebx\n"
        "orl %eax, %ebx\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 2086 | source */
        "movl %ebx, %edx\n" /* newValue */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0xe0, %esp\n" /* line 2091 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf54166_00054399:\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf54166_00054215\n"
        ".Lf54166_000543a9:\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf54166_00054218\n"
        ".Lf54166_000543b9:\n"
        "movss 0x18(%ebp), %xmm0\n" /* a */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf54166_00054358\n"
        ".Lf54166_000543c8:\n"
        "movaps %xmm2, %xmm0\n"
        "subss 0x18(%ebp), %xmm0\n" /* a */
        "jmp .Lf54166_00054350\n"
        ".Lf54166_000543d5:\n"
        "movss 0x14(%ebp), %xmm0\n" /* b */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf54166_000542ed\n"
        ".Lf54166_000543e7:\n"
        "movaps %xmm2, %xmm0\n"
        "subss 0x14(%ebp), %xmm0\n" /* b */
        "jmp .Lf54166_000542e1\n"
        ".Lf54166_000543f4:\n"
        "movaps %xmm3, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf54166_0005428a\n"
        ".Lf54166_00054404:\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf54166_0005427e\n"
    );
}

/* line 2136 */
__attribute__((naked))
void Dvar_SetColor(const dvar_t *dvar, float r, float g, float b, float a)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2136 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0, 0x14(%esp)\n" /* line 2138 */
        "movl 0x18(%ebp), %eax\n" /* a */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* b */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* g */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* r */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dvar */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetColorFromSource\n"
        "leave\n" /* line 2139 */
        "retl\n"
    );
}

/* line 1896 */
__attribute__((naked))
void Dvar_SetFloatFromSource(const dvar_t *dvar, float value, DvarSetSource source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1896 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvar */
        "movss 0xc(%ebp), %xmm0\n" /* value */
        /* { scope 1 */
        "cmpb $1, 6(%esi)\n" /* line 1905 | dvar */
        "je .Lf54448_00054496\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1911 */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl $str_00217c20, 8(%esp)\n" /* "%g" */
        "movl $0x20, 4(%esp)\n"
        "leal -0x28(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1912 */
        "movl 0x10(%ebp), %ecx\n" /* line 1919 | source */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 1924 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf54448_00054496:\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* line 1907 */
        "movl -0x2c(%ebp), %edx\n"
        "movl 0x10(%ebp), %ecx\n" /* line 1919 | source */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 1924 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1865 */
__attribute__((naked))
void Dvar_SetIntFromSource(const dvar_t *dvar, int value, DvarSetSource source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1865 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvar */
        /* { scope 1 */
        "movzbl 6(%esi), %eax\n" /* line 1874 | dvar */
        "subb $5, %al\n"
        "cmpb $1, %al\n"
        "jbe .Lf544b0_000544fa\n"
        "movl 0xc(%ebp), %eax\n" /* line 1880 | value */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_0021785c, 8(%esp)\n" /* "%i" */
        "movl $0x20, 4(%esp)\n"
        "leal -0x28(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1881 */
        "movl 0x10(%ebp), %ecx\n" /* line 1888 | source */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 1893 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf544b0_000544fa:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1876 | value */
        "movl 0x10(%ebp), %ecx\n" /* line 1888 | source */
        "movl %esi, %eax\n" /* dvar */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 1893 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1840 */
__attribute__((naked))
void Dvar_SetBoolFromSource(const dvar_t *dvar, int value, DvarSetSource source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1840 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "xorl %edx, %edx\n"
        "movl 8(%ebp), %ebx\n" /* dvar */
        "movl 0xc(%ebp), %eax\n" /* value */
        "movl 0x10(%ebp), %esi\n" /* source */
        /* { scope 1 */
        "cmpb $0, 6(%ebx)\n" /* line 1848 | dvar */
        "jne .Lf5450e_00054532\n"
        "movb %al, %dl\n" /* line 1849 */
        "movl %esi, %ecx\n" /* line 1857 | source */
        "movl %ebx, %eax\n" /* dvar */
        /* } scope */
        "popl %ebx\n" /* line 1862 */
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Dvar_SetVariant\n" /* line 1857 */
        ".Lf5450e_00054532:\n"
        "movl $str_002162ac, %edx\n" /* line 1851 */
        "testb %al, %al\n"
        "movl $str_0021952c, %eax\n" /* "0" */
        "cmovel %eax, %edx\n"
        "movl %esi, %ecx\n" /* line 1857 | source */
        "movl %ebx, %eax\n" /* dvar */
        /* } scope */
        "popl %ebx\n" /* line 1862 */
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Dvar_SetVariant\n" /* line 1857 */
    );
}

/* line 1698 */
static __attribute__((naked))
const dvar_t * Dvar_RegisterVariant(const char *dvarName, short unsigned int flags, DvarValue value, DvarLimits domain)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1698 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, %esi\n" /* type */
        "movw %cx, -0x26(%ebp)\n"
        /* { scope 1: flags, flags, type */
        /* { scope 2: type */
        "testl %eax, %eax\n" /* line 68 */
        "je .Lf54550_0005495f\n"
        "movl %eax, %edx\n"
        ".Lf54550_0005456c:\n"
        "movzbl (%edx), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf54550_000546b4\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf54550_00054579:\n"
        "movl dvarHashTable(, %eax, 4), %edi\n" /* line 1054 */
        "testl %edi, %edi\n"
        "je .Lf54550_000545a4\n"
        ".Lf54550_00054584:\n"
        "movl (%edi), %eax\n" /* line 1056 */
        "movl %eax, 4(%esp)\n"
        "movl -0x24(%ebp), %ebx\n" /* hash */
        "movl %ebx, (%esp)\n" /* hash */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf54550_000547d7\n"
        "movl 0x20(%edi), %edi\n" /* line 1054 */
        "testl %edi, %edi\n"
        "jne .Lf54550_00054584\n"
        ".Lf54550_000545a4:\n"
        "movl %esi, %edi\n" /* line 1712 | type */
        "movzwl -0x26(%ebp), %ecx\n"
        "movw %cx, -0x1a(%ebp)\n" /* flags */
        /* { scope 2: type */
        /* { scope 3 */
        "cmpl $0x4ff, dvarCount\n" /* line 1622 */
        "jg .Lf54550_000547af\n"
        ".Lf54550_000545be:\n"
        "movl dvarCount, %eax\n" /* line 1630 */
        "leal (%eax, %eax, 8), %edx\n"
        "leal (, %edx, 4), %ebx\n" /* hash */
        "leal dvarPool(%ebx), %esi\n" /* hash */
        "addl $1, %eax\n" /* line 1631 */
        "movl %eax, dvarCount\n"
        "movl %edi, %ecx\n" /* line 1632 | prev */
        "movb %cl, 6(%esi)\n"
        "testw $0x4000, -0x1a(%ebp)\n" /* line 1633 | flags */
        "jne .Lf54550_0005472e\n"
        "movl -0x24(%ebp), %edx\n" /* line 1636 */
        "movl %edx, dvarPool(%ebx)\n" /* hash */
        "movl %edi, %ecx\n" /* line 1637 | prev */
        "cmpb $3, %cl\n"
        "je .Lf54550_0005474a\n"
        ".Lf54550_00054600:\n"
        "jbe .Lf54550_00054627\n"
        "movl %edi, %ebx\n" /* prev, hash */
        "cmpb $4, %bl\n" /* hash */
        "je .Lf54550_000548d5\n"
        "cmpb $7, %bl\n" /* hash */
        "jne .Lf54550_00054630\n"
        "movl 8(%ebp), %eax\n" /* line 155 | value */
        "movzbl (%eax), %edx\n"
        "testb %dl, %dl\n"
        "jne .Lf54550_00054a10\n"
        "movl $str_002157b8, %eax\n"
        "jmp .Lf54550_00054633\n"
        ".Lf54550_00054627:\n"
        "cmpb $2, %cl\n" /* line 1637 */
        "je .Lf54550_00054882\n"
        ".Lf54550_00054630:\n"
        "movl 8(%ebp), %eax\n" /* line 1668 | value */
        ".Lf54550_00054633:\n"
        "movl %eax, 8(%esi)\n" /* dvar */
        "movl %eax, 0xc(%esi)\n" /* line 1669 | dvar */
        "movl %eax, 0x10(%esi)\n" /* line 1670 | dvar */
        ".Lf54550_0005463c:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1673 | domain */
        "movl 0x10(%ebp), %ecx\n"
        "movl %edx, 0x14(%esi)\n" /* dvar */
        "movl %ecx, 0x18(%esi)\n" /* dvar */
        "movb $0, 7(%esi)\n" /* line 1674 | dvar */
        "movl sortedDvars, %eax\n" /* line 1677 */
        "testl %eax, %eax\n"
        "je .Lf54550_000546e2\n"
        "movl $sortedDvars, %edi\n" /* prev */
        ".Lf54550_0005465e:\n"
        "movl (%eax), %eax\n" /* line 1679 */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* dvar */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "js .Lf54550_0005467e\n"
        "movl (%edi), %eax\n" /* line 1677 | prev */
        "leal 0x1c(%eax), %edi\n" /* prev */
        "movl 0x1c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf54550_0005465e\n"
        ".Lf54550_0005467e:\n"
        "movl (%edi), %eax\n" /* line 1682 | prev */
        "movl %eax, 0x1c(%esi)\n" /* dvar */
        "movl %esi, (%edi)\n" /* line 1683 | dvar, prev */
        "movzwl -0x1a(%ebp), %ecx\n" /* line 1685 | flags */
        "movw %cx, 4(%esi)\n" /* dvar */
        /* { scope 4 */
        "movl -0x24(%ebp), %ebx\n" /* line 74 | hash */
        "movzbl (%ebx), %eax\n" /* hash */
        "testb %al, %al\n"
        "jne .Lf54550_00054700\n"
        ".Lf54550_00054697:\n"
        "xorl %edx, %edx\n"
        /* } scope */
        ".Lf54550_00054699:\n"
        "movl dvarHashTable(, %edx, 4), %eax\n" /* line 1688 */
        "movl %eax, 0x20(%esi)\n" /* dvar */
        "movl %esi, dvarHashTable(, %edx, 4)\n" /* line 1689 | dvar */
        "movl %esi, %eax\n" /* line 1694 | dvar */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1713 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: flags, flags, type */
        /* { scope 2: type */
        ".Lf54550_000546b4:\n"
        "xorl %ebx, %ebx\n" /* line 74 | hash */
        "movl $0x77, %edi\n"
        ".Lf54550_000546bb:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %edi, %eax\n" /* line 77 */
        "addl %eax, %ebx\n" /* hash */
        "movl -0x24(%ebp), %ecx\n" /* line 74 */
        "movzbl -0x76(%ecx, %edi), %eax\n"
        "addl $1, %edi\n"
        "testb %al, %al\n"
        "jne .Lf54550_000546bb\n"
        "movzbl %bl, %eax\n" /* hash */
        "jmp .Lf54550_00054579\n"
        /* } scope */
        /* { scope 2: type */
        /* { scope 3 */
        ".Lf54550_000546e2:\n"
        "movl $sortedDvars, %edi\n" /* line 1677 | prev */
        "movl (%edi), %eax\n" /* line 1682 | prev */
        "movl %eax, 0x1c(%esi)\n" /* dvar */
        "movl %esi, (%edi)\n" /* line 1683 | dvar, prev */
        "movzwl -0x1a(%ebp), %ecx\n" /* line 1685 | flags */
        "movw %cx, 4(%esi)\n" /* dvar */
        /* { scope 4 */
        "movl -0x24(%ebp), %ebx\n" /* line 74 | hash */
        "movzbl (%ebx), %eax\n" /* hash */
        "testb %al, %al\n"
        "je .Lf54550_00054697\n"
        ".Lf54550_00054700:\n"
        "xorl %ebx, %ebx\n" /* hash */
        "movl $0x77, %edi\n"
        ".Lf54550_00054707:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %edi, %eax\n" /* line 77 */
        "addl %eax, %ebx\n" /* hash */
        "movl -0x24(%ebp), %edx\n" /* line 74 */
        "movzbl -0x76(%edx, %edi), %eax\n"
        "addl $1, %edi\n"
        "testb %al, %al\n"
        "jne .Lf54550_00054707\n"
        "movzbl %bl, %edx\n" /* hash */
        "jmp .Lf54550_00054699\n"
        /* } scope */
        ".Lf54550_0005472e:\n"
        "movl -0x24(%ebp), %eax\n" /* line 139 */
        "movl %eax, (%esp)\n"
        "calll CopyStringInternal\n"
        "movl %eax, dvarPool(%ebx)\n" /* line 1634 | hash */
        "movl %edi, %ecx\n" /* line 1637 | prev */
        "cmpb $3, %cl\n"
        "jne .Lf54550_00054600\n"
        ".Lf54550_0005474a:\n"
        "movzbl 6(%esi), %eax\n" /* line 125 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 8(%esi)\n"
        "movzbl 6(%esi), %ecx\n" /* line 126 */
        "shll $2, %ecx\n"
        "leal (%eax, %ecx), %edx\n"
        "movl %edx, 0xc(%esi)\n"
        "addl %ecx, %edx\n" /* line 127 */
        "movl %edx, 0x10(%esi)\n"
        "movl 8(%ebp), %ecx\n" /* line 199 | value */
        "movl (%ecx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, 8(%eax)\n"
        "movl 0xc(%esi), %edx\n" /* line 1655 | to */
        /* { scope 4 */
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x10(%esi), %edx\n" /* line 1656 | to */
        /* { scope 4 */
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf54550_0005463c\n"
        /* } scope */
        ".Lf54550_000547af:\n"
        "movl $0x500, 0xc(%esp)\n" /* line 1627 */
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $str_0021987c, 4(%esp)\n" /* "Can't create dvar '%s': %i dvars already exist" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf54550_000545be\n"
        /* } scope */
        /* } scope */
        ".Lf54550_000547d7:\n"
        "movl %esi, %eax\n" /* line 1708 | type */
        "movb %al, -0x1c(%ebp)\n" /* type */
        "movzwl -0x26(%ebp), %edx\n"
        "movw %dx, -0x1e(%ebp)\n" /* flags */
        /* { scope 2: type */
        "movzwl 4(%edi), %edx\n" /* line 1580 */
        "movzwl -0x1e(%ebp), %ecx\n" /* flags */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl %ecx, %eax\n"
        "xorl %edx, %eax\n"
        "testb $0x70, %ah\n"
        "je .Lf54550_00054815\n"
        "movl %esi, %ebx\n" /* line 1582 | hash */
        "movb %bl, -0x1b(%ebp)\n" /* hash, type */
        /* { scope 3 */
        "testb $0x40, %dh\n" /* line 1513 */
        "je .Lf54550_00054a88\n"
        "movzwl %cx, %esi\n"
        "testl $0x4000, %esi\n"
        "je .Lf54550_0005497b\n"
        /* } scope */
        ".Lf54550_00054815:\n"
        "andb $0x40, %dh\n" /* line 1586 */
        "je .Lf54550_0005484b\n"
        "movzbl -0x1c(%ebp), %eax\n" /* type */
        "cmpb 6(%edi), %al\n"
        "je .Lf54550_0005484b\n"
        "movzbl %al, %ecx\n" /* line 1589 */
        "movl 0xc(%ebp), %ebx\n" /* domain, hash */
        "movl 0x10(%ebp), %esi\n"
        "movl %ebx, 8(%esp)\n" /* hash */
        "movl %esi, 0xc(%esp)\n"
        "movl 8(%ebp), %esi\n" /* value */
        "movl %esi, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_MakeExplicitType\n"
        ".Lf54550_0005484b:\n"
        "movzwl -0x1e(%ebp), %eax\n" /* line 1595 | flags */
        "orw 4(%edi), %ax\n"
        "movw %ax, 4(%edi)\n"
        "testb %al, %al\n" /* line 1597 */
        "jns .Lf54550_0005486e\n"
        "movl dvar_cheats, %eax\n"
        "testl %eax, %eax\n"
        "je .Lf54550_0005486e\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf54550_000549f5\n"
        ".Lf54550_0005486e:\n"
        "testb $0x20, 4(%edi)\n" /* line 1603 */
        "jne .Lf54550_0005494c\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 1709 | dvar */
        /* } scope */
        ".Lf54550_0005487a:\n"
        "addl $0x3c, %esp\n" /* line 1713 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: flags, flags, type */
        /* { scope 2: type */
        /* { scope 3 */
        ".Lf54550_00054882:\n"
        "movzbl 6(%esi), %eax\n" /* line 125 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 8(%esi)\n"
        "movzbl 6(%esi), %ecx\n" /* line 126 */
        "shll $2, %ecx\n"
        "leal (%eax, %ecx), %edx\n"
        "movl %edx, 0xc(%esi)\n"
        "addl %ecx, %edx\n" /* line 127 */
        "movl %edx, 0x10(%esi)\n"
        "movl 8(%ebp), %ebx\n" /* line 37 | value */
        "movl (%ebx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 4(%ebx), %edx\n" /* line 38 */
        "movl %edx, 4(%eax)\n"
        "movl 0xc(%esi), %edx\n" /* line 1648 | to */
        /* { scope 4 */
        "movl (%ebx), %eax\n" /* line 37 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 38 */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        "movl 0x10(%esi), %edx\n" /* line 1649 | to */
        /* { scope 4 */
        "movl (%ebx), %eax\n" /* line 37 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 38 */
        "movl %eax, 4(%edx)\n"
        "jmp .Lf54550_0005463c\n"
        /* } scope */
        /* { scope 4 */
        ".Lf54550_000548d5:\n"
        "movzbl 6(%esi), %eax\n" /* line 125 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, 8(%esi)\n"
        "movzbl 6(%esi), %ecx\n" /* line 126 */
        "shll $2, %ecx\n"
        "leal (%eax, %ecx), %edx\n"
        "movl %edx, 0xc(%esi)\n"
        "addl %ecx, %edx\n" /* line 127 */
        "movl %edx, 0x10(%esi)\n"
        /* } scope */
        "movl 8(%ebp), %ebx\n" /* line 456 | value, hash */
        "movl (%ebx), %edx\n" /* hash */
        "movl %edx, (%eax)\n"
        "movl 4(%ebx), %edx\n" /* line 457 | hash */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ebx), %edx\n" /* line 458 | hash */
        "movl %edx, 8(%eax)\n"
        "movl 0xc(%ebx), %edx\n" /* line 459 | hash */
        "movl %edx, 0xc(%eax)\n"
        "movl 0xc(%esi), %edx\n" /* line 1662 | dvar, to */
        /* { scope 4 */
        "movl (%ebx), %eax\n" /* line 456 | hash */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 457 | hash */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 458 | hash */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 459 | hash */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movl 0x10(%esi), %edx\n" /* line 1663 | dvar, to */
        /* { scope 4 */
        "movl (%ebx), %eax\n" /* line 456 | hash */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 457 | hash */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 458 | hash */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 459 | hash */
        "movl %eax, 0xc(%edx)\n"
        "jmp .Lf54550_0005463c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: type */
        ".Lf54550_0005494c:\n"
        "movl 0xc(%edi), %edx\n" /* line 1553 */
        "xorl %ecx, %ecx\n"
        "movl %edi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 1709 | dvar */
        "jmp .Lf54550_0005487a\n"
        /* { scope 2: type */
        ".Lf54550_0005495f:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x24(%ebp), %edx\n"
        "jmp .Lf54550_0005456c\n"
        /* } scope */
        /* { scope 2: type */
        /* { scope 3 */
        ".Lf54550_0005497b:\n"
        "movl %edi, %eax\n" /* line 1522 */
        "calll Dvar_PerformUnregistration\n"
        "movl (%edi), %eax\n" /* line 145 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl -0x24(%ebp), %eax\n" /* line 1525 */
        "movl %eax, (%edi)\n"
        "andw $0xbfff, 4(%edi)\n" /* line 1526 */
        "movzbl %bl, %ecx\n" /* line 1528 | hash */
        "movl 0xc(%ebp), %eax\n" /* domain */
        "movl 0x10(%ebp), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 8(%ebp), %edx\n" /* value */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_MakeExplicitType\n"
        "movzwl 4(%edi), %edx\n"
        /* } scope */
        ".Lf54550_000549c0:\n"
        "andl $__mh_execute_header, %esi\n" /* line 1538 */
        "je .Lf54550_00054815\n"
        "testb $0x10, %dh\n"
        "jne .Lf54550_00054815\n"
        "movl -0x24(%ebp), %ecx\n" /* line 1540 */
        "movl %ecx, (%edi)\n"
        "cmpb $6, 6(%edi)\n" /* line 1541 */
        "jne .Lf54550_00054815\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1542 | domain, hash */
        "movl 0x10(%ebp), %esi\n"
        "movl %ebx, 0x14(%edi)\n" /* hash */
        "movl %esi, 0x18(%edi)\n"
        "jmp .Lf54550_00054815\n"
        ".Lf54550_000549f5:\n"
        "movl 0x10(%edi), %edx\n" /* line 1599 */
        "xorl %ecx, %ecx\n"
        "movl %edi, %eax\n"
        "calll Dvar_SetVariant\n"
        "movl 0x10(%edi), %edx\n" /* line 1600 */
        "movl %edi, %eax\n"
        "calll Dvar_SetLatchedValue\n"
        "jmp .Lf54550_0005486e\n"
        ".Lf54550_00054a10:\n"
        "movl %eax, %edi\n"
        "movl %eax, %ebx\n" /* hash */
        /* } scope */
        /* { scope 2: type */
        /* { scope 3 */
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movzbl 1(%ebx), %eax\n" /* line 160 | hash */
        "testb %al, %al\n"
        "jne .Lf54550_00054a51\n"
        "leal -0x30(%edx), %eax\n" /* line 162 */
        "cmpb $9, %al\n"
        "ja .Lf54550_00054a41\n"
        "movsbl %dl, %eax\n" /* line 163 */
        "leal __ZZN16CStringEdPackage9ParseLineEPKchE5C.208+1024(%eax, %eax), %eax\n"
        "jmp .Lf54550_00054633\n"
        ".Lf54550_00054a41:\n"
        "movl 8(%ebp), %ecx\n" /* value */
        ".Lf54550_00054a44:\n"
        "movl %ecx, (%esp)\n" /* line 173 */
        "calll CopyStringInternal\n"
        "jmp .Lf54550_00054633\n"
        ".Lf54550_00054a51:\n"
        "cmpb $0x6f, %dl\n" /* line 165 */
        "jne .Lf54550_00054a41\n"
        "cmpl $3, %ecx\n" /* line 167 */
        "je .Lf54550_00054a77\n"
        "cmpl $2, %ecx\n" /* line 169 */
        "jne .Lf54550_00054a41\n"
        "cmpb $0x6e, %al\n"
        "jne .Lf54550_00054a41\n"
        "movl 8(%ebp), %edx\n" /* value */
        "cmpb $0, 2(%edx)\n"
        "jne .Lf54550_00054a9c\n"
        "movl dvarOnOffStrings+4, %eax\n" /* line 170 */
        "jmp .Lf54550_00054633\n"
        ".Lf54550_00054a77:\n"
        "cmpb $0x66, %al\n" /* line 167 */
        "jne .Lf54550_00054a41\n"
        "movl 8(%ebp), %eax\n" /* value */
        "cmpb $0x66, 2(%eax)\n"
        "je .Lf54550_00054aa0\n"
        "movl %eax, %ecx\n"
        "jmp .Lf54550_00054a44\n"
        /* } scope */
        /* } scope */
        /* { scope 2: type */
        /* { scope 3 */
        ".Lf54550_00054a88:\n"
        "movzwl %cx, %esi\n" /* line 1513 */
        /* } scope */
        "testl $0x4000, %esi\n" /* line 1534 */
        "je .Lf54550_000549c0\n"
        "jmp .Lf54550_00054815\n"
        ".Lf54550_00054a9c:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf54550_00054a44\n"
        /* } scope */
        /* { scope 2: type */
        /* { scope 3 */
        ".Lf54550_00054aa0:\n"
        "cmpb $0, 3(%eax)\n" /* line 167 */
        "jne .Lf54550_00054a41\n"
        "movl dvarOnOffStrings, %eax\n" /* line 168 */
        "jmp .Lf54550_00054633\n"
    );
}

/* line 1825 */
__attribute__((naked))
const dvar_t * Dvar_RegisterColor(const char *dvarName, float r, float g, float b, float a, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1825 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "xorl %ebx, %ebx\n"
        "movss 0xc(%ebp), %xmm1\n" /* r */
        "movss 0x10(%ebp), %xmm3\n" /* g */
        "movl 0x1c(%ebp), %esi\n" /* flags */
        /* { scope 1 */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54ab0_00054cd0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        ".Lf54ab0_00054aef:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54ab0_00054cc0\n"
        "movaps %xmm2, %xmm0\n"
        ".Lf54ab0_00054afb:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "movss %xmm3, -0x48(%ebp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "movb %al, %bl\n"
        "movss -0x48(%ebp), %xmm3\n" /* line 45 */
        "movaps %xmm3, %xmm0\n"
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54ab0_00054cb4\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        ".Lf54ab0_00054b4f:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54ab0_00054ca4\n"
        "movaps %xmm2, %xmm0\n"
        ".Lf54ab0_00054b5b:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll floorf\n"
        "fstps -0x20(%ebp)\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "movb %al, %bh\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 45 | b */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54ab0_00054c97\n"
        "movl $0x3f800000, 0x14(%ebp)\n" /* b */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        ".Lf54ab0_00054ba6:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54ab0_00054c85\n"
        "movaps %xmm2, %xmm0\n"
        ".Lf54ab0_00054bb2:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll floorf\n"
        "fstps -0x24(%ebp)\n"
        "cvttss2si -0x24(%ebp), %eax\n"
        "movzbl %al, %eax\n"
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %ebx\n"
        "orl %eax, %ebx\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 45 | a */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54ab0_00054c7b\n"
        "movl $0x3f800000, 0x18(%ebp)\n" /* a */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        ".Lf54ab0_00054c09:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf54ab0_00054c6c\n"
        "movaps %xmm2, %xmm0\n"
        ".Lf54ab0_00054c11:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x28(%ebp)\n"
        "cvttss2si -0x28(%ebp), %eax\n"
        "shll $0x18, %eax\n"
        "andl $g_effectVisArray+4351, %ebx\n"
        "orl %eax, %ebx\n"
        "movl $0, -0x10(%ebp)\n" /* line 1835 | dvarDomain */
        "movl $0, -0xc(%ebp)\n"
        "movzwl %si, %ecx\n" /* line 1836 | flags */
        "movl -0x10(%ebp), %eax\n" /* dvarDomain */
        "movl -0xc(%ebp), %edx\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %ebx, (%esp)\n" /* dvarValue */
        "movl $8, %edx\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 1837 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf54ab0_00054c6c:\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 45 | a */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf54ab0_00054c11\n"
        ".Lf54ab0_00054c7b:\n"
        "movaps %xmm2, %xmm0\n"
        "subss 0x18(%ebp), %xmm0\n" /* a */
        "jmp .Lf54ab0_00054c09\n"
        ".Lf54ab0_00054c85:\n"
        "movss 0x14(%ebp), %xmm0\n" /* b */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf54ab0_00054bb2\n"
        ".Lf54ab0_00054c97:\n"
        "movaps %xmm2, %xmm0\n"
        "subss 0x14(%ebp), %xmm0\n" /* b */
        "jmp .Lf54ab0_00054ba6\n"
        ".Lf54ab0_00054ca4:\n"
        "movaps %xmm3, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf54ab0_00054b5b\n"
        ".Lf54ab0_00054cb4:\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf54ab0_00054b4f\n"
        ".Lf54ab0_00054cc0:\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf54ab0_00054afb\n"
        ".Lf54ab0_00054cd0:\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "jmp .Lf54ab0_00054aef\n"
    );
}

/* line 1808 */
__attribute__((naked))
const dvar_t * Dvar_RegisterEnum(const char *dvarName, const char * *valueList, int defaultIndex, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1808 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* dvarName, valueList */
        "movl %eax, -0x10(%ebp)\n" /* valueList, dvarName */
        "movl 0xc(%ebp), %eax\n" /* valueList */
        "movl 0x10(%ebp), %edi\n" /* defaultIndex */
        "movl 0x14(%ebp), %ecx\n" /* flags */
        /* { scope 1 */
        "movl %eax, %esi\n" /* line 1816 */
        "xorl %ebx, %ebx\n" /* line 1817 | dvarDomain */
        "movl (%eax), %edx\n" /* line 1818 */
        "testl %edx, %edx\n"
        "je .Lf54cdc_00054d0c\n"
        "xorl %edx, %edx\n"
        ".Lf54cdc_00054d00:\n"
        "addl $1, %edx\n" /* line 1819 */
        "movl (%eax, %edx, 4), %ebx\n" /* line 1818 | dvarDomain */
        "testl %ebx, %ebx\n" /* dvarDomain */
        "jne .Lf54cdc_00054d00\n"
        "movl %edx, %ebx\n" /* dvarDomain */
        ".Lf54cdc_00054d0c:\n"
        "movzwl %cx, %ecx\n" /* line 1821 */
        "movl %ebx, 0xc(%ebp)\n" /* dvarDomain, valueList */
        "movl %esi, 0x10(%ebp)\n" /* defaultIndex */
        "movl %edi, 8(%ebp)\n" /* defaultIndex, dvarName */
        "movl $6, %edx\n"
        "movl -0x10(%ebp), %eax\n" /* dvarName */
        /* } scope */
        "addl $4, %esp\n" /* line 1822 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Dvar_RegisterVariant\n" /* line 1821 */
    );
}

/* line 1793 */
__attribute__((naked))
const dvar_t * Dvar_RegisterString(const char *dvarName, const char *value, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1793 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        "movzwl 0x10(%ebp), %ecx\n" /* flags */
        /* { scope 1 */
        "movl $0, -0x10(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0xc(%ebp)\n"
        "movl -0x10(%ebp), %ebx\n" /* line 1804 | dvarDomain */
        "movl -0xc(%ebp), %esi\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* value */
        "movl %edx, (%esp)\n"
        "movl $7, %edx\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 1805 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1779 */
__attribute__((naked))
const dvar_t * Dvar_RegisterVec4(const char *dvarName, float x, float y, float z, float w, float min, float max, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1779 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        "movzwl 0x24(%ebp), %ecx\n" /* flags */
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 447 | x */
        "movl %edx, -0x18(%ebp)\n" /* vector */
        "movl 0x10(%ebp), %edx\n" /* line 448 | y */
        "movl %edx, -0x14(%ebp)\n"
        "movl 0x14(%ebp), %edx\n" /* line 449 | z */
        "movl %edx, -0x10(%ebp)\n"
        "movl 0x18(%ebp), %edx\n" /* line 450 | w */
        "movl %edx, -0xc(%ebp)\n"
        "leal -0x18(%ebp), %edx\n" /* line 1786 | vector */
        "movl 0x1c(%ebp), %ebx\n" /* line 1787 | min, dvarDomain */
        "movl 0x20(%ebp), %esi\n" /* line 1788 | max */
        "movl %ebx, 4(%esp)\n" /* line 1789 | dvarDomain */
        "movl %esi, 8(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl $4, %edx\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 1790 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1765 */
__attribute__((naked))
const dvar_t * Dvar_RegisterVec3(const char *dvarName, float x, float y, float z, float min, float max, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1765 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        "movzwl 0x20(%ebp), %ecx\n" /* flags */
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 191 | x */
        "movl %edx, -0x14(%ebp)\n" /* vector */
        "movl 0x10(%ebp), %edx\n" /* line 192 | y */
        "movl %edx, -0x10(%ebp)\n"
        "movl 0x14(%ebp), %edx\n" /* line 193 | z */
        "movl %edx, -0xc(%ebp)\n"
        "leal -0x14(%ebp), %edx\n" /* line 1772 | vector */
        "movl 0x18(%ebp), %ebx\n" /* line 1773 | min, dvarDomain */
        "movl 0x1c(%ebp), %esi\n" /* line 1774 | max */
        "movl %ebx, 4(%esp)\n" /* line 1775 | dvarDomain */
        "movl %esi, 8(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl $3, %edx\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 1776 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1751 */
__attribute__((naked))
const dvar_t * Dvar_RegisterVec2(const char *dvarName, float x, float y, float min, float max, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1751 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        "movzwl 0x1c(%ebp), %ecx\n" /* flags */
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 30 | x */
        "movl %edx, -0x10(%ebp)\n" /* vector */
        "movl 0x10(%ebp), %edx\n" /* line 31 | y */
        "movl %edx, -0xc(%ebp)\n"
        "leal -0x10(%ebp), %edx\n" /* line 1758 | vector */
        "movl 0x14(%ebp), %ebx\n" /* line 1759 | min, dvarDomain */
        "movl 0x18(%ebp), %esi\n" /* line 1760 | max */
        "movl %ebx, 4(%esp)\n" /* line 1761 | dvarDomain */
        "movl %esi, 8(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl $2, %edx\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 1762 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1739 */
__attribute__((naked))
const dvar_t * Dvar_RegisterFloat(const char *dvarName, float value, float min, float max, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1739 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 1744 | value */
        "movl 0x10(%ebp), %ebx\n" /* line 1745 | min, dvarDomain */
        "movl 0x14(%ebp), %esi\n" /* line 1746 | max */
        "movzwl 0x18(%ebp), %ecx\n" /* line 1747 | flags */
        "movl %ebx, 0xc(%ebp)\n" /* dvarDomain, value */
        "movl %esi, 0x10(%ebp)\n" /* min */
        "movl %edx, 8(%ebp)\n" /* dvarName */
        "movl $1, %edx\n"
        /* } scope */
        "popl %ebx\n" /* line 1748 */
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Dvar_RegisterVariant\n" /* line 1747 */
    );
}

/* line 1727 */
__attribute__((naked))
const dvar_t * Dvar_RegisterInt(const char *dvarName, int value, int min, int max, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1727 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        "movl 0xc(%ebp), %edx\n" /* value */
        /* { scope 1 */
        "movl 0x10(%ebp), %ebx\n" /* line 1733 | min, dvarDomain */
        "movl 0x14(%ebp), %esi\n" /* line 1734 | max */
        "movzwl 0x18(%ebp), %ecx\n" /* line 1735 | flags */
        "movl %ebx, 0xc(%ebp)\n" /* dvarDomain, value */
        "movl %esi, 0x10(%ebp)\n" /* min */
        "movl %edx, 8(%ebp)\n" /* dvarName */
        "movl $5, %edx\n"
        /* } scope */
        "popl %ebx\n" /* line 1736 */
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Dvar_RegisterVariant\n" /* line 1735 */
    );
}

/* line 1716 */
__attribute__((naked))
const dvar_t * Dvar_RegisterBool(const char *dvarName, int value, int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1716 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "xorl %edx, %edx\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        "movzwl 0x10(%ebp), %ecx\n" /* flags */
        /* { scope 1 */
        "movb 0xc(%ebp), %dl\n" /* line 1721 | value */
        "movl $0, -0x10(%ebp)\n" /* line 1722 | dvarDomain */
        "movl $0, -0xc(%ebp)\n"
        "movl -0x10(%ebp), %ebx\n" /* line 1723 | dvarDomain */
        "movl -0xc(%ebp), %esi\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edx, (%esp)\n"
        "xorl %edx, %edx\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 1724 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2376 */
__attribute__((naked))
void Dvar_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2376 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movb $1, isDvarSystemActive\n" /* line 2378 */
        /* { scope 1 */
        "movl $0, -0x10(%ebp)\n" /* line 1722 | dvarDomain */
        "movl $0, -0xc(%ebp)\n"
        "movl -0x10(%ebp), %eax\n" /* line 1723 | dvarDomain */
        "movl -0xc(%ebp), %edx\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $0x1018, %ecx\n"
        "xorl %edx, %edx\n"
        "movl $str_002198ac, %eax\n" /* "sv_cheats" */
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "movl %eax, dvar_cheats\n" /* line 2379 */
        "calll Dvar_AddCommands\n" /* line 2382 */
        "leave\n" /* line 2384 */
        "retl\n"
    );
}

/* line 2517 */
__attribute__((naked))
void Dvar_ResetDvars(unsigned int filter, DvarSetSource setSource)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2517 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %esi\n" /* filter */
        "movl 0xc(%ebp), %edi\n" /* setSource */
        /* { scope 1 */
        "movl sortedDvars, %ebx\n" /* line 2525 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf54f28_00054f4a\n"
        "jmp .Lf54f28_00054f65\n"
        ".Lf54f28_00054f43:\n"
        "movl 0x1c(%ebx), %ebx\n" /* var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf54f28_00054f65\n"
        ".Lf54f28_00054f4a:\n"
        "movzwl 4(%ebx), %eax\n" /* line 2527 | var */
        "testl %esi, %eax\n" /* filter */
        "je .Lf54f28_00054f43\n"
        "movl 0x10(%ebx), %edx\n" /* line 2335 */
        "movl %edi, %ecx\n"
        "movl %ebx, %eax\n"
        "calll Dvar_SetVariant\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 2525 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf54f28_00054f4a\n"
        /* } scope */
        ".Lf54f28_00054f65:\n"
        "addl $0xc, %esp\n" /* line 2534 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2574 */
__attribute__((naked))
qboolean Com_LoadDvarsFromBuffer(const char * *dvarnames, int numDvars, const char *buffer, const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2574 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x402c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 2587 | numDvars */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x4018(%ebp), %edx\n" /* wasRead */
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl 0xc(%ebp), %esi\n" /* line 2590 | numDvars, token */
        "testl %esi, %esi\n" /* token */
        "jle .Lf54f6e_0005500d\n"
        "movl $0, -0x4024(%ebp)\n" /* i */
        "movl -0x4024(%ebp), %eax\n" /* i */
        ".Lf54f6e_00054fae:\n"
        "movl 8(%ebp), %edx\n" /* line 2592 | dvarnames */
        "movl (%edx, %eax, 4), %esi\n" /* token */
        /* { scope 2 */
        /* { scope 3: hash */
        /* { scope 4 */
        "testl %esi, %esi\n" /* line 68 */
        "je .Lf54f6e_000551e3\n"
        ".Lf54f6e_00054fbc:\n"
        "movzbl (%esi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf54f6e_00055179\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf54f6e_00054fc9:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf54f6e_00054fed\n"
        ".Lf54f6e_00054fd4:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fname */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf54f6e_00054fef\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf54f6e_00054fd4\n"
        ".Lf54f6e_00054fed:\n"
        "xorl %ebx, %ebx\n" /* var */
        /* } scope */
        ".Lf54f6e_00054fef:\n"
        "movl 0x10(%ebx), %edx\n" /* line 2335 | var */
        "xorl %ecx, %ecx\n"
        "movl %ebx, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        "addl $1, -0x4024(%ebp)\n" /* line 2590 | i */
        "movl -0x4024(%ebp), %eax\n" /* i */
        "cmpl %eax, 0xc(%ebp)\n" /* numDvars */
        "jne .Lf54f6e_00054fae\n"
        ".Lf54f6e_0005500d:\n"
        "movl 0x14(%ebp), %edx\n" /* line 2597 | filename */
        "movl %edx, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "movl $0, -0x4020(%ebp)\n" /* numRead */
        "leal 0x10(%ebp), %eax\n" /* line 2600 | buffer */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* token */
        "cmpb $0, (%eax)\n" /* line 2601 */
        "je .Lf54f6e_00055095\n"
        ".Lf54f6e_00055034:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 2604 | numDvars, var */
        "testl %ebx, %ebx\n" /* var */
        "jle .Lf54f6e_00055061\n"
        "movl 8(%ebp), %ebx\n" /* dvarnames, var */
        "xorl %edi, %edi\n" /* hash */
        ".Lf54f6e_00055040:\n"
        "movl (%ebx), %eax\n" /* line 2606 | var */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* token */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf54f6e_00055104\n"
        "addl $1, %edi\n" /* line 2604 | hash */
        "addl $4, %ebx\n" /* var */
        "cmpl %edi, 0xc(%ebp)\n" /* hash, numDvars */
        "jne .Lf54f6e_00055040\n"
        ".Lf54f6e_00055061:\n"
        "movl 0x14(%ebp), %eax\n" /* line 2620 | filename */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* token */
        "movl $str_002198b8, (%esp)\n" /* "^3WARNING: unknown dvar '%s' in file '%s'
" */
        "calll Com_Printf\n"
        ".Lf54f6e_00055078:\n"
        "leal 0x10(%ebp), %edx\n" /* line 2623 | buffer */
        "movl %edx, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "leal 0x10(%ebp), %eax\n" /* line 2600 | buffer */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* token */
        "cmpb $0, (%eax)\n" /* line 2601 */
        "jne .Lf54f6e_00055034\n"
        ".Lf54f6e_00055095:\n"
        "calll Com_EndParseSession\n" /* line 2625 */
        "movl -0x4020(%ebp), %eax\n" /* line 2627 | numRead */
        "cmpl %eax, 0xc(%ebp)\n" /* numDvars */
        "je .Lf54f6e_000551fc\n"
        "movl 0x14(%ebp), %edx\n" /* line 2630 | filename */
        "movl %edx, 4(%esp)\n"
        "movl $str_002198e4, (%esp)\n" /* "^1ERROR: the following dvars were not specified in file '%s'" */
        "calll Com_Printf\n"
        "movl 0xc(%ebp), %ecx\n" /* line 2631 | numDvars */
        "testl %ecx, %ecx\n"
        "jle .Lf54f6e_000550f7\n"
        "xorl %ebx, %ebx\n" /* var */
        "jmp .Lf54f6e_000550cf\n"
        ".Lf54f6e_000550c7:\n"
        "addl $1, %ebx\n" /* var */
        "cmpl %ebx, 0xc(%ebp)\n" /* var, numDvars */
        "je .Lf54f6e_000550f7\n"
        ".Lf54f6e_000550cf:\n"
        "cmpb $0, -0x4018(%ebx, %ebp)\n" /* line 2633 | var */
        "jne .Lf54f6e_000550c7\n"
        "movl 8(%ebp), %edx\n" /* line 2634 | dvarnames */
        "movl (%edx, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00219924, (%esp)\n" /* "^1  %s
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 2631 | var */
        "cmpl %ebx, 0xc(%ebp)\n" /* var, numDvars */
        "jne .Lf54f6e_000550cf\n"
        ".Lf54f6e_000550f7:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x402c, %esp\n" /* line 2637 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf54f6e_00055104:\n"
        "movl (%ebx), %esi\n" /* line 2608 | var, token */
        /* { scope 2 */
        /* { scope 3: hash */
        /* { scope 4 */
        "testl %esi, %esi\n" /* line 68 */
        "je .Lf54f6e_0005520c\n"
        ".Lf54f6e_0005510e:\n"
        "movzbl (%esi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf54f6e_000551a8\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf54f6e_0005511b:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf54f6e_0005513f\n"
        ".Lf54f6e_00055126:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fname */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf54f6e_00055141\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf54f6e_00055126\n"
        ".Lf54f6e_0005513f:\n"
        "xorl %ebx, %ebx\n" /* var */
        /* } scope */
        ".Lf54f6e_00055141:\n"
        "leal 0x10(%ebp), %edx\n" /* line 2610 | buffer */
        "movl %edx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "xorl %ecx, %ecx\n" /* line 2170 */
        "movl %eax, %edx\n"
        "movl %ebx, %eax\n" /* var */
        "calll Dvar_SetFromStringFromSource\n"
        "cmpb $0, -0x4018(%ebp, %edi)\n" /* line 2612 */
        "jne .Lf54f6e_00055078\n"
        "movb $1, -0x4018(%ebp, %edi)\n" /* line 2614 */
        "addl $1, -0x4020(%ebp)\n" /* line 2615 | numRead */
        "jmp .Lf54f6e_00055078\n"
        /* { scope 2 */
        /* { scope 3: hash */
        /* { scope 4 */
        ".Lf54f6e_00055179:\n"
        "xorl %edi, %edi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf54f6e_00055180:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %edi\n" /* hash */
        "movzbl -0x76(%ebx, %esi), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf54f6e_00055180\n"
        "movl %edi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf54f6e_00054fc9\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: hash */
        /* { scope 4 */
        ".Lf54f6e_000551a8:\n"
        "movl $0, -0x401c(%ebp)\n" /* hash */
        "movl $0x77, %ebx\n"
        ".Lf54f6e_000551b7:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, -0x401c(%ebp)\n" /* hash */
        "movzbl -0x76(%esi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf54f6e_000551b7\n"
        "movzbl -0x401c(%ebp), %eax\n" /* hash */
        "jmp .Lf54f6e_0005511b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: hash */
        /* { scope 4 */
        ".Lf54f6e_000551e3:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf54f6e_00054fbc\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf54f6e_000551fc:\n"
        "movl $1, %eax\n" /* line 2627 */
        /* } scope */
        "addl $0x402c, %esp\n" /* line 2637 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3: hash */
        /* { scope 4 */
        ".Lf54f6e_0005520c:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf54f6e_0005510e\n"
    );
}

/* line 2094 */
__attribute__((naked))
void Dvar_SetBool(const dvar_t *dvar, int value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2094 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "xorl %edx, %edx\n"
        "movl 8(%ebp), %ebx\n" /* dvar */
        "movzbl 0xc(%ebp), %eax\n" /* value */
        /* { scope 1 */
        /* { scope 2 */
        "cmpb $0, 6(%ebx)\n" /* line 1848 */
        "jne .Lf55226_00055246\n"
        "movb %al, %dl\n" /* line 1849 */
        "xorl %ecx, %ecx\n" /* line 1857 */
        "movl %ebx, %eax\n"
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 2097 */
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp Dvar_SetVariant\n" /* line 1857 */
        ".Lf55226_00055246:\n"
        "movl $str_002162ac, %edx\n" /* line 1851 */
        "testb %al, %al\n"
        "movl $str_0021952c, %eax\n" /* "0" */
        "cmovel %eax, %edx\n"
        "xorl %ecx, %ecx\n" /* line 1857 */
        "movl %ebx, %eax\n"
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 2097 */
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp Dvar_SetVariant\n" /* line 1857 */
    );
}

/* line 2106 */
__attribute__((naked))
void Dvar_SetFloat(const dvar_t *dvar, float value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2106 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvar */
        "movss 0xc(%ebp), %xmm0\n" /* value */
        /* { scope 1 */
        "cmpb $1, 6(%esi)\n" /* line 1905 */
        "je .Lf55260_000552ad\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1911 */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl $str_00217c20, 8(%esp)\n" /* "%g" */
        "movl $0x20, 4(%esp)\n"
        "leal -0x28(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1912 */
        "xorl %ecx, %ecx\n" /* line 1919 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 2109 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf55260_000552ad:\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* line 1907 */
        "movl -0x2c(%ebp), %edx\n"
        "xorl %ecx, %ecx\n" /* line 1919 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 2109 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2100 */
__attribute__((naked))
void Dvar_SetInt(const dvar_t *dvar, int value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2100 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvar */
        /* { scope 1 */
        "movzbl 6(%esi), %eax\n" /* line 1874 */
        "subb $5, %al\n"
        "cmpb $1, %al\n"
        "jbe .Lf552c6_0005530f\n"
        "movl 0xc(%ebp), %eax\n" /* line 1880 | value */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_0021785c, 8(%esp)\n" /* "%i" */
        "movl $0x20, 4(%esp)\n"
        "leal -0x28(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1881 */
        "xorl %ecx, %ecx\n" /* line 1888 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 2103 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf552c6_0005530f:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1876 | value */
        "xorl %ecx, %ecx\n" /* line 1888 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 2103 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2112 */
__attribute__((naked))
void Dvar_SetVec2(const dvar_t *dvar, float x, float y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2112 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x70, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvar */
        "movss 0xc(%ebp), %xmm1\n" /* x */
        "movss 0x10(%ebp), %xmm0\n" /* y */
        /* { scope 1 */
        "cmpb $4, 6(%esi)\n" /* line 1937 */
        "je .Lf55322_0005537e\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1944 */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0xc(%esp)\n"
        "movl $str_00219530, 8(%esp)\n" /* "%g %g" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x50(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1945 */
        "xorl %ecx, %ecx\n" /* line 1952 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x70, %esp\n" /* line 2115 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf55322_0005537e:\n"
        "movss %xmm1, -0x10(%ebp)\n" /* line 30 | vector */
        "movss %xmm0, -0xc(%ebp)\n" /* line 31 */
        "leal -0x10(%ebp), %edx\n" /* line 1940 | vector */
        "xorl %ecx, %ecx\n" /* line 1952 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x70, %esp\n" /* line 2115 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2118 */
__attribute__((naked))
void Dvar_SetVec3(const dvar_t *dvar, float x, float y, float z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2118 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xa0, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvar */
        "movss 0xc(%ebp), %xmm2\n" /* x */
        "movss 0x10(%ebp), %xmm1\n" /* y */
        "movss 0x14(%ebp), %xmm0\n" /* z */
        /* { scope 1 */
        "cmpb $3, 6(%esi)\n" /* line 1970 */
        "je .Lf5539c_0005540d\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1977 */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0x14(%esp)\n"
        "cvtss2sd %xmm2, %xmm2\n"
        "movsd %xmm2, 0xc(%esp)\n"
        "movl $str_00219538, 8(%esp)\n" /* "%g %g %g" */
        "movl $0x60, 4(%esp)\n"
        "leal -0x74(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1978 */
        "xorl %ecx, %ecx\n" /* line 1985 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0xa0, %esp\n" /* line 2121 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5539c_0005540d:\n"
        "movss %xmm2, -0x14(%ebp)\n" /* line 191 | vector */
        "movss %xmm1, -0x10(%ebp)\n" /* line 192 */
        "movss %xmm0, -0xc(%ebp)\n" /* line 193 */
        "leal -0x14(%ebp), %edx\n" /* line 1973 | vector */
        "xorl %ecx, %ecx\n" /* line 1985 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0xa0, %esp\n" /* line 2121 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2124 */
__attribute__((naked))
void Dvar_SetVec4(const dvar_t *dvar, float x, float y, float z, float w)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2124 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc0, %esp\n"
        "movl 8(%ebp), %esi\n" /* dvar */
        "movss 0xc(%ebp), %xmm3\n" /* x */
        "movss 0x10(%ebp), %xmm2\n" /* y */
        "movss 0x14(%ebp), %xmm1\n" /* z */
        "movss 0x18(%ebp), %xmm0\n" /* w */
        /* { scope 1 */
        "cmpb $4, 6(%esi)\n" /* line 2003 */
        "je .Lf55432_000554b5\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 2010 */
        "movsd %xmm0, 0x24(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0x1c(%esp)\n"
        "cvtss2sd %xmm2, %xmm2\n"
        "movsd %xmm2, 0x14(%esp)\n"
        "cvtss2sd %xmm3, %xmm3\n"
        "movsd %xmm3, 0xc(%esp)\n"
        "movl $str_00219544, 8(%esp)\n" /* "%g %g %g %g" */
        "movl $0x80, 4(%esp)\n"
        "leal -0x98(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 2011 */
        "xorl %ecx, %ecx\n" /* line 2018 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0xc0, %esp\n" /* line 2127 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf55432_000554b5:\n"
        "movss %xmm3, -0x18(%ebp)\n" /* line 447 | vector */
        "movss %xmm2, -0x14(%ebp)\n" /* line 448 */
        "movss %xmm1, -0x10(%ebp)\n" /* line 449 */
        "movss %xmm0, -0xc(%ebp)\n" /* line 450 */
        "leal -0x18(%ebp), %edx\n" /* line 2006 | vector */
        "xorl %ecx, %ecx\n" /* line 2018 */
        "movl %esi, %eax\n"
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0xc0, %esp\n" /* line 2127 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2174 */
__attribute__((naked))
void Dvar_SetBoolByName(const char *dvarName, int value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2174 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl $0, -0x2c(%ebp)\n" /* newValue */
        "movl 8(%ebp), %edi\n" /* dvarName */
        "movzbl 0xc(%ebp), %eax\n" /* value */
        "movb %al, -0x2d(%ebp)\n" /* value */
        /* { scope 1: newValue */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf554e0_000555cc\n"
        ".Lf554e0_00055502:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf554e0_00055578\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf554e0_0005550b:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf554e0_0005552f\n"
        ".Lf554e0_00055516:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf554e0_000555a7\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf554e0_00055516\n"
        /* } scope */
        ".Lf554e0_0005552f:\n"
        "movl $str_002162ac, %ecx\n" /* line 2182 */
        "cmpb $0, -0x2d(%ebp)\n" /* value */
        "movl $str_0021952c, %eax\n" /* "0" */
        "cmovel %eax, %ecx\n"
        /* { scope 1: newValue */
        "movl $0, -0x20(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 1804 | dvarDomain */
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl $0x4000, %ecx\n"
        "movl $7, %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: newValue */
        /* { scope 2 */
        ".Lf554e0_00055578:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf554e0_0005557f:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf554e0_0005557f\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf554e0_0005550b\n"
        /* } scope */
        /* } scope */
        ".Lf554e0_000555a7:\n"
        "testl %ebx, %ebx\n" /* line 2179 | var */
        "je .Lf554e0_0005552f\n"
        "movzbl -0x2d(%ebp), %eax\n" /* value */
        /* { scope 1: newValue */
        /* { scope 2 */
        "cmpb $0, 6(%ebx)\n" /* line 1848 | var */
        "jne .Lf554e0_000555e5\n"
        "movb %al, -0x2c(%ebp)\n" /* line 1849 | newValue */
        "movl -0x2c(%ebp), %edx\n" /* newValue */
        ".Lf554e0_000555bb:\n"
        "xorl %ecx, %ecx\n" /* line 1857 */
        "movl %ebx, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: newValue */
        /* { scope 2 */
        ".Lf554e0_000555cc:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf554e0_00055502\n"
        /* } scope */
        /* } scope */
        /* { scope 1: newValue */
        /* { scope 2 */
        ".Lf554e0_000555e5:\n"
        "movl $str_002162ac, -0x2c(%ebp)\n" /* line 1851 | newValue */
        "testb %al, %al\n"
        "movl $str_0021952c, %eax\n" /* "0" */
        "cmovnel -0x2c(%ebp), %eax\n" /* newValue */
        "movl %eax, -0x2c(%ebp)\n" /* newValue */
        "movl %eax, %edx\n"
        "jmp .Lf554e0_000555bb\n"
    );
}

/* line 2186 */
__attribute__((naked))
void Dvar_SetIntByName(const char *dvarName, int value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2186 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1: dvarDomain */
        /* { scope 2 */
        /* { scope 3 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf555fe_00055717\n"
        ".Lf555fe_00055612:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf555fe_000556a1\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf555fe_0005561f:\n"
        "movl dvarHashTable(, %eax, 4), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "je .Lf555fe_00055647\n"
        ".Lf555fe_0005562a:\n"
        "movl (%esi), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf555fe_000556d0\n"
        "movl 0x20(%esi), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "jne .Lf555fe_0005562a\n"
        /* } scope */
        ".Lf555fe_00055647:\n"
        "movl 0xc(%ebp), %eax\n" /* line 2198 | value */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_0021785c, 8(%esp)\n" /* "%i" */
        "movl $0x20, 4(%esp)\n"
        "leal -0x38(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        /* { scope 2 */
        "movl $0, -0x58(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0x54(%ebp)\n"
        "movl -0x58(%ebp), %eax\n" /* line 1804 | dvarDomain */
        "movl -0x54(%ebp), %edx\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl $0x4000, %ecx\n"
        "movl $7, %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dvarDomain */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf555fe_000556a1:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf555fe_000556a8:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf555fe_000556a8\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf555fe_0005561f\n"
        /* } scope */
        /* } scope */
        ".Lf555fe_000556d0:\n"
        "testl %esi, %esi\n" /* line 2192 | var */
        "je .Lf555fe_00055647\n"
        /* { scope 2 */
        "movzbl 6(%esi), %eax\n" /* line 1874 | var */
        "subb $5, %al\n"
        "cmpb $1, %al\n"
        "jbe .Lf555fe_00055730\n"
        "movl 0xc(%ebp), %eax\n" /* line 1880 | value */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_0021785c, 8(%esp)\n" /* "%i" */
        "movl $0x20, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* dvarDomain */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1881 */
        ".Lf555fe_00055706:\n"
        "xorl %ecx, %ecx\n" /* line 1888 */
        "movl %esi, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dvarDomain */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf555fe_00055717:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf555fe_00055612\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf555fe_00055730:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1876 | value */
        "jmp .Lf555fe_00055706\n"
    );
}

/* line 2204 */
__attribute__((naked))
void Dvar_SetFloatByName(const char *dvarName, float value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2204 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf55736_00055845\n"
        ".Lf55736_0005574a:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf55736_000557ca\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf55736_00055753:\n"
        "movl dvarHashTable(, %eax, 4), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "je .Lf55736_0005577b\n"
        ".Lf55736_0005575e:\n"
        "movl (%esi), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf55736_000557f9\n"
        "movl 0x20(%esi), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "jne .Lf55736_0005575e\n"
        /* } scope */
        ".Lf55736_0005577b:\n"
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* line 2212 | value */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00217c20, (%esp)\n" /* "%g" */
        "calll va\n"
        /* { scope 1 */
        "movl $0, -0x38(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0x34(%ebp)\n"
        "movl -0x38(%ebp), %edx\n" /* line 1804 | dvarDomain */
        "movl -0x34(%ebp), %ecx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl $0x4000, %ecx\n"
        "movl $7, %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2213 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf55736_000557ca:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf55736_000557d1:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf55736_000557d1\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf55736_00055753\n"
        /* } scope */
        /* } scope */
        ".Lf55736_000557f9:\n"
        "testl %esi, %esi\n" /* line 2209 | var */
        "je .Lf55736_0005577b\n"
        /* { scope 1 */
        "cmpb $1, 6(%esi)\n" /* line 1905 | var */
        "jne .Lf55736_0005581b\n"
        "movl 0xc(%ebp), %edx\n" /* line 1907 | value */
        ".Lf55736_0005580a:\n"
        "xorl %ecx, %ecx\n" /* line 1919 */
        "movl %esi, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2213 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf55736_0005581b:\n"
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* line 1911 | value */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl $str_00217c20, 8(%esp)\n" /* "%g" */
        "movl $0x20, 4(%esp)\n"
        "leal -0x38(%ebp), %ebx\n" /* dvarDomain */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1912 */
        "jmp .Lf55736_0005580a\n"
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf55736_00055845:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf55736_0005574a\n"
    );
}

/* line 2216 */
__attribute__((naked))
void Dvar_SetVec2ByName(const char *dvarName, float x, float y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2216 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf5585e_0005599b\n"
        ".Lf5585e_00055872:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf5585e_00055901\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf5585e_0005587f:\n"
        "movl dvarHashTable(, %eax, 4), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "je .Lf5585e_000558a7\n"
        ".Lf5585e_0005588a:\n"
        "movl (%esi), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5585e_00055930\n"
        "movl 0x20(%esi), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "jne .Lf5585e_0005588a\n"
        /* } scope */
        ".Lf5585e_000558a7:\n"
        "cvtss2sd 0x10(%ebp), %xmm0\n" /* line 2224 | y */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* x */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00219530, (%esp)\n" /* "%g %g" */
        "calll va\n"
        /* { scope 1 */
        "movl $0, -0x20(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %edx\n" /* line 1804 | dvarDomain */
        "movl -0x1c(%ebp), %ecx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl $0x4000, %ecx\n"
        "movl $7, %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 2225 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf5585e_00055901:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf5585e_00055908:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf5585e_00055908\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf5585e_0005587f\n"
        /* } scope */
        /* } scope */
        ".Lf5585e_00055930:\n"
        "testl %esi, %esi\n" /* line 2221 | var */
        "je .Lf5585e_000558a7\n"
        /* { scope 1 */
        "cmpb $4, 6(%esi)\n" /* line 1937 | var */
        "jne .Lf5585e_00055966\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 30 | x */
        "movss %xmm0, -0x20(%ebp)\n" /* dvarDomain */
        "movss 0x10(%ebp), %xmm0\n" /* line 31 | y */
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x20(%ebp), %edx\n" /* line 1940 | dvarDomain */
        ".Lf5585e_00055955:\n"
        "xorl %ecx, %ecx\n" /* line 1952 */
        "movl %esi, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 2225 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5585e_00055966:\n"
        "cvtss2sd 0x10(%ebp), %xmm0\n" /* line 1944 | y */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* x */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl $str_00219530, 8(%esp)\n" /* "%g %g" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x60(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1945 */
        "jmp .Lf5585e_00055955\n"
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf5585e_0005599b:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf5585e_00055872\n"
    );
}

/* line 2228 */
__attribute__((naked))
void Dvar_SetVec3ByName(const char *dvarName, float x, float y, float z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2228 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf559b4_00055b1d\n"
        ".Lf559b4_000559cb:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf559b4_00055a68\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf559b4_000559d8:\n"
        "movl dvarHashTable(, %eax, 4), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "je .Lf559b4_00055a00\n"
        ".Lf559b4_000559e3:\n"
        "movl (%esi), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf559b4_00055a97\n"
        "movl 0x20(%esi), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "jne .Lf559b4_000559e3\n"
        /* } scope */
        ".Lf559b4_00055a00:\n"
        "cvtss2sd 0x14(%ebp), %xmm0\n" /* line 2236 | z */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0x10(%ebp), %xmm0\n" /* y */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* x */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00219538, (%esp)\n" /* "%g %g %g" */
        "calll va\n"
        /* { scope 1 */
        "movl $0, -0x24(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0x20(%ebp)\n"
        "movl -0x24(%ebp), %edx\n" /* line 1804 | dvarDomain */
        "movl -0x20(%ebp), %ecx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl $0x4000, %ecx\n"
        "movl $7, %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 2237 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf559b4_00055a68:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf559b4_00055a6f:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf559b4_00055a6f\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf559b4_000559d8\n"
        /* } scope */
        /* } scope */
        ".Lf559b4_00055a97:\n"
        "testl %esi, %esi\n" /* line 2233 | var */
        "je .Lf559b4_00055a00\n"
        /* { scope 1 */
        "cmpb $3, 6(%esi)\n" /* line 1970 | var */
        "jne .Lf559b4_00055ada\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 191 | x */
        "movss %xmm0, -0x24(%ebp)\n" /* dvarDomain */
        "movss 0x10(%ebp), %xmm0\n" /* line 192 | y */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 193 | z */
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %edx\n" /* line 1973 | dvarDomain */
        ".Lf559b4_00055ac6:\n"
        "xorl %ecx, %ecx\n" /* line 1985 */
        "movl %esi, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 2237 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf559b4_00055ada:\n"
        "cvtss2sd 0x14(%ebp), %xmm0\n" /* line 1977 | z */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd 0x10(%ebp), %xmm0\n" /* y */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* x */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl $str_00219538, 8(%esp)\n" /* "%g %g %g" */
        "movl $0x60, 4(%esp)\n"
        "leal -0x84(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 1978 */
        "jmp .Lf559b4_00055ac6\n"
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf559b4_00055b1d:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf559b4_000559cb\n"
    );
}

/* line 2240 */
__attribute__((naked))
void Dvar_SetVec4ByName(const char *dvarName, float x, float y, float z, float w)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2240 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf55b36_00055cbf\n"
        ".Lf55b36_00055b4d:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf55b36_00055bf5\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf55b36_00055b5a:\n"
        "movl dvarHashTable(, %eax, 4), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "je .Lf55b36_00055b82\n"
        ".Lf55b36_00055b65:\n"
        "movl (%esi), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf55b36_00055c24\n"
        "movl 0x20(%esi), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "jne .Lf55b36_00055b65\n"
        /* } scope */
        ".Lf55b36_00055b82:\n"
        "cvtss2sd 0x18(%ebp), %xmm0\n" /* line 2248 | w */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd 0x14(%ebp), %xmm0\n" /* z */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0x10(%ebp), %xmm0\n" /* y */
        "movsd %xmm0, 0xc(%esp)\n"
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* x */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00219544, (%esp)\n" /* "%g %g %g %g" */
        "calll va\n"
        /* { scope 1 */
        "movl $0, -0x28(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0x24(%ebp)\n"
        "movl -0x28(%ebp), %edx\n" /* line 1804 | dvarDomain */
        "movl -0x24(%ebp), %ecx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl $0x4000, %ecx\n"
        "movl $7, %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 2249 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf55b36_00055bf5:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf55b36_00055bfc:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf55b36_00055bfc\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf55b36_00055b5a\n"
        /* } scope */
        /* } scope */
        ".Lf55b36_00055c24:\n"
        "testl %esi, %esi\n" /* line 2245 | var */
        "je .Lf55b36_00055b82\n"
        /* { scope 1 */
        "cmpb $4, 6(%esi)\n" /* line 2003 | var */
        "jne .Lf55b36_00055c71\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 447 | x */
        "movss %xmm0, -0x28(%ebp)\n" /* dvarDomain */
        "movss 0x10(%ebp), %xmm0\n" /* line 448 | y */
        "movss %xmm0, -0x24(%ebp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 449 | z */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 450 | w */
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x28(%ebp), %edx\n" /* line 2006 | dvarDomain */
        ".Lf55b36_00055c5d:\n"
        "xorl %ecx, %ecx\n" /* line 2018 */
        "movl %esi, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 2249 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf55b36_00055c71:\n"
        "cvtss2sd 0x18(%ebp), %xmm0\n" /* line 2010 | w */
        "movsd %xmm0, 0x24(%esp)\n"
        "cvtss2sd 0x14(%ebp), %xmm0\n" /* z */
        "movsd %xmm0, 0x1c(%esp)\n"
        "cvtss2sd 0x10(%ebp), %xmm0\n" /* y */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 0xc(%ebp), %xmm0\n" /* x */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl $str_00219544, 8(%esp)\n" /* "%g %g %g %g" */
        "movl $0x80, 4(%esp)\n"
        "leal -0xa8(%ebp), %ebx\n" /* string */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, %edx\n" /* line 2011 */
        "jmp .Lf55b36_00055c5d\n"
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf55b36_00055cbf:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf55b36_00055b4d\n"
    );
}

/* line 2253 */
__attribute__((naked))
void Dvar_SetStringByName(const char *dvarName, const char *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2253 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1: domain */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf55cd8_00055e44\n"
        ".Lf55cd8_00055cef:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf55cd8_00055d6a\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf55cd8_00055cf8:\n"
        "movl dvarHashTable(, %eax, 4), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "je .Lf55cd8_00055d20\n"
        ".Lf55cd8_00055d03:\n"
        "movl (%esi), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf55cd8_00055d99\n"
        "movl 0x20(%esi), %esi\n" /* line 1054 | var */
        "testl %esi, %esi\n" /* var */
        "jne .Lf55cd8_00055d03\n"
        /* } scope */
        /* { scope 1: domain */
        ".Lf55cd8_00055d20:\n"
        "movl $0, -0x418(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0x414(%ebp)\n"
        "movl -0x418(%ebp), %eax\n" /* line 1804 | dvarDomain */
        "movl -0x414(%ebp), %edx\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "movl $0x4000, %ecx\n"
        "movl $7, %edx\n"
        "movl %edi, %eax\n" /* len */
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2262 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: domain */
        /* { scope 2 */
        ".Lf55cd8_00055d6a:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf55cd8_00055d71:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf55cd8_00055d71\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf55cd8_00055cf8\n"
        /* } scope */
        /* } scope */
        ".Lf55cd8_00055d99:\n"
        "testl %esi, %esi\n" /* line 2258 | var */
        "je .Lf55cd8_00055d20\n"
        /* { scope 1: domain */
        "cmpb $7, 6(%esi)\n" /* line 2036 | var */
        "je .Lf55cd8_00055ecd\n"
        "leal 0x14(%esi), %edx\n" /* line 2043 | var */
        "movl %edx, -0x420(%ebp)\n" /* domain */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x14(%esi), %eax\n" /* line 402 | hash */
        "movl %eax, -0x41c(%ebp)\n"
        "testl %eax, %eax\n"
        "jg .Lf55cd8_00055e8c\n"
        ".Lf55cd8_00055dc1:\n"
        "movl 0xc(%ebp), %eax\n" /* line 408 | value */
        "movzbl (%eax), %ecx\n"
        "testb %cl, %cl\n"
        "jne .Lf55cd8_00055e5d\n"
        "xorl %ebx, %ebx\n" /* stringIndex */
        ".Lf55cd8_00055dd1:\n"
        "cmpl %ebx, -0x41c(%ebp)\n" /* line 414 | stringIndex */
        "jg .Lf55cd8_00055e2e\n"
        ".Lf55cd8_00055dd9:\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* value, len */
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* len */
        "movl -0x420(%ebp), %edx\n" /* line 418 | domain */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf55cd8_00055e29\n"
        "xorl %ebx, %ebx\n" /* stringIndex */
        ".Lf55cd8_00055df9:\n"
        "movl %edi, 8(%esp)\n" /* line 420 | len */
        "movl -0x420(%ebp), %edx\n" /* domain */
        "movl 4(%edx), %eax\n"
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf55cd8_00055e2e\n"
        "addl $1, %ebx\n" /* line 418 | stringIndex */
        "movl -0x420(%ebp), %edx\n" /* domain */
        "cmpl (%edx), %ebx\n" /* stringIndex */
        "jl .Lf55cd8_00055df9\n"
        ".Lf55cd8_00055e29:\n"
        "movl $0xfffffac7, %ebx\n" /* stringIndex */
        /* } scope */
        /* } scope */
        ".Lf55cd8_00055e2e:\n"
        "movl %ebx, %edx\n" /* line 2043 | stringIndex */
        ".Lf55cd8_00055e30:\n"
        "xorl %ecx, %ecx\n" /* line 2051 */
        "movl %esi, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 2262 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: domain */
        /* { scope 2 */
        ".Lf55cd8_00055e44:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf55cd8_00055cef\n"
        /* } scope */
        /* } scope */
        /* { scope 1: domain */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf55cd8_00055e5d:\n"
        "leal -0x30(%ecx), %eax\n" /* line 410 */
        "cmpb $9, %al\n"
        "ja .Lf55cd8_00055e29\n"
        "movl 0xc(%ebp), %edi\n" /* value, len */
        "xorl %ebx, %ebx\n" /* stringIndex */
        ".Lf55cd8_00055e69:\n"
        "leal (%ebx, %ebx, 4), %edx\n" /* line 412 | stringIndex */
        "movsbl %cl, %eax\n"
        "leal -0x30(%eax, %edx, 2), %ebx\n" /* stringIndex */
        "movzbl 1(%edi), %ecx\n" /* line 408 | len */
        "testb %cl, %cl\n"
        "je .Lf55cd8_00055ef1\n"
        "addl $1, %edi\n" /* len */
        "leal -0x30(%ecx), %eax\n" /* line 410 */
        "cmpb $9, %al\n"
        "jbe .Lf55cd8_00055e69\n"
        "movl $0xfffffac7, %ebx\n" /* line 418 | stringIndex */
        "jmp .Lf55cd8_00055e2e\n"
        ".Lf55cd8_00055e8c:\n"
        "xorl %ebx, %ebx\n" /* line 402 | stringIndex */
        "jmp .Lf55cd8_00055ea9\n"
        ".Lf55cd8_00055e90:\n"
        "addl $1, %ebx\n" /* stringIndex */
        "movl -0x420(%ebp), %edx\n" /* domain */
        "movl (%edx), %edx\n"
        "movl %edx, -0x41c(%ebp)\n"
        "cmpl %edx, %ebx\n" /* stringIndex */
        "jge .Lf55cd8_00055dc1\n"
        ".Lf55cd8_00055ea9:\n"
        "movl -0x420(%ebp), %edx\n" /* line 404 | domain */
        "movl 4(%edx), %eax\n"
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf55cd8_00055e90\n"
        "jmp .Lf55cd8_00055e2e\n"
        /* } scope */
        /* } scope */
        ".Lf55cd8_00055ecd:\n"
        "movl $0x400, 8(%esp)\n" /* line 2038 */
        "movl 0xc(%ebp), %eax\n" /* value */
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* dvarDomain, stringIndex */
        "movl %ebx, (%esp)\n" /* stringIndex */
        "calll I_strncpyz\n"
        "movl %ebx, %edx\n" /* line 2039 | stringIndex */
        "jmp .Lf55cd8_00055e30\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf55cd8_00055ef1:\n"
        "testl %ebx, %ebx\n" /* line 414 | stringIndex */
        "js .Lf55cd8_00055dd9\n"
        "jmp .Lf55cd8_00055dd1\n"
    );
}

/* line 2265 */
__attribute__((naked))
void Dvar_SetColorByName(const char *dvarName, int r, int g, int b, int a)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2265 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        "movzbl 0xc(%ebp), %eax\n" /* r */
        "movb %al, -0x29(%ebp)\n" /* r */
        "movzbl 0x10(%ebp), %eax\n" /* g */
        "movb %al, -0x2a(%ebp)\n" /* g */
        "movzbl 0x14(%ebp), %eax\n" /* b */
        "movb %al, -0x2b(%ebp)\n" /* b */
        "movzbl 0x18(%ebp), %eax\n" /* a */
        "movb %al, -0x2c(%ebp)\n" /* a */
        /* { scope 1 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf55efe_0005604e\n"
        ".Lf55efe_00055f2e:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf55efe_00055fc7\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf55efe_00055f3b:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf55efe_00055f63\n"
        ".Lf55efe_00055f46:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf55efe_00055ff6\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf55efe_00055f46\n"
        /* } scope */
        ".Lf55efe_00055f63:\n"
        "movzbl -0x2c(%ebp), %eax\n" /* line 2273 | a */
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x2b(%ebp), %eax\n" /* b */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x2a(%ebp), %eax\n" /* g */
        "movl %eax, 8(%esp)\n"
        "movzbl -0x29(%ebp), %eax\n" /* r */
        "movl %eax, 4(%esp)\n"
        "movl $str_00219544, (%esp)\n" /* "%g %g %g %g" */
        "calll va\n"
        /* { scope 1 */
        "movl $0, -0x20(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %edx\n" /* line 1804 | dvarDomain */
        "movl -0x1c(%ebp), %ecx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl $0x4000, %ecx\n"
        "movl $7, %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_RegisterVariant\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 2274 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf55efe_00055fc7:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf55efe_00055fce:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf55efe_00055fce\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf55efe_00055f3b\n"
        /* } scope */
        /* } scope */
        ".Lf55efe_00055ff6:\n"
        "testl %ebx, %ebx\n" /* line 2270 | var */
        "je .Lf55efe_00055f63\n"
        "movl $0, 0x14(%esp)\n" /* line 2138 */
        "movzbl -0x2c(%ebp), %eax\n" /* a */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movzbl -0x2b(%ebp), %eax\n" /* b */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movzbl -0x2a(%ebp), %eax\n" /* g */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movzbl -0x29(%ebp), %eax\n" /* r */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* var */
        "calll Dvar_SetColorFromSource\n"
        "addl $0x4c, %esp\n" /* line 2274 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf55efe_0005604e:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf55efe_00055f2e\n"
    );
}

/* line 2277 */
__attribute__((naked))
const dvar_t * Dvar_SetFromStringByNameFromSource(const char *dvarName, const char *string, DvarSetSource source)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2277 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dvarName */
        /* { scope 1: dvarDomain */
        /* { scope 2 */
        /* { scope 3 */
        "testl %edi, %edi\n" /* line 68 */
        "je .Lf56068_00056131\n"
        ".Lf56068_0005607c:\n"
        "movzbl (%edi), %eax\n" /* line 74 */
        "testb %al, %al\n"
        "jne .Lf56068_000560c6\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf56068_00056085:\n"
        "movl dvarHashTable(, %eax, 4), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf56068_000560a9\n"
        ".Lf56068_00056090:\n"
        "movl (%ebx), %eax\n" /* line 1056 | var */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf56068_000560ab\n"
        "movl 0x20(%ebx), %ebx\n" /* line 1054 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf56068_00056090\n"
        ".Lf56068_000560a9:\n"
        "xorl %ebx, %ebx\n" /* var */
        /* } scope */
        ".Lf56068_000560ab:\n"
        "testl %ebx, %ebx\n" /* line 2282 | dvar */
        "je .Lf56068_000560f2\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2285 | source */
        "movl 0xc(%ebp), %edx\n" /* string */
        "movl %ebx, %eax\n" /* dvar */
        "calll Dvar_SetFromStringFromSource\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 2288 | dvar */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dvarDomain */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf56068_000560c6:\n"
        "xorl %esi, %esi\n" /* line 74 | hash */
        "movl $0x77, %ebx\n"
        ".Lf56068_000560cd:\n"
        "movsbl %al, %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %ebx, %eax\n" /* line 77 */
        "addl %eax, %esi\n" /* hash */
        "movzbl -0x76(%edi, %ebx), %eax\n" /* line 74 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf56068_000560cd\n"
        "movl %esi, %eax\n" /* hash */
        "andl $0xff, %eax\n"
        "jmp .Lf56068_00056085\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf56068_000560f2:\n"
        "movl $0, -0x20(%ebp)\n" /* line 1803 | dvarDomain */
        "movl $0, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 1804 | dvarDomain */
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "movl $0x4000, %ecx\n"
        "movl $7, %edx\n"
        "movl %edi, %eax\n"
        "calll Dvar_RegisterVariant\n"
        "movl %eax, %ebx\n" /* var */
        /* } scope */
        /* } scope */
        "movl %ebx, %eax\n" /* line 2288 | dvar */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dvarDomain */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf56068_00056131:\n"
        "movl $str_00219550, 4(%esp)\n" /* line 70 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf56068_0005607c\n"
    );
}

/* line 2303 */
__attribute__((naked))
void Dvar_SetCommand(const char *dvarName, const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2303 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $1, 8(%esp)\n" /* line 2307 */
        "movl 0xc(%ebp), %eax\n" /* string */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dvarName */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFromStringByNameFromSource\n"
        "testl %eax, %eax\n" /* line 2311 */
        "je .Lf5614a_00056177\n"
        "cmpb $0, isLoadingAutoExecGlobalFlag\n"
        "jne .Lf5614a_00056179\n"
        /* } scope */
        ".Lf5614a_00056177:\n"
        "leave\n" /* line 2316 */
        "retl\n"
        /* { scope 1 */
        ".Lf5614a_00056179:\n"
        "orw $0x8000, 4(%eax)\n" /* line 2323 */
        "movl 8(%eax), %edx\n" /* line 2314 */
        /* } scope */
        "leave\n" /* line 2316 */
        /* { scope 1 */
        "jmp Dvar_UpdateResetValue\n" /* line 2314 */
    );
}

/* line 2292 */
void Dvar_SetFromStringByName(const char *dvarName, const char *string)
{
    Dvar_SetFromStringByNameFromSource(dvarName, string, 0);
}

