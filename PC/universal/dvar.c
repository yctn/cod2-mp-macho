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

__attribute__((used, packed, aligned(4)))
const char * dvarOnOffStrings[] = {
    "off",
    "on",
    NULL, NULL, NULL, NULL, NULL, NULL,
}; /* 0x30a3e0 */

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
    return Dvar_RegisterVariant_impl(dvarName, type, flags, value, domain);
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
        Com_Error(1, "\x15null name in generateHashValue");
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
            isAlnum = (((unsigned long *)((byte *)runeLocale + 0x34))[(unsigned char)sch] & 0x500) != 0;
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

    if (!dvar || (unsigned int)dvar < 0x08000000) return;
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
static unsigned char Dvar_HashName(const char *name)
{
    int hash;
    const char *p;
    int i;

    if (!name) {
        Com_Error(1, (const char *)"\x15null name in generateHashValue");
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
        return (const char *)"";
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
        Com_Error(1, (const char *)"\x15null name in generateHashValue");
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

const dvar_t * Dvar_RegisterBool(const char *dvarName, int value, int flags)
{
    DvarValue dvarValue;
    DvarLimits dvarDomain;
    memset(&dvarValue, 0, sizeof(dvarValue));
    memset(&dvarDomain, 0, sizeof(dvarDomain));
    dvarValue.enabled = value;
    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_BOOL, flags, dvarValue, dvarDomain);
}

const dvar_t * Dvar_RegisterInt(const char *dvarName, int value, int min, int max, int flags)
{
    DvarValue dvarValue;
    DvarLimits dvarDomain;
    memset(&dvarValue, 0, sizeof(dvarValue));
    dvarValue.integer = value;
    dvarDomain.integer.min = min;
    dvarDomain.integer.max = max;
    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_INT, flags, dvarValue, dvarDomain);
}

const dvar_t * Dvar_RegisterFloat(const char *dvarName, float value, float min, float max, int flags)
{
    DvarValue dvarValue;
    DvarLimits dvarDomain;
    memset(&dvarValue, 0, sizeof(dvarValue));
    dvarValue.value = value;
    dvarDomain.value.min = min;
    dvarDomain.value.max = max;
    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_FLOAT, flags, dvarValue, dvarDomain);
}

const dvar_t * Dvar_RegisterString(const char *dvarName, const char *value, int flags)
{
    DvarValue dvarValue;
    DvarLimits dvarDomain;
    memset(&dvarDomain, 0, sizeof(dvarDomain));
    dvarValue.string = value;
    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_STRING, flags, dvarValue, dvarDomain);
}

const dvar_t * Dvar_RegisterEnum(const char *dvarName, const char * *valueList, int defaultIndex, int flags)
{
    DvarValue dvarValue;
    DvarLimits dvarDomain;
    dvarDomain.enumeration.strings = valueList;
    dvarDomain.enumeration.stringCount = 0;
    while (valueList[dvarDomain.enumeration.stringCount] != NULL)
        dvarDomain.enumeration.stringCount++;
    dvarValue.integer = defaultIndex;
    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_ENUM, flags, dvarValue, dvarDomain);
}

const dvar_t * Dvar_RegisterVec2(const char *dvarName, float x, float y, float min, float max, int flags)
{
    DvarValue dvarValue;
    DvarLimits dvarDomain;
    vec_t *v = Dvar_AllocTempVector(2);
    v[0] = x;
    v[1] = y;
    dvarValue.vector = v;
    dvarDomain.vector.min = min;
    dvarDomain.vector.max = max;
    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_VEC2, flags, dvarValue, dvarDomain);
}

const dvar_t * Dvar_RegisterVec3(const char *dvarName, float x, float y, float z, float min, float max, int flags)
{
    DvarValue dvarValue;
    DvarLimits dvarDomain;
    vec_t *v = Dvar_AllocTempVector(3);
    v[0] = x;
    v[1] = y;
    v[2] = z;
    dvarValue.vector = v;
    dvarDomain.vector.min = min;
    dvarDomain.vector.max = max;
    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_VEC3, flags, dvarValue, dvarDomain);
}

const dvar_t * Dvar_RegisterVec4(const char *dvarName, float x, float y, float z, float w, float min, float max, int flags)
{
    DvarValue dvarValue;
    DvarLimits dvarDomain;
    vec_t *v = Dvar_AllocTempVector(4);
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
    dvarValue.vector = v;
    dvarDomain.vector.min = min;
    dvarDomain.vector.max = max;
    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_VEC4, flags, dvarValue, dvarDomain);
}

const dvar_t * Dvar_RegisterColor(const char *dvarName, float r, float g, float b, float a, int flags)
{
    DvarValue dvarValue;
    DvarLimits dvarDomain;
    memset(&dvarDomain, 0, sizeof(dvarDomain));
    dvarValue.color[0] = (byte)(255.0f * (r < 0.0f ? 0.0f : (r > 1.0f ? 1.0f : r)) + 0.001f);
    dvarValue.color[1] = (byte)(255.0f * (g < 0.0f ? 0.0f : (g > 1.0f ? 1.0f : g)) + 0.001f);
    dvarValue.color[2] = (byte)(255.0f * (b < 0.0f ? 0.0f : (b > 1.0f ? 1.0f : b)) + 0.001f);
    dvarValue.color[3] = (byte)(255.0f * (a < 0.0f ? 0.0f : (a > 1.0f ? 1.0f : a)) + 0.001f);
    return Dvar_RegisterVariantReg(dvarName, DVAR_TYPE_COLOR, flags, dvarValue, dvarDomain);
}

void Dvar_SetBool(const dvar_t *dvar, int value)
{
    Dvar_SetBoolFromSource(dvar, value, DVAR_SOURCE_INTERNAL);
}

void Dvar_SetInt(const dvar_t *dvar, int value)
{
    Dvar_SetIntFromSource(dvar, value, DVAR_SOURCE_INTERNAL);
}

void Dvar_SetFloat(const dvar_t *dvar, float value)
{
    Dvar_SetFloatFromSource(dvar, value, DVAR_SOURCE_INTERNAL);
}

void Dvar_SetVec2(const dvar_t *dvar, float x, float y)
{
    DvarValue newValue;
    char string[64];
    if (dvar->type == DVAR_TYPE_VEC2) {
        vec_t *v = Dvar_AllocTempVector(2);
        v[0] = x; v[1] = y;
        newValue.vector = v;
    } else {
        Com_sprintf(string, sizeof(string), "%g %g", x, y);
        newValue.string = string;
    }
    Dvar_SetVariantReg(dvar, newValue, DVAR_SOURCE_INTERNAL);
}

void Dvar_SetVec3(const dvar_t *dvar, float x, float y, float z)
{
    DvarValue newValue;
    char string[96];
    if (dvar->type == DVAR_TYPE_VEC3) {
        vec_t *v = Dvar_AllocTempVector(3);
        v[0] = x; v[1] = y; v[2] = z;
        newValue.vector = v;
    } else {
        Com_sprintf(string, sizeof(string), "%g %g %g", x, y, z);
        newValue.string = string;
    }
    Dvar_SetVariantReg(dvar, newValue, DVAR_SOURCE_INTERNAL);
}

void Dvar_SetVec4(const dvar_t *dvar, float x, float y, float z, float w)
{
    DvarValue newValue;
    char string[128];
    if (dvar->type == DVAR_TYPE_VEC4) {
        vec_t *v = Dvar_AllocTempVector(4);
        v[0] = x; v[1] = y; v[2] = z; v[3] = w;
        newValue.vector = v;
    } else {
        Com_sprintf(string, sizeof(string), "%g %g %g %g", x, y, z, w);
        newValue.string = string;
    }
    Dvar_SetVariantReg(dvar, newValue, DVAR_SOURCE_INTERNAL);
}

void Dvar_SetBoolByName(const char *dvarName, int value)
{
    const dvar_t *dvar = Dvar_FindVar(dvarName);
    if (dvar)
        Dvar_SetBool(dvar, value);
    else
        Dvar_RegisterString(dvarName, value ? "1" : "0", 0x4000);
}

void Dvar_SetIntByName(const char *dvarName, int value)
{
    char buf[32];
    const dvar_t *dvar = Dvar_FindVar(dvarName);
    if (dvar)
        Dvar_SetInt(dvar, value);
    else {
        Com_sprintf(buf, sizeof(buf), "%i", value);
        Dvar_RegisterString(dvarName, buf, 0x4000);
    }
}

void Dvar_SetFloatByName(const char *dvarName, float value)
{
    char buf[32];
    const dvar_t *dvar = Dvar_FindVar(dvarName);
    if (dvar)
        Dvar_SetFloat(dvar, value);
    else {
        Com_sprintf(buf, sizeof(buf), "%g", value);
        Dvar_RegisterString(dvarName, buf, 0x4000);
    }
}

void Dvar_SetVec2ByName(const char *dvarName, float x, float y)
{
    char buf[64];
    const dvar_t *dvar = Dvar_FindVar(dvarName);
    if (dvar)
        Dvar_SetVec2(dvar, x, y);
    else {
        Com_sprintf(buf, sizeof(buf), "%g %g", x, y);
        Dvar_RegisterString(dvarName, buf, 0x4000);
    }
}

void Dvar_SetVec3ByName(const char *dvarName, float x, float y, float z)
{
    char buf[128];
    const dvar_t *dvar = Dvar_FindVar(dvarName);
    if (dvar)
        Dvar_SetVec3(dvar, x, y, z);
    else {
        Com_sprintf(buf, sizeof(buf), "%g %g %g", x, y, z);
        Dvar_RegisterString(dvarName, buf, 0x4000);
    }
}

void Dvar_SetVec4ByName(const char *dvarName, float x, float y, float z, float w)
{
    char buf[128];
    const dvar_t *dvar = Dvar_FindVar(dvarName);
    if (dvar)
        Dvar_SetVec4(dvar, x, y, z, w);
    else {
        Com_sprintf(buf, sizeof(buf), "%g %g %g %g", x, y, z, w);
        Dvar_RegisterString(dvarName, buf, 0x4000);
    }
}

void Dvar_SetStringByName(const char *dvarName, const char *value)
{
    const dvar_t *dvar = Dvar_FindVar(dvarName);
    if (dvar)
        Dvar_SetString(dvar, value);
    else
        Dvar_RegisterString(dvarName, value, 0x4000);
}

void Dvar_SetColorByName(const char *dvarName, int r, int g, int b, int a)
{
    char buf[128];
    const dvar_t *dvar = Dvar_FindVar(dvarName);
    if (dvar)
        Dvar_SetColor(dvar, (float)r/255.0f, (float)g/255.0f, (float)b/255.0f, (float)a/255.0f);
    else {
        Com_sprintf(buf, sizeof(buf), "%g %g %g %g", (float)r/255.0f, (float)g/255.0f, (float)b/255.0f, (float)a/255.0f);
        Dvar_RegisterString(dvarName, buf, 0x4000);
    }
}

const dvar_t * Dvar_SetFromStringByNameFromSource(const char *dvarName, const char *string, DvarSetSource source)
{
    const dvar_t *dvar = Dvar_FindVar(dvarName);
    if (!dvar)
        return Dvar_RegisterString(dvarName, string, 0x4000);
    Dvar_SetFromString(dvar, string);
    return dvar;
}

void Dvar_SetCommand(const char *dvarName, const char *string)
{
    const dvar_t *dvar = Dvar_SetFromStringByNameFromSource(dvarName, string, DVAR_SOURCE_EXTERNAL);
    if (dvar && isLoadingAutoExecGlobalFlag) {
        Dvar_AddFlags(dvar, 0x2000);
        Dvar_UpdateResetValueReg(dvar, dvar->current);
    }
}

void Dvar_SetFromStringByName(const char *dvarName, const char *string)
{
    Dvar_SetFromStringByNameFromSource(dvarName, string, DVAR_SOURCE_INTERNAL);
}

void Dvar_ResetDvars(unsigned int filter, DvarSetSource setSource)
{
    dvar_t *dvar;
    int i;
    for (i = 0; i < dvarCount; i++) {
        dvar = &dvarPool[i];
        if (dvar->flags & filter)
            Dvar_Reset(dvar, setSource);
    }
}

qboolean Com_LoadDvarsFromBuffer(const char * *dvarnames, int numDvars, const char *buffer, const char *filename)
{
    int i;
    const char *token;

    Com_BeginParseSession(filename);

    for (i = 0; i < numDvars; i++) {
        token = Com_Parse(&buffer);
        if (!token || !*token) {
            Com_EndParseSession();
            return 0;
        }
        Dvar_SetCommand(dvarnames[i], token);
    }

    Com_EndParseSession();
    return 1;
}

void Dvar_Init(void)
{
    isDvarSystemActive = 1;
    dvar_cheats = Dvar_RegisterBool("sv_cheats", 0, 0x1018);
    Dvar_AddCommands();
}
