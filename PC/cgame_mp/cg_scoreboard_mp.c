/* ASM dump from: cg_scoreboard_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_scoreboard_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

static int lastLeadTeam; /* 0x314640 */
static const listColumnInfo_t columnInfo[6]; /* 0x333b60 */

qboolean CG_ScoreboardDisplayed(void);
float CG_ScrollScoreboardUp(void);
float CG_ScrollScoreboardDown(void);
float CG_RegisterScoreboardGraphics(void);
int CalcBorderLines(sbpicinfo_t *backdropBorderLines);
float CG_DrawScoreboard_GetTeamColor(int team, vec_t *color);
static float CG_DrawClientScore(vec_t *color, float y, score_t *score, float listWidth, qboolean selection, int *piDrawLine, const int numDrawn);
static float CG_DrawScoreboard_ListBanner(float y, float w, float h);
static float CG_DrawScoreboard_ScoresList(float alpha);
qboolean CG_DrawScoreboard(void);

/* line 1392 */
qboolean CG_ScoreboardDisplayed(void)
{
    return *(int *)(*(int *)0x195f584 + 0x2b534);
}

/* line 1404 */
float CG_ScrollScoreboardUp(void)
{
    int *cg = (int *)*(int *)0x195f584;
    int scrollOffset = *(int *)((byte *)cg + 0x2b53c);
    if (scrollOffset > 0) {
        scrollOffset -= *(int *)(*(int *)0x195f754 + 8);
        *(int *)((byte *)cg + 0x2b53c) = scrollOffset;
        if (scrollOffset < 0)
            *(int *)((byte *)cg + 0x2b53c) = 0;
    }
    return 0;
}

/* line 1415 */
float CG_ScrollScoreboardDown(void)
{
    int *cg = (int *)*(int *)0x195f584;
    if (*(int *)((byte *)cg + 0x2b540) != 0) {
        int scrollOffset = *(int *)((byte *)cg + 0x2b53c);
        scrollOffset += *(int *)(*(int *)0x195f754 + 8);
        *(int *)((byte *)cg + 0x2b53c) = scrollOffset;
        int maxScroll = *(int *)((byte *)cg + 0x2af00) - 1;
        if (scrollOffset > maxScroll)
            *(int *)((byte *)cg + 0x2b53c) = maxScroll;
    }
    return 0;
}

/* line 1427 */
__attribute__((naked))
float CG_RegisterScoreboardGraphics(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1427 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $7, 4(%esp)\n" /* line 1431 */
        "movl $0x224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1432 */
        "movl $0x224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1433 */
        "movl $0x226ec8, (%esp)\n" /* "black" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1434 */
        "movl $0x224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1435 */
        "movl $0x224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1436 */
        "movl $0x226ec8, (%esp)\n" /* "black" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1438 */
        "movl $0x2b6834, (%esp)\n" /* "hudscoreboardscroll_uparrow" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1439 */
        "movl $0x2b6850, (%esp)\n" /* "hudscoreboardscroll_upkey" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1440 */
        "movl $0x2b686c, (%esp)\n" /* "hudscoreboardscroll_downarrow" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1441 */
        "movl $0x2b688c, (%esp)\n" /* "hudscoreboardscroll_downkey" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $0x2b4730, (%esp)\n" /* line 1443 */
        "calll Dvar_GetString\n"
        "movl $7, 4(%esp)\n" /* line 1444 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl $0x2b46e8, (%esp)\n" /* line 1446 */
        "calll Dvar_GetString\n"
        "movl $7, 4(%esp)\n" /* line 1447 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl $0x2b46c0, (%esp)\n" /* line 1448 */
        "calll Dvar_GetString\n"
        "movl $7, 4(%esp)\n" /* line 1449 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl $0x2b4708, (%esp)\n" /* line 1451 */
        "calll Dvar_GetString\n"
        "movl $7, 4(%esp)\n" /* line 1452 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1455 */
        "movl $0x2aa96c, (%esp)\n" /* "voice_on" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl $7, 4(%esp)\n" /* line 1456 */
        "movl $0x2b68a8, (%esp)\n" /* "voice_off" */
        "calll CL_RegisterMaterialNoMip\n"
        /* } scope */
        "leave\n" /* line 1458 */
        "retl\n"
    );
}

/* line 322 */
__attribute__((naked))
int CalcBorderLines(sbpicinfo_t *backdropBorderLines)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 322 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* backdropBorderLines */
        "movl $0x42f60000, %ecx\n" /* line 325 */
        "movl %ecx, (%edx)\n"
        "movl $0x41c80000, 4(%edx)\n" /* line 326 */
        "movl $0x43c50000, %esi\n" /* line 327 */
        "movl %esi, 8(%edx)\n"
        "movl $0x40000000, %ebx\n" /* line 328 */
        "movl %ebx, 0xc(%edx)\n"
        "leal 0x10(%edx), %eax\n" /* line 331 */
        "movl %ecx, 0x10(%edx)\n"
        "movl $0x43df8000, 4(%eax)\n" /* line 332 */
        "movl %esi, 8(%eax)\n" /* line 333 */
        "movl %ebx, 0xc(%eax)\n" /* line 334 */
        "leal 0x20(%edx), %eax\n" /* line 337 */
        "movl %ecx, 0x20(%edx)\n"
        "movl $0x41d80000, %esi\n" /* line 338 */
        "movl %esi, 4(%eax)\n"
        "movl %ebx, 8(%eax)\n" /* line 339 */
        "movl $0x43d20000, %ecx\n" /* line 340 */
        "movl %ecx, 0xc(%eax)\n"
        "leal 0x30(%edx), %eax\n" /* line 343 */
        "movl $0x4400c000, 0x30(%edx)\n"
        "movl %esi, 4(%eax)\n" /* line 344 */
        "movl %ebx, 8(%eax)\n" /* line 345 */
        "movl %ecx, 0xc(%eax)\n" /* line 346 */
        "leal 0x40(%edx), %eax\n" /* line 349 */
        "movl $0x42fa0000, %esi\n"
        "movl %esi, 0x40(%edx)\n"
        "movl $0x424c0000, 4(%eax)\n" /* line 350 */
        "movl $0x43c30000, %ebx\n" /* line 351 */
        "movl %ebx, 8(%eax)\n"
        "movl $0x3f800000, %ecx\n" /* line 352 */
        "movl %ecx, 0xc(%eax)\n"
        "leal 0x50(%edx), %eax\n" /* line 359 */
        "movl %esi, 0x50(%edx)\n"
        "movl $0x43d80000, 4(%eax)\n" /* line 360 */
        "movl %ebx, 8(%eax)\n" /* line 361 */
        "movl %ecx, 0xc(%eax)\n" /* line 362 */
        "movl $6, %eax\n" /* line 366 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 843 */
__attribute__((naked))
float CG_DrawScoreboard_GetTeamColor(int team, vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 843 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* team */
        "movl 0xc(%ebp), %edx\n" /* color */
        /* { scope 1 */
        "leal 0xc(%edx), %esi\n" /* line 847 */
        "movl 0xc(%edx), %ebx\n" /* savedAlpha */
        "cmpl $1, %eax\n" /* line 848 */
        "je .Lf1c2f74_001c2fa8\n"
        "cmpl $2, %eax\n"
        "je .Lf1c2f74_001c2fc1\n"
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, (%edx)\n"
        "movl %eax, 4(%edx)\n" /* line 192 */
        "movl %eax, 8(%edx)\n" /* line 193 */
        "movl %ebx, (%esi)\n" /* line 860 | savedAlpha */
        /* } scope */
        "addl $0x10, %esp\n" /* line 861 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c2f74_001c2fa8:\n"
        "movl %edx, 4(%esp)\n" /* line 851 */
        "movl $0x2addd4, (%esp)\n" /* "g_TeamColor_Axis" */
        "calll Dvar_GetUnpackedColorByName\n"
        "movl %ebx, (%esi)\n" /* line 860 | savedAlpha */
        /* } scope */
        "addl $0x10, %esp\n" /* line 861 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c2f74_001c2fc1:\n"
        "movl %edx, 4(%esp)\n" /* line 854 */
        "movl $0x2addc0, (%esp)\n" /* "g_TeamColor_Allies" */
        "calll Dvar_GetUnpackedColorByName\n"
        "movl %ebx, (%esi)\n" /* line 860 | savedAlpha */
        /* } scope */
        "addl $0x10, %esp\n" /* line 861 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 958 */
static __attribute__((naked))
float CG_DrawClientScore(vec_t *color, float y, score_t *score, float listWidth, qboolean selection, int *piDrawLine, const int numDrawn)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 958 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl %eax, -0x54(%ebp)\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movl %edx, -0x5c(%ebp)\n"
        "movss %xmm1, -0x60(%ebp)\n"
        "movl %ecx, %esi\n" /* highlight */
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 821 */
        "movl (%eax), %ebx\n"
        "movl 0x2b540(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1c2fda_001c31b0\n"
        "movl 0xc(%ebp), %edx\n" /* line 825 | piDrawLine */
        "movl (%edx), %eax\n"
        "cmpl 0x2b53c(%ebx), %eax\n"
        "jl .Lf1c2fda_001c31bb\n"
        "movss 0x2ed79c, %xmm0\n" /* line 832 | 12.0f */
        "addss -0x58(%ebp), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "ucomiss 0x2ed9bc, %xmm0\n" /* 432.0f */
        "ja .Lf1c2fda_001c31d0\n"
        "addl $1, %eax\n" /* line 838 */
        "movl 0xc(%ebp), %edx\n" /* piDrawLine */
        "movl %eax, (%edx)\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 979 */
        "movl (%ecx), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0900(%ebx, %eax, 8), %eax\n" /* adjustedStyle */
        "leal 0x14(%eax), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* ci */
        "movl 0x14(%eax), %edi\n" /* line 980 */
        "testl %edi, %edi\n"
        "je .Lf1c2fda_001c3490\n"
        "movl 0x2b544(%ebx), %ecx\n" /* line 983 | adjustedStyle */
        "testl %ecx, %ecx\n"
        "js .Lf1c2fda_001c34d8\n"
        ".Lf1c2fda_001c307d:\n"
        "movl 0x10(%ebp), %eax\n" /* line 985 | numDrawn */
        "movl %eax, 0x2b548(%ebx)\n" /* adjustedStyle */
        "movl -0x5c(%ebp), %edx\n" /* line 987 */
        "movl (%edx), %eax\n"
        "cmpl 4(%ebx), %eax\n" /* adjustedStyle */
        "je .Lf1c2fda_001c351a\n"
        "testl %esi, %esi\n" /* line 997 | string */
        "jne .Lf1c2fda_001c340c\n"
        ".Lf1c2fda_001c309c:\n"
        "movl $0x3e6147ae, 4(%esp)\n" /* line 1020 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x48(%ebp)\n" /* listFont */
        "movss 0x2ed9c0, %xmm0\n" /* 129.0f */
        "movss %xmm0, -0x50(%ebp)\n" /* x */
        "movl $columnInfo, %edi\n"
        "jmp .Lf1c2fda_001c3119\n"
        ".Lf1c2fda_001c30c7:\n"
        "cmpl $6, %eax\n" /* line 1042 */
        "je .Lf1c2fda_001c3327\n"
        "cmpl $2, %eax\n" /* line 1075 */
        "je .Lf1c2fda_001c3300\n"
        "jg .Lf1c2fda_001c31ea\n"
        "testl %eax, %eax\n"
        "jne .Lf1c2fda_001c31fc\n"
        "movl -0x4c(%ebp), %esi\n" /* line 1078 | ci, string */
        "addl $0xc, %esi\n" /* string */
        ".Lf1c2fda_001c30ed:\n"
        "cmpb $0, (%esi)\n" /* line 1102 | string */
        "jne .Lf1c2fda_001c3206\n"
        ".Lf1c2fda_001c30f6:\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 1124 */
        "mulss 4(%edi), %xmm0\n"
        "addss -0x50(%ebp), %xmm0\n" /* x */
        "movss %xmm0, -0x50(%ebp)\n" /* x */
        "addl $0x10, %edi\n"
        "cmpl $commandsList, %edi\n" /* line 1025 */
        "je .Lf1c2fda_001c31a6\n"
        ".Lf1c2fda_001c3119:\n"
        "movl (%edi), %eax\n" /* line 1027 */
        "cmpl $5, %eax\n"
        "jne .Lf1c2fda_001c30c7\n"
        "movl -0x5c(%ebp), %eax\n" /* line 1029 */
        "movl 0x14(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1c2fda_001c30f6\n"
        "pxor %xmm0, %xmm0\n" /* line 1031 */
        "cmpl $2, 0xc(%edi)\n"
        "je .Lf1c2fda_001c349a\n"
        ".Lf1c2fda_001c3138:\n"
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 191 | backColor */
        "movl $0x3f800000, -0x24(%ebp)\n" /* line 192 */
        "movl $0x3f800000, -0x20(%ebp)\n" /* line 193 */
        "movl -0x54(%ebp), %edx\n" /* line 1037 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 1038 */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* backColor */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x41500000, 0xc(%esp)\n"
        "movl $0x41500000, 8(%esp)\n"
        "movss -0x58(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "addss -0x50(%ebp), %xmm0\n" /* x */
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf1c2fda_001c30f6\n"
        ".Lf1c2fda_001c31a6:\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 1025 */
        "movss %xmm0, -0x58(%ebp)\n"
        /* } scope */
        ".Lf1c2fda_001c31b0:\n"
        "addl $0x8c, %esp\n" /* line 1128 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c2fda_001c31bb:\n"
        "addl $1, %eax\n" /* line 827 */
        "movl %eax, (%edx)\n"
        "movss -0x58(%ebp), %xmm0\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1128 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c2fda_001c31d0:\n"
        "movl $1, 0x2b540(%ebx)\n" /* line 834 */
        "movss -0x58(%ebp), %xmm0\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1128 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c2fda_001c31ea:\n"
        "cmpl $3, %eax\n" /* line 1075 */
        "je .Lf1c2fda_001c34b1\n"
        "cmpl $4, %eax\n"
        "je .Lf1c2fda_001c33ef\n"
        ".Lf1c2fda_001c31fc:\n"
        "movl $0x2157b8, %esi\n" /* line 1092 | string */
        "jmp .Lf1c2fda_001c30ed\n"
        ".Lf1c2fda_001c3206:\n"
        "movss 0x2ed9c4, %xmm0\n" /* line 1102 | 0.2199999988079071f */
        "movss %xmm0, -0x44(%ebp)\n" /* adjustedScale */
        "jmp .Lf1c2fda_001c322a\n"
        ".Lf1c2fda_001c3215:\n"
        "movss -0x44(%ebp), %xmm1\n" /* line 1107 | adjustedScale */
        "subss 0x2ed9ac, %xmm1\n" /* 0.019999999552965164f */
        "movss %xmm1, -0x44(%ebp)\n" /* adjustedScale */
        "movaps %xmm1, %xmm0\n"
        ".Lf1c2fda_001c322a:\n"
        "movss %xmm0, 0xc(%esp)\n" /* line 1106 */
        "movl -0x48(%ebp), %eax\n" /* listFont */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* string */
        "calll UI_TextWidth\n"
        "movss -0x60(%ebp), %xmm0\n"
        "mulss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "ucomiss -0x3c(%ebp), %xmm0\n"
        "ja .Lf1c2fda_001c3215\n"
        "movss 0x2ed7e0, %xmm0\n" /* line 1110 | 0.1599999964237213f */
        "xorl %ebx, %ebx\n" /* adjustedStyle */
        "ucomiss -0x44(%ebp), %xmm0\n" /* adjustedScale */
        "setbe %bl\n" /* adjustedStyle */
        "leal (%ebx, %ebx, 2), %ebx\n" /* adjustedStyle */
        "pxor %xmm1, %xmm1\n" /* line 1113 */
        "cmpl $2, 0xc(%edi)\n"
        "je .Lf1c2fda_001c34e6\n"
        ".Lf1c2fda_001c3282:\n"
        "movl $0x3f800000, -0x38(%ebp)\n" /* line 191 | textColor */
        "movl $0x3f800000, -0x34(%ebp)\n" /* line 192 */
        "movl $0x3f800000, -0x30(%ebp)\n" /* line 193 */
        "movl -0x54(%ebp), %edx\n" /* line 1119 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %ebx, 0x24(%esp)\n" /* line 1120 | adjustedStyle */
        "leal -0x38(%ebp), %eax\n" /* textColor */
        "movl %eax, 0x20(%esp)\n"
        "movss -0x44(%ebp), %xmm0\n" /* adjustedScale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "addss 0x2ed9c8, %xmm0\n" /* 10.079999923706055f */
        "movss %xmm0, 0x10(%esp)\n"
        "addss -0x50(%ebp), %xmm1\n" /* x */
        "movss %xmm1, 0xc(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* listFont */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* string */
        "calll UI_DrawText\n"
        "jmp .Lf1c2fda_001c30f6\n"
        ".Lf1c2fda_001c3300:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 1088 */
        "cmpl $3, 0x10(%eax)\n"
        "je .Lf1c2fda_001c31fc\n"
        "movl 4(%eax), %eax\n" /* line 1089 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, %esi\n" /* string */
        "jmp .Lf1c2fda_001c30ed\n"
        ".Lf1c2fda_001c3327:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 1044 */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_IsPlayerMuted\n"
        "testb %al, %al\n"
        "je .Lf1c2fda_001c33bf\n"
        "movl $7, 4(%esp)\n" /* line 1046 */
        "movl $0x2b68a8, (%esp)\n" /* "voice_off" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, %edx\n"
        ".Lf1c2fda_001c3352:\n"
        "testl %edx, %edx\n" /* line 1064 */
        "je .Lf1c2fda_001c30f6\n"
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 191 | backColor */
        "movl $0x3f800000, -0x24(%ebp)\n" /* line 192 */
        "movl $0x3f800000, -0x20(%ebp)\n" /* line 193 */
        "movl -0x54(%ebp), %ecx\n" /* line 1067 */
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edx, 0x1c(%esp)\n" /* line 1068 */
        "leal -0x28(%ebp), %eax\n" /* backColor */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x41500000, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x50(%ebp), %xmm1\n" /* x */
        "movss %xmm1, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf1c2fda_001c30f6\n"
        ".Lf1c2fda_001c33bf:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 1057 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_IsPlayerTalking\n"
        "testb %al, %al\n"
        "je .Lf1c2fda_001c30f6\n"
        "movl $7, 4(%esp)\n" /* line 1058 */
        "movl $0x2aa96c, (%esp)\n" /* "voice_on" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, %edx\n"
        "jmp .Lf1c2fda_001c3352\n"
        ".Lf1c2fda_001c33ef:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 1096 */
        "movl 8(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, %esi\n" /* string */
        "jmp .Lf1c2fda_001c30ed\n"
        ".Lf1c2fda_001c340c:\n"
        "movl $7, 4(%esp)\n" /* line 1002 */
        "movl $0x226ec8, (%esp)\n" /* "black" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl -0x54(%ebp), %ecx\n" /* line 199 */
        "movl (%ecx), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* backColor */
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, -0x24(%ebp)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, -0x20(%ebp)\n"
        "movss 0x2ed764, %xmm0\n" /* line 1004 | 0.15000000596046448f */
        ".Lf1c2fda_001c343c:\n"
        "mulss 0xc(%ecx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl %eax, 0x1c(%esp)\n" /* line 1005 */
        "leal -0x28(%ebp), %eax\n" /* backColor */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x41400000, 0xc(%esp)\n"
        "movss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x58(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl $0x43010000, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf1c2fda_001c309c\n"
        ".Lf1c2fda_001c3490:\n"
        "movss -0x58(%ebp), %xmm0\n"
        "jmp .Lf1c2fda_001c31b0\n"
        ".Lf1c2fda_001c349a:\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 1032 */
        "mulss 4(%edi), %xmm0\n"
        "subss 0x2ed8c0, %xmm0\n" /* 13.0f */
        "jmp .Lf1c2fda_001c3138\n"
        ".Lf1c2fda_001c34b1:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 1092 */
        "cmpl $3, 0x10(%ecx)\n"
        "je .Lf1c2fda_001c31fc\n"
        "movl 0xc(%ecx), %eax\n" /* line 1093 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, %esi\n" /* string */
        "jmp .Lf1c2fda_001c30ed\n"
        ".Lf1c2fda_001c34d8:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 984 | numDrawn */
        "movl %ecx, 0x2b544(%ebx)\n" /* adjustedStyle */
        "jmp .Lf1c2fda_001c307d\n"
        ".Lf1c2fda_001c34e6:\n"
        "movss -0x44(%ebp), %xmm1\n" /* line 1114 | adjustedScale */
        "movss %xmm1, 0xc(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* listFont */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* string */
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x3c(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "jmp .Lf1c2fda_001c3282\n"
        ".Lf1c2fda_001c351a:\n"
        "movl $7, 4(%esp)\n" /* line 992 */
        "movl $0x224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl -0x54(%ebp), %ecx\n" /* line 199 */
        "movl (%ecx), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* backColor */
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, -0x24(%ebp)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, -0x20(%ebp)\n"
        "movss 0x2ed724, %xmm0\n" /* line 994 | 0.20000000298023224f */
        "jmp .Lf1c2fda_001c343c\n"
    );
}

/* line 864 */
static __attribute__((naked))
float CG_DrawScoreboard_ListBanner(float y, float w, float h)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 864 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %ebx\n" /* color */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss %xmm1, -0x40(%ebp)\n"
        "movss %xmm2, -0x44(%ebp)\n"
        "movl %edx, %esi\n" /* team */
        /* { scope 1 */
        "movl 0x195f750, %eax\n" /* line 881 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 8(%eax), %xmm0\n" /* fLineHeight */
        /* { scope 2 */
        "movl 0x195f584, %eax\n" /* line 821 */
        "movl (%eax), %edx\n"
        "movl 0x2b540(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1c3550_001c3747\n"
        "movl (%ecx), %eax\n" /* line 825 */
        "cmpl 0x2b53c(%edx), %eax\n"
        "jl .Lf1c3550_001c3754\n"
        "addss -0x3c(%ebp), %xmm0\n" /* line 832 */
        "ucomiss 0x2ed9bc, %xmm0\n" /* 432.0f */
        "ja .Lf1c3550_001c3766\n"
        "addl $1, %eax\n" /* line 838 */
        "movl %eax, (%ecx)\n"
        /* } scope */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x28(%ebp)\n" /* teamColor */
        "movl %eax, -0x24(%ebp)\n" /* line 192 */
        "movl %eax, -0x20(%ebp)\n" /* line 193 */
        "movl 0xc(%ebx), %eax\n" /* line 885 | playersString */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x2af24(%edx, %esi, 4), %eax\n" /* line 887 */
        "cmpl $1, %eax\n" /* line 888 */
        "je .Lf1c3550_001c37f2\n"
        "movl %eax, 4(%esp)\n" /* line 891 */
        "movl $0x2b68e0, (%esp)\n" /* "CGAME_SB_PLAYERS%i" */
        ".Lf1c3550_001c35e1:\n"
        "calll va\n"
        "movl $0, 8(%esp)\n"
        "movl $0x2b68c8, 4(%esp)\n" /* "scoreboard banner text" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl %eax, %ebx\n" /* playersString */
        "cmpl $1, %esi\n" /* line 893 | team */
        "je .Lf1c3550_001c37c3\n"
        "cmpl $2, %esi\n" /* team */
        "je .Lf1c3550_001c392e\n"
        "testl %esi, %esi\n" /* team */
        "jne .Lf1c3550_001c377d\n"
        "movl $0x2b4708, (%esp)\n" /* line 896 */
        "calll Dvar_GetString\n"
        "movl %eax, %edi\n" /* bannerFont */
        "movl %ebx, -0x34(%ebp)\n" /* playersString, displayString */
        ".Lf1c3550_001c362b:\n"
        "movl $7, 4(%esp)\n" /* line 916 */
        "movl %edi, (%esp)\n" /* bannerFont */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x1c(%esp)\n" /* line 918 */
        "leal -0x28(%ebp), %eax\n" /* teamColor */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl $0x43010000, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movl $0x3ea3d70a, 4(%esp)\n" /* line 920 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %edi\n" /* bannerFont */
        /* { scope 2 */
        "movl -0x1c(%ebp), %ebx\n" /* line 847 | savedAlpha */
        "cmpl $1, %esi\n" /* line 848 */
        "je .Lf1c3550_001c3806\n"
        "cmpl $2, %esi\n"
        "je .Lf1c3550_001c3916\n"
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x28(%ebp)\n" /* teamColor */
        "movl %eax, -0x24(%ebp)\n" /* line 192 */
        "movl %eax, -0x20(%ebp)\n" /* line 193 */
        ".Lf1c3550_001c36bc:\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 860 | savedAlpha */
        /* } scope */
        "movl $3, 0x24(%esp)\n" /* line 923 */
        "leal -0x28(%ebp), %eax\n" /* teamColor */
        "movl %eax, 0x20(%esp)\n"
        "movl $0x3ea3d70a, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x195f750, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 8(%eax), %xmm0\n"
        "mulss 0x2ed9cc, %xmm0\n" /* 0.8399999737739563f */
        "addss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl $0x43050000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* bannerFont */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n" /* displayString */
        "movl %edx, (%esp)\n"
        "calll UI_DrawText\n"
        "leal -1(%esi), %eax\n" /* line 926 | team */
        "cmpl $1, %eax\n"
        "jbe .Lf1c3550_001c381e\n"
        ".Lf1c3550_001c3730:\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 954 */
        "addss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 955 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1c3550_001c3747:\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1c3550_001c3754:\n"
        "addl $1, %eax\n" /* line 827 */
        "movl %eax, (%ecx)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        /* } scope */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 955 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1c3550_001c3766:\n"
        "movl $1, 0x2b540(%edx)\n" /* line 834 */
        "movss -0x3c(%ebp), %xmm0\n"
        /* } scope */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 955 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c3550_001c377d:\n"
        "movl $0x2b4730, (%esp)\n" /* line 911 */
        "calll Dvar_GetString\n"
        "movl %eax, %edi\n" /* bannerFont */
        "movl $0, 8(%esp)\n" /* line 912 */
        "movl $0x2b68f4, 4(%esp)\n" /* "scoreboard team name" */
        "movl $0x2b690c, (%esp)\n" /* "CGAME_SPECTATORS" */
        ".Lf1c3550_001c37a2:\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl %ebx, 8(%esp)\n" /* playersString */
        "movl %eax, 4(%esp)\n"
        "movl $0x2aa8a8, (%esp)\n" /* "%s (%s)" */
        "calll va\n"
        "movl %eax, -0x34(%ebp)\n" /* displayString */
        "jmp .Lf1c3550_001c362b\n"
        ".Lf1c3550_001c37c3:\n"
        "movl $0x2b46e8, (%esp)\n" /* line 900 */
        "calll Dvar_GetString\n"
        "movl %eax, %edi\n" /* bannerFont */
        "movl $0x2b4760, (%esp)\n" /* line 901 */
        "calll Dvar_GetString\n"
        "movl $0, 8(%esp)\n" /* line 902 */
        "movl $0x2b68f4, 4(%esp)\n" /* "scoreboard team name" */
        "movl %eax, (%esp)\n"
        "jmp .Lf1c3550_001c37a2\n"
        ".Lf1c3550_001c37f2:\n"
        "movl $1, 4(%esp)\n" /* line 889 */
        "movl $0x2b68b4, (%esp)\n" /* "CGAME_SB_PLAYER%i" */
        "jmp .Lf1c3550_001c35e1\n"
        /* { scope 2 */
        ".Lf1c3550_001c3806:\n"
        "leal -0x28(%ebp), %eax\n" /* line 851 | teamColor */
        "movl %eax, 4(%esp)\n"
        "movl $0x2addd4, (%esp)\n" /* "g_TeamColor_Axis" */
        "calll Dvar_GetUnpackedColorByName\n"
        "jmp .Lf1c3550_001c36bc\n"
        /* } scope */
        ".Lf1c3550_001c381e:\n"
        "movss 0x2ed9c0, %xmm0\n" /* line 926 | 129.0f */
        "movss %xmm0, -0x38(%ebp)\n" /* x */
        "movl $columnInfo, %ebx\n" /* playersString */
        "jmp .Lf1c3550_001c385e\n"
        ".Lf1c3550_001c3832:\n"
        "cmpl $4, %eax\n" /* line 934 */
        "je .Lf1c3550_001c3902\n"
        ".Lf1c3550_001c383b:\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 950 */
        "mulss 4(%ebx), %xmm0\n" /* playersString */
        "addss -0x38(%ebp), %xmm0\n" /* x */
        "movss %xmm0, -0x38(%ebp)\n" /* x */
        "addl $0x10, %ebx\n" /* playersString */
        "cmpl $commandsList, %ebx\n" /* line 932 | playersString */
        "je .Lf1c3550_001c3730\n"
        ".Lf1c3550_001c385e:\n"
        "movl (%ebx), %eax\n" /* line 934 | playersString */
        "cmpl $2, %eax\n"
        "jne .Lf1c3550_001c3832\n"
        "movl 0x195f584, %edx\n" /* line 937 */
        "movl (%edx), %eax\n"
        "movl 0x2af04(%eax, %esi, 4), %eax\n"
        ".Lf1c3550_001c3874:\n"
        "movl %eax, 4(%esp)\n" /* line 941 */
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, -0x2c(%ebp)\n"
        "pxor %xmm1, %xmm1\n" /* line 942 */
        "cmpl $2, 0xc(%ebx)\n" /* playersString */
        "je .Lf1c3550_001c3960\n"
        ".Lf1c3550_001c3895:\n"
        "movl $3, 0x24(%esp)\n" /* line 947 */
        "leal -0x28(%ebp), %edx\n" /* teamColor */
        "movl %edx, 0x20(%esp)\n"
        "movl $0x3ea3d70a, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x195f750, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 8(%eax), %xmm0\n"
        "mulss 0x2ed9cc, %xmm0\n" /* 0.8399999737739563f */
        "addss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "addss -0x38(%ebp), %xmm1\n" /* x */
        "movss %xmm1, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* bannerFont */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "jmp .Lf1c3550_001c383b\n"
        ".Lf1c3550_001c3902:\n"
        "movl 0x195f584, %edx\n" /* line 939 */
        "movl (%edx), %eax\n"
        "movl 0x2af14(%eax, %esi, 4), %eax\n"
        "jmp .Lf1c3550_001c3874\n"
        /* { scope 2 */
        ".Lf1c3550_001c3916:\n"
        "leal -0x28(%ebp), %edx\n" /* line 854 | teamColor */
        "movl %edx, 4(%esp)\n"
        "movl $0x2addc0, (%esp)\n" /* "g_TeamColor_Allies" */
        "calll Dvar_GetUnpackedColorByName\n"
        "jmp .Lf1c3550_001c36bc\n"
        /* } scope */
        ".Lf1c3550_001c392e:\n"
        "movl $0x2b46c0, (%esp)\n" /* line 905 */
        "calll Dvar_GetString\n"
        "movl %eax, %edi\n" /* bannerFont */
        "movl $0x2b474c, (%esp)\n" /* line 906 */
        "calll Dvar_GetString\n"
        "movl $0, 8(%esp)\n" /* line 907 */
        "movl $0x2b68f4, 4(%esp)\n" /* "scoreboard team name" */
        "movl %eax, (%esp)\n"
        "jmp .Lf1c3550_001c37a2\n"
        ".Lf1c3550_001c3960:\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 943 */
        "mulss 4(%ebx), %xmm0\n" /* playersString */
        "movss %xmm0, -0x30(%ebp)\n"
        "movl $0x3ea3d70a, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* bannerFont */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x30(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "jmp .Lf1c3550_001c3895\n"
    );
}

/* line 1246 */
static __attribute__((naked))
float CG_DrawScoreboard_ScoresList(float alpha)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1246 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x21c, %esp\n"
        /* { scope 1: y, x, highlight, teamColor, ... */
        "movl 0x195f584, %eax\n" /* line 1262 */
        "movl %eax, -0x1a4(%ebp)\n"
        "movl (%eax), %esi\n" /* score */
        "movl $0, 0x2b540(%esi)\n" /* score */
        "movl $0xffffffff, 0x2b544(%esi)\n" /* line 1263 | score */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x2c(%ebp)\n" /* color */
        "movl %eax, -0x28(%ebp)\n" /* line 192 */
        "movl %eax, -0x24(%ebp)\n" /* line 193 */
        "movl 8(%ebp), %eax\n" /* line 1267 | alpha */
        "movl %eax, -0x20(%ebp)\n"
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        "cmpb $0, 0x2a9fc(%esi)\n" /* line 630 */
        "jne .Lf1c399e_001c3fc6\n"
        "movss 0x2ed9d0, %xmm2\n" /* 52.0f */
        "movl -0x1a4(%ebp), %eax\n"
        /* } scope */
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        ".Lf1c399e_001c39fa:\n"
        "movl (%eax), %edx\n" /* line 783 */
        "movl 0x2af28(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1c399e_001c3a14\n"
        "movl 0x2af2c(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1c399e_001c3f9a\n"
        ".Lf1c399e_001c3a14:\n"
        "movl 0x195f750, %ecx\n" /* line 785 */
        "movl (%ecx), %eax\n"
        "movl 8(%eax), %eax\n"
        "leal 8(%eax, %eax), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss 0x2ed6b4, %xmm1\n" /* 10.0f */
        "movl $2, -0x19c(%ebp)\n" /* totalLines */
        ".Lf1c399e_001c3a39:\n"
        "movl 0x2af24(%edx), %eax\n" /* line 789 */
        "testl %eax, %eax\n"
        "je .Lf1c399e_001c3a5a\n"
        "movl (%ecx), %eax\n" /* line 791 */
        "movl 8(%eax), %eax\n"
        "addl $4, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, -0x19c(%ebp)\n" /* line 792 | totalLines */
        ".Lf1c399e_001c3a5a:\n"
        "movl 0x2af30(%edx), %eax\n" /* line 795 */
        "testl %eax, %eax\n"
        "je .Lf1c399e_001c3a7b\n"
        "movl (%ecx), %eax\n" /* line 797 */
        "movl 8(%eax), %eax\n"
        "addl $4, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, -0x19c(%ebp)\n" /* line 798 | totalLines */
        ".Lf1c399e_001c3a7b:\n"
        "movl 0x2af00(%edx), %edx\n" /* line 802 */
        "testl %edx, %edx\n"
        "jle .Lf1c399e_001c3aa1\n"
        "xorl %eax, %eax\n"
        "movss 0x2ed79c, %xmm0\n" /* 12.0f */
        ".Lf1c399e_001c3a8f:\n"
        "addss %xmm0, %xmm1\n" /* line 804 */
        "addl $1, -0x19c(%ebp)\n" /* line 805 | totalLines */
        "addl $1, %eax\n" /* line 802 */
        "cmpl %edx, %eax\n"
        "jne .Lf1c399e_001c3a8f\n"
        /* } scope */
        ".Lf1c399e_001c3aa1:\n"
        "movss 0x2ed9bc, %xmm0\n" /* line 1272 | 432.0f */
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1c399e_001c3e6c\n"
        "movl $1, -0x18c(%ebp)\n" /* drawScrollBar */
        "movss 0x2ed9d8, %xmm0\n" /* 374.0f */
        "movss %xmm0, -0x194(%ebp)\n" /* listWidth */
        ".Lf1c399e_001c3ad0:\n"
        "movl (%ecx), %eax\n" /* line 1281 */
        "cvtsi2ssl 8(%eax), %xmm0\n"
        "divss 0x2ed67c, %xmm0\n" /* 0.75f */
        "movss %xmm0, -0x198(%ebp)\n" /* h */
        "addss 0x2ed608, %xmm2\n" /* line 1283 | 4.0f */
        "movss %xmm2, -0x15c(%ebp)\n"
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        "movl $0x3e99999a, 4(%esp)\n" /* line 750 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %edi\n" /* font */
        "movss 0x2ed9c0, %xmm1\n" /* 129.0f */
        "movss %xmm1, -0x180(%ebp)\n" /* x */
        "movl $0x333b68, %ebx\n" /* textStart */
        "jmp .Lf1c399e_001c3b50\n"
        ".Lf1c399e_001c3b24:\n"
        "movss -0x194(%ebp), %xmm0\n" /* line 767 | listWidth */
        "mulss -4(%ebx), %xmm0\n" /* textStart */
        "addss -0x180(%ebp), %xmm0\n" /* x */
        "movss %xmm0, -0x180(%ebp)\n" /* x */
        "addl $0x10, %ebx\n" /* textStart */
        "cmpl $0x333bc8, %ebx\n" /* line 754 | textStart */
        "je .Lf1c399e_001c3bd3\n"
        ".Lf1c399e_001c3b50:\n"
        "movl (%ebx), %eax\n" /* line 756 | textStart */
        "cmpb $0, (%eax)\n"
        "je .Lf1c399e_001c3b24\n"
        "movl %eax, (%esp)\n" /* line 758 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %esi\n" /* translation */
        "pxor %xmm1, %xmm1\n" /* line 759 */
        "cmpl $2, 4(%ebx)\n" /* textStart */
        "je .Lf1c399e_001c44ff\n"
        ".Lf1c399e_001c3b6f:\n"
        "movl $3, 0x24(%esp)\n" /* line 764 */
        "leal -0x2c(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "movl $0x3e99999a, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x15c(%ebp), %xmm0\n"
        "addss 0x2ed9e0, %xmm0\n" /* 11.75999927520752f */
        "movss %xmm0, 0x10(%esp)\n"
        "addss -0x180(%ebp), %xmm1\n" /* x */
        "movss %xmm1, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* font */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* translation */
        "calll UI_DrawText\n"
        "jmp .Lf1c399e_001c3b24\n"
        ".Lf1c399e_001c3bd3:\n"
        "movss -0x15c(%ebp), %xmm1\n" /* line 770 */
        "addss 0x2ed9e4, %xmm1\n" /* 14.0f */
        "movss %xmm1, -0x158(%ebp)\n"
        /* } scope */
        "movl $0, -0x1c(%ebp)\n" /* line 1287 | drawLine */
        "movl 0x195f584, %eax\n" /* line 1291 */
        "movl %eax, -0x1a4(%ebp)\n"
        "movl (%eax), %edx\n"
        "movl 0x2af28(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1c399e_001c3c17\n"
        "movl 0x2af2c(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1c399e_001c3ea4\n"
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        ".Lf1c399e_001c3c17:\n"
        "movl 0x2af0c(%edx), %eax\n" /* line 1295 */
        "cmpl %eax, 0x2af08(%edx)\n"
        "jle .Lf1c399e_001c3e8b\n"
        "movl $1, -0x1a0(%ebp)\n" /* team */
        "movl -0x1a0(%ebp), %eax\n" /* team */
        ".Lf1c399e_001c3c39:\n"
        "movl %eax, lastLeadTeam\n" /* line 1301 */
        "leal -0x1c(%ebp), %ecx\n" /* line 1303 | drawLine */
        "movl %eax, %edx\n"
        "movss -0x198(%ebp), %xmm2\n" /* h */
        "movss -0x194(%ebp), %xmm1\n" /* listWidth */
        "movss -0x158(%ebp), %xmm0\n"
        "leal -0x2c(%ebp), %eax\n" /* color */
        "calll CG_DrawScoreboard_ListBanner\n"
        "movss %xmm0, -0x150(%ebp)\n"
        /* { scope 3 */
        "cmpl $1, -0x1a0(%ebp)\n" /* line 848 | team */
        "je .Lf1c399e_001c46db\n"
        "cmpl $2, -0x1a0(%ebp)\n" /* team */
        "je .Lf1c399e_001c476a\n"
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x3c(%ebp)\n" /* borderColor */
        "movl %eax, -0x38(%ebp)\n" /* line 192 */
        "movl %eax, -0x34(%ebp)\n" /* line 193 */
        ".Lf1c399e_001c3c93:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1140 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x195f584, %edx\n" /* line 1144 */
        "movl %edx, -0x1a4(%ebp)\n"
        "movl (%edx), %ebx\n" /* textStart */
        "leal 0x2af34(%ebx), %esi\n" /* textStart, score */
        "movl 0x2af00(%ebx), %edi\n" /* line 1145 | textStart, i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf1c399e_001c3fb7\n"
        "movl $0, -0x17c(%ebp)\n" /* highlight */
        "xorl %edi, %edi\n" /* i */
        "movl $0, -0x190(%ebp)\n" /* numDrawn */
        "movl %edx, -0x1ac(%ebp)\n"
        ".Lf1c399e_001c3cd7:\n"
        "movl (%esi), %eax\n" /* line 1147 | score */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0xe0914(%ebx, %edx, 8), %ebx\n" /* textStart */
        "testl %ebx, %ebx\n" /* textStart */
        "je .Lf1c399e_001c3d00\n"
        "movl -0x1a0(%ebp), %eax\n" /* line 1149 | team */
        "cmpl 0x10(%esi), %eax\n" /* score */
        "je .Lf1c399e_001c4601\n"
        ".Lf1c399e_001c3d00:\n"
        "movl -0x1a4(%ebp), %eax\n"
        ".Lf1c399e_001c3d06:\n"
        "addl $1, %edi\n" /* line 1145 | i */
        "addl $0x18, %esi\n" /* score */
        "movl (%eax), %ebx\n" /* textStart */
        "cmpl %edi, 0x2af00(%ebx)\n" /* i, textStart */
        "jg .Lf1c399e_001c3cd7\n"
        /* } scope */
        ".Lf1c399e_001c3d16:\n"
        "xorl %eax, %eax\n" /* line 1306 */
        "cmpl $1, -0x1a0(%ebp)\n" /* team */
        "sete %al\n"
        "addl $1, %eax\n"
        "movl %eax, -0x14c(%ebp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 1312 | drawLine */
        "movl %eax, %edx\n"
        "movss -0x198(%ebp), %xmm2\n" /* h */
        "movss -0x194(%ebp), %xmm1\n" /* listWidth */
        "movss -0x150(%ebp), %xmm0\n"
        "addss 0x2ed608, %xmm0\n" /* 4.0f */
        "leal -0x2c(%ebp), %eax\n" /* color */
        "calll CG_DrawScoreboard_ListBanner\n"
        "movss %xmm0, -0x154(%ebp)\n"
        /* { scope 3 */
        "cmpl $1, -0x14c(%ebp)\n" /* line 848 */
        "je .Lf1c399e_001c46c3\n"
        "cmpl $2, -0x14c(%ebp)\n"
        "je .Lf1c399e_001c4752\n"
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x3c(%ebp)\n" /* borderColor */
        "movl %eax, -0x38(%ebp)\n" /* line 192 */
        "movl %eax, -0x34(%ebp)\n" /* line 193 */
        ".Lf1c399e_001c3d88:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1140 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x195f584, %edx\n" /* line 1144 */
        "movl %edx, -0x1a4(%ebp)\n"
        "movl (%edx), %ebx\n" /* textStart */
        "leal 0x2af34(%ebx), %esi\n" /* textStart, score */
        "movl 0x2af00(%ebx), %ecx\n" /* line 1145 | textStart */
        "testl %ecx, %ecx\n"
        "jle .Lf1c399e_001c3dfd\n"
        "movl $0, -0x178(%ebp)\n" /* highlight */
        "xorl %edi, %edi\n" /* i */
        "movl %edx, -0x1a8(%ebp)\n"
        ".Lf1c399e_001c3dbe:\n"
        "movl (%esi), %eax\n" /* line 1147 | score */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0xe0914(%ebx, %edx, 8), %eax\n" /* textStart */
        "testl %eax, %eax\n"
        "je .Lf1c399e_001c3de7\n"
        "movl -0x14c(%ebp), %eax\n" /* line 1149 */
        "cmpl 0x10(%esi), %eax\n" /* score */
        "je .Lf1c399e_001c4662\n"
        ".Lf1c399e_001c3de7:\n"
        "movl -0x1a4(%ebp), %eax\n"
        ".Lf1c399e_001c3ded:\n"
        "addl $1, %edi\n" /* line 1145 | i */
        "addl $0x18, %esi\n" /* score */
        "movl (%eax), %ebx\n" /* textStart */
        "cmpl %edi, 0x2af00(%ebx)\n" /* i, textStart */
        "jg .Lf1c399e_001c3dbe\n"
        /* } scope */
        ".Lf1c399e_001c3dfd:\n"
        "movss -0x154(%ebp), %xmm0\n" /* line 1314 */
        "addss 0x2ed608, %xmm0\n" /* 4.0f */
        /* } scope */
        "movl -0x1a4(%ebp), %edx\n" /* line 1317 */
        "movl (%edx), %ebx\n" /* textStart */
        "movl 0x2af24(%ebx), %eax\n" /* textStart */
        "testl %eax, %eax\n"
        "jne .Lf1c399e_001c3ec7\n"
        ".Lf1c399e_001c3e23:\n"
        "movl %edx, %eax\n"
        ".Lf1c399e_001c3e25:\n"
        "movl (%eax), %ebx\n" /* line 1325 | textStart */
        "movl 0x2af30(%ebx), %eax\n" /* textStart */
        "testl %eax, %eax\n"
        "jne .Lf1c399e_001c43c0\n"
        ".Lf1c399e_001c3e35:\n"
        "movl -0x18c(%ebp), %ecx\n" /* line 1332 | drawScrollBar */
        "testl %ecx, %ecx\n"
        "jne .Lf1c399e_001c4162\n"
        "movl -0x19c(%ebp), %edx\n" /* totalLines */
        ".Lf1c399e_001c3e49:\n"
        "movl 0x195f584, %eax\n" /* line 1335 */
        "movl (%eax), %eax\n"
        "subl $1, %edx\n"
        "cmpl %edx, 0x2b53c(%eax)\n"
        "jle .Lf1c399e_001c3e61\n"
        "movl %edx, 0x2b53c(%eax)\n" /* line 1336 */
        /* } scope */
        ".Lf1c399e_001c3e61:\n"
        "addl $0x21c, %esp\n" /* line 1344 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: y, x, highlight, teamColor, ... */
        ".Lf1c399e_001c3e6c:\n"
        "movl $0, -0x18c(%ebp)\n" /* line 1272 | drawScrollBar */
        "movss 0x2ed9dc, %xmm1\n" /* 382.0f */
        "movss %xmm1, -0x194(%ebp)\n" /* listWidth */
        "jmp .Lf1c399e_001c3ad0\n"
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        ".Lf1c399e_001c3e8b:\n"
        "jl .Lf1c399e_001c46f3\n" /* line 1297 */
        "movl lastLeadTeam, %edx\n" /* line 1300 */
        "movl %edx, -0x1a0(%ebp)\n" /* team */
        "movl %edx, %eax\n"
        "jmp .Lf1c399e_001c3c39\n"
        /* } scope */
        ".Lf1c399e_001c3ea4:\n"
        "movaps %xmm1, %xmm0\n" /* line 1291 */
        "movl $0, -0x190(%ebp)\n" /* numDrawn */
        "movl -0x1a4(%ebp), %edx\n" /* line 1317 */
        "movl (%edx), %ebx\n" /* textStart */
        "movl 0x2af24(%ebx), %eax\n" /* textStart */
        "testl %eax, %eax\n"
        "je .Lf1c399e_001c3e23\n"
        ".Lf1c399e_001c3ec7:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 1319 | color */
        "leal -0x1c(%ebp), %ecx\n" /* drawLine */
        "xorl %edx, %edx\n"
        "movss -0x198(%ebp), %xmm2\n" /* h */
        "movss -0x194(%ebp), %xmm1\n" /* listWidth */
        "calll CG_DrawScoreboard_ListBanner\n"
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x3c(%ebp)\n" /* borderColor */
        "movl %eax, -0x38(%ebp)\n" /* line 192 */
        "movl %eax, -0x34(%ebp)\n" /* line 193 */
        "movl -0x20(%ebp), %eax\n" /* line 1140 */
        "movl %eax, -0x30(%ebp)\n"
        "leal 0x2af34(%ebx), %esi\n" /* line 1144 | textStart, score */
        "movl 0x2af00(%ebx), %eax\n" /* line 1145 | textStart */
        "testl %eax, %eax\n"
        "jle .Lf1c399e_001c4733\n"
        "movl $0, -0x174(%ebp)\n" /* highlight */
        "xorl %edi, %edi\n" /* i */
        "jmp .Lf1c399e_001c3f39\n"
        ".Lf1c399e_001c3f1a:\n"
        "addl $1, %edi\n" /* i */
        "addl $0x18, %esi\n" /* score */
        "movl 0x195f584, %eax\n"
        "movl %eax, -0x1a4(%ebp)\n"
        "movl (%eax), %ebx\n" /* textStart */
        "cmpl %edi, 0x2af00(%ebx)\n" /* i, textStart */
        "jle .Lf1c399e_001c473f\n"
        ".Lf1c399e_001c3f39:\n"
        "movl (%esi), %eax\n" /* line 1147 | score */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0xe0914(%ebx, %edx, 8), %eax\n" /* textStart */
        "testl %eax, %eax\n"
        "je .Lf1c399e_001c3f1a\n"
        "movl 0x10(%esi), %eax\n" /* line 1149 | score */
        "testl %eax, %eax\n"
        "jne .Lf1c399e_001c3f1a\n"
        "movl -0x190(%ebp), %eax\n" /* line 1160 | numDrawn */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* drawLine */
        "movl %edx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl -0x174(%ebp), %ecx\n" /* highlight */
        "movss -0x194(%ebp), %xmm1\n" /* listWidth */
        "movl %esi, %edx\n" /* score */
        "leal -0x3c(%ebp), %eax\n" /* borderColor */
        "calll CG_DrawClientScore\n"
        "xorl $1, -0x174(%ebp)\n" /* line 1161 | highlight */
        "addl $1, -0x190(%ebp)\n" /* line 1163 | numDrawn */
        "jmp .Lf1c399e_001c3f1a\n"
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        ".Lf1c399e_001c3f9a:\n"
        "movss 0x2ed6b4, %xmm1\n" /* line 783 | 10.0f */
        "movl $0, -0x19c(%ebp)\n" /* totalLines */
        "movl 0x195f750, %ecx\n"
        "jmp .Lf1c399e_001c3a39\n"
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        ".Lf1c399e_001c3fb7:\n"
        "movl $0, -0x190(%ebp)\n" /* line 1145 | numDrawn */
        "jmp .Lf1c399e_001c3d16\n"
        /* } scope */
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        ".Lf1c399e_001c3fc6:\n"
        "movl $0x3e75c28f, 4(%esp)\n" /* line 635 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x184(%ebp)\n" /* objectiveFont */
        "leal -0x13c(%ebp), %ebx\n" /* line 637 | hudElemString, textStart */
        "movl %ebx, 8(%esp)\n" /* textStart */
        "movl $0x2b6920, 4(%esp)\n" /* "scoreboard objective info" */
        "leal 0x2a9fc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_TranslateHudElemMessage\n"
        "movl $0, -0x160(%ebp)\n"
        "movl %ebx, %edi\n" /* textStart */
        "movss 0x2ed9d4, %xmm1\n" /* 56.0f */
        "movss %xmm1, -0x188(%ebp)\n" /* y */
        ".Lf1c399e_001c401c:\n"
        "movl %ebx, %esi\n" /* textStart */
        ".Lf1c399e_001c401e:\n"
        "movzbl (%edi), %eax\n" /* line 643 */
        "cmpb $0x20, %al\n"
        "je .Lf1c399e_001c4096\n"
        "cmpb $0xa, %al\n" /* line 651 */
        "je .Lf1c399e_001c4131\n"
        "cmpb $0x5c, %al\n"
        "je .Lf1c399e_001c4153\n"
        ".Lf1c399e_001c4035:\n"
        "leal 1(%esi), %ebx\n" /* line 664 | textStart */
        "movzbl 1(%esi), %eax\n" /* line 665 */
        "testb %al, %al\n"
        "je .Lf1c399e_001c482f\n"
        "cmpb $0xa, %al\n" /* line 672 */
        "je .Lf1c399e_001c4490\n"
        "cmpb $0x5c, %al\n"
        "jne .Lf1c399e_001c405a\n"
        "cmpb $0x6e, 2(%esi)\n"
        "je .Lf1c399e_001c4490\n"
        ".Lf1c399e_001c405a:\n"
        "movl $0x3e75c28f, 0xc(%esp)\n" /* line 687 */
        "movl -0x184(%ebp), %eax\n" /* objectiveFont */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, %eax\n" /* textStart */
        "subl %edi, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "ucomiss 0x2ed9d8, %xmm0\n" /* 374.0f */
        "ja .Lf1c399e_001c40ba\n"
        "cmpb $0x20, (%ebx)\n" /* line 703 | textStart */
        "jne .Lf1c399e_001c401c\n"
        "movl %ebx, -0x160(%ebp)\n" /* textStart */
        "jmp .Lf1c399e_001c401c\n"
        ".Lf1c399e_001c4096:\n"
        "leal 1(%edi), %esi\n" /* line 645 */
        "movl %esi, %edi\n"
        ".Lf1c399e_001c409b:\n"
        "testl %edi, %edi\n" /* line 641 */
        "je .Lf1c399e_001c4545\n"
        "testl %esi, %esi\n"
        "je .Lf1c399e_001c4545\n"
        "movl $0, -0x160(%ebp)\n"
        "jmp .Lf1c399e_001c401e\n"
        ".Lf1c399e_001c40ba:\n"
        "movl $3, 0x24(%esp)\n" /* line 689 */
        "leal -0x2c(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movl $0x3e75c28f, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x188(%ebp), %xmm0\n" /* y */
        "addss 0x2ed9c8, %xmm0\n" /* 10.079999923706055f */
        "movss %xmm0, 0x10(%esp)\n"
        "movl $0x43010000, 0xc(%esp)\n"
        "movl -0x184(%ebp), %eax\n" /* objectiveFont */
        "movl %eax, 8(%esp)\n"
        "movl -0x160(%ebp), %eax\n"
        "subl %edi, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll UI_DrawText\n"
        "movl -0x160(%ebp), %edx\n" /* line 691 */
        "testl %edx, %edx\n"
        "je .Lf1c399e_001c4827\n"
        "movl -0x160(%ebp), %edi\n" /* line 692 */
        ".Lf1c399e_001c4131:\n"
        "addl $1, %edi\n"
        ".Lf1c399e_001c4134:\n"
        "movss -0x188(%ebp), %xmm0\n" /* line 699 | y */
        "addss 0x2ed79c, %xmm0\n" /* 12.0f */
        "movss %xmm0, -0x188(%ebp)\n" /* y */
        "movl %edi, %esi\n"
        "jmp .Lf1c399e_001c409b\n"
        ".Lf1c399e_001c4153:\n"
        "cmpb $0x6e, 1(%edi)\n" /* line 651 */
        "jne .Lf1c399e_001c4035\n"
        "addl $2, %edi\n" /* line 656 */
        "jmp .Lf1c399e_001c4134\n"
        /* } scope */
        /* } scope */
        ".Lf1c399e_001c4162:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1333 | drawLine */
        "movl %eax, -0x16c(%ebp)\n" /* drawLine */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        "movl -0x2c(%ebp), %eax\n" /* line 199 | color */
        "movl %eax, -0x3c(%ebp)\n" /* borderColor */
        "movl -0x28(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x34(%ebp)\n"
        "movl $7, 4(%esp)\n" /* line 1181 */
        "movl $0x226ec8, (%esp)\n" /* "black" */
        "calll CL_RegisterMaterialNoMip\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 1182 | 0.5f */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movss 0x2ed9bc, %xmm0\n" /* line 1186 | 432.0f */
        "subss -0x158(%ebp), %xmm0\n"
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movl %eax, 0x1c(%esp)\n" /* line 1187 */
        "leal -0x3c(%ebp), %edi\n" /* borderColor, i */
        "movl %edi, 0x18(%esp)\n" /* i */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x41000000, 8(%esp)\n"
        "movss -0x158(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl $0x43fc8000, (%esp)\n"
        "movss %xmm0, -0x1c8(%ebp)\n"
        "calll UI_DrawHandlePic\n"
        "movss 0x2ed5d0, %xmm2\n" /* line 1191 | 1.0f */
        "addss -0x158(%ebp), %xmm2\n"
        "movss -0x1c8(%ebp), %xmm0\n" /* line 1192 */
        "movaps %xmm0, %xmm3\n"
        "subss 0x2ed62c, %xmm3\n" /* 2.0f */
        "movl 0x195f584, %eax\n" /* line 1194 */
        "movl (%eax), %eax\n"
        "movl 0x2b53c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1c399e_001c4708\n"
        ".Lf1c399e_001c423e:\n"
        "movl -0x16c(%ebp), %edx\n" /* line 1197 | drawLine */
        "subl %eax, %edx\n"
        "cmpl $1, %edx\n"
        "jle .Lf1c399e_001c4268\n"
        "cmpl $1, -0x19c(%ebp)\n" /* totalLines */
        "jle .Lf1c399e_001c4268\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 1198 */
        "cvtsi2ssl -0x19c(%ebp), %xmm1\n" /* totalLines */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        ".Lf1c399e_001c4268:\n"
        "movl $7, 4(%esp)\n" /* line 1200 */
        "movl $0x224184, (%esp)\n" /* "white" */
        "movss %xmm2, -0x1d8(%ebp)\n"
        "movss %xmm3, -0x1e8(%ebp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movss 0x2ed604, %xmm0\n" /* line 1201 | 0.25f */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl %eax, 0x1c(%esp)\n" /* line 1202 */
        "movl %edi, 0x18(%esp)\n" /* i */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movss -0x1e8(%ebp), %xmm3\n"
        "movss %xmm3, 0xc(%esp)\n"
        "movl $0x40c00000, 8(%esp)\n"
        "movss -0x1d8(%ebp), %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl $0x43fd0000, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movl -0x20(%ebp), %eax\n" /* line 1204 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x195f584, %eax\n" /* line 1206 */
        "movl (%eax), %eax\n"
        "movl 0x2b53c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1c399e_001c43a7\n"
        "movl $7, 4(%esp)\n" /* line 1208 */
        "movl $0x2b6834, (%esp)\n" /* "hudscoreboardscroll_uparrow" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x1c(%esp)\n" /* line 1213 */
        "movl %edi, 0x18(%esp)\n" /* i */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x41800000, %ebx\n" /* textStart */
        "movl %ebx, 0xc(%esp)\n" /* textStart */
        "movl %ebx, 8(%esp)\n" /* textStart */
        "movss -0x158(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl $0x44024000, %esi\n" /* score */
        "movl %esi, (%esp)\n" /* score */
        "calll UI_DrawHandlePic\n"
        "movl $7, 4(%esp)\n" /* line 1216 */
        "movl $0x2b6850, (%esp)\n" /* "hudscoreboardscroll_upkey" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x1c(%esp)\n" /* line 1221 */
        "movl %edi, 0x18(%esp)\n" /* i */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* textStart */
        "movl %ebx, 8(%esp)\n" /* textStart */
        "movss -0x158(%ebp), %xmm1\n"
        "addss 0x2ed6c8, %xmm1\n" /* 18.0f */
        "movss %xmm1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* score */
        "calll UI_DrawHandlePic\n"
        ".Lf1c399e_001c43a7:\n"
        "movl -0x19c(%ebp), %eax\n" /* line 1225 | totalLines */
        "cmpl %eax, -0x16c(%ebp)\n" /* drawLine */
        "jl .Lf1c399e_001c4782\n"
        "movl %eax, %edx\n"
        "jmp .Lf1c399e_001c3e49\n"
        /* } scope */
        /* } scope */
        ".Lf1c399e_001c43c0:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 1327 | color */
        "leal -0x1c(%ebp), %ecx\n" /* drawLine */
        "movl $3, %edx\n"
        "movss -0x198(%ebp), %xmm2\n" /* h */
        "movss -0x194(%ebp), %xmm1\n" /* listWidth */
        "calll CG_DrawScoreboard_ListBanner\n"
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x3c(%ebp)\n" /* borderColor */
        "movl %eax, -0x38(%ebp)\n" /* line 192 */
        "movl %eax, -0x34(%ebp)\n" /* line 193 */
        "movl -0x20(%ebp), %eax\n" /* line 1140 */
        "movl %eax, -0x30(%ebp)\n"
        "leal 0x2af34(%ebx), %esi\n" /* line 1144 | textStart, score */
        "movl 0x2af00(%ebx), %edi\n" /* line 1145 | textStart, i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf1c399e_001c3e35\n"
        "movl $0, -0x170(%ebp)\n" /* highlight */
        "xorl %edi, %edi\n" /* i */
        "jmp .Lf1c399e_001c4430\n"
        ".Lf1c399e_001c4416:\n"
        "addl $1, %edi\n" /* i */
        "addl $0x18, %esi\n" /* score */
        "movl 0x195f584, %edx\n"
        "movl (%edx), %ebx\n" /* textStart */
        "cmpl %edi, 0x2af00(%ebx)\n" /* i, textStart */
        "jle .Lf1c399e_001c3e35\n"
        ".Lf1c399e_001c4430:\n"
        "movl (%esi), %eax\n" /* line 1147 | score */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0xe0914(%ebx, %edx, 8), %ebx\n" /* textStart */
        "testl %ebx, %ebx\n" /* textStart */
        "je .Lf1c399e_001c4416\n"
        "cmpl $3, 0x10(%esi)\n" /* line 1149 | score */
        "jne .Lf1c399e_001c4416\n"
        "movl -0x190(%ebp), %edx\n" /* line 1160 | numDrawn */
        "movl %edx, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* drawLine */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl -0x170(%ebp), %ecx\n" /* highlight */
        "movss -0x194(%ebp), %xmm1\n" /* listWidth */
        "movl %esi, %edx\n" /* score */
        "leal -0x3c(%ebp), %eax\n" /* borderColor */
        "calll CG_DrawClientScore\n"
        "xorl $1, -0x170(%ebp)\n" /* line 1161 | highlight */
        "addl $1, -0x190(%ebp)\n" /* line 1163 | numDrawn */
        "jmp .Lf1c399e_001c4416\n"
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        ".Lf1c399e_001c4490:\n"
        "movl $3, 0x24(%esp)\n" /* line 674 */
        "leal -0x2c(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "movl $0x3e75c28f, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x188(%ebp), %xmm0\n" /* y */
        "addss 0x2ed9c8, %xmm0\n" /* 10.079999923706055f */
        "movss %xmm0, 0x10(%esp)\n"
        "movl $0x43010000, 0xc(%esp)\n"
        "movl -0x184(%ebp), %edx\n" /* objectiveFont */
        "movl %edx, 8(%esp)\n"
        "subl %edi, %ebx\n" /* textStart */
        "movl %ebx, 4(%esp)\n" /* textStart */
        "movl %edi, (%esp)\n"
        "calll UI_DrawText\n"
        "cmpb $0xa, 1(%esi)\n" /* line 676 */
        "je .Lf1c399e_001c481f\n"
        "leal 3(%esi), %edi\n" /* line 679 */
        "jmp .Lf1c399e_001c4134\n"
        /* } scope */
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        ".Lf1c399e_001c44ff:\n"
        "movss -0x194(%ebp), %xmm0\n" /* line 760 | listWidth */
        "mulss -4(%ebx), %xmm0\n" /* textStart */
        "movss %xmm0, -0x164(%ebp)\n"
        "movl $0x3e99999a, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* font */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x164(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "jmp .Lf1c399e_001c3b6f\n"
        ".Lf1c399e_001c4545:\n"
        "movss -0x188(%ebp), %xmm1\n" /* y */
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        ".Lf1c399e_001c454d:\n"
        "addss 0x2ed62c, %xmm1\n" /* line 707 | 2.0f */
        "movss %xmm1, -0x168(%ebp)\n"
        "movl $7, 4(%esp)\n" /* line 713 */
        "movl $0x224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl -0x2c(%ebp), %edx\n" /* line 199 | color */
        "movl %edx, -0x3c(%ebp)\n" /* borderColor */
        "movl -0x28(%ebp), %edx\n" /* line 200 */
        "movl %edx, -0x38(%ebp)\n"
        "movl -0x24(%ebp), %edx\n" /* line 201 */
        "movl %edx, -0x34(%ebp)\n"
        "movss 0x2ed7d0, %xmm0\n" /* line 715 | 0.10000000149011612f */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl %eax, 0x1c(%esp)\n" /* line 716 */
        "leal -0x3c(%ebp), %eax\n" /* borderColor */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x3f800000, %ebx\n" /* textStart */
        "movl %ebx, 0xc(%esp)\n" /* textStart */
        "movl $0x43c30000, 8(%esp)\n"
        "movss -0x168(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl $0x42fa0000, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movl %ebx, -0x1ec(%ebp)\n" /* line 717 | textStart */
        "movss -0x1ec(%ebp), %xmm2\n"
        "addss -0x168(%ebp), %xmm2\n"
        "movl 0x195f584, %eax\n"
        "movl %eax, -0x1a4(%ebp)\n"
        "jmp .Lf1c399e_001c39fa\n"
        /* } scope */
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        ".Lf1c399e_001c4601:\n"
        "movl -0x190(%ebp), %edx\n" /* line 1160 | numDrawn */
        "movl %edx, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* drawLine */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl -0x17c(%ebp), %ecx\n" /* highlight */
        "movss -0x194(%ebp), %xmm1\n" /* listWidth */
        "movl %esi, %edx\n" /* score */
        "movss -0x150(%ebp), %xmm0\n"
        "leal -0x3c(%ebp), %eax\n" /* borderColor */
        "calll CG_DrawClientScore\n"
        "movss %xmm0, -0x150(%ebp)\n"
        "xorl $1, -0x17c(%ebp)\n" /* line 1161 | highlight */
        "addl $1, -0x190(%ebp)\n" /* line 1163 | numDrawn */
        "movl -0x1ac(%ebp), %edx\n"
        "movl %edx, -0x1a4(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf1c399e_001c3d06\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1c399e_001c4662:\n"
        "movl -0x190(%ebp), %edx\n" /* line 1160 | numDrawn */
        "movl %edx, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* drawLine */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl -0x178(%ebp), %ecx\n" /* highlight */
        "movss -0x194(%ebp), %xmm1\n" /* listWidth */
        "movl %esi, %edx\n" /* score */
        "movss -0x154(%ebp), %xmm0\n"
        "leal -0x3c(%ebp), %eax\n" /* borderColor */
        "calll CG_DrawClientScore\n"
        "movss %xmm0, -0x154(%ebp)\n"
        "xorl $1, -0x178(%ebp)\n" /* line 1161 | highlight */
        "addl $1, -0x190(%ebp)\n" /* line 1163 | numDrawn */
        "movl -0x1a8(%ebp), %edx\n"
        "movl %edx, -0x1a4(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf1c399e_001c3ded\n"
        ".Lf1c399e_001c46c3:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 851 | borderColor */
        "movl %eax, 4(%esp)\n"
        "movl $0x2addd4, (%esp)\n" /* "g_TeamColor_Axis" */
        "calll Dvar_GetUnpackedColorByName\n"
        "jmp .Lf1c399e_001c3d88\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1c399e_001c46db:\n"
        "leal -0x3c(%ebp), %eax\n" /* borderColor */
        "movl %eax, 4(%esp)\n"
        "movl $0x2addd4, (%esp)\n" /* "g_TeamColor_Axis" */
        "calll Dvar_GetUnpackedColorByName\n"
        "jmp .Lf1c399e_001c3c93\n"
        /* } scope */
        ".Lf1c399e_001c46f3:\n"
        "movl $2, -0x1a0(%ebp)\n" /* line 1297 | team */
        "movl -0x1a0(%ebp), %eax\n" /* team */
        "jmp .Lf1c399e_001c3c39\n"
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        ".Lf1c399e_001c4708:\n"
        "movl -0x19c(%ebp), %edx\n" /* line 1194 | totalLines */
        "testl %edx, %edx\n"
        "je .Lf1c399e_001c423e\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1195 */
        "cvtsi2ssl -0x19c(%ebp), %xmm1\n" /* totalLines */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "jmp .Lf1c399e_001c423e\n"
        ".Lf1c399e_001c4733:\n"
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x1a4(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf1c399e_001c473f:\n"
        "addss 0x2ed608, %xmm0\n" /* line 1321 | 4.0f */
        "movl -0x1a4(%ebp), %eax\n"
        "jmp .Lf1c399e_001c3e25\n"
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        ".Lf1c399e_001c4752:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 854 | borderColor */
        "movl %eax, 4(%esp)\n"
        "movl $0x2addc0, (%esp)\n" /* "g_TeamColor_Allies" */
        "calll Dvar_GetUnpackedColorByName\n"
        "jmp .Lf1c399e_001c3d88\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1c399e_001c476a:\n"
        "leal -0x3c(%ebp), %eax\n" /* borderColor */
        "movl %eax, 4(%esp)\n"
        "movl $0x2addc0, (%esp)\n" /* "g_TeamColor_Allies" */
        "calll Dvar_GetUnpackedColorByName\n"
        "jmp .Lf1c399e_001c3c93\n"
        /* } scope */
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        ".Lf1c399e_001c4782:\n"
        "movl $7, 4(%esp)\n" /* line 1227 */
        "movl $0x2b686c, (%esp)\n" /* "hudscoreboardscroll_downarrow" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x1c(%esp)\n" /* line 1232 */
        "movl %edi, 0x18(%esp)\n" /* i */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x41800000, %ebx\n" /* textStart */
        "movl %ebx, 0xc(%esp)\n" /* textStart */
        "movl %ebx, 8(%esp)\n" /* textStart */
        "movl $0x43cf8000, 4(%esp)\n"
        "movl $0x44024000, %esi\n" /* score */
        "movl %esi, (%esp)\n" /* score */
        "calll UI_DrawHandlePic\n"
        "movl $7, 4(%esp)\n" /* line 1235 */
        "movl $0x2b688c, (%esp)\n" /* "hudscoreboardscroll_downkey" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x1c(%esp)\n" /* line 1240 */
        "movl %edi, 0x18(%esp)\n" /* i */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* textStart */
        "movl %ebx, 8(%esp)\n" /* textStart */
        "movl $0x43c68000, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* score */
        "calll UI_DrawHandlePic\n"
        "movl -0x19c(%ebp), %edx\n" /* totalLines */
        "jmp .Lf1c399e_001c3e49\n"
        /* } scope */
        /* } scope */
        /* { scope 2: borderColor, objectiveFont, hudElemString, highlight, ... */
        /* { scope 3 */
        ".Lf1c399e_001c481f:\n"
        "leal 2(%esi), %edi\n" /* line 677 */
        "jmp .Lf1c399e_001c4134\n"
        ".Lf1c399e_001c4827:\n"
        "leal -1(%ebx), %edi\n" /* line 694 | textStart */
        "jmp .Lf1c399e_001c4134\n"
        ".Lf1c399e_001c482f:\n"
        "movl $3, 0x24(%esp)\n" /* line 667 */
        "leal -0x2c(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "movl $0x3e75c28f, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x188(%ebp), %xmm0\n" /* y */
        "addss 0x2ed9c8, %xmm0\n" /* 10.079999923706055f */
        "movss %xmm0, 0x10(%esp)\n"
        "movl $0x43010000, 0xc(%esp)\n"
        "movl -0x184(%ebp), %edx\n" /* objectiveFont */
        "movl %edx, 8(%esp)\n"
        "subl %edi, %ebx\n" /* textStart */
        "movl %ebx, 4(%esp)\n" /* textStart */
        "movl %edi, (%esp)\n"
        "calll UI_DrawText\n"
        "movss -0x188(%ebp), %xmm0\n" /* line 668 | y */
        "addss 0x2ed79c, %xmm0\n" /* 12.0f */
        "movss %xmm0, -0x188(%ebp)\n" /* y */
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf1c399e_001c454d\n"
    );
}

/* line 1347 */
__attribute__((naked))
qboolean CG_DrawScoreboard(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1347 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        /* { scope 1: color, material, borderLines, gameType, ... */
        "movl 0x195f74c, %eax\n" /* line 1352 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* mapLen */
        "testl %ebx, %ebx\n" /* mapLen */
        "jne .Lf1c48ac_001c503b\n"
        "movl 0x195f584, %esi\n" /* line 1395 | footerFont */
        "movl (%esi), %ebx\n" /* footerFont, mapLen */
        "movl 0x2b534(%ebx), %ecx\n" /* line 1355 | mapLen */
        "testl %ecx, %ecx\n"
        "je .Lf1c48ac_001c4faf\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0xb4(%ebp)\n" /* fade */
        "movss 0x2ed7f0, %xmm1\n" /* 0.800000011920929f */
        "movss %xmm1, -0x90(%ebp)\n"
        "movss 0x2ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "movss %xmm0, -0x8c(%ebp)\n"
        "movl (%esi), %edx\n" /* line 1378 | footerFont */
        "movl 0x25bb0(%edx), %ecx\n"
        "movl 0x2aefc(%edx), %eax\n"
        "addl $0x7d0, %eax\n"
        "cmpl %ecx, %eax\n"
        "jl .Lf1c48ac_001c5024\n"
        /* { scope 2: color, fontScale, mapBuffer, map */
        ".Lf1c48ac_001c492b:\n"
        "movl 0x195f58c, %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* color */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x20(%ebp)\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 435 */
        "movss %xmm1, -0x1c(%ebp)\n"
        "movl $7, 4(%esp)\n" /* line 437 */
        "movl $0x224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x1c(%esp)\n" /* line 440 */
        "leal -0x28(%ebp), %eax\n" /* color */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x43d70000, 0xc(%esp)\n"
        "movl $0x43c80000, 8(%esp)\n"
        "movl $0x41b00000, 4(%esp)\n"
        "movl $0x42f00000, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        /* } scope */
        /* { scope 2: color, fontScale, mapBuffer, map */
        "movl 0x195ed2c, %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* color */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x20(%ebp)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 465 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl $7, 4(%esp)\n" /* line 467 */
        "movl $0x224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, -0xb0(%ebp)\n" /* material */
        "leal -0x88(%ebp), %eax\n" /* line 469 | borderLines */
        "movl %eax, (%esp)\n"
        "calll CalcBorderLines\n"
        "movl %eax, %edi\n" /* numLines */
        "testl %eax, %eax\n" /* line 470 */
        "jg .Lf1c48ac_001c50dc\n"
        /* } scope */
        ".Lf1c48ac_001c49f8:\n"
        "movl 0x195f5c4, %eax\n" /* line 605 */
        "movl (%eax), %eax\n"
        "movl %eax, -0xb8(%ebp)\n"
        "addl $0x5ea4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetGameTypeDisplayName\n"
        "movl $0, 8(%esp)\n"
        "movl $0x2b693c, 4(%esp)\n" /* "scoreboard gametype display" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl %eax, -0xac(%ebp)\n" /* gameType */
        /* { scope 2: color, fontScale, mapBuffer, map */
        "movl 0x195ed2c, %eax\n" /* line 199 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n"
        "movss %xmm0, -0x28(%ebp)\n" /* color */
        "movss 4(%eax), %xmm1\n" /* line 200 */
        "movss %xmm1, -0xc0(%ebp)\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movl 8(%eax), %edi\n" /* line 201 */
        "movl %edi, -0x20(%ebp)\n"
        "movss -0xb4(%ebp), %xmm0\n" /* line 488 | fade */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl $0x3ed1eb85, %ebx\n" /* line 490 */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %esi\n" /* headerFont */
        "movl %ebx, 4(%esp)\n" /* line 493 */
        "movl %eax, (%esp)\n"
        "calll UI_TextHeight\n"
        "movl $3, 0x24(%esp)\n" /* line 494 */
        "leal -0x28(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x18, %edx\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss 0x2ed63c, %xmm0\n" /* -0.5f */
        "addss 0x2ed9ec, %xmm0\n" /* 51.0f */
        "movss %xmm0, 0x10(%esp)\n"
        "movl $0x43010000, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* headerFont */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0xac(%ebp), %eax\n" /* gameType */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        /* { scope 2: color, fontScale, mapBuffer, map */
        /* { scope 3 */
        "movss -0xbc(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x28(%ebp)\n" /* color */
        "movss -0xc0(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, -0x24(%ebp)\n"
        "movl %edi, -0x20(%ebp)\n" /* line 201 */
        "movss -0xb4(%ebp), %xmm0\n" /* line 515 | fade */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0xb8(%ebp), %ebx\n" /* line 519 | mapLen */
        "addl $0x5fc8, %ebx\n" /* mapLen */
        "movl %ebx, (%esp)\n" /* mapLen */
        "calll FS_GetMapBaseName\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetMapDisplayName\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x88(%ebp), %eax\n" /* borderLines */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "cmpb $0, -0x88(%ebp)\n" /* line 520 | borderLines */
        "je .Lf1c48ac_001c5081\n"
        ".Lf1c48ac_001c4b61:\n"
        "movl $4, 8(%esp)\n" /* line 528 */
        "movl $0x2b6958, 4(%esp)\n" /* "maps" */
        "leal -0x88(%ebp), %eax\n" /* borderLines */
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1c48ac_001c4b9a\n"
        "movzbl -0x84(%ebp), %eax\n"
        "cmpb $0x2f, %al\n"
        "je .Lf1c48ac_001c5062\n"
        "cmpb $0x5c, %al\n"
        "je .Lf1c48ac_001c5062\n"
        ".Lf1c48ac_001c4b9a:\n"
        "leal -0x88(%ebp), %edx\n" /* borderLines */
        "movl %edx, -0xa4(%ebp)\n" /* map */
        ".Lf1c48ac_001c4ba6:\n"
        "movl $2, 8(%esp)\n" /* line 530 */
        "movl $0x21cc10, 4(%esp)\n" /* "mp" */
        "movl %edx, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1c48ac_001c4bdc\n"
        "movl -0xa4(%ebp), %edx\n" /* map */
        "movzbl 2(%edx), %eax\n"
        "cmpb $0x2f, %al\n"
        "je .Lf1c48ac_001c5075\n"
        "cmpb $0x5c, %al\n"
        "je .Lf1c48ac_001c5075\n"
        ".Lf1c48ac_001c4bdc:\n"
        "movss 0x2ed9e8, %xmm0\n" /* line 531 | 0.4099999964237213f */
        "movss %xmm0, -0xa8(%ebp)\n" /* fontScale */
        "movl $0xe, %edi\n" /* numLines */
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf1c48ac_001c4bf9\n"
        ".Lf1c48ac_001c4bf6:\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf1c48ac_001c4bf9:\n"
        "movss %xmm1, 4(%esp)\n" /* line 536 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %esi\n" /* headerFont */
        "movss -0xa8(%ebp), %xmm0\n" /* line 537 | fontScale */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0xac(%ebp), %eax\n" /* gameType */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl %eax, %ebx\n" /* mapLen */
        "movss -0xa8(%ebp), %xmm0\n" /* fontScale */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* headerFont */
        "movl $0, 4(%esp)\n"
        "movl -0xa4(%ebp), %eax\n" /* map */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "leal 4(%ebx, %eax), %eax\n" /* mapLen */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed9f0, %xmm1\n" /* 386.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf1c48ac_001c5048\n"
        "movss -0xa8(%ebp), %xmm0\n" /* line 539 | fontScale */
        "subss 0x2ed9f4, %xmm0\n" /* 0.02500000037252903f */
        "movss %xmm0, -0xa8(%ebp)\n" /* fontScale */
        "subl $1, %edi\n" /* line 534 | numLines */
        "jne .Lf1c48ac_001c4bf6\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf1c48ac_001c4c9c:\n"
        "movss %xmm1, 0xc(%esp)\n" /* line 543 */
        "movl %esi, 8(%esp)\n" /* headerFont */
        "movl $0, 4(%esp)\n"
        "movl -0xa4(%ebp), %eax\n" /* map */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl %eax, %ebx\n" /* mapLen */
        "movss -0xa8(%ebp), %xmm0\n" /* line 544 | fontScale */
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* headerFont */
        "calll UI_TextHeight\n"
        "movl $3, 0x24(%esp)\n" /* line 545 */
        "leal -0x28(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movss -0xa8(%ebp), %xmm0\n" /* fontScale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x18, %edx\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss 0x2ed63c, %xmm0\n" /* -0.5f */
        "addss 0x2ed9ec, %xmm0\n" /* 51.0f */
        "movss %xmm0, 0x10(%esp)\n"
        "leal 4(%ebx), %eax\n" /* mapLen */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss 0x2ed9f8, %xmm0\n" /* 511.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* headerFont */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0xa4(%ebp), %eax\n" /* map */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        /* } scope */
        /* { scope 2: color, fontScale, mapBuffer, map */
        "movl 0x195ed2c, %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* color */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x20(%ebp)\n"
        "movss -0xb4(%ebp), %xmm0\n" /* line 567 | fade */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0x195f5c4, %eax\n" /* line 570 */
        "movl (%eax), %eax\n"
        "addl $0x5ec4, %eax\n"
        "movl %eax, -0x98(%ebp)\n" /* serverName */
        "calll CL_GetServerIPAddress\n" /* line 571 */
        "movl %eax, -0x94(%ebp)\n" /* serverIP */
        "movl $0x2b6960, 4(%esp)\n" /* line 572 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1c48ac_001c5130\n"
        ".Lf1c48ac_001c4dae:\n"
        "movss 0x2ed724, %xmm1\n" /* line 573 | 0.20000000298023224f */
        "movss %xmm1, -0x9c(%ebp)\n" /* fontScale */
        "movl $0xd, %edi\n" /* numLines */
        "movaps %xmm1, %xmm0\n"
        ".Lf1c48ac_001c4dc6:\n"
        "movss %xmm0, 4(%esp)\n" /* line 577 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %esi\n" /* footerFont */
        "movss -0x9c(%ebp), %xmm1\n" /* line 578 | fontScale */
        "movss %xmm1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x98(%ebp), %eax\n" /* serverName */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl %eax, %ebx\n" /* mapLen */
        "movss -0x9c(%ebp), %xmm0\n" /* fontScale */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* footerFont */
        "movl $0, 4(%esp)\n"
        "movl -0x94(%ebp), %eax\n" /* serverIP */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "leal 4(%ebx, %eax), %eax\n" /* mapLen */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed9f0, %xmm1\n" /* 386.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf1c48ac_001c5055\n"
        "movss -0x9c(%ebp), %xmm0\n" /* line 580 | fontScale */
        "subss 0x2ed738, %xmm0\n" /* 0.009999999776482582f */
        "movss %xmm0, -0x9c(%ebp)\n" /* fontScale */
        "subl $1, %edi\n" /* line 575 | numLines */
        "jne .Lf1c48ac_001c4dc6\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf1c48ac_001c4e69:\n"
        "movss %xmm1, 4(%esp)\n" /* line 584 */
        "movl %esi, (%esp)\n" /* footerFont */
        "calll UI_TextHeight\n"
        "movl $0xe, %edx\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "mulss 0x2ed63c, %xmm0\n" /* -0.5f */
        "addss 0x2ed9fc, %xmm0\n" /* 447.0f */
        "movss %xmm0, -0xa0(%ebp)\n" /* y */
        "movl $3, 0x24(%esp)\n" /* line 586 */
        "leal -0x28(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "movss -0x9c(%ebp), %xmm0\n" /* fontScale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0xa0(%ebp), %xmm1\n" /* y */
        "movss %xmm1, 0x10(%esp)\n"
        "movl $0x43010000, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* footerFont */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x98(%ebp), %eax\n" /* serverName */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movss -0x9c(%ebp), %xmm0\n" /* line 590 | fontScale */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* footerFont */
        "movl $0, 4(%esp)\n"
        "movl -0x94(%ebp), %eax\n" /* serverIP */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl $3, 0x24(%esp)\n" /* line 591 */
        "leal -0x28(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movss -0x9c(%ebp), %xmm0\n" /* fontScale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0xa0(%ebp), %xmm1\n" /* y */
        "movss %xmm1, 0x10(%esp)\n"
        "addl $4, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss 0x2ed9f8, %xmm0\n" /* 511.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* footerFont */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x94(%ebp), %eax\n" /* serverIP */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "movss -0xb4(%ebp), %xmm0\n" /* line 1386 | fade */
        "movss %xmm0, (%esp)\n"
        "calll CG_DrawScoreboard_ScoresList\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1c48ac_001c4fa4:\n"
        "addl $0xec, %esp\n" /* line 1389 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: color, material, borderLines, gameType, ... */
        ".Lf1c48ac_001c4faf:\n"
        "movl $0x64, 8(%esp)\n" /* line 1365 */
        "movl $0x64, 4(%esp)\n"
        "movl 0x2b538(%ebx), %eax\n" /* mapLen */
        "movl %eax, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 1368 */
        "je .Lf1c48ac_001c5147\n"
        "movss (%eax), %xmm1\n" /* line 1374 */
        "movss %xmm1, -0xb4(%ebp)\n" /* fade */
        "mulss 0x2ed7f0, %xmm1\n" /* 0.800000011920929f */
        "movss %xmm1, -0x90(%ebp)\n"
        "movss -0xb4(%ebp), %xmm0\n" /* fade */
        "mulss 0x2ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "movss %xmm0, -0x8c(%ebp)\n"
        "movl (%esi), %edx\n" /* line 1378 | footerFont */
        "movl 0x25bb0(%edx), %ecx\n"
        "movl 0x2aefc(%edx), %eax\n"
        "addl $0x7d0, %eax\n"
        "cmpl %ecx, %eax\n"
        "jge .Lf1c48ac_001c492b\n"
        ".Lf1c48ac_001c5024:\n"
        "movl %ecx, 0x2aefc(%edx)\n" /* line 1381 */
        "movl $0x2b3bec, (%esp)\n" /* line 1382 */
        "calll CL_AddReliableCommand\n"
        "jmp .Lf1c48ac_001c492b\n"
        ".Lf1c48ac_001c503b:\n"
        "xorl %eax, %eax\n" /* line 1352 */
        /* } scope */
        "addl $0xec, %esp\n" /* line 1389 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1c48ac_001c5048:\n"
        "movss -0xa8(%ebp), %xmm1\n" /* fontScale */
        "jmp .Lf1c48ac_001c4c9c\n"
        ".Lf1c48ac_001c5055:\n"
        "movss -0x9c(%ebp), %xmm1\n" /* fontScale */
        "jmp .Lf1c48ac_001c4e69\n"
        /* { scope 1: color, material, borderLines, gameType, ... */
        /* { scope 2: color, fontScale, mapBuffer, map */
        /* { scope 3 */
        ".Lf1c48ac_001c5062:\n"
        "leal -0x83(%ebp), %eax\n" /* line 528 */
        "movl %eax, -0xa4(%ebp)\n" /* map */
        "movl %eax, %edx\n"
        "jmp .Lf1c48ac_001c4ba6\n"
        ".Lf1c48ac_001c5075:\n"
        "addl $3, -0xa4(%ebp)\n" /* line 531 | map */
        "jmp .Lf1c48ac_001c4bdc\n"
        ".Lf1c48ac_001c5081:\n"
        "movl %ebx, 4(%esp)\n" /* line 522 | mapLen */
        "leal -0x88(%ebp), %edx\n" /* borderLines */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 523 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x88(%ebp), %edi\n" /* borderLines, numLines */
        "repne scasb %es:(%edi), %al\n" /* numLines */
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n" /* mapLen */
        "movl $3, 8(%esp)\n" /* line 524 */
        "movl $0x217ff4, 4(%esp)\n" /* "bsp" */
        "leal -0x8b(%ebp, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1c48ac_001c4b61\n"
        "movb $0, -0x8f(%ebp, %ebx)\n" /* line 525 */
        "jmp .Lf1c48ac_001c4b61\n"
        /* } scope */
        /* } scope */
        /* { scope 2: color, fontScale, mapBuffer, map */
        ".Lf1c48ac_001c50dc:\n"
        "xorl %esi, %esi\n" /* line 470 | lineIndex */
        "leal -0x7c(%ebp), %ebx\n"
        ".Lf1c48ac_001c50e1:\n"
        "movl -0xb0(%ebp), %edx\n" /* line 471 | material */
        "movl %edx, 0x1c(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* color */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -4(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -8(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xc(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "addl $1, %esi\n" /* line 470 | lineIndex */
        "addl $0x10, %ebx\n"
        "cmpl %esi, %edi\n" /* lineIndex, numLines */
        "jne .Lf1c48ac_001c50e1\n"
        "jmp .Lf1c48ac_001c49f8\n"
        /* } scope */
        /* { scope 2: color, fontScale, mapBuffer, map */
        ".Lf1c48ac_001c5130:\n"
        "movl $0x2b696c, (%esp)\n" /* line 573 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, -0x94(%ebp)\n" /* serverIP */
        "jmp .Lf1c48ac_001c4dae\n"
        /* } scope */
        ".Lf1c48ac_001c5147:\n"
        "movb $0, 0x2b54c(%ebx)\n" /* line 1371 | mapLen */
        "jmp .Lf1c48ac_001c4fa4\n"
    );
}

