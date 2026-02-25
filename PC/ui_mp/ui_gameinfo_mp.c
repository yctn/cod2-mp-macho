/* ASM dump from: ui_gameinfo_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui_mp/ui_gameinfo_mp.cpp */

#include "common_types.h"
#include "imports.h"

static int ui_numArenas; /* 0xf13280 */
static char * ui_arenaInfos[64]; /* 0xf13180 */

int UI_ParseInfos(const char *buf, int max, char * *infos);
inflate_blocks_statef UI_LoadArenas(void);

/* line 43 */
__attribute__((naked))
int UI_ParseInfos(const char *buf, int max, char * *infos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x83c, %esp\n"
        "movl $0, -0x81c(%ebp)\n" /* count */
        /* { scope 1 */
        ".Lf17ea04_0017ea1a:\n"
        "leal 8(%ebp), %eax\n" /* line 54 | buf */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "cmpb $0, (%eax)\n" /* line 55 */
        "je .Lf17ea04_0017eb9a\n"
        ".Lf17ea04_0017ea2e:\n"
        "movl $0x21e50c, %edi\n" /* line 59 */
        "movl $2, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf17ea04_0017ea4e\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf17ea04_0017ea4e:\n"
        "testl %edx, %edx\n"
        "jne .Lf17ea04_0017ebab\n"
        "movl -0x81c(%ebp), %edx\n" /* line 65 | count */
        "cmpl %edx, 0xc(%ebp)\n" /* max */
        "je .Lf17ea04_0017ebc8\n"
        "movb $0, -0x818(%ebp)\n" /* line 71 | info */
        "jmp .Lf17ea04_0017eae6\n"
        ".Lf17ea04_0017ea6e:\n"
        "movl $0x21e508, %edi\n" /* line 80 */
        "movl $2, %ebx\n"
        "cld\n"
        "movl %eax, %esi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf17ea04_0017ea90\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf17ea04_0017ea90:\n"
        "testl %edx, %edx\n"
        "je .Lf17ea04_0017eb0c\n"
        "movl $0x400, 8(%esp)\n" /* line 84 */
        "movl -0x82c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* key */
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "leal 8(%ebp), %ecx\n" /* line 86 | buf */
        "movl %ecx, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "cmpb $0, (%eax)\n" /* line 87 */
        "movl $0x2ae950, %edx\n" /* "<NULL>" */
        "cmovel %edx, %eax\n"
        "movl %eax, 8(%esp)\n" /* line 91 */
        "leal -0x418(%ebp), %eax\n" /* key */
        "movl %eax, 4(%esp)\n"
        "leal -0x818(%ebp), %edx\n" /* info */
        "movl %edx, (%esp)\n"
        "calll Info_SetValueForKey\n"
        ".Lf17ea04_0017eae6:\n"
        "leal 8(%ebp), %ecx\n" /* line 74 | buf */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x82c(%ebp)\n"
        "cmpb $0, (%eax)\n" /* line 75 */
        "jne .Lf17ea04_0017ea6e\n"
        "movl $0x2ae930, (%esp)\n" /* line 77 */
        "calll Com_Printf\n"
        ".Lf17ea04_0017eb0c:\n"
        "cld\n" /* line 94 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x818(%ebp), %edi\n" /* info */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "subl $1, %ebx\n"
        "movl $0x40, 4(%esp)\n"
        "movl $0x215a64, (%esp)\n" /* "%d" */
        "calll va\n"
        "movl %eax, %edi\n"
        "movl $1, 4(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal 5(%ecx, %ebx), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll UI_Alloc\n"
        "movl -0x81c(%ebp), %edx\n" /* count */
        "movl 0x10(%ebp), %ecx\n" /* infos */
        "movl %eax, (%ecx, %edx, 4)\n"
        "testl %eax, %eax\n" /* line 95 */
        "je .Lf17ea04_0017ea1a\n"
        "leal -0x818(%ebp), %edx\n" /* line 97 | info */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "addl $1, -0x81c(%ebp)\n" /* line 98 | count */
        "leal 8(%ebp), %eax\n" /* line 54 | buf */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "cmpb $0, (%eax)\n" /* line 55 */
        "jne .Lf17ea04_0017ea2e\n"
        /* } scope */
        ".Lf17ea04_0017eb9a:\n"
        "movl -0x81c(%ebp), %eax\n" /* line 102 | count */
        "addl $0x83c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17ea04_0017ebab:\n"
        "movl $0x2ae904, (%esp)\n" /* line 61 */
        "calll Com_Printf\n"
        /* } scope */
        "movl -0x81c(%ebp), %eax\n" /* line 102 | count */
        "addl $0x83c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17ea04_0017ebc8:\n"
        "movl $0x2ae91c, (%esp)\n" /* line 67 */
        "calll Com_Printf\n"
        /* } scope */
        "movl -0x81c(%ebp), %eax\n" /* line 102 | count */
        "addl $0x83c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 159 */
__attribute__((naked))
inflate_blocks_statef UI_LoadArenas(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 159 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x24cc, %esp\n"
        /* { scope 1: f, buf */
        "movl $0, ui_numArenas\n" /* line 177 */
        "movl 0x195f5d8, %eax\n" /* line 178 */
        "movl $0, 0x1350(%eax)\n"
        "movl $0x400, 0x10(%esp)\n" /* line 182 */
        "leal -0x4a0(%ebp), %edi\n" /* dirlist, dirlen */
        "movl %edi, 0xc(%esp)\n" /* dirlen */
        "movl $0, 8(%esp)\n"
        "movl $0x218e6c, 4(%esp)\n" /* "arena" */
        "movl $0x21cc10, (%esp)\n" /* "mp" */
        "calll FS_GetFileList\n"
        "movl %eax, -0x24b0(%ebp)\n" /* numdirs */
        "testl %eax, %eax\n" /* line 184 */
        "jg .Lf17ebe6_0017eedc\n"
        ".Lf17ebe6_0017ec47:\n"
        "movl ui_numArenas, %ecx\n" /* line 196 */
        "testl %ecx, %ecx\n"
        "jg .Lf17ebe6_0017ec5c\n"
        /* } scope */
        ".Lf17ebe6_0017ec51:\n"
        "addl $0x24cc, %esp\n" /* line 246 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: f, buf */
        ".Lf17ebe6_0017ec5c:\n"
        "movl $0, -0x24b4(%ebp)\n" /* line 196 | n */
        "movl $ui_arenaInfos, -0x24ac(%ebp)\n"
        "jmp .Lf17ebe6_0017ecc7\n"
        ".Lf17ebe6_0017ec72:\n"
        "movl 0x195f5d8, %edx\n" /* line 238 */
        "movl 0x1350(%edx), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl 0x195f5d8, %ecx\n"
        "movl $0xffffffff, 0x1368(%ecx, %edx, 4)\n"
        "movl %ecx, %edx\n"
        ".Lf17ebe6_0017ec97:\n"
        "movl 0x1350(%edx), %eax\n" /* line 242 */
        "addl $1, %eax\n"
        "movl %eax, 0x1350(%edx)\n"
        "cmpl $0x7f, %eax\n" /* line 243 */
        "jg .Lf17ebe6_0017ec51\n"
        "addl $1, -0x24b4(%ebp)\n" /* line 196 | n */
        "addl $4, -0x24ac(%ebp)\n"
        "movl -0x24b4(%ebp), %ecx\n" /* n */
        "cmpl %ecx, ui_numArenas\n"
        "jle .Lf17ebe6_0017ec51\n"
        ".Lf17ebe6_0017ecc7:\n"
        "movl 0x195f5d8, %eax\n" /* line 200 */
        "movl 0x1350(%eax), %ebx\n" /* len */
        "movl $0x2ac808, 4(%esp)\n" /* "map" */
        "movl -0x24ac(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "leal (%ebx, %ebx, 4), %edx\n" /* len */
        "leal (%ebx, %edx, 8), %edx\n" /* len */
        "movl 0x195f5d8, %ecx\n"
        "movl %eax, 0x1358(%ecx, %edx, 4)\n"
        "movl 0x1350(%ecx), %ebx\n" /* line 201 | len */
        "movl $0x2ae9a0, 4(%esp)\n" /* "longname" */
        "movl -0x24ac(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "leal (%ebx, %ebx, 4), %edx\n" /* len */
        "leal (%ebx, %edx, 8), %edx\n" /* len */
        "movl 0x195f5d8, %ecx\n"
        "movl %eax, 0x1354(%ecx, %edx, 4)\n"
        "movl 0x1350(%ecx), %eax\n" /* line 203 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl $0xffffffff, 0x136c(%ecx, %edx, 4)\n"
        "movl 0x1350(%ecx), %eax\n" /* line 204 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl $0, 0x13f0(%ecx, %edx, 4)\n"
        "movl 0x1350(%ecx), %eax\n" /* line 205 */
        "leal (%eax, %eax, 4), %ebx\n" /* len */
        "leal (%eax, %ebx, 8), %ebx\n" /* len */
        "leal (%ecx, %ebx, 4), %ebx\n" /* len */
        "movl 0x1358(%ebx), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl $0x2ae9ac, (%esp)\n" /* "loadscreen_%s" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, 0x135c(%ebx)\n" /* len */
        "movl 0x195f5d8, %edx\n" /* line 206 */
        "movl 0x1350(%edx), %eax\n"
        "movl $3, 4(%esp)\n"
        "leal (%eax, %eax, 4), %ebx\n" /* len */
        "leal (%eax, %ebx, 8), %ebx\n" /* len */
        "leal (%edx, %ebx, 4), %ebx\n" /* len */
        "movl 0x135c(%ebx), %eax\n" /* len */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x13f0(%ebx)\n" /* len */
        "movl $0x2aa884, 4(%esp)\n" /* line 210 */
        "movl -0x24ac(%ebp), %ecx\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, %ebx\n" /* len */
        "testl %eax, %eax\n" /* line 211 */
        "je .Lf17ebe6_0017ec72\n"
        "cmpb $0, (%eax)\n"
        "je .Lf17ebe6_0017ec72\n"
        "movl 0x195f5d8, %edx\n" /* line 214 */
        "movl 0x1350(%edx), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl 0x195f5d8, %ecx\n"
        "movl $0, 0x1368(%ecx, %edx, 4)\n"
        "movl 0x1350(%ecx), %eax\n" /* line 217 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl 0x1358(%ecx, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2ae9bc, (%esp)\n" /* ".arena files : %s" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 218 | len, pszText */
        ".Lf17ebe6_0017ee4c:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 221 | pszText */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* dirptr */
        "testl %eax, %eax\n" /* line 222 */
        "je .Lf17ebe6_0017eecc\n"
        "cmpb $0, (%eax)\n"
        "je .Lf17ebe6_0017eecc\n"
        "movl 0x195f5d8, %eax\n" /* line 226 */
        "movl 0x1148(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf17ebe6_0017ee4c\n"
        "xorl %ebx, %ebx\n" /* len */
        "movl %eax, %edi\n" /* dirlen */
        "jmp .Lf17ebe6_0017eeaf\n"
        ".Lf17ebe6_0017ee77:\n"
        "movl 0x195f5d8, %edx\n" /* line 229 */
        "movl 0x1350(%edx), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl $1, %eax\n"
        "movl %ebx, %ecx\n" /* len */
        "shll %cl, %eax\n"
        "movl 0x195f5d8, %ecx\n"
        "orl %eax, 0x1368(%ecx, %edx, 4)\n"
        "movl %ecx, %eax\n"
        ".Lf17ebe6_0017eea1:\n"
        "addl $1, %ebx\n" /* line 226 | len */
        "addl $8, %edi\n" /* dirlen */
        "cmpl 0x1148(%eax), %ebx\n" /* len */
        "jge .Lf17ebe6_0017ee4c\n"
        ".Lf17ebe6_0017eeaf:\n"
        "movl 0x114c(%edi), %eax\n" /* line 228 | dirlen */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* dirptr */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf17ebe6_0017ee77\n"
        "movl 0x195f5d8, %eax\n"
        "jmp .Lf17ebe6_0017eea1\n"
        ".Lf17ebe6_0017eecc:\n"
        "calll Com_EndParseSession\n" /* line 233 */
        "movl 0x195f5d8, %edx\n"
        "jmp .Lf17ebe6_0017ec97\n"
        ".Lf17ebe6_0017eedc:\n"
        "movl %edi, %esi\n" /* line 184 | dirlen, dirptr */
        "movl $0, -0x24b8(%ebp)\n" /* i */
        "jmp .Lf17ebe6_0017ef34\n"
        /* { scope 2 */
        ".Lf17ebe6_0017eeea:\n"
        "movl $0x2000, 0xc(%esp)\n" /* line 130 */
        "movl %ebx, 8(%esp)\n" /* len */
        "leal -0xa0(%ebp), %ecx\n" /* filename */
        "movl %ecx, 4(%esp)\n"
        "movl $0x2ae970, (%esp)\n" /* "^1file too large: %s is %i, max allowed is %i" */
        "calll Com_Printf\n"
        "movl -0x20(%ebp), %eax\n" /* line 131 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        /* } scope */
        ".Lf17ebe6_0017ef17:\n"
        "addl $1, -0x24b8(%ebp)\n" /* line 184 | i */
        "leal 1(%esi, %edi), %esi\n" /* dirptr */
        "movl -0x24b8(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x24b0(%ebp)\n" /* numdirs */
        "je .Lf17ebe6_0017ec47\n"
        ".Lf17ebe6_0017ef34:\n"
        "cld\n" /* line 186 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* dirptr, dirlen */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* dirlen */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* dirlen */
        "movl %esi, 0xc(%esp)\n" /* line 187 | dirptr */
        "movl $0x21cc10, 8(%esp)\n" /* "mp" */
        "movl $0x216e18, 4(%esp)\n" /* "%s/%s" */
        "leal -0xa0(%ebp), %edx\n" /* filename */
        "movl %edx, (%esp)\n"
        "calll sprintf\n"
        /* { scope 2 */
        "movl $0, 8(%esp)\n" /* line 122 */
        "leal -0x20(%ebp), %ecx\n" /* f */
        "movl %ecx, 4(%esp)\n"
        "leal -0xa0(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %ebx\n" /* len */
        "movl -0x20(%ebp), %eax\n" /* line 123 | f */
        "testl %eax, %eax\n"
        "je .Lf17ebe6_0017eff7\n"
        "cmpl $0x1fff, %ebx\n" /* line 128 | len */
        "jg .Lf17ebe6_0017eeea\n"
        "movl %eax, 8(%esp)\n" /* line 135 */
        "movl %ebx, 4(%esp)\n" /* len */
        "leal -0x24a0(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x24a0(%ebp, %ebx)\n" /* line 136 */
        "movl -0x20(%ebp), %eax\n" /* line 137 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl ui_numArenas, %edx\n" /* line 150 */
        "leal ui_arenaInfos(, %edx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x40, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x24a0(%ebp), %edx\n" /* buf */
        "movl %edx, (%esp)\n"
        "calll UI_ParseInfos\n"
        "addl %eax, ui_numArenas\n"
        "jmp .Lf17ebe6_0017ef17\n"
        ".Lf17ebe6_0017eff7:\n"
        "leal -0xa0(%ebp), %edx\n" /* line 125 | filename */
        "movl %edx, 4(%esp)\n"
        "movl $0x2ae958, (%esp)\n" /* "^1file not found: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf17ebe6_0017ef17\n"
    );
}

