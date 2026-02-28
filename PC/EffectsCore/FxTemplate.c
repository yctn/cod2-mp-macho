/* ASM dump from: FxTemplate.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxTemplate.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/GenericParser2.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/EffectsCore/FxTemplate.h"
 *   #include "PC/universal/com_vector.h"
 */

extern const FxFlagEntry fxAttributeFlags[24]; /* 0x0 */
extern const FxFlagEntry fxSpawnFlags[13]; /* 0x0 */
extern Bool g_rendererExists; /* 0x0 */

extern MaterialHandle Material_RegisterHandle(const char *name, int imageTrack, int materialType);
extern void MediaHandles_Shutdown(MediaHandles *handles);
extern void Com_Printf(const char *fmt, ...);
extern Bool Com_ValidXModelName(const char *name);
extern struct XModel * FX_XModelPrecache(const char *name);
extern float flrand(float min, float max);

#include <stdarg.h>

void FxRange_SetRange(const FxRange * _this, float min, float max);
void PrimitiveTemplate_Shutdown(const PrimitiveTemplate * _this);
float FxRange_GetValPct(const FxRange * _this, float percent);
Bool PrimitiveTemplate_ParseGroupFlags(const PrimitiveTemplate * _this, const char *val, int *groupFlags, const PrimitiveTemplate * _this_3, const char *flag, const FxFlagEntry *flagEntries, int flagEntryCount);
void FX_Print(const char *msg, ...);
MaterialHandle FX_RegisterMaterial(const char *material);
struct XModel * FX_ModelRegister(const char *name);
float FxRange_GetVal(const FxRange * _this);
void PrimitiveTemplate_Init(const PrimitiveTemplate * _this);
void PrimitiveTemplate_ParseChannelCurve(const PrimitiveTemplate * _this, GPValue *pairs, FxChannelId channel);
Bool PrimitiveTemplate_ParseImpactFxStrings(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParseDeathFxStrings(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParseEmitterFxStrings(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParsePlayFxStrings(const PrimitiveTemplate * _this, GPValue *grp);
void PrimitiveTemplate_ParseChannelRgbCurve(const PrimitiveTemplate * _this, GPValue *pairs, FxChannelId channel);
void PrimitiveTemplate_CreateBackCompatibleRotationDeltaCurve(const PrimitiveTemplate * _this, float initialValue, float keyScale, float lifetime, int channelId, float graphScale);
Bool PrimitiveTemplate_ParseMaterials(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParseFlags(const PrimitiveTemplate * _this, const char *line, const FxFlagEntry *flagEntries, int flagEntryCount);
Bool PrimitiveTemplate_ParseModels(const PrimitiveTemplate * _this, GPValue *grp);
Bool PrimitiveTemplate_ParseRotationDelta(const PrimitiveTemplate * _this, const char *val);
Bool PrimitiveTemplate_ParseChannel(const PrimitiveTemplate * _this, BackCompatibleParameters *backCompatibleParameters, GPGroup *grp, FxChannelId channelId, const PrimitiveTemplate * _this_4, const char *val, const PrimitiveTemplate * _this_6, const char *val_7, const PrimitiveTemplate * _this_8, const char *val_9, const PrimitiveTemplate * _this_10, const char *val_11);
Bool PrimitiveTemplate_ParseVelocity(const PrimitiveTemplate * _this, const char *val);
Bool PrimitiveTemplate_ParseAcceleration(const PrimitiveTemplate * _this, const char *val);
Bool PrimitiveTemplate_ParsePrimitiveInternal(const PrimitiveTemplate * _this, BackCompatibleParameters *backCompatibleParameters, GPGroup *grp);
Bool PrimitiveTemplate_ParsePrimitive(const PrimitiveTemplate * _this, GPGroup *grp);

/* line 2199 */
void FxRange_SetRange(const FxRange * _this, float min, float max)
{
    *(float *)_this = min;
    *(float *)((byte *)_this + 4) = max;
}

/* line 151 */
void PrimitiveTemplate_Shutdown(const PrimitiveTemplate * _this)
{
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x68));
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x70));
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x78));
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x80));
    MediaHandles_Shutdown((MediaHandles *)((byte *)_this + 0x88));
}

/* line 2213 */
float FxRange_GetValPct(const FxRange * _this, float percent)
{
    float base = *(float *)((byte *)_this);
    float range = *(float *)((byte *)_this + 4) - base;
    return base + range * percent;
}

/* line 351 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseGroupFlags(const PrimitiveTemplate * _this, const char *val, int *groupFlags, const PrimitiveTemplate * _this_3, const char *flag, const FxFlagEntry *flagEntries, int flagEntryCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 351 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* groupFlags */
        /* { scope 1 */
        "movl $0x80, 8(%esp)\n" /* line 353 */
        "movl $__ZZN17PrimitiveTemplate15ParseGroupFlagsEPKcPiE5C.148, 4(%esp)\n"
        "leal -0x98(%ebp), %eax\n" /* flag */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leal -0x38(%ebp), %eax\n" /* line 359 */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x58(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x78(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x98(%ebp), %eax\n" /* flag */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021a198, 4(%esp)\n" /* "%s %s %s %s" */
        "movl 0xc(%ebp), %eax\n" /* val */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        "movl %eax, -0x9c(%ebp)\n" /* v */
    );
}

/* line 2127 */
void FX_Print(const char *msg, ...)
{
    char text[1024];
    va_list argptr;

    va_start(argptr, msg);
    vsnprintf(text, 0x400, msg, argptr);
    va_end(argptr);

    Com_Printf("%s", text);
}

/* line 2151 */
MaterialHandle FX_RegisterMaterial(const char *material)
{
    return Material_RegisterHandle(material, 3, 6);
}

/* line 2161 */
struct XModel * FX_ModelRegister(const char *name)
{
    if (!Com_ValidXModelName(name)) {
        return NULL;
    }

    return FX_XModelPrecache(name + 7);
}

/* line 2205 */
float FxRange_GetVal(const FxRange * _this)
{
    float base = *(float *)((byte *)_this);
    float amplitude = *(float *)((byte *)_this + 4);

    if (base == amplitude) {
        return base;
    }

    return flrand(base, amplitude);
}

/* line 94 */
__attribute__((naked))
void PrimitiveTemplate_Init(const PrimitiveTemplate * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 94 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x3f800000, %edi\n" /* line 2201 */
        "movl %edi, 0x58(%ebx)\n" /* this */
        "movl %edi, 0x5c(%ebx)\n" /* line 2202 | this */
        "movl %edi, 0x50(%ebx)\n" /* line 2201 | this */
        "movl %edi, 0x54(%ebx)\n" /* line 2202 | this */
        "movl %edi, 0xe8(%ebx)\n" /* line 2201 | this */
        "movl %edi, 0xec(%ebx)\n" /* line 2202 | this */
        "movl %edi, 0xf0(%ebx)\n" /* line 2201 | this */
        "movl %edi, 0xf4(%ebx)\n" /* line 2202 | this */
        "xorl %esi, %esi\n" /* line 105 */
        "movl %esi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "leal 0x100(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 106 */
        "movl %edi, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "leal 0x10c(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 107 */
        "movl %edi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x118(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 108 */
        "movl %edi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x124(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 109 */
        "movl %edi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x130(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 110 */
        "movl %edi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x13c(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 111 */
        "movl %edi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x148(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 112 */
        "movl %edi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x154(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 113 */
        "movl %edi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x160(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 114 */
        "movl %edi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x16c(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 115 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x178(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 116 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x184(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 118 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x190(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 119 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x19c(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 120 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x1a8(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 121 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x1b4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 122 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x1c0(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 123 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x1cc(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 125 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x1d8(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 126 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x1e4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 127 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x1f0(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 128 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x1fc(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 129 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x208(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %esi, 0xc(%esp)\n" /* line 130 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal 0x214(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll FxChannel_CreateDefault\n"
        "movl %edi, 0x270(%ebx)\n" /* line 2201 | this */
        "movl %edi, 0x274(%ebx)\n" /* line 2202 | this */
        "movl %edi, 0x278(%ebx)\n" /* line 2201 | this */
        "movl %edi, 0x27c(%ebx)\n" /* line 2202 | this */
        "movl %edi, 0x268(%ebx)\n" /* line 2201 | this */
        "movl %edi, 0x26c(%ebx)\n" /* line 2202 | this */
        "movl $0x41200000, %eax\n" /* line 2201 */
        "movl %eax, 0x260(%ebx)\n" /* this */
        "movl %eax, 0x264(%ebx)\n" /* line 2202 | this */
        "movl $0, 0x288(%ebx)\n" /* line 138 | this */
        "movl $1, 0x28c(%ebx)\n" /* line 139 | this */
        "movl $0, 0x290(%ebx)\n" /* line 141 | this */
        "movl %edi, 0x294(%ebx)\n" /* line 142 | this */
        "movl $0, 0x298(%ebx)\n" /* line 144 | this */
        "movl $1, 0x29c(%ebx)\n" /* line 145 | this */
        "movl %esi, 0x2a0(%ebx)\n" /* line 147 | this */
        "addl $0x1c, %esp\n" /* line 148 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1590 */
__attribute__((naked))
void PrimitiveTemplate_ParseChannelCurve(const PrimitiveTemplate * _this, GPValue *pairs, FxChannelId channel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1590 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this, pairs */
        "movl %eax, -0x20(%ebp)\n" /* pairs, this */
        "movl 0x10(%ebp), %ecx\n" /* channel */
        "movl %ecx, -0x24(%ebp)\n" /* channel */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 86 | pairs */
        "movl 0x10(%eax), %ebx\n"
        "testl %ebx, %ebx\n" /* line 1599 | list */
        "je .Lf5e49e_0005e550\n"
        "movl %ebx, %eax\n" /* list */
        "xorl %edx, %edx\n"
        ".Lf5e49e_0005e4c5:\n"
        "addl $1, %edx\n" /* line 1600 */
        "movl 4(%eax), %eax\n" /* line 51 */
        "testl %eax, %eax\n" /* line 1599 */
        "jne .Lf5e49e_0005e4c5\n"
        "leal (, %edx, 8), %eax\n"
        ".Lf5e49e_0005e4d6:\n"
        "movl %eax, (%esp)\n" /* line 1605 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x1c(%ebp)\n" /* keys */
        "testl %ebx, %ebx\n" /* line 1608 | list */
        "je .Lf5e49e_0005e54c\n"
        "movl %eax, %esi\n"
        "xorl %edi, %edi\n" /* keyCount */
        ".Lf5e49e_0005e4e9:\n"
        "leal 4(%esi), %eax\n" /* line 1609 */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl (%ebx), %eax\n" /* list */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        "addl $1, %edi\n" /* line 1608 | keyCount */
        "movl 4(%ebx), %ebx\n" /* line 51 */
        "addl $8, %esi\n"
        "testl %ebx, %ebx\n" /* line 1608 | list */
        "jne .Lf5e49e_0005e4e9\n"
        ".Lf5e49e_0005e513:\n"
        "movl %edi, 8(%esp)\n" /* line 1614 | keyCount */
        "movl $1, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* keys */
        "movl %eax, (%esp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl -0x24(%ebp), %ecx\n" /* channel */
        "leal (%ecx, %ecx, 2), %edx\n"
        "movl -0x20(%ebp), %ecx\n" /* this */
        "movl %eax, 0x100(%ecx, %edx, 4)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1619 | keys */
        "movl %eax, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1621 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Hunk_FreeTempMemory\n" /* line 1619 */
        ".Lf5e49e_0005e54c:\n"
        "xorl %edi, %edi\n" /* line 1608 | keyCount */
        "jmp .Lf5e49e_0005e513\n"
        ".Lf5e49e_0005e550:\n"
        "xorl %eax, %eax\n" /* line 1599 */
        "jmp .Lf5e49e_0005e4d6\n"
    );
}

/* line 1310 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseImpactFxStrings(const PrimitiveTemplate * _this, GPValue *grp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1310 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* grp */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 1315 | grp */
        "calll GPValue_IsList\n"
        "testb %al, %al\n"
        "je .Lf5e554_0005e5b1\n"
        /* { scope 2 */
        "movl 0x10(%ebx), %ebx\n" /* line 86 */
        "testl %ebx, %ebx\n" /* line 1320 | list */
        "je .Lf5e554_0005e59a\n"
        "leal 0x70(%edi), %esi\n" /* this */
        ".Lf5e554_0005e579:\n"
        "movl (%ebx), %eax\n" /* line 1324 | list */
        "movl %eax, (%esp)\n"
        "calll FX_RegisterEffect\n"
        "testl %eax, %eax\n" /* line 1326 */
        "je .Lf5e554_0005e5da\n"
        "movl %eax, 4(%esp)\n" /* line 1328 */
        "movl %esi, (%esp)\n"
        "calll MediaHandles_AddEffect\n"
        "movl 4(%ebx), %ebx\n" /* line 1336 | list */
        "testl %ebx, %ebx\n" /* line 1320 | list */
        "jne .Lf5e554_0005e579\n"
        /* } scope */
        ".Lf5e554_0005e59a:\n"
        "orl $0x820, 0x90(%edi)\n" /* line 1366 | this */
        "movl $1, %eax\n"
        /* } scope */
        ".Lf5e554_0005e5a9:\n"
        "addl $0x1c, %esp\n" /* line 1369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e554_0005e5b1:\n"
        "movl %ebx, (%esp)\n" /* line 1342 | list */
        "calll GPValue_GetTopValue\n"
        "testl %eax, %eax\n" /* line 1344 */
        "je .Lf5e554_0005e5f0\n"
        "movl %eax, (%esp)\n" /* line 1346 */
        "calll FX_RegisterEffect\n"
        "testl %eax, %eax\n" /* line 1348 */
        "je .Lf5e554_0005e5da\n"
        "movl %eax, 4(%esp)\n" /* line 1350 */
        "leal 0x70(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_AddEffect\n"
        "jmp .Lf5e554_0005e59a\n"
        ".Lf5e554_0005e5da:\n"
        "movl $str_0021a1d0, (%esp)\n" /* line 1354 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e554_0005e5f0:\n"
        "movl $str_0021a1fc, (%esp)\n" /* line 1361 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5e554_0005e5a9\n"
    );
}

/* line 1372 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseDeathFxStrings(const PrimitiveTemplate * _this, GPValue *grp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1372 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* grp */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 1377 | grp */
        "calll GPValue_IsList\n"
        "testb %al, %al\n"
        "je .Lf5e600_0005e65d\n"
        /* { scope 2 */
        "movl 0x10(%ebx), %ebx\n" /* line 86 */
        "testl %ebx, %ebx\n" /* line 1382 | list */
        "je .Lf5e600_0005e646\n"
        "leal 0x78(%edi), %esi\n" /* this */
        ".Lf5e600_0005e625:\n"
        "movl (%ebx), %eax\n" /* line 1386 | list */
        "movl %eax, (%esp)\n"
        "calll FX_RegisterEffect\n"
        "testl %eax, %eax\n" /* line 1388 */
        "je .Lf5e600_0005e686\n"
        "movl %eax, 4(%esp)\n" /* line 1390 */
        "movl %esi, (%esp)\n"
        "calll MediaHandles_AddEffect\n"
        "movl 4(%ebx), %ebx\n" /* line 1398 | list */
        "testl %ebx, %ebx\n" /* line 1382 | list */
        "jne .Lf5e600_0005e625\n"
        /* } scope */
        ".Lf5e600_0005e646:\n"
        "orl $0x200, 0x90(%edi)\n" /* line 1428 | this */
        "movl $1, %eax\n"
        /* } scope */
        ".Lf5e600_0005e655:\n"
        "addl $0x1c, %esp\n" /* line 1431 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e600_0005e65d:\n"
        "movl %ebx, (%esp)\n" /* line 1404 | list */
        "calll GPValue_GetTopValue\n"
        "testl %eax, %eax\n" /* line 1406 */
        "je .Lf5e600_0005e69c\n"
        "movl %eax, (%esp)\n" /* line 1408 */
        "calll FX_RegisterEffect\n"
        "testl %eax, %eax\n" /* line 1410 */
        "je .Lf5e600_0005e686\n"
        "movl %eax, 4(%esp)\n" /* line 1412 */
        "leal 0x78(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_AddEffect\n"
        "jmp .Lf5e600_0005e646\n"
        ".Lf5e600_0005e686:\n"
        "movl $str_0021a240, (%esp)\n" /* line 1416 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1431 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e600_0005e69c:\n"
        "movl $str_0021a26c, (%esp)\n" /* line 1423 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5e600_0005e655\n"
    );
}

/* line 1434 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseEmitterFxStrings(const PrimitiveTemplate * _this, GPValue *grp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1434 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* grp */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 1439 | grp */
        "calll GPValue_IsList\n"
        "testb %al, %al\n"
        "je .Lf5e6ac_0005e70c\n"
        /* { scope 2 */
        "movl 0x10(%ebx), %ebx\n" /* line 86 */
        "testl %ebx, %ebx\n" /* line 1444 | list */
        "je .Lf5e6ac_0005e6f5\n"
        "leal 0x80(%edi), %esi\n" /* this */
        ".Lf5e6ac_0005e6d4:\n"
        "movl (%ebx), %eax\n" /* line 1448 | list */
        "movl %eax, (%esp)\n"
        "calll FX_RegisterEffect\n"
        "testl %eax, %eax\n" /* line 1450 */
        "je .Lf5e6ac_0005e738\n"
        "movl %eax, 4(%esp)\n" /* line 1452 */
        "movl %esi, (%esp)\n"
        "calll MediaHandles_AddEffect\n"
        "movl 4(%ebx), %ebx\n" /* line 1460 | list */
        "testl %ebx, %ebx\n" /* line 1444 | list */
        "jne .Lf5e6ac_0005e6d4\n"
        /* } scope */
        ".Lf5e6ac_0005e6f5:\n"
        "orl $0x100, 0x90(%edi)\n" /* line 1490 | this */
        "movl $1, %eax\n"
        /* } scope */
        ".Lf5e6ac_0005e704:\n"
        "addl $0x1c, %esp\n" /* line 1493 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e6ac_0005e70c:\n"
        "movl %ebx, (%esp)\n" /* line 1466 | list */
        "calll GPValue_GetTopValue\n"
        "testl %eax, %eax\n" /* line 1468 */
        "je .Lf5e6ac_0005e74e\n"
        "movl %eax, (%esp)\n" /* line 1470 */
        "calll FX_RegisterEffect\n"
        "testl %eax, %eax\n" /* line 1472 */
        "je .Lf5e6ac_0005e738\n"
        "movl %eax, 4(%esp)\n" /* line 1474 */
        "leal 0x80(%edi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll MediaHandles_AddEffect\n"
        "jmp .Lf5e6ac_0005e6f5\n"
        ".Lf5e6ac_0005e738:\n"
        "movl $str_0021a2b0, (%esp)\n" /* line 1478 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1493 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e6ac_0005e74e:\n"
        "movl $str_0021a2dc, (%esp)\n" /* line 1485 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5e6ac_0005e704\n"
    );
}

/* line 1496 */
__attribute__((naked))
Bool PrimitiveTemplate_ParsePlayFxStrings(const PrimitiveTemplate * _this, GPValue *grp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1496 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* grp */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 1501 | grp */
        "calll GPValue_IsList\n"
        "testb %al, %al\n"
        "je .Lf5e75e_0005e7b2\n"
        /* { scope 2 */
        "movl 0x10(%ebx), %ebx\n" /* line 86 */
        "testl %ebx, %ebx\n" /* line 1506 | list */
        "je .Lf5e75e_0005e7a6\n"
        "movl 8(%ebp), %esi\n" /* this */
        "addl $0x88, %esi\n"
        ".Lf5e75e_0005e785:\n"
        "movl (%ebx), %eax\n" /* line 1510 | list */
        "movl %eax, (%esp)\n"
        "calll FX_RegisterEffect\n"
        "testl %eax, %eax\n" /* line 1512 */
        "je .Lf5e75e_0005e7ea\n"
        "movl %eax, 4(%esp)\n" /* line 1514 */
        "movl %esi, (%esp)\n"
        "calll MediaHandles_AddEffect\n"
        "movl 4(%ebx), %ebx\n" /* line 1522 | list */
        "testl %ebx, %ebx\n" /* line 1506 | list */
        "jne .Lf5e75e_0005e785\n"
        /* } scope */
        ".Lf5e75e_0005e7a6:\n"
        "movl $1, %eax\n" /* line 1548 */
        /* } scope */
        ".Lf5e75e_0005e7ab:\n"
        "addl $0x10, %esp\n" /* line 1553 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e75e_0005e7b2:\n"
        "movl %ebx, (%esp)\n" /* line 1528 | list */
        "calll GPValue_GetTopValue\n"
        "testl %eax, %eax\n" /* line 1530 */
        "je .Lf5e75e_0005e7ff\n"
        "movl %eax, (%esp)\n" /* line 1532 */
        "calll FX_RegisterEffect\n"
        "testl %eax, %eax\n" /* line 1534 */
        "je .Lf5e75e_0005e7ea\n"
        "movl %eax, 4(%esp)\n" /* line 1536 */
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x88, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MediaHandles_AddEffect\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1553 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e75e_0005e7ea:\n"
        "movl $str_0021a324, (%esp)\n" /* line 1540 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1553 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e75e_0005e7ff:\n"
        "movl $str_0021a348, (%esp)\n" /* line 1547 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5e75e_0005e7ab\n"
    );
}

/* line 1556 */
__attribute__((naked))
void PrimitiveTemplate_ParseChannelRgbCurve(const PrimitiveTemplate * _this, GPValue *pairs, FxChannelId channel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1556 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this, pairs */
        "movl %eax, -0x20(%ebp)\n" /* pairs, this */
        "movl 0x10(%ebp), %ecx\n" /* channel */
        "movl %ecx, -0x24(%ebp)\n" /* channel */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 86 | pairs */
        "movl 0x10(%eax), %esi\n"
        "testl %esi, %esi\n" /* line 1565 | list */
        "je .Lf5e810_0005e8ce\n"
        "movl %esi, %eax\n" /* list */
        "xorl %edx, %edx\n"
        ".Lf5e810_0005e837:\n"
        "addl $1, %edx\n" /* line 1566 */
        "movl 4(%eax), %eax\n" /* line 51 */
        "testl %eax, %eax\n" /* line 1565 */
        "jne .Lf5e810_0005e837\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        ".Lf5e810_0005e846:\n"
        "movl %eax, (%esp)\n" /* line 1571 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x1c(%ebp)\n" /* keys */
        "testl %esi, %esi\n" /* line 1574 | list */
        "je .Lf5e810_0005e8ca\n"
        "movl %eax, %ebx\n"
        "xorl %edi, %edi\n" /* keyCount */
        ".Lf5e810_0005e859:\n"
        "leal 0xc(%ebx), %eax\n" /* line 1575 */
        "movl %eax, 0x14(%esp)\n"
        "leal 8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal 4(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $str_0021a38c, 4(%esp)\n" /* "%f %f %f %f" */
        "movl (%esi), %eax\n" /* list */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        "addl $1, %edi\n" /* line 1574 | keyCount */
        "movl 4(%esi), %esi\n" /* line 51 */
        "addl $0x10, %ebx\n"
        "testl %esi, %esi\n" /* line 1574 | list */
        "jne .Lf5e810_0005e859\n"
        ".Lf5e810_0005e891:\n"
        "movl %edi, 8(%esp)\n" /* line 1580 | keyCount */
        "movl $3, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* keys */
        "movl %eax, (%esp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl -0x24(%ebp), %ecx\n" /* channel */
        "leal (%ecx, %ecx, 2), %edx\n"
        "movl -0x20(%ebp), %ecx\n" /* this */
        "movl %eax, 0x100(%ecx, %edx, 4)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1585 | keys */
        "movl %eax, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1587 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Hunk_FreeTempMemory\n" /* line 1585 */
        ".Lf5e810_0005e8ca:\n"
        "xorl %edi, %edi\n" /* line 1574 | keyCount */
        "jmp .Lf5e810_0005e891\n"
        ".Lf5e810_0005e8ce:\n"
        "xorl %eax, %eax\n" /* line 1565 */
        "jmp .Lf5e810_0005e846\n"
    );
}

/* line 626 */
__attribute__((naked))
void PrimitiveTemplate_CreateBackCompatibleRotationDeltaCurve(const PrimitiveTemplate * _this, float initialValue, float keyScale, float lifetime, int channelId, float graphScale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 626 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movss 0xc(%ebp), %xmm7\n" /* initialValue */
        "movss 0x10(%ebp), %xmm5\n" /* keyScale */
        "movss 0x14(%ebp), %xmm1\n" /* lifetime */
        "movl 0x18(%ebp), %esi\n" /* channelId */
        "movl 0x1c(%ebp), %edi\n" /* graphScale */
        /* { scope 1 */
        "divss lit4_002ed694, %xmm1\n" /* line 653 | 20.0f */
        "mulss lit4_002ed698, %xmm1\n" /* 0.0006500000017695129f */
        "movss lit4_002ed5d0, %xmm0\n" /* line 184 | 1.0f */
        "movaps %xmm1, %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "ucomiss %xmm4, %xmm5\n"
        "je .Lf5e8d6_0005e9d7\n"
        ".Lf5e8d6_0005e92d:\n"
        "ucomiss %xmm2, %xmm4\n" /* line 657 */
        "ja .Lf5e8d6_0005ea7a\n"
        "ucomiss %xmm3, %xmm4\n"
        "ja .Lf5e8d6_0005ea34\n"
        "xorl %ecx, %ecx\n"
        "movss lit4_002ed69c, %xmm3\n" /* 19.0f */
        "jmp .Lf5e8d6_0005e962\n"
        ".Lf5e8d6_0005e94b:\n"
        "movaps %xmm7, %xmm0\n" /* line 648 */
        "divss %xmm5, %xmm0\n"
        "movss %xmm0, -0xb4(%ebp)\n"
        "addl $1, %ecx\n" /* line 634 */
        "cmpl $0x14, %ecx\n"
        "je .Lf5e8d6_0005e994\n"
        ".Lf5e8d6_0005e962:\n"
        "leal (, %ecx, 8), %edx\n" /* line 626 */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 636 */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp, %edx)\n"
        "testl %ecx, %ecx\n" /* line 641 */
        "je .Lf5e8d6_0005e94b\n"
        "movl -0xbc(%ebp, %edx), %eax\n" /* line 657 */
        "movl %eax, -0xb4(%ebp, %edx)\n"
        "addl $1, %ecx\n" /* line 634 */
        "cmpl $0x14, %ecx\n"
        "jne .Lf5e8d6_0005e962\n"
        ".Lf5e8d6_0005e994:\n"
        "movl $0x14, 8(%esp)\n" /* line 667 */
        "movl $1, 4(%esp)\n"
        "leal -0xb8(%ebp), %eax\n" /* keys */
        "movl %eax, (%esp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "leal (%esi, %esi, 2), %edx\n" /* channelId */
        "shll $2, %edx\n"
        "movl %eax, 0x100(%edx, %ebx)\n"
        "leal 0x100(%edx, %ebx), %edx\n" /* line 668 */
        "movl %edi, 4(%edx)\n" /* line 2201 | graphScale */
        "movl %edi, 8(%edx)\n" /* line 2202 | graphScale */
        /* } scope */
        "addl $0xbc, %esp\n" /* line 669 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5e8d6_0005e9d7:\n"
        "jp .Lf5e8d6_0005e92d\n" /* line 184 */
        "ucomiss %xmm2, %xmm4\n" /* line 657 */
        "ja .Lf5e8d6_0005eb0a\n"
        "ucomiss %xmm3, %xmm4\n" /* line 644 */
        "ja .Lf5e8d6_0005eac9\n"
        "xorl %ecx, %ecx\n"
        "movss lit4_002ed69c, %xmm3\n" /* 19.0f */
        ".Lf5e8d6_0005e9f9:\n"
        "leal (, %ecx, 8), %edx\n" /* line 626 */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 636 */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp, %edx)\n"
        "testl %ecx, %ecx\n" /* line 641 */
        "je .Lf5e8d6_0005ebb2\n"
        "movl -0xbc(%ebp, %edx), %eax\n" /* line 657 */
        "movl %eax, -0xb4(%ebp, %edx)\n"
        ".Lf5e8d6_0005ea27:\n"
        "addl $1, %ecx\n" /* line 634 */
        "cmpl $0x14, %ecx\n"
        "jne .Lf5e8d6_0005e9f9\n"
        "jmp .Lf5e8d6_0005e994\n"
        ".Lf5e8d6_0005ea34:\n"
        "xorl %ecx, %ecx\n" /* line 657 */
        "movss lit4_002ed69c, %xmm3\n" /* 19.0f */
        ".Lf5e8d6_0005ea3e:\n"
        "leal (, %ecx, 8), %edx\n" /* line 626 */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 636 */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp, %edx)\n"
        "testl %ecx, %ecx\n" /* line 641 */
        "jne .Lf5e8d6_0005ec23\n"
        "movaps %xmm7, %xmm0\n" /* line 648 */
        "divss %xmm5, %xmm0\n"
        "movss %xmm0, -0xb4(%ebp)\n"
        ".Lf5e8d6_0005ea6d:\n"
        "addl $1, %ecx\n" /* line 634 */
        "cmpl $0x14, %ecx\n"
        "jne .Lf5e8d6_0005ea3e\n"
        "jmp .Lf5e8d6_0005e994\n"
        ".Lf5e8d6_0005ea7a:\n"
        "ucomiss %xmm3, %xmm4\n" /* line 657 */
        "ja .Lf5e8d6_0005ebda\n"
        "xorl %edx, %edx\n"
        "movss lit4_002ed69c, %xmm3\n" /* 19.0f */
        ".Lf5e8d6_0005ea8d:\n"
        "leal (, %edx, 8), %eax\n" /* line 626 */
        "cvtsi2ssl %edx, %xmm0\n" /* line 636 */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp, %eax)\n"
        "testl %edx, %edx\n" /* line 641 */
        "jne .Lf5e8d6_0005ebbf\n"
        "movaps %xmm7, %xmm0\n" /* line 648 */
        "divss %xmm5, %xmm0\n"
        "movss %xmm0, -0xb4(%ebp)\n"
        ".Lf5e8d6_0005eabc:\n"
        "addl $1, %edx\n" /* line 634 */
        "cmpl $0x14, %edx\n"
        "jne .Lf5e8d6_0005ea8d\n"
        "jmp .Lf5e8d6_0005e994\n"
        ".Lf5e8d6_0005eac9:\n"
        "xorl %ecx, %ecx\n" /* line 657 */
        "movss lit4_002ed69c, %xmm3\n" /* 19.0f */
        ".Lf5e8d6_0005ead3:\n"
        "leal (, %ecx, 8), %edx\n" /* line 626 */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 636 */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp, %edx)\n"
        "testl %ecx, %ecx\n" /* line 641 */
        "je .Lf5e8d6_0005eb58\n"
        "movl -0xbc(%ebp, %edx), %eax\n" /* line 657 */
        "movl %eax, -0xb4(%ebp, %edx)\n"
        ".Lf5e8d6_0005eafd:\n"
        "addl $1, %ecx\n" /* line 634 */
        "cmpl $0x14, %ecx\n"
        "jne .Lf5e8d6_0005ead3\n"
        "jmp .Lf5e8d6_0005e994\n"
        ".Lf5e8d6_0005eb0a:\n"
        "ucomiss %xmm3, %xmm4\n" /* line 644 */
        "ja .Lf5e8d6_0005eb6c\n"
        "xorl %edx, %edx\n"
        "movss lit4_002ed69c, %xmm3\n" /* 19.0f */
        ".Lf5e8d6_0005eb19:\n"
        "leal (, %edx, 8), %eax\n" /* line 626 */
        "cvtsi2ssl %edx, %xmm0\n" /* line 636 */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp, %eax)\n"
        "testl %edx, %edx\n" /* line 641 */
        "je .Lf5e8d6_0005eb62\n"
        "movss -0xbc(%ebp, %eax), %xmm0\n" /* line 657 */
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xb4(%ebp, %eax)\n"
        ".Lf5e8d6_0005eb4b:\n"
        "addl $1, %edx\n" /* line 634 */
        "cmpl $0x14, %edx\n"
        "jne .Lf5e8d6_0005eb19\n"
        "jmp .Lf5e8d6_0005e994\n"
        ".Lf5e8d6_0005eb58:\n"
        "movss %xmm7, -0xb4(%ebp)\n" /* line 644 */
        "jmp .Lf5e8d6_0005eafd\n"
        ".Lf5e8d6_0005eb62:\n"
        "movss %xmm7, -0xb4(%ebp)\n"
        "jmp .Lf5e8d6_0005eb4b\n"
        ".Lf5e8d6_0005eb6c:\n"
        "xorl %edx, %edx\n" /* line 184 */
        "movss lit4_002ed69c, %xmm3\n" /* 19.0f */
        "movaps %xmm0, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        ".Lf5e8d6_0005eb7d:\n"
        "leal (, %edx, 8), %eax\n" /* line 626 */
        "cvtsi2ssl %edx, %xmm0\n" /* line 636 */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp, %eax)\n"
        "testl %edx, %edx\n" /* line 641 */
        "jne .Lf5e8d6_0005ec36\n"
        "movss %xmm7, -0xb4(%ebp)\n" /* line 644 */
        ".Lf5e8d6_0005eba5:\n"
        "addl $1, %edx\n" /* line 634 */
        "cmpl $0x14, %edx\n"
        "jne .Lf5e8d6_0005eb7d\n"
        "jmp .Lf5e8d6_0005e994\n"
        ".Lf5e8d6_0005ebb2:\n"
        "movss %xmm7, -0xb4(%ebp)\n" /* line 644 */
        "jmp .Lf5e8d6_0005ea27\n"
        ".Lf5e8d6_0005ebbf:\n"
        "movss -0xbc(%ebp, %eax), %xmm0\n" /* line 657 */
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0xb4(%ebp, %eax)\n"
        "jmp .Lf5e8d6_0005eabc\n"
        ".Lf5e8d6_0005ebda:\n"
        "xorl %edx, %edx\n" /* line 669 */
        "movss lit4_002ed69c, %xmm3\n" /* 19.0f */
        "movaps %xmm0, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        ".Lf5e8d6_0005ebeb:\n"
        "leal (, %edx, 8), %eax\n" /* line 626 */
        "cvtsi2ssl %edx, %xmm0\n" /* line 636 */
        "divss %xmm3, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp, %eax)\n"
        "testl %edx, %edx\n" /* line 641 */
        "jne .Lf5e8d6_0005ec50\n"
        "movaps %xmm7, %xmm0\n" /* line 648 */
        "divss %xmm5, %xmm0\n"
        "movss %xmm0, -0xb4(%ebp)\n"
        ".Lf5e8d6_0005ec16:\n"
        "addl $1, %edx\n" /* line 634 */
        "cmpl $0x14, %edx\n"
        "jne .Lf5e8d6_0005ebeb\n"
        "jmp .Lf5e8d6_0005e994\n"
        ".Lf5e8d6_0005ec23:\n"
        "movl -0xbc(%ebp, %edx), %eax\n" /* line 657 */
        "movl %eax, -0xb4(%ebp, %edx)\n"
        "jmp .Lf5e8d6_0005ea6d\n"
        ".Lf5e8d6_0005ec36:\n"
        "movaps %xmm2, %xmm0\n"
        "mulss -0xbc(%ebp, %eax), %xmm0\n"
        "movss %xmm0, -0xb4(%ebp, %eax)\n"
        "jmp .Lf5e8d6_0005eba5\n"
        ".Lf5e8d6_0005ec50:\n"
        "movaps %xmm2, %xmm0\n"
        "mulss -0xbc(%ebp, %eax), %xmm0\n"
        "movss %xmm0, -0xb4(%ebp, %eax)\n"
        "jmp .Lf5e8d6_0005ec16\n"
    );
}

/* line 1206 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseMaterials(const PrimitiveTemplate * _this, GPValue *grp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1206 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "cmpb $0, g_rendererExists\n" /* line 1211 */
        "jne .Lf5ec68_0005ec85\n"
        ".Lf5ec68_0005ec79:\n"
        "movl $1, %eax\n" /* line 1249 */
        /* } scope */
        ".Lf5ec68_0005ec7e:\n"
        "addl $0x10, %esp\n" /* line 1254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5ec68_0005ec85:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1219 | grp */
        "movl %eax, (%esp)\n"
        "calll GPValue_IsList\n"
        "testb %al, %al\n"
        "je .Lf5ec68_0005ecd3\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 86 | grp */
        "movl 0x10(%eax), %ebx\n"
        "testl %ebx, %ebx\n" /* line 1224 | list */
        "je .Lf5ec68_0005ec79\n"
        "movl 8(%ebp), %eax\n" /* this */
        "leal 0x68(%eax), %esi\n"
        ".Lf5ec68_0005eca4:\n"
        "movl $6, 8(%esp)\n" /* line 2156 */
        "movl $3, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* list */
        "movl %eax, (%esp)\n"
        "calll Material_RegisterHandle\n"
        "movl %eax, 4(%esp)\n" /* line 1230 */
        "movl %esi, (%esp)\n"
        "calll MediaHandles_AddHandle\n"
        "movl 4(%ebx), %ebx\n" /* line 1232 | list */
        "testl %ebx, %ebx\n" /* line 1224 | list */
        "jne .Lf5ec68_0005eca4\n"
        "jmp .Lf5ec68_0005ec79\n"
        /* } scope */
        ".Lf5ec68_0005ecd3:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1238 | grp */
        "movl %eax, (%esp)\n"
        "calll GPValue_GetTopValue\n"
        "testl %eax, %eax\n" /* line 1240 */
        "je .Lf5ec68_0005ed18\n"
        "movl $6, 8(%esp)\n" /* line 2156 */
        "movl $3, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Material_RegisterHandle\n"
        "movl %eax, 4(%esp)\n" /* line 1243 */
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x68, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MediaHandles_AddHandle\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5ec68_0005ed18:\n"
        "movl $str_0021a3ac, (%esp)\n" /* line 1248 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5ec68_0005ec7e\n"
    );
}

/* line 852 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseFlags(const PrimitiveTemplate * _this, const char *line, const FxFlagEntry *flagEntries, int flagEntryCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 852 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "cld\n" /* line 864 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* line */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, %ebx\n" /* line 865 */
        "subl $1, %ebx\n"
        "jne .Lf5ed2c_0005ed57\n"
        "xorl %edi, %edi\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 898 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5ed2c_0005ed57:\n"
        "movl %ebx, (%esp)\n" /* line 868 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x24(%ebp)\n" /* flag */
        "movl 0xc(%ebp), %eax\n" /* line 869 | line */
        "testl %ebx, %ebx\n" /* line 873 */
        "jg .Lf5ed2c_0005ed83\n"
        ".Lf5ed2c_0005ed69:\n"
        "movl $1, %edi\n"
        ".Lf5ed2c_0005ed6e:\n"
        "movl -0x24(%ebp), %eax\n" /* line 895 | flag */
        "movl %eax, (%esp)\n"
        "calll Hunk_FreeTempMemory\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 898 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5ed2c_0005ed83:\n"
        "movl $0, -0x20(%ebp)\n" /* line 873 | parsedLength */
        ".Lf5ed2c_0005ed8a:\n"
        "movl -0x24(%ebp), %edx\n" /* line 875 | flag */
        "movl %edx, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        "subl $1, %eax\n"
        "jne .Lf5ed2c_0005edc2\n"
        "cld\n" /* line 881 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x24(%ebp), %edi\n" /* flag */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* flagLength */
        /* { scope 2 */
        "movl 0x14(%ebp), %edx\n" /* line 837 | flagEntryCount */
        "testl %edx, %edx\n"
        "jg .Lf5ed2c_0005edc6\n"
        /* } scope */
        ".Lf5ed2c_0005edc2:\n"
        "xorl %edi, %edi\n" /* line 873 */
        "jmp .Lf5ed2c_0005ed6e\n"
        /* { scope 2 */
        ".Lf5ed2c_0005edc6:\n"
        "movl 0x10(%ebp), %edi\n" /* line 837 | flagEntries */
        "xorl %esi, %esi\n" /* entryIndex */
        ".Lf5ed2c_0005edcb:\n"
        "movl -0x24(%ebp), %edx\n" /* line 840 | flag */
        "movl %edx, 4(%esp)\n"
        "movl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5ed2c_0005edf2\n"
        "addl $1, %esi\n" /* line 837 | entryIndex */
        "addl $0xc, %edi\n"
        "cmpl %esi, 0x14(%ebp)\n" /* entryIndex, flagEntryCount */
        "jne .Lf5ed2c_0005edcb\n"
        /* } scope */
        "xorl %edi, %edi\n" /* line 873 */
        "jmp .Lf5ed2c_0005ed6e\n"
        /* { scope 2 */
        ".Lf5ed2c_0005edf2:\n"
        "movl 8(%ebp), %edx\n" /* line 842 | this */
        "movl 0x90(%edx), %eax\n"
        "orl 4(%edi), %eax\n"
        "movl %eax, 0x90(%edx)\n"
        "movl 0x94(%edx), %eax\n" /* line 843 */
        "orl 8(%edi), %eax\n"
        "movl %eax, 0x94(%edx)\n"
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 891 | parsedLength */
        "movl -0x1c(%ebp), %edx\n" /* flagLength */
        "leal 1(%eax, %edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* parsedLength */
        "movl 0xc(%ebp), %eax\n" /* line 892 | line */
        "addl -0x20(%ebp), %eax\n" /* parsedLength */
        "cmpl -0x20(%ebp), %ebx\n" /* line 873 | parsedLength */
        "jg .Lf5ed2c_0005ed8a\n"
        "jmp .Lf5ed2c_0005ed69\n"
    );
}

/* line 1257 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseModels(const PrimitiveTemplate * _this, GPValue *grp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1257 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* grp */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 1262 | val */
        "calll GPValue_IsList\n"
        "testb %al, %al\n"
        "je .Lf5ee34_0005eeb0\n"
        /* { scope 2 */
        "movl 0x10(%ebx), %esi\n" /* line 86 */
        "testl %esi, %esi\n" /* line 1267 | list */
        "je .Lf5ee34_0005eea3\n"
        "movl 8(%ebp), %edi\n" /* this */
        "addl $0x68, %edi\n"
        ".Lf5ee34_0005ee59:\n"
        "movl (%esi), %ebx\n" /* line 49 */
        /* { scope 3 */
        "movl %ebx, (%esp)\n" /* line 2165 | val */
        "calll Com_ValidXModelName\n"
        "testb %al, %al\n"
        "jne .Lf5ee34_0005ee81\n"
        /* } scope */
        ".Lf5ee34_0005ee67:\n"
        "movl %ebx, 4(%esp)\n" /* line 1275 | val */
        "movl $str_0021a3ec, (%esp)\n" /* "PrimitiveTemplate::ParseModels, could not register model '%s" */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf5ee34_0005ee79:\n"
        "addl $0x1c, %esp\n" /* line 1307 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf5ee34_0005ee81:\n"
        "leal 7(%ebx), %eax\n" /* line 2171 | val */
        "movl %eax, (%esp)\n"
        "calll FX_XModelPrecache\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1273 */
        "je .Lf5ee34_0005ee67\n"
        "movl %eax, 4(%esp)\n" /* line 1279 */
        "movl %edi, (%esp)\n"
        "calll MediaHandles_AddHandle\n"
        "movl 4(%esi), %esi\n" /* line 1281 | list */
        "testl %esi, %esi\n" /* line 1267 | list */
        "jne .Lf5ee34_0005ee59\n"
        /* } scope */
        ".Lf5ee34_0005eea3:\n"
        "movl $1, %eax\n" /* line 1303 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1307 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5ee34_0005eeb0:\n"
        "movl %ebx, (%esp)\n" /* line 1287 | val */
        "calll GPValue_GetTopValue\n"
        "movl %eax, %ebx\n" /* val */
        "testl %eax, %eax\n" /* line 1289 */
        "je .Lf5ee34_0005eef2\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 2165 */
        "calll Com_ValidXModelName\n"
        "testb %al, %al\n"
        "je .Lf5ee34_0005ee67\n"
        "leal 7(%ebx), %eax\n" /* line 2171 | val */
        "movl %eax, (%esp)\n"
        "calll FX_XModelPrecache\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1297 */
        "je .Lf5ee34_0005ee67\n"
        "movl %eax, 4(%esp)\n" /* line 1303 */
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x68, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MediaHandles_AddHandle\n"
        "movl $1, %eax\n"
        "jmp .Lf5ee34_0005ee79\n"
        ".Lf5ee34_0005eef2:\n"
        "movl $str_0021a42c, (%esp)\n" /* line 1292 */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5ee34_0005ee79\n"
    );
}

/* line 718 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseRotationDelta(const PrimitiveTemplate * _this, const char *val)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 718 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        /* { scope 2 */
        "leal -0x10(%ebp), %eax\n" /* line 311 | max, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0xc(%ebp), %eax\n" /* min, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl 0xc(%ebp), %eax\n" /* val, v */
        "movl %eax, (%esp)\n" /* v */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5ef06_0005efc0\n"
        "subl $1, %eax\n" /* line 317 */
        "je .Lf5ef06_0005f018\n"
        /* } scope */
        "movss -0xc(%ebp), %xmm2\n" /* line 726 | min */
        "movaps %xmm2, %xmm1\n"
        "movss -0x10(%ebp), %xmm0\n" /* max */
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf5ef06_0005efc6\n"
        ".Lf5ef06_0005ef54:\n"
        "cvttss2si %xmm2, %eax\n" /* line 617 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movaps %xmm1, %xmm3\n"
        "cmpnltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm3\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm3, %xmm1\n"
        "addss %xmm1, %xmm1\n" /* line 732 */
        "movss %xmm1, 0x14(%esp)\n" /* line 734 */
        "movl $0xa, 0x10(%esp)\n"
        "movl 0x58(%ebx), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss %xmm2, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "movss %xmm1, -0x28(%ebp)\n"
        "calll PrimitiveTemplate_CreateBackCompatibleRotationDeltaCurve\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 736 | min */
        "movss -0x28(%ebp), %xmm1\n"
        "ucomiss -0x10(%ebp), %xmm0\n" /* max */
        "jne .Lf5ef06_0005efdb\n"
        "jp .Lf5ef06_0005efdb\n"
        "movl $1, %eax\n" /* line 739 */
        /* } scope */
        ".Lf5ef06_0005efc0:\n"
        "addl $0x44, %esp\n" /* line 746 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5ef06_0005efc6:\n"
        "movaps %xmm0, %xmm2\n" /* line 117 */
        "movss %xmm0, -0xc(%ebp)\n" /* min */
        "movss %xmm1, -0x10(%ebp)\n" /* line 118 | max */
        "movaps %xmm1, %xmm0\n"
        "jmp .Lf5ef06_0005ef54\n"
        ".Lf5ef06_0005efdb:\n"
        "orl $0x40000, 0x90(%ebx)\n" /* line 738 | this */
        "movl $0x3f800000, 0x14(%esp)\n" /* line 739 */
        "movl $0xb, 0x10(%esp)\n"
        "movl 0x5c(%ebx), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movl -0x10(%ebp), %eax\n" /* max */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll PrimitiveTemplate_CreateBackCompatibleRotationDeltaCurve\n"
        "movl $1, %eax\n"
        "jmp .Lf5ef06_0005efc0\n"
        /* { scope 2 */
        ".Lf5ef06_0005f018:\n"
        "movl -0xc(%ebp), %eax\n" /* line 319 | min */
        "movl %eax, -0x10(%ebp)\n" /* max */
        /* } scope */
        "movss -0xc(%ebp), %xmm2\n" /* line 726 | min */
        "movaps %xmm2, %xmm1\n"
        "movss -0x10(%ebp), %xmm0\n" /* max */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf5ef06_0005ef54\n"
        "jmp .Lf5ef06_0005efc6\n"
    );
}

/* line 1633 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseChannel(const PrimitiveTemplate * _this, BackCompatibleParameters *backCompatibleParameters, GPGroup *grp, FxChannelId channelId, const PrimitiveTemplate * _this_4, const char *val, const PrimitiveTemplate * _this_6, const char *val_7, const PrimitiveTemplate * _this_8, const char *val_9, const PrimitiveTemplate * _this_10, const char *val_11)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1633 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1: min, max, min, max */
        "movl 0x10(%ebp), %eax\n" /* line 121 | grp */
        "movl 0x10(%eax), %esi\n"
        "testl %esi, %esi\n" /* line 1642 | pairs */
        "je 0x5f124\n"
        "movl 0x14(%ebp), %eax\n" /* channelId */
        "shll $6, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* backCompatibleParameters */
        "addl %eax, %edx\n"
        "movl %edx, -0x3c(%ebp)\n" /* this */
        "addl $0x30, %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl -0x3c(%ebp), %ecx\n" /* this */
        "movl %ecx, -0x4c(%ebp)\n"
        "movl %edx, -0x50(%ebp)\n"
        "movl 0x14(%ebp), %edx\n" /* channelId */
        "leal (%edx, %edx, 2), %eax\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "leal 0x100(%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "jmp .Lf5f038_0005f0ad\n"
        ".Lf5f038_0005f084:\n"
        "cmpl $1, 0x14(%ebp)\n" /* line 1650 | channelId */
        "jbe 0x5f1bc\n"
        "movl 0x14(%ebp), %ecx\n" /* line 1653 | channelId */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* pairs */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_ParseChannelCurve\n"
        "movl 4(%esi), %eax\n" /* line 80 */
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 1642 */
        "je 0x5f124\n"
        ".Lf5f038_0005f0ad:\n"
        "movl (%esi), %ebx\n" /* line 49 */
        "movl %esi, (%esp)\n" /* line 1646 | pairs */
        "calll GPValue_GetTopValue\n"
        "movl %eax, %edi\n" /* val */
        "movl $str_0021a468, 4(%esp)\n" /* line 1648 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5f038_0005f084\n"
        "movl $str_0021a470, 4(%esp)\n" /* line 1655 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne 0x5f131\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x1c(%ebp), %edx\n" /* line 311 | max */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x20(%ebp), %ecx\n" /* min */
        "movl %ecx, 8(%esp)\n"
    );
}

/* line 781 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseVelocity(const PrimitiveTemplate * _this, const char *val)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 781 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1: keys */
        /* { scope 2: keys */
        "leal -0x24(%ebp), %edx\n" /* line 335 | max */
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, 0x1c(%esp)\n" /* v */
        "leal -0x20(%ebp), %eax\n" /* v */
        "movl %eax, 0x18(%esp)\n" /* v */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* min */
        "leal -0x28(%ebp), %eax\n" /* v */
        "movl %eax, 0x10(%esp)\n" /* v */
        "leal -0x2c(%ebp), %eax\n" /* v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "movl %edx, 8(%esp)\n"
        "movl $str_0021a398, 4(%esp)\n" /* "%f %f %f   %f %f %f" */
        "movl 0xc(%ebp), %eax\n" /* val, v */
        "movl %eax, (%esp)\n" /* v */
        "calll sscanf\n"
        "cmpl $2, %eax\n" /* line 338 */
        "jle .Lf5f4fa_0005f8cc\n"
        "cmpl $4, %eax\n"
        "je .Lf5f4fa_0005f8cc\n"
        "cmpl $5, %eax\n"
        "je .Lf5f4fa_0005f8cc\n"
        "cmpl $3, %eax\n" /* line 342 */
        "je .Lf5f4fa_0005f93e\n"
        /* } scope */
        ".Lf5f4fa_0005f567:\n"
        "movss -0x30(%ebp), %xmm6\n" /* line 790 | min */
        "movaps %xmm6, %xmm0\n"
        "ucomiss -0x24(%ebp), %xmm6\n" /* max */
        "ja .Lf5f4fa_0005f91b\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 792 */
        "movaps %xmm1, %xmm0\n"
        "ucomiss -0x20(%ebp), %xmm1\n"
        "ja .Lf5f4fa_0005f8f8\n"
        ".Lf5f4fa_0005f58b:\n"
        "movss -0x28(%ebp), %xmm4\n" /* line 794 */
        "movaps %xmm4, %xmm0\n"
        "ucomiss -0x1c(%ebp), %xmm4\n"
        "ja .Lf5f4fa_0005f8e4\n"
        ".Lf5f4fa_0005f59d:\n"
        "movss -0x24(%ebp), %xmm3\n" /* line 797 | max */
        "cvttss2si %xmm6, %eax\n" /* line 617 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "maxss %xmm0, %xmm3\n"
        "movss -0x20(%ebp), %xmm2\n" /* line 798 */
        "cvttss2si %xmm1, %eax\n" /* line 617 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "maxss %xmm0, %xmm2\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 799 */
        "cvttss2si %xmm4, %eax\n" /* line 617 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "maxss %xmm0, %xmm1\n"
        "addss %xmm3, %xmm3\n" /* line 802 */
        "addss %xmm2, %xmm2\n" /* line 803 */
        "addss %xmm1, %xmm1\n" /* line 804 */
        "movaps %xmm3, %xmm5\n" /* line 45 */
        "subss %xmm2, %xmm5\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm3, %xmm0\n"
        "cmpnltss %xmm4, %xmm5\n"
        "andps %xmm5, %xmm0\n"
        "andnps %xmm2, %xmm5\n"
        "orps %xmm0, %xmm5\n"
        "movaps %xmm5, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movaps %xmm5, %xmm2\n"
        "cmpnltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm5\n"
        /* { scope 2: keys */
        "movss %xmm4, -0x40(%ebp)\n" /* line 677 | keys */
        "ucomiss %xmm4, %xmm5\n" /* line 679 */
        "jne .Lf5f4fa_0005f8d6\n"
        "jp .Lf5f4fa_0005f8d6\n"
        "movss %xmm4, -0x3c(%ebp)\n" /* line 680 */
        ".Lf5f4fa_0005f64a:\n"
        "movl $0x3f800000, -0x38(%ebp)\n" /* line 684 */
        "movl -0x3c(%ebp), %eax\n" /* line 685 */
        "movl %eax, -0x34(%ebp)\n"
        "movl $2, 8(%esp)\n" /* line 690 */
        "movl $1, 4(%esp)\n"
        "leal -0x40(%ebp), %edi\n" /* keys */
        "movl %edi, (%esp)\n"
        "movss %xmm5, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x190(%esi)\n"
        "movss -0x58(%ebp), %xmm5\n" /* line 2201 */
        "movss %xmm5, 0x194(%esi)\n" /* this */
        "movss %xmm5, 0x198(%esi)\n" /* line 2202 | this */
        /* } scope */
        "movss -0x2c(%ebp), %xmm1\n" /* line 809 | initialValue */
        /* { scope 2: keys */
        /* { scope 3 */
        "pxor %xmm0, %xmm0\n" /* line 677 */
        "movss %xmm0, -0x40(%ebp)\n" /* keys */
        "ucomiss %xmm0, %xmm5\n" /* line 679 */
        "jne .Lf5f4fa_0005f963\n"
        "jp .Lf5f4fa_0005f963\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* line 680 */
        ".Lf5f4fa_0005f6b4:\n"
        "movl $0x3f800000, -0x38(%ebp)\n" /* line 684 */
        "movl -0x3c(%ebp), %eax\n" /* line 685 */
        "movl %eax, -0x34(%ebp)\n"
        "movl $2, 8(%esp)\n" /* line 690 */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movss %xmm5, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x19c(%esi)\n"
        "movss -0x58(%ebp), %xmm5\n" /* line 2201 */
        "movss %xmm5, 0x1a0(%esi)\n" /* this */
        "movss %xmm5, 0x1a4(%esi)\n" /* line 2202 | this */
        /* } scope */
        /* } scope */
        "movss -0x28(%ebp), %xmm1\n" /* line 810 | initialValue */
        /* { scope 2: keys */
        /* { scope 3 */
        "pxor %xmm0, %xmm0\n" /* line 677 */
        "movss %xmm0, -0x40(%ebp)\n" /* keys */
        "ucomiss %xmm0, %xmm5\n" /* line 679 */
        "jne .Lf5f4fa_0005f955\n"
        "jp .Lf5f4fa_0005f955\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* line 680 */
        ".Lf5f4fa_0005f71b:\n"
        "movl $0x3f800000, -0x38(%ebp)\n" /* line 684 */
        "movl -0x3c(%ebp), %eax\n" /* line 685 */
        "movl %eax, -0x34(%ebp)\n"
        "movl $2, 8(%esp)\n" /* line 690 */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movss %xmm5, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x1a8(%esi)\n"
        "movss -0x58(%ebp), %xmm5\n" /* line 2201 */
        "movss %xmm5, 0x1ac(%esi)\n" /* this */
        "movss %xmm5, 0x1b0(%esi)\n" /* line 2202 | this */
        /* } scope */
        /* } scope */
        "movss -0x30(%ebp), %xmm0\n" /* line 310 | min */
        "ucomiss -0x24(%ebp), %xmm0\n" /* max */
        "jne .Lf5f4fa_0005f789\n"
        "jp .Lf5f4fa_0005f789\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "ucomiss -0x20(%ebp), %xmm0\n"
        "jne .Lf5f4fa_0005f789\n"
        "jp .Lf5f4fa_0005f789\n"
        "movss -0x28(%ebp), %xmm0\n"
        "ucomiss -0x1c(%ebp), %xmm0\n"
        "je .Lf5f4fa_0005f99b\n"
        ".Lf5f4fa_0005f789:\n"
        "xorl %eax, %eax\n"
        ".Lf5f4fa_0005f78b:\n"
        "testl %eax, %eax\n" /* line 812 */
        "jne .Lf5f4fa_0005f8bf\n"
        "orl $0x80000, 0x90(%esi)\n" /* line 814 | this */
        "movss -0x24(%ebp), %xmm1\n" /* line 816 | max, initialValue */
        /* { scope 2: keys */
        /* { scope 3 */
        "pxor %xmm0, %xmm0\n" /* line 677 */
        "movss %xmm0, -0x40(%ebp)\n" /* keys */
        "ucomiss %xmm0, %xmm5\n" /* line 679 */
        "jne .Lf5f4fa_0005f98d\n"
        "jp .Lf5f4fa_0005f98d\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* line 680 */
        ".Lf5f4fa_0005f7bf:\n"
        "movl $0x3f800000, %ebx\n" /* line 684 */
        "movl %ebx, -0x38(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 685 */
        "movl %eax, -0x34(%ebp)\n"
        "movl $2, 8(%esp)\n" /* line 690 */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movss %xmm5, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x1b4(%esi)\n"
        "movl %ebx, 0x1b8(%esi)\n" /* line 2201 | this */
        "movl %ebx, 0x1bc(%esi)\n" /* line 2202 | this */
        /* } scope */
        /* } scope */
        "movss -0x20(%ebp), %xmm1\n" /* line 817 | initialValue */
        /* { scope 2: keys */
        /* { scope 3 */
        "pxor %xmm0, %xmm0\n" /* line 677 */
        "movss %xmm0, -0x40(%ebp)\n" /* keys */
        "movss -0x58(%ebp), %xmm5\n" /* line 679 */
        "ucomiss %xmm0, %xmm5\n"
        "jne .Lf5f4fa_0005f97f\n"
        "jp .Lf5f4fa_0005f97f\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* line 680 */
        ".Lf5f4fa_0005f823:\n"
        "movl $0x3f800000, %ebx\n" /* line 684 */
        "movl %ebx, -0x38(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 685 */
        "movl %eax, -0x34(%ebp)\n"
        "movl $2, 8(%esp)\n" /* line 690 */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movss %xmm5, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x1c0(%esi)\n"
        "movl %ebx, 0x1c4(%esi)\n" /* line 2201 | this */
        "movl %ebx, 0x1c8(%esi)\n" /* line 2202 | this */
        /* } scope */
        /* } scope */
        "movss -0x1c(%ebp), %xmm1\n" /* line 818 | initialValue */
        /* { scope 2: keys */
        /* { scope 3 */
        "pxor %xmm0, %xmm0\n" /* line 677 */
        "movss %xmm0, -0x40(%ebp)\n" /* keys */
        "movss -0x58(%ebp), %xmm5\n" /* line 679 */
        "ucomiss %xmm0, %xmm5\n"
        "jne .Lf5f4fa_0005f971\n"
        "jp .Lf5f4fa_0005f971\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* line 680 */
        ".Lf5f4fa_0005f887:\n"
        "movl $0x3f800000, %ebx\n" /* line 684 */
        "movl %ebx, -0x38(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 685 */
        "movl %eax, -0x34(%ebp)\n"
        "movl $2, 8(%esp)\n" /* line 690 */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x1cc(%esi)\n"
        "movl %ebx, 0x1d0(%esi)\n" /* line 2201 | this */
        "movl %ebx, 0x1d4(%esi)\n" /* line 2202 | this */
        ".Lf5f4fa_0005f8bf:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 825 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keys */
        ".Lf5f4fa_0005f8cc:\n"
        "xorl %eax, %eax\n" /* line 788 */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 825 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keys */
        /* { scope 2: keys */
        ".Lf5f4fa_0005f8d6:\n"
        "divss %xmm5, %xmm6\n" /* line 682 */
        "movss %xmm6, -0x3c(%ebp)\n"
        "jmp .Lf5f4fa_0005f64a\n"
        /* } scope */
        ".Lf5f4fa_0005f8e4:\n"
        "movss -0x1c(%ebp), %xmm4\n" /* line 117 */
        "movss %xmm4, -0x28(%ebp)\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* line 118 */
        "jmp .Lf5f4fa_0005f59d\n"
        ".Lf5f4fa_0005f8f8:\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 117 */
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss %xmm0, -0x20(%ebp)\n" /* line 118 */
        "movss -0x28(%ebp), %xmm4\n" /* line 794 */
        "movaps %xmm4, %xmm0\n"
        "ucomiss -0x1c(%ebp), %xmm4\n"
        "jbe .Lf5f4fa_0005f59d\n"
        "jmp .Lf5f4fa_0005f8e4\n"
        ".Lf5f4fa_0005f91b:\n"
        "movss -0x24(%ebp), %xmm6\n" /* line 117 | max */
        "movss %xmm6, -0x30(%ebp)\n" /* min */
        "movss %xmm0, -0x24(%ebp)\n" /* line 118 | max */
        "movss -0x2c(%ebp), %xmm1\n" /* line 792 */
        "movaps %xmm1, %xmm0\n"
        "ucomiss -0x20(%ebp), %xmm1\n"
        "jbe .Lf5f4fa_0005f58b\n"
        "jmp .Lf5f4fa_0005f8f8\n"
        /* { scope 2: keys */
        ".Lf5f4fa_0005f93e:\n"
        "movl -0x30(%ebp), %eax\n" /* line 199 | min */
        "movl %eax, -0x24(%ebp)\n" /* max */
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "jmp .Lf5f4fa_0005f567\n"
        /* } scope */
        /* { scope 2: keys */
        /* { scope 3 */
        ".Lf5f4fa_0005f955:\n"
        "divss %xmm5, %xmm1\n" /* line 682 */
        "movss %xmm1, -0x3c(%ebp)\n"
        "jmp .Lf5f4fa_0005f71b\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keys */
        /* { scope 3 */
        ".Lf5f4fa_0005f963:\n"
        "divss %xmm5, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "jmp .Lf5f4fa_0005f6b4\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keys */
        /* { scope 3 */
        ".Lf5f4fa_0005f971:\n"
        "divss %xmm5, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "jmp .Lf5f4fa_0005f887\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keys */
        /* { scope 3 */
        ".Lf5f4fa_0005f97f:\n"
        "divss %xmm5, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "jmp .Lf5f4fa_0005f823\n"
        /* } scope */
        /* } scope */
        /* { scope 2: keys */
        /* { scope 3 */
        ".Lf5f4fa_0005f98d:\n"
        "divss %xmm5, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "jmp .Lf5f4fa_0005f7bf\n"
        /* } scope */
        /* } scope */
        ".Lf5f4fa_0005f99b:\n"
        "jp .Lf5f4fa_0005f789\n" /* line 310 */
        "movl $1, %eax\n"
        "jmp .Lf5f4fa_0005f78b\n"
    );
}

/* line 913 */
__attribute__((naked))
Bool PrimitiveTemplate_ParseAcceleration(const PrimitiveTemplate * _this, const char *val)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 913 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x70, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: keys */
        /* { scope 2 */
        "leal -0x14(%ebp), %edx\n" /* line 335 | max */
        "leal -0xc(%ebp), %eax\n" /* v */
        "movl %eax, 0x1c(%esp)\n" /* v */
        "leal -0x10(%ebp), %eax\n" /* v */
        "movl %eax, 0x18(%esp)\n" /* v */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x20(%ebp), %edx\n" /* min */
        "leal -0x18(%ebp), %eax\n" /* v */
        "movl %eax, 0x10(%esp)\n" /* v */
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "movl %edx, 8(%esp)\n"
        "movl $str_0021a398, 4(%esp)\n" /* "%f %f %f   %f %f %f" */
        "movl 0xc(%ebp), %eax\n" /* val, v */
        "movl %eax, (%esp)\n" /* v */
        "calll sscanf\n"
        "cmpl $2, %eax\n" /* line 338 */
        "jle .Lf5f9ac_0005fe02\n"
        "cmpl $4, %eax\n"
        "je .Lf5f9ac_0005fe02\n"
        "cmpl $5, %eax\n"
        "je .Lf5f9ac_0005fe02\n"
        "cmpl $3, %eax\n" /* line 342 */
        "je .Lf5f9ac_0005fe73\n"
        /* } scope */
        ".Lf5f9ac_0005fa18:\n"
        "movss -0x20(%ebp), %xmm5\n" /* line 923 | min */
        "movaps %xmm5, %xmm0\n"
        "ucomiss -0x14(%ebp), %xmm5\n" /* max */
        "ja .Lf5f9ac_0005fe50\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 925 */
        "movaps %xmm1, %xmm0\n"
        "ucomiss -0x10(%ebp), %xmm1\n"
        "ja .Lf5f9ac_0005fe2d\n"
        ".Lf5f9ac_0005fa3c:\n"
        "movss -0x18(%ebp), %xmm4\n" /* line 927 */
        "movaps %xmm4, %xmm0\n"
        "ucomiss -0xc(%ebp), %xmm4\n"
        "ja .Lf5f9ac_0005fe19\n"
        ".Lf5f9ac_0005fa4e:\n"
        "movss 0x5c(%ebx), %xmm0\n" /* line 930 | this */
        "movss %xmm0, -0x3c(%ebp)\n" /* maxScale */
        "movss -0x14(%ebp), %xmm3\n" /* line 932 | max */
        "cvttss2si %xmm5, %eax\n" /* line 617 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "maxss %xmm0, %xmm3\n"
        "movss -0x10(%ebp), %xmm2\n" /* line 933 */
        "cvttss2si %xmm1, %eax\n" /* line 617 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "maxss %xmm0, %xmm2\n"
        "movss -0xc(%ebp), %xmm1\n" /* line 934 */
        "cvttss2si %xmm4, %eax\n" /* line 617 */
        "movl %eax, %edx\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "maxss %xmm0, %xmm1\n"
        "addss %xmm3, %xmm3\n" /* line 937 */
        "addss %xmm2, %xmm2\n" /* line 938 */
        "addss %xmm1, %xmm1\n" /* line 939 */
        "movaps %xmm3, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm3, %xmm6\n"
        "cmpnltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm6\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm6, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm3\n"
        "cmpnltss %xmm4, %xmm2\n"
        "andps %xmm2, %xmm3\n"
        "andnps %xmm1, %xmm2\n"
        "orps %xmm3, %xmm2\n"
        "movss lit4_002ed658, %xmm1\n" /* line 942 | 0.0010000000474974513f */
        "movss -0x3c(%ebp), %xmm0\n" /* maxScale */
        "mulss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        /* { scope 2 */
        "movss %xmm4, -0x30(%ebp)\n" /* line 700 | keys */
        "movss %xmm4, -0x2c(%ebp)\n" /* line 701 */
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 702 */
        "movss -0x3c(%ebp), %xmm0\n" /* line 703 | maxScale */
        "mulss %xmm5, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "ucomiss %xmm4, %xmm2\n" /* line 705 */
        "jne .Lf5f9ac_0005fe0b\n"
        "jp .Lf5f9ac_0005fe0b\n"
        "movss %xmm4, -0x24(%ebp)\n" /* line 706 */
        ".Lf5f9ac_0005fb35:\n"
        "movl $2, 8(%esp)\n" /* line 713 */
        "movl $1, 4(%esp)\n"
        "leal -0x30(%ebp), %esi\n" /* keys */
        "movl %esi, (%esp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x1d8(%ebx)\n"
        "movss -0x58(%ebp), %xmm2\n" /* line 2201 */
        "movss %xmm2, 0x1dc(%ebx)\n" /* this */
        "movss %xmm2, 0x1e0(%ebx)\n" /* line 2202 | this */
        /* } scope */
        "movss -0x1c(%ebp), %xmm0\n" /* line 945 */
        /* { scope 2 */
        "pxor %xmm1, %xmm1\n" /* line 700 */
        "movss %xmm1, -0x30(%ebp)\n" /* keys */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 701 */
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 702 */
        "mulss -0x3c(%ebp), %xmm0\n" /* line 703 | maxScale */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x24(%ebp)\n"
        "ucomiss %xmm1, %xmm2\n" /* line 705 */
        "jne .Lf5f9ac_0005fe98\n"
        "jp .Lf5f9ac_0005fe98\n"
        "movss %xmm1, -0x24(%ebp)\n" /* line 706 */
        ".Lf5f9ac_0005fbb0:\n"
        "movl $2, 8(%esp)\n" /* line 713 */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x1e4(%ebx)\n"
        "movss -0x58(%ebp), %xmm2\n" /* line 2201 */
        "movss %xmm2, 0x1e8(%ebx)\n" /* this */
        "movss %xmm2, 0x1ec(%ebx)\n" /* line 2202 | this */
        /* } scope */
        "movss -0x18(%ebp), %xmm0\n" /* line 946 */
        /* { scope 2 */
        "pxor %xmm1, %xmm1\n" /* line 700 */
        "movss %xmm1, -0x30(%ebp)\n" /* keys */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 701 */
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 702 */
        "mulss -0x3c(%ebp), %xmm0\n" /* line 703 | maxScale */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x24(%ebp)\n"
        "ucomiss %xmm1, %xmm2\n" /* line 705 */
        "jne .Lf5f9ac_0005fe8a\n"
        "jp .Lf5f9ac_0005fe8a\n"
        "movss %xmm1, -0x24(%ebp)\n" /* line 706 */
        ".Lf5f9ac_0005fc28:\n"
        "movl $2, 8(%esp)\n" /* line 713 */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x1f0(%ebx)\n"
        "movss -0x58(%ebp), %xmm2\n" /* line 2201 */
        "movss %xmm2, 0x1f4(%ebx)\n" /* this */
        "movss %xmm2, 0x1f8(%ebx)\n" /* line 2202 | this */
        /* } scope */
        "movss -0x20(%ebp), %xmm0\n" /* line 310 | min */
        "ucomiss -0x14(%ebp), %xmm0\n" /* max */
        "jne .Lf5f9ac_0005fc89\n"
        "jp .Lf5f9ac_0005fc89\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "ucomiss -0x10(%ebp), %xmm0\n"
        "jne .Lf5f9ac_0005fc89\n"
        "jp .Lf5f9ac_0005fc89\n"
        "movss -0x18(%ebp), %xmm0\n"
        "ucomiss -0xc(%ebp), %xmm0\n"
        "je .Lf5f9ac_0005fed0\n"
        ".Lf5f9ac_0005fc89:\n"
        "xorl %eax, %eax\n"
        ".Lf5f9ac_0005fc8b:\n"
        "testl %eax, %eax\n" /* line 948 */
        "jne .Lf5f9ac_0005fdf6\n"
        "orl $0x100000, 0x90(%ebx)\n" /* line 950 | this */
        "movss -0x14(%ebp), %xmm0\n" /* line 952 | max */
        /* { scope 2 */
        "pxor %xmm1, %xmm1\n" /* line 700 */
        "movss %xmm1, -0x30(%ebp)\n" /* keys */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 701 */
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 702 */
        "mulss -0x3c(%ebp), %xmm0\n" /* line 703 | maxScale */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x24(%ebp)\n"
        "ucomiss %xmm1, %xmm2\n" /* line 705 */
        "jne .Lf5f9ac_0005fec2\n"
        "jp .Lf5f9ac_0005fec2\n"
        "movss %xmm1, -0x24(%ebp)\n" /* line 706 */
        ".Lf5f9ac_0005fcdd:\n"
        "movl $2, 8(%esp)\n" /* line 713 */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x1fc(%ebx)\n"
        "movl $0x3f800000, %eax\n" /* line 2201 */
        "movl %eax, 0x200(%ebx)\n" /* this */
        "movl %eax, 0x204(%ebx)\n" /* line 2202 | this */
        /* } scope */
        "movss -0x10(%ebp), %xmm0\n" /* line 953 */
        /* { scope 2 */
        "pxor %xmm1, %xmm1\n" /* line 700 */
        "movss %xmm1, -0x30(%ebp)\n" /* keys */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 701 */
        "movl %eax, -0x28(%ebp)\n" /* line 702 */
        "mulss -0x3c(%ebp), %xmm0\n" /* line 703 | maxScale */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x24(%ebp)\n"
        "movss -0x58(%ebp), %xmm2\n" /* line 705 */
        "ucomiss %xmm1, %xmm2\n"
        "jne .Lf5f9ac_0005feb4\n"
        "jp .Lf5f9ac_0005feb4\n"
        "movss %xmm1, -0x24(%ebp)\n" /* line 706 */
        ".Lf5f9ac_0005fd52:\n"
        "movl $2, 8(%esp)\n" /* line 713 */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x208(%ebx)\n"
        "movl $0x3f800000, %eax\n" /* line 2201 */
        "movl %eax, 0x20c(%ebx)\n" /* this */
        "movl %eax, 0x210(%ebx)\n" /* line 2202 | this */
        /* } scope */
        "movss -0xc(%ebp), %xmm0\n" /* line 954 */
        /* { scope 2 */
        "pxor %xmm1, %xmm1\n" /* line 700 */
        "movss %xmm1, -0x30(%ebp)\n" /* keys */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 701 */
        "movl %eax, -0x28(%ebp)\n" /* line 702 */
        "mulss -0x3c(%ebp), %xmm0\n" /* line 703 | maxScale */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, -0x24(%ebp)\n"
        "movss -0x58(%ebp), %xmm2\n" /* line 705 */
        "ucomiss %xmm1, %xmm2\n"
        "jne .Lf5f9ac_0005fea6\n"
        "jp .Lf5f9ac_0005fea6\n"
        "movss %xmm1, -0x24(%ebp)\n" /* line 706 */
        ".Lf5f9ac_0005fdc7:\n"
        "movl $2, 8(%esp)\n" /* line 713 */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxCurve_AllocAndCreateWithKeys\n"
        "movl %eax, 0x214(%ebx)\n"
        "movl $0x3f800000, %eax\n" /* line 2201 */
        "movl %eax, 0x218(%ebx)\n" /* this */
        "movl %eax, 0x21c(%ebx)\n" /* line 2202 | this */
        ".Lf5f9ac_0005fdf6:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x70, %esp\n" /* line 961 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keys */
        ".Lf5f9ac_0005fe02:\n"
        "xorl %eax, %eax\n" /* line 921 */
        /* } scope */
        "addl $0x70, %esp\n" /* line 961 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: keys */
        /* { scope 2 */
        ".Lf5f9ac_0005fe0b:\n"
        "divss %xmm2, %xmm0\n" /* line 708 */
        "movss %xmm0, -0x24(%ebp)\n"
        "jmp .Lf5f9ac_0005fb35\n"
        /* } scope */
        ".Lf5f9ac_0005fe19:\n"
        "movss -0xc(%ebp), %xmm4\n" /* line 117 */
        "movss %xmm4, -0x18(%ebp)\n"
        "movss %xmm0, -0xc(%ebp)\n" /* line 118 */
        "jmp .Lf5f9ac_0005fa4e\n"
        ".Lf5f9ac_0005fe2d:\n"
        "movss -0x10(%ebp), %xmm1\n" /* line 117 */
        "movss %xmm1, -0x1c(%ebp)\n"
        "movss %xmm0, -0x10(%ebp)\n" /* line 118 */
        "movss -0x18(%ebp), %xmm4\n" /* line 927 */
        "movaps %xmm4, %xmm0\n"
        "ucomiss -0xc(%ebp), %xmm4\n"
        "jbe .Lf5f9ac_0005fa4e\n"
        "jmp .Lf5f9ac_0005fe19\n"
        ".Lf5f9ac_0005fe50:\n"
        "movss -0x14(%ebp), %xmm5\n" /* line 117 | max */
        "movss %xmm5, -0x20(%ebp)\n" /* min */
        "movss %xmm0, -0x14(%ebp)\n" /* line 118 | max */
        "movss -0x1c(%ebp), %xmm1\n" /* line 925 */
        "movaps %xmm1, %xmm0\n"
        "ucomiss -0x10(%ebp), %xmm1\n"
        "jbe .Lf5f9ac_0005fa3c\n"
        "jmp .Lf5f9ac_0005fe2d\n"
        /* { scope 2 */
        ".Lf5f9ac_0005fe73:\n"
        "movl -0x20(%ebp), %eax\n" /* line 199 | min */
        "movl %eax, -0x14(%ebp)\n" /* max */
        "movl -0x1c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl -0x18(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        "jmp .Lf5f9ac_0005fa18\n"
        /* } scope */
        /* { scope 2 */
        ".Lf5f9ac_0005fe8a:\n"
        "divss %xmm2, %xmm0\n" /* line 708 */
        "movss %xmm0, -0x24(%ebp)\n"
        "jmp .Lf5f9ac_0005fc28\n"
        /* } scope */
        /* { scope 2 */
        ".Lf5f9ac_0005fe98:\n"
        "divss %xmm2, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "jmp .Lf5f9ac_0005fbb0\n"
        /* } scope */
        /* { scope 2 */
        ".Lf5f9ac_0005fea6:\n"
        "divss %xmm2, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "jmp .Lf5f9ac_0005fdc7\n"
        /* } scope */
        /* { scope 2 */
        ".Lf5f9ac_0005feb4:\n"
        "divss %xmm2, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "jmp .Lf5f9ac_0005fd52\n"
        /* } scope */
        /* { scope 2 */
        ".Lf5f9ac_0005fec2:\n"
        "divss %xmm2, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "jmp .Lf5f9ac_0005fcdd\n"
        /* } scope */
        ".Lf5f9ac_0005fed0:\n"
        "jp .Lf5f9ac_0005fc89\n" /* line 310 */
        "movl $1, %eax\n"
        "jmp .Lf5f9ac_0005fc8b\n"
    );
}

/* line 1701 */
__attribute__((naked))
Bool PrimitiveTemplate_ParsePrimitiveInternal(const PrimitiveTemplate * _this, BackCompatibleParameters *backCompatibleParameters, GPGroup *grp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1701 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1: min, max, channelId, min, ... */
        "movl 0x10(%ebp), %eax\n" /* line 121 | grp */
        "movl 0x10(%eax), %edi\n"
        /* { scope 2: this */
        "movl $0x600, 8(%esp)\n" /* line 261 */
        "movl $0, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* backCompatibleParameters */
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "xorl %esi, %esi\n" /* channelId */
        "movl 0xc(%ebp), %ecx\n" /* backCompatibleParameters */
        "addl $0x30, %ecx\n"
        "movl 0xc(%ebp), %ebx\n" /* backCompatibleParameters */
        ".Lf5fee0_0005ff15:\n"
        "xorl %edx, %edx\n"
        "leal 0x10(%ebx), %eax\n"
        ".Lf5fee0_0005ff1a:\n"
        "movl $0x3f800000, -0x10(%eax)\n" /* line 2201 */
        "movl $0x3f800000, -0xc(%eax)\n" /* line 2202 */
        "movl $0x3f800000, 8(%eax)\n" /* line 2201 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 2202 */
        "movl $0x3f800000, (%ecx)\n" /* line 2201 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 2202 */
        "addl $1, %edx\n" /* line 265 */
        "addl $8, %eax\n"
        "cmpl $3, %edx\n"
        "jne .Lf5fee0_0005ff1a\n"
        "addl $1, %esi\n" /* line 263 | channelId */
        "addl $0x40, %ebx\n"
        "addl $0x40, %ecx\n"
        "cmpl $0x18, %esi\n" /* channelId */
        "jne .Lf5fee0_0005ff15\n"
        /* } scope */
        "testl %edi, %edi\n" /* line 1714 | pairs */
        "je .Lf5fee0_0005ffc9\n"
        ".Lf5fee0_0005ff60:\n"
        "movl (%edi), %ebx\n" /* line 49 */
        "movl %edi, (%esp)\n" /* line 1717 | pairs */
        "calll GPValue_GetTopValue\n"
        "movl %eax, %esi\n" /* val */
        "movl $str_0021a4c4, 4(%esp)\n" /* line 1719 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_0006004b\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x1c(%ebp), %eax\n" /* line 311 | max, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x20(%ebp), %eax\n" /* min, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "je .Lf5fee0_00060168\n"
        "movl -0x20(%ebp), %eax\n" /* min */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_0005ffb6:\n"
        "movl 8(%ebp), %ecx\n" /* line 2201 | this */
        "movl %eax, 0x50(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2202 | max */
        "movl %eax, 0x54(%ecx)\n"
        /* } scope */
        /* } scope */
        "movl 4(%edi), %edi\n" /* line 80 */
        "testl %edi, %edi\n" /* line 1714 | pairs */
        "jne .Lf5fee0_0005ff60\n"
        ".Lf5fee0_0005ffc9:\n"
        "movl 8(%ebp), %edx\n" /* line 1941 | this */
        "movss 0xa0(%edx), %xmm4\n"
        "movss 0xac(%edx), %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "ja .Lf5fee0_00060147\n"
        ".Lf5fee0_0005ffe5:\n"
        "movss 0xa4(%edx), %xmm5\n"
        "movss 0xb0(%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm5\n"
        "ja .Lf5fee0_00060163\n"
        "movss 0xa8(%edx), %xmm3\n"
        "movss 0xb4(%edx), %xmm2\n"
        "ucomiss %xmm2, %xmm3\n"
        "ja .Lf5fee0_00060163\n"
        "subss %xmm3, %xmm2\n" /* line 1947 */
        "subss %xmm4, %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lf5fee0_00060031\n"
        "subss %xmm5, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf5fee0_000601bb\n"
        ".Lf5fee0_00060031:\n"
        "movl 8(%ebp), %eax\n" /* line 1949 | this */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021a708, (%esp)\n" /* "^1FX bounding box width or depth is larger than height for e" */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5fee0_000600fa\n"
        ".Lf5fee0_0006004b:\n"
        "movl $str_0021a4cc, 4(%esp)\n" /* line 1724 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060102\n"
        ".Lf5fee0_00060063:\n"
        "movl %edi, 4(%esp)\n" /* line 1726 | pairs */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_ParseMaterials\n"
        "testb %al, %al\n"
        "je .Lf5fee0_000600e0\n"
        ".Lf5fee0_00060076:\n"
        "movl 4(%edi), %edi\n" /* line 80 */
        "testl %edi, %edi\n" /* line 1714 | pairs */
        "jne .Lf5fee0_0005ff60\n"
        "movl 8(%ebp), %edx\n" /* line 1941 | this */
        "movss 0xa0(%edx), %xmm4\n"
        "movss 0xac(%edx), %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "jbe .Lf5fee0_0005ffe5\n"
        "jmp .Lf5fee0_00060147\n"
        ".Lf5fee0_000600a2:\n"
        "movl $str_0021a624, 4(%esp)\n" /* line 1905 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000612a1\n"
        "movl %esi, (%esp)\n" /* line 1045 | channelId */
        "calll atof\n"
        "fstpl -0x50(%ebp)\n"
        "cvtsd2ss -0x50(%ebp), %xmm0\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movss %xmm0, 0x294(%ecx)\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 1907 | 0.0f */
        "jae .Lf5fee0_00060076\n"
        "jp .Lf5fee0_00060076\n"
        ".Lf5fee0_000600e0:\n"
        "testl %ebx, %ebx\n" /* line 1935 | key */
        "je .Lf5fee0_0005ffc9\n"
        ".Lf5fee0_000600e8:\n"
        "movl %ebx, 4(%esp)\n" /* line 2092 | key */
        "movl $str_0021a6ac, (%esp)\n" /* "^1FX Error while parsing key '%s'
" */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf5fee0_000600fa:\n"
        "addl $0x6c, %esp\n" /* line 2099 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: min, max, channelId, min, ... */
        ".Lf5fee0_00060102:\n"
        "movl $str_0021a4d4, 4(%esp)\n" /* line 1724 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_00060063\n"
        "movl $str_0021a880, 4(%esp)\n" /* line 1729 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060173\n"
        ".Lf5fee0_0006012e:\n"
        "movl %edi, 4(%esp)\n" /* line 1731 | pairs */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll PrimitiveTemplate_ParseModels\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_00060147:\n"
        "movl %edx, %ecx\n"
        ".Lf5fee0_00060149:\n"
        "movl %ecx, 4(%esp)\n" /* line 1943 */
        "movl $str_0021a6d0, (%esp)\n" /* "^1FX bounding box mins / maxs invalid for effect '%s'
" */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 2099 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf5fee0_00060163:\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "jmp .Lf5fee0_00060149\n"
        /* { scope 1: min, max, channelId, min, ... */
        /* { scope 2: this */
        /* { scope 3 */
        ".Lf5fee0_00060168:\n"
        "movl -0x20(%ebp), %eax\n" /* line 319 | min */
        "movl %eax, -0x1c(%ebp)\n" /* max */
        "jmp .Lf5fee0_0005ffb6\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060173:\n"
        "movl $str_0021593c, 4(%esp)\n" /* line 1729 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_0006012e\n"
        "movl $str_0021a888, 4(%esp)\n" /* line 1734 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_0006035a\n"
        "movl %edi, 4(%esp)\n" /* line 1736 | pairs */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll PrimitiveTemplate_ParseImpactFxStrings\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_000601bb:\n"
        "movl 0x10(%ebp), %edx\n" /* line 123 | grp */
        "movl 0x1c(%edx), %esi\n"
        "testl %esi, %esi\n" /* line 1956 | val */
        "jne .Lf5fee0_000602c0\n"
        ".Lf5fee0_000601c9:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 2093 | backCompatibleParameters, key */
        "movl $0, -0x40(%ebp)\n" /* channelId */
        "movl 8(%ebp), %ecx\n" /* this */
        "addl $0x58, %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n" /* this */
        "movl %ebx, %edi\n" /* key, pairs */
        "movl 8(%ebp), %esi\n" /* this, val */
        "addl $0x100, %esi\n" /* val */
        "jmp .Lf5fee0_00060241\n"
        /* { scope 2: this */
        ".Lf5fee0_000601e9:\n"
        "movl $1, %edx\n" /* line 293 */
        "xorl %eax, %eax\n"
        /* { scope 3 */
        ".Lf5fee0_000601f0:\n"
        "movl 8(%ebp), %ecx\n" /* line 2215 | this */
        "movss 0x58(%ecx), %xmm1\n"
        /* } scope */
        "movl %esi, 0x10(%esp)\n" /* line 296 | channelId */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x3c(%ebp), %eax\n" /* this */
        "movss 4(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FxChannel_CreateViaMigration\n"
        ".Lf5fee0_0006022a:\n"
        "addl $1, -0x40(%ebp)\n" /* line 283 | channelId */
        "addl $0xc, %esi\n" /* channelId */
        "addl $0x40, %edi\n"
        "addl $0x40, %ebx\n"
        "cmpl $0x18, -0x40(%ebp)\n" /* channelId */
        "je .Lf5fee0_00060309\n"
        ".Lf5fee0_00060241:\n"
        "cmpb $0, 0x3c(%ebx)\n" /* line 285 */
        "je .Lf5fee0_0006022a\n"
        "cmpl $2, -0x40(%ebp)\n" /* line 290 | channelId */
        "je .Lf5fee0_000602fa\n"
        "movl -0x40(%ebp), %ecx\n" /* line 293 | channelId */
        "testl %ecx, %ecx\n"
        "jne .Lf5fee0_000601e9\n"
        "movl $3, %edx\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5fee0_000601f0\n"
        /* } scope */
        ".Lf5fee0_00060261:\n"
        "movl $str_0021a754, 4(%esp)\n" /* line 1965 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_0006028d\n"
        "movl $str_0021a75c, 4(%esp)\n" /* "rgbRand" */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060313\n"
        ".Lf5fee0_0006028d:\n"
        "movl $1, 0xc(%esp)\n" /* line 1967 */
        ".Lf5fee0_00060295:\n"
        "movl %esi, 8(%esp)\n" /* line 2072 | val */
        "movl 0xc(%ebp), %edx\n" /* backCompatibleParameters */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll PrimitiveTemplate_ParseChannel\n"
        "testb %al, %al\n"
        "je .Lf5fee0_0006034d\n"
        ".Lf5fee0_000602b3:\n"
        "movl 4(%esi), %eax\n" /* line 113 */
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 1956 */
        "je .Lf5fee0_000601c9\n"
        ".Lf5fee0_000602c0:\n"
        "movl (%esi), %ebx\n" /* line 49 */
        "movl $str_0021a750, 4(%esp)\n" /* line 1960 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060261\n"
        "movl $0, 0xc(%esp)\n" /* line 1962 */
        ".Lf5fee0_000602de:\n"
        "movl %esi, 8(%esp)\n" /* line 2067 | val */
        "movl 0xc(%ebp), %ecx\n" /* backCompatibleParameters */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_ParseChannel\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_000602b3\n"
        "jmp .Lf5fee0_0006034d\n"
        /* { scope 2: this */
        ".Lf5fee0_000602fa:\n"
        "movl $1, %edx\n" /* line 290 */
        "movl $1, %eax\n"
        "jmp .Lf5fee0_000601f0\n"
        ".Lf5fee0_00060309:\n"
        "movl $1, %eax\n" /* line 283 */
        "jmp .Lf5fee0_000600fa\n"
        /* } scope */
        ".Lf5fee0_00060313:\n"
        "movl $str_0021a8d8, 4(%esp)\n" /* line 1970 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_0006038a\n"
        "movl $2, 0xc(%esp)\n" /* line 1972 */
        ".Lf5fee0_0006032f:\n"
        "movl %esi, 8(%esp)\n" /* line 2077 | val */
        "movl 0xc(%ebp), %eax\n" /* backCompatibleParameters */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll PrimitiveTemplate_ParseChannel\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_000602b3\n"
        ".Lf5fee0_0006034d:\n"
        "testl %ebx, %ebx\n" /* line 2090 | key */
        "jne .Lf5fee0_000600e8\n"
        "jmp .Lf5fee0_000601c9\n"
        ".Lf5fee0_0006035a:\n"
        "movl $str_0021a4dc, 4(%esp)\n" /* line 1739 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000603ab\n"
        "movl %edi, 4(%esp)\n" /* line 1741 | pairs */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_ParseDeathFxStrings\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_0006038a:\n"
        "movl $str_0021a764, 4(%esp)\n" /* line 1975 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000603db\n"
        "movl $3, 0xc(%esp)\n" /* line 1977 */
        "jmp .Lf5fee0_000602de\n"
        ".Lf5fee0_000603ab:\n"
        "movl $str_0021a4e4, 4(%esp)\n" /* line 1744 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060410\n"
        "movl %edi, 4(%esp)\n" /* line 1746 | pairs */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll PrimitiveTemplate_ParseEmitterFxStrings\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_000603db:\n"
        "movl $str_0021a770, 4(%esp)\n" /* line 1980 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_00060403\n"
        "movl $str_0021a778, 4(%esp)\n" /* "width" */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060440\n"
        ".Lf5fee0_00060403:\n"
        "movl $4, 0xc(%esp)\n" /* line 1982 */
        "jmp .Lf5fee0_00060295\n"
        ".Lf5fee0_00060410:\n"
        "movl $str_0021a4ec, 4(%esp)\n" /* line 1749 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060465\n"
        "movl %edi, 4(%esp)\n" /* line 1751 | pairs */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll PrimitiveTemplate_ParsePlayFxStrings\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_00060440:\n"
        "movl $str_0021a8e0, 4(%esp)\n" /* line 1985 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000604ef\n"
        "movl $5, 0xc(%esp)\n" /* line 1987 */
        "jmp .Lf5fee0_0006032f\n"
        ".Lf5fee0_00060465:\n"
        "movl $str_0021a4f4, 4(%esp)\n" /* line 1754 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000604be\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x20(%ebp), %eax\n" /* line 311 | min, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x1c(%ebp), %eax\n" /* max, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_000604aa\n"
        "movl -0x1c(%ebp), %eax\n" /* line 319 | max */
        "movl %eax, -0x20(%ebp)\n" /* min */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_000604aa:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2201 | max */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x58(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 2202 | min */
        "movl %eax, 0x5c(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_000604be:\n"
        "movl $str_0021a4fc, 4(%esp)\n" /* line 1759 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060528\n"
        "movl %esi, (%esp)\n" /* line 1762 | val */
        "calll atof\n"
        "fstpl -0x58(%ebp)\n"
        "cvtsd2ss -0x58(%ebp), %xmm0\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movss %xmm0, 0x64(%ecx)\n"
        "jmp .Lf5fee0_00060076\n"
        ".Lf5fee0_000604ef:\n"
        "movl $str_0021a780, 4(%esp)\n" /* line 1990 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_0006051b\n"
        "movl $str_0021a788, 4(%esp)\n" /* "width2" */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000606b0\n"
        ".Lf5fee0_0006051b:\n"
        "movl $6, 0xc(%esp)\n" /* line 1992 */
        "jmp .Lf5fee0_000602de\n"
        ".Lf5fee0_00060528:\n"
        "movl $str_0021a508, 4(%esp)\n" /* line 1764 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060592\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x1c(%ebp), %eax\n" /* line 311 | max, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x20(%ebp), %eax\n" /* min, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_0006056d\n"
        "movl -0x20(%ebp), %eax\n" /* line 319 | min */
        "movl %eax, -0x1c(%ebp)\n" /* max */
        /* } scope */
        ".Lf5fee0_0006056d:\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 455 | min */
        "movss -0x1c(%ebp), %xmm0\n" /* max */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf5fee0_000600e0\n"
        "movl 8(%ebp), %eax\n" /* line 2201 | this */
        "movss %xmm1, 0x60(%eax)\n"
        "movss %xmm0, 0x64(%eax)\n" /* line 2202 */
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        ".Lf5fee0_00060592:\n"
        "movl $str_0021a514, 4(%esp)\n" /* line 1769 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000605eb\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x20(%ebp), %eax\n" /* line 311 | min, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x1c(%ebp), %eax\n" /* max, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_000605d7\n"
        "movl -0x1c(%ebp), %eax\n" /* line 319 | max */
        "movl %eax, -0x20(%ebp)\n" /* min */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_000605d7:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2201 | max */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x48(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 2202 | min */
        "movl %eax, 0x4c(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_000605eb:\n"
        "movl $str_0021a51c, 4(%esp)\n" /* line 1774 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_00060617\n"
        "movl $str_0021a524, 4(%esp)\n" /* "intensity" */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000606d5\n"
        /* { scope 2: this */
        /* { scope 3 */
        ".Lf5fee0_00060617:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 311 | max, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x20(%ebp), %eax\n" /* min, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_00060648\n"
        "movl -0x20(%ebp), %eax\n" /* line 319 | min */
        "movl %eax, -0x1c(%ebp)\n" /* max */
        /* } scope */
        ".Lf5fee0_00060648:\n"
        "movss -0x20(%ebp), %xmm2\n" /* line 500 | min */
        "movss -0x1c(%ebp), %xmm1\n" /* max */
        "ucomiss %xmm1, %xmm2\n"
        "ja .Lf5fee0_000600e0\n"
        "ucomiss lit4_002ed5e8, %xmm2\n" /* line 502 | 0.0f */
        "jp .Lf5fee0_0006066a\n"
        "jb .Lf5fee0_000600e0\n"
        ".Lf5fee0_0006066a:\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 504 | 1.0f */
        "ucomiss %xmm3, %xmm2\n"
        "ja .Lf5fee0_000600e0\n"
        "pxor %xmm0, %xmm0\n" /* line 506 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf5fee0_000600e0\n"
        "ucomiss %xmm3, %xmm1\n" /* line 508 */
        "ja .Lf5fee0_000600e0\n"
        "movl 8(%ebp), %ecx\n" /* line 2201 | this */
        "movss %xmm2, 0x280(%ecx)\n"
        "movss %xmm1, 0x284(%ecx)\n" /* line 2202 */
        "orl $0x20, 0x90(%ecx)\n" /* line 515 */
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        ".Lf5fee0_000606b0:\n"
        "movl $str_0021a8ec, 4(%esp)\n" /* line 1995 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060766\n"
        "movl $7, 0xc(%esp)\n" /* line 1997 */
        "jmp .Lf5fee0_00060295\n"
        ".Lf5fee0_000606d5:\n"
        "movl $str_0021a894, 4(%esp)\n" /* line 1779 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_0006079f\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x38(%ebp), %eax\n" /* line 335 | min, v */
        "leal -0x30(%ebp), %edx\n"
        "movl %edx, 0x1c(%esp)\n"
        "leal -0x34(%ebp), %ecx\n"
        "movl %ecx, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n" /* v */
        "movl %edx, 0x10(%esp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a398, 4(%esp)\n" /* "%f %f %f   %f %f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "cmpl $2, %eax\n" /* line 338 */
        "jle .Lf5fee0_000600e0\n"
        "cmpl $4, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $5, %eax\n"
        "je .Lf5fee0_000600e0\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 407 | this, to */
        "addl $0xa0, %edx\n" /* to */
        /* { scope 3 */
        "movl -0x38(%ebp), %eax\n" /* line 199 | min */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0xa0(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x30(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "orl $0x60, 0x90(%ecx)\n" /* line 410 */
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        ".Lf5fee0_00060766:\n"
        "movl $str_0021a790, 4(%esp)\n" /* line 2000 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_00060792\n"
        "movl $str_0021a588, 4(%esp)\n" /* "height" */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060830\n"
        ".Lf5fee0_00060792:\n"
        "movl $8, 0xc(%esp)\n" /* line 2002 */
        "jmp .Lf5fee0_0006032f\n"
        ".Lf5fee0_0006079f:\n"
        "movl $str_0021a530, 4(%esp)\n" /* line 1784 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060855\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x2c(%ebp), %eax\n" /* line 335 | max, v */
        "leal -0x24(%ebp), %edx\n"
        "movl %edx, 0x1c(%esp)\n"
        "leal -0x28(%ebp), %ecx\n"
        "movl %ecx, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n" /* v */
        "movl %edx, 0x10(%esp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a398, 4(%esp)\n" /* "%f %f %f   %f %f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "cmpl $2, %eax\n" /* line 338 */
        "jle .Lf5fee0_000600e0\n"
        "cmpl $4, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $5, %eax\n"
        "je .Lf5fee0_000600e0\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 424 | this, to */
        "addl $0xac, %edx\n" /* to */
        /* { scope 3 */
        "movl -0x2c(%ebp), %eax\n" /* line 199 | max */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0xac(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "orl $0x60, 0x90(%ecx)\n" /* line 427 */
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        ".Lf5fee0_00060830:\n"
        "movl $str_0021a8f8, 4(%esp)\n" /* line 2005 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_0006092b\n"
        "movl $9, 0xc(%esp)\n" /* line 2007 */
        "jmp .Lf5fee0_000602de\n"
        ".Lf5fee0_00060855:\n"
        "movl $str_0021a534, 4(%esp)\n" /* line 1789 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_00060881\n"
        "movl $str_0021a53c, 4(%esp)\n" /* "angles" */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060950\n"
        /* { scope 2: this */
        /* { scope 3 */
        ".Lf5fee0_00060881:\n"
        "leal -0x38(%ebp), %edx\n" /* line 335 | min */
        "leal -0x30(%ebp), %eax\n" /* v */
        "movl %eax, 0x1c(%esp)\n" /* v */
        "leal -0x34(%ebp), %eax\n" /* v */
        "movl %eax, 0x18(%esp)\n" /* v */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x2c(%ebp), %edx\n" /* max */
        "leal -0x24(%ebp), %eax\n" /* v */
        "movl %eax, 0x10(%esp)\n" /* v */
        "leal -0x28(%ebp), %eax\n" /* v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "movl %edx, 8(%esp)\n"
        "movl $str_0021a398, 4(%esp)\n" /* "%f %f %f   %f %f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "cmpl $2, %eax\n" /* line 338 */
        "jle .Lf5fee0_000600e0\n"
        "cmpl $4, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $5, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $3, %eax\n" /* line 342 */
        "jne .Lf5fee0_000608ed\n"
        "movl -0x2c(%ebp), %eax\n" /* line 199 | max */
        "movl %eax, -0x38(%ebp)\n" /* min */
        "movl -0x28(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x30(%ebp)\n"
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_000608ed:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2201 | max */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x228(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 2202 | min */
        "movl %eax, 0x22c(%edx)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x28(%ebp), %eax\n" /* line 2201 */
        "movl %eax, 0x230(%edx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 0x234(%edx)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x24(%ebp), %eax\n" /* line 2201 */
        "movl %eax, 0x238(%edx)\n"
        "movl -0x30(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 0x23c(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_0006092b:\n"
        "movl $str_0021a5a4, 4(%esp)\n" /* line 2010 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060a56\n"
        "movl $0xa, 0xc(%esp)\n" /* line 2012 */
        "jmp .Lf5fee0_00060295\n"
        ".Lf5fee0_00060950:\n"
        "movl $str_0021a898, 4(%esp)\n" /* line 1794 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060a12\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x2c(%ebp), %edx\n" /* line 335 | max */
        "leal -0x24(%ebp), %eax\n" /* v */
        "movl %eax, 0x1c(%esp)\n" /* v */
        "leal -0x28(%ebp), %eax\n" /* v */
        "movl %eax, 0x18(%esp)\n" /* v */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* min */
        "leal -0x30(%ebp), %eax\n" /* v */
        "movl %eax, 0x10(%esp)\n" /* v */
        "leal -0x34(%ebp), %eax\n" /* v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "movl %edx, 8(%esp)\n"
        "movl $str_0021a398, 4(%esp)\n" /* "%f %f %f   %f %f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "cmpl $2, %eax\n" /* line 338 */
        "jle .Lf5fee0_000600e0\n"
        "cmpl $4, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $5, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $3, %eax\n" /* line 342 */
        "jne .Lf5fee0_000609d4\n"
        "movl -0x38(%ebp), %eax\n" /* line 199 | min */
        "movl %eax, -0x2c(%ebp)\n" /* max */
        "movl -0x34(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x24(%ebp)\n"
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_000609d4:\n"
        "movl -0x38(%ebp), %eax\n" /* line 2201 | min */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x240(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2202 | max */
        "movl %eax, 0x244(%ecx)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x34(%ebp), %eax\n" /* line 2201 */
        "movl %eax, 0x248(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 0x24c(%ecx)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x30(%ebp), %eax\n" /* line 2201 */
        "movl %eax, 0x250(%ecx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 0x254(%ecx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060a12:\n"
        "movl $str_0021a544, 4(%esp)\n" /* line 1799 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_00060a3a\n"
        "movl $str_0021a550, 4(%esp)\n" /* "vel" */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060a77\n"
        ".Lf5fee0_00060a3a:\n"
        "movl %esi, 4(%esp)\n" /* line 1801 | val */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_ParseVelocity\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_00060a56:\n"
        "movl $str_0021a798, 4(%esp)\n" /* line 2015 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060aa7\n"
        "movl $0xb, 0xc(%esp)\n" /* line 2017 */
        "jmp .Lf5fee0_0006032f\n"
        ".Lf5fee0_00060a77:\n"
        "movl $str_0021a8a4, 4(%esp)\n" /* line 1804 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060acc\n"
        ".Lf5fee0_00060a8b:\n"
        "movl %esi, 4(%esp)\n" /* line 1806 | val */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll PrimitiveTemplate_ParseAcceleration\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_00060aa7:\n"
        "movl $str_0021a7ac, 4(%esp)\n" /* line 2020 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060f2d\n"
        "movl $0xc, 0xc(%esp)\n" /* line 2022 */
        "jmp .Lf5fee0_000602de\n"
        ".Lf5fee0_00060acc:\n"
        "movl $str_0021a554, 4(%esp)\n" /* line 1804 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_00060a8b\n"
        "movl $str_0021a8b4, 4(%esp)\n" /* line 1809 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060b3f\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x1c(%ebp), %eax\n" /* line 311 | max, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x20(%ebp), %eax\n" /* min, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_00060b25\n"
        "movl -0x20(%ebp), %eax\n" /* line 319 | min */
        "movl %eax, -0x1c(%ebp)\n" /* max */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_00060b25:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2201 | min */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x258(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2202 | max */
        "movl %eax, 0x25c(%ecx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060b3f:\n"
        "movl $str_0021a55c, 4(%esp)\n" /* line 1814 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060b9e\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x20(%ebp), %eax\n" /* line 311 | min, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x1c(%ebp), %eax\n" /* max, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_00060b84\n"
        "movl -0x1c(%ebp), %eax\n" /* line 319 | max */
        "movl %eax, -0x20(%ebp)\n" /* min */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_00060b84:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2201 | max */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x260(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 2202 | min */
        "movl %eax, 0x264(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060b9e:\n"
        "movl $str_0021a564, 4(%esp)\n" /* line 1819 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060bfd\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x20(%ebp), %eax\n" /* line 311 | min, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x1c(%ebp), %eax\n" /* max, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_00060be3\n"
        "movl -0x1c(%ebp), %eax\n" /* line 319 | max */
        "movl %eax, -0x20(%ebp)\n" /* min */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_00060be3:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2201 | max */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x268(%ecx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 2202 | min */
        "movl %eax, 0x26c(%ecx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060bfd:\n"
        "movl $str_0021a570, 4(%esp)\n" /* line 1824 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060cbf\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x2c(%ebp), %edx\n" /* line 335 | max */
        "leal -0x24(%ebp), %eax\n" /* v */
        "movl %eax, 0x1c(%esp)\n" /* v */
        "leal -0x28(%ebp), %eax\n" /* v */
        "movl %eax, 0x18(%esp)\n" /* v */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* min */
        "leal -0x30(%ebp), %eax\n" /* v */
        "movl %eax, 0x10(%esp)\n" /* v */
        "leal -0x34(%ebp), %eax\n" /* v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "movl %edx, 8(%esp)\n"
        "movl $str_0021a398, 4(%esp)\n" /* "%f %f %f   %f %f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "cmpl $2, %eax\n" /* line 338 */
        "jle .Lf5fee0_000600e0\n"
        "cmpl $4, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $5, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $3, %eax\n" /* line 342 */
        "jne .Lf5fee0_00060c81\n"
        "movl -0x38(%ebp), %eax\n" /* line 199 | min */
        "movl %eax, -0x2c(%ebp)\n" /* max */
        "movl -0x34(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x24(%ebp)\n"
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_00060c81:\n"
        "movl -0x38(%ebp), %eax\n" /* line 2201 | min */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0xb8(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2202 | max */
        "movl %eax, 0xbc(%edx)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x34(%ebp), %eax\n" /* line 2201 */
        "movl %eax, 0xc0(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 0xc4(%edx)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x30(%ebp), %eax\n" /* line 2201 */
        "movl %eax, 0xc8(%edx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 0xcc(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060cbf:\n"
        "movl $str_0021a578, 4(%esp)\n" /* line 1829 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060d81\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x38(%ebp), %edx\n" /* line 335 | min */
        "leal -0x30(%ebp), %eax\n" /* v */
        "movl %eax, 0x1c(%esp)\n" /* v */
        "leal -0x34(%ebp), %eax\n" /* v */
        "movl %eax, 0x18(%esp)\n" /* v */
        "movl %edx, 0x14(%esp)\n"
        "leal -0x2c(%ebp), %edx\n" /* max */
        "leal -0x24(%ebp), %eax\n" /* v */
        "movl %eax, 0x10(%esp)\n" /* v */
        "leal -0x28(%ebp), %eax\n" /* v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "movl %edx, 8(%esp)\n"
        "movl $str_0021a398, 4(%esp)\n" /* "%f %f %f   %f %f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "cmpl $2, %eax\n" /* line 338 */
        "jle .Lf5fee0_000600e0\n"
        "cmpl $4, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $5, %eax\n"
        "je .Lf5fee0_000600e0\n"
        "cmpl $3, %eax\n" /* line 342 */
        "jne .Lf5fee0_00060d43\n"
        "movl -0x2c(%ebp), %eax\n" /* line 199 | max */
        "movl %eax, -0x38(%ebp)\n" /* min */
        "movl -0x28(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x30(%ebp)\n"
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_00060d43:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2201 | max */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0xd0(%ecx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 2202 | min */
        "movl %eax, 0xd4(%ecx)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x28(%ebp), %eax\n" /* line 2201 */
        "movl %eax, 0xd8(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 0xdc(%ecx)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x24(%ebp), %eax\n" /* line 2201 */
        "movl %eax, 0xe0(%ecx)\n"
        "movl -0x30(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 0xe4(%ecx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060d81:\n"
        "movl $str_0021a580, 4(%esp)\n" /* line 1834 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060de0\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x1c(%ebp), %eax\n" /* line 311 | max, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x20(%ebp), %eax\n" /* min, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_00060dc6\n"
        "movl -0x20(%ebp), %eax\n" /* line 319 | min */
        "movl %eax, -0x1c(%ebp)\n" /* max */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_00060dc6:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2201 | min */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0xe8(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2202 | max */
        "movl %eax, 0xec(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060de0:\n"
        "movl $str_0021a588, 4(%esp)\n" /* line 1839 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060e3f\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x20(%ebp), %eax\n" /* line 311 | min, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x1c(%ebp), %eax\n" /* max, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_00060e25\n"
        "movl -0x1c(%ebp), %eax\n" /* line 319 | max */
        "movl %eax, -0x20(%ebp)\n" /* min */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_00060e25:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2201 | max */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0xf0(%ecx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 2202 | min */
        "movl %eax, 0xf4(%ecx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060e3f:\n"
        "movl $str_0021a590, 4(%esp)\n" /* line 1844 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060e9e\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x1c(%ebp), %eax\n" /* line 311 | max, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x20(%ebp), %eax\n" /* min, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_00060e84\n"
        "movl -0x20(%ebp), %eax\n" /* line 319 | min */
        "movl %eax, -0x1c(%ebp)\n" /* max */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_00060e84:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2201 | min */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0xf8(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2202 | max */
        "movl %eax, 0xfc(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060e9e:\n"
        "movl $str_0021a598, 4(%esp)\n" /* line 1849 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060efd\n"
        /* { scope 2: this */
        /* { scope 3 */
        "leal -0x1c(%ebp), %eax\n" /* line 311 | max, v */
        "movl %eax, 0xc(%esp)\n" /* v */
        "leal -0x20(%ebp), %eax\n" /* min, v */
        "movl %eax, 8(%esp)\n" /* v */
        "movl $str_0021a190, 4(%esp)\n" /* "%f %f" */
        "movl %esi, (%esp)\n" /* channelId */
        "calll sscanf\n"
        "testl %eax, %eax\n" /* line 313 */
        "je .Lf5fee0_000600e0\n"
        "subl $1, %eax\n" /* line 317 */
        "jne .Lf5fee0_00060ee3\n"
        "movl -0x20(%ebp), %eax\n" /* line 319 | min */
        "movl %eax, -0x1c(%ebp)\n" /* max */
        /* } scope */
        /* { scope 3 */
        ".Lf5fee0_00060ee3:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2201 | min */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x220(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2202 | max */
        "movl %eax, 0x224(%ecx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        /* } scope */
        ".Lf5fee0_00060efd:\n"
        "movl $str_0021a5a4, 4(%esp)\n" /* line 1854 */
        "movl %ebx, (%esp)\n" /* key */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060f4e\n"
        "movl %esi, 4(%esp)\n" /* line 1856 | val */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_ParseRotationDelta\n"
        "testb %al, %al\n"
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_00060f2d:\n"
        "movl $str_0021a7b8, 4(%esp)\n" /* line 2025 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060fa2\n"
        "movl $0xd, 0xc(%esp)\n" /* line 2027 */
        "jmp .Lf5fee0_00060295\n"
        ".Lf5fee0_00060f4e:\n"
        "movl $str_0021a498, 4(%esp)\n" /* line 1859 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_00060f76\n"
        "movl $str_0021a490, 4(%esp)\n" /* "flag" */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00060fc3\n"
        ".Lf5fee0_00060f76:\n"
        "movl $0x18, 0xc(%esp)\n" /* line 903 */
        "movl $fxAttributeFlags, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* channelId */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll PrimitiveTemplate_ParseFlags\n"
        "testb %al, %al\n" /* line 1861 */
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_00060fa2:\n"
        "movl $str_0021a7c4, 4(%esp)\n" /* line 2030 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061003\n"
        "movl $0xe, 0xc(%esp)\n" /* line 2032 */
        "jmp .Lf5fee0_0006032f\n"
        ".Lf5fee0_00060fc3:\n"
        "movl $str_0021a8bc, 4(%esp)\n" /* line 1864 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061024\n"
        ".Lf5fee0_00060fd7:\n"
        "movl $0xd, 0xc(%esp)\n" /* line 909 */
        "movl $fxSpawnFlags, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* channelId */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll PrimitiveTemplate_ParseFlags\n"
        "testb %al, %al\n" /* line 1866 */
        "jne .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_00061003:\n"
        "movl $str_0021a7d0, 4(%esp)\n" /* line 2035 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061065\n"
        "movl $0xf, 0xc(%esp)\n" /* line 2037 */
        "jmp .Lf5fee0_000602de\n"
        ".Lf5fee0_00061024:\n"
        "movl $str_0021a5b4, 4(%esp)\n" /* line 1864 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5fee0_00060fd7\n"
        "movl $str_0021a8c8, 4(%esp)\n" /* line 1869 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061086\n"
        "movl %esi, (%esp)\n" /* line 1871 | val */
        "calll atoi\n"
        "testl %eax, %eax\n"
        "movl 8(%ebp), %eax\n" /* this */
        "setne 0x9c(%eax)\n"
        "jmp .Lf5fee0_00060076\n"
        ".Lf5fee0_00061065:\n"
        "movl $str_0021a7e0, 4(%esp)\n" /* line 2040 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000610b3\n"
        "movl $0x10, 0xc(%esp)\n" /* line 2042 */
        "jmp .Lf5fee0_00060295\n"
        ".Lf5fee0_00061086:\n"
        "movl $str_0021a5c0, 4(%esp)\n" /* line 1873 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000610d4\n"
        "movl %esi, (%esp)\n" /* line 1875 | val */
        "calll atoi\n"
        "testl %eax, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "setne 0x9d(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        ".Lf5fee0_000610b3:\n"
        "movl $str_0021a7f0, 4(%esp)\n" /* line 2045 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_0006110c\n"
        "movl $0x11, 0xc(%esp)\n" /* line 2047 */
        "jmp .Lf5fee0_0006032f\n"
        ".Lf5fee0_000610d4:\n"
        "movl $str_002194b4, 4(%esp)\n" /* line 1877 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_0006112d\n"
        "testl %esi, %esi\n" /* line 1879 | val */
        "je .Lf5fee0_000600e0\n"
        "movl $0x20, 8(%esp)\n" /* line 1883 */
        "movl %esi, 4(%esp)\n" /* val */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf5fee0_00060076\n"
        ".Lf5fee0_0006110c:\n"
        "movl $str_0021a800, 4(%esp)\n" /* line 2050 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061160\n"
        "movl $0x12, 0xc(%esp)\n" /* line 2052 */
        "jmp .Lf5fee0_000602de\n"
        ".Lf5fee0_0006112d:\n"
        "movl $str_0021a5cc, 4(%esp)\n" /* line 1885 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061181\n"
        "movl $0x20, 8(%esp)\n" /* line 1696 */
        "movl %esi, 4(%esp)\n" /* channelId */
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x20, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf5fee0_00060076\n"
        ".Lf5fee0_00061160:\n"
        "movl $str_0021a80c, 4(%esp)\n" /* line 2055 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000611b4\n"
        "movl $0x13, 0xc(%esp)\n" /* line 2057 */
        "jmp .Lf5fee0_00060295\n"
        ".Lf5fee0_00061181:\n"
        "movl $str_0021a5dc, 4(%esp)\n" /* line 1890 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000611d5\n"
        /* { scope 2: this */
        "movl %esi, (%esp)\n" /* line 1008 | channelId */
        "calll atoi\n"
        "cmpl $2, %eax\n" /* line 1010 */
        "ja .Lf5fee0_000600e0\n"
        "movl 8(%ebp), %edx\n" /* line 1013 | this */
        "movl %eax, 0x288(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        ".Lf5fee0_000611b4:\n"
        "movl $str_0021a818, 4(%esp)\n" /* line 2060 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061207\n"
        "movl $0x14, 0xc(%esp)\n" /* line 2062 */
        "jmp .Lf5fee0_0006032f\n"
        ".Lf5fee0_000611d5:\n"
        "movl $str_0021a5f4, 4(%esp)\n" /* line 1895 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061228\n"
        "movl %esi, (%esp)\n" /* line 1021 | channelId */
        "calll atoi\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x28c(%ecx)\n"
        "testl %eax, %eax\n" /* line 1897 */
        "jg .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_00061207:\n"
        "movl $str_0021a824, 4(%esp)\n" /* line 2065 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_0006125f\n"
        "movl $0x15, 0xc(%esp)\n" /* line 2067 */
        "jmp .Lf5fee0_000602de\n"
        ".Lf5fee0_00061228:\n"
        "movl $str_0021a60c, 4(%esp)\n" /* line 1900 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000600a2\n"
        /* { scope 2: this */
        "movl %esi, (%esp)\n" /* line 1032 | channelId */
        "calll atoi\n"
        "cmpl $1, %eax\n" /* line 1034 */
        "ja .Lf5fee0_000600e0\n"
        "movl 8(%ebp), %edx\n" /* line 1037 | this */
        "movl %eax, 0x290(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        ".Lf5fee0_0006125f:\n"
        "movl $str_0021a834, 4(%esp)\n" /* line 2070 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061280\n"
        "movl $0x16, 0xc(%esp)\n" /* line 2072 */
        "jmp .Lf5fee0_00060295\n"
        ".Lf5fee0_00061280:\n"
        "movl $str_0021a844, 4(%esp)\n" /* line 2075 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000612d4\n"
        "movl $0x17, 0xc(%esp)\n" /* line 2077 */
        "jmp .Lf5fee0_0006032f\n"
        ".Lf5fee0_000612a1:\n"
        "movl $str_0021a63c, 4(%esp)\n" /* line 1910 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_000612eb\n"
        /* { scope 2: this */
        "movl %esi, (%esp)\n" /* line 1056 | channelId */
        "calll atoi\n"
        "cmpl $1, %eax\n" /* line 1058 */
        "ja .Lf5fee0_000600e0\n"
        "movl 8(%ebp), %edx\n" /* line 1061 | this */
        "movl %eax, 0x298(%edx)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        ".Lf5fee0_000612d4:\n"
        "movl %ebx, 4(%esp)\n" /* line 2082 | key */
        "movl $str_0021a854, (%esp)\n" /* "Unknown group key parsing a particle: %s
" */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5fee0_000600fa\n"
        ".Lf5fee0_000612eb:\n"
        "movl $str_0021a650, 4(%esp)\n" /* line 1915 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_0006131d\n"
        "movl %esi, (%esp)\n" /* line 1069 | channelId */
        "calll atoi\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x29c(%ecx)\n"
        "testl %eax, %eax\n" /* line 1917 */
        "jns .Lf5fee0_00060076\n"
        "jmp .Lf5fee0_000600e0\n"
        ".Lf5fee0_0006131d:\n"
        "movl $str_0021a664, 4(%esp)\n" /* line 1920 */
        "movl %ebx, (%esp)\n" /* key */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5fee0_00061360\n"
        /* { scope 2: this */
        "movl %esi, (%esp)\n" /* line 1084 | channelId */
        "calll atof\n"
        "fstpl -0x48(%ebp)\n"
        "cvtsd2ss -0x48(%ebp), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 1086 | 0.0f */
        "jp .Lf5fee0_00061350\n"
        "jb .Lf5fee0_000600e0\n"
        ".Lf5fee0_00061350:\n"
        "movl 8(%ebp), %eax\n" /* line 1089 | this */
        "movss %xmm0, 0x2a0(%eax)\n"
        "jmp .Lf5fee0_00060076\n"
        /* } scope */
        ".Lf5fee0_00061360:\n"
        "movl %ebx, 4(%esp)\n" /* line 1927 | key */
        "movl $str_0021a67c, (%esp)\n" /* "Unknown key parsing an effect primitive: %s
" */
        "calll FX_Print\n"
        "xorl %eax, %eax\n"
        "jmp .Lf5fee0_000600fa\n"
    );
}

/* line 2102 */
__attribute__((naked))
Bool PrimitiveTemplate_ParsePrimitive(const PrimitiveTemplate * _this, GPGroup *grp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2102 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $0x600, (%esp)\n" /* line 2110 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, %esi\n"
        "movl 0xc(%ebp), %eax\n" /* line 2113 | grp */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_ParsePrimitiveInternal\n"
        "movl %eax, %ebx\n" /* success */
        "movl %esi, (%esp)\n" /* line 2118 */
        "calll Hunk_FreeTempMemory\n"
        "movzbl %bl, %ebx\n" /* success */
        /* } scope */
        "movl %ebx, %eax\n" /* line 2122 | success */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

