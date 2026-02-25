/* ASM dump from: GameMain.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/GameMain.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Main/GameMain.h"
 */

static CCallOfDutyEngine theGameEngine; /* 0xceb420 */

CMacGameEngine * GetMacGameEngine(void);
void CCallOfDutyEngine_WaitForParentToQuit(const CCallOfDutyEngine * _this);
void CCallOfDutyEngine_MacMain(const CCallOfDutyEngine * _this);
static void __tcf_0(void);
Boolean CCallOfDutyEngine_Initialize(const CCallOfDutyEngine * _this);
void CCallOfDutyEngine_GameMain(const CCallOfDutyEngine * _this);
void ZN17CCallOfDutyEngineD1Ev(void); /* CCallOfDutyEngine_~CCallOfDutyEngine */
void ZN17CCallOfDutyEngineD0Ev(void); /* CCallOfDutyEngine_~CCallOfDutyEngine */

/* line 26 */
__attribute__((naked))
CMacGameEngine * GetMacGameEngine(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 26 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "cmpb $0, __ZGVZ16GetMacGameEnginevE13theGameEngine\n" /* line 28 */
        "je .Lf11251c_00112537\n"
        /* } scope */
        ".Lf11251c_0011252c:\n"
        "movl $theGameEngine, %eax\n" /* line 30 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf11251c_00112537:\n"
        "movl $__ZGVZ16GetMacGameEnginevE13theGameEngine, (%esp)\n" /* line 28 */
        "calll ___cxa_guard_acquire\n"
        "testl %eax, %eax\n"
        "je .Lf11251c_0011252c\n"
        "movl $theGameEngine, (%esp)\n" /* line 21 */
        "calll CMacGameEngine_CMacGameEngine\n"
        "movl $0x332228, theGameEngine\n"
        "movl $__ZGVZ16GetMacGameEnginevE13theGameEngine, (%esp)\n" /* line 28 */
        "calll ___cxa_guard_release\n"
        "movl $__tcf_0, (%esp)\n"
        "calll atexit\n"
        /* } scope */
        "movl $theGameEngine, %eax\n" /* line 30 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        /* { scope 1 */
        "movl $__ZGVZ16GetMacGameEnginevE13theGameEngine, (%esp)\n" /* line 28 */
        "calll ___cxa_guard_abort\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 187 */
__attribute__((naked))
void CCallOfDutyEngine_WaitForParentToQuit(const CCallOfDutyEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 187 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1: endTime */
        "leal -0x10(%ebp), %ebx\n" /* line 204 | psn */
        "movl %ebx, 4(%esp)\n"
        "movl $0x43443253, (%esp)\n"
        "calll MacTools_FindApplicationPSN\n"
        "testb %al, %al\n" /* line 205 */
        "jne .Lf112596_001125ba\n"
        /* } scope */
        ".Lf112596_001125b4:\n"
        "addl $0x34, %esp\n" /* line 230 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: endTime */
        /* { scope 2 */
        ".Lf112596_001125ba:\n"
        "movl %ebx, (%esp)\n" /* line 208 */
        "calll MacTools_SendQuitAppleEvent\n"
        "calll GetCurrentEventTime\n" /* line 211 */
        "fstpl -0x20(%ebp)\n" /* endTime */
        "movsd -0x20(%ebp), %xmm0\n" /* endTime */
        "addsd 0x307d48, %xmm0\n" /* 6.0 */
        "movsd %xmm0, -0x20(%ebp)\n" /* endTime */
        "jmp .Lf112596_001125fe\n"
        ".Lf112596_001125de:\n"
        "movl %ebx, 4(%esp)\n" /* line 214 */
        "movl $0x43443253, (%esp)\n"
        "calll MacTools_FindApplicationPSN\n"
        "testb %al, %al\n" /* line 215 */
        "je .Lf112596_00112612\n"
        "movl $0x3e8, (%esp)\n" /* line 220 */
        "calll MacTools_Sleep\n"
        ".Lf112596_001125fe:\n"
        "calll GetCurrentEventTime\n" /* line 212 */
        "fstpl -0x28(%ebp)\n"
        "movsd -0x20(%ebp), %xmm0\n" /* endTime */
        "ucomisd -0x28(%ebp), %xmm0\n"
        "ja .Lf112596_001125de\n"
        ".Lf112596_00112612:\n"
        "movl %ebx, (%esp)\n" /* line 224 */
        "calll GetCurrentProcess\n"
        "testw %ax, %ax\n" /* line 225 */
        "jne .Lf112596_001125b4\n"
        "movl %ebx, (%esp)\n" /* line 227 */
        "calll SetFrontProcess\n"
        /* } scope */
        /* } scope */
        "addl $0x34, %esp\n" /* line 230 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 235 */
__attribute__((naked))
void CCallOfDutyEngine_MacMain(const CCallOfDutyEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 235 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 252 */
        "jmp CMacGameEngine_MacMain\n" /* line 251 */
    );
}

/* line 28 */
static __attribute__((naked))
void __tcf_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 28 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x332228, theGameEngine\n" /* line 24 */
        "movl $theGameEngine, (%esp)\n"
        "calll ZN14CMacGameEngineD2Ev\n"
        "leave\n" /* line 28 */
        "retl\n"
    );
}

/* line 74 */
__attribute__((naked))
Boolean CCallOfDutyEngine_Initialize(const CCallOfDutyEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 74 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movl $0, 0x20(%ebx)\n" /* line 76 | this */
        "movl %ebx, (%esp)\n" /* line 78 | this */
        "calll CMacGameEngine_Initialize\n"
        "testb %al, %al\n"
        "jne .Lf112656_00112685\n"
        /* { scope 2 */
        /* { scope 3: temp */
        ".Lf112656_00112678:\n"
        "xorl %eax, %eax\n" /* line 160 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0xac, %esp\n" /* line 182 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf112656_00112685:\n"
        "movl %ebx, (%esp)\n" /* line 84 | this */
        "calll CCallOfDutyEngine_WaitForParentToQuit\n"
        "movl $0, 0xc(%esp)\n" /* line 91 */
        "movl $0x80, 8(%esp)\n"
        "leal -0xa2(%ebp), %eax\n" /* key */
        "movl %eax, 4(%esp)\n"
        "movl $0x21614c, (%esp)\n" /* "codkey" */
        "calll MacPreferences_GetString\n"
        "testb %al, %al\n"
        "je .Lf112656_001126d0\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0xa2(%ebp), %edi\n" /* key */
        "repne scasb %es:(%edi), %al\n"
        "cmpl $-0x16, %ecx\n"
        "je .Lf112656_001129b1\n"
        /* { scope 2 */
        ".Lf112656_001126d0:\n"
        "movl $0, 0xc(%esp)\n" /* line 93 */
        "movl $1, 8(%esp)\n"
        "movl $0x32e804, 4(%esp)\n"
        "movl $0x32e804, (%esp)\n"
        "calll MacBuilder_BuildWindow\n"
        "movl %eax, %ebx\n" /* theWindow */
        "testl %eax, %eax\n" /* line 94 */
        "je .Lf112656_001129b1\n"
        /* { scope 3: temp */
        "movl $4, 0xc(%esp)\n" /* line 105 */
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacBuilder_SetEditTextHook\n"
        "movl $4, 0xc(%esp)\n" /* line 106 */
        "movl $0, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_SetEditTextHook\n"
        "movl $4, 0xc(%esp)\n" /* line 107 */
        "movl $0, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_SetEditTextHook\n"
        "movl $4, 0xc(%esp)\n" /* line 108 */
        "movl $0, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_SetEditTextHook\n"
        "movl $4, 0xc(%esp)\n" /* line 109 */
        "movl $0, 8(%esp)\n"
        "movl $5, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_SetEditTextHook\n"
        "leal -0x1d(%ebp), %esi\n" /* temp */
        "jmp .Lf112656_001127b7\n"
        /* { scope 4: chs */
        ".Lf112656_001127a3:\n"
        "movl $0, 4(%esp)\n" /* line 155 */
        "movl $0x32e824, (%esp)\n"
        "calll MacTools_MessageAlertFromKey\n"
        ".Lf112656_001127b7:\n"
        "movl $1, 4(%esp)\n" /* line 114 */
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_SetControlFocus\n"
        "movl %ebx, (%esp)\n" /* line 116 | theWindow */
        "calll MacBuilder_RunModalWindow\n"
        "movl %eax, %edi\n" /* result */
        "cmpl $0x6f6b2020, %eax\n" /* line 117 */
        "jne .Lf112656_0011299d\n"
        "movl %esi, 0xc(%esp)\n" /* line 124 */
        "movl $5, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_GetControlText\n"
        "movl %esi, 4(%esp)\n" /* line 125 */
        "leal -0xa2(%ebp), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl %esi, 0xc(%esp)\n" /* line 127 */
        "movl $5, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_GetControlText\n"
        "movl %esi, 4(%esp)\n" /* line 128 */
        "leal -0xa2(%ebp), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll strcat\n"
        "movl %esi, 0xc(%esp)\n" /* line 130 */
        "movl $5, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_GetControlText\n"
        "movl %esi, 4(%esp)\n" /* line 131 */
        "leal -0xa2(%ebp), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll strcat\n"
        "movl %esi, 0xc(%esp)\n" /* line 133 */
        "movl $5, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_GetControlText\n"
        "movl %esi, 4(%esp)\n" /* line 134 */
        "leal -0xa2(%ebp), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll strcat\n"
        "movl %esi, 0xc(%esp)\n" /* line 136 */
        "movl $5, 8(%esp)\n"
        "movl $5, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* theWindow */
        "calll MacBuilder_GetControlText\n"
        "movl $0xffffffff, %edx\n" /* line 138 */
        "xorl %eax, %eax\n"
        "cld\n"
        "movl %edx, %ecx\n"
        "leal -0xa2(%ebp), %edi\n" /* key, result */
        "repne scasb %es:(%edi), %al\n" /* result */
        "cmpl $-0x12, %ecx\n"
        "jne .Lf112656_001127a3\n"
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n" /* result */
        "repne scasb %es:(%edi), %al\n" /* result */
        "cmpl $-6, %ecx\n"
        "jne .Lf112656_001127a3\n"
        "leal -0xa2(%ebp), %eax\n" /* line 140 | key */
        "movl %eax, (%esp)\n"
        "calll strupr\n"
        "movl %esi, (%esp)\n" /* line 141 */
        "calll strupr\n"
        "xorl %edx, %edx\n"
        "xorl %ecx, %ecx\n"
        /* { scope 5 */
        ".Lf112656_001128f4:\n"
        "movsbl -0xa2(%ecx, %ebp), %eax\n" /* line 51 */
        "xorl %eax, %edx\n"
        "movl $8, %eax\n"
        "jmp .Lf112656_00112912\n"
        ".Lf112656_00112905:\n"
        "shrl $1, %edx\n" /* line 56 */
        "xorl $0xa001, %edx\n"
        "subl $1, %eax\n" /* line 53 */
        "je .Lf112656_0011291e\n"
        ".Lf112656_00112912:\n"
        "testb $1, %dl\n" /* line 55 */
        "jne .Lf112656_00112905\n"
        "shrl $1, %edx\n" /* line 58 */
        "subl $1, %eax\n" /* line 53 */
        "jne .Lf112656_00112912\n"
        ".Lf112656_0011291e:\n"
        "addl $1, %ecx\n" /* line 49 */
        "cmpl $0x10, %ecx\n"
        "jne .Lf112656_001128f4\n"
        "movl %edx, 8(%esp)\n" /* line 62 */
        "movl $0x228f18, 4(%esp)\n" /* "%04x" */
        "leal -0x22(%ebp), %eax\n" /* chs */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "movl $4, 8(%esp)\n" /* line 64 */
        "movl %esi, 4(%esp)\n"
        "leal -0x22(%ebp), %eax\n" /* chs */
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 143 */
        "jne .Lf112656_001127a3\n"
        "movl %esi, 4(%esp)\n" /* line 145 */
        "leal -0xa2(%ebp), %eax\n" /* key */
        "movl %eax, (%esp)\n"
        "calll strcat\n"
        "leal -0xa2(%ebp), %eax\n" /* line 146 | key */
        "movl %eax, 4(%esp)\n"
        "movl $0x21614c, (%esp)\n" /* "codkey" */
        "calll MacPreferences_PutString\n"
        "movl $0, 4(%esp)\n" /* line 148 */
        "movl $0x32e814, (%esp)\n"
        "calll MacTools_MessageAlertFromKey\n"
        "movl $0x6f6b2020, %edi\n" /* result */
        /* } scope */
        ".Lf112656_0011299d:\n"
        "movl %ebx, (%esp)\n" /* line 158 | theWindow */
        "calll MacBuilder_ReleaseWindow\n"
        "cmpl $0x6f6b2020, %edi\n" /* line 160 | result */
        "jne .Lf112656_00112678\n"
        ".Lf112656_001129b1:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0xac, %esp\n" /* line 182 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 257 */
__attribute__((naked))
void CCallOfDutyEngine_GameMain(const CCallOfDutyEngine * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 257 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n" /* line 178 */
        "movl %eax, -0x2c(%ebp)\n"
        "addl $0xc, %eax\n" /* line 251 */
        "movl %eax, -0x20(%ebp)\n" /* commandLine */
        /* { scope 2 */
        "movl 4(%esi), %eax\n" /* line 261 | this */
        "testl %eax, %eax\n"
        "jle .Lf1129c2_00112a38\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1129c2_001129e5:\n"
        "leal (, %ebx, 4), %eax\n" /* line 263 */
        "addl 8(%esi), %eax\n" /* this */
        "movl (%eax), %edx\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* commandLine */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6appendEPKcm\n"
        "movl $1, 8(%esp)\n" /* line 813 */
        "movl $0x217914, 4(%esp)\n" /* " " */
        "leal -0x20(%ebp), %edi\n" /* commandLine */
        "movl %edi, (%esp)\n"
        "calll __ZNSs6appendEPKcm\n"
        "addl $1, %ebx\n" /* line 261 | i */
        "cmpl 4(%esi), %ebx\n" /* this, i */
        "jl .Lf1129c2_001129e5\n"
        /* } scope */
        ".Lf1129c2_00112a38:\n"
        "calll MacDisplay_GetMainWindow\n" /* line 282 */
        "movl %eax, (%esp)\n"
        "calll ShowWindow\n"
        "movl $1, 4(%esp)\n" /* line 285 */
        "movl %esi, (%esp)\n" /* this */
        "calll CMacGameEngine_SetIsRunning\n"
        "movl $0, 0xc(%esp)\n" /* line 289 */
        "movl -0x20(%ebp), %eax\n" /* commandLine */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll WinMain\n"
        "movl -0x20(%ebp), %eax\n" /* line 277 | commandLine */
        "leal -0xc(%eax), %ebx\n" /* i */
        "cmpl %ebx, -0x2c(%ebp)\n" /* line 224 */
        "jne .Lf1129c2_00112a8b\n"
        /* } scope */
        ".Lf1129c2_00112a83:\n"
        "addl $0x4c, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1129c2_00112a8b:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1129c2_00112a83\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1129c2_00112a83\n"
        "movl %eax, %ebx\n"
        "movl -0x20(%ebp), %eax\n" /* line 277 | commandLine */
        "leal -0xc(%eax), %esi\n" /* this */
        "cmpl %esi, -0x2c(%ebp)\n" /* line 224 */
        "jne .Lf1129c2_00112acc\n"
        ".Lf1129c2_00112ac0:\n"
        "movl %ebx, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "jmp .Lf1129c2_00112ac0\n"
        ".Lf1129c2_00112acc:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1129c2_00112ac0\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1129c2_00112ac0\n"
    );
}

/* line 24 */
__attribute__((naked))
void ZN17CCallOfDutyEngineD1Ev(void) /* CCallOfDutyEngine_~CCallOfDutyEngine */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 24 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x332228, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp ZN14CMacGameEngineD2Ev\n"
    );
}

/* line 24 */
__attribute__((naked))
void ZN17CCallOfDutyEngineD0Ev(void) /* CCallOfDutyEngine_~CCallOfDutyEngine */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 24 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x332228, (%ebx)\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll ZN14CMacGameEngineD2Ev\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

