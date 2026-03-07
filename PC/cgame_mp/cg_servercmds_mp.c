/* Decompiled from: cg_servercmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_servercmds_mp.cpp */

#include "common_types.h"
#include "imports.h"

#include <string.h>
#include <stdlib.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern float floorf(float x);

/* Extern declarations for called functions */
extern const char *CL_GetConfigString(int index);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern void Dvar_SetStringByName(const char *dvarName, const char *value);
extern void Dvar_SetFromStringByName(const char *dvarName, const char *value);
extern const char *GetBspExtension(void);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void Com_Error(errorParm_t code, const char *fmt, ...);
extern const char *CG_Argv(int arg);
extern int Cmd_Argc(void);
extern void Cbuf_AddText(const char *text);
extern const char *va(const char *format, ...);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern int I_stricmp(const char *s1, const char *s2);
extern int CL_Popup(const char *menuName);
extern void CL_ClosePopup(const char *menuName);
extern const char *Com_Parse(const char **data_p);
extern void CL_SwitchFog(int fogIndex, int serverTime, int transitionTime);
extern void CL_SetFog(int fogIndex, float start, float halfDist, int r, int g, int b, float density);
extern void SND_DeactivateChannelVolumes(int prio, int fadeTime);
extern void SND_SetChannelVolumes(int prio, char *volumes, int fadeTime);
extern void SND_DeactivateEnvironmentEffects(int prio, int fadeTime);
extern int Load_ScriptMenu(const char *name, int flags);
extern void CL_RegisterMaterialNoMip(const char *name, int flags);
extern void CL_RegisterMaterial(const char *name, int flags);
extern void CG_InitLocalEntities(void);
extern void CG_InitMarkPolys(void);
extern void FX_FreeActive(void);
extern void SND_StopSounds(int mode);
extern void CG_StartAmbient(void);
extern void Dvar_SetBool(void *dvar, int value);
extern void CL_SetADS(int value);
extern void CL_CloseAllMenus(void);
extern void CG_ScoresUp_f(void);
extern void CL_SyncTimes(void);
extern int CL_GetServerCommand(int seq);
extern int stricmp(const char *s1, const char *s2);

/*
 * Indirect global pointers (absolute addresses from original binary).
 *   imp_cgs -> cgs_t* (game static state)
 *   imp_cg -> cg_t* (main cgame state)
 *   imp_legacyHacks -> cgame UI state
 *   imp_cg_chatHeight -> dvar (cg_teamChatHeight)
 *   imp_cg_chatTime -> dvar (cg_teamChatTime)
 *   imp_cg_showmiss -> dvar (developer)
 *   imp_cg_thirdPerson -> dvar
 *   imp_cg_teamChatsOnly -> dvar (cl_paused)
 */
#define CGS_PTR      ((char *)*(void **)imp_cgs)
#define CG_PTR       ((char *)*(void **)imp_cg)
#define CGUI_PTR     ((char *)*(void **)imp_legacyHacks)

void CG_ParseServerinfo(void);
void CG_ParseCodinfo(void);
static void CG_AddToTeamChat(void);
static void CG_OpenScriptMenu(void);
void CG_CheckOpenWaitingScriptMenu(void);
void CG_CloseScriptMenu(void);
void CG_MenuShowNotify(int menuToShow);
static void CG_SetClientDvarFromServer(void);
void CG_ParseFog(void);
static void CG_DeactivateChannelVolCmd(void);
static void CG_SetChannelVolCmd(void);
static void CG_DeactivateReverbCmd(void);
void CG_SetConfigValues(void);
void CG_MapRestart(qboolean savepersist);
void CG_ServerCommand(void);
void CG_ExecuteNewServerCommands(int latestSequence);

/* line 148 */
void CG_ParseServerinfo(void)
{
    const char *info;
    const char *val;
    char *cgs;
    const char *mapname;
    const char *ext;

    info = CL_GetConfigString(0);

    val = Info_ValueForKey(info, (const char *)str_002a714c);
    cgs = CGS_PTR;
    strncpy(cgs + 0x5ec4, val, 0x100);

    val = Info_ValueForKey(info, (const char *)str_002a7100);
    strncpy(cgs + 0x5ea4, val, 0x20);

    if (*(int *)(cgs + 0x5ea0) == 0) {
        Dvar_SetStringByName((const char *)str_002a7100, cgs + 0x5ea4);
    }

    val = Info_ValueForKey(info, (const char *)str_002a70dc);
    *(int *)(cgs + 0x5fc4) = atoi(val);

    mapname = Info_ValueForKey(info, (const char *)str_002a7124);
    ext = GetBspExtension();
    Com_sprintf(cgs + 0x5fc8, 0x40, (const char *)str_002a74ac, mapname, ext);
}

/* line 172 */
void CG_ParseCodinfo(void)
{
    char *cgs;
    int i;
    const char *key;

    cgs = CGS_PTR;
    if (*(int *)(cgs + 0x5ea0) != 0) {
        return;
    }

    for (i = 0x8e; i < 0xee; i++) {
        key = CL_GetConfigString(i);
        if (*key == '\0') {
            break;
        }
        Dvar_SetFromStringByName(key, CL_GetConfigString(i + 0x60));
    }
}

/* line 540 — uses register calling convention (str in eax), called from naked CG_ServerCommand */
static __attribute__((naked))
void CG_AddToTeamChat(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 540 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %esi\n" /* str */
        /* { scope 1 */
        "movl imp_cg_chatHeight, %eax\n" /* line 547 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edi\n" /* chatHeight */
        "testl %edi, %edi\n" /* line 548 | chatHeight */
        "je .Lf1df89c_001dfa01\n"
        "movl imp_cg_chatTime, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1df89c_001dfa01\n"
        "movl imp_cgs, %eax\n" /* line 557 */
        "movl (%eax), %ebx\n" /* len */
        "movl 0xba14(%ebx), %eax\n" /* len */
        "cltd\n"
        "idivl %edi\n" /* chatHeight */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %ecx\n"
        "shll $8, %ecx\n"
        "addl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xb170(%eax, %ebx), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movb $0, 0xc(%eax)\n" /* line 558 */
        "xorl %ebx, %ebx\n" /* len */
        "movl $0x37, -0x10(%ebp)\n" /* lastcolor */
        "movl $0, -0x14(%ebp)\n" /* ls */
        "jmp .Lf1df89c_001df92d\n"
        ".Lf1df89c_001df909:\n"
        "movl %esi, %edx\n" /* line 565 | str */
        "cmpb $0x5e, (%esi)\n" /* line 586 | str */
        "je .Lf1df89c_001df9cb\n"
        ".Lf1df89c_001df914:\n"
        "addl $1, %esi\n" /* str */
        "addl $1, %ebx\n" /* len */
        ".Lf1df89c_001df91a:\n"
        "movzbl (%edx), %eax\n" /* line 593 */
        "cmpb $0x20, %al\n"
        "movl -0x14(%ebp), %edx\n" /* ls */
        "cmovel %ecx, %edx\n"
        "movl %edx, -0x14(%ebp)\n" /* ls */
        "movb %al, (%ecx)\n" /* line 597 */
        "addl $1, %ecx\n"
        ".Lf1df89c_001df92d:\n"
        "cmpb $0, (%esi)\n" /* line 563 | str */
        "je .Lf1df89c_001dfa2c\n"
        "cmpl $0x59, %ebx\n" /* line 565 | len */
        "jle .Lf1df89c_001df909\n"
        "movl -0x14(%ebp), %ebx\n" /* line 567 | ls, len */
        "testl %ebx, %ebx\n" /* len */
        "je .Lf1df89c_001df950\n"
        "movl %ecx, %edx\n" /* line 569 */
        "subl -0x14(%ebp), %edx\n" /* ls */
        "movl %esi, %eax\n" /* str */
        "subl %edx, %eax\n"
        "leal 1(%eax), %esi\n" /* line 570 | str */
        "subl %edx, %ecx\n" /* line 571 */
        ".Lf1df89c_001df950:\n"
        "movb $0, (%ecx)\n" /* line 573 */
        "movl imp_cgs, %edx\n" /* line 575 */
        "movl (%edx), %ebx\n" /* len */
        "movl 0xba14(%ebx), %eax\n" /* len */
        "movl %eax, -0x18(%ebp)\n"
        "cltd\n"
        "idivl %edi\n" /* chatHeight */
        "movl %edx, %ecx\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x25bb0(%edx), %edx\n"
        "movl %edx, 0xb9f4(%ebx, %ecx, 4)\n" /* len */
        "movl -0x18(%ebp), %eax\n" /* line 577 */
        "addl $1, %eax\n"
        "movl %eax, 0xba14(%ebx)\n" /* len */
        "cltd\n" /* line 578 */
        "idivl %edi\n" /* chatHeight */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %ecx\n"
        "shll $8, %ecx\n"
        "addl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xb170(%eax, %ebx), %eax\n"
        "movb $0x5e, 0xc(%eax)\n" /* line 580 */
        "movzbl -0x10(%ebp), %edx\n" /* line 581 | lastcolor */
        "movb %dl, 0xd(%eax)\n"
        "leal 0xe(%eax), %ecx\n"
        "testl %esi, %esi\n" /* line 586 | str */
        "je .Lf1df89c_001dfa7f\n"
        "movl %esi, %edx\n" /* str */
        "xorl %ebx, %ebx\n" /* len */
        "movl $0, -0x14(%ebp)\n" /* ls */
        "cmpb $0x5e, (%esi)\n" /* str */
        "jne .Lf1df89c_001df914\n"
        ".Lf1df89c_001df9cb:\n"
        "addl $1, %esi\n" /* str */
        "movzbl 1(%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf1df89c_001dfa24\n"
        "cmpb $0x5e, %al\n"
        "je .Lf1df89c_001dfa24\n"
        "cmpb $0x2f, %al\n"
        "jle .Lf1df89c_001dfa24\n"
        "cmpb $0x39, %al\n"
        "jg .Lf1df89c_001dfa24\n"
        "movb $0x5e, (%ecx)\n" /* line 588 */
        "movzbl 1(%edx), %esi\n" /* line 589 | str */
        "movl %esi, %eax\n" /* str */
        "movsbl %al, %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* lastcolor */
        "movl %esi, %eax\n" /* line 590 | str */
        "movb %al, 1(%ecx)\n"
        "addl $2, %ecx\n"
        "leal 2(%edx), %esi\n" /* str */
        "jmp .Lf1df89c_001df92d\n"
        ".Lf1df89c_001dfa01:\n"
        "movl imp_cgs, %eax\n" /* line 551 */
        "movl (%eax), %eax\n"
        "movl $0, 0xba18(%eax)\n"
        "movl $0, 0xba14(%eax)\n"
        /* } scope */
        ".Lf1df89c_001dfa1c:\n"
        "addl $0x10, %esp\n" /* line 607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1df89c_001dfa24:\n"
        "addl $1, %ebx\n" /* line 586 | len */
        "jmp .Lf1df89c_001df91a\n"
        ".Lf1df89c_001dfa2c:\n"
        "movb $0, (%ecx)\n" /* line 600 */
        "movl imp_cgs, %eax\n" /* line 602 */
        "movl (%eax), %ebx\n" /* len */
        "movl 0xba14(%ebx), %esi\n" /* len, str */
        "movl %esi, %eax\n" /* str */
        "cltd\n"
        "idivl %edi\n" /* chatHeight */
        "movl %edx, %ecx\n"
        "movl imp_cg, %edx\n"
        "movl (%edx), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl %eax, 0xb9f4(%ebx, %ecx, 4)\n" /* len */
        "leal 1(%esi), %edx\n" /* line 603 | str */
        "movl %edx, 0xba14(%ebx)\n" /* len */
        "movl %edx, %eax\n" /* line 605 */
        "subl 0xba18(%ebx), %eax\n" /* len */
        "cmpl %eax, %edi\n" /* chatHeight */
        "jge .Lf1df89c_001dfa1c\n"
        "movl %edx, %eax\n" /* line 606 */
        "subl %edi, %eax\n" /* chatHeight */
        "movl %eax, 0xba18(%ebx)\n" /* len */
        /* } scope */
        "addl $0x10, %esp\n" /* line 607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1df89c_001dfa7f:\n"
        "movl $0, -0x14(%ebp)\n" /* line 591 | ls */
        "xorl %edx, %edx\n"
        "movl $1, %esi\n" /* str */
        "movl $1, %ebx\n" /* len */
        "jmp .Lf1df89c_001df91a\n"
    );
}

/* line 692 */
static void CG_OpenScriptMenu(void)
{
    int menuIndex;
    const char *pszMenu;
    unsigned char noMouseControl;
    char *cgui;
    int result;
    const char *arg2;

    menuIndex = atoi(CG_Argv(1));

    if ((unsigned int)menuIndex > 31) {
        Com_Printf((const char *)str_002b8070, menuIndex);
        Cbuf_AddText(va((const char *)str_002b80a4, menuIndex));
        return;
    }

    pszMenu = CL_GetConfigString(menuIndex + 0x4de);

    if (*pszMenu == '\0') {
        Com_Printf((const char *)str_002b80b4, menuIndex);
        Cbuf_AddText(va((const char *)str_002b80a4, menuIndex));
        return;
    }

    if (Cmd_Argc() > 2) {
        arg2 = CG_Argv(2);
        if (arg2 != NULL) {
            arg2 = CG_Argv(2);
            noMouseControl = (*arg2 != '\0') ? 1 : 0;
        } else {
            noMouseControl = 0;
        }
    } else {
        noMouseControl = 0;
    }

    cgui = CGUI_PTR;
    I_strncpyz(cgui + 0x2e4, pszMenu, 0x100);
    *(int *)(cgui + 0x3e4) = menuIndex;

    if (noMouseControl) {
        result = CL_Popup((const char *)str_002adc98);
    } else {
        result = CL_Popup((const char *)str_002adc84);
    }

    if (result) {
        return;
    }

    /* Popup failed */
    cgui = CGUI_PTR;
    *(cgui + 0x2e4) = '\0';
    *(int *)(cgui + 0x3e4) = -1;

    if (*(cgui + 0x3e8) != '\0') {
        if (I_stricmp(pszMenu, cgui + 0x3e8) == 0) {
            return;
        }
        Cbuf_AddText(va((const char *)str_002b80f0, *(int *)(cgui + 0x4e8)));
    }

    /* Store as waiting menu */
    cgui = CGUI_PTR;
    I_strncpyz(cgui + 0x3e8, pszMenu, 0x100);
    *(int *)(cgui + 0x4e8) = menuIndex;
    *(unsigned char *)(cgui + 0x4ec) = noMouseControl;
}

/* line 763 */
void CG_CheckOpenWaitingScriptMenu(void)
{
    char *cgui;
    int result;

    cgui = CGUI_PTR;
    if (*(cgui + 0x3e8) == '\0') {
        return;
    }

    /* Copy waiting menu to active */
    strcpy(cgui + 0x2e4, cgui + 0x3e8);
    cgui = CGUI_PTR;
    *(int *)(cgui + 0x3e4) = *(int *)(cgui + 0x4e8);

    cgui = CGUI_PTR;
    if (*(unsigned char *)(cgui + 0x4ec)) {
        result = CL_Popup((const char *)str_002adc98);
    } else {
        result = CL_Popup((const char *)str_002adc84);
    }

    if (result) {
        /* Popup succeeded, clear waiting */
        cgui = CGUI_PTR;
        *(cgui + 0x3e8) = '\0';
        *(int *)(cgui + 0x4e8) = -1;
        *(unsigned char *)(cgui + 0x4ec) = 0;
    } else {
        /* Popup failed, clear active */
        cgui = CGUI_PTR;
        *(cgui + 0x2e4) = '\0';
        *(int *)(cgui + 0x3e4) = -1;
    }
}

/* line 805 */
void CG_CloseScriptMenu(void)
{
    char *cgui;

    CL_ClosePopup((const char *)str_002adc84);
    CL_ClosePopup((const char *)str_002adc98);

    cgui = CGUI_PTR;
    *(unsigned char *)(cgui + 0x1de) = 0;
    *(int *)(cgui + 0x2e0) = -1;
    *(cgui + 0x2e4) = '\0';
    *(int *)(cgui + 0x3e4) = -1;
    *(cgui + 0x3e8) = '\0';
    *(int *)(cgui + 0x4e8) = -1;
    *(unsigned char *)(cgui + 0x4ec) = 0;
}

/* line 825 — jump table, kept as naked */
__attribute__((naked))
void CG_MenuShowNotify(int menuToShow)
{
    __asm__ __volatile__ (
        ".Lf1dfd68_001dfd68:\n"
        "pushl %ebp\n" /* line 825 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* menuToShow */
        /* { scope 1 */
        "cmpl $5, %eax\n" /* line 829 */
        "ja .Lf1dfd68_001dfddb\n"
        "jmpl *.Ljt_1dfd68_0(, %eax, 4)\n"
        ".Lf1dfd68_001dfd7d:\n"
        "movl $4, (%esp)\n" /* line 844 */
        "calll CG_MenuShowNotify\n"
        "movl imp_cg, %eax\n" /* line 846 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5c8(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5c8(%eax)\n" /* line 848 */
        "calll CL_GetLocalClientActiveCount\n" /* line 849 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff1f\n"
        "movl $str_002b703c, 4(%esp)\n" /* line 852 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        ".Lf1dfd68_001dfdc7:\n"
        "testl %eax, %eax\n" /* line 898 */
        "je .Lf1dfd68_001dfddb\n"
        "movl $4, 4(%esp)\n" /* line 899 */
        "movl %eax, (%esp)\n"
        "calll Window_AddDynamicFlags\n"
        /* } scope */
        ".Lf1dfd68_001dfddb:\n"
        "leave\n" /* line 905 */
        "retl\n"
        /* { scope 1 */
        ".Lf1dfd68_001dfddd:\n"
        "movl imp_cg, %eax\n" /* line 832 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5c4(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5c4(%eax)\n" /* line 834 */
        "calll CL_GetLocalClientActiveCount\n" /* line 835 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff87\n"
        "movl $str_002b7030, 4(%esp)\n" /* line 838 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dfe1d:\n"
        "movl imp_cg, %eax\n" /* line 894 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2b538(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2b538(%eax)\n" /* line 896 */
        "movl $str_002b7074, 4(%esp)\n" /* line 897 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dfe52:\n"
        "movl imp_cg, %eax\n" /* line 882 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5d0(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5d0(%eax)\n" /* line 884 */
        "calll CL_GetLocalClientActiveCount\n" /* line 885 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff53\n"
        "movl $str_002b7064, 4(%esp)\n" /* line 888 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dfe99:\n"
        "movl imp_cg, %eax\n" /* line 870 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5cc(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5cc(%eax)\n" /* line 872 */
        "calll CL_GetLocalClientActiveCount\n" /* line 873 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff39\n"
        "movl $str_002b704c, 4(%esp)\n" /* line 876 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dfedc:\n"
        "movl imp_cg, %eax\n" /* line 858 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5c0(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5c0(%eax)\n" /* line 860 */
        "calll CL_GetLocalClientActiveCount\n" /* line 861 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff6d\n"
        "movl $str_002a79e8, 4(%esp)\n" /* line 864 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff1f:\n"
        "movl $str_002b5978, 4(%esp)\n" /* line 850 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff39:\n"
        "movl $str_00221984, 4(%esp)\n" /* line 874 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff53:\n"
        "movl $str_002b7058, 4(%esp)\n" /* line 886 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff6d:\n"
        "movl $str_002a79e0, 4(%esp)\n" /* line 862 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff87:\n"
        "movl $str_002b7028, 4(%esp)\n" /* line 836 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_1dfd68_0:\n"
        ".long .Lf1dfd68_001dfddd\n"
        ".long .Lf1dfd68_001dfd7d\n"
        ".long .Lf1dfd68_001dfedc\n"
        ".long .Lf1dfd68_001dfe99\n"
        ".long .Lf1dfd68_001dfe52\n"
        ".long .Lf1dfd68_001dfe1d\n"
        ".text\n"
    );
}

/* line 1165 — uses register calling convention (dvarname in eax, value in edx) */
static __attribute__((naked))
void CG_SetClientDvarFromServer(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1165 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %ebx\n" /* dvarname */
        "movl %edx, %esi\n" /* value */
        "movl $str_002b8100, 4(%esp)\n" /* line 1167 */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1dffa2_001dffe9\n"
        "movl $0x400, 8(%esp)\n" /* line 1147 */
        "movl %esi, 4(%esp)\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x2a9fc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x10, %esp\n" /* line 1175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1dffa2_001dffe9:\n"
        "movl $str_002b8114, 4(%esp)\n" /* line 1169 */
        "movl %ebx, (%esp)\n" /* dvarname */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1dffa2_001e0024\n"
        "movl $str_002b8120, 4(%esp)\n" /* line 1171 */
        "movl %ebx, (%esp)\n" /* dvarname */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1dffa2_001e0041\n"
        "movl %esi, 4(%esp)\n" /* line 1174 | value */
        "movl %ebx, (%esp)\n" /* dvarname */
        "calll Dvar_SetFromStringByName\n"
        "addl $0x10, %esp\n" /* line 1175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1dffa2_001e0024:\n"
        "movl %esi, (%esp)\n" /* line 1170 | value */
        "calll atoi\n"
        /* { scope 1 */
        "movl imp_cg, %edx\n" /* line 1154 */
        "movl (%edx), %edx\n"
        "movl %eax, 0x2bdc8(%edx)\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1dffa2_001e0041:\n"
        "movl $0x100, 8(%esp)\n" /* line 1161 */
        "movl %esi, 4(%esp)\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x2adfc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x10, %esp\n" /* line 1175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 272 */
void CG_ParseFog(void)
{
    const char *info;
    const char *token;
    float start;
    double halfDist_d, val3_d, val4_d, val5_d, val6_d;
    int transitionTime;
    char *cg;

    info = CL_GetConfigString(12);

    token = Com_Parse(&info);
    start = (float)atof(token);

    token = Com_Parse(&info);
    if (token == NULL || *token == '\0') {
        /* Simple fog: just switch */
        cg = CG_PTR;
        CL_SwitchFog(0, *(int *)(cg + 0x25bb0), (int)start);
        return;
    }

    halfDist_d = atof(token);

    val3_d = atof(Com_Parse(&info));
    val4_d = atof(Com_Parse(&info));
    val5_d = atof(Com_Parse(&info));
    val6_d = atof(Com_Parse(&info));

    token = Com_Parse(&info);
    transitionTime = atoi(token);

    CL_SetFog(1, start, (float)halfDist_d,
        (int)(unsigned char)(int)floorf((float)val4_d * 255.0f + 0.5f),
        (int)(unsigned char)(int)floorf((float)val5_d * 255.0f + 0.5f),
        (int)(unsigned char)(int)floorf((float)val6_d * 255.0f + 0.5f),
        (float)val3_d);

    cg = CG_PTR;
    CL_SwitchFog(1, *(int *)(cg + 0x25bb0), transitionTime);
}

/* line 1097 */
static void CG_DeactivateChannelVolCmd(void)
{
    int argc;
    int prio;
    int fadeTime;
    float fval;

    argc = Cmd_Argc();
    if (argc != 3) {
        Com_Printf((const char *)str_002b8134, argc);
        return;
    }

    prio = atoi(CG_Argv(1));
    fval = (float)(int)floorf((float)atof(CG_Argv(2)) * 1000.0f + 0.5f);
    fadeTime = (fval > 0.0f) ? (int)fval : 0;

    SND_DeactivateChannelVolumes(prio, fadeTime);
}

/* line 1071 */
static void CG_SetChannelVolCmd(void)
{
    int argc;
    int prio;
    int shockIndex;
    int fadeTime;
    float fval;
    char *cgs;

    argc = Cmd_Argc();
    if (argc != 4) {
        Com_Printf((const char *)str_002b817c, argc);
        return;
    }

    prio = atoi(CG_Argv(1));
    shockIndex = atoi(CG_Argv(2));
    fval = (float)(int)floorf((float)atof(CG_Argv(3)) * 1000.0f + 0.5f);
    fadeTime = (fval > 0.0f) ? (int)fval : 0;

    cgs = CGS_PTR;
    SND_SetChannelVolumes(prio, cgs + 0x68fc + shockIndex * 132, fadeTime);
}

/* line 1047 */
static void CG_DeactivateReverbCmd(void)
{
    int argc;
    int prio;
    int fadeTime;
    float fval;

    argc = Cmd_Argc();
    if (argc != 3) {
        Com_Printf((const char *)str_002b81bc, argc);
        return;
    }

    prio = atoi(CG_Argv(1));
    fval = (float)(int)floorf((float)atof(CG_Argv(2)) * 1000.0f + 0.5f);
    fadeTime = (fval > 0.0f) ? (int)fval : 0;

    SND_DeactivateEnvironmentEffects(prio, fadeTime);
}

/* line 359 */
void CG_SetConfigValues(void)
{
    char *cgs;
    int i;
    const char *str;

    cgs = CGS_PTR;
    *(int *)(cgs + 0x63b8) = atoi(CL_GetConfigString(5));
    *(int *)(cgs + 0x63bc) = atoi(CL_GetConfigString(6));
    *(int *)(cgs + 0x63b4) = atoi(CL_GetConfigString(13));

    CL_SwitchFog(0, *(int *)(CG_PTR + 0x25bb0), 0);

    /* Load script menus */
    for (i = 0x4de; i < 0x4fe; i++) {
        str = CL_GetConfigString(i);
        if (*str == '\0') {
            continue;
        }
        if (!Load_ScriptMenu(str, 7)) {
            Com_Error(ERR_DROP, (const char *)str_002b8200, str);
        }
    }

    /* Register materials (no mip) */
    for (i = 0x17; i < 0x1f; i++) {
        CL_RegisterMaterialNoMip(CL_GetConfigString(i), 7);
    }

    /* Register materials */
    for (i = 0x1f; i < 0x2e; i++) {
        CL_RegisterMaterial(CL_GetConfigString(i), 7);
    }

    /* Register additional materials (no mip, skip empty) */
    for (i = 0x61f; i < 0x69e; i++) {
        str = CL_GetConfigString(i);
        if (*str == '\0') {
            continue;
        }
        CL_RegisterMaterialNoMip(str, 7);
    }
}

/* line 621 */
void CG_MapRestart(qboolean savepersist)
{
    char *cg;
    char *cgs;
    char *cgui;

    if (*(int *)(*(char **)*(void **)imp_cg_showmiss + 8) != 0) {
        Com_Printf((const char *)str_002b8228);
    }

    cg = CG_PTR;
    *(int *)(cg + 0x2b990) = 0;
    *(int *)(cg + 0x2bdf0) = 0;
    *(int *)(cg + 0x2be00) = 1;

    CG_InitLocalEntities();
    CG_InitMarkPolys();
    FX_FreeActive();

    cgs = CGS_PTR;
    *(int *)(cgs + 0x6088) = 0;

    *(int *)(cg + 0x25bbc) = 1;

    SND_StopSounds(0);
    CG_StartAmbient();

    *(int *)(cg + 0x2c5a4) = 0;
    *(int *)(cg + 0x2bf0c) = 0;

    memset(cg + 0x2be74, 0, 0x60);

    *(int *)(cg + 0x2be60) = 0;
    *(int *)(cg + 0x2be64) = 0;
    *(int *)(cg + 0x2be68) = 0;
    *(int *)(cg + 0x2be6c) = 0;

    Dvar_SetBool(*(void **)*(void **)imp_cg_thirdPerson, 0);

    cgui = CGUI_PTR;
    *(int *)(cgui + 8) = 0;

    CL_SetADS(0);

    if (!savepersist) {
        cgui = CGUI_PTR;
        *(unsigned char *)(cgui + 0x4ed) = 0;

        CG_CloseScriptMenu();
        CG_CloseScriptMenu();

        cgui = CGUI_PTR;
        *(unsigned char *)(cgui + 0x4ed) = 1;

        CL_CloseAllMenus();
    }

    CG_ScoresUp_f();
    *(unsigned char *)(cg + 0x2a9fc) = 0;

    CL_SyncTimes();
}

/* line 1189 — massive jump table dispatch, kept as naked */
__attribute__((naked))
void CG_ServerCommand(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 1199 */
        "calll CG_Argv\n"
        "movsbl (%eax), %eax\n" /* line 1201 */
        "cmpl $0x76, %eax\n"
        "ja .Lf1e07d0_001e08ae\n"
        "jmpl *.Ljt_1e07d0_0(, %eax, 4)\n"
        ".Lf1e07d0_001e07fb:\n"
        "cmpl $5, %ebx\n" /* line 470 */
        "je .Lf1e07d0_001e14b5\n"
        "cmpl $6, %ebx\n" /* line 474 */
        "je .Lf1e07d0_001e149b\n"
        "cmpl $0xd, %ebx\n" /* line 478 */
        "je .Lf1e07d0_001e1481\n"
        "cmpl $0xf, %ebx\n" /* line 482 */
        "je .Lf1e07d0_001e1467\n"
        "cmpl $0x11, %ebx\n" /* line 486 */
        "je .Lf1e07d0_001e144d\n"
        "cmpl $0x12, %ebx\n" /* line 490 */
        "je .Lf1e07d0_001e1433\n"
        "cmpl $0x10, %ebx\n" /* line 494 */
        "je .Lf1e07d0_001e136d\n"
        "cmpl $0xc, %ebx\n" /* line 498 */
        "je .Lf1e07d0_001e152f\n"
        "leal -0x14e(%ebx), %esi\n" /* line 502 */
        "cmpl $0xff, %esi\n"
        "jbe .Lf1e07d0_001e1352\n"
        "leal -0x34e(%ebx), %esi\n" /* line 506 */
        "cmpl $0x3f, %esi\n"
        "jbe .Lf1e07d0_001e1337\n"
        "leal -0x48e(%ebx), %esi\n" /* line 510 */
        "cmpl $0xf, %esi\n"
        "ja .Lf1e07d0_001e12fd\n"
        "cmpb $0, (%edi)\n" /* line 512 */
        "je .Lf1e07d0_001e08a3\n"
        "movl %edi, (%esp)\n"
        "calll CG_LoadShellShockDvars\n"
        "testl %eax, %eax\n"
        "je .Lf1e07d0_001e08a3\n"
        "movl %esi, %eax\n" /* line 513 */
        "shll $7, %eax\n"
        "leal 0x68c0(%eax, %esi, 4), %eax\n"
        "movl imp_cgs, %edx\n"
        "addl (%edx), %eax\n"
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_SetShellShockParmsFromDvars\n"
        /* } scope */
        ".Lf1e07d0_001e08a3:\n"
        "addl $0x30c, %esp\n" /* line 1369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e07d0_001e08ae:\n"
        "movl $0, (%esp)\n" /* line 1357 */
        "calll CG_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b8350, (%esp)\n"
        "calll Com_Printf\n"
        "calll Cmd_Argc\n" /* line 1359 */
        "movl %eax, %esi\n" /* argc */
        "cmpl $1, %eax\n" /* line 1360 */
        "jle .Lf1e07d0_001e08a3\n"
        "leal -1(%eax), %eax\n" /* line 1362 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b8374, (%esp)\n"
        "calll Com_Printf\n"
        "movl $1, %ebx\n" /* weapIndex */
        ".Lf1e07d0_001e08ee:\n"
        "movl %ebx, (%esp)\n" /* line 1364 | weapIndex */
        "calll CG_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002abc2c, (%esp)\n"
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 1363 | weapIndex */
        "cmpl %ebx, %esi\n" /* weapIndex, argc */
        "jne .Lf1e07d0_001e08ee\n"
        "movl $str_002160e8, (%esp)\n" /* line 1365 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x30c, %esp\n" /* line 1369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e07d0_001e0924:\n"
        "movl $1, (%esp)\n" /* line 1230 */
        "calll CG_Argv\n"
        "leal -0x1b2(%ebp), %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $str_002b8250, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CG_TranslateHudElemMessage\n"
        "movl %ebx, (%esp)\n" /* line 1231 */
        "calll CG_GameMessage\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0957:\n"
        "movl $1, (%esp)\n" /* line 1327 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* weapIndex */
        "testl %eax, %eax\n" /* line 1328 */
        "je .Lf1e07d0_001e0987\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x84(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0987:\n"
        "movl %ebx, (%esp)\n" /* line 1329 | weapIndex */
        "calll CG_SetEquippedOffHand\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0994:\n"
        "calll CG_DeactivateReverbCmd\n" /* line 1284 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e099e:\n"
        "calll CG_SetChannelVolCmd\n" /* line 1288 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e09a8:\n"
        "calll CG_DeactivateChannelVolCmd\n" /* line 1292 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e09b2:\n"
        "movl $1, (%esp)\n" /* line 1345 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        /* { scope 2 */
        "movl imp_cgs, %edx\n" /* line 1008 */
        "movl (%edx), %edx\n"
        "movl %eax, 0x63b8(%edx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        /* } scope */
        ".Lf1e07d0_001e09d9:\n"
        "movl $1, (%esp)\n" /* line 1349 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        /* { scope 2 */
        "movl imp_cgs, %edx\n" /* line 1008 */
        "movl (%edx), %edx\n"
        "movl %eax, 0x63bc(%edx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        /* } scope */
        ".Lf1e07d0_001e0a00:\n"
        "movl $1, (%esp)\n" /* line 1353 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%esp)\n"
        "calll CG_MenuShowNotify\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0a21:\n"
        "movl $1, (%esp)\n" /* line 1334 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%esp)\n"
        "calll CL_ResetPlayerMuting\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0a42:\n"
        "calll CL_CloseInGameMenu\n" /* line 1308 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0a4c:\n"
        "movl $1, (%esp)\n" /* line 1208 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%esp)\n"
        "calll CG_SelectWeaponIndex\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0a6d:\n"
        "movl $0, (%esp)\n" /* line 1323 */
        "calll CG_MapRestart\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0a7e:\n"
        "movl $1, (%esp)\n" /* line 434 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n"
        "movl %eax, (%esp)\n" /* line 437 */
        "calll CL_GetConfigString\n"
        "movl %eax, %edi\n"
        "cmpl $7, %ebx\n" /* line 440 */
        "je .Lf1e07d0_001e12d6\n"
        "cmpl $8, %ebx\n" /* line 444 */
        "je .Lf1e07d0_001e12e0\n"
        "cmpl $3, %ebx\n" /* line 448 */
        "je .Lf1e07d0_001e12ea\n"
        "testl %ebx, %ebx\n" /* line 452 */
        "je .Lf1e07d0_001e12b1\n"
        "leal -0x8e(%ebx), %eax\n" /* line 456 */
        "cmpl $0xbf, %eax\n"
        "ja .Lf1e07d0_001e07fb\n"
        "movl imp_cgs, %eax\n" /* line 178 */
        "movl (%eax), %eax\n"
        "movl 0x5ea0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1e07d0_001e08a3\n"
        "movl $0x8e, %esi\n"
        "jmp .Lf1e07d0_001e0b14\n"
        ".Lf1e07d0_001e0aee:\n"
        "leal 0x60(%esi), %eax\n" /* line 186 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, 4(%esp)\n" /* line 187 */
        "movl %ebx, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        "addl $1, %esi\n"
        "cmpl $0xee, %esi\n" /* line 181 */
        "je .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0b14:\n"
        "movl %esi, (%esp)\n" /* line 183 */
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n"
        "cmpb $0, (%eax)\n" /* line 184 */
        "jne .Lf1e07d0_001e0aee\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0b28:\n"
        "movl imp_cg, %esi\n" /* line 44 */
        "movl (%esi), %ebx\n"
        "movl $1, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af00(%ebx)\n"
        "cmpl $0x40, %eax\n" /* line 45 */
        "jle .Lf1e07d0_001e0b59\n"
        "movl $0x40, 0x2af00(%ebx)\n" /* line 46 */
        ".Lf1e07d0_001e0b59:\n"
        "leal 0x2af04(%ebx), %eax\n" /* line 48 */
        "movl $0, 0x2af04(%ebx)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $2, (%esp)\n" /* line 49 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af08(%ebx)\n"
        "movl $3, (%esp)\n" /* line 50 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af0c(%ebx)\n"
        "leal 0x2af34(%ebx), %eax\n" /* line 57 */
        "movl $0x600, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal 0x2af14(%ebx), %eax\n" /* line 58 */
        "movl $0, 0x2af14(%ebx)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "leal 0x2af24(%ebx), %eax\n" /* line 59 */
        "movl $0, 0x2af24(%ebx)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl 0x2af00(%ebx), %ecx\n" /* line 60 */
        "testl %ecx, %ecx\n"
        "jg .Lf1e07d0_001e0fbe\n"
        "movl imp_cg, %esi\n"
        "movl (%esi), %ecx\n"
        ".Lf1e07d0_001e0c30:\n"
        "xorl %ebx, %ebx\n"
        ".Lf1e07d0_001e0c32:\n"
        "movl 0x2af24(%ecx, %ebx, 4), %edx\n" /* line 96 */
        "testl %edx, %edx\n"
        "jle .Lf1e07d0_001e0fa7\n"
        "movl 0x2af14(%ecx, %ebx, 4), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1e07d0_001e0fa7\n"
        "movl %edx, %esi\n" /* line 99 */
        "cltd\n"
        "idivl %esi\n"
        "movl %eax, 0x2af14(%ecx, %ebx, 4)\n"
        ".Lf1e07d0_001e0c5c:\n"
        "addl $1, %ebx\n" /* line 94 */
        "cmpl $4, %ebx\n"
        "jne .Lf1e07d0_001e0c32\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0c69:\n"
        "movl $1, (%esp)\n" /* line 1216 */
        "calll CG_Argv\n"
        "leal -0x1b2(%ebp), %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $str_002b8238, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CG_TranslateHudElemMessage\n"
        "movl %ebx, (%esp)\n" /* line 1217 */
        "calll CG_BoldGameMessage\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0c9c:\n"
        "movl $1, (%esp)\n" /* line 1235 */
        "calll CG_Argv\n"
        "leal -0x1b2(%ebp), %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $str_002b8260, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CG_TranslateHudElemMessage\n"
        "movl %ebx, (%esp)\n" /* line 1236 */
        "calll CG_BoldGameMessage\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0ccf:\n"
        "movl imp_cg_teamChatsOnly, %eax\n" /* line 1240 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1243 */
        "calll CG_Argv\n"
        "movl $0, 8(%esp)\n"
        "movl $str_002b8274, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl $0x96, 8(%esp)\n" /* line 1245 */
        "movl %eax, 4(%esp)\n"
        "leal -0xb2(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        /* { scope 2 */
        "movzbl -0xb2(%ebp), %eax\n" /* line 990 */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e0fb7\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %edx\n"
        ".Lf1e07d0_001e0d31:\n"
        "cmpb $0x19, %al\n" /* line 992 */
        "je .Lf1e07d0_001e0d3f\n"
        "movb %al, -0xb2(%ebp, %ecx)\n" /* line 994 */
        "addl $1, %ecx\n"
        ".Lf1e07d0_001e0d3f:\n"
        "movzbl 1(%edx), %eax\n" /* line 990 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lf1e07d0_001e0d31\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1e07d0_001e0d4a:\n"
        "movl %ecx, %eax\n"
        ".Lf1e07d0_001e0d4c:\n"
        "movb $0, -0xb2(%ebp, %eax)\n" /* line 996 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1256 */
        "calll CG_AddToTeamChat\n"
        "movl %ebx, 4(%esp)\n" /* line 1257 */
        "movl $str_00215bbc, (%esp)\n"
        "calll Com_Printf\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0d70:\n"
        "movl $1, (%esp)\n" /* line 1252 */
        "calll CG_Argv\n"
        "movl $0, 8(%esp)\n"
        "movl $str_002b8284, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl $0x96, 8(%esp)\n" /* line 1254 */
        "movl %eax, 4(%esp)\n"
        "leal -0xb2(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        /* { scope 2 */
        "movzbl -0xb2(%ebp), %eax\n" /* line 990 */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e0fb7\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %edx\n"
        ".Lf1e07d0_001e0dc1:\n"
        "cmpb $0x19, %al\n" /* line 992 */
        "je .Lf1e07d0_001e0dcf\n"
        "movb %al, -0xb2(%ebp, %ecx)\n" /* line 994 */
        "addl $1, %ecx\n"
        ".Lf1e07d0_001e0dcf:\n"
        "movzbl 1(%edx), %eax\n" /* line 990 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lf1e07d0_001e0dc1\n"
        "jmp .Lf1e07d0_001e0d4a\n"
        /* } scope */
        ".Lf1e07d0_001e0ddf:\n"
        "calll CG_PlaySoundOnFirstClient\n" /* line 1265 */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1266 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll CL_PickSoundAlias\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SND_PlayMusicAlias\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0e15:\n"
        "calll CG_PlaySoundOnFirstClient\n" /* line 1270 */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1271 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%esp)\n"
        "calll SND_StopMusic\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0e43:\n"
        "calll CG_PlaySoundOnFirstClient\n" /* line 1275 */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e08a3\n"
        "movl $2, (%esp)\n" /* line 1276 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n"
        "movl $1, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x2e8(%ebp)\n"
        "movl %ebx, 4(%esp)\n"
        "cvtsd2ss -0x2e8(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll SND_FadeAllSounds\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0e9b:\n"
        "calll Cmd_Argc\n" /* line 1026 */
        "cmpl $6, %eax\n" /* line 1027 */
        "je .Lf1e07d0_001e1167\n"
        "movl %eax, 4(%esp)\n" /* line 1029 */
        "movl $str_002b8298, (%esp)\n"
        "calll Com_Printf\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0ebe:\n"
        "calll Cmd_Argc\n" /* line 1127 */
        "cmpl $2, %eax\n" /* line 1128 */
        "je .Lf1e07d0_001e1274\n"
        "movl %eax, 4(%esp)\n" /* line 1130 */
        "movl $str_002b82d0, (%esp)\n"
        "calll Com_Printf\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0ee1:\n"
        "movl $str_002adc84, (%esp)\n" /* line 808 */
        "calll CL_ClosePopup\n"
        "movl $str_002adc98, (%esp)\n" /* line 809 */
        "calll CL_ClosePopup\n"
        "movl imp_legacyHacks, %edx\n" /* line 812 */
        "movl (%edx), %eax\n"
        "movb $0, 0x1de(%eax)\n"
        "movl (%edx), %eax\n" /* line 813 */
        "movl $0xffffffff, 0x2e0(%eax)\n"
        "movl (%edx), %eax\n" /* line 814 */
        "movb $0, 0x2e4(%eax)\n"
        "movl (%edx), %eax\n" /* line 815 */
        "movl $0xffffffff, 0x3e4(%eax)\n"
        "movl (%edx), %eax\n" /* line 816 */
        "movb $0, 0x3e8(%eax)\n"
        "movl (%edx), %eax\n" /* line 817 */
        "movl $0xffffffff, 0x4e8(%eax)\n"
        "movl (%edx), %eax\n" /* line 818 */
        "movb $0, 0x4ec(%eax)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0f4c:\n"
        "calll CG_OpenScriptMenu\n" /* line 1300 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0f56:\n"
        "movl $1, (%esp)\n" /* line 1312 */
        "calll CG_Argv\n"
        "movl $0x96, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0xb2(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $2, (%esp)\n" /* line 1313 */
        "calll CG_Argv\n"
        "movl %eax, %edx\n"
        "movl %ebx, %eax\n"
        "calll CG_SetClientDvarFromServer\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0f96:\n"
        "movl $1, (%esp)\n" /* line 1261 */
        "calll CG_MapRestart\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0fa7:\n"
        "movl $0, 0x2af14(%ecx, %ebx, 4)\n" /* line 97 */
        "jmp .Lf1e07d0_001e0c5c\n"
        /* { scope 2 */
        ".Lf1e07d0_001e0fb7:\n"
        "xorl %eax, %eax\n" /* line 990 */
        "jmp .Lf1e07d0_001e0d4c\n"
        /* } scope */
        ".Lf1e07d0_001e0fbe:\n"
        "movl $0, -0x2e0(%ebp)\n" /* line 60 */
        "movl $4, %edi\n"
        "movl %esi, -0x2f0(%ebp)\n"
        "movl $0, -0x2f4(%ebp)\n"
        "jmp .Lf1e07d0_001e104f\n"
        ".Lf1e07d0_001e0fdf:\n"
        "movl 0xe0940(%eax), %eax\n" /* line 79 */
        ".Lf1e07d0_001e0fe5:\n"
        "movl -0x2f4(%ebp), %edx\n"
        "movl %eax, 0x2af44(%edx, %esi)\n"
        "movl -0x2f0(%ebp), %esi\n" /* line 81 */
        "movl (%esi), %ecx\n"
        "movl -0x2f4(%ebp), %edx\n"
        "addl %ecx, %edx\n"
        "movl 0x2af44(%edx), %eax\n"
        "addl $1, 0x2af24(%ecx, %eax, 4)\n"
        "movl 0x2af44(%edx), %ebx\n" /* line 82 */
        "movl 0x2af14(%ecx, %ebx, 4), %eax\n"
        "addl 0x2af3c(%edx), %eax\n"
        "movl %eax, 0x2af14(%ecx, %ebx, 4)\n"
        "addl $1, -0x2e0(%ebp)\n" /* line 60 */
        "addl $0x18, -0x2f4(%ebp)\n"
        "movl %ecx, %ebx\n"
        "addl $5, %edi\n"
        "movl -0x2e0(%ebp), %eax\n"
        "cmpl %eax, 0x2af00(%ecx)\n"
        "jle .Lf1e07d0_001e0c30\n"
        ".Lf1e07d0_001e104f:\n"
        "movl %edi, (%esp)\n" /* line 62 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl -0x2f4(%ebp), %edx\n"
        "movl %eax, 0x2af34(%edx, %ebx)\n"
        "movl imp_cg, %eax\n" /* line 63 */
        "movl (%eax), %esi\n"
        "leal 1(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl -0x2f4(%ebp), %ebx\n"
        "addl %esi, %ebx\n"
        "movl %eax, 0x2af38(%ebx)\n"
        "leal 2(%edi), %eax\n" /* line 64 */
        "movl %eax, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af3c(%ebx)\n"
        "leal 3(%edi), %eax\n" /* line 65 */
        "movl %eax, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af40(%ebx)\n"
        "leal 4(%edi), %eax\n" /* line 66 */
        "movl %eax, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %edx\n"
        "leal -1(%eax), %eax\n" /* line 68 */
        "cmpl $7, %eax\n"
        "jbe .Lf1e07d0_001e1141\n"
        ".Lf1e07d0_001e10e3:\n"
        "cmpl $0x3f, 0x2af34(%ebx)\n" /* line 74 */
        "jbe .Lf1e07d0_001e10f6\n"
        "movl $0, 0x2af34(%ebx)\n" /* line 75 */
        ".Lf1e07d0_001e10f6:\n"
        "movl 0x2af34(%ebx), %edx\n" /* line 77 */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0x2af38(%ebx), %edx\n"
        "movl %edx, 0xe0948(%esi, %eax, 8)\n"
        "movl 0x2af34(%ebx), %edx\n" /* line 79 */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%esi, %eax, 8), %eax\n"
        "movl 0xe0914(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1e07d0_001e0fdf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1e07d0_001e0fe5\n"
        ".Lf1e07d0_001e1141:\n"
        "leal 0x16(%edx), %eax\n" /* line 70 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl $7, 4(%esp)\n" /* line 71 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x2af48(%ebx)\n"
        "jmp .Lf1e07d0_001e10e3\n"
        ".Lf1e07d0_001e1167:\n"
        "movl $1, (%esp)\n" /* line 1033 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %esi\n"
        "movl $3, (%esp)\n" /* line 1034 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x2d8(%ebp)\n"
        "cvtsd2ss -0x2d8(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c0(%ebp)\n"
        "movl $4, (%esp)\n" /* line 1035 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x2d0(%ebp)\n"
        "cvtsd2ss -0x2d0(%ebp), %xmm0\n"
        "movss %xmm0, -0x2bc(%ebp)\n"
        "movl $5, (%esp)\n" /* line 1036 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x2c8(%ebp)\n"
        "movl $2, (%esp)\n" /* line 1037 */
        "calll CG_Argv\n"
        "movl %eax, %ebx\n"
        "cvtsd2ss -0x2c8(%ebp), %xmm0\n" /* line 428 */
        "mulss lit4_002ed5c8, %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x2ec(%ebp)\n"
        "cvttss2si -0x2ec(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "pxor %xmm1, %xmm1\n" /* line 45 */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1e07d0_001e12f4\n"
        "xorl %eax, %eax\n"
        ".Lf1e07d0_001e1243:\n"
        "movl %eax, 0x10(%esp)\n" /* line 1038 */
        "movss -0x2bc(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x2c0(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SND_SetEnvironmentEffects\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1274:\n"
        "movl $1, (%esp)\n" /* line 1134 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %edx\n"
        "leal -1(%eax), %eax\n" /* line 1135 */
        "cmpl $0xff, %eax\n"
        "jbe .Lf1e07d0_001e12bb\n"
        "movl $0x100, 8(%esp)\n" /* line 1137 */
        "movl %edx, 4(%esp)\n"
        "movl $str_002b8308, (%esp)\n"
        "calll Com_Printf\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12b1:\n"
        "calll CG_ParseServerinfo\n" /* line 454 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12bb:\n"
        "leal 0x24e(%edx), %eax\n" /* line 1140 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n" /* line 1141 */
        "calll CG_PlayClientSoundAliasByName\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12d6:\n"
        "calll CG_SetupWeaponDef\n" /* line 442 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12e0:\n"
        "calll CG_RegisterItems\n" /* line 446 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12ea:\n"
        "calll CG_StartAmbient\n" /* line 450 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12f4:\n"
        "cvttss2si %xmm2, %eax\n" /* line 45 */
        "jmp .Lf1e07d0_001e1243\n"
        ".Lf1e07d0_001e12fd:\n"
        "leal -0x17(%ebx), %eax\n" /* line 515 */
        "cmpl $7, %eax\n"
        "jbe .Lf1e07d0_001e14ec\n"
        "leal -0x1f(%ebx), %eax\n" /* line 519 */
        "cmpl $0xe, %eax\n"
        "jbe .Lf1e07d0_001e14cf\n"
        "leal -0x61e(%ebx), %eax\n" /* line 523 */
        "cmpl $0x7f, %eax\n"
        "jbe .Lf1e07d0_001e1509\n"
        "cmpl $0xb, %ebx\n" /* line 527 */
        "jne .Lf1e07d0_001e08a3\n"
        "calll CG_NorthDirectionChanged\n" /* line 529 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1337:\n"
        "movl imp_cgs, %eax\n" /* line 508 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll FX_RegisterEffect\n"
        "movl %eax, 0x67c0(%ebx, %esi, 4)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1352:\n"
        "movl imp_cgs, %eax\n" /* line 504 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll CL_RegisterModel\n"
        "movl %eax, 0x63c0(%ebx, %esi, 4)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e136d:\n"
        "movl $0, -0x2dc(%ebp)\n" /* line 494 */
        "xorl %esi, %esi\n"
        ".Lf1e07d0_001e1379:\n"
        "leal (%edi, %esi), %ebx\n" /* line 393 */
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll UI_GetMapDisplayNameFromPartialLoadNameMatch\n"
        "testl %eax, %eax\n" /* line 395 */
        "je .Lf1e07d0_001e13c0\n"
        "movzbl (%eax), %edx\n" /* line 401 */
        "testb %dl, %dl\n"
        "je .Lf1e07d0_001e13ba\n"
        "leal -0x2b2(%ebp), %ecx\n"
        "addl -0x2dc(%ebp), %ecx\n"
        "xorl %ebx, %ebx\n"
        ".Lf1e07d0_001e13a4:\n"
        "movb %dl, (%ecx)\n" /* line 403 */
        "addl $1, %ebx\n" /* line 405 */
        "movzbl (%ebx, %eax), %edx\n" /* line 401 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lf1e07d0_001e13a4\n"
        "addl %ebx, -0x2dc(%ebp)\n"
        ".Lf1e07d0_001e13ba:\n"
        "addl -0x1c(%ebp), %esi\n" /* line 408 */
        "leal (%esi, %edi), %ebx\n"
        ".Lf1e07d0_001e13c0:\n"
        "movzbl (%ebx), %eax\n" /* line 411 */
        "movl -0x2dc(%ebp), %edx\n"
        "movb %al, -0x2b2(%ebp, %edx)\n"
        "addl $1, %edx\n" /* line 412 */
        "movl %edx, -0x2dc(%ebp)\n"
        "cmpb $0, (%ebx)\n" /* line 414 */
        "je .Lf1e07d0_001e13e9\n"
        "addl $1, %esi\n" /* line 391 */
        "cmpl $0xff, %esi\n"
        "jle .Lf1e07d0_001e1379\n"
        ".Lf1e07d0_001e13e9:\n"
        "movb $0, -0x1b3(%ebp)\n" /* line 418 */
        "movl $0, 8(%esp)\n" /* line 420 */
        "movl $str_002a79f4, 4(%esp)\n"
        "leal -0x2b2(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl $0x100, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_cgs, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x6094, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1433:\n"
        "movl imp_cgs, %eax\n" /* line 492 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x6090(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e144d:\n"
        "movl imp_cgs, %eax\n" /* line 488 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x608c(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1467:\n"
        "movl imp_cgs, %eax\n" /* line 484 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x6088(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1481:\n"
        "movl imp_cgs, %eax\n" /* line 480 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x63b4(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e149b:\n"
        "movl imp_cgs, %eax\n" /* line 476 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x63bc(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e14b5:\n"
        "movl imp_cgs, %eax\n" /* line 472 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x63b8(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e14cf:\n"
        "movl %ebx, (%esp)\n" /* line 521 */
        "calll CL_GetConfigString\n"
        "movl $7, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterial\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e14ec:\n"
        "movl %ebx, (%esp)\n" /* line 517 */
        "calll CL_GetConfigString\n"
        "movl $7, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1509:\n"
        "movl %ebx, (%esp)\n" /* line 343 */
        "calll CL_GetConfigString\n"
        "cmpb $0, (%eax)\n" /* line 344 */
        "je .Lf1e07d0_001e08a3\n"
        "movl $7, 4(%esp)\n" /* line 347 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e152f:\n"
        "calll CG_ParseFog\n" /* line 500 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_1e07d0_0:\n"
        ".long .Lf1e07d0_001e08a3\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e0a6d\n"
        ".long .Lf1e07d0_001e0957\n"
        ".long .Lf1e07d0_001e0994\n"
        ".long .Lf1e07d0_001e099e\n"
        ".long .Lf1e07d0_001e09a8\n"
        ".long .Lf1e07d0_001e09b2\n"
        ".long .Lf1e07d0_001e09d9\n"
        ".long .Lf1e07d0_001e0a00\n"
        ".long .Lf1e07d0_001e0a21\n"
        ".long .Lf1e07d0_001e0a42\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e0a4c\n"
        ".long .Lf1e07d0_001e0b28\n"
        ".long .Lf1e07d0_001e0c69\n"
        ".long .Lf1e07d0_001e0a7e\n"
        ".long .Lf1e07d0_001e0924\n"
        ".long .Lf1e07d0_001e0924\n"
        ".long .Lf1e07d0_001e0c9c\n"
        ".long .Lf1e07d0_001e0ccf\n"
        ".long .Lf1e07d0_001e0d70\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e08ae\n"
        ".long .Lf1e07d0_001e0f96\n"
        ".long .Lf1e07d0_001e0ddf\n"
        ".long .Lf1e07d0_001e0e15\n"
        ".long .Lf1e07d0_001e0e43\n"
        ".long .Lf1e07d0_001e0e9b\n"
        ".long .Lf1e07d0_001e0ebe\n"
        ".long .Lf1e07d0_001e0f4c\n"
        ".long .Lf1e07d0_001e0ee1\n"
        ".long .Lf1e07d0_001e0f56\n"
        ".text\n"
    );
}

/* line 1380 */
void CG_ExecuteNewServerCommands(int latestSequence)
{
    char *cgs;

    cgs = CGS_PTR;

    while (*(int *)(cgs + 0x5e98) < latestSequence) {
        *(int *)(cgs + 0x5e98) += 1;
        if (CL_GetServerCommand(*(int *)(cgs + 0x5e98))) {
            CG_ServerCommand();
        }
    }
}
