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
/* Dvar type enumeration (from switch analysis, 0-8) */
enum {
    DVAR_TYPE_BOOL = 0,
    DVAR_TYPE_FLOAT = 1,
    DVAR_TYPE_VEC2 = 2,
    DVAR_TYPE_VEC3 = 3,
    DVAR_TYPE_VEC4 = 4,
    DVAR_TYPE_INT = 5,
    DVAR_TYPE_ENUM = 6,
    DVAR_TYPE_STRING = 7,
    DVAR_TYPE_COLOR = 8,
    DVAR_TYPE_COUNT = 9
};
enum {
    DVAR_FLAG_WRITEPROTECTED = 0x10,
    DVAR_FLAG_LATCH = 0x20,
    DVAR_FLAG_READONLY = 0x40,
    DVAR_FLAG_CHEAT = 0x80,
    DVAR_FLAG_EXTERNAL = 0x4000,
    DVAR_MAX_COUNT = 0x500,
    CON_CHANNEL_LOGFILEONLY = 4,
    DVAR_INVALID_ENUM_INDEX = -1337
};
static const char dvarDigitStrings[10][2]; /* dvarDigitStrings */
extern const char str_00219524[];
extern const char str_00219528[];
__attribute__((used, packed, aligned(4)))
UInt32 dvarOnOffStrings_storage[8] __asm__("dvarOnOffStrings") = {
    (UInt32)str_00219524,
    (UInt32)str_00219528,
    0, 0, 0, 0, 0, 0,
}; /* 0x30a3e0 */
#define dvarOnOffStrings ((const char **)dvarOnOffStrings_storage)
static Bool isDvarSystemActive; /* isDvarSystemActive */
static Bool isLoadingAutoExecGlobalFlag; /* isLoadingAutoExecGlobalFlag */

extern char *va(const char *format, ...);
extern int Com_sprintf(char *dest, int size, const char *fmt, ...);
extern byte *__DefaultRuneLocale;
extern int ___maskrune(int ch, unsigned int mask);
extern int ___tolower(int c);
extern void Com_BeginParseSession(const char *filename);
extern void Com_EndParseSession(void);
extern void Com_PrintMessage(int channel, const char *msg);
extern const char *Com_Parse(const char **data_p);
extern const char *Com_ParseOnLine(const char **data_p);
extern char *CopyStringInternal(const char *in);
extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void Com_SkipRestOfLine(const char **data);
extern void Dvar_AddCommands(void);
extern int I_stricmp(const char *s1, const char *s2);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void *Z_MallocInternal(int size);
extern void Z_FreeInternal(void *ptr);
extern int stricmp(const char *s1, const char *s2);
extern int strnicmp(const char *s1, const char *s2, int n);
extern int atoi(const char *string);
extern double atof(const char *string);
extern int strcmp(const char *s1, const char *s2);
extern int sscanf(const char *str, const char *format, ...);
extern float floorf(float x);

void Dvar_SetInAutoExec(int inAutoExec);
Bool Dvar_IsSystemActive(void);
Bool Dvar_IsValidName(const char *dvarName);
const char * Dvar_EnumToString(const dvar_t *dvar);
const char * __attribute_regparm__(2) Dvar_ValueToString(const dvar_t *dvar, DvarValue value);
static const char *Dvar_ValueToString_impl(const dvar_t *dvar, DvarValue value);
const char * Dvar_DisplayableValue(const dvar_t *dvar);
const char * Dvar_DisplayableResetValue(const dvar_t *dvar);
const char * Dvar_DisplayableLatchedValue(const dvar_t *dvar);
static Bool __attribute_regparm__(3) Dvar_ValuesEqual(int type, DvarValue val0, DvarValue val1);
Bool Dvar_HasLatchedValue(const dvar_t *dvar);
Bool Dvar_IsAtDefaultValue(const dvar_t *dvar);
void Dvar_ClearModified(const dvar_t *dvar);
void Dvar_SetModified(const dvar_t *dvar);
void Dvar_AddFlags(const dvar_t *dvar, int flags);
void Dvar_ResetScriptInfo(void);
const char * Dvar_IndexStringToEnumString(const dvar_t *dvar, const char *indexString);
static void __attribute_regparm__(2) Dvar_StringToColor(const char *string, byte color[4]);
static DvarValue Dvar_StringToValue_impl(int type, DvarLimits domain, const char *string);
static DvarValue __attribute_regparm__(3) Dvar_StringToValue(
    int type, uint32_t domainLo, uint32_t domainHi, const char *string);
void Dvar_GetUnpackedColor(const dvar_t *dvar, long unsigned int (*expandedColor)[16]);
static void __attribute_regparm__(2) Dvar_SetLatchedValue(const dvar_t *dvar, DvarValue value);
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
static const char *Dvar_DomainToString_Internal_impl(
    int type, DvarLimits domain, char *outBuffer, int outBufferLen, int *outLineCount);
static const char * __attribute_regparm__(3) Dvar_DomainToString_Internal(
    int type, uint32_t domainLo, uint32_t domainHi, char *outBuffer, int outBufferLen, int *outLineCount);
const char * Dvar_DomainToString_GetLines(int type, DvarLimits domain, char *outBuffer, int outBufferLen, int *outLineCount);
void Dvar_PrintDomain(int type, DvarLimits domain);
static void __attribute_regparm__(1) Dvar_PerformUnregistration(dvar_t *dvar);
void Dvar_UnregisterSystem(int sysFlag);
static void __attribute_regparm__(2) Dvar_UpdateResetValue(const dvar_t *dvar, DvarValue value);
static Bool Dvar_ValueInDomain(int type, DvarValue value, DvarLimits domain);
static DvarValue Dvar_ClampValueToDomain(int type, DvarValue value, DvarValue resetValue, DvarLimits domain);
static Bool Dvar_CanChangeValue(const dvar_t *dvar, DvarSetSource source);
static void Dvar_UpdateValue(dvar_t *dvar, DvarValue value);
static void __attribute_regparm__(3) Dvar_MakeExplicitType(
    dvar_t *dvar, const char *dvarName, int type, unsigned short flags, DvarValue resetValue, DvarLimits domain);
void Dvar_ChangeResetValue(const dvar_t *dvar, DvarValue value);
static void __attribute_regparm__(3) Dvar_SetVariant(
    const dvar_t *dvar, DvarValue value, DvarSetSource source);
void Dvar_SetCheatState(void);
void Dvar_Reset(const dvar_t *dvar, DvarSetSource setSource);
static void __attribute_regparm__(3) Dvar_SetFromStringFromSource(
    const dvar_t *dvar, const char *string, DvarSetSource source);
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

typedef const dvar_t *(__attribute_regparm__(3) *DvarRegisterVariantRegparmFn)(
    const char *dvarName, int type, unsigned int flags, DvarValue value, DvarLimits domain);
typedef void (__attribute_regparm__(3) *DvarSetVariantRegparmFn)(
    const dvar_t *dvar, DvarValue value, DvarSetSource source);
typedef void (__attribute_regparm__(3) *DvarSetFromStringFromSourceRegparmFn)(
    const dvar_t *dvar, const char *string, DvarSetSource source);
typedef void (__attribute_regparm__(2) *DvarUpdateResetValueRegparmFn)(
    const dvar_t *dvar, DvarValue value);
typedef void (__attribute_regparm__(1) *DvarPerformUnregistrationRegparmFn)(
    dvar_t *dvar);
typedef const char *(__attribute_regparm__(3) *DvarDomainToStringRegparmFn)(
    int type, uint32_t domainLo, uint32_t domainHi, char *outBuffer, int outBufferLen, int *outLineCount);
typedef DvarValue (__attribute_regparm__(3) *DvarStringToValueRegparmFn)(
    int type, uint32_t domainLo, uint32_t domainHi, const char *string);

static const dvar_t *Dvar_RegisterVariant_impl(
    const char *dvarName, int type, unsigned int flags, DvarValue value, DvarLimits domain);

static const dvar_t *Dvar_RegisterVariantReg(const char *dvarName, int type, unsigned int flags, DvarValue value, DvarLimits domain)
{
#ifndef __EMSCRIPTEN__
    return ((DvarRegisterVariantRegparmFn)Dvar_RegisterVariant)(dvarName, type, flags, value, domain);
#else
    return Dvar_RegisterVariant_impl(dvarName, type, flags, value, domain);
#endif
}

static void Dvar_SetVariantReg(const dvar_t *dvar, DvarValue value, DvarSetSource source)
{
    ((DvarSetVariantRegparmFn)Dvar_SetVariant)(dvar, value, source);
}

static void Dvar_SetFromStringFromSourceReg(const dvar_t *dvar, const char *string, DvarSetSource source)
{
    Dvar_SetFromStringFromSource(dvar, string, source);
}

static void Dvar_UpdateResetValueReg(const dvar_t *dvar, DvarValue value)
{
    Dvar_UpdateResetValue(dvar, value);
}

static void Dvar_PerformUnregistrationReg(dvar_t *dvar)
{
    Dvar_PerformUnregistration(dvar);
}

static const char *Dvar_DomainToString_InternalReg(int type, DvarLimits domain, char *outBuffer, int outBufferLen, int *outLineCount)
{
    return Dvar_DomainToString_Internal_impl(type, domain, outBuffer, outBufferLen, outLineCount);
}

static DvarValue Dvar_StringToValueReg(int type, DvarLimits domain, const char *string)
{
    return Dvar_StringToValue_impl(type, domain, string);
}

static unsigned int Dvar_GenerateHashValue(const char *name)
{
    unsigned int hash;
    int i;

    if (!name) {
        Com_Error(1, str_00219550);
        return 0;
    }

    hash = 0;
    for (i = 0; name[i]; ++i) {
        hash += (unsigned int)___tolower((unsigned char)name[i]) * (unsigned int)(i + 0x77);
    }

    return hash & 0xff;
}

static void Dvar_ClampVectorToDomain(vec_t *vector, int components, float min, float max)
{
    int i;

    for (i = 0; i < components; ++i) {
        if (vector[i] < min) {
            vector[i] = min;
        } else if (vector[i] > max) {
            vector[i] = max;
        }
    }
}

static byte Dvar_FloatToColorComponent(float value)
{
    if (!(value < 1.0f)) {
        value = 1.0f;
    } else if (value < 0.0f) {
        value = 0.0f;
    }

    return (byte)(int)floorf(value * 255.0f + 0.5f);
}

static Bool Dvar_StringEqualsRef(const char *value, const char *reference)
{
    if (!value || !reference) {
        return value == reference;
    }

    return value == reference || strcmp(value, reference) == 0;
}

static Bool Dvar_IsStaticValueString(const char *value)
{
    if (!value || !*value) {
        return 1;
    }

    if (!value[1] && value[0] >= '0' && value[0] <= '9') {
        return 1;
    }

    return value == dvarOnOffStrings[0] || value == dvarOnOffStrings[1];
}

static const char *Dvar_CanonicalizeValueString(const char *value)
{
    if (!value || !*value) {
        return "";
    }

    if (!value[1] && value[0] >= '0' && value[0] <= '9') {
        return dvarDigitStrings[value[0] - '0'];
    }

    if (value[0] == 'o') {
        if (!strcmp(value, "on")) {
            return dvarOnOffStrings[1];
        }
        if (!strcmp(value, "off")) {
            return dvarOnOffStrings[0];
        }
    }

    return CopyStringInternal(value);
}

static const char *Dvar_RebuildResetString(const dvar_t *dvar, const char *value)
{
    if (Dvar_StringEqualsRef(value, dvar->current.string)) {
        return dvar->current.string;
    }
    if (Dvar_StringEqualsRef(value, dvar->latched.string)) {
        return dvar->latched.string;
    }

    return Dvar_CanonicalizeValueString(value);
}

static const char *Dvar_RebuildStringValue(const char *value, const char *first, const char *second)
{
    if (Dvar_StringEqualsRef(value, first)) {
        return first;
    }
    if (Dvar_StringEqualsRef(value, second)) {
        return second;
    }

    return Dvar_CanonicalizeValueString(value);
}

static void Dvar_FreeOwnedString(const char *value, const char *keep0, const char *keep1)
{
    if (!value || value == keep0 || value == keep1 || Dvar_IsStaticValueString(value)) {
        return;
    }

    Z_FreeInternal((void *)value);
}

static Bool Dvar_VectorEqual(const vec_t *a, const vec_t *b, int count)
{
    int i;

    for (i = 0; i < count; ++i) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

static Bool Dvar_VectorInDomain(const vec_t *vector, int components, float min, float max)
{
    int i;

    for (i = 0; i < components; ++i) {
        if (vector[i] < min || vector[i] > max) {
            return 0;
        }
    }

    return 1;
}

static DvarLimits Dvar_UnpackLimits(uint32_t lo, uint32_t hi)
{
    union {
        DvarLimits domain;
        struct {
            uint32_t lo;
            uint32_t hi;
        } raw;
    } bits;

    bits.raw.lo = lo;
    bits.raw.hi = hi;
    return bits.domain;
}

static vec_t *Dvar_AllocTempVector(int components)
{
    vec_t *vector;
    int i;
    int index;

    index = dvarVectorIndex;
    if (index + components > 12) {
        index = 0;
    }

    dvarVectorIndex = index + components;
    vector = &dvarVectorPool[index];
    for (i = 0; i < components; ++i) {
        vector[i] = 0.0f;
    }

    return vector;
}

static int Dvar_StringToEnumIndex(DvarLimits domain, const char *string)
{
    int i;
    int index;
    int len;

    if (domain.enumeration.stringCount > 0) {
        for (i = 0; i < domain.enumeration.stringCount; ++i) {
            if (!stricmp(string, domain.enumeration.strings[i])) {
                return i;
            }
        }
    }

    if (!string[0]) {
        index = 0;
    } else {
        index = 0;
        for (i = 0; string[i]; ++i) {
            if (string[i] < '0' || string[i] > '9') {
                index = DVAR_INVALID_ENUM_INDEX;
                break;
            }

            index = index * 10 + (string[i] - '0');
        }
    }

    if (index >= 0 && index < domain.enumeration.stringCount) {
        return index;
    }

    len = 0;
    while (string[len]) {
        ++len;
    }

    for (i = 0; i < domain.enumeration.stringCount; ++i) {
        if (!strnicmp(string, domain.enumeration.strings[i], len)) {
            return i;
        }
    }

    return DVAR_INVALID_ENUM_INDEX;
}

static Bool Dvar_IsMinFloatDomain(float value)
{
    return value == -3.4028234663852886e+38f;
}

static Bool Dvar_IsMaxFloatDomain(float value)
{
    return value == 3.4028234663852886e+38f;
}

static void Dvar_AdvanceCursor(char **cursor, const char *end, int written)
{
    if (written < 0) {
        return;
    }

    *cursor += written;
    if (*cursor > end) {
        *cursor = (char *)end;
    }
}

static int Dvar_DescribeIntDomain(char *outBuffer, int outBufferLen, int min, int max)
{
    if (min == (-2147483647 - 1)) {
        if (max == 2147483647) {
            return snprintf(outBuffer, outBufferLen, "Domain is any integer");
        }

        return snprintf(outBuffer, outBufferLen, "Domain is any integer %i or smaller", max);
    }

    if (max == 2147483647) {
        return snprintf(outBuffer, outBufferLen, "Domain is any integer %i or bigger", min);
    }

    return snprintf(outBuffer, outBufferLen, "Domain is any integer from %i to %i", min, max);
}

static int Dvar_DescribeFloatDomain(char *outBuffer, int outBufferLen, float min, float max)
{
    if (Dvar_IsMinFloatDomain(min)) {
        if (Dvar_IsMaxFloatDomain(max)) {
            return snprintf(outBuffer, outBufferLen, "Domain is any number");
        }

        return snprintf(outBuffer, outBufferLen, "Domain is any number %g or smaller", max);
    }

    if (Dvar_IsMaxFloatDomain(max)) {
        return snprintf(outBuffer, outBufferLen, "Domain is any number %g or bigger", min);
    }

    return snprintf(outBuffer, outBufferLen, "Domain is any number from %g to %g", min, max);
}

static int Dvar_DescribeVectorDomain(char *outBuffer, int outBufferLen, int components, float min, float max)
{
    if (Dvar_IsMinFloatDomain(min)) {
        if (Dvar_IsMaxFloatDomain(max)) {
            return snprintf(outBuffer, outBufferLen, "Domain is any %iD vector", components);
        }

        return snprintf(
            outBuffer,
            outBufferLen,
            "Domain is any %iD vector with components %g or smaller",
            components,
            max);
    }

    if (Dvar_IsMaxFloatDomain(max)) {
        return snprintf(
            outBuffer,
            outBufferLen,
            "Domain is any %iD vector with components %g or bigger",
            components,
            min);
    }

    return snprintf(
        outBuffer,
        outBufferLen,
        "Domain is any %iD vector with components from %g to %g",
        components,
        min,
        max);
}

static Bool Dvar_ValueInDomain(int type, DvarValue value, DvarLimits domain)
{
    switch (type) {
    case DVAR_TYPE_BOOL:
        return 1;
    case DVAR_TYPE_FLOAT:
        return domain.value.min <= value.value && value.value <= domain.value.max;
    case DVAR_TYPE_VEC2:
        return Dvar_VectorInDomain(value.vector, 2, domain.vector.min, domain.vector.max);
    case DVAR_TYPE_VEC3:
        return Dvar_VectorInDomain(value.vector, 3, domain.vector.min, domain.vector.max);
    case DVAR_TYPE_VEC4:
        return Dvar_VectorInDomain(value.vector, 4, domain.vector.min, domain.vector.max);
    case DVAR_TYPE_INT:
        return domain.integer.min <= value.integer && value.integer <= domain.integer.max;
    case DVAR_TYPE_ENUM:
        return value.integer >= 0 &&
            (value.integer < domain.enumeration.stringCount || !value.integer);
    case DVAR_TYPE_STRING:
    case DVAR_TYPE_COLOR:
        return 1;
    default:
        return 0;
    }
}

static DvarValue Dvar_ClampValueToDomain(int type, DvarValue value, DvarValue resetValue, DvarLimits domain)
{
    switch (type) {
    case DVAR_TYPE_BOOL:
        value.enabled = value.enabled != 0;
        break;
    case DVAR_TYPE_FLOAT:
        if (value.value < domain.value.min) {
            value.value = domain.value.min;
        } else if (value.value > domain.value.max) {
            value.value = domain.value.max;
        }
        break;
    case DVAR_TYPE_VEC2:
        Dvar_ClampVectorToDomain(value.vector, 2, domain.vector.min, domain.vector.max);
        break;
    case DVAR_TYPE_VEC3:
        Dvar_ClampVectorToDomain(value.vector, 3, domain.vector.min, domain.vector.max);
        break;
    case DVAR_TYPE_VEC4:
        Dvar_ClampVectorToDomain(value.vector, 4, domain.vector.min, domain.vector.max);
        break;
    case DVAR_TYPE_INT:
        if (value.integer < domain.integer.min) {
            value.integer = domain.integer.min;
        } else if (value.integer > domain.integer.max) {
            value.integer = domain.integer.max;
        }
        break;
    case DVAR_TYPE_ENUM:
        if (value.integer < 0 || value.integer >= domain.enumeration.stringCount) {
            value.integer = resetValue.integer;
        }
        break;
    default:
        break;
    }

    return value;
}

static Bool Dvar_CanChangeValue(const dvar_t *dvar, DvarSetSource source)
{
    if (dvar->flags & DVAR_FLAG_READONLY) {
        Com_Printf("%s is read only.\n", dvar->name);
        return 0;
    }

    if (dvar->flags & DVAR_FLAG_WRITEPROTECTED) {
        Com_Printf("%s is write protected.\n", dvar->name);
        return 0;
    }

    if (source == DVAR_SOURCE_EXTERNAL &&
        (dvar->flags & DVAR_FLAG_CHEAT) &&
        dvar_cheats &&
        !dvar_cheats->current.enabled) {
        Com_Printf("%s is cheat protected.\n", dvar->name);
        return 0;
    }

    return 1;
}

static void Dvar_UpdateValue(dvar_t *dvar, DvarValue value)
{
    const char *oldCurrentString;
    const char *oldLatchedString;
    const char *oldResetString;
    Bool freeOldCurrentString;

    switch (dvar->type) {
    case DVAR_TYPE_VEC2:
        dvar->current.vector[0] = value.vector[0];
        dvar->current.vector[1] = value.vector[1];
        dvar->latched.vector[0] = value.vector[0];
        dvar->latched.vector[1] = value.vector[1];
        return;
    case DVAR_TYPE_VEC3:
        dvar->current.vector[0] = value.vector[0];
        dvar->current.vector[1] = value.vector[1];
        dvar->current.vector[2] = value.vector[2];
        dvar->latched.vector[0] = value.vector[0];
        dvar->latched.vector[1] = value.vector[1];
        dvar->latched.vector[2] = value.vector[2];
        return;
    case DVAR_TYPE_VEC4:
        dvar->current.vector[0] = value.vector[0];
        dvar->current.vector[1] = value.vector[1];
        dvar->current.vector[2] = value.vector[2];
        dvar->current.vector[3] = value.vector[3];
        dvar->latched.vector[0] = value.vector[0];
        dvar->latched.vector[1] = value.vector[1];
        dvar->latched.vector[2] = value.vector[2];
        dvar->latched.vector[3] = value.vector[3];
        return;
    case DVAR_TYPE_STRING:
        if (value.string == dvar->current.string) {
            return;
        }

        oldCurrentString = dvar->current.string;
        oldLatchedString = dvar->latched.string;
        oldResetString = dvar->reset.string;
        freeOldCurrentString =
            oldCurrentString &&
            oldCurrentString != oldLatchedString &&
            oldCurrentString != oldResetString &&
            !Dvar_IsStaticValueString(oldCurrentString);

        dvar->current.string =
            Dvar_RebuildStringValue(value.string, dvar->latched.string, dvar->reset.string);

        if (oldLatchedString != dvar->current.string &&
            oldLatchedString != oldResetString &&
            !Dvar_IsStaticValueString(oldLatchedString)) {
            Z_FreeInternal((void *)oldLatchedString);
        }

        dvar->latched.string = dvar->current.string;

        if (freeOldCurrentString) {
            Z_FreeInternal((void *)oldCurrentString);
        }
        return;
    default:
        dvar->current = value;
        dvar->latched = value;
        return;
    }
}

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
Bool Dvar_IsValidName(const char *dvarName)
{
    byte *runeLocale;
    const char *s;
    char ch;

    if (!dvarName) {
        return 0;
    }

    runeLocale = *(byte **)&__DefaultRuneLocale;
    s = dvarName;
    ch = *s;

    while (ch) {
        int isAlnum;
        int sch;

        sch = (signed char)ch;
        if (sch & ~0x7f) {
            isAlnum = ___maskrune(sch, 0x500) != 0;
        } else {
            isAlnum = (*(int *)(runeLocale + 0x34 + sch * 4) & 0x500) != 0;
        }

        if (!isAlnum && ch != '_') {
            return 0;
        }

        ++s;
        ch = *s;
    }

    return 1;
}

/* line 247 */
const char * Dvar_EnumToString(const dvar_t *dvar)
{
    if (!dvar->domain.enumeration.stringCount)
        return "";
    return dvar->domain.enumeration.strings[dvar->current.integer];
}

/* C implementation of Dvar_ValueToString
 * Original used register CC: dvar in %eax, value (raw bits) in %edx.
 * Converted to standard args. Naked wrapper below preserves register CC ABI
 * for other naked callers within this file. */
static const char *Dvar_ValueToString_impl(const dvar_t *dvar, DvarValue value)
{
    switch (dvar->type) {
    case DVAR_TYPE_BOOL:
        return value.enabled ? "1" : "0";
    case DVAR_TYPE_FLOAT:
        return va("%g", value.value);
    case DVAR_TYPE_VEC2:
        return va("%g %g", value.vector[0], value.vector[1]);
    case DVAR_TYPE_VEC3:
        return va("%g %g %g", value.vector[0], value.vector[1], value.vector[2]);
    case DVAR_TYPE_VEC4:
        return va("%g %g %g %g", value.vector[0], value.vector[1], value.vector[2], value.vector[3]);
    case DVAR_TYPE_INT:
        return va("%i", value.integer);
    case DVAR_TYPE_ENUM:
        if (dvar->domain.enumeration.stringCount) {
            return dvar->domain.enumeration.strings[value.integer];
        }
        return "";
    case DVAR_TYPE_STRING:
        return va("%s", value.string);
    case DVAR_TYPE_COLOR:
        return va("%g %g %g %g",
            (float)value.color[0] * (1.0f / 255.0f),
            (float)value.color[1] * (1.0f / 255.0f),
            (float)value.color[2] * (1.0f / 255.0f),
            (float)value.color[3] * (1.0f / 255.0f));
    default:
        return "";
    }
}

/* Register CC ABI: dvar in %eax, value in %edx, returns in %eax */
const char * __attribute_regparm__(2) Dvar_ValueToString(const dvar_t *dvar, DvarValue value)
{
    return Dvar_ValueToString_impl(dvar, value);
}

/* line 496 */
const char * Dvar_DisplayableValue(const dvar_t *dvar)
{
    return Dvar_ValueToString_impl(dvar, dvar->current);
}

/* line 516 */
const char * Dvar_DisplayableResetValue(const dvar_t *dvar)
{
    return Dvar_ValueToString_impl(dvar, dvar->reset);
}

/* line 536 */
const char * Dvar_DisplayableLatchedValue(const dvar_t *dvar)
{
    return Dvar_ValueToString_impl(dvar, dvar->latched);
}

/* line 838 */
static Bool __attribute_regparm__(3) Dvar_ValuesEqual(int type, DvarValue val0, DvarValue val1)
{
    switch (type) {
    case DVAR_TYPE_BOOL:
        return val0.enabled == val1.enabled;
    case DVAR_TYPE_FLOAT:
        return val0.value == val1.value;
    case DVAR_TYPE_VEC2:
        return Dvar_VectorEqual(val0.vector, val1.vector, 2);
    case DVAR_TYPE_VEC3:
        return Dvar_VectorEqual(val0.vector, val1.vector, 3);
    case DVAR_TYPE_VEC4:
        return Dvar_VectorEqual(val0.vector, val1.vector, 4);
    case DVAR_TYPE_INT:
    case DVAR_TYPE_ENUM:
    case DVAR_TYPE_COLOR:
        return val0.integer == val1.integer;
    case DVAR_TYPE_STRING:
        return strcmp(val0.string, val1.string) == 0;
    default:
        return 0;
    }
}

/* line 908 */
Bool Dvar_HasLatchedValue(const dvar_t *dvar)
{
    return !Dvar_ValuesEqual(dvar->type, dvar->current, dvar->latched);
}

/* line 914 */
Bool Dvar_IsAtDefaultValue(const dvar_t *dvar)
{
    return Dvar_ValuesEqual(dvar->type, dvar->current, dvar->reset);
}

/* line 1078 */
void Dvar_ClearModified(const dvar_t *dvar)
{
    ((dvar_t *)dvar)->modified = 0;
}

/* line 1085 */
void Dvar_SetModified(const dvar_t *dvar)
{
    ((dvar_t *)dvar)->modified = 1;
}

/* line 2319 */
void Dvar_AddFlags(const dvar_t *dvar, int flags)
{
    ((dvar_t *)dvar)->flags |= (unsigned short)flags;
}

/* line 2388 */
void Dvar_ResetScriptInfo(void)
{
    dvar_t *dvar = dvarPool;
    while (dvar) {
        dvar->flags &= ~0x0400;
        dvar = (dvar_t *)(uintptr_t)dvar->next;
    }
}

/* line 260 */
const char * Dvar_IndexStringToEnumString(const dvar_t *dvar, const char *indexString)
{
    int i;

    if (!dvar->domain.enumeration.stringCount) {
        return "";
    }

    for (i = 0; indexString[i]; ++i) {
        if (indexString[i] < '0' || indexString[i] > '9') {
            return "";
        }
    }

    return dvar->domain.enumeration.strings[atoi(indexString)];
}

/* line 428 */
static void __attribute_regparm__(2) Dvar_StringToColor(const char *string, byte color[4])
{
    float colorVec[4];

    colorVec[0] = 0.0f;
    colorVec[1] = 0.0f;
    colorVec[2] = 0.0f;
    colorVec[3] = 0.0f;
    sscanf(string, "%g %g %g %g", &colorVec[0], &colorVec[1], &colorVec[2], &colorVec[3]);

    color[0] = Dvar_FloatToColorComponent(colorVec[0]);
    color[1] = Dvar_FloatToColorComponent(colorVec[1]);
    color[2] = Dvar_FloatToColorComponent(colorVec[2]);
    color[3] = Dvar_FloatToColorComponent(colorVec[3]);
}

/* line 441 */
static DvarValue Dvar_StringToValue_impl(int type, DvarLimits domain, const char *string)
{
    DvarValue value;

    value.integer = 0;

    switch (type) {
    case DVAR_TYPE_BOOL:
        value.enabled = atoi(string) != 0;
        break;
    case DVAR_TYPE_FLOAT:
        value.value = (float)atof(string);
        break;
    case DVAR_TYPE_VEC2:
        value.vector = Dvar_AllocTempVector(2);
        sscanf(string, "%g %g", &value.vector[0], &value.vector[1]);
        break;
    case DVAR_TYPE_VEC3:
        value.vector = Dvar_AllocTempVector(3);
        sscanf(string, "%g %g %g", &value.vector[0], &value.vector[1], &value.vector[2]);
        break;
    case DVAR_TYPE_VEC4:
        value.vector = Dvar_AllocTempVector(4);
        sscanf(string, "%g %g %g %g", &value.vector[0], &value.vector[1], &value.vector[2], &value.vector[3]);
        break;
    case DVAR_TYPE_INT:
        value.integer = atoi(string);
        break;
    case DVAR_TYPE_ENUM:
        value.integer = Dvar_StringToEnumIndex(domain, string);
        break;
    case DVAR_TYPE_STRING:
        value.string = string;
        break;
    case DVAR_TYPE_COLOR:
        Dvar_StringToColor(string, value.color);
        break;
    default:
        value.integer = 0;
        break;
    }

    return value;
}

static DvarValue __attribute_regparm__(3) Dvar_StringToValue(
    int type, uint32_t domainLo, uint32_t domainHi, const char *string)
{
    return Dvar_StringToValue_impl(type, Dvar_UnpackLimits(domainLo, domainHi), string);
}

/* line 1249 */
void Dvar_GetUnpackedColor(const dvar_t *dvar, long unsigned int (*expandedColor)[16])
{
    byte color[4];
    float *expanded;

    if (dvar->type == DVAR_TYPE_COLOR) {
        color[0] = dvar->current.color[0];
        color[1] = dvar->current.color[1];
        color[2] = dvar->current.color[2];
        color[3] = dvar->current.color[3];
    } else {
        Dvar_StringToColor(dvar->current.string, color);
    }

    expanded = (float *)expandedColor;
    expanded[0] = (float)color[0] * (1.0f / 255.0f);
    expanded[1] = (float)color[1] * (1.0f / 255.0f);
    expanded[2] = (float)color[2] * (1.0f / 255.0f);
    expanded[3] = (float)color[3] * (1.0f / 255.0f);
}

/* line 879 */
static void __attribute_regparm__(2) Dvar_SetLatchedValue(const dvar_t *dvar, DvarValue value)
{
    dvar_t *mutableDvar;

    mutableDvar = (dvar_t *)dvar;

    switch (dvar->type) {
    case DVAR_TYPE_VEC2:
        mutableDvar->latched.vector[0] = value.vector[0];
        mutableDvar->latched.vector[1] = value.vector[1];
        return;
    case DVAR_TYPE_VEC3:
        mutableDvar->latched.vector[0] = value.vector[0];
        mutableDvar->latched.vector[1] = value.vector[1];
        mutableDvar->latched.vector[2] = value.vector[2];
        return;
    case DVAR_TYPE_VEC4:
        mutableDvar->latched.vector[0] = value.vector[0];
        mutableDvar->latched.vector[1] = value.vector[1];
        mutableDvar->latched.vector[2] = value.vector[2];
        mutableDvar->latched.vector[3] = value.vector[3];
        return;
    case DVAR_TYPE_STRING:
        Dvar_FreeOwnedString(dvar->latched.string, dvar->current.string, dvar->reset.string);
        mutableDvar->latched.string =
            Dvar_RebuildStringValue(value.string, dvar->current.string, dvar->reset.string);
        return;
    default:
        mutableDvar->latched = value;
        return;
    }
}

/* line 1279 */
void Dvar_Shutdown(void)
{
    dvar_t *dvar;

    for (dvar = sortedDvars; dvar; dvar = (dvar_t *)dvar->next) {
        if (dvar->type == DVAR_TYPE_STRING) {
            Dvar_FreeOwnedString(dvar->current.string, dvar->latched.string, dvar->reset.string);
            ((dvar_t *)dvar)->current.string = NULL;

            Dvar_FreeOwnedString(dvar->reset.string, dvar->latched.string, NULL);
            ((dvar_t *)dvar)->reset.string = NULL;

            Dvar_FreeOwnedString(dvar->latched.string, NULL, NULL);
            ((dvar_t *)dvar)->latched.string = NULL;
        } else if (dvar->type >= DVAR_TYPE_VEC2 && dvar->type <= DVAR_TYPE_VEC4) {
            Z_FreeInternal(dvar->current.vector);
        }

        if (dvar->flags & 0x4000) {
            Z_FreeInternal((void *)dvar->name);
        }
    }

    dvarCount = 0;
    sortedDvars = NULL;
    dvar_cheats = NULL;
    dvar_modifiedFlags = 0;
    isDvarSystemActive = 0;
    memset(dvarHashTable, 0, sizeof(dvarHashTable));
}

/* line 2406 */
Bool Dvar_AnyLatchedValues(void)
{
    dvar_t *dvar;

    for (dvar = sortedDvars; dvar; dvar = (dvar_t *)dvar->next) {
        if (!Dvar_ValuesEqual(dvar->type, dvar->current, dvar->latched)) {
            return 1;
        }
    }

    return 0;
}

/* line 2542 */
qboolean Com_SaveDvarsToBuffer(const char * *dvarnames, int numDvars, char *buffer, int bufsize)
{
    int i;

    for (i = 0; i < numDvars; ++i) {
        const dvar_t *var;
        const char *valueString;
        int len;

        var = Dvar_FindVar(dvarnames[i]);
        valueString = Dvar_ValueToString_impl(var, var->current);
        len = snprintf(buffer, bufsize, "%s \"%s\"\n", var->name, valueString);
        if (len < 0) {
            return 0;
        }

        buffer += len;
        bufsize -= len;
    }

    return 1;
}

/* line 1267 */
void Dvar_GetUnpackedColorByName(const char *dvarName, long unsigned int (*expandedColor)[16])
{
    const dvar_t *var;

    var = Dvar_FindVar(dvarName);
    if (!var) {
        const float *white = (const float *)imp_colorWhite;
        float *color = (float *)expandedColor;

        color[0] = white[0];
        color[1] = white[1];
        color[2] = white[2];
        color[3] = white[3];
        return;
    }

    Dvar_GetUnpackedColor(var, expandedColor);
}

/* line 1226 */
const char * Dvar_GetVariantString(const char *dvarName)
{
    const dvar_t *var;

    var = Dvar_FindVar(dvarName);
    if (!var) {
        return "";
    }

    return Dvar_ValueToString_impl(var, var->current);
}

/* line 1211 */
const char * Dvar_GetString(const char *dvarName)
{
    const dvar_t *var;

    var = Dvar_FindVar(dvarName);
    if (!var) {
        return "";
    }

    if (var->type == DVAR_TYPE_ENUM) {
        return Dvar_EnumToString(var);
    }

    return var->current.string;
}

/* line 1147 */
float Dvar_GetFloat(const char *dvarName)
{
    const dvar_t *var;

    var = Dvar_FindVar(dvarName);
    if (!var) {
        return 0.0f;
    }

    if (var->type == DVAR_TYPE_FLOAT) {
        return var->current.value;
    }

    return (float)atof(var->current.string);
}

/* line 1131 */
int Dvar_GetInt(const char *dvarName)
{
    const dvar_t *var;

    var = Dvar_FindVar(dvarName);
    if (!var) {
        return 0;
    }

    if (var->type == DVAR_TYPE_INT || var->type == DVAR_TYPE_ENUM) {
        return var->current.integer;
    }

    return atoi(var->current.string);
}

/* line 1115 */
Bool Dvar_GetBool(const char *dvarName)
{
    const dvar_t *var;

    var = Dvar_FindVar(dvarName);
    if (!var) {
        return 0;
    }

    if (var->type == DVAR_TYPE_BOOL) {
        return var->current.enabled;
    }

    return atoi(var->current.string) != 0;
}

/* line 1072 */
const dvar_t * Dvar_FindVar(const char *dvarName)
{
    dvar_t *var;

    for (var = dvarHashTable[Dvar_GenerateHashValue(dvarName)]; var; var = (dvar_t *)var->hashNext) {
        if (!I_stricmp(dvarName, var->name)) {
            return var;
        }
    }

    return 0;
}

/* line 1092 */
void Dvar_UpdateEnumDomain(const dvar_t *dvar, const char * *stringTable)
{
    dvar_t *mutableDvar;
    DvarValue value;
    int stringCount;

    stringCount = 0;
    if (stringTable) {
        while (stringTable[stringCount]) {
            ++stringCount;
        }
    }

    mutableDvar = (dvar_t *)dvar;
    mutableDvar->domain.enumeration.stringCount = stringCount;
    mutableDvar->domain.enumeration.strings = stringTable;

    value = mutableDvar->current;
    switch (mutableDvar->type) {
    case DVAR_TYPE_BOOL:
        value.enabled = value.enabled != 0;
        break;
    case DVAR_TYPE_FLOAT:
        if (value.value < mutableDvar->domain.value.min) {
            value.value = mutableDvar->domain.value.min;
        } else if (value.value > mutableDvar->domain.value.max) {
            value.value = mutableDvar->domain.value.max;
        }
        break;
    case DVAR_TYPE_VEC2:
        Dvar_ClampVectorToDomain(value.vector, 2, mutableDvar->domain.vector.min, mutableDvar->domain.vector.max);
        break;
    case DVAR_TYPE_VEC3:
        Dvar_ClampVectorToDomain(value.vector, 3, mutableDvar->domain.vector.min, mutableDvar->domain.vector.max);
        break;
    case DVAR_TYPE_VEC4:
        Dvar_ClampVectorToDomain(value.vector, 4, mutableDvar->domain.vector.min, mutableDvar->domain.vector.max);
        break;
    case DVAR_TYPE_INT:
        if (value.integer < mutableDvar->domain.integer.min) {
            value.integer = mutableDvar->domain.integer.min;
        } else if (value.integer > mutableDvar->domain.integer.max) {
            value.integer = mutableDvar->domain.integer.max;
        }
        break;
    case DVAR_TYPE_ENUM:
        if (value.integer < 0 || value.integer >= mutableDvar->domain.enumeration.stringCount) {
            value.integer = mutableDvar->reset.integer;
        }
        break;
    default:
        break;
    }

    mutableDvar->current = value;
    mutableDvar->latched = value;
}

/* line 716 */
static const char *Dvar_DomainToString_Internal_impl(
    int type, DvarLimits domain, char *outBuffer, int outBufferLen, int *outLineCount)
{
    char *cursor;
    char *outBufferEnd;
    int i;
    int len;

    if (outLineCount) {
        *outLineCount = 0;
    }

    if (outBufferLen <= 0) {
        return outBuffer;
    }

    cursor = outBuffer;
    outBufferEnd = outBuffer + outBufferLen;

    switch (type) {
    case DVAR_TYPE_BOOL:
        snprintf(outBuffer, outBufferLen, "Domain is 0 or 1");
        break;
    case DVAR_TYPE_FLOAT:
        Dvar_DescribeFloatDomain(outBuffer, outBufferLen, domain.value.min, domain.value.max);
        break;
    case DVAR_TYPE_VEC2:
        Dvar_DescribeVectorDomain(outBuffer, outBufferLen, 2, domain.vector.min, domain.vector.max);
        break;
    case DVAR_TYPE_VEC3:
        Dvar_DescribeVectorDomain(outBuffer, outBufferLen, 3, domain.vector.min, domain.vector.max);
        break;
    case DVAR_TYPE_VEC4:
        Dvar_DescribeVectorDomain(outBuffer, outBufferLen, 4, domain.vector.min, domain.vector.max);
        break;
    case DVAR_TYPE_INT:
        Dvar_DescribeIntDomain(outBuffer, outBufferLen, domain.integer.min, domain.integer.max);
        break;
    case DVAR_TYPE_ENUM:
        len = snprintf(cursor, outBufferLen, "Domain is one of the following:");
        Dvar_AdvanceCursor(&cursor, outBufferEnd, len);
        for (i = 0; i < domain.enumeration.stringCount; ++i) {
            len = snprintf(cursor, cursor < outBufferEnd ? (int)(outBufferEnd - cursor) : 0, "\n  %2i: %s", i, domain.enumeration.strings[i]);
            if (len < 0) {
                break;
            }
            if (outLineCount) {
                ++*outLineCount;
            }
            Dvar_AdvanceCursor(&cursor, outBufferEnd, len);
        }
        break;
    case DVAR_TYPE_STRING:
        snprintf(outBuffer, outBufferLen, "Domain is any text");
        break;
    case DVAR_TYPE_COLOR:
        snprintf(outBuffer, outBufferLen, "Domain is any 4-component color, in RGBA format");
        break;
    default:
        outBuffer[0] = '\0';
        break;
    }

    outBufferEnd[-1] = '\0';
    return outBuffer;
}

static const char * __attribute_regparm__(3) Dvar_DomainToString_Internal(
    int type, uint32_t domainLo, uint32_t domainHi, char *outBuffer, int outBufferLen, int *outLineCount)
{
    return Dvar_DomainToString_Internal_impl(
        type,
        Dvar_UnpackLimits(domainLo, domainHi),
        outBuffer,
        outBufferLen,
        outLineCount);
}

/* line 824 */
const char * Dvar_DomainToString_GetLines(int type, DvarLimits domain, char *outBuffer, int outBufferLen, int *outLineCount)
{
    return Dvar_DomainToString_InternalReg(type, domain, outBuffer, outBufferLen, outLineCount);
}

/* line 831 */
void Dvar_PrintDomain(int type, DvarLimits domain)
{
    char domainBuffer[0x400];

    Com_Printf("  %s\n", Dvar_DomainToString_InternalReg(type, domain, domainBuffer, sizeof(domainBuffer), NULL));
}

/* line 1310 */
static void __attribute_regparm__(1) Dvar_PerformUnregistration(dvar_t *dvar)
{
    vec_t *vectorMem;
    const char *valueString;

    if (!(dvar->flags & 0x4000)) {
        dvar->flags |= 0x4000;
        dvar->name = CopyStringInternal(dvar->name);
    }

    if (dvar->type == DVAR_TYPE_STRING) {
        return;
    }

    vectorMem = NULL;
    if (dvar->type >= DVAR_TYPE_VEC2 && dvar->type <= DVAR_TYPE_VEC4) {
        vectorMem = dvar->current.vector;
    }

    valueString = Dvar_ValueToString_impl(dvar, dvar->latched);
    ((dvar_t *)dvar)->current.string = Dvar_CanonicalizeValueString(valueString);
    ((dvar_t *)dvar)->latched.string = dvar->current.string;

    valueString = Dvar_ValueToString_impl(dvar, dvar->reset);
    ((dvar_t *)dvar)->reset.string = Dvar_RebuildResetString(dvar, valueString);
    ((dvar_t *)dvar)->type = DVAR_TYPE_STRING;

    if (vectorMem) {
        Z_FreeInternal(vectorMem);
    }
}

/* line 1364 */
void Dvar_UnregisterSystem(int sysFlag)
{
    dvar_t *dvar;
    unsigned short remainingFlags;

    for (dvar = sortedDvars; dvar; dvar = (dvar_t *)dvar->next) {
        if (!(dvar->flags & sysFlag) || (dvar->flags & 0x4000)) {
            continue;
        }

        dvar->flags &= (unsigned short)~sysFlag;
        remainingFlags = dvar->flags;
        if (!(remainingFlags & 0x7000)) {
            Dvar_PerformUnregistrationReg(dvar);
        }
    }
}

/* line 1377 */
static void __attribute_regparm__(2) Dvar_UpdateResetValue(const dvar_t *dvar, DvarValue value)
{
    dvar_t *mutableDvar;
    const char *oldResetString;

    mutableDvar = (dvar_t *)dvar;

    switch (dvar->type) {
    case DVAR_TYPE_VEC2:
        mutableDvar->reset.vector[0] = value.vector[0];
        mutableDvar->reset.vector[1] = value.vector[1];
        return;
    case DVAR_TYPE_VEC3:
        mutableDvar->reset.vector[0] = value.vector[0];
        mutableDvar->reset.vector[1] = value.vector[1];
        mutableDvar->reset.vector[2] = value.vector[2];
        return;
    case DVAR_TYPE_VEC4:
        mutableDvar->reset.vector[0] = value.vector[0];
        mutableDvar->reset.vector[1] = value.vector[1];
        mutableDvar->reset.vector[2] = value.vector[2];
        mutableDvar->reset.vector[3] = value.vector[3];
        return;
    case DVAR_TYPE_STRING:
        oldResetString = dvar->reset.string;
        if (oldResetString != dvar->current.string &&
            oldResetString != dvar->latched.string &&
            !Dvar_IsStaticValueString(oldResetString)) {
            Z_FreeInternal((void *)oldResetString);
        }

        mutableDvar->reset.string = Dvar_RebuildResetString(dvar, value.string);
        return;
    default:
        mutableDvar->reset = value;
        return;
    }
}

/* line 1452 */
static void __attribute_regparm__(3) Dvar_MakeExplicitType(
    dvar_t *dvar, const char *dvarName, int type, unsigned short flags, DvarValue resetValue, DvarLimits domain)
{
    DvarValue castValue;
    const char *oldCurrentString;
    const char *oldLatchedString;
    const char *oldResetString;
    const char *tempString;
    vec_t *vectorStorage;
    int components;

    dvar->type = (byte)type;
    dvar->domain = domain;

    if ((flags & DVAR_FLAG_READONLY) ||
        ((flags & DVAR_FLAG_CHEAT) && dvar_cheats && !dvar_cheats->current.enabled)) {
        castValue = resetValue;
    } else {
        castValue = Dvar_StringToValue_impl(dvar->type, dvar->domain, dvar->current.string);
        castValue = Dvar_ClampValueToDomain(type, castValue, resetValue, domain);
    }

    tempString = NULL;
    if (dvar->type == DVAR_TYPE_STRING && castValue.string) {
        tempString = CopyStringInternal(castValue.string);
        castValue.string = tempString;
    }

    oldCurrentString = dvar->current.string;
    oldLatchedString = dvar->latched.string;
    oldResetString = dvar->reset.string;

    if (dvar->type != DVAR_TYPE_STRING) {
        Dvar_FreeOwnedString(oldCurrentString, oldLatchedString, oldResetString);
        dvar->current.string = NULL;
    }

    Dvar_FreeOwnedString(oldLatchedString, oldCurrentString, oldResetString);
    dvar->latched.string = NULL;

    Dvar_FreeOwnedString(oldResetString, oldCurrentString, oldLatchedString);
    dvar->reset.string = NULL;

    if (dvar->type >= DVAR_TYPE_VEC2 && dvar->type <= DVAR_TYPE_VEC4) {
        components = dvar->type;
        vectorStorage = (vec_t *)Z_MallocInternal(components * 3 * sizeof(vec_t));
        dvar->current.vector = vectorStorage;
        dvar->latched.vector = vectorStorage + components;
        dvar->reset.vector = vectorStorage + components * 2;
    }

    Dvar_UpdateResetValue(dvar, resetValue);
    Dvar_UpdateValue(dvar, castValue);
    dvar_modifiedFlags |= flags;

    if (tempString) {
        Z_FreeInternal((void *)tempString);
    }

    (void)dvarName;
}

/* line 1406 */
void Dvar_ChangeResetValue(const dvar_t *dvar, DvarValue value)
{
    Dvar_UpdateResetValueReg(dvar, value);
}

/* line 925 */
static void __attribute_regparm__(3) Dvar_SetVariant(
    const dvar_t *dvarConst, DvarValue value, DvarSetSource source)
{
    dvar_t *dvar;
    char domainBuffer[0x400];

    dvar = (dvar_t *)dvarConst;
    if (!dvar || !dvar->name || !dvar->name[0]) {
        return;
    }

    Com_PrintMessage(
        CON_CHANNEL_LOGFILEONLY,
        va("      dvar set %s %s\n", dvar->name, Dvar_ValueToString_impl(dvar, value)));

    if (!Dvar_ValueInDomain(dvar->type, value, dvar->domain)) {
        Com_Printf("'%s' is not a valid value for dvar '%s'\n", Dvar_ValueToString_impl(dvar, value), dvar->name);
        Com_Printf(
            "  %s\n",
            Dvar_DomainToString_Internal_impl(
                dvar->type,
                dvar->domain,
                domainBuffer,
                sizeof(domainBuffer),
                NULL));

        if (dvar->type == DVAR_TYPE_ENUM) {
            Dvar_SetVariant(dvar, dvar->reset, source);
        }
        return;
    }

    if (source == DVAR_SOURCE_EXTERNAL || source == DVAR_SOURCE_SCRIPT) {
        if (!Dvar_CanChangeValue(dvar, source)) {
            return;
        }

        if (dvar->flags & DVAR_FLAG_LATCH) {
            Dvar_SetLatchedValue(dvar, value);
            if (!Dvar_ValuesEqual(dvar->type, dvar->latched, dvar->current)) {
                Com_Printf("%s will be changed upon restarting.\n", dvar->name);
            }
            return;
        }
    }

    if (Dvar_ValuesEqual(dvar->type, dvar->current, value)) {
        Dvar_SetLatchedValue(dvar, dvar->current);
        return;
    }

    dvar_modifiedFlags |= dvar->flags;
    Dvar_UpdateValue(dvar, value);
    dvar->modified = 1;
}

/* line 2350 */
void Dvar_SetCheatState(void)
{
    dvar_t *var;

    for (var = sortedDvars; var; var = (dvar_t *)var->next) {
        if (var->flags & 0x80) {
            Dvar_SetVariantReg(var, var->reset, DVAR_SOURCE_INTERNAL);
        }
    }
}

/* line 2327 */
void Dvar_Reset(const dvar_t *dvar, DvarSetSource setSource)
{
    Dvar_SetVariantReg(dvar, dvar->reset, setSource);
}

/* line 2142 */
static void __attribute_regparm__(3) Dvar_SetFromStringFromSource(
    const dvar_t *dvar, const char *string, DvarSetSource source)
{
    char buf[0x400];
    char domainBuffer[0x400];
    DvarValue value;

    I_strncpyz(buf, string, sizeof(buf));
    value = Dvar_StringToValue_impl(dvar->type, dvar->domain, buf);

    if (dvar->type == DVAR_TYPE_ENUM && value.integer == DVAR_INVALID_ENUM_INDEX) {
        Com_Printf("'%s' is not a valid value for dvar '%s'\n", buf, dvar->name);
        Com_Printf(
            "  %s\n",
            Dvar_DomainToString_Internal_impl(
                dvar->type,
                dvar->domain,
                domainBuffer,
                sizeof(domainBuffer),
                NULL));
        Dvar_SetVariantReg(dvar, dvar->reset, source);
        return;
    }

    Dvar_SetVariantReg(dvar, value, source);
}

/* line 2168 */
void Dvar_SetFromString(const dvar_t *dvar, const char *string)
{
    Dvar_SetFromStringFromSourceReg(dvar, string, (DvarSetSource)0);
}

/* line 2130 */
void Dvar_SetString(const dvar_t *dvar, const char *value)
{
    DvarValue newValue;
    char stringCopy[1024];

    if (dvar->type == DVAR_TYPE_STRING) {
        I_strncpyz(stringCopy, value, sizeof(stringCopy));
        newValue.string = stringCopy;
    } else {
        /* The original non-string path reuses enum-style lookup against the dvar domain. */
        newValue = Dvar_StringToValueReg(DVAR_TYPE_ENUM, dvar->domain, value);
    }

    Dvar_SetVariantReg(dvar, newValue, DVAR_SOURCE_INTERNAL);
}

/* line 2059 */
void Dvar_SetColorFromSource(const dvar_t *dvar, float r, float g, float b, float a, DvarSetSource source)
{
    DvarValue newValue;
    DvarLimits domain;
    char string[128];

    Com_sprintf(string, sizeof(string), "%g %g %g %g", r, g, b, a);

    if (dvar->type == DVAR_TYPE_COLOR) {
        memset(&domain, 0, sizeof(domain));
        newValue = Dvar_StringToValueReg(DVAR_TYPE_COLOR, domain, string);
    } else {
        newValue.string = string;
    }

    Dvar_SetVariantReg(dvar, newValue, source);
}

/* line 2136 */
void Dvar_SetColor(const dvar_t *dvar, float r, float g, float b, float a)
{
    Dvar_SetColorFromSource(dvar, r, g, b, a, DVAR_SOURCE_INTERNAL);
}

/* line 1896 */
void Dvar_SetFloatFromSource(const dvar_t *dvar, float value, DvarSetSource source)
{
    DvarValue newValue;
    char string[32];

    if (dvar->type == DVAR_TYPE_FLOAT) {
        newValue.value = value;
    } else {
        Com_sprintf(string, sizeof(string), "%g", value);
        newValue.string = string;
    }

    Dvar_SetVariantReg(dvar, newValue, source);
}

/* line 1865 */
void Dvar_SetIntFromSource(const dvar_t *dvar, int value, DvarSetSource source)
{
    DvarValue newValue;
    char string[32];

    if (dvar->type == DVAR_TYPE_INT || dvar->type == DVAR_TYPE_ENUM) {
        newValue.integer = value;
    } else {
        Com_sprintf(string, sizeof(string), "%i", value);
        newValue.string = string;
    }

    Dvar_SetVariantReg(dvar, newValue, source);
}

/* line 1840 */
void Dvar_SetBoolFromSource(const dvar_t *dvar, int value, DvarSetSource source)
{
    DvarValue newValue;
    int enabled;

    enabled = (byte)value != 0;
    if (dvar->type == DVAR_TYPE_BOOL) {
        newValue.enabled = enabled;
    } else {
        newValue.string = enabled ? "1" : "0";
    }

    Dvar_SetVariantReg(dvar, newValue, source);
}

/* line 1698 */
#ifndef __EMSCRIPTEN__
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
        "andl $0x1000, %esi\n" /* line 1538 */
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
#if 0
/* original asm reference */
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
        "andl $0x00FFFFFF, %ebx\n"
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
#endif

/* line 1825 */
const dvar_t * Dvar_RegisterColor(const char *dvarName, float r, float g, float b, float a, int flags)
{
    DvarValue valueUnion;
    DvarLimits domain;
    char string[128];

    memset(&domain, 0, sizeof(domain));
    Com_sprintf(string, sizeof(string), "%g %g %g %g", r, g, b, a);
    valueUnion = Dvar_StringToValueReg(DVAR_TYPE_COLOR, domain, string);

    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_COLOR, flags, valueUnion, domain);
}

/* line 1808 */
const dvar_t * Dvar_RegisterEnum(const char *dvarName, const char * *valueList, int defaultIndex, int flags)
{
    DvarValue valueUnion;
    DvarLimits domain;
    int stringCount;

    valueUnion.integer = defaultIndex;
    domain.enumeration.stringCount = 0;
    domain.enumeration.strings = valueList;

    if (valueList) {
        for (stringCount = 0; valueList[stringCount]; ++stringCount) {
        }
        domain.enumeration.stringCount = stringCount;
    }

    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_ENUM, flags, valueUnion, domain);
}

/* line 1793 */
const dvar_t * Dvar_RegisterString(const char *dvarName, const char *value, int flags)
{
    DvarValue valueUnion;
    DvarLimits domain;

    valueUnion.string = value;
    memset(&domain, 0, sizeof(domain));

    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_STRING, flags, valueUnion, domain);
}

/* line 1779 */
const dvar_t * Dvar_RegisterVec4(const char *dvarName, float x, float y, float z, float w, float min, float max, int flags)
{
    DvarValue valueUnion;
    DvarLimits domain;
    vec4_t vector;

    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
    vector[3] = w;
    valueUnion.vector = vector;
    domain.vector.min = min;
    domain.vector.max = max;

    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_VEC4, flags, valueUnion, domain);
}

/* line 1765 */
const dvar_t * Dvar_RegisterVec3(const char *dvarName, float x, float y, float z, float min, float max, int flags)
{
    DvarValue valueUnion;
    DvarLimits domain;
    vec3_t vector;

    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
    valueUnion.vector = vector;
    domain.vector.min = min;
    domain.vector.max = max;

    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_VEC3, flags, valueUnion, domain);
}

/* line 1751 */
const dvar_t * Dvar_RegisterVec2(const char *dvarName, float x, float y, float min, float max, int flags)
{
    DvarValue valueUnion;
    DvarLimits domain;
    vec2_t vector;

    vector[0] = x;
    vector[1] = y;
    valueUnion.vector = vector;
    domain.vector.min = min;
    domain.vector.max = max;

    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_VEC2, flags, valueUnion, domain);
}

/* line 1739 */
const dvar_t * Dvar_RegisterFloat(const char *dvarName, float value, float min, float max, int flags)
{
    DvarValue valueUnion;
    DvarLimits domain;

    valueUnion.value = value;
    domain.value.min = min;
    domain.value.max = max;

    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_FLOAT, flags, valueUnion, domain);
}

/* line 1727 */
const dvar_t * Dvar_RegisterInt(const char *dvarName, int value, int min, int max, int flags)
{
    DvarValue valueUnion;
    DvarLimits domain;

    valueUnion.integer = value;
    domain.integer.min = min;
    domain.integer.max = max;

    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_INT, flags, valueUnion, domain);
}

/* line 1716 */
const dvar_t * Dvar_RegisterBool(const char *dvarName, int value, int flags)
{
    DvarValue valueUnion;
    DvarLimits domain;

    valueUnion.enabled = value != 0;
    memset(&domain, 0, sizeof(domain));

    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_BOOL, flags, valueUnion, domain);
}

/* line 2376 */
void Dvar_Init(void)
{
    DvarValue valueUnion;
    DvarLimits domain;

    isDvarSystemActive = 1;
    valueUnion.enabled = 0;
    memset(&domain, 0, sizeof(domain));
    dvar_cheats = Dvar_RegisterVariantReg("sv_cheats", DVAR_TYPE_BOOL, 0x1018, valueUnion, domain);
    Dvar_AddCommands();
}

/* line 2517 */
void Dvar_ResetDvars(unsigned int filter, DvarSetSource setSource)
{
    dvar_t *var;

    for (var = sortedDvars; var; var = (dvar_t *)var->next) {
        if (filter & var->flags) {
            Dvar_SetVariantReg(var, var->reset, setSource);
        }
    }
}

/* line 2574 */
#if 0
/* original asm reference */
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
        "jmp .Lf54f6e_skip_dvar_set\n" /* skip Dvar_SetVariant when dvar not found */
        /* } scope */
        ".Lf54f6e_00054fef:\n"
        "movl 0x10(%ebx), %edx\n" /* line 2335 | var */
        "xorl %ecx, %ecx\n"
        "movl %ebx, %eax\n" /* var */
        "calll Dvar_SetVariant\n"
        ".Lf54f6e_skip_dvar_set:\n"
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
#endif

/* line 2574 */
qboolean Com_LoadDvarsFromBuffer(const char * *dvarnames, int numDvars, const char *buffer, const char *filename)
{
    byte wasRead[0x4000];
    const dvar_t *var;
    const char *token;
    int i;
    int numRead;

    memset(wasRead, 0, numDvars);

    for (i = 0; i < numDvars; ++i) {
        var = Dvar_FindVar(dvarnames[i]);
        if (var) {
            Dvar_SetVariantReg(var, var->reset, DVAR_SOURCE_INTERNAL);
        }
    }

    Com_BeginParseSession(filename);
    numRead = 0;

    for (token = Com_Parse(&buffer); *token; token = Com_Parse(&buffer)) {
        for (i = 0; i < numDvars; ++i) {
            if (!stricmp(token, dvarnames[i])) {
                break;
            }
        }

        if (i == numDvars) {
            Com_Printf("^3WARNING: unknown dvar '%s' in file '%s'\n", token, filename);
            Com_SkipRestOfLine(&buffer);
            continue;
        }

        var = Dvar_FindVar(dvarnames[i]);
        Dvar_SetFromStringFromSourceReg(var, Com_ParseOnLine(&buffer), DVAR_SOURCE_INTERNAL);

        if (!wasRead[i]) {
            wasRead[i] = 1;
            ++numRead;
        }
    }

    Com_EndParseSession();

    if (numRead == numDvars) {
        return 1;
    }

    Com_Printf("^1ERROR: the following dvars were not specified in file '%s'", filename);
    for (i = 0; i < numDvars; ++i) {
        if (!wasRead[i]) {
            Com_Printf("^1  %s\n", dvarnames[i]);
        }
    }

    return 0;
}

/* line 2094 */
void Dvar_SetBool(const dvar_t *dvar, int value)
{
    DvarValue newValue;

    if (dvar->type == DVAR_TYPE_BOOL) {
        newValue.enabled = value != 0;
    } else {
        newValue.string = value ? "1" : "0";
    }

    Dvar_SetVariantReg(dvar, newValue, (DvarSetSource)0);
}

/* line 2106 */
void Dvar_SetFloat(const dvar_t *dvar, float value)
{
    DvarValue newValue;
    char string[32];

    if (dvar->type == DVAR_TYPE_FLOAT) {
        newValue.value = value;
    } else {
        Com_sprintf(string, sizeof(string), "%g", value);
        newValue.string = string;
    }

    Dvar_SetVariantReg(dvar, newValue, (DvarSetSource)0);
}

/* line 2100 */
void Dvar_SetInt(const dvar_t *dvar, int value)
{
    DvarValue newValue;
    char string[32];

    if (dvar->type == DVAR_TYPE_INT || dvar->type == DVAR_TYPE_ENUM) {
        newValue.integer = value;
    } else {
        Com_sprintf(string, sizeof(string), "%i", value);
        newValue.string = string;
    }

    Dvar_SetVariantReg(dvar, newValue, (DvarSetSource)0);
}

/* line 2112 */
void Dvar_SetVec2(const dvar_t *dvar, float x, float y)
{
    DvarValue newValue;
    vec2_t vector;
    char string[64];

    /* Vec2 is type 2 everywhere else in dvar.c; the raw immediate here is a bad dump. */
    if (dvar->type == DVAR_TYPE_VEC2) {
        vector[0] = x;
        vector[1] = y;
        newValue.vector = vector;
    } else {
        Com_sprintf(string, sizeof(string), "%g %g", x, y);
        newValue.string = string;
    }

    Dvar_SetVariantReg(dvar, newValue, (DvarSetSource)0);
}

/* line 2118 */
void Dvar_SetVec3(const dvar_t *dvar, float x, float y, float z)
{
    DvarValue newValue;
    vec3_t vector;
    char string[96];

    if (dvar->type == DVAR_TYPE_VEC3) {
        vector[0] = x;
        vector[1] = y;
        vector[2] = z;
        newValue.vector = vector;
    } else {
        Com_sprintf(string, sizeof(string), "%g %g %g", x, y, z);
        newValue.string = string;
    }

    Dvar_SetVariantReg(dvar, newValue, (DvarSetSource)0);
}

/* line 2124 */
void Dvar_SetVec4(const dvar_t *dvar, float x, float y, float z, float w)
{
    DvarValue newValue;
    vec4_t vector;
    char string[128];

    if (dvar->type == DVAR_TYPE_VEC4) {
        vector[0] = x;
        vector[1] = y;
        vector[2] = z;
        vector[3] = w;
        newValue.vector = vector;
    } else {
        Com_sprintf(string, sizeof(string), "%g %g %g %g", x, y, z, w);
        newValue.string = string;
    }

    Dvar_SetVariantReg(dvar, newValue, (DvarSetSource)0);
}

/* line 2174 */
void Dvar_SetBoolByName(const char *dvarName, int value)
{
    const dvar_t *var;

    var = Dvar_FindVar(dvarName);
    if (!var) {
        Dvar_RegisterString(dvarName, value ? "1" : "0", 0x4000);
        return;
    }

    Dvar_SetBool(var, value);
}

/* line 2186 */
void Dvar_SetIntByName(const char *dvarName, int value)
{
    const dvar_t *var;
    char string[32];

    var = Dvar_FindVar(dvarName);
    if (!var) {
        Com_sprintf(string, sizeof(string), "%i", value);
        Dvar_RegisterString(dvarName, string, 0x4000);
        return;
    }

    Dvar_SetInt(var, value);
}

/* line 2204 */
void Dvar_SetFloatByName(const char *dvarName, float value)
{
    const dvar_t *var;
    char string[32];

    var = Dvar_FindVar(dvarName);
    if (!var) {
        Com_sprintf(string, sizeof(string), "%g", value);
        Dvar_RegisterString(dvarName, string, 0x4000);
        return;
    }

    Dvar_SetFloat(var, value);
}

/* line 2216 */
void Dvar_SetVec2ByName(const char *dvarName, float x, float y)
{
    const dvar_t *var;
    char string[64];

    var = Dvar_FindVar(dvarName);
    if (!var) {
        Com_sprintf(string, sizeof(string), "%g %g", x, y);
        Dvar_RegisterString(dvarName, string, 0x4000);
        return;
    }

    Dvar_SetVec2(var, x, y);
}

/* line 2228 */
void Dvar_SetVec3ByName(const char *dvarName, float x, float y, float z)
{
    const dvar_t *var;
    char string[96];

    var = Dvar_FindVar(dvarName);
    if (!var) {
        Com_sprintf(string, sizeof(string), "%g %g %g", x, y, z);
        Dvar_RegisterString(dvarName, string, 0x4000);
        return;
    }

    Dvar_SetVec3(var, x, y, z);
}

/* line 2240 */
void Dvar_SetVec4ByName(const char *dvarName, float x, float y, float z, float w)
{
    const dvar_t *var;
    char string[128];

    var = Dvar_FindVar(dvarName);
    if (!var) {
        Com_sprintf(string, sizeof(string), "%g %g %g %g", x, y, z, w);
        Dvar_RegisterString(dvarName, string, 0x4000);
        return;
    }

    Dvar_SetVec4(var, x, y, z, w);
}

/* line 2253 */
void Dvar_SetStringByName(const char *dvarName, const char *value)
{
    const dvar_t *var;

    var = Dvar_FindVar(dvarName);
    if (!var) {
        Dvar_RegisterString(dvarName, value, 0x4000);
        return;
    }

    Dvar_SetString(var, value);
}

/* line 2265 */
void Dvar_SetColorByName(const char *dvarName, int r, int g, int b, int a)
{
    const dvar_t *var;
    byte red;
    byte green;
    byte blue;
    byte alpha;
    char string[128];

    red = (byte)r;
    green = (byte)g;
    blue = (byte)b;
    alpha = (byte)a;

    var = Dvar_FindVar(dvarName);
    if (!var) {
        Com_sprintf(string, sizeof(string), "%g %g %g %g",
            (double)red, (double)green, (double)blue, (double)alpha);
        Dvar_RegisterString(dvarName, string, 0x4000);
        return;
    }

    Dvar_SetColorFromSource(var, (float)red, (float)green, (float)blue, (float)alpha, DVAR_SOURCE_INTERNAL);
}

/* line 2277 */
const dvar_t * Dvar_SetFromStringByNameFromSource(const char *dvarName, const char *string, DvarSetSource source)
{
    const dvar_t *dvar;

    dvar = Dvar_FindVar(dvarName);
    if (dvar) {
        Dvar_SetFromStringFromSourceReg(dvar, string, source);
        return dvar;
    }

    return Dvar_RegisterString(dvarName, string, 0x4000);
}

/* line 2303 */
void Dvar_SetCommand(const char *dvarName, const char *string)
{
    const dvar_t *dvar;

    dvar = Dvar_SetFromStringByNameFromSource(dvarName, string, (DvarSetSource)1);
    if (!dvar || !isLoadingAutoExecGlobalFlag) {
        return;
    }

    ((dvar_t *)dvar)->flags |= 0x8000;
    Dvar_UpdateResetValueReg(dvar, dvar->current);
}

/* line 2292 */
void Dvar_SetFromStringByName(const char *dvarName, const char *string)
{
    Dvar_SetFromStringByNameFromSource(dvarName, string, 0);
}
#else
static unsigned char Dvar_HashName(const char *name)
{
    int hash;
    const char *p;
    int i;

    if (!name) {
        Com_Error(1, (const char *)str_00219550);
    }

    p = name;
    if (*p == '\0')
        return 0;

    hash = 0;
    i = 0x77;
    while (*p) {
        int ch = ___tolower((signed char)*p);
        hash += ch * i;
        i++;
        p++;
    }
    return (unsigned char)hash;
}

static const char *Dvar_ConvertStringValue(const char *value, int type)
{
    int len;
    unsigned char ch;

    if (value == NULL || *value == '\0') {
        return (const char *)str_002157b8;
    }

    ch = *(unsigned char *)(value + 1);
    if (ch == '\0') {
        /* single char: check if digit */
        unsigned char first = *(unsigned char *)value;
        if ((unsigned char)(first - '0') <= 9) {
            /* Return digit string: "0", "1", ..., "9" */
            {
                static const char * const digit_strs[] = {"0","1","2","3","4","5","6","7","8","9"};
                return digit_strs[first - '0'];
            }
        }
        return CopyStringInternal(value);
    }

    if (*(unsigned char *)value == 'o') {
        if (ch == 'n') {
            /* "on" */
            if (*(unsigned char *)(value + 2) == '\0') {
                return dvarOnOffStrings[1];
            }
            return CopyStringInternal(value);
        } else if (ch == 'f') {
            /* "off" */
            if (*(unsigned char *)(value + 2) == 'f' && *(unsigned char *)(value + 3) == '\0') {
                return dvarOnOffStrings[0];
            }
            return CopyStringInternal(value);
        }
    }

    return CopyStringInternal(value);
}

static const dvar_t *Dvar_RegisterVariant_impl(
    const char *dvarName, int type, unsigned int flags, DvarValue value, DvarLimits domain)
{
    unsigned char hash;
    dvar_t *dvar;
    dvar_t *existing;
    dvar_t **prev;
    int newType;

    /* line 68: null name check */
    if (!dvarName) {
        Com_Error(1, (const char *)str_00219550);
    }

    /* Compute hash */
    hash = Dvar_HashName(dvarName);

    /* line 1054: search hash table for existing dvar */
    existing = dvarHashTable[hash];
    while (existing) {
        if (I_stricmp(dvarName, existing->name) == 0) {
            goto found_existing;
        }
        existing = (dvar_t *)(uintptr_t)existing->hashNext;
    }

    /* NOT FOUND: create new dvar */
    goto create_new;

found_existing:
    /* line 1708: dvar already exists */
    {
        unsigned short oldFlags = existing->flags;
        unsigned short newFlags = (unsigned short)flags;

        /* line 1580: check if flag update types differ */
        if ((oldFlags ^ newFlags) & 0x7000) {
            /* line 1513: check old READONLY flag */
            if (oldFlags & 0x4000) {
                if (newFlags & 0x4000) {
                    /* both external: go to line 1815 */
                    goto check_flags;
                }
                /* line 1522: unregister */
                ((DvarPerformUnregistrationRegparmFn)Dvar_PerformUnregistration)(existing);
                /* line 145: free old name */
                Z_FreeInternal((char *)existing->name);
                /* line 1525 */
                existing->name = dvarName;
                /* line 1526 */
                existing->flags &= ~0x4000;

                /* line 1528 */
                {
                    DvarValue *valuePtr = (DvarValue *)&value;
                    DvarLimits *domainPtr = (DvarLimits *)&domain;
                    ((void (*)(dvar_t *, const char *, int, unsigned short, DvarValue *, DvarLimits *))Dvar_MakeExplicitType)(
                        existing, dvarName, type, (unsigned short)flags, valuePtr, domainPtr);
                }
                oldFlags = existing->flags;
                goto check_flags_cont;
            } else {
                if (newFlags & 0x4000) {
                    goto check_flags;
                }
                /* line 1534-1541 */
                if (flags & 0x1000) {
                    if (!(oldFlags & 0x1000)) {
                        /* line 1540 */
                        existing->name = dvarName;
                        /* line 1541 */
                        if (existing->type == 6) {
                            /* line 1542: update enum domain */
                            existing->domain = domain;
                        }
                    }
                }
                goto check_flags;
            }

check_flags_cont:
            if (flags & 0x1000) {
                if (!(oldFlags & 0x1000)) {
                    existing->name = dvarName;
                    if (existing->type == 6) {
                        existing->domain = domain;
                    }
                }
            }
        }

check_flags:
        /* line 1586: check READONLY flag mismatch */
        if ((oldFlags & 0x4000) && type != existing->type) {
            /* line 1589: type mismatch, call MakeExplicitType */
            ((void (*)(dvar_t *, const char *, int, unsigned short, DvarValue *, DvarLimits *))Dvar_MakeExplicitType)(
                existing, dvarName, type, (unsigned short)flags, (DvarValue *)&value, (DvarLimits *)&domain);
        }

        /* line 1595: merge flags */
        existing->flags |= (unsigned short)flags;

        /* line 1597: cheat enforcement */
        if (existing->flags & 0x80) {
            if (dvar_cheats && dvar_cheats->current.enabled == 0) {
                /* line 1599: set to reset value */
                {
                    DvarValue resetVal = existing->reset;
                    ((DvarSetVariantRegparmFn)Dvar_SetVariant)(existing, resetVal, 0);
                }
                {
                    DvarValue resetVal = existing->reset;
                    ((DvarUpdateResetValueRegparmFn)Dvar_SetLatchedValue)(existing, resetVal);
                }
            }
        }

        /* line 1603: check LATCH flag */
        if (existing->flags & 0x20) {
            /* line 1553: set variant from latched */
            DvarValue latchedVal = existing->latched;
            ((DvarSetVariantRegparmFn)Dvar_SetVariant)(existing, latchedVal, 0);
        }

        return existing;
    }

create_new:
    /* line 1712 */
    newType = type;

    /* line 1622: check dvar count limit */
    if (dvarCount > 0x4ff) {
        Com_Error(0, "Can't create dvar '%s': %i dvars already exist", dvarName, 0x500);
    }

    /* line 1630: allocate from pool */
    dvar = &dvarPool[dvarCount];
    dvarCount++;

    /* line 1632: set type */
    dvar->type = (byte)newType;

    /* line 1633: check EXTERNAL flag */
    if (flags & 0x4000) {
        /* line 1634: copy name string */
        dvar->name = CopyStringInternal(dvarName);
    } else {
        /* line 1636: direct pointer */
        dvar->name = dvarName;
    }

    /* line 1637: set value based on type */
    if (newType == DVAR_TYPE_VEC3) {
        /* line 125-127: allocate vec3 storage (3 components * 3 copies = 9 floats * 4 = 36) */
        int numComponents = (unsigned char)dvar->type;
        int allocSize = numComponents * 3 * 4;
        float *mem = (float *)Z_MallocInternal(allocSize);
        dvar->current.vector = mem;
        dvar->latched.vector = mem + numComponents;
        dvar->reset.vector = mem + numComponents * 2;

        /* Copy vec3 value to all three (current, latched, reset) */
        {
            float *src = (float *)&value;
            mem[0] = src[0];
            mem[1] = src[1];
            mem[2] = src[2];

            float *latched = dvar->latched.vector;
            latched[0] = src[0];
            latched[1] = src[1];
            latched[2] = src[2];

            float *reset = dvar->reset.vector;
            reset[0] = src[0];
            reset[1] = src[1];
            reset[2] = src[2];
        }
    } else if (newType == DVAR_TYPE_VEC2) {
        /* line 125-127 */
        int numComponents = (unsigned char)dvar->type;
        int allocSize = numComponents * 3 * 4;
        float *mem = (float *)Z_MallocInternal(allocSize);
        dvar->current.vector = mem;
        dvar->latched.vector = mem + numComponents;
        dvar->reset.vector = mem + numComponents * 2;

        /* Copy vec2 value */
        {
            float *src = (float *)&value;
            mem[0] = src[0];
            mem[1] = src[1];

            float *latched = dvar->latched.vector;
            latched[0] = src[0];
            latched[1] = src[1];

            float *reset = dvar->reset.vector;
            reset[0] = src[0];
            reset[1] = src[1];
        }
    } else if (newType == DVAR_TYPE_VEC4) {
        /* line 125-127 */
        int numComponents = (unsigned char)dvar->type;
        int allocSize = numComponents * 3 * 4;
        float *mem = (float *)Z_MallocInternal(allocSize);
        dvar->current.vector = mem;
        dvar->latched.vector = mem + numComponents;
        dvar->reset.vector = mem + numComponents * 2;

        /* Copy vec4 value */
        {
            float *src = (float *)&value;
            mem[0] = src[0];
            mem[1] = src[1];
            mem[2] = src[2];
            mem[3] = src[3];

            float *latched = dvar->latched.vector;
            latched[0] = src[0];
            latched[1] = src[1];
            latched[2] = src[2];
            latched[3] = src[3];

            float *reset = dvar->reset.vector;
            reset[0] = src[0];
            reset[1] = src[1];
            reset[2] = src[2];
            reset[3] = src[3];
        }
    } else if (newType == DVAR_TYPE_STRING) {
        /* line 155-173: string dvar */
        const char *strVal = Dvar_ConvertStringValue(*(const char **)&value, newType);
        dvar->current.string = strVal;
        dvar->latched.string = strVal;
        dvar->reset.string = strVal;
    } else {
        /* line 1668-1670: simple value types (bool, int, float, enum, color) */
        int val = *(int *)&value;
        dvar->current.integer = val;
        dvar->latched.integer = val;
        dvar->reset.integer = val;
    }

    /* line 1673: set domain */
    dvar->domain = domain;

    /* line 1674: clear modified */
    dvar->modified = 0;

    /* line 1677-1683: insert into sorted list */
    {
        dvar_t **prevPtr = &sortedDvars;
        dvar_t *cur = sortedDvars;

        while (cur) {
            if (stricmp(dvar->name, cur->name) < 0)
                break;
            prevPtr = (dvar_t **)&cur->next;
            cur = (dvar_t *)(uintptr_t)cur->next;
        }

        dvar->next = (int)(uintptr_t)*prevPtr;
        *prevPtr = dvar;
    }

    /* line 1685 */
    dvar->flags = (unsigned short)flags;

    /* line 1688-1689: insert into hash table */
    {
        unsigned char h = Dvar_HashName(dvarName);
        dvar->hashNext = (int)(uintptr_t)dvarHashTable[h];
        dvarHashTable[h] = dvar;
    }

    /* line 1694 */
    return dvar;
}

static const dvar_t * Dvar_RegisterVariant(const char *dvarName, short unsigned int flags, DvarValue value, DvarLimits domain)
{
    /* This function is only called via regparm(3) trampoline in non-Emscripten builds.
       In Emscripten, Dvar_RegisterVariantReg calls Dvar_RegisterVariant_impl directly. */
    return NULL;
}
#endif
