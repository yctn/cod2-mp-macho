/* ASM dump from: stringed_ingame.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/stringed/stringed_ingame.cpp */

#include "common_types.h"
#include "imports.h"
#include <ctype.h>

extern CStringEdPackage *TheStringPackage; /* 0x0 */
static char sString[64]; /* sString */
static char sString_00482f80[64]; /* sString */
static char sTemp[64]; /* sTemp */

qboolean CStringEdPackage_ReadLine(const CStringEdPackage * _this, const char * *psParsePos, char *psDest);
double CStringEdPackage_SetupNewFileParse(const CStringEdPackage * _this, const char *psFileName);
static const char * SE_GetFoundFile(LocalizeString *strResult);
LocalizeString CStringEdPackage_ConvertCRLiterals_Read(const CStringEdPackage * _this, LocalizeString *string);
LocalizeString CStringEdPackage_InsideQuotes(const CStringEdPackage * _this, const char *psLine);
double CStringEdPackage_AddEntry(const CStringEdPackage * _this, const char *psLocalReference);
double CStringEdPackage_SetString(const CStringEdPackage * _this, const char *psLocalReference, const char *psNewString, qboolean bSentenceIsEnglish);
const char * CStringEdPackage_ParseLine(const CStringEdPackage * _this, const char *psLine, int forceEnglish);
const char * SE_Load(const char *psFileName, int forceEnglish);
const char * SE_GetString(const char *psPackageAndStringReference);
double CStringEdPackage_Clear(const CStringEdPackage * _this);
const char * SE_LoadLanguage(int forceEnglish);
double SE_Init(void);
double SE_ShutDown(void);
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE11lower_boundERS1_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_lower_bound */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE4findERS1_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_find */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE9_M_insertEPSt18_Rb_tree_node_baseSA_RKS2_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >__M_insert */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE13insert_uniqueERKS2_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_insert_unique */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE13insert_uniqueESt17_Rb_tree_iteratorIS2_ERKS2_(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >_insert_unique */
void ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E(void); /* std__Rb_tree<std_basic_string<char, std_char_traits<char>, std_allocator<char> >, std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std__Select1st<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > >, std_less<std_basic_string<char, std_char_traits<char>, std_allocator<char> > >, std_allocator<std_pair<std_basic_string<char, std_char_traits<char>, std_allocator<char> > const, std_basic_string<char, std_char_traits<char>, std_allocator<char> > > > >__M_erase */

/* line 474 */
qboolean CStringEdPackage_ReadLine(const CStringEdPackage * _this, const char * *psParsePos, char *psDest) {
    const char *p = *psParsePos;
    const char *nl;
    int len, i;

    if (!*p)
        return 0;

    nl = strchr(p, '\n');
    if (nl) {
        int charsToCopy = nl - p;
        strncpy(psDest, p, charsToCopy);
        psDest[charsToCopy] = '\0';
        *psParsePos = p + charsToCopy;
        /* skip newline-like characters */
        while (**psParsePos && strchr((const char *)"\r\n", **psParsePos)) {
            (*psParsePos)++;
        }
    } else {
        strcpy(psDest, p);
        *psParsePos = p + strlen(p);
    }

    if (!psDest[0])
        return 1;

    /* strip trailing whitespace */
    len = strlen(psDest);
    for (i = len - 2; i >= 0; i--) {
        if (!isspace((unsigned char)psDest[i]))
            break;
        psDest[i] = '\0';
    }

    /* strip // comments respecting double-quote escaping */
    {
        char *s = psDest;
        for (;;) {
            char *comment = strstr(s, (const char *)"//");
            int quoteCount = 0;
            if (!comment)
                return 1;

            /* count double quotes before the comment */
            for (i = 0; i < (int)(comment - s); i++) {
                if (s[i] == '"')
                    quoteCount++;
            }

            if (quoteCount & 1) {
                /* odd number of quotes means // is inside a string */
                s = comment + 1;
                continue;
            }

            *comment = '\0';
            if (!*s)
                return 1;

            /* strip trailing whitespace after removing comment */
            len = strlen(s);
            for (i = len - 2; i >= 0; i--) {
                if (!isspace((unsigned char)s[i]))
                    break;
                s[i] = '\0';
            }
            return 1;
        }
    }
}

/* line 298 */
double CStringEdPackage_SetupNewFileParse(const CStringEdPackage * _this, const char *psFileName) { return 0.0f; }
