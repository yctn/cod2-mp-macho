/* ASM dump from: cl_console_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_console_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/q_shared.h"
 */

extern void Field_Clear(void *field);
extern int g_console_field_width; /* 0x0 */
extern float g_console_char_height; /* 0x0 */
extern const dvar_t *con_gamemessagetime; /* 0x0 */
extern const dvar_t *con_boldgamemessagetime; /* 0x0 */
extern const dvar_t *con_minicontime; /* 0x0 */
extern const dvar_t *con_miniconlines; /* 0x0 */
extern const dvar_t *con_restricted; /* 0x0 */
static struct ConDrawInputGlob conDrawInputGlob; /* conDrawInputGlob */
static struct Console con; /* con */
static const dvar_t *con_inputBoxColor; /* con_inputBoxColor */
static const dvar_t *con_inputHintBoxColor; /* con_inputHintBoxColor */
static const dvar_t *con_outputBarColor; /* con_outputBarColor */
static const dvar_t *con_outputSliderColor; /* con_outputSliderColor */
static const dvar_t *con_outputWindowColor; /* con_outputWindowColor */
extern int I_stricmp(const char *s1, const char *s2);

static vec4_t con_versionColor; /* con_versionColor */
static vec4_t con_inputCommandMatchColor; /* con_inputCommandMatchColor */
static vec4_t con_inputDvarMatchColor; /* con_inputDvarMatchColor */
static vec4_t con_inputDvarValueColor; /* con_inputDvarValueColor */
static vec4_t con_inputDvarInactiveValueColor; /* con_inputDvarInactiveValueColor */
static vec4_t con_inputDvarInfoColor; /* con_inputDvarInfoColor */
static int registeredIconMaterialCount; /* registeredIconMaterialCount */
static const char * hudMsgIconMaterials[256]; /* hudMsgIconMaterials */

void CL_RegisterHudMsgIconMaterial(const char *name);
const char * CL_GetHudMsgIconMaterialName(int index);
void Con_ToggleConsole_f(void);
static void Con_ChatModePublic_f(void);
static void Con_ChatModeTeam_f(void);
void Con_Bottom(void);
static void Con_Dump_f(void);
void Con_Shutdown(void);
static void Con_UpdateMessageWindowLine(qboolean linefeed);
static void Con_Linefeed(void);
void Con_AutoCompleteFromList(const char * *strings, int stringCount, const char *prefix, char *completed, int sizeofCompleted);
static void ConDraw_Box(float x, float y, float w, float h);
static int ConDrawInput_CompareStrings(const void *e0, const void *e1);
static void Con_DrawStringOnHUD(int y, int horzAlign, int vertAlign, const short int *string, int length, float msgwndScale, qboolean centerText);
void Con_DrawSay(int y);
void Con_ToggleConsoleOutput(void);
static void Con_DrawOuputWindow(void);
void Con_PageUp(void);
void Con_PageDown(void);
void Con_Top(void);
Bool Con_IsActive(void);
static void Con_Clear_f(void);
static void CL_AddConsoleInfoColor(void);
static void Con_DrawMessageWindow(int x, int y, int charHeight, int horzAlign, int vertAlign, float alpha, float msgwndScale, msgwnd_mode_t mode);
void Con_DrawSubtitles(int xPos, int yPos, int charHeight, float alpha, msgwnd_mode_t mode);
void Con_DrawMiniConsole(int xPos, int yPos, float alpha);
void Con_DrawBoldMessages(int xPos, int yPos, float alpha, msgwnd_mode_t mode);
void Con_DrawNotify(int xPos, int yPos, float alpha, msgwnd_mode_t mode);
static void ConDrawInput_IncrMatchCounter(const char *str);
void Con_ClearNotify(void);
void Con_ClearSubtitles(void);
static void ConDrawInput_DvarMatch(const char *str);
const char * Con_TokenizeInput(void);
Bool Con_AnySpaceAfterCommand(void);
static void Con_CheckResize(void);
static void Con_OneTimeInit(void);
void Con_Close(void);
static void ConDrawInput_AutoCompleteArg(int stringCount);
static void ConDrawInput_CmdMatch(const char *str);
static int CL_ConsolePrint_AddLine(print_msg_type_t type, int duration, int linewidth, int color);
void CL_ConsolePrint(print_msg_type_t type, const char *txt, int duration, int linewidth);
void CL_ConsoleFixPosition(void);
static void ConDrawInput_DetailedDvarMatch(const char *str);
static void ConDrawInput_DetailedCmdMatch(const char *str);
static void Con_DrawInput(void);
void Con_DrawConsole(void);
void Con_Init(void);
void CL_DeathMessagePrint(const char *attackerName, const vec_t *attackerColor, const char *victimName, const vec_t *victimColor, const char *iconShader, float iconWidth, float iconHeight, const vec_t *iconColor, int horzFlipIcon);

/* line 211 */
__attribute__((naked))
void CL_RegisterHudMsgIconMaterial(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 211 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl registeredIconMaterialCount, %edi\n" /* line 218 */
        "testl %edi, %edi\n"
        "jle .Lf15b608_0015b641\n"
        "xorl %esi, %esi\n" /* index */
        "movl $hudMsgIconMaterials, %ebx\n"
        ".Lf15b608_0015b622:\n"
        "movl 8(%ebp), %eax\n" /* line 220 | name */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf15b608_0015b65a\n"
        "addl $1, %esi\n" /* line 218 | index */
        "addl $4, %ebx\n"
        "cmpl %edi, %esi\n" /* index */
        "jne .Lf15b608_0015b622\n"
        ".Lf15b608_0015b641:\n"
        "movl 8(%ebp), %eax\n" /* line 224 | name */
        "movl %eax, (%esp)\n"
        "calll CopyStringInternal\n"
        "movl %eax, hudMsgIconMaterials(, %edi, 4)\n"
        "addl $1, registeredIconMaterialCount\n" /* line 225 */
        /* } scope */
        ".Lf15b608_0015b65a:\n"
        "addl $0x1c, %esp\n" /* line 226 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 229 */
const char * CL_GetHudMsgIconMaterialName(int index)
{
    return hudMsgIconMaterials[(unsigned char)index];
}

/* line 265 */
void Con_ToggleConsole_f(void)
{
    char *field;
    if (!*(byte *)((char *)con_restricted + 8)) {
        if (*(int *)((char *)*(void **)imp_keys + 0x780))
            goto toggle;
        if (!(*(int *)((char *)*(void **)imp_cl + 4) & 1))
            return;
    }
toggle:
    field = (char *)imp_g_consoleField;
    Field_Clear(field);
    *(int *)(field + 0xc) = g_console_field_width;
    *(int *)(field + 0x10) = *(int *)&g_console_char_height;
    *(int *)(field + 0x14) = 1;
    *(byte *)((char *)&con + 131100) = 0;
    *(int *)(4 + (char *)imp_clients) ^= 1;
}

/* line 319 */
static void Con_ChatModePublic_f(void)
{
    char *field;
    **(int **)imp_chat_team = 0;
    field = *(char **)*(int **)imp_chatField;
    Field_Clear(field);
    *(int *)(field + 0xc) = 0x24c;
    *(int *)(field + 0x10) = 0x41200000;
    *(int *)(field + 0x14) = 0;
    *(int *)((char *)*(void **)imp_cl + 4) ^= 0x10;
}

/* line 331 */
static void Con_ChatModeTeam_f(void)
{
    char *field;
    **(int **)imp_chat_team = 1;
    field = *(char **)*(int **)imp_chatField;
    Field_Clear(field);
    *(int *)(field + 0xc) = 0x21f;
    *(int *)(field + 0x10) = 0x41200000;
    *(int *)(field + 0x14) = 0;
    *(int *)((char *)*(void **)imp_cl + 4) ^= 0x10;
}

/* line 2032 */
void Con_Bottom(void)
{
    *(int *)((char *)&con + 131084) = *(int *)((char *)&con + 131076);
}

/* line 354 */
static __attribute__((naked))
void Con_Dump_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 354 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 363 */
        "cmpl $2, %eax\n"
        "je .Lf15b798_0015b7c5\n"
        "movl $str_002ab710, (%esp)\n" /* line 365 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf15b798_0015b7ba:\n"
        "addl $0x43c, %esp\n" /* line 418 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15b798_0015b7c5:\n"
        "movl $1, (%esp)\n" /* line 369 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab72c, (%esp)\n" /* "Dumped console text to %s.
" */
        "calll Com_Printf\n"
        "movl $1, (%esp)\n" /* line 379 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileWrite\n"
        "movl %eax, -0x41c(%ebp)\n" /* f */
        "testl %eax, %eax\n" /* line 380 */
        "je .Lf15b798_0015b973\n"
        "movl con+131076, %edi\n" /* line 387 | line */
        "movl con+131096, %ebx\n"
        "movl %edi, %eax\n" /* line */
        "subl %ebx, %eax\n"
        "leal 1(%eax), %esi\n" /* lineIndex */
        "cmpl %esi, %edi\n" /* lineIndex, line */
        "jl .Lf15b798_0015b921\n"
        "movl con+131092, %ecx\n" /* line 389 */
        ".Lf15b798_0015b824:\n"
        "movl %esi, %eax\n" /* lineIndex */
        "cltd\n"
        "idivl %ebx\n"
        "imull %ecx, %edx\n"
        "leal (%edx, %edx), %eax\n"
        "leal con+4(%eax), %edx\n"
        "cmpl $0, %ecx\n" /* line 390 */
        "jle .Lf15b798_0015b95d\n"
        "cmpb $0x20, con+4(%eax)\n" /* line 392 */
        "je .Lf15b798_0015b984\n"
        ".Lf15b798_0015b84b:\n"
        "movb $0, -0x418(%ebp, %ecx)\n" /* line 400 */
        "cmpl %esi, %edi\n" /* line 401 | lineIndex, line */
        "jge .Lf15b798_0015b8ed\n"
        ".Lf15b798_0015b85b:\n"
        "movl -0x41c(%ebp), %eax\n" /* line 417 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        /* } scope */
        "addl $0x43c, %esp\n" /* line 418 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15b798_0015b874:\n"
        "movl %ecx, %edi\n" /* line 406 | line */
        "subl $1, %edi\n" /* line */
        "js .Lf15b798_0015b889\n"
        "cmpb $0x20, -0x418(%ebp, %edi)\n" /* line 408 */
        "je .Lf15b798_0015b92c\n"
        ".Lf15b798_0015b889:\n"
        "movl $str_002160e8, 8(%esp)\n" /* line 413 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll I_strncat\n"
        "movl -0x41c(%ebp), %eax\n" /* line 414 | f */
        "movl %eax, 8(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x418(%ebp), %edi\n" /* buffer, line */
        "repne scasb %es:(%edi), %al\n" /* line */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buffer */
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "addl $1, %esi\n" /* line 401 | lineIndex */
        "cmpl con+131076, %esi\n" /* lineIndex */
        "jg .Lf15b798_0015b85b\n"
        "movl con+131092, %ecx\n"
        ".Lf15b798_0015b8ed:\n"
        "movl %esi, %eax\n" /* line 403 | lineIndex */
        "cltd\n"
        "idivl con+131096\n"
        "imull %ecx, %edx\n"
        "leal con+4(%edx, %edx), %edi\n" /* line */
        "testl %ecx, %ecx\n" /* line 404 */
        "jle .Lf15b798_0015b874\n"
        "xorl %edx, %edx\n"
        ".Lf15b798_0015b90a:\n"
        "movzwl (%edi, %edx, 2), %eax\n" /* line 405 | line */
        "movb %al, -0x418(%edx, %ebp)\n"
        "addl $1, %edx\n" /* line 404 */
        "cmpl %edx, %ecx\n"
        "jne .Lf15b798_0015b90a\n"
        "jmp .Lf15b798_0015b874\n"
        ".Lf15b798_0015b921:\n"
        "movl con+131092, %ecx\n"
        "jmp .Lf15b798_0015b84b\n"
        ".Lf15b798_0015b92c:\n"
        "leal -0x418(%ebp), %eax\n" /* line 411 | buffer */
        "addl %edi, %eax\n" /* line */
        "xorl %ebx, %ebx\n"
        "leal -0x41a(%ecx, %ebp), %ecx\n"
        "subl %eax, %ecx\n"
        ".Lf15b798_0015b93f:\n"
        "movl %eax, %edx\n" /* line 354 */
        "movb $0, (%eax)\n" /* line 409 */
        "cmpl %edi, %ebx\n" /* line 406 | line */
        "je .Lf15b798_0015b889\n"
        "addl $1, %ebx\n"
        "subl $1, %eax\n"
        "cmpb $0x20, (%edx, %ecx)\n" /* line 408 */
        "je .Lf15b798_0015b93f\n"
        "jmp .Lf15b798_0015b889\n"
        ".Lf15b798_0015b95d:\n"
        "jne .Lf15b798_0015b84b\n" /* line 395 */
        ".Lf15b798_0015b963:\n"
        "addl $1, %esi\n" /* line 387 | lineIndex */
        "cmpl %esi, %edi\n" /* lineIndex, line */
        "jge .Lf15b798_0015b824\n"
        "jmp .Lf15b798_0015b84b\n"
        ".Lf15b798_0015b973:\n"
        "movl $str_002a9268, (%esp)\n" /* line 382 */
        "calll Com_Printf\n"
        "jmp .Lf15b798_0015b7ba\n"
        ".Lf15b798_0015b984:\n"
        "xorl %eax, %eax\n" /* line 393 */
        ".Lf15b798_0015b986:\n"
        "addl $1, %eax\n" /* line 390 */
        "cmpl %eax, %ecx\n"
        "je .Lf15b798_0015b963\n"
        "cmpb $0x20, (%edx, %eax, 2)\n" /* line 392 */
        "je .Lf15b798_0015b986\n"
        "jmp .Lf15b798_0015b84b\n"
    );
}

/* line 583 */
__attribute__((naked))
void Con_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 583 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl registeredIconMaterialCount, %eax\n" /* line 203 */
        "testl %eax, %eax\n"
        "jne .Lf15b998_0015b9a9\n"
        ".Lf15b998_0015b9a7:\n"
        "leave\n" /* line 586 */
        "retl\n"
        ".Lf15b998_0015b9a9:\n"
        "subl $1, %eax\n" /* line 205 */
        "movl %eax, registeredIconMaterialCount\n"
        "movl hudMsgIconMaterials(, %eax, 4), %eax\n" /* line 206 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl registeredIconMaterialCount, %eax\n" /* line 203 */
        "testl %eax, %eax\n"
        "je .Lf15b998_0015b9a7\n"
        "subl $1, %eax\n" /* line 205 */
        "movl %eax, registeredIconMaterialCount\n"
        "movl hudMsgIconMaterials(, %eax, 4), %eax\n" /* line 206 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl registeredIconMaterialCount, %eax\n" /* line 203 */
        "testl %eax, %eax\n"
        "jne .Lf15b998_0015b9a9\n"
        "jmp .Lf15b998_0015b9a7\n"
    );
}

/* line 620 */
static __attribute__((naked))
void Con_UpdateMessageWindowLine(qboolean linefeed)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 620 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %edi\n" /* msgwnd */
        "movl %edx, -0x24(%ebp)\n"
        /* { scope 1 */
        "movl 4(%eax), %eax\n" /* line 630 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl (%edi), %eax\n" /* msgwnd */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* line */
        "movl imp_cl, %eax\n" /* line 632 */
        "movl (%eax), %edx\n"
        "movl 0x26f0(%edx), %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* line */
        "movl %eax, 0x9c(%ebx)\n"
        "addl 0x26f0(%edx), %ecx\n" /* line 633 | duration */
        "movl %ecx, 0xa0(%ebx)\n" /* duration */
        /* { scope 2 */
        "movl con+131092, %ebx\n" /* line 600 */
        "movl %ebx, %ecx\n"
        "cmpl $0x4f, %ebx\n"
        "movl $0x4e, %eax\n"
        "cmovgel %eax, %ebx\n"
        "movl con+131076, %eax\n" /* line 601 */
        "cltd\n"
        "idivl con+131096\n"
        "imull %edx, %ecx\n"
        "testl %ebx, %ebx\n" /* line 603 */
        "jle .Lf15b9ec_0015ba72\n"
        "leal con+4(%ecx, %ecx), %ecx\n"
        "movl -0x1c(%ebp), %edx\n" /* line */
        "xorl %esi, %esi\n" /* charIndex */
        ".Lf15b9ec_0015ba5f:\n"
        "movzwl (%ecx), %eax\n" /* line 607 */
        "movw %ax, (%edx)\n"
        "addl $1, %esi\n" /* line 603 | charIndex */
        "addl $2, %ecx\n"
        "addl $2, %edx\n"
        "cmpl %esi, %ebx\n" /* charIndex */
        "jne .Lf15b9ec_0015ba5f\n"
        ".Lf15b9ec_0015ba72:\n"
        "cmpl $0x4d, %ebx\n" /* line 610 */
        "jle .Lf15b9ec_0015bb1e\n"
        /* } scope */
        ".Lf15b9ec_0015ba7b:\n"
        "movl -0x24(%ebp), %ebx\n" /* line 637 */
        "testl %ebx, %ebx\n"
        "je .Lf15b9ec_0015bb16\n"
        "movl 8(%edi), %edx\n" /* msgwnd */
        "testl %edx, %edx\n"
        "jle .Lf15b9ec_0015bb16\n"
        "movl 4(%edi), %eax\n" /* line 639 | msgwnd */
        "addl $1, %eax\n"
        "movl %edx, %ebx\n"
        "cltd\n"
        "idivl %ebx\n"
        "movl %edx, 4(%edi)\n" /* msgwnd */
        "movl 0xc(%edi), %ecx\n" /* line 642 | msgwnd, duration */
        "testl %ecx, %ecx\n" /* duration */
        "jle .Lf15b9ec_0015bb16\n"
        "movl $0, -0x20(%ebp)\n" /* i */
        "jmp .Lf15b9ec_0015bab2\n"
        ".Lf15b9ec_0015baaf:\n"
        "movl 4(%edi), %edx\n" /* msgwnd */
        ".Lf15b9ec_0015bab2:\n"
        "movl -0x20(%ebp), %eax\n" /* line 646 | i */
        "addl %edx, %eax\n"
        "cltd\n"
        "idivl 8(%edi)\n" /* msgwnd */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl (%edi), %edx\n" /* msgwnd */
        "leal (%edx, %eax, 4), %ebx\n"
        "movl 0xa0(%ebx), %ecx\n" /* line 648 | duration */
        "movl 0x18(%edi), %esi\n" /* msgwnd, charIndex */
        "movl imp_cl, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x26f0(%eax), %edx\n"
        "movl %ecx, %eax\n" /* duration */
        "subl %esi, %eax\n" /* charIndex */
        "cmpl %edx, %eax\n"
        "jle .Lf15b9ec_0015bb0a\n"
        "subl 0x9c(%ebx), %ecx\n" /* line 652 | duration */
        "subl %ecx, %edx\n" /* duration */
        "leal (%esi, %edx), %eax\n" /* charIndex */
        "movl %eax, 0x9c(%ebx)\n"
        "movl -0x28(%ebp), %edx\n" /* line 653 */
        "movl 0x26f0(%edx), %eax\n"
        "addl 0x18(%edi), %eax\n" /* msgwnd */
        "movl %eax, 0xa0(%ebx)\n"
        ".Lf15b9ec_0015bb0a:\n"
        "addl $1, -0x20(%ebp)\n" /* line 642 | i */
        "movl -0x20(%ebp), %ecx\n" /* i, duration */
        "cmpl 0xc(%edi), %ecx\n" /* msgwnd, duration */
        "jl .Lf15b9ec_0015baaf\n"
        /* } scope */
        ".Lf15b9ec_0015bb16:\n"
        "addl $0x2c, %esp\n" /* line 657 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf15b9ec_0015bb1e:\n"
        "movl $0x37, (%esp)\n" /* line 612 */
        "calll ColorIndex\n"
        "shll $8, %eax\n"
        "orl $0x20, %eax\n"
        "movl -0x1c(%ebp), %ecx\n" /* line */
        "leal (%ecx, %ebx, 2), %edx\n"
        ".Lf15b9ec_0015bb36:\n"
        "movw %ax, (%edx)\n" /* line 615 */
        "addl $1, %ebx\n" /* line 614 */
        "addl $2, %edx\n"
        "cmpl $0x4e, %ebx\n"
        "jne .Lf15b9ec_0015bb36\n"
        "jmp .Lf15b9ec_0015ba7b\n"
    );
}

/* line 686 */
static __attribute__((naked))
void Con_Linefeed(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 686 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl con+131076, %esi\n" /* line 662 */
        "testl %esi, %esi\n"
        "js .Lf15bb4a_0015bb7e\n"
        "cmpl $1, %eax\n" /* line 665 */
        "je .Lf15bb4a_0015bbfd\n"
        "jle .Lf15bb4a_0015bc13\n"
        "cmpl $2, %eax\n"
        "je .Lf15bb4a_0015bc51\n"
        "cmpl $3, %eax\n"
        "je .Lf15bb4a_0015bc36\n"
        ".Lf15bb4a_0015bb7e:\n"
        "movl $0, con+131080\n" /* line 693 */
        "movl con+131084, %eax\n" /* line 694 | type */
        "cmpl con+131076, %eax\n" /* type */
        "je .Lf15bb4a_0015bbf3\n"
        ".Lf15bb4a_0015bb95:\n"
        "addl $1, con+131076\n" /* line 696 */
        "movl con+131092, %ecx\n" /* line 698 */
        "testl %ecx, %ecx\n"
        "jg .Lf15bb4a_0015bbae\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 704 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15bb4a_0015bbae:\n"
        "xorl %esi, %esi\n" /* line 698 | cursor */
        "movl $con, %edi\n"
        ".Lf15bb4a_0015bbb5:\n"
        "movl con+131076, %eax\n" /* line 700 | type */
        "cltd\n"
        "idivl con+131096\n"
        "imull %edx, %ecx\n" /* duration */
        "leal (%esi, %ecx), %ebx\n" /* cursor, textIndex */
        "movl $0x37, (%esp)\n" /* line 702 */
        "calll ColorIndex\n"
        "shll $8, %eax\n" /* type */
        "orl $0x20, %eax\n" /* type */
        "movw %ax, 4(%edi, %ebx, 2)\n" /* type */
        "addl $1, %esi\n" /* line 698 | cursor */
        "movl con+131092, %ecx\n"
        "cmpl %esi, %ecx\n" /* cursor */
        "jg .Lf15bb4a_0015bbb5\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 704 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15bb4a_0015bbf3:\n"
        "addl $1, %eax\n" /* line 695 | type */
        "movl %eax, con+131084\n" /* type */
        "jmp .Lf15bb4a_0015bb95\n"
        ".Lf15bb4a_0015bbfd:\n"
        "movl %edx, %ecx\n" /* line 671 */
        "movl $1, %edx\n"
        "movl con+131120, %eax\n"
        "calll Con_UpdateMessageWindowLine\n"
        "jmp .Lf15bb4a_0015bb7e\n"
        ".Lf15bb4a_0015bc13:\n"
        "testl %eax, %eax\n" /* line 665 */
        "jne .Lf15bb4a_0015bb7e\n"
        "movl con+131120, %eax\n" /* line 668 */
        "addl $0xfb4, %eax\n"
        "movl %edx, %ecx\n"
        "movl $1, %edx\n"
        "calll Con_UpdateMessageWindowLine\n"
        "jmp .Lf15bb4a_0015bb7e\n"
        ".Lf15bb4a_0015bc36:\n"
        "movl con+131120, %eax\n" /* line 677 */
        "addl $0xa78, %eax\n"
        "movl %edx, %ecx\n"
        "movl $1, %edx\n"
        "calll Con_UpdateMessageWindowLine\n"
        "jmp .Lf15bb4a_0015bb7e\n"
        ".Lf15bb4a_0015bc51:\n"
        "movl con+131120, %eax\n" /* line 674 */
        "addl $0x53c, %eax\n"
        "movl %edx, %ecx\n"
        "movl $1, %edx\n"
        "calll Con_UpdateMessageWindowLine\n"
        "jmp .Lf15bb4a_0015bb7e\n"
    );
}

/* line 1102 */
__attribute__((naked))
void Con_AutoCompleteFromList(const char * *strings, int stringCount, const char *prefix, char *completed, int sizeofCompleted)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1102 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "cld\n" /* line 1109 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0x10(%ebp), %edi\n" /* prefix, string */
        "repne scasb %es:(%edi), %al\n" /* string */
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* prefixLen */
        "movl 0x14(%ebp), %eax\n" /* line 1110 | completed */
        "movb $0, (%eax)\n"
        "movl 0xc(%ebp), %edi\n" /* line 1111 | stringCount, string */
        "testl %edi, %edi\n" /* string */
        "jg .Lf15bc6c_0015bc9c\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1126 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15bc6c_0015bc9c:\n"
        "xorl %ebx, %ebx\n" /* line 1111 | stringIndex */
        ".Lf15bc6c_0015bc9e:\n"
        "movl 8(%ebp), %eax\n" /* line 1113 | strings */
        "movl (%eax, %ebx, 4), %edi\n" /* string */
        "movl %esi, 8(%esp)\n" /* line 1114 | prefixLen */
        "movl %edi, 4(%esp)\n" /* string */
        "movl 0x10(%ebp), %eax\n" /* prefix */
        "movl %eax, (%esp)\n"
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf15bc6c_0015bcd0\n"
        "movl 0x14(%ebp), %eax\n" /* line 1116 | completed */
        "cmpb $0, (%eax)\n"
        "je .Lf15bc6c_0015bd08\n"
        "addl %esi, %eax\n" /* line 1122 | prefixLen */
        "movzbl (%eax), %edx\n"
        "cmpb (%edi, %esi), %dl\n" /* string */
        "je .Lf15bc6c_0015bce0\n"
        ".Lf15bc6c_0015bccd:\n"
        "movb $0, (%eax)\n" /* line 1124 */
        ".Lf15bc6c_0015bcd0:\n"
        "addl $1, %ebx\n" /* line 1111 | stringIndex */
        "cmpl %ebx, 0xc(%ebp)\n" /* stringIndex, stringCount */
        "jne .Lf15bc6c_0015bc9e\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1126 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15bc6c_0015bce0:\n"
        "testb %dl, %dl\n" /* line 1122 */
        "je .Lf15bc6c_0015bccd\n"
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal (%edi, %esi), %edx\n" /* line 1102 */
        "jmp .Lf15bc6c_0015bcf1\n"
        ".Lf15bc6c_0015bcef:\n"
        "movl %edi, %eax\n"
        ".Lf15bc6c_0015bcf1:\n"
        "movzbl (%eax), %ecx\n" /* line 1122 */
        "cmpb 1(%edx), %cl\n"
        "jne .Lf15bc6c_0015bccd\n"
        "leal 1(%eax), %edi\n" /* string */
        "movl %edi, -0x1c(%ebp)\n" /* string */
        "addl $1, %edx\n"
        "testb %cl, %cl\n"
        "jne .Lf15bc6c_0015bcef\n"
        "jmp .Lf15bc6c_0015bccd\n"
        ".Lf15bc6c_0015bd08:\n"
        "movl 0x18(%ebp), %eax\n" /* line 1118 | sizeofCompleted */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* string */
        "movl 0x14(%ebp), %edi\n" /* completed, string */
        "movl %edi, (%esp)\n" /* string */
        "calll I_strncpyz\n"
        "jmp .Lf15bc6c_0015bcd0\n"
    );
}

/* line 1211 */
static __attribute__((naked))
void ConDraw_Box(float x, float y, float w, float h)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1211 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movss %xmm2, -0x34(%ebp)\n"
        "movss %xmm3, -0x38(%ebp)\n"
        "movl %eax, %esi\n" /* color */
        /* { scope 1 */
        "movl imp_cls, %edi\n" /* line 1215 */
        "movl 0x2a0a58(%edi), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* color */
        "xorl %ebx, %ebx\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movss %xmm3, 0xc(%esp)\n"
        "movss %xmm2, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x94(%eax)\n"
        "movss lit4_002ed5d8, %xmm0\n" /* line 519 | 0.5f */
        "movss (%esi), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* darkColor */
        "movss 4(%esi), %xmm1\n" /* line 520 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "mulss 8(%esi), %xmm0\n" /* line 521 */
        "movss %xmm0, -0x20(%ebp)\n"
        "movl 0xc(%esi), %eax\n" /* line 522 */
        "movl %eax, -0x1c(%ebp)\n" /* line 1218 */
        "movl 0x2a0a58(%edi), %eax\n" /* line 1220 */
        "movl %eax, 0x24(%esp)\n"
        "leal -0x28(%ebp), %esi\n" /* darkColor, color */
        "movl %esi, 0x20(%esp)\n" /* color */
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x40000000, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x94(%eax)\n"
        "movl 0x2a0a58(%edi), %eax\n" /* line 1221 */
        "movl %eax, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* color */
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x40000000, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "addss -0x34(%ebp), %xmm0\n"
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x94(%eax)\n"
        "movl 0x2a0a58(%edi), %eax\n" /* line 1222 */
        "movl %eax, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* color */
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl $0x40000000, 0xc(%esp)\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x94(%eax)\n"
        "movl 0x2a0a58(%edi), %eax\n" /* line 1223 */
        "movl %eax, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* color */
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl $0x40000000, 0xc(%esp)\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x94(%eax)\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1224 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1278 */
static int ConDrawInput_CompareStrings(const void *e0, const void *e1)
{
    return I_stricmp(*(const char **)e0, *(const char **)e1);
}

/* line 1528 */
static __attribute__((naked))
void Con_DrawStringOnHUD(int y, int horzAlign, int vertAlign, const short int *string, int length, float msgwndScale, qboolean centerText)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1528 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %edi\n" /* vertAlign, x */
        "movl %edx, -0x40(%ebp)\n"
        "movss %xmm1, -0x44(%ebp)\n"
        /* { scope 1 */
        "movl $0x3f800000, %eax\n" /* line 447 */
        "movl %eax, -0x38(%ebp)\n" /* color */
        "movl %eax, -0x34(%ebp)\n" /* line 448 */
        "movl %eax, -0x30(%ebp)\n" /* line 449 */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 450 */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 1540 | charHeight, alpha */
        "divss lit4_002ed6b8, %xmm0\n" /* 48.0f, alpha */
        "movss %xmm0, -0x3c(%ebp)\n" /* alpha, fontScale */
        "movl 0x18(%ebp), %eax\n" /* line 1542 | centerText */
        "testl %eax, %eax\n"
        "je .Lf15bf48_0015c0a6\n"
        "movss %xmm0, 4(%esp)\n" /* line 1544 | alpha */
        "movl $4, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %esi\n" /* font */
        "movl imp_re, %ebx\n" /* line 1545 */
        "movss -0x3c(%ebp), %xmm0\n" /* fontScale, alpha */
        "movss %xmm0, 4(%esp)\n" /* alpha */
        "movl %eax, (%esp)\n"
        "calll *0x110(%ebx)\n"
        "fstps -0x1c(%ebp)\n" /* xScale */
        "movl %esi, 8(%esp)\n" /* line 1546 | font */
        "movl 0x14(%ebp), %eax\n" /* length */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll *0x124(%ebx)\n"
        "cvtsi2ssl %eax, %xmm0\n" /* alpha */
        "mulss -0x1c(%ebp), %xmm0\n" /* xScale, alpha */
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f, alpha */
        "cvttss2si %xmm0, %eax\n" /* alpha */
        "subl %eax, %edi\n" /* x */
        ".Lf15bf48_0015bfe9:\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 1553 | alpha */
        "mulss -0x1c(%ebp), %xmm0\n" /* xScale, alpha */
        "movss %xmm0, -0x1c(%ebp)\n" /* alpha, xScale */
        "movss %xmm0, -0x20(%ebp)\n" /* line 1554 | alpha, yScale */
        "cvtsi2ssl %edi, %xmm0\n" /* line 1556 | x, alpha */
        "movss %xmm0, -0x24(%ebp)\n" /* alpha, xAdj */
        "movl imp_re, %ebx\n" /* line 1557 */
        "movl %esi, (%esp)\n" /* font */
        "calll *0x118(%ebx)\n"
        "cvtsi2ssl %eax, %xmm0\n" /* alpha */
        "mulss -0x20(%ebp), %xmm0\n" /* yScale, alpha */
        "cvttss2si %xmm0, %eax\n" /* alpha */
        "addl -0x40(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n" /* alpha */
        "movss %xmm0, -0x28(%ebp)\n" /* alpha, yAdj */
        "movl 0xc(%ebp), %eax\n" /* line 1559 | vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 8(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* yScale */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* xScale */
        "movl %eax, 8(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* yAdj */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* xAdj */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movl $3, 0x20(%esp)\n" /* line 1560 */
        "leal -0x38(%ebp), %eax\n" /* color */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* yScale */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* xScale */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* yAdj */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* xAdj */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* font */
        "movl 0x14(%ebp), %eax\n" /* length */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll *0x128(%ebx)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1561 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15bf48_0015c0a6:\n"
        "movss %xmm0, 4(%esp)\n" /* line 1550 | alpha */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %esi\n" /* font */
        "movss -0x3c(%ebp), %xmm0\n" /* line 1551 | fontScale, alpha */
        "movss %xmm0, 4(%esp)\n" /* alpha */
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x110(%eax)\n"
        "fstps -0x1c(%ebp)\n" /* xScale */
        "jmp .Lf15bf48_0015bfe9\n"
    );
}

/* line 1770 */
__attribute__((naked))
void Con_DrawSay(int y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1770 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl imp_cl, %eax\n" /* line 1778 */
        "movl (%eax), %eax\n"
        "testb $0x10, 4(%eax)\n"
        "jne .Lf15c0dc_0015c0fa\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1795 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15c0dc_0015c0fa:\n"
        "movl $0x3e555555, 4(%esp)\n" /* line 1781 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %edi\n" /* font */
        "movl imp_chat_team, %eax\n" /* line 1783 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf15c0dc_0015c242\n"
        "movl $str_002ab748, (%esp)\n" /* line 1784 */
        ".Lf15c0dc_0015c128:\n"
        "calll SEH_SafeTranslateString\n" /* line 1786 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021dc58, (%esp)\n" /* "%s: " */
        "calll va\n"
        "movl %eax, %esi\n" /* string */
        "movl $0x3e555555, 4(%esp)\n" /* line 1788 */
        "movl %edi, (%esp)\n" /* font */
        "movl imp_re, %eax\n"
        "calll *0x110(%eax)\n"
        "fstps -0x1c(%ebp)\n" /* normalizedScale */
        "movl imp_cg_hudSayPosition, %eax\n" /* line 1789 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cvttss2si (%eax), %ebx\n" /* x */
        "movl %edi, (%esp)\n" /* line 1791 | font */
        "movl imp_re, %edx\n"
        "calll *0x118(%edx)\n"
        "movl $3, 0x28(%esp)\n"
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0x24(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* normalizedScale */
        "movss %xmm0, 0x20(%esp)\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $1, 0x18(%esp)\n"
        "movl $1, 0x14(%esp)\n"
        "cvtsi2ssl 8(%ebp), %xmm1\n" /* y */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* normalizedScale */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* x */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* font */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* string */
        "calll CL_DrawText\n"
        "movl %edi, 8(%esp)\n" /* line 1792 | font */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* string */
        "movl imp_re, %edx\n"
        "calll *0x114(%edx)\n"
        "movl $1, 0x14(%esp)\n" /* line 1794 */
        "movl $1, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl 8(%ebp), %edx\n" /* y */
        "movl %edx, 8(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* normalizedScale */
        "cvttss2si %xmm0, %eax\n"
        "addl %eax, %ebx\n" /* x */
        "movl %ebx, 4(%esp)\n" /* x */
        "movl imp_chatField, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Field_Draw\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1795 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15c0dc_0015c242:\n"
        "movl $str_002ab754, (%esp)\n" /* line 1786 */
        "jmp .Lf15c0dc_0015c128\n"
    );
}

/* line 1873 */
void Con_ToggleConsoleOutput(void)
{
    *(byte *)((char *)&con + 131100) = (*(byte *)((char *)&con + 131100) == 0) ? 1 : 0;
}

/* line 1952 */
static __attribute__((naked))
void Con_DrawOuputWindow(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1952 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1: y */
        "movss con+131104, %xmm0\n" /* line 1959 */
        "movss %xmm0, -0x48(%ebp)\n" /* x */
        "movss con+131108, %xmm4\n" /* line 1960 */
        "movss con+131112, %xmm0\n" /* line 1962 */
        "subss -0x48(%ebp), %xmm0\n" /* x */
        "movss %xmm0, -0x44(%ebp)\n" /* width */
        "movss con+131116, %xmm5\n" /* line 1963 */
        "subss %xmm4, %xmm5\n"
        "movss lit4_002ed830, %xmm0\n" /* line 1965 | 32.0f */
        "addss %xmm0, %xmm4\n"
        "subss %xmm0, %xmm5\n" /* line 1966 */
        "movl con_outputWindowColor, %eax\n" /* line 1968 */
        "movl 8(%eax), %eax\n"
        "movaps %xmm5, %xmm3\n"
        "movss -0x44(%ebp), %xmm2\n" /* width */
        "movaps %xmm4, %xmm1\n"
        "movss -0x48(%ebp), %xmm0\n" /* x */
        "movss %xmm4, -0x58(%ebp)\n"
        "movss %xmm5, -0x68(%ebp)\n"
        "calll ConDraw_Box\n"
        "movss lit4_002ed5e0, %xmm1\n" /* line 1970 | 6.0f */
        "movss -0x48(%ebp), %xmm0\n" /* x */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x58(%ebp), %xmm4\n" /* line 1971 */
        "addss %xmm1, %xmm4\n"
        "movss %xmm4, -0x30(%ebp)\n"
        "movss -0x68(%ebp), %xmm5\n" /* line 1974 */
        "subss lit4_002ed79c, %xmm5\n" /* 12.0f */
        "movss %xmm5, -0x38(%ebp)\n"
        "calll getBuildNumber\n" /* line 1937 */
        "movl $str_002167c8, 8(%esp)\n" /* "MacOSXS-i386" */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab75c, (%esp)\n" /* "Build %s %s" */
        "calll va\n"
        "cvttss2si -0x2c(%ebp), %edx\n" /* line 1948 */
        "movl %edx, -0x40(%ebp)\n"
        "movl $con_versionColor, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "subss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "addss -0x30(%ebp), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SCR_DrawSmallStringExt\n"
        /* { scope 2: color, rowCount */
        "movss -0x44(%ebp), %xmm6\n" /* line 1883 | width */
        "subss lit4_002ed79c, %xmm6\n" /* 12.0f */
        "addss -0x2c(%ebp), %xmm6\n"
        "movss lit4_002ed6b4, %xmm5\n" /* 10.0f */
        "subss %xmm5, %xmm6\n"
        "movl con_outputBarColor, %eax\n" /* line 1884 */
        "movl 8(%eax), %eax\n"
        "movss -0x38(%ebp), %xmm3\n"
        "movaps %xmm5, %xmm2\n"
        "movss -0x30(%ebp), %xmm1\n"
        "movaps %xmm6, %xmm0\n"
        "movss %xmm5, -0x68(%ebp)\n"
        "movss %xmm6, -0x78(%ebp)\n"
        "calll ConDraw_Box\n"
        "movl con_outputSliderColor, %eax\n" /* line 1890 */
        "movl 8(%eax), %eax\n"
        "movl con+131076, %edx\n"
        "subl con+131084, %edx\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "movl con+131096, %edx\n"
        "subl $1, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f */
        "subss %xmm1, %xmm4\n"
        "movss -0x30(%ebp), %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n"
        "movss -0x68(%ebp), %xmm5\n"
        "subss %xmm5, %xmm0\n"
        "subss -0x30(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "movaps %xmm5, %xmm3\n"
        "movaps %xmm5, %xmm2\n"
        "movss -0x30(%ebp), %xmm1\n"
        "addss %xmm4, %xmm1\n"
        "movss -0x78(%ebp), %xmm6\n"
        "movaps %xmm6, %xmm0\n"
        "calll ConDraw_Box\n"
        /* } scope */
        "movss -0x38(%ebp), %xmm0\n" /* line 1979 */
        "subss lit4_002ed8f0, %xmm0\n" /* 28.0f */
        "movss %xmm0, -0x34(%ebp)\n"
        /* { scope 2: color, rowCount */
        /* { scope 3 */
        "leal -0x28(%ebp), %eax\n" /* line 1902 | color */
        "movl %eax, 4(%esp)\n"
        "movl $0x37, (%esp)\n"
        "calll CL_LookupColor\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 1906 */
        "mulss lit4_002ed8f4, %xmm0\n" /* 0.0625f */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, -0x7c(%ebp)\n" /* rowCount */
        "movl con+131084, %esi\n" /* line 1907 | row */
        "cmpl $1, con+131080\n" /* line 1910 */
        "sbbl $0, %esi\n" /* row */
        "movss -0x30(%ebp), %xmm0\n" /* line 1912 */
        "addss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* y */
        "testl %edx, %edx\n" /* line 1914 */
        "jle .Lf15c262_0015c4f6\n"
        "testl %esi, %esi\n" /* line 1916 | row */
        "js .Lf15c262_0015c4f6\n"
        "xorl %ebx, %ebx\n" /* line 1917 | rowIndex */
        "jmp .Lf15c262_0015c48a\n"
        ".Lf15c262_0015c47b:\n"
        "addl $1, %ebx\n" /* line 1914 | rowIndex */
        "cmpl %ebx, -0x7c(%ebp)\n" /* rowIndex, rowCount */
        "je .Lf15c262_0015c4f6\n"
        ".Lf15c262_0015c483:\n"
        "leal 1(%esi), %eax\n" /* line 1916 | row */
        "cmpl %eax, %ebx\n" /* rowIndex */
        "je .Lf15c262_0015c4f6\n"
        ".Lf15c262_0015c48a:\n"
        "movl %esi, %ecx\n" /* line 1952 | row */
        "subl %ebx, %ecx\n" /* rowIndex */
        "movl con+131096, %edx\n" /* line 1919 */
        "movl con+131076, %eax\n"
        "subl %ecx, %eax\n"
        "cmpl %edx, %eax\n"
        "jge .Lf15c262_0015c47b\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 1924 | y */
        "subss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "movss %xmm0, -0x3c(%ebp)\n" /* y */
        "leal -0x28(%ebp), %eax\n" /* line 1925 | color */
        "movl %eax, 0x10(%esp)\n"
        "movl con+131092, %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %ecx, %eax\n"
        "movl %edx, %edi\n"
        "cltd\n"
        "idivl %edi\n"
        "imull con+131092, %edx\n"
        "leal con+4(%edx, %edx), %edx\n"
        "movl %edx, 8(%esp)\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SCR_DrawConsoleString\n"
        "addl $1, %ebx\n" /* line 1914 | rowIndex */
        "cmpl %ebx, -0x7c(%ebp)\n" /* rowIndex, rowCount */
        "jne .Lf15c262_0015c483\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf15c262_0015c4f6:\n"
        "addl $0x9c, %esp\n" /* line 1982 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2008 */
void Con_PageUp(void)
{
    con.display -= 2;
    if (con.currentLine - con.display >= con.totallines)
        con.display = con.currentLine - con.totallines + 1;
}

/* line 2016 */
void Con_PageDown(void)
{
    con.display += 2;
    if (con.display > con.currentLine)
        con.display = con.currentLine;
}

/* line 2024 */
void Con_Top(void)
{
    con.display = con.totallines;
    if (con.currentLine - con.totallines >= con.totallines)
        con.display = con.currentLine - con.totallines + 1;
}

/* line 2060 */
Bool Con_IsActive(void)
{
    return (*(int *)((char *)*(void **)imp_cl + 4) & 1) != 0;
}

/* line 343 */
static __attribute__((naked))
void Con_Clear_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 343 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $con, %ebx\n"
        ".Lf15c596_0015c5a2:\n"
        "movl $0x37, (%esp)\n" /* line 348 */
        "calll ColorIndex\n"
        "shll $8, %eax\n"
        "orl $0x20, %eax\n"
        "movw %ax, 4(%ebx)\n"
        "addl $2, %ebx\n"
        "cmpl $con+131072, %ebx\n" /* line 347 */
        "jne .Lf15c596_0015c5a2\n"
        "movl con+131076, %eax\n" /* line 2034 */
        "movl %eax, con+131084\n"
        "addl $0x14, %esp\n" /* line 351 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 966 */
static __attribute__((naked))
void CL_AddConsoleInfoColor(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 966 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl %eax, %edi\n" /* iFirstInfo */
        "movl %edx, %esi\n" /* vColor */
        "movss lit4_002ed5d4, %xmm3\n" /* line 971 | 255.0f */
        "movss (%edx), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm3, %xmm1\n"
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm3, %xmm4\n"
        "cmpnltss %xmm2, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        /* { scope 1 */
        "movaps %xmm2, %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "ucomiss %xmm4, %xmm2\n"
        "ja .Lf15c5d4_0015c74c\n"
        "movl $0, -0x14(%ebp)\n"
        /* } scope */
        ".Lf15c5d4_0015c62c:\n"
        "movl con+131076, %ebx\n" /* line 961 */
        "movl %ebx, %eax\n"
        "cltd\n"
        "idivl con+131096\n"
        "imull con+131092, %edx\n"
        "movl con+131080, %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edi, %eax\n"
        "shll $8, %eax\n"
        "orl -0x14(%ebp), %eax\n"
        "movw %ax, con+4(%edx, %edx)\n"
        "addl $1, %ecx\n" /* line 962 */
        "movl %ecx, con+131080\n"
        "movss 4(%esi), %xmm0\n" /* line 974 | vColor */
        "mulss %xmm3, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm3, %xmm1\n"
        "movaps %xmm3, %xmm4\n"
        "cmpnltss %xmm2, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        /* { scope 1 */
        "movaps %xmm2, %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "ucomiss %xmm4, %xmm2\n"
        "ja .Lf15c5d4_0015c740\n"
        "movl $0, -0x10(%ebp)\n"
        /* } scope */
        ".Lf15c5d4_0015c6a3:\n"
        "movl %ebx, %eax\n" /* line 961 */
        "cltd\n"
        "idivl con+131096\n"
        "imull con+131092, %edx\n"
        "leal (%ecx, %edx), %edx\n"
        "leal 1(%edi), %eax\n"
        "shll $8, %eax\n"
        "orl -0x10(%ebp), %eax\n"
        "movw %ax, con+4(%edx, %edx)\n"
        "addl $1, %ecx\n" /* line 962 */
        "movl %ecx, con+131080\n"
        "movss 8(%esi), %xmm0\n" /* line 977 | vColor */
        "mulss %xmm3, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm3, %xmm1\n"
        "movaps %xmm3, %xmm4\n"
        "cmpnltss %xmm2, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        /* { scope 1 */
        "movaps %xmm2, %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "ucomiss %xmm3, %xmm2\n"
        "ja .Lf15c5d4_0015c73a\n"
        "xorl %esi, %esi\n"
        /* } scope */
        ".Lf15c5d4_0015c707:\n"
        "movl %ebx, %eax\n" /* line 961 */
        "cltd\n"
        "idivl con+131096\n"
        "imull con+131092, %edx\n"
        "leal (%ecx, %edx), %edx\n"
        "leal 2(%edi), %eax\n"
        "shll $8, %eax\n"
        "orl %esi, %eax\n"
        "movw %ax, con+4(%edx, %edx)\n"
        "leal 1(%ecx), %eax\n" /* line 962 */
        "movl %eax, con+131080\n"
        "addl $0xc, %esp\n" /* line 979 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15c5d4_0015c73a:\n"
        "cvttss2si %xmm1, %esi\n" /* line 45 */
        "jmp .Lf15c5d4_0015c707\n"
        /* } scope */
        /* { scope 1 */
        ".Lf15c5d4_0015c740:\n"
        "cvttss2si %xmm1, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "jmp .Lf15c5d4_0015c6a3\n"
        /* } scope */
        /* { scope 1 */
        ".Lf15c5d4_0015c74c:\n"
        "cvttss2si %xmm1, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "jmp .Lf15c5d4_0015c62c\n"
    );
}

/* line 1632 */
static __attribute__((naked))
void Con_DrawMessageWindow(int x, int y, int charHeight, int horzAlign, int vertAlign, float alpha, float msgwndScale, msgwnd_mode_t mode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1632 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %edi\n" /* msgwnd */
        "movl %edx, -0x4c(%ebp)\n" /* mode */
        "movl %ecx, -0x50(%ebp)\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "movl 0x14(%ebp), %edx\n" /* mode */
        /* { scope 1: centered */
        "movl imp_cl, %ecx\n" /* line 1646 */
        "movl (%ecx), %eax\n"
        "cmpl $5, 0x38(%eax)\n"
        "je .Lf15c758_0015c78d\n"
        "testb $8, 4(%eax)\n"
        "jne .Lf15c758_0015c7ac\n"
        ".Lf15c758_0015c78d:\n"
        "cmpl $1, %edx\n" /* line 1649 */
        "je .Lf15c758_0015c7b7\n"
        ".Lf15c758_0015c792:\n"
        "jle .Lf15c758_0015cafe\n"
        "cmpl $3, %edx\n"
        "jle .Lf15c758_0015c8b9\n"
        /* } scope */
        ".Lf15c758_0015c7a1:\n"
        "addl $0x9c, %esp\n" /* line 1767 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: centered */
        ".Lf15c758_0015c7ac:\n"
        "cmpb $0, 8(%eax)\n" /* line 1646 */
        "je .Lf15c758_0015c7a1\n"
        "cmpl $1, %edx\n" /* line 1649 */
        "jne .Lf15c758_0015c792\n"
        ".Lf15c758_0015c7b7:\n"
        "movl -0x50(%ebp), %esi\n" /* line 1669 */
        "subl 8(%ebp), %esi\n" /* charHeight */
        "movl %esi, -0x34(%ebp)\n" /* v */
        "movl $1, -0x28(%ebp)\n" /* reversed */
        ".Lf15c758_0015c7c7:\n"
        "movl 4(%edi), %ebx\n" /* line 1671 | msgwnd, i */
        "movl %ebx, -0x68(%ebp)\n" /* i */
        "movl 8(%edi), %esi\n" /* msgwnd */
        "leal (%esi, %ebx), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "cmpl %ebx, %eax\n" /* i */
        "jle .Lf15c758_0015c7a1\n"
        "movl 8(%ebp), %edx\n" /* line 1746 | charHeight */
        "addl %edx, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* iOverStepStartHeight */
        "movl $0, -0x30(%ebp)\n" /* groupsize */
        "jmp .Lf15c758_0015c801\n"
        ".Lf15c758_0015c7f2:\n"
        "addl $1, %ebx\n" /* line 428 */
        "movl -0x68(%ebp), %eax\n"
        ".Lf15c758_0015c7f8:\n"
        "addl %esi, %eax\n" /* line 1671 */
        "movl %eax, -0x48(%ebp)\n"
        "cmpl %ebx, %eax\n" /* i */
        "jle .Lf15c758_0015c7a1\n"
        ".Lf15c758_0015c801:\n"
        "movl (%edi), %ecx\n" /* line 1675 | msgwnd */
        "movl %ecx, -0x44(%ebp)\n"
        "movl %ebx, %eax\n" /* i */
        "cltd\n"
        "idivl %esi\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* line */
        "movl 0x9c(%eax), %ecx\n" /* line 1677 */
        "testl %ecx, %ecx\n"
        "je .Lf15c758_0015c7f2\n"
        "movl imp_cl, %eax\n" /* line 1680 */
        "movl (%eax), %eax\n"
        "movl 0x26f0(%eax), %eax\n"
        "cmpl %eax, %ecx\n"
        "jle .Lf15c758_0015c850\n"
        "movl -0x24(%ebp), %ecx\n" /* line 1682 | line */
        "movl $0, 0x9c(%ecx)\n"
        "addl $1, %ebx\n" /* i */
        "movl 4(%edi), %esi\n" /* msgwnd */
        "movl %esi, -0x68(%ebp)\n"
        "movl 8(%edi), %esi\n" /* msgwnd */
        "movl -0x68(%ebp), %eax\n"
        "jmp .Lf15c758_0015c7f8\n"
        ".Lf15c758_0015c850:\n"
        "movl -0x24(%ebp), %edx\n" /* line 1686 | line */
        "movl 0xa0(%edx), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "cmpl %edx, %eax\n"
        "jle .Lf15c758_0015ca41\n"
        "movl 0x10(%edi), %ecx\n" /* line 1689 | msgwnd */
        "subl %edx, %eax\n"
        "movl %ecx, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "testl %edx, %edx\n" /* line 1690 */
        "jle .Lf15c758_0015c7f2\n"
        "movl -0x28(%ebp), %edx\n" /* line 1693 | reversed */
        "testl %edx, %edx\n"
        "je .Lf15c758_0015cb57\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "cvtsi2ssl %ecx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "cvtsi2ssl 8(%ebp), %xmm1\n" /* charHeight */
        "mulss %xmm1, %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x60(%ebp)\n"
        "cvttss2si -0x60(%ebp), %eax\n"
        "subl %eax, -0x34(%ebp)\n" /* v */
        "jmp .Lf15c758_0015c7f2\n"
        ".Lf15c758_0015c8b9:\n"
        "xorl %eax, %eax\n" /* line 1659 */
        "cmpl $3, %edx\n"
        "sete %al\n"
        "movl %eax, -0x20(%ebp)\n" /* centered */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %edx\n" /* line 1578 | charHeight */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* charHeight */
        "movl 4(%edi), %ecx\n" /* line 1580 */
        "movl %ecx, -0x68(%ebp)\n"
        "movl %ecx, %ebx\n" /* lineIndex */
        "movl 8(%edi), %esi\n"
        "leal (%esi, %ecx), %eax\n"
        "cmpl %ecx, %eax\n"
        "jg .Lf15c758_0015c947\n"
        ".Lf15c758_0015c8df:\n"
        "leal -1(%eax), %ebx\n" /* line 1600 | lineIndex */
        "cmpl %ebx, 4(%edi)\n" /* lineIndex */
        "jle .Lf15c758_0015c9a7\n"
        "jmp .Lf15c758_0015c7a1\n"
        ".Lf15c758_0015c8f0:\n"
        "subl %edx, %eax\n" /* line 1595 */
        "movl 0x10(%edi), %edx\n" /* line 1596 */
        "cmpl %edx, %eax\n"
        "jge .Lf15c758_0015c93a\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "cvtsi2ssl %edx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "cvtsi2ssl 8(%ebp), %xmm1\n" /* charHeight */
        "mulss %xmm1, %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x5c(%ebp)\n"
        "cvttss2si -0x5c(%ebp), %eax\n"
        "addl %eax, -0x50(%ebp)\n"
        ".Lf15c758_0015c93a:\n"
        "movl -0x68(%ebp), %edx\n"
        ".Lf15c758_0015c93d:\n"
        "addl $1, %ebx\n" /* line 1580 | lineIndex */
        "leal (%esi, %edx), %eax\n"
        "cmpl %ebx, %eax\n" /* lineIndex */
        "jle .Lf15c758_0015c8df\n"
        ".Lf15c758_0015c947:\n"
        "movl %ebx, %eax\n" /* line 1584 | lineIndex */
        "cltd\n"
        "idivl %esi\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl (%edi), %edx\n"
        "leal (%edx, %eax, 4), %ecx\n"
        "movl 0x9c(%ecx), %edx\n" /* line 1586 */
        "testl %edx, %edx\n"
        "je .Lf15c758_0015c93a\n"
        "movl imp_cl, %eax\n" /* line 1589 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl 0x26f0(%eax), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "cmpl %eax, %edx\n"
        "jle .Lf15c758_0015c8f0\n"
        "movl $0, 0x9c(%ecx)\n" /* line 1591 */
        "movl 4(%edi), %edx\n"
        "movl %edx, -0x68(%ebp)\n"
        "movl 8(%edi), %esi\n"
        "jmp .Lf15c758_0015c93d\n"
        ".Lf15c758_0015c991:\n"
        "movl $0, 0x9c(%ecx)\n" /* line 1611 */
        ".Lf15c758_0015c99b:\n"
        "subl $1, %ebx\n" /* line 1600 | lineIndex */
        "cmpl %ebx, 4(%edi)\n" /* lineIndex */
        "jg .Lf15c758_0015c7a1\n"
        ".Lf15c758_0015c9a7:\n"
        "movl %ebx, %eax\n" /* line 1604 | lineIndex */
        "cltd\n"
        "idivl 8(%edi)\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl (%edi), %edx\n"
        "leal (%edx, %eax, 4), %ecx\n"
        "movl 0x9c(%ecx), %edx\n" /* line 1606 */
        "testl %edx, %edx\n"
        "je .Lf15c758_0015c99b\n"
        "movl imp_cl, %eax\n" /* line 1609 */
        "movl (%eax), %eax\n"
        "movl 0x26f0(%eax), %eax\n"
        "movl 0xa0(%ecx), %esi\n"
        "movl %esi, -0x6c(%ebp)\n"
        "cmpl %esi, %eax\n"
        "jns .Lf15c758_0015c991\n"
        "movl %eax, %esi\n" /* line 1615 */
        "subl %edx, %esi\n"
        "movl %esi, %edx\n"
        "movl 0x14(%edi), %esi\n" /* line 1617 */
        "movl %esi, -0x1c(%ebp)\n"
        "cmpl %esi, %edx\n"
        "jge .Lf15c758_0015cb8e\n"
        "cvtsi2ssl %edx, %xmm2\n" /* line 1618 */
        "mulss -0x54(%ebp), %xmm2\n"
        "cvtsi2ssl %esi, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        ".Lf15c758_0015ca01:\n"
        "movl 8(%ebp), %esi\n" /* line 1624 | charHeight */
        "subl %esi, -0x50(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 1627 | centered */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x4e, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* vertAlign */
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* horzAlign */
        "movl %ecx, (%esp)\n"
        "movss -0x58(%ebp), %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "movl %esi, %ecx\n"
        "movl -0x50(%ebp), %edx\n"
        "movl -0x4c(%ebp), %eax\n"
        "calll Con_DrawStringOnHUD\n"
        "jmp .Lf15c758_0015c99b\n"
        /* } scope */
        /* } scope */
        ".Lf15c758_0015ca41:\n"
        "movl %eax, %edx\n" /* line 1703 */
        "subl %ecx, %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl 0x14(%edi), %edx\n" /* msgwnd */
        "movl %edx, -0x3c(%ebp)\n"
        "cmpl %edx, -0x40(%ebp)\n"
        "jge .Lf15c758_0015cb18\n"
        "cvtsi2ssl -0x40(%ebp), %xmm2\n" /* line 1706 */
        "cvtsi2ssl %edx, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "mulss -0x54(%ebp), %xmm2\n"
        ".Lf15c758_0015ca69:\n"
        "movl -0x28(%ebp), %edx\n" /* line 1717 | reversed */
        "testl %edx, %edx\n"
        "je .Lf15c758_0015cb38\n"
        "movl -0x30(%ebp), %eax\n" /* line 1720 | groupsize */
        "testl %eax, %eax\n"
        "jne .Lf15c758_0015cb32\n"
        "addl $1, %ebx\n" /* line 1723 | i */
        "cmpl %ebx, -0x48(%ebp)\n" /* i */
        "jg .Lf15c758_0015cbd2\n"
        ".Lf15c758_0015ca8b:\n"
        "movl $0, -0x30(%ebp)\n" /* line 1746 | groupsize */
        ".Lf15c758_0015ca92:\n"
        "movl $0, 0x10(%esp)\n" /* line 1751 */
        "movl $0x4e, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* line */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* vertAlign */
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* horzAlign */
        "movl %ecx, (%esp)\n"
        "movss -0x58(%ebp), %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "movl 8(%ebp), %ecx\n" /* charHeight */
        "movl -0x34(%ebp), %edx\n" /* v */
        "movl -0x4c(%ebp), %eax\n"
        "calll Con_DrawStringOnHUD\n"
        "movl -0x28(%ebp), %eax\n" /* line 1753 | reversed */
        "testl %eax, %eax\n"
        "je .Lf15c758_0015cb40\n"
        "movl -0x30(%ebp), %eax\n" /* line 1756 | groupsize */
        "testl %eax, %eax\n"
        "je .Lf15c758_0015cae8\n"
        "subl $1, -0x30(%ebp)\n" /* line 1759 | groupsize */
        "movl -0x2c(%ebp), %esi\n" /* iOverStepStartHeight */
        "cmovnel -0x34(%ebp), %esi\n" /* v */
        "movl %esi, -0x34(%ebp)\n" /* v */
        ".Lf15c758_0015cae8:\n"
        "movl 8(%ebp), %eax\n" /* line 1762 | charHeight */
        "subl %eax, -0x34(%ebp)\n" /* v */
        "movl 4(%edi), %edx\n" /* msgwnd */
        "movl %edx, -0x68(%ebp)\n"
        "movl 8(%edi), %esi\n" /* msgwnd */
        "movl %edx, %eax\n"
        "jmp .Lf15c758_0015c7f8\n"
        ".Lf15c758_0015cafe:\n"
        "testl %edx, %edx\n" /* line 1649 */
        "jne .Lf15c758_0015c7a1\n"
        "movl -0x50(%ebp), %esi\n"
        "movl %esi, -0x34(%ebp)\n" /* v */
        "movl $0, -0x28(%ebp)\n" /* reversed */
        "jmp .Lf15c758_0015c7c7\n"
        ".Lf15c758_0015cb18:\n"
        "movl -0x70(%ebp), %edx\n" /* line 1708 */
        "subl %eax, %edx\n"
        "movl 0x18(%edi), %eax\n" /* msgwnd */
        "cmpl %eax, %edx\n"
        "jl .Lf15c758_0015cbb2\n"
        "movss -0x54(%ebp), %xmm2\n"
        "jmp .Lf15c758_0015ca69\n"
        ".Lf15c758_0015cb32:\n"
        "movl -0x38(%ebp), %esi\n" /* line 1746 */
        "addl %esi, -0x34(%ebp)\n" /* v */
        ".Lf15c758_0015cb38:\n"
        "addl $1, %ebx\n" /* i */
        "jmp .Lf15c758_0015ca92\n"
        ".Lf15c758_0015cb40:\n"
        "movl 8(%ebp), %ecx\n" /* line 1765 | charHeight */
        "addl %ecx, -0x34(%ebp)\n" /* v */
        "movl 4(%edi), %esi\n" /* msgwnd */
        "movl %esi, -0x68(%ebp)\n"
        "movl 8(%edi), %esi\n" /* msgwnd */
        "movl -0x68(%ebp), %eax\n"
        "jmp .Lf15c758_0015c7f8\n"
        ".Lf15c758_0015cb57:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "cvtsi2ssl %ecx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "cvtsi2ssl 8(%ebp), %xmm1\n" /* charHeight */
        "mulss %xmm1, %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x64(%ebp)\n"
        "cvttss2si -0x64(%ebp), %eax\n"
        "addl %eax, -0x34(%ebp)\n" /* v */
        "jmp .Lf15c758_0015c7f2\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf15c758_0015cb8e:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 1619 */
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "movl 0x18(%edi), %edx\n"
        "cmpl %edx, %eax\n"
        "jge .Lf15c758_0015cbc8\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 1620 */
        "mulss -0x54(%ebp), %xmm2\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "jmp .Lf15c758_0015ca01\n"
        /* } scope */
        /* } scope */
        ".Lf15c758_0015cbb2:\n"
        "cvtsi2ssl %edx, %xmm2\n" /* line 1711 */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "mulss -0x54(%ebp), %xmm2\n"
        "jmp .Lf15c758_0015ca69\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf15c758_0015cbc8:\n"
        "movss -0x54(%ebp), %xmm2\n" /* line 1619 */
        "jmp .Lf15c758_0015ca01\n"
        /* } scope */
        /* } scope */
        ".Lf15c758_0015cbd2:\n"
        "movl %ebx, %eax\n" /* line 1730 | i */
        "cltd\n"
        "idivl %esi\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl -0x44(%ebp), %edx\n"
        "cmpl 0x9c(%edx, %eax, 4), %ecx\n"
        "jne .Lf15c758_0015ca8b\n"
        ".Lf15c758_0015cbed:\n"
        "addl $1, -0x30(%ebp)\n" /* line 1733 | groupsize */
        "movl -0x30(%ebp), %edx\n" /* groupsize */
        "addl %ebx, %edx\n" /* i */
        "movl -0x48(%ebp), %eax\n" /* line 1723 */
        "subl %ebx, %eax\n" /* i */
        "cmpl %eax, -0x30(%ebp)\n" /* groupsize */
        "je .Lf15c758_0015cc17\n"
        "movl %edx, %eax\n" /* line 1730 */
        "cltd\n"
        "idivl %esi\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl -0x44(%ebp), %edx\n"
        "cmpl 0x9c(%edx, %eax, 4), %ecx\n"
        "je .Lf15c758_0015cbed\n"
        ".Lf15c758_0015cc17:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1736 | groupsize */
        "testl %eax, %eax\n"
        "je .Lf15c758_0015ca92\n"
        "movl 8(%ebp), %eax\n" /* line 1738 | charHeight */
        "imull -0x30(%ebp), %eax\n" /* groupsize */
        "subl %eax, -0x34(%ebp)\n" /* v */
        "addl $1, -0x30(%ebp)\n" /* line 1740 | groupsize */
        "movl -0x34(%ebp), %ecx\n" /* v */
        "movl %ecx, -0x2c(%ebp)\n" /* iOverStepStartHeight */
        "jmp .Lf15c758_0015ca92\n"
    );
}

/* line 1855 */
__attribute__((naked))
void Con_DrawSubtitles(int xPos, int yPos, int charHeight, float alpha, msgwnd_mode_t mode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1855 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* xPos */
        "movl 0xc(%ebp), %ecx\n" /* yPos */
        "movl 0x10(%ebp), %esi\n" /* charHeight */
        "movss 0x14(%ebp), %xmm0\n" /* alpha */
        "movl con+131120, %eax\n" /* line 1869 */
        "addl $0xa78, %eax\n"
        "movl 0x18(%ebp), %ebx\n" /* mode */
        "movl %ebx, 0x14(%ebp)\n" /* mode, alpha */
        "movl $1, 0x10(%ebp)\n" /* charHeight */
        "movl $1, 0xc(%ebp)\n" /* yPos */
        "movl %esi, 8(%ebp)\n" /* charHeight, xPos */
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "popl %ebx\n" /* line 1870 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Con_DrawMessageWindow\n" /* line 1869 */
    );
}

/* line 1834 */
__attribute__((naked))
void Con_DrawMiniConsole(int xPos, int yPos, float alpha)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1834 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* xPos */
        "movl 0xc(%ebp), %ecx\n" /* yPos */
        "movl con_miniconlines, %eax\n" /* line 1850 */
        "movl 8(%eax), %ebx\n"
        "movl con+131120, %eax\n"
        "movl %ebx, 0xfbc(%eax)\n"
        "movl con+131120, %eax\n" /* line 1851 */
        "addl $0xfb4, %eax\n"
        "movl $0, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0xc, (%esp)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss 0x10(%ebp), %xmm0\n" /* alpha */
        "calll Con_DrawMessageWindow\n"
        "addl $0x14, %esp\n" /* line 1852 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1816 */
__attribute__((naked))
void Con_DrawBoldMessages(int xPos, int yPos, float alpha, msgwnd_mode_t mode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1816 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* xPos */
        "movl 0xc(%ebp), %ecx\n" /* yPos */
        "movss 0x10(%ebp), %xmm0\n" /* alpha */
        "movl con+131120, %eax\n" /* line 1830 */
        "addl $0x53c, %eax\n"
        "movl $7, 0x10(%ebp)\n" /* alpha */
        "movl $7, 0xc(%ebp)\n" /* yPos */
        "movl $0xc, 8(%ebp)\n" /* xPos */
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "popl %ebp\n" /* line 1831 */
        "jmp Con_DrawMessageWindow\n" /* line 1830 */
    );
}

/* line 1798 */
__attribute__((naked))
void Con_DrawNotify(int xPos, int yPos, float alpha, msgwnd_mode_t mode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1798 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* xPos */
        "movl 0xc(%ebp), %ecx\n" /* yPos */
        "movss 0x10(%ebp), %xmm0\n" /* alpha */
        "movl $3, 0x10(%ebp)\n" /* line 1812 | alpha */
        "movl $1, 0xc(%ebp)\n" /* yPos */
        "movl $0xc, 8(%ebp)\n" /* xPos */
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movl con+131120, %eax\n"
        "popl %ebp\n" /* line 1813 */
        "jmp Con_DrawMessageWindow\n" /* line 1812 */
    );
}

/* line 1253 */
static __attribute__((naked))
void ConDrawInput_IncrMatchCounter(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1253 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* str */
        "movl conDrawInputGlob+8, %eax\n" /* line 1249 */
        "movl %eax, 8(%esp)\n"
        "movl conDrawInputGlob+4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n" /* line 1255 */
        "jne .Lf15cd54_0015cda2\n"
        "addl $1, conDrawInputGlob\n" /* line 1257 */
        "movl $1, %eax\n" /* line 1259 */
        "movl conDrawInputGlob+8, %edx\n"
        "cmpb $0, (%ebx, %edx)\n" /* str */
        "movzbl conDrawInputGlob+12, %edx\n"
        "cmovnel %edx, %eax\n"
        "movb %al, conDrawInputGlob+12\n"
        ".Lf15cd54_0015cda2:\n"
        "addl $0x14, %esp\n" /* line 1261 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 428 */
__attribute__((naked))
void Con_ClearNotify(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 428 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl con+131120, %ebx\n" /* line 430 | msgwnd */
        /* { scope 1 */
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl (%ebx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        /* } scope */
        "movl con+131120, %ecx\n" /* line 431 */
        "leal 0x53c(%ecx), %ebx\n" /* msgwnd */
        /* { scope 1 */
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl 0x53c(%ecx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 432 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 441 */
__attribute__((naked))
void Con_ClearSubtitles(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 441 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl con+131120, %ecx\n" /* line 443 */
        "leal 0xa78(%ecx), %ebx\n" /* msgwnd */
        /* { scope 1 */
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl 0xa78(%ecx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 444 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1264 */
static __attribute__((naked))
void ConDrawInput_DvarMatch(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1264 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* str */
        "movl conDrawInputGlob+8, %eax\n" /* line 1249 */
        "movl %eax, 8(%esp)\n"
        "movl conDrawInputGlob+4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n" /* line 1268 */
        "jne .Lf15ce64_0015cf8e\n"
        "movl $0, 0x20(%esp)\n" /* line 1186 */
        "movl $con_inputDvarMatchColor, 0x1c(%esp)\n"
        "movl $0x3f800000, %ebx\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_cls, %esi\n"
        "movl 0x2a0a60(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x11c(%eax)\n"
        "movss lit4_002ed734, %xmm0\n" /* line 1199 | 200.0f */
        "addss conDrawInputGlob+16, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+16\n"
        "movl %edi, (%esp)\n" /* line 1273 | str */
        "calll Dvar_GetVariantString\n"
        /* { scope 1 */
        "movl $0, 0x20(%esp)\n" /* line 1186 */
        "movl $con_inputDvarValueColor, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0x2a0a60(%esi), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x28, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x11c(%eax)\n"
        /* } scope */
        "movss conDrawInputGlob+20, %xmm0\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        ".Lf15ce64_0015cf8e:\n"
        "addl $0x3c, %esp\n" /* line 1275 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1129 */
__attribute__((naked))
const char * Con_TokenizeInput(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1129 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl imp_g_consoleField, %eax\n" /* line 1133 */
        "addl $0x18, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Cmd_TokenizeString\n"
        "movl $0, (%esp)\n" /* line 1135 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* cmd */
        "movzbl (%eax), %eax\n" /* line 1136 */
        "cmpb $0x5c, %al\n"
        "je .Lf15cf96_0015cfe4\n"
        "cmpb $0x2f, %al\n"
        "je .Lf15cf96_0015cfe4\n"
        "movsbl (%ebx), %edx\n" /* line 1138 | cmd, _c */
        /* { scope 2 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "jne .Lf15cf96_0015cff2\n"
        ".Lf15cf96_0015cfd1:\n"
        "movl __DefaultRuneLocale, %eax\n"
        "movl 0x34(%eax, %edx, 4), %eax\n"
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1138 */
        "je .Lf15cf96_0015d00e\n"
        ".Lf15cf96_0015cfe4:\n"
        "addl $1, %ebx\n" /* line 1139 | cmd */
        "movsbl (%ebx), %edx\n" /* line 1138 | cmd, _c */
        /* { scope 2 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf15cf96_0015cfd1\n"
        ".Lf15cf96_0015cff2:\n"
        "movl $0x4000, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1138 */
        "jne .Lf15cf96_0015cfe4\n"
        /* } scope */
        ".Lf15cf96_0015d00e:\n"
        "movl %ebx, %eax\n" /* line 1142 | cmd */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1145 */
__attribute__((naked))
Bool Con_AnySpaceAfterCommand(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1145 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl imp_g_consoleField, %ebx\n"
        "movl __DefaultRuneLocale, %esi\n"
        "jmp .Lf15d016_0015d03d\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf15d016_0015d02c:\n"
        "movl 0x34(%esi, %eax, 4), %eax\n" /* line 220 */
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1150 | _c */
        "je .Lf15d016_0015d064\n"
        ".Lf15d016_0015d03a:\n"
        "addl $1, %ebx\n"
        ".Lf15d016_0015d03d:\n"
        "movsbl 0x18(%ebx), %eax\n" /* _c */
        /* { scope 2 */
        "testl $0xffffff80, %eax\n" /* line 220 */
        "je .Lf15d016_0015d02c\n"
        "movl $0x4000, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1150 | _c */
        "jne .Lf15d016_0015d03a\n"
        ".Lf15d016_0015d064:\n"
        "movl imp_g_consoleField, %edx\n" /* line 1153 */
        "movl %ebx, %ecx\n"
        "subl %edx, %ecx\n"
        "movzbl 0x18(%ecx, %edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf15d016_0015d0ce\n"
        "leal 0x18(%ecx, %edx), %ebx\n"
        "jmp .Lf15d016_0015d09b\n"
        /* { scope 2 */
        ".Lf15d016_0015d07d:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "movl 0x34(%eax, %edx, 4), %eax\n"
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1155 */
        "jne .Lf15d016_0015d0c2\n"
        ".Lf15d016_0015d090:\n"
        "movzbl 1(%ebx), %eax\n" /* line 1153 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "je .Lf15d016_0015d0ce\n"
        ".Lf15d016_0015d09b:\n"
        "movsbl %al, %edx\n" /* line 1155 | _c */
        /* { scope 2 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf15d016_0015d07d\n"
        "movl $0x4000, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1155 */
        "je .Lf15d016_0015d090\n"
        ".Lf15d016_0015d0c2:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15d016_0015d0ce:\n"
        "xorl %eax, %eax\n" /* line 1153 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 447 */
static __attribute__((naked))
void Con_CheckResize(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 447 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl $0x20000, 4(%esp)\n" /* line 455 */
        "leal -0x1c(%ebp), %eax\n" /* tbuf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %eax\n" /* tbuf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x30(%ebp)\n" /* tbuf */
        "movl $0x40800000, %eax\n" /* line 30 */
        "movl %eax, con+131104\n"
        "movl %eax, con+131108\n" /* line 31 */
        "movl $0xc0800000, %eax\n" /* line 30 */
        "movl %eax, con+131112\n"
        "movl %eax, con+131116\n" /* line 31 */
        "movl $1, 4(%esp)\n" /* line 461 */
        "movl $con+131104, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $1, 4(%esp)\n" /* line 462 */
        "movl $con+131108, (%esp)\n"
        "calll CalcScreenY\n"
        "movl $3, 4(%esp)\n" /* line 464 */
        "movl $con+131112, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $3, 4(%esp)\n" /* line 465 */
        "movl $con+131116, (%esp)\n"
        "calll CalcScreenY\n"
        "movl con+131104, %eax\n" /* line 467 */
        "movl %eax, (%esp)\n"
        "calll floorf\n"
        "fstps con+131104\n"
        "movl con+131108, %eax\n" /* line 468 */
        "movl %eax, (%esp)\n"
        "calll floorf\n"
        "fstps con+131108\n"
        "movl con+131112, %eax\n" /* line 469 */
        "movl %eax, (%esp)\n"
        "calll floorf\n"
        "fstps -0x44(%ebp)\n"
        "movss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, con+131112\n"
        "movl con+131116, %eax\n" /* line 470 */
        "movl %eax, (%esp)\n"
        "calll floorf\n"
        "fstps con+131116\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 472 */
        "subss con+131104, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "cmpl $0x27f, %eax\n" /* line 473 */
        "jg .Lf15d0d8_0015d3e5\n"
        "movl $0x50, %eax\n"
        ".Lf15d0d8_0015d1e7:\n"
        "leal -2(%eax), %ecx\n" /* line 476 */
        "movl con+131092, %eax\n" /* line 478 */
        "movl %eax, -0x2c(%ebp)\n"
        "cmpl %eax, %ecx\n"
        "je .Lf15d0d8_0015d3d2\n"
        "testl %ecx, %ecx\n" /* line 481 */
        "jle .Lf15d0d8_0015d3ed\n"
        "movl %ecx, con+131092\n" /* line 492 */
        "movl con+131096, %eax\n" /* line 493 */
        "movl %eax, -0x3c(%ebp)\n" /* oldtotallines */
        "movl $0x10000, %edx\n" /* line 494 */
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl %ecx\n"
        "movl %eax, -0x38(%ebp)\n" /* numlines */
        "movl %eax, con+131096\n"
        "cmpl %eax, -0x3c(%ebp)\n" /* line 497 | oldtotallines */
        "movl -0x3c(%ebp), %eax\n" /* oldtotallines */
        "cmovgl -0x38(%ebp), %eax\n" /* numlines */
        "movl %eax, -0x38(%ebp)\n" /* numlines */
        "cmpl %ecx, -0x2c(%ebp)\n" /* line 502 */
        "movl -0x2c(%ebp), %eax\n"
        "cmovgl %ecx, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* numchars */
        "movl $0x20000, 8(%esp)\n" /* line 507 */
        "movl $con+4, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* tbuf */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $con, %ebx\n"
        "movl $con+131072, %esi\n" /* j */
        ".Lf15d0d8_0015d260:\n"
        "movl $0x37, (%esp)\n" /* line 511 */
        "calll ColorIndex\n"
        "shll $8, %eax\n"
        "orl $0x20, %eax\n"
        "movw %ax, 4(%ebx)\n"
        "addl $2, %ebx\n"
        "cmpl %ebx, %esi\n" /* line 510 | j */
        "jne .Lf15d0d8_0015d260\n"
        "movl -0x38(%ebp), %ebx\n" /* line 514 | numlines */
        "testl %ebx, %ebx\n"
        "jle .Lf15d0d8_0015d2e6\n"
        "movl $0, -0x40(%ebp)\n" /* i */
        ".Lf15d0d8_0015d28b:\n"
        "movl -0x34(%ebp), %esi\n" /* line 516 | numchars, j */
        "testl %esi, %esi\n" /* j */
        "jle .Lf15d0d8_0015d2da\n"
        "xorl %esi, %esi\n" /* line 510 | j */
        "movl con+131076, %eax\n"
        "movl -0x40(%ebp), %ebx\n" /* i */
        "notl %ebx\n"
        "addl con+131096, %ebx\n"
        "imull con+131092, %ebx\n"
        "subl -0x40(%ebp), %eax\n" /* i */
        "movl -0x3c(%ebp), %edi\n" /* oldtotallines */
        "addl %eax, %edi\n"
        ".Lf15d0d8_0015d2b3:\n"
        "leal (%esi, %ebx), %ecx\n" /* line 524 | j */
        "movl %edi, %eax\n"
        "cltd\n"
        "idivl -0x3c(%ebp)\n" /* oldtotallines */
        "imull -0x2c(%ebp), %edx\n"
        "leal (%esi, %edx), %edx\n" /* j */
        "movl -0x30(%ebp), %eax\n" /* tbuf */
        "movzwl (%eax, %edx, 2), %edx\n"
        "movw %dx, con+4(%ecx, %ecx)\n"
        "addl $1, %esi\n" /* line 516 | j */
        "cmpl %esi, -0x34(%ebp)\n" /* j, numchars */
        "jne .Lf15d0d8_0015d2b3\n"
        ".Lf15d0d8_0015d2da:\n"
        "addl $1, -0x40(%ebp)\n" /* line 514 | i */
        "movl -0x40(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x38(%ebp)\n" /* numlines */
        "jne .Lf15d0d8_0015d28b\n"
        ".Lf15d0d8_0015d2e6:\n"
        "movl con+131120, %ebx\n" /* line 430 */
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl (%ebx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        "movl con+131120, %ecx\n" /* line 431 */
        "leal 0x53c(%ecx), %ebx\n"
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl 0x53c(%ecx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        "movl con+131120, %ecx\n" /* line 437 */
        "leal 0xfb4(%ecx), %ebx\n"
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl 0xfb4(%ecx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        "movl con+131120, %ecx\n" /* line 443 */
        "leal 0xa78(%ecx), %ebx\n"
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl 0xa78(%ecx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        ".Lf15d0d8_0015d3c0:\n"
        "movl con+131096, %eax\n" /* line 534 */
        "subl $1, %eax\n"
        "movl %eax, con+131076\n"
        "movl %eax, con+131084\n" /* line 535 */
        ".Lf15d0d8_0015d3d2:\n"
        "leal -0x1c(%ebp), %eax\n" /* tbuf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 536 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15d0d8_0015d3e5:\n"
        "sarl $3, %eax\n" /* line 473 */
        "jmp .Lf15d0d8_0015d1e7\n"
        ".Lf15d0d8_0015d3ed:\n"
        "movl $0x4e, con+131092\n" /* line 484 */
        "movl $0x348, con+131096\n" /* line 485 */
        "movl $con, %ebx\n"
        ".Lf15d0d8_0015d406:\n"
        "movl $0x37, (%esp)\n" /* line 487 */
        "calll ColorIndex\n"
        "shll $8, %eax\n"
        "orl $0x20, %eax\n"
        "movw %ax, 4(%ebx)\n"
        "addl $2, %ebx\n"
        "cmpl $con+131072, %ebx\n" /* line 486 */
        "jne .Lf15d0d8_0015d406\n"
        "jmp .Lf15d0d8_0015d3c0\n"
        "movl %eax, %ebx\n"
        "leal -0x1c(%ebp), %eax\n" /* line 535 | tbuf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 731 */
static __attribute__((naked))
void Con_OneTimeInit(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 731 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $0x1001, 0x1c(%esp)\n" /* line 736 */
        "movl $0x3f800000, %ebx\n"
        "movl %ebx, 0x18(%esp)\n"
        "xorl %esi, %esi\n"
        "movl %esi, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl $0x3e4ccccd, 0xc(%esp)\n"
        "movl $0x3e800000, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab768, (%esp)\n" /* "con_inputBoxColor" */
        "calll Dvar_RegisterVec4\n"
        "movl %eax, con_inputBoxColor\n"
        "movl $0x1001, 0x1c(%esp)\n" /* line 737 */
        "movl %ebx, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl $0x3eb33333, 0xc(%esp)\n"
        "movl $0x3ecccccd, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab77c, (%esp)\n" /* "con_inputHintBoxColor" */
        "calll Dvar_RegisterVec4\n"
        "movl %eax, con_inputHintBoxColor\n"
        "movl $0x1001, 0x1c(%esp)\n" /* line 738 */
        "movl %ebx, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "movl $0x3f19999a, %edi\n"
        "movl %edi, 0x10(%esp)\n"
        "movl $0x3f733333, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002ab794, (%esp)\n" /* "con_outputBarColor" */
        "calll Dvar_RegisterVec4\n"
        "movl %eax, con_outputBarColor\n"
        "movl $0x1001, 0x1c(%esp)\n" /* line 739 */
        "movl %ebx, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n"
        "movl $0x3dcccccd, 0xc(%esp)\n"
        "movl $0x3e19999a, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ab7a8, (%esp)\n" /* "con_outputSliderColor" */
        "calll Dvar_RegisterVec4\n"
        "movl %eax, con_outputSliderColor\n"
        "movl $0x1001, 0x1c(%esp)\n" /* line 740 */
        "movl %ebx, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "movl $0x3f400000, 0x10(%esp)\n"
        "movl $0x3e99999a, 0xc(%esp)\n"
        "movl $0x3eb33333, 8(%esp)\n"
        "movl $0x3eb33333, 4(%esp)\n"
        "movl $str_002ab7c0, (%esp)\n" /* "con_outputWindowColor" */
        "calll Dvar_RegisterVec4\n"
        "movl %eax, con_outputWindowColor\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 742 */
        "movl $0x7f7fffff, %ebx\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $str_002ab7d8, (%esp)\n" /* "con_gamemessagetime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, con_gamemessagetime\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 743 */
        "movl %ebx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x41000000, 4(%esp)\n"
        "movl $str_002ab7ec, (%esp)\n" /* "con_boldgamemessagetime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, con_boldgamemessagetime\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 744 */
        "movl %ebx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x40800000, 4(%esp)\n"
        "movl $str_002ab804, (%esp)\n" /* "con_minicontime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, con_minicontime\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 745 */
        "movl $0x64, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $5, 4(%esp)\n"
        "movl $str_002ab814, (%esp)\n" /* "con_miniconlines" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, con_miniconlines\n"
        "movl $con+131152, con+131124\n" /* line 545 */
        "movl $0, con+131128\n" /* line 546 */
        "movl $8, con+131132\n" /* line 547 */
        "movl $3, con+131136\n" /* line 548 */
        "movl $0xfa, con+131140\n" /* line 549 */
        "movl $0xfa, con+131144\n" /* line 550 */
        "movl $0x1f4, con+131148\n" /* line 551 */
        "movl $con+132492, con+132464\n" /* line 545 */
        "movl $0, con+132468\n" /* line 546 */
        "movl $8, con+132472\n" /* line 547 */
        "movl $3, con+132476\n" /* line 548 */
        "movl $0xfa, con+132480\n" /* line 549 */
        "movl $0xfa, con+132484\n" /* line 550 */
        "movl $0x1f4, con+132488\n" /* line 551 */
        "movl $con+133832, con+133804\n" /* line 545 */
        "movl $0, con+133808\n" /* line 546 */
        "movl $8, con+133812\n" /* line 547 */
        "movl $3, con+133816\n" /* line 548 */
        "movl $0xfa, con+133820\n" /* line 549 */
        "movl $0xfa, con+133824\n" /* line 550 */
        "movl $0x1f4, con+133828\n" /* line 551 */
        "movl 8(%eax), %eax\n" /* line 724 */
        "movl $con+135172, con+135144\n" /* line 545 */
        "movl $0, con+135148\n" /* line 546 */
        "movl %eax, con+135152\n" /* line 547 */
        "movl $0, con+135156\n" /* line 548 */
        "movl $0, con+135160\n" /* line 549 */
        "movl $0, con+135164\n" /* line 550 */
        "movl $0, con+135168\n" /* line 551 */
        "movl $con+131124, con+131120\n" /* line 727 */
        "movl imp_colorWhite, %edx\n" /* line 456 */
        "movl (%edx), %eax\n"
        "movl %eax, con+151572\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, con+151576\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, con+151580\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, con+151584\n"
        "movl $0xffffffff, con+131092\n" /* line 757 */
        "calll Con_CheckResize\n" /* line 758 */
        "movl $1, con\n" /* line 759 */
        "addl $0x2c, %esp\n" /* line 760 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2038 */
__attribute__((naked))
void Con_Close(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2038 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_legacyHacks, %eax\n" /* line 2042 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf15d78e_0015d897\n"
        "movl imp_g_consoleField, %eax\n" /* line 2045 */
        "movl %eax, (%esp)\n"
        "calll Field_Clear\n"
        "movl con+131120, %ebx\n" /* line 430 */
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl (%ebx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        "movl con+131120, %ecx\n" /* line 431 */
        "leal 0x53c(%ecx), %ebx\n"
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl 0x53c(%ecx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        "movl con+131120, %ecx\n" /* line 437 */
        "leal 0xfb4(%ecx), %ebx\n"
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl 0xfb4(%ecx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        "movl con+131120, %ecx\n" /* line 443 */
        "leal 0xa78(%ecx), %ebx\n"
        "movl 8(%ebx), %eax\n" /* line 423 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl 0xa78(%ecx), %eax\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 4(%ebx)\n" /* line 424 */
        "movl imp_clients, %eax\n" /* line 2051 */
        "andl $0xfffffffe, 4(%eax)\n"
        ".Lf15d78e_0015d897:\n"
        "addl $0x14, %esp\n" /* line 2057 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1300 */
static __attribute__((naked))
void ConDrawInput_AutoCompleteArg(int stringCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1300 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4ec, %esp\n"
        "movl %eax, %ebx\n" /* stringList */
        "movl %edx, -0x47c(%ebp)\n"
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 1317 */
        "calll Cmd_Argv\n"
        "movl %eax, -0x464(%ebp)\n" /* prefix */
        "cld\n" /* line 1318 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x464(%ebp), %edi\n" /* prefix */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x460(%ebp)\n" /* prefixLen */
        "movl -0x47c(%ebp), %eax\n" /* line 1324 */
        "testl %eax, %eax\n"
        "jg .Lf15d89e_0015d8f4\n"
        /* } scope */
        ".Lf15d89e_0015d8e9:\n"
        "addl $0x4ec, %esp\n" /* line 1360 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15d89e_0015d8f4:\n"
        "movl $0, -0x46c(%ebp)\n" /* line 1324 | matchBufferUsed */
        "xorl %esi, %esi\n" /* stringIndex */
        "movl $0, -0x468(%ebp)\n" /* matchCount */
        "movl $0, -0x45c(%ebp)\n" /* matchLenMax */
        ".Lf15d89e_0015d914:\n"
        "movl -0x460(%ebp), %eax\n" /* line 1326 | prefixLen */
        "movl %eax, 8(%esp)\n"
        "movl (%ebx), %eax\n" /* matchIndex */
        "movl %eax, 4(%esp)\n"
        "movl -0x464(%ebp), %edx\n" /* prefix */
        "movl %edx, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf15d89e_0015d9de\n"
        "cmpl $0x10, -0x468(%ebp)\n" /* line 1328 | matchCount */
        "je .Lf15d89e_0015d8e9\n"
        "movl (%ebx), %edx\n" /* line 1330 | matchIndex */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0x46c(%ebp), %edi\n" /* matchBufferUsed */
        "leal -1(%ecx, %edi), %ecx\n"
        "cmpl $0x3ff, %ecx\n"
        "ja .Lf15d89e_0015d8e9\n"
        "leal -0x458(%ebp, %edi), %eax\n" /* line 1332 */
        "movl -0x468(%ebp), %ecx\n" /* matchCount */
        "movl %eax, -0x58(%ebp, %ecx, 4)\n"
        "movl %eax, 4(%esp)\n" /* line 1333 */
        "movl %edx, (%esp)\n"
        "calll Com_StripExtension\n"
        "movl -0x468(%ebp), %edi\n" /* line 1334 | matchCount */
        "movl -0x58(%ebp, %edi, 4), %edx\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl %ecx, -0x46c(%ebp)\n" /* matchBufferUsed */
        "movl imp_cls, %eax\n" /* line 1172 */
        "movl 0x2a0a60(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl imp_re, %edx\n"
        "calll *0x114(%edx)\n"
        "cmpl %eax, -0x45c(%ebp)\n" /* line 1336 | matchLenMax */
        "cmovgel -0x45c(%ebp), %eax\n" /* matchLenMax */
        "movl %eax, -0x45c(%ebp)\n" /* matchLenMax */
        "addl $1, -0x468(%ebp)\n" /* line 1338 | matchCount */
        ".Lf15d89e_0015d9de:\n"
        "addl $1, %esi\n" /* line 1324 | stringIndex */
        "addl $4, %ebx\n" /* matchIndex */
        "cmpl %esi, -0x47c(%ebp)\n" /* stringIndex */
        "jne .Lf15d89e_0015d914\n"
        "movl -0x468(%ebp), %eax\n" /* line 1341 | matchCount */
        "testl %eax, %eax\n"
        "je .Lf15d89e_0015d8e9\n"
        "movl $ConDrawInput_CompareStrings, 0xc(%esp)\n" /* line 1343 */
        "movl $4, 8(%esp)\n"
        "movl -0x468(%ebp), %ecx\n" /* matchCount */
        "movl %ecx, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* matches */
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movss conDrawInputGlob+24, %xmm0\n" /* line 1345 */
        "movss %xmm0, -0x478(%ebp)\n"
        "movl imp_re, %eax\n"
        "movl 0x114(%eax), %eax\n"
        "movl %eax, -0x474(%ebp)\n"
        "movl imp_cls, %eax\n"
        "movl 0x2a0a60(%eax), %eax\n"
        "movl %eax, -0x470(%ebp)\n"
        "movl imp_g_consoleField, %ebx\n" /* matchIndex */
        "movl __DefaultRuneLocale, %esi\n" /* stringIndex */
        "jmp .Lf15d89e_0015da74\n"
        ".Lf15d89e_0015da63:\n"
        "movl 0x34(%esi, %eax, 4), %eax\n" /* line 220 */
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        "testl %eax, %eax\n" /* line 1289 */
        "je .Lf15d89e_0015da9b\n"
        ".Lf15d89e_0015da71:\n"
        "addl $1, %ebx\n"
        ".Lf15d89e_0015da74:\n"
        "movsbl 0x18(%ebx), %eax\n"
        "testl $0xffffff80, %eax\n" /* line 220 */
        "je .Lf15d89e_0015da63\n"
        "movl $0x4000, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "testl %eax, %eax\n" /* line 1289 */
        "jne .Lf15d89e_0015da71\n"
        ".Lf15d89e_0015da9b:\n"
        "movl imp_g_consoleField, %eax\n"
        "subl %eax, %ebx\n"
        "leal 0x10(%ebx), %edx\n"
        "movl %edx, -0x484(%ebp)\n"
        "leal 8(%edx, %eax), %edi\n"
        "movl __DefaultRuneLocale, %esi\n"
        "jmp .Lf15d89e_0015dac8\n"
        ".Lf15d89e_0015dab7:\n"
        "movl 0x34(%esi, %eax, 4), %eax\n" /* line 220 */
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        "testl %eax, %eax\n" /* line 1291 */
        "jne .Lf15d89e_0015daee\n"
        ".Lf15d89e_0015dac5:\n"
        "addl $1, %edi\n" /* line 1289 */
        ".Lf15d89e_0015dac8:\n"
        "movsbl (%edi), %eax\n" /* line 1291 */
        "testl $0xffffff80, %eax\n" /* line 220 */
        "je .Lf15d89e_0015dab7\n"
        "movl $0x4000, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "testl %eax, %eax\n" /* line 1291 */
        "je .Lf15d89e_0015dac5\n"
        ".Lf15d89e_0015daee:\n"
        "movl imp_g_consoleField, %edx\n"
        "movl -0x484(%ebp), %ecx\n"
        "leal 8(%ecx, %edx), %eax\n"
        "subl %eax, %ebx\n"
        "addl %edi, %ebx\n"
        "leal 0x10(%ebx), %edi\n"
        "movl %edi, -0x480(%ebp)\n"
        "leal 8(%edi, %edx), %edi\n"
        "movl __DefaultRuneLocale, %esi\n"
        "jmp .Lf15d89e_0015db28\n"
        ".Lf15d89e_0015db17:\n"
        "movl 0x34(%esi, %eax, 4), %eax\n" /* line 220 */
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        "testl %eax, %eax\n" /* line 1293 */
        "je .Lf15d89e_0015db4e\n"
        ".Lf15d89e_0015db25:\n"
        "addl $1, %edi\n" /* line 1291 */
        ".Lf15d89e_0015db28:\n"
        "movsbl (%edi), %eax\n" /* line 1293 */
        "testl $0xffffff80, %eax\n" /* line 220 */
        "je .Lf15d89e_0015db17\n"
        "movl $0x4000, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "testl %eax, %eax\n" /* line 1293 */
        "jne .Lf15d89e_0015db25\n"
        ".Lf15d89e_0015db4e:\n"
        "movl -0x470(%ebp), %edx\n" /* line 1345 */
        "movl %edx, 8(%esp)\n"
        "movl imp_g_consoleField, %edx\n"
        "movl -0x480(%ebp), %ecx\n"
        "leal 8(%ecx, %edx), %eax\n"
        "subl %eax, %ebx\n" /* matchIndex */
        "leal (%ebx, %edi), %eax\n" /* matchIndex */
        "movl %eax, 4(%esp)\n"
        "addl $0x18, %edx\n"
        "movl %edx, (%esp)\n"
        "calll *-0x474(%ebp)\n"
        "cvtsi2ssl %eax, %xmm4\n"
        "addss -0x478(%ebp), %xmm4\n"
        "movss lit4_002ed5e0, %xmm6\n" /* 6.0f */
        "subss %xmm6, %xmm4\n"
        "movss conDrawInputGlob+28, %xmm3\n" /* line 1346 */
        "movaps %xmm3, %xmm5\n"
        "addss con+131108, %xmm5\n"
        "addss %xmm6, %xmm5\n"
        "movl con_inputHintBoxColor, %eax\n" /* line 1349 */
        "movl 8(%eax), %eax\n"
        "cvtsi2ssl -0x468(%ebp), %xmm0\n" /* matchCount */
        "mulss %xmm0, %xmm3\n"
        "movss lit4_002ed79c, %xmm0\n" /* 12.0f */
        "cvtsi2ssl -0x45c(%ebp), %xmm2\n" /* matchLenMax */
        "addss %xmm0, %xmm3\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm5, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "movss %xmm4, -0x498(%ebp)\n"
        "movss %xmm5, -0x4a8(%ebp)\n"
        "movss %xmm6, -0x4b8(%ebp)\n"
        "calll ConDraw_Box\n"
        "movss -0x498(%ebp), %xmm4\n" /* line 1351 */
        "movss -0x4b8(%ebp), %xmm6\n"
        "addss %xmm6, %xmm4\n"
        "movss %xmm4, conDrawInputGlob+16\n"
        "movaps %xmm6, %xmm0\n" /* line 1352 */
        "movss -0x4a8(%ebp), %xmm5\n"
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movss %xmm4, conDrawInputGlob+24\n" /* line 1353 */
        "movl -0x468(%ebp), %eax\n" /* line 1355 | matchCount */
        "testl %eax, %eax\n"
        "jle .Lf15d89e_0015d8e9\n"
        "xorl %ebx, %ebx\n" /* matchIndex */
        "movl imp_re, %edi\n"
        "movl imp_cls, %esi\n" /* stringIndex */
        "movl conDrawInputGlob+16, %eax\n"
        ".Lf15d89e_0015dc57:\n"
        "movl $0, 0x20(%esp)\n" /* line 1179 */
        "movl $con_inputDvarInfoColor, 0x1c(%esp)\n"
        "movl $0x3f800000, 0x18(%esp)\n"
        "movl $0x3f800000, 0x14(%esp)\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2a0a60(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x58(%ebp, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x11c(%edi)\n"
        "movss conDrawInputGlob+20, %xmm0\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        "addl $1, %ebx\n" /* line 1355 | matchIndex */
        "cmpl -0x468(%ebp), %ebx\n" /* matchCount, matchIndex */
        "jne .Lf15d89e_0015dc57\n"
        "jmp .Lf15d89e_0015d8e9\n"
    );
}

/* line 1451 */
static __attribute__((naked))
void ConDrawInput_CmdMatch(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1451 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* str */
        "movl conDrawInputGlob+8, %eax\n" /* line 1249 */
        "movl %eax, 8(%esp)\n"
        "movl conDrawInputGlob+4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n" /* line 1455 */
        "jne .Lf15dcda_0015dd89\n"
        "movl $0, 0x20(%esp)\n" /* line 1179 */
        "movl $con_inputCommandMatchColor, 0x1c(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_cls, %eax\n"
        "movl 0x2a0a60(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x11c(%eax)\n"
        "movss conDrawInputGlob+20, %xmm0\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        ".Lf15dcda_0015dd89:\n"
        "addl $0x34, %esp\n" /* line 1460 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 763 */
static __attribute__((naked))
int CL_ConsolePrint_AddLine(print_msg_type_t type, int duration, int linewidth, int color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 763 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl %edx, %ebx\n" /* txt */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* linewidth */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 777 */
        "je .Lf15dd90_0015df27\n"
        "cmpl $4, %eax\n"
        "je .Lf15dd90_0015df27\n"
        "movl con+131092, %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0x4e, %eax\n"
        "movl $0x4e, %eax\n"
        "cmovnsl %eax, %edx\n"
        "testl %edi, %edi\n" /* line 778 | linewidth */
        "jg .Lf15dd90_0015df35\n"
        ".Lf15dd90_0015ddd0:\n"
        "movl %edx, %edi\n" /* linewidth */
        "movl -0x28(%ebp), %eax\n" /* line 782 */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf15dd90_0015e00f\n"
        ".Lf15dd90_0015dde1:\n"
        "movl %edi, -0x20(%ebp)\n" /* line 787 | linewidth, targetLineWidth */
        ".Lf15dd90_0015dde4:\n"
        "movl con+131088, %eax\n" /* line 793 */
        "cmpl %eax, -0x28(%ebp)\n"
        "je .Lf15dd90_0015de00\n"
        "movl con+131080, %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf15dd90_0015de00\n"
        "movl -0x2c(%ebp), %edx\n" /* line 794 */
        "calll Con_Linefeed\n"
        ".Lf15dd90_0015de00:\n"
        "movl %ebx, %esi\n" /* line 796 | txt, buf */
        "movl $0, -0x1c(%ebp)\n" /* lineBroken */
        ".Lf15dd90_0015de09:\n"
        "movzbl (%esi), %ebx\n" /* line 798 | buf, txt */
        "movzbl %bl, %eax\n" /* txt */
        "movl %eax, -0x24(%ebp)\n" /* c */
        "testb %bl, %bl\n" /* txt */
        "je .Lf15dd90_0015dee2\n"
        ".Lf15dd90_0015de1a:\n"
        "cmpb $0x5e, %bl\n" /* line 800 | txt */
        "je .Lf15dd90_0015df95\n"
        ".Lf15dd90_0015de23:\n"
        "cmpl $0, %edi\n" /* line 811 | linewidth */
        "jle .Lf15dd90_0015df51\n"
        "cmpb $0x20, %bl\n" /* line 813 | txt */
        "jbe .Lf15dd90_0015df57\n"
        "xorl %eax, %eax\n" /* line 814 */
        ".Lf15dd90_0015de37:\n"
        "addl $1, %eax\n" /* line 811 */
        "cmpl %eax, %edi\n" /* linewidth */
        "je .Lf15dd90_0015de52\n"
        "cmpb $0x20, (%esi, %eax)\n" /* line 813 | buf */
        "ja .Lf15dd90_0015de37\n"
        "addl con+131080, %eax\n" /* line 818 */
        "cmpl %eax, %edi\n" /* linewidth */
        "jl .Lf15dd90_0015df67\n"
        ".Lf15dd90_0015de52:\n"
        "addl $1, %esi\n" /* line 824 | buf */
        "cmpb $0xa, %bl\n" /* line 826 | txt */
        "je .Lf15dd90_0015df85\n"
        ".Lf15dd90_0015de5e:\n"
        "cmpb $0xd, %bl\n" /* txt */
        "je .Lf15dd90_0015dfd2\n"
        "movl con+131080, %ecx\n" /* line 835 */
        "testl %ecx, %ecx\n"
        "jne .Lf15dd90_0015de7a\n"
        "cmpb $0x20, %bl\n" /* txt */
        "je .Lf15dd90_0015dfe1\n"
        ".Lf15dd90_0015de7a:\n"
        "movl con+131076, %eax\n" /* line 845 */
        "cltd\n"
        "idivl con+131096\n"
        "imull con+131092, %edx\n"
        "leal (%ecx, %edx), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* color */
        "shll $8, %eax\n"
        "orl -0x24(%ebp), %eax\n" /* c */
        "movw %ax, con+4(%edx, %edx)\n"
        "leal 1(%ecx), %eax\n" /* line 846 */
        "movl %eax, con+131080\n"
        "cmpl %eax, %edi\n" /* line 848 | linewidth */
        "jle .Lf15dd90_0015debf\n"
        "cmpl %eax, -0x20(%ebp)\n" /* targetLineWidth */
        "jg .Lf15dd90_0015de09\n"
        "cmpb $0x20, %bl\n" /* txt */
        "jne .Lf15dd90_0015de09\n"
        ".Lf15dd90_0015debf:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 850 */
        "movl -0x28(%ebp), %eax\n"
        "calll Con_Linefeed\n"
        "movl $1, -0x1c(%ebp)\n" /* lineBroken */
        "movzbl (%esi), %ebx\n" /* line 798 | buf, txt */
        "movzbl %bl, %eax\n" /* txt */
        "movl %eax, -0x24(%ebp)\n" /* c */
        "testb %bl, %bl\n" /* txt */
        "jne .Lf15dd90_0015de1a\n"
        ".Lf15dd90_0015dee2:\n"
        "movl con+131080, %edx\n" /* line 858 */
        "testl %edx, %edx\n"
        "jle .Lf15dd90_0015df14\n"
        "movl -0x28(%ebp), %eax\n" /* line 860 */
        "testl %eax, %eax\n"
        "jne .Lf15dd90_0015dff1\n"
        "movl con+131076, %eax\n" /* line 662 */
        "testl %eax, %eax\n"
        "js .Lf15dd90_0015df14\n"
        "movl con+131120, %eax\n" /* line 668 */
        "addl $0xfb4, %eax\n"
        "movl -0x2c(%ebp), %ecx\n"
        "xorl %edx, %edx\n"
        "calll Con_UpdateMessageWindowLine\n"
        ".Lf15dd90_0015df14:\n"
        "movl -0x28(%ebp), %eax\n" /* line 866 */
        "movl %eax, con+131088\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 869 | color */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15dd90_0015df27:\n"
        "movl con+131092, %edx\n" /* line 777 */
        "testl %edi, %edi\n" /* line 778 | linewidth */
        "jle .Lf15dd90_0015ddd0\n"
        ".Lf15dd90_0015df35:\n"
        "cmpl %edi, %edx\n" /* linewidth */
        "jl .Lf15dd90_0015ddd0\n"
        "movl -0x28(%ebp), %eax\n" /* line 782 */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf15dd90_0015dde1\n"
        "jmp .Lf15dd90_0015e00f\n"
        ".Lf15dd90_0015df51:\n"
        "je .Lf15dd90_0015de52\n" /* line 818 */
        ".Lf15dd90_0015df57:\n"
        "xorl %eax, %eax\n"
        "addl con+131080, %eax\n"
        "cmpl %eax, %edi\n" /* linewidth */
        "jge .Lf15dd90_0015de52\n"
        ".Lf15dd90_0015df67:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 820 */
        "movl -0x28(%ebp), %eax\n"
        "calll Con_Linefeed\n"
        "movl $1, -0x1c(%ebp)\n" /* lineBroken */
        "addl $1, %esi\n" /* line 824 | buf */
        "cmpb $0xa, %bl\n" /* line 826 | txt */
        "jne .Lf15dd90_0015de5e\n"
        ".Lf15dd90_0015df85:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 829 */
        "movl -0x28(%ebp), %eax\n"
        "calll Con_Linefeed\n"
        "jmp .Lf15dd90_0015de09\n"
        ".Lf15dd90_0015df95:\n"
        "movzbl 1(%esi), %eax\n" /* line 800 | buf */
        "testb %al, %al\n"
        "je .Lf15dd90_0015de23\n"
        "cmpb $0x5e, %al\n"
        "je .Lf15dd90_0015de23\n"
        "cmpb $0x2f, %al\n"
        "jbe .Lf15dd90_0015de23\n"
        "cmpb $0x39, %al\n"
        "ja .Lf15dd90_0015de23\n"
        "movzbl %al, %eax\n" /* line 802 */
        "movl %eax, (%esp)\n"
        "calll ColorIndex\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* color */
        "addl $2, %esi\n" /* line 804 | buf */
        "jmp .Lf15dd90_0015de09\n"
        ".Lf15dd90_0015dfd2:\n"
        "movl $0, con+131080\n" /* line 832 */
        "jmp .Lf15dd90_0015de09\n"
        ".Lf15dd90_0015dfe1:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 835 | lineBroken */
        "testl %eax, %eax\n"
        "jne .Lf15dd90_0015de09\n"
        "jmp .Lf15dd90_0015de7a\n"
        ".Lf15dd90_0015dff1:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 861 */
        "movl -0x28(%ebp), %eax\n"
        "calll Con_Linefeed\n"
        "movl -0x28(%ebp), %eax\n" /* line 866 */
        "movl %eax, con+131088\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 869 | color */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15dd90_0015e00f:\n"
        "movl %ebx, (%esp)\n" /* line 784 | txt */
        "calll SEH_PrintStrlen\n"
        "cmpl %eax, %edi\n" /* line 785 | linewidth */
        "jge .Lf15dd90_0015dde1\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 787 */
        "cvtsi2ssl %edi, %xmm0\n" /* linewidth */
        "movaps %xmm1, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll ceilf\n"
        "fstps -0x30(%ebp)\n"
        "cvttss2si -0x30(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x48(%ebp), %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* targetLineWidth */
        "jmp .Lf15dd90_0015dde4\n"
    );
}

/* line 872 */
__attribute__((naked))
void CL_ConsolePrint(print_msg_type_t type, const char *txt, int duration, int linewidth)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 872 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x103c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* duration */
        /* { scope 1 */
        "movl imp_cl_noprint, %eax\n" /* line 886 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf15e05e_0015e0e3\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf15e05e_0015e0e3\n"
        "cmpl $4, 8(%ebp)\n" /* line 888 | type */
        "je .Lf15e05e_0015e0e3\n"
        "movl con, %ebx\n" /* line 891 | charCount */
        "testl %ebx, %ebx\n" /* charCount */
        "je .Lf15e05e_0015e112\n"
        "testl %edi, %edi\n" /* line 898 | duration */
        "je .Lf15e05e_0015e0ee\n"
        ".Lf15e05e_0015e096:\n"
        "testl %edi, %edi\n" /* line 919 | duration */
        "movl $0, %eax\n"
        "cmovsl %eax, %edi\n" /* duration */
        ".Lf15e05e_0015e0a0:\n"
        "movl $0x37, (%esp)\n" /* line 922 */
        "calll ColorIndex\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x101c(%ebp)\n" /* color */
        "movl 8(%ebp), %eax\n" /* line 925 | type */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf15e05e_0015e158\n"
        "movl 0xc(%ebp), %esi\n" /* line 928 | txt, lineStart */
        ".Lf15e05e_0015e0c7:\n"
        "movl -0x101c(%ebp), %eax\n" /* line 945 | color */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* linewidth */
        "movl %eax, (%esp)\n"
        "movl %edi, %ecx\n" /* duration */
        "movl %esi, %edx\n" /* lineStart */
        "movl 8(%ebp), %eax\n" /* type */
        "calll CL_ConsolePrint_AddLine\n"
        /* } scope */
        ".Lf15e05e_0015e0e3:\n"
        "addl $0x103c, %esp\n" /* line 946 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15e05e_0015e0ee:\n"
        "cmpl $1, 8(%ebp)\n" /* line 900 | type */
        "je .Lf15e05e_0015e121\n"
        "jle .Lf15e05e_0015e223\n"
        "cmpl $2, 8(%ebp)\n" /* type */
        "je .Lf15e05e_0015e1ec\n"
        "cmpl $3, 8(%ebp)\n" /* type */
        "je .Lf15e05e_0015e1e2\n"
        ".Lf15e05e_0015e10e:\n"
        "xorl %edi, %edi\n" /* duration */
        "jmp .Lf15e05e_0015e0a0\n"
        ".Lf15e05e_0015e112:\n"
        "calll Con_OneTimeInit\n" /* line 893 */
        "testl %edi, %edi\n" /* line 898 | duration */
        "jne .Lf15e05e_0015e096\n"
        "jmp .Lf15e05e_0015e0ee\n"
        ".Lf15e05e_0015e121:\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl con_gamemessagetime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1024(%ebp)\n"
        "cvttss2si -0x1024(%ebp), %edi\n"
        "jmp .Lf15e05e_0015e096\n"
        ".Lf15e05e_0015e158:\n"
        "movl 0xc(%ebp), %esi\n" /* line 925 | txt, lineStart */
        "jmp .Lf15e05e_0015e1c3\n"
        ".Lf15e05e_0015e15d:\n"
        "subl %esi, %eax\n" /* line 934 | lineStart */
        "leal 1(%eax), %ebx\n" /* charCount */
        "movl %ebx, %eax\n" /* line 935 | charCount */
        "cmpl $0xfff, %ebx\n" /* charCount */
        "jbe .Lf15e05e_0015e176\n"
        "movl $0xfff, %ebx\n" /* charCount */
        "movl $0xfff, %eax\n"
        ".Lf15e05e_0015e176:\n"
        "movl %eax, 8(%esp)\n" /* line 937 */
        "movl %esi, 4(%esp)\n" /* lineStart */
        "leal -0x1018(%ebp), %eax\n" /* lineText */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movb $0, -0x1018(%ebp, %ebx)\n" /* line 938 */
        "movl -0x101c(%ebp), %eax\n" /* line 939 | color */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* linewidth */
        "movl %eax, (%esp)\n"
        "movl %edi, %ecx\n" /* duration */
        "leal -0x1018(%ebp), %edx\n" /* lineText */
        "movl 8(%ebp), %eax\n" /* type */
        "calll CL_ConsolePrint_AddLine\n"
        "movl %eax, -0x101c(%ebp)\n" /* color */
        "movl -0x102c(%ebp), %esi\n" /* line 941 | lineStart */
        "addl $1, %esi\n" /* lineStart */
        ".Lf15e05e_0015e1c3:\n"
        "movl $0xa, 4(%esp)\n" /* line 930 */
        "movl %esi, (%esp)\n" /* lineStart */
        "calll strchr\n"
        "movl %eax, -0x102c(%ebp)\n"
        "testl %eax, %eax\n" /* line 931 */
        "jne .Lf15e05e_0015e15d\n"
        "jmp .Lf15e05e_0015e0c7\n"
        ".Lf15e05e_0015e1e2:\n"
        "movl $0x1388, %edi\n" /* line 900 | duration */
        "jmp .Lf15e05e_0015e0a0\n"
        ".Lf15e05e_0015e1ec:\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl con_boldgamemessagetime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1028(%ebp)\n"
        "cvttss2si -0x1028(%ebp), %edi\n"
        "jmp .Lf15e05e_0015e096\n"
        ".Lf15e05e_0015e223:\n"
        "movl 8(%ebp), %ecx\n" /* line 900 | type */
        "testl %ecx, %ecx\n"
        "jne .Lf15e05e_0015e10e\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl con_minicontime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1020(%ebp)\n"
        "cvttss2si -0x1020(%ebp), %edi\n"
        "jmp .Lf15e05e_0015e096\n"
    );
}

/* line 949 */
void CL_ConsoleFixPosition(void)
{
    CL_ConsolePrint(0, "\n", 0, 0);
    *(int *)((char *)&con + 131084) = *(int *)((char *)&con + 131076) - 1;
}

/* line 1363 */
static __attribute__((naked))
void ConDrawInput_DetailedDvarMatch(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1363 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        "movl 8(%ebp), %edi\n" /* str */
        /* { scope 1 */
        "movl conDrawInputGlob+8, %eax\n" /* line 1249 */
        "movl %eax, 8(%esp)\n"
        "movl conDrawInputGlob+4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n" /* line 1372 */
        "jne .Lf15e2a0_0015e6b5\n"
        "cmpb $0, conDrawInputGlob+12\n" /* line 1374 */
        "je .Lf15e2a0_0015e2e9\n"
        "movl conDrawInputGlob+8, %eax\n"
        "cmpb $0, (%edi, %eax)\n" /* str */
        "jne .Lf15e2a0_0015e6b5\n"
        ".Lf15e2a0_0015e2e9:\n"
        "movl %edi, (%esp)\n" /* line 1377 | str */
        "calll Dvar_FindVar\n"
        "movl %eax, -0x42c(%ebp)\n" /* dvar */
        "movl %eax, (%esp)\n" /* line 1380 */
        "calll Dvar_HasLatchedValue\n"
        "movl %eax, %ebx\n" /* hasLatchedValue */
        "cmpb $1, %al\n" /* line 1383 */
        "sbbl %eax, %eax\n"
        "addl $3, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* lineCount */
        /* { scope 2 */
        "movss conDrawInputGlob+16, %xmm0\n" /* line 1233 */
        "subss lit4_002ed5e0, %xmm0\n" /* 6.0f */
        "movss con+131104, %xmm1\n" /* line 1236 */
        "movl con_inputHintBoxColor, %eax\n" /* line 1239 */
        "movl 8(%eax), %eax\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm3\n" /* lineCount */
        "mulss conDrawInputGlob+28, %xmm3\n"
        "movss con+131112, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm4\n"
        "subss %xmm1, %xmm4\n"
        "addss lit4_002ed79c, %xmm3\n" /* 12.0f */
        "subss %xmm4, %xmm2\n"
        "movss conDrawInputGlob+20, %xmm1\n"
        "subss lit4_002ed5e0, %xmm1\n" /* 6.0f */
        "calll ConDraw_Box\n"
        /* } scope */
        "movl $0, 0x20(%esp)\n" /* line 1186 */
        "movl $con_inputDvarMatchColor, 0x1c(%esp)\n"
        "movl $0x3f800000, %esi\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_cls, %edx\n"
        "movl 0x2a0a60(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "movl imp_re, %ecx\n"
        "calll *0x11c(%ecx)\n"
        "movss conDrawInputGlob+16, %xmm0\n" /* line 1199 */
        "addss lit4_002ed734, %xmm0\n" /* 200.0f */
        "movss %xmm0, conDrawInputGlob+16\n"
        "movl -0x42c(%ebp), %eax\n" /* line 1391 | dvar, str */
        "movl %eax, (%esp)\n" /* str */
        "calll Dvar_DisplayableValue\n"
        /* { scope 2 */
        "movl $0, 0x20(%esp)\n" /* line 1186 */
        "movl $con_inputDvarValueColor, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl imp_cls, %ecx\n"
        "movl 0x2a0a60(%ecx), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x28, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x11c(%eax)\n"
        /* } scope */
        "movss conDrawInputGlob+20, %xmm0\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        "testb %bl, %bl\n" /* line 1394 | hasLatchedValue */
        "jne .Lf15e2a0_0015e6c0\n"
        ".Lf15e2a0_0015e47d:\n"
        "movl $0, 0x20(%esp)\n" /* line 1179 */
        "movl $con_inputDvarInactiveValueColor, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_cls, %edx\n"
        "movl 0x2a0a60(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl $str_002ab838, (%esp)\n" /* "  default" */
        "movl imp_re, %ecx\n"
        "calll *0x11c(%ecx)\n"
        "movss lit4_002ed734, %xmm0\n" /* line 1199 | 200.0f */
        "addss conDrawInputGlob+16, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+16\n"
        "movl -0x42c(%ebp), %eax\n" /* line 1404 | dvar, str */
        "movl %eax, (%esp)\n" /* str */
        "calll Dvar_DisplayableResetValue\n"
        /* { scope 2 */
        "movl $0, 0x20(%esp)\n" /* line 1186 */
        "movl $con_inputDvarInactiveValueColor, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl imp_cls, %ecx\n"
        "movl 0x2a0a60(%ecx), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x28, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x11c(%eax)\n"
        /* } scope */
        "movss conDrawInputGlob+20, %xmm0\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        "movl -0x42c(%ebp), %eax\n" /* line 1408 | dvar */
        "movl 0x14(%eax), %edx\n"
        "movl 0x18(%eax), %ecx\n"
        "leal -0x1c(%ebp), %eax\n" /* lineCount */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x400, 0x10(%esp)\n"
        "leal -0x41c(%ebp), %ebx\n" /* dvarInfo, hasLatchedValue */
        "movl %ebx, 0xc(%esp)\n" /* hasLatchedValue */
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl -0x42c(%ebp), %edx\n" /* dvar */
        "movzbl 6(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_DomainToString_GetLines\n"
        /* { scope 2 */
        "movss conDrawInputGlob+16, %xmm0\n" /* line 1233 */
        "subss lit4_002ed5e0, %xmm0\n" /* 6.0f */
        "movss con+131104, %xmm1\n" /* line 1236 */
        "movl con_inputHintBoxColor, %eax\n" /* line 1239 */
        "movl 8(%eax), %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* lineCount */
        "addl $1, %edx\n"
        "cvtsi2ssl %edx, %xmm3\n"
        "mulss conDrawInputGlob+28, %xmm3\n"
        "movss con+131112, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm4\n"
        "subss %xmm1, %xmm4\n"
        "addss lit4_002ed79c, %xmm3\n" /* 12.0f */
        "subss %xmm4, %xmm2\n"
        "movss conDrawInputGlob+20, %xmm1\n"
        "subss lit4_002ed5e0, %xmm1\n" /* 6.0f */
        "calll ConDraw_Box\n"
        /* } scope */
        "movl $0, 0x20(%esp)\n" /* line 1179 */
        "movl $con_inputDvarInfoColor, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_cls, %edx\n"
        "movl 0x2a0a60(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl imp_re, %ecx\n"
        "calll *0x11c(%ecx)\n"
        "movss conDrawInputGlob+20, %xmm0\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        "movl -0x42c(%ebp), %eax\n" /* line 1414 | dvar */
        "cmpb $6, 6(%eax)\n"
        "je .Lf15e2a0_0015e7c0\n"
        /* } scope */
        ".Lf15e2a0_0015e6b5:\n"
        "addl $0x45c, %esp\n" /* line 1416 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15e2a0_0015e6c0:\n"
        "movl $0, 0x20(%esp)\n" /* line 1179 */
        "movl $con_inputDvarInactiveValueColor, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_cls, %edx\n"
        "movl 0x2a0a60(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl $str_002ab828, (%esp)\n" /* "  latched value" */
        "movl imp_re, %ecx\n"
        "calll *0x11c(%ecx)\n"
        "movss conDrawInputGlob+16, %xmm0\n" /* line 1199 */
        "addss lit4_002ed734, %xmm0\n" /* 200.0f */
        "movss %xmm0, conDrawInputGlob+16\n"
        "movl -0x42c(%ebp), %eax\n" /* line 1398 | dvar, str */
        "movl %eax, (%esp)\n" /* str */
        "calll Dvar_DisplayableLatchedValue\n"
        /* { scope 2 */
        "movl $0, 0x20(%esp)\n" /* line 1186 */
        "movl $con_inputDvarInactiveValueColor, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl imp_cls, %ecx\n"
        "movl 0x2a0a60(%ecx), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x28, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x11c(%eax)\n"
        /* } scope */
        "movss conDrawInputGlob+20, %xmm0\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        "jmp .Lf15e2a0_0015e47d\n"
        ".Lf15e2a0_0015e7c0:\n"
        "calll Cmd_Argc\n" /* line 1414 */
        "cmpl $2, %eax\n"
        "jne .Lf15e2a0_0015e6b5\n"
        "movl -0x42c(%ebp), %ecx\n" /* line 1415 | dvar */
        "movl 0x14(%ecx), %edx\n"
        "movl 0x18(%ecx), %eax\n"
        "calll ConDrawInput_AutoCompleteArg\n"
        "jmp .Lf15e2a0_0015e6b5\n"
    );
}

/* line 1419 */
static __attribute__((naked))
void ConDrawInput_DetailedCmdMatch(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1419 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 8(%ebp), %ebx\n" /* str */
        /* { scope 1 */
        "movl conDrawInputGlob+8, %eax\n" /* line 1249 */
        "movl %eax, 8(%esp)\n"
        "movl conDrawInputGlob+4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n" /* line 1428 */
        "jne .Lf15e7e4_0015e915\n"
        "cmpb $0, conDrawInputGlob+12\n" /* line 1430 */
        "je .Lf15e7e4_0015e828\n"
        "movl conDrawInputGlob+8, %eax\n"
        "cmpb $0, (%ebx, %eax)\n" /* files */
        "jne .Lf15e7e4_0015e915\n"
        /* { scope 2 */
        ".Lf15e7e4_0015e828:\n"
        "movss conDrawInputGlob+16, %xmm0\n" /* line 1233 */
        "movss lit4_002ed5e0, %xmm5\n" /* 6.0f */
        "subss %xmm5, %xmm0\n"
        "movss con+131104, %xmm1\n" /* line 1236 */
        "movl con_inputHintBoxColor, %eax\n" /* line 1239 */
        "movl 8(%eax), %eax\n"
        "movss con+131112, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm4\n"
        "subss %xmm1, %xmm4\n"
        "movss lit4_002ed79c, %xmm1\n" /* 12.0f */
        "movss conDrawInputGlob+28, %xmm3\n"
        "addss %xmm1, %xmm3\n"
        "subss %xmm4, %xmm2\n"
        "movss conDrawInputGlob+20, %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "calll ConDraw_Box\n"
        /* } scope */
        "movl $0, 0x20(%esp)\n" /* line 1179 */
        "movl $con_inputCommandMatchColor, 0x1c(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_cls, %eax\n"
        "movl 0x2a0a60(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x11c(%eax)\n"
        "movss conDrawInputGlob+20, %xmm0\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        "calll Cmd_Argc\n" /* line 1438 */
        "cmpl $2, %eax\n"
        "je .Lf15e7e4_0015e91b\n"
        /* } scope */
        ".Lf15e7e4_0015e915:\n"
        "addl $0x44, %esp\n" /* line 1448 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15e7e4_0015e91b:\n"
        "movl $0xa, 8(%esp)\n" /* line 1440 */
        "leal -0xc(%ebp), %eax\n" /* fileCount */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* files */
        "calll Cmd_GetAutoCompleteFileList\n"
        "movl %eax, %ebx\n" /* files */
        "movl -0xc(%ebp), %edx\n" /* line 1441 | fileCount */
        "testl %edx, %edx\n"
        "je .Lf15e7e4_0015e915\n"
        "calll ConDrawInput_AutoCompleteArg\n" /* line 1443 */
        "movl $0xa, 4(%esp)\n" /* line 1444 */
        "movl %ebx, (%esp)\n" /* files */
        "calll FS_FreeFileList\n"
        "jmp .Lf15e7e4_0015e915\n"
    );
}

/* line 1463 */
static __attribute__((naked))
void Con_DrawInput(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1463 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl imp_cl, %eax\n" /* line 1471 */
        "movl (%eax), %eax\n"
        "testb $1, 4(%eax)\n"
        "jne .Lf15e952_0015e970\n"
        /* } scope */
        ".Lf15e952_0015e968:\n"
        "addl $0x4c, %esp\n" /* line 1525 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15e952_0015e970:\n"
        "calll Sys_IsMainThread\n" /* line 1473 */
        "testb %al, %al\n"
        "je .Lf15e952_0015e968\n"
        "movl $str_002167d8, 8(%esp)\n" /* line 1476 */
        "movl $str_002167dc, 4(%esp)\n" /* "CoD2 MP" */
        "movl $str_002ab844, (%esp)\n" /* "%s: %s> " */
        "calll va\n"
        "movl %eax, %edi\n"
        "movl imp_re, %esi\n" /* line 1165 */
        "movl imp_cls, %ebx\n"
        "movl 0x2a0a60(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x118(%esi)\n"
        "cvtsi2ssl %eax, %xmm3\n" /* line 1478 */
        "movss %xmm3, conDrawInputGlob+28\n"
        "movss con+131104, %xmm1\n" /* line 1479 */
        "movaps %xmm1, %xmm0\n"
        "addss lit4_002ed5e0, %xmm0\n" /* 6.0f */
        "movss %xmm0, conDrawInputGlob+16\n"
        "movss con+131108, %xmm5\n" /* line 1480 */
        "addss lit4_002ed5e0, %xmm5\n" /* 6.0f */
        "movss %xmm5, conDrawInputGlob+20\n"
        "movss %xmm0, conDrawInputGlob+24\n" /* line 1481 */
        /* { scope 2 */
        "subss lit4_002ed5e0, %xmm0\n" /* line 1233 | 6.0f */
        "movl con_inputBoxColor, %eax\n" /* line 1239 */
        "movl 8(%eax), %eax\n"
        "movss con+131112, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm4\n"
        "subss %xmm1, %xmm4\n"
        "addss lit4_002ed79c, %xmm3\n" /* 12.0f */
        "subss %xmm4, %xmm2\n"
        "movaps %xmm5, %xmm1\n"
        "subss lit4_002ed5e0, %xmm1\n" /* 6.0f */
        "calll ConDraw_Box\n"
        /* } scope */
        "movl $0, 0x20(%esp)\n" /* line 1179 */
        "movl $con_versionColor, 0x1c(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2a0a60(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *0x11c(%esi)\n"
        "movss conDrawInputGlob+16, %xmm6\n" /* line 1208 */
        "movss %xmm6, -0x1c(%ebp)\n"
        "movl 0x2a0a60(%ebx), %eax\n" /* line 1172 */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *0x114(%esi)\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 1208 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, conDrawInputGlob+16\n"
        "movss %xmm1, conDrawInputGlob+24\n" /* line 1485 */
        "movl imp_g_consoleField, %ebx\n" /* line 1487 */
        "movss con+131112, %xmm0\n"
        "subss lit4_002ed5e0, %xmm0\n" /* 6.0f */
        "subss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl $1, 0x14(%esp)\n" /* line 1489 */
        "movl $5, 0x10(%esp)\n"
        "movl $5, 0xc(%esp)\n"
        "cvttss2si conDrawInputGlob+20, %eax\n"
        "movl %eax, 8(%esp)\n"
        "cvttss2si %xmm1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Field_Draw\n"
        "movss conDrawInputGlob+20, %xmm0\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        "addl $0x18, %ebx\n" /* line 1133 */
        "movl %ebx, (%esp)\n"
        "calll Cmd_TokenizeString\n"
        "movl $0, (%esp)\n" /* line 1135 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n"
        "movzbl (%eax), %eax\n" /* line 1136 */
        "cmpb $0x5c, %al\n"
        "je .Lf15e952_0015eb6b\n"
        "cmpb $0x2f, %al\n"
        "jne .Lf15e952_0015eb6e\n"
        ".Lf15e952_0015eb6b:\n"
        "addl $1, %ebx\n" /* line 1139 */
        ".Lf15e952_0015eb6e:\n"
        "movsbl (%ebx), %edx\n" /* line 1138 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "jne .Lf15e952_0015ec6f\n"
        "movl __DefaultRuneLocale, %eax\n"
        "movl 0x34(%eax, %edx, 4), %eax\n"
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        ".Lf15e952_0015eb8c:\n"
        "testl %eax, %eax\n" /* line 1138 */
        "jne .Lf15e952_0015eb6b\n"
        "movl %ebx, conDrawInputGlob+4\n" /* line 1492 */
        "cld\n" /* line 1493 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, conDrawInputGlob+8\n"
        "testl %ecx, %ecx\n" /* line 1494 */
        "je .Lf15e952_0015e968\n"
        "movb $0, conDrawInputGlob+12\n" /* line 1497 */
        "movl $0, conDrawInputGlob\n" /* line 1498 */
        "movl $ConDrawInput_IncrMatchCounter, (%esp)\n" /* line 1499 */
        "calll Dvar_ForEach\n"
        "movl $ConDrawInput_IncrMatchCounter, (%esp)\n" /* line 1500 */
        "calll Cmd_ForEach\n"
        "movl conDrawInputGlob, %esi\n" /* line 1501 | matchCount */
        "testl %esi, %esi\n" /* line 1503 | matchCount */
        "je .Lf15e952_0015e968\n"
        "movss conDrawInputGlob+20, %xmm5\n" /* line 1192 */
        "addss conDrawInputGlob+28, %xmm5\n"
        "movss %xmm5, conDrawInputGlob+20\n"
        "movl conDrawInputGlob+24, %eax\n" /* line 1193 */
        "movl %eax, conDrawInputGlob+16\n"
        "cmpl $0x18, %esi\n" /* line 1508 | matchCount */
        "jg .Lf15e952_0015ec8c\n"
        "cmpl $1, %esi\n" /* line 1514 | matchCount */
        "je .Lf15e952_0015ee48\n"
        "cmpb $0, conDrawInputGlob+12\n"
        "je .Lf15e952_0015ed6c\n"
        "movl imp_g_consoleField, %ebx\n"
        "movl __DefaultRuneLocale, %edi\n"
        "jmp .Lf15e952_0015ec4a\n"
        ".Lf15e952_0015ec35:\n"
        "movl 0x34(%edi, %eax, 4), %eax\n" /* line 220 */
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        ".Lf15e952_0015ec3f:\n"
        "testl %eax, %eax\n" /* line 1150 */
        "je .Lf15e952_0015ede4\n"
        "addl $1, %ebx\n" /* line 1514 */
        ".Lf15e952_0015ec4a:\n"
        "movsbl 0x18(%ebx), %eax\n" /* line 1150 */
        "testl $0xffffff80, %eax\n" /* line 220 */
        "je .Lf15e952_0015ec35\n"
        "movl $0x4000, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf15e952_0015ec3f\n"
        ".Lf15e952_0015ec6f:\n"
        "movl $0x4000, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf15e952_0015eb8c\n"
        ".Lf15e952_0015ec8c:\n"
        "movl %esi, 4(%esp)\n" /* line 1510 | matchCount */
        "movl $str_002ab850, (%esp)\n" /* "%i matches (too many to show)" */
        "calll va\n"
        "movl %eax, %ebx\n"
        /* { scope 2 */
        "movss conDrawInputGlob+16, %xmm0\n" /* line 1233 */
        "movss lit4_002ed5e0, %xmm5\n" /* 6.0f */
        "subss %xmm5, %xmm0\n"
        "movss con+131104, %xmm1\n" /* line 1236 */
        "movl con_inputHintBoxColor, %eax\n" /* line 1239 */
        "movl 8(%eax), %eax\n"
        "movss con+131112, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm4\n"
        "subss %xmm1, %xmm4\n"
        "movss lit4_002ed79c, %xmm1\n" /* 12.0f */
        "movss conDrawInputGlob+28, %xmm3\n"
        "addss %xmm1, %xmm3\n"
        "subss %xmm4, %xmm2\n"
        "movss conDrawInputGlob+20, %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "calll ConDraw_Box\n"
        /* } scope */
        "movl $0, 0x20(%esp)\n" /* line 1179 */
        "movl $con_inputDvarMatchColor, 0x1c(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movss conDrawInputGlob+20, %xmm0\n"
        "addss conDrawInputGlob+28, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl conDrawInputGlob+16, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imp_cls, %eax\n"
        "movl 0x2a0a60(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl imp_re, %eax\n"
        "calll *0x11c(%eax)\n"
        "jmp .Lf15e952_0015e968\n"
        ".Lf15e952_0015ed64:\n"
        "movss conDrawInputGlob+20, %xmm5\n"
        /* { scope 2 */
        ".Lf15e952_0015ed6c:\n"
        "movss conDrawInputGlob+16, %xmm0\n" /* line 1233 */
        "movss lit4_002ed5e0, %xmm4\n" /* 6.0f */
        "subss %xmm4, %xmm0\n"
        "movss con+131104, %xmm1\n" /* line 1236 */
        "movl con_inputHintBoxColor, %eax\n" /* line 1239 */
        "movl 8(%eax), %eax\n"
        "cvtsi2ssl %esi, %xmm3\n"
        "mulss conDrawInputGlob+28, %xmm3\n"
        "movss con+131112, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm6\n"
        "subss %xmm1, %xmm6\n"
        "addss lit4_002ed79c, %xmm3\n" /* 12.0f */
        "subss %xmm6, %xmm2\n"
        "movaps %xmm5, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "calll ConDraw_Box\n"
        /* } scope */
        "movl $ConDrawInput_DvarMatch, (%esp)\n" /* line 1522 */
        "calll Dvar_ForEach\n"
        "movl $ConDrawInput_CmdMatch, (%esp)\n" /* line 1523 */
        "calll Cmd_ForEach\n"
        "jmp .Lf15e952_0015e968\n"
        ".Lf15e952_0015ede4:\n"
        "movl imp_g_consoleField, %edx\n"
        "movl %ebx, %ecx\n"
        "subl %edx, %ecx\n"
        "movzbl 0x18(%ecx, %edx), %eax\n" /* line 1153 */
        "testb %al, %al\n"
        "je .Lf15e952_0015ed64\n"
        "leal 0x18(%ecx, %edx), %ebx\n"
        "jmp .Lf15e952_0015ee23\n"
        ".Lf15e952_0015ee01:\n"
        "movl __DefaultRuneLocale, %eax\n" /* line 220 */
        "movl 0x34(%eax, %edx, 4), %eax\n"
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        ".Lf15e952_0015ee10:\n"
        "testl %eax, %eax\n" /* line 1155 */
        "jne .Lf15e952_0015ee48\n"
        "movzbl 1(%ebx), %eax\n" /* line 1153 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "je .Lf15e952_0015ed64\n"
        ".Lf15e952_0015ee23:\n"
        "movsbl %al, %edx\n" /* line 1155 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "je .Lf15e952_0015ee01\n"
        "movl $0x4000, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf15e952_0015ee10\n"
        ".Lf15e952_0015ee48:\n"
        "movl $ConDrawInput_DetailedDvarMatch, (%esp)\n" /* line 1516 */
        "calll Dvar_ForEach\n"
        "movl $ConDrawInput_DetailedCmdMatch, (%esp)\n" /* line 1517 */
        "calll Cmd_ForEach\n"
        "jmp .Lf15e952_0015e968\n"
    );
}

/* line 1998 */
void Con_DrawConsole(void)
{
    Con_CheckResize();
    if (!(*(int *)((char *)*(void **)imp_cl + 4) & 1))
        return;
    if (con.outputVisible)
        Con_DrawOuputWindow();
    Con_DrawInput();
}

/* line 555 */
__attribute__((naked))
void Con_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 555 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "movl $0x1001, 8(%esp)\n" /* line 559 */
        "movl $0, 4(%esp)\n"
        "movl $str_002ab870, (%esp)\n" /* "con_restricted" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, con_restricted\n"
        "movl imp_g_consoleField, %ebx\n" /* line 561 */
        "movl %ebx, (%esp)\n"
        "calll Field_Clear\n"
        "movl g_console_field_width, %eax\n" /* line 562 */
        "movl %eax, 0xc(%ebx)\n"
        "movl g_console_char_height, %eax\n" /* line 563 */
        "movl %eax, 0x10(%ebx)\n"
        "movl $1, 0x14(%ebx)\n" /* line 564 */
        "xorl %esi, %esi\n" /* i */
        "movl imp_historyEditLines, %ebx\n"
        "movl %ebx, %ecx\n"
        "jmp .Lf15ee9c_0015eefd\n"
        ".Lf15ee9c_0015eef7:\n"
        "movl imp_historyEditLines, %ecx\n"
        ".Lf15ee9c_0015eefd:\n"
        "leal (%esi, %esi, 4), %edx\n" /* line 567 | i */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Field_Clear\n"
        "movl g_console_field_width, %eax\n" /* line 568 */
        "movl %eax, 0xc(%ebx)\n"
        "movl g_console_char_height, %eax\n" /* line 569 */
        "movl %eax, 0x10(%ebx)\n"
        "movl $1, 0x14(%ebx)\n" /* line 570 */
        "addl $1, %esi\n" /* line 565 | i */
        "addl $0x118, %ebx\n"
        "cmpl $0x20, %esi\n" /* i */
        "jne .Lf15ee9c_0015eef7\n"
        "movl $Con_ToggleConsole_f, 4(%esp)\n" /* line 573 */
        "movl $str_002ab880, (%esp)\n" /* "toggleconsole" */
        "calll Cmd_AddCommand\n"
        "movl $Con_ChatModePublic_f, 4(%esp)\n" /* line 574 */
        "movl $str_002ab890, (%esp)\n" /* "chatmodepublic" */
        "calll Cmd_AddCommand\n"
        "movl $Con_ChatModeTeam_f, 4(%esp)\n" /* line 575 */
        "movl $str_002ab8a0, (%esp)\n" /* "chatmodeteam" */
        "calll Cmd_AddCommand\n"
        "movl $Con_Clear_f, 4(%esp)\n" /* line 576 */
        "movl $str_002ab8b0, (%esp)\n" /* "clear" */
        "calll Cmd_AddCommand\n"
        "movl $Con_Dump_f, 4(%esp)\n" /* line 577 */
        "movl $str_002ab8b8, (%esp)\n" /* "condump" */
        "calll Cmd_AddCommand\n"
        "movl $0, registeredIconMaterialCount\n" /* line 190 */
        "movl $str_002a762c, (%esp)\n" /* line 224 */
        "calll CopyStringInternal\n"
        "movl %eax, hudMsgIconMaterials\n"
        "movl registeredIconMaterialCount, %eax\n" /* line 225 */
        "addl $1, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl %eax, %ebx\n"
        "movl %eax, registeredIconMaterialCount\n"
        "testl %eax, %eax\n" /* line 218 */
        "jle .Lf15ee9c_0015f015\n"
        "movl $0, -0x40(%ebp)\n"
        "movl $hudMsgIconMaterials, -0x1c(%ebp)\n"
        "cld\n"
        ".Lf15ee9c_0015efdd:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 220 */
        "movl (%edx), %edx\n"
        "movl $0xd, %ecx\n"
        "movl %edx, %esi\n"
        "movl $str_002a763c, %edi\n" /* "killicondied" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf15ee9c_0015f001\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf15ee9c_0015f001:\n"
        "testl %eax, %eax\n"
        "je .Lf15ee9c_0015f03a\n"
        "addl $1, -0x40(%ebp)\n" /* line 218 */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x44(%ebp), %esi\n"
        "cmpl %esi, -0x40(%ebp)\n"
        "jne .Lf15ee9c_0015efdd\n"
        ".Lf15ee9c_0015f015:\n"
        "movl $str_002a763c, (%esp)\n" /* line 224 */
        "calll CopyStringInternal\n"
        "movl -0x44(%ebp), %edx\n"
        "movl %eax, hudMsgIconMaterials(, %edx, 4)\n"
        "movl registeredIconMaterialCount, %ebx\n" /* line 225 */
        "addl $1, %ebx\n"
        "movl %ebx, registeredIconMaterialCount\n"
        ".Lf15ee9c_0015f03a:\n"
        "testl %ebx, %ebx\n" /* line 218 */
        "jle .Lf15ee9c_0015f083\n"
        "movl $0, -0x3c(%ebp)\n"
        "movl $hudMsgIconMaterials, -0x20(%ebp)\n"
        "cld\n"
        ".Lf15ee9c_0015f04d:\n"
        "movl -0x20(%ebp), %esi\n" /* line 220 */
        "movl (%esi), %esi\n"
        "movl %esi, -0x4c(%ebp)\n"
        "movl $0x10, %ecx\n"
        "movl $str_002a761c, %edi\n" /* "killiconfalling" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf15ee9c_0015f072\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf15ee9c_0015f072:\n"
        "testl %eax, %eax\n"
        "je .Lf15ee9c_0015f0a5\n"
        "addl $1, -0x3c(%ebp)\n" /* line 218 */
        "addl $4, -0x20(%ebp)\n"
        "cmpl -0x3c(%ebp), %ebx\n"
        "jne .Lf15ee9c_0015f04d\n"
        ".Lf15ee9c_0015f083:\n"
        "movl $str_002a761c, (%esp)\n" /* line 224 */
        "calll CopyStringInternal\n"
        "movl %eax, hudMsgIconMaterials(, %ebx, 4)\n"
        "movl registeredIconMaterialCount, %ebx\n" /* line 225 */
        "addl $1, %ebx\n"
        "movl %ebx, registeredIconMaterialCount\n"
        ".Lf15ee9c_0015f0a5:\n"
        "testl %ebx, %ebx\n" /* line 218 */
        "jle .Lf15ee9c_0015f0ee\n"
        "movl $0, -0x38(%ebp)\n"
        "movl $hudMsgIconMaterials, -0x24(%ebp)\n"
        "cld\n"
        ".Lf15ee9c_0015f0b8:\n"
        "movl -0x24(%ebp), %esi\n" /* line 220 */
        "movl (%esi), %esi\n"
        "movl %esi, -0x4c(%ebp)\n"
        "movl $0x11, %ecx\n"
        "movl $str_002a89d8, %edi\n" /* "killiconheadshot" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf15ee9c_0015f0dd\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf15ee9c_0015f0dd:\n"
        "testl %eax, %eax\n"
        "je .Lf15ee9c_0015f110\n"
        "addl $1, -0x38(%ebp)\n" /* line 218 */
        "addl $4, -0x24(%ebp)\n"
        "cmpl %ebx, -0x38(%ebp)\n"
        "jne .Lf15ee9c_0015f0b8\n"
        ".Lf15ee9c_0015f0ee:\n"
        "movl $str_002a89d8, (%esp)\n" /* line 224 */
        "calll CopyStringInternal\n"
        "movl %eax, hudMsgIconMaterials(, %ebx, 4)\n"
        "movl registeredIconMaterialCount, %ebx\n" /* line 225 */
        "addl $1, %ebx\n"
        "movl %ebx, registeredIconMaterialCount\n"
        ".Lf15ee9c_0015f110:\n"
        "testl %ebx, %ebx\n" /* line 218 */
        "jle .Lf15ee9c_0015f159\n"
        "movl $0, -0x34(%ebp)\n"
        "movl $hudMsgIconMaterials, -0x28(%ebp)\n"
        "cld\n"
        ".Lf15ee9c_0015f123:\n"
        "movl -0x28(%ebp), %esi\n" /* line 220 */
        "movl (%esi), %esi\n"
        "movl %esi, -0x4c(%ebp)\n"
        "movl $0xe, %ecx\n"
        "movl $str_002a75fc, %edi\n" /* "killiconmelee" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf15ee9c_0015f148\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf15ee9c_0015f148:\n"
        "testl %eax, %eax\n"
        "je .Lf15ee9c_0015f17b\n"
        "addl $1, -0x34(%ebp)\n" /* line 218 */
        "addl $4, -0x28(%ebp)\n"
        "cmpl %ebx, -0x34(%ebp)\n"
        "jne .Lf15ee9c_0015f123\n"
        ".Lf15ee9c_0015f159:\n"
        "movl $str_002a75fc, (%esp)\n" /* line 224 */
        "calll CopyStringInternal\n"
        "movl %eax, hudMsgIconMaterials(, %ebx, 4)\n"
        "movl registeredIconMaterialCount, %ebx\n" /* line 225 */
        "addl $1, %ebx\n"
        "movl %ebx, registeredIconMaterialCount\n"
        ".Lf15ee9c_0015f17b:\n"
        "testl %ebx, %ebx\n" /* line 218 */
        "jle .Lf15ee9c_0015f1c4\n"
        "movl $0, -0x30(%ebp)\n"
        "movl $hudMsgIconMaterials, -0x2c(%ebp)\n"
        "cld\n"
        ".Lf15ee9c_0015f18e:\n"
        "movl -0x2c(%ebp), %esi\n" /* line 220 */
        "movl (%esi), %esi\n"
        "movl %esi, -0x4c(%ebp)\n"
        "movl $0x10, %ecx\n"
        "movl $str_002a760c, %edi\n" /* "killiconsuicide" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf15ee9c_0015f1b3\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf15ee9c_0015f1b3:\n"
        "testl %eax, %eax\n"
        "je .Lf15ee9c_0015f1de\n"
        "addl $1, -0x30(%ebp)\n" /* line 218 */
        "addl $4, -0x2c(%ebp)\n"
        "cmpl %ebx, -0x30(%ebp)\n"
        "jne .Lf15ee9c_0015f18e\n"
        ".Lf15ee9c_0015f1c4:\n"
        "movl $str_002a760c, (%esp)\n" /* line 224 */
        "calll CopyStringInternal\n"
        "movl %eax, hudMsgIconMaterials(, %ebx, 4)\n"
        "addl $1, registeredIconMaterialCount\n" /* line 225 */
        /* } scope */
        ".Lf15ee9c_0015f1de:\n"
        "addl $0x7c, %esp\n" /* line 580 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1025 */
__attribute__((naked))
void CL_DeathMessagePrint(const char *attackerName, const vec_t *attackerColor, const char *victimName, const vec_t *victimColor, const char *iconShader, float iconWidth, float iconHeight, const vec_t *iconColor, int horzFlipIcon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1025 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* attackerName */
        "movzbl 0x28(%ebp), %eax\n" /* horzFlipIcon */
        "movb %al, -0x31(%ebp)\n" /* horzFlipIcon */
        /* { scope 1 */
        "movl imp_cl_noprint, %eax\n" /* line 1035 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf15f1e6_0015f20e\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf15f1e6_0015f481\n"
        ".Lf15f1e6_0015f20e:\n"
        "movl con, %edi\n" /* line 1038 | c */
        "testl %edi, %edi\n" /* c */
        "je .Lf15f1e6_0015f6af\n"
        ".Lf15f1e6_0015f21c:\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl con_gamemessagetime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x38(%ebp)\n"
        "cvttss2si -0x38(%ebp), %edx\n"
        "testl %edx, %edx\n" /* line 1046 */
        "movl $0, %eax\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* duration */
        "movl con+131080, %esi\n" /* line 1050 | index */
        "testl %esi, %esi\n" /* index */
        "jle .Lf15f1e6_0015f26b\n"
        "movl %eax, %edx\n" /* line 1051 */
        "movl con+131088, %eax\n"
        "calll Con_Linefeed\n"
        ".Lf15f1e6_0015f26b:\n"
        "movl $0x37, (%esp)\n" /* line 1055 */
        "calll ColorIndex\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "cmpb $0, (%ebx)\n" /* line 1058 | attackerName */
        "jne .Lf15f1e6_0015f573\n"
        ".Lf15f1e6_0015f286:\n"
        "movl 0x24(%ebp), %edx\n" /* line 1069 | iconColor */
        "movl $0xd, %eax\n"
        "calll CL_AddConsoleInfoColor\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 1072 | horzFlipIcon */
        "je .Lf15f1e6_0015f489\n"
        "movl con+131076, %edi\n" /* line 961 */
        "movl %edi, %eax\n"
        "cltd\n"
        "idivl con+131096\n"
        "imull con+131092, %edx\n"
        "movl con+131080, %ecx\n"
        "addl %ecx, %edx\n"
        "movss lit4_002ed830, %xmm0\n" /* 32.0f */
        "movss 0x1c(%ebp), %xmm1\n" /* iconWidth */
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "orb $0x13, %ah\n"
        "movw %ax, con+4(%edx, %edx)\n"
        "addl $1, %ecx\n" /* line 962 */
        "movl %ecx, con+131080\n"
        ".Lf15f1e6_0015f2e4:\n"
        "movl %edi, %eax\n" /* line 961 */
        "cltd\n"
        "idivl con+131096\n"
        "imull con+131092, %edx\n"
        "addl %ecx, %edx\n"
        "mulss 0x20(%ebp), %xmm0\n" /* iconHeight */
        "cvttss2si %xmm0, %eax\n"
        "orb $0x11, %ah\n"
        "movw %ax, con+4(%edx, %edx)\n"
        "addl $1, %ecx\n" /* line 962 */
        "movl %ecx, -0x28(%ebp)\n"
        "movl %ecx, con+131080\n"
        /* { scope 2 */
        "movl registeredIconMaterialCount, %esi\n" /* line 243 | index */
        "movl %esi, -0x24(%ebp)\n" /* index */
        "testl %esi, %esi\n" /* index */
        "jg .Lf15f1e6_0015f4d5\n"
        ".Lf15f1e6_0015f327:\n"
        "xorl %ecx, %ecx\n"
        /* } scope */
        ".Lf15f1e6_0015f329:\n"
        "movl %edi, %eax\n" /* line 961 */
        "cltd\n"
        "idivl con+131096\n"
        "imull con+131092, %edx\n"
        "addl -0x28(%ebp), %edx\n"
        "movzbl %cl, %eax\n"
        "orb $0x12, %ah\n"
        "movw %ax, con+4(%edx, %edx)\n"
        "addl $1, con+131080\n" /* line 962 */
        "movl -0x1c(%ebp), %edx\n" /* line 988 */
        "movl %edx, -0x4c(%ebp)\n"
        "movl %edi, %eax\n" /* line 993 | c */
        "cltd\n"
        "idivl con+131096\n"
        "movl %edx, -0x44(%ebp)\n"
        /* { scope 2 */
        "movl $str_00217914, %edx\n" /* line 997 */
        "shll $8, -0x4c(%ebp)\n"
        "movl con+131092, %esi\n" /* index */
        /* } scope */
        "movzbl (%edx), %eax\n" /* line 995 */
        "movzbl %al, %ebx\n"
        "testb %al, %al\n"
        "je .Lf15f1e6_0015f3c2\n"
        ".Lf15f1e6_0015f37c:\n"
        "movl con+131080, %ecx\n"
        "cmpl %esi, %ecx\n" /* index */
        "jge .Lf15f1e6_0015f3c2\n"
        "cmpb $0x5e, %al\n" /* line 997 */
        "je .Lf15f1e6_0015f505\n"
        "leal 1(%edx), %edi\n" /* line 1009 | c */
        "cmpb $0xa, %al\n"
        "je .Lf15f1e6_0015f3b6\n"
        "cmpb $0xd, %al\n"
        "je .Lf15f1e6_0015f3b6\n"
        ".Lf15f1e6_0015f399:\n"
        "movl -0x44(%ebp), %eax\n" /* line 1017 */
        "imull %esi, %eax\n" /* index */
        "addl %ecx, %eax\n"
        "movl -0x4c(%ebp), %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, con+4(%eax, %eax)\n"
        "leal 1(%ecx), %eax\n" /* line 1018 */
        "movl %eax, con+131080\n"
        ".Lf15f1e6_0015f3b6:\n"
        "movl %edi, %edx\n" /* line 995 | c */
        ".Lf15f1e6_0015f3b8:\n"
        "movzbl (%edx), %eax\n"
        "movzbl %al, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf15f1e6_0015f37c\n"
        ".Lf15f1e6_0015f3c2:\n"
        "movl 0x14(%ebp), %edx\n" /* line 1086 | victimColor */
        "movl $0xa, %eax\n"
        "calll CL_AddConsoleInfoColor\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0x10(%ebp), %edi\n" /* victimName */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl con+131080, %eax\n"
        "leal 2(%ecx, %eax), %ecx\n"
        "cmpl con+131092, %ecx\n"
        "jge .Lf15f1e6_0015f6b9\n"
        ".Lf15f1e6_0015f3f3:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 988 */
        "movl %edx, -0x20(%ebp)\n"
        "movl con+131076, %eax\n" /* line 993 */
        "cltd\n"
        "idivl con+131096\n"
        "movl %edx, -0x5c(%ebp)\n"
        "movl 0x10(%ebp), %esi\n" /* victimName, index */
        "movzbl (%esi), %eax\n" /* line 995 | index */
        "movzbl %al, %ebx\n"
        "testb %al, %al\n"
        "je .Lf15f1e6_0015f46a\n"
        ".Lf15f1e6_0015f415:\n"
        "movl con+131080, %ecx\n"
        "movl con+131092, %edx\n"
        "cmpl %edx, %ecx\n"
        "jge .Lf15f1e6_0015f46a\n"
        "cmpb $0x5e, %al\n" /* line 997 */
        "je .Lf15f1e6_0015f536\n"
        "movl 0x10(%ebp), %edi\n" /* line 1009 | victimName, c */
        "addl $1, %edi\n" /* c */
        "cmpb $0xa, %al\n"
        "je .Lf15f1e6_0015f45b\n"
        "cmpb $0xd, %al\n"
        "je .Lf15f1e6_0015f45b\n"
        ".Lf15f1e6_0015f43b:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 1017 */
        "imull %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl -0x20(%ebp), %edx\n"
        "shll $8, %edx\n"
        "orl %ebx, %edx\n"
        "movw %dx, con+4(%eax, %eax)\n"
        "leal 1(%ecx), %eax\n" /* line 1018 */
        "movl %eax, con+131080\n"
        ".Lf15f1e6_0015f45b:\n"
        "movl %edi, 0x10(%ebp)\n" /* line 995 | c, victimName */
        "movl %edi, %esi\n" /* c, index */
        ".Lf15f1e6_0015f460:\n"
        "movzbl (%esi), %eax\n" /* index */
        "movzbl %al, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf15f1e6_0015f415\n"
        ".Lf15f1e6_0015f46a:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1096 | duration */
        "movl $1, %eax\n"
        "calll Con_Linefeed\n"
        "movl $1, con+131088\n" /* line 1098 */
        /* } scope */
        ".Lf15f1e6_0015f481:\n"
        "addl $0x6c, %esp\n" /* line 1099 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15f1e6_0015f489:\n"
        "movl con+131076, %edi\n" /* line 961 */
        "movl %edi, %eax\n"
        "cltd\n"
        "idivl con+131096\n"
        "imull con+131092, %edx\n"
        "movl con+131080, %ecx\n"
        "addl %ecx, %edx\n"
        "movss lit4_002ed830, %xmm0\n" /* 32.0f */
        "movss 0x1c(%ebp), %xmm1\n" /* iconWidth */
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "orb $0x10, %ah\n"
        "movw %ax, con+4(%edx, %edx)\n"
        "addl $1, %ecx\n" /* line 962 */
        "movl %ecx, con+131080\n"
        "jmp .Lf15f1e6_0015f2e4\n"
        /* { scope 2 */
        ".Lf15f1e6_0015f4d5:\n"
        "xorl %esi, %esi\n" /* line 243 | index */
        "movl $hudMsgIconMaterials, %ebx\n"
        ".Lf15f1e6_0015f4dc:\n"
        "movl 0x18(%ebp), %eax\n" /* line 245 | iconShader */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf15f1e6_0015f6d8\n"
        "addl $1, %esi\n" /* line 243 | index */
        "addl $4, %ebx\n"
        "cmpl -0x24(%ebp), %esi\n" /* index */
        "jne .Lf15f1e6_0015f4dc\n"
        "jmp .Lf15f1e6_0015f327\n"
        /* } scope */
        ".Lf15f1e6_0015f505:\n"
        "leal 1(%edx), %edi\n" /* line 997 | c */
        "movzbl 1(%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf15f1e6_0015f399\n"
        "cmpb $0x5e, %al\n"
        "je .Lf15f1e6_0015f399\n"
        "cmpb $0x2f, %al\n"
        "jle .Lf15f1e6_0015f399\n"
        "cmpb $0x39, %al\n"
        "jg .Lf15f1e6_0015f399\n"
        "leal 2(%edx), %edi\n" /* line 1001 | c */
        "movl %edi, %edx\n" /* line 995 | c */
        "jmp .Lf15f1e6_0015f3b8\n"
        ".Lf15f1e6_0015f536:\n"
        "movl 0x10(%ebp), %edi\n" /* line 997 | victimName, c */
        "addl $1, %edi\n" /* c */
        "movl 0x10(%ebp), %esi\n" /* victimName, index */
        "movzbl 1(%esi), %eax\n" /* index */
        "testb %al, %al\n"
        "je .Lf15f1e6_0015f43b\n"
        "cmpb $0x5e, %al\n"
        "je .Lf15f1e6_0015f43b\n"
        "cmpb $0x2f, %al\n"
        "jle .Lf15f1e6_0015f43b\n"
        "cmpb $0x39, %al\n"
        "jg .Lf15f1e6_0015f43b\n"
        "movl 0x10(%ebp), %edi\n" /* line 1001 | victimName, c */
        "addl $2, %edi\n" /* c */
        "movl %edi, 0x10(%ebp)\n" /* line 995 | c, victimName */
        "movl %edi, %esi\n" /* c, index */
        "jmp .Lf15f1e6_0015f460\n"
        ".Lf15f1e6_0015f573:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1061 | attackerColor */
        "movl $0xa, %eax\n"
        "calll CL_AddConsoleInfoColor\n"
        /* { scope 2 */
        "movl -0x1c(%ebp), %esi\n" /* line 988 | index */
        "movl %esi, -0x30(%ebp)\n" /* index, color */
        "movl con+131076, %eax\n" /* line 993 */
        "cltd\n"
        "idivl con+131096\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movzbl (%ebx), %eax\n" /* line 995 */
        "movzbl %al, %edi\n" /* c */
        "testb %al, %al\n"
        "je .Lf15f1e6_0015f5ee\n"
        ".Lf15f1e6_0015f59f:\n"
        "movl con+131080, %ecx\n"
        "movl con+131092, %edx\n"
        "cmpl %edx, %ecx\n"
        "jge .Lf15f1e6_0015f5ee\n"
        "cmpb $0x5e, %al\n" /* line 997 */
        "je .Lf15f1e6_0015f65d\n"
        "leal 1(%ebx), %esi\n" /* line 1009 | index */
        "cmpb $0xa, %al\n"
        "je .Lf15f1e6_0015f5e2\n"
        "cmpb $0xd, %al\n"
        "je .Lf15f1e6_0015f5e2\n"
        ".Lf15f1e6_0015f5c2:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1017 */
        "imull %edx, %eax\n"
        "addl %ecx, %eax\n"
        "movl -0x30(%ebp), %edx\n" /* color */
        "shll $8, %edx\n"
        "orl %edi, %edx\n" /* c */
        "movw %dx, con+4(%eax, %eax)\n"
        "leal 1(%ecx), %eax\n" /* line 1018 */
        "movl %eax, con+131080\n"
        ".Lf15f1e6_0015f5e2:\n"
        "movl %esi, %ebx\n" /* line 995 | index */
        ".Lf15f1e6_0015f5e4:\n"
        "movzbl (%ebx), %eax\n"
        "movzbl %al, %edi\n" /* c */
        "testb %al, %al\n"
        "jne .Lf15f1e6_0015f59f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf15f1e6_0015f5ee:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 988 | index */
        "movl con+131076, %eax\n" /* line 993 */
        "cltd\n"
        "idivl con+131096\n"
        "movl %edx, -0x40(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl $str_00217914, %edx\n" /* line 997 */
        "shll $8, %esi\n" /* index */
        "movl %esi, -0x48(%ebp)\n" /* index */
        "movl con+131092, %edi\n" /* c */
        /* } scope */
        /* { scope 2 */
        ".Lf15f1e6_0015f611:\n"
        "movzbl (%edx), %eax\n" /* line 995 */
        "movzbl %al, %esi\n" /* index */
        "testb %al, %al\n"
        "je .Lf15f1e6_0015f286\n"
        "movl con+131080, %ecx\n"
        "cmpl %edi, %ecx\n" /* c */
        "jge .Lf15f1e6_0015f286\n"
        "cmpb $0x5e, %al\n" /* line 997 */
        "je .Lf15f1e6_0015f68e\n"
        "leal 1(%edx), %ebx\n" /* line 1009 */
        "cmpb $0xa, %al\n"
        "je .Lf15f1e6_0015f659\n"
        "cmpb $0xd, %al\n"
        "je .Lf15f1e6_0015f659\n"
        ".Lf15f1e6_0015f63c:\n"
        "movl -0x40(%ebp), %eax\n" /* line 1017 */
        "imull %edi, %eax\n" /* c */
        "addl %ecx, %eax\n"
        "movl -0x48(%ebp), %edx\n"
        "orl %esi, %edx\n" /* index */
        "movw %dx, con+4(%eax, %eax)\n"
        "leal 1(%ecx), %eax\n" /* line 1018 */
        "movl %eax, con+131080\n"
        ".Lf15f1e6_0015f659:\n"
        "movl %ebx, %edx\n" /* line 995 */
        "jmp .Lf15f1e6_0015f611\n"
        /* } scope */
        /* { scope 2 */
        ".Lf15f1e6_0015f65d:\n"
        "leal 1(%ebx), %esi\n" /* line 997 | index */
        "movzbl 1(%ebx), %eax\n"
        "testb %al, %al\n"
        "je .Lf15f1e6_0015f5c2\n"
        "cmpb $0x5e, %al\n"
        "je .Lf15f1e6_0015f5c2\n"
        "cmpb $0x2f, %al\n"
        "jle .Lf15f1e6_0015f5c2\n"
        "cmpb $0x39, %al\n"
        "jg .Lf15f1e6_0015f5c2\n"
        "leal 2(%ebx), %esi\n" /* line 1001 | index */
        "movl %esi, %ebx\n" /* line 995 | index */
        "jmp .Lf15f1e6_0015f5e4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf15f1e6_0015f68e:\n"
        "leal 1(%edx), %ebx\n" /* line 997 */
        "movzbl 1(%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf15f1e6_0015f63c\n"
        "cmpb $0x5e, %al\n"
        "je .Lf15f1e6_0015f63c\n"
        "cmpb $0x2f, %al\n"
        "jle .Lf15f1e6_0015f63c\n"
        "cmpb $0x39, %al\n"
        "jg .Lf15f1e6_0015f63c\n"
        "leal 2(%edx), %ebx\n" /* line 1001 */
        "movl %ebx, %edx\n" /* line 995 */
        "jmp .Lf15f1e6_0015f611\n"
        /* } scope */
        ".Lf15f1e6_0015f6af:\n"
        "calll Con_OneTimeInit\n" /* line 1040 */
        "jmp .Lf15f1e6_0015f21c\n"
        ".Lf15f1e6_0015f6b9:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1091 | duration */
        "movl $1, %eax\n"
        "calll Con_Linefeed\n"
        "movl 0x14(%ebp), %edx\n" /* line 1092 | victimColor */
        "movl $0xa, %eax\n"
        "calll CL_AddConsoleInfoColor\n"
        "jmp .Lf15f1e6_0015f3f3\n"
        /* { scope 2 */
        ".Lf15f1e6_0015f6d8:\n"
        "movl %esi, %ecx\n" /* line 245 | index */
        "jmp .Lf15f1e6_0015f329\n"
    );
}
