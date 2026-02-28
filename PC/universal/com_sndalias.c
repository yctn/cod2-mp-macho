/* ASM dump from: com_sndalias.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_sndalias.cpp */

#include "common_types.h"
#include "imports.h"

extern void * Hunk_AllocateTempMemoryInternal(int size, const char *name);
extern void * Hunk_AllocInternal(int size);
extern float GraphGetValueFromFraction(int knotCount, float *knots, float fraction);

extern struct g_sa_type g_sa; /* 0x0 */

float Com_GetVolumeFalloffCurveValue(SndCurve *volumeFalloffCurve, float fraction);
const char * Com_GetSoundFileName(const snd_alias_t *pAlias);
J_COLOR_SPACE * Com_GetSoundFileMem(const snd_alias_t *pAlias);
J_COLOR_SPACE Com_LoadSoundAliases(const char *loadspec, const char *loadspecCurGame, snd_alias_system_t system);
SndCurve * Com_RegisterSoundAliasVolumeFalloffCurve(const char *filename, const char *sourceFile);
SndCurve * Com_GetDefaultSoundAliasVolumeFalloffCurve(void);
J_COLOR_SPACE * Com_AllocateTempSoundMemory(int size, const char *name);
J_COLOR_SPACE * Com_AllocSoundMemory(int size, const char *name, int type);
J_COLOR_SPACE Com_UnloadSoundAliasSounds(snd_alias_system_t system);
J_COLOR_SPACE Com_UnloadSoundAliases(snd_alias_system_t system);
static J_COLOR_SPACE Com_StreamedSoundList(void);
static J_COLOR_SPACE Com_LoadedSoundList(void);
static J_COLOR_SPACE Com_SoundList_f(void);
snd_alias_t * Com_PickSoundAliasFromList(snd_alias_list_t *aliasList);
snd_alias_list_t * Com_FindSoundAlias(const char *name);
Bool Com_AddAliasList(const char *name, snd_alias_list_t *aliasList);
J_COLOR_SPACE Com_DuplicateSoundAlias(snd_alias_list_t *aliasCopy, const char *name);
int SND_GetAliasOffset(const snd_alias_t *alias);
snd_alias_t * SND_GetAliasWithOffset(const char *name, int offset);
snd_alias_t * Com_PickSoundAlias(const char *aliasname);

/* line 296 */
float Com_GetVolumeFalloffCurveValue(SndCurve *volumeFalloffCurve, float fraction)
{
    return GraphGetValueFromFraction(*(int *)((char *)volumeFalloffCurve + 4), (float *)((char *)volumeFalloffCurve + 8), fraction);
}

/* line 874 */
const char * Com_GetSoundFileName(const snd_alias_t *pAlias)
{
    return *(const char **)(*(int *)((byte *)pAlias + 0xc));
}

/* line 887 */
J_COLOR_SPACE * Com_GetSoundFileMem(const snd_alias_t *pAlias)
{
    return *(J_COLOR_SPACE **)(*(int *)((byte *)pAlias + 0xc) + 4);
}

/* line 979 */
__attribute__((naked))
J_COLOR_SPACE Com_LoadSoundAliases(const char *loadspec, const char *loadspecCurGame, snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 979 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1 */
        "cmpb $0, g_sa+4240\n" /* line 1002 */
        "je .Lfad324_000ad575\n"
        ".Lfad324_000ad33d:\n"
        "movl $8, 8(%esp)\n" /* line 1014 */
        "movl $str_00217fe8, 4(%esp)\n" /* "maps/mp/" */
        "movl 8(%ebp), %eax\n" /* loadspec */
        "movl %eax, (%esp)\n"
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lfad324_000ad485\n"
        "leal -0x60(%ebp), %edx\n" /* line 1015 | trimspec */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* loadspec */
        "addl $8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_StripExtension\n"
        ".Lfad324_000ad375:\n"
        "leal -0x60(%ebp), %eax\n" /* line 1027 | trimspec */
        "movl %eax, (%esp)\n"
        "calll strlwr\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1028 | system */
        "je .Lfad324_000ad4cf\n"
        ".Lfad324_000ad38a:\n"
        "movl $0xa, 0x10(%esp)\n" /* line 1032 */
        "leal -0x1c(%ebp), %eax\n" /* fileCount */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_0021e5ac, 4(%esp)\n" /* "csv" */
        "movl $str_0021e51c, (%esp)\n" /* "soundaliases" */
        "calll FS_ListFiles\n"
        "movl %eax, %esi\n" /* fileNames */
        "movl -0x1c(%ebp), %edx\n" /* line 1035 | fileCount */
        "testl %edx, %edx\n"
        "je .Lfad324_000ad545\n"
        "calll Hunk_HideTempMemory\n" /* line 1043 */
        "movl %eax, %edi\n" /* mark */
        "calll Com_InitSoundAlias\n" /* line 1045 */
        "movl -0x1c(%ebp), %eax\n" /* line 1047 | fileCount */
        "testl %eax, %eax\n"
        "jg .Lfad324_000ad67c\n"
        ".Lfad324_000ad3d9:\n"
        "movl 0x10(%ebp), %edx\n" /* line 1053 | system */
        "leal g_sa+4152(, %edx, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl $g_sa+4104, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_MakeSoundAliasesPermanent\n"
        "calll Hunk_ClearTempMemory\n" /* line 1057 */
        "movl %edi, (%esp)\n" /* line 1058 | mark */
        "calll Hunk_ShowTempMemory\n"
        "movl $0xa, 4(%esp)\n" /* line 1060 */
        "movl %esi, (%esp)\n" /* fileNames */
        "calll FS_FreeFileList\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1075 | system */
        "jbe .Lfad324_000ad51e\n"
        ".Lfad324_000ad420:\n"
        "movl 0x10(%ebp), %edi\n" /* line 1081 | system, mark */
        "movb $1, g_sa(%edi)\n" /* mark */
        "cmpl $1, %edi\n" /* line 1085 | mark */
        "ja .Lfad324_000ad551\n"
        "leal g_sa+4152(, %edi, 8), %eax\n" /* line 1087 */
        "movl %eax, (%esp)\n"
        "calll Com_LoadSoundAliasSounds\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 1088 */
        "je .Lfad324_000ad551\n"
        "movl imp_snd_errorOnMissing, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfad324_000ad551\n"
        "movl %edx, 4(%esp)\n" /* line 1089 */
        "movl $str_0021e5fc, (%esp)\n" /* "%i sound file(s) are missing or in a bad format
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "xorl %eax, %eax\n"
        "testl %edi, %edi\n" /* mark */
        "setne %al\n"
        "movl %eax, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfad324_000ad551\n"
        ".Lfad324_000ad485:\n"
        "movl $5, 8(%esp)\n" /* line 1016 */
        "movl $str_0021e5a4, 4(%esp)\n" /* "maps/" */
        "movl 8(%ebp), %edi\n" /* loadspec, mark */
        "movl %edi, (%esp)\n" /* mark */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lfad324_000ad55c\n"
        "movl 8(%ebp), %edx\n" /* line 1019 | loadspec */
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %edi\n" /* trimspec, mark */
        "movl %edi, (%esp)\n" /* mark */
        "calll strcpy\n"
        "leal -0x60(%ebp), %eax\n" /* line 1027 | trimspec */
        "movl %eax, (%esp)\n"
        "calll strlwr\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1028 | system */
        "jne .Lfad324_000ad38a\n"
        ".Lfad324_000ad4cf:\n"
        "movl imp_com_sv_running, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfad324_000ad38a\n"
        "movl g_sa+4136, %eax\n" /* line 1068 */
        "movl %eax, g_sa+4120\n"
        "movl g_sa+4140, %eax\n"
        "movl %eax, g_sa+4124\n"
        "movl g_sa+4144, %eax\n"
        "movl %eax, g_sa+4128\n"
        "movl g_sa+4148, %eax\n"
        "movl %eax, g_sa+4132\n"
        "movl g_sa+4168, %eax\n" /* line 1069 */
        "movl g_sa+4172, %edx\n"
        "movl %eax, g_sa+4160\n"
        "movl %edx, g_sa+4164\n"
        ".Lfad324_000ad51e:\n"
        "cmpw $0, g_sa\n" /* line 1075 */
        "jne .Lfad324_000ad420\n"
        "movl $Com_SoundList_f, 4(%esp)\n" /* line 1076 */
        "movl $str_0021e5f0, (%esp)\n" /* "snd_list" */
        "calll Cmd_AddCommand\n"
        "jmp .Lfad324_000ad420\n"
        ".Lfad324_000ad545:\n"
        "movl $str_0021e5b0, (%esp)\n" /* line 1037 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lfad324_000ad551:\n"
        "addl $0x9c, %esp\n" /* line 1094 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfad324_000ad55c:\n"
        "leal -0x60(%ebp), %eax\n" /* line 1017 | trimspec */
        "movl %eax, 4(%esp)\n"
        "movl %edi, %eax\n" /* mark */
        "addl $5, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_StripExtension\n"
        "jmp .Lfad324_000ad375\n"
        ".Lfad324_000ad575:\n"
        "movl $0x480, 8(%esp)\n" /* line 950 */
        "movl $0, 4(%esp)\n"
        "movl $g_sa+4244, (%esp)\n"
        "calll memset\n"
        "movl $g_sa+4244, (%esp)\n" /* line 953 */
        "calll Com_InitDefaultSoundAliasVolumeFalloffCurve\n"
        "movl $0xa, 0x10(%esp)\n" /* line 955 */
        "leal -0x20(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_0021e514, 4(%esp)\n" /* "vfcurve" */
        "movl $str_0021e51c, (%esp)\n" /* "soundaliases" */
        "calll FS_ListFiles\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 956 */
        "cmpl $0xf, %eax\n"
        "jg .Lfad324_000ad6a4\n"
        ".Lfad324_000ad5d7:\n"
        "movl $0, -0x6c(%ebp)\n" /* line 957 */
        "movl $g_sa+4244, -0x74(%ebp)\n"
        "movl -0x70(%ebp), %ebx\n"
        "movl $g_sa+5396, %esi\n"
        ".Lfad324_000ad5ed:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 959 */
        "cmpl -0x20(%ebp), %edx\n"
        "jge .Lfad324_000ad65d\n"
        ".Lfad324_000ad5f5:\n"
        "addl $1, -0x6c(%ebp)\n" /* line 961 */
        "addl $0x40, %esi\n"
        "addl $4, %ebx\n"
        "addl $0x48, -0x74(%ebp)\n"
        "movl -4(%ebx), %edx\n" /* line 962 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $8, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x74(%ebp), %eax\n" /* line 963 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_LoadVolumeFalloffCurve\n"
        "testb %al, %al\n"
        "jne .Lfad324_000ad5ed\n"
        "movl -4(%ebx), %eax\n" /* line 964 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021e580, 4(%esp)\n" /* "Failed to load sndcurve file '%s'" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x6c(%ebp), %edx\n" /* line 959 */
        "cmpl -0x20(%ebp), %edx\n"
        "jl .Lfad324_000ad5f5\n"
        ".Lfad324_000ad65d:\n"
        "movl $0xa, 4(%esp)\n" /* line 967 */
        "movl -0x70(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll FS_FreeFileList\n"
        "movb $1, g_sa+4240\n" /* line 968 */
        "jmp .Lfad324_000ad33d\n"
        ".Lfad324_000ad67c:\n"
        "xorl %ebx, %ebx\n" /* line 1047 | i */
        ".Lfad324_000ad67e:\n"
        "movl (%esi, %ebx, 4), %eax\n" /* line 1048 | fileNames */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* loadspecCurGame */
        "movl %edx, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* trimspec */
        "movl %eax, (%esp)\n"
        "calll Com_LoadSoundAliasFile\n"
        "addl $1, %ebx\n" /* line 1047 | i */
        "cmpl -0x1c(%ebp), %ebx\n" /* fileCount, i */
        "jl .Lfad324_000ad67e\n"
        "jmp .Lfad324_000ad3d9\n"
        ".Lfad324_000ad6a4:\n"
        "movl $0xf, 0xc(%esp)\n" /* line 957 */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021e52c, 4(%esp)\n" /* "Snd_Alias Curve initialization: '.vfcurve' file count (%d) " */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfad324_000ad5d7\n"
    );
}

/* line 1274 */
__attribute__((naked))
SndCurve * Com_RegisterSoundAliasVolumeFalloffCurve(const char *filename, const char *sourceFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1274 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "xorl %esi, %esi\n"
        "movl $g_sa, %ebx\n"
        "movl $g_sa+4244, %edi\n"
        /* { scope 1 */
        ".Lfad6ca_000ad6df:\n"
        "movl 0x1094(%ebx), %eax\n" /* line 1282 */
        "testl %eax, %eax\n"
        "je .Lfad6ca_000ad6fc\n"
        "movl %eax, 4(%esp)\n" /* line 1284 */
        "movl 8(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfad6ca_000ad736\n"
        ".Lfad6ca_000ad6fc:\n"
        "addl $1, %esi\n" /* line 1280 | i */
        "addl $0x48, %edi\n"
        "addl $0x48, %ebx\n"
        "cmpl $0x10, %esi\n" /* i */
        "jne .Lfad6ca_000ad6df\n"
        "movl 8(%ebp), %eax\n" /* line 1288 | filename */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* sourceFile */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021e630, 4(%esp)\n" /* "Sound alias file %s: Volume Falloff Curve '%s' not found." */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1290 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfad6ca_000ad736:\n"
        "movl %edi, %eax\n" /* line 1285 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1290 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1322 */
SndCurve * Com_GetDefaultSoundAliasVolumeFalloffCurve(void)
{
    return (SndCurve *)((char *)&g_sa + 4244);
}

/* line 1346 */
J_COLOR_SPACE * Com_AllocateTempSoundMemory(int size, const char *name)
{
    return (J_COLOR_SPACE *)Hunk_AllocateTempMemoryInternal(size, name);
}

/* line 1357 */
J_COLOR_SPACE * Com_AllocSoundMemory(int size, const char *name, int type)
{
    return (J_COLOR_SPACE *)Hunk_AllocInternal(size);
}

/* line 902 */
__attribute__((naked))
J_COLOR_SPACE Com_UnloadSoundAliasSounds(snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 902 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 911 */
        "calll SND_StopSounds\n"
        "movl 8(%ebp), %eax\n" /* line 913 | system */
        "shll $4, %eax\n"
        "movl g_sa+4108(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* aliases */
        "movl g_sa+4112(%eax), %ecx\n" /* line 914 */
        "testl %ecx, %ecx\n"
        "jle .Lfad75e_000ad81a\n"
        "movl %edx, -0x2c(%ebp)\n"
        "xorl %edi, %edi\n" /* i */
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, %esi\n"
        "jmp .Lfad75e_000ad7b6\n"
        ".Lfad75e_000ad79c:\n"
        "cmpl $3, %ebx\n" /* line 916 */
        "je .Lfad75e_000ad7c4\n"
        "addl $1, %edi\n" /* line 914 | i */
        "addl $0x44, -0x2c(%ebp)\n"
        "movl -0x24(%ebp), %esi\n"
        "cmpl %edi, g_sa+4112(%esi)\n" /* i */
        "jle .Lfad75e_000ad81a\n"
        ".Lfad75e_000ad7b3:\n"
        "movl -0x2c(%ebp), %esi\n"
        ".Lfad75e_000ad7b6:\n"
        "movl 0x2c(%esi), %ebx\n" /* line 916 */
        "andl $0x60, %ebx\n"
        "sarl $5, %ebx\n"
        "cmpl $1, %ebx\n"
        "jne .Lfad75e_000ad79c\n"
        ".Lfad75e_000ad7c4:\n"
        "testl %edi, %edi\n" /* line 918 | i */
        "jle .Lfad75e_000ad822\n"
        "movl -0x2c(%ebp), %eax\n" /* line 876 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl (%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n" /* aliases */
        "xorl %ecx, %ecx\n"
        "jmp .Lfad75e_000ad7e7\n"
        ".Lfad75e_000ad7dd:\n"
        "addl $1, %ecx\n" /* line 918 */
        "addl $0x44, %edx\n"
        "cmpl %ecx, %edi\n" /* i */
        "je .Lfad75e_000ad7fe\n"
        ".Lfad75e_000ad7e7:\n"
        "movl 0xc(%edx), %eax\n" /* line 920 */
        "movl -0x20(%ebp), %esi\n"
        "cmpl %esi, (%eax)\n"
        "jne .Lfad75e_000ad7dd\n"
        "movl 0x2c(%edx), %eax\n"
        "andl $0x60, %eax\n"
        "sarl $5, %eax\n"
        "cmpl %eax, %ebx\n"
        "jne .Lfad75e_000ad7dd\n"
        ".Lfad75e_000ad7fe:\n"
        "movl -0x28(%ebp), %edx\n"
        ".Lfad75e_000ad801:\n"
        "movl $0, 4(%edx)\n" /* line 925 */
        "addl $1, %edi\n" /* line 914 | i */
        "addl $0x44, -0x2c(%ebp)\n"
        "movl -0x24(%ebp), %esi\n"
        "cmpl %edi, g_sa+4112(%esi)\n" /* i */
        "jg .Lfad75e_000ad7b3\n"
        /* } scope */
        ".Lfad75e_000ad81a:\n"
        "addl $0x3c, %esp\n" /* line 928 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfad75e_000ad822:\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfad75e_000ad801\n"
    );
}

/* line 1102 */
__attribute__((naked))
J_COLOR_SPACE Com_UnloadSoundAliases(snd_alias_system_t system)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1102 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* system */
        "cmpb $0, g_sa(%ebx)\n" /* line 1110 | system */
        "je .Lfad830_000ad89c\n"
        "cmpl $2, %ebx\n" /* line 1114 | system */
        "je .Lfad830_000ad850\n"
        "movl %ebx, (%esp)\n" /* line 1115 | system */
        "calll Com_UnloadSoundAliasSounds\n"
        ".Lfad830_000ad850:\n"
        "movl $g_sa+4096, %edx\n" /* line 1123 */
        "movl %ebx, %eax\n" /* system */
        "shll $4, %eax\n"
        "movl g_sa+4108(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfad830_000ad890\n"
        "movl $0, 0xc(%eax, %edx)\n" /* line 1125 */
        "movl $0, 0x10(%eax, %edx)\n" /* line 1126 */
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1132 */
        "movl $0, 4(%esp)\n"
        "movl $g_sa+8, (%esp)\n"
        "calll memset\n"
        ".Lfad830_000ad890:\n"
        "movb $0, g_sa(%ebx)\n" /* line 1139 | system */
        "cmpl $1, %ebx\n" /* line 1141 | system */
        "jbe .Lfad830_000ad8a2\n"
        ".Lfad830_000ad89c:\n"
        "addl $0x14, %esp\n" /* line 1144 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfad830_000ad8a2:\n"
        "cmpw $0, g_sa\n" /* line 1141 */
        "jne .Lfad830_000ad89c\n"
        "movl $str_0021e5f0, 8(%ebp)\n" /* line 1142 | system */
        "addl $0x14, %esp\n" /* line 1144 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp Cmd_RemoveCommand\n" /* line 1142 */
    );
}

/* line 607 */
static __attribute__((naked))
J_COLOR_SPACE Com_StreamedSoundList(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 607 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x20(%ebp)\n" /* system */
        /* { scope 1 */
        "cmpb $0, g_sa(%eax)\n" /* line 613 | system */
        "je .Lfad8be_000ad978\n"
        "shll $4, %eax\n" /* line 616 | system */
        "movl g_sa+4108(%eax), %edx\n" /* system */
        "movl %edx, -0x1c(%ebp)\n" /* aliases */
        "movl g_sa+4112(%eax), %ebx\n" /* line 617 | system */
        "testl %ebx, %ebx\n"
        "jle .Lfad8be_000ad978\n"
        "movl %edx, %ebx\n"
        "xorl %edi, %edi\n" /* i */
        "jmp .Lfad8be_000ad90b\n"
        ".Lfad8be_000ad8f7:\n"
        "addl $1, %edi\n" /* i */
        "addl $0x44, %ebx\n"
        "movl -0x20(%ebp), %eax\n" /* system */
        "shll $4, %eax\n" /* system */
        "cmpl %edi, g_sa+4112(%eax)\n" /* i, system */
        "jle .Lfad8be_000ad978\n"
        ".Lfad8be_000ad90b:\n"
        "movl 0x2c(%ebx), %eax\n" /* line 619 | system */
        "andl $0x60, %eax\n" /* system */
        "cmpl $0x40, %eax\n" /* system */
        "jne .Lfad8be_000ad8f7\n"
        "testl %edi, %edi\n" /* line 622 | i */
        "jle .Lfad8be_000ad980\n"
        "movl -0x1c(%ebp), %edx\n" /* aliases */
        "xorl %ecx, %ecx\n"
        "movl 0xc(%ebx), %esi\n"
        "jmp .Lfad8be_000ad92e\n"
        ".Lfad8be_000ad924:\n"
        "addl $1, %ecx\n"
        "addl $0x44, %edx\n"
        "cmpl %ecx, %edi\n" /* i */
        "je .Lfad8be_000ad94c\n"
        ".Lfad8be_000ad92e:\n"
        "movl 0x2c(%edx), %eax\n" /* line 624 | system */
        "andl $0x60, %eax\n" /* system */
        "cmpl $0x40, %eax\n" /* system */
        "jne .Lfad8be_000ad924\n"
        "movl 0xc(%edx), %eax\n" /* system */
        "movl (%eax), %eax\n" /* system */
        "cmpl (%esi), %eax\n" /* system */
        "je .Lfad8be_000ad8f7\n"
        "addl $1, %ecx\n" /* line 622 */
        "addl $0x44, %edx\n"
        "cmpl %ecx, %edi\n" /* i */
        "jne .Lfad8be_000ad92e\n"
        ".Lfad8be_000ad94c:\n"
        "cmpb $0, 8(%esi)\n" /* line 627 */
        "je .Lfad8be_000ad989\n"
        ".Lfad8be_000ad952:\n"
        "movl (%esi), %eax\n" /* line 628 | system */
        "movl %eax, 4(%esp)\n" /* system */
        "movl $str_0021e66c, (%esp)\n" /* "%-64s
" */
        "calll Com_Printf\n"
        "addl $1, %edi\n" /* line 617 | i */
        "addl $0x44, %ebx\n"
        "movl -0x20(%ebp), %eax\n" /* system */
        "shll $4, %eax\n" /* system */
        "cmpl %edi, g_sa+4112(%eax)\n" /* i, system */
        "jg .Lfad8be_000ad90b\n"
        /* } scope */
        ".Lfad8be_000ad978:\n"
        "addl $0x2c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfad8be_000ad980:\n"
        "movl 0xc(%ebx), %esi\n"
        /* { scope 1 */
        "cmpb $0, 8(%esi)\n" /* line 627 */
        "jne .Lfad8be_000ad952\n"
        ".Lfad8be_000ad989:\n"
        "movl (%esi), %eax\n" /* line 630 | system */
        "movl %eax, 4(%esp)\n" /* system */
        "movl $str_0021e674, (%esp)\n" /* "%-64s FILE NOT FOUND
" */
        "calll Com_Printf\n"
        "jmp .Lfad8be_000ad8f7\n"
    );
}

/* line 563 */
static __attribute__((naked))
J_COLOR_SPACE Com_LoadedSoundList(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 563 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x24(%ebp)\n" /* system */
        /* { scope 1 */
        "cmpb $0, g_sa(%eax)\n" /* line 571 */
        "je .Lfad9a0_000adac0\n"
        "shll $4, %eax\n" /* line 575 */
        "movl g_sa+4108(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* aliases */
        "movl g_sa+4112(%eax), %eax\n" /* line 576 */
        "pxor %xmm0, %xmm0\n"
        "testl %eax, %eax\n"
        "jle .Lfad9a0_000adaa2\n"
        "movl %edx, %ebx\n"
        "xorl %edi, %edi\n" /* i */
        "movl $0, -0x1c(%ebp)\n" /* totalMem */
        "jmp .Lfad9a0_000ad9fc\n"
        ".Lfad9a0_000ad9e4:\n"
        "addl $1, %edi\n" /* i */
        "addl $0x44, %ebx\n"
        "movl -0x24(%ebp), %eax\n"
        "shll $4, %eax\n"
        "cmpl g_sa+4112(%eax), %edi\n" /* i */
        "jge .Lfad9a0_000ada9d\n"
        ".Lfad9a0_000ad9fc:\n"
        "movl 0x2c(%ebx), %eax\n" /* line 578 */
        "andl $0x60, %eax\n"
        "cmpl $0x20, %eax\n"
        "jne .Lfad9a0_000ad9e4\n"
        "testl %edi, %edi\n" /* line 581 | i */
        "jle .Lfad9a0_000adac8\n"
        "movl -0x20(%ebp), %edx\n" /* aliases */
        "xorl %ecx, %ecx\n"
        "movl 0xc(%ebx), %esi\n"
        "jmp .Lfad9a0_000ada23\n"
        ".Lfad9a0_000ada19:\n"
        "addl $1, %ecx\n"
        "addl $0x44, %edx\n"
        "cmpl %ecx, %edi\n" /* i */
        "je .Lfad9a0_000ada41\n"
        ".Lfad9a0_000ada23:\n"
        "movl 0x2c(%edx), %eax\n" /* line 583 */
        "andl $0x60, %eax\n"
        "cmpl $0x20, %eax\n"
        "jne .Lfad9a0_000ada19\n"
        "movl 0xc(%edx), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl (%esi), %eax\n"
        "je .Lfad9a0_000ad9e4\n"
        "addl $1, %ecx\n" /* line 581 */
        "addl $0x44, %edx\n"
        "cmpl %ecx, %edi\n" /* i */
        "jne .Lfad9a0_000ada23\n"
        ".Lfad9a0_000ada41:\n"
        "movl 4(%esi), %eax\n" /* line 586 */
        "testl %eax, %eax\n"
        "je .Lfad9a0_000adad6\n"
        ".Lfad9a0_000ada4c:\n"
        "movl 4(%esi), %eax\n" /* line 588 */
        "movl %eax, (%esp)\n"
        "calll SND_GetSoundFileSize\n"
        "addl %eax, -0x1c(%ebp)\n" /* line 589 | totalMem */
        "cvtsi2ssl %eax, %xmm0\n" /* line 590 */
        "mulss lit4_002ed60c, %xmm0\n" /* 0.0009765625f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021e68c, (%esp)\n" /* "%-64s %7.1f KB
" */
        "calll Com_Printf\n"
        "addl $1, %edi\n" /* line 576 | i */
        "addl $0x44, %ebx\n"
        "movl -0x24(%ebp), %eax\n"
        "shll $4, %eax\n"
        "cmpl g_sa+4112(%eax), %edi\n" /* i */
        "jl .Lfad9a0_000ad9fc\n"
        ".Lfad9a0_000ada9d:\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm0\n" /* totalMem */
        ".Lfad9a0_000adaa2:\n"
        "mulss lit4_002ed820, %xmm0\n" /* line 598 | 9.5367431640625e-07f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_0021e6b4, (%esp)\n" /* "
total usage %7.3f MB
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lfad9a0_000adac0:\n"
        "addl $0x2c, %esp\n" /* line 599 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfad9a0_000adac8:\n"
        "movl 0xc(%ebx), %esi\n"
        /* { scope 1 */
        "movl 4(%esi), %eax\n" /* line 586 */
        "testl %eax, %eax\n"
        "jne .Lfad9a0_000ada4c\n"
        ".Lfad9a0_000adad6:\n"
        "movl (%esi), %eax\n" /* line 594 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021e69c, (%esp)\n" /* "%-64s FAILED TO LOAD
" */
        "calll Com_Printf\n"
        "jmp .Lfad9a0_000ad9e4\n"
    );
}

/* line 641 */
static __attribute__((naked))
J_COLOR_SPACE Com_SoundList_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 641 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $str_0021e6cc, (%esp)\n" /* line 643 */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n" /* line 644 */
        "calll Com_StreamedSoundList\n"
        "movl $str_0021e718, (%esp)\n" /* line 646 */
        "calll Com_Printf\n"
        "movl $1, %eax\n" /* line 647 */
        "calll Com_StreamedSoundList\n"
        "movl $str_0021e768, (%esp)\n" /* line 649 */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n" /* line 650 */
        "calll Com_LoadedSoundList\n"
        "movl $str_0021e7b0, (%esp)\n" /* line 652 */
        "calll Com_Printf\n"
        "movl $1, %eax\n" /* line 653 */
        "calll Com_LoadedSoundList\n"
        "movl $str_002160e8, (%esp)\n" /* line 655 */
        "calll Com_Printf\n"
        "leave\n" /* line 656 */
        "retl\n"
    );
}

/* line 1193 */
__attribute__((naked))
snd_alias_t * Com_PickSoundAliasFromList(snd_alias_list_t *aliasList)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1193 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1202 | aliasList */
        "testl %eax, %eax\n"
        "je .Lfadb54_000adc8e\n"
        "movl 8(%ebp), %eax\n" /* line 1207 | aliasList */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x14(%ebp)\n" /* pFirstAlias */
        "movss 0x34(%eax), %xmm2\n" /* line 1209 */
        "movl 0x10(%eax), %edx\n" /* line 1210 */
        "movl %edx, -0x10(%ebp)\n" /* iMaxSequence */
        "movl %eax, %ecx\n"
        "addl $0x54, %ecx\n"
        "movl %eax, %edi\n" /* pBestAlias */
        "movl %eax, %ebx\n"
        "xorl %esi, %esi\n" /* index */
        "movss lit4_002ed824, %xmm3\n" /* 32768.0f */
        "addl $1, %esi\n" /* line 1215 | index */
        "movl 8(%ebp), %edx\n" /* line 1216 | aliasList */
        "movl 8(%edx), %eax\n"
        "cmpl %esi, %eax\n" /* index */
        "je .Lfadb54_000adbff\n"
        ".Lfadb54_000adb9c:\n"
        "addl $0x44, %ebx\n" /* line 1218 */
        "addss 0x24(%ecx), %xmm2\n" /* line 1219 */
        "movl g_sa+4, %edx\n" /* line 1183 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal str_00269d54+367(%edx, %eax, 4), %eax\n"
        "movl %eax, g_sa+4\n"
        "sarl $0x10, %eax\n" /* line 1221 */
        "andl $0x7fff, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss 0x24(%ecx), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "cmoval %ebx, %edi\n" /* pBestAlias */
        "movl (%ecx), %eax\n" /* line 1226 */
        "cmpl -0x10(%ebp), %eax\n" /* iMaxSequence */
        "jle .Lfadb54_000adbef\n"
        "movl %eax, -0x10(%ebp)\n" /* iMaxSequence */
        ".Lfadb54_000adbef:\n"
        "addl $0x44, %ecx\n" /* line 1210 */
        "addl $1, %esi\n" /* line 1215 | index */
        "movl 8(%ebp), %edx\n" /* line 1216 | aliasList */
        "movl 8(%edx), %eax\n"
        "cmpl %esi, %eax\n" /* index */
        "jne .Lfadb54_000adb9c\n"
        ".Lfadb54_000adbff:\n"
        "cmpl $2, %esi\n" /* line 1231 | index */
        "jg .Lfadb54_000adc17\n"
        ".Lfadb54_000adc04:\n"
        "movl -0x10(%ebp), %eax\n" /* line 1248 | iMaxSequence */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n" /* pBestAlias */
        /* } scope */
        "movl %edi, %eax\n" /* line 1250 | pBestAlias */
        "addl $8, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfadb54_000adc17:\n"
        "movl 0x10(%edi), %esi\n" /* line 1231 | pBestAlias, index */
        "cmpl -0x10(%ebp), %esi\n" /* iMaxSequence, index */
        "jne .Lfadb54_000adc04\n"
        "testl %eax, %eax\n" /* line 1234 */
        "jle .Lfadb54_000adc04\n"
        "movl -0x14(%ebp), %ecx\n" /* pFirstAlias */
        "pxor %xmm2, %xmm2\n"
        "xorl %ebx, %ebx\n"
        ".Lfadb54_000adc2c:\n"
        "cmpl 0x10(%ecx), %esi\n" /* line 1236 | index */
        "je .Lfadb54_000adc7b\n"
        "addss 0x34(%ecx), %xmm2\n" /* line 1238 */
        "movl g_sa+4, %edx\n" /* line 1183 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal str_00269d54+367(%edx, %eax, 4), %eax\n"
        "movl %eax, g_sa+4\n"
        "sarl $0x10, %eax\n" /* line 1240 */
        "andl $0x7fff, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movss lit4_002ed824, %xmm0\n" /* 32768.0f */
        "mulss 0x34(%ecx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "cmoval %ecx, %edi\n" /* pBestAlias */
        ".Lfadb54_000adc7b:\n"
        "addl $0x44, %ecx\n" /* line 1234 */
        "addl $1, %ebx\n"
        "movl 8(%ebp), %eax\n" /* aliasList */
        "cmpl %ebx, 8(%eax)\n"
        "jg .Lfadb54_000adc2c\n"
        "jmp .Lfadb54_000adc04\n"
        ".Lfadb54_000adc8e:\n"
        "xorl %edi, %edi\n" /* line 1202 | pBestAlias */
        /* } scope */
        "movl %edi, %eax\n" /* line 1250 | pBestAlias */
        "addl $8, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 695 */
__attribute__((naked))
snd_alias_list_t * Com_FindSoundAlias(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 695 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "testl %edi, %edi\n" /* line 700 | name */
        "jne .Lfadc9a_000adcb6\n"
        ".Lfadc9a_000adcaa:\n"
        "xorl %ebx, %ebx\n" /* line 704 | aliasList */
        /* } scope */
        ".Lfadc9a_000adcac:\n"
        "movl %ebx, %eax\n" /* line 711 | aliasList */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfadc9a_000adcb6:\n"
        "movzbl (%edi), %eax\n" /* line 680 */
        "testb %al, %al\n"
        "jne .Lfadc9a_000adce5\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfadc9a_000adcbf:\n"
        "movl g_sa+8(, %eax, 4), %ebx\n" /* line 704 | aliasList */
        "testl %ebx, %ebx\n" /* aliasList */
        "je .Lfadc9a_000adcaa\n"
        ".Lfadc9a_000adcca:\n"
        "movl (%ebx), %eax\n" /* line 706 | aliasList */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* name */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfadc9a_000adcac\n"
        "movl 0xc(%ebx), %ebx\n" /* line 704 | aliasList */
        "testl %ebx, %ebx\n" /* aliasList */
        "jne .Lfadc9a_000adcca\n"
        "jmp .Lfadc9a_000adcaa\n"
        /* { scope 2 */
        ".Lfadc9a_000adce5:\n"
        "movl %edi, %esi\n" /* line 680 */
        "xorl %ebx, %ebx\n" /* iHash */
        ".Lfadc9a_000adce9:\n"
        "movsbl %al, %eax\n" /* line 682 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %ebx, %edx\n" /* iHash */
        "shll $4, %edx\n"
        "subl %ebx, %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%ebx, %edx, 2), %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%edx, %eax), %ebx\n" /* iHash */
        "movzbl 1(%esi), %eax\n" /* line 680 */
        "addl $1, %esi\n"
        "testb %al, %al\n"
        "jne .Lfadc9a_000adce9\n"
        "movl %ebx, %eax\n" /* iHash */
        "andl $0x3ff, %eax\n"
        "jmp .Lfadc9a_000adcbf\n"
    );
}

/* line 811 */
__attribute__((naked))
Bool Com_AddAliasList(const char *name, snd_alias_list_t *aliasList)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 811 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        /* { scope 1 */
        /* { scope 2 */
        "movzbl (%edi), %eax\n" /* line 680 */
        "testb %al, %al\n"
        "jne .Lfadd22_000add80\n"
        "xorl %esi, %esi\n"
        /* } scope */
        ".Lfadd22_000add37:\n"
        "movl g_sa+8(, %esi, 4), %eax\n" /* line 817 */
        "movl %eax, %ebx\n" /* aliasListIter */
        "testl %eax, %eax\n"
        "je .Lfadd22_000add64\n"
        ".Lfadd22_000add44:\n"
        "movl (%ebx), %eax\n" /* line 819 | aliasListIter */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* name */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfadd22_000addc0\n"
        "movl 0xc(%ebx), %ebx\n" /* line 817 | aliasListIter */
        "testl %ebx, %ebx\n" /* aliasListIter */
        "jne .Lfadd22_000add44\n"
        "movl g_sa+8(, %esi, 4), %eax\n"
        ".Lfadd22_000add64:\n"
        "movl 0xc(%ebp), %edx\n" /* line 823 | aliasList */
        "movl %eax, 0xc(%edx)\n"
        "movl $g_sa, %eax\n" /* line 824 */
        "movl %edx, 8(%eax, %esi, 4)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 826 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfadd22_000add80:\n"
        "movl %edi, %esi\n" /* line 680 */
        "xorl %ebx, %ebx\n" /* iHash */
        ".Lfadd22_000add84:\n"
        "movsbl %al, %eax\n" /* line 682 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %ebx, %edx\n" /* iHash */
        "shll $4, %edx\n"
        "subl %ebx, %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%ebx, %edx, 2), %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%edx, %eax), %ebx\n" /* iHash */
        "movzbl 1(%esi), %eax\n" /* line 680 */
        "addl $1, %esi\n"
        "testb %al, %al\n"
        "jne .Lfadd22_000add84\n"
        "movl %ebx, %esi\n" /* iHash */
        "andl $0x3ff, %esi\n"
        "jmp .Lfadd22_000add37\n"
        /* } scope */
        ".Lfadd22_000addc0:\n"
        "xorl %eax, %eax\n" /* line 819 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 826 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 835 */
__attribute__((naked))
J_COLOR_SPACE Com_DuplicateSoundAlias(snd_alias_list_t *aliasCopy, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 835 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* aliasCopy */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0xc(%ebp), %edx\n" /* line 680 | name */
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "jne .Lfaddca_000ade85\n"
        "movl $0, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n"
        /* } scope */
        ".Lfaddca_000addee:\n"
        "movl g_sa+8(, %eax, 4), %ebx\n" /* line 843 | aliasList */
        "testl %ebx, %ebx\n" /* aliasList */
        "je .Lfaddca_000ade19\n"
        ".Lfaddca_000addf9:\n"
        "movl (%ebx), %eax\n" /* line 845 | aliasList */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfaddca_000adec8\n"
        "movl 0xc(%ebx), %ebx\n" /* line 843 | aliasList */
        "testl %ebx, %ebx\n" /* aliasList */
        "jne .Lfaddca_000addf9\n"
        ".Lfaddca_000ade19:\n"
        "movl $0x10, (%esp)\n" /* line 1359 */
        "calll Hunk_AllocInternal\n"
        "movl %eax, %ebx\n" /* aliasList */
        "movl (%edi), %eax\n" /* line 854 | aliasCopy */
        "movl %eax, (%ebx)\n" /* aliasList */
        "movl 4(%edi), %eax\n" /* aliasCopy */
        "movl %eax, 4(%ebx)\n" /* aliasList */
        "movl 8(%edi), %eax\n" /* aliasCopy */
        "movl %eax, 8(%ebx)\n" /* aliasList */
        "movl 0xc(%edi), %eax\n" /* aliasCopy */
        "movl %eax, 0xc(%ebx)\n" /* aliasList */
        "cld\n" /* line 856 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* name, aliasCopy */
        "repne scasb %es:(%edi), %al\n" /* aliasCopy */
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, %esi\n"
        "movl 0xc(%ebp), %eax\n" /* line 857 | name */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll strcpy\n"
        "movl %esi, (%ebx)\n" /* line 858 | aliasList */
        "movl -0x1c(%ebp), %edx\n" /* line 860 */
        "movl g_sa+8(, %edx, 4), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* aliasList */
        "movl $g_sa, %eax\n" /* line 861 */
        "movl %ebx, 8(%eax, %edx, 4)\n" /* aliasList */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 862 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaddca_000ade85:\n"
        "movl %edx, %esi\n"
        /* { scope 1 */
        /* { scope 2 */
        "xorl %ebx, %ebx\n" /* line 680 | iHash */
        ".Lfaddca_000ade89:\n"
        "movsbl %al, %eax\n" /* line 682 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %ebx, %edx\n" /* iHash */
        "shll $4, %edx\n"
        "subl %ebx, %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%ebx, %edx, 2), %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%edx, %eax), %ebx\n" /* iHash */
        "movzbl 1(%esi), %eax\n" /* line 680 */
        "addl $1, %esi\n"
        "testb %al, %al\n"
        "jne .Lfaddca_000ade89\n"
        "andl $0x3ff, %ebx\n" /* iHash */
        "movl %ebx, -0x1c(%ebp)\n" /* iHash */
        "movl %ebx, %eax\n" /* iHash */
        "jmp .Lfaddca_000addee\n"
        /* } scope */
        ".Lfaddca_000adec8:\n"
        "movl (%ebx), %edx\n" /* line 847 | aliasList */
        "movl (%edi), %eax\n" /* line 848 | aliasCopy */
        "movl %eax, (%ebx)\n" /* aliasList */
        "movl 4(%edi), %eax\n" /* aliasCopy */
        "movl %eax, 4(%ebx)\n" /* aliasList */
        "movl 8(%edi), %eax\n" /* aliasCopy */
        "movl %eax, 8(%ebx)\n" /* aliasList */
        "movl 0xc(%edi), %eax\n" /* aliasCopy */
        "movl %eax, 0xc(%ebx)\n" /* aliasList */
        "movl %edx, (%ebx)\n" /* line 849 | aliasList */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 862 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 742 */
__attribute__((naked))
int SND_GetAliasOffset(const snd_alias_t *alias)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 742 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 751 | alias */
        "movl (%eax), %edi\n" /* pszName */
        "testl %edi, %edi\n" /* line 700 */
        "je .Lfadeec_000adf2b\n"
        /* { scope 2 */
        /* { scope 3 */
        "movzbl (%edi), %eax\n" /* line 680 */
        "testb %al, %al\n"
        "jne .Lfadeec_000adf5f\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lfadeec_000adf07:\n"
        "movl g_sa+8(, %eax, 4), %ebx\n" /* line 704 | iHash */
        "testl %ebx, %ebx\n" /* iHash */
        "je .Lfadeec_000adf2b\n"
        ".Lfadeec_000adf12:\n"
        "movl (%ebx), %eax\n" /* line 706 | iHash */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pszName */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfadeec_000adf2d\n"
        "movl 0xc(%ebx), %ebx\n" /* line 704 | iHash */
        "testl %ebx, %ebx\n" /* iHash */
        "jne .Lfadeec_000adf12\n"
        ".Lfadeec_000adf2b:\n"
        "xorl %ebx, %ebx\n" /* iHash */
        ".Lfadeec_000adf2d:\n"
        "movl 4(%ebx), %ecx\n" /* line 758 | aliasList */
        "movl 8(%ebx), %edx\n" /* aliasList */
        "testl %edx, %edx\n"
        "jle .Lfadeec_000adf55\n"
        "cmpl %ecx, 8(%ebp)\n" /* line 760 | alias */
        "je .Lfadeec_000adf55\n"
        "xorl %eax, %eax\n"
        ".Lfadeec_000adf3e:\n"
        "addl $0x44, %ecx\n" /* line 758 */
        "addl $1, %eax\n"
        "cmpl %edx, %eax\n"
        "je .Lfadeec_000adf55\n"
        "cmpl %ecx, 8(%ebp)\n" /* line 760 | alias */
        "jne .Lfadeec_000adf3e\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfadeec_000adf55:\n"
        "xorl %eax, %eax\n" /* line 758 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfadeec_000adf5f:\n"
        "movl %edi, %esi\n" /* line 680 */
        "xorl %ebx, %ebx\n" /* iHash */
        ".Lfadeec_000adf63:\n"
        "movsbl %al, %eax\n" /* line 682 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %ebx, %edx\n" /* iHash */
        "shll $4, %edx\n"
        "subl %ebx, %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%ebx, %edx, 2), %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%edx, %eax), %ebx\n" /* iHash */
        "movzbl 1(%esi), %eax\n" /* line 680 */
        "addl $1, %esi\n"
        "testb %al, %al\n"
        "jne .Lfadeec_000adf63\n"
        "movl %ebx, %eax\n" /* iHash */
        "andl $0x3ff, %eax\n"
        "jmp .Lfadeec_000adf07\n"
    );
}

/* line 773 */
__attribute__((naked))
snd_alias_t * SND_GetAliasWithOffset(const char *name, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 773 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "testl %edi, %edi\n" /* line 700 */
        "je .Lfadf9e_000adfdf\n"
        /* { scope 2 */
        "movzbl (%edi), %eax\n" /* line 680 */
        "testb %al, %al\n"
        "jne .Lfadf9e_000ae040\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfadf9e_000adfbb:\n"
        "movl g_sa+8(, %eax, 4), %ebx\n" /* line 704 | iHash */
        "testl %ebx, %ebx\n" /* iHash */
        "je .Lfadf9e_000adfdf\n"
        ".Lfadf9e_000adfc6:\n"
        "movl (%ebx), %eax\n" /* line 706 | iHash */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfadf9e_000adfe1\n"
        "movl 0xc(%ebx), %ebx\n" /* line 704 | iHash */
        "testl %ebx, %ebx\n" /* iHash */
        "jne .Lfadf9e_000adfc6\n"
        ".Lfadf9e_000adfdf:\n"
        "xorl %ebx, %ebx\n" /* iHash */
        ".Lfadf9e_000adfe1:\n"
        "movl 4(%ebx), %esi\n" /* line 789 | aliasList */
        "movl 8(%ebx), %edx\n" /* aliasList */
        "testl %edx, %edx\n"
        "jle .Lfadf9e_000ae011\n"
        "movl 0xc(%ebp), %eax\n" /* line 791 | offset */
        "testl %eax, %eax\n"
        "je .Lfadf9e_000ae007\n"
        "movl %esi, %eax\n"
        "xorl %ecx, %ecx\n"
        ".Lfadf9e_000adff6:\n"
        "addl $0x44, %eax\n" /* line 789 */
        "addl $1, %ecx\n"
        "cmpl %edx, %ecx\n"
        "je .Lfadf9e_000ae007\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* line 791 | offset */
        "jne .Lfadf9e_000adff6\n"
        "movl %eax, %esi\n"
        /* } scope */
        ".Lfadf9e_000ae007:\n"
        "movl %esi, %eax\n" /* line 800 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfadf9e_000ae011:\n"
        "testl %edx, %edx\n" /* line 795 */
        "jne .Lfadf9e_000ae007\n"
        "movl 0xc(%ebp), %eax\n" /* line 798 | offset */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* name */
        "movl $str_0021e7fc, 4(%esp)\n" /* "SND_GetAliasWithOffset: could not find sound alias '%s' with" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %esi, %esi\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 800 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfadf9e_000ae040:\n"
        "movl %edi, %esi\n" /* line 680 */
        "xorl %ebx, %ebx\n" /* iHash */
        ".Lfadf9e_000ae044:\n"
        "movsbl %al, %eax\n" /* line 682 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %ebx, %edx\n" /* iHash */
        "shll $4, %edx\n"
        "subl %ebx, %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%ebx, %edx, 2), %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%edx, %eax), %ebx\n" /* iHash */
        "movzbl 1(%esi), %eax\n" /* line 680 */
        "addl $1, %esi\n"
        "testb %al, %al\n"
        "jne .Lfadf9e_000ae044\n"
        "movl %ebx, %eax\n" /* iHash */
        "andl $0x3ff, %eax\n"
        "jmp .Lfadf9e_000adfbb\n"
    );
}

/* line 1258 */
__attribute__((naked))
snd_alias_t * Com_PickSoundAlias(const char *aliasname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1258 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* aliasname */
        /* { scope 1: iMaxSequence */
        "testl %edi, %edi\n" /* line 700 */
        "je .Lfae082_000ae0bf\n"
        /* { scope 2 */
        "movzbl (%edi), %eax\n" /* line 680 */
        "testb %al, %al\n"
        "jne .Lfae082_000ae0d1\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfae082_000ae09b:\n"
        "movl g_sa+8(, %eax, 4), %ebx\n" /* line 704 | iHash */
        "testl %ebx, %ebx\n" /* iHash */
        "je .Lfae082_000ae0bf\n"
        ".Lfae082_000ae0a6:\n"
        "movl (%ebx), %eax\n" /* line 706 | iHash */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfae082_000ae10d\n"
        "movl 0xc(%ebx), %ebx\n" /* line 704 | iHash */
        "testl %ebx, %ebx\n" /* iHash */
        "jne .Lfae082_000ae0a6\n"
        /* { scope 2 */
        ".Lfae082_000ae0bf:\n"
        "movl $0, -0x20(%ebp)\n" /* line 1248 */
        /* } scope */
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 1264 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iMaxSequence */
        /* { scope 2 */
        ".Lfae082_000ae0d1:\n"
        "movl %edi, %esi\n" /* line 680 */
        "xorl %ebx, %ebx\n" /* iHash */
        ".Lfae082_000ae0d5:\n"
        "movsbl %al, %eax\n" /* line 682 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %ebx, %edx\n" /* iHash */
        "shll $4, %edx\n"
        "subl %ebx, %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%ebx, %edx, 2), %edx\n" /* iHash */
        "leal (%ebx, %edx, 4), %edx\n" /* iHash */
        "leal (%ebx, %edx, 8), %edx\n" /* iHash */
        "leal (%edx, %eax), %ebx\n" /* iHash */
        "movzbl 1(%esi), %eax\n" /* line 680 */
        "addl $1, %esi\n"
        "testb %al, %al\n"
        "jne .Lfae082_000ae0d5\n"
        "movl %ebx, %eax\n" /* iHash */
        "andl $0x3ff, %eax\n"
        "jmp .Lfae082_000ae09b\n"
        /* } scope */
        /* { scope 2 */
        ".Lfae082_000ae10d:\n"
        "movl 4(%ebx), %eax\n" /* line 1207 | iHash */
        "movl %eax, -0x1c(%ebp)\n"
        "movss 0x34(%eax), %xmm2\n" /* line 1209 */
        "movl 0x10(%eax), %edx\n" /* line 1210 */
        "movl %edx, -0x24(%ebp)\n" /* iMaxSequence */
        "movl %eax, %ecx\n"
        "addl $0x54, %ecx\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %eax, %edi\n"
        "xorl %esi, %esi\n" /* index */
        "addl $1, %esi\n" /* line 1215 | index */
        "movl 8(%ebx), %eax\n" /* line 1216 | iHash */
        "cmpl %esi, %eax\n" /* index */
        "je .Lfae082_000ae19e\n"
        ".Lfae082_000ae134:\n"
        "addl $0x44, %edi\n" /* line 1218 */
        "addss 0x24(%ecx), %xmm2\n" /* line 1219 */
        "movl g_sa+4, %edx\n" /* line 1183 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal str_00269d54+367(%edx, %eax, 4), %eax\n"
        "movl %eax, g_sa+4\n"
        "sarl $0x10, %eax\n" /* line 1221 */
        "andl $0x7fff, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movss lit4_002ed824, %xmm0\n" /* 32768.0f */
        "mulss 0x24(%ecx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "movl -0x20(%ebp), %eax\n"
        "cmoval %edi, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1226 */
        "cmpl %eax, -0x24(%ebp)\n" /* iMaxSequence */
        "jge .Lfae082_000ae191\n"
        "movl %eax, -0x24(%ebp)\n" /* iMaxSequence */
        /* } scope */
        ".Lfae082_000ae191:\n"
        "addl $0x44, %ecx\n" /* line 704 */
        /* { scope 2 */
        "addl $1, %esi\n" /* line 1215 | index */
        "movl 8(%ebx), %eax\n" /* line 1216 | iHash */
        "cmpl %esi, %eax\n" /* index */
        "jne .Lfae082_000ae134\n"
        ".Lfae082_000ae19e:\n"
        "cmpl $2, %esi\n" /* line 1231 | index */
        "jle .Lfae082_000ae235\n"
        "movl -0x20(%ebp), %edx\n"
        "movl 0x10(%edx), %esi\n" /* index */
        "cmpl -0x24(%ebp), %esi\n" /* iMaxSequence, index */
        "je .Lfae082_000ae1c6\n"
        ".Lfae082_000ae1b2:\n"
        "movl -0x24(%ebp), %eax\n" /* line 1248 | iMaxSequence */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edx)\n"
        /* } scope */
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 1264 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iMaxSequence */
        /* { scope 2 */
        ".Lfae082_000ae1c6:\n"
        "testl %eax, %eax\n" /* line 1234 */
        "jle .Lfae082_000ae235\n"
        "pxor %xmm2, %xmm2\n"
        "xorl %ecx, %ecx\n"
        ".Lfae082_000ae1d0:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1236 */
        "cmpl 0x10(%eax), %esi\n" /* index */
        "je .Lfae082_000ae229\n"
        "addss 0x34(%eax), %xmm2\n" /* line 1238 */
        "movl g_sa+4, %edx\n" /* line 1183 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal str_00269d54+367(%edx, %eax, 4), %eax\n"
        "movl %eax, g_sa+4\n"
        "sarl $0x10, %eax\n" /* line 1240 */
        "andl $0x7fff, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movss lit4_002ed824, %xmm0\n" /* 32768.0f */
        "movl -0x1c(%ebp), %edx\n"
        "mulss 0x34(%edx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "cmovbel -0x20(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        ".Lfae082_000ae229:\n"
        "addl $0x44, -0x1c(%ebp)\n" /* line 1234 */
        "addl $1, %ecx\n"
        "cmpl 8(%ebx), %ecx\n" /* iHash */
        "jl .Lfae082_000ae1d0\n"
        ".Lfae082_000ae235:\n"
        "movl -0x20(%ebp), %edx\n"
        "jmp .Lfae082_000ae1b2\n"
    );
}

