/* ASM dump from: com_sndalias_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_sndalias_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern struct saLoadObjGlob_type saLoadObjGlob; /* 0x0 */
static char szReference[1024]; /* 0x7ef080 */
static const char * g_pszSndAliasKeyNames[24]; /* 0x30f600 */
static const char * g_pszChannelNames[11]; /* 0x30f660 */

extern int I_stricmp(const char *s0, const char *s1);

void Com_InitSoundAlias(void);
static void Com_RefreshVolumeModGroups_f(void);
static int AliasNameCompare(snd_alias_build_t *pFrontList, snd_alias_build_t *pBackList);
static snd_alias_build_t * Com_SortTempSoundAliases_r(snd_alias_build_t *pAliasList, int *piAliasCount, int (*test)(), int isRemovingDups);
void Com_MakeSoundAliasesPermanent(snd_alias_list_t *aliasInfo, SoundFileInfo *soundFileInfo);
Bool Com_LoadVolumeFalloffCurve(const char *name, SndCurve *curve);
int Com_LoadSoundAliasSounds(SoundFileInfo *soundFileInfo);
void Com_InitDefaultSoundAliasVolumeFalloffCurve(SndCurve *sndCurve);
static const char * Com_GetSubtitleStringEdReference(const char *pszSubtitle);
static void Com_WriteStringEdReferenceToFile(const char *pszReference);
static int FileNameTypeCompare(snd_alias_build_t *frontList, snd_alias_build_t *backList);
static void Com_LoadSoundAliasField(const char *loadspecCurGame, const char *sourceFile, const char *token, snd_alias_members_t field, char *bFieldSet, snd_alias_build_t *alias);
void Com_ProcessSoundAliasFileLocalization(const char *sourceFile, const char *loadspecCurGame, const char *stringEdFileName);
void Com_WriteLocalizedSoundAliasFiles(void);
void Com_LoadSoundAliasFile(const char *loadspec, const char *loadspecCurGame, const char *sourceFile);

/* line 764 */
void Com_InitSoundAlias(void)
{
    *(int *)&saLoadObjGlob = 0;
    *(int *)0x1150524 = 0;
}

/* line 873 */
static void Com_RefreshVolumeModGroups_f(void)
{
    *(byte *)0x1150da8 = 0;
}

/* line 1013 */
static int AliasNameCompare(snd_alias_build_t *pFrontList, snd_alias_build_t *pBackList)
{
    return I_stricmp((const char *)pFrontList + 0x40, (const char *)pBackList + 0x40);
}

/* line 1024 */
static __attribute__((naked))
snd_alias_build_t * Com_SortTempSoundAliases_r(snd_alias_build_t *pAliasList, int *piAliasCount, int (*test)(), int isRemovingDups)
{
    __asm__ __volatile__ (
        ".Lfb6fd4_000b6fd4:\n"
        "pushl %ebp\n" /* line 1024 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movzbl 8(%ebp), %eax\n" /* isRemovingDups */
        "movb %al, -0x35(%ebp)\n" /* isRemovingDups */
        /* { scope 1 */
        "movl (%edx), %ecx\n" /* line 1036 */
        "cmpl $1, %ecx\n"
        "je .Lfb6fd4_000b7167\n"
        "movl %ecx, %eax\n" /* line 1043 */
        "shrl $0x1f, %eax\n"
        "addl %ecx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* iFrontCount */
        "subl %eax, %ecx\n" /* line 1044 */
        "movl %ecx, -0x20(%ebp)\n" /* iBackCount */
        "movl -0x2c(%ebp), %edi\n" /* line 1045 | pBackList */
        "testl %eax, %eax\n"
        "jg .Lfb6fd4_000b710c\n"
        "movl %edi, %esi\n" /* pBackList, ppListPos */
        ".Lfb6fd4_000b7016:\n"
        "movzbl -0x35(%ebp), %ebx\n" /* line 1049 | isRemovingDups */
        "leal -0x1c(%ebp), %edx\n" /* iFrontCount */
        "movl %ebx, (%esp)\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl %edi, %eax\n" /* pBackList */
        "calll Com_SortTempSoundAliases_r\n"
        "movl %eax, %edi\n" /* pBackList */
        "leal -0x20(%ebp), %edx\n" /* line 1050 | iBackCount */
        "movl %ebx, (%esp)\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl %esi, %eax\n" /* ppListPos */
        "calll Com_SortTempSoundAliases_r\n"
        "movl %eax, %ebx\n"
        "movl -0x30(%ebp), %edx\n" /* line 1053 */
        "movl $0, (%edx)\n"
        "movl $0, -0x2c(%ebp)\n" /* line 1054 */
        "leal -0x2c(%ebp), %esi\n" /* ppListPos */
        "movl -0x1c(%ebp), %edx\n" /* iFrontCount */
        ".Lfb6fd4_000b7054:\n"
        "cmpb $0, -0x35(%ebp)\n" /* isRemovingDups */
        "jne .Lfb6fd4_000b70ca\n"
        "jmp .Lfb6fd4_000b7079\n"
        ".Lfb6fd4_000b705c:\n"
        "movl %ebx, (%esi)\n" /* line 1103 | ppListPos */
        "movl 0x150(%ebx), %ebx\n" /* line 1104 */
        "subl $1, -0x20(%ebp)\n" /* line 1105 | iBackCount */
        "movl -0x1c(%ebp), %edx\n" /* iFrontCount */
        ".Lfb6fd4_000b706b:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1108 */
        "addl $1, (%eax)\n"
        "movl (%esi), %esi\n" /* line 1109 | ppListPos */
        "addl $0x150, %esi\n" /* ppListPos */
        ".Lfb6fd4_000b7079:\n"
        "testl %edx, %edx\n" /* line 1056 */
        "je .Lfb6fd4_000b7147\n"
        "movl -0x20(%ebp), %ecx\n" /* iBackCount */
        "testl %ecx, %ecx\n"
        "je .Lfb6fd4_000b715e\n"
        "movl %ebx, 4(%esp)\n" /* line 1058 */
        "movl %edi, (%esp)\n" /* pBackList */
        "calll *-0x34(%ebp)\n"
        "testl %eax, %eax\n" /* line 1095 */
        "jg .Lfb6fd4_000b705c\n"
        "movl %edi, (%esi)\n" /* line 1097 | pBackList, ppListPos */
        "movl 0x150(%edi), %edi\n" /* line 1098 | pBackList */
        "movl -0x1c(%ebp), %edx\n" /* line 1099 | iFrontCount */
        "subl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* iFrontCount */
        "jmp .Lfb6fd4_000b706b\n"
        ".Lfb6fd4_000b70ad:\n"
        "movl %ebx, (%esi)\n" /* line 1103 | ppListPos */
        "movl 0x150(%ebx), %ebx\n" /* line 1104 */
        "subl $1, -0x20(%ebp)\n" /* line 1105 | iBackCount */
        "movl -0x1c(%ebp), %edx\n" /* iFrontCount */
        ".Lfb6fd4_000b70bc:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1108 */
        "addl $1, (%eax)\n"
        "movl (%esi), %esi\n" /* line 1109 | ppListPos */
        "addl $0x150, %esi\n" /* ppListPos */
        ".Lfb6fd4_000b70ca:\n"
        "testl %edx, %edx\n" /* line 1056 */
        "je .Lfb6fd4_000b7147\n"
        "movl -0x20(%ebp), %eax\n" /* iBackCount */
        "testl %eax, %eax\n"
        "je .Lfb6fd4_000b715e\n"
        "movl %ebx, 4(%esp)\n" /* line 1058 */
        "movl %edi, (%esp)\n" /* pBackList */
        "calll *-0x34(%ebp)\n"
        "testl %eax, %eax\n" /* line 1062 */
        "jne .Lfb6fd4_000b70f5\n"
        "movl 0xc4(%edi), %eax\n" /* line 1064 | pBackList */
        "subl 0xc4(%ebx), %eax\n" /* line 1065 */
        "je .Lfb6fd4_000b7122\n"
        ".Lfb6fd4_000b70f5:\n"
        "testl %eax, %eax\n" /* line 1095 */
        "jg .Lfb6fd4_000b70ad\n"
        "movl %edi, (%esi)\n" /* line 1097 | pBackList, ppListPos */
        "movl 0x150(%edi), %edi\n" /* line 1098 | pBackList */
        "movl -0x1c(%ebp), %edx\n" /* line 1099 | iFrontCount */
        "subl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* iFrontCount */
        "jmp .Lfb6fd4_000b70bc\n"
        ".Lfb6fd4_000b710c:\n"
        "movl %edi, %esi\n" /* line 1045 | pBackList, ppListPos */
        "xorl %edx, %edx\n"
        ".Lfb6fd4_000b7110:\n"
        "addl $1, %edx\n"
        "movl 0x150(%esi), %esi\n" /* ppListPos */
        "cmpl %edx, %eax\n"
        "jne .Lfb6fd4_000b7110\n"
        "jmp .Lfb6fd4_000b7016\n"
        ".Lfb6fd4_000b7122:\n"
        "movl %ebx, 4(%esp)\n" /* line 1068 */
        "movl %edi, (%esp)\n" /* pBackList */
        "calll I_stricmp\n"
        "cmpl $0, %eax\n" /* line 1069 */
        "je .Lfb6fd4_000b717f\n"
        "jl .Lfb6fd4_000b71b4\n" /* line 1080 */
        "movl 0x150(%ebx), %ebx\n" /* line 1087 */
        "subl $1, -0x20(%ebp)\n" /* line 1088 | iBackCount */
        "movl -0x1c(%ebp), %edx\n" /* iFrontCount */
        "jmp .Lfb6fd4_000b7054\n"
        ".Lfb6fd4_000b7147:\n"
        "movl %ebx, (%esi)\n" /* line 1120 | ppListPos */
        "movl -0x30(%ebp), %edx\n" /* line 1121 */
        "movl (%edx), %eax\n"
        "addl -0x20(%ebp), %eax\n" /* iBackCount */
        "movl %eax, (%edx)\n"
        ".Lfb6fd4_000b7153:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1124 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1125 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb6fd4_000b715e:\n"
        "movl %edi, (%esi)\n" /* line 1115 | pBackList, ppListPos */
        "movl -0x30(%ebp), %eax\n" /* line 1116 */
        "addl %edx, (%eax)\n"
        "jmp .Lfb6fd4_000b7153\n"
        ".Lfb6fd4_000b7167:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1038 */
        "movl $0, 0x150(%eax)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1039 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1125 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb6fd4_000b717f:\n"
        "leal 0x40(%edi), %eax\n" /* line 1071 | pBackList */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* pBackList */
        "movl $0x21ec34, (%esp)\n" /* "^1ERROR: sound alias file %s: duplicate alias '%s'
" */
        "calll Com_Printf\n"
        "movl 0x150(%edi), %edi\n" /* line 1072 | pBackList */
        "movl -0x1c(%ebp), %edx\n" /* line 1073 | iFrontCount */
        "subl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* iFrontCount */
        "movl 0x150(%ebx), %ebx\n" /* line 1074 */
        "subl $1, -0x20(%ebp)\n" /* line 1075 | iBackCount */
        "jmp .Lfb6fd4_000b7054\n"
        ".Lfb6fd4_000b71b4:\n"
        "movl 0x150(%edi), %edi\n" /* line 1082 | pBackList */
        "movl -0x1c(%ebp), %edx\n" /* line 1083 | iFrontCount */
        "subl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* iFrontCount */
        "jmp .Lfb6fd4_000b7054\n"
    );
}

/* line 1294 */
__attribute__((naked))
void Com_MakeSoundAliasesPermanent(snd_alias_list_t *aliasInfo, SoundFileInfo *soundFileInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1294 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 1314 | soundFileInfo */
        "movl $0, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 1315 | aliasInfo */
        "movl $0, 8(%edx)\n"
        "movl 0x1150524, %eax\n" /* line 1317 */
        "testl %eax, %eax\n"
        "jne .Lfb71c8_000b71f5\n"
        /* } scope */
        ".Lfb71c8_000b71ed:\n"
        "addl $0x7c, %esp\n" /* line 1446 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb71c8_000b71f5:\n"
        "movl $1, (%esp)\n" /* line 1320 */
        "movl $AliasNameCompare, %ecx\n"
        "movl $0x1150524, %edx\n"
        "movl saLoadObjGlob, %eax\n"
        "calll Com_SortTempSoundAliases_r\n"
        "movl %eax, saLoadObjGlob\n"
        "testl %eax, %eax\n" /* line 1321 */
        "je .Lfb71c8_000b71ed\n"
        "movl $0, (%esp)\n" /* line 1323 */
        "movl $FileNameTypeCompare, %ecx\n"
        "movl $0x1150524, %edx\n"
        "calll Com_SortTempSoundAliases_r\n"
        "movl %eax, %ebx\n" /* alias */
        "movl %eax, saLoadObjGlob\n"
        "testl %eax, %eax\n" /* line 1324 */
        "je .Lfb71c8_000b71ed\n"
        "movl $0, -0x3c(%ebp)\n" /* line 1325 | stringBytesCount */
        "movl $0, -0x44(%ebp)\n" /* other */
        "movl $0, -0x4c(%ebp)\n" /* currentName */
        "movl $0, -0x30(%ebp)\n" /* soundCount */
        ".Lfb71c8_000b7256:\n"
        "leal 0xc8(%ebx), %ecx\n" /* line 1335 | alias */
        "movl %ecx, -0x24(%ebp)\n"
        "cld\n"
        "xorl %eax, %eax\n"
        "movl $0xffffffff, %ecx\n"
        "movl -0x24(%ebp), %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %esi\n"
        "notl %esi\n"
        "movl -0x44(%ebp), %eax\n" /* line 1337 | other */
        "testl %eax, %eax\n"
        "je .Lfb71c8_000b728c\n"
        "movl 0x12c(%ebx), %eax\n" /* alias */
        "movl -0x44(%ebp), %edi\n" /* other */
        "cmpl 0x12c(%edi), %eax\n"
        "je .Lfb71c8_000b7642\n"
        ".Lfb71c8_000b728c:\n"
        "xorl %edi, %edi\n"
        "movl -0x4c(%ebp), %eax\n" /* line 1338 | currentName */
        "testl %eax, %eax\n"
        "je .Lfb71c8_000b7652\n"
        ".Lfb71c8_000b7299:\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x4c(%ebp), %ecx\n" /* currentName */
        "movl %ecx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb71c8_000b7652\n"
        "movl %edi, %eax\n" /* line 1340 */
        "testb %al, %al\n"
        "je .Lfb71c8_000b7671\n"
        "movl -0x44(%ebp), %ecx\n" /* line 1357 | other */
        "movl %ecx, 0x14c(%ebx)\n" /* alias */
        ".Lfb71c8_000b72c6:\n"
        "movl 0x150(%ebx), %ebx\n" /* line 1333 | alias */
        "testl %ebx, %ebx\n" /* alias */
        "jne .Lfb71c8_000b7256\n"
        "movl $1, (%esp)\n" /* line 1361 */
        "movl $AliasNameCompare, %ecx\n"
        "movl $0x1150524, %edx\n"
        "movl saLoadObjGlob, %eax\n"
        "calll Com_SortTempSoundAliases_r\n"
        "movl %eax, %esi\n"
        "movl %eax, saLoadObjGlob\n"
        "testl %eax, %eax\n" /* line 1362 */
        "je .Lfb71c8_000b71ed\n"
        "movl $0, -0x2c(%ebp)\n" /* line 1363 */
        ".Lfb71c8_000b7301:\n"
        "leal 0x40(%esi), %edi\n" /* line 1368 */
        "movl %edi, -0x28(%ebp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n" /* alias */
        "notl %ebx\n" /* alias */
        "movl -0x2c(%ebp), %eax\n" /* line 1369 */
        "testl %eax, %eax\n"
        "je .Lfb71c8_000b7332\n"
        "movl -0x28(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfb71c8_000b733b\n"
        ".Lfb71c8_000b7332:\n"
        "addl %ebx, -0x3c(%ebp)\n" /* line 1371 | alias, stringBytesCount */
        "movl -0x28(%ebp), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        ".Lfb71c8_000b733b:\n"
        "movl 0xc0(%esi), %edx\n" /* line 1379 */
        "testl %edx, %edx\n"
        "je .Lfb71c8_000b7356\n"
        "cld\n" /* line 1380 */
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl %ecx, -0x3c(%ebp)\n" /* stringBytesCount */
        ".Lfb71c8_000b7356:\n"
        "movl 0x150(%esi), %esi\n" /* line 1366 */
        "testl %esi, %esi\n"
        "jne .Lfb71c8_000b7301\n"
        "movl $0xe, 8(%esp)\n" /* line 1383 */
        "movl $0x21eccc, 4(%esp)\n" /* "Com_MakeSoundAliasesPermanent:aliases" */
        "movl 0x1150524, %eax\n"
        "movl %eax, %edx\n"
        "shll $6, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_AllocSoundMemory\n"
        "movl 8(%ebp), %edx\n" /* aliasInfo */
        "movl %eax, 4(%edx)\n"
        "movl $0xe, 8(%esp)\n" /* line 1384 */
        "movl $0x21ecf4, 4(%esp)\n" /* "Com_MakeSoundAliasesPermanent:soundFiles" */
        "shll $4, -0x30(%ebp)\n" /* soundCount */
        "movl -0x30(%ebp), %ecx\n" /* soundCount */
        "movl %ecx, (%esp)\n"
        "calll Com_AllocSoundMemory\n"
        "movl 0xc(%ebp), %edi\n" /* soundFileInfo */
        "movl %eax, 4(%edi)\n"
        "movl $0xe, 8(%esp)\n" /* line 1385 */
        "movl $0x21ed20, 4(%esp)\n" /* "Com_MakeSoundAliasesPermanent:strings" */
        "movl -0x3c(%ebp), %eax\n" /* stringBytesCount */
        "movl %eax, (%esp)\n"
        "calll Com_AllocSoundMemory\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl saLoadObjGlob, %esi\n" /* line 1392 */
        "testl %esi, %esi\n"
        "je .Lfb71c8_000b71ed\n"
        "movl $0, -0x34(%ebp)\n" /* aliasList */
        "leal 0x40(%esi), %ebx\n" /* alias */
        "movl -0x1c(%ebp), %edi\n"
        ".Lfb71c8_000b73e9:\n"
        "movl %ebx, 4(%esp)\n" /* line 1397 | alias */
        "movl %edi, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 1398 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x1c(%ebp), %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl -0x1c(%ebp), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        ".Lfb71c8_000b740a:\n"
        "movl 0xc0(%esi), %eax\n" /* line 1401 */
        "testl %eax, %eax\n"
        "je .Lfb71c8_000b7737\n"
        "movl %eax, 4(%esp)\n" /* line 1404 */
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 1405 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x20(%ebp), %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl -0x20(%ebp), %ecx\n"
        "movl %ecx, -0x40(%ebp)\n" /* strings */
        "movl -0x20(%ebp), %ecx\n"
        "movl %ecx, -0x48(%ebp)\n" /* subtitle */
        ".Lfb71c8_000b7442:\n"
        "movl 8(%ebp), %edi\n" /* line 1412 | aliasInfo */
        "movl 8(%edi), %edx\n"
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* alias */
        "addl 4(%edi), %ebx\n" /* alias */
        "movl -0x34(%ebp), %edi\n" /* line 1414 | aliasList */
        "testl %edi, %edi\n"
        "je .Lfb71c8_000b7475\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n" /* aliasList */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfb71c8_000b74b6\n"
        ".Lfb71c8_000b7475:\n"
        "movl $0xe, 8(%esp)\n" /* line 1416 */
        "movl $0x21ed48, 4(%esp)\n" /* "Com_MakeSoundAliasesPermanent:aliasList" */
        "movl $0x10, (%esp)\n"
        "calll Com_AllocSoundMemory\n"
        "movl %eax, -0x34(%ebp)\n" /* aliasList */
        "movl %eax, 4(%esp)\n" /* line 1417 */
        "movl -0x1c(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_AddAliasList\n"
        "testb %al, %al\n"
        "je .Lfb71c8_000b778d\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1424 */
        "movl -0x34(%ebp), %edx\n" /* aliasList */
        "movl %ecx, (%edx)\n"
        "movl %ebx, 4(%edx)\n" /* line 1425 | alias */
        ".Lfb71c8_000b74b6:\n"
        "movl 0x14c(%esi), %eax\n" /* line 1428 */
        "testl %eax, %eax\n"
        "je .Lfb71c8_000b77b2\n"
        "movl 0x108(%eax), %eax\n" /* line 1430 */
        "movl %eax, -0x38(%ebp)\n" /* currentSound */
        "movl -0x40(%ebp), %edi\n" /* strings */
        "movl %edi, -0x20(%ebp)\n"
        "movl %eax, %edx\n"
        ".Lfb71c8_000b74d5:\n"
        "movl %edx, 0x108(%esi)\n" /* line 1441 */
        "movl -0x1c(%ebp), %ecx\n" /* line 1231 */
        "movl %ecx, (%ebx)\n"
        "cmpb $0, 0x80(%esi)\n" /* line 1232 */
        "jne .Lfb71c8_000b7749\n"
        "movl $0, 8(%ebx)\n" /* line 1239 */
        ".Lfb71c8_000b74f4:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 1241 | currentSound */
        "movl %ecx, 0xc(%ebx)\n"
        "movl -0x48(%ebp), %edi\n" /* line 1242 | subtitle */
        "movl %edi, 4(%ebx)\n"
        "movl $0, 0x10(%ebx)\n" /* line 1243 */
        "movl 0x10c(%esi), %eax\n" /* line 1244 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 0x110(%esi), %eax\n" /* line 1245 */
        "movl %eax, 0x18(%ebx)\n"
        "movl 0x118(%esi), %eax\n" /* line 1246 */
        "movl %eax, 0x1c(%ebx)\n"
        "movl 0x11c(%esi), %eax\n" /* line 1247 */
        "movl %eax, 0x20(%ebx)\n"
        "movl 0x120(%esi), %eax\n" /* line 1248 */
        "movl %eax, 0x24(%ebx)\n"
        "movl 0x124(%esi), %eax\n" /* line 1249 */
        "movl %eax, 0x28(%ebx)\n"
        "movl 0x2c(%ebx), %edx\n" /* line 1250 */
        "andl $0xfffff87f, %edx\n"
        "movl 0x128(%esi), %eax\n"
        "shll $7, %eax\n"
        "orl %eax, %edx\n"
        "movl %edx, 0x2c(%ebx)\n"
        "andl $0xffffff9f, %edx\n" /* line 1251 */
        "movl 0x12c(%esi), %eax\n"
        "shll $5, %eax\n"
        "orl %eax, %edx\n"
        "movl %edx, 0x2c(%ebx)\n"
        "movl 0x130(%esi), %eax\n" /* line 1252 */
        "movl %eax, 0x40(%ebx)\n"
        "cmpb $0, 0x144(%esi)\n" /* line 1257 */
        "je .Lfb71c8_000b772c\n"
        "orl $1, %edx\n" /* line 1258 */
        "movl %edx, 0x2c(%ebx)\n"
        ".Lfb71c8_000b7581:\n"
        "cmpb $0, 0x145(%esi)\n" /* line 1262 */
        "je .Lfb71c8_000b771e\n"
        "movl 0x2c(%ebx), %edx\n" /* line 1263 */
        "orl $2, %edx\n"
        "movl %edx, 0x2c(%ebx)\n"
        ".Lfb71c8_000b7597:\n"
        "cmpb $0, 0x146(%esi)\n" /* line 1267 */
        "je .Lfb71c8_000b7713\n"
        "orl $4, %edx\n" /* line 1268 */
        "movl %edx, 0x2c(%ebx)\n"
        ".Lfb71c8_000b75aa:\n"
        "cmpb $0, 0x147(%esi)\n" /* line 1272 */
        "je .Lfb71c8_000b7708\n"
        "orl $8, %edx\n" /* line 1273 */
        "movl %edx, 0x2c(%ebx)\n"
        ".Lfb71c8_000b75bd:\n"
        "cmpb $0, 0x148(%esi)\n" /* line 1277 */
        "je .Lfb71c8_000b76fd\n"
        "orl $0x10, %edx\n" /* line 1278 */
        "movl %edx, 0x2c(%ebx)\n"
        ".Lfb71c8_000b75d0:\n"
        "movl 0x134(%esi), %eax\n" /* line 1282 */
        "movl %eax, 0x30(%ebx)\n"
        "movl 0x138(%esi), %eax\n" /* line 1283 */
        "movl %eax, 0x34(%ebx)\n"
        "movl 0x13c(%esi), %eax\n" /* line 1284 */
        "movl %eax, 0x38(%ebx)\n"
        "movl 0x140(%esi), %eax\n" /* line 1285 */
        "movl %eax, 0x3c(%ebx)\n"
        "movl 8(%ebp), %eax\n" /* line 1443 | aliasInfo */
        "addl $1, 8(%eax)\n"
        "movl -0x34(%ebp), %edx\n" /* line 1444 | aliasList */
        "addl $1, 8(%edx)\n"
        ".Lfb71c8_000b7602:\n"
        "movl 0x150(%esi), %esi\n" /* line 1392 */
        "testl %esi, %esi\n"
        "je .Lfb71c8_000b71ed\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1394 */
        "testl %eax, %eax\n"
        "je .Lfb71c8_000b7829\n"
        "leal 0x40(%esi), %ebx\n" /* alias */
        "movl %ebx, 4(%esp)\n" /* alias */
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfb71c8_000b740a\n"
        "movl -0x20(%ebp), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edi\n"
        "jmp .Lfb71c8_000b73e9\n"
        ".Lfb71c8_000b7642:\n"
        "movl $1, %edi\n" /* line 1337 */
        "movl -0x4c(%ebp), %eax\n" /* line 1338 | currentName */
        "testl %eax, %eax\n"
        "jne .Lfb71c8_000b7299\n"
        ".Lfb71c8_000b7652:\n"
        "movl $0, 0x14c(%ebx)\n" /* line 1349 | alias */
        "addl %esi, -0x3c(%ebp)\n" /* line 1350 | stringBytesCount */
        "addl $1, -0x30(%ebp)\n" /* line 1351 | soundCount */
        "movl %ebx, -0x44(%ebp)\n" /* alias, other */
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* currentName */
        "jmp .Lfb71c8_000b72c6\n"
        /* { scope 2 */
        ".Lfb71c8_000b7671:\n"
        "movl 0x12c(%ebx), %eax\n" /* line 1174 */
        "cmpl $2, %eax\n"
        "je .Lfb71c8_000b781f\n"
        "movl $0x21ec68, %ecx\n" /* "primed" */
        "cmpl $3, %eax\n"
        "movl $0x21ec70, %eax\n" /* "loaded" */
        "cmovnel %eax, %ecx\n"
        ".Lfb71c8_000b7690:\n"
        "movl -0x44(%ebp), %edi\n" /* line 1187 | other */
        "movl 0x12c(%edi), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lfb71c8_000b7815\n"
        "movl $0x21ec68, %edx\n" /* "primed" */
        "cmpl $3, %eax\n"
        "movl $0x21ec70, %eax\n" /* "loaded" */
        "cmovnel %eax, %edx\n"
        ".Lfb71c8_000b76b2:\n"
        "movl -0x44(%ebp), %eax\n" /* line 1201 | other */
        "addl $0x40, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "leal 0x40(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21ec84, (%esp)\n" /* "WARNING: sound file '%s' used as %s in alias '%s' and %s in " */
        "calll Com_Printf\n"
        /* } scope */
        "movl $0, 0x14c(%ebx)\n" /* line 1349 | alias */
        "addl %esi, -0x3c(%ebp)\n" /* line 1350 | stringBytesCount */
        "addl $1, -0x30(%ebp)\n" /* line 1351 | soundCount */
        "movl %ebx, -0x44(%ebp)\n" /* alias, other */
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* currentName */
        "jmp .Lfb71c8_000b72c6\n"
        ".Lfb71c8_000b76fd:\n"
        "andl $0xffffffef, %edx\n" /* line 1280 */
        "movl %edx, 0x2c(%ebx)\n"
        "jmp .Lfb71c8_000b75d0\n"
        ".Lfb71c8_000b7708:\n"
        "andl $0xfffffff7, %edx\n" /* line 1275 */
        "movl %edx, 0x2c(%ebx)\n"
        "jmp .Lfb71c8_000b75bd\n"
        ".Lfb71c8_000b7713:\n"
        "andl $0xfffffffb, %edx\n" /* line 1270 */
        "movl %edx, 0x2c(%ebx)\n"
        "jmp .Lfb71c8_000b75aa\n"
        ".Lfb71c8_000b771e:\n"
        "movl 0x2c(%ebx), %edx\n" /* line 1265 */
        "andl $0xfffffffd, %edx\n"
        "movl %edx, 0x2c(%ebx)\n"
        "jmp .Lfb71c8_000b7597\n"
        ".Lfb71c8_000b772c:\n"
        "andl $0xfffffffe, %edx\n" /* line 1260 */
        "movl %edx, 0x2c(%ebx)\n"
        "jmp .Lfb71c8_000b7581\n"
        ".Lfb71c8_000b7737:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1401 */
        "movl %eax, -0x40(%ebp)\n" /* strings */
        "movl $0, -0x48(%ebp)\n" /* subtitle */
        "jmp .Lfb71c8_000b7442\n"
        ".Lfb71c8_000b7749:\n"
        "leal 0x80(%esi), %edi\n" /* line 1234 */
        "movl %edi, -0x5c(%ebp)\n"
        "movl $0xe, 8(%esp)\n"
        "movl $0x21eda0, 4(%esp)\n" /* "Com_AddSoundAlias" */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_AllocSoundMemory\n"
        "movl %eax, 8(%ebx)\n"
        "movl -0x5c(%ebp), %edx\n" /* line 1235 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lfb71c8_000b74f4\n"
        ".Lfb71c8_000b778d:\n"
        "movl -0x1c(%ebp), %edi\n" /* line 1420 */
        "movl %edi, 4(%esp)\n"
        "movl $0x21ed70, (%esp)\n" /* "^1ERROR: alias '%s' already added - ignoring
" */
        "calll Com_Printf\n"
        "movl -0x40(%ebp), %eax\n" /* strings */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* aliasList */
        "jmp .Lfb71c8_000b7602\n"
        ".Lfb71c8_000b77b2:\n"
        "leal 0xc8(%esi), %eax\n" /* line 1435 */
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* strings */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 1436 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x40(%ebp), %edi\n" /* strings */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl -0x40(%ebp), %ecx\n" /* strings */
        "movl %ecx, -0x20(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 1437 | soundFileInfo */
        "movl (%edx), %edx\n"
        "shll $4, %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* currentSound */
        "movl 0xc(%ebp), %ecx\n" /* soundFileInfo */
        "movl 4(%ecx), %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* currentSound */
        "movl 0x12c(%esi), %eax\n" /* line 1438 | type */
        /* { scope 2 */
        "movl -0x40(%ebp), %edi\n" /* line 1214 | strings */
        "movl %edi, (%edx)\n"
        "movl $0, 4(%edx)\n" /* line 1215 */
        "movl %eax, 0xc(%edx)\n" /* line 1216 */
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 1439 | soundFileInfo */
        "addl $1, (%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* currentSound */
        "jmp .Lfb71c8_000b74d5\n"
        /* { scope 2 */
        ".Lfb71c8_000b7815:\n"
        "movl $0x21ec78, %edx\n" /* line 1187 */
        "jmp .Lfb71c8_000b76b2\n"
        ".Lfb71c8_000b781f:\n"
        "movl $0x21ec78, %ecx\n" /* line 1174 */
        "jmp .Lfb71c8_000b7690\n"
        ".Lfb71c8_000b7829:\n"
        "leal 0x40(%esi), %ebx\n"
        /* } scope */
        "movl -0x20(%ebp), %ecx\n" /* line 1394 */
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, %edi\n"
        "jmp .Lfb71c8_000b73e9\n"
    );
}

/* line 1548 */
__attribute__((naked))
Bool Com_LoadVolumeFalloffCurve(const char *name, SndCurve *curve)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1548 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x207c, %esp\n"
        /* { scope 1: buffer */
        "movl 8(%ebp), %eax\n" /* line 1557 | name */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x21edb4, 8(%esp)\n" /* "soundaliases/%s.vfcurve" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x60(%ebp), %edx\n" /* fileName */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $1, 8(%esp)\n" /* line 1559 */
        "leal -0x1c(%ebp), %eax\n" /* fileHandle */
        "movl %eax, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* fileName */
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileRead\n"
        "movl %eax, %ebx\n" /* fileLength */
        "cmpl $0, %eax\n" /* line 1560 */
        "jl .Lfb783a_000b7a2a\n"
        "je .Lfb783a_000b79a9\n" /* line 1565 */
        "movl -0x1c(%ebp), %eax\n" /* line 1573 | fileHandle */
        "movl %eax, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "leal -0x2060(%ebp), %edx\n" /* buffer */
        "movl %edx, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x2058(%ebp)\n" /* line 1574 */
        "movl $0x21ee20, %edi\n" /* line 1576 */
        "movl $8, %ecx\n"
        "cld\n"
        "leal -0x2060(%ebp), %esi\n" /* buffer */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lfb783a_000b78db\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfb783a_000b78db:\n"
        "testl %eax, %eax\n"
        "jne .Lfb783a_000b79ff\n"
        "leal -8(%ebx), %esi\n" /* line 1584 | fileLength */
        "cmpl $0x1fff, %esi\n"
        "jg .Lfb783a_000b79d4\n"
        "movl $0x2000, 8(%esp)\n" /* line 1592 */
        "movl $0, 4(%esp)\n"
        "leal -0x2060(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1593 | fileHandle */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x2060(%ebp), %edx\n" /* buffer */
        "movl %edx, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x2060(%ebp, %esi)\n" /* line 1594 */
        "movl -0x1c(%ebp), %eax\n" /* line 1595 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0x2060(%ebp), %eax\n" /* buffer */
        "movl %eax, -0x20(%ebp)\n" /* buffer */
        /* { scope 2 */
        /* { scope 3 */
        "leal -0x60(%ebp), %edx\n" /* line 1463 | fileName */
        "movl %edx, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "leal -0x20(%ebp), %edi\n" /* line 1466 | buffer */
        "movl %edi, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, (%esp)\n" /* line 1467 */
        "calll atoi\n"
        "movl 0xc(%ebp), %edx\n" /* curve */
        "movl %eax, 4(%edx)\n"
        "cmpl $1, %eax\n" /* line 1468 */
        "jle .Lfb783a_000b7b2c\n"
        "cmpl $8, %eax\n" /* line 1474 */
        "jle .Lfb783a_000b7a4a\n"
        "calll Com_EndParseSession\n" /* line 1476 */
        "movl $8, 0xc(%esp)\n" /* line 1477 */
        "movl 0xc(%ebp), %edx\n" /* curve */
        "movl 4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* fileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x21eeec, (%esp)\n" /* "^1ERROR: sndcurve parse failure on file "%s": knot count (%d" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 1597 */
        "jmp .Lfb783a_000b79c9\n"
        ".Lfb783a_000b79a9:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1567 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0x60(%ebp), %eax\n" /* line 1568 | fileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x21edf8, (%esp)\n" /* "^1ERROR: sndcurve file '%s' is empty
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfb783a_000b79c9:\n"
        "addl $0x207c, %esp\n" /* line 1602 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buffer */
        ".Lfb783a_000b79d4:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1586 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0x60(%ebp), %edx\n" /* line 1587 | fileName */
        "movl %edx, 4(%esp)\n"
        "movl $0x21ee64, (%esp)\n" /* "^1ERROR: "%s" Is too long of a sndcurve file to parse
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x207c, %esp\n" /* line 1602 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buffer */
        ".Lfb783a_000b79ff:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1578 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0x60(%ebp), %eax\n" /* line 1579 | fileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x21ee2c, (%esp)\n" /* "^1ERROR: "%s" does not appear to be a sndcurve file
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x207c, %esp\n" /* line 1602 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buffer */
        ".Lfb783a_000b7a2a:\n"
        "leal -0x60(%ebp), %edx\n" /* line 1562 | fileName */
        "movl %edx, 4(%esp)\n"
        "movl $0x21edcc, (%esp)\n" /* "^1ERROR: Could not load sndcurve file '%s'
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x207c, %esp\n" /* line 1602 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buffer */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfb783a_000b7a4a:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1477 | curve */
        "xorl %esi, %esi\n"
        "jmp .Lfb783a_000b7ae0\n"
        ".Lfb783a_000b7a54:\n"
        "movl %eax, (%esp)\n" /* line 1496 */
        "calll atof\n"
        "fstpl -0x2078(%ebp)\n"
        "cvtsd2ss -0x2078(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "pxor %xmm1, %xmm1\n" /* line 1497 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lfb783a_000b7bc9\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ja .Lfb783a_000b7bc9\n"
        "movl %edi, (%esp)\n" /* line 1504 */
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 1505 */
        "testb %dl, %dl\n"
        "je .Lfb783a_000b7b55\n"
        "cmpb $0x7d, %dl\n"
        "je .Lfb783a_000b7b55\n"
        "movl %eax, (%esp)\n" /* line 1508 */
        "calll atof\n"
        "fstpl -0x2070(%ebp)\n"
        "cvtsd2ss -0x2070(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%ebx)\n"
        "pxor %xmm1, %xmm1\n" /* line 1509 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lfb783a_000b7bf7\n"
        "addl $8, %ebx\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ja .Lfb783a_000b7bf7\n"
        "addl $1, %esi\n" /* line 1516 */
        ".Lfb783a_000b7ae0:\n"
        "movl %edi, (%esp)\n" /* line 1485 */
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 1486 */
        "testb %dl, %dl\n"
        "je .Lfb783a_000b7b55\n"
        "cmpb $0x7d, %dl\n"
        "je .Lfb783a_000b7b55\n"
        "cmpl $8, %esi\n" /* line 1489 */
        "jne .Lfb783a_000b7a54\n"
        "calll Com_EndParseSession\n" /* line 1491 */
        "movl $8, 0xc(%esp)\n" /* line 1492 */
        "movl $8, 8(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* fileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x21ef4c, (%esp)\n" /* "^1ERROR: sndcurve parse failure on file "%s": knots parsed (" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 1597 */
        "jmp .Lfb783a_000b79c9\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfb783a_000b7b2c:\n"
        "calll Com_EndParseSession\n" /* line 1470 */
        "movl 0xc(%ebp), %edx\n" /* line 1471 | curve */
        "movl 4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* fileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x21ee9c, (%esp)\n" /* "^1ERROR: sndcurve parse failure on file "%s": knot count (%d" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 1597 */
        "jmp .Lfb783a_000b79c9\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfb783a_000b7b55:\n"
        "calll Com_EndParseSession\n" /* line 1519 */
        "movl 0xc(%ebp), %edx\n" /* line 1521 | curve */
        "movl 4(%edx), %eax\n"
        "cmpl %esi, %eax\n"
        "je .Lfb783a_000b7b86\n"
        "movl %esi, 0xc(%esp)\n" /* line 1523 */
        "movl %eax, 8(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* fileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x21f014, (%esp)\n" /* "^1ERROR: sndcurve parse failure on file "%s": knot count (%d" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 1597 */
        "jmp .Lfb783a_000b79c9\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfb783a_000b7b86:\n"
        "subl $1, %eax\n" /* line 1527 */
        "pxor %xmm1, %xmm1\n" /* line 1528 */
        "ucomiss 8(%edx), %xmm1\n"
        "jne .Lfb783a_000b7c0a\n"
        "jp .Lfb783a_000b7c0a\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss 0xc(%edx), %xmm0\n"
        "jne .Lfb783a_000b7c07\n"
        "jp .Lfb783a_000b7c07\n"
        "ucomiss 8(%edx, %eax, 8), %xmm0\n"
        "jne .Lfb783a_000b7c07\n"
        "jp .Lfb783a_000b7c07\n"
        "ucomiss 0xc(%edx, %eax, 8), %xmm1\n"
        "jne .Lfb783a_000b7c07\n"
        "jp .Lfb783a_000b7c07\n"
        /* } scope */
        /* } scope */
        ".Lfb783a_000b7bb7:\n"
        "movl 8(%ebp), %eax\n" /* line 1600 | name */
        "movl 0xc(%ebp), %edx\n" /* curve */
        "movl %eax, (%edx)\n"
        "movl $1, %eax\n"
        "jmp .Lfb783a_000b79c9\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfb783a_000b7bc9:\n"
        "calll Com_EndParseSession\n" /* line 1499 */
        "movl 0xc(%ebp), %eax\n" /* line 1500 | curve */
        "cvtss2sd 8(%eax, %esi, 8), %xmm0\n"
        ".Lfb783a_000b7bd7:\n"
        "movsd %xmm0, 8(%esp)\n" /* line 1512 */
        "leal -0x60(%ebp), %edx\n" /* fileName */
        "movl %edx, 4(%esp)\n"
        "movl $0x21efb8, (%esp)\n" /* "^1ERROR: sndcurve parse failure on file "%s": knot x-coord '" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 1597 */
        "jmp .Lfb783a_000b79c9\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfb783a_000b7bf7:\n"
        "calll Com_EndParseSession\n" /* line 1511 */
        "movl 0xc(%ebp), %eax\n" /* line 1512 | curve */
        "cvtss2sd 0xc(%eax, %esi, 8), %xmm0\n"
        "jmp .Lfb783a_000b7bd7\n"
        ".Lfb783a_000b7c07:\n"
        "movl 0xc(%ebp), %edx\n" /* curve */
        ".Lfb783a_000b7c0a:\n"
        "movl $0, 8(%edx)\n" /* line 1530 */
        "movl $0x3f800000, 0xc(%edx)\n" /* line 1531 */
        "movl $0x3f800000, 8(%edx, %eax, 8)\n" /* line 1532 */
        "movl $0, 0xc(%edx, %eax, 8)\n" /* line 1533 */
        "leal -0x60(%ebp), %eax\n" /* line 1534 | fileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x21f078, (%esp)\n" /* "^3WARNING^7: sndcurve parse on file "%s": the first point mu" */
        "calll Com_Printf\n"
        "jmp .Lfb783a_000b7bb7\n"
    );
}

/* line 1612 */
__attribute__((naked))
int Com_LoadSoundAliasSounds(SoundFileInfo *soundFileInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1612 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* soundFileInfo */
        /* { scope 1 */
        "movl (%edi), %edx\n" /* line 1626 | soundFileInfo */
        "testl %edx, %edx\n"
        "jle .Lfb7c40_000b7cf6\n"
        "xorl %esi, %esi\n" /* soundIndex */
        "movl $0, -0x1c(%ebp)\n" /* numMissing */
        "jmp .Lfb7c40_000b7c8b\n"
        ".Lfb7c40_000b7c61:\n"
        "movl (%ebx), %eax\n" /* line 1648 | soundFile */
        "movl %eax, 4(%esp)\n"
        "movl $0x219968, (%esp)\n" /* "sound/%s" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll FS_TouchFile\n"
        "movb %al, 8(%ebx)\n" /* soundFile */
        "cmpb $0, 8(%ebx)\n" /* line 1651 | soundFile */
        "je .Lfb7c40_000b7cbd\n"
        ".Lfb7c40_000b7c84:\n"
        "addl $1, %esi\n" /* line 1626 | soundIndex */
        "cmpl (%edi), %esi\n" /* soundFileInfo, soundIndex */
        "jge .Lfb7c40_000b7cd6\n"
        ".Lfb7c40_000b7c8b:\n"
        "movl %esi, %ebx\n" /* line 1628 | soundIndex, soundFile */
        "shll $4, %ebx\n" /* soundFile */
        "addl 4(%edi), %ebx\n" /* soundFileInfo, soundFile */
        "cmpl $1, 0xc(%ebx)\n" /* line 1630 | soundFile */
        "je .Lfb7c40_000b7ce1\n"
        "movl 0x195ee94, %eax\n" /* line 1647 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfb7c40_000b7c61\n"
        "movl 0x195ee90, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfb7c40_000b7c61\n"
        "movb $1, 8(%ebx)\n" /* line 1650 | soundFile */
        "cmpb $0, 8(%ebx)\n" /* line 1651 | soundFile */
        "jne .Lfb7c40_000b7c84\n"
        ".Lfb7c40_000b7cbd:\n"
        "movl (%ebx), %eax\n" /* line 1652 | soundFile */
        "movl %eax, 4(%esp)\n"
        "movl $0x21f118, (%esp)\n" /* "^1ERROR: Streamed sound file '%s' not found
" */
        "calll Com_Printf\n"
        "addl $1, %esi\n" /* line 1626 | soundIndex */
        "cmpl (%edi), %esi\n" /* soundFileInfo, soundIndex */
        "jl .Lfb7c40_000b7c8b\n"
        /* } scope */
        ".Lfb7c40_000b7cd6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1676 | numMissing */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb7c40_000b7ce1:\n"
        "movl %ebx, (%esp)\n" /* line 1632 | soundFile */
        "calll SND_LoadSoundFile\n"
        "movl 4(%ebx), %eax\n" /* line 1633 | soundFile */
        "testl %eax, %eax\n"
        "jne .Lfb7c40_000b7c84\n"
        "addl $1, -0x1c(%ebp)\n" /* line 1634 | numMissing */
        "jmp .Lfb7c40_000b7c84\n"
        ".Lfb7c40_000b7cf6:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 1626 | numMissing */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 1676 | numMissing */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1687 */
__attribute__((naked))
void Com_InitDefaultSoundAliasVolumeFalloffCurve(SndCurve *sndCurve)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1687 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* sndCurve */
        "movl $0x2157b8, (%eax)\n" /* line 1689 */
        "xorl %ecx, %ecx\n" /* line 1690 */
        "movl %ecx, 8(%eax)\n"
        "movl $0x3f800000, %edx\n" /* line 1691 */
        "movl %edx, 0xc(%eax)\n"
        "movl %edx, 0x10(%eax)\n" /* line 1692 */
        "movl %ecx, 0x14(%eax)\n" /* line 1693 */
        "movl $2, 4(%eax)\n" /* line 1694 */
        "popl %ebp\n" /* line 1695 */
        "retl\n"
    );
}

/* line 2145 */
static __attribute__((naked))
const char * Com_GetSubtitleStringEdReference(const char *pszSubtitle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2145 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "leal -0x1c(%ebp), %eax\n" /* line 2152 | file */
        "movl %eax, 4(%esp)\n"
        "movl $0x21f148, (%esp)\n" /* "soundaliases/subtitle.st" */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n"
        "js .Lfb7d30_000b7e95\n"
        "movl $0x21f148, (%esp)\n" /* line 2158 */
        "calll Com_BeginParseSession\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2160 | file */
        "movl %eax, -0x20(%ebp)\n" /* ptr */
        "leal -0x20(%ebp), %eax\n" /* line 2163 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl -0x20(%ebp), %ebx\n" /* line 2164 | ptr */
        "testl %ebx, %ebx\n"
        "je .Lfb7d30_000b7e3d\n"
        ".Lfb7d30_000b7d7c:\n"
        "movl $0x218158, %edi\n" /* line 2167 */
        "movl $0xa, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lfb7d30_000b7d9c\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfb7d30_000b7d9c:\n"
        "testl %edx, %edx\n"
        "jne .Lfb7d30_000b7e1c\n"
        "leal -0x20(%ebp), %eax\n" /* line 2169 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, 4(%esp)\n" /* line 2170 */
        "movl $szReference, (%esp)\n"
        "calll strcpy\n"
        "leal -0x20(%ebp), %eax\n" /* line 2171 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        ".Lfb7d30_000b7dc6:\n"
        "leal -0x20(%ebp), %eax\n" /* line 2175 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %ebx\n"
        "movl -0x20(%ebp), %ecx\n" /* line 2176 | ptr */
        "testl %ecx, %ecx\n"
        "je .Lfb7d30_000b7e57\n"
        ".Lfb7d30_000b7dda:\n"
        "movl $0xd, %ecx\n" /* line 2178 */
        "cld\n"
        "movl %ebx, %esi\n"
        "movl $0x21f1c0, %edi\n" /* "LANG_ENGLISH" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lfb7d30_000b7dfa\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfb7d30_000b7dfa:\n"
        "testl %eax, %eax\n"
        "jne .Lfb7d30_000b7dc6\n"
        "leal -0x20(%ebp), %eax\n" /* line 2181 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, 4(%esp)\n" /* line 2182 */
        "movl 8(%ebp), %eax\n" /* pszSubtitle */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfb7d30_000b7e78\n"
        ".Lfb7d30_000b7e1c:\n"
        "leal -0x20(%ebp), %eax\n" /* line 2190 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "leal -0x20(%ebp), %eax\n" /* line 2163 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl -0x20(%ebp), %ebx\n" /* line 2164 | ptr */
        "testl %ebx, %ebx\n"
        "jne .Lfb7d30_000b7d7c\n"
        ".Lfb7d30_000b7e3d:\n"
        "calll Com_EndParseSession\n" /* line 2193 */
        "movl -0x1c(%ebp), %eax\n" /* line 2194 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfb7d30_000b7e4f:\n"
        "addl $0x2c, %esp\n" /* line 2197 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb7d30_000b7e57:\n"
        "movl $0x21f148, 8(%esp)\n" /* line 2177 */
        "movl $0x21f19c, 4(%esp)\n" /* "StringEd file %s has bad syntax" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfb7d30_000b7dda\n"
        ".Lfb7d30_000b7e78:\n"
        "calll Com_EndParseSession\n" /* line 2184 */
        "movl -0x1c(%ebp), %eax\n" /* line 2185 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl $szReference, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2197 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb7d30_000b7e95:\n"
        "movl $0x21f148, 4(%esp)\n" /* line 2154 */
        "movl $0x21f164, (%esp)\n" /* "WARNING: Could not read local copy of StringEd file %s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lfb7d30_000b7e4f\n"
    );
}

/* line 2205 */
static __attribute__((naked))
void Com_WriteStringEdReferenceToFile(const char *pszReference)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2205 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edx, %esi\n" /* pszSubtitle */
        "movl %ecx, %ebx\n" /* hOutFile */
        "movl %ecx, 8(%esp)\n" /* line 2210 */
        "movl $0x14, 4(%esp)\n"
        "movl $0x21f1d0, (%esp)\n" /* "REFERENCE           " */
        "calll FS_Write\n"
        "movl %ebx, 8(%esp)\n" /* line 2211 | hOutFile */
        "movl -0x1c(%ebp), %edx\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FS_Write\n"
        "movl %ebx, 8(%esp)\n" /* line 2213 | hOutFile */
        "movl $0x17, 4(%esp)\n"
        "movl $0x21f1e8, (%esp)\n" /* "
LANG_ENGLISH        "" */
        "calll FS_Write\n"
        "movl %ebx, 8(%esp)\n" /* line 2214 | hOutFile */
        "movl %esi, %edi\n" /* pszSubtitle */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pszSubtitle */
        "calll FS_Write\n"
        "movl %ebx, 8(%esp)\n" /* line 2216 | hOutFile */
        "movl $5, 4(%esp)\n"
        "movl $0x21f200, (%esp)\n" /* ""

" */
        "calll FS_Write\n"
        "addl $0x2c, %esp\n" /* line 2217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1135 */
static __attribute__((naked))
int FileNameTypeCompare(snd_alias_build_t *frontList, snd_alias_build_t *backList)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1135 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* frontList */
        "movl 0xc(%ebp), %ebx\n" /* backList */
        /* { scope 1 */
        "leal 0xc8(%ebx), %eax\n" /* line 1140 | backList */
        "movl %eax, 4(%esp)\n"
        "leal 0xc8(%esi), %eax\n" /* frontList */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n" /* line 1143 */
        "jne .Lfb7f54_000b7f8c\n"
        "movl 0x12c(%esi), %eax\n" /* line 1145 | frontList */
        "subl 0x12c(%ebx), %eax\n" /* line 1147 | backList */
        "je .Lfb7f54_000b7f93\n"
        /* } scope */
        ".Lfb7f54_000b7f8c:\n"
        "addl $0x10, %esp\n" /* line 1154 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb7f54_000b7f93:\n"
        "leal 0x40(%ebx), %eax\n" /* line 1015 */
        "movl %eax, 0xc(%ebp)\n" /* backList */
        "leal 0x40(%esi), %eax\n"
        "movl %eax, 8(%ebp)\n" /* frontList */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1154 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp I_stricmp\n" /* line 1015 */
    );
}

/* line 513 */
static __attribute__((naked))
void Com_LoadSoundAliasField(const char *loadspecCurGame, const char *sourceFile, const char *token, snd_alias_members_t field, char *bFieldSet, snd_alias_build_t *alias)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 513 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40ac, %esp\n"
        "movl %eax, %ebx\n" /* loadspec */
        "movl %edx, -0x4074(%ebp)\n" /* field */
        "movl %ecx, -0x4078(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* field */
        /* { scope 1: list, loadlist, len */
        "testl %edx, %edx\n" /* line 520 */
        "je .Lfb7faa_000b8076\n"
        "movl 0x10(%ebp), %ecx\n" /* line 523 | bFieldSet */
        "leal (%edx, %ecx), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lfb7faa_000b8081\n"
        "movb $1, (%eax)\n" /* line 529 */
        "cmpl $0x17, %edx\n" /* line 534 */
        "ja .Lfb7faa_000b8076\n"
        "jmpl *0x2f1d60(, %edx, 4)\n"
        "cld\n" /* line 537 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x3e, %ecx\n"
        "ja .Lfb7faa_000b881e\n"
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 291 | token, _c */
        "movzbl (%edx), %eax\n"
        "cmpb $0x1f, %al\n"
        "jle .Lfb7faa_000b8810\n"
        "movsbl %al, %edx\n" /* _c */
        /* { scope 3 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "jne .Lfb7faa_000b8b60\n"
        "movl __DefaultRuneLocale, %eax\n"
        "testl $0x500, 0x34(%eax, %edx, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lfb7faa_000b803c:\n"
        "testl %eax, %eax\n" /* line 291 */
        "jne .Lfb7faa_000b8a2f\n"
        "movl 8(%ebp), %ecx\n" /* token */
        "cmpb $0x5f, (%ecx)\n"
        "je .Lfb7faa_000b8a2f\n"
        "movl %ecx, %edi\n"
        /* } scope */
        ".Lfb7faa_000b8052:\n"
        "movl %edi, 8(%esp)\n" /* line 545 */
        "movl -0x4078(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21f29c, (%esp)\n" /* "^1ERROR: Sound alias file %s: Alias name '%s' is invalid
" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %edx\n" /* line 546 | alias */
        "movb $1, 0x149(%edx)\n"
        /* } scope */
        ".Lfb7faa_000b8076:\n"
        "addl $0x40ac, %esp\n" /* line 668 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: list, loadlist, len */
        ".Lfb7faa_000b8081:\n"
        "movl g_pszSndAliasKeyNames(, %edx, 4), %eax\n" /* line 525 */
        "movl %eax, 8(%esp)\n"
        "movl -0x4078(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21f208, (%esp)\n" /* "^1ERROR: Sound alias file %s: Duplicate entries for the '%s'" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %eax\n" /* line 526 | alias */
        "movb $1, 0x149(%eax)\n"
        /* } scope */
        "addl $0x40ac, %esp\n" /* line 668 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: list, loadlist, len */
        "movl 8(%ebp), %eax\n" /* line 663 | token */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x4038(%ebp)\n"
        "cvtsd2ss -0x4038(%ebp), %xmm0\n"
        "movss 0x2ed5d0, %xmm3\n" /* line 45 | 1.0f */
        "movaps %xmm0, %xmm2\n"
        "subss %xmm3, %xmm2\n"
        "pxor %xmm1, %xmm1\n"
        "movaps %xmm3, %xmm4\n"
        "cmpnltss %xmm1, %xmm2\n"
        "andps %xmm2, %xmm4\n"
        "andnps %xmm0, %xmm2\n"
        "orps %xmm4, %xmm2\n"
        "movaps %xmm1, %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "movaps %xmm2, %xmm4\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movl 0x14(%ebp), %eax\n" /* line 663 | alias */
        "movss %xmm0, 0x13c(%eax)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl $0x21f6b0, 4(%esp)\n" /* line 500 */
        "movl 8(%ebp), %eax\n" /* token */
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lfb7faa_000b8140\n"
        "movl 0x14(%ebp), %edx\n" /* line 501 | alias */
        "movb $1, 0x147(%edx)\n"
        ".Lfb7faa_000b8140:\n"
        "movl $0x21f6c0, 4(%esp)\n" /* line 503 */
        "movl 8(%ebp), %ecx\n" /* token */
        "movl %ecx, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lfb7faa_000b8076\n"
        "movl 0x14(%ebp), %edi\n" /* line 504 | alias */
        "movb $1, 0x148(%edi)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl 8(%ebp), %ecx\n" /* line 652 | token */
        "movl %ecx, (%esp)\n"
        "calll atoi\n"
        "movl 0x14(%ebp), %edi\n" /* alias */
        "movl %eax, 0x140(%edi)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl -0x4078(%ebp), %edi\n" /* line 649 */
        "movl %edi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* token */
        "movl %eax, (%esp)\n"
        "calll Com_RegisterSoundAliasVolumeFalloffCurve\n"
        "movl 0x14(%ebp), %edx\n" /* alias */
        "movl %eax, 0x130(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "cld\n" /* line 552 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x3e, %ecx\n"
        "ja .Lfb7faa_000b8852\n"
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 291 | token */
        "movzbl (%ecx), %eax\n"
        "cmpb $0x1f, %al\n"
        "jle .Lfb7faa_000b8817\n"
        "movsbl %al, %edx\n" /* _c */
        /* { scope 3 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "jne .Lfb7faa_000b8b3b\n"
        "movl __DefaultRuneLocale, %eax\n"
        "testl $0x500, 0x34(%eax, %edx, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lfb7faa_000b81f1:\n"
        "testl %eax, %eax\n" /* line 291 */
        "jne .Lfb7faa_000b89b2\n"
        "movl 8(%ebp), %edi\n" /* token */
        "cmpb $0x5f, (%edi)\n"
        "je .Lfb7faa_000b89b2\n"
        "movl %edi, %eax\n"
        /* } scope */
        ".Lfb7faa_000b8207:\n"
        "movl %eax, 8(%esp)\n" /* line 560 */
        "movl -0x4078(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl $0x21f330, (%esp)\n" /* "^1ERROR: Sound alias file %s: Secondary Alias name '%s' is i" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %ecx\n" /* line 561 | alias */
        "movb $1, 0x149(%ecx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl $0x21f64c, 4(%esp)\n" /* line 472 */
        "movl 8(%ebp), %ecx\n" /* token */
        "movl %ecx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb7faa_000b88ef\n"
        "movl 0x14(%ebp), %edi\n" /* line 474 | alias */
        "movb $1, 0x145(%edi)\n"
        "movb $0, 0x146(%edi)\n" /* line 475 */
        "jmp .Lfb7faa_000b8076\n"
        /* { scope 2 */
        "cld\n" /* line 428 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* len */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x402c(%ebp)\n" /* len */
        "movb $0, -0x19(%ebp)\n" /* line 430 */
        "movl $0x4000, 8(%esp)\n" /* line 431 */
        "movl 8(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "leal -0x4018(%ebp), %edx\n" /* loadlist */
        "movl %edx, (%esp)\n"
        "calll strncpy\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 432 */
        "je .Lfb7faa_000b8729\n"
        "movl $0x3fff, 8(%esp)\n" /* line 434 */
        "movl -0x4078(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x21f610, (%esp)\n" /* "^1ERROR: Sound alias file %s: loadspec is > %i characters
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfb7faa_000b82c3:\n"
        "movl 0x14(%ebp), %edx\n" /* line 643 | alias */
        "movb %al, 0x14a(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl 8(%ebp), %ecx\n" /* line 640 | token */
        "movl %ecx, (%esp)\n"
        "calll atof\n"
        "fstpl -0x4040(%ebp)\n"
        "cvtsd2ss -0x4040(%ebp), %xmm0\n"
        "movl 0x14(%ebp), %edi\n" /* alias */
        "movss %xmm0, 0x138(%edi)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl $0x21f59c, 4(%esp)\n" /* line 392 */
        "movl 8(%ebp), %ecx\n" /* token */
        "movl %ecx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb7faa_000b8988\n"
        "movl 0x14(%ebp), %edx\n" /* line 394 | alias */
        "movb $1, 0x144(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl 8(%ebp), %edi\n" /* line 622 | token */
        "movl %edi, (%esp)\n"
        "calll atof\n"
        "fstpl -0x4058(%ebp)\n"
        "cvtsd2ss -0x4058(%ebp), %xmm0\n"
        "movl 0x14(%ebp), %eax\n" /* alias */
        "movss %xmm0, 0x11c(%eax)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl $0x21ec78, 4(%esp)\n" /* line 356 */
        "movl 8(%ebp), %edx\n" /* token */
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb7faa_000b88c2\n"
        "movl 0x14(%ebp), %ecx\n" /* line 358 | alias */
        "movl $2, 0x12c(%ecx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "xorl %esi, %esi\n" /* line 629 | i */
        "movl $g_pszChannelNames, %ebx\n" /* loadspec */
        /* { scope 2 */
        ".Lfb7faa_000b8381:\n"
        "movl (%ebx), %eax\n" /* line 323 | len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* token */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfb7faa_000b8802\n"
        "addl $1, %esi\n" /* line 321 | i */
        "addl $4, %ebx\n" /* len */
        "cmpl $0xb, %esi\n" /* i */
        "jne .Lfb7faa_000b8381\n"
        "xorw %si, %si\n" /* i */
        "xorl %ebx, %ebx\n" /* len */
        "movl $g_pszChannelNames, %edi\n"
        "jmp .Lfb7faa_000b83c9\n"
        ".Lfb7faa_000b83b1:\n"
        "cmpl $9, %esi\n" /* line 336 | i */
        "je .Lfb7faa_000b86a5\n"
        ".Lfb7faa_000b83ba:\n"
        "addl $1, %esi\n" /* line 331 | i */
        "addl $4, %edi\n"
        "cmpl $0xb, %esi\n" /* i */
        "je .Lfb7faa_000b86bf\n"
        ".Lfb7faa_000b83c9:\n"
        "movl (%edi), %eax\n" /* line 333 */
        "movl %eax, 8(%esp)\n"
        "movl $0x216058, 4(%esp)\n" /* "%s" */
        "leal -0x4018(%ebp), %eax\n" /* loadlist */
        "addl %ebx, %eax\n" /* len */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "addl %eax, %ebx\n" /* len */
        "cmpl $8, %esi\n" /* line 334 | i */
        "jg .Lfb7faa_000b83b1\n"
        "leal -0x4018(%ebp), %eax\n" /* line 335 | loadlist */
        "addl %ebx, %eax\n" /* len */
        "movw $0x202c, (%eax)\n"
        "movb $0, 2(%eax)\n"
        "addl $2, %ebx\n" /* len */
        "jmp .Lfb7faa_000b83ba\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 628 | token */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x4048(%ebp)\n"
        "cvtsd2ss -0x4048(%ebp), %xmm0\n"
        "movl 0x14(%ebp), %edx\n" /* alias */
        "movss %xmm0, 0x124(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl 8(%ebp), %eax\n" /* line 625 | token */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x4050(%ebp)\n"
        "cvtsd2ss -0x4050(%ebp), %xmm0\n"
        "movl 0x14(%ebp), %edx\n" /* alias */
        "movss %xmm0, 0x120(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl 8(%ebp), %ecx\n" /* line 594 | token */
        "movl %ecx, (%esp)\n"
        "calll atof\n"
        "fstpl -0x4070(%ebp)\n"
        "cvtsd2ss -0x4070(%ebp), %xmm0\n"
        "movl 0x14(%ebp), %edi\n" /* alias */
        "movss %xmm0, 0x10c(%edi)\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 595 | 0.0f */
        "jp .Lfb7faa_000b8485\n"
        "jb .Lfb7faa_000b8492\n"
        ".Lfb7faa_000b8485:\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lfb7faa_000b8ae2\n"
        ".Lfb7faa_000b8492:\n"
        "movl $0, 0x18(%esp)\n" /* line 597 */
        "movl $0x3ff00000, 0x1c(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl -0x4078(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21f414, (%esp)\n" /* "^1ERROR: Sound alias file %s: MinVolume '%f' is not within t" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %edx\n" /* line 598 | alias */
        "movb $1, 0x149(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl 8(%ebp), %edx\n" /* line 579 | token */
        "movzbl (%edx), %eax\n"
        "cmpb $0, %al\n"
        "je .Lfb7faa_000b8886\n"
        "jl .Lfb7faa_000b8c03\n" /* line 581 */
        "xorl %eax, %eax\n"
        ".Lfb7faa_000b84f7:\n"
        "addl $1, %eax\n" /* line 579 */
        "movl %eax, %ebx\n" /* loadspec */
        "movl 8(%ebp), %ecx\n" /* token */
        "movzbl (%ecx, %eax), %edx\n"
        "cmpb $0, %dl\n"
        "je .Lfb7faa_000b8ad8\n"
        "jge .Lfb7faa_000b84f7\n" /* line 581 */
        ".Lfb7faa_000b850e:\n"
        "movzbl %dl, %eax\n" /* line 583 */
        "movl %eax, 0x10(%esp)\n"
        "movsbl %dl, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %edi\n" /* token */
        "movl %edi, 8(%esp)\n"
        "movl -0x4078(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21f3c0, (%esp)\n" /* "^1ERROR: Sound alias file %s: Subtitle '%s' has invalid char" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %edx\n" /* line 584 | alias */
        "movb $1, 0x149(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "cld\n" /* line 570 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x3e, %ecx\n"
        "ja .Lfb7faa_000b86f5\n"
        "movl 8(%ebp), %ecx\n" /* line 576 | token */
        "movl %ecx, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* alias */
        "addl $0xc8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl 8(%ebp), %edi\n" /* line 567 | token */
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl 0x14(%ebp), %edx\n" /* alias */
        "movl %eax, 0xc4(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        "xorl %esi, %esi\n" /* line 610 | i */
        "movl $0x1150528, %ebx\n" /* loadspec */
        "xorl %edi, %edi\n"
        "jmp .Lfb7faa_000b85b5\n"
        /* { scope 2 */
        ".Lfb7faa_000b85a3:\n"
        "addl $1, %esi\n" /* line 226 | i */
        "addl $0x44, %edi\n"
        "addl $0x44, %ebx\n"
        "cmpl $0x20, %esi\n" /* i */
        "je .Lfb7faa_000b87d6\n"
        ".Lfb7faa_000b85b5:\n"
        "movl %ebx, 4(%esp)\n" /* line 228 */
        "movl 8(%ebp), %eax\n" /* token */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb7faa_000b85a3\n"
        "movl 0x1150568(%edi), %eax\n" /* line 229 */
        /* } scope */
        ".Lfb7faa_000b85ce:\n"
        "movl 0x14(%ebp), %edi\n" /* line 614 | alias */
        "movl %eax, 0x114(%edi)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl 8(%ebp), %eax\n" /* line 605 | token */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x4068(%ebp)\n"
        "cvtsd2ss -0x4068(%ebp), %xmm0\n"
        "movl 0x14(%ebp), %edx\n" /* alias */
        "movss %xmm0, 0x110(%edx)\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 606 | 0.0f */
        "jp .Lfb7faa_000b860b\n"
        "jb .Lfb7faa_000b8618\n"
        ".Lfb7faa_000b860b:\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8618:\n"
        "movl $0, 0x18(%esp)\n" /* line 608 */
        "movl $0x3ff00000, 0x1c(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl -0x4078(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x21f468, (%esp)\n" /* "^1ERROR: Sound alias file %s: MaxVolume '%f' is not within t" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %edi\n" /* line 609 | alias */
        "movb $1, 0x149(%edi)\n"
        "jmp .Lfb7faa_000b8076\n"
        "movl 8(%ebp), %eax\n" /* line 617 | token */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x4060(%ebp)\n"
        "cvtsd2ss -0x4060(%ebp), %xmm0\n"
        "movl 0x14(%ebp), %edx\n" /* alias */
        "movss %xmm0, 0x118(%edx)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 618 | bFieldSet */
        "cmpb $0, 9(%ecx)\n"
        "jne .Lfb7faa_000b8076\n"
        "movss %xmm0, 0x11c(%edx)\n" /* line 619 */
        "jmp .Lfb7faa_000b8076\n"
        /* { scope 2 */
        ".Lfb7faa_000b86a5:\n"
        "leal -0x4018(%ebp), %eax\n" /* line 337 | loadlist */
        "addl %ebx, %eax\n" /* len */
        "movl $0x20726f20, (%eax)\n"
        "movb $0, 4(%eax)\n"
        "addl $4, %ebx\n" /* len */
        "jmp .Lfb7faa_000b83ba\n"
        ".Lfb7faa_000b86bf:\n"
        "leal -0x4018(%ebp), %edx\n" /* line 340 | loadlist */
        "movl %edx, 0xc(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* token */
        "movl %ecx, 8(%esp)\n"
        "movl -0x4078(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21f4f4, (%esp)\n" /* "^1ERROR: Sound alias file %s: Unknown sound channel '%s'; sh" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %eax\n" /* line 341 | alias */
        "movb $1, 0x149(%eax)\n"
        "jmp .Lfb7faa_000b8076\n"
        /* } scope */
        ".Lfb7faa_000b86f5:\n"
        "movl $0x3f, 0xc(%esp)\n" /* line 572 */
        "movl 8(%ebp), %ecx\n" /* token */
        "movl %ecx, 8(%esp)\n"
        "movl -0x4078(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21f374, (%esp)\n" /* "^1ERROR: Sound alias file %s: Sound file '%s' is longer than" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %eax\n" /* line 573 | alias */
        "movb $1, 0x149(%eax)\n"
        "jmp .Lfb7faa_000b8076\n"
        /* { scope 2 */
        ".Lfb7faa_000b8729:\n"
        "leal -0x4018(%ebp), %edi\n" /* line 437 | loadlist */
        "movl %edi, (%esp)\n"
        "calll strlwr\n"
        "cmpb $0x21, -0x4018(%ebp)\n" /* line 440 | loadlist */
        "je .Lfb7faa_000b8bcf\n"
        ".Lfb7faa_000b8744:\n"
        "movb $1, -0x4019(%ebp)\n"
        ".Lfb7faa_000b874b:\n"
        "leal -0x4018(%ebp), %eax\n" /* loadlist */
        "movl %eax, -0x408c(%ebp)\n" /* list */
        "movl %eax, %edx\n"
        "jmp .Lfb7faa_000b8786\n"
        ".Lfb7faa_000b875b:\n"
        "leal -0x4018(%ebp), %ecx\n" /* line 453 | loadlist */
        "cmpl %eax, %ecx\n"
        "je .Lfb7faa_000b876b\n"
        "cmpb $0x21, -1(%eax)\n"
        "jg .Lfb7faa_000b877b\n"
        ".Lfb7faa_000b876b:\n"
        "movl -0x402c(%ebp), %edi\n" /* len */
        "cmpb $0x20, (%eax, %edi)\n"
        "jle .Lfb7faa_000b8acc\n"
        ".Lfb7faa_000b877b:\n"
        "addl $1, %eax\n" /* line 456 */
        "movl %eax, -0x408c(%ebp)\n" /* list */
        "movl %eax, %edx\n"
        ".Lfb7faa_000b8786:\n"
        "movl %ebx, 4(%esp)\n" /* line 444 | len */
        "movl %edx, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n" /* line 445 */
        "jne .Lfb7faa_000b875b\n"
        "movl $0x216cd8, -0x407c(%ebp)\n" /* line 448 */
        "movl $5, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* len, i */
        "movl $0x216cd8, %edi\n" /* "menu" */
        "repe cmpsb %es:(%edi), (%esi)\n" /* i */
        "movl $0, %edx\n"
        "je .Lfb7faa_000b87c0\n"
        "movzbl -1(%esi), %edx\n" /* i */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfb7faa_000b87c0:\n"
        "testl %edx, %edx\n"
        "jne .Lfb7faa_000b8aac\n"
        ".Lfb7faa_000b87c8:\n"
        "movzbl -0x4019(%ebp), %eax\n"
        "xorb $1, %al\n"
        "jmp .Lfb7faa_000b82c3\n"
        /* } scope */
        /* { scope 2 */
        ".Lfb7faa_000b87d6:\n"
        "movl 8(%ebp), %edx\n" /* line 232 | token */
        "movl %edx, 0xc(%esp)\n"
        "movl -0x4078(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x21f4bc, 4(%esp)\n" /* "Sound alias file %s: Volume Mod Group '%s' not found." */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "xorl %eax, %eax\n"
        "jmp .Lfb7faa_000b85ce\n"
        /* } scope */
        /* { scope 2 */
        ".Lfb7faa_000b8802:\n"
        "movl 0x14(%ebp), %edx\n" /* line 325 | alias */
        "movl %esi, 0x128(%edx)\n" /* i */
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8810:\n"
        "movl %edx, %edi\n"
        "jmp .Lfb7faa_000b8052\n"
        ".Lfb7faa_000b8817:\n"
        "movl %ecx, %eax\n"
        "jmp .Lfb7faa_000b8207\n"
        /* } scope */
        ".Lfb7faa_000b881e:\n"
        "movl $0x3f, 0xc(%esp)\n" /* line 539 */
        "movl 8(%ebp), %edx\n" /* token */
        "movl %edx, 8(%esp)\n"
        "movl -0x4078(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0x21f250, (%esp)\n" /* "^1ERROR: Sound alias file %s: Alias name '%s' is longer than" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %edi\n" /* line 540 | alias */
        "movb $1, 0x149(%edi)\n"
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8852:\n"
        "movl $0x3f, 0xc(%esp)\n" /* line 554 */
        "movl 8(%ebp), %edi\n" /* token */
        "movl %edi, 8(%esp)\n"
        "movl -0x4078(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21f2d8, (%esp)\n" /* "^1ERROR: Sound alias file %s: Secondary Alias name '%s' is l" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %edx\n" /* line 555 | alias */
        "movb $1, 0x149(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8886:\n"
        "movl $1, %edx\n" /* line 579 */
        "xorl %esi, %esi\n" /* i */
        "xorl %ebx, %ebx\n" /* loadspec */
        ".Lfb7faa_000b888f:\n"
        "movl %edx, (%esp)\n" /* line 589 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl 0x14(%ebp), %edi\n" /* alias */
        "movl %eax, 0xc0(%edi)\n"
        "movl %esi, 8(%esp)\n" /* line 590 | i */
        "movl 8(%ebp), %edx\n" /* token */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0xc0(%edi), %eax\n" /* line 591 */
        "movb $0, (%eax, %ebx)\n"
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b88c2:\n"
        "movl $0x21ec68, 4(%esp)\n" /* line 361 */
        "movl 8(%ebp), %ecx\n" /* token */
        "movl %ecx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb7faa_000b8ba6\n"
        "movl 0x14(%ebp), %edi\n" /* line 366 | alias */
        "movl $2, 0x12c(%edi)\n"
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b88ef:\n"
        "movl 0x14(%ebp), %edi\n" /* line 479 | alias */
        "movb $0, 0x145(%edi)\n"
        "movb $1, 0x146(%edi)\n" /* line 480 */
        "movl 8(%ebp), %eax\n" /* line 481 | token */
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x4028(%ebp)\n"
        "cvtsd2ss -0x4028(%ebp), %xmm0\n"
        "movss %xmm0, 0x134(%edi)\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 482 | 0.0f */
        "jp .Lfb7faa_000b892c\n"
        "jb .Lfb7faa_000b8939\n"
        ".Lfb7faa_000b892c:\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8939:\n"
        "movl $0, 0x18(%esp)\n" /* line 484 */
        "movl $0x3ff00000, 0x1c(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl -0x4078(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl $0x21f654, (%esp)\n" /* "^1ERROR: Sound alias file %s: SlavePercentage'%f' is not wit" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %ecx\n" /* line 485 | alias */
        "movb $1, 0x149(%ecx)\n"
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8988:\n"
        "movl $0x21f5a4, 4(%esp)\n" /* line 397 */
        "movl 8(%ebp), %edi\n" /* token */
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb7faa_000b8b7d\n"
        "movl 0x14(%ebp), %ecx\n" /* line 399 | alias */
        "movb $0, 0x144(%ecx)\n"
        "jmp .Lfb7faa_000b8076\n"
        /* { scope 2 */
        ".Lfb7faa_000b89b2:\n"
        "movl 8(%ebp), %edx\n" /* line 293 | token */
        "addl $1, %edx\n"
        "movl 8(%ebp), %edi\n" /* line 295 | token */
        "movzbl 1(%edi), %eax\n"
        "testb %al, %al\n"
        "je .Lfb7faa_000b8aff\n"
        "cmpb $0x1f, %al\n" /* line 297 */
        "jle .Lfb7faa_000b8b58\n"
        "movl %edx, %ebx\n" /* _c */
        "jmp .Lfb7faa_000b8a0a\n"
        /* { scope 3 */
        ".Lfb7faa_000b89d3:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "testl $0x500, 0x34(%eax, %edx, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lfb7faa_000b89e6:\n"
        "testl %eax, %eax\n" /* line 297 */
        "jne .Lfb7faa_000b89f3\n"
        "cmpb $0x5f, (%ebx)\n"
        "jne .Lfb7faa_000b8b58\n"
        ".Lfb7faa_000b89f3:\n"
        "movzbl 1(%ebx), %eax\n" /* line 295 */
        "testb %al, %al\n"
        "je .Lfb7faa_000b8aff\n"
        "addl $1, %ebx\n" /* line 291 */
        "cmpb $0x1f, %al\n" /* line 297 */
        "jle .Lfb7faa_000b8b58\n"
        ".Lfb7faa_000b8a0a:\n"
        "movsbl %al, %edx\n" /* _c */
        /* { scope 3 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lfb7faa_000b89d3\n"
        "movl $0x500, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lfb7faa_000b89e6\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfb7faa_000b8a2f:\n"
        "movl 8(%ebp), %edx\n" /* line 293 | token */
        "addl $1, %edx\n"
        "movl 8(%ebp), %ecx\n" /* line 295 | token */
        "movzbl 1(%ecx), %eax\n"
        "testb %al, %al\n"
        "je .Lfb7faa_000b8b19\n"
        "cmpb $0x1f, %al\n" /* line 297 */
        "jle .Lfb7faa_000b8b33\n"
        "movl %edx, %ebx\n" /* _c */
        "jmp .Lfb7faa_000b8a87\n"
        /* { scope 3 */
        ".Lfb7faa_000b8a50:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "testl $0x500, 0x34(%eax, %edx, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lfb7faa_000b8a63:\n"
        "testl %eax, %eax\n" /* line 297 */
        "jne .Lfb7faa_000b8a70\n"
        "cmpb $0x5f, (%ebx)\n"
        "jne .Lfb7faa_000b8b33\n"
        ".Lfb7faa_000b8a70:\n"
        "movzbl 1(%ebx), %eax\n" /* line 295 */
        "testb %al, %al\n"
        "je .Lfb7faa_000b8b19\n"
        "addl $1, %ebx\n" /* line 291 */
        "cmpb $0x1f, %al\n" /* line 297 */
        "jle .Lfb7faa_000b8b33\n"
        ".Lfb7faa_000b8a87:\n"
        "movsbl %al, %edx\n" /* _c */
        /* { scope 3 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lfb7faa_000b8a50\n"
        "movl $0x500, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lfb7faa_000b8a63\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfb7faa_000b8aac:\n"
        "movl -0x4074(%ebp), %eax\n" /* line 448 */
        "movl %eax, 4(%esp)\n"
        "movl -0x408c(%ebp), %edx\n" /* list */
        "movl %edx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb7faa_000b87c8\n"
        ".Lfb7faa_000b8acc:\n"
        "movzbl -0x4019(%ebp), %eax\n" /* line 453 */
        "jmp .Lfb7faa_000b82c3\n"
        /* } scope */
        ".Lfb7faa_000b8ad8:\n"
        "leal 1(%eax), %edx\n" /* line 579 */
        "movl %eax, %esi\n" /* i */
        "jmp .Lfb7faa_000b888f\n"
        ".Lfb7faa_000b8ae2:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 601 | bFieldSet */
        "cmpb $0, 6(%ecx)\n"
        "jne .Lfb7faa_000b8076\n"
        "movl 0x14(%ebp), %edi\n" /* line 602 | alias */
        "movss %xmm0, 0x110(%edi)\n"
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8aff:\n"
        "movl 8(%ebp), %eax\n" /* line 564 | token */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* alias */
        "subl $-0x80, %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8b19:\n"
        "movl 8(%ebp), %ecx\n" /* line 549 | token */
        "movl %ecx, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* alias */
        "addl $0x40, %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8b33:\n"
        "movl 8(%ebp), %edi\n" /* token */
        "jmp .Lfb7faa_000b8052\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfb7faa_000b8b3b:\n"
        "movl $0x500, 4(%esp)\n" /* line 220 */
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lfb7faa_000b81f1\n"
        ".Lfb7faa_000b8b58:\n"
        "movl 8(%ebp), %eax\n" /* token */
        "jmp .Lfb7faa_000b8207\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfb7faa_000b8b60:\n"
        "movl $0x500, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lfb7faa_000b803c\n"
        /* } scope */
        /* } scope */
        ".Lfb7faa_000b8b7d:\n"
        "movl %edi, 8(%esp)\n" /* line 403 */
        "movl -0x4078(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21f5b0, (%esp)\n" /* "^1ERROR: Sound alias file %s: Unknown sound looping type '%s" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %edx\n" /* line 404 | alias */
        "movb $1, 0x149(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
        ".Lfb7faa_000b8ba6:\n"
        "movl $0x21ec70, 4(%esp)\n" /* line 370 */
        "movl 8(%ebp), %edi\n" /* token */
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb7faa_000b8c0a\n"
        "movl 0x14(%ebp), %eax\n" /* line 372 | alias */
        "movl $1, 0x12c(%eax)\n"
        "jmp .Lfb7faa_000b8076\n"
        /* { scope 2 */
        ".Lfb7faa_000b8bcf:\n"
        "movl $0x216cd8, %edi\n" /* line 440 */
        "movl $5, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* len, i */
        "repe cmpsb %es:(%edi), (%esi)\n" /* i */
        "movl $0, %edx\n"
        "je .Lfb7faa_000b8bef\n"
        "movzbl -1(%esi), %edx\n" /* i */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfb7faa_000b8bef:\n"
        "testl %edx, %edx\n"
        "je .Lfb7faa_000b8744\n"
        "movb $0, -0x4019(%ebp)\n"
        "jmp .Lfb7faa_000b874b\n"
        ".Lfb7faa_000b8c03:\n"
        "movl %eax, %edx\n"
        "jmp .Lfb7faa_000b850e\n"
        /* } scope */
        ".Lfb7faa_000b8c0a:\n"
        "movl %edi, 8(%esp)\n" /* line 376 */
        "movl -0x4078(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21f53c, (%esp)\n" /* "^1ERROR: Sound alias file %s: Unknown sound type '%s'; shoul" */
        "calll Com_Printf\n"
        "movl 0x14(%ebp), %edx\n" /* line 377 | alias */
        "movb $1, 0x149(%edx)\n"
        "jmp .Lfb7faa_000b8076\n"
    );
}

/* line 2346 */
__attribute__((naked))
void Com_ProcessSoundAliasFileLocalization(const char *sourceFile, const char *loadspecCurGame, const char *stringEdFileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2346 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x700c, %esp\n"
        /* { scope 1: bHasName, bHasFile, file, ptr, ... */
        "movl 8(%ebp), %eax\n" /* line 2372 | sourceFile */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x21f6cc, 8(%esp)\n" /* "soundaliases/%s" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x540(%ebp), %edx\n" /* soundAliasFile */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x240(%ebp), %ebx\n" /* line 2374 | szFullPath, startmarker */
        "movl %ebx, 0xc(%esp)\n" /* startmarker */
        "leal -0x540(%ebp), %ecx\n" /* soundAliasFile */
        "movl %ecx, 8(%esp)\n"
        "movl 0x195ee98, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ecc8, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "movl %ebx, 4(%esp)\n" /* line 2375 | startmarker */
        "movl $0x21f6dc, (%esp)\n" /* "Processing sound alias file %s..
" */
        "calll Com_Printf\n"
        "movl $0x21f700, 4(%esp)\n" /* line 2378 */
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll FS_FileOpen\n"
        "testl %eax, %eax\n" /* line 2379 */
        "je .Lfb8c34_000b940c\n"
        "movl %eax, (%esp)\n" /* line 2384 */
        "calll FS_FileClose\n"
        "leal -0x20(%ebp), %eax\n" /* line 2386 | file */
        "movl %eax, 4(%esp)\n"
        "leal -0x540(%ebp), %edi\n" /* soundAliasFile */
        "movl %edi, (%esp)\n"
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n"
        "js .Lfb8c34_000b94fb\n"
        "movl $0x21f764, (%esp)\n" /* line 2392 */
        "calll FS_FOpenFileWrite\n"
        "movl %eax, -0x6fc4(%ebp)\n" /* hAliasOutFile */
        "testl %eax, %eax\n" /* line 2393 */
        "je .Lfb8c34_000b8e7c\n"
        "leal -0x540(%ebp), %edx\n" /* line 2399 | soundAliasFile */
        "movl %edx, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "movl $1, (%esp)\n" /* line 2400 */
        "calll Com_SetCSV\n"
        "movl -0x20(%ebp), %eax\n" /* line 2402 | file */
        "movl %eax, -0x28(%ebp)\n" /* ptr */
        "movl $0, -0x6fcc(%ebp)\n" /* iColCount */
        "movl $0, -0x6fc8(%ebp)\n" /* iNumSubtitlesLocalized */
        "movl %eax, %ecx\n"
        ".Lfb8c34_000b8d31:\n"
        "movl %ecx, -0x6fe4(%ebp)\n" /* line 2408 */
        "movl %ecx, %eax\n"
        "testl %ecx, %ecx\n"
        "je .Lfb8c34_000b8f02\n"
        "cmpb $0xd, (%ecx)\n" /* line 2410 */
        "je .Lfb8c34_000b8e9b\n"
        "movl -0x6fe4(%ebp), %edi\n"
        "cmpb $0xa, (%edi)\n" /* line 2415 */
        "je .Lfb8c34_000b8eb7\n"
        ".Lfb8c34_000b8d59:\n"
        "leal -0x28(%ebp), %ecx\n" /* line 2422 | ptr */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x6ff0(%ebp)\n" /* token */
        "movl -0x28(%ebp), %edx\n" /* line 2423 | ptr */
        "testl %edx, %edx\n"
        "je .Lfb8c34_000b8f02\n"
        ".Lfb8c34_000b8d75:\n"
        "movl $0x21f7b0, 4(%esp)\n" /* line 2426 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "movl -0x6ff0(%ebp), %edi\n" /* line 2430 | token */
        "movzbl (%edi), %eax\n"
        "testb %al, %al\n"
        "je .Lfb8c34_000b8fcf\n"
        "cmpb $0x23, %al\n"
        "je .Lfb8c34_000b8fcf\n"
        "movl -0x6fcc(%ebp), %eax\n" /* line 2443 | iColCount */
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b9034\n"
        "movl $0, -0x6fc0(%ebp)\n" /* bHasName */
        "movl $0, -0x6fbc(%ebp)\n" /* bHasFile */
        "movl $1, -0x6fac(%ebp)\n"
        ".Lfb8c34_000b8dca:\n"
        "movl -0x6fac(%ebp), %edx\n" /* line 2346 */
        "leal -0xb94(%ebp, %edx, 4), %eax\n"
        "leal -4(%eax), %ecx\n"
        "movl %ecx, -0x6fa8(%ebp)\n"
        /* { scope 2 */
        "movl $0, -4(%eax)\n" /* line 2451 */
        "movl $1, %esi\n" /* i */
        "movl $g_pszSndAliasKeyNames, %ebx\n" /* startmarker */
        "jmp .Lfb8c34_000b8dfe\n"
        ".Lfb8c34_000b8df3:\n"
        "addl $1, %esi\n" /* line 2452 | i */
        "addl $4, %ebx\n" /* startmarker */
        "cmpl $0x18, %esi\n" /* i */
        "je .Lfb8c34_000b8e31\n"
        ".Lfb8c34_000b8dfe:\n"
        "movl -0x6ff0(%ebp), %edi\n" /* line 2454 | token */
        "movl %edi, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* startmarker */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b8df3\n"
        "movl -0x6fa8(%ebp), %eax\n" /* line 2456 */
        "movl %esi, (%eax)\n" /* i */
        "cmpl $1, %esi\n" /* line 2457 | i */
        "je .Lfb8c34_000b9016\n"
        "cmpl $3, %esi\n" /* line 2459 | i */
        "je .Lfb8c34_000b9025\n"
        ".Lfb8c34_000b8e31:\n"
        "movl -0x6fac(%ebp), %edx\n" /* line 2452 */
        "movl %edx, -0x6fcc(%ebp)\n" /* iColCount */
        "cmpl $0x100, %edx\n" /* line 2465 */
        "je .Lfb8c34_000b8fa0\n"
        "movl -0x28(%ebp), %eax\n" /* line 2467 | ptr */
        "testl %eax, %eax\n"
        "je .Lfb8c34_000b8fa0\n"
        "addl $1, %edx\n"
        "movl %edx, -0x6fac(%ebp)\n"
        "cmpb $0xa, (%eax)\n"
        "je .Lfb8c34_000b8fa0\n"
        "leal -0x28(%ebp), %ecx\n" /* line 2469 | ptr */
        "movl %ecx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, -0x6ff0(%ebp)\n" /* token */
        "jmp .Lfb8c34_000b8dca\n"
        /* } scope */
        ".Lfb8c34_000b8e7c:\n"
        "movl $0x21f764, 4(%esp)\n" /* line 2395 */
        "movl $0x21f77c, (%esp)\n" /* "WARNING: Could not open output file %s for writing
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x700c, %esp\n" /* line 2611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bHasName, bHasFile, file, ptr, ... */
        ".Lfb8c34_000b8e9b:\n"
        "addl $1, %eax\n" /* line 2413 */
        "movl %eax, -0x28(%ebp)\n" /* ptr */
        "cmpb $0xd, (%eax)\n" /* line 2412 */
        "je .Lfb8c34_000b8e9b\n"
        "movl %eax, -0x6fe4(%ebp)\n"
        "movl %eax, %edi\n"
        "cmpb $0xa, (%edi)\n" /* line 2415 */
        "jne .Lfb8c34_000b8d59\n"
        ".Lfb8c34_000b8eb7:\n"
        "movl %edi, %eax\n" /* line 2417 */
        "addl $1, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* ptr */
        "movl -0x6fc4(%ebp), %eax\n" /* line 2418 | hAliasOutFile */
        "movl %eax, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl $0x218068, (%esp)\n" /* "
" */
        "calll FS_Write\n"
        "movl -0x28(%ebp), %edx\n" /* ptr */
        "movl %edx, -0x6fe4(%ebp)\n"
        "leal -0x28(%ebp), %ecx\n" /* line 2422 | ptr */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x6ff0(%ebp)\n" /* token */
        "movl -0x28(%ebp), %edx\n" /* line 2423 | ptr */
        "testl %edx, %edx\n"
        "jne .Lfb8c34_000b8d75\n"
        ".Lfb8c34_000b8f02:\n"
        "calll Com_EndParseSession\n" /* line 2595 */
        "movl -0x6fc4(%ebp), %edi\n" /* line 2597 | hAliasOutFile */
        "movl %edi, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0x340(%ebp), %edi\n" /* line 2600 | szFromFile */
        "movl %edi, 0xc(%esp)\n"
        "movl $0x21f764, 8(%esp)\n" /* "soundaliases/temp.csv" */
        "movl 0x195ee98, %ebx\n" /* startmarker */
        "movl %ebx, 4(%esp)\n" /* startmarker */
        "movl 0x195ecc8, %esi\n" /* i */
        "movl (%esi), %eax\n" /* i */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "leal -0x440(%ebp), %eax\n" /* line 2601 | szToFile */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x540(%ebp), %edx\n" /* soundAliasFile */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* startmarker */
        "movl (%esi), %eax\n" /* i */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "movl -0x6fc8(%ebp), %esi\n" /* line 2602 | iNumSubtitlesLocalized, i */
        "testl %esi, %esi\n" /* i */
        "jne .Lfb8c34_000b9516\n"
        ".Lfb8c34_000b8f77:\n"
        "movl %edi, (%esp)\n" /* line 2604 */
        "calll FS_Remove\n"
        "movl -0x6fc8(%ebp), %edi\n" /* line 2606 | iNumSubtitlesLocalized */
        "movl %edi, 4(%esp)\n"
        "movl $0x21f890, (%esp)\n" /* "Localized %i sound alias subtitles
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x700c, %esp\n" /* line 2611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bHasName, bHasFile, file, ptr, ... */
        /* { scope 2 */
        ".Lfb8c34_000b8fa0:\n"
        "movl -0x6fc0(%ebp), %eax\n" /* line 2472 | bHasName */
        "testl %eax, %eax\n"
        "je .Lfb8c34_000b8fb4\n"
        "movl -0x6fbc(%ebp), %edi\n" /* bHasFile */
        "testl %edi, %edi\n"
        "jne .Lfb8c34_000b8fcf\n"
        ".Lfb8c34_000b8fb4:\n"
        "movl 8(%ebp), %edi\n" /* line 2473 | sourceFile */
        "movl %edi, 8(%esp)\n"
        "movl $0x21f7c0, 4(%esp)\n" /* "Sound alias file %s: missing 'name' and/or 'file' columns
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lfb8c34_000b8fcf:\n"
        "leal -0x28(%ebp), %eax\n" /* line 2476 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "movl -0x6fe4(%ebp), %edx\n" /* line 2477 */
        "cmpb $0xa, (%edx)\n"
        "je .Lfb8c34_000b93e9\n"
        ".Lfb8c34_000b8fe9:\n"
        "movl -0x6fc4(%ebp), %edi\n" /* line 2480 | hAliasOutFile */
        "movl %edi, 8(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* ptr */
        "subl -0x6fe4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x6fe4(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "movl -0x28(%ebp), %ecx\n" /* ptr */
        "jmp .Lfb8c34_000b8d31\n"
        ".Lfb8c34_000b9016:\n"
        "movl $1, -0x6fc0(%ebp)\n" /* line 2457 | bHasName */
        "jmp .Lfb8c34_000b8e31\n"
        ".Lfb8c34_000b9025:\n"
        "movl $1, -0x6fbc(%ebp)\n" /* line 2459 | bHasFile */
        "jmp .Lfb8c34_000b8e31\n"
        /* } scope */
        ".Lfb8c34_000b9034:\n"
        "cld\n" /* line 2486 */
        "movl $6, %ecx\n"
        "leal -0x40(%ebp), %edi\n" /* bFieldSet */
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl 8(%ebp), %eax\n" /* line 246 | sourceFile */
        "movl %eax, 4(%esp)\n"
        "leal -0x794(%ebp), %edx\n" /* alias */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "movb $0, -0x754(%ebp)\n" /* line 248 */
        "movb $0, -0x714(%ebp)\n" /* line 249 */
        "movl $0, -0x6d0(%ebp)\n" /* line 250 */
        "movb $0, -0x6cc(%ebp)\n" /* line 251 */
        "movl $0, -0x6d4(%ebp)\n" /* line 252 */
        "movl $0x3f800000, -0x688(%ebp)\n" /* line 253 */
        "movl $0x3f800000, -0x684(%ebp)\n" /* line 254 */
        "movl $0x3f800000, -0x680(%ebp)\n" /* line 255 */
        "movl $0x3f800000, -0x67c(%ebp)\n" /* line 256 */
        "movl $0x3f800000, -0x678(%ebp)\n" /* line 257 */
        "movl $0x42f00000, -0x674(%ebp)\n" /* line 258 */
        "xorl %eax, %eax\n" /* line 259 */
        "movl %eax, -0x670(%ebp)\n"
        "movl $0, -0x66c(%ebp)\n" /* line 260 */
        "movl $1, -0x668(%ebp)\n" /* line 261 */
        "movb $0, -0x650(%ebp)\n" /* line 262 */
        "movl $0x3f800000, -0x65c(%ebp)\n" /* line 263 */
        "movl %eax, -0x658(%ebp)\n" /* line 264 */
        "movb $0, -0x64b(%ebp)\n" /* line 265 */
        "movb $0, -0x64a(%ebp)\n" /* line 266 */
        "movb $0, -0x64f(%ebp)\n" /* line 267 */
        "movb $0, -0x64e(%ebp)\n" /* line 268 */
        "movb $0, -0x64d(%ebp)\n" /* line 269 */
        "movb $0, -0x64c(%ebp)\n" /* line 270 */
        "movl $0x3f800000, -0x660(%ebp)\n" /* line 271 */
        "movl $0, -0x654(%ebp)\n" /* line 272 */
        "calll Com_GetDefaultSoundAliasVolumeFalloffCurve\n" /* line 273 */
        "movl %eax, -0x664(%ebp)\n"
        "movl $0, -0x644(%ebp)\n" /* line 278 */
        "xorl %esi, %esi\n"
        "movl -0x6ff0(%ebp), %ecx\n" /* token */
        "jmp .Lfb8c34_000b9169\n"
        ".Lfb8c34_000b914b:\n"
        "addl $1, %esi\n" /* line 2495 | i */
        "cmpl %esi, -0x6fcc(%ebp)\n" /* line 2496 | i, iColCount */
        "je .Lfb8c34_000b91c8\n"
        ".Lfb8c34_000b9156:\n"
        "leal -0x28(%ebp), %edi\n" /* line 2498 | ptr */
        "movl %edi, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, -0x6ff0(%ebp)\n" /* token */
        "movl %eax, %ecx\n"
        ".Lfb8c34_000b9169:\n"
        "movl -0xb94(%ebp, %esi, 4), %ebx\n" /* line 2491 | startmarker */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, %eax\n" /* startmarker */
        "shll $0xa, %eax\n"
        "leal -0x6f94(%ebp), %edi\n" /* szAliasTokens */
        "leal (%edi, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x6ff0(%ebp), %eax\n" /* line 2493 | token */
        "cmpb $0, (%eax)\n"
        "je .Lfb8c34_000b914b\n"
        "leal -0x794(%ebp), %edx\n" /* line 2494 | alias */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x40(%ebp), %ecx\n" /* bFieldSet */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* startmarker */
        "movl %eax, (%esp)\n"
        "movl 8(%ebp), %ecx\n" /* sourceFile */
        "movl 0xc(%ebp), %edx\n" /* loadspecCurGame */
        "movl $0x216cd8, %eax\n" /* "menu" */
        "calll Com_LoadSoundAliasField\n"
        "addl $1, %esi\n" /* line 2495 | i */
        "cmpl %esi, -0x6fcc(%ebp)\n" /* line 2496 | i, iColCount */
        "jne .Lfb8c34_000b9156\n"
        ".Lfb8c34_000b91c8:\n"
        "cmpb $0, -0x3f(%ebp)\n" /* line 2500 */
        "je .Lfb8c34_000b938c\n"
        "cmpb $0, -0x3d(%ebp)\n"
        "je .Lfb8c34_000b938c\n"
        "cmpb $0, -0x3c(%ebp)\n" /* line 2505 */
        "je .Lfb8c34_000b93b1\n"
        ".Lfb8c34_000b91e6:\n"
        "cld\n" /* line 2507 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x5f94(%ebp), %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "testl %ecx, %ecx\n" /* line 2508 */
        "jle .Lfb8c34_000b9223\n"
        "xorl %ebx, %ebx\n" /* startmarker */
        ".Lfb8c34_000b9201:\n"
        "movzbl -0x5f94(%ebp, %ebx), %edx\n" /* line 2510 */
        "leal -0x41(%edx), %eax\n"
        "cmpb $0x19, %al\n"
        "jbe .Lfb8c34_000b921c\n"
        "leal -0x30(%edx), %eax\n"
        "cmpb $9, %al\n"
        "jbe .Lfb8c34_000b921c\n"
        "cmpb $0x5f, %dl\n"
        "jne .Lfb8c34_000b9249\n"
        ".Lfb8c34_000b921c:\n"
        "addl $1, %ebx\n" /* line 2508 | startmarker */
        "cmpl %ebx, %ecx\n" /* startmarker */
        "jne .Lfb8c34_000b9201\n"
        ".Lfb8c34_000b9223:\n"
        "movl $9, 8(%esp)\n" /* line 2516 */
        "movl $0x21f838, 4(%esp)\n" /* "SUBTITLE_" */
        "leal -0x5f94(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "je .Lfb8c34_000b9427\n"
        ".Lfb8c34_000b9249:\n"
        "movl -0x6fcc(%ebp), %ecx\n" /* line 2526 | iColCount */
        "testl %ecx, %ecx\n"
        "jle .Lfb8c34_000b935b\n"
        "movl $0, -0x6fa4(%ebp)\n"
        "movl -0x6fa4(%ebp), %edi\n"
        "jmp .Lfb8c34_000b9308\n"
        ".Lfb8c34_000b926c:\n"
        "cmpb $0, -0x40(%ebp, %edx)\n" /* line 2528 */
        "je .Lfb8c34_000b9317\n"
        "cmpl $4, %edx\n" /* line 2530 */
        "je .Lfb8c34_000b9567\n"
        "movl -0x6fcc(%ebp), %eax\n" /* line 2555 | iColCount */
        "subl $1, %eax\n"
        "cmpl %eax, -0x6fa4(%ebp)\n"
        "je .Lfb8c34_000b952d\n"
        "shll $0xa, %edx\n" /* line 2566 */
        "leal -0x6f94(%ebp), %ebx\n" /* szAliasTokens, startmarker */
        "addl %edx, %ebx\n" /* startmarker */
        "movl $0x2c, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lfb8c34_000b95eb\n"
        ".Lfb8c34_000b92b8:\n"
        "movl %ebx, 4(%esp)\n" /* line 2568 | startmarker */
        "movl $0x21f880, (%esp)\n" /* ""%s"," */
        "calll va\n"
        "movl %eax, %ebx\n" /* startmarker */
        ".Lfb8c34_000b92ca:\n"
        "movl -0x6fc4(%ebp), %edx\n" /* line 2575 | hAliasOutFile */
        "movl %edx, 8(%esp)\n"
        "cld\n" /* line 2574 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* startmarker */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll FS_Write\n"
        ".Lfb8c34_000b92f1:\n"
        "addl $1, -0x6fa4(%ebp)\n" /* line 2526 */
        "movl -0x6fa4(%ebp), %edx\n"
        "cmpl %edx, -0x6fcc(%ebp)\n" /* iColCount */
        "je .Lfb8c34_000b935b\n"
        ".Lfb8c34_000b9306:\n"
        "movl %edx, %edi\n"
        ".Lfb8c34_000b9308:\n"
        "movl -0xb94(%ebp, %edi, 4), %edx\n" /* line 2528 */
        "testl %edx, %edx\n"
        "jne .Lfb8c34_000b926c\n"
        ".Lfb8c34_000b9317:\n"
        "movl -0x6fcc(%ebp), %eax\n" /* line 2578 | iColCount */
        "subl $1, %eax\n"
        "cmpl %eax, -0x6fa4(%ebp)\n"
        "je .Lfb8c34_000b92f1\n"
        "movl -0x6fc4(%ebp), %eax\n" /* line 2579 | hAliasOutFile */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0x21f88c, (%esp)\n" /* "," */
        "calll FS_Write\n"
        "addl $1, -0x6fa4(%ebp)\n" /* line 2526 */
        "movl -0x6fa4(%ebp), %edx\n"
        "cmpl %edx, -0x6fcc(%ebp)\n" /* iColCount */
        "jne .Lfb8c34_000b9306\n"
        ".Lfb8c34_000b935b:\n"
        "movl -0x6fc4(%ebp), %ecx\n" /* line 2581 | hAliasOutFile */
        "movl %ecx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl $0x218068, (%esp)\n" /* "
" */
        "calll FS_Write\n"
        "leal -0x28(%ebp), %edi\n" /* line 2592 | ptr */
        "movl %edi, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "movl -0x28(%ebp), %ecx\n" /* ptr */
        "jmp .Lfb8c34_000b8d31\n"
        ".Lfb8c34_000b938c:\n"
        "movl 8(%ebp), %eax\n" /* line 2501 | sourceFile */
        "movl %eax, 8(%esp)\n"
        "movl $0x21f7fc, 4(%esp)\n" /* "Sound alias file %s: alias entry missing name and/or file
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "cmpb $0, -0x3c(%ebp)\n" /* line 2505 */
        "jne .Lfb8c34_000b91e6\n"
        ".Lfb8c34_000b93b1:\n"
        "leal -0x28(%ebp), %eax\n" /* line 2585 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "movl -0x6fc4(%ebp), %edx\n" /* line 2587 | hAliasOutFile */
        "movl %edx, 8(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* ptr */
        "subl -0x6fe4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x6fe4(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll FS_Write\n"
        "movl -0x28(%ebp), %ecx\n" /* ptr */
        "jmp .Lfb8c34_000b8d31\n"
        /* { scope 2 */
        ".Lfb8c34_000b93e9:\n"
        "movl -0x6fc4(%ebp), %ecx\n" /* line 2478 | hAliasOutFile */
        "movl %ecx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0x21f7bc, (%esp)\n" /* "" */
        "calll FS_Write\n"
        "jmp .Lfb8c34_000b8fe9\n"
        /* } scope */
        ".Lfb8c34_000b940c:\n"
        "movl %ebx, 4(%esp)\n" /* line 2381 | startmarker */
        "movl $0x21f704, (%esp)\n" /* "WARNING: Can not write to sound alias file %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x700c, %esp\n" /* line 2611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bHasName, bHasFile, file, ptr, ... */
        /* { scope 2 */
        ".Lfb8c34_000b9427:\n"
        "movl $9, 8(%esp)\n" /* line 2099 */
        "movl $0x21f838, 4(%esp)\n" /* "SUBTITLE_" */
        "leal -0x5f94(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b9249\n"
        "leal -0x24(%ebp), %eax\n" /* line 2102 | file */
        "movl %eax, 4(%esp)\n"
        "movl $0x21f148, (%esp)\n" /* "soundaliases/subtitle.st" */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n"
        "js .Lfb8c34_000b9731\n"
        "movl $0x21f148, (%esp)\n" /* line 2108 */
        "calll Com_BeginParseSession\n"
        "movl -0x24(%ebp), %eax\n" /* line 2110 | file */
        "movl %eax, -0x1c(%ebp)\n" /* ptr */
        "leal -0x1c(%ebp), %ebx\n" /* ptr, bReferenceFound */
        "jmp .Lfb8c34_000b94cd\n"
        ".Lfb8c34_000b947f:\n"
        "movl $0x218158, %edi\n" /* line 2117 */
        "movl $0xa, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lfb8c34_000b949f\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lfb8c34_000b949f:\n"
        "testl %edx, %edx\n"
        "jne .Lfb8c34_000b94c5\n"
        "movl %ebx, (%esp)\n" /* line 2119 | bReferenceFound */
        "calll Com_ParseOnLine\n"
        "movl %eax, 4(%esp)\n" /* line 2120 */
        "leal -0x5f8b(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfb8c34_000b974a\n"
        ".Lfb8c34_000b94c5:\n"
        "movl %ebx, (%esp)\n" /* line 2127 | bReferenceFound */
        "calll Com_SkipRestOfLine\n"
        ".Lfb8c34_000b94cd:\n"
        "movl %ebx, (%esp)\n" /* line 2113 | bReferenceFound */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %esi\n" /* line 2114 | ptr */
        "testl %esi, %esi\n"
        "jne .Lfb8c34_000b947f\n"
        "xorl %ebx, %ebx\n" /* line 2111 | bReferenceFound */
        ".Lfb8c34_000b94de:\n"
        "calll Com_EndParseSession\n" /* line 2130 */
        "movl -0x24(%ebp), %eax\n" /* line 2131 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 2516 | startmarker */
        "jne .Lfb8c34_000b93b1\n"
        "jmp .Lfb8c34_000b9249\n"
        ".Lfb8c34_000b94fb:\n"
        "movl %edi, 4(%esp)\n" /* line 2388 */
        "movl $0x21f734, (%esp)\n" /* "WARNING: Could not read sound alias file %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x700c, %esp\n" /* line 2611 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bHasName, bHasFile, file, ptr, ... */
        ".Lfb8c34_000b9516:\n"
        "leal -0x440(%ebp), %ecx\n" /* line 2603 | szToFile */
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FS_CopyFile\n"
        "jmp .Lfb8c34_000b8f77\n"
        ".Lfb8c34_000b952d:\n"
        "shll $0xa, %edx\n" /* line 2557 */
        "leal -0x6f94(%ebp), %ebx\n" /* szAliasTokens, startmarker */
        "addl %edx, %ebx\n" /* startmarker */
        "movl $0x2c, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lfb8c34_000b964a\n"
        ".Lfb8c34_000b9550:\n"
        "movl %ebx, 4(%esp)\n" /* line 2559 | startmarker */
        "movl $0x21f878, (%esp)\n" /* ""%s"" */
        "calll va\n"
        "movl %eax, %ebx\n" /* startmarker */
        "jmp .Lfb8c34_000b92ca\n"
        ".Lfb8c34_000b9567:\n"
        "leal -0x5f94(%ebp), %eax\n" /* line 2532 */
        "movl %eax, (%esp)\n"
        "calll Com_GetSubtitleStringEdReference\n"
        "testl %eax, %eax\n" /* line 2533 */
        "je .Lfb8c34_000b96a9\n"
        "movl %eax, 0x10(%esp)\n" /* line 2535 */
        "movl $0x21f838, 0xc(%esp)\n" /* "SUBTITLE_" */
        "movl $0x215f50, 8(%esp)\n" /* "%s%s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0xf94(%ebp), %ebx\n" /* szNewReference, startmarker */
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll Com_sprintf\n"
        "movl %ebx, (%esp)\n" /* line 2536 | startmarker */
        "calll I_strupr\n"
        "movl %eax, -0x6f9c(%ebp)\n"
        ".Lfb8c34_000b95b5:\n"
        "movl -0x6fc4(%ebp), %eax\n" /* line 2551 | hAliasOutFile */
        "movl %eax, 8(%esp)\n"
        "cld\n" /* line 2550 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x6f9c(%ebp), %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x6f9c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "jmp .Lfb8c34_000b92f1\n"
        ".Lfb8c34_000b95eb:\n"
        "movl $0x20, 4(%esp)\n" /* line 2566 */
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b92b8\n"
        "movl $0xa, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b92b8\n"
        "movl $0xd, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b92b8\n"
        "movl %ebx, 4(%esp)\n" /* line 2571 | startmarker */
        "movl $0x21f888, (%esp)\n" /* "%s," */
        "calll va\n"
        "movl %eax, %ebx\n" /* startmarker */
        "jmp .Lfb8c34_000b92ca\n"
        ".Lfb8c34_000b964a:\n"
        "movl $0x20, 4(%esp)\n" /* line 2557 */
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b9550\n"
        "movl $0xa, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b9550\n"
        "movl $0xd, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll strchr\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b9550\n"
        "movl %ebx, 4(%esp)\n" /* line 2562 | startmarker */
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "movl %eax, %ebx\n" /* startmarker */
        "jmp .Lfb8c34_000b92ca\n"
        ".Lfb8c34_000b96a9:\n"
        "cmpb $0, -0x3e(%ebp)\n" /* line 2540 */
        "je .Lfb8c34_000b9a19\n"
        "leal -0x6794(%ebp), %eax\n" /* line 2541 */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x6b94(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x21f838, 0xc(%esp)\n" /* "SUBTITLE_" */
        "movl $0x21f844, 8(%esp)\n" /* "%s%s_%s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0xf94(%ebp), %ebx\n" /* szNewReference, startmarker */
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll Com_sprintf\n"
        ".Lfb8c34_000b96ed:\n"
        "movl %ebx, (%esp)\n" /* line 2544 | startmarker */
        "calll I_strupr\n"
        "movl %eax, -0x6f9c(%ebp)\n"
        /* { scope 2 */
        "movl $0x21f84c, (%esp)\n" /* line 2245 */
        "calll FS_FOpenFileWrite\n"
        "movl %eax, -0x6fb4(%ebp)\n" /* hOutFile */
        "testl %eax, %eax\n" /* line 2246 */
        "jne .Lfb8c34_000b9754\n"
        "movl $0x21f84c, 4(%esp)\n" /* line 2248 */
        "movl $0x21f77c, (%esp)\n" /* "WARNING: Could not open output file %s for writing
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lfb8c34_000b9725:\n"
        "addl $1, -0x6fc8(%ebp)\n" /* line 2547 | iNumSubtitlesLocalized */
        "jmp .Lfb8c34_000b95b5\n"
        /* { scope 2 */
        ".Lfb8c34_000b9731:\n"
        "movl $0x21f148, 4(%esp)\n" /* line 2104 */
        "movl $0x21f164, (%esp)\n" /* "WARNING: Could not read local copy of StringEd file %s
" */
        "calll Com_Printf\n"
        "jmp .Lfb8c34_000b9249\n"
        ".Lfb8c34_000b974a:\n"
        "movl $1, %ebx\n" /* line 2120 | bReferenceFound */
        "jmp .Lfb8c34_000b94de\n"
        /* } scope */
        /* { scope 2 */
        ".Lfb8c34_000b9754:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 2252 | ptr */
        "movl %edx, 4(%esp)\n"
        "movl $0x21f148, (%esp)\n" /* "soundaliases/subtitle.st" */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n"
        "js .Lfb8c34_000b99f2\n"
        "movl $0x21f148, (%esp)\n" /* line 2259 */
        "calll Com_BeginParseSession\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2261 | ptr */
        "movl %eax, -0x24(%ebp)\n" /* file */
        "movl %eax, %ebx\n" /* line 2262 | startmarker */
        "movl $0, -0x6fb0(%ebp)\n" /* bReferenceAdded */
        "jmp .Lfb8c34_000b979a\n"
        ".Lfb8c34_000b978f:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2317 | file */
        "movl %eax, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        ".Lfb8c34_000b979a:\n"
        "leal -0x24(%ebp), %edi\n" /* line 2265 | file */
        "movl %edi, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x6fb8(%ebp)\n" /* token */
        "movl -0x24(%ebp), %eax\n" /* line 2266 | file */
        "movl %eax, -0x6fec(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lfb8c34_000b9924\n"
        "movl $0xa, -0x6fd4(%ebp)\n" /* line 2269 */
        "cld\n"
        "movl -0x6fb8(%ebp), %esi\n" /* token */
        "movl $0x218164, %edi\n" /* "ENDMARKER" */
        "movl $0xa, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lfb8c34_000b97ea\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfb8c34_000b97ea:\n"
        "testl %eax, %eax\n"
        "je .Lfb8c34_000b98f7\n"
        "movl $0xa, %ecx\n" /* line 2281 */
        "cld\n"
        "movl -0x6fb8(%ebp), %esi\n" /* token */
        "movl $0x218158, %edi\n" /* "REFERENCE" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lfb8c34_000b9816\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfb8c34_000b9816:\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b978f\n"
        "leal -0x24(%ebp), %eax\n" /* line 2283 | file */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "leal -0xf8b(%ebp), %edx\n" /* line 2284 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b978f\n"
        "movl -0x24(%ebp), %eax\n" /* line 2287 | file */
        "cmpl %ebx, %eax\n" /* startmarker */
        "jbe .Lfb8c34_000b9862\n"
        "movl -0x6fb4(%ebp), %ecx\n" /* line 2290 | hOutFile */
        "movl %ecx, 8(%esp)\n"
        "subl %ebx, %eax\n" /* startmarker */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll FS_Write\n"
        ".Lfb8c34_000b9862:\n"
        "movl -0x6fb4(%ebp), %ecx\n" /* line 2293 | hOutFile */
        "leal -0x5f94(%ebp), %edx\n"
        "leal -0xf8b(%ebp), %eax\n"
        "calll Com_WriteStringEdReferenceToFile\n"
        ".Lfb8c34_000b9879:\n"
        "movl -0x24(%ebp), %ebx\n" /* line 2300 | file, startmarker */
        "leal -0x24(%ebp), %edi\n" /* line 2301 | file */
        "movl %edi, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x6fa0(%ebp)\n"
        "movl -0x24(%ebp), %edx\n" /* line 2302 | file */
        "testl %edx, %edx\n"
        "je .Lfb8c34_000b9a4e\n"
        "movl $0xa, %ecx\n" /* line 2308 */
        "cld\n"
        "movl %eax, %esi\n"
        "movl $0x218158, %edi\n" /* "REFERENCE" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lfb8c34_000b98b8\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfb8c34_000b98b8:\n"
        "testl %eax, %eax\n"
        "je .Lfb8c34_000b98e3\n"
        "movl $0xa, %ecx\n"
        "movl -0x6fa0(%ebp), %esi\n"
        "movl $0x218164, %edi\n" /* "ENDMARKER" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lfb8c34_000b98df\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfb8c34_000b98df:\n"
        "testl %eax, %eax\n"
        "jne .Lfb8c34_000b9879\n"
        ".Lfb8c34_000b98e3:\n"
        "calll Com_UngetToken\n" /* line 2310 */
        "movl $1, -0x6fb0(%ebp)\n" /* bReferenceAdded */
        "jmp .Lfb8c34_000b978f\n"
        ".Lfb8c34_000b98f7:\n"
        "cmpl -0x6fec(%ebp), %ebx\n" /* line 2272 | startmarker */
        "jae .Lfb8c34_000b9924\n"
        "movl -0x6fb4(%ebp), %eax\n" /* line 2275 | hOutFile */
        "movl %eax, 8(%esp)\n"
        "subl %ebx, -0x6fec(%ebp)\n" /* startmarker */
        "movl -0x6fec(%ebp), %eax\n"
        "subl $0xb, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll FS_Write\n"
        ".Lfb8c34_000b9924:\n"
        "movl -0x6fb0(%ebp), %edi\n" /* line 2320 | bReferenceAdded */
        "testl %edi, %edi\n"
        "jne .Lfb8c34_000b9945\n"
        "movl -0x6fb4(%ebp), %ecx\n" /* line 2322 | hOutFile */
        "leal -0x5f94(%ebp), %edx\n"
        "leal -0xf8b(%ebp), %eax\n"
        "calll Com_WriteStringEdReferenceToFile\n"
        ".Lfb8c34_000b9945:\n"
        "calll Com_EndParseSession\n" /* line 2325 */
        "movl -0x1c(%ebp), %eax\n" /* line 2326 | ptr */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl -0x6fb4(%ebp), %edx\n" /* line 2330 | hOutFile */
        "movl %edx, 8(%esp)\n"
        "movl $0x11, 4(%esp)\n"
        "movl $0x21f864, (%esp)\n" /* "
ENDMARKER


" */
        "calll FS_Write\n"
        "movl -0x6fb4(%ebp), %ecx\n" /* line 2331 | hOutFile */
        "movl %ecx, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0x640(%ebp), %edi\n" /* line 2334 | szFromFile */
        "movl %edi, 0xc(%esp)\n"
        "movl $0x21f84c, 8(%esp)\n" /* "soundaliases/temp.st" */
        "movl 0x195ee98, %ebx\n" /* startmarker */
        "movl %ebx, 4(%esp)\n" /* startmarker */
        "movl 0x195ecc8, %esi\n"
        "movl (%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "leal -0x140(%ebp), %eax\n" /* line 2335 | szToFile */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x21f148, 8(%esp)\n" /* "soundaliases/subtitle.st" */
        "movl %ebx, 4(%esp)\n" /* startmarker */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "leal -0x140(%ebp), %edx\n" /* line 2336 | szToFile */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FS_CopyFile\n"
        "movl %edi, (%esp)\n" /* line 2337 */
        "calll FS_Remove\n"
        "jmp .Lfb8c34_000b9725\n"
        ".Lfb8c34_000b99f2:\n"
        "movl $0x21f148, 4(%esp)\n" /* line 2254 */
        "movl $0x21f164, (%esp)\n" /* "WARNING: Could not read local copy of StringEd file %s
" */
        "calll Com_Printf\n"
        "movl -0x6fb4(%ebp), %ecx\n" /* line 2255 | hOutFile */
        "movl %ecx, (%esp)\n"
        "calll FS_FCloseFile\n"
        "jmp .Lfb8c34_000b9725\n"
        /* } scope */
        ".Lfb8c34_000b9a19:\n"
        "leal -0x6b94(%ebp), %eax\n" /* line 2543 */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x21f838, 0xc(%esp)\n" /* "SUBTITLE_" */
        "movl $0x215f50, 8(%esp)\n" /* "%s%s" */
        "movl $0x400, 4(%esp)\n"
        "leal -0xf94(%ebp), %ebx\n" /* szNewReference, startmarker */
        "movl %ebx, (%esp)\n" /* startmarker */
        "calll Com_sprintf\n"
        "jmp .Lfb8c34_000b96ed\n"
        /* { scope 2 */
        ".Lfb8c34_000b9a4e:\n"
        "movl $1, -0x6fb0(%ebp)\n" /* line 2302 | bReferenceAdded */
        "xorl %ebx, %ebx\n" /* startmarker */
        "jmp .Lfb8c34_000b978f\n"
    );
}

/* line 2670 */
__attribute__((naked))
void Com_WriteLocalizedSoundAliasFiles(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2670 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x24c, %esp\n"
        /* { scope 1 */
        "leal -0x11c(%ebp), %ebx\n" /* line 2681 | stringEdExternalFileName */
        "movl %ebx, 0xc(%esp)\n"
        "movl $0x2157b8, 8(%esp)\n"
        "movl $0x21f8b4, 4(%esp)\n" /* "../source_data/string_resources/subtitle.st" */
        "movl 0x195ed00, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "cld\n" /* line 2682 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* i */
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "movb $0, -0x11e(%ecx, %ebp)\n"
        "movl $0x21f700, 4(%esp)\n" /* line 2683 */
        "movl %ebx, (%esp)\n"
        "calll FS_FileOpen\n"
        "testl %eax, %eax\n" /* line 2684 */
        "je .Lfb9a60_000b9d2f\n"
        "movl %eax, (%esp)\n" /* line 2689 */
        "calll FS_FileClose\n"
        "leal -0x21c(%ebp), %eax\n" /* line 2692 | stringEdFileName */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x21f148, 8(%esp)\n" /* "soundaliases/subtitle.st" */
        "movl 0x195ee98, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ecc8, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "leal -0x21c(%ebp), %eax\n" /* line 2693 | stringEdFileName */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_CopyFile\n"
        "movl $0x21f148, (%esp)\n" /* line 2694 */
        "calll FS_FileExists\n"
        "testl %eax, %eax\n"
        "je .Lfb9a60_000b9b84\n"
        "movl $0x21f944, (%esp)\n" /* line 2700 */
        "calll Com_Printf\n"
        "movl %ebx, 4(%esp)\n" /* line 2701 */
        "movl $0x21f970, (%esp)\n" /* "Writing to StringEd file %s
" */
        "calll Com_Printf\n"
        "movl $0xa, 0x10(%esp)\n" /* line 2704 */
        "leal -0x1c(%ebp), %eax\n" /* fileCount */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x21e5ac, 4(%esp)\n" /* "csv" */
        "movl $0x21e51c, (%esp)\n" /* "soundaliases" */
        "calll FS_ListFiles\n"
        "movl %eax, %esi\n" /* fileNames */
        "movl -0x1c(%ebp), %edi\n" /* line 2705 | fileCount, i */
        "testl %edi, %edi\n" /* i */
        "jne .Lfb9a60_000b9ba3\n"
        "movl $0x21e5b0, (%esp)\n" /* line 2707 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x24c, %esp\n" /* line 2728 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb9a60_000b9b84:\n"
        "movl $0x21f148, 4(%esp)\n" /* line 2696 */
        "movl $0x21f90c, (%esp)\n" /* "WARNING: Could not make local copy of StringEd file %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x24c, %esp\n" /* line 2728 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb9a60_000b9ba3:\n"
        "calll Hunk_HideTempMemory\n" /* line 2711 */
        "movl %eax, -0x22c(%ebp)\n" /* mark */
        "movl -0x1c(%ebp), %ecx\n" /* line 2713 | fileCount */
        "testl %ecx, %ecx\n"
        "jg .Lfb9a60_000b9cf8\n"
        ".Lfb9a60_000b9bb9:\n"
        "movl %eax, (%esp)\n" /* line 2719 */
        "calll Hunk_ShowTempMemory\n"
        "movl $0xa, 4(%esp)\n" /* line 2721 */
        "movl %esi, (%esp)\n" /* fileNames */
        "calll FS_FreeFileList\n"
        /* { scope 2 */
        "movl $0x215b98, 4(%esp)\n" /* line 2625 */
        "leal -0x21c(%ebp), %eax\n" /* stringEdFileName */
        "movl %eax, (%esp)\n"
        "calll FS_FileOpen\n"
        "movl %eax, %edi\n" /* f */
        "testl %eax, %eax\n" /* line 2626 */
        "je .Lfb9a60_000b9cd3\n"
        "movl $2, 8(%esp)\n" /* line 2629 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "movl %edi, (%esp)\n" /* line 2630 | f */
        "calll ftell\n"
        "movl %eax, %esi\n"
        "movl $0, 8(%esp)\n" /* line 2631 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* f */
        "calll FS_FileSeek\n"
        "movl %esi, (%esp)\n" /* line 2635 */
        "calll malloc\n"
        "movl %eax, -0x230(%ebp)\n"
        "movl %edi, 0xc(%esp)\n" /* line 2636 | f */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "cmpl %eax, %esi\n"
        "je .Lfb9a60_000b9c69\n"
        "movl $0x21f998, 4(%esp)\n" /* line 2637 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lfb9a60_000b9c69:\n"
        "movl %edi, (%esp)\n" /* line 2638 | f */
        "calll FS_FileClose\n"
        "movl $0x216fec, 4(%esp)\n" /* line 2640 */
        "movl %ebx, (%esp)\n"
        "calll FS_FileOpen\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 2641 */
        "je .Lfb9a60_000b9cc5\n"
        "movl %eax, 0xc(%esp)\n" /* line 2646 */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl -0x230(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileWrite\n"
        "cmpl %eax, %esi\n"
        "je .Lfb9a60_000b9cbd\n"
        "movl $0x21f9c8, 4(%esp)\n" /* line 2647 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lfb9a60_000b9cbd:\n"
        "movl %ebx, (%esp)\n" /* line 2648 */
        "calll FS_FileClose\n"
        ".Lfb9a60_000b9cc5:\n"
        "movl -0x230(%ebp), %eax\n" /* line 2649 */
        "movl %eax, (%esp)\n"
        "calll free\n"
        /* } scope */
        ".Lfb9a60_000b9cd3:\n"
        "leal -0x21c(%ebp), %eax\n" /* line 2725 | stringEdFileName */
        "movl %eax, (%esp)\n"
        "calll FS_Remove\n"
        "movl $0x21f9f8, (%esp)\n" /* line 2727 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x24c, %esp\n" /* line 2728 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb9a60_000b9cf8:\n"
        "xorl %edi, %edi\n" /* line 2713 | i */
        ".Lfb9a60_000b9cfa:\n"
        "leal -0x21c(%ebp), %eax\n" /* line 2715 | stringEdFileName */
        "movl %eax, 8(%esp)\n"
        "movl $0x21f990, 4(%esp)\n" /* "all_mp" */
        "movl (%esi, %edi, 4), %eax\n" /* fileNames */
        "movl %eax, (%esp)\n"
        "calll Com_ProcessSoundAliasFileLocalization\n"
        "calll Hunk_ClearTempMemory\n" /* line 2716 */
        "addl $1, %edi\n" /* line 2713 | i */
        "cmpl -0x1c(%ebp), %edi\n" /* fileCount, i */
        "jl .Lfb9a60_000b9cfa\n"
        "movl -0x22c(%ebp), %eax\n" /* mark */
        "jmp .Lfb9a60_000b9bb9\n"
        ".Lfb9a60_000b9d2f:\n"
        "movl %ebx, 4(%esp)\n" /* line 2686 */
        "movl $0x21f8e0, (%esp)\n" /* "WARNING: Can not write to StringEd file %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x24c, %esp\n" /* line 2728 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 885 */
__attribute__((naked))
void Com_LoadSoundAliasFile(const char *loadspec, const char *loadspecCurGame, const char *sourceFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 885 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x265c, %esp\n"
        /* { scope 1: fileName, fileHandle, buffer, parseBuffer, ... */
        "movl 0x10(%ebp), %eax\n" /* line 897 | sourceFile */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x21f6cc, 8(%esp)\n" /* "soundaliases/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x80(%ebp), %edx\n" /* filename */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x1c(%ebp), %eax\n" /* line 899 | file */
        "movl %eax, 4(%esp)\n"
        "leal -0x80(%ebp), %edi\n" /* filename, volumeModGroupIndex */
        "movl %edi, (%esp)\n" /* volumeModGroupIndex */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n"
        "js .Lfb9d4a_000b9ec0\n"
        "cmpb $0, 0x1150da8\n" /* line 902 */
        "jne .Lfb9d4a_000b9efb\n"
        "cmpb $0, 0x1150da9\n" /* line 905 */
        "je .Lfb9d4a_000ba3c8\n"
        /* { scope 2 */
        ".Lfb9d4a_000b9dac:\n"
        "movl $0x6e756f73, -0xc0(%ebp)\n" /* line 790 | fileName */
        "movl $0x696c6164, -0xbc(%ebp)\n"
        "movl $0x73657361, -0xb8(%ebp)\n"
        "movl $0x6c6f762f, -0xb4(%ebp)\n"
        "movl $0x6d656d75, -0xb0(%ebp)\n"
        "movl $0x7267646f, -0xac(%ebp)\n"
        "movl $0x7370756f, -0xa8(%ebp)\n"
        "movl $0x6665642e, -0xa4(%ebp)\n"
        "movb $0, -0xa0(%ebp)\n"
        "movl $1, 8(%esp)\n" /* line 792 */
        "leal -0x24(%ebp), %eax\n" /* fileHandle */
        "movl %eax, 4(%esp)\n"
        "leal -0xc0(%ebp), %eax\n" /* fileName */
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileRead\n"
        "movl %eax, %ebx\n" /* fileLength */
        "cmpl $0, %eax\n" /* line 793 */
        "jl .Lfb9d4a_000ba5d9\n"
        "je .Lfb9d4a_000b9ecb\n" /* line 798 */
        "movl -0x24(%ebp), %eax\n" /* line 806 | fileHandle */
        "movl %eax, 8(%esp)\n"
        "movl $0xf, 4(%esp)\n"
        "leal -0x2614(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x2605(%ebp)\n" /* line 807 */
        "movl $0x21fa50, %edi\n" /* line 809 | volumeModGroupIndex */
        "movl $0xf, %ecx\n"
        "cld\n"
        "leal -0x2614(%ebp), %esi\n" /* buffer */
        "repe cmpsb %es:(%edi), (%esi)\n" /* volumeModGroupIndex */
        "movl $0, %eax\n"
        "je .Lfb9d4a_000b9e79\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n" /* volumeModGroupIndex */
        "subl %ecx, %eax\n"
        ".Lfb9d4a_000b9e79:\n"
        "testl %eax, %eax\n"
        "jne .Lfb9d4a_000ba5ab\n"
        "subl $0xf, %ebx\n" /* line 817 | fileLength */
        "cmpl $0x1fff, %ebx\n" /* fileLength */
        "jle .Lfb9d4a_000ba49b\n"
        "movl -0x24(%ebp), %eax\n" /* line 819 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0xc0(%ebp), %edi\n" /* line 820 | fileName, volumeModGroupIndex */
        "movl %edi, 8(%esp)\n" /* volumeModGroupIndex */
        "movl $0x21fa9c, 4(%esp)\n" /* "ERROR: "%s" Is too long of a volumemodgroups file to parse
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfb9d4a_000b9ef4\n"
        /* } scope */
        ".Lfb9d4a_000b9ebb:\n"
        "calll Com_EndParseSession\n" /* line 1000 */
        /* } scope */
        ".Lfb9d4a_000b9ec0:\n"
        "addl $0x265c, %esp\n" /* line 1003 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fileName, fileHandle, buffer, parseBuffer, ... */
        /* { scope 2 */
        ".Lfb9d4a_000b9ecb:\n"
        "movl -0x24(%ebp), %eax\n" /* line 800 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0xc0(%ebp), %edi\n" /* line 801 | fileName, volumeModGroupIndex */
        "movl %edi, 8(%esp)\n" /* volumeModGroupIndex */
        "movl $0x21fa38, 4(%esp)\n" /* "ERROR: '%s' is empty
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lfb9d4a_000b9ef4:\n"
        "movb $1, 0x1150da8\n" /* line 913 */
        ".Lfb9d4a_000b9efb:\n"
        "leal -0x80(%ebp), %eax\n" /* line 916 | filename */
        "movl %eax, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "movl $1, (%esp)\n" /* line 917 */
        "calll Com_SetCSV\n"
        "movl -0x1c(%ebp), %eax\n" /* line 919 | file */
        "movl %eax, -0x20(%ebp)\n" /* ptr */
        "movl $0, -0x2638(%ebp)\n" /* iColCount */
        ".Lfb9d4a_000b9f22:\n"
        "leal -0x20(%ebp), %edx\n" /* line 923 | ptr */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x2640(%ebp)\n" /* token */
        "movl -0x20(%ebp), %edx\n" /* line 924 | ptr */
        "testl %edx, %edx\n"
        "je .Lfb9d4a_000b9ebb\n"
        "movzbl (%eax), %eax\n" /* line 927 */
        "testb %al, %al\n"
        "je .Lfb9d4a_000ba074\n"
        "cmpb $0x23, %al\n"
        "je .Lfb9d4a_000ba074\n"
        "movl -0x2638(%ebp), %eax\n" /* line 933 | iColCount */
        "testl %eax, %eax\n"
        "jne .Lfb9d4a_000ba084\n"
        "movl $0, -0x2628(%ebp)\n" /* bHasName */
        "movl $0, -0x2624(%ebp)\n" /* bHasFile */
        "movl $1, -0x2620(%ebp)\n"
        ".Lfb9d4a_000b9f79:\n"
        "movl -0x2620(%ebp), %edx\n" /* line 885 */
        "leal -0x614(%ebp, %edx, 4), %eax\n"
        "leal -4(%eax), %edi\n" /* volumeModGroupIndex */
        "movl %edi, -0x261c(%ebp)\n" /* volumeModGroupIndex */
        /* { scope 2 */
        "movl $0, -4(%eax)\n" /* line 941 */
        "movl $1, %esi\n"
        "movl $g_pszSndAliasKeyNames, %ebx\n" /* i */
        "jmp .Lfb9d4a_000b9fad\n"
        ".Lfb9d4a_000b9fa2:\n"
        "addl $1, %esi\n" /* line 942 */
        "addl $4, %ebx\n" /* i */
        "cmpl $0x18, %esi\n"
        "je .Lfb9d4a_000b9fdc\n"
        ".Lfb9d4a_000b9fad:\n"
        "movl -0x2640(%ebp), %eax\n" /* line 944 | token */
        "movl %eax, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfb9d4a_000b9fa2\n"
        "movl -0x261c(%ebp), %edx\n" /* line 946 */
        "movl %esi, (%edx)\n"
        "cmpl $1, %esi\n" /* line 947 */
        "je .Lfb9d4a_000ba01b\n"
        "cmpl $3, %esi\n" /* line 949 */
        "je .Lfb9d4a_000ba065\n"
        ".Lfb9d4a_000b9fdc:\n"
        "movl -0x2620(%ebp), %edi\n" /* line 942 | volumeModGroupIndex */
        "movl %edi, -0x2638(%ebp)\n" /* volumeModGroupIndex, iColCount */
        "cmpl $0x100, %edi\n" /* line 955 | volumeModGroupIndex */
        "je .Lfb9d4a_000ba039\n"
        ".Lfb9d4a_000b9ff0:\n"
        "movl -0x20(%ebp), %eax\n" /* line 957 | ptr */
        "testl %eax, %eax\n"
        "je .Lfb9d4a_000ba039\n"
        "addl $1, %edi\n" /* volumeModGroupIndex */
        "movl %edi, -0x2620(%ebp)\n" /* volumeModGroupIndex */
        "cmpb $0xa, (%eax)\n"
        "je .Lfb9d4a_000ba039\n"
        "leal -0x20(%ebp), %eax\n" /* line 959 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, -0x2640(%ebp)\n" /* token */
        "jmp .Lfb9d4a_000b9f79\n"
        ".Lfb9d4a_000ba01b:\n"
        "movl $1, -0x2628(%ebp)\n" /* line 947 | bHasName */
        "movl -0x2620(%ebp), %edi\n" /* line 942 | volumeModGroupIndex */
        "movl %edi, -0x2638(%ebp)\n" /* volumeModGroupIndex, iColCount */
        "cmpl $0x100, %edi\n" /* line 955 | volumeModGroupIndex */
        "jne .Lfb9d4a_000b9ff0\n"
        ".Lfb9d4a_000ba039:\n"
        "movl -0x2628(%ebp), %eax\n" /* line 962 | bHasName */
        "testl %eax, %eax\n"
        "je .Lfb9d4a_000ba3e8\n"
        "movl -0x2624(%ebp), %eax\n" /* bHasFile */
        "testl %eax, %eax\n"
        "je .Lfb9d4a_000ba3e8\n"
        /* } scope */
        ".Lfb9d4a_000ba055:\n"
        "leal -0x20(%ebp), %edx\n" /* line 997 | ptr */
        "movl %edx, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "jmp .Lfb9d4a_000b9f22\n"
        /* { scope 2 */
        ".Lfb9d4a_000ba065:\n"
        "movl $1, -0x2624(%ebp)\n" /* line 949 | bHasFile */
        "jmp .Lfb9d4a_000b9fdc\n"
        /* } scope */
        ".Lfb9d4a_000ba074:\n"
        "leal -0x20(%ebp), %eax\n" /* line 929 | ptr */
        "movl %eax, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "jmp .Lfb9d4a_000b9f22\n"
        ".Lfb9d4a_000ba084:\n"
        "cld\n" /* line 972 */
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x40(%ebp), %edi\n" /* bFieldSet, volumeModGroupIndex */
        "rep stosl %eax, %es:(%edi)\n" /* volumeModGroupIndex */
        "movl 0x10(%ebp), %eax\n" /* line 246 | sourceFile */
        "movl %eax, 4(%esp)\n"
        "leal -0x214(%ebp), %edx\n" /* alias */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "movb $0, -0x1d4(%ebp)\n" /* line 248 */
        "movb $0, -0x194(%ebp)\n" /* line 249 */
        "movl $0, -0x150(%ebp)\n" /* line 250 */
        "movb $0, -0x14c(%ebp)\n" /* line 251 */
        "movl $0, -0x154(%ebp)\n" /* line 252 */
        "movl $0x3f800000, %eax\n" /* line 253 */
        "movl %eax, -0x108(%ebp)\n"
        "movl %eax, -0x104(%ebp)\n" /* line 254 */
        "movl %eax, -0x100(%ebp)\n" /* line 255 */
        "movl %eax, -0x263c(%ebp)\n" /* line 256 */
        "movss -0x263c(%ebp), %xmm0\n"
        "movss %xmm0, -0xfc(%ebp)\n"
        "movss %xmm0, -0xf8(%ebp)\n" /* line 257 */
        "movl $0x42f00000, -0xf4(%ebp)\n" /* line 258 */
        "xorl %eax, %eax\n" /* line 259 */
        "movl %eax, -0xf0(%ebp)\n"
        "movl $0, -0xec(%ebp)\n" /* line 260 */
        "movl $1, -0xe8(%ebp)\n" /* line 261 */
        "movb $0, -0xd0(%ebp)\n" /* line 262 */
        "movss %xmm0, -0xdc(%ebp)\n" /* line 263 */
        "movl %eax, -0xd8(%ebp)\n" /* line 264 */
        "movb $0, -0xcb(%ebp)\n" /* line 265 */
        "movl $0x216cd8, %ebx\n" /* line 266 */
        "movl $5, %ecx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* loadspec */
        "movl %ebx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lfb9d4a_000ba169\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfb9d4a_000ba169:\n"
        "testl %eax, %eax\n"
        "setne -0xca(%ebp)\n"
        "movb $0, -0xcf(%ebp)\n" /* line 267 */
        "movb $0, -0xce(%ebp)\n" /* line 268 */
        "movb $0, -0xcd(%ebp)\n" /* line 269 */
        "movb $0, -0xcc(%ebp)\n" /* line 270 */
        "movss %xmm0, -0xe0(%ebp)\n" /* line 271 */
        "movl $0, -0xd4(%ebp)\n" /* line 272 */
        "calll Com_GetDefaultSoundAliasVolumeFalloffCurve\n" /* line 273 */
        "movl %eax, -0xe4(%ebp)\n"
        "movl $0, -0xc4(%ebp)\n" /* line 278 */
        "xorl %ebx, %ebx\n"
        "movl -0x2640(%ebp), %eax\n" /* token */
        "jmp .Lfb9d4a_000ba1db\n"
        ".Lfb9d4a_000ba1bf:\n"
        "addl $1, %ebx\n" /* line 979 | i */
        "cmpl %ebx, -0x2638(%ebp)\n" /* line 980 | i, iColCount */
        "je .Lfb9d4a_000ba21e\n"
        ".Lfb9d4a_000ba1ca:\n"
        "leal -0x20(%ebp), %edx\n" /* line 982 | ptr */
        "movl %edx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, -0x2640(%ebp)\n" /* token */
        ".Lfb9d4a_000ba1db:\n"
        "cmpb $0, (%eax)\n" /* line 977 */
        "je .Lfb9d4a_000ba1bf\n"
        "leal -0x214(%ebp), %edx\n" /* line 978 | alias */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x40(%ebp), %edi\n" /* bFieldSet, volumeModGroupIndex */
        "movl %edi, 8(%esp)\n" /* volumeModGroupIndex */
        "movl -0x614(%ebp, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2640(%ebp), %eax\n" /* token */
        "movl %eax, (%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* sourceFile */
        "movl 0xc(%ebp), %edx\n" /* loadspecCurGame */
        "movl 8(%ebp), %eax\n" /* loadspec */
        "calll Com_LoadSoundAliasField\n"
        "addl $1, %ebx\n" /* line 979 | i */
        "cmpl %ebx, -0x2638(%ebp)\n" /* line 980 | i, iColCount */
        "jne .Lfb9d4a_000ba1ca\n"
        ".Lfb9d4a_000ba21e:\n"
        "cmpb $0, -0x3f(%ebp)\n" /* line 984 */
        "je .Lfb9d4a_000ba434\n"
        "cmpb $0, -0x3d(%ebp)\n"
        "je .Lfb9d4a_000ba434\n"
        "cmpb $0, -0xca(%ebp)\n" /* line 990 */
        "je .Lfb9d4a_000ba055\n"
        "cmpb $0, -0xcb(%ebp)\n"
        "jne .Lfb9d4a_000ba055\n"
        /* { scope 2 */
        "movss -0xfc(%ebp), %xmm0\n" /* line 683 */
        "movss -0xf8(%ebp), %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lfb9d4a_000ba3b0\n"
        ".Lfb9d4a_000ba265:\n"
        "pxor %xmm2, %xmm2\n" /* line 689 */
        "ucomiss %xmm0, %xmm2\n"
        "jae .Lfb9d4a_000ba476\n"
        "movss -0x108(%ebp), %xmm1\n" /* line 695 */
        "movss -0x104(%ebp), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lfb9d4a_000ba38b\n"
        ".Lfb9d4a_000ba28b:\n"
        "ucomiss %xmm1, %xmm2\n" /* line 701 */
        "ja .Lfb9d4a_000ba451\n"
        "ucomiss -0xf0(%ebp), %xmm2\n" /* line 707 */
        "jne .Lfb9d4a_000ba3a3\n"
        "jp .Lfb9d4a_000ba3a3\n"
        "movss -0xf4(%ebp), %xmm1\n" /* line 708 */
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed6d4, %xmm0\n" /* 5.0f */
        "movss %xmm0, -0xf0(%ebp)\n"
        ".Lfb9d4a_000ba2c2:\n"
        "movss -0xf0(%ebp), %xmm0\n" /* line 709 */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lfb9d4a_000ba405\n"
        "ucomiss %xmm1, %xmm2\n" /* line 714 */
        "jae .Lfb9d4a_000ba586\n"
        "movss -0x100(%ebp), %xmm0\n" /* line 720 */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lfb9d4a_000ba2f3\n"
        "je .Lfb9d4a_000ba33e\n"
        ".Lfb9d4a_000ba2f3:\n"
        "mulss -0x108(%ebp), %xmm0\n" /* line 722 */
        "ucomiss %xmm0, %xmm2\n" /* line 723 */
        "ja .Lfb9d4a_000ba66e\n"
        "movaps %xmm1, %xmm3\n" /* line 725 */
        "minss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        ".Lfb9d4a_000ba30e:\n"
        "movss %xmm0, -0x108(%ebp)\n" /* line 727 */
        "movss -0x104(%ebp), %xmm0\n" /* line 729 */
        "mulss -0x100(%ebp), %xmm0\n"
        "ucomiss %xmm0, %xmm2\n" /* line 730 */
        "ja .Lfb9d4a_000ba666\n"
        "minss %xmm0, %xmm1\n" /* line 732 */
        "movaps %xmm1, %xmm0\n"
        ".Lfb9d4a_000ba336:\n"
        "movss %xmm0, -0x104(%ebp)\n" /* line 734 */
        /* } scope */
        ".Lfb9d4a_000ba33e:\n"
        "movl $0x21fd00, 4(%esp)\n" /* line 750 */
        "movl $0x154, (%esp)\n"
        "calll Com_AllocateTempSoundMemory\n"
        "movl %eax, %ebx\n"
        "movl $0x154, 8(%esp)\n" /* line 752 */
        "leal -0x214(%ebp), %eax\n" /* alias */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl saLoadObjGlob, %eax\n" /* line 753 */
        "movl %eax, 0x150(%ebx)\n"
        "movl %ebx, saLoadObjGlob\n" /* line 754 */
        "addl $1, 0x1150524\n" /* line 755 */
        "jmp .Lfb9d4a_000ba055\n"
        /* { scope 2 */
        ".Lfb9d4a_000ba38b:\n"
        "movss %xmm1, -0x104(%ebp)\n" /* line 698 */
        "movss %xmm0, -0x108(%ebp)\n" /* line 699 */
        "movaps %xmm0, %xmm1\n"
        "jmp .Lfb9d4a_000ba28b\n"
        ".Lfb9d4a_000ba3a3:\n"
        "movss -0xf4(%ebp), %xmm1\n"
        "jmp .Lfb9d4a_000ba2c2\n"
        ".Lfb9d4a_000ba3b0:\n"
        "movss %xmm0, -0xf8(%ebp)\n" /* line 686 */
        "movaps %xmm1, %xmm0\n" /* line 687 */
        "movss %xmm1, -0xfc(%ebp)\n"
        "jmp .Lfb9d4a_000ba265\n"
        /* } scope */
        ".Lfb9d4a_000ba3c8:\n"
        "movl $Com_RefreshVolumeModGroups_f, 4(%esp)\n" /* line 907 */
        "movl $0x21fa00, (%esp)\n" /* "snd_refreshVolumeModGroups" */
        "calll Cmd_AddCommand\n"
        "movb $1, 0x1150da9\n" /* line 908 */
        "jmp .Lfb9d4a_000b9dac\n"
        /* { scope 2 */
        ".Lfb9d4a_000ba3e8:\n"
        "movl 0x10(%ebp), %edx\n" /* line 964 | sourceFile */
        "movl %edx, 4(%esp)\n"
        "movl $0x21fba8, (%esp)\n" /* "^1ERROR: Sound alias file %s: missing 'name' and/or 'file' c" */
        "calll Com_Printf\n"
        "calll Com_EndParseSession\n" /* line 965 */
        "jmp .Lfb9d4a_000b9ec0\n"
        /* } scope */
        /* { scope 2 */
        ".Lfb9d4a_000ba405:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 711 */
        "movsd %xmm0, 0x10(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 8(%esp)\n"
        "leal -0x1d4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21fc94, (%esp)\n" /* "^1ERROR: sound alias '%s' has dist_min %g <= dist_max %g
" */
        "calll Com_Printf\n"
        "jmp .Lfb9d4a_000ba055\n"
        /* } scope */
        ".Lfb9d4a_000ba434:\n"
        "movl 0x10(%ebp), %edi\n" /* line 986 | sourceFile, volumeModGroupIndex */
        "movl %edi, 4(%esp)\n" /* volumeModGroupIndex */
        "movl $0x21fbec, (%esp)\n" /* "^1ERROR: Sound alias file %s: alias entry missing name and/o" */
        "calll Com_Printf\n"
        "calll Com_EndParseSession\n" /* line 987 */
        "jmp .Lfb9d4a_000b9ec0\n"
        /* { scope 2 */
        ".Lfb9d4a_000ba451:\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 703 */
        "movsd %xmm1, 8(%esp)\n"
        "leal -0x1d4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21fc64, (%esp)\n" /* "^1ERROR: sound alias '%s' has vol_min %g < 0
" */
        "calll Com_Printf\n"
        "jmp .Lfb9d4a_000ba055\n"
        ".Lfb9d4a_000ba476:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 691 */
        "movsd %xmm0, 8(%esp)\n"
        "leal -0x1d4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21fc30, (%esp)\n" /* "^1ERROR: sound alias '%s' has pitch_min %g <= 0
" */
        "calll Com_Printf\n"
        "jmp .Lfb9d4a_000ba055\n"
        /* } scope */
        /* { scope 2 */
        ".Lfb9d4a_000ba49b:\n"
        "movl $0x2000, 8(%esp)\n" /* line 825 */
        "movl $0, 4(%esp)\n"
        "leal -0x2614(%ebp), %edx\n" /* buffer */
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl -0x24(%ebp), %eax\n" /* line 826 | fileHandle */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* fileLength */
        "leal -0x2614(%ebp), %edi\n" /* buffer, volumeModGroupIndex */
        "movl %edi, (%esp)\n" /* volumeModGroupIndex */
        "calll FS_Read\n"
        "movb $0, -0x2614(%ebp, %ebx)\n" /* line 827 */
        "movl -0x24(%ebp), %eax\n" /* line 828 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0xc0(%ebp), %eax\n" /* line 831 | fileName */
        "movl %eax, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "movl %edi, -0x28(%ebp)\n" /* line 832 | volumeModGroupIndex, parseBuffer */
        "xorl %edi, %edi\n" /* volumeModGroupIndex */
        "movl $0x1150568, %esi\n"
        "xorl %ebx, %ebx\n" /* fileLength */
        "jmp .Lfb9d4a_000ba56a\n"
        ".Lfb9d4a_000ba501:\n"
        "cmpb $0x7d, %dl\n" /* line 838 */
        "je .Lfb9d4a_000ba57c\n"
        "cmpl $0x20, %edi\n" /* line 841 | volumeModGroupIndex */
        "je .Lfb9d4a_000ba62e\n"
        "leal 0x1150528(%ebx), %edx\n" /* line 844 | fileLength */
        "movl %edx, -0x2634(%ebp)\n"
        "movl %eax, 4(%esp)\n" /* line 848 */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "leal -0x28(%ebp), %eax\n" /* line 850 | parseBuffer */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 851 */
        "testb %dl, %dl\n"
        "je .Lfb9d4a_000ba5fc\n"
        "addl $0x44, %esi\n"
        "addl $0x44, %ebx\n" /* fileLength */
        "cmpb $0x7d, %dl\n"
        "je .Lfb9d4a_000ba5fc\n"
        "movl %eax, (%esp)\n" /* line 858 */
        "calll atof\n"
        "fstpl -0x2630(%ebp)\n"
        "cvtsd2ss -0x2630(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%esi)\n"
        "addl $1, %edi\n" /* line 860 | volumeModGroupIndex */
        ".Lfb9d4a_000ba56a:\n"
        "leal -0x28(%ebp), %eax\n" /* line 837 | parseBuffer */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 838 */
        "testb %dl, %dl\n"
        "jne .Lfb9d4a_000ba501\n"
        ".Lfb9d4a_000ba57c:\n"
        "calll Com_EndParseSession\n" /* line 863 */
        "jmp .Lfb9d4a_000b9ef4\n"
        /* } scope */
        /* { scope 2 */
        ".Lfb9d4a_000ba586:\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 716 */
        "movsd %xmm1, 8(%esp)\n"
        "leal -0x1d4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21fcd0, (%esp)\n" /* "^1ERROR: sound alias '%s' has dist_min %g <= 0
" */
        "calll Com_Printf\n"
        "jmp .Lfb9d4a_000ba055\n"
        /* } scope */
        /* { scope 2 */
        ".Lfb9d4a_000ba5ab:\n"
        "movl -0x24(%ebp), %eax\n" /* line 811 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "leal -0xc0(%ebp), %edx\n" /* line 812 | fileName */
        "movl %edx, 8(%esp)\n"
        "movl $0x21fa60, 4(%esp)\n" /* "ERROR: "%s" does not appear to be a volumemodgroups file
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfb9d4a_000b9ef4\n"
        ".Lfb9d4a_000ba5d9:\n"
        "leal -0xc0(%ebp), %edx\n" /* line 795 | fileName */
        "movl %edx, 8(%esp)\n"
        "movl $0x21fa1c, 4(%esp)\n" /* "ERROR: Could not find '%s'
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfb9d4a_000b9ef4\n"
        ".Lfb9d4a_000ba5fc:\n"
        "calll Com_EndParseSession\n" /* line 853 */
        "movl -0x2634(%ebp), %edx\n" /* line 854 */
        "movl %edx, 0xc(%esp)\n"
        "leal -0xc0(%ebp), %edi\n" /* fileName, volumeModGroupIndex */
        "movl %edi, 8(%esp)\n" /* volumeModGroupIndex */
        "movl $0x21fb4c, 4(%esp)\n" /* "ERROR: volumemodgroups parse failure on file "%s": groupname" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfb9d4a_000b9ef4\n"
        ".Lfb9d4a_000ba62e:\n"
        "calll Com_EndParseSession\n" /* line 843 */
        "movl $0x20, 0x10(%esp)\n" /* line 844 */
        "movl $0x20, 0xc(%esp)\n"
        "leal -0xc0(%ebp), %eax\n" /* fileName */
        "movl %eax, 8(%esp)\n"
        "movl $0x21fad8, 4(%esp)\n" /* "ERROR: volumemodgroups parse failure on file "%s": groups pa" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfb9d4a_000b9ef4\n"
        /* } scope */
        /* { scope 2 */
        ".Lfb9d4a_000ba666:\n"
        "movaps %xmm2, %xmm0\n" /* line 730 */
        "jmp .Lfb9d4a_000ba336\n"
        ".Lfb9d4a_000ba66e:\n"
        "movaps %xmm2, %xmm0\n" /* line 723 */
        "jmp .Lfb9d4a_000ba30e\n"
    );
}

