/* ASM dump from: com_sndalias_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_sndalias_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern struct saLoadObjGlob_type saLoadObjGlob; /* 0x0 */
static char szReference[1024]; /* szReference */
extern const char str_00216cd8[];
extern const char str_002182a8[];
extern const char str_002194b4[];
extern const char str_0021eaec[];
extern const char str_0021eaf8[];
extern const char str_0021eb00[];
extern const char str_0021eb0c[];
extern const char str_0021eb14[];
extern const char str_0021eb1c[];
extern const char str_0021eb24[];
extern const char str_0021eb30[];
extern const char str_0021eb3c[];
extern const char str_0021eb48[];
extern const char str_0021eb54[];
extern const char str_0021eb5c[];
extern const char str_0021eb64[];
extern const char str_0021eb6c[];
extern const char str_0021eb78[];
extern const char str_0021eb84[];
extern const char str_0021eb90[];
extern const char str_0021eba4[];
extern const char str_0021ebb8[];
extern const char str_0021ebc4[];
extern const char str_0021ebd0[];
extern const char str_0021ebd8[];
extern const char str_0021ebe8[];
extern const char str_0021ebf0[];
extern const char str_0021ebf8[];
extern const char str_0021ec00[];
extern const char str_0021ec08[];
extern const char str_0021ec10[];
extern const char str_0021ec18[];
extern const char str_0021ec20[];
extern const char str_0021ec28[];

__attribute__((used, packed, aligned(4)))
UInt32 g_pszSndAliasKeyNames_storage[24] __asm__("g_pszSndAliasKeyNames") = {
    0,
    (UInt32)str_002194b4,
    (UInt32)str_0021eaec,
    (UInt32)str_0021eaf8,
    (UInt32)str_0021eb00,
    (UInt32)str_0021eb0c,
    (UInt32)str_0021eb14,
    (UInt32)str_0021eb1c,
    (UInt32)str_0021eb24,
    (UInt32)str_0021eb30,
    (UInt32)str_0021eb3c,
    (UInt32)str_0021eb48,
    (UInt32)str_0021eb54,
    (UInt32)str_0021eb5c,
    (UInt32)str_0021eb64,
    (UInt32)str_0021eb6c,
    (UInt32)str_0021eb78,
    (UInt32)str_0021eb84,
    (UInt32)str_0021eb90,
    (UInt32)str_0021eba4,
    (UInt32)str_0021ebb8,
    (UInt32)str_0021ebc4,
    (UInt32)str_0021ebd0,
    (UInt32)str_0021ebd8,
}; /* 0x3128bc */
__attribute__((used, packed, aligned(4)))
UInt32 g_pszChannelNames_storage[16] __asm__("g_pszChannelNames") = {
    (UInt32)str_0021ebe8,
    (UInt32)str_0021ebf0,
    (UInt32)str_00216cd8,
    (UInt32)str_0021ebf8,
    (UInt32)str_0021ec00,
    (UInt32)str_0021ec08,
    (UInt32)str_0021ec10,
    (UInt32)str_0021ec18,
    (UInt32)str_0021ec20,
    (UInt32)str_0021ec28,
    (UInt32)str_002182a8,
    0,
    0,
    0,
    0,
    0,
}; /* 0x31291c */

#define g_pszSndAliasKeyNames ((const char * const *)g_pszSndAliasKeyNames_storage)
#define g_pszChannelNames ((const char * const *)g_pszChannelNames_storage)

extern int I_stricmp(const char *s0, const char *s1);
extern void Com_Printf(const char *fmt, ...);

static snd_alias_build_t * Com_SortTempSoundAliases_r_impl(snd_alias_build_t *pAliasList, int *piAliasCount, int (*test)(snd_alias_build_t *, snd_alias_build_t *), int isRemovingDups);

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
    *(int *)((char *)&saLoadObjGlob + 4) = 0;
}

/* line 873 */
static void Com_RefreshVolumeModGroups_f(void)
{
    *(byte *)((char *)&saLoadObjGlob + 2184) = 0;
}

/* line 1013 */
static int AliasNameCompare(snd_alias_build_t *pFrontList, snd_alias_build_t *pBackList)
{
    return I_stricmp((const char *)pFrontList + 0x40, (const char *)pBackList + 0x40);
}

/* line 1024 */
/* Recursive merge sort for sound alias linked lists.
 * Splits the list in half, recursively sorts both halves, then merges.
 * When isRemovingDups is set, duplicates (same test() result AND same iSequence)
 * are resolved by I_stricmp on szSourceFile: true duplicates (same file) print
 * an error and both are dropped; otherwise the lesser-sorted-file entry is dropped.
 */
static snd_alias_build_t * Com_SortTempSoundAliases_r_impl(snd_alias_build_t *pAliasList, int *piAliasCount, int (*test)(snd_alias_build_t *, snd_alias_build_t *), int isRemovingDups)
{
    snd_alias_build_t *pSplitPoint;
    snd_alias_build_t *pFrontList;
    snd_alias_build_t *pBackList;
    snd_alias_build_t *result;
    snd_alias_build_t **ppListPos;
    int iFrontCount;
    int iBackCount;
    int count;
    int cmp;
    int i;

    count = *piAliasCount;

    /* Base case: single element */
    if (count == 1)
    {
        pAliasList->pNext = 0;
        return pAliasList;
    }

    /* Split the list in half */
    iFrontCount = count / 2;
    iBackCount = count - iFrontCount;

    /* Walk to the split point */
    pSplitPoint = pAliasList;
    for (i = 0; i < iFrontCount; i++)
    {
        pSplitPoint = (snd_alias_build_t *)(uintptr_t)pSplitPoint->pNext;
    }

    /* Recursively sort both halves */
    pFrontList = Com_SortTempSoundAliases_r_impl(pAliasList, &iFrontCount, test, isRemovingDups);
    pBackList = Com_SortTempSoundAliases_r_impl(pSplitPoint, &iBackCount, test, isRemovingDups);

    /* Merge the two sorted halves */
    *piAliasCount = 0;
    result = NULL;
    ppListPos = &result;

    for (;;)
    {
        if (isRemovingDups)
        {
            /* Duplicate-removing merge path */
            if (iFrontCount <= 0)
                goto front_exhausted;
            if (iBackCount <= 0)
                goto back_exhausted;

            cmp = test(pFrontList, pBackList);

            if (cmp == 0)
            {
                /* Same sort key -- check iSequence tie-break */
                cmp = pFrontList->iSequence - pBackList->iSequence;

                if (cmp == 0)
                {
                    /* Same sort key AND same iSequence -- compare source files */
                    cmp = I_stricmp((const char *)pFrontList, (const char *)pBackList);

                    if (cmp == 0)
                    {
                        /* True duplicate from same file -- print error, skip both */
                        Com_Printf(str_0021ec34, (const char *)pFrontList, (const char *)pFrontList + 0x40);
                        pFrontList = (snd_alias_build_t *)(uintptr_t)pFrontList->pNext;
                        iFrontCount--;
                        pBackList = (snd_alias_build_t *)(uintptr_t)pBackList->pNext;
                        iBackCount--;
                        continue;
                    }
                    else if (cmp < 0)
                    {
                        /* Different files, front sorts first -- drop front (keep back) */
                        pFrontList = (snd_alias_build_t *)(uintptr_t)pFrontList->pNext;
                        iFrontCount--;
                        continue;
                    }
                    else
                    {
                        /* Different files, back sorts first -- drop back (keep front) */
                        pBackList = (snd_alias_build_t *)(uintptr_t)pBackList->pNext;
                        iBackCount--;
                        continue;
                    }
                }
            }

            /* Non-duplicate: pick the lesser element */
            if (cmp > 0)
            {
                *ppListPos = pBackList;
                pBackList = (snd_alias_build_t *)(uintptr_t)pBackList->pNext;
                iBackCount--;
            }
            else
            {
                *ppListPos = pFrontList;
                pFrontList = (snd_alias_build_t *)(uintptr_t)pFrontList->pNext;
                iFrontCount--;
            }
        }
        else
        {
            /* Simple merge path (no duplicate removal) */
            if (iFrontCount <= 0)
                goto front_exhausted;
            if (iBackCount <= 0)
                goto back_exhausted;

            cmp = test(pFrontList, pBackList);

            if (cmp > 0)
            {
                *ppListPos = pBackList;
                pBackList = (snd_alias_build_t *)(uintptr_t)pBackList->pNext;
                iBackCount--;
            }
            else
            {
                *ppListPos = pFrontList;
                pFrontList = (snd_alias_build_t *)(uintptr_t)pFrontList->pNext;
                iFrontCount--;
            }
        }

        (*piAliasCount)++;
        ppListPos = (snd_alias_build_t **)&((*ppListPos)->pNext);
    }

back_exhausted:
    /* Front list has remaining elements */
    *ppListPos = pFrontList;
    *piAliasCount += iFrontCount;
    return result;

front_exhausted:
    /* Back list has remaining elements */
    *ppListPos = pBackList;
    *piAliasCount += iBackCount;
    return result;
}

static snd_alias_build_t * Com_SortTempSoundAliases_r(snd_alias_build_t *pAliasList, int *piAliasCount, int (*test)(), int isRemovingDups)
{
    return Com_SortTempSoundAliases_r_impl(pAliasList, piAliasCount, (int (*)(snd_alias_build_t *, snd_alias_build_t *))test, isRemovingDups);
}
