/* ASM dump from: cg_effects_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame/cg_effects_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

static const const char * g_TypeName[11]; /* 0x333c80 */

static int compare_impact_files(const int *pe0, const int *pe1);
static int CG_RegisterImpactEffectsForDir(const char *dir, char * (*szEffectFile)[23]);
FxImpactTable * CG_RegisterImpactEffects(const char *mapname);

/* line 128 */
static __attribute__((naked))
int compare_impact_files(const int *pe0, const int *pe1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 128 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* line 133 | pe1 */
        "movl (%eax), %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* pe1 */
        "movl 8(%ebp), %eax\n" /* pe0 */
        "movl (%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pe0 */
        "popl %ebp\n" /* line 134 */
        "jmp stricmp\n" /* line 133 */
    );
}

/* line 145 */
static __attribute__((naked))
int CG_RegisterImpactEffectsForDir(const char *dir, char * (*szEffectFile)[23])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 145 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x406c, %esp\n"
        "movl %eax, -0x403c(%ebp)\n"
        "movl %edx, -0x4040(%ebp)\n"
        "movl %ecx, %ebx\n" /* listbuf */
        /* { scope 1: buf */
        "movl $0x10000, 0x10(%esp)\n" /* line 157 */
        "movl %ecx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x21e5ac, 4(%esp)\n" /* "csv" */
        "movl %eax, (%esp)\n"
        "calll FS_GetFileList\n"
        "movl %eax, -0x4038(%ebp)\n" /* iListCount */
        "testl %eax, %eax\n" /* line 158 */
        "je .Lf1e5382_001e5595\n"
        "cmpl $__mh_execute_header, %eax\n" /* line 161 */
        "jbe .Lf1e5382_001e55a0\n"
        "movl $__mh_execute_header, -0x4038(%ebp)\n" /* iListCount */
        ".Lf1e5382_001e53e3:\n"
        "movl %ebx, -0x404c(%ebp)\n" /* line 164 | pszErrorMsg, psz */
        "xorl %edx, %edx\n"
        "movl $0xffffffff, %esi\n" /* iFileSize */
        "xorl %ebx, %ebx\n" /* pszErrorMsg */
        "cld\n"
        ".Lf1e5382_001e53f3:\n"
        "movl -0x404c(%ebp), %eax\n" /* line 166 | psz */
        "movl %eax, -0x4020(%ebp, %edx, 4)\n"
        "movl %esi, %ecx\n" /* line 167 | iFileSize */
        "movl %eax, %edi\n"
        "movl %ebx, %eax\n" /* pszErrorMsg */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl %ecx, -0x404c(%ebp)\n" /* psz */
        "addl $1, %edx\n" /* line 164 */
        "cmpl %edx, -0x4038(%ebp)\n" /* iListCount */
        "jne .Lf1e5382_001e53f3\n"
        ".Lf1e5382_001e541b:\n"
        "movl $compare_impact_files, 0xc(%esp)\n" /* line 171 */
        "movl $4, 8(%esp)\n"
        "movl -0x4038(%ebp), %edx\n" /* iListCount */
        "movl %edx, 4(%esp)\n"
        "leal -0x4020(%ebp), %eax\n" /* pszFiles */
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl -0x4038(%ebp), %edx\n" /* line 173 | iListCount */
        "testl %edx, %edx\n"
        "jle .Lf1e5382_001e5595\n"
        "movl $0, -0x402c(%ebp)\n"
        "movl -0x402c(%ebp), %ecx\n"
        ".Lf1e5382_001e5461:\n"
        "movl -0x4020(%ebp, %ecx, 4), %eax\n" /* line 175 */
        "movl %eax, 8(%esp)\n"
        "movl -0x403c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x216e18, (%esp)\n" /* "%s/%s" */
        "calll va\n"
        "movl %eax, -0x4030(%ebp)\n"
        "movl $0, 8(%esp)\n" /* line 176 */
        "leal -0x1c(%ebp), %edx\n" /* f */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %esi\n" /* iFileSize */
        "testl %eax, %eax\n" /* line 177 */
        "js .Lf1e5382_001e55b3\n"
        "leal 1(%eax), %eax\n" /* line 182 */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %ebx\n" /* pszErrorMsg */
        "movl -0x1c(%ebp), %eax\n" /* line 183 | f */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* iFileSize */
        "movl %ebx, (%esp)\n" /* pszErrorMsg */
        "calll FS_Read\n"
        "movl -0x1c(%ebp), %eax\n" /* line 184 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movb $0, (%ebx, %esi)\n" /* line 185 | pszErrorMsg */
        "movl -0x4030(%ebp), %ecx\n" /* line 186 */
        "movl %ecx, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "movl $1, (%esp)\n" /* line 187 */
        "calll Com_SetCSV\n"
        "movl %ebx, -0x20(%ebp)\n" /* pszErrorMsg, buf */
        /* { scope 2: iSurfaceType */
        /* { scope 3 */
        ".Lf1e5382_001e54f5:\n"
        "leal -0x20(%ebp), %eax\n" /* line 82 | buf */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %edi\n"
        "movl -0x20(%ebp), %eax\n" /* line 83 | buf */
        "testl %eax, %eax\n"
        "je .Lf1e5382_001e5533\n"
        ".Lf1e5382_001e5509:\n"
        "movzbl (%edi), %eax\n" /* line 86 */
        "testb %al, %al\n"
        "je .Lf1e5382_001e5514\n"
        "cmpb $0x23, %al\n"
        "jne .Lf1e5382_001e5537\n"
        ".Lf1e5382_001e5514:\n"
        "leal -0x20(%ebp), %edx\n" /* line 88 | buf */
        "movl %edx, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "leal -0x20(%ebp), %eax\n" /* line 82 | buf */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %edi\n"
        "movl -0x20(%ebp), %eax\n" /* line 83 | buf */
        "testl %eax, %eax\n"
        "jne .Lf1e5382_001e5509\n"
        ".Lf1e5382_001e5533:\n"
        "xorl %ebx, %ebx\n" /* line 118 | token */
        "jmp .Lf1e5382_001e5577\n"
        ".Lf1e5382_001e5537:\n"
        "xorl %esi, %esi\n" /* line 89 | iEffectType */
        "movl $g_TypeName, %ebx\n" /* token */
        ".Lf1e5382_001e553e:\n"
        "movl %edi, 4(%esp)\n" /* line 95 */
        "movl (%ebx), %eax\n" /* token */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1e5382_001e55cf\n"
        "addl $1, %esi\n" /* line 93 | iEffectType */
        "addl $4, %ebx\n" /* token */
        "cmpl $0xb, %esi\n" /* iEffectType */
        "jne .Lf1e5382_001e553e\n"
        "movl -0x4030(%ebp), %ecx\n" /* line 99 */
        "movl %ecx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2b85c0, (%esp)\n" /* "unknown effect type '%s' in first column of file '%s'" */
        "calll va\n"
        "movl %eax, %ebx\n" /* token */
        /* } scope */
        /* } scope */
        ".Lf1e5382_001e5577:\n"
        "calll Com_EndParseSession\n" /* line 191 */
        "calll Hunk_ClearTempMemoryHigh\n" /* line 193 */
        "testl %ebx, %ebx\n" /* line 195 | pszErrorMsg */
        "je .Lf1e5382_001e55b3\n"
        "movl %ebx, 4(%esp)\n" /* line 197 | pszErrorMsg */
        "movl $0x2b86b4, (%esp)\n" /* "^1ERROR: %s" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf1e5382_001e5595:\n"
        "addl $0x406c, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: buf */
        ".Lf1e5382_001e55a0:\n"
        "movl -0x4038(%ebp), %ecx\n" /* line 164 | iListCount */
        "testl %ecx, %ecx\n"
        "jle .Lf1e5382_001e541b\n"
        "jmp .Lf1e5382_001e53e3\n"
        ".Lf1e5382_001e55b3:\n"
        "addl $1, -0x402c(%ebp)\n" /* line 173 */
        "movl -0x402c(%ebp), %edx\n"
        "cmpl %edx, -0x4038(%ebp)\n" /* iListCount */
        "je .Lf1e5382_001e5595\n"
        "movl %edx, %ecx\n"
        "jmp .Lf1e5382_001e5461\n"
        /* { scope 2: iSurfaceType */
        /* { scope 3 */
        ".Lf1e5382_001e55cf:\n"
        "leal -0x20(%ebp), %eax\n" /* line 102 | buf */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "cmpb $0, (%eax)\n" /* line 103 */
        "je .Lf1e5382_001e56a5\n"
        "movl %eax, (%esp)\n" /* line 105 */
        "calll Com_SurfaceTypeFromName\n"
        "movl %eax, -0x4034(%ebp)\n" /* iSurfaceType */
        "testl %eax, %eax\n" /* line 106 */
        "js .Lf1e5382_001e565b\n"
        "leal -0x20(%ebp), %edx\n" /* line 110 | buf */
        "movl %edx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "cld\n" /* line 111 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "cmpl $0x3f, %eax\n" /* line 112 */
        "jg .Lf1e5382_001e567c\n"
        "movl %ecx, (%esp)\n" /* line 114 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "leal (%esi, %esi, 2), %edx\n" /* iEffectType */
        "shll $3, %edx\n"
        "subl %esi, %edx\n" /* iEffectType */
        "movl -0x4034(%ebp), %ecx\n" /* iSurfaceType */
        "shll $2, %ecx\n"
        "leal (%ecx, %edx, 4), %edx\n"
        "movl -0x4040(%ebp), %ecx\n"
        "movl %eax, (%edx, %ecx)\n"
        "movl %ebx, 4(%esp)\n" /* line 115 | token */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "leal -0x20(%ebp), %eax\n" /* line 118 | buf */
        "movl %eax, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "jmp .Lf1e5382_001e54f5\n"
        ".Lf1e5382_001e565b:\n"
        "movl -0x4030(%ebp), %ecx\n" /* line 107 */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* token */
        "movl $0x2b862c, (%esp)\n" /* "unknown surface type '%s' in second column of file '%s'" */
        "calll va\n"
        "movl %eax, %ebx\n" /* token */
        "jmp .Lf1e5382_001e5577\n"
        ".Lf1e5382_001e567c:\n"
        "movl $0x3f, 0xc(%esp)\n" /* line 113 */
        "movl -0x4030(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* token */
        "movl $0x2b8664, (%esp)\n" /* "effect filename '%s' in third column of file '%s' is longer " */
        "calll va\n"
        "movl %eax, %ebx\n" /* token */
        "jmp .Lf1e5382_001e5577\n"
        ".Lf1e5382_001e56a5:\n"
        "movl -0x4030(%ebp), %eax\n" /* line 104 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b85f8, (%esp)\n" /* "missing surface type in second column of file '%s'" */
        "calll va\n"
        "movl %eax, %ebx\n" /* token */
        "jmp .Lf1e5382_001e5577\n"
    );
}

/* line 209 */
__attribute__((naked))
FxImpactTable * CG_RegisterImpactEffects(const char *mapname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 209 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* mapname */
        /* { scope 1: pszTypeName */
        "movl $0x10000, (%esp)\n" /* line 220 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, %esi\n"
        "leal -0x44c(%ebp), %edi\n" /* line 222 | szEffectFile */
        "movl $0x3f4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memset\n"
        "movl %esi, %ecx\n" /* line 224 */
        "movl %edi, %edx\n"
        "movl $0x2b86c0, %eax\n" /* "fx" */
        "calll CG_RegisterImpactEffectsForDir\n"
        "testl %ebx, %ebx\n" /* line 226 | mapname */
        "je .Lf1e56c2_001e5739\n"
        "movl %ebx, 0xc(%esp)\n" /* line 228 | mapname */
        "movl $0x2b86c4, 8(%esp)\n" /* "fx/maps/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapdir, mapname */
        "movl %ebx, (%esp)\n" /* mapname */
        "calll Com_sprintf\n"
        "movl %esi, %ecx\n" /* line 229 */
        "movl %edi, %edx\n"
        "movl %ebx, %eax\n" /* mapname */
        "calll CG_RegisterImpactEffectsForDir\n"
        ".Lf1e56c2_001e5739:\n"
        "movl $4, 4(%esp)\n" /* line 232 */
        "movl $8, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, -0x46c(%ebp)\n" /* fx */
        "movl $4, 4(%esp)\n" /* line 235 */
        "movl $0x3f4, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl -0x46c(%ebp), %edx\n" /* fx */
        "movl %eax, 4(%edx)\n"
        "movl $0, -0x474(%ebp)\n" /* i */
        "movl $0, -0x470(%ebp)\n" /* iBadCount */
        "movl $0, -0x460(%ebp)\n"
        "movl $g_TypeName, -0x45c(%ebp)\n"
        ".Lf1e56c2_001e5798:\n"
        "movl -0x460(%ebp), %esi\n" /* line 240 | fx */
        "movl -0x46c(%ebp), %eax\n" /* fx */
        "addl 4(%eax), %esi\n" /* fx */
        "movl -0x45c(%ebp), %edx\n"
        "movl (%edx), %edx\n"
        "movl %edx, -0x468(%ebp)\n" /* pszTypeName */
        "movl $0, -0x464(%ebp)\n" /* iBadCount */
        "xorl %ebx, %ebx\n" /* mapname */
        "jmp .Lf1e56c2_001e57d2\n"
        /* { scope 2: iBadCount */
        /* { scope 3 */
        ".Lf1e56c2_001e57c3:\n"
        "movl $0, (%esi, %ebx, 4)\n" /* line 54 */
        ".Lf1e56c2_001e57ca:\n"
        "addl $1, %ebx\n" /* line 44 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "je .Lf1e56c2_001e57f1\n"
        ".Lf1e56c2_001e57d2:\n"
        "movl (%edi, %ebx, 4), %eax\n" /* line 46 */
        "testl %eax, %eax\n"
        "je .Lf1e56c2_001e584e\n"
        "cmpb $0, (%eax)\n" /* line 52 */
        "je .Lf1e56c2_001e57c3\n"
        "movl %eax, (%esp)\n" /* line 58 */
        "calll FX_RegisterEffect\n"
        "movl %eax, (%esi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 44 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf1e56c2_001e57d2\n"
        /* } scope */
        /* } scope */
        ".Lf1e56c2_001e57f1:\n"
        "movl -0x464(%ebp), %edx\n" /* line 240 | iBadCount */
        "addl %edx, -0x470(%ebp)\n" /* iBadCount */
        "addl $1, -0x474(%ebp)\n" /* line 239 | i */
        "addl $0x5c, %edi\n"
        "addl $0x5c, -0x460(%ebp)\n"
        "addl $4, -0x45c(%ebp)\n"
        "cmpl $0xb, -0x474(%ebp)\n" /* i */
        "jne .Lf1e56c2_001e5798\n"
        "movl -0x470(%ebp), %ebx\n" /* line 241 | iBadCount, mapname */
        "testl %ebx, %ebx\n" /* mapname */
        "jne .Lf1e56c2_001e5883\n"
        "movl -0x46c(%ebp), %edx\n" /* line 247 | fx */
        "movl $0x2157b8, (%edx)\n"
        "calll Hunk_ClearTempMemory\n" /* line 249 */
        /* } scope */
        "movl -0x46c(%ebp), %eax\n" /* line 251 | fx */
        "addl $0x47c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pszTypeName */
        /* { scope 2: iBadCount */
        /* { scope 3 */
        ".Lf1e56c2_001e584e:\n"
        "movl %ebx, (%esp)\n" /* line 48 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x468(%ebp), %eax\n" /* pszTypeName */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b86d0, (%esp)\n" /* "no entry for effect type '%s' on surface type '%s'
" */
        "calll Com_Printf\n"
        "addl $1, -0x464(%ebp)\n" /* line 49 | iBadCount */
        "movl $0, (%esi, %ebx, 4)\n" /* line 50 */
        "jmp .Lf1e56c2_001e57ca\n"
        /* } scope */
        /* } scope */
        ".Lf1e56c2_001e5883:\n"
        "movl -0x470(%ebp), %eax\n" /* line 243 | iBadCount */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8704, (%esp)\n" /* "^1ERROR: %i missing entries in effect CSV files (see console" */
        "calll Com_Printf\n"
        "movl $0, -0x46c(%ebp)\n" /* fx */
        /* } scope */
        "movl -0x46c(%ebp), %eax\n" /* line 251 | fx */
        "addl $0x47c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

