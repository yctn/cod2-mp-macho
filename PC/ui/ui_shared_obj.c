/* ASM dump from: ui_shared_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui/ui_shared_obj.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdint.h>
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/ui/ui_utils.h"
 */

extern keywordHash_t * itemParseKeywordHash[512]; /* 0x0 */
extern keywordHash_t menuParseKeywords[33]; /* 0x0 */
extern keywordHash_t itemParseKeywords[66]; /* 0x0 */
static char string_00f3b9c0[4096]; /* string */
static unsigned char g_load[0x640]; /* g_load */
static char menuBuf[32768]; /* menuBuf */
static keywordHash_t * menuParseKeywordHash[512]; /* menuParseKeywordHash */
static char menuBuf1[4096]; /* menuBuf1 */
void UI_MapLoadInfo(const char *filename);
void PC_SourceError(int handle, char *format, ...);
qboolean PC_Script_Parse(int handle, const char * *out);
void Window_SetStaticFlags(void *item, int flags);
qboolean PC_ReadTokenHandle(int handle, void *token);
const char *String_Alloc(const char *str);
void I_strncpyz(char *dest, const char *src, int destsize);
void I_strlwr(char *str);
void *CL_RegisterMaterialNoMip(const char *name, int imageTrack);
void *UI_Alloc(int size, int align);
extern int FS_ReadFile(const char *filename, void **buffer);
extern void FS_FreeFile(void *buffer);
extern void Com_SetCSV(int csv);
extern const char *Com_ParseOnLine(const char **data_p);
extern int Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void CL_Material_Duplicate(int material, const char *name);
void Window_SetRect(menuDef_t *menu, rectDef_t *rect);
void Menu_UpdatePosition(menuDef_t *menu);
void Item_InitControls(const char (*item)[4]);
qboolean MenuParse_onOpen(const char (*item)[4], int handle);
qboolean MenuParse_onClose(const char (*item)[4], int handle);
qboolean MenuParse_onESC(const char (*item)[4], int handle);
qboolean MenuParse_soundLoop(const char (*item)[4], int handle);
void __attribute_regparm__(2) Item_ValidateTypeData(itemDef_t *item, int handle);
qboolean Item_IsEditFieldDef(itemDef_t *item);
editFieldDef_t *Item_GetEditFieldDef(itemDef_t *item);
qboolean ItemParse_textsavegame(const char (*item)[4], int handle);
qboolean ItemParse_notselectable(const char (*item)[4], int handle);
qboolean ItemParse_noScrollBars(const char (*item)[4], int handle);
qboolean ItemParse_horizontalscroll(const char (*item)[4], int handle);
qboolean ItemParse_doubleClick(const char (*item)[4], int handle);
qboolean ItemParse_onFocus(const char (*item)[4], int handle);
qboolean ItemParse_leaveFocus(const char (*item)[4], int handle);
qboolean ItemParse_mouseEnter(const char (*item)[4], int handle);
qboolean ItemParse_mouseExit(const char (*item)[4], int handle);
qboolean ItemParse_mouseEnterText(const char (*item)[4], int handle);
qboolean ItemParse_mouseExitText(const char (*item)[4], int handle);
qboolean ItemParse_action(const char (*item)[4], int handle);
qboolean ItemParse_accept(const char (*item)[4], int handle);
qboolean Item_Parse_maxCharsGotoNext(const char (*item)[4], int handle);
qboolean ItemParse_dvarStrList(const char (*item)[4], int handle);
qboolean ItemParse_enableDvar(const char (*item)[4], int handle);
qboolean ItemParse_disableDvar(const char (*item)[4], int handle);
qboolean ItemParse_showDvar(const char (*item)[4], int handle);
qboolean ItemParse_hideDvar(const char (*item)[4], int handle);
qboolean ItemParse_focusDvar(const char (*item)[4], int handle);
void Menu_PostParse(menuDef_t *menu);
qboolean MenuParse_popup(const char (*item)[4], int handle);
qboolean MenuParse_outOfBounds(const char (*item)[4], int handle);
qboolean MenuParse_legacySplitScreenScale(const char (*item)[4], int handle);
qboolean ItemParse_decoration(const char (*item)[4], int handle);
qboolean ItemParse_wrapped(const char (*item)[4], int handle);
qboolean ItemParse_autowrapped(const char (*item)[4], int handle);
qboolean MenuParse_execKey(const char (*item)[4], int handle);
qboolean ItemParse_execKey(const char (*item)[4], int handle);
qboolean ItemParse_textfile(const char (*item)[4], int handle);
int FS_FOpenFileByMode(const char *qpath, fileHandle_t *f, fsMode_t mode);
int FS_Read(void *buffer, int len, fileHandle_t h);
void FS_FCloseFile(fileHandle_t h);
int Com_Compress(char *data_p);
void Com_BeginParseSession(const char *filename);
void Com_EndParseSession(void);
const char *Com_Parse(const char **data_p);
int I_stricmp(const char *s1, const char *s2);
Bool I_isupper(int c);
void Com_Printf(const char *fmt, ...);
void Com_Error(errorParm_t code, const char *fmt, ...);
void Menu_SetCursorItem(menuDef_t *menu, int cursorItem);
static Bool __attribute_regparm__(2) Menu_New(int handle, int imageTrack);
qboolean Item_Parse(int handle, const char (*item)[4]);
qboolean MenuParse_itemDef(const char (*item)[4], int handle);
void Item_SetupKeywordHash(void);
void Menu_SetupKeywordHash(void);
qboolean MenuParse_name(const char (*item)[4], int handle);
qboolean MenuParse_background(const char (*item)[4], int handle);
qboolean MenuParse_cinematic(const char (*item)[4], int handle);
qboolean ItemParse_name(const char (*item)[4], int handle);
qboolean ItemParse_focusSound(const char (*item)[4], int handle);
qboolean ItemParse_text(const char (*item)[4], int handle);
qboolean ItemParse_group(const char (*item)[4], int handle);
qboolean ItemParse_background(const char (*item)[4], int handle);
qboolean ItemParse_cinematic(const char (*item)[4], int handle);
qboolean ItemParse_dvarTest(const char (*item)[4], int handle);
qboolean ItemParse_dvar(const char (*item)[4], int handle);
qboolean ItemParse_dvarEnumList(const char (*item)[4], int handle);
qboolean ItemParse_outlinecolor(const char (*item)[4], int handle);
qboolean MenuParse_outlinecolor(const char (*item)[4], int handle);
qboolean PC_Rect_Parse(int handle, rectDef_t *r);
qboolean ItemParse_rect(const char (*item)[4], int handle);
qboolean MenuParse_rect(const char (*item)[4], int handle);
qboolean MenuParse_borderSize(const char (*item)[4], int handle);
qboolean MenuParse_backcolor(const char (*item)[4], int handle);
qboolean MenuParse_forecolor(const char (*item)[4], int handle);
qboolean MenuParse_bordercolor(const char (*item)[4], int handle);
qboolean MenuParse_focuscolor(const char (*item)[4], int handle);
qboolean MenuParse_disablecolor(const char (*item)[4], int handle);
qboolean MenuParse_fadeClamp(const char (*item)[4], int handle);
qboolean MenuParse_fadeAmount(const char (*item)[4], int handle);
qboolean MenuParse_fadeInAmount(const char (*item)[4], int handle);
qboolean MenuParse_blurWorld(const char (*item)[4], int handle);
qboolean ItemParse_elementwidth(const char (*item)[4], int handle);
qboolean ItemParse_elementheight(const char (*item)[4], int handle);
qboolean ItemParse_feeder(const char (*item)[4], int handle);
qboolean ItemParse_bordersize(const char (*item)[4], int handle);
qboolean ItemParse_textalignx(const char (*item)[4], int handle);
qboolean ItemParse_textaligny(const char (*item)[4], int handle);
qboolean ItemParse_textscale(const char (*item)[4], int handle);
qboolean ItemParse_backcolor(const char (*item)[4], int handle);
qboolean ItemParse_forecolor(const char (*item)[4], int handle);
qboolean ItemParse_bordercolor(const char (*item)[4], int handle);
qboolean ItemParse_special(const char (*item)[4], int handle);
qboolean ItemParse_dvarFloat(const char (*item)[4], int handle);
qboolean ItemParse_dvarFloatList(const char (*item)[4], int handle);
qboolean MenuParse_fullscreen(const char (*item)[4], int handle);
qboolean MenuParse_style(const char (*item)[4], int handle);
qboolean MenuParse_visible(const char (*item)[4], int handle);
qboolean MenuParse_border(const char (*item)[4], int handle);
qboolean MenuParse_ownerdrawFlag(const char (*item)[4], int handle);
qboolean MenuParse_ownerdraw(const char (*item)[4], int handle);
qboolean MenuParse_fadeCycle(const char (*item)[4], int handle);
qboolean MenuParse_execKeyInt(const char (*item)[4], int handle);
qboolean ItemParse_origin(const char (*item)[4], int handle);
qboolean ItemParse_style(const char (*item)[4], int handle);
qboolean ItemParse_type(const char (*item)[4], int handle);
qboolean ItemParse_elementtype(const char (*item)[4], int handle);
qboolean ItemParse_columns(const char (*item)[4], int handle);
qboolean ItemParse_border(const char (*item)[4], int handle);
qboolean ItemParse_visible(const char (*item)[4], int handle);
qboolean ItemParse_ownerdraw(const char (*item)[4], int handle);
qboolean ItemParse_align(const char (*item)[4], int handle);
qboolean ItemParse_textalign(const char (*item)[4], int handle);
qboolean ItemParse_textstyle(const char (*item)[4], int handle);
qboolean ItemParse_textfont(const char (*item)[4], int handle);
qboolean ItemParse_maxChars(const char (*item)[4], int handle);
qboolean ItemParse_maxPaintChars(const char (*item)[4], int handle);
qboolean ItemParse_ownerdrawFlag(const char (*item)[4], int handle);
qboolean ItemParse_execKeyInt(const char (*item)[4], int handle);
static Bool __attribute_regparm__(2) UI_ParseMenuInternal(const char *menuFile, int imageTrack);
MenuList * UI_LoadMenus(const char *menuFile, int imageTrack);
MenuList * UI_LoadMenu(const char *menuFile, int imageTrack);

static loadAssets_t *UI_LoadAssets(void)
{
    return (loadAssets_t *)g_load;
}

static MenuList *UI_MenuList(void)
{
    return (MenuList *)(g_load + sizeof(loadAssets_t));
}

static itemDef_t **UI_MenuItemStorage(void)
{
    return (itemDef_t **)(g_load + 64);
}

static menuDef_t **UI_MenuStorage(void)
{
    return (menuDef_t **)(g_load + 1088);
}

static keywordHash_t *UI_KeywordHashNext(keywordHash_t *hash)
{
    return (keywordHash_t *)(uintptr_t)hash->next;
}

static unsigned int UI_KeywordHashKey(const char *keyword)
{
    int hash;
    int weight;
    unsigned char c;

    hash = 0;
    weight = 0x77;
    c = (unsigned char)*keyword;

    while (c != '\0') {
        int ch = (char)c;

        if (I_isupper(ch))
            ch += 0x20;

        hash += ch * weight;
        weight += 1;
        c = (unsigned char)*++keyword;
    }

    return (unsigned int)((hash ^ (hash >> 10) ^ (hash >> 20)) & 0x1ff);
}

/* line 103 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void UI_MapLoadInfo(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 103 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x17c, %esp\n"
        /* { scope 1: name */
        "movl 8(%ebp), %eax\n" /* line 113 | filename */
        "cmpb $0, (%eax)\n"
        "jne .Lf1a6004_001a6023\n"
        /* } scope */
        ".Lf1a6004_001a6018:\n"
        "addl $0x17c, %esp\n" /* line 151 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1a6004_001a6023:\n"
        "movl %eax, %ecx\n"
        /* { scope 1: name */
        "leal -0x1c(%ebp), %eax\n" /* line 116 | loadfile */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n" /* line 117 */
        "js .Lf1a6004_001a6197\n"
        "movl -0x1c(%ebp), %eax\n" /* line 123 | loadfile */
        "movl %eax, -0x20(%ebp)\n" /* parse */
        "movl 8(%ebp), %eax\n" /* line 124 | filename */
        "movl %eax, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "movl $1, (%esp)\n" /* line 125 */
        "calll Com_SetCSV\n"
        "jmp .Lf1a6004_001a60d0\n"
        ".Lf1a6004_001a605b:\n"
        "leal -0x160(%ebp), %edi\n" /* key */
        "movl %ebx, 8(%esp)\n" /* line 137 | material */
        "movl %esi, 4(%esp)\n" /* token */
        "movl %edi, (%esp)\n"
        "calll memcpy\n"
        "leal -0x20(%ebp), %eax\n" /* line 139 | parse */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "cmpb $0, (%eax)\n" /* line 140 */
        "je .Lf1a6004_001a6158\n"
        /* { scope 2 */
        ".Lf1a6004_001a6085:\n"
        "movl $3, 4(%esp)\n" /* line 96 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, %ebx\n" /* material */
        "movl %edi, 0xc(%esp)\n" /* line 97 */
        "movl $str_002b409c, 8(%esp)\n" /* "$%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x60(%ebp), %ecx\n" /* name */
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x60(%ebp), %eax\n" /* line 98 | name */
        "movl %eax, (%esp)\n"
        "calll I_strlwr\n"
        "leal -0x60(%ebp), %ecx\n" /* line 99 | name */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* material */
        "calll CL_Material_Duplicate\n"
        /* } scope */
        ".Lf1a6004_001a60d0:\n"
        "leal -0x20(%ebp), %ecx\n" /* line 128 | parse */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* token */
        "cmpb $0, (%eax)\n" /* line 129 */
        "je .Lf1a6004_001a617c\n"
        "cld\n" /* line 131 */
        "movl $0xffffffff, %ecx\n"
        "movl %eax, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n" /* material */
        "notl %ebx\n" /* material */
        "leal -1(%ebx), %edi\n" /* material */
        "cmpl $0xff, %ebx\n" /* line 132 | material */
        "jbe .Lf1a6004_001a605b\n"
        "calll Com_EndParseSession\n" /* line 134 */
        "movl $0xff, 0x10(%esp)\n" /* line 135 */
        "movl %edi, 0xc(%esp)\n"
        "leal -0x160(%ebp), %edi\n" /* key */
        "movl %edi, 8(%esp)\n"
        "movl $str_002b4058, 4(%esp)\n" /* "key '%s' is %i > %i characters long" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl %ebx, 8(%esp)\n" /* line 137 | material */
        "movl %esi, 4(%esp)\n" /* token */
        "movl %edi, (%esp)\n"
        "calll memcpy\n"
        "leal -0x20(%ebp), %eax\n" /* line 139 | parse */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "cmpb $0, (%eax)\n" /* line 140 */
        "jne .Lf1a6004_001a6085\n"
        ".Lf1a6004_001a6158:\n"
        "calll Com_EndParseSession\n" /* line 142 */
        "movl 8(%ebp), %ecx\n" /* line 143 | filename */
        "movl %ecx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $str_002b407c, 4(%esp)\n" /* "key '%s' missing value in '%s'
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf1a6004_001a617c:\n"
        "calll Com_EndParseSession\n" /* line 149 */
        "movl -0x1c(%ebp), %eax\n" /* line 150 | loadfile */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "addl $0x17c, %esp\n" /* line 151 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: name */
        ".Lf1a6004_001a6197:\n"
        "movl 8(%ebp), %eax\n" /* line 119 | filename */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b4034, (%esp)\n" /* "^3WARNING: Could not find '%s'.
" */
        "calll Com_Printf\n"
        "jmp .Lf1a6004_001a6018\n"
    );
}

/* line 159 */
__attribute__((naked))
void PC_SourceError(int handle, char *format, ...)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 159 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0xa4, %esp\n"
        /* { scope 1 */
        "leal 0x10(%ebp), %eax\n" /* line 166 */
        "movl %eax, -0x10(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 167 */
        "movl 0xc(%ebp), %eax\n" /* format */
        "movl %eax, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "movl $string, (%esp)\n"
        "calll vsnprintf\n"
        "movb $0, -0x90(%ebp)\n" /* line 170 | filename */
        "movl $0, -0xc(%ebp)\n" /* line 171 | line */
        "leal -0xc(%ebp), %eax\n" /* line 172 | line */
        "movl %eax, 8(%esp)\n"
        "leal -0x90(%ebp), %ebx\n" /* filename */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* handle */
        "movl %eax, (%esp)\n"
        "calll PC_SourceFileAndLine\n"
        "movl $string, 0xc(%esp)\n" /* line 174 */
        "movl -0xc(%ebp), %eax\n" /* line */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002b40a0, (%esp)\n" /* "^1Menu load error: %s, line %d: %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0xa4, %esp\n" /* line 175 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 371 */
__attribute__((naked))
qboolean PC_Script_Parse(int handle, const char * *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 371 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x82c, %esp\n"
        /* { scope 1 */
        "leal -0x418(%ebp), %esi\n" /* line 376 | script */
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memset\n"
        "leal -0x828(%ebp), %edi\n" /* line 380 | token */
        "movl %edi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* handle */
        "movl %eax, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a6232_001a6282\n"
        ".Lf1a6232_001a6275:\n"
        "xorl %eax, %eax\n" /* line 387 */
        /* } scope */
        "addl $0x82c, %esp\n" /* line 408 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a6232_001a6282:\n"
        "movl $str_0021e50c, 4(%esp)\n" /* line 382 */
        "leal -0x818(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a6232_001a6275\n"
        "jmp .Lf1a6232_001a62da\n"
        ".Lf1a6232_001a629e:\n"
        "movl %ebx, 4(%esp)\n" /* line 400 */
        "movl $str_0021f878, (%esp)\n" /* ""%s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        ".Lf1a6232_001a62c2:\n"
        "movl $str_00217914, 8(%esp)\n" /* line 406 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        ".Lf1a6232_001a62da:\n"
        "movl %edi, 4(%esp)\n" /* line 389 */
        "movl 8(%ebp), %edx\n" /* handle */
        "movl %edx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a6232_001a6275\n"
        "movl $str_0021e508, 4(%esp)\n" /* line 392 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a6232_001a6329\n"
        "cmpb $0, -0x818(%ebp)\n" /* line 398 */
        "je .Lf1a6232_001a629e\n"
        "cmpb $0, -0x817(%ebp)\n"
        "jne .Lf1a6232_001a629e\n"
        "movl %ebx, 8(%esp)\n" /* line 404 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        "jmp .Lf1a6232_001a62c2\n"
        ".Lf1a6232_001a6329:\n"
        "movl %esi, (%esp)\n" /* line 394 */
        "calll String_Alloc\n"
        "movl 0xc(%ebp), %edx\n" /* out */
        "movl %eax, (%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x82c, %esp\n" /* line 408 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 540 */
__attribute__((naked))
void Item_InitControls(const char (*item)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 540 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "testl %ebx, %ebx\n" /* line 542 | item */
        "je .Lf1a6348_001a6360\n"
        "cmpl $6, 0x270(%ebx)\n" /* line 546 | item */
        "je .Lf1a6348_001a6367\n"
        ".Lf1a6348_001a6360:\n"
        "addl $0x10, %esp\n" /* line 558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a6348_001a6367:\n"
        "movl %ebx, (%esp)\n" /* line 548 | item */
        "calll Item_GetListBoxDef\n"
        "movl %eax, %esi\n" /* listPtr */
        "movl $0, 4(%esp)\n" /* line 550 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "testl %esi, %esi\n" /* line 551 | listPtr */
        "je .Lf1a6348_001a6360\n"
        "movl $0, 4(%esp)\n" /* line 553 */
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl $0, 4(%esp)\n" /* line 554 */
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl $0, 4(%esp)\n" /* line 555 */
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetEndPos\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 632 */
qboolean MenuParse_onOpen(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x244)) != 0;
}

/* line 644 */
qboolean MenuParse_onClose(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x248)) != 0;
}

/* line 656 */
qboolean MenuParse_onESC(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x24c)) != 0;
}

/* line 875 */
__attribute__((naked))
qboolean MenuParse_soundLoop(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 875 */
        "movl %esp, %ebp\n"
        "subl $0x428, %esp\n"
        /* { scope 1 */
        "leal -0x418(%ebp), %eax\n" /* line 880 | token */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* handle */
        "movl %eax, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a6434_001a6464\n"
        "cmpb $0, -0x408(%ebp)\n" /* line 883 */
        "jne .Lf1a6434_001a6466\n"
        "movl $1, %eax\n" /* line 884 */
        /* } scope */
        ".Lf1a6434_001a6464:\n"
        "leave\n" /* line 887 */
        "retl\n"
        /* { scope 1 */
        ".Lf1a6434_001a6466:\n"
        "leal -0x408(%ebp), %eax\n" /* line 884 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl 8(%ebp), %edx\n" /* item */
        "movl %eax, 0x254(%edx)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a6434_001a6464\n"
    );
}

/* line 1117 */
void __attribute_regparm__(2) Item_ValidateTypeData(itemDef_t *item, int handle)
{
    editFieldDef_t *editDef;

    if (item->typeData.data) {
        if (item->dataType != item->type) {
            PC_SourceError(handle,
                "Attempting to change type from %d to %d.\nMove the type definition higher up in the itemDef.\n",
                item->dataType, item->type);
        }
        return;
    }

    item->dataType = item->type;

    switch (item->type) {
    case 6:
        item->typeData.listBox = UI_Alloc(sizeof(listBoxDef_t), 4);
        return;

    case 4:
    case 9:
    case 0x10:
    case 0x12:
    case 0xb:
    case 0xe:
    case 0xa:
    case 0:
    case 0x11:
        item->typeData.editField = UI_Alloc(sizeof(editFieldDef_t), 4);
        if (item->type != 4 && item->type != 0x10 && item->type != 9 &&
            item->type != 0x12 && item->type != 0x11) {
            return;
        }

        editDef = Item_GetEditFieldDef(item);
        if (editDef && !editDef->maxPaintChars) {
            editDef->maxPaintChars = 0x100;
        }
        return;

    case 0xc:
        item->typeData.multi = UI_Alloc(sizeof(multiDef_t), 4);
        return;
    }
}

static void Item_InitDvarEditField(itemDef_t *item)
{
    editFieldDef_t *editDef;

    if (!item->dvar || !item->typeData.data || !Item_IsEditFieldDef(item)) {
        return;
    }

    editDef = Item_GetEditFieldDef(item);
    if (!editDef) {
        return;
    }

    editDef->minVal = -1.0f;
    editDef->maxVal = -1.0f;
    editDef->defVal = -1.0f;
}

/* line 1201 */
qboolean ItemParse_textsavegame(const char (*item)[4], int handle)
{
    *(const char **)((char *)item + 0x294) = (const char *)str_002b4164;
    *(int *)((char *)item + 0x298) = 1;
    return 1;
}

/* line 1272 */
__attribute__((naked))
qboolean ItemParse_notselectable(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1272 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %edx\n" /* handle */
        /* { scope 1 */
        "movl %ebx, %eax\n" /* line 1276 | item */
        "calll Item_ValidateTypeData\n"
        "movl %ebx, (%esp)\n" /* line 1277 | item */
        "calll Item_GetListBoxDef\n"
        "testl %eax, %eax\n" /* line 1278 */
        "je .Lf1a65c4_001a65f2\n"
        "cmpl $6, 0x270(%ebx)\n" /* line 1280 | item */
        "je .Lf1a65c4_001a65f8\n"
        ".Lf1a65c4_001a65ed:\n"
        "movl $1, %eax\n" /* line 1282 */
        /* } scope */
        ".Lf1a65c4_001a65f2:\n"
        "addl $0x14, %esp\n" /* line 1285 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a65c4_001a65f8:\n"
        "movl $1, 0x108(%eax)\n" /* line 1282 */
        "jmp .Lf1a65c4_001a65ed\n"
    );
}

/* line 1288 */
__attribute__((naked))
qboolean ItemParse_noScrollBars(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1288 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %edx\n" /* handle */
        /* { scope 1 */
        "movl %ebx, %eax\n" /* line 1292 | item */
        "calll Item_ValidateTypeData\n"
        "movl %ebx, (%esp)\n" /* line 1293 | item */
        "calll Item_GetListBoxDef\n"
        "testl %eax, %eax\n" /* line 1294 */
        "je .Lf1a6604_001a6632\n"
        "cmpl $6, 0x270(%ebx)\n" /* line 1296 | item */
        "je .Lf1a6604_001a6638\n"
        ".Lf1a6604_001a662d:\n"
        "movl $1, %eax\n" /* line 1298 */
        /* } scope */
        ".Lf1a6604_001a6632:\n"
        "addl $0x14, %esp\n" /* line 1301 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a6604_001a6638:\n"
        "movl $1, 0x10c(%eax)\n" /* line 1298 */
        "jmp .Lf1a6604_001a662d\n"
    );
}

/* line 1327 */
qboolean ItemParse_horizontalscroll(const char (*item)[4], int handle)
{
    Window_SetStaticFlags((void *)item, *(int *)((char *)item + 0xe4) | 0x200000);
    return 1;
}

/* line 1681 */
__attribute__((naked))
qboolean ItemParse_doubleClick(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1681 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1 */
        "movl %esi, %edx\n" /* line 1685 | handle */
        "movl %ebx, %eax\n" /* item */
        "calll Item_ValidateTypeData\n"
        "movl 0x2ec(%ebx), %eax\n" /* line 1686 | item */
        "testl %eax, %eax\n"
        "je .Lf1a666c_001a66ae\n"
        "movl %ebx, (%esp)\n" /* line 1691 | item */
        "calll Item_GetListBoxDef\n"
        "testl %eax, %eax\n" /* line 1692 */
        "je .Lf1a666c_001a66ae\n"
        "addl $0x104, %eax\n" /* line 1695 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll PC_Script_Parse\n"
        "testl %eax, %eax\n"
        "jne .Lf1a666c_001a66b7\n"
        ".Lf1a666c_001a66ae:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1700 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a666c_001a66b7:\n"
        "movl $1, %eax\n" /* line 1695 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1700 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1703 */
qboolean ItemParse_onFocus(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x2b8)) != 0;
}

/* line 1713 */
qboolean ItemParse_leaveFocus(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x2bc)) != 0;
}

/* line 1723 */
qboolean ItemParse_mouseEnter(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x2a8)) != 0;
}

/* line 1733 */
qboolean ItemParse_mouseExit(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x2ac)) != 0;
}

/* line 1743 */
qboolean ItemParse_mouseEnterText(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x2a0)) != 0;
}

/* line 1753 */
qboolean ItemParse_mouseExitText(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x2a4)) != 0;
}

/* line 1763 */
qboolean ItemParse_action(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x2b0)) != 0;
}

/* line 1774 */
qboolean ItemParse_accept(const char (*item)[4], int handle)
{
    return PC_Script_Parse(handle, (const char **)((char *)item + 0x2b4)) != 0;
}

/* line 1851 */
__attribute__((naked))
qboolean Item_Parse_maxCharsGotoNext(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1851 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %edx\n" /* handle */
        /* { scope 1 */
        "movl %ebx, %eax\n" /* line 1855 | item */
        "calll Item_ValidateTypeData\n"
        "movl 0x2ec(%ebx), %eax\n" /* line 1856 | item */
        "testl %eax, %eax\n"
        "je .Lf1a6804_001a6840\n"
        "movl %ebx, (%esp)\n" /* line 1859 | item */
        "calll Item_GetEditFieldDef\n"
        "testl %eax, %eax\n" /* line 1860 */
        "je .Lf1a6804_001a6840\n"
        "movl $1, 0x14(%eax)\n" /* line 1862 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1864 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a6804_001a6840:\n"
        "xorl %eax, %eax\n" /* line 1863 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1864 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1906 */
__attribute__((naked))
qboolean ItemParse_dvarStrList(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1906 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %edi\n" /* handle */
        /* { scope 1 */
        "movl %edi, %edx\n" /* line 1912 | handle */
        "movl %ebx, %eax\n" /* pass */
        "calll Item_ValidateTypeData\n"
        "movl 0x2ec(%ebx), %eax\n" /* line 1913 | pass */
        "testl %eax, %eax\n"
        "je .Lf1a6848_001a6876\n"
        "cmpl $0xc, 0x270(%ebx)\n" /* line 1915 | pass */
        "je .Lf1a6848_001a6883\n"
        ".Lf1a6848_001a6876:\n"
        "xorl %eax, %eax\n" /* line 1958 */
        /* } scope */
        ".Lf1a6848_001a6878:\n"
        "addl $0x42c, %esp\n" /* line 1965 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a6848_001a6883:\n"
        "movl %ebx, (%esp)\n" /* line 1917 | pass */
        "calll Item_GetMultiDef\n"
        "movl %eax, %esi\n" /* multiPtr */
        "movl $0, 0x180(%eax)\n" /* line 1919 */
        "movl $1, 0x184(%eax)\n" /* line 1920 */
        "leal -0x428(%ebp), %eax\n" /* line 1922 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a6848_001a6876\n"
        "cmpb $0x7b, -0x418(%ebp)\n" /* line 1924 */
        "jne .Lf1a6848_001a6876\n"
        ".Lf1a6848_001a68c0:\n"
        "xorl %ebx, %ebx\n" /* pass */
        ".Lf1a6848_001a68c2:\n"
        "leal -0x428(%ebp), %eax\n" /* line 1932 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a6848_001a6925\n"
        ".Lf1a6848_001a68d8:\n"
        "movzbl -0x418(%ebp), %eax\n" /* line 1938 */
        "cmpb $0x7d, %al\n"
        "je .Lf1a6848_001a6974\n"
        "cmpb $0x2c, %al\n" /* line 1943 */
        "je .Lf1a6848_001a68c2\n"
        "cmpb $0x3b, %al\n"
        "je .Lf1a6848_001a68c2\n"
        "testl %ebx, %ebx\n" /* line 1948 | pass */
        "jne .Lf1a6848_001a693c\n"
        "movl 0x180(%esi), %ebx\n" /* line 1950 | multiPtr, pass */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, (%esi, %ebx, 4)\n" /* multiPtr */
        "movl $1, %ebx\n" /* pass */
        "leal -0x428(%ebp), %eax\n" /* line 1932 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handle */
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a6848_001a68d8\n"
        ".Lf1a6848_001a6925:\n"
        "movl $str_002b4174, 4(%esp)\n" /* line 1934 */
        "movl %edi, (%esp)\n" /* handle */
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1a6848_001a6878\n"
        ".Lf1a6848_001a693c:\n"
        "movl 0x180(%esi), %ebx\n" /* line 1955 | multiPtr, pass */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, 0x80(%esi, %ebx, 4)\n" /* multiPtr */
        "movl 0x180(%esi), %eax\n" /* line 1957 | multiPtr */
        "addl $1, %eax\n"
        "movl %eax, 0x180(%esi)\n" /* multiPtr */
        "cmpl $0x1f, %eax\n" /* line 1958 */
        "jle .Lf1a6848_001a68c0\n"
        "jmp .Lf1a6848_001a6876\n"
        ".Lf1a6848_001a6974:\n"
        "movl $1, %eax\n" /* line 1938 */
        "jmp .Lf1a6848_001a6878\n"
    );
}

/* line 2049 */
qboolean ItemParse_enableDvar(const char (*item)[4], int handle)
{
    if (!PC_Script_Parse(handle, (const char **)((char *)item + 0x2cc)))
        return 0;
    *(int *)((char *)item + 0x2d0) |= 1;
    return 1;
}

/* line 2060 */
qboolean ItemParse_disableDvar(const char (*item)[4], int handle)
{
    if (!PC_Script_Parse(handle, (const char **)((char *)item + 0x2cc)))
        return 0;
    *(int *)((char *)item + 0x2d0) |= 2;
    return 1;
}

/* line 2071 */
qboolean ItemParse_showDvar(const char (*item)[4], int handle)
{
    if (!PC_Script_Parse(handle, (const char **)((char *)item + 0x2cc)))
        return 0;
    *(int *)((char *)item + 0x2d0) |= 4;
    return 1;
}

/* line 2082 */
qboolean ItemParse_hideDvar(const char (*item)[4], int handle)
{
    if (!PC_Script_Parse(handle, (const char **)((char *)item + 0x2cc)))
        return 0;
    *(int *)((char *)item + 0x2d0) |= 8;
    return 1;
}

/* line 2093 */
qboolean ItemParse_focusDvar(const char (*item)[4], int handle)
{
    if (!PC_Script_Parse(handle, (const char **)((char *)item + 0x2cc)))
        return 0;
    *(int *)((char *)item + 0x2d0) |= 0x10;
    return 1;
}

/* line 2483 */
void Menu_PostParse(menuDef_t *menu)
{
    int size = *(int *)((char *)menu + 0x218) * 4;
    void *items = UI_Alloc(size, 4);
    *(void **)((char *)menu + 0x27c) = items;
    memcpy(items, (void *)(g_load + 64), size);
    if (*(int *)((char *)menu + 0x214)) {
        rectDef_t rect;
        rect.x = 0.0f;
        rect.y = 0.0f;
        rect.w = 640.0f;
        rect.h = 480.0f;
        Window_SetRect(menu, &rect);
    }
    Menu_UpdatePosition(menu);
}

/* line 853 */
qboolean MenuParse_popup(const char (*item)[4], int handle)
{
    Window_SetStaticFlags((void *)item, *(int *)((char *)item + 0xe4) | 0x1000000);
    return 1;
}

/* line 864 */
qboolean MenuParse_outOfBounds(const char (*item)[4], int handle)
{
    Window_SetStaticFlags((void *)item, *(int *)((char *)item + 0xe4) | 0x2000000);
    return 1;
}

/* line 1021 */
qboolean MenuParse_legacySplitScreenScale(const char (*item)[4], int handle)
{
    Window_SetStaticFlags((void *)item, *(int *)((char *)item + 0xe4) | 0x4000000);
    return 1;
}

/* line 1261 */
qboolean ItemParse_decoration(const char (*item)[4], int handle)
{
    Window_SetStaticFlags((void *)item, *(int *)((char *)item + 0xe4) | 0x100000);
    return 1;
}

/* line 1305 */
qboolean ItemParse_wrapped(const char (*item)[4], int handle)
{
    Window_SetStaticFlags((void *)item, *(int *)((char *)item + 0xe4) | 0x400000);
    return 1;
}

/* line 1316 */
qboolean ItemParse_autowrapped(const char (*item)[4], int handle)
{
    Window_SetStaticFlags((void *)item, *(int *)((char *)item + 0xe4) | 0x800000);
    return 1;
}

/* line 957 */
__attribute__((naked))
qboolean MenuParse_execKey(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 957 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x430, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* handle */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x41c(%ebp), %eax\n" /* line 358 | token */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a6c04_001a6c43\n"
        /* } scope */
        "movzbw -0x40c(%ebp), %si\n" /* line 968 | keyindex */
        "leal -0xc(%ebp), %eax\n" /* line 970 | action */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* handle */
        "calll PC_Script_Parse\n"
        "testl %eax, %eax\n"
        "jne .Lf1a6c04_001a6c4f\n"
        ".Lf1a6c04_001a6c43:\n"
        "xorl %eax, %eax\n" /* line 978 */
        /* } scope */
        "addl $0x430, %esp\n" /* line 979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lf1a6c04_001a6c4f:\n"
        "movl $4, 4(%esp)\n" /* line 973 */
        "movl $0xc, (%esp)\n"
        "calll UI_Alloc\n"
        "movswl %si, %edx\n" /* line 974 | keyindex */
        "movl %edx, (%eax)\n"
        "movl -0xc(%ebp), %edx\n" /* line 975 | action */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 976 | item */
        "movl 0x250(%ecx), %edx\n"
        "movl %edx, 8(%eax)\n"
        "movl %eax, 0x250(%ecx)\n" /* line 977 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x430, %esp\n" /* line 979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2104 */
__attribute__((naked))
qboolean ItemParse_execKey(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2104 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x430, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* handle */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x41c(%ebp), %eax\n" /* line 358 | token */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a6c90_001a6ccf\n"
        /* } scope */
        "movzbw -0x40c(%ebp), %si\n" /* line 2114 | keyindex */
        "leal -0xc(%ebp), %eax\n" /* line 2116 | action */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* handle */
        "calll PC_Script_Parse\n"
        "testl %eax, %eax\n"
        "jne .Lf1a6c90_001a6cdb\n"
        ".Lf1a6c90_001a6ccf:\n"
        "xorl %eax, %eax\n" /* line 2124 */
        /* } scope */
        "addl $0x430, %esp\n" /* line 2125 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lf1a6c90_001a6cdb:\n"
        "movl $4, 4(%esp)\n" /* line 2119 */
        "movl $0xc, (%esp)\n"
        "calll UI_Alloc\n"
        "movswl %si, %edx\n" /* line 2120 | keyindex */
        "movl %edx, (%eax)\n"
        "movl -0xc(%ebp), %edx\n" /* line 2121 | action */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 2122 | item */
        "movl 0x2c8(%ecx), %edx\n"
        "movl %edx, 8(%eax)\n"
        "movl %eax, 0x2c8(%ecx)\n" /* line 2123 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x430, %esp\n" /* line 2125 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1186 */
__attribute__((naked))
qboolean ItemParse_textfile(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1186 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x434, %esp\n"
        /* { scope 1: f */
        "leal -0x41c(%ebp), %eax\n" /* line 1191 | token */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* handle */
        "movl %eax, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a6d1c_001a6d48\n"
        /* } scope */
        "addl $0x434, %esp\n" /* line 1198 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: f */
        /* { scope 2 */
        ".Lf1a6d1c_001a6d48:\n"
        "movl $0, 8(%esp)\n" /* line 1099 */
        "leal -0xc(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "leal -0x40c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %ebx\n" /* len */
        "movl -0xc(%ebp), %eax\n" /* line 1100 | f */
        "testl %eax, %eax\n"
        "jne .Lf1a6d1c_001a6d8d\n"
        /* } scope */
        ".Lf1a6d1c_001a6d6e:\n"
        "movl %eax, (%esp)\n" /* line 1195 */
        "calll String_Alloc\n"
        "movl 8(%ebp), %edx\n" /* item */
        "movl %eax, 0x294(%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x434, %esp\n" /* line 1198 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: f */
        /* { scope 2 */
        ".Lf1a6d1c_001a6d8d:\n"
        "movl %eax, 8(%esp)\n" /* line 1105 */
        "movl %ebx, 4(%esp)\n" /* len */
        "movl $menuBuf1, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, menuBuf1(%ebx)\n" /* line 1106 | len */
        "movl -0xc(%ebp), %eax\n" /* line 1107 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl $menuBuf1, %eax\n"
        "jmp .Lf1a6d1c_001a6d6e\n"
    );
}

/* line 2515 */
static Bool __attribute_regparm__(2) Menu_New(int handle, int imageTrack)
{
    loadAssets_t *load;
    MenuList *menuList;
    menuDef_t *menu;
    keywordHash_t *hash;
    pc_token_t token;
    byte *menuBytes;

    load = UI_LoadAssets();
    menuList = UI_MenuList();

    menu = (menuDef_t *)UI_Alloc(0x280, 4);
    memset(menu, 0, 0x280);
    Menu_SetCursorItem(menu, -1);

    menuBytes = (byte *)menu;
    *(float *)(menuBytes + 0x238) = load->fadeAmount;
    *(float *)(menuBytes + 0x23c) = load->fadeInAmount;
    *(float *)(menuBytes + 0x234) = load->fadeClamp;
    *(int *)(menuBytes + 0x230) = load->fadeCycle;
    *(int *)(menuBytes + 0x258) = imageTrack;
    *(itemDef_t ***)(menuBytes + 0x27c) = UI_MenuItemStorage();

    memset(menu, 0, 0x210);
    *(float *)(menuBytes + 0xe0) = 1.0f;
    *(float *)(menuBytes + 0x1d8) = 1.0f;
    *(float *)(menuBytes + 0x1d4) = 1.0f;
    *(float *)(menuBytes + 0x1d0) = 1.0f;
    *(float *)(menuBytes + 0x1cc) = 1.0f;
    *(int *)(menuBytes + 0xcc) = -1;

    if (!PC_ReadTokenHandle(handle, &token) || token.string[0] != '{')
        return 0;

    for (;;) {
        memset(&token, 0, sizeof(token));

        if (!PC_ReadTokenHandle(handle, &token)) {
            PC_SourceError(handle, "end of file inside menu");
            return 0;
        }

        if (token.string[0] == '}')
            break;

        hash = menuParseKeywordHash[UI_KeywordHashKey(token.string)];
        while (hash != NULL && I_stricmp(hash->keyword, token.string) != 0)
            hash = UI_KeywordHashNext(hash);

        if (hash == NULL) {
            PC_SourceError(handle, "unknown menu keyword %s", token.string);
            continue;
        }

        if (!((qboolean (*)(menuDef_t *, int))hash->func)(menu, handle)) {
            PC_SourceError(handle, "couldn't parse menu keyword %s", token.string);
            return 0;
        }
    }

    if (*(const char **)(menuBytes + 0xc0) == NULL) {
        PC_SourceError(handle, "menu has no name");
        return 0;
    }

    Menu_PostParse(menu);

    if (menuList->menuCount > 0x7f)
        Com_Error(ERR_DROP, "too many menus");

    menuList->menus[menuList->menuCount] = menu;
    menuList->menuCount += 1;
    return 1;
}

/* line 503 */
qboolean Item_Parse(int handle, const char (*item)[4])
{
    keywordHash_t *hash;
    pc_token_t token;

    if (!PC_ReadTokenHandle(handle, &token) || token.string[0] != '{')
        return 0;

    for (;;) {
        memset(&token, 0, sizeof(token));

        if (!PC_ReadTokenHandle(handle, &token)) {
            PC_SourceError(handle, "end of file inside menu item");
            return 0;
        }

        if (token.string[0] == '}')
            return 1;

        hash = itemParseKeywordHash[UI_KeywordHashKey(token.string)];
        while (hash != NULL && I_stricmp(hash->keyword, token.string) != 0)
            hash = UI_KeywordHashNext(hash);

        if (hash == NULL) {
            PC_SourceError(handle, "unknown menu item keyword %s", token.string);
            continue;
        }

        if (!((qboolean (*)(const char (*)[4], int))hash->func)(item, handle)) {
            PC_SourceError(handle, "couldn't parse menu item keyword %s", token.string);
            return 0;
        }
    }
}

/* line 938 */
qboolean MenuParse_itemDef(const char (*item)[4], int handle)
{
    itemDef_t *itemDef;
    itemDef_t **items;
    byte *menuBytes;
    byte *itemBytes;
    int itemCount;
    int imageTrack;

    menuBytes = (byte *)item;
    itemCount = *(int *)(menuBytes + 0x218);
    if (itemCount > 0xff)
        return 1;

    items = *(itemDef_t ***)(menuBytes + 0x27c);
    itemDef = (itemDef_t *)UI_Alloc(0x2f4, 4);
    items[itemCount] = itemDef;

    imageTrack = *(int *)(menuBytes + 0x258);
    itemBytes = (byte *)itemDef;
    memset(itemDef, 0, 0x2f4);
    *(float *)(itemBytes + 0x28c) = 0.55f;
    *(int *)(itemBytes + 0x2f0) = imageTrack;

    memset(itemDef, 0, 0x210);
    *(float *)(itemBytes + 0xe0) = 1.0f;
    *(float *)(itemBytes + 0x1d8) = 1.0f;
    *(float *)(itemBytes + 0x1d4) = 1.0f;
    *(float *)(itemBytes + 0x1d0) = 1.0f;
    *(float *)(itemBytes + 0x1cc) = 1.0f;
    *(int *)(itemBytes + 0xcc) = -1;

    if (!Item_Parse(handle, (const char (*)[4])itemDef))
        return 0;

    Item_InitControls((const char (*)[4])itemDef);

    *(const char (**)[4])(itemBytes + 0x29c) = item;
    *(int *)(menuBytes + 0x218) = itemCount + 1;
    return 1;
}

/* line 2225 */
__attribute__((naked))
void Item_SetupKeywordHash(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2225 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl $0x800, 8(%esp)\n" /* line 2229 */
        "movl $0, 4(%esp)\n"
        "movl $itemParseKeywordHash, (%esp)\n"
        "calll memset\n"
        "movl itemParseKeywords, %ecx\n" /* line 2230 */
        "testl %ecx, %ecx\n"
        "je .Lf1a7400_001a751d\n"
        "movl $itemParseKeywords, -0x1c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "jmp .Lf1a7400_001a748d\n"
        /* { scope 1: keyword */
        /* { scope 2: hash */
        /* { scope 3 */
        ".Lf1a7400_001a7443:\n"
        "movl $0, -0x20(%ebp)\n" /* line 461 | hash */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf1a7400_001a744e:\n"
        "xorl -0x20(%ebp), %edx\n" /* line 478 | hash */
        "xorl %edx, %eax\n"
        "andl $0x1ff, %eax\n"
        "shll $2, %eax\n"
        "movl itemParseKeywordHash(%eax), %edx\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl %edx, itemParseKeywords+8(%ecx)\n"
        "movl -0x28(%ebp), %edx\n" /* line 479 | key */
        "movl %edx, itemParseKeywordHash(%eax)\n"
        /* } scope */
        "addl $0xc, %ecx\n" /* line 2230 */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl 0xc(%ecx), %eax\n"
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf1a7400_001a751d\n"
        ".Lf1a7400_001a748d:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2232 */
        "addl $itemParseKeywords, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* key */
        /* { scope 1: keyword */
        "movl -0x2c(%ebp), %edx\n" /* line 477 */
        "movl itemParseKeywords(%edx), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* keyword */
        /* { scope 2: hash */
        /* { scope 3 */
        "movzbl (%edx), %eax\n" /* line 461 */
        "testb %al, %al\n"
        "je .Lf1a7400_001a7443\n"
        "movl %edx, %ebx\n"
        "movl %edx, %esi\n"
        "addl $1, %ebx\n"
        "movl $0, -0x20(%ebp)\n" /* hash */
        "movl $0x77, %edi\n"
        "jmp .Lf1a7400_001a74e0\n"
        ".Lf1a7400_001a74c0:\n"
        "movsbl (%esi), %eax\n" /* line 464 */
        "addl $0x20, %eax\n"
        "imull %edi, %eax\n"
        "addl %eax, -0x20(%ebp)\n" /* hash */
        "movl %ebx, %esi\n" /* line 466 */
        "movl -0x24(%ebp), %ecx\n" /* line 461 | keyword */
        "movzbl -0x76(%ecx, %edi), %eax\n"
        "addl $1, %ebx\n"
        "addl $1, %edi\n"
        "testb %al, %al\n"
        "je .Lf1a7400_001a750c\n"
        ".Lf1a7400_001a74e0:\n"
        "movsbl %al, %eax\n" /* line 463 */
        "movl %eax, (%esp)\n"
        "calll I_isupper\n"
        "testb %al, %al\n"
        "jne .Lf1a7400_001a74c0\n"
        "movsbl (%esi), %eax\n" /* line 466 */
        "imull %edi, %eax\n"
        "addl %eax, -0x20(%ebp)\n" /* hash */
        "movl %ebx, %esi\n"
        "movl -0x24(%ebp), %ecx\n" /* line 461 | keyword */
        "movzbl -0x76(%ecx, %edi), %eax\n"
        "addl $1, %ebx\n"
        "addl $1, %edi\n"
        "testb %al, %al\n"
        "jne .Lf1a7400_001a74e0\n"
        ".Lf1a7400_001a750c:\n"
        "movl -0x20(%ebp), %edx\n" /* hash */
        "sarl $0xa, %edx\n"
        "movl -0x20(%ebp), %eax\n" /* hash */
        "sarl $0x14, %eax\n"
        "jmp .Lf1a7400_001a744e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1a7400_001a751d:\n"
        "addl $0x3c, %esp\n" /* line 2234 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1077 */
__attribute__((naked))
void Menu_SetupKeywordHash(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1077 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl $0x800, 8(%esp)\n" /* line 1081 */
        "movl $0, 4(%esp)\n"
        "movl $menuParseKeywordHash, (%esp)\n"
        "calll memset\n"
        "movl menuParseKeywords, %ebx\n" /* line 1082 */
        "testl %ebx, %ebx\n"
        "je .Lf1a7526_001a7643\n"
        "movl $menuParseKeywords, -0x1c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "jmp .Lf1a7526_001a75b3\n"
        /* { scope 1: keyword */
        /* { scope 2: hash */
        /* { scope 3 */
        ".Lf1a7526_001a7569:\n"
        "movl $0, -0x20(%ebp)\n" /* line 461 | hash */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf1a7526_001a7574:\n"
        "xorl -0x20(%ebp), %edx\n" /* line 478 | hash */
        "xorl %edx, %eax\n"
        "andl $0x1ff, %eax\n"
        "shll $2, %eax\n"
        "movl menuParseKeywordHash(%eax), %edx\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl %edx, menuParseKeywords+8(%ecx)\n"
        "movl -0x28(%ebp), %edx\n" /* line 479 | key */
        "movl %edx, menuParseKeywordHash(%eax)\n"
        /* } scope */
        "addl $0xc, %ecx\n" /* line 1082 */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl 0xc(%ecx), %eax\n"
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf1a7526_001a7643\n"
        ".Lf1a7526_001a75b3:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1084 */
        "addl $menuParseKeywords, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* key */
        /* { scope 1: keyword */
        "movl -0x2c(%ebp), %edx\n" /* line 477 */
        "movl menuParseKeywords(%edx), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* keyword */
        /* { scope 2: hash */
        /* { scope 3 */
        "movzbl (%edx), %eax\n" /* line 461 */
        "testb %al, %al\n"
        "je .Lf1a7526_001a7569\n"
        "movl %edx, %ebx\n"
        "movl %edx, %esi\n"
        "addl $1, %ebx\n"
        "movl $0, -0x20(%ebp)\n" /* hash */
        "movl $0x77, %edi\n"
        "jmp .Lf1a7526_001a7606\n"
        ".Lf1a7526_001a75e6:\n"
        "movsbl (%esi), %eax\n" /* line 464 */
        "addl $0x20, %eax\n"
        "imull %edi, %eax\n"
        "addl %eax, -0x20(%ebp)\n" /* hash */
        "movl %ebx, %esi\n" /* line 466 */
        "movl -0x24(%ebp), %ecx\n" /* line 461 | keyword */
        "movzbl -0x76(%ecx, %edi), %eax\n"
        "addl $1, %ebx\n"
        "addl $1, %edi\n"
        "testb %al, %al\n"
        "je .Lf1a7526_001a7632\n"
        ".Lf1a7526_001a7606:\n"
        "movsbl %al, %eax\n" /* line 463 */
        "movl %eax, (%esp)\n"
        "calll I_isupper\n"
        "testb %al, %al\n"
        "jne .Lf1a7526_001a75e6\n"
        "movsbl (%esi), %eax\n" /* line 466 */
        "imull %edi, %eax\n"
        "addl %eax, -0x20(%ebp)\n" /* hash */
        "movl %ebx, %esi\n"
        "movl -0x24(%ebp), %ecx\n" /* line 461 | keyword */
        "movzbl -0x76(%ecx, %edi), %eax\n"
        "addl $1, %ebx\n"
        "addl $1, %edi\n"
        "testb %al, %al\n"
        "jne .Lf1a7526_001a7606\n"
        ".Lf1a7526_001a7632:\n"
        "movl -0x20(%ebp), %edx\n" /* hash */
        "sarl $0xa, %edx\n"
        "movl -0x20(%ebp), %eax\n" /* hash */
        "sarl $0x14, %eax\n"
        "jmp .Lf1a7526_001a7574\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1a7526_001a7643:\n"
        "addl $0x3c, %esp\n" /* line 1086 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 567 */
qboolean MenuParse_name(const char (*item)[4], int handle)
{
    char token[0x418];
    if (!PC_ReadTokenHandle(handle, token))
        return 0;
    *(const char **)((char *)item + 0xc0) = String_Alloc(token + 0x10);
    return 1;
}

/* line 798 */
qboolean MenuParse_background(const char (*item)[4], int handle)
{
    char token[0x418];
    char name[0x40];
    if (!PC_ReadTokenHandle(handle, token))
        return 0;
    I_strncpyz(name, String_Alloc(token + 0x10), 0x40);
    I_strlwr(name);
    *(void **)((char *)item + 0x20c) = CL_RegisterMaterialNoMip(name, *(int *)((char *)item + 0x258));
    return 1;
}

/* line 814 */
qboolean MenuParse_cinematic(const char (*item)[4], int handle)
{
    char token[0x418];
    if (!PC_ReadTokenHandle(handle, token))
        return 0;
    *(const char **)((char *)item + 0xc8) = String_Alloc(token + 0x10);
    return 1;
}

/* line 1159 */
qboolean ItemParse_name(const char (*item)[4], int handle)
{
    char token[0x418];
    if (!PC_ReadTokenHandle(handle, token))
        return 0;
    *(const char **)((char *)item + 0xc0) = String_Alloc(token + 0x10);
    return 1;
}

/* line 1166 */
__attribute__((naked))
qboolean ItemParse_focusSound(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1166 */
        "movl %esp, %ebp\n"
        "subl $0x428, %esp\n"
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x418(%ebp), %eax\n" /* line 341 | token */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* handle */
        "movl %eax, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a779a_001a77be\n"
        /* } scope */
        /* } scope */
        "leave\n" /* line 1174 */
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a779a_001a77be:\n"
        "leal -0x408(%ebp), %eax\n" /* line 344 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 1172 */
        "calll Com_FindSoundAlias\n"
        "movl 8(%ebp), %edx\n" /* item */
        "movl %eax, 0x2d4(%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        "leave\n" /* line 1174 */
        "retl\n"
    );
}

/* line 1178 */
qboolean ItemParse_text(const char (*item)[4], int handle)
{
    char token[0x418];
    if (!PC_ReadTokenHandle(handle, token))
        return 0;
    *(const char **)((char *)item + 0x294) = String_Alloc(token + 0x10);
    return 1;
}

/* line 1211 */
qboolean ItemParse_group(const char (*item)[4], int handle)
{
    char token[0x418];
    if (!PC_ReadTokenHandle(handle, token))
        return 0;
    *(const char **)((char *)item + 0xc4) = String_Alloc(token + 0x10);
    return 1;
}

/* line 1656 */
qboolean ItemParse_background(const char (*item)[4], int handle)
{
    char token[0x418];
    char name[0x40];
    if (!PC_ReadTokenHandle(handle, token))
        return 0;
    I_strncpyz(name, String_Alloc(token + 0x10), 0x40);
    I_strlwr(name);
    *(void **)((char *)item + 0x20c) = CL_RegisterMaterialNoMip(name, *(int *)((char *)item + 0x2f0));
    return 1;
}

/* line 1671 */
qboolean ItemParse_cinematic(const char (*item)[4], int handle)
{
    char token[0x418];
    if (!PC_ReadTokenHandle(handle, token))
        return 0;
    *(const char **)((char *)item + 0xc8) = String_Alloc(token + 0x10);
    return 1;
}

/* line 1796 */
qboolean ItemParse_dvarTest(const char (*item)[4], int handle)
{
    char token[0x418];
    if (!PC_ReadTokenHandle(handle, token))
        return 0;
    *(const char **)((char *)item + 0x2c4) = String_Alloc(token + 0x10);
    return 1;
}

/* line 1806 */
qboolean ItemParse_dvar(const char (*item)[4], int handle)
{
    itemDef_t *itemDef;
    pc_token_t token;

    itemDef = (itemDef_t *)item;
    if (!PC_ReadTokenHandle(handle, &token)) {
        return 0;
    }

    itemDef->dvar = String_Alloc(token.string);
    Item_InitDvarEditField(itemDef);
    return 1;
}

/* line 2022 */
__attribute__((naked))
qboolean ItemParse_dvarEnumList(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2022 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl 8(%ebp), %esi\n" /* item */
        "movl 0xc(%ebp), %ebx\n" /* handle */
        "movl %ebx, %edx\n" /* line 2024 | handle */
        "movl %esi, %eax\n" /* item */
        "calll Item_ValidateTypeData\n"
        "cmpl $0xd, 0x270(%esi)\n" /* line 2025 | item */
        "je .Lf1a7a0a_001a7a39\n"
        /* { scope 1 */
        ".Lf1a7a0a_001a7a2d:\n"
        "xorl %eax, %eax\n" /* line 344 */
        /* } scope */
        ".Lf1a7a0a_001a7a2f:\n"
        "addl $0x420, %esp\n" /* line 2033 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1a7a0a_001a7a39:\n"
        "movl 0x2ec(%esi), %eax\n" /* line 2027 | item */
        "testl %eax, %eax\n"
        "je .Lf1a7a0a_001a7a5f\n"
        "movl $str_002b4264, 4(%esp)\n" /* line 2029 */
        "movl %ebx, (%esp)\n" /* handle */
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        "addl $0x420, %esp\n" /* line 2033 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a7a0a_001a7a5f:\n"
        "leal -0x418(%ebp), %eax\n" /* line 341 | token */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7a0a_001a7a2d\n"
        "leal -0x408(%ebp), %eax\n" /* line 344 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, 0x2ec(%esi)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a7a0a_001a7a2f\n"
    );
}

/* line 1646 */
__attribute__((naked))
qboolean ItemParse_outlinecolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1646 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %ebx\n" /* item */
        "addl $0x1fc, %ebx\n"
        "movl $4, %edi\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7a90_001a7aad:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7a90_001a7b14\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a7a90_001a7afe\n"
        "xorl %eax, %eax\n"
        ".Lf1a7a90_001a7ace:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a7a90_001a7b21\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7a90_001a7afe:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a7a90_001a7b4d\n"
        ".Lf1a7a90_001a7b14:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a7a90_001a7b16:\n"
        "addl $0x42c, %esp\n" /* line 1653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7a90_001a7b21:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a7a90_001a7b45\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a7a90_001a7b30:\n"
        "movl %eax, (%ebx)\n" /* line 264 */
        "addl $4, %ebx\n"
        "subl $1, %edi\n" /* line 258 */
        "jne .Lf1a7a90_001a7aad\n"
        "movl $1, %eax\n"
        "jmp .Lf1a7a90_001a7b16\n"
        /* { scope 2 */
        ".Lf1a7a90_001a7b45:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a7a90_001a7b30\n"
        ".Lf1a7a90_001a7b4d:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a7a90_001a7ace\n"
    );
}

/* line 786 */
__attribute__((naked))
qboolean MenuParse_outlinecolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 786 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %ebx\n" /* item */
        "addl $0x1fc, %ebx\n"
        "movl $4, %edi\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7b58_001a7b75:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7b58_001a7bdc\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a7b58_001a7bc6\n"
        "xorl %eax, %eax\n"
        ".Lf1a7b58_001a7b96:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a7b58_001a7be9\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 795 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7b58_001a7bc6:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a7b58_001a7c15\n"
        ".Lf1a7b58_001a7bdc:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a7b58_001a7bde:\n"
        "addl $0x42c, %esp\n" /* line 795 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7b58_001a7be9:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a7b58_001a7c0d\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a7b58_001a7bf8:\n"
        "movl %eax, (%ebx)\n" /* line 264 */
        "addl $4, %ebx\n"
        "subl $1, %edi\n" /* line 258 */
        "jne .Lf1a7b58_001a7b75\n"
        "movl $1, %eax\n"
        "jmp .Lf1a7b58_001a7bde\n"
        /* { scope 2 */
        ".Lf1a7b58_001a7c0d:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a7b58_001a7bf8\n"
        ".Lf1a7b58_001a7c15:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a7b58_001a7b96\n"
    );
}

/* line 307 */
__attribute__((naked))
qboolean PC_Rect_Parse(int handle, rectDef_t *r)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 307 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* handle */
        /* { scope 1: token */
        "leal -0x428(%ebp), %esi\n" /* line 188 | token */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7df1\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a7c22_001a7de1\n"
        "xorl %eax, %eax\n"
        ".Lf1a7c22_001a7c5a:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "jne .Lf1a7c22_001a7dfe\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a7c22_001a7e25\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* r */
        "movl %eax, (%edx)\n"
        /* } scope */
        ".Lf1a7c22_001a7c7f:\n"
        "movl 0xc(%ebp), %edi\n" /* line 311 | r, f */
        "addl $4, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "movl %esi, 4(%esp)\n" /* line 188 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7df1\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a7c22_001a7e4c\n"
        "xorl %eax, %eax\n"
        ".Lf1a7c22_001a7ca8:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "jne .Lf1a7c22_001a7dfe\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a7c22_001a7e3f\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        /* } scope */
        /* } scope */
        ".Lf1a7c22_001a7cca:\n"
        "movl 0xc(%ebp), %edi\n" /* line 313 | r, f */
        "addl $8, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "movl %esi, 4(%esp)\n" /* line 188 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7df1\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a7c22_001a7e73\n"
        "xorl %eax, %eax\n"
        ".Lf1a7c22_001a7cf3:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "jne .Lf1a7c22_001a7dfe\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a7c22_001a7e66\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        /* } scope */
        /* } scope */
        ".Lf1a7c22_001a7d15:\n"
        "movl 0xc(%ebp), %edi\n" /* line 315 | r, f */
        "addl $0xc, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "movl %esi, 4(%esp)\n" /* line 188 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7df1\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a7c22_001a7ed5\n"
        "xorl %eax, %eax\n"
        ".Lf1a7c22_001a7d3e:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "jne .Lf1a7c22_001a7dfe\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a7c22_001a7ec8\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        /* } scope */
        /* } scope */
        ".Lf1a7c22_001a7d60:\n"
        "movl 0xc(%ebp), %edi\n" /* line 317 | r, i */
        "addl $0x10, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "movl %esi, 4(%esp)\n" /* line 225 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadLineHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a7c22_001a7e91\n"
        /* } scope */
        /* } scope */
        ".Lf1a7c22_001a7d7a:\n"
        "movl 0xc(%ebp), %eax\n" /* line 318 | r */
        "movl $0, 0x10(%eax)\n"
        ".Lf1a7c22_001a7d84:\n"
        "movl 0xc(%ebp), %edi\n" /* line 320 | r, i */
        "addl $0x14, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "movl %esi, 4(%esp)\n" /* line 225 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadLineHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7dd0\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 229 */
        "je .Lf1a7c22_001a7f2a\n"
        "xorl %edx, %edx\n"
        ".Lf1a7c22_001a7da9:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 235 | token */
        "je .Lf1a7c22_001a7ef3\n"
        "leal -0x418(%ebp), %eax\n" /* line 237 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %ebx, (%esp)\n"
        "calll PC_SourceError\n"
        /* } scope */
        /* } scope */
        ".Lf1a7c22_001a7dd0:\n"
        "movl 0xc(%ebp), %edx\n" /* line 321 | r */
        "movl $0, 0x14(%edx)\n"
        ".Lf1a7c22_001a7dda:\n"
        "movl $1, %eax\n"
        "jmp .Lf1a7c22_001a7df3\n"
        /* { scope 1: token */
        ".Lf1a7c22_001a7de1:\n"
        "movl %esi, 4(%esp)\n" /* line 194 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a7c22_001a7e35\n"
        /* } scope */
        ".Lf1a7c22_001a7df1:\n"
        "xorl %eax, %eax\n" /* line 321 */
        ".Lf1a7c22_001a7df3:\n"
        "addl $0x42c, %esp\n" /* line 329 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7c22_001a7dfe:\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %ebx, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 329 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lf1a7c22_001a7e25:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl 0xc(%ebp), %edx\n" /* r */
        "movl %eax, (%edx)\n"
        "jmp .Lf1a7c22_001a7c7f\n"
        ".Lf1a7c22_001a7e35:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a7c22_001a7c5a\n"
        /* } scope */
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7c22_001a7e3f:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "jmp .Lf1a7c22_001a7cca\n"
        ".Lf1a7c22_001a7e4c:\n"
        "movl %esi, 4(%esp)\n" /* line 194 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7df1\n"
        "movl $1, %eax\n"
        "jmp .Lf1a7c22_001a7ca8\n"
        /* } scope */
        /* } scope */
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7c22_001a7e66:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "jmp .Lf1a7c22_001a7d15\n"
        ".Lf1a7c22_001a7e73:\n"
        "movl %esi, 4(%esp)\n" /* line 194 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7df1\n"
        "movl $1, %eax\n"
        "jmp .Lf1a7c22_001a7cf3\n"
        /* } scope */
        /* } scope */
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7c22_001a7e91:\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 229 */
        "je .Lf1a7c22_001a7f48\n"
        "xorl %edx, %edx\n"
        ".Lf1a7c22_001a7ea0:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 235 | token */
        "je .Lf1a7c22_001a7f11\n"
        "leal -0x418(%ebp), %eax\n" /* line 237 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %ebx, (%esp)\n"
        "calll PC_SourceError\n"
        "jmp .Lf1a7c22_001a7d7a\n"
        /* } scope */
        /* } scope */
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7c22_001a7ec8:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "jmp .Lf1a7c22_001a7d60\n"
        ".Lf1a7c22_001a7ed5:\n"
        "movl %esi, 4(%esp)\n" /* line 194 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7df1\n"
        "movl $1, %eax\n"
        "jmp .Lf1a7c22_001a7d3e\n"
        /* } scope */
        /* } scope */
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7c22_001a7ef3:\n"
        "movl -0x420(%ebp), %eax\n" /* line 240 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 241 */
        "je .Lf1a7c22_001a7dda\n"
        "negl %eax\n" /* line 242 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a7c22_001a7df3\n"
        /* } scope */
        /* } scope */
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7c22_001a7f11:\n"
        "movl -0x420(%ebp), %eax\n" /* line 240 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 241 */
        "je .Lf1a7c22_001a7d84\n"
        "negl %eax\n" /* line 242 */
        "movl %eax, (%edi)\n"
        "jmp .Lf1a7c22_001a7d84\n"
        /* } scope */
        /* } scope */
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7c22_001a7f2a:\n"
        "movl %esi, 4(%esp)\n" /* line 231 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadLineHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7dd0\n"
        "movl $1, %edx\n"
        "jmp .Lf1a7c22_001a7da9\n"
        /* } scope */
        /* } scope */
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7c22_001a7f48:\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll PC_ReadLineHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7c22_001a7d7a\n"
        "movl $1, %edx\n"
        "jmp .Lf1a7c22_001a7ea0\n"
    );
}

/* line 1218 */
__attribute__((naked))
qboolean ItemParse_rect(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1218 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1 */
        "leal -0x20(%ebp), %ebx\n" /* line 1221 | rectClient */
        "movl %ebx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* handle */
        "movl %eax, (%esp)\n"
        "calll PC_Rect_Parse\n"
        "testl %eax, %eax\n"
        "je .Lf1a7f66_001a7f97\n"
        "movl %ebx, 4(%esp)\n" /* line 1224 */
        "movl 8(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Window_SetRectClient\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1a7f66_001a7f97:\n"
        "addl $0x34, %esp\n" /* line 1226 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 587 */
__attribute__((naked))
qboolean MenuParse_rect(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 587 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1 */
        "leal -0x20(%ebp), %ebx\n" /* line 592 | rect */
        "movl %ebx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* handle */
        "movl %eax, (%esp)\n"
        "calll PC_Rect_Parse\n"
        "testl %eax, %eax\n"
        "je .Lf1a7f9e_001a7fcf\n"
        "movl %ebx, 4(%esp)\n" /* line 596 */
        "movl 8(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Window_SetRect\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1a7f9e_001a7fcf:\n"
        "addl $0x34, %esp\n" /* line 598 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 680 */
__attribute__((naked))
qboolean MenuParse_borderSize(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 680 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 684 | item, f */
        "addl $0xe0, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7fd6_001a805b\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a7fd6_001a8085\n"
        "xorl %eax, %eax\n"
        ".Lf1a7fd6_001a800f:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a7fd6_001a803f\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 689 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7fd6_001a803f:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a7fd6_001a8068\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 689 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7fd6_001a805b:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 689 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7fd6_001a8068:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 689 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a7fd6_001a8085:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a7fd6_001a805b\n"
        "movl $1, %eax\n"
        "jmp .Lf1a7fd6_001a800f\n"
    );
}

/* line 692 */
__attribute__((naked))
qboolean MenuParse_backcolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 692 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %ebx\n" /* item */
        "movl $4, %edi\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a80a0_001a80b7:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a80a0_001a811e\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a80a0_001a8108\n"
        "xorl %eax, %eax\n"
        ".Lf1a80a0_001a80d8:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a80a0_001a812b\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 707 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a80a0_001a8108:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a80a0_001a815b\n"
        ".Lf1a80a0_001a811e:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a80a0_001a8120:\n"
        "addl $0x42c, %esp\n" /* line 707 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a80a0_001a812b:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a80a0_001a8153\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a80a0_001a813a:\n"
        "movl %eax, 0x1dc(%ebx)\n" /* line 704 */
        "addl $4, %ebx\n"
        "subl $1, %edi\n" /* line 698 */
        "jne .Lf1a80a0_001a80b7\n"
        "movl $1, %eax\n"
        "jmp .Lf1a80a0_001a8120\n"
        /* { scope 2 */
        ".Lf1a80a0_001a8153:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a80a0_001a813a\n"
        ".Lf1a80a0_001a815b:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a80a0_001a80d8\n"
    );
}

/* line 710 */
__attribute__((naked))
qboolean MenuParse_forecolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 710 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %esi\n" /* item */
        "movl 0xc(%ebp), %edi\n" /* handle */
        /* { scope 1: token */
        "movl %esi, %ebx\n" /* line 715 | item */
        /* { scope 2 */
        ".Lf1a8166_001a817a:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8166_001a81e1\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8166_001a81cb\n"
        "xorl %eax, %eax\n"
        ".Lf1a8166_001a819b:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8166_001a81ee\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %edi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 729 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8166_001a81cb:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a8166_001a8237\n"
        ".Lf1a8166_001a81e1:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a8166_001a81e3:\n"
        "addl $0x42c, %esp\n" /* line 729 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8166_001a81ee:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a8166_001a822f\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a8166_001a81fd:\n"
        "movl %eax, 0x1cc(%ebx)\n" /* line 723 */
        "movl 0xe8(%esi), %eax\n" /* line 726 | item */
        "orl $0x10000, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Window_SetDynamicFlags\n"
        "addl $4, %ebx\n"
        "leal 0x10(%esi), %eax\n" /* line 717 | item */
        "cmpl %ebx, %eax\n"
        "jne .Lf1a8166_001a817a\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8166_001a81e3\n"
        /* { scope 2 */
        ".Lf1a8166_001a822f:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a8166_001a81fd\n"
        ".Lf1a8166_001a8237:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a8166_001a819b\n"
    );
}

/* line 732 */
__attribute__((naked))
qboolean MenuParse_bordercolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 732 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %ebx\n" /* item */
        "movl $4, %edi\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8242_001a8259:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8242_001a82c0\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8242_001a82aa\n"
        "xorl %eax, %eax\n"
        ".Lf1a8242_001a827a:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8242_001a82cd\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 747 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8242_001a82aa:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a8242_001a82fd\n"
        ".Lf1a8242_001a82c0:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a8242_001a82c2:\n"
        "addl $0x42c, %esp\n" /* line 747 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8242_001a82cd:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a8242_001a82f5\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a8242_001a82dc:\n"
        "movl %eax, 0x1ec(%ebx)\n" /* line 744 */
        "addl $4, %ebx\n"
        "subl $1, %edi\n" /* line 738 */
        "jne .Lf1a8242_001a8259\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8242_001a82c2\n"
        /* { scope 2 */
        ".Lf1a8242_001a82f5:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a8242_001a82dc\n"
        ".Lf1a8242_001a82fd:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a8242_001a827a\n"
    );
}

/* line 750 */
__attribute__((naked))
qboolean MenuParse_focuscolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 750 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %ebx\n" /* item */
        "movl $4, %edi\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8308_001a831f:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8308_001a8386\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8308_001a8370\n"
        "xorl %eax, %eax\n"
        ".Lf1a8308_001a8340:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8308_001a8393\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8308_001a8370:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a8308_001a83c3\n"
        ".Lf1a8308_001a8386:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a8308_001a8388:\n"
        "addl $0x42c, %esp\n" /* line 765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8308_001a8393:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a8308_001a83bb\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a8308_001a83a2:\n"
        "movl %eax, 0x25c(%ebx)\n" /* line 762 */
        "addl $4, %ebx\n"
        "subl $1, %edi\n" /* line 756 */
        "jne .Lf1a8308_001a831f\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8308_001a8388\n"
        /* { scope 2 */
        ".Lf1a8308_001a83bb:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a8308_001a83a2\n"
        ".Lf1a8308_001a83c3:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a8308_001a8340\n"
    );
}

/* line 768 */
__attribute__((naked))
qboolean MenuParse_disablecolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 768 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %ebx\n" /* item */
        "movl $4, %edi\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a83ce_001a83e5:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a83ce_001a844c\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a83ce_001a8436\n"
        "xorl %eax, %eax\n"
        ".Lf1a83ce_001a8406:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a83ce_001a8459\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a83ce_001a8436:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a83ce_001a8489\n"
        ".Lf1a83ce_001a844c:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a83ce_001a844e:\n"
        "addl $0x42c, %esp\n" /* line 783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a83ce_001a8459:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a83ce_001a8481\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a83ce_001a8468:\n"
        "movl %eax, 0x26c(%ebx)\n" /* line 780 */
        "addl $4, %ebx\n"
        "subl $1, %edi\n" /* line 774 */
        "jne .Lf1a83ce_001a83e5\n"
        "movl $1, %eax\n"
        "jmp .Lf1a83ce_001a844e\n"
        /* { scope 2 */
        ".Lf1a83ce_001a8481:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a83ce_001a8468\n"
        ".Lf1a83ce_001a8489:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a83ce_001a8406\n"
    );
}

/* line 890 */
__attribute__((naked))
qboolean MenuParse_fadeClamp(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 890 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 894 | item, f */
        "addl $0x234, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8494_001a8519\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8494_001a8543\n"
        "xorl %eax, %eax\n"
        ".Lf1a8494_001a84cd:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8494_001a84fd\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 899 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8494_001a84fd:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a8494_001a8526\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 899 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8494_001a8519:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 899 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8494_001a8526:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 899 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8494_001a8543:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8494_001a8519\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8494_001a84cd\n"
    );
}

/* line 902 */
__attribute__((naked))
qboolean MenuParse_fadeAmount(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 902 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 906 | item, f */
        "addl $0x238, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a855e_001a85e3\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a855e_001a860d\n"
        "xorl %eax, %eax\n"
        ".Lf1a855e_001a8597:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a855e_001a85c7\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 911 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a855e_001a85c7:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a855e_001a85f0\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 911 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a855e_001a85e3:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 911 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a855e_001a85f0:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 911 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a855e_001a860d:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a855e_001a85e3\n"
        "movl $1, %eax\n"
        "jmp .Lf1a855e_001a8597\n"
    );
}

/* line 914 */
__attribute__((naked))
qboolean MenuParse_fadeInAmount(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 914 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 918 | item, f */
        "addl $0x23c, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8628_001a86ad\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8628_001a86d7\n"
        "xorl %eax, %eax\n"
        ".Lf1a8628_001a8661:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8628_001a8691\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 923 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8628_001a8691:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a8628_001a86ba\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 923 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8628_001a86ad:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 923 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8628_001a86ba:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 923 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8628_001a86d7:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8628_001a86ad\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8628_001a8661\n"
    );
}

/* line 1004 */
__attribute__((naked))
qboolean MenuParse_blurWorld(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1004 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1010 | item, f */
        "addl $0x240, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a86f2_001a876b\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a86f2_001a875b\n"
        "xorl %eax, %eax\n"
        ".Lf1a86f2_001a872b:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a86f2_001a8778\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1018 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a86f2_001a875b:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a86f2_001a87d7\n"
        /* } scope */
        /* } scope */
        ".Lf1a86f2_001a876b:\n"
        "xorl %eax, %eax\n" /* line 1015 */
        ".Lf1a86f2_001a876d:\n"
        "addl $0x42c, %esp\n" /* line 1018 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a86f2_001a8778:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a86f2_001a87af\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        /* } scope */
        /* } scope */
        ".Lf1a86f2_001a8789:\n"
        "movl 8(%ebp), %eax\n" /* line 1012 | item */
        "movss 0x240(%eax), %xmm0\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1a86f2_001a879f\n"
        "jb .Lf1a86f2_001a87b9\n"
        ".Lf1a86f2_001a879f:\n"
        "movl $1, %eax\n"
        "addl $0x42c, %esp\n" /* line 1018 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a86f2_001a87af:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "jmp .Lf1a86f2_001a8789\n"
        /* } scope */
        /* } scope */
        ".Lf1a86f2_001a87b9:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1014 */
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_002b4280, 4(%esp)\n" /* "blur must be >= 0; %g is invalid" */
        "movl %esi, (%esp)\n" /* handle */
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1a86f2_001a876d\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a86f2_001a87d7:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a86f2_001a872b\n"
    );
}

/* line 1351 */
__attribute__((naked))
qboolean ItemParse_elementwidth(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1351 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1 */
        "movl %esi, %edx\n" /* line 1355 | handle */
        "movl %ebx, %eax\n" /* item */
        "calll Item_ValidateTypeData\n"
        "movl %ebx, (%esp)\n" /* line 1356 | item */
        "calll Item_GetListBoxDef\n"
        "testl %eax, %eax\n" /* line 1357 */
        "je .Lf1a87e2_001a886d\n"
        "leal 0x34(%eax), %edi\n" /* line 1359 | f */
        /* { scope 2: token */
        /* { scope 3 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a87e2_001a886d\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a87e2_001a885d\n"
        "xorl %eax, %eax\n"
        ".Lf1a87e2_001a882d:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a87e2_001a887a\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1364 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a87e2_001a885d:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a87e2_001a88a1\n"
        ".Lf1a87e2_001a886d:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1a87e2_001a886f:\n"
        "addl $0x42c, %esp\n" /* line 1364 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a87e2_001a887a:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a87e2_001a8892\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a87e2_001a886f\n"
        ".Lf1a87e2_001a8892:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a87e2_001a886f\n"
        ".Lf1a87e2_001a88a1:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a87e2_001a882d\n"
    );
}

/* line 1369 */
__attribute__((naked))
qboolean ItemParse_elementheight(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1369 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1 */
        "movl %esi, %edx\n" /* line 1373 | handle */
        "movl %ebx, %eax\n" /* item */
        "calll Item_ValidateTypeData\n"
        "movl %ebx, (%esp)\n" /* line 1374 | item */
        "calll Item_GetListBoxDef\n"
        "testl %eax, %eax\n" /* line 1375 */
        "je .Lf1a88a8_001a8933\n"
        "leal 0x38(%eax), %edi\n" /* line 1377 | f */
        /* { scope 2: token */
        /* { scope 3 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a88a8_001a8933\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a88a8_001a8923\n"
        "xorl %eax, %eax\n"
        ".Lf1a88a8_001a88f3:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a88a8_001a8940\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1382 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a88a8_001a8923:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a88a8_001a8967\n"
        ".Lf1a88a8_001a8933:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1a88a8_001a8935:\n"
        "addl $0x42c, %esp\n" /* line 1382 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a88a8_001a8940:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a88a8_001a8958\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a88a8_001a8935\n"
        ".Lf1a88a8_001a8958:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a88a8_001a8935\n"
        ".Lf1a88a8_001a8967:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a88a8_001a88f3\n"
    );
}

/* line 1386 */
__attribute__((naked))
qboolean ItemParse_feeder(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1386 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1388 | item, f */
        "addl $0x2d8, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a896e_001a89f3\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a896e_001a8a1d\n"
        "xorl %eax, %eax\n"
        ".Lf1a896e_001a89a7:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a896e_001a89d7\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1393 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a896e_001a89d7:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a896e_001a8a00\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1393 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a896e_001a89f3:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1393 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a896e_001a8a00:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1393 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a896e_001a8a1d:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a896e_001a89f3\n"
        "movl $1, %eax\n"
        "jmp .Lf1a896e_001a89a7\n"
    );
}

/* line 1469 */
__attribute__((naked))
qboolean ItemParse_bordersize(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1469 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1471 | item, f */
        "addl $0xe0, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8a38_001a8abd\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8a38_001a8ae7\n"
        "xorl %eax, %eax\n"
        ".Lf1a8a38_001a8a71:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8a38_001a8aa1\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1476 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8a38_001a8aa1:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a8a38_001a8aca\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1476 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8a38_001a8abd:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1476 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8a38_001a8aca:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1476 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8a38_001a8ae7:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8a38_001a8abd\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8a38_001a8a71\n"
    );
}

/* line 1541 */
__attribute__((naked))
qboolean ItemParse_textalignx(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1541 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1543 | item, f */
        "addl $0x284, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8b02_001a8b87\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8b02_001a8bb1\n"
        "xorl %eax, %eax\n"
        ".Lf1a8b02_001a8b3b:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8b02_001a8b6b\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1548 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8b02_001a8b6b:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a8b02_001a8b94\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1548 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8b02_001a8b87:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1548 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8b02_001a8b94:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1548 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8b02_001a8bb1:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8b02_001a8b87\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8b02_001a8b3b\n"
    );
}

/* line 1551 */
__attribute__((naked))
qboolean ItemParse_textaligny(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1551 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1553 | item, f */
        "addl $0x288, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8bcc_001a8c51\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8bcc_001a8c7b\n"
        "xorl %eax, %eax\n"
        ".Lf1a8bcc_001a8c05:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8bcc_001a8c35\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8bcc_001a8c35:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a8bcc_001a8c5e\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8bcc_001a8c51:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8bcc_001a8c5e:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8bcc_001a8c7b:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8bcc_001a8c51\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8bcc_001a8c05\n"
    );
}

/* line 1561 */
__attribute__((naked))
qboolean ItemParse_textscale(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1561 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1563 | item, f */
        "addl $0x28c, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8c96_001a8d1b\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8c96_001a8d45\n"
        "xorl %eax, %eax\n"
        ".Lf1a8c96_001a8ccf:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8c96_001a8cff\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1568 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8c96_001a8cff:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a8c96_001a8d28\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1568 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8c96_001a8d1b:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1568 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8c96_001a8d28:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1568 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8c96_001a8d45:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8c96_001a8d1b\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8c96_001a8ccf\n"
    );
}

/* line 1591 */
__attribute__((naked))
qboolean ItemParse_backcolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1591 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %ebx\n" /* item */
        "movl $4, %edi\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8d60_001a8d77:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8d60_001a8dde\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8d60_001a8dc8\n"
        "xorl %eax, %eax\n"
        ".Lf1a8d60_001a8d98:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8d60_001a8deb\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1605 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8d60_001a8dc8:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a8d60_001a8e1b\n"
        ".Lf1a8d60_001a8dde:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a8d60_001a8de0:\n"
        "addl $0x42c, %esp\n" /* line 1605 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8d60_001a8deb:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a8d60_001a8e13\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a8d60_001a8dfa:\n"
        "movl %eax, 0x1dc(%ebx)\n" /* line 1602 */
        "addl $4, %ebx\n"
        "subl $1, %edi\n" /* line 1596 */
        "jne .Lf1a8d60_001a8d77\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8d60_001a8de0\n"
        /* { scope 2 */
        ".Lf1a8d60_001a8e13:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a8d60_001a8dfa\n"
        ".Lf1a8d60_001a8e1b:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a8d60_001a8d98\n"
    );
}

/* line 1608 */
__attribute__((naked))
qboolean ItemParse_forecolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1608 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %esi\n" /* item */
        "movl 0xc(%ebp), %edi\n" /* handle */
        "movl %esi, %ebx\n" /* item */
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8e26_001a8e3a:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8e26_001a8ea1\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8e26_001a8e8b\n"
        "xorl %eax, %eax\n"
        ".Lf1a8e26_001a8e5b:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8e26_001a8eae\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %edi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1626 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8e26_001a8e8b:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a8e26_001a8ef7\n"
        ".Lf1a8e26_001a8ea1:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a8e26_001a8ea3:\n"
        "addl $0x42c, %esp\n" /* line 1626 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8e26_001a8eae:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a8e26_001a8eef\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a8e26_001a8ebd:\n"
        "movl %eax, 0x1cc(%ebx)\n" /* line 1620 */
        "movl 0xe8(%esi), %eax\n" /* line 1623 | item */
        "orl $0x10000, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Window_SetDynamicFlags\n"
        "addl $4, %ebx\n"
        "leal 0x10(%esi), %eax\n" /* line 1614 | item */
        "cmpl %ebx, %eax\n"
        "jne .Lf1a8e26_001a8e3a\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8e26_001a8ea3\n"
        /* { scope 2 */
        ".Lf1a8e26_001a8eef:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a8e26_001a8ebd\n"
        ".Lf1a8e26_001a8ef7:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a8e26_001a8e5b\n"
    );
}

/* line 1629 */
__attribute__((naked))
qboolean ItemParse_bordercolor(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1629 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %ebx\n" /* item */
        "movl $4, %edi\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8f02_001a8f19:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8f02_001a8f80\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8f02_001a8f6a\n"
        "xorl %eax, %eax\n"
        ".Lf1a8f02_001a8f3a:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8f02_001a8f8d\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1643 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8f02_001a8f6a:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a8f02_001a8fbd\n"
        ".Lf1a8f02_001a8f80:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        ".Lf1a8f02_001a8f82:\n"
        "addl $0x42c, %esp\n" /* line 1643 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8f02_001a8f8d:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a8f02_001a8fb5\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1a8f02_001a8f9c:\n"
        "movl %eax, 0x1ec(%ebx)\n" /* line 1640 */
        "addl $4, %ebx\n"
        "subl $1, %edi\n" /* line 1634 */
        "jne .Lf1a8f02_001a8f19\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8f02_001a8f82\n"
        /* { scope 2 */
        ".Lf1a8f02_001a8fb5:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1a8f02_001a8f9c\n"
        ".Lf1a8f02_001a8fbd:\n"
        "movl $1, %eax\n" /* line 194 */
        "jmp .Lf1a8f02_001a8f3a\n"
    );
}

/* line 1786 */
__attribute__((naked))
qboolean ItemParse_special(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1786 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1788 | item, f */
        "addl $0x2d8, %edi\n" /* f */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8fc8_001a904d\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a8fc8_001a9077\n"
        "xorl %eax, %eax\n"
        ".Lf1a8fc8_001a9001:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "je .Lf1a8fc8_001a9031\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1793 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8fc8_001a9031:\n"
        "testl %eax, %eax\n" /* line 203 */
        "jne .Lf1a8fc8_001a905a\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1793 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8fc8_001a904d:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1793 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8fc8_001a905a:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%edi)\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1793 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a8fc8_001a9077:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a8fc8_001a904d\n"
        "movl $1, %eax\n"
        "jmp .Lf1a8fc8_001a9001\n"
    );
}

/* line 1888 */
__attribute__((naked))
qboolean ItemParse_dvarFloat(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1888 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %edi\n" /* handle */
        /* { scope 1: token */
        "movl %edi, %edx\n" /* line 1892 | handle */
        "movl %ebx, %eax\n" /* item */
        "calll Item_ValidateTypeData\n"
        "movl 0x2ec(%ebx), %eax\n" /* line 1893 | item */
        "testl %eax, %eax\n"
        "je .Lf1a9092_001a90db\n"
        "movl %ebx, (%esp)\n" /* line 1895 | item */
        "calll Item_GetEditFieldDef\n"
        "movl %eax, %esi\n" /* editPtr */
        "testl %eax, %eax\n" /* line 1896 */
        "je .Lf1a9092_001a90db\n"
        /* { scope 2: token */
        "leal -0x428(%ebp), %eax\n" /* line 341 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a9092_001a90e8\n"
        /* } scope */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9092_001a90db:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1a9092_001a90dd:\n"
        "addl $0x42c, %esp\n" /* line 1903 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2: token */
        ".Lf1a9092_001a90e8:\n"
        "leal -0x418(%ebp), %eax\n" /* line 344 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, 0x2c0(%ebx)\n"
        /* } scope */
        "leal 8(%esi), %ebx\n" /* line 1898 | editPtr, f */
        /* { scope 2: token */
        /* { scope 3 */
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9092_001a90db\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a9092_001a9215\n"
        "xorl %eax, %eax\n"
        ".Lf1a9092_001a9124:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "jne .Lf1a9092_001a91e1\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a9092_001a9208\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%ebx)\n"
        /* } scope */
        /* } scope */
        /* { scope 2: token */
        ".Lf1a9092_001a9146:\n"
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9092_001a90db\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a9092_001a9246\n"
        "xorl %eax, %eax\n"
        ".Lf1a9092_001a916f:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "jne .Lf1a9092_001a91e1\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a9092_001a9239\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%esi)\n"
        /* } scope */
        ".Lf1a9092_001a918d:\n"
        "leal 4(%esi), %ebx\n" /* line 1898 | editPtr, f */
        /* { scope 2: token */
        /* { scope 3 */
        "leal -0x428(%ebp), %eax\n" /* line 188 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9092_001a90db\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 192 */
        "je .Lf1a9092_001a927c\n"
        "xorl %eax, %eax\n"
        ".Lf1a9092_001a91b9:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 198 | token */
        "jne .Lf1a9092_001a91e1\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a9092_001a926a\n"
        "movl -0x41c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%ebx)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a9092_001a90dd\n"
        ".Lf1a9092_001a91e1:\n"
        "leal -0x418(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %edi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1903 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9092_001a9208:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%ebx)\n"
        "jmp .Lf1a9092_001a9146\n"
        ".Lf1a9092_001a9215:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9092_001a90db\n"
        "movl $1, %eax\n"
        "jmp .Lf1a9092_001a9124\n"
        /* } scope */
        /* } scope */
        /* { scope 2: token */
        ".Lf1a9092_001a9239:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%esi)\n"
        "jmp .Lf1a9092_001a918d\n"
        ".Lf1a9092_001a9246:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9092_001a90db\n"
        "movl $1, %eax\n"
        "jmp .Lf1a9092_001a916f\n"
        /* } scope */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9092_001a926a:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 206 */
        "movl %eax, (%ebx)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a9092_001a90dd\n"
        ".Lf1a9092_001a927c:\n"
        "leal -0x428(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9092_001a90db\n"
        "movl $1, %eax\n"
        "jmp .Lf1a9092_001a91b9\n"
    );
}

/* line 1968 */
__attribute__((naked))
qboolean ItemParse_dvarFloatList(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1968 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x84c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1: f */
        "movl %esi, %edx\n" /* line 1973 | handle */
        "movl %ebx, %eax\n" /* item */
        "calll Item_ValidateTypeData\n"
        "movl 0x2ec(%ebx), %eax\n" /* line 1974 | item */
        "testl %eax, %eax\n"
        "je .Lf1a92a0_001a92ce\n"
        "cmpl $0xc, 0x270(%ebx)\n" /* line 1976 | item */
        "je .Lf1a92a0_001a92db\n"
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a92a0_001a92ce:\n"
        "xorl %eax, %eax\n" /* line 206 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1a92a0_001a92d0:\n"
        "addl $0x84c, %esp\n" /* line 2019 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: f */
        ".Lf1a92a0_001a92db:\n"
        "movl %ebx, (%esp)\n" /* line 1978 | item */
        "calll Item_GetMultiDef\n"
        "movl %eax, %edi\n" /* multiPtr */
        "movl $0, 0x180(%eax)\n" /* line 1980 */
        "movl $0, 0x184(%eax)\n" /* line 1981 */
        "leal -0x428(%ebp), %eax\n" /* line 1983 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a92a0_001a92ce\n"
        "cmpb $0x7b, -0x418(%ebp)\n" /* line 1985 */
        "jne .Lf1a92a0_001a92ce\n"
        ".Lf1a92a0_001a9318:\n"
        "leal -0x428(%ebp), %edx\n" /* line 1990 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a92a0_001a942e\n"
        "movzbl -0x418(%ebp), %eax\n" /* line 1996 */
        "cmpb $0x7d, %al\n"
        "je .Lf1a92a0_001a9424\n"
        "cmpb $0x2c, %al\n" /* line 2001 */
        "je .Lf1a92a0_001a9318\n"
        "cmpb $0x3b, %al\n"
        "je .Lf1a92a0_001a9318\n"
        "movl 0x180(%edi), %ebx\n" /* line 2006 | multiPtr, item */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, (%edi, %ebx, 4)\n" /* multiPtr */
        "movl 0x180(%edi), %eax\n" /* line 2007 | multiPtr */
        "leal 0x100(%edi, %eax, 4), %eax\n" /* multiPtr */
        "movl %eax, -0x83c(%ebp)\n" /* f */
        /* { scope 2: token */
        /* { scope 3 */
        "leal -0x838(%ebp), %ebx\n" /* line 188 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a92a0_001a92ce\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 192 */
        "je .Lf1a92a0_001a9406\n"
        "xorl %eax, %eax\n"
        ".Lf1a92a0_001a9398:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 198 | token */
        "je .Lf1a92a0_001a93c2\n"
        "leal -0x828(%ebp), %eax\n" /* line 200 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1a92a0_001a92d0\n"
        ".Lf1a92a0_001a93c2:\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1a92a0_001a93f6\n"
        "movl -0x82c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl -0x83c(%ebp), %edx\n" /* f */
        "movl %eax, (%edx)\n"
        /* } scope */
        /* } scope */
        ".Lf1a92a0_001a93d9:\n"
        "movl 0x180(%edi), %eax\n" /* line 2012 | multiPtr */
        "addl $1, %eax\n"
        "movl %eax, 0x180(%edi)\n" /* multiPtr */
        "cmpl $0x1f, %eax\n" /* line 2013 */
        "jle .Lf1a92a0_001a9318\n"
        "jmp .Lf1a92a0_001a92ce\n"
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a92a0_001a93f6:\n"
        "movl -0x82c(%ebp), %eax\n" /* line 206 */
        "movl -0x83c(%ebp), %edx\n" /* f */
        "movl %eax, (%edx)\n"
        "jmp .Lf1a92a0_001a93d9\n"
        ".Lf1a92a0_001a9406:\n"
        "movl %ebx, 4(%esp)\n" /* line 194 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a92a0_001a92ce\n"
        "movl $1, %eax\n"
        "jmp .Lf1a92a0_001a9398\n"
        /* } scope */
        /* } scope */
        ".Lf1a92a0_001a9424:\n"
        "movl $1, %eax\n" /* line 1996 */
        "jmp .Lf1a92a0_001a92d0\n"
        ".Lf1a92a0_001a942e:\n"
        "movl $str_002b4174, 4(%esp)\n" /* line 1992 */
        "movl %esi, (%esp)\n" /* handle */
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1a92a0_001a92d0\n"
    );
}

/* line 575 */
__attribute__((naked))
qboolean MenuParse_fullscreen(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 575 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 579 | item, i */
        "addl $0x214, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9446_001a94cf\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a9446_001a94dc\n"
        "xorl %edx, %edx\n"
        ".Lf1a9446_001a947f:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1a9446_001a94af\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9446_001a94af:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1a9446_001a94bf\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1a9446_001a94bf:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9446_001a94cf:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9446_001a94dc:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9446_001a94cf\n"
        "movl $1, %edx\n"
        "jmp .Lf1a9446_001a947f\n"
    );
}

/* line 601 */
__attribute__((naked))
qboolean MenuParse_style(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 601 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 605 | item, i */
        "addl $0xd0, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a94f4_001a957d\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a94f4_001a958a\n"
        "xorl %edx, %edx\n"
        ".Lf1a94f4_001a952d:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1a94f4_001a955d\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 610 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a94f4_001a955d:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1a94f4_001a956d\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1a94f4_001a956d:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 610 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a94f4_001a957d:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 610 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a94f4_001a958a:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a94f4_001a957d\n"
        "movl $1, %edx\n"
        "jmp .Lf1a94f4_001a952d\n"
    );
}

/* line 613 */
__attribute__((naked))
qboolean MenuParse_visible(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 613 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x418(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a95a2_001a9610\n"
        "cmpb $0x2d, -0x408(%ebp)\n" /* line 284 */
        "je .Lf1a95a2_001a9600\n"
        "xorl %edx, %edx\n"
        ".Lf1a95a2_001a95d1:\n"
        "cmpl $3, -0x418(%ebp)\n" /* line 290 | token */
        "je .Lf1a95a2_001a961c\n"
        "leal -0x408(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x420, %esp\n" /* line 629 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a95a2_001a9600:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a95a2_001a9663\n"
        /* } scope */
        ".Lf1a95a2_001a9610:\n"
        "xorl %eax, %eax\n" /* line 625 */
        /* } scope */
        "addl $0x420, %esp\n" /* line 629 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a95a2_001a961c:\n"
        "movl -0x410(%ebp), %eax\n" /* line 295 */
        "testl %edx, %edx\n" /* line 296 */
        "jne .Lf1a95a2_001a9636\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 622 */
        "jne .Lf1a95a2_001a963c\n"
        ".Lf1a95a2_001a962a:\n"
        "movb $1, %al\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 629 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a95a2_001a9636:\n"
        "negl %eax\n" /* line 297 */
        /* } scope */
        "testl %eax, %eax\n" /* line 622 */
        "je .Lf1a95a2_001a962a\n"
        ".Lf1a95a2_001a963c:\n"
        "movl 8(%ebp), %edx\n" /* line 625 | item */
        "movl 0xe8(%edx), %eax\n"
        "orl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Window_SetDynamicFlags\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 629 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a95a2_001a9663:\n"
        "movl $1, %edx\n" /* line 286 */
        "jmp .Lf1a95a2_001a95d1\n"
    );
}

/* line 668 */
__attribute__((naked))
qboolean MenuParse_border(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 668 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 672 | item, i */
        "addl $0xd4, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a966e_001a96f7\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a966e_001a9704\n"
        "xorl %edx, %edx\n"
        ".Lf1a966e_001a96a7:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1a966e_001a96d7\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 677 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a966e_001a96d7:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1a966e_001a96e7\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1a966e_001a96e7:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 677 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a966e_001a96f7:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 677 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a966e_001a9704:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a966e_001a96f7\n"
        "movl $1, %edx\n"
        "jmp .Lf1a966e_001a96a7\n"
    );
}

/* line 826 */
__attribute__((naked))
qboolean MenuParse_ownerdrawFlag(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 826 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x418(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a971c_001a978a\n"
        "cmpb $0x2d, -0x408(%ebp)\n" /* line 284 */
        "je .Lf1a971c_001a977a\n"
        "xorl %edx, %edx\n"
        ".Lf1a971c_001a974b:\n"
        "cmpl $3, -0x418(%ebp)\n" /* line 290 | token */
        "je .Lf1a971c_001a9796\n"
        "leal -0x408(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x420, %esp\n" /* line 837 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a971c_001a977a:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a971c_001a97ca\n"
        ".Lf1a971c_001a978a:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x420, %esp\n" /* line 837 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a971c_001a9796:\n"
        "movl -0x410(%ebp), %eax\n" /* line 295 */
        "testl %edx, %edx\n" /* line 296 */
        "jne .Lf1a971c_001a97b8\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 835 | item */
        "orl %eax, 0xdc(%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1a971c_001a97ae:\n"
        "addl $0x420, %esp\n" /* line 837 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a971c_001a97b8:\n"
        "negl %eax\n" /* line 297 */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 835 | item */
        "orl %eax, 0xdc(%edx)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a971c_001a97ae\n"
        /* { scope 2 */
        ".Lf1a971c_001a97ca:\n"
        "movl $1, %edx\n" /* line 286 */
        "jmp .Lf1a971c_001a974b\n"
    );
}

/* line 840 */
__attribute__((naked))
qboolean MenuParse_ownerdraw(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 840 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 844 | item, i */
        "addl $0xd8, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a97d4_001a985d\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a97d4_001a986a\n"
        "xorl %edx, %edx\n"
        ".Lf1a97d4_001a980d:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1a97d4_001a983d\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 849 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a97d4_001a983d:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1a97d4_001a984d\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1a97d4_001a984d:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 849 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a97d4_001a985d:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 849 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a97d4_001a986a:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a97d4_001a985d\n"
        "movl $1, %edx\n"
        "jmp .Lf1a97d4_001a980d\n"
    );
}

/* line 926 */
__attribute__((naked))
qboolean MenuParse_fadeCycle(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 926 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 930 | item, i */
        "addl $0x230, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9882_001a990b\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a9882_001a9918\n"
        "xorl %edx, %edx\n"
        ".Lf1a9882_001a98bb:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1a9882_001a98eb\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 935 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9882_001a98eb:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1a9882_001a98fb\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1a9882_001a98fb:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 935 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9882_001a990b:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 935 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9882_001a9918:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9882_001a990b\n"
        "movl $1, %edx\n"
        "jmp .Lf1a9882_001a98bb\n"
    );
}

/* line 982 */
__attribute__((naked))
qboolean MenuParse_execKeyInt(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 982 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x430, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x41c(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9930_001a99b1\n"
        "cmpb $0x2d, -0x40c(%ebp)\n" /* line 284 */
        "je .Lf1a9930_001a99fa\n"
        "xorl %eax, %eax\n"
        ".Lf1a9930_001a9963:\n"
        "cmpl $3, -0x41c(%ebp)\n" /* line 290 | token */
        "je .Lf1a9930_001a9992\n"
        "leal -0x40c(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x430, %esp\n" /* line 1001 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9930_001a9992:\n"
        "movl -0x414(%ebp), %ebx\n" /* line 295 */
        "testl %eax, %eax\n" /* line 296 */
        "je .Lf1a9930_001a999e\n"
        "negl %ebx\n" /* line 297 */
        /* } scope */
        ".Lf1a9930_001a999e:\n"
        "leal -0xc(%ebp), %eax\n" /* line 992 | action */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll PC_Script_Parse\n"
        "testl %eax, %eax\n"
        "jne .Lf1a9930_001a99bd\n"
        ".Lf1a9930_001a99b1:\n"
        "xorl %eax, %eax\n" /* line 1000 */
        /* } scope */
        "addl $0x430, %esp\n" /* line 1001 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lf1a9930_001a99bd:\n"
        "movl $4, 4(%esp)\n" /* line 995 */
        "movl $0xc, (%esp)\n"
        "calll UI_Alloc\n"
        "movl %ebx, (%eax)\n" /* line 996 | keyname */
        "movl -0xc(%ebp), %edx\n" /* line 997 | action */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 998 | item */
        "movl 0x250(%ecx), %edx\n"
        "movl %edx, 8(%eax)\n"
        "movl %eax, 0x250(%ecx)\n" /* line 999 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x430, %esp\n" /* line 1001 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9930_001a99fa:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9930_001a99b1\n"
        "movl $1, %eax\n"
        "jmp .Lf1a9930_001a9963\n"
    );
}

/* line 1230 */
__attribute__((naked))
qboolean ItemParse_origin(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1230 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x440(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9a14_001a9b14\n"
        "cmpb $0x2d, -0x430(%ebp)\n" /* line 284 */
        "je .Lf1a9a14_001a9b04\n"
        "xorl %eax, %eax\n"
        ".Lf1a9a14_001a9a4c:\n"
        "cmpl $3, -0x440(%ebp)\n" /* line 290 | token */
        "jne .Lf1a9a14_001a9b21\n"
        "movl -0x438(%ebp), %edi\n" /* line 295 */
        "testl %eax, %eax\n" /* line 296 */
        "jne .Lf1a9a14_001a9b48\n"
        /* } scope */
        /* { scope 2 */
        "movl %ebx, 4(%esp)\n" /* line 280 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9a14_001a9b14\n"
        ".Lf1a9a14_001a9a7b:\n"
        "cmpb $0x2d, -0x430(%ebp)\n" /* line 284 */
        "je .Lf1a9a14_001a9b70\n"
        "xorl %eax, %eax\n"
        ".Lf1a9a14_001a9a8a:\n"
        "cmpl $3, -0x440(%ebp)\n" /* line 290 | token */
        "jne .Lf1a9a14_001a9b21\n"
        "movl -0x438(%ebp), %ecx\n" /* line 295 */
        "testl %eax, %eax\n" /* line 296 */
        "jne .Lf1a9a14_001a9b69\n"
        /* } scope */
        ".Lf1a9a14_001a9aa5:\n"
        "movl 8(%ebp), %edx\n" /* line 60 | item */
        "addl $0x60, %edx\n"
        "movl 8(%ebp), %ebx\n" /* line 1242 | item */
        "movl 0x60(%ebx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* newRect */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl 0x14(%edx), %edx\n"
        "cvtsi2ssl %edi, %xmm0\n" /* line 1243 | x */
        "addss -0x30(%ebp), %xmm0\n" /* newRect */
        "movss %xmm0, -0x30(%ebp)\n" /* newRect */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 1244 */
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl %eax, -0x20(%ebp)\n" /* line 1245 */
        "movl %edx, -0x1c(%ebp)\n" /* line 1246 */
        "leal -0x30(%ebp), %eax\n" /* line 1247 | newRect */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Window_SetRectClient\n"
        "movl $1, %eax\n"
        "jmp .Lf1a9a14_001a9b16\n"
        /* { scope 2 */
        ".Lf1a9a14_001a9b04:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1a9a14_001a9b5f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1a9a14_001a9b14:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        ".Lf1a9a14_001a9b16:\n"
        "addl $0x44c, %esp\n" /* line 1250 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9a14_001a9b21:\n"
        "leal -0x430(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x44c, %esp\n" /* line 1250 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9a14_001a9b48:\n"
        "negl %edi\n" /* line 297 */
        /* } scope */
        /* { scope 2 */
        "movl %ebx, 4(%esp)\n" /* line 280 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9a14_001a9b14\n"
        "jmp .Lf1a9a14_001a9a7b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1a9a14_001a9b5f:\n"
        "movl $1, %eax\n" /* line 286 */
        "jmp .Lf1a9a14_001a9a4c\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1a9a14_001a9b69:\n"
        "negl %ecx\n" /* line 297 */
        "jmp .Lf1a9a14_001a9aa5\n"
        ".Lf1a9a14_001a9b70:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9a14_001a9b14\n"
        "movl $1, %eax\n"
        "jmp .Lf1a9a14_001a9a8a\n"
    );
}

/* line 1254 */
__attribute__((naked))
qboolean ItemParse_style(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1254 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1256 | item, i */
        "addl $0xd0, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9b8a_001a9c13\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a9b8a_001a9c20\n"
        "xorl %edx, %edx\n"
        ".Lf1a9b8a_001a9bc3:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1a9b8a_001a9bf3\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1257 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9b8a_001a9bf3:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1a9b8a_001a9c03\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1a9b8a_001a9c03:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1257 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9b8a_001a9c13:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1257 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1a9b8a_001a9c20:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9b8a_001a9c13\n"
        "movl $1, %edx\n"
        "jmp .Lf1a9b8a_001a9bc3\n"
    );
}

/* line 1338 */
qboolean ItemParse_type(const char (*item)[4], int handle)
{
    itemDef_t *itemDef;
    pc_token_t token;
    qboolean negative;

    itemDef = (itemDef_t *)item;
    negative = 0;

    if (!PC_ReadTokenHandle(handle, &token)) {
        return 0;
    }

    if (token.string[0] == '-' && token.string[1] == '\0') {
        negative = 1;
        if (!PC_ReadTokenHandle(handle, &token)) {
            return 0;
        }
    }

    if (token.type != 3) {
        PC_SourceError(handle, "expected integer but found %s\n", token.string);
        return 0;
    }

    itemDef->type = token.intvalue;
    if (negative) {
        itemDef->type = -itemDef->type;
    }

    Item_ValidateTypeData(itemDef, handle);
    Item_InitDvarEditField(itemDef);
    return 1;
}

/* line 1398 */
__attribute__((naked))
qboolean ItemParse_elementtype(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1398 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1 */
        "movl %esi, %edx\n" /* line 1402 | handle */
        "movl %ebx, %eax\n" /* item */
        "calll Item_ValidateTypeData\n"
        "movl 0x2ec(%ebx), %eax\n" /* line 1403 | item */
        "testl %eax, %eax\n"
        "je .Lf1a9d0e_001a9d93\n"
        "movl %ebx, (%esp)\n" /* line 1405 | item */
        "calll Item_GetListBoxDef\n"
        "testl %eax, %eax\n" /* line 1406 */
        "je .Lf1a9d0e_001a9d93\n"
        "leal 0x3c(%eax), %edi\n" /* line 1408 | i */
        /* { scope 2: token */
        /* { scope 3 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9d0e_001a9d93\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a9d0e_001a9dc0\n"
        "xorl %edx, %edx\n"
        ".Lf1a9d0e_001a9d63:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1a9d0e_001a9da0\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1413 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9d0e_001a9d93:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1413 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9d0e_001a9da0:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1a9d0e_001a9db0\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1a9d0e_001a9db0:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1413 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9d0e_001a9dc0:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9d0e_001a9d93\n"
        "movl $1, %edx\n"
        "jmp .Lf1a9d0e_001a9d63\n"
    );
}

/* line 1417 */
__attribute__((naked))
qboolean ItemParse_columns(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1417 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %edi\n" /* handle */
        /* { scope 1: token */
        "movl %edi, %edx\n" /* line 1422 | handle */
        "movl %ebx, %eax\n" /* listPtr */
        "calll Item_ValidateTypeData\n"
        "movl 0x2ec(%ebx), %eax\n" /* line 1423 | listPtr */
        "testl %eax, %eax\n"
        "je .Lf1a9dd8_001a9e53\n"
        "movl %ebx, (%esp)\n" /* line 1425 | listPtr */
        "calll Item_GetListBoxDef\n"
        "movl %eax, %ebx\n" /* listPtr */
        "testl %eax, %eax\n" /* line 1426 */
        "je .Lf1a9dd8_001a9e53\n"
        /* { scope 2: token */
        "leal -0x428(%ebp), %eax\n" /* line 280 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9dd8_001a9e53\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a9dd8_001a9fe1\n"
        "xorl %eax, %eax\n"
        ".Lf1a9dd8_001a9e30:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1a9dd8_001a9e60\n"
        /* } scope */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9dd8_001a9e39:\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %edi, (%esp)\n"
        "calll PC_SourceError\n"
        ".Lf1a9dd8_001a9e53:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x43c, %esp\n" /* line 1456 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2: token */
        ".Lf1a9dd8_001a9e60:\n"
        "movl -0x420(%ebp), %edx\n" /* line 295 */
        "movl %edx, -0x434(%ebp)\n" /* num */
        "testl %eax, %eax\n" /* line 296 */
        "je .Lf1a9dd8_001a9e78\n"
        "negl %edx\n" /* line 297 */
        "movl %edx, -0x434(%ebp)\n" /* num */
        /* } scope */
        ".Lf1a9dd8_001a9e78:\n"
        "cmpl $0x10, -0x434(%ebp)\n" /* line 1430 | num */
        "jle .Lf1a9dd8_001a9e8b\n"
        /* { scope 2: token */
        "movl $0x10, -0x434(%ebp)\n" /* line 297 | num */
        /* } scope */
        ".Lf1a9dd8_001a9e8b:\n"
        "movl -0x434(%ebp), %eax\n" /* line 1434 | num */
        "movl %eax, 0x40(%ebx)\n" /* listPtr */
        "testl %eax, %eax\n" /* line 1435 */
        "jg .Lf1a9dd8_001a9ea8\n"
        ".Lf1a9dd8_001a9e98:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x43c, %esp\n" /* line 1456 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lf1a9dd8_001a9ea8:\n"
        "movl %ebx, -0x42c(%ebp)\n" /* line 1435 | listPtr */
        "movl $0, -0x430(%ebp)\n" /* i */
        "jmp .Lf1a9dd8_001a9f96\n"
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9dd8_001a9ebd:\n"
        "xorl %edx, %edx\n" /* line 284 */
        ".Lf1a9dd8_001a9ebf:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "jne .Lf1a9dd8_001a9e39\n"
        "movl -0x420(%ebp), %esi\n" /* line 295 */
        "movl %esi, %eax\n" /* line 297 */
        "negl %eax\n"
        "testl %edx, %edx\n"
        "cmovnel %eax, %esi\n"
        /* } scope */
        /* { scope 3 */
        "leal -0x428(%ebp), %edx\n" /* line 280 | token */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9dd8_001a9e53\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a9dd8_001aa005\n"
        "xorl %edx, %edx\n"
        ".Lf1a9dd8_001a9f04:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "jne .Lf1a9dd8_001a9e39\n"
        "movl -0x420(%ebp), %ebx\n" /* line 295 */
        "movl %ebx, %eax\n" /* line 297 */
        "negl %eax\n"
        "testl %edx, %edx\n"
        "cmovnel %eax, %ebx\n"
        /* } scope */
        /* { scope 3 */
        "leal -0x428(%ebp), %edx\n" /* line 280 | token */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9dd8_001a9e53\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1a9dd8_001aa029\n"
        "xorl %ecx, %ecx\n"
        ".Lf1a9dd8_001a9f49:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "jne .Lf1a9dd8_001a9e39\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, %edx\n" /* line 297 */
        "negl %edx\n"
        "testl %ecx, %ecx\n"
        "cmovnel %edx, %eax\n"
        /* } scope */
        "movl -0x42c(%ebp), %edx\n" /* line 1441 */
        "movl %esi, 0x44(%edx)\n" /* pos */
        "movl %ebx, 0x48(%edx)\n" /* line 1442 | width */
        "movl %eax, 0x4c(%edx)\n" /* line 1443 */
        /* } scope */
        "addl $1, -0x430(%ebp)\n" /* line 1435 | i */
        "addl $0xc, %edx\n"
        "movl %edx, -0x42c(%ebp)\n"
        "movl -0x434(%ebp), %eax\n" /* num */
        "cmpl %eax, -0x430(%ebp)\n" /* i */
        "je .Lf1a9dd8_001a9e98\n"
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9dd8_001a9f96:\n"
        "leal -0x428(%ebp), %edx\n" /* line 280 | token */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9dd8_001a9e53\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "jne .Lf1a9dd8_001a9ebd\n"
        "leal -0x428(%ebp), %eax\n" /* line 286 | token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9dd8_001a9e53\n"
        "movl $1, %edx\n"
        "jmp .Lf1a9dd8_001a9ebf\n"
        /* } scope */
        /* } scope */
        /* { scope 2: token */
        ".Lf1a9dd8_001a9fe1:\n"
        "leal -0x428(%ebp), %edx\n" /* token */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9dd8_001a9e53\n"
        "movl $1, %eax\n"
        "jmp .Lf1a9dd8_001a9e30\n"
        /* } scope */
        /* { scope 2: token */
        /* { scope 3 */
        ".Lf1a9dd8_001aa005:\n"
        "leal -0x428(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9dd8_001a9e53\n"
        "movl $1, %edx\n"
        "jmp .Lf1a9dd8_001a9f04\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1a9dd8_001aa029:\n"
        "leal -0x428(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1a9dd8_001a9e53\n"
        "movl $1, %ecx\n"
        "jmp .Lf1a9dd8_001a9f49\n"
    );
}

/* line 1459 */
__attribute__((naked))
qboolean ItemParse_border(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1459 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1461 | item, i */
        "addl $0xd4, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa04e_001aa0d7\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1aa04e_001aa0e4\n"
        "xorl %edx, %edx\n"
        ".Lf1aa04e_001aa087:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1aa04e_001aa0b7\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1466 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa04e_001aa0b7:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1aa04e_001aa0c7\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1aa04e_001aa0c7:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1466 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa04e_001aa0d7:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1466 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa04e_001aa0e4:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa04e_001aa0d7\n"
        "movl $1, %edx\n"
        "jmp .Lf1aa04e_001aa087\n"
    );
}

/* line 1479 */
__attribute__((naked))
qboolean ItemParse_visible(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1479 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* handle */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %esi\n" /* line 280 | token */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa0fc_001aa170\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1aa0fc_001aa15c\n"
        "xorl %eax, %eax\n"
        ".Lf1aa0fc_001aa12c:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1aa0fc_001aa17d\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %ebx, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1507 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa0fc_001aa15c:\n"
        "movl %esi, 4(%esp)\n" /* line 286 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa0fc_001aa23e\n"
        /* } scope */
        ".Lf1aa0fc_001aa170:\n"
        "xorl %eax, %eax\n" /* line 1504 */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1507 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa0fc_001aa17d:\n"
        "movl -0x420(%ebp), %ebx\n" /* line 295 */
        "testl %eax, %eax\n" /* line 296 */
        "jne .Lf1aa0fc_001aa219\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1491 | item */
        "movl 0x294(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1aa0fc_001aa1bc\n"
        ".Lf1aa0fc_001aa198:\n"
        "movl $str_002b42a4, %edi\n" /* "@MENU_SHADOWS" */
        "movl $0xe, %ecx\n"
        "cld\n"
        "movl %edx, %esi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1aa0fc_001aa1b8\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1aa0fc_001aa1b8:\n"
        "testl %edx, %edx\n"
        "je .Lf1aa0fc_001aa22e\n"
        ".Lf1aa0fc_001aa1bc:\n"
        "movl 8(%ebp), %eax\n" /* line 1495 | item */
        "movl 0x2c0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1aa0fc_001aa1ed\n"
        "movl $str_002b42b4, %edi\n" /* "ui_sc_enable" */
        "movl $0xd, %ecx\n"
        "cld\n"
        "movl %edx, %esi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1aa0fc_001aa1e9\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1aa0fc_001aa1e9:\n"
        "testl %edx, %edx\n"
        "je .Lf1aa0fc_001aa22e\n"
        ".Lf1aa0fc_001aa1ed:\n"
        "testl %ebx, %ebx\n" /* line 1501 | i */
        "je .Lf1aa0fc_001aa22e\n"
        "movl 8(%ebp), %edx\n" /* line 1504 | item */
        "movl 0xe8(%edx), %eax\n"
        "orl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Window_SetDynamicFlags\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1507 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa0fc_001aa219:\n"
        "negl %ebx\n" /* line 297 */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1491 | item */
        "movl 0x294(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1aa0fc_001aa198\n"
        "jmp .Lf1aa0fc_001aa1bc\n"
        ".Lf1aa0fc_001aa22e:\n"
        "movl $1, %eax\n" /* line 1504 */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1507 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa0fc_001aa23e:\n"
        "movl $1, %eax\n" /* line 286 */
        "jmp .Lf1aa0fc_001aa12c\n"
    );
}

/* line 1510 */
__attribute__((naked))
qboolean ItemParse_ownerdraw(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1510 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1512 | item, i */
        "addl $0xd8, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa248_001aa2c1\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1aa248_001aa2b1\n"
        "xorl %edx, %edx\n"
        ".Lf1aa248_001aa281:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1aa248_001aa2ce\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1518 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa248_001aa2b1:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa248_001aa30f\n"
        ".Lf1aa248_001aa2c1:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1518 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa248_001aa2ce:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "jne .Lf1aa248_001aa2f7\n"
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1516 | item */
        "movl $8, 0x270(%eax)\n"
        "movl $1, %eax\n"
        ".Lf1aa248_001aa2ec:\n"
        "addl $0x42c, %esp\n" /* line 1518 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa248_001aa2f7:\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1516 | item */
        "movl $8, 0x270(%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lf1aa248_001aa2ec\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa248_001aa30f:\n"
        "movl $1, %edx\n" /* line 286 */
        "jmp .Lf1aa248_001aa281\n"
    );
}

/* line 1521 */
__attribute__((naked))
qboolean ItemParse_align(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1521 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1523 | item, i */
        "addl $0x278, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa31a_001aa3a3\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1aa31a_001aa3b0\n"
        "xorl %edx, %edx\n"
        ".Lf1aa31a_001aa353:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1aa31a_001aa383\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1528 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa31a_001aa383:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1aa31a_001aa393\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1aa31a_001aa393:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1528 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa31a_001aa3a3:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1528 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa31a_001aa3b0:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa31a_001aa3a3\n"
        "movl $1, %edx\n"
        "jmp .Lf1aa31a_001aa353\n"
    );
}

/* line 1531 */
__attribute__((naked))
qboolean ItemParse_textalign(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1531 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1533 | item, i */
        "addl $0x280, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa3c8_001aa451\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1aa3c8_001aa45e\n"
        "xorl %edx, %edx\n"
        ".Lf1aa3c8_001aa401:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1aa3c8_001aa431\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1538 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa3c8_001aa431:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1aa3c8_001aa441\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1aa3c8_001aa441:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1538 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa3c8_001aa451:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1538 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa3c8_001aa45e:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa3c8_001aa451\n"
        "movl $1, %edx\n"
        "jmp .Lf1aa3c8_001aa401\n"
    );
}

/* line 1571 */
__attribute__((naked))
qboolean ItemParse_textstyle(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1571 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1573 | item, i */
        "addl $0x290, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa476_001aa4ff\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1aa476_001aa50c\n"
        "xorl %edx, %edx\n"
        ".Lf1aa476_001aa4af:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1aa476_001aa4df\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1578 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa476_001aa4df:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1aa476_001aa4ef\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1aa476_001aa4ef:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1578 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa476_001aa4ff:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1578 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa476_001aa50c:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa476_001aa4ff\n"
        "movl $1, %edx\n"
        "jmp .Lf1aa476_001aa4af\n"
    );
}

/* line 1581 */
__attribute__((naked))
qboolean ItemParse_textfont(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1581 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        "movl 8(%ebp), %edi\n" /* line 1583 | item, i */
        "addl $0x27c, %edi\n" /* i */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x428(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa524_001aa5ad\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1aa524_001aa5ba\n"
        "xorl %edx, %edx\n"
        ".Lf1aa524_001aa55d:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1aa524_001aa58d\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1588 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa524_001aa58d:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 */
        "movl %eax, (%edi)\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1aa524_001aa59d\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, (%edi)\n"
        ".Lf1aa524_001aa59d:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1588 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa524_001aa5ad:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1588 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa524_001aa5ba:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa524_001aa5ad\n"
        "movl $1, %edx\n"
        "jmp .Lf1aa524_001aa55d\n"
    );
}

/* line 1830 */
__attribute__((naked))
qboolean ItemParse_maxChars(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1830 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %esi\n" /* item */
        "movl 0xc(%ebp), %ebx\n" /* handle */
        /* { scope 1: token */
        "movl %ebx, %edx\n" /* line 1835 | maxChars */
        "movl %esi, %eax\n" /* item */
        "calll Item_ValidateTypeData\n"
        "movl 0x2ec(%esi), %edx\n" /* line 1836 | item */
        "testl %edx, %edx\n"
        "je .Lf1aa5d2_001aa658\n"
        /* { scope 2 */
        "leal -0x428(%ebp), %edi\n" /* line 280 | token */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa5d2_001aa658\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1aa5d2_001aa648\n"
        "xorl %eax, %eax\n"
        ".Lf1aa5d2_001aa618:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1aa5d2_001aa665\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %ebx, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1848 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa5d2_001aa648:\n"
        "movl %edi, 4(%esp)\n" /* line 286 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa5d2_001aa690\n"
        /* } scope */
        ".Lf1aa5d2_001aa658:\n"
        "xorl %eax, %eax\n" /* line 1847 */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1848 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa5d2_001aa665:\n"
        "movl -0x420(%ebp), %ebx\n" /* line 295 */
        "testl %eax, %eax\n" /* line 296 */
        "je .Lf1aa5d2_001aa671\n"
        "negl %ebx\n" /* line 297 */
        /* } scope */
        ".Lf1aa5d2_001aa671:\n"
        "movl %esi, (%esp)\n" /* line 1843 | item */
        "calll Item_GetEditFieldDef\n"
        "testl %eax, %eax\n" /* line 1844 */
        "je .Lf1aa5d2_001aa658\n"
        "movl %ebx, 0x10(%eax)\n" /* line 1846 | maxChars */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1848 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa5d2_001aa690:\n"
        "movl $1, %eax\n" /* line 286 */
        "jmp .Lf1aa5d2_001aa618\n"
    );
}

/* line 1867 */
__attribute__((naked))
qboolean ItemParse_maxPaintChars(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1867 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 8(%ebp), %esi\n" /* item */
        "movl 0xc(%ebp), %ebx\n" /* handle */
        /* { scope 1: token */
        "movl %ebx, %edx\n" /* line 1872 | maxChars */
        "movl %esi, %eax\n" /* item */
        "calll Item_ValidateTypeData\n"
        "movl 0x2ec(%esi), %ecx\n" /* line 1873 | item */
        "testl %ecx, %ecx\n"
        "je .Lf1aa698_001aa71e\n"
        /* { scope 2 */
        "leal -0x428(%ebp), %edi\n" /* line 280 | token */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa698_001aa71e\n"
        "cmpb $0x2d, -0x418(%ebp)\n" /* line 284 */
        "je .Lf1aa698_001aa70e\n"
        "xorl %eax, %eax\n"
        ".Lf1aa698_001aa6de:\n"
        "cmpl $3, -0x428(%ebp)\n" /* line 290 | token */
        "je .Lf1aa698_001aa72b\n"
        "leal -0x418(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %ebx, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1885 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa698_001aa70e:\n"
        "movl %edi, 4(%esp)\n" /* line 286 */
        "movl %ebx, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa698_001aa756\n"
        /* } scope */
        ".Lf1aa698_001aa71e:\n"
        "xorl %eax, %eax\n" /* line 1884 */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1885 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa698_001aa72b:\n"
        "movl -0x420(%ebp), %ebx\n" /* line 295 */
        "testl %eax, %eax\n" /* line 296 */
        "je .Lf1aa698_001aa737\n"
        "negl %ebx\n" /* line 297 */
        /* } scope */
        ".Lf1aa698_001aa737:\n"
        "movl %esi, (%esp)\n" /* line 1880 | item */
        "calll Item_GetEditFieldDef\n"
        "testl %eax, %eax\n" /* line 1881 */
        "je .Lf1aa698_001aa71e\n"
        "movl %ebx, 0x18(%eax)\n" /* line 1883 | maxChars */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 1885 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa698_001aa756:\n"
        "movl $1, %eax\n" /* line 286 */
        "jmp .Lf1aa698_001aa6de\n"
    );
}

/* line 2036 */
__attribute__((naked))
qboolean ItemParse_ownerdrawFlag(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2036 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x418(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa75e_001aa7cc\n"
        "cmpb $0x2d, -0x408(%ebp)\n" /* line 284 */
        "je .Lf1aa75e_001aa7bc\n"
        "xorl %edx, %edx\n"
        ".Lf1aa75e_001aa78d:\n"
        "cmpl $3, -0x418(%ebp)\n" /* line 290 | token */
        "je .Lf1aa75e_001aa7d8\n"
        "leal -0x408(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x420, %esp\n" /* line 2046 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa75e_001aa7bc:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa75e_001aa80c\n"
        ".Lf1aa75e_001aa7cc:\n"
        "xorl %eax, %eax\n" /* line 297 */
        /* } scope */
        /* } scope */
        "addl $0x420, %esp\n" /* line 2046 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa75e_001aa7d8:\n"
        "movl -0x410(%ebp), %eax\n" /* line 295 */
        "testl %edx, %edx\n" /* line 296 */
        "jne .Lf1aa75e_001aa7fa\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 2044 | item */
        "orl %eax, 0xdc(%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1aa75e_001aa7f0:\n"
        "addl $0x420, %esp\n" /* line 2046 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa75e_001aa7fa:\n"
        "negl %eax\n" /* line 297 */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 2044 | item */
        "orl %eax, 0xdc(%edx)\n"
        "movl $1, %eax\n"
        "jmp .Lf1aa75e_001aa7f0\n"
        /* { scope 2 */
        ".Lf1aa75e_001aa80c:\n"
        "movl $1, %edx\n" /* line 286 */
        "jmp .Lf1aa75e_001aa78d\n"
    );
}

/* line 2128 */
__attribute__((naked))
qboolean ItemParse_execKeyInt(const char (*item)[4], int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2128 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x430, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* handle */
        /* { scope 1: token */
        /* { scope 2 */
        "leal -0x41c(%ebp), %ebx\n" /* line 280 | token */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa816_001aa897\n"
        "cmpb $0x2d, -0x40c(%ebp)\n" /* line 284 */
        "je .Lf1aa816_001aa8e0\n"
        "xorl %eax, %eax\n"
        ".Lf1aa816_001aa849:\n"
        "cmpl $3, -0x41c(%ebp)\n" /* line 290 | token */
        "je .Lf1aa816_001aa878\n"
        "leal -0x40c(%ebp), %eax\n" /* line 292 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x430, %esp\n" /* line 2146 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa816_001aa878:\n"
        "movl -0x414(%ebp), %ebx\n" /* line 295 */
        "testl %eax, %eax\n" /* line 296 */
        "je .Lf1aa816_001aa884\n"
        "negl %ebx\n" /* line 297 */
        /* } scope */
        ".Lf1aa816_001aa884:\n"
        "leal -0xc(%ebp), %eax\n" /* line 2137 | action */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll PC_Script_Parse\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa816_001aa8a3\n"
        ".Lf1aa816_001aa897:\n"
        "xorl %eax, %eax\n" /* line 2145 */
        /* } scope */
        "addl $0x430, %esp\n" /* line 2146 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lf1aa816_001aa8a3:\n"
        "movl $4, 4(%esp)\n" /* line 2140 */
        "movl $0xc, (%esp)\n"
        "calll UI_Alloc\n"
        "movl %ebx, (%eax)\n" /* line 2141 | keyname */
        "movl -0xc(%ebp), %edx\n" /* line 2142 | action */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 2143 | item */
        "movl 0x2c8(%ecx), %edx\n"
        "movl %edx, 8(%eax)\n"
        "movl %eax, 0x2c8(%ecx)\n" /* line 2144 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x430, %esp\n" /* line 2146 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2 */
        ".Lf1aa816_001aa8e0:\n"
        "movl %ebx, 4(%esp)\n" /* line 286 */
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa816_001aa897\n"
        "movl $1, %eax\n"
        "jmp .Lf1aa816_001aa849\n"
    );
}

/* line 2549 */
static __attribute__((naked, regparm(2)))
Bool UI_ParseMenuInternal(const char *menuFile, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2549 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc5c, %esp\n"
        "movl %eax, %ebx\n" /* menuFile */
        "movl %edx, -0xc4c(%ebp)\n"
        /* { scope 1: token */
        "movl %eax, 4(%esp)\n" /* line 2554 */
        "movl $str_002b42c4, (%esp)\n" /* "	Loading '%s'...
" */
        "calll Com_Printf\n"
        "movl %ebx, (%esp)\n" /* line 2556 | menuFile */
        "calll PC_LoadSourceHandle\n"
        "movl %eax, %esi\n" /* handle */
        "testl %eax, %eax\n" /* line 2557 */
        "jne .Lf1aa8fa_001aa964\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0xc5c, %esp\n" /* line 2584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        ".Lf1aa8fa_001aa939:\n"
        "movl $str_002b43a4, 4(%esp)\n" /* line 2575 */
        "leal -0xc38(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aa964\n"
        "movl -0xc4c(%ebp), %edx\n" /* line 2577 */
        "movl %esi, %eax\n" /* handle */
        "calll Menu_New\n"
        "testb %al, %al\n"
        "je .Lf1aa8fa_001aa9b3\n"
        ".Lf1aa8fa_001aa964:\n"
        "leal -0xc48(%ebp), %eax\n" /* line 2562 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* handle */
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x7d, -0xc38(%ebp)\n" /* line 2565 */
        "je .Lf1aa8fa_001aa9b3\n"
        "movl $str_002b42d8, 4(%esp)\n" /* line 2568 */
        "leal -0xc38(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aa939\n"
        /* { scope 2: token */
        "leal -0x428(%ebp), %eax\n" /* line 2245 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aa9cb\n"
        /* } scope */
        ".Lf1aa8fa_001aa9b3:\n"
        "movl %esi, (%esp)\n" /* line 2582 | handle */
        "calll PC_FreeSourceHandle\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0xc5c, %esp\n" /* line 2584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: token */
        /* { scope 2: token */
        ".Lf1aa8fa_001aa9cb:\n"
        "movl $str_0021e50c, 4(%esp)\n" /* line 2247 */
        "leal -0x418(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aa9b3\n"
        ".Lf1aa8fa_001aa9e5:\n"
        "leal -0x428(%ebp), %eax\n" /* line 2252 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        ".Lf1aa8fa_001aa9fb:\n"
        "movl $str_0021e508, 4(%esp)\n" /* line 2255 */
        "leal -0x418(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa964\n"
        "movl $str_002ace38, 4(%esp)\n" /* line 2258 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aaad6\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 341 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %eax\n" /* line 344 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 280 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 284 */
        "je .Lf1aa8fa_001aacbf\n"
        ".Lf1aa8fa_001aaa88:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 290 | token */
        "jne .Lf1aa8fa_001ab058\n"
        /* } scope */
        "movl -0xc4c(%ebp), %eax\n" /* line 2265 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_RegisterFont\n"
        "movl $str_002a9fd4, 4(%esp)\n" /* line 2266 */
        "movl %eax, (%esp)\n"
        "calll CL_DuplicateFont\n"
        "leal -0x428(%ebp), %eax\n" /* line 2252 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aa9fb\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        ".Lf1aa8fa_001aaad6:\n"
        "movl $str_002b42e8, 4(%esp)\n" /* line 2270 */
        "leal -0x418(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aab79\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %eax\n" /* line 341 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %edi\n" /* line 344 */
        "movl %edi, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 280 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 284 */
        "je .Lf1aa8fa_001aad81\n"
        ".Lf1aa8fa_001aab45:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 290 | token */
        "jne .Lf1aa8fa_001ab03f\n"
        /* } scope */
        "movl -0xc4c(%ebp), %edx\n" /* line 2277 */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_RegisterFont\n"
        "movl $str_002a9fac, 4(%esp)\n" /* line 2278 */
        "movl %eax, (%esp)\n"
        "calll CL_DuplicateFont\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        ".Lf1aa8fa_001aab79:\n"
        "movl $str_002b42f4, 4(%esp)\n" /* line 2282 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aac1c\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 341 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %edi\n" /* line 344 */
        "movl %edi, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* { scope 3: token */
        "leal -0x838(%ebp), %eax\n" /* line 280 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 284 */
        "je .Lf1aa8fa_001aaeb0\n"
        ".Lf1aa8fa_001aabe8:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 290 | token */
        "jne .Lf1aa8fa_001ab03f\n"
        /* } scope */
        "movl -0xc4c(%ebp), %eax\n" /* line 2289 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_RegisterFont\n"
        "movl $str_002a9fa0, 4(%esp)\n" /* line 2290 */
        "movl %eax, (%esp)\n"
        "calll CL_DuplicateFont\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        ".Lf1aa8fa_001aac1c:\n"
        "movl $str_002b42fc, 4(%esp)\n" /* line 2294 */
        "leal -0x418(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aacde\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %eax\n" /* line 341 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %edi\n" /* line 344 */
        "movl %edi, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 280 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 284 */
        "je .Lf1aa8fa_001aaecf\n"
        ".Lf1aa8fa_001aac8b:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 290 | token */
        "jne .Lf1aa8fa_001ab03f\n"
        /* } scope */
        "movl -0xc4c(%ebp), %edx\n" /* line 2301 */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_RegisterFont\n"
        "movl $str_002a9fdc, 4(%esp)\n" /* line 2302 */
        "movl %eax, (%esp)\n"
        "calll CL_DuplicateFont\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* { scope 3: token */
        ".Lf1aa8fa_001aacbf:\n"
        "leal -0x838(%ebp), %eax\n" /* line 286 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aaa88\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        /* } scope */
        ".Lf1aa8fa_001aacde:\n"
        "movl $str_002b430c, 4(%esp)\n" /* line 2306 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aada0\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 341 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %edi\n" /* line 344 */
        "movl %edi, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* { scope 3: token */
        "leal -0x838(%ebp), %eax\n" /* line 280 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 284 */
        "je .Lf1aa8fa_001aaf42\n"
        ".Lf1aa8fa_001aad4d:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 290 | token */
        "jne .Lf1aa8fa_001ab03f\n"
        /* } scope */
        "movl -0xc4c(%ebp), %eax\n" /* line 2313 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_RegisterFont\n"
        "movl $str_002a9fc8, 4(%esp)\n" /* line 2314 */
        "movl %eax, (%esp)\n"
        "calll CL_DuplicateFont\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* { scope 3: token */
        ".Lf1aa8fa_001aad81:\n"
        "leal -0x838(%ebp), %eax\n" /* line 286 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aab45\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        /* } scope */
        ".Lf1aa8fa_001aada0:\n"
        "movl $str_002b4318, 4(%esp)\n" /* line 2318 */
        "leal -0x418(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aae43\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %eax\n" /* line 341 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %edi\n" /* line 344 */
        "movl %edi, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, %ebx\n"
        /* } scope */
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 280 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 284 */
        "je .Lf1aa8fa_001aafb5\n"
        ".Lf1aa8fa_001aae0f:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 290 | token */
        "jne .Lf1aa8fa_001ab03f\n"
        /* } scope */
        "movl -0xc4c(%ebp), %edx\n" /* line 2325 */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_RegisterFont\n"
        "movl $str_002a9fb8, 4(%esp)\n" /* line 2326 */
        "movl %eax, (%esp)\n"
        "calll CL_DuplicateFont\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        ".Lf1aa8fa_001aae43:\n"
        "movl $str_002b4324, 4(%esp)\n" /* line 2330 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aaeee\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 341 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %eax\n" /* line 344 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        /* } scope */
        "movl -0xc4c(%ebp), %edx\n" /* line 2335 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl $str_002b4330, 4(%esp)\n" /* line 2336 */
        "movl %eax, (%esp)\n"
        "calll CL_Material_Duplicate\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* { scope 3: token */
        ".Lf1aa8fa_001aaeb0:\n"
        "leal -0x838(%ebp), %edx\n" /* line 286 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aabe8\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        /* } scope */
        /* { scope 3: token */
        ".Lf1aa8fa_001aaecf:\n"
        "leal -0x838(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aac8b\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        /* } scope */
        ".Lf1aa8fa_001aaeee:\n"
        "movl $str_002b4340, 4(%esp)\n" /* line 2340 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aaf61\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 341 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %eax\n" /* line 344 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 2345 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, g_load\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* { scope 3: token */
        ".Lf1aa8fa_001aaf42:\n"
        "leal -0x838(%ebp), %edx\n" /* line 286 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aad4d\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        /* } scope */
        ".Lf1aa8fa_001aaf61:\n"
        "movl $str_002b4350, 4(%esp)\n" /* line 2349 */
        "leal -0x418(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aafd4\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %eax\n" /* line 341 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %edx\n" /* line 344 */
        "movl %edx, (%esp)\n"
        "calll String_Alloc\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 2354 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, g_load+4\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* { scope 3: token */
        ".Lf1aa8fa_001aafb5:\n"
        "leal -0x838(%ebp), %eax\n" /* line 286 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aae0f\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        /* } scope */
        ".Lf1aa8fa_001aafd4:\n"
        "movl $str_002b4360, 4(%esp)\n" /* line 2358 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001ab077\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 341 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %eax\n" /* line 344 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 2363 */
        "calll Com_FindSoundAlias\n"
        "testl %eax, %eax\n" /* line 2364 */
        "je .Lf1aa8fa_001aa9e5\n"
        "movl $str_002a9fec, 4(%esp)\n" /* line 2365 */
        "movl %eax, (%esp)\n"
        "calll Com_DuplicateSoundAlias\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* { scope 3: token */
        ".Lf1aa8fa_001ab03f:\n"
        "movl %edi, 8(%esp)\n" /* line 292 */
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        /* } scope */
        /* { scope 3: token */
        ".Lf1aa8fa_001ab058:\n"
        "leal -0x828(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $str_002b40e4, 4(%esp)\n" /* "expected integer but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        /* } scope */
        ".Lf1aa8fa_001ab077:\n"
        "movl $str_002b4370, 4(%esp)\n" /* line 2369 */
        "leal -0x418(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001ab0cb\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %eax\n" /* line 341 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %edx\n" /* line 344 */
        "movl %edx, (%esp)\n"
        "calll String_Alloc\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 2374 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, g_load+8\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        ".Lf1aa8fa_001ab0cb:\n"
        "movl $str_002b4380, 4(%esp)\n" /* line 2378 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001ab134\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 341 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "leal -0x828(%ebp), %eax\n" /* line 344 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        /* } scope */
        "movl -0xc4c(%ebp), %edx\n" /* line 2383 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl $str_002a9f98, 4(%esp)\n" /* line 2384 */
        "movl %eax, (%esp)\n"
        "calll CL_Material_Duplicate\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        ".Lf1aa8fa_001ab134:\n"
        "movl $str_002b3fdc, 4(%esp)\n" /* line 2388 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001ab1a1\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 188 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 192 */
        "je .Lf1aa8fa_001ab2d0\n"
        "xorl %eax, %eax\n"
        ".Lf1aa8fa_001ab177:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 198 | token */
        "jne .Lf1aa8fa_001ab27d\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1aa8fa_001ab29c\n"
        "movl -0x82c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, g_load+12\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* } scope */
        ".Lf1aa8fa_001ab1a1:\n"
        "movl $str_002b3fe8, 4(%esp)\n" /* line 2395 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001ab210\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 280 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 284 */
        "je .Lf1aa8fa_001ab2ac\n"
        "xorl %edx, %edx\n"
        ".Lf1aa8fa_001ab1e4:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 290 | token */
        "jne .Lf1aa8fa_001ab058\n"
        "movl -0x830(%ebp), %eax\n" /* line 295 */
        "movl %eax, g_load+16\n"
        "testl %edx, %edx\n" /* line 296 */
        "je .Lf1aa8fa_001aa9e5\n"
        "negl %eax\n" /* line 297 */
        "movl %eax, g_load+16\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* } scope */
        ".Lf1aa8fa_001ab210:\n"
        "movl $str_002b3ff4, 4(%esp)\n" /* line 2402 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001ab328\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 188 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 192 */
        "je .Lf1aa8fa_001ab304\n"
        "xorl %eax, %eax\n"
        ".Lf1aa8fa_001ab257:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 198 | token */
        "jne .Lf1aa8fa_001ab27d\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1aa8fa_001ab2f4\n"
        "movl -0x82c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, g_load+20\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* } scope */
        /* { scope 3: token */
        /* { scope 4 */
        ".Lf1aa8fa_001ab27d:\n"
        "leal -0x828(%ebp), %edx\n" /* line 200 */
        "movl %edx, 8(%esp)\n"
        "movl $str_002b40c4, 4(%esp)\n" /* "expected float but found %s
" */
        "movl %esi, (%esp)\n"
        "calll PC_SourceError\n"
        "jmp .Lf1aa8fa_001aa9b3\n"
        /* } scope */
        /* } scope */
        /* { scope 3: token */
        ".Lf1aa8fa_001ab29c:\n"
        "movl -0x82c(%ebp), %eax\n" /* line 206 */
        "movl %eax, g_load+12\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* } scope */
        /* { scope 3: token */
        ".Lf1aa8fa_001ab2ac:\n"
        "leal -0x838(%ebp), %eax\n" /* line 286 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "movl $1, %edx\n"
        "jmp .Lf1aa8fa_001ab1e4\n"
        /* } scope */
        /* { scope 3: token */
        ".Lf1aa8fa_001ab2d0:\n"
        "leal -0x838(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "movl $1, %eax\n"
        "jmp .Lf1aa8fa_001ab177\n"
        /* } scope */
        /* { scope 3: token */
        ".Lf1aa8fa_001ab2f4:\n"
        "movl -0x82c(%ebp), %eax\n" /* line 206 */
        "movl %eax, g_load+20\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        ".Lf1aa8fa_001ab304:\n"
        "leal -0x838(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "movl $1, %eax\n"
        "jmp .Lf1aa8fa_001ab257\n"
        /* } scope */
        ".Lf1aa8fa_001ab328:\n"
        "movl $str_002b4000, 4(%esp)\n" /* line 2409 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001ab391\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 188 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 192 */
        "je .Lf1aa8fa_001ab40a\n"
        "xorl %eax, %eax\n"
        ".Lf1aa8fa_001ab36b:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 198 | token */
        "jne .Lf1aa8fa_001ab27d\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1aa8fa_001ab3fa\n"
        "movl -0x82c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, g_load+24\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* } scope */
        ".Lf1aa8fa_001ab391:\n"
        "movl $str_002b4388, 4(%esp)\n" /* line 2416 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001ab462\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 188 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 192 */
        "je .Lf1aa8fa_001ab43e\n"
        "xorl %eax, %eax\n"
        ".Lf1aa8fa_001ab3d4:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 198 | token */
        "jne .Lf1aa8fa_001ab27d\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1aa8fa_001ab42e\n"
        "movl -0x82c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, g_load+28\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* } scope */
        /* { scope 3: token */
        ".Lf1aa8fa_001ab3fa:\n"
        "movl -0x82c(%ebp), %eax\n" /* line 206 */
        "movl %eax, g_load+24\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        ".Lf1aa8fa_001ab40a:\n"
        "leal -0x838(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "movl $1, %eax\n"
        "jmp .Lf1aa8fa_001ab36b\n"
        /* } scope */
        /* { scope 3: token */
        ".Lf1aa8fa_001ab42e:\n"
        "movl -0x82c(%ebp), %eax\n" /* line 206 */
        "movl %eax, g_load+28\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        ".Lf1aa8fa_001ab43e:\n"
        "leal -0x838(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "movl $1, %eax\n"
        "jmp .Lf1aa8fa_001ab3d4\n"
        /* } scope */
        ".Lf1aa8fa_001ab462:\n"
        "movl $str_002b4390, 4(%esp)\n" /* line 2423 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001ab4cf\n"
        /* { scope 3: token */
        "leal -0x838(%ebp), %edx\n" /* line 188 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 192 */
        "je .Lf1aa8fa_001ab560\n"
        "xorl %eax, %eax\n"
        ".Lf1aa8fa_001ab4a5:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 198 | token */
        "jne .Lf1aa8fa_001ab27d\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1aa8fa_001ab550\n"
        "movl -0x82c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        "movl %eax, g_load+32\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* } scope */
        ".Lf1aa8fa_001ab4cf:\n"
        "movl $str_002b4398, 4(%esp)\n" /* line 2430 */
        "leal -0x418(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1aa8fa_001aa9e5\n"
        "movl $g_load, %ebx\n"
        /* { scope 3: token */
        /* { scope 4 */
        ".Lf1aa8fa_001ab4f2:\n"
        "leal -0x838(%ebp), %edx\n" /* line 188 | token */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "cmpb $0x2d, -0x828(%ebp)\n" /* line 192 */
        "je .Lf1aa8fa_001ab58c\n"
        "xorl %eax, %eax\n"
        ".Lf1aa8fa_001ab517:\n"
        "cmpl $3, -0x838(%ebp)\n" /* line 198 | token */
        "jne .Lf1aa8fa_001ab27d\n"
        "testl %eax, %eax\n" /* line 203 */
        "je .Lf1aa8fa_001ab584\n"
        "movl -0x82c(%ebp), %eax\n" /* line 204 */
        "xorl $0x80000000, %eax\n"
        /* } scope */
        ".Lf1aa8fa_001ab533:\n"
        "movl %eax, 0x24(%ebx)\n" /* line 264 */
        "addl $4, %ebx\n"
        "cmpl $g_load+16, %ebx\n" /* line 258 */
        "jne .Lf1aa8fa_001ab4f2\n"
        /* } scope */
        "movl g_load+48, %eax\n" /* line 2434 */
        "movl %eax, g_load+52\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        /* { scope 3: token */
        ".Lf1aa8fa_001ab550:\n"
        "movl -0x82c(%ebp), %eax\n" /* line 206 */
        "movl %eax, g_load+32\n"
        "jmp .Lf1aa8fa_001aa9e5\n"
        ".Lf1aa8fa_001ab560:\n"
        "leal -0x838(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "movl $1, %eax\n"
        "jmp .Lf1aa8fa_001ab4a5\n"
        /* } scope */
        /* { scope 3: token */
        /* { scope 4 */
        ".Lf1aa8fa_001ab584:\n"
        "movl -0x82c(%ebp), %eax\n" /* line 206 */
        "jmp .Lf1aa8fa_001ab533\n"
        ".Lf1aa8fa_001ab58c:\n"
        "leal -0x838(%ebp), %eax\n" /* line 194 | token */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll PC_ReadTokenHandle\n"
        "testl %eax, %eax\n"
        "je .Lf1aa8fa_001aa9b3\n"
        "movl $1, %eax\n"
        "jmp .Lf1aa8fa_001ab517\n"
    );
}

/* line 2640 */
MenuList * UI_LoadMenus(const char *menuFile, int imageTrack)
{
    const char *p;
    const char *token;
    fileHandle_t f;
    int len;

    memset(g_load, 0, sizeof(g_load));
    UI_MenuList()->menus = UI_MenuStorage();

    len = FS_FOpenFileByMode(menuFile, &f, FS_READ);
    if (!f) {
        Com_Printf("^3WARNING: menu file not found: %s\n", menuFile);
        len = FS_FOpenFileByMode("ui/default.menu", &f, FS_READ);
        if (!f)
            Com_Error(ERR_DROP, "default menu file not found");
    }

    if (len > 0x7fff) {
        FS_FCloseFile(f);
        Com_Error(ERR_DROP, "^1menu file too large: %s is %i, max allowed is %i",
                  menuFile, len, 0x8000);
    }

    FS_Read(menuBuf, len, f);
    menuBuf[len] = '\0';
    FS_FCloseFile(f);
    Com_Compress(menuBuf);

    p = menuBuf;
    Com_BeginParseSession(menuFile);

    for (;;) {
        token = Com_Parse(&p);
        if (token == NULL || token[0] == '\0' || token[0] == '}')
            break;

        if (I_stricmp(token, "loadmenu") != 0)
            continue;

        token = Com_Parse(&p);
        if (token == NULL || token[0] != '{')
            break;

        for (;;) {
            token = Com_Parse(&p);
            if (token == NULL || token[0] == '\0')
                goto done;
            if (I_stricmp(token, "}") == 0)
                break;

            UI_ParseMenuInternal(token, imageTrack);
        }
    }

done:
    Com_EndParseSession();
    return UI_MenuList();
}

/* line 2587 */
MenuList * UI_LoadMenu(const char *menuFile, int imageTrack)
{
    memset(g_load, 0, sizeof(g_load));
    UI_MenuList()->menus = UI_MenuStorage();

    if (!UI_ParseMenuInternal(menuFile, imageTrack)) {
        Com_Printf("^3WARNING: menu file not found: %s\n", menuFile);
        if (!UI_ParseMenuInternal("ui/default.menu", imageTrack))
            Com_Error(ERR_DROP, "default menu file not found");
    }

    return UI_MenuList();
}
#else
void UI_MapLoadInfo(const char *filename) {
    void *loadfile;
    const char *parse;
    const char *token;
    char key[256];
    char name[64];
    int tokenLen;
    int material;
    const char *value;

    if (!filename[0])
        return;

    if (FS_ReadFile(filename, &loadfile) < 0) {
        Com_Printf((const char *)str_002b4034, filename);
        return;
    }

    parse = (const char *)loadfile;
    Com_BeginParseSession(filename);
    Com_SetCSV(1);

    for (;;) {
        token = Com_Parse(&parse);
        if (!token[0])
            break;

        tokenLen = strlen(token);
        if (tokenLen + 1 > 255) {
            Com_EndParseSession();
            Com_Error(1, (const char *)str_002b4058, key, tokenLen, 255);
        }

        memcpy(key, token, tokenLen + 1);

        value = Com_ParseOnLine(&parse);
        if (!value[0]) {
            Com_EndParseSession();
            Com_Error(1, (const char *)str_002b407c, key, filename);
        }

        material = (int)CL_RegisterMaterialNoMip(value, 3);
        Com_sprintf(name, 64, (const char *)str_002b409c, key);
        I_strlwr(name);
        CL_Material_Duplicate(material, name);
    }

    Com_EndParseSession();
    FS_FreeFile(loadfile);
}
#endif
