/* ASM dump from: scr_compiler.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_compiler.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/script/scr_variable.h"
 */

extern struct scrCompilePub_t scrCompilePub; /* 0x0 */
extern void Z_FreeInternal(void *ptr);
static struct scrCompileGlob_t scrCompileGlob; /* scrCompileGlob */

static unsigned int LinkThread(unsigned int threadId, VariableUnion (*pos)[16]);
static unsigned int SpecifyThreadPosition(int type);
int CompareCaseInfo(const unsigned int *elem1, const unsigned int *elem2);
unsigned int Scr_CompileShutdown(void);
static unsigned int Scr_CalcLocalVarsVariableExpressionRef(void);
static Bool EvalPrimitiveExpression(void);
static Bool EvalBinaryOperatorExpression(sval_t opcode, sval_t sourcePos, VariableCompileValue *constValue);
static unsigned int Scr_CalcLocalVarsStatement(scr_block_t *block);
static unsigned int EmitValue(void);
static unsigned int EmitOpcode(unsigned int op, int offset, int callType);
static unsigned int EmitGetInteger(void);
static int Scr_FindLocalVarIndex(unsigned int name, sval_t sourcePos, Bool create, scr_block_t *block);
static unsigned int EmitContinueStatement(void);
static unsigned int EmitBreakStatement(void);
static unsigned int EmitFunction(sval_t sourcePos);
static unsigned int EmitCall(sval_t func_name, sval_t params, Bool bStatement, scr_block_t *block);
static Bool EmitOrEvalPrimitiveExpression(void);
static Bool EmitOrEvalExpression(void);
static unsigned int EmitPostFunctionCall(scr_block_t *block);
static unsigned int EmitMethod(sval_t expr, sval_t func_name, sval_t params, sval_t methodSourcePos, int bStatement, scr_block_t *block);
static unsigned int EmitPrimitiveExpressionFieldObject(void);
static unsigned int EmitVariableExpression(void);
static unsigned int EmitVariableExpressionRef(void);
static unsigned int EmitStatement(scr_block_t *block);
static unsigned int EmitIfStatement(sval_t stmt, int lastStatement, unsigned int endSourcePos, scr_block_t *block, sval_t *ifStatBlock);
static unsigned int EmitIfElseStatement(sval_t stmt1, sval_t stmt2, sval_t sourcePos, sval_t elseSourcePos, int lastStatement, unsigned int endSourcePos, scr_block_t *block, sval_t *ifStatBlock, sval_t *elseStatBlock);
static unsigned int EmitWhileStatement(sval_t expr, sval_t stmt, sval_t sourcePos, sval_t whileSourcePos, scr_block_t *block, sval_t *whileStatBlock);
static unsigned int EmitForStatement(sval_t expr, sval_t stmt2, sval_t stmt, sval_t sourcePos, sval_t forSourcePos, scr_block_t *block, sval_t *forStatBlock, sval_t *forStatPostBlock);
static unsigned int EmitSwitchStatement(sval_t sourcePos, int lastStatement, unsigned int endSourcePos, scr_block_t *block);
static unsigned int EmitThreadInternal(sval_t val, sval_t sourcePos, sval_t endSourcePos, scr_block_t *block);
unsigned int ScriptCompile(sval_t val, unsigned int fileId, unsigned int scriptId);
static unsigned int EmitDeveloperStatementList(sval_t val, scr_block_t *block, sval_t *devStatBlock);

/* line 2300 */
static __attribute__((naked))
unsigned int LinkThread(unsigned int threadId, VariableUnion (*pos)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2300 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl %ecx, %ebx\n" /* allowFarCall */
        /* { scope 1 */
        "movl $0, 4(%esp)\n" /* line 2309 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 2310 */
        "jne .Lf92666_00092693\n"
        /* } scope */
        ".Lf92666_0009268b:\n"
        "addl $0x2c, %esp\n" /* line 2349 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf92666_00092693:\n"
        "movl %eax, (%esp)\n" /* line 2313 */
        "calll Scr_EvalVariable\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 2316 */
        "testl %eax, %eax\n"
        "jle .Lf92666_0009268b\n"
        "xorl %esi, %esi\n" /* i */
        "testb %bl, %bl\n" /* valueId */
        "je .Lf92666_00092732\n"
        "jmp .Lf92666_000926c7\n"
        ".Lf92666_000926ae:\n"
        "testl %edx, %edx\n" /* line 2335 */
        "je .Lf92666_0009276a\n"
        ".Lf92666_000926b6:\n"
        "movl (%edi), %eax\n" /* value */
        "movl -0x24(%ebp), %ecx\n" /* line 2347 */
        "movl (%ecx), %edx\n"
        "movl %edx, (%eax)\n"
        "addl $1, %esi\n" /* line 2316 | i */
        "cmpl -0x1c(%ebp), %esi\n" /* i */
        "je .Lf92666_0009268b\n"
        ".Lf92666_000926c7:\n"
        "leal 2(%esi), %eax\n" /* line 2318 | i */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, %ebx\n" /* valueId */
        "movl %eax, (%esp)\n" /* line 2320 */
        "calll GetVariableValueAddress\n"
        "movl %eax, %edi\n" /* value */
        "movl %ebx, (%esp)\n" /* line 2321 | valueId */
        "calll GetVarType\n"
        "movl -0x24(%ebp), %ecx\n" /* line 2324 */
        "movl 4(%ecx), %edx\n"
        "cmpl $0xc, %edx\n"
        "jne .Lf92666_000926ae\n"
        "cmpl $7, %eax\n" /* line 2328 */
        "jne .Lf92666_000926b6\n"
        ".Lf92666_000926fd:\n"
        "movl $str_0021d718, 4(%esp)\n" /* line 2330 */
        "movl (%edi), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "calll CompileError2\n"
        "jmp .Lf92666_0009268b\n"
        ".Lf92666_00092714:\n"
        "testl %edx, %edx\n" /* line 2335 */
        "je .Lf92666_0009276a\n"
        ".Lf92666_00092718:\n"
        "movl (%edi), %eax\n" /* line 2341 | value */
        "cmpl $1, (%eax)\n"
        "je .Lf92666_00092781\n"
        "movl -0x24(%ebp), %ecx\n" /* line 2347 */
        "movl (%ecx), %edx\n"
        "movl %edx, (%eax)\n"
        "addl $1, %esi\n" /* line 2316 | i */
        "cmpl -0x1c(%ebp), %esi\n" /* i */
        "je .Lf92666_0009268b\n"
        ".Lf92666_00092732:\n"
        "leal 2(%esi), %eax\n" /* line 2318 | i */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, %ebx\n" /* valueId */
        "movl %eax, (%esp)\n" /* line 2320 */
        "calll GetVariableValueAddress\n"
        "movl %eax, %edi\n" /* value */
        "movl %ebx, (%esp)\n" /* line 2321 | valueId */
        "calll GetVarType\n"
        "movl -0x24(%ebp), %ecx\n" /* line 2324 */
        "movl 4(%ecx), %edx\n"
        "cmpl $0xc, %edx\n"
        "jne .Lf92666_00092714\n"
        "cmpl $7, %eax\n" /* line 2328 */
        "jne .Lf92666_00092718\n"
        "jmp .Lf92666_000926fd\n"
        ".Lf92666_0009276a:\n"
        "movl $str_0021d75c, 4(%esp)\n" /* line 2337 */
        "movl (%edi), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "calll CompileError2\n"
        "jmp .Lf92666_0009268b\n"
        ".Lf92666_00092781:\n"
        "movl $str_0021d75c, 4(%esp)\n" /* line 2343 */
        "movl %eax, (%esp)\n"
        "calll CompileError2\n"
        "jmp .Lf92666_0009268b\n"
    );
}

/* line 2390 */
static __attribute__((naked))
unsigned int SpecifyThreadPosition(int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2390 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %edx, %esi\n" /* name */
        "movl %ecx, %edi\n" /* sourcePos */
        /* { scope 1 */
        "movl $1, 4(%esp)\n" /* line 2396 */
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, %ebx\n" /* posId */
        "movl %eax, (%esp)\n" /* line 2397 */
        "calll Scr_EvalVariable\n"
        "movl %eax, -0x20(%ebp)\n" /* pos */
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2399 */
        "testl %eax, %eax\n"
        "je .Lf92796_00092814\n"
        "movl -0x20(%ebp), %eax\n" /* line 2401 | pos */
        "testl %eax, %eax\n"
        "je .Lf92796_0009283a\n"
        "movl %eax, (%esp)\n" /* line 2403 */
        "calll Scr_GetSourceBuffer\n"
        "movl imp_scrParserPub, %edx\n" /* line 2404 */
        "movl (%edx), %edx\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 4(%edx, %eax, 8), %ebx\n" /* posId */
        "movl %esi, (%esp)\n" /* name */
        "calll SL_ConvertToString\n"
        "movl %ebx, 0xc(%esp)\n" /* posId */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021d770, 4(%esp)\n" /* "function '%s' already defined in '%s'" */
        "movl %edi, (%esp)\n" /* sourcePos */
        "calll CompileError\n"
        "xorl %ebx, %ebx\n" /* posId */
        /* } scope */
        "movl %ebx, %eax\n" /* line 2418 | posId */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf92796_00092814:\n"
        "movl 8(%ebp), %eax\n" /* line 2413 | type */
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x20(%ebp)\n" /* line 2414 | pos */
        "leal -0x20(%ebp), %eax\n" /* line 2416 | pos */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* posId */
        "calll SetNewVariableValue\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 2418 | posId */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf92796_0009283a:\n"
        "movl %esi, (%esp)\n" /* line 2408 | name */
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021d798, 4(%esp)\n" /* "function '%s' already defined" */
        "movl %edi, (%esp)\n" /* sourcePos */
        "calll CompileError\n"
        "xorl %ebx, %ebx\n" /* posId */
        /* } scope */
        "movl %ebx, %eax\n" /* line 2418 | posId */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3973 */
int CompareCaseInfo(const unsigned int *elem1, const unsigned int *elem2)
{
    if (*elem1 > *elem2)
        return -1;
    return *elem1 < *elem2;
}

/* line 5088 */
unsigned int Scr_CompileShutdown(void)
{
    void *node;
    while ((node = *(void **)0x4ece58) != 0) {
        *(void **)0x4ece58 = *(void **)((char *)node + 8);
        Z_FreeInternal(node);
    }
    return 0;
}

/* line 2913 */
static __attribute__((naked))
unsigned int Scr_CalcLocalVarsVariableExpressionRef(void)
{
    __asm__ __volatile__ (
        ".Lf928ac_000928ac:\n"
        "pushl %ebp\n" /* line 2913 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %edx, %esi\n" /* block */
        "movl (%eax), %edx\n" /* line 2915 | expr */
        "cmpl $4, %edx\n"
        "je .Lf928ac_000928cb\n"
        "cmpl $0xd, %edx\n"
        "je .Lf928ac_00092910\n"
        ".Lf928ac_000928c3:\n"
        "addl $0x1c, %esp\n" /* line 2925 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf928ac_000928cb:\n"
        "movl 4(%eax), %ebx\n" /* line 2918 | expr */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 904 */
        "testl %eax, %eax\n"
        "jne .Lf928ac_000928c3\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf928ac_000928f7\n"
        "cmpl %ebx, 0x18(%esi)\n" /* line 909 */
        "je .Lf928ac_000928c3\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        "jmp .Lf928ac_000928f0\n"
        ".Lf928ac_000928e6:\n"
        "movl 0x1c(%ecx), %eax\n"
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "je .Lf928ac_000928c3\n"
        ".Lf928ac_000928f0:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edx, %edi\n"
        "jne .Lf928ac_000928e6\n"
        /* } scope */
        /* { scope 1 */
        ".Lf928ac_000928f7:\n"
        "cmpl $0x3f, %edi\n" /* line 894 */
        "jg .Lf928ac_00092a7a\n"
        ".Lf928ac_00092900:\n"
        "movl %ebx, 0x18(%esi, %edi, 4)\n" /* line 914 */
        "addl $1, 0xc(%esi)\n" /* line 918 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2925 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf928ac_00092910:\n"
        "movl 4(%eax), %ebx\n" /* line 2922 | expr */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf928ac_000928c3\n"
        "movl 4(%ebx), %eax\n" /* line 2952 | expr */
        "movl (%eax), %edx\n" /* line 2915 | expr */
        "cmpl $4, %edx\n"
        "je .Lf928ac_00092a39\n"
        "cmpl $0xd, %edx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 4(%eax), %ebx\n" /* line 2922 | expr */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf928ac_000928c3\n"
        "movl 4(%ebx), %eax\n" /* line 2952 | expr */
        "movl (%eax), %edx\n" /* line 2915 | expr */
        "cmpl $4, %edx\n"
        "je .Lf928ac_00092a96\n"
        "cmpl $0xd, %edx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 4(%eax), %ebx\n" /* line 2922 | expr */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf928ac_000928c3\n"
        "movl 4(%ebx), %eax\n" /* line 2952 | expr */
        "movl (%eax), %edx\n" /* line 2915 | expr */
        "cmpl $4, %edx\n"
        "je .Lf928ac_00092ad7\n"
        "cmpl $0xd, %edx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 4(%eax), %ebx\n" /* line 2922 | expr */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf928ac_000928c3\n"
        "movl 4(%ebx), %eax\n" /* line 2952 | expr */
        "movl (%eax), %edx\n" /* line 2915 | expr */
        "cmpl $4, %edx\n"
        "je .Lf928ac_00092c14\n"
        "cmpl $0xd, %edx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 4(%eax), %ebx\n" /* line 2922 | expr */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf928ac_000928c3\n"
        "movl 4(%ebx), %eax\n" /* line 2952 | expr */
        "movl (%eax), %edx\n" /* line 2915 | expr */
        "cmpl $4, %edx\n"
        "je .Lf928ac_00092bd5\n"
        "cmpl $0xd, %edx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 4(%eax), %ebx\n" /* line 2922 | expr */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf928ac_000928c3\n"
        "movl 4(%ebx), %eax\n" /* line 2952 | expr */
        "movl (%eax), %edx\n" /* line 2915 | expr */
        "cmpl $4, %edx\n"
        "je .Lf928ac_00092b96\n"
        "cmpl $0xd, %edx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 4(%eax), %ebx\n" /* line 2922 | expr */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf928ac_000928c3\n"
        "movl 4(%ebx), %eax\n" /* line 2952 | expr */
        "movl (%eax), %edx\n" /* line 2915 | expr */
        "cmpl $4, %edx\n"
        "je .Lf928ac_00092b57\n"
        "cmpl $0xd, %edx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 4(%eax), %ebx\n" /* line 2922 | expr */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf928ac_000928c3\n"
        "movl 4(%ebx), %eax\n" /* line 2952 | expr */
        "movl (%eax), %edx\n" /* line 2915 | expr */
        "cmpl $4, %edx\n"
        "je .Lf928ac_00092b18\n"
        "cmpl $0xd, %edx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 4(%eax), %ebx\n" /* line 2922 | expr */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf928ac_000928c3\n"
        "movl 4(%ebx), %eax\n" /* line 2952 | expr */
        "movl %esi, %edx\n" /* block */
        "addl $0x1c, %esp\n" /* line 2925 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Scr_CalcLocalVarsVariableExpressionRef\n" /* line 2952 */
        ".Lf928ac_00092a39:\n"
        "movl 4(%eax), %ebx\n" /* line 2918 | expr */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 904 */
        "testl %eax, %eax\n"
        "jne .Lf928ac_000928c3\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf928ac_000928f7\n"
        "cmpl %ebx, 0x18(%esi)\n" /* line 909 */
        "je .Lf928ac_000928c3\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        "jmp .Lf928ac_00092a6e\n"
        ".Lf928ac_00092a60:\n"
        "movl 0x1c(%ecx), %eax\n"
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "je .Lf928ac_000928c3\n"
        ".Lf928ac_00092a6e:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edx, %edi\n"
        "jne .Lf928ac_00092a60\n"
        "jmp .Lf928ac_000928f7\n"
        /* } scope */
        /* { scope 1 */
        ".Lf928ac_00092a7a:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%esi), %edi\n"
        "jmp .Lf928ac_00092900\n"
        /* } scope */
        ".Lf928ac_00092a96:\n"
        "movl 4(%eax), %ebx\n" /* line 2918 | expr */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 904 */
        "testl %eax, %eax\n"
        "jne .Lf928ac_000928c3\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf928ac_000928f7\n"
        "cmpl %ebx, 0x18(%esi)\n" /* line 909 */
        "je .Lf928ac_000928c3\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        "jmp .Lf928ac_00092acb\n"
        ".Lf928ac_00092abd:\n"
        "movl 0x1c(%ecx), %eax\n"
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "je .Lf928ac_000928c3\n"
        ".Lf928ac_00092acb:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edx, %edi\n"
        "jne .Lf928ac_00092abd\n"
        "jmp .Lf928ac_000928f7\n"
        /* } scope */
        ".Lf928ac_00092ad7:\n"
        "movl 4(%eax), %ebx\n" /* line 2918 | expr */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 904 */
        "testl %eax, %eax\n"
        "jne .Lf928ac_000928c3\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf928ac_000928f7\n"
        "cmpl %ebx, 0x18(%esi)\n" /* line 909 */
        "je .Lf928ac_000928c3\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        "jmp .Lf928ac_00092b0c\n"
        ".Lf928ac_00092afe:\n"
        "movl 0x1c(%ecx), %eax\n"
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "je .Lf928ac_000928c3\n"
        ".Lf928ac_00092b0c:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edx, %edi\n"
        "jne .Lf928ac_00092afe\n"
        "jmp .Lf928ac_000928f7\n"
        /* } scope */
        ".Lf928ac_00092b18:\n"
        "movl 4(%eax), %ebx\n" /* line 2918 | expr */
        /* { scope 1 */
        "movl (%esi), %edx\n" /* line 904 */
        "testl %edx, %edx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf928ac_000928f7\n"
        "cmpl 0x18(%esi), %ebx\n" /* line 909 */
        "je .Lf928ac_000928c3\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf928ac_00092b3d:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edi, %edx\n"
        "je .Lf928ac_000928f7\n"
        "movl 0x1c(%ecx), %eax\n" /* line 909 */
        "addl $4, %ecx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf928ac_00092b3d\n"
        "jmp .Lf928ac_000928c3\n"
        /* } scope */
        ".Lf928ac_00092b57:\n"
        "movl 4(%eax), %ebx\n" /* line 2918 | expr */
        /* { scope 1 */
        "movl (%esi), %ecx\n" /* line 904 */
        "testl %ecx, %ecx\n"
        "jne .Lf928ac_000928c3\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf928ac_000928f7\n"
        "cmpl 0x18(%esi), %ebx\n" /* line 909 */
        "je .Lf928ac_000928c3\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf928ac_00092b7c:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edx, %edi\n"
        "je .Lf928ac_000928f7\n"
        "movl 0x1c(%ecx), %eax\n" /* line 909 */
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "jne .Lf928ac_00092b7c\n"
        "jmp .Lf928ac_000928c3\n"
        /* } scope */
        ".Lf928ac_00092b96:\n"
        "movl 4(%eax), %ebx\n" /* line 2918 | expr */
        /* { scope 1 */
        "movl (%esi), %edi\n" /* line 904 */
        "testl %edi, %edi\n"
        "jne .Lf928ac_000928c3\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf928ac_000928f7\n"
        "cmpl %ebx, 0x18(%esi)\n" /* line 909 */
        "je .Lf928ac_000928c3\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf928ac_00092bbb:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edx, %edi\n"
        "je .Lf928ac_000928f7\n"
        "movl 0x1c(%ecx), %eax\n" /* line 909 */
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "jne .Lf928ac_00092bbb\n"
        "jmp .Lf928ac_000928c3\n"
        /* } scope */
        ".Lf928ac_00092bd5:\n"
        "movl 4(%eax), %ebx\n" /* line 2918 | expr */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 904 */
        "testl %eax, %eax\n"
        "jne .Lf928ac_000928c3\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf928ac_000928f7\n"
        "cmpl %ebx, 0x18(%esi)\n" /* line 909 */
        "je .Lf928ac_000928c3\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf928ac_00092bfa:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edx, %edi\n"
        "je .Lf928ac_000928f7\n"
        "movl 0x1c(%ecx), %eax\n" /* line 909 */
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "jne .Lf928ac_00092bfa\n"
        "jmp .Lf928ac_000928c3\n"
        /* } scope */
        ".Lf928ac_00092c14:\n"
        "movl 4(%eax), %ebx\n" /* line 2918 | expr */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 904 */
        "testl %eax, %eax\n"
        "jne .Lf928ac_000928c3\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf928ac_000928f7\n"
        "cmpl %ebx, 0x18(%esi)\n" /* line 909 */
        "je .Lf928ac_000928c3\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf928ac_00092c39:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edx, %edi\n"
        "je .Lf928ac_000928f7\n"
        "movl 0x1c(%ecx), %eax\n" /* line 909 */
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "jne .Lf928ac_00092c39\n"
        "jmp .Lf928ac_000928c3\n"
    );
}

/* line 2594 */
static __attribute__((naked))
Bool EvalPrimitiveExpression(void)
{
    __asm__ __volatile__ (
        ".Lf92c54_00092c54:\n"
        "pushl %ebp\n" /* line 2594 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %edx, %ebx\n" /* constValue */
        "movl (%eax), %edx\n" /* line 2596 | expr */
        "subl $7, %edx\n"
        "cmpl $0x42, %edx\n"
        "ja .Lf92c54_00092c70\n"
        "jmpl *CorrectSolidDeltas+3584(, %edx, 4)\n"
        ".Lf92c54_00092c70:\n"
        "xorl %eax, %eax\n" /* expr */
        ".Lf92c54_00092c72:\n"
        "addl $0x6c, %esp\n" /* line 2639 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 8(%eax), %esi\n" /* line 2602 */
        "movl 4(%eax), %eax\n" /* value */
        /* { scope 1: vec */
        "movl $6, 4(%ebx)\n" /* line 662 */
        "movl %eax, (%ebx)\n" /* line 663 */
        "movl %esi, 8(%ebx)\n" /* line 664 */
        "movl $1, %eax\n"
        "jmp .Lf92c54_00092c72\n"
        /* } scope */
        "movl 8(%eax), %esi\n" /* line 2606 */
        "movl 4(%eax), %eax\n" /* value */
        /* { scope 1: vec */
        "movl $5, 4(%ebx)\n" /* line 724 */
        "movl %eax, (%ebx)\n" /* line 725 */
        "movl %esi, 8(%ebx)\n" /* line 726 */
        "movl $1, %eax\n"
        "jmp .Lf92c54_00092c72\n"
        /* } scope */
        "movl 8(%eax), %esi\n" /* line 2610 */
        "movl 4(%eax), %eax\n"
        "negl %eax\n"
        "movl $6, 4(%ebx)\n" /* line 662 */
        "movl %eax, (%ebx)\n" /* line 663 */
        "movl %esi, 8(%ebx)\n" /* line 664 */
        "movl $1, %eax\n"
        "jmp .Lf92c54_00092c72\n"
        "movl 8(%eax), %esi\n" /* line 2614 */
        "movl 4(%eax), %eax\n"
        "xorl $0x80000000, %eax\n"
        "movl $5, 4(%ebx)\n" /* line 724 */
        "movl %eax, (%ebx)\n" /* line 725 */
        "movl %esi, 8(%ebx)\n" /* line 726 */
        "movl $1, %eax\n"
        "jmp .Lf92c54_00092c72\n"
        "movl 8(%eax), %esi\n" /* line 2618 */
        "movl 4(%eax), %eax\n" /* value */
        /* { scope 1: vec */
        "movl $2, 4(%ebx)\n" /* line 1134 */
        "movl %eax, (%ebx)\n" /* line 1135 */
        "movl %esi, 8(%ebx)\n" /* line 1136 */
        "movl $1, %eax\n"
        "jmp .Lf92c54_00092c72\n"
        /* } scope */
        "movl 8(%eax), %esi\n" /* line 2622 */
        "movl 4(%eax), %eax\n" /* value */
        /* { scope 1: vec */
        "movl $3, 4(%ebx)\n" /* line 1153 */
        "movl %eax, (%ebx)\n" /* line 1154 */
        "movl %esi, 8(%ebx)\n" /* line 1155 */
        "movl $1, %eax\n"
        "jmp .Lf92c54_00092c72\n"
        /* } scope */
        "movl 4(%eax), %eax\n" /* line 2626 */
        "movl $0, 4(%ebx)\n" /* line 646 */
        "movl %eax, 8(%ebx)\n" /* line 647 */
        "movl $1, %eax\n"
        "jmp .Lf92c54_00092c72\n"
        "movl 8(%eax), %esi\n" /* line 2599 | expr */
        "movl 4(%eax), %eax\n" /* expr */
        /* { scope 1: vec */
        /* { scope 2 */
        "movl (%eax), %eax\n" /* line 1612 */
        "movl %eax, %edx\n"
        "testl %eax, %eax\n"
        "je .Lf92c54_00092d67\n"
        "xorl %ecx, %ecx\n"
        ".Lf92c54_00092d44:\n"
        "addl $1, %ecx\n" /* line 1613 */
        "movl 4(%edx), %edx\n" /* line 1612 */
        "testl %edx, %edx\n"
        "jne .Lf92c54_00092d44\n"
        /* } scope */
        "cmpl $1, %ecx\n" /* line 2500 */
        "jne .Lf92c54_00092dcd\n"
        "movl (%eax), %eax\n" /* line 2503 */
        "movl (%eax), %edi\n"
        "movl (%edi), %eax\n" /* line 2833 */
        "cmpl $6, %eax\n"
        "je .Lf92c54_00092e95\n"
        "cmpl $0x31, %eax\n"
        "je .Lf92c54_00092dab\n"
        ".Lf92c54_00092d67:\n"
        "xorl %eax, %eax\n" /* line 2517 */
        /* } scope */
        "movzbl %al, %eax\n" /* line 2599 | expr */
        "jmp .Lf92c54_00092c72\n"
        "movl 4(%eax), %eax\n" /* line 2630 */
        "movl $6, 4(%ebx)\n" /* line 662 */
        "movl $0, (%ebx)\n" /* line 663 */
        "movl %eax, 8(%ebx)\n" /* line 664 */
        "movl $1, %eax\n"
        "jmp .Lf92c54_00092c72\n"
        "movl 4(%eax), %eax\n" /* line 2634 */
        "movl $6, 4(%ebx)\n" /* line 662 */
        "movl $1, (%ebx)\n" /* line 663 */
        "movl %eax, 8(%ebx)\n" /* line 664 */
        "movl $1, %eax\n"
        "jmp .Lf92c54_00092c72\n"
        /* { scope 1: vec */
        ".Lf92c54_00092dab:\n"
        "movl 0x10(%edi), %eax\n" /* line 2839 */
        "movl 0xc(%edi), %ecx\n"
        "movl 8(%edi), %edx\n"
        "movl 4(%edi), %esi\n"
        "movl %ebx, 4(%esp)\n" /* constValue */
        "movl %eax, (%esp)\n"
        "movl %esi, %eax\n"
        "calll EvalBinaryOperatorExpression\n"
        /* } scope */
        "movzbl %al, %eax\n" /* line 2599 | expr */
        "jmp .Lf92c54_00092c72\n"
        /* { scope 1: vec */
        ".Lf92c54_00092dcd:\n"
        "cmpl $3, %ecx\n" /* line 2506 */
        "jne .Lf92c54_00092d67\n"
        "movl %eax, -0x54(%ebp)\n" /* line 2509 | node */
        "testl %eax, %eax\n"
        "je .Lf92c54_00092e36\n"
        "leal -0x48(%ebp), %eax\n" /* constValue2 */
        "movl %eax, -0x58(%ebp)\n"
        ".Lf92c54_00092ddf:\n"
        "movl -0x54(%ebp), %edx\n" /* line 2511 | node */
        "movl (%edx), %eax\n"
        "movl (%eax), %edi\n"
        "movl (%edi), %eax\n" /* line 2833 */
        "cmpl $6, %eax\n"
        "je .Lf92c54_00092ea9\n"
        "cmpl $0x31, %eax\n"
        "jne .Lf92c54_00092d67\n"
        "movl 0x10(%edi), %eax\n" /* line 2839 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0xc(%edi), %ecx\n"
        "movl 8(%edi), %edx\n"
        "movl 4(%edi), %edi\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl %edi, %eax\n"
        "calll EvalBinaryOperatorExpression\n"
        ".Lf92c54_00092e1d:\n"
        "testb %al, %al\n" /* line 2511 */
        "je .Lf92c54_00092d67\n"
        "addl $0xc, -0x58(%ebp)\n"
        "movl -0x54(%ebp), %edx\n" /* line 2509 | node */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* node */
        "testl %edx, %edx\n"
        "jne .Lf92c54_00092ddf\n"
        ".Lf92c54_00092e36:\n"
        "leal -0x44(%ebp), %edi\n" /* line 2516 */
        "xorl %ecx, %ecx\n"
        "leal -0x24(%ebp), %eax\n" /* vec */
        "movl %eax, -0x4c(%ebp)\n"
        ".Lf92c54_00092e41:\n"
        "leal -0x48(%ebp), %edx\n" /* constValue2 */
        "addl %ecx, %edx\n"
        "movl %edx, -0x50(%ebp)\n"
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 2467 */
        "cmpl $5, %edx\n" /* line 2468 */
        "je .Lf92c54_00092ebb\n"
        "cmpl $6, %edx\n" /* line 2473 */
        "jne .Lf92c54_00092ec6\n"
        "cvtsi2ssl -4(%edi), %xmm0\n" /* line 2475 */
        "movl -0x4c(%ebp), %eax\n"
        "movss %xmm0, 8(%eax)\n"
        ".Lf92c54_00092e62:\n"
        "addl $0xc, %edi\n" /* line 2480 */
        "addl $0xc, %ecx\n"
        "subl $4, -0x4c(%ebp)\n"
        "cmpl $0x24, %ecx\n" /* line 2465 */
        "jne .Lf92c54_00092e41\n"
        "movl $4, 4(%ebx)\n" /* line 2484 */
        "leal -0x24(%ebp), %eax\n" /* line 2485 | vec */
        "movl %eax, (%esp)\n"
        "calll Scr_AllocVector\n"
        "movl %eax, (%ebx)\n"
        /* } scope */
        ".Lf92c54_00092e85:\n"
        "movl %esi, 8(%ebx)\n" /* line 2517 */
        "movl $1, %eax\n"
        /* } scope */
        "movzbl %al, %eax\n" /* line 2599 | expr */
        "jmp .Lf92c54_00092c72\n"
        /* { scope 1: vec */
        ".Lf92c54_00092e95:\n"
        "movl 4(%edi), %esi\n" /* line 2836 */
        "movl %ebx, %edx\n" /* constValue */
        "movl %esi, %eax\n"
        "calll EvalPrimitiveExpression\n"
        /* } scope */
        "movzbl %al, %eax\n" /* line 2599 | expr */
        "jmp .Lf92c54_00092c72\n"
        /* { scope 1: vec */
        ".Lf92c54_00092ea9:\n"
        "movl 4(%edi), %edi\n" /* line 2836 */
        "movl -0x58(%ebp), %edx\n"
        "movl %edi, %eax\n"
        "calll EvalPrimitiveExpression\n"
        "jmp .Lf92c54_00092e1d\n"
        /* { scope 2 */
        ".Lf92c54_00092ebb:\n"
        "movl -4(%edi), %eax\n" /* line 2470 */
        "movl -0x4c(%ebp), %edx\n"
        "movl %eax, 8(%edx)\n"
        "jmp .Lf92c54_00092e62\n"
        ".Lf92c54_00092ec6:\n"
        "movl imp_var_typename, %eax\n" /* line 2480 */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cea0, 4(%esp)\n" /* "type %s is not a float" */
        "movl -0x50(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf92c54_00092e85\n"
    );
}

/* line 2748 */
static __attribute__((naked))
Bool EvalBinaryOperatorExpression(sval_t opcode, sval_t sourcePos, VariableCompileValue *constValue)
{
    __asm__ __volatile__ (
        ".Lf92eea_00092eea:\n"
        "pushl %ebp\n" /* line 2748 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %edx, %edi\n" /* expr2 */
        "movl %ecx, -0x3c(%ebp)\n"
        /* { scope 1 */
        "movl (%eax), %edx\n" /* line 2833 | expr1 */
        "cmpl $6, %edx\n"
        "je .Lf92eea_00092fcb\n"
        "cmpl $0x31, %edx\n"
        "je .Lf92eea_00092f12\n"
        ".Lf92eea_00092f08:\n"
        "xorl %eax, %eax\n" /* line 2770 | expr1 */
        /* } scope */
        ".Lf92eea_00092f0a:\n"
        "addl $0x4c, %esp\n" /* line 2771 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf92eea_00092f12:\n"
        "movl 0x10(%eax), %ebx\n" /* line 2839 | expr1 */
        "movl 0xc(%eax), %ecx\n" /* expr1 */
        "movl 8(%eax), %edx\n" /* expr1 */
        "movl 4(%eax), %esi\n" /* expr1 */
        "leal -0x24(%ebp), %eax\n" /* constValue1, expr1 */
        "movl %eax, 4(%esp)\n" /* expr1 */
        "movl %ebx, (%esp)\n"
        "movl %esi, %eax\n" /* expr1 */
        "calll EvalBinaryOperatorExpression\n"
        ".Lf92eea_00092f2f:\n"
        "testb %al, %al\n" /* line 2753 | expr1 */
        "je .Lf92eea_00092f08\n"
        "movl (%edi), %eax\n" /* line 2833 | expr2, expr1 */
        "cmpl $6, %eax\n" /* expr1 */
        "je .Lf92eea_00092fdd\n"
        "cmpl $0x31, %eax\n" /* expr1 */
        "jne .Lf92eea_00092f08\n"
        "movl 0x10(%edi), %ebx\n" /* line 2839 | expr2 */
        "movl 0xc(%edi), %ecx\n" /* expr2 */
        "movl 8(%edi), %edx\n" /* expr2 */
        "movl 4(%edi), %esi\n" /* expr2 */
        "leal -0x30(%ebp), %eax\n" /* constValue2, expr1 */
        "movl %eax, 4(%esp)\n" /* expr1 */
        "movl %ebx, (%esp)\n"
        "movl %esi, %eax\n" /* expr1 */
        "calll EvalBinaryOperatorExpression\n"
        ".Lf92eea_00092f60:\n"
        "testb %al, %al\n" /* line 2756 | expr1 */
        "je .Lf92eea_00092f08\n"
        "movl -0x24(%ebp), %eax\n" /* line 246 | constValue1 */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddRefToValue\n"
        "movl -0x30(%ebp), %eax\n" /* constValue2 */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddRefToValue\n"
        "leal -0x30(%ebp), %eax\n" /* line 2761 | constValue2, expr1 */
        "movl %eax, 8(%esp)\n" /* expr1 */
        "leal -0x24(%ebp), %eax\n" /* constValue1, expr1 */
        "movl %eax, 4(%esp)\n" /* expr1 */
        "movl -0x3c(%ebp), %eax\n" /* expr1 */
        "movl %eax, (%esp)\n" /* expr1 */
        "calll Scr_EvalBinaryOperator\n"
        "movl imp_scrVarPub, %eax\n" /* line 2762 | expr1 */
        "movl 0x10(%eax), %eax\n" /* expr1 */
        "testl %eax, %eax\n" /* expr1 */
        "je .Lf92eea_00092fef\n"
        "movl %eax, 8(%esp)\n" /* line 2764 | expr1 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "movl 8(%ebp), %edx\n" /* sourcePos */
        "movl %edx, (%esp)\n"
        "calll CompileError\n"
        "xorl %eax, %eax\n" /* expr1 */
        "jmp .Lf92eea_00092f0a\n"
        ".Lf92eea_00092fcb:\n"
        "movl 4(%eax), %esi\n" /* line 2836 | expr1 */
        "leal -0x24(%ebp), %edx\n" /* constValue1 */
        "movl %esi, %eax\n" /* expr1 */
        "calll EvalPrimitiveExpression\n"
        "jmp .Lf92eea_00092f2f\n"
        ".Lf92eea_00092fdd:\n"
        "movl 4(%edi), %esi\n" /* expr2 */
        "leal -0x30(%ebp), %edx\n" /* constValue2 */
        "movl %esi, %eax\n" /* expr1 */
        "calll EvalPrimitiveExpression\n"
        "jmp .Lf92eea_00092f60\n"
        ".Lf92eea_00092fef:\n"
        "movl -0x24(%ebp), %eax\n" /* line 2768 | constValue1, expr1 */
        "movl -0x20(%ebp), %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* constValue */
        "movl %eax, (%ecx)\n" /* expr1 */
        "movl %edx, 4(%ecx)\n"
        "movl 8(%ebp), %eax\n" /* line 2769 | sourcePos, expr1 */
        "movl %eax, 8(%ecx)\n" /* expr1 */
        "movl $1, %eax\n" /* expr1 */
        "jmp .Lf92eea_00092f0a\n"
    );
}

/* line 4592 */
static __attribute__((naked))
unsigned int Scr_CalcLocalVarsStatement(scr_block_t *block)
{
    __asm__ __volatile__ (
        ".Lf9300e_0009300e:\n"
        "pushl %ebp\n" /* line 4592 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20c, %esp\n"
        "movl %eax, %ebx\n" /* val */
        "movl %edx, -0x174(%ebp)\n"
        "cmpl $0x40, (%eax)\n" /* line 4594 */
        "ja .Lf9300e_000931ad\n"
        "movl (%eax), %eax\n"
        "jmpl *CorrectSolidDeltas+3852(, %eax, 4)\n"
        "movl 8(%ebx), %edi\n" /* line 4644 | val, abortLevel */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        "movl scrCompileGlob+60, %esi\n" /* line 4141 | currentBlock */
        "movl %esi, -0xd0(%ebp)\n" /* currentBlock, oldBreakChildBlocks */
        "movl scrCompileGlob+64, %eax\n" /* line 4142 */
        "movl %eax, -0xcc(%ebp)\n" /* oldBreakChildCount */
        "movl $0, -0x1c(%ebp)\n" /* line 4144 | breakChildCount */
        "movl $__mh_execute_header, (%esp)\n" /* line 4145 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, -0xc0(%ebp)\n" /* childBlocks */
        "movl %eax, scrCompileGlob+60\n" /* line 4146 */
        "leal -0x1c(%ebp), %eax\n" /* line 4147 | breakChildCount */
        "movl %eax, scrCompileGlob+64\n"
        "movl $__mh_execute_header, (%esp)\n" /* line 4154 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, -0xb4(%ebp)\n" /* childBlocks */
        "movl (%edi), %eax\n" /* line 4156 | abortLevel */
        "movl 4(%eax), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf9300e_00093195\n"
        "movl $3, %edi\n" /* abortLevel */
        "movl $0, -0xb8(%ebp)\n" /* childCount */
        "movb $0, -0xc5(%ebp)\n" /* hasDefault */
        "xorl %esi, %esi\n" /* currentBlock */
        ".Lf9300e_000930ab:\n"
        "movl (%ebx), %ecx\n" /* line 4158 | node */
        "movl (%ecx), %eax\n"
        "subl $0x3d, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf9300e_00094488\n"
        "testl %esi, %esi\n" /* line 4176 | currentBlock */
        "je .Lf9300e_000930de\n"
        "movl %esi, %edx\n" /* line 4179 | currentBlock */
        "movl %ecx, %eax\n"
        "calll Scr_CalcLocalVarsStatement\n"
        "movl (%esi), %eax\n" /* line 4180 | currentBlock */
        "testl %eax, %eax\n"
        "je .Lf9300e_000930de\n"
        "cmpl $2, %eax\n" /* line 4183 */
        "je .Lf9300e_0009451f\n"
        "cmpl %edi, %eax\n" /* line 4194 | abortLevel */
        "cmovlel %eax, %edi\n" /* abortLevel */
        ".Lf9300e_000930dc:\n"
        "xorl %esi, %esi\n" /* currentBlock */
        ".Lf9300e_000930de:\n"
        "movl 4(%ebx), %ebx\n" /* line 4156 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf9300e_000930ab\n"
        "cmpb $0, -0xc5(%ebp)\n" /* line 4201 | hasDefault */
        "je .Lf9300e_00093195\n"
        "testl %esi, %esi\n" /* line 4203 | currentBlock */
        "je .Lf9300e_00093150\n"
        "movl (%esi), %edx\n" /* line 3286 | j */
        "testl %edx, %edx\n"
        "jne .Lf9300e_00093128\n"
        "movl scrCompileGlob+60, %eax\n" /* line 3288 */
        "testl %eax, %eax\n"
        "je .Lf9300e_00093128\n"
        "movl scrCompileGlob+64, %eax\n" /* line 886 */
        "cmpl $0x3ff, (%eax)\n"
        "jg .Lf9300e_00094f80\n"
        ".Lf9300e_00093116:\n"
        "movl (%eax), %edx\n" /* line 3291 */
        "movl scrCompileGlob+60, %eax\n"
        "movl %esi, (%eax, %edx, 4)\n" /* j */
        "movl scrCompileGlob+64, %eax\n" /* line 3292 */
        "addl $1, (%eax)\n"
        ".Lf9300e_00093128:\n"
        "cmpl $0x3ff, -0xb8(%ebp)\n" /* line 886 | childCount */
        "jg .Lf9300e_00094b59\n"
        ".Lf9300e_00093138:\n"
        "movl -0xb8(%ebp), %edx\n" /* line 4208 | childCount */
        "movl -0xb4(%ebp), %ecx\n" /* childBlocks */
        "movl %esi, (%ecx, %edx, 4)\n" /* currentBlock */
        "addl $1, %edx\n" /* line 4209 */
        "movl %edx, -0xb8(%ebp)\n" /* childCount */
        ".Lf9300e_00093150:\n"
        "movl -0x174(%ebp), %esi\n" /* line 4212 | currentBlock */
        "movl (%esi), %eax\n" /* currentBlock */
        "testl %eax, %eax\n"
        "jne .Lf9300e_0009315e\n"
        "movl %edi, (%esi)\n" /* line 4213 | abortLevel, currentBlock */
        ".Lf9300e_0009315e:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 4214 | breakChildCount */
        "movl %eax, -0xc4(%ebp)\n" /* childCount */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        "testl %eax, %eax\n" /* line 983 */
        "je .Lf9300e_0009317b\n"
        "movl -0x174(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf9300e_00094898\n"
        /* } scope */
        /* } scope */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_0009317b:\n"
        "movl -0xb8(%ebp), %eax\n" /* line 1021 | childCount */
        "testl %eax, %eax\n"
        "je .Lf9300e_00093195\n"
        "movl -0x174(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf9300e_000949b3\n"
        /* } scope */
        /* } scope */
        ".Lf9300e_00093195:\n"
        "movl -0xd0(%ebp), %edx\n" /* line 4218 | oldBreakChildBlocks */
        "movl %edx, scrCompileGlob+60\n"
        "movl -0xcc(%ebp), %ecx\n" /* line 4219 | oldBreakChildCount */
        "movl %ecx, scrCompileGlob+64\n"
        /* } scope */
        ".Lf9300e_000931ad:\n"
        "addl $0x20c, %esp\n" /* line 4659 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 4(%ebx), %esi\n" /* line 4597 | val, currentBlock */
        "movl (%esi), %eax\n" /* line 2915 | j */
        "cmpl $4, %eax\n"
        "je .Lf9300e_0009467c\n"
        ".Lf9300e_000931c6:\n"
        "cmpl $0xd, %eax\n"
        "jne .Lf9300e_000931ad\n"
        "movl 4(%esi), %ebx\n" /* line 2922 | j */
        "cmpl $0x11, (%ebx)\n" /* line 2949 */
        "jne .Lf9300e_000931ad\n"
        "movl 4(%ebx), %eax\n" /* line 2952 */
        "movl -0x174(%ebp), %edx\n"
        "calll Scr_CalcLocalVarsVariableExpressionRef\n"
        "jmp .Lf9300e_000931ad\n"
        "movl -0x174(%ebp), %esi\n" /* line 4602 | currentBlock */
        "movl (%esi), %eax\n" /* currentBlock */
        "testl %eax, %eax\n"
        "jne .Lf9300e_000931ad\n"
        "movl $3, (%esi)\n" /* line 4603 | currentBlock */
        "jmp .Lf9300e_000931ad\n"
        "movl 8(%ebx), %edi\n" /* line 4607 | val, abortLevel */
        "movl 0x10(%ebx), %eax\n" /* line 924 */
        "testl %eax, %eax\n"
        "je .Lf9300e_00094e71\n"
        "movl 0x10(%ebx), %eax\n"
        ".Lf9300e_00093208:\n"
        "movl $0x118, 8(%esp)\n" /* line 926 */
        "movl -0x174(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x10(%ebx), %eax\n" /* line 927 */
        "movl $0, 8(%eax)\n"
        "movl 0x10(%ebx), %edx\n" /* line 3169 */
        "movl %edi, %eax\n" /* i */
        "calll Scr_CalcLocalVarsStatement\n"
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        "movl -0x174(%ebp), %ecx\n" /* line 1021 */
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf9300e_000931ad\n"
        "movl 0x10(%ebx), %ebx\n" /* line 1026 */
        "movl %ebx, -0x5c(%ebp)\n"
        "movl 0xc(%ecx), %eax\n" /* line 1028 */
        "movl %ebx, %esi\n" /* j */
        "movl %eax, 8(%ebx)\n"
        "testl %eax, %eax\n" /* line 1029 */
        "jle .Lf9300e_000931ad\n"
        "addl $0x18, %ecx\n"
        "movl %ecx, -0xa8(%ebp)\n"
        "movl %ebx, -0xa4(%ebp)\n"
        "movl $0, -0x164(%ebp)\n" /* j */
        "addl $0x18, %esi\n" /* j */
        "movl %esi, -0x1f4(%ebp)\n" /* j */
        "movl %ebx, %eax\n"
        "addl $0x1c, %eax\n"
        "movl %eax, -0x1f8(%ebp)\n"
        "movl %ebx, %edx\n"
        "addl $0x10, %edx\n"
        "movl %edx, -0x1fc(%ebp)\n"
        ".Lf9300e_00093294:\n"
        "movl (%ecx), %ecx\n" /* line 1031 */
        "movl %ecx, -0x168(%ebp)\n"
        "movl -0x5c(%ebp), %esi\n" /* line 764 */
        "movl 0xc(%esi), %ebx\n"
        "movl %ebx, -0x18c(%ebp)\n"
        "cmpl %ebx, -0x164(%ebp)\n" /* j */
        "jge .Lf9300e_0009404a\n"
        "movl -0xa4(%ebp), %eax\n" /* line 766 */
        "cmpl 0x18(%eax), %ecx\n"
        "je .Lf9300e_00094612\n"
        "movl -0x1fc(%ebp), %edx\n"
        "addl $8, %edx\n"
        "movl -0x164(%ebp), %ecx\n" /* j */
        "movl %ebx, %edi\n"
        "movl -0x1f8(%ebp), %esi\n"
        "subl -0x1f4(%ebp), %esi\n"
        ".Lf9300e_000932e0:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %edi\n"
        "je .Lf9300e_0009404a\n"
        "movl (%esi, %edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0x168(%ebp)\n"
        "jne .Lf9300e_000932e0\n"
        ".Lf9300e_000932f9:\n"
        "testl %ecx, %ecx\n" /* line 1033 */
        "js .Lf9300e_0009404a\n"
        "movl %ecx, %ebx\n"
        ".Lf9300e_00093303:\n"
        "cmpl %ebx, -0x164(%ebp)\n" /* line 1039 | j */
        "jge .Lf9300e_00093332\n"
        "leal (, %ebx, 4), %eax\n"
        "movl -0x5c(%ebp), %esi\n" /* j */
        "leal 0x14(%eax, %esi), %ecx\n"
        "leal 0x18(%eax, %esi), %edx\n"
        ".Lf9300e_0009331d:\n"
        "subl $1, %ebx\n" /* line 1041 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x164(%ebp)\n" /* line 1039 | j */
        "jl .Lf9300e_0009331d\n"
        ".Lf9300e_00093332:\n"
        "movl -0x168(%ebp), %edx\n" /* line 1044 */
        "movl -0xa4(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "addl $1, -0x164(%ebp)\n" /* line 1029 | j */
        "addl $4, -0x1fc(%ebp)\n"
        "addl $4, -0x1f8(%ebp)\n"
        "addl $4, -0x1f4(%ebp)\n"
        "addl $4, -0xa8(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0xa4(%ebp)\n"
        "movl -0x164(%ebp), %esi\n" /* j */
        "movl -0x174(%ebp), %ecx\n"
        "cmpl 0xc(%ecx), %esi\n" /* j */
        "jge .Lf9300e_000931ad\n"
        "movl -0xa8(%ebp), %ecx\n"
        "jmp .Lf9300e_00093294\n"
        /* } scope */
        "leal 0x1c(%ebx), %esi\n" /* line 4611 | val, elseStatBlock */
        "movl 0xc(%ebx), %eax\n" /* val */
        "movl %eax, -0x170(%ebp)\n"
        "movl 8(%ebx), %edi\n" /* val, abortLevel */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        "movl 0x18(%ebx), %eax\n" /* line 924 */
        "testl %eax, %eax\n"
        "je .Lf9300e_00094ea4\n"
        "movl 0x18(%ebx), %eax\n"
        ".Lf9300e_000933aa:\n"
        "movl $0x118, 8(%esp)\n" /* line 926 */
        "movl -0x174(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x18(%ebx), %eax\n" /* line 927 */
        "movl $0, 8(%eax)\n"
        "movl 0x18(%ebx), %edx\n" /* line 3254 | abortLevel */
        "movl %edi, %eax\n" /* i */
        "calll Scr_CalcLocalVarsStatement\n"
        "movl 0x18(%ebx), %eax\n" /* line 3255 | abortLevel */
        "movl (%eax), %ebx\n" /* abortLevel */
        "cmpl $3, %ebx\n" /* abortLevel */
        "jle .Lf9300e_00094574\n"
        "movl $0, -0x15c(%ebp)\n" /* childCount */
        "movl $3, %ebx\n" /* abortLevel */
        ".Lf9300e_000933f5:\n"
        "movl (%esi), %ecx\n" /* line 924 */
        "testl %ecx, %ecx\n"
        "je .Lf9300e_00094eb8\n"
        "movl (%esi), %eax\n"
        ".Lf9300e_00093401:\n"
        "movl $0x118, 8(%esp)\n" /* line 926 */
        "movl -0x174(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl (%esi), %eax\n" /* line 927 */
        "movl $0, 8(%eax)\n"
        "movl (%esi), %edx\n" /* line 3266 | j */
        "movl -0x170(%ebp), %eax\n"
        "calll Scr_CalcLocalVarsStatement\n"
        "movl (%esi), %eax\n" /* line 3267 | j */
        "movl (%eax), %ecx\n"
        "cmpl %ecx, %ebx\n" /* abortLevel */
        "jge .Lf9300e_00094554\n"
        "movl %ebx, %ecx\n" /* abortLevel */
        ".Lf9300e_0009343f:\n"
        "movl -0x174(%ebp), %eax\n" /* line 3277 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf9300e_0009344d\n"
        "movl %ecx, (%eax)\n" /* line 3278 */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_0009344d:\n"
        "movl -0x15c(%ebp), %eax\n" /* line 983 | childCount */
        "testl %eax, %eax\n"
        "je .Lf9300e_000931ad\n"
        "movl -0x174(%ebp), %edx\n"
        "movl (%edx), %edi\n" /* i */
        "testl %edi, %edi\n" /* i */
        "je .Lf9300e_00094735\n"
        /* } scope */
        /* { scope 3: j, childIndex, i, block, ... */
        /* { scope 4 */
        ".Lf9300e_0009346b:\n"
        "movl (%edx), %ebx\n" /* line 1021 */
        "testl %ebx, %ebx\n"
        "jne .Lf9300e_000931ad\n"
        "movl -0x15c(%ebp), %edx\n" /* line 1024 | childCount */
        "testl %edx, %edx\n"
        "jle .Lf9300e_000931ad\n"
        "movl $0, -0x150(%ebp)\n" /* line 1021 | childIndex */
        ".Lf9300e_0009348d:\n"
        "movl -0x150(%ebp), %ecx\n" /* line 1026 | childIndex */
        "movl -0x2c(%ebp, %ecx, 4), %ecx\n"
        "movl %ecx, -0x60(%ebp)\n"
        "movl -0x174(%ebp), %esi\n" /* line 1028 | j */
        "movl 0xc(%esi), %eax\n" /* j */
        "movl %eax, 8(%ecx)\n"
        "testl %eax, %eax\n" /* line 1029 */
        "jle .Lf9300e_00094067\n"
        "addl $0x18, %esi\n" /* j */
        "movl %esi, -0xa0(%ebp)\n" /* j */
        "movl %ecx, -0x9c(%ebp)\n"
        "movl $0, -0x154(%ebp)\n" /* j */
        "addl $0x18, %ecx\n"
        "movl %ecx, -0x1e8(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "addl $0x1c, %eax\n"
        "movl %eax, -0x1ec(%ebp)\n"
        "movl -0x9c(%ebp), %edx\n"
        "addl $0x10, %edx\n"
        "movl %edx, -0x1f0(%ebp)\n"
        "movl %esi, %ecx\n" /* j */
        "movl (%ecx), %ecx\n" /* line 1031 */
        "movl %ecx, -0x158(%ebp)\n"
        "movl -0x60(%ebp), %esi\n" /* line 764 */
        "movl 0xc(%esi), %ebx\n"
        "movl %ebx, -0x190(%ebp)\n"
        "cmpl %ebx, -0x154(%ebp)\n" /* j */
        "jge .Lf9300e_00093604\n"
        ".Lf9300e_00093510:\n"
        "movl -0x9c(%ebp), %eax\n" /* line 766 */
        "cmpl 0x18(%eax), %ecx\n"
        "je .Lf9300e_000940cc\n"
        "movl -0x1f0(%ebp), %edx\n"
        "addl $8, %edx\n"
        "movl -0x154(%ebp), %ecx\n" /* j */
        "movl %ebx, %edi\n"
        "movl -0x1ec(%ebp), %esi\n"
        "subl -0x1e8(%ebp), %esi\n"
        ".Lf9300e_0009353c:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %edi\n"
        "je .Lf9300e_00093604\n"
        "movl (%esi, %edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0x158(%ebp)\n"
        "jne .Lf9300e_0009353c\n"
        ".Lf9300e_00093555:\n"
        "testl %ecx, %ecx\n" /* line 1033 */
        "js .Lf9300e_00093604\n"
        "movl %ecx, %ebx\n"
        ".Lf9300e_0009355f:\n"
        "cmpl %ebx, -0x154(%ebp)\n" /* line 1039 | j */
        "jge .Lf9300e_0009358e\n"
        "leal (, %ebx, 4), %eax\n"
        "movl -0x60(%ebp), %esi\n" /* j */
        "leal 0x14(%eax, %esi), %ecx\n"
        "leal 0x18(%eax, %esi), %edx\n"
        ".Lf9300e_00093579:\n"
        "subl $1, %ebx\n" /* line 1041 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x154(%ebp)\n" /* line 1039 | j */
        "jl .Lf9300e_00093579\n"
        ".Lf9300e_0009358e:\n"
        "movl -0x158(%ebp), %edx\n" /* line 1044 */
        "movl -0x9c(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "addl $1, -0x154(%ebp)\n" /* line 1029 | j */
        "addl $4, -0x1f0(%ebp)\n"
        "addl $4, -0x1ec(%ebp)\n"
        "addl $4, -0x1e8(%ebp)\n"
        "addl $4, -0xa0(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0x9c(%ebp)\n"
        "movl -0x154(%ebp), %esi\n" /* j */
        "movl -0x174(%ebp), %ecx\n"
        "cmpl 0xc(%ecx), %esi\n" /* j */
        "jge .Lf9300e_00094067\n"
        "movl -0xa0(%ebp), %ecx\n"
        "movl (%ecx), %ecx\n" /* line 1031 */
        "movl %ecx, -0x158(%ebp)\n"
        "movl -0x60(%ebp), %esi\n" /* line 764 */
        "movl 0xc(%esi), %ebx\n"
        "movl %ebx, -0x190(%ebp)\n"
        "cmpl %ebx, -0x154(%ebp)\n" /* j */
        "jl .Lf9300e_00093510\n"
        ".Lf9300e_00093604:\n"
        "cmpl $0x3f, %ebx\n" /* line 894 */
        "jg .Lf9300e_00094085\n"
        "movl -0x190(%ebp), %eax\n"
        ".Lf9300e_00093613:\n"
        "addl $1, %eax\n" /* line 1037 */
        "movl -0x60(%ebp), %ecx\n"
        "movl %eax, 0xc(%ecx)\n"
        "jmp .Lf9300e_0009355f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "leal 0x14(%ebx), %edx\n" /* line 4615 | val */
        "movl %edx, -0x14c(%ebp)\n" /* whileStatBlock */
        "movl 8(%ebx), %edi\n" /* val, abortLevel */
        "movl 4(%ebx), %esi\n" /* val, elseStatBlock */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        "movl (%esi), %eax\n" /* line 2833 | j */
        "cmpl $6, %eax\n"
        "je .Lf9300e_000946e4\n"
        "cmpl $0x31, %eax\n"
        "je .Lf9300e_0009485d\n"
        ".Lf9300e_00093644:\n"
        "movb $0, -0x145(%ebp)\n" /* line 3474 | constConditional */
        ".Lf9300e_0009364b:\n"
        "movl scrCompileGlob+60, %ecx\n" /* line 3485 */
        "movl %ecx, -0x144(%ebp)\n" /* oldBreakChildBlocks */
        "movl scrCompileGlob+64, %esi\n" /* line 3486 | continueChildBlocks */
        "movl %esi, -0x140(%ebp)\n" /* continueChildBlocks, oldBreakChildCount */
        "movl scrCompileGlob+72, %eax\n" /* line 3488 */
        "movl %eax, -0x13c(%ebp)\n" /* oldContinueChildBlocks */
        "movl scrCompileGlob+76, %edx\n" /* line 3489 */
        "movl %edx, -0x138(%ebp)\n" /* oldContinueChildCount */
        "movl $0, -0x1c(%ebp)\n" /* line 3491 | breakChildCount */
        "movl $0, -0x20(%ebp)\n" /* line 3492 | continueChildCount */
        "movl $__mh_execute_header, (%esp)\n" /* line 3494 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %esi\n" /* continueChildBlocks */
        "movl %eax, scrCompileGlob+72\n" /* line 3495 */
        "leal -0x20(%ebp), %eax\n" /* line 3496 | continueChildCount */
        "movl %eax, scrCompileGlob+76\n"
        "cmpb $0, -0x145(%ebp)\n" /* line 3500 | constConditional */
        "jne .Lf9300e_0009463e\n"
        "movl $0, -0x130(%ebp)\n" /* childBlocks */
        ".Lf9300e_000936ba:\n"
        "movl -0x130(%ebp), %ecx\n" /* line 3510 | childBlocks */
        "movl %ecx, scrCompileGlob+60\n"
        "movl -0x14c(%ebp), %eax\n" /* line 924 | whileStatBlock */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf9300e_00094e52\n"
        "movl %eax, %ecx\n"
        ".Lf9300e_000936d8:\n"
        "movl (%ecx), %eax\n" /* line 926 */
        "movl $0x118, 8(%esp)\n"
        "movl -0x174(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x14c(%ebp), %ecx\n" /* line 927 | whileStatBlock */
        "movl (%ecx), %eax\n"
        "movl $0, 8(%eax)\n"
        "movl (%ecx), %edx\n" /* line 3513 */
        "movl %edi, %eax\n" /* i */
        "calll Scr_CalcLocalVarsStatement\n"
        "movl -0x14c(%ebp), %eax\n" /* line 3514 | whileStatBlock */
        "movl (%eax), %ebx\n" /* block */
        /* { scope 3: j, childIndex, i, block, ... */
        "movl (%ebx), %eax\n" /* line 3298 | abortLevel */
        "testl %eax, %eax\n"
        "jne .Lf9300e_00093746\n"
        "movl scrCompileGlob+72, %eax\n" /* line 3300 */
        "testl %eax, %eax\n"
        "je .Lf9300e_00093746\n"
        "movl scrCompileGlob+76, %eax\n" /* line 886 */
        "cmpl $0x3ff, (%eax)\n"
        "jg .Lf9300e_00094e1e\n"
        ".Lf9300e_00093734:\n"
        "movl (%eax), %edx\n" /* line 3303 */
        "movl scrCompileGlob+72, %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n" /* abortLevel */
        "movl scrCompileGlob+76, %eax\n" /* line 3304 */
        "addl $1, (%eax)\n"
        /* } scope */
        ".Lf9300e_00093746:\n"
        "movl -0x20(%ebp), %edi\n" /* line 3516 | continueChildCount, i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf9300e_00093e9a\n"
        "movl $1, -0x90(%ebp)\n"
        "addl $4, %esi\n" /* continueChildBlocks */
        "movl %esi, -0x1e4(%ebp)\n" /* continueChildBlocks */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00093764:\n"
        "movl -0x174(%ebp), %edx\n" /* line 983 */
        "movl (%edx), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lf9300e_00093e7d\n"
        "movl -0x1e4(%ebp), %ecx\n" /* line 4592 */
        "subl $4, %ecx\n"
        "movl %ecx, -0x8c(%ebp)\n"
        "movl -0x1e4(%ebp), %esi\n" /* line 989 */
        "movl -4(%esi), %eax\n"
        "movl $0, (%eax)\n"
        "movl -4(%esi), %eax\n" /* line 992 */
        "movl 0xc(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf9300e_00093e7d\n"
        "xorl %edi, %edi\n" /* i */
        "jmp .Lf9300e_000937c2\n"
        ".Lf9300e_000937a4:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf9300e_000937a6:\n"
        "movl %esi, 0x18(%edx, %ebx, 4)\n" /* line 1004 */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        "addl $1, 0xc(%edx)\n" /* line 1005 */
        ".Lf9300e_000937ae:\n"
        "addl $1, %edi\n" /* line 992 | i */
        "movl -0x8c(%ebp), %esi\n"
        "movl (%esi), %eax\n"
        "cmpl 0xc(%eax), %edi\n" /* i */
        "jge .Lf9300e_00093e7d\n"
        ".Lf9300e_000937c2:\n"
        "movl 0x18(%eax, %edi, 4), %esi\n" /* line 994 */
        /* { scope 4 */
        "movl -0x174(%ebp), %eax\n" /* line 764 */
        "movl 0xc(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf9300e_000937a4\n"
        "cmpl 0x18(%eax), %esi\n" /* line 766 */
        "je .Lf9300e_000937ae\n"
        "movl %eax, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf9300e_000937dc:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %ebx\n"
        "je .Lf9300e_000937f1\n"
        "movl 0x1c(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, %esi\n"
        "jne .Lf9300e_000937dc\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 995 */
        "jns .Lf9300e_000937ae\n"
        ".Lf9300e_000937f1:\n"
        "movl -0x174(%ebp), %edx\n"
        "jmp .Lf9300e_000937a6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "leal 0x20(%ebx), %eax\n" /* line 4619 | val */
        "movl %eax, -0x11c(%ebp)\n" /* forStatPostBlock */
        "leal 0x1c(%ebx), %edx\n" /* val */
        "movl %edx, -0x118(%ebp)\n" /* forStatBlock */
        "movl 0x10(%ebx), %ecx\n" /* val */
        "movl %ecx, -0x16c(%ebp)\n"
        "movl 0xc(%ebx), %esi\n" /* val, elseStatBlock */
        "movl %esi, -0x170(%ebp)\n" /* elseStatBlock */
        "movl 8(%ebx), %edi\n" /* val, abortLevel */
        "movl 4(%ebx), %esi\n" /* val, elseStatBlock */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        "movl -0x174(%ebp), %edx\n" /* line 3714 */
        "movl %esi, %eax\n" /* continueChildBlocks */
        "calll Scr_CalcLocalVarsStatement\n"
        "cmpl $0x41, (%edi)\n" /* line 3716 | i */
        "je .Lf9300e_000946c1\n"
        "movb $1, -0x111(%ebp)\n" /* constConditional */
        ".Lf9300e_00093840:\n"
        "movl scrCompileGlob+60, %eax\n" /* line 3735 */
        "movl %eax, -0x110(%ebp)\n" /* oldBreakChildBlocks */
        "movl scrCompileGlob+64, %edx\n" /* line 3736 */
        "movl %edx, -0x10c(%ebp)\n" /* oldBreakChildCount */
        "movl scrCompileGlob+72, %ecx\n" /* line 3738 */
        "movl %ecx, -0x108(%ebp)\n" /* oldContinueChildBlocks */
        "movl scrCompileGlob+76, %esi\n" /* line 3739 | continueChildBlocks */
        "movl %esi, -0x104(%ebp)\n" /* continueChildBlocks, oldContinueChildCount */
        "movl $0, -0x1c(%ebp)\n" /* line 3741 | breakChildCount */
        "movl $0, -0x20(%ebp)\n" /* line 3742 | continueChildCount */
        "movl $__mh_execute_header, (%esp)\n" /* line 3744 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %esi\n" /* continueChildBlocks */
        "movl %eax, scrCompileGlob+72\n" /* line 3745 */
        "leal -0x20(%ebp), %eax\n" /* line 3746 | continueChildCount */
        "movl %eax, scrCompileGlob+76\n"
        "cmpb $0, -0x111(%ebp)\n" /* line 3750 | constConditional */
        "jne .Lf9300e_0009465d\n"
        "movl $0, -0xf0(%ebp)\n" /* childBlocks */
        ".Lf9300e_000938af:\n"
        "movl -0xf0(%ebp), %eax\n" /* line 3760 | childBlocks */
        "movl %eax, scrCompileGlob+60\n"
        "movl -0x118(%ebp), %edx\n" /* line 924 | forStatBlock */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf9300e_00094e85\n"
        ".Lf9300e_000938ca:\n"
        "movl (%edx), %eax\n" /* line 926 */
        "movl $0x118, 8(%esp)\n"
        "movl -0x174(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x118(%ebp), %edx\n" /* line 927 | forStatBlock */
        "movl (%edx), %eax\n"
        "movl $0, 8(%eax)\n"
        "movl -0x11c(%ebp), %ecx\n" /* line 924 | forStatPostBlock */
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf9300e_00094edf\n"
        ".Lf9300e_00093905:\n"
        "movl (%ecx), %eax\n" /* line 926 */
        "movl $0x118, 8(%esp)\n"
        "movl -0x174(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x11c(%ebp), %ecx\n" /* line 927 | forStatPostBlock */
        "movl (%ecx), %eax\n"
        "movl $0, 8(%eax)\n"
        "movl -0x118(%ebp), %eax\n" /* line 3765 | forStatBlock */
        "movl (%eax), %edx\n"
        "movl -0x16c(%ebp), %eax\n"
        "calll Scr_CalcLocalVarsStatement\n"
        "movl -0x118(%ebp), %edx\n" /* line 3766 | forStatBlock */
        "movl (%edx), %ebx\n" /* block */
        /* { scope 3: j, childIndex, i, block, ... */
        "movl (%ebx), %eax\n" /* line 3298 | abortLevel */
        "testl %eax, %eax\n"
        "jne .Lf9300e_0009397d\n"
        "movl scrCompileGlob+72, %eax\n" /* line 3300 */
        "testl %eax, %eax\n"
        "je .Lf9300e_0009397d\n"
        "movl scrCompileGlob+76, %eax\n" /* line 886 */
        "cmpl $0x3ff, (%eax)\n"
        "jg .Lf9300e_00094de2\n"
        ".Lf9300e_0009396b:\n"
        "movl (%eax), %edx\n" /* line 3303 */
        "movl scrCompileGlob+72, %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n" /* abortLevel */
        "movl scrCompileGlob+76, %eax\n" /* line 3304 */
        "addl $1, (%eax)\n"
        /* } scope */
        ".Lf9300e_0009397d:\n"
        "movl -0x20(%ebp), %edi\n" /* line 3768 | continueChildCount, i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf9300e_00093dd2\n"
        "movl $1, -0x78(%ebp)\n"
        "addl $4, %esi\n" /* continueChildBlocks */
        "movl %esi, -0x1d4(%ebp)\n" /* continueChildBlocks */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00093998:\n"
        "movl -0x174(%ebp), %ecx\n" /* line 983 */
        "movl (%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf9300e_00093dbb\n"
        "movl -0x1d4(%ebp), %esi\n" /* line 4592 | currentBlock */
        "subl $4, %esi\n" /* currentBlock */
        "movl %esi, -0x74(%ebp)\n" /* currentBlock */
        "movl -0x1d4(%ebp), %edx\n" /* line 989 */
        "movl -4(%edx), %eax\n"
        "movl $0, (%eax)\n"
        "movl -4(%edx), %eax\n" /* line 992 */
        "movl 0xc(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf9300e_00093dbb\n"
        "xorl %edi, %edi\n" /* i */
        "jmp .Lf9300e_000939f0\n"
        ".Lf9300e_000939d5:\n"
        "movl %ecx, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_000939d7:\n"
        "movl %esi, 0x18(%eax, %ebx, 4)\n" /* line 1004 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        "addl $1, 0xc(%eax)\n" /* line 1005 */
        ".Lf9300e_000939df:\n"
        "addl $1, %edi\n" /* line 992 | i */
        "movl -0x74(%ebp), %ecx\n"
        "movl (%ecx), %eax\n"
        "cmpl 0xc(%eax), %edi\n" /* i */
        "jge .Lf9300e_00093dbb\n"
        ".Lf9300e_000939f0:\n"
        "movl 0x18(%eax, %edi, 4), %esi\n" /* line 994 */
        /* { scope 4 */
        "movl -0x174(%ebp), %ecx\n" /* line 764 */
        "movl 0xc(%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf9300e_000939d5\n"
        "movl %ecx, %edx\n"
        "cmpl 0x18(%ecx), %esi\n" /* line 766 */
        "je .Lf9300e_000939df\n"
        "xorl %ecx, %ecx\n"
        ".Lf9300e_00093a0a:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %ebx\n"
        "je .Lf9300e_00093a1f\n"
        "movl 0x1c(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, %esi\n"
        "jne .Lf9300e_00093a0a\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 995 */
        "jns .Lf9300e_000939df\n"
        ".Lf9300e_00093a1f:\n"
        "movl -0x174(%ebp), %eax\n"
        "jmp .Lf9300e_000939d7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 4(%ebx), %esi\n" /* line 4624 | val, elseStatBlock */
        "movl (%esi), %eax\n" /* line 2915 | j */
        "cmpl $4, %eax\n"
        "jne .Lf9300e_000931c6\n"
        "movl 4(%esi), %ebx\n" /* line 2918 | j */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        "movl -0x174(%ebp), %eax\n" /* line 904 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf9300e_000931ad\n"
        "movl %eax, %ecx\n"
        "movl 0xc(%eax), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf9300e_00094839\n"
        "cmpl 0x18(%eax), %ebx\n" /* line 909 */
        "je .Lf9300e_000931ad\n"
        "xorl %edx, %edx\n"
        ".Lf9300e_00093a60:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edi, %edx\n"
        "je .Lf9300e_00094839\n"
        "movl 0x1c(%ecx), %eax\n" /* line 909 */
        "addl $4, %ecx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_00093a60\n"
        "jmp .Lf9300e_000931ad\n"
        /* } scope */
        "movl 4(%ebx), %esi\n" /* line 4628 | val, elseStatBlock */
        "movl (%esi), %eax\n" /* line 2915 | j */
        "cmpl $4, %eax\n"
        "jne .Lf9300e_000931c6\n"
        "movl 4(%esi), %ebx\n" /* line 2918 | j */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        "movl -0x174(%ebp), %esi\n" /* line 904 */
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf9300e_000931ad\n"
        "movl 0xc(%esi), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf9300e_00094dc6\n"
        "cmpl 0x18(%esi), %ebx\n" /* line 909 */
        "je .Lf9300e_000931ad\n"
        "movl %esi, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf9300e_00093ab3:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edi, %edx\n"
        "je .Lf9300e_00094dc6\n"
        "movl 0x1c(%ecx), %eax\n" /* line 909 */
        "addl $4, %ecx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_00093ab3\n"
        "jmp .Lf9300e_000931ad\n"
        /* } scope */
        "movl 4(%ebx), %esi\n" /* line 4632 | val, elseStatBlock */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        "movl (%esi), %eax\n" /* line 4679 | elseStatBlock */
        "movl 4(%eax), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf9300e_000931ad\n"
        ".Lf9300e_00093add:\n"
        "movl (%ebx), %eax\n" /* line 4680 | node */
        "movl -0x174(%ebp), %edx\n"
        "calll Scr_CalcLocalVarsStatement\n"
        "movl 4(%ebx), %ebx\n" /* line 4679 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf9300e_00093add\n"
        "jmp .Lf9300e_000931ad\n"
        /* } scope */
        "movl 8(%ebx), %edi\n" /* line 4640 | val, abortLevel */
        "movl (%edi), %eax\n" /* line 3881 | i */
        "movl 4(%eax), %ebx\n" /* block */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00093afe:\n"
        "movl 4(%ebx), %ebx\n" /* line 3836 | block */
        "testl %ebx, %ebx\n" /* line 3837 | block */
        "je .Lf9300e_000931ad\n"
        "movl (%ebx), %eax\n" /* line 3839 | block */
        "movl (%eax), %esi\n" /* continueChildBlocks */
        /* { scope 2: i, childIndex, i, childCount, ... */
        "movl -0x174(%ebp), %eax\n" /* line 904 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf9300e_00093afe\n"
        "movl -0x174(%ebp), %eax\n" /* line 907 */
        "movl 0xc(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf9300e_00093b42\n"
        "cmpl 0x18(%eax), %esi\n" /* line 909 */
        "je .Lf9300e_00093afe\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        "jmp .Lf9300e_00093b3b\n"
        ".Lf9300e_00093b31:\n"
        "movl 0x1c(%ecx), %eax\n"
        "addl $4, %ecx\n"
        "cmpl %eax, %esi\n"
        "je .Lf9300e_00093afe\n"
        ".Lf9300e_00093b3b:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edi, %edx\n"
        "jne .Lf9300e_00093b31\n"
        ".Lf9300e_00093b42:\n"
        "cmpl $0x3f, %edi\n" /* line 894 */
        "jg .Lf9300e_00094464\n"
        "movl -0x174(%ebp), %ecx\n"
        ".Lf9300e_00093b51:\n"
        "movl %esi, 0x18(%ecx, %edi, 4)\n" /* line 914 */
        "addl $1, 0xc(%ecx)\n" /* line 918 */
        "jmp .Lf9300e_00093afe\n"
        /* } scope */
        /* } scope */
        "leal 0xc(%ebx), %ecx\n" /* line 4636 | val */
        "movl %ecx, -0xdc(%ebp)\n" /* devStatBlock */
        "movl 4(%ebx), %esi\n" /* val, elseStatBlock */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        "movl 0xc(%ebx), %edi\n" /* line 924 */
        "testl %edi, %edi\n"
        "je .Lf9300e_00094ecb\n"
        "movl 0xc(%ebx), %eax\n"
        ".Lf9300e_00093b75:\n"
        "movl $0x118, 8(%esp)\n" /* line 926 */
        "movl -0x174(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0xc(%ebx), %eax\n" /* line 927 */
        "movl $0, 8(%eax)\n"
        "movl 0xc(%ebx), %edi\n" /* line 4687 | node, block */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        "movl (%esi), %eax\n" /* line 4679 | elseStatBlock */
        "movl 4(%eax), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf9300e_00093bb5\n"
        ".Lf9300e_00093ba5:\n"
        "movl (%ebx), %eax\n" /* line 4680 | node */
        "movl %edi, %edx\n" /* abortLevel */
        "calll Scr_CalcLocalVarsStatement\n"
        "movl 4(%ebx), %ebx\n" /* line 4679 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf9300e_00093ba5\n"
        /* } scope */
        /* } scope */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00093bb5:\n"
        "movl -0x174(%ebp), %ecx\n" /* line 1021 */
        "movl (%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf9300e_000931ad\n"
        "movl -0xdc(%ebp), %esi\n" /* line 1026 | devStatBlock, j */
        "movl (%esi), %esi\n" /* j */
        "movl %esi, -0x54(%ebp)\n" /* j */
        "movl 0xc(%ecx), %eax\n" /* line 1028 */
        "movl %eax, 8(%esi)\n" /* j */
        "testl %eax, %eax\n" /* line 1029 */
        "jle .Lf9300e_000931ad\n"
        "addl $0x18, %ecx\n"
        "movl %ecx, -0x70(%ebp)\n"
        "movl %esi, -0x6c(%ebp)\n" /* j */
        "movl $0, -0xd4(%ebp)\n" /* j */
        "addl $0x18, %esi\n" /* j */
        "movl %esi, -0x1b0(%ebp)\n" /* j */
        "movl -0x6c(%ebp), %eax\n"
        "addl $0x1c, %eax\n"
        "movl %eax, -0x1b4(%ebp)\n"
        "movl -0x6c(%ebp), %edx\n"
        "addl $0x10, %edx\n"
        "movl %edx, -0x1b8(%ebp)\n"
        ".Lf9300e_00093c12:\n"
        "movl (%ecx), %ecx\n" /* line 1031 */
        "movl %ecx, -0xd8(%ebp)\n"
        "movl -0x54(%ebp), %esi\n" /* line 764 */
        "movl 0xc(%esi), %ebx\n"
        "movl %ebx, -0x184(%ebp)\n"
        "cmpl %ebx, -0xd4(%ebp)\n" /* j */
        "jge .Lf9300e_0009402d\n"
        "movl -0x6c(%ebp), %eax\n" /* line 766 */
        "cmpl %ecx, 0x18(%eax)\n"
        "je .Lf9300e_00094607\n"
        "movl -0x1b8(%ebp), %edx\n"
        "addl $8, %edx\n"
        "movl -0xd4(%ebp), %ecx\n" /* j */
        "movl %ebx, %edi\n"
        "movl -0x1b4(%ebp), %esi\n"
        "subl -0x1b0(%ebp), %esi\n"
        ".Lf9300e_00093c5b:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %edi\n"
        "je .Lf9300e_0009402d\n"
        "movl (%esi, %edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl -0xd8(%ebp), %eax\n"
        "jne .Lf9300e_00093c5b\n"
        ".Lf9300e_00093c74:\n"
        "testl %ecx, %ecx\n" /* line 1033 */
        "js .Lf9300e_0009402d\n"
        "movl %ecx, %ebx\n"
        ".Lf9300e_00093c7e:\n"
        "cmpl %ebx, -0xd4(%ebp)\n" /* line 1039 | j */
        "jge .Lf9300e_00093cad\n"
        "leal (, %ebx, 4), %eax\n"
        "movl -0x54(%ebp), %esi\n" /* j */
        "leal 0x14(%eax, %esi), %ecx\n"
        "leal 0x18(%eax, %esi), %edx\n"
        ".Lf9300e_00093c98:\n"
        "subl $1, %ebx\n" /* line 1041 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0xd4(%ebp)\n" /* line 1039 | j */
        "jl .Lf9300e_00093c98\n"
        ".Lf9300e_00093cad:\n"
        "movl -0xd8(%ebp), %edx\n" /* line 1044 */
        "movl -0x6c(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "addl $1, -0xd4(%ebp)\n" /* line 1029 | j */
        "addl $4, -0x1b8(%ebp)\n"
        "addl $4, -0x1b4(%ebp)\n"
        "addl $4, -0x1b0(%ebp)\n"
        "addl $4, -0x70(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0xd4(%ebp), %esi\n" /* j */
        "movl -0x174(%ebp), %ecx\n"
        "cmpl 0xc(%ecx), %esi\n" /* j */
        "jge .Lf9300e_000931ad\n"
        "movl -0x70(%ebp), %ecx\n"
        "jmp .Lf9300e_00093c12\n"
        /* } scope */
        /* } scope */
        "movl -0x174(%ebp), %esi\n" /* line 3286 | j */
        "movl (%esi), %edi\n" /* j, i */
        "testl %edi, %edi\n" /* i */
        "jne .Lf9300e_00093d45\n"
        "movl scrCompileGlob+60, %ebx\n" /* line 3288 | abortLevel */
        "testl %ebx, %ebx\n" /* abortLevel */
        "je .Lf9300e_00094e3c\n"
        "movl scrCompileGlob+64, %eax\n" /* line 886 */
        "cmpl $0x3ff, (%eax)\n"
        "jg .Lf9300e_00094e00\n"
        ".Lf9300e_00093d27:\n"
        "movl (%eax), %edx\n" /* line 3291 */
        "movl scrCompileGlob+60, %eax\n"
        "movl -0x174(%ebp), %ecx\n"
        "movl %ecx, (%eax, %edx, 4)\n"
        "movl scrCompileGlob+64, %eax\n" /* line 3292 */
        "addl $1, (%eax)\n"
        "movl -0x174(%ebp), %esi\n" /* j */
        ".Lf9300e_00093d45:\n"
        "movl (%esi), %ecx\n" /* line 4649 | elseStatBlock */
        "testl %ecx, %ecx\n"
        "jne .Lf9300e_000931ad\n"
        "movl $2, (%esi)\n" /* line 4650 | elseStatBlock */
        "jmp .Lf9300e_000931ad\n"
        "movl -0x174(%ebp), %eax\n" /* line 3298 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf9300e_0009458b\n"
        "movl scrCompileGlob+72, %eax\n" /* line 3300 */
        "testl %eax, %eax\n"
        "je .Lf9300e_00094e47\n"
        "movl scrCompileGlob+76, %eax\n" /* line 886 */
        "cmpl $0x3ff, (%eax)\n"
        "jg .Lf9300e_00094da8\n"
        ".Lf9300e_00093d88:\n"
        "movl (%eax), %edx\n" /* line 3303 */
        "movl scrCompileGlob+72, %eax\n"
        "movl -0x174(%ebp), %ecx\n"
        "movl %ecx, (%eax, %edx, 4)\n"
        "movl scrCompileGlob+76, %eax\n" /* line 3304 */
        "addl $1, (%eax)\n"
        "movl -0x174(%ebp), %esi\n" /* j */
        ".Lf9300e_00093da6:\n"
        "movl (%esi), %eax\n" /* line 4655 | elseStatBlock */
        "testl %eax, %eax\n"
        "jne .Lf9300e_000931ad\n"
        "movl $1, (%esi)\n" /* line 4656 | elseStatBlock */
        "jmp .Lf9300e_000931ad\n"
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00093dbb:\n"
        "movl -0x78(%ebp), %eax\n" /* line 992 */
        "addl $1, -0x78(%ebp)\n"
        "addl $4, -0x1d4(%ebp)\n"
        /* } scope */
        "cmpl -0x20(%ebp), %eax\n" /* line 3768 | continueChildCount */
        "jl .Lf9300e_00093998\n"
        ".Lf9300e_00093dd2:\n"
        "movl -0x11c(%ebp), %esi\n" /* line 3771 | forStatPostBlock, continueChildBlocks */
        "movl (%esi), %edx\n" /* continueChildBlocks */
        "movl -0x170(%ebp), %eax\n"
        "calll Scr_CalcLocalVarsStatement\n"
        /* { scope 3: j, childIndex, i, block, ... */
        "movl -0x174(%ebp), %eax\n" /* line 983 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf9300e_00094111\n"
        "movl (%esi), %eax\n" /* line 989 */
        "movl $0, (%eax)\n"
        "movl (%esi), %edi\n" /* line 992 | i */
        "movl 0xc(%edi), %eax\n" /* i */
        "testl %eax, %eax\n"
        "jle .Lf9300e_0009410b\n"
        "movl $0, -0x100(%ebp)\n" /* i */
        "movl -0x100(%ebp), %edx\n" /* i */
        "jmp .Lf9300e_00093e46\n"
        ".Lf9300e_00093e1c:\n"
        "movl %ecx, %eax\n"
        /* } scope */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00093e1e:\n"
        "movl %esi, 0x18(%eax, %ebx, 4)\n" /* line 1004 */
        /* } scope */
        /* { scope 3: j, childIndex, i, block, ... */
        "addl $1, 0xc(%eax)\n" /* line 1005 */
        "movl -0x11c(%ebp), %edx\n" /* forStatPostBlock */
        "movl (%edx), %edi\n" /* i */
        ".Lf9300e_00093e2e:\n"
        "addl $1, -0x100(%ebp)\n" /* line 992 | i */
        "movl -0x100(%ebp), %esi\n" /* i */
        "cmpl 0xc(%edi), %esi\n" /* i */
        "jge .Lf9300e_0009410b\n"
        "movl %esi, %edx\n"
        ".Lf9300e_00093e46:\n"
        "movl 0x18(%edi, %edx, 4), %esi\n" /* line 994 | i */
        /* { scope 4 */
        "movl -0x174(%ebp), %ecx\n" /* line 764 */
        "movl 0xc(%ecx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf9300e_00093e1c\n"
        "cmpl 0x18(%ecx), %esi\n" /* line 766 */
        "je .Lf9300e_00093e2e\n"
        "movl %ecx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf9300e_00093e60:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %ebx\n"
        "je .Lf9300e_00093e75\n"
        "movl 0x1c(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, %esi\n"
        "jne .Lf9300e_00093e60\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 995 */
        "jns .Lf9300e_00093e2e\n"
        ".Lf9300e_00093e75:\n"
        "movl -0x174(%ebp), %eax\n"
        "jmp .Lf9300e_00093e1e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00093e7d:\n"
        "movl -0x90(%ebp), %eax\n" /* line 992 */
        "addl $1, -0x90(%ebp)\n"
        "addl $4, -0x1e4(%ebp)\n"
        /* } scope */
        "cmpl %eax, -0x20(%ebp)\n" /* line 3516 | continueChildCount */
        "jg .Lf9300e_00093764\n"
        ".Lf9300e_00093e9a:\n"
        "cmpb $0, -0x145(%ebp)\n" /* line 3519 | constConditional */
        "je .Lf9300e_00094459\n"
        "movl -0x1c(%ebp), %eax\n" /* line 3520 | breakChildCount */
        "movl %eax, -0x134(%ebp)\n" /* childCount */
        /* { scope 3: j, childIndex, i, block, ... */
        /* { scope 4 */
        "testl %eax, %eax\n" /* line 983 */
        "je .Lf9300e_00094459\n"
        "movl -0x174(%ebp), %edx\n"
        "movl (%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf9300e_00094c8d\n"
        /* } scope */
        /* } scope */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00093ec8:\n"
        "movl (%edx), %eax\n" /* line 1021 */
        "testl %eax, %eax\n"
        "jne .Lf9300e_000940d7\n"
        "movl -0x14c(%ebp), %ecx\n" /* line 1026 | whileStatBlock */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x120(%ebp)\n" /* block */
        "movl 0xc(%edx), %eax\n" /* line 1028 */
        "movl %eax, 8(%ecx)\n"
        "testl %eax, %eax\n" /* line 1029 */
        "jle .Lf9300e_000940d7\n"
        "addl $0x18, %edx\n"
        "movl %edx, -0x98(%ebp)\n"
        "movl %ecx, -0x94(%ebp)\n"
        "movl $0, -0x124(%ebp)\n" /* j */
        "addl $0x18, %ecx\n"
        "movl %ecx, -0x1d8(%ebp)\n"
        "movl -0x94(%ebp), %esi\n" /* j */
        "addl $0x1c, %esi\n" /* j */
        "movl %esi, -0x1dc(%ebp)\n" /* j */
        "movl -0x94(%ebp), %eax\n"
        "addl $0x10, %eax\n"
        "movl %eax, -0x1e0(%ebp)\n"
        ".Lf9300e_00093f2e:\n"
        "movl (%edx), %edx\n" /* line 1031 */
        "movl %edx, -0x128(%ebp)\n"
        /* { scope 4 */
        "movl -0x120(%ebp), %ecx\n" /* line 764 | block */
        "movl 0xc(%ecx), %ebx\n"
        "movl %ebx, -0x178(%ebp)\n"
        "cmpl %ebx, -0x124(%ebp)\n" /* j */
        "jge .Lf9300e_000940ac\n"
        "movl -0x94(%ebp), %esi\n" /* line 766 */
        "cmpl 0x18(%esi), %edx\n"
        "je .Lf9300e_0009461d\n"
        "movl -0x1e0(%ebp), %edx\n"
        "addl $8, %edx\n"
        "movl -0x124(%ebp), %ecx\n" /* j */
        "movl %ebx, %edi\n"
        "movl -0x1dc(%ebp), %esi\n"
        "subl -0x1d8(%ebp), %esi\n"
        ".Lf9300e_00093f7d:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %edi\n"
        "je .Lf9300e_000940ac\n"
        "movl (%esi, %edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0x128(%ebp)\n"
        "jne .Lf9300e_00093f7d\n"
        /* } scope */
        ".Lf9300e_00093f96:\n"
        "testl %ecx, %ecx\n" /* line 1033 */
        "js .Lf9300e_000940ac\n"
        "movl %ecx, %ebx\n"
        ".Lf9300e_00093fa0:\n"
        "cmpl %ebx, -0x124(%ebp)\n" /* line 1039 | j */
        "jge .Lf9300e_00093fd2\n"
        "leal (, %ebx, 4), %eax\n"
        "movl -0x120(%ebp), %esi\n" /* block, j */
        "leal 0x14(%eax, %esi), %ecx\n"
        "leal 0x18(%eax, %esi), %edx\n"
        ".Lf9300e_00093fbd:\n"
        "subl $1, %ebx\n" /* line 1041 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x124(%ebp)\n" /* line 1039 | j */
        "jl .Lf9300e_00093fbd\n"
        ".Lf9300e_00093fd2:\n"
        "movl -0x128(%ebp), %edx\n" /* line 1044 */
        "movl -0x94(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "addl $1, -0x124(%ebp)\n" /* line 1029 | j */
        "addl $4, -0x1e0(%ebp)\n"
        "addl $4, -0x1dc(%ebp)\n"
        "addl $4, -0x1d8(%ebp)\n"
        "addl $4, -0x98(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0x94(%ebp)\n"
        "movl -0x124(%ebp), %esi\n" /* j */
        "movl -0x174(%ebp), %ecx\n"
        "cmpl 0xc(%ecx), %esi\n" /* j */
        "jge .Lf9300e_000940d7\n"
        "movl -0x98(%ebp), %edx\n"
        "jmp .Lf9300e_00093f2e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_0009402d:\n"
        "cmpl $0x3f, %ebx\n" /* line 894 */
        "jg .Lf9300e_000944f8\n"
        "movl -0x184(%ebp), %eax\n"
        ".Lf9300e_0009403c:\n"
        "addl $1, %eax\n" /* line 1037 */
        "movl -0x54(%ebp), %ecx\n"
        "movl %eax, 0xc(%ecx)\n"
        "jmp .Lf9300e_00093c7e\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_0009404a:\n"
        "cmpl $0x3f, %ebx\n" /* line 894 */
        "jg .Lf9300e_000944d1\n"
        "movl -0x18c(%ebp), %eax\n"
        ".Lf9300e_00094059:\n"
        "addl $1, %eax\n" /* line 1037 */
        "movl -0x5c(%ebp), %ecx\n"
        "movl %eax, 0xc(%ecx)\n"
        "jmp .Lf9300e_00093303\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        /* { scope 4 */
        ".Lf9300e_00094067:\n"
        "addl $1, -0x150(%ebp)\n" /* line 1024 | childIndex */
        "movl -0x150(%ebp), %eax\n" /* childIndex */
        "cmpl %eax, -0x15c(%ebp)\n" /* childCount */
        "jne .Lf9300e_0009348d\n"
        "jmp .Lf9300e_000931ad\n"
        ".Lf9300e_00094085:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x60(%ebp), %edx\n"
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x190(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf9300e_00093613\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_000940ac:\n"
        "cmpl $0x3f, %ebx\n" /* line 894 */
        "jg .Lf9300e_00094592\n"
        "movl -0x178(%ebp), %eax\n"
        ".Lf9300e_000940bb:\n"
        "addl $1, %eax\n" /* line 1037 */
        "movl -0x120(%ebp), %edx\n" /* block */
        "movl %eax, 0xc(%edx)\n"
        "jmp .Lf9300e_00093fa0\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        /* { scope 4 */
        ".Lf9300e_000940cc:\n"
        "movl -0x154(%ebp), %ecx\n" /* line 764 | j */
        "jmp .Lf9300e_00093555\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_000940d7:\n"
        "movl -0x144(%ebp), %eax\n" /* line 3524 | oldBreakChildBlocks */
        "movl %eax, scrCompileGlob+60\n"
        "movl -0x140(%ebp), %edx\n" /* line 3525 | oldBreakChildCount */
        "movl %edx, scrCompileGlob+64\n"
        "movl -0x13c(%ebp), %ecx\n" /* line 3527 | oldContinueChildBlocks */
        "movl %ecx, scrCompileGlob+72\n"
        "movl -0x138(%ebp), %esi\n" /* line 3528 | oldContinueChildCount, continueChildBlocks */
        "movl %esi, scrCompileGlob+76\n" /* continueChildBlocks */
        "jmp .Lf9300e_000931ad\n"
        ".Lf9300e_0009410b:\n"
        "movl -0x174(%ebp), %eax\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00094111:\n"
        "movl (%eax), %edi\n" /* line 1021 | i */
        "testl %edi, %edi\n" /* i */
        "jne .Lf9300e_0009426b\n"
        "movl -0x11c(%ebp), %edx\n" /* line 1026 | forStatPostBlock */
        "movl (%edx), %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl %eax, %ecx\n" /* line 1028 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 8(%edx)\n"
        "testl %eax, %eax\n" /* line 1029 */
        "jle .Lf9300e_0009426b\n"
        "addl $0x18, %ecx\n"
        "movl %ecx, -0x80(%ebp)\n"
        "movl %edx, -0x7c(%ebp)\n"
        "movl $0, -0xf8(%ebp)\n" /* j */
        "addl $0x18, %edx\n"
        "movl %edx, -0x1c8(%ebp)\n"
        "movl -0x7c(%ebp), %esi\n" /* j */
        "addl $0x1c, %esi\n" /* j */
        "movl %esi, -0x1cc(%ebp)\n" /* j */
        "movl -0x7c(%ebp), %eax\n"
        "addl $0x10, %eax\n"
        "movl %eax, -0x1d0(%ebp)\n"
        "movl %ecx, %edx\n"
        ".Lf9300e_0009416c:\n"
        "movl (%edx), %edx\n" /* line 1031 */
        "movl %edx, -0xfc(%ebp)\n"
        "movl -0x58(%ebp), %ecx\n" /* line 764 */
        "movl 0xc(%ecx), %ebx\n"
        "movl %ebx, -0x188(%ebp)\n"
        "cmpl %ebx, -0xf8(%ebp)\n" /* j */
        "jge .Lf9300e_0009424e\n"
        "movl -0x7c(%ebp), %esi\n" /* line 766 */
        "cmpl %edx, 0x18(%esi)\n"
        "je .Lf9300e_00094633\n"
        "movl -0x1d0(%ebp), %edx\n"
        "addl $8, %edx\n"
        "movl -0xf8(%ebp), %ecx\n" /* j */
        "movl %ebx, %edi\n"
        "movl -0x1cc(%ebp), %esi\n"
        "subl -0x1c8(%ebp), %esi\n"
        ".Lf9300e_000941b5:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %edi, %ecx\n"
        "je .Lf9300e_0009424e\n"
        "movl (%esi, %edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl -0xfc(%ebp), %eax\n"
        "jne .Lf9300e_000941b5\n"
        ".Lf9300e_000941ce:\n"
        "testl %ecx, %ecx\n" /* line 1033 */
        "js .Lf9300e_0009424e\n"
        "movl %ecx, %ebx\n"
        ".Lf9300e_000941d4:\n"
        "cmpl %ebx, -0xf8(%ebp)\n" /* line 1039 | j */
        "jge .Lf9300e_00094203\n"
        "leal (, %ebx, 4), %eax\n"
        "movl -0x58(%ebp), %esi\n" /* j */
        "leal 0x14(%eax, %esi), %ecx\n"
        "leal 0x18(%eax, %esi), %edx\n"
        ".Lf9300e_000941ee:\n"
        "subl $1, %ebx\n" /* line 1041 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0xf8(%ebp)\n" /* line 1039 | j */
        "jl .Lf9300e_000941ee\n"
        ".Lf9300e_00094203:\n"
        "movl -0xfc(%ebp), %edx\n" /* line 1044 */
        "movl -0x7c(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "addl $1, -0xf8(%ebp)\n" /* line 1029 | j */
        "addl $4, -0x1d0(%ebp)\n"
        "addl $4, -0x1cc(%ebp)\n"
        "addl $4, -0x1c8(%ebp)\n"
        "addl $4, -0x80(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl -0xf8(%ebp), %esi\n" /* j */
        "movl -0x174(%ebp), %ecx\n"
        "cmpl %esi, 0xc(%ecx)\n" /* j */
        "jle .Lf9300e_0009426b\n"
        "movl -0x80(%ebp), %edx\n"
        "jmp .Lf9300e_0009416c\n"
        ".Lf9300e_0009424e:\n"
        "cmpl $0x3f, %ebx\n" /* line 894 */
        "jg .Lf9300e_000945ba\n"
        "movl -0x188(%ebp), %eax\n"
        ".Lf9300e_0009425d:\n"
        "addl $1, %eax\n" /* line 1037 */
        "movl -0x58(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "jmp .Lf9300e_000941d4\n"
        /* } scope */
        ".Lf9300e_0009426b:\n"
        "cmpb $0, -0x111(%ebp)\n" /* line 3775 | constConditional */
        "je .Lf9300e_0009444e\n"
        "movl -0x1c(%ebp), %eax\n" /* line 3776 | breakChildCount */
        "movl %eax, -0xf4(%ebp)\n" /* childCount */
        /* { scope 3: j, childIndex, i, block, ... */
        /* { scope 4 */
        "testl %eax, %eax\n" /* line 983 */
        "je .Lf9300e_0009444e\n"
        "movl -0x174(%ebp), %edx\n"
        "movl (%edx), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf9300e_00094b72\n"
        /* } scope */
        /* } scope */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00094299:\n"
        "movl (%edx), %ecx\n" /* line 1021 */
        "testl %ecx, %ecx\n"
        "jne .Lf9300e_0009441a\n"
        "movl -0x118(%ebp), %ecx\n" /* line 1026 | forStatBlock */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0xe0(%ebp)\n" /* block */
        "movl 0xc(%edx), %eax\n" /* line 1028 */
        "movl %eax, 8(%ecx)\n"
        "testl %eax, %eax\n" /* line 1029 */
        "jle .Lf9300e_0009441a\n"
        "addl $0x18, %edx\n"
        "movl %edx, -0x88(%ebp)\n"
        "movl %ecx, -0x84(%ebp)\n"
        "movl $0, -0xe4(%ebp)\n" /* j */
        "addl $0x18, %ecx\n"
        "movl %ecx, -0x1bc(%ebp)\n"
        "movl -0x84(%ebp), %esi\n" /* j */
        "addl $0x1c, %esi\n" /* j */
        "movl %esi, -0x1c0(%ebp)\n" /* j */
        "movl -0x84(%ebp), %eax\n"
        "addl $0x10, %eax\n"
        "movl %eax, -0x1c4(%ebp)\n"
        ".Lf9300e_000942ff:\n"
        "movl (%edx), %edx\n" /* line 1031 */
        "movl %edx, -0xe8(%ebp)\n"
        /* { scope 4 */
        "movl -0xe0(%ebp), %ecx\n" /* line 764 | block */
        "movl 0xc(%ecx), %ebx\n"
        "movl %ebx, -0x1a0(%ebp)\n"
        "cmpl %ebx, -0xe4(%ebp)\n" /* j */
        "jge .Lf9300e_000943fa\n"
        "movl -0x84(%ebp), %esi\n" /* line 766 */
        "cmpl 0x18(%esi), %edx\n"
        "je .Lf9300e_00094628\n"
        "movl -0x1c4(%ebp), %edx\n"
        "addl $8, %edx\n"
        "movl -0xe4(%ebp), %ecx\n" /* j */
        "movl %ebx, %edi\n"
        "movl -0x1c0(%ebp), %esi\n"
        "subl -0x1bc(%ebp), %esi\n"
        ".Lf9300e_0009434e:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %edi\n"
        "je .Lf9300e_000943fa\n"
        "movl (%esi, %edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0xe8(%ebp)\n"
        "jne .Lf9300e_0009434e\n"
        /* } scope */
        ".Lf9300e_00094367:\n"
        "testl %ecx, %ecx\n" /* line 1033 */
        "js .Lf9300e_000943fa\n"
        "movl %ecx, %ebx\n"
        ".Lf9300e_00094371:\n"
        "cmpl %ebx, -0xe4(%ebp)\n" /* line 1039 | j */
        "jge .Lf9300e_000943a3\n"
        "leal (, %ebx, 4), %eax\n"
        "movl -0xe0(%ebp), %esi\n" /* block, j */
        "leal 0x14(%eax, %esi), %ecx\n"
        "leal 0x18(%eax, %esi), %edx\n"
        ".Lf9300e_0009438e:\n"
        "subl $1, %ebx\n" /* line 1041 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0xe4(%ebp)\n" /* line 1039 | j */
        "jl .Lf9300e_0009438e\n"
        ".Lf9300e_000943a3:\n"
        "movl -0xe8(%ebp), %edx\n" /* line 1044 */
        "movl -0x84(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "addl $1, -0xe4(%ebp)\n" /* line 1029 | j */
        "addl $4, -0x1c4(%ebp)\n"
        "addl $4, -0x1c0(%ebp)\n"
        "addl $4, -0x1bc(%ebp)\n"
        "addl $4, -0x88(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0x84(%ebp)\n"
        "movl -0xe4(%ebp), %esi\n" /* j */
        "movl -0x174(%ebp), %ecx\n"
        "cmpl 0xc(%ecx), %esi\n" /* j */
        "jge .Lf9300e_0009441a\n"
        "movl -0x88(%ebp), %edx\n"
        "jmp .Lf9300e_000942ff\n"
        ".Lf9300e_000943fa:\n"
        "cmpl $0x3f, %ebx\n" /* line 894 */
        "jg .Lf9300e_000945df\n"
        "movl -0x1a0(%ebp), %eax\n"
        ".Lf9300e_00094409:\n"
        "addl $1, %eax\n" /* line 1037 */
        "movl -0xe0(%ebp), %edx\n" /* block */
        "movl %eax, 0xc(%edx)\n"
        "jmp .Lf9300e_00094371\n"
        /* } scope */
        ".Lf9300e_0009441a:\n"
        "movl -0x110(%ebp), %eax\n" /* line 3780 | oldBreakChildBlocks */
        "movl %eax, scrCompileGlob+60\n"
        "movl -0x10c(%ebp), %edx\n" /* line 3781 | oldBreakChildCount */
        "movl %edx, scrCompileGlob+64\n"
        "movl -0x108(%ebp), %ecx\n" /* line 3783 | oldContinueChildBlocks */
        "movl %ecx, scrCompileGlob+72\n"
        "movl -0x104(%ebp), %esi\n" /* line 3784 | oldContinueChildCount, continueChildBlocks */
        "movl %esi, scrCompileGlob+76\n" /* continueChildBlocks */
        "jmp .Lf9300e_000931ad\n"
        ".Lf9300e_0009444e:\n"
        "movl -0x174(%ebp), %edx\n"
        "jmp .Lf9300e_00094299\n"
        ".Lf9300e_00094459:\n"
        "movl -0x174(%ebp), %edx\n"
        "jmp .Lf9300e_00093ec8\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094464:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x174(%ebp), %edx\n"
        "movl 0xc(%edx), %edi\n"
        "movl %edx, %ecx\n"
        "jmp .Lf9300e_00093b51\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00094488:\n"
        "movl $0x118, (%esp)\n" /* line 925 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %esi\n"
        "movl $0x118, 8(%esp)\n" /* line 926 */
        "movl -0x174(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0, 8(%esi)\n" /* line 927 */
        "movl (%ebx), %eax\n" /* line 4164 | node */
        "cmpl $0x3d, (%eax)\n"
        "je .Lf9300e_00094855\n"
        "movl %esi, 8(%eax)\n" /* line 4170 | currentBlock */
        "movb $1, -0xc5(%ebp)\n" /* hasDefault */
        "jmp .Lf9300e_000930de\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_000944d1:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x5c(%ebp), %edx\n"
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x18c(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf9300e_00094059\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_000944f8:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* "LOCAL_VAR_STACK_SIZE exceeded" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x54(%ebp), %edx\n"
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x184(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf9300e_0009403c\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_0009451f:\n"
        "movl $0, (%esi)\n" /* line 4185 | currentBlock */
        "cmpl $0x3ff, -0xb8(%ebp)\n" /* line 886 | childCount */
        "jg .Lf9300e_0009487f\n"
        ".Lf9300e_00094535:\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 4189 | childCount */
        "movl -0xb4(%ebp), %eax\n" /* childBlocks */
        "movl %esi, (%eax, %ecx, 4)\n" /* currentBlock */
        "addl $1, %ecx\n" /* line 4190 */
        "movl %ecx, -0xb8(%ebp)\n" /* childCount */
        "xorl %edi, %edi\n" /* abortLevel */
        "jmp .Lf9300e_000930dc\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094554:\n"
        "testl %ecx, %ecx\n" /* line 3270 */
        "jne .Lf9300e_0009343f\n"
        "movl -0x15c(%ebp), %esi\n" /* line 3272 | childCount, j */
        "movl %eax, -0x2c(%ebp, %esi, 4)\n"
        "addl $1, %esi\n" /* line 3273 | j */
        "movl %esi, -0x15c(%ebp)\n" /* j, childCount */
        "jmp .Lf9300e_0009343f\n"
        ".Lf9300e_00094574:\n"
        "testl %ebx, %ebx\n" /* line 3258 | abortLevel */
        "je .Lf9300e_00094723\n"
        "movl $0, -0x15c(%ebp)\n" /* childCount */
        "jmp .Lf9300e_000933f5\n"
        ".Lf9300e_0009458b:\n"
        "movl %eax, %esi\n" /* j */
        "jmp .Lf9300e_00093da6\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00094592:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x120(%ebp), %eax\n" /* block */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x178(%ebp)\n"
        "jmp .Lf9300e_000940bb\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_000945ba:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* "LOCAL_VAR_STACK_SIZE exceeded" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x58(%ebp), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x188(%ebp)\n"
        "jmp .Lf9300e_0009425d\n"
        /* } scope */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_000945df:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* "LOCAL_VAR_STACK_SIZE exceeded" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0xe0(%ebp), %eax\n" /* block */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x1a0(%ebp)\n"
        "jmp .Lf9300e_00094409\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094607:\n"
        "movl -0xd4(%ebp), %ecx\n" /* line 764 | j */
        "jmp .Lf9300e_00093c74\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00094612:\n"
        "movl -0x164(%ebp), %ecx\n" /* j */
        "jmp .Lf9300e_000932f9\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        /* { scope 4 */
        ".Lf9300e_0009461d:\n"
        "movl -0x124(%ebp), %ecx\n" /* j */
        "jmp .Lf9300e_00093f96\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        /* { scope 4 */
        ".Lf9300e_00094628:\n"
        "movl -0xe4(%ebp), %ecx\n" /* j */
        "jmp .Lf9300e_00094367\n"
        /* } scope */
        /* } scope */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00094633:\n"
        "movl -0xf8(%ebp), %ecx\n" /* j */
        "jmp .Lf9300e_000941ce\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_0009463e:\n"
        "movl $__mh_execute_header, (%esp)\n" /* line 3502 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, -0x130(%ebp)\n" /* childBlocks */
        "leal -0x1c(%ebp), %eax\n" /* line 3503 | breakChildCount */
        "movl %eax, scrCompileGlob+64\n"
        "jmp .Lf9300e_000936ba\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_0009465d:\n"
        "movl $__mh_execute_header, (%esp)\n" /* line 3752 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, -0xf0(%ebp)\n" /* childBlocks */
        "leal -0x1c(%ebp), %eax\n" /* line 3753 | breakChildCount */
        "movl %eax, scrCompileGlob+64\n"
        "jmp .Lf9300e_000938af\n"
        /* } scope */
        /* } scope */
        ".Lf9300e_0009467c:\n"
        "movl 4(%esi), %ebx\n" /* line 2918 | j */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        "movl -0x174(%ebp), %eax\n" /* line 904 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf9300e_000931ad\n"
        "movl 0xc(%eax), %edi\n" /* line 907 */
        "testl %edi, %edi\n"
        "jle .Lf9300e_00094839\n"
        "cmpl %ebx, 0x18(%eax)\n" /* line 909 */
        "je .Lf9300e_000931ad\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf9300e_000946a7:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %edx, %edi\n"
        "je .Lf9300e_00094839\n"
        "movl 0x1c(%ecx), %eax\n" /* line 909 */
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n"
        "jne .Lf9300e_000946a7\n"
        "jmp .Lf9300e_000931ad\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_000946c1:\n"
        "movl 4(%edi), %eax\n" /* line 3719 | i */
        "movl (%eax), %edx\n" /* line 2833 */
        "cmpl $6, %edx\n"
        "je .Lf9300e_00094efe\n"
        "cmpl $0x31, %edx\n"
        "je .Lf9300e_00094f61\n"
        ".Lf9300e_000946d8:\n"
        "movb $0, -0x111(%ebp)\n" /* line 3719 | constConditional */
        "jmp .Lf9300e_00093840\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_000946e4:\n"
        "movl 4(%esi), %esi\n" /* line 2836 | j */
        "leal -0x2c(%ebp), %edx\n" /* childBlocks */
        "movl %esi, %eax\n" /* j */
        "calll EvalPrimitiveExpression\n"
        ".Lf9300e_000946f1:\n"
        "testb %al, %al\n" /* line 3474 */
        "je .Lf9300e_00093644\n"
        "movl -0x28(%ebp), %edx\n" /* line 3476 */
        "leal -5(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf9300e_00094fc2\n"
        ".Lf9300e_00094708:\n"
        "movb $0, -0x145(%ebp)\n" /* line 3479 | constConditional */
        ".Lf9300e_0009470f:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 252 | childBlocks */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "jmp .Lf9300e_0009364b\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094723:\n"
        "movl %eax, -0x2c(%ebp)\n" /* line 3260 | childBlocks */
        "movl $1, -0x15c(%ebp)\n" /* childCount */
        "jmp .Lf9300e_000933f5\n"
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00094735:\n"
        "movl -0x15c(%ebp), %ecx\n" /* line 986 | childCount */
        "testl %ecx, %ecx\n"
        "jle .Lf9300e_00094756\n"
        "xorl %edx, %edx\n" /* line 983 */
        ".Lf9300e_00094741:\n"
        "movl -0x2c(%ebp, %edx, 4), %eax\n" /* line 989 */
        "movl $0, (%eax)\n"
        "addl $1, %edx\n" /* line 986 */
        "cmpl %edx, -0x15c(%ebp)\n" /* childCount */
        "jne .Lf9300e_00094741\n"
        ".Lf9300e_00094756:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 992 | childBlocks */
        "movl %ecx, -0x17c(%ebp)\n"
        "movl 0xc(%ecx), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf9300e_000947c1\n"
        "movl $0, -0x160(%ebp)\n" /* i */
        "movl -0x160(%ebp), %esi\n" /* i */
        "movl -0x17c(%ebp), %eax\n"
        ".Lf9300e_0009477c:\n"
        "movl 0x18(%eax, %esi, 4), %ebx\n" /* line 994 */
        /* { scope 4 */
        "movl -0x174(%ebp), %edx\n" /* line 764 */
        "movl 0xc(%edx), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf9300e_000947cc\n"
        "cmpl 0x18(%edx), %ebx\n" /* line 766 */
        "je .Lf9300e_000947a9\n"
        "xorl %ecx, %ecx\n"
        ".Lf9300e_00094794:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %esi\n"
        "je .Lf9300e_000947cc\n"
        "movl 0x1c(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_00094794\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 995 */
        "js .Lf9300e_000947cc\n"
        ".Lf9300e_000947a9:\n"
        "movl -0x17c(%ebp), %eax\n"
        ".Lf9300e_000947af:\n"
        "addl $1, -0x160(%ebp)\n" /* line 992 | i */
        "movl -0x160(%ebp), %esi\n" /* i */
        "cmpl %esi, 0xc(%eax)\n"
        "jg .Lf9300e_0009477c\n"
        ".Lf9300e_000947c1:\n"
        "movl -0x174(%ebp), %edx\n"
        "jmp .Lf9300e_0009346b\n"
        ".Lf9300e_000947cc:\n"
        "cmpl $1, -0x15c(%ebp)\n" /* line 998 | childCount */
        "jle .Lf9300e_0009481b\n"
        "movl $1, -0x3c(%ebp)\n" /* line 995 */
        "movl -0x3c(%ebp), %ecx\n"
        ".Lf9300e_000947df:\n"
        "movl -0x2c(%ebp, %ecx, 4), %eax\n" /* line 1000 | block */
        /* { scope 4 */
        /* { scope 5 */
        "movl 0xc(%eax), %edi\n" /* line 764 */
        "testl %edi, %edi\n"
        "jle .Lf9300e_000947a9\n"
        "cmpl 0x18(%eax), %ebx\n" /* line 766 */
        "je .Lf9300e_00094808\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf9300e_000947f3:\n"
        "addl $1, %edx\n" /* line 764 */
        "cmpl %edx, %edi\n"
        "je .Lf9300e_000947a9\n"
        "movl 0x1c(%ecx), %eax\n" /* line 766 */
        "addl $4, %ecx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_000947f3\n"
        /* } scope */
        /* } scope */
        "testl %edx, %edx\n" /* line 1000 */
        "js .Lf9300e_000947a9\n"
        ".Lf9300e_00094808:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 998 */
        "movl -0x3c(%ebp), %eax\n"
        "cmpl %eax, -0x15c(%ebp)\n" /* childCount */
        "je .Lf9300e_0009481b\n"
        "movl %eax, %ecx\n"
        "jmp .Lf9300e_000947df\n"
        ".Lf9300e_0009481b:\n"
        "movl -0x174(%ebp), %edx\n" /* line 1004 */
        "movl %ebx, 0x18(%edx, %esi, 4)\n"
        "addl $1, 0xc(%edx)\n" /* line 1005 */
        "movl -0x2c(%ebp), %ecx\n" /* childBlocks */
        "movl %ecx, -0x17c(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf9300e_000947af\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00094839:\n"
        "cmpl $0x3f, %edi\n" /* line 894 */
        "jg .Lf9300e_00094f3d\n"
        "movl -0x174(%ebp), %ecx\n"
        ".Lf9300e_00094848:\n"
        "movl %ebx, 0x18(%ecx, %edi, 4)\n" /* line 914 */
        "addl $1, 0xc(%ecx)\n" /* line 918 */
        "jmp .Lf9300e_000931ad\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00094855:\n"
        "movl %esi, 0xc(%eax)\n" /* line 4166 | currentBlock */
        "jmp .Lf9300e_000930de\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_0009485d:\n"
        "movl 0x10(%esi), %ebx\n" /* line 2839 | j */
        "movl 0xc(%esi), %ecx\n" /* j */
        "movl 8(%esi), %edx\n" /* j */
        "movl 4(%esi), %esi\n" /* j */
        "leal -0x2c(%ebp), %eax\n" /* childBlocks */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl %esi, %eax\n" /* j */
        "calll EvalBinaryOperatorExpression\n"
        "jmp .Lf9300e_000946f1\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_0009487f:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* line 888 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf9300e_00094535\n"
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00094898:\n"
        "movl -0xc4(%ebp), %eax\n" /* line 986 | childCount */
        "testl %eax, %eax\n"
        "jle .Lf9300e_000948be\n"
        "xorl %edx, %edx\n" /* line 983 */
        ".Lf9300e_000948a4:\n"
        "movl -0xc0(%ebp), %ecx\n" /* line 989 | childBlocks */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl $0, (%eax)\n"
        "addl $1, %edx\n" /* line 986 */
        "cmpl %edx, -0xc4(%ebp)\n" /* childCount */
        "jne .Lf9300e_000948a4\n"
        ".Lf9300e_000948be:\n"
        "movl -0xc0(%ebp), %esi\n" /* line 992 | childBlocks */
        "movl (%esi), %esi\n"
        "movl %esi, -0x194(%ebp)\n"
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf9300e_0009317b\n"
        "movl $0, -0xbc(%ebp)\n" /* i */
        "movl -0xbc(%ebp), %eax\n" /* i */
        ".Lf9300e_000948e7:\n"
        "movl -0x194(%ebp), %edx\n" /* line 994 */
        "movl 0x18(%edx, %eax, 4), %ebx\n"
        /* { scope 4 */
        "movl -0x174(%ebp), %ecx\n" /* line 764 */
        "movl 0xc(%ecx), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf9300e_0009493c\n"
        "cmpl 0x18(%ecx), %ebx\n" /* line 766 */
        "je .Lf9300e_0009491c\n"
        "movl %ecx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf9300e_00094907:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %esi\n"
        "je .Lf9300e_0009493c\n"
        "movl 0x1c(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_00094907\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 995 */
        "js .Lf9300e_0009493c\n"
        ".Lf9300e_0009491c:\n"
        "movl -0x194(%ebp), %eax\n"
        ".Lf9300e_00094922:\n"
        "addl $1, -0xbc(%ebp)\n" /* line 992 | i */
        "movl -0xbc(%ebp), %esi\n" /* i */
        "cmpl 0xc(%eax), %esi\n"
        "jge .Lf9300e_0009317b\n"
        "movl %esi, %eax\n"
        "jmp .Lf9300e_000948e7\n"
        ".Lf9300e_0009493c:\n"
        "cmpl $1, -0xc4(%ebp)\n" /* line 998 | childCount */
        "jle .Lf9300e_00094990\n"
        "movl $1, -0x48(%ebp)\n" /* line 995 */
        "movl -0x48(%ebp), %edx\n"
        ".Lf9300e_0009494f:\n"
        "movl -0xc0(%ebp), %ecx\n" /* line 1000 | childBlocks */
        "movl (%ecx, %edx, 4), %eax\n" /* block */
        /* { scope 4 */
        "movl 0xc(%eax), %edi\n" /* line 764 */
        "testl %edi, %edi\n"
        "jle .Lf9300e_0009491c\n"
        "cmpl 0x18(%eax), %ebx\n" /* line 766 */
        "je .Lf9300e_0009497d\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf9300e_00094968:\n"
        "addl $1, %edx\n" /* line 764 */
        "cmpl %edx, %edi\n"
        "je .Lf9300e_0009491c\n"
        "movl 0x1c(%ecx), %eax\n" /* line 766 */
        "addl $4, %ecx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_00094968\n"
        /* } scope */
        "testl %edx, %edx\n" /* line 1000 */
        "js .Lf9300e_0009491c\n"
        ".Lf9300e_0009497d:\n"
        "addl $1, -0x48(%ebp)\n" /* line 998 */
        "movl -0x48(%ebp), %eax\n"
        "cmpl %eax, -0xc4(%ebp)\n" /* childCount */
        "je .Lf9300e_00094990\n"
        "movl %eax, %edx\n"
        "jmp .Lf9300e_0009494f\n"
        ".Lf9300e_00094990:\n"
        "movl -0x174(%ebp), %edx\n" /* line 1004 */
        "movl %ebx, 0x18(%edx, %esi, 4)\n"
        "addl $1, 0xc(%edx)\n" /* line 1005 */
        "movl -0xc0(%ebp), %ecx\n" /* childBlocks */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x194(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf9300e_00094922\n"
        /* } scope */
        /* } scope */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_000949b3:\n"
        "movl -0xb8(%ebp), %edi\n" /* line 1024 | childCount, i */
        "testl %edi, %edi\n" /* i */
        "jle .Lf9300e_00093195\n"
        "movl $0, -0xac(%ebp)\n" /* line 1021 | childIndex */
        "movl -0xac(%ebp), %ecx\n" /* childIndex */
        ".Lf9300e_000949d1:\n"
        "movl -0xb4(%ebp), %esi\n" /* line 1026 | childBlocks, j */
        "movl (%esi, %ecx, 4), %ecx\n" /* j */
        "movl %ecx, -0x50(%ebp)\n"
        "movl -0x174(%ebp), %esi\n" /* line 1028 | j */
        "movl 0xc(%esi), %eax\n" /* j */
        "movl %eax, 8(%ecx)\n"
        "testl %eax, %eax\n" /* line 1029 */
        "jle .Lf9300e_00094b0d\n"
        "addl $0x18, %esi\n" /* j */
        "movl %esi, -0x68(%ebp)\n" /* j */
        "movl %ecx, -0x64(%ebp)\n"
        "movl $0, -0x4c(%ebp)\n"
        "addl $0x18, %ecx\n"
        "movl %ecx, -0x1a4(%ebp)\n"
        "movl -0x64(%ebp), %eax\n"
        "addl $0x1c, %eax\n"
        "movl %eax, -0x1a8(%ebp)\n"
        "movl -0x64(%ebp), %edx\n"
        "addl $0x10, %edx\n"
        "movl %edx, -0x1ac(%ebp)\n"
        "movl %esi, %ecx\n" /* j */
        ".Lf9300e_00094a24:\n"
        "movl (%ecx), %ecx\n" /* line 1031 */
        "movl %ecx, -0xb0(%ebp)\n"
        "movl -0x50(%ebp), %eax\n" /* line 764 */
        "movl 0xc(%eax), %esi\n"
        "movl %esi, -0x180(%ebp)\n"
        "cmpl -0x4c(%ebp), %esi\n"
        "jle .Lf9300e_00094af2\n"
        "movl -0x64(%ebp), %edx\n" /* line 766 */
        "cmpl %ecx, 0x18(%edx)\n"
        "je .Lf9300e_00094b51\n"
        "movl -0x1ac(%ebp), %edx\n"
        "addl $8, %edx\n"
        "movl -0x4c(%ebp), %ebx\n"
        "movl %esi, %edi\n"
        "movl -0x1a8(%ebp), %ecx\n"
        "subl -0x1a4(%ebp), %ecx\n"
        ".Lf9300e_00094a67:\n"
        "addl $1, %ebx\n" /* line 764 */
        "cmpl %edi, %ebx\n"
        "je .Lf9300e_00094af2\n"
        "movl (%ecx, %edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl -0xb0(%ebp), %eax\n"
        "jne .Lf9300e_00094a67\n"
        ".Lf9300e_00094a80:\n"
        "testl %ebx, %ebx\n" /* line 1033 */
        "js .Lf9300e_00094af2\n"
        ".Lf9300e_00094a84:\n"
        "cmpl %ebx, -0x4c(%ebp)\n" /* line 1039 */
        "jge .Lf9300e_00094aad\n"
        "leal (, %ebx, 4), %eax\n"
        "movl -0x50(%ebp), %esi\n" /* j */
        "leal 0x14(%eax, %esi), %ecx\n"
        "leal 0x18(%eax, %esi), %edx\n"
        ".Lf9300e_00094a9b:\n"
        "subl $1, %ebx\n" /* line 1041 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x4c(%ebp)\n" /* line 1039 */
        "jl .Lf9300e_00094a9b\n"
        ".Lf9300e_00094aad:\n"
        "movl -0xb0(%ebp), %edx\n" /* line 1044 */
        "movl -0x64(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "addl $1, -0x4c(%ebp)\n" /* line 1029 */
        "addl $4, -0x1ac(%ebp)\n"
        "addl $4, -0x1a8(%ebp)\n"
        "addl $4, -0x1a4(%ebp)\n"
        "addl $4, -0x68(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl -0x4c(%ebp), %esi\n" /* j */
        "movl -0x174(%ebp), %ecx\n"
        "cmpl %esi, 0xc(%ecx)\n" /* j */
        "jle .Lf9300e_00094b0d\n"
        "movl -0x68(%ebp), %ecx\n"
        "jmp .Lf9300e_00094a24\n"
        ".Lf9300e_00094af2:\n"
        "cmpl $0x3f, %esi\n" /* line 894 */
        "jg .Lf9300e_00094b2d\n"
        "movl -0x180(%ebp), %eax\n"
        ".Lf9300e_00094afd:\n"
        "addl $1, %eax\n" /* line 1037 */
        "movl -0x50(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "movl %esi, %ebx\n" /* j */
        "jmp .Lf9300e_00094a84\n"
        ".Lf9300e_00094b0d:\n"
        "addl $1, -0xac(%ebp)\n" /* line 1024 | childIndex */
        "movl -0xac(%ebp), %eax\n" /* childIndex */
        "cmpl %eax, -0xb8(%ebp)\n" /* childCount */
        "je .Lf9300e_00093195\n"
        "movl %eax, %ecx\n"
        "jmp .Lf9300e_000949d1\n"
        ".Lf9300e_00094b2d:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x50(%ebp), %ecx\n"
        "movl 0xc(%ecx), %ecx\n"
        "movl %ecx, -0x180(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf9300e_00094afd\n"
        ".Lf9300e_00094b51:\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 764 */
        "jmp .Lf9300e_00094a80\n"
        /* } scope */
        /* } scope */
        ".Lf9300e_00094b59:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* line 888 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf9300e_00093138\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        /* { scope 4 */
        ".Lf9300e_00094b72:\n"
        "movl -0xf4(%ebp), %esi\n" /* line 986 | childCount */
        "testl %esi, %esi\n"
        "jle .Lf9300e_00094b98\n"
        "xorl %edx, %edx\n" /* line 983 */
        ".Lf9300e_00094b7e:\n"
        "movl -0xf0(%ebp), %ecx\n" /* line 989 | childBlocks */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl $0, (%eax)\n"
        "addl $1, %edx\n" /* line 986 */
        "cmpl %edx, -0xf4(%ebp)\n" /* childCount */
        "jne .Lf9300e_00094b7e\n"
        ".Lf9300e_00094b98:\n"
        "movl -0xf0(%ebp), %esi\n" /* line 992 | childBlocks */
        "movl (%esi), %esi\n"
        "movl %esi, -0x198(%ebp)\n"
        "movl 0xc(%esi), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf9300e_0009444e\n"
        "movl $0, -0xec(%ebp)\n" /* i */
        "movl -0xec(%ebp), %eax\n" /* i */
        ".Lf9300e_00094bc1:\n"
        "movl -0x198(%ebp), %edx\n" /* line 994 */
        "movl 0x18(%edx, %eax, 4), %ebx\n"
        /* { scope 5 */
        "movl -0x174(%ebp), %ecx\n" /* line 764 */
        "movl 0xc(%ecx), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf9300e_00094c16\n"
        "cmpl 0x18(%ecx), %ebx\n" /* line 766 */
        "je .Lf9300e_00094bf6\n"
        "movl %ecx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf9300e_00094be1:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %esi, %ecx\n"
        "je .Lf9300e_00094c16\n"
        "movl 0x1c(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_00094be1\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 995 */
        "js .Lf9300e_00094c16\n"
        ".Lf9300e_00094bf6:\n"
        "movl -0x198(%ebp), %eax\n"
        ".Lf9300e_00094bfc:\n"
        "addl $1, -0xec(%ebp)\n" /* line 992 | i */
        "movl -0xec(%ebp), %esi\n" /* i */
        "cmpl %esi, 0xc(%eax)\n"
        "jle .Lf9300e_0009444e\n"
        "movl %esi, %eax\n"
        "jmp .Lf9300e_00094bc1\n"
        ".Lf9300e_00094c16:\n"
        "cmpl $1, -0xf4(%ebp)\n" /* line 998 | childCount */
        "jle .Lf9300e_00094c6a\n"
        "movl $1, -0x44(%ebp)\n" /* line 995 */
        "movl -0x44(%ebp), %edx\n"
        ".Lf9300e_00094c29:\n"
        "movl -0xf0(%ebp), %ecx\n" /* line 1000 | childBlocks */
        "movl (%ecx, %edx, 4), %eax\n" /* block */
        /* { scope 5 */
        /* { scope 6 */
        "movl 0xc(%eax), %edi\n" /* line 764 */
        "testl %edi, %edi\n"
        "jle .Lf9300e_00094bf6\n"
        "cmpl 0x18(%eax), %ebx\n" /* line 766 */
        "je .Lf9300e_00094c57\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf9300e_00094c42:\n"
        "addl $1, %edx\n" /* line 764 */
        "cmpl %edi, %edx\n"
        "je .Lf9300e_00094bf6\n"
        "movl 0x1c(%ecx), %eax\n" /* line 766 */
        "addl $4, %ecx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_00094c42\n"
        /* } scope */
        /* } scope */
        "testl %edx, %edx\n" /* line 1000 */
        "js .Lf9300e_00094bf6\n"
        ".Lf9300e_00094c57:\n"
        "addl $1, -0x44(%ebp)\n" /* line 998 */
        "movl -0x44(%ebp), %eax\n"
        "cmpl %eax, -0xf4(%ebp)\n" /* childCount */
        "je .Lf9300e_00094c6a\n"
        "movl %eax, %edx\n"
        "jmp .Lf9300e_00094c29\n"
        ".Lf9300e_00094c6a:\n"
        "movl -0x174(%ebp), %edx\n" /* line 1004 */
        "movl %ebx, 0x18(%edx, %esi, 4)\n"
        "addl $1, 0xc(%edx)\n" /* line 1005 */
        "movl -0xf0(%ebp), %ecx\n" /* childBlocks */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x198(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf9300e_00094bfc\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        /* { scope 4 */
        ".Lf9300e_00094c8d:\n"
        "movl -0x134(%ebp), %ebx\n" /* line 986 | childCount */
        "testl %ebx, %ebx\n"
        "jle .Lf9300e_00094cb3\n"
        "xorl %edx, %edx\n" /* line 983 */
        ".Lf9300e_00094c99:\n"
        "movl -0x130(%ebp), %ecx\n" /* line 989 | childBlocks */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl $0, (%eax)\n"
        "addl $1, %edx\n" /* line 986 */
        "cmpl %edx, -0x134(%ebp)\n" /* childCount */
        "jne .Lf9300e_00094c99\n"
        ".Lf9300e_00094cb3:\n"
        "movl -0x130(%ebp), %esi\n" /* line 992 | childBlocks */
        "movl (%esi), %esi\n"
        "movl %esi, -0x19c(%ebp)\n"
        "movl 0xc(%esi), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf9300e_00094459\n"
        "movl $0, -0x12c(%ebp)\n" /* i */
        "movl -0x12c(%ebp), %eax\n" /* i */
        ".Lf9300e_00094cdc:\n"
        "movl -0x19c(%ebp), %edx\n" /* line 994 */
        "movl 0x18(%edx, %eax, 4), %ebx\n"
        /* { scope 5 */
        "movl -0x174(%ebp), %ecx\n" /* line 764 */
        "movl 0xc(%ecx), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf9300e_00094d31\n"
        "cmpl 0x18(%ecx), %ebx\n" /* line 766 */
        "je .Lf9300e_00094d11\n"
        "movl %ecx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf9300e_00094cfc:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %esi\n"
        "je .Lf9300e_00094d31\n"
        "movl 0x1c(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_00094cfc\n"
        /* } scope */
        "testl %ecx, %ecx\n" /* line 995 */
        "js .Lf9300e_00094d31\n"
        ".Lf9300e_00094d11:\n"
        "movl -0x19c(%ebp), %eax\n"
        ".Lf9300e_00094d17:\n"
        "addl $1, -0x12c(%ebp)\n" /* line 992 | i */
        "movl -0x12c(%ebp), %esi\n" /* i */
        "cmpl 0xc(%eax), %esi\n"
        "jge .Lf9300e_00094459\n"
        "movl %esi, %eax\n"
        "jmp .Lf9300e_00094cdc\n"
        ".Lf9300e_00094d31:\n"
        "cmpl $1, -0x134(%ebp)\n" /* line 998 | childCount */
        "jle .Lf9300e_00094d85\n"
        "movl $1, -0x40(%ebp)\n" /* line 995 */
        "movl -0x40(%ebp), %edx\n"
        ".Lf9300e_00094d44:\n"
        "movl -0x130(%ebp), %ecx\n" /* line 1000 | childBlocks */
        "movl (%ecx, %edx, 4), %eax\n" /* block */
        /* { scope 5 */
        /* { scope 6 */
        "movl 0xc(%eax), %edi\n" /* line 764 */
        "testl %edi, %edi\n"
        "jle .Lf9300e_00094d11\n"
        "cmpl 0x18(%eax), %ebx\n" /* line 766 */
        "je .Lf9300e_00094d72\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf9300e_00094d5d:\n"
        "addl $1, %edx\n" /* line 764 */
        "cmpl %edx, %edi\n"
        "je .Lf9300e_00094d11\n"
        "movl 0x1c(%ecx), %eax\n" /* line 766 */
        "addl $4, %ecx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9300e_00094d5d\n"
        /* } scope */
        /* } scope */
        "testl %edx, %edx\n" /* line 1000 */
        "js .Lf9300e_00094d11\n"
        ".Lf9300e_00094d72:\n"
        "addl $1, -0x40(%ebp)\n" /* line 998 */
        "movl -0x40(%ebp), %eax\n"
        "cmpl %eax, -0x134(%ebp)\n" /* childCount */
        "je .Lf9300e_00094d85\n"
        "movl %eax, %edx\n"
        "jmp .Lf9300e_00094d44\n"
        ".Lf9300e_00094d85:\n"
        "movl -0x174(%ebp), %edx\n" /* line 1004 */
        "movl %ebx, 0x18(%edx, %esi, 4)\n"
        "addl $1, 0xc(%edx)\n" /* line 1005 */
        "movl -0x130(%ebp), %ecx\n" /* childBlocks */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x19c(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf9300e_00094d17\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf9300e_00094da8:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* line 888 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompileGlob+76, %eax\n"
        "jmp .Lf9300e_00093d88\n"
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00094dc6:\n"
        "cmpl $0x3f, %edi\n" /* line 894 */
        "jg .Lf9300e_00094f9e\n"
        "movl -0x174(%ebp), %edx\n"
        ".Lf9300e_00094dd5:\n"
        "movl %ebx, 0x18(%edx, %edi, 4)\n" /* line 914 */
        "addl $1, 0xc(%edx)\n" /* line 918 */
        "jmp .Lf9300e_000931ad\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00094de2:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* line 888 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompileGlob+76, %eax\n"
        "jmp .Lf9300e_0009396b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf9300e_00094e00:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* "MAX_SWITCH_CASES exceeded" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompileGlob+64, %eax\n"
        "jmp .Lf9300e_00093d27\n"
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        /* { scope 3: j, childIndex, i, block, ... */
        ".Lf9300e_00094e1e:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* "MAX_SWITCH_CASES exceeded" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompileGlob+76, %eax\n"
        "jmp .Lf9300e_00093734\n"
        ".Lf9300e_00094e3c:\n"
        "movl -0x174(%ebp), %esi\n"
        "jmp .Lf9300e_00093d45\n"
        ".Lf9300e_00094e47:\n"
        "movl -0x174(%ebp), %esi\n"
        "jmp .Lf9300e_00093da6\n"
        /* } scope */
        ".Lf9300e_00094e52:\n"
        "movl $0x118, (%esp)\n" /* line 925 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl -0x14c(%ebp), %edx\n" /* whileStatBlock */
        "movl %eax, (%edx)\n"
        "movl -0x14c(%ebp), %ecx\n" /* whileStatBlock */
        "jmp .Lf9300e_000936d8\n"
        /* } scope */
        /* } scope */
        ".Lf9300e_00094e71:\n"
        "movl $0x118, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, 0x10(%ebx)\n"
        "jmp .Lf9300e_00093208\n"
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094e85:\n"
        "movl $0x118, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl -0x118(%ebp), %ecx\n" /* forStatBlock */
        "movl %eax, (%ecx)\n"
        "movl -0x118(%ebp), %edx\n" /* forStatBlock */
        "jmp .Lf9300e_000938ca\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094ea4:\n"
        "movl $0x118, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, 0x18(%ebx)\n"
        "jmp .Lf9300e_000933aa\n"
        ".Lf9300e_00094eb8:\n"
        "movl $0x118, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf9300e_00093401\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00094ecb:\n"
        "movl $0x118, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, 0xc(%ebx)\n"
        "jmp .Lf9300e_00093b75\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094edf:\n"
        "movl $0x118, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl -0x11c(%ebp), %edx\n" /* forStatPostBlock */
        "movl %eax, (%edx)\n"
        "movl -0x11c(%ebp), %ecx\n" /* forStatPostBlock */
        "jmp .Lf9300e_00093905\n"
        ".Lf9300e_00094efe:\n"
        "movl 4(%eax), %esi\n" /* line 2836 | j */
        "leal -0x2c(%ebp), %edx\n" /* childBlocks */
        "movl %esi, %eax\n" /* j */
        "calll EvalPrimitiveExpression\n"
        ".Lf9300e_00094f0b:\n"
        "testb %al, %al\n" /* line 3719 */
        "je .Lf9300e_000946d8\n"
        "movl -0x28(%ebp), %edx\n" /* line 3721 */
        "leal -5(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf9300e_00094feb\n"
        ".Lf9300e_00094f22:\n"
        "movb $0, -0x111(%ebp)\n" /* line 3724 | constConditional */
        ".Lf9300e_00094f29:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 252 | childBlocks */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RemoveRefToValue\n"
        "jmp .Lf9300e_00093840\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00094f3d:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x174(%ebp), %edx\n"
        "movl 0xc(%edx), %edi\n"
        "movl %edx, %ecx\n"
        "jmp .Lf9300e_00094848\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094f61:\n"
        "movl 0x10(%eax), %ebx\n" /* line 2839 */
        "movl 0xc(%eax), %ecx\n"
        "movl 8(%eax), %edx\n"
        "movl 4(%eax), %esi\n" /* j */
        "leal -0x2c(%ebp), %eax\n" /* childBlocks */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl %esi, %eax\n" /* j */
        "calll EvalBinaryOperatorExpression\n"
        "jmp .Lf9300e_00094f0b\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00094f80:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* line 888 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompileGlob+64, %eax\n"
        "jmp .Lf9300e_00093116\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        ".Lf9300e_00094f9e:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x174(%ebp), %eax\n"
        "movl 0xc(%eax), %edi\n"
        "movl %eax, %edx\n"
        "jmp .Lf9300e_00094dd5\n"
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094fc2:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 3478 | childBlocks */
        "movl %eax, (%esp)\n"
        "calll Scr_CastBool\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 3479 | childBlocks */
        "testl %ecx, %ecx\n"
        "je .Lf9300e_00094fe3\n"
        "movb $1, -0x145(%ebp)\n" /* constConditional */
        "movl -0x28(%ebp), %edx\n"
        "jmp .Lf9300e_0009470f\n"
        ".Lf9300e_00094fe3:\n"
        "movl -0x28(%ebp), %edx\n"
        "jmp .Lf9300e_00094708\n"
        /* } scope */
        /* } scope */
        /* { scope 1: childCount, childBlocks, childCount, childBlocks, ... */
        /* { scope 2: i, childIndex, i, childCount, ... */
        ".Lf9300e_00094feb:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 3723 | childBlocks */
        "movl %eax, (%esp)\n"
        "calll Scr_CastBool\n"
        "movl -0x2c(%ebp), %eax\n" /* line 3724 | childBlocks */
        "testl %eax, %eax\n"
        "je .Lf9300e_0009500c\n"
        "movb $1, -0x111(%ebp)\n" /* constConditional */
        "movl -0x28(%ebp), %edx\n"
        "jmp .Lf9300e_00094f29\n"
        ".Lf9300e_0009500c:\n"
        "movl -0x28(%ebp), %edx\n"
        "jmp .Lf9300e_00094f22\n"
    );
}

/* line 1183 */
static __attribute__((naked))
unsigned int EmitValue(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1183 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %ecx\n" /* constValue */
        "cmpl $6, 4(%eax)\n" /* line 1185 */
        "ja .Lf95014_00095093\n"
        "movl 4(%eax), %eax\n"
        "jmpl *CorrectSolidDeltas+4112(, %eax, 4)\n"
        "movl 8(%ecx), %esi\n" /* line 1204 | constValue */
        "movl (%ecx), %ebx\n" /* constValue, value */
        "xorl %ecx, %ecx\n" /* line 1161 */
        "movl $1, %edx\n"
        "movl $0xb, %eax\n"
        ".Lf95014_00095040:\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 1162 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 630 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw %bx, (%eax)\n" /* line 631 | stringValue */
        "cmpl $2, scrCompilePub+40\n" /* line 255 */
        "je .Lf95014_0009517c\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 266 */
        "jne .Lf95014_00095196\n"
        ".Lf95014_00095083:\n"
        "movl $1, 4(%esp)\n" /* line 268 */
        "movl %ebx, (%esp)\n" /* stringValue */
        "calll SL_TransferRefToUser\n"
        ".Lf95014_00095093:\n"
        "addl $0x1c, %esp\n" /* line 1211 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 8(%ecx), %esi\n" /* line 1188 | constValue */
        "xorl %ecx, %ecx\n" /* line 653 */
        "movl $1, %edx\n"
        "movl $2, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 654 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf95014_00095093\n"
        "movl 8(%ecx), %esi\n" /* line 1192 | constValue */
        "movl %esi, %edx\n"
        "movl (%ecx), %eax\n" /* constValue */
        "addl $0x1c, %esp\n" /* line 1211 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp EmitGetInteger\n" /* line 1192 */
        "movl 8(%ecx), %esi\n" /* line 1196 | constValue */
        "movl (%ecx), %ebx\n" /* constValue, value */
        "xorl %ecx, %ecx\n" /* line 732 */
        "movl $1, %edx\n"
        "movl $9, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 733 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        /* { scope 1 */
        "movl $4, (%esp)\n" /* line 623 */
        "calll TempMallocAlignStrict\n"
        "movl %eax, scrCompileGlob\n"
        "movl %ebx, (%eax)\n" /* line 624 | stringValue */
        "jmp .Lf95014_00095093\n"
        /* } scope */
        "movl 8(%ecx), %esi\n" /* line 1208 | constValue */
        "movl (%ecx), %edi\n" /* constValue, value */
        /* { scope 1 */
        "xorl %ecx, %ecx\n" /* line 1172 */
        "movl $1, %edx\n"
        "movl $0xc, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 1173 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $1, %esi\n"
        ".Lf95014_0009513a:\n"
        "movl -4(%edi, %esi, 4), %ebx\n" /* line 1178 | value */
        /* { scope 2 */
        "movl $4, (%esp)\n" /* line 623 */
        "calll TempMallocAlignStrict\n"
        "movl %eax, scrCompileGlob\n"
        "movl %ebx, (%eax)\n" /* line 624 | stringValue */
        "addl $1, %esi\n"
        /* } scope */
        "cmpl $4, %esi\n" /* line 1177 */
        "jne .Lf95014_0009513a\n"
        "movl %edi, (%esp)\n" /* line 1179 */
        "calll RemoveRefToVector\n"
        "jmp .Lf95014_00095093\n"
        /* } scope */
        "movl 8(%ecx), %esi\n" /* line 1200 | constValue */
        "movl (%ecx), %ebx\n" /* constValue, value */
        "xorl %ecx, %ecx\n" /* line 1142 */
        "movl $1, %edx\n"
        "movl $0xa, %eax\n"
        "jmp .Lf95014_00095040\n"
        /* { scope 1 */
        ".Lf95014_0009517c:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf95014_00095093\n"
        "movl %ebx, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf95014_00095093\n"
        /* } scope */
        ".Lf95014_00095196:\n"
        "movl %ebx, (%esp)\n" /* line 267 | stringValue */
        "calll SL_AddRefToString\n"
        "jmp .Lf95014_00095083\n"
    );
}

/* line 309 */
static __attribute__((naked))
unsigned int EmitOpcode(unsigned int op, int offset, int callType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 309 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl %ecx, -0x24(%ebp)\n"
        /* { scope 1 */
        "movl scrCompilePub, %edi\n" /* line 324 */
        "cmpl $0, %edi\n"
        "je .Lf951a4_000951d1\n"
        "movl $0, scrCompilePub\n" /* line 327 */
        "jg .Lf951a4_00095290\n" /* line 329 */
        ".Lf951a4_000951d1:\n"
        "movl scrCompileGlob+16, %eax\n" /* line 333 */
        "testl %eax, %eax\n"
        "je .Lf951a4_000951ea\n"
        "cmpl $2, -0x24(%ebp)\n"
        "je .Lf951a4_000951ea\n"
        "cmpl $3, -0x24(%ebp)\n"
        "je .Lf951a4_000951ea\n"
        "xorl %edx, %edx\n"
        "jmp .Lf951a4_000951ef\n"
        ".Lf951a4_000951ea:\n"
        "movl $1, %edx\n"
        ".Lf951a4_000951ef:\n"
        "movb %dl, scrCompilePub+37\n"
        "movl -0x20(%ebp), %ecx\n" /* line 335 */
        "leal (%eax, %ecx), %edx\n"
        "movl %edx, scrCompileGlob+16\n"
        "cmpl scrCompileGlob+20, %edx\n" /* line 337 */
        "movl scrCompileGlob+20, %eax\n"
        "cmovgl %edx, %eax\n"
        "movl %eax, scrCompileGlob+20\n"
        "movl -0x24(%ebp), %ecx\n" /* line 338 */
        "testl %ecx, %ecx\n"
        "je .Lf951a4_0009522e\n"
        "cmpl %edx, scrCompileGlob+24\n" /* line 339 */
        "movl scrCompileGlob+24, %eax\n"
        "cmovll %edx, %eax\n"
        "movl %eax, scrCompileGlob+24\n"
        ".Lf951a4_0009522e:\n"
        "movl imp_scrVarPub, %ecx\n" /* line 342 */
        "movl 0x3c(%ecx), %edx\n"
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "addl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x3c(%ecx)\n"
        "movl scrCompilePub+44, %edx\n" /* line 347 */
        "testl %edx, %edx\n"
        "je .Lf951a4_0009525f\n"
        "movl %edx, scrCompileGlob\n" /* line 349 */
        "movl -0x1c(%ebp), %eax\n" /* line 352 */
        "subl $0x20, %eax\n"
        "cmpl $0x3e, %eax\n"
        "jbe .Lf951a4_00095289\n"
        ".Lf951a4_0009525f:\n"
        "movl %edx, scrCompileGlob+4\n" /* line 568 */
        "movl $1, (%esp)\n" /* line 569 */
        "calll TempMalloc\n"
        "movl %eax, scrCompilePub+44\n"
        "movl %eax, scrCompileGlob\n" /* line 570 */
        "movzbl -0x1c(%ebp), %edx\n" /* line 571 */
        "movb %dl, (%eax)\n"
        /* } scope */
        ".Lf951a4_00095281:\n"
        "addl $0x2c, %esp\n" /* line 572 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf951a4_00095289:\n"
        "jmpl *CorrectSolidDeltas+4140(, %eax, 4)\n" /* line 352 */
        ".Lf951a4_00095290:\n"
        "xorl %esi, %esi\n" /* line 329 | valueIndex */
        "movl $scrCompileGlob+92, %ebx\n" /* index */
        ".Lf951a4_00095297:\n"
        "movl %ebx, %eax\n" /* line 330 | index */
        "calll EmitValue\n"
        "addl $1, %esi\n" /* line 329 | valueIndex */
        "addl $0xc, %ebx\n" /* index */
        "cmpl %esi, %edi\n" /* valueIndex */
        "jne .Lf951a4_00095297\n"
        "jmp .Lf951a4_000951d1\n"
        "movzbl (%edx), %eax\n" /* line 355 */
        "cmpb $0x1e, %al\n"
        "je .Lf951a4_000954a4\n"
        "movzbl %al, %eax\n" /* line 363 */
        "leal -0x18(%eax), %ebx\n" /* index */
        "cmpl $5, %ebx\n" /* line 364 | index */
        "ja .Lf951a4_0009525f\n"
        "calll RemoveOpcodePos\n" /* line 366 */
        "movl scrCompilePub+44, %eax\n" /* line 367 */
        "movb $0x1f, (%eax)\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movb %bl, (%eax)\n" /* line 617 | index */
        "jmp .Lf951a4_00095281\n"
        "cmpb $0x5c, (%edx)\n" /* line 558 */
        "jne .Lf951a4_0009525f\n"
        "calll RemoveOpcodePos\n" /* line 560 */
        "movl scrCompilePub+44, %eax\n" /* line 561 */
        "movb $0x5f, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
        "movzbl (%edx), %eax\n" /* line 541 */
        "cmpb $0x1e, %al\n"
        "je .Lf951a4_0009546a\n"
        "movzbl %al, %eax\n" /* line 548 */
        "leal -0x18(%eax), %ebx\n" /* index */
        "cmpl $5, %ebx\n" /* line 549 | index */
        "ja .Lf951a4_0009525f\n"
        "movb $0x5a, (%edx)\n" /* line 551 */
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movb %bl, (%eax)\n" /* line 617 | index */
        "jmp .Lf951a4_00095281\n"
        "cmpb $0xf, (%edx)\n" /* line 532 */
        "jne .Lf951a4_0009525f\n"
        "calll RemoveOpcodePos\n" /* line 534 */
        "movl scrCompilePub+44, %eax\n" /* line 535 */
        "movb $0x54, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
        "cmpb $0x16, (%edx)\n" /* line 449 */
        "jne .Lf951a4_0009525f\n"
        "movb $0x30, (%edx)\n" /* line 451 */
        "jmp .Lf951a4_00095281\n"
        "movzbl (%edx), %eax\n" /* line 422 */
        "cmpb $0x26, %al\n"
        "je .Lf951a4_00095472\n"
        "cmpb $0xd, %al\n" /* line 430 */
        "je .Lf951a4_00095482\n"
        "cmpb $0xe, %al\n" /* line 438 */
        "jne .Lf951a4_0009525f\n"
        "movb $0x2c, (%edx)\n" /* line 440 */
        "jmp .Lf951a4_00095281\n"
        "movzbl (%edx), %eax\n" /* line 395 */
        "cmpb $0x26, %al\n"
        "je .Lf951a4_0009547a\n"
        "cmpb $0xd, %al\n" /* line 403 */
        "je .Lf951a4_0009548a\n"
        "cmpb $0xe, %al\n" /* line 411 */
        "jne .Lf951a4_0009525f\n"
        "movb $0x28, (%edx)\n" /* line 413 */
        "jmp .Lf951a4_00095281\n"
        "movzbl (%edx), %eax\n" /* line 374 */
        "cmpb $0x37, %al\n"
        "je .Lf951a4_00095492\n"
        "cmpb $0x36, %al\n" /* line 383 */
        "jne .Lf951a4_0009525f\n"
        "calll RemoveOpcodePos\n" /* line 385 */
        "movl scrCompilePub+44, %eax\n" /* line 386 */
        "movb $0x21, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
        "cmpb $0x4e, (%edx)\n" /* line 505 */
        "jne .Lf951a4_0009525f\n"
        "movb $0x4f, (%edx)\n" /* line 507 */
        "jmp .Lf951a4_00095281\n"
        "cmpb $0xf, (%edx)\n" /* line 513 */
        "jne .Lf951a4_0009525f\n"
        "calll RemoveOpcodePos\n" /* line 515 */
        "movl scrCompilePub+44, %eax\n" /* line 516 */
        "movb $0x50, (%eax)\n"
        "movl scrCompileGlob+4, %eax\n" /* line 518 */
        "cmpb $0x4e, (%eax)\n"
        "jne .Lf951a4_00095281\n"
        "movl scrCompilePub+44, %eax\n" /* line 521 */
        "movl %eax, (%esp)\n"
        "calll TempMemorySetPos\n"
        "movl scrCompilePub+44, %edx\n" /* line 522 */
        "leal -1(%edx), %eax\n"
        "movl %eax, scrCompilePub+44\n"
        "movl $0, scrCompileGlob+4\n" /* line 523 */
        "movl %eax, scrCompileGlob\n" /* line 524 */
        "movb $0x4f, -1(%edx)\n" /* line 525 */
        "jmp .Lf951a4_00095281\n"
        "movzbl (%edx), %eax\n" /* line 457 */
        "cmpb $0x37, %al\n"
        "je .Lf951a4_000954b6\n"
        "cmpb $0x36, %al\n" /* line 466 */
        "je .Lf951a4_000954c8\n"
        "cmpb $0x2d, %al\n" /* line 475 */
        "je .Lf951a4_000954da\n"
        "cmpb $0x2b, %al\n" /* line 484 */
        "je .Lf951a4_000954ec\n"
        "cmpb $0x2c, %al\n" /* line 493 */
        "jne .Lf951a4_0009525f\n"
        "calll RemoveOpcodePos\n" /* line 495 */
        "movl scrCompilePub+44, %eax\n" /* line 496 */
        "movb $0x3a, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_0009546a:\n"
        "movb $0x5a, (%edx)\n" /* line 543 */
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_00095472:\n"
        "movb $0x2d, (%edx)\n" /* line 424 */
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_0009547a:\n"
        "movb $0x29, (%edx)\n" /* line 397 */
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_00095482:\n"
        "movb $0x2b, (%edx)\n" /* line 432 */
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_0009548a:\n"
        "movb $0x27, (%edx)\n" /* line 405 */
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_00095492:\n"
        "calll RemoveOpcodePos\n" /* line 376 */
        "movl scrCompilePub+44, %eax\n" /* line 377 */
        "movb $0x22, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_000954a4:\n"
        "calll RemoveOpcodePos\n" /* line 357 */
        "movl scrCompilePub+44, %eax\n" /* line 358 */
        "movb $0x1f, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_000954b6:\n"
        "calll RemoveOpcodePos\n" /* line 459 */
        "movl scrCompilePub+44, %eax\n" /* line 460 */
        "movb $0x3d, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_000954c8:\n"
        "calll RemoveOpcodePos\n" /* line 468 */
        "movl scrCompilePub+44, %eax\n" /* line 469 */
        "movb $0x3c, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_000954da:\n"
        "calll RemoveOpcodePos\n" /* line 477 */
        "movl scrCompilePub+44, %eax\n" /* line 478 */
        "movb $0x3b, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
        ".Lf951a4_000954ec:\n"
        "calll RemoveOpcodePos\n" /* line 486 */
        "movl scrCompilePub+44, %eax\n" /* line 487 */
        "movb $0x38, (%eax)\n"
        "jmp .Lf951a4_00095281\n"
    );
}

/* line 668 */
static __attribute__((naked))
unsigned int EmitGetInteger(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 668 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %ebx\n" /* value */
        "movl %edx, %esi\n" /* sourcePos */
        "cmpl $0, %eax\n" /* line 670 */
        "jl .Lf954fe_0009558a\n"
        "je .Lf954fe_00095562\n" /* line 672 */
        "cmpl $0xff, %eax\n" /* line 679 */
        "jle .Lf954fe_000955d3\n"
        "cmpl $0xffff, %eax\n" /* line 687 */
        "jle .Lf954fe_0009564b\n"
        ".Lf954fe_00095527:\n"
        "xorl %ecx, %ecx\n" /* line 714 */
        "movl $1, %edx\n"
        "movl $8, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 715 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll AddOpcodePos\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %ebx, (%eax)\n" /* line 596 */
        ".Lf954fe_0009555b:\n"
        "addl $0x10, %esp\n" /* line 717 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf954fe_00095562:\n"
        "xorl %ecx, %ecx\n" /* line 674 */
        "movl $1, %edx\n"
        "movl $3, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 675 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll AddOpcodePos\n"
        "addl $0x10, %esp\n" /* line 717 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf954fe_0009558a:\n"
        "cmpl $0xffffff00, %eax\n" /* line 697 */
        "jg .Lf954fe_0009560e\n"
        "cmpl $0xffff0000, %eax\n" /* line 705 */
        "jle .Lf954fe_00095527\n"
        "xorl %ecx, %ecx\n" /* line 707 */
        "movl $1, %edx\n"
        "movl $7, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 708 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %ebx, %edx\n" /* line 610 */
        "negl %edx\n"
        "movw %dx, (%eax)\n"
        "jmp .Lf954fe_0009555b\n"
        ".Lf954fe_000955d3:\n"
        "xorl %ecx, %ecx\n" /* line 681 */
        "movl $1, %edx\n"
        "movl $4, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 682 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll AddOpcodePos\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movb %bl, (%eax)\n" /* line 617 */
        "addl $0x10, %esp\n" /* line 717 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf954fe_0009560e:\n"
        "xorl %ecx, %ecx\n" /* line 699 */
        "movl $1, %edx\n"
        "movl $5, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 700 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll AddOpcodePos\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movl %ebx, %edx\n" /* line 617 */
        "negb %dl\n"
        "movb %dl, (%eax)\n"
        "jmp .Lf954fe_0009555b\n"
        ".Lf954fe_0009564b:\n"
        "xorl %ecx, %ecx\n" /* line 689 */
        "movl $1, %edx\n"
        "movl $6, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 690 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw %bx, (%eax)\n" /* line 610 */
        "addl $0x10, %esp\n" /* line 717 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 773 */
static __attribute__((naked))
int Scr_FindLocalVarIndex(unsigned int name, sval_t sourcePos, Bool create, scr_block_t *block)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 773 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, -0x28(%ebp)\n"
        "movb %cl, -0x29(%ebp)\n"
        /* { scope 1: bConstRefCount */
        "movl 8(%ebp), %esi\n" /* line 782 | block, i */
        "testl %esi, %esi\n" /* i */
        "je .Lf95688_000957d9\n"
        "movl 8(%ebp), %eax\n" /* line 785 | block */
        "movl 0xc(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf95688_000957ca\n"
        "movl %eax, %edi\n"
        "xorl %esi, %esi\n" /* i */
        "movl 8(%ebp), %eax\n" /* block */
        "jmp .Lf95688_000956da\n"
        ".Lf95688_000956bc:\n"
        "movl -0x24(%ebp), %eax\n" /* line 797 */
        "cmpl 0x18(%edi), %eax\n"
        "je .Lf95688_00095761\n"
        ".Lf95688_000956c8:\n"
        "addl $1, %esi\n" /* line 785 | i */
        "addl $4, %edi\n"
        "movl 8(%ebp), %eax\n" /* block */
        "cmpl 0xc(%eax), %esi\n" /* i */
        "jge .Lf95688_000957ca\n"
        ".Lf95688_000956da:\n"
        "cmpl 4(%eax), %esi\n" /* line 787 | i */
        "jne .Lf95688_000956bc\n"
        "movl %eax, %edx\n"
        "leal 1(%esi), %eax\n" /* line 789 | i */
        "movl %eax, 4(%edx)\n"
        "xorl %ecx, %ecx\n" /* line 790 */
        "xorl %edx, %edx\n"
        "movl $0x16, %eax\n"
        "calll EmitOpcode\n"
        "movl 0x18(%edi), %eax\n" /* line 791 */
        "movl %eax, -0x1c(%ebp)\n" /* stringValue */
        /* { scope 2: stringValue */
        "movzbl scrCompileGlob+28, %edx\n" /* line 244 */
        "movb %dl, -0x1d(%ebp)\n" /* bConstRefCount */
        "movb $1, scrCompileGlob+28\n" /* line 245 */
        "movl $2, (%esp)\n" /* line 214 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "cmpl $2, scrCompilePub+40\n" /* line 216 */
        "je .Lf95688_000957f6\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 233 */
        "jne .Lf95688_00095813\n"
        ".Lf95688_00095737:\n"
        "movl scrCompileGlob, %ebx\n" /* line 236 */
        "movl -0x1c(%ebp), %eax\n" /* stringValue */
        "movl %eax, (%esp)\n"
        "calll SL_TransferToCanonicalString\n"
        "movw %ax, (%ebx)\n"
        ".Lf95688_0009574b:\n"
        "movzbl -0x1d(%ebp), %edx\n" /* line 247 | bConstRefCount */
        "movb %dl, scrCompileGlob+28\n"
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 797 */
        "cmpl 0x18(%edi), %eax\n"
        "jne .Lf95688_000956c8\n"
        ".Lf95688_00095761:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "je .Lf95688_00095848\n"
        ".Lf95688_0009576e:\n"
        "movl %esi, %ecx\n" /* line 802 | i */
        "andl $7, %ecx\n"
        "movl $1, %eax\n"
        "movl %eax, %edx\n"
        "shlb %cl, %dl\n"
        "movl %esi, %ebx\n" /* line 803 | i */
        "sarl $3, %ebx\n"
        "movl 8(%ebp), %eax\n" /* block */
        "movzbl 0x10(%ebx, %eax), %ecx\n"
        "movzbl %dl, %eax\n"
        "testl %ecx, %eax\n"
        "jne .Lf95688_00095839\n"
        "cmpb $0, -0x29(%ebp)\n" /* line 805 */
        "jne .Lf95688_00095823\n"
        ".Lf95688_0009579e:\n"
        "movl -0x24(%ebp), %edx\n" /* line 815 */
        "movl %edx, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021d7f4, 4(%esp)\n" /* "uninitialised variable '%s'" */
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf95688_000957c2:\n"
        "addl $0x3c, %esp\n" /* line 822 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bConstRefCount */
        ".Lf95688_000957ca:\n"
        "cmpb $0, -0x29(%ebp)\n" /* line 813 */
        "je .Lf95688_0009579e\n"
        "cmpb $0, scrCompileGlob+80\n"
        "jne .Lf95688_0009579e\n"
        ".Lf95688_000957d9:\n"
        "movl $str_0021d810, 4(%esp)\n" /* line 820 */
        "movl -0x28(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CompileError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 822 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bConstRefCount */
        /* { scope 2: stringValue */
        /* { scope 3 */
        ".Lf95688_000957f6:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf95688_0009574b\n"
        "movl -0x1c(%ebp), %eax\n" /* line 206 | stringValue */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "jmp .Lf95688_0009574b\n"
        /* } scope */
        ".Lf95688_00095813:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 234 | stringValue */
        "movl %edx, (%esp)\n"
        "calll SL_AddRefToString\n"
        "jmp .Lf95688_00095737\n"
        /* } scope */
        ".Lf95688_00095823:\n"
        "cmpb $0, scrCompileGlob+80\n" /* line 805 */
        "jne .Lf95688_0009579e\n"
        "orb %cl, %dl\n" /* line 807 */
        "movl 8(%ebp), %eax\n" /* block */
        "movb %dl, 0x10(%ebx, %eax)\n"
        ".Lf95688_00095839:\n"
        "movl %esi, %eax\n" /* line 810 | i */
        "notl %eax\n"
        "movl 8(%ebp), %edx\n" /* block */
        "addl 4(%edx), %eax\n"
        "jmp .Lf95688_000957c2\n"
        ".Lf95688_00095848:\n"
        "movl %eax, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf95688_0009576e\n"
    );
}

/* line 4366 */
static __attribute__((naked))
unsigned int EmitContinueStatement(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4366 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %esi\n" /* sourcePos */
        "movl %edx, %ebx\n" /* block */
        "cmpb $0, scrCompileGlob+52\n" /* line 4370 */
        "je .Lf95856_00095954\n"
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf95856_00095954\n"
        "movl scrCompileGlob+72, %eax\n" /* line 3300 */
        "testl %eax, %eax\n"
        "je .Lf95856_000958a6\n"
        "movl scrCompileGlob+76, %eax\n" /* line 886 */
        "cmpl $0x3ff, (%eax)\n"
        "jg .Lf95856_0009596c\n"
        ".Lf95856_00095894:\n"
        "movl (%eax), %edx\n" /* line 3303 */
        "movl scrCompileGlob+72, %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n"
        "movl scrCompileGlob+76, %eax\n" /* line 3304 */
        "addl $1, (%eax)\n"
        /* { scope 1 */
        ".Lf95856_000958a6:\n"
        "movl (%ebx), %edi\n" /* line 850 | removeCount */
        "testl %edi, %edi\n" /* removeCount */
        "jne .Lf95856_000958df\n"
        "movl 4(%ebx), %eax\n" /* line 854 */
        "movl %eax, %edi\n" /* line 856 | removeCount */
        "subl 8(%ebx), %edi\n" /* removeCount */
        "je .Lf95856_000958df\n"
        "xorl %ecx, %ecx\n" /* line 858 */
        "xorl %edx, %edx\n"
        "movl $0x17, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movl %edi, %edx\n" /* line 617 */
        "movb %dl, (%eax)\n"
        "movl 8(%ebx), %eax\n" /* line 860 */
        "movl %eax, 4(%ebx)\n"
        /* } scope */
        ".Lf95856_000958df:\n"
        "movl $1, (%ebx)\n" /* line 4378 | block */
        "xorl %ecx, %ecx\n" /* line 4380 */
        "xorl %edx, %edx\n"
        "movl $0x62, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 4381 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll AddOpcodePos\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl $0, (%eax)\n" /* line 596 */
        "movl $0xc, (%esp)\n" /* line 4384 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %ebx\n" /* block */
        "movl scrCompileGlob, %eax\n" /* line 4385 */
        "movl %eax, (%ebx)\n" /* block */
        "movl $0, (%esp)\n" /* line 4386 */
        "calll TempMalloc\n"
        "movl %eax, 4(%ebx)\n" /* block */
        "movl scrCompileGlob+56, %eax\n" /* line 4387 */
        "movl %eax, 8(%ebx)\n" /* block */
        "movl %ebx, scrCompileGlob+56\n" /* line 4388 | block */
        "addl $0x1c, %esp\n" /* line 4389 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf95856_00095954:\n"
        "movl $str_0021d824, 4(%esp)\n" /* line 4372 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll CompileError\n"
        "addl $0x1c, %esp\n" /* line 4389 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf95856_0009596c:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* line 888 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompileGlob+76, %eax\n"
        "jmp .Lf95856_00095894\n"
    );
}

/* line 4339 */
static __attribute__((naked))
unsigned int EmitBreakStatement(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4339 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %esi\n" /* sourcePos */
        "movl %edx, %ebx\n" /* block */
        "cmpb $0, scrCompileGlob+44\n" /* line 4343 */
        "je .Lf9598a_00095a8e\n"
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf9598a_00095a8e\n"
        "movl scrCompileGlob+60, %eax\n" /* line 3288 */
        "testl %eax, %eax\n"
        "je .Lf9598a_000959da\n"
        "movl scrCompileGlob+64, %eax\n" /* line 886 */
        "cmpl $0x3ff, (%eax)\n"
        "jg .Lf9598a_00095aa6\n"
        ".Lf9598a_000959c8:\n"
        "movl (%eax), %edx\n" /* line 3291 */
        "movl scrCompileGlob+60, %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n"
        "movl scrCompileGlob+64, %eax\n" /* line 3292 */
        "addl $1, (%eax)\n"
        ".Lf9598a_000959da:\n"
        "movl scrCompileGlob+68, %edx\n" /* line 4351 | outerBlock */
        /* { scope 1 */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 850 */
        "testl %eax, %eax\n"
        "jne .Lf9598a_00095a19\n"
        "movl 4(%ebx), %eax\n" /* line 854 */
        "movl %eax, %edi\n" /* line 856 | removeCount */
        "subl 8(%edx), %edi\n" /* removeCount */
        "je .Lf9598a_00095a19\n"
        "xorl %ecx, %ecx\n" /* line 858 */
        "xorl %edx, %edx\n"
        "movl $0x17, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movl %edi, %edx\n" /* line 617 */
        "movb %dl, (%eax)\n"
        "movl 8(%ebx), %eax\n" /* line 860 */
        "movl %eax, 4(%ebx)\n"
        /* } scope */
        /* } scope */
        ".Lf9598a_00095a19:\n"
        "movl $2, (%ebx)\n" /* line 4352 | block */
        "xorl %ecx, %ecx\n" /* line 4354 */
        "xorl %edx, %edx\n"
        "movl $0x62, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 4355 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll AddOpcodePos\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl $0, (%eax)\n" /* line 596 */
        "movl $0xc, (%esp)\n" /* line 4358 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %ebx\n" /* block */
        "movl scrCompileGlob, %eax\n" /* line 4359 */
        "movl %eax, (%ebx)\n" /* block */
        "movl $0, (%esp)\n" /* line 4360 */
        "calll TempMalloc\n"
        "movl %eax, 4(%ebx)\n" /* block */
        "movl scrCompileGlob+48, %eax\n" /* line 4361 */
        "movl %eax, 8(%ebx)\n" /* block */
        "movl %ebx, scrCompileGlob+48\n" /* line 4362 | block */
        "addl $0x1c, %esp\n" /* line 4363 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9598a_00095a8e:\n"
        "movl $str_0021d840, 4(%esp)\n" /* line 4345 */
        "movl %esi, (%esp)\n" /* sourcePos */
        "calll CompileError\n"
        "addl $0x1c, %esp\n" /* line 4363 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9598a_00095aa6:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* line 888 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompileGlob+64, %eax\n"
        "jmp .Lf9598a_000959c8\n"
    );
}

/* line 1680 */
static __attribute__((naked))
unsigned int EmitFunction(sval_t sourcePos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1680 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ebx\n" /* func */
        "movl %edx, -0x2c(%ebp)\n"
        /* { scope 1 */
        "cmpl $2, scrCompilePub+40\n" /* line 1703 */
        "je .Lf95ac4_00095ce5\n"
        "cmpl $0x14, (%eax)\n" /* line 1716 */
        "je .Lf95ac4_00095d19\n"
        "movl 4(%eax), %eax\n" /* line 1729 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, (%esp)\n"
        "calll Scr_CreateCanonicalFilename\n"
        "movl %eax, %esi\n" /* scope */
        "movl 4(%ebx), %eax\n" /* line 1730 | threadId, stringValue */
        /* { scope 2 */
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "je .Lf95ac4_00095d7a\n"
        /* } scope */
        ".Lf95ac4_00095b0d:\n"
        "movl %esi, 4(%esp)\n" /* line 1731 | scope */
        "movl scrCompilePub+8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalVariable\n"
        "movl %eax, -0x28(%ebp)\n" /* value */
        "movl %edx, -0x24(%ebp)\n"
        "movl -0x24(%ebp), %edi\n" /* line 1732 */
        "movl %esi, (%esp)\n" /* line 1663 */
        "calll SL_AddRefToString\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "je .Lf95ac4_00095d6d\n"
        ".Lf95ac4_00095b44:\n"
        "movl scrCompileGlob+84, %eax\n" /* line 1665 */
        "movw %si, (%eax)\n"
        "movl scrCompileGlob+84, %eax\n" /* line 1666 */
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, 4(%eax)\n"
        "movl scrCompileGlob+84, %eax\n" /* line 1667 */
        "movb $0, 2(%eax)\n"
        "addl $0xc, scrCompileGlob+84\n" /* line 1668 */
        "movl %esi, 4(%esp)\n" /* line 1669 */
        "movl scrCompilePub+12, %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetObjectA\n"
        "movl %eax, %edx\n"
        "testl %edi, %edi\n" /* line 1734 */
        "jne .Lf95ac4_00095ca3\n"
        "leal 8(%ebx), %edi\n" /* line 1751 | threadId */
        "movl 8(%ebx), %eax\n" /* threadId */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, %esi\n" /* scope */
        ".Lf95ac4_00095b9e:\n"
        "movl (%edi), %ebx\n" /* line 1754 | threadId */
        "cmpl $2, scrCompilePub+40\n" /* line 255 */
        "je .Lf95ac4_00095e07\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 266 */
        "jne .Lf95ac4_00095de0\n"
        ".Lf95ac4_00095bba:\n"
        "movl $2, 4(%esp)\n" /* line 268 */
        "movl %ebx, (%esp)\n" /* stringValue */
        "calll SL_TransferRefToUser\n"
        ".Lf95ac4_00095bca:\n"
        "movl %esi, (%esp)\n" /* line 1756 | scope */
        "calll GetObjectA\n"
        "movl %eax, %ebx\n" /* threadId */
        "movl $1, 4(%esp)\n" /* line 1758 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 1759 */
        "jne .Lf95ac4_00095da2\n"
        ".Lf95ac4_00095bec:\n"
        "movl $1, %esi\n" /* line 1793 | scope */
        ".Lf95ac4_00095bf1:\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %esi, (%eax)\n" /* line 596 */
        "movl $0, 4(%esp)\n" /* line 1800 */
        "movl %ebx, (%esp)\n" /* threadId */
        "calll GetVariable\n"
        "movl %eax, %esi\n" /* scope */
        "movl %eax, (%esp)\n" /* line 1801 */
        "calll Scr_EvalVariable\n"
        "movl %eax, -0x20(%ebp)\n" /* count */
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1804 */
        "testl %eax, %eax\n"
        "jne .Lf95ac4_00095c39\n"
        "movl $6, -0x1c(%ebp)\n" /* line 1806 */
        "movl $0, -0x20(%ebp)\n" /* line 1807 | count */
        ".Lf95ac4_00095c39:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1810 | count */
        "addl $2, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* threadId */
        "calll GetNewVariable\n"
        "movl scrCompileGlob, %edx\n" /* line 1811 */
        "movl %edx, -0x28(%ebp)\n" /* value */
        "cmpl $1, scrCompilePub+40\n" /* line 1816 */
        "sbbl %edx, %edx\n"
        "andl $0xfffffffb, %edx\n"
        "addl $0xc, %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "leal -0x28(%ebp), %edx\n" /* line 1823 | value */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetNewVariableValue\n"
        "addl $1, -0x20(%ebp)\n" /* line 1825 | count */
        "leal -0x20(%ebp), %eax\n" /* line 1826 | count */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* scope */
        "calll SetVariableValue\n"
        "movl $0, 4(%esp)\n" /* line 1828 */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        /* } scope */
        ".Lf95ac4_00095c9b:\n"
        "addl $0x3c, %esp\n" /* line 1829 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf95ac4_00095ca3:\n"
        "leal 8(%ebx), %edi\n" /* line 1736 | threadId */
        "movl 8(%ebx), %eax\n" /* threadId */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, %esi\n" /* scope */
        "testl %eax, %eax\n" /* line 1737 */
        "je .Lf95ac4_00095d87\n"
        "movl %eax, (%esp)\n" /* line 1743 */
        "calll GetVarType\n"
        "subl $1, %eax\n"
        "je .Lf95ac4_00095b9e\n"
        "movl $str_0021d75c, 4(%esp)\n" /* line 1745 */
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf95ac4_00095c9b\n"
        ".Lf95ac4_00095ce5:\n"
        "movl 4(%eax), %eax\n" /* line 1705 | stringValue */
        /* { scope 2 */
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "je .Lf95ac4_00095e21\n"
        /* } scope */
        ".Lf95ac4_00095cf5:\n"
        "cmpl $0x15, (%ebx)\n" /* line 1706 | threadId */
        "jne .Lf95ac4_00095c9b\n"
        "movl 8(%ebx), %eax\n" /* line 1708 | threadId, stringValue */
        /* { scope 2 */
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "je .Lf95ac4_00095e53\n"
        /* } scope */
        ".Lf95ac4_00095d0a:\n"
        "subl $1, scrCompilePub+4\n" /* line 1709 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1829 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf95ac4_00095d19:\n"
        "movl 4(%eax), %eax\n" /* line 1720 */
        "movl %eax, 4(%esp)\n"
        "movl scrCompileGlob+8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, %esi\n" /* scope */
        "movl 4(%ebx), %ebx\n" /* line 1721 | threadId */
        "cmpl $2, scrCompilePub+40\n" /* line 255 */
        "je .Lf95ac4_00095ded\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 266 */
        "jne .Lf95ac4_00095e46\n"
        ".Lf95ac4_00095d4c:\n"
        "movl $2, 4(%esp)\n" /* line 268 */
        "movl %ebx, (%esp)\n" /* stringValue */
        "calll SL_TransferRefToUser\n"
        ".Lf95ac4_00095d5c:\n"
        "movl %esi, (%esp)\n" /* line 1722 | scope */
        "calll GetObjectA\n"
        "movl %eax, %ebx\n" /* threadId */
        "xorl %esi, %esi\n" /* scope */
        "jmp .Lf95ac4_00095bf1\n"
        ".Lf95ac4_00095d6d:\n"
        "movl %esi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf95ac4_00095b44\n"
        /* { scope 2 */
        ".Lf95ac4_00095d7a:\n"
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "jmp .Lf95ac4_00095b0d\n"
        /* } scope */
        ".Lf95ac4_00095d87:\n"
        "movl $str_0021d75c, 4(%esp)\n" /* line 1769 */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1829 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf95ac4_00095da2:\n"
        "movl %eax, (%esp)\n" /* line 1762 */
        "calll Scr_EvalVariable\n"
        "movl %eax, %esi\n" /* scope */
        "cmpl $0xd, %edx\n" /* line 1767 */
        "je .Lf95ac4_00095d87\n"
        "testl %esi, %esi\n" /* line 1773 | scope */
        "je .Lf95ac4_00095bec\n"
        "cmpl $7, %edx\n" /* line 1776 */
        "je .Lf95ac4_00095dc8\n"
        "movl scrCompilePub+40, %edx\n" /* line 1786 */
        "testl %edx, %edx\n"
        "je .Lf95ac4_00095e2e\n"
        ".Lf95ac4_00095dc8:\n"
        "movl $4, (%esp)\n" /* line 637 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %esi, (%eax)\n" /* line 638 */
        "jmp .Lf95ac4_00095c9b\n"
        ".Lf95ac4_00095de0:\n"
        "movl %ebx, (%esp)\n" /* line 267 | stringValue */
        "calll SL_AddRefToString\n"
        "jmp .Lf95ac4_00095bba\n"
        /* { scope 2 */
        ".Lf95ac4_00095ded:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf95ac4_00095d5c\n"
        "movl %ebx, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf95ac4_00095d5c\n"
        /* } scope */
        /* { scope 2 */
        ".Lf95ac4_00095e07:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf95ac4_00095bca\n"
        "movl %ebx, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf95ac4_00095bca\n"
        /* } scope */
        /* { scope 2 */
        ".Lf95ac4_00095e21:\n"
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "jmp .Lf95ac4_00095cf5\n"
        /* } scope */
        ".Lf95ac4_00095e2e:\n"
        "movl $str_0021d718, 4(%esp)\n" /* line 1788 */
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf95ac4_00095c9b\n"
        ".Lf95ac4_00095e46:\n"
        "movl %ebx, (%esp)\n" /* line 267 | stringValue */
        "calll SL_AddRefToString\n"
        "jmp .Lf95ac4_00095d4c\n"
        /* { scope 2 */
        ".Lf95ac4_00095e53:\n"
        "movl %eax, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf95ac4_00095d0a\n"
    );
}

/* line 2091 */
static __attribute__((naked))
unsigned int EmitCall(sval_t func_name, sval_t params, Bool bStatement, scr_block_t *block)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2091 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl %edx, -0x50(%ebp)\n"
        "movb %cl, -0x51(%ebp)\n"
        /* { scope 1 */
        "cmpl $0x1a, (%eax)\n" /* line 1969 */
        "je .Lf95e60_00095f4b\n"
        "movl %eax, %edx\n"
        "cmpl $0x1a, (%edx)\n" /* line 1947 */
        "je .Lf95e60_00095f5f\n"
        /* { scope 2: constValue */
        ".Lf95e60_00095e86:\n"
        "movl -0x50(%ebp), %eax\n" /* line 1624 */
        "movl (%eax), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf95e60_00095f2a\n"
        "xorl %esi, %esi\n"
        "leal -0x34(%ebp), %edi\n" /* constValue */
        "jmp .Lf95e60_00095ea4\n"
        ".Lf95e60_00095e9a:\n"
        "addl $1, %esi\n" /* line 1627 */
        "movl 4(%ebx), %ebx\n" /* line 1624 | node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf95e60_00095ec7\n"
        ".Lf95e60_00095ea4:\n"
        "movl (%ebx), %eax\n" /* line 1626 | node */
        "movl (%eax), %eax\n"
        /* { scope 3 */
        "movl 8(%ebp), %ecx\n" /* line 2883 | block */
        "movl %edi, %edx\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf95e60_00095e9a\n"
        "movl %edi, %eax\n" /* line 2885 */
        "calll EmitValue\n"
        /* } scope */
        "addl $1, %esi\n" /* line 1627 */
        "movl 4(%ebx), %ebx\n" /* line 1624 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf95e60_00095ea4\n"
        /* } scope */
        ".Lf95e60_00095ec7:\n"
        "movl 8(%ebp), %edx\n" /* line 2183 | block */
        "movl %edx, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %esi, %edx\n" /* name */
        "movl -0x4c(%ebp), %eax\n"
        "calll EmitPostFunctionCall\n"
        /* { scope 2: constValue */
        "movl imp_scrVarPub, %eax\n" /* line 1651 */
        "cmpb $0, 0xa(%eax)\n"
        "jne .Lf95e60_00095f03\n"
        /* } scope */
        ".Lf95e60_00095ee4:\n"
        "cmpb $0, -0x51(%ebp)\n" /* line 2186 */
        "je .Lf95e60_00095efb\n"
        "xorl %ecx, %ecx\n" /* line 1535 */
        "movl $0xffffffff, %edx\n"
        "movl $0x58, %eax\n"
        "calll EmitOpcode\n"
        /* } scope */
        ".Lf95e60_00095efb:\n"
        "addl $0x5c, %esp\n" /* line 2188 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: constValue */
        ".Lf95e60_00095f03:\n"
        "movl -0x50(%ebp), %eax\n" /* line 1654 */
        "movl (%eax), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf95e60_00095ee4\n"
        ".Lf95e60_00095f0c:\n"
        "movl $0, 4(%esp)\n" /* line 1655 */
        "movl (%ebx), %eax\n" /* node */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl 4(%ebx), %ebx\n" /* line 1654 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf95e60_00095f0c\n"
        "jmp .Lf95e60_00095ee4\n"
        /* } scope */
        /* { scope 2: constValue */
        ".Lf95e60_00095f2a:\n"
        "xorl %esi, %esi\n" /* line 1624 */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 2183 | block */
        "movl %edx, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %esi, %edx\n" /* name */
        "movl -0x4c(%ebp), %eax\n"
        "calll EmitPostFunctionCall\n"
        /* { scope 2: constValue */
        "movl imp_scrVarPub, %eax\n" /* line 1651 */
        "cmpb $0, 0xa(%eax)\n"
        "je .Lf95e60_00095ee4\n"
        "jmp .Lf95e60_00095f03\n"
        /* } scope */
        ".Lf95e60_00095f4b:\n"
        "movl 4(%eax), %ebx\n" /* line 1971 | i */
        "cmpl $0x12, (%ebx)\n" /* line 1972 | i */
        "je .Lf95e60_00095f75\n"
        ".Lf95e60_00095f53:\n"
        "movl -0x4c(%ebp), %edx\n"
        "cmpl $0x1a, (%edx)\n" /* line 1947 */
        "jne .Lf95e60_00095e86\n"
        ".Lf95e60_00095f5f:\n"
        "xorl %ecx, %ecx\n" /* line 1948 */
        "movl $1, %edx\n"
        "movl $0x4e, %eax\n"
        "calll EmitOpcode\n"
        "jmp .Lf95e60_00095e86\n"
        ".Lf95e60_00095f75:\n"
        "movl 4(%ebx), %ebx\n" /* line 1974 | i */
        "cmpl $0x14, (%ebx)\n" /* line 1975 | i */
        "jne .Lf95e60_00095f53\n"
        "movl 4(%ebx), %eax\n" /* line 1981 | i */
        "movl %eax, 4(%esp)\n"
        "movl scrCompileGlob+8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf95e60_00095f53\n"
        "movl 4(%ebx), %esi\n" /* line 1984 | i */
        "testl %esi, %esi\n" /* line 2104 | name */
        "je .Lf95e60_00095f53\n"
        "movl %esi, (%esp)\n" /* line 2106 | name */
        "calll SL_ConvertToString\n"
        "movl %eax, -0x1c(%ebp)\n" /* pName */
        "movl -0x4c(%ebp), %eax\n" /* line 2107 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* sourcePos */
        "movl %esi, 4(%esp)\n" /* line 2114 | name */
        "movl scrCompilePub+16, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 2115 */
        "je .Lf95e60_00096039\n"
        "movl %eax, (%esp)\n" /* line 2117 */
        "calll Scr_EvalVariable\n"
        "movl %eax, -0x28(%ebp)\n" /* value */
        "movl %edx, -0x24(%ebp)\n"
        "xorl %eax, %eax\n" /* line 2038 */
        "cmpl $7, -0x24(%ebp)\n"
        "setne %al\n"
        "movl %eax, -0x20(%ebp)\n" /* line 2118 | type */
        "movl -0x28(%ebp), %edx\n" /* line 2119 | value */
        "movl %edx, -0x40(%ebp)\n" /* func */
        ".Lf95e60_00095fe5:\n"
        "movl -0x40(%ebp), %ebx\n" /* line 2139 | func, i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf95e60_00095f53\n"
        "cmpl $1, -0x20(%ebp)\n" /* line 2142 | type */
        "je .Lf95e60_000961f4\n"
        /* { scope 2: constValue */
        ".Lf95e60_00095ffa:\n"
        "movl -0x50(%ebp), %edx\n" /* line 1624 */
        "movl (%edx), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf95e60_000961e3\n"
        "movl $0, -0x44(%ebp)\n" /* param_count */
        "leal -0x34(%ebp), %edi\n" /* constValue */
        "jmp .Lf95e60_0009601e\n"
        ".Lf95e60_00096013:\n"
        "addl $1, -0x44(%ebp)\n" /* line 1627 | param_count */
        "movl 4(%ebx), %ebx\n" /* line 1624 | node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf95e60_0009608f\n"
        ".Lf95e60_0009601e:\n"
        "movl (%ebx), %eax\n" /* line 1626 | node */
        "movl (%eax), %eax\n"
        /* { scope 3 */
        "movl 8(%ebp), %ecx\n" /* line 2883 | block */
        "movl %edi, %edx\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf95e60_00096013\n"
        "movl %edi, %eax\n" /* line 2885 */
        "calll EmitValue\n"
        "jmp .Lf95e60_00096013\n"
        /* } scope */
        /* } scope */
        ".Lf95e60_00096039:\n"
        "movl $0, -0x20(%ebp)\n" /* line 2123 | type */
        "leal -0x20(%ebp), %eax\n" /* line 2124 | type */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* pName */
        "movl %eax, (%esp)\n"
        "calll Scr_GetFunction\n"
        "movl %eax, -0x40(%ebp)\n" /* func */
        "movl %esi, 4(%esp)\n" /* line 2125 | name */
        "movl scrCompilePub+16, %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetNewVariable\n"
        "cmpl $1, -0x20(%ebp)\n" /* line 2024 | type */
        "sbbl %edx, %edx\n"
        "andl $0xfffffffb, %edx\n"
        "addl $0xc, %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* line 2126 */
        "movl -0x40(%ebp), %edx\n" /* line 2127 | func */
        "movl %edx, -0x28(%ebp)\n" /* value */
        "leal -0x28(%ebp), %edx\n" /* line 2128 | value */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        "jmp .Lf95e60_00095fe5\n"
        ".Lf95e60_0009608f:\n"
        "cmpl $0xff, -0x44(%ebp)\n" /* line 2154 | param_count */
        "jg .Lf95e60_00096231\n"
        "movb $1, %bl\n" /* i */
        "subl -0x44(%ebp), %ebx\n" /* param_count, i */
        ".Lf95e60_000960a1:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf95e60_000960b2\n"
        "movl %esi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        /* { scope 2: constValue */
        ".Lf95e60_000960b2:\n"
        "cmpl $5, -0x44(%ebp)\n" /* line 2054 | param_count */
        "jle .Lf95e60_000961d8\n"
        "movl $0x44, %esi\n" /* opcode */
        ".Lf95e60_000960c1:\n"
        "movl $1, %ecx\n" /* line 2059 */
        "movl %ebx, %edx\n" /* i */
        "movl %esi, %eax\n" /* opcode */
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 2060 */
        "movl -0x48(%ebp), %edx\n" /* sourcePos */
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "cmpl $0x44, %esi\n" /* line 2062 | opcode */
        "je .Lf95e60_00096294\n"
        /* } scope */
        /* { scope 2: constValue */
        ".Lf95e60_000960eb:\n"
        "movl scrCompilePub+52, %edx\n" /* line 1844 */
        "testl %edx, %edx\n"
        "jg .Lf95e60_000961a7\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf95e60_000960fb:\n"
        "cmpl $0x400, %edx\n" /* line 1851 */
        "je .Lf95e60_00096267\n"
        ".Lf95e60_00096107:\n"
        "movl -0x40(%ebp), %eax\n" /* line 1854 | func */
        "movl %eax, scrCompilePub+56(, %edx, 4)\n"
        "leal 1(%edx), %eax\n" /* line 1860 */
        "movl %eax, scrCompilePub+52\n"
        /* } scope */
        ".Lf95e60_00096119:\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw %bx, (%eax)\n" /* line 610 */
        /* { scope 2: constValue */
        "movl imp_scrVarPub, %eax\n" /* line 1651 */
        "cmpb $0, 0xa(%eax)\n"
        "je .Lf95e60_0009615d\n"
        "movl -0x50(%ebp), %edx\n" /* line 1654 */
        "movl (%edx), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf95e60_0009615d\n"
        ".Lf95e60_00096141:\n"
        "movl $0, 4(%esp)\n" /* line 1655 */
        "movl (%ebx), %eax\n" /* node */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl 4(%ebx), %ebx\n" /* line 1654 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf95e60_00096141\n"
        /* } scope */
        ".Lf95e60_0009615d:\n"
        "cmpb $0, -0x51(%ebp)\n" /* line 2165 */
        "je .Lf95e60_00096174\n"
        "xorl %ecx, %ecx\n" /* line 1535 */
        "movl $0xffffffff, %edx\n"
        "movl $0x58, %eax\n"
        "calll EmitOpcode\n"
        ".Lf95e60_00096174:\n"
        "cmpl $1, -0x20(%ebp)\n" /* line 2012 | type */
        "jne .Lf95e60_00095efb\n"
        "movl $0, scrCompilePub+40\n" /* line 2015 */
        "movl imp_scrVarPub, %eax\n" /* line 2017 */
        "cmpb $0, 0xb(%eax)\n"
        "jne .Lf95e60_00095efb\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2018 | savedPos */
        "movl %eax, (%esp)\n"
        "calll TempMemorySetPos\n"
        "jmp .Lf95e60_00095efb\n"
        /* { scope 2: constValue */
        ".Lf95e60_000961a7:\n"
        "movl -0x40(%ebp), %eax\n" /* line 1846 | func */
        "cmpl scrCompilePub+56, %eax\n"
        "je .Lf95e60_0009628d\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl $scrCompilePub, %ecx\n"
        ".Lf95e60_000961bd:\n"
        "addl $1, %ebx\n" /* line 1844 | i */
        "cmpl %ebx, %edx\n" /* i */
        "je .Lf95e60_00096286\n"
        "movl 0x3c(%ecx), %eax\n" /* line 1846 */
        "addl $4, %ecx\n"
        "cmpl %eax, -0x40(%ebp)\n" /* func */
        "jne .Lf95e60_000961bd\n"
        "jmp .Lf95e60_00096119\n"
        /* } scope */
        /* { scope 2: constValue */
        ".Lf95e60_000961d8:\n"
        "movl -0x44(%ebp), %esi\n" /* line 2055 | param_count, opcode */
        "addl $0x3e, %esi\n" /* opcode */
        "jmp .Lf95e60_000960c1\n"
        /* } scope */
        ".Lf95e60_000961e3:\n"
        "movl $0, -0x44(%ebp)\n" /* line 2157 | param_count */
        "movl $1, %ebx\n" /* i */
        "jmp .Lf95e60_000960a1\n"
        ".Lf95e60_000961f4:\n"
        "movl scrCompilePub+40, %ecx\n" /* line 1990 */
        "testl %ecx, %ecx\n"
        "je .Lf95e60_00096249\n"
        "movl $0, -0x20(%ebp)\n" /* line 1992 | type */
        ".Lf95e60_00096205:\n"
        "cmpl $1, -0x20(%ebp)\n" /* line 2145 | type */
        "jne .Lf95e60_00095ffa\n"
        "cmpb $0, -0x51(%ebp)\n"
        "jne .Lf95e60_00095ffa\n"
        "movl $str_0021d858, 4(%esp)\n" /* line 2147 */
        "movl -0x48(%ebp), %eax\n" /* sourcePos */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf95e60_00095efb\n"
        ".Lf95e60_00096231:\n"
        "movl $str_0021d8ac, 4(%esp)\n" /* line 2156 */
        "movl -0x48(%ebp), %eax\n" /* sourcePos */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf95e60_00095efb\n"
        ".Lf95e60_00096249:\n"
        "movl imp_scrVarPub, %eax\n" /* line 1996 */
        "cmpb $0, 0xb(%eax)\n"
        "je .Lf95e60_000962b0\n"
        "movl $1, scrCompilePub+40\n" /* line 2003 */
        ".Lf95e60_0009625e:\n"
        "movl $1, -0x20(%ebp)\n" /* line 2006 | type */
        "jmp .Lf95e60_00096205\n"
        /* { scope 2: constValue */
        ".Lf95e60_00096267:\n"
        "movl $str_0021d8c8, 4(%esp)\n" /* line 1852 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompilePub+52, %edx\n"
        "jmp .Lf95e60_00096107\n"
        ".Lf95e60_00096286:\n"
        "movl %edx, %ebx\n" /* line 1844 | i */
        "jmp .Lf95e60_000960fb\n"
        ".Lf95e60_0009628d:\n"
        "xorl %ebx, %ebx\n" /* line 1846 | i */
        "jmp .Lf95e60_00096119\n"
        /* } scope */
        /* { scope 2: constValue */
        ".Lf95e60_00096294:\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movzbl -0x44(%ebp), %edx\n" /* line 617 | param_count */
        "movb %dl, (%eax)\n"
        "jmp .Lf95e60_000960eb\n"
        /* } scope */
        ".Lf95e60_000962b0:\n"
        "movl $0, (%esp)\n" /* line 1998 */
        "calll TempMalloc\n"
        "movl %eax, -0x3c(%ebp)\n" /* savedPos */
        "movl $2, scrCompilePub+40\n" /* line 1999 */
        "jmp .Lf95e60_0009625e\n"
    );
}

/* line 2642 */
static __attribute__((naked))
Bool EmitOrEvalPrimitiveExpression(void)
{
    __asm__ __volatile__ (
        ".Lf962cc_000962cc:\n"
        "pushl %ebp\n" /* line 2642 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %edx, %edi\n" /* constValue */
        "movl %ecx, %ebx\n" /* block */
        "movl (%eax), %edx\n" /* line 2644 | expr */
        "subl $0x11, %edx\n"
        "cmpl $0x39, %edx\n"
        "ja .Lf962cc_000962ea\n"
        "jmpl *CorrectSolidDeltas+4392(, %edx, 4)\n"
        ".Lf962cc_000962ea:\n"
        "movl %edi, %edx\n" /* line 2694 | constValue */
        "calll EvalPrimitiveExpression\n"
        ".Lf962cc_000962f1:\n"
        "movzbl %al, %eax\n" /* expr */
        ".Lf962cc_000962f4:\n"
        "addl $0x4c, %esp\n" /* line 2695 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 4(%eax), %esi\n" /* line 2654 | expr */
        "movl %ecx, %edx\n"
        "movl %esi, %eax\n" /* expr */
        "calll EmitVariableExpression\n"
        "xorl %eax, %eax\n" /* expr */
        "jmp .Lf962cc_000962f4\n"
        "movl 8(%eax), %edx\n" /* line 2678 | expr */
        "movl %edx, -0x48(%ebp)\n"
        "movl 4(%eax), %esi\n" /* expr */
        "xorl %ecx, %ecx\n" /* line 1834 */
        "movl $1, %edx\n"
        "movl $0x15, %eax\n"
        "calll EmitOpcode\n"
        "movl $3, 4(%esp)\n" /* line 1835 */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl -0x48(%ebp), %edx\n" /* line 1836 */
        "movl %esi, %eax\n"
        "calll EmitFunction\n"
        "xorl %eax, %eax\n"
        "jmp .Lf962cc_000962f4\n"
        "movl 4(%eax), %esi\n" /* line 2650 | expr */
        "movl (%esi), %eax\n" /* line 2429 */
        "cmpl $0x17, %eax\n"
        "je .Lf962cc_000965e2\n"
        "cmpl $0x18, %eax\n"
        "je .Lf962cc_00096585\n"
        ".Lf962cc_0009635e:\n"
        "xorl %eax, %eax\n" /* line 2694 | expr */
        "jmp .Lf962cc_000962f4\n"
        "movl 4(%eax), %esi\n" /* line 2658 | expr */
        "xorl %ecx, %ecx\n" /* line 1268 */
        "movl $1, %edx\n"
        "movl $0xf, %eax\n"
        ".Lf962cc_00096371:\n"
        "calll EmitOpcode\n" /* line 1275 */
        "movl $1, 4(%esp)\n" /* line 1276 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "xorl %eax, %eax\n"
        "addl $0x4c, %esp\n" /* line 2695 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 4(%eax), %esi\n" /* line 2662 | expr */
        "xorl %ecx, %ecx\n" /* line 1275 */
        "movl $1, %edx\n"
        "movl $0x10, %eax\n"
        "jmp .Lf962cc_00096371\n"
        "movl 4(%eax), %esi\n" /* line 2666 | expr */
        "xorl %ecx, %ecx\n" /* line 1282 */
        "movl $1, %edx\n"
        "movl $0x11, %eax\n"
        "jmp .Lf962cc_00096371\n"
        "movl 4(%eax), %esi\n" /* line 2670 | expr */
        "xorl %ecx, %ecx\n" /* line 1289 */
        "movl $1, %edx\n"
        "movl $0x12, %eax\n"
        "jmp .Lf962cc_00096371\n"
        "movl 8(%eax), %edx\n" /* line 2647 | expr */
        "movl %edx, -0x48(%ebp)\n"
        "movl 4(%eax), %esi\n" /* expr */
        /* { scope 1: constValue */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 1612 */
        "movl %eax, %edx\n"
        "testl %eax, %eax\n"
        "je .Lf962cc_000965bc\n"
        "xorl %ecx, %ecx\n"
        ".Lf962cc_000963da:\n"
        "addl $1, %ecx\n" /* line 1613 */
        "movl 4(%edx), %edx\n" /* line 1612 */
        "testl %edx, %edx\n"
        "jne .Lf962cc_000963da\n"
        /* } scope */
        "cmpl $1, %ecx\n" /* line 2536 */
        "je .Lf962cc_000965fb\n"
        "cmpl $3, %ecx\n" /* line 2542 */
        "jne .Lf962cc_000965bc\n"
        "movl %eax, -0x3c(%ebp)\n" /* line 2545 */
        "testl %eax, %eax\n"
        "je .Lf962cc_00096617\n"
        ".Lf962cc_00096401:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 2549 */
        "movl (%edx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %ebx, %ecx\n" /* node */
        "leal -0x24(%ebp), %edx\n" /* constValue2 */
        "calll EmitOrEvalExpression\n"
        "movb %al, -0x41(%ebp)\n" /* success */
        "testb %al, %al\n" /* line 2550 */
        "je .Lf962cc_00096455\n"
        "movl scrCompilePub, %eax\n" /* line 1218 */
        "movl %eax, -0x40(%ebp)\n"
        "cmpl $0x1f, %eax\n"
        "jg .Lf962cc_00096686\n"
        "movl $scrCompileGlob+80, %ecx\n" /* line 1224 */
        "leal (%eax, %eax, 2), %edx\n"
        "shll $2, %edx\n"
        "movl -0x24(%ebp), %eax\n" /* constValue2 */
        "movl %eax, 0xc(%edx, %ecx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%edx, %ecx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x14(%edx, %ecx)\n"
        "movl -0x40(%ebp), %eax\n" /* line 1225 */
        "addl $1, %eax\n"
        "movl %eax, scrCompilePub\n"
        ".Lf962cc_00096455:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2545 */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf962cc_0009660d\n"
        "cmpb $0, -0x41(%ebp)\n" /* line 2547 | success */
        "jne .Lf962cc_00096401\n"
        "movl -0x3c(%ebp), %edx\n" /* line 2555 */
        "movl (%edx), %eax\n"
        "movl (%eax), %eax\n"
        /* { scope 2 */
        "movl %ebx, %ecx\n" /* line 2883 | block */
        "leal -0x30(%ebp), %edx\n" /* constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n" /* expr */
        "je .Lf962cc_00096455\n"
        "leal -0x30(%ebp), %eax\n" /* line 2885 | constValue, expr */
        "calll EmitValue\n"
        "jmp .Lf962cc_00096455\n"
        /* } scope */
        /* } scope */
        "movl 8(%eax), %edx\n" /* line 2674 | expr */
        "movl %edx, -0x48(%ebp)\n"
        "movl 4(%eax), %esi\n" /* expr */
        /* { scope 1: constValue */
        "leal -0x30(%ebp), %edi\n" /* line 2702 | constValue */
        "movl %edi, %edx\n" /* constValue */
        "movl %esi, %eax\n" /* expr */
        "calll EmitOrEvalPrimitiveExpression\n"
        "testb %al, %al\n" /* expr */
        "jne .Lf962cc_000965d6\n"
        /* } scope */
        ".Lf962cc_000964a8:\n"
        "xorl %ecx, %ecx\n" /* line 1261 */
        "xorl %edx, %edx\n"
        "movl $0x76, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1262 */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "xorl %eax, %eax\n"
        "jmp .Lf962cc_000962f4\n"
        "movl 4(%eax), %esi\n" /* line 2682 | expr */
        "xorl %ecx, %ecx\n" /* line 1424 */
        "movl $1, %edx\n"
        "movl $0x25, %eax\n"
        "jmp .Lf962cc_00096371\n"
        "movl 8(%eax), %edx\n" /* line 2686 | expr */
        "movl %edx, -0x48(%ebp)\n"
        "movl 4(%eax), %esi\n" /* expr */
        "xorl %ecx, %ecx\n" /* line 1433 */
        "movl $1, %edx\n"
        "movl $0x13, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 1434 */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl $0xffffffff, (%eax)\n" /* line 596 */
        "movl -0x48(%ebp), %edx\n" /* line 1437 */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl scrCompileGlob, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EmitAnimation\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf962cc_0009635e\n"
        "movl %esi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "xorl %eax, %eax\n"
        "jmp .Lf962cc_000962f4\n"
        "movl 4(%eax), %esi\n" /* line 2690 | expr */
        "movl imp_scrAnimPub, %eax\n" /* line 740 */
        "movl 0x414(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf962cc_000965ae\n"
        "movl $str_0021d930, 4(%esp)\n" /* line 742 */
        "movl %esi, (%esp)\n"
        "calll CompileError\n"
        "xorl %eax, %eax\n"
        "jmp .Lf962cc_000962f4\n"
        ".Lf962cc_00096585:\n"
        "movl 0x10(%esi), %eax\n" /* line 2436 */
        "movl 0xc(%esi), %ecx\n"
        "movl 8(%esi), %edx\n"
        "movl 4(%esi), %esi\n"
        "movl %ebx, 8(%esp)\n" /* node */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl %esi, %eax\n"
        "calll EmitMethod\n"
        "xorl %eax, %eax\n"
        "jmp .Lf962cc_000962f4\n"
        ".Lf962cc_000965ae:\n"
        "movl %esi, %edx\n" /* line 746 */
        "calll EmitGetInteger\n"
        "xorl %eax, %eax\n"
        "jmp .Lf962cc_000962f4\n"
        /* { scope 1: constValue */
        ".Lf962cc_000965bc:\n"
        "movl $str_0021d904, 4(%esp)\n" /* line 2574 */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "xorl %eax, %eax\n"
        "jmp .Lf962cc_000962f1\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf962cc_000965d6:\n"
        "movl %edi, %eax\n" /* line 2704 | constValue, expr */
        "calll EmitValue\n"
        "jmp .Lf962cc_000964a8\n"
        /* } scope */
        ".Lf962cc_000965e2:\n"
        "movl 8(%esi), %edx\n" /* line 2432 */
        "movl 4(%esi), %esi\n"
        "movl %ecx, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %esi, %eax\n"
        "calll EmitCall\n"
        "xorl %eax, %eax\n"
        "jmp .Lf962cc_000962f4\n"
        /* { scope 1: constValue */
        ".Lf962cc_000965fb:\n"
        "movl (%eax), %eax\n" /* line 2539 */
        "movl (%eax), %eax\n"
        "movl %ebx, %ecx\n" /* node */
        "movl %edi, %edx\n"
        "calll EmitOrEvalExpression\n"
        "jmp .Lf962cc_000962f1\n"
        ".Lf962cc_0009660d:\n"
        "cmpb $0, -0x41(%ebp)\n" /* line 2559 | success */
        "je .Lf962cc_0009669e\n"
        ".Lf962cc_00096617:\n"
        "movl scrCompilePub, %eax\n" /* line 2562 */
        "subl $3, %eax\n"
        "movl %eax, scrCompilePub\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 2563 */
        "leal scrCompileGlob+92(, %eax, 4), %ecx\n"
        "xorl %esi, %esi\n"
        "leal -0x30(%ebp), %ebx\n" /* constValue, node */
        /* { scope 2 */
        ".Lf962cc_00096633:\n"
        "movl 4(%ecx), %edx\n" /* line 2467 */
        "cmpl $5, %edx\n" /* line 2468 */
        "je .Lf962cc_0009667f\n"
        "cmpl $6, %edx\n" /* line 2473 */
        "jne .Lf962cc_000966f6\n"
        "cvtsi2ssl (%ecx), %xmm0\n" /* line 2475 */
        "movss %xmm0, 8(%ebx)\n" /* node */
        ".Lf962cc_0009664d:\n"
        "addl $0xc, %esi\n" /* line 2480 */
        "addl $0xc, %ecx\n"
        "subl $4, %ebx\n" /* node */
        "cmpl $0x24, %esi\n" /* line 2465 */
        "jne .Lf962cc_00096633\n"
        "movl $4, 4(%edi)\n" /* line 2484 */
        "leal -0x30(%ebp), %edx\n" /* line 2485 | constValue */
        "movl %edx, (%esp)\n"
        "calll Scr_AllocVector\n"
        "movl %eax, (%edi)\n"
        /* } scope */
        ".Lf962cc_0009666f:\n"
        "movl -0x48(%ebp), %eax\n" /* line 2564 */
        "movl %eax, 8(%edi)\n"
        "movl $1, %eax\n"
        "jmp .Lf962cc_000962f1\n"
        /* { scope 2 */
        ".Lf962cc_0009667f:\n"
        "movl (%ecx), %eax\n" /* line 2470 */
        "movl %eax, 8(%ebx)\n" /* node */
        "jmp .Lf962cc_0009664d\n"
        /* } scope */
        ".Lf962cc_00096686:\n"
        "movl $str_0021d8e8, 4(%esp)\n" /* line 1220 */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf962cc_00096455\n"
        ".Lf962cc_0009669e:\n"
        "xorl %ecx, %ecx\n" /* line 2568 */
        "movl $0xfffffffe, %edx\n"
        "movl $0x7e, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 2569 */
        "movl -0x48(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        /* { scope 2 */
        "movl imp_scrVarPub, %eax\n" /* line 1651 */
        "cmpb $0, 0xa(%eax)\n"
        "je .Lf962cc_000966ef\n"
        "movl (%esi), %ebx\n" /* line 1654 | node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf962cc_000966ef\n"
        ".Lf962cc_000966d3:\n"
        "movl $0, 4(%esp)\n" /* line 1655 */
        "movl (%ebx), %eax\n" /* node */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl 4(%ebx), %ebx\n" /* line 1654 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf962cc_000966d3\n"
        /* } scope */
        ".Lf962cc_000966ef:\n"
        "xorl %eax, %eax\n" /* line 2574 */
        "jmp .Lf962cc_000962f1\n"
        /* { scope 2 */
        ".Lf962cc_000966f6:\n"
        "movl imp_var_typename, %eax\n" /* line 2480 */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021cea0, 4(%esp)\n" /* "type %s is not a float" */
        "movl 8(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf962cc_0009666f\n"
    );
}

/* line 2846 */
static __attribute__((naked))
Bool EmitOrEvalExpression(void)
{
    __asm__ __volatile__ (
        ".Lf9671a_0009671a:\n"
        "pushl %ebp\n" /* line 2846 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %ebx\n" /* expr */
        "movl %edx, %edi\n" /* constValue */
        "movl %ecx, %esi\n" /* block */
        "movl (%eax), %eax\n" /* line 2848 */
        "subl $6, %eax\n"
        "cmpl $0x2d, %eax\n"
        "ja .Lf9671a_00096776\n"
        "jmpl *CorrectSolidDeltas+4624(, %eax, 4)\n"
        "movl 4(%ebx), %eax\n" /* line 2870 | expr */
        /* { scope 1: constValue, constValue */
        "leal -0x24(%ebp), %edi\n" /* line 2883 | constValue */
        "movl %edi, %edx\n" /* constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf9671a_00096a69\n"
        /* } scope */
        ".Lf9671a_0009674f:\n"
        "movl 8(%ebx), %ebx\n" /* line 2871 | expr */
        "movl %ebx, -0x54(%ebp)\n" /* expr */
        "xorl %ecx, %ecx\n" /* line 1253 */
        "xorl %edx, %edx\n"
        "movl $0x5d, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1254 */
        "movl -0x54(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        ".Lf9671a_00096776:\n"
        "xorl %eax, %eax\n"
        ".Lf9671a_00096778:\n"
        "addl $0x6c, %esp\n" /* line 2876 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 4(%ebx), %eax\n" /* line 2851 | expr */
        "calll EmitOrEvalPrimitiveExpression\n"
        "movzbl %al, %eax\n"
        "jmp .Lf9671a_00096778\n"
        "movl 4(%ebx), %eax\n" /* line 2865 | expr */
        /* { scope 1: constValue, constValue */
        "leal -0x3c(%ebp), %edi\n" /* line 2883 | constValue */
        "movl %edi, %edx\n" /* constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf9671a_00096a5d\n"
        /* } scope */
        ".Lf9671a_000967a2:\n"
        "movl 8(%ebx), %ebx\n" /* line 2866 | expr */
        "movl %ebx, -0x54(%ebp)\n" /* expr */
        "xorl %ecx, %ecx\n" /* line 1246 */
        "xorl %edx, %edx\n"
        "movl $0x5c, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1247 */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "xorl %eax, %eax\n"
        "jmp .Lf9671a_00096778\n"
        "movl 0x10(%ebx), %eax\n" /* line 2862 | expr */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0xc(%ebx), %edx\n" /* expr */
        "movl %edx, -0x58(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* expr */
        "movl %eax, -0x54(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* expr */
        /* { scope 1: constValue, constValue */
        "leal -0x24(%ebp), %edx\n" /* line 2779 | constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf9671a_00096a3a\n"
        "movl scrCompilePub, %ebx\n" /* line 1218 */
        "cmpl $0x1f, %ebx\n"
        "jg .Lf9671a_000969fe\n"
        "movl $scrCompileGlob+80, %ecx\n" /* line 1224 */
        "leal (%ebx, %ebx, 2), %edx\n"
        "shll $2, %edx\n"
        "movl -0x24(%ebp), %eax\n" /* constValue */
        "movl %eax, 0xc(%edx, %ecx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%edx, %ecx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x14(%edx, %ecx)\n"
        "leal 1(%ebx), %eax\n" /* line 1225 */
        "movl %eax, scrCompilePub\n"
        ".Lf9671a_00096829:\n"
        "leal -0x30(%ebp), %ebx\n" /* line 2787 | constValue2 */
        "movl %esi, %ecx\n"
        "movl %ebx, %edx\n"
        "movl -0x54(%ebp), %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf9671a_00096a81\n"
        ".Lf9671a_00096840:\n"
        "movsbl -0x58(%ebp), %eax\n" /* line 2804 */
        "xorl %ecx, %ecx\n"
        "movl $0xffffffff, %edx\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 2805 */
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "movzbl %al, %eax\n" /* line 2862 */
        "jmp .Lf9671a_00096778\n"
        "movl 0x10(%ebx), %eax\n" /* line 2858 | expr */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0xc(%ebx), %edx\n" /* expr */
        "movl %edx, -0x58(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* expr */
        "movl %eax, -0x54(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* expr */
        /* { scope 1: constValue, constValue */
        /* { scope 2 */
        "leal -0x24(%ebp), %ebx\n" /* line 2883 | constValue, expr */
        "movl %ebx, %edx\n" /* expr */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf9671a_00096a16\n"
        /* } scope */
        ".Lf9671a_00096894:\n"
        "xorl %ecx, %ecx\n" /* line 2735 */
        "movl $0xffffffff, %edx\n"
        "movl $0x60, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 2736 */
        "movl -0x58(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw $0, (%eax)\n" /* line 610 */
        "movl scrCompileGlob, %eax\n" /* line 2738 */
        "movl %eax, -0x4c(%ebp)\n" /* pos */
        "movl $0, (%esp)\n" /* line 2739 */
        "calll TempMalloc\n"
        "movl %eax, %edi\n" /* nextPos */
        /* { scope 2 */
        "movl %esi, %ecx\n" /* line 2883 | block */
        "movl %ebx, %edx\n" /* expr */
        "movl -0x54(%ebp), %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf9671a_00096a2e\n"
        /* } scope */
        ".Lf9671a_000968f8:\n"
        "xorl %ecx, %ecx\n" /* line 1239 */
        "xorl %edx, %edx\n"
        "movl $0x5b, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1240 */
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, (%esp)\n" /* line 2742 */
        "calll TempMalloc\n"
        "subl %edi, %eax\n" /* line 2744 | nextPos */
        "movl -0x4c(%ebp), %edx\n" /* pos */
        "movw %ax, (%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf9671a_00096778\n"
        /* } scope */
        "movl 0x10(%ebx), %eax\n" /* line 2854 | expr */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0xc(%ebx), %edx\n" /* expr */
        "movl %edx, -0x58(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* expr */
        "movl %eax, -0x54(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* expr */
        /* { scope 1: constValue, constValue */
        /* { scope 2 */
        "leal -0x3c(%ebp), %ebx\n" /* line 2883 | constValue, expr */
        "movl %ebx, %edx\n" /* expr */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf9671a_00096a22\n"
        /* } scope */
        ".Lf9671a_0009695b:\n"
        "xorl %ecx, %ecx\n" /* line 2715 */
        "movl $0xffffffff, %edx\n"
        "movl $0x61, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 2716 */
        "movl -0x58(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw $0, (%eax)\n" /* line 610 */
        "movl scrCompileGlob, %eax\n" /* line 2718 */
        "movl %eax, -0x50(%ebp)\n" /* pos */
        "movl $0, (%esp)\n" /* line 2719 */
        "calll TempMalloc\n"
        "movl %eax, %edi\n" /* nextPos */
        /* { scope 2 */
        "leal -0x24(%ebp), %ebx\n" /* line 2883 | constValue, expr */
        "movl %esi, %ecx\n" /* block */
        "movl %ebx, %edx\n" /* expr */
        "movl -0x54(%ebp), %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf9671a_00096a75\n"
        /* } scope */
        ".Lf9671a_000969c2:\n"
        "xorl %ecx, %ecx\n" /* line 1239 */
        "xorl %edx, %edx\n"
        "movl $0x5b, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1240 */
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, (%esp)\n" /* line 2722 */
        "calll TempMalloc\n"
        "subl %edi, %eax\n" /* line 2724 | nextPos */
        "movl -0x50(%ebp), %edx\n" /* pos */
        "movw %ax, (%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf9671a_00096778\n"
        /* } scope */
        /* { scope 1: constValue, constValue */
        ".Lf9671a_000969fe:\n"
        "movl $str_0021d8e8, 4(%esp)\n" /* line 1220 */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9671a_00096829\n"
        /* } scope */
        /* { scope 1: constValue, constValue */
        /* { scope 2 */
        ".Lf9671a_00096a16:\n"
        "movl %ebx, %eax\n" /* line 2885 | expr */
        "calll EmitValue\n"
        "jmp .Lf9671a_00096894\n"
        /* } scope */
        /* } scope */
        /* { scope 1: constValue, constValue */
        /* { scope 2 */
        ".Lf9671a_00096a22:\n"
        "movl %ebx, %eax\n" /* expr */
        "calll EmitValue\n"
        "jmp .Lf9671a_0009695b\n"
        /* } scope */
        /* } scope */
        /* { scope 1: constValue, constValue */
        /* { scope 2 */
        ".Lf9671a_00096a2e:\n"
        "movl %ebx, %eax\n" /* expr */
        "calll EmitValue\n"
        "jmp .Lf9671a_000968f8\n"
        /* } scope */
        /* } scope */
        /* { scope 1: constValue, constValue */
        /* { scope 2 */
        ".Lf9671a_00096a3a:\n"
        "leal -0x3c(%ebp), %ebx\n" /* line 2883 | constValue, expr */
        "movl %esi, %ecx\n" /* block */
        "movl %ebx, %edx\n" /* expr */
        "movl -0x54(%ebp), %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf9671a_00096840\n"
        "movl %ebx, %eax\n" /* line 2885 | expr */
        "calll EmitValue\n"
        "jmp .Lf9671a_00096840\n"
        /* } scope */
        /* } scope */
        /* { scope 1: constValue, constValue */
        ".Lf9671a_00096a5d:\n"
        "movl %edi, %eax\n" /* constValue */
        "calll EmitValue\n"
        "jmp .Lf9671a_000967a2\n"
        /* } scope */
        /* { scope 1: constValue, constValue */
        ".Lf9671a_00096a69:\n"
        "movl %edi, %eax\n" /* constValue */
        "calll EmitValue\n"
        "jmp .Lf9671a_0009674f\n"
        /* } scope */
        /* { scope 1: constValue, constValue */
        /* { scope 2 */
        ".Lf9671a_00096a75:\n"
        "movl %ebx, %eax\n" /* expr */
        "calll EmitValue\n"
        "jmp .Lf9671a_000969c2\n"
        /* } scope */
        /* } scope */
        /* { scope 1: constValue, constValue */
        ".Lf9671a_00096a81:\n"
        "subl $1, scrCompilePub\n" /* line 1233 */
        "movl %ebx, 8(%esp)\n" /* line 2792 */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "movl %edx, 4(%esp)\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_EvalBinaryOperator\n"
        "movl imp_scrVarPub, %eax\n" /* line 2793 */
        "movl 0x10(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf9671a_00096acb\n"
        "movl %eax, 8(%esp)\n" /* line 2795 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CompileError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "movzbl %al, %eax\n" /* line 2862 */
        "jmp .Lf9671a_00096778\n"
        /* { scope 1: constValue, constValue */
        ".Lf9671a_00096acb:\n"
        "movl -0x24(%ebp), %eax\n" /* line 2799 | constValue */
        "movl -0x20(%ebp), %edx\n"
        "movl %eax, (%edi)\n" /* nextPos */
        "movl %edx, 4(%edi)\n" /* nextPos */
        "movl -0x5c(%ebp), %eax\n" /* line 2800 */
        "movl %eax, 8(%edi)\n" /* nextPos */
        "movl $1, %eax\n"
        /* } scope */
        "movzbl %al, %eax\n" /* line 2862 */
        "jmp .Lf9671a_00096778\n"
    );
}

/* line 1952 */
static __attribute__((naked))
unsigned int EmitPostFunctionCall(scr_block_t *block)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1952 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %edx, %ebx\n" /* param_count */
        "movl (%eax), %edx\n" /* line 1954 | func_name */
        "cmpl $0x1a, %edx\n"
        "je .Lf96aea_00096b0d\n"
        "cmpl $0x1e, %edx\n"
        "je .Lf96aea_00096b89\n"
        ".Lf96aea_00096b05:\n"
        "addl $0x4c, %esp\n" /* line 1964 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf96aea_00096b0d:\n"
        "movl 8(%eax), %edi\n" /* line 1957 | func_name */
        "movl 4(%eax), %eax\n" /* func_name */
        /* { scope 1: bMethod, bMethod */
        "movl (%eax), %edx\n" /* line 1915 */
        "cmpl $0x12, %edx\n"
        "je .Lf96aea_00096c10\n"
        "cmpl $0x16, %edx\n"
        "jne .Lf96aea_00096b05\n"
        "movl 8(%eax), %edx\n" /* line 1922 */
        "movl %edx, -0x38(%ebp)\n"
        "movl 4(%eax), %esi\n"
        "movb %cl, -0x31(%ebp)\n" /* bMethod */
        /* { scope 2: constValue */
        /* { scope 3 */
        "movl 8(%ebp), %ecx\n" /* line 2883 | block */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "movl %esi, %eax\n" /* func_name */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n" /* func_name */
        "jne .Lf96aea_00096c8e\n"
        /* } scope */
        ".Lf96aea_00096b44:\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 1880 | bMethod */
        "jne .Lf96aea_00096c5d\n"
        "notl %ebx\n" /* line 1881 */
        "movl $3, %ecx\n"
        "movl %ebx, %edx\n"
        "movl $0x51, %eax\n"
        "calll EmitOpcode\n"
        ".Lf96aea_00096b61:\n"
        "movl $0, 4(%esp)\n" /* line 1884 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $1, 4(%esp)\n" /* line 1885 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf96aea_00096b05\n"
        /* } scope */
        /* } scope */
        ".Lf96aea_00096b89:\n"
        "movl 0xc(%eax), %edx\n" /* line 1961 | func_name */
        "movl %edx, -0x3c(%ebp)\n"
        "movl 8(%eax), %edi\n" /* func_name */
        "movl 4(%eax), %eax\n" /* func_name */
        /* { scope 1: bMethod, bMethod */
        "movl (%eax), %edx\n" /* line 1930 */
        "cmpl $0x12, %edx\n"
        "je .Lf96aea_00096bbd\n"
        "cmpl $0x16, %edx\n"
        "je .Lf96aea_00096c9b\n"
        ".Lf96aea_00096ba5:\n"
        "movl $0, 4(%esp)\n" /* line 1941 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1964 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: bMethod, bMethod */
        ".Lf96aea_00096bbd:\n"
        "movl 4(%eax), %esi\n" /* line 1933 */
        "testb %cl, %cl\n" /* line 1891 */
        "jne .Lf96aea_00096c76\n"
        "movl $1, %edx\n" /* line 1892 */
        "subl %ebx, %edx\n"
        "movl $2, %ecx\n"
        "movl $0x54, %eax\n"
        "calll EmitOpcode\n"
        ".Lf96aea_00096bde:\n"
        "movl $3, 4(%esp)\n" /* line 1895 */
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl -0x3c(%ebp), %edx\n" /* line 1896 */
        "movl %esi, %eax\n"
        "calll EmitFunction\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %ebx, (%eax)\n" /* line 596 */
        "jmp .Lf96aea_00096ba5\n"
        /* } scope */
        /* { scope 1: bMethod, bMethod */
        ".Lf96aea_00096c10:\n"
        "movl 4(%eax), %esi\n" /* line 1918 */
        "testb %cl, %cl\n" /* line 1868 */
        "jne .Lf96aea_00096c48\n"
        "negl %ebx\n" /* line 1869 */
        "movl $3, %ecx\n"
        "movl %ebx, %edx\n"
        "movl $0x50, %eax\n"
        "calll EmitOpcode\n"
        ".Lf96aea_00096c2a:\n"
        "movl $3, 4(%esp)\n" /* line 1872 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl %edi, %edx\n" /* line 1873 */
        "movl %esi, %eax\n"
        "calll EmitFunction\n"
        "jmp .Lf96aea_00096b05\n"
        ".Lf96aea_00096c48:\n"
        "notl %ebx\n" /* line 1871 */
        "movl $3, %ecx\n"
        "movl %ebx, %edx\n"
        "movl $0x52, %eax\n"
        "calll EmitOpcode\n"
        "jmp .Lf96aea_00096c2a\n"
        /* { scope 2: constValue */
        ".Lf96aea_00096c5d:\n"
        "negl %ebx\n" /* line 1883 */
        "leal -2(%ebx), %edx\n"
        "movl $3, %ecx\n"
        "movl $0x53, %eax\n"
        "calll EmitOpcode\n"
        "jmp .Lf96aea_00096b61\n"
        /* } scope */
        /* } scope */
        /* { scope 1: bMethod, bMethod */
        ".Lf96aea_00096c76:\n"
        "movl %ebx, %edx\n" /* line 1894 */
        "negl %edx\n"
        "movl $2, %ecx\n"
        "movl $0x56, %eax\n"
        "calll EmitOpcode\n"
        "jmp .Lf96aea_00096bde\n"
        /* } scope */
        /* { scope 1: bMethod, bMethod */
        /* { scope 2: constValue */
        /* { scope 3 */
        ".Lf96aea_00096c8e:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2885 | constValue, func_name */
        "calll EmitValue\n"
        "jmp .Lf96aea_00096b44\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: bMethod, bMethod */
        ".Lf96aea_00096c9b:\n"
        "movl 8(%eax), %edx\n" /* line 1937 */
        "movl %edx, -0x30(%ebp)\n"
        "movl 4(%eax), %esi\n"
        "movb %cl, -0x29(%ebp)\n" /* bMethod */
        /* { scope 2: constValue */
        /* { scope 3 */
        "movl 8(%ebp), %ecx\n" /* line 2883 | block */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "movl %esi, %eax\n" /* func_name */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n" /* func_name */
        "jne .Lf96aea_00096d11\n"
        /* } scope */
        ".Lf96aea_00096cb8:\n"
        "cmpb $0, -0x29(%ebp)\n" /* line 1904 | bMethod */
        "jne .Lf96aea_00096cfc\n"
        "movl %ebx, %edx\n" /* line 1905 */
        "negl %edx\n"
        "movl $2, %ecx\n"
        "movl $0x55, %eax\n"
        "calll EmitOpcode\n"
        ".Lf96aea_00096cd1:\n"
        "movl $1, 4(%esp)\n" /* line 1908 */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %ebx, (%eax)\n" /* line 596 */
        "jmp .Lf96aea_00096ba5\n"
        ".Lf96aea_00096cfc:\n"
        "movl %ebx, %edx\n" /* line 1907 */
        "notl %edx\n"
        "movl $2, %ecx\n"
        "movl $0x57, %eax\n"
        "calll EmitOpcode\n"
        "jmp .Lf96aea_00096cd1\n"
        /* { scope 3 */
        ".Lf96aea_00096d11:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2885 | constValue, func_name */
        "calll EmitValue\n"
        "jmp .Lf96aea_00096cb8\n"
    );
}

/* line 2191 */
static __attribute__((naked))
unsigned int EmitMethod(sval_t expr, sval_t func_name, sval_t params, sval_t methodSourcePos, int bStatement, scr_block_t *block)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2191 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl %edx, -0x50(%ebp)\n"
        "movl %ecx, -0x54(%ebp)\n"
        "movl 0x10(%ebp), %edi\n" /* block */
        "movzbl 0xc(%ebp), %eax\n" /* bStatement */
        "movb %al, -0x55(%ebp)\n" /* bStatement */
        /* { scope 1: constValue */
        "cmpl $0x1a, (%edx)\n" /* line 1969 */
        "je .Lf96d1c_00096e3a\n"
        "movl %edx, %eax\n"
        "cmpl $0x1a, (%eax)\n" /* line 1947 */
        "je .Lf96d1c_00096e4e\n"
        /* { scope 2: constValue */
        ".Lf96d1c_00096d4c:\n"
        "movl -0x54(%ebp), %edx\n" /* line 1624 */
        "movl (%edx), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf96d1c_00096e16\n"
        "xorl %esi, %esi\n"
        "jmp .Lf96d1c_00096d67\n"
        ".Lf96d1c_00096d5d:\n"
        "addl $1, %esi\n" /* line 1627 */
        "movl 4(%ebx), %ebx\n" /* line 1624 | node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf96d1c_00096d8b\n"
        ".Lf96d1c_00096d67:\n"
        "movl (%ebx), %eax\n" /* line 1626 | node */
        "movl (%eax), %eax\n"
        /* { scope 3 */
        "movl %edi, %ecx\n" /* line 2883 | block */
        "leal -0x34(%ebp), %edx\n" /* constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf96d1c_00096d5d\n"
        "leal -0x34(%ebp), %eax\n" /* line 2885 | constValue */
        "calll EmitValue\n"
        /* } scope */
        "addl $1, %esi\n" /* line 1627 */
        "movl 4(%ebx), %ebx\n" /* line 1624 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf96d1c_00096d67\n"
        /* } scope */
        /* { scope 2: constValue */
        ".Lf96d1c_00096d8b:\n"
        "movl %edi, %ecx\n" /* line 2702 | block */
        "leal -0x34(%ebp), %edx\n" /* constValue */
        "movl -0x4c(%ebp), %eax\n"
        "calll EmitOrEvalPrimitiveExpression\n"
        "testb %al, %al\n"
        "jne .Lf96d1c_00096e2d\n"
        /* } scope */
        ".Lf96d1c_00096da0:\n"
        "movl %edi, (%esp)\n" /* line 2291 | block */
        "movl $1, %ecx\n"
        "movl %esi, %edx\n" /* param_count */
        "movl -0x50(%ebp), %eax\n"
        "calll EmitPostFunctionCall\n"
        "movl $0, 4(%esp)\n" /* line 2292 */
        "movl 8(%ebp), %eax\n" /* methodSourcePos */
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        /* { scope 2: constValue */
        "movl imp_scrVarPub, %eax\n" /* line 1651 */
        "cmpb $0, 0xa(%eax)\n"
        "jne .Lf96d1c_00096def\n"
        /* } scope */
        ".Lf96d1c_00096dd0:\n"
        "cmpb $0, -0x55(%ebp)\n" /* line 2295 | bStatement */
        "je .Lf96d1c_00096de7\n"
        "xorl %ecx, %ecx\n" /* line 1535 */
        "movl $0xffffffff, %edx\n"
        "movl $0x58, %eax\n"
        "calll EmitOpcode\n"
        /* } scope */
        ".Lf96d1c_00096de7:\n"
        "addl $0x5c, %esp\n" /* line 2297 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: constValue */
        /* { scope 2: constValue */
        ".Lf96d1c_00096def:\n"
        "movl -0x54(%ebp), %edx\n" /* line 1654 */
        "movl (%edx), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf96d1c_00096dd0\n"
        ".Lf96d1c_00096df8:\n"
        "movl $0, 4(%esp)\n" /* line 1655 */
        "movl (%ebx), %eax\n" /* node */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl 4(%ebx), %ebx\n" /* line 1654 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf96d1c_00096df8\n"
        "jmp .Lf96d1c_00096dd0\n"
        /* } scope */
        /* { scope 2: constValue */
        ".Lf96d1c_00096e16:\n"
        "xorl %esi, %esi\n" /* line 1624 */
        /* } scope */
        /* { scope 2: constValue */
        "movl %edi, %ecx\n" /* line 2702 | block */
        "leal -0x34(%ebp), %edx\n" /* constValue */
        "movl -0x4c(%ebp), %eax\n"
        "calll EmitOrEvalPrimitiveExpression\n"
        "testb %al, %al\n"
        "je .Lf96d1c_00096da0\n"
        ".Lf96d1c_00096e2d:\n"
        "leal -0x34(%ebp), %eax\n" /* line 2704 | constValue */
        "calll EmitValue\n"
        "jmp .Lf96d1c_00096da0\n"
        /* } scope */
        ".Lf96d1c_00096e3a:\n"
        "movl 4(%edx), %ebx\n" /* line 1971 | i */
        "cmpl $0x12, (%ebx)\n" /* line 1972 | i */
        "je .Lf96d1c_00096e64\n"
        ".Lf96d1c_00096e42:\n"
        "movl -0x50(%ebp), %eax\n"
        "cmpl $0x1a, (%eax)\n" /* line 1947 */
        "jne .Lf96d1c_00096d4c\n"
        ".Lf96d1c_00096e4e:\n"
        "xorl %ecx, %ecx\n" /* line 1948 */
        "movl $1, %edx\n"
        "movl $0x4e, %eax\n"
        "calll EmitOpcode\n"
        "jmp .Lf96d1c_00096d4c\n"
        ".Lf96d1c_00096e64:\n"
        "movl 4(%ebx), %ebx\n" /* line 1974 | i */
        "cmpl $0x14, (%ebx)\n" /* line 1975 | i */
        "jne .Lf96d1c_00096e42\n"
        "movl 4(%ebx), %eax\n" /* line 1981 | i */
        "movl %eax, 4(%esp)\n"
        "movl scrCompileGlob+8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf96d1c_00096e42\n"
        "movl 4(%ebx), %ebx\n" /* line 1984 | i */
        "movl %ebx, -0x44(%ebp)\n" /* i, name */
        "testl %ebx, %ebx\n" /* line 2204 | opcode */
        "je .Lf96d1c_00096e42\n"
        "movl %ebx, (%esp)\n" /* line 2206 | opcode */
        "calll SL_ConvertToString\n"
        "movl %eax, -0x20(%ebp)\n" /* pName */
        "movl -0x50(%ebp), %eax\n" /* line 2207 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* sourcePos */
        "movl -0x44(%ebp), %edx\n" /* line 2214 | name */
        "movl %edx, 4(%esp)\n"
        "movl scrCompilePub+20, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 2215 */
        "je .Lf96d1c_0009706a\n"
        "movl %eax, (%esp)\n" /* line 2217 */
        "calll Scr_EvalVariable\n"
        "movl %eax, -0x28(%ebp)\n" /* value */
        "movl %edx, -0x24(%ebp)\n"
        "xorl %eax, %eax\n" /* line 2038 */
        "cmpl $7, -0x24(%ebp)\n"
        "setne %al\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 2218 | type */
        "movl -0x28(%ebp), %eax\n" /* line 2219 | value */
        "movl %eax, -0x40(%ebp)\n" /* meth */
        ".Lf96d1c_00096ede:\n"
        "movl -0x40(%ebp), %eax\n" /* line 2239 | meth */
        "testl %eax, %eax\n"
        "je .Lf96d1c_00096e42\n"
        "cmpl $1, -0x1c(%ebp)\n" /* line 2242 | type */
        "je .Lf96d1c_000970db\n"
        /* { scope 2: constValue */
        ".Lf96d1c_00096ef3:\n"
        "movl -0x54(%ebp), %edx\n" /* line 1624 */
        "movl (%edx), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf96d1c_00096f26\n"
        "xorl %esi, %esi\n"
        "jmp .Lf96d1c_00096f0a\n"
        ".Lf96d1c_00096f00:\n"
        "addl $1, %esi\n" /* line 1627 */
        "movl 4(%ebx), %ebx\n" /* line 1624 | node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf96d1c_00096f28\n"
        ".Lf96d1c_00096f0a:\n"
        "movl (%ebx), %eax\n" /* line 1626 | node */
        "movl (%eax), %eax\n"
        /* { scope 3 */
        "movl %edi, %ecx\n" /* line 2883 | block */
        "leal -0x34(%ebp), %edx\n" /* constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf96d1c_00096f00\n"
        "leal -0x34(%ebp), %eax\n" /* line 2885 | constValue */
        "calll EmitValue\n"
        "jmp .Lf96d1c_00096f00\n"
        /* } scope */
        ".Lf96d1c_00096f26:\n"
        "xorl %esi, %esi\n" /* line 1624 */
        /* } scope */
        /* { scope 2: constValue */
        ".Lf96d1c_00096f28:\n"
        "movl %edi, %ecx\n" /* line 2702 | block */
        "leal -0x34(%ebp), %edx\n" /* constValue */
        "movl -0x4c(%ebp), %eax\n"
        "calll EmitOrEvalPrimitiveExpression\n"
        "testb %al, %al\n"
        "je .Lf96d1c_00096f41\n"
        "leal -0x34(%ebp), %eax\n" /* line 2704 | constValue */
        "calll EmitValue\n"
        /* } scope */
        ".Lf96d1c_00096f41:\n"
        "cmpl $0xff, %esi\n" /* line 2255 | param_count */
        "jg .Lf96d1c_000970c3\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf96d1c_00096f61\n"
        "movl -0x44(%ebp), %edx\n" /* line 206 | name */
        "movl %edx, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        /* { scope 2: constValue */
        ".Lf96d1c_00096f61:\n"
        "cmpl $5, %esi\n" /* line 2073 */
        "jle .Lf96d1c_00097151\n"
        "movl $0x4b, %ebx\n" /* opcode */
        ".Lf96d1c_00096f6f:\n"
        "movl %esi, %edx\n" /* line 2078 */
        "negl %edx\n"
        "movl $1, %ecx\n"
        "movl %ebx, %eax\n" /* opcode */
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 2082 */
        "movl -0x48(%ebp), %eax\n" /* sourcePos */
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "cmpl $0x4b, %ebx\n" /* line 2084 | opcode */
        "je .Lf96d1c_00097159\n"
        /* } scope */
        /* { scope 2: constValue */
        ".Lf96d1c_00096f9b:\n"
        "movl scrCompilePub+52, %edx\n" /* line 1844 */
        "testl %edx, %edx\n"
        "jg .Lf96d1c_0009711c\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf96d1c_00096fab:\n"
        "cmpl $0x400, %edx\n" /* line 1851 */
        "je .Lf96d1c_00097173\n"
        ".Lf96d1c_00096fb7:\n"
        "movl -0x40(%ebp), %eax\n" /* line 1854 | meth */
        "movl %eax, scrCompilePub+56(, %edx, 4)\n"
        "leal 1(%edx), %eax\n" /* line 1860 */
        "movl %eax, scrCompilePub+52\n"
        /* } scope */
        ".Lf96d1c_00096fc9:\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw %bx, (%eax)\n" /* line 610 */
        "movl $0, 4(%esp)\n" /* line 2265 */
        "movl 8(%ebp), %edx\n" /* methodSourcePos */
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        /* { scope 2: constValue */
        "movl imp_scrVarPub, %eax\n" /* line 1651 */
        "cmpb $0, 0xa(%eax)\n"
        "je .Lf96d1c_00097020\n"
        "movl -0x54(%ebp), %eax\n" /* line 1654 */
        "movl (%eax), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf96d1c_00097020\n"
        ".Lf96d1c_00097004:\n"
        "movl $0, 4(%esp)\n" /* line 1655 */
        "movl (%ebx), %eax\n" /* node */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl 4(%ebx), %ebx\n" /* line 1654 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf96d1c_00097004\n"
        /* } scope */
        ".Lf96d1c_00097020:\n"
        "cmpb $0, -0x55(%ebp)\n" /* line 2268 | bStatement */
        "je .Lf96d1c_00097037\n"
        "xorl %ecx, %ecx\n" /* line 1535 */
        "movl $0xffffffff, %edx\n"
        "movl $0x58, %eax\n"
        "calll EmitOpcode\n"
        ".Lf96d1c_00097037:\n"
        "cmpl $1, -0x1c(%ebp)\n" /* line 2012 | type */
        "jne .Lf96d1c_00096de7\n"
        "movl $0, scrCompilePub+40\n" /* line 2015 */
        "movl imp_scrVarPub, %eax\n" /* line 2017 */
        "cmpb $0, 0xb(%eax)\n"
        "jne .Lf96d1c_00096de7\n"
        "movl -0x3c(%ebp), %edx\n" /* line 2018 | savedPos */
        "movl %edx, (%esp)\n"
        "calll TempMemorySetPos\n"
        "jmp .Lf96d1c_00096de7\n"
        ".Lf96d1c_0009706a:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 2223 | type */
        "leal -0x1c(%ebp), %eax\n" /* line 2224 | type */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* pName */
        "movl %eax, (%esp)\n"
        "calll Scr_GetMethod\n"
        "movl %eax, -0x40(%ebp)\n" /* meth */
        "movl -0x44(%ebp), %edx\n" /* line 2225 | name */
        "movl %edx, 4(%esp)\n"
        "movl scrCompilePub+20, %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetNewVariable\n"
        "cmpl $1, -0x1c(%ebp)\n" /* line 2024 | type */
        "sbbl %edx, %edx\n"
        "andl $0xfffffffb, %edx\n"
        "addl $0xc, %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* line 2226 */
        "movl -0x40(%ebp), %edx\n" /* line 2227 | meth */
        "movl %edx, -0x28(%ebp)\n" /* value */
        "leal -0x28(%ebp), %edx\n" /* line 2228 | value */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        "jmp .Lf96d1c_00096ede\n"
        ".Lf96d1c_000970c3:\n"
        "movl $str_0021d8ac, 4(%esp)\n" /* line 2257 */
        "movl -0x48(%ebp), %eax\n" /* sourcePos */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf96d1c_00096de7\n"
        ".Lf96d1c_000970db:\n"
        "movl scrCompilePub+40, %esi\n" /* line 1990 */
        "testl %esi, %esi\n"
        "je .Lf96d1c_00097192\n"
        "movl $0, -0x1c(%ebp)\n" /* line 1992 | type */
        ".Lf96d1c_000970f0:\n"
        "cmpl $1, -0x1c(%ebp)\n" /* line 2245 | type */
        "jne .Lf96d1c_00096ef3\n"
        "cmpb $0, -0x55(%ebp)\n" /* bStatement */
        "jne .Lf96d1c_00096ef3\n"
        "movl $str_0021d858, 4(%esp)\n" /* line 2247 */
        "movl -0x48(%ebp), %eax\n" /* sourcePos */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf96d1c_00096de7\n"
        /* { scope 2: constValue */
        ".Lf96d1c_0009711c:\n"
        "movl -0x40(%ebp), %eax\n" /* line 1846 | meth */
        "cmpl scrCompilePub+56, %eax\n"
        "je .Lf96d1c_000971b3\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl $scrCompilePub, %ecx\n"
        "jmp .Lf96d1c_00097143\n"
        ".Lf96d1c_00097134:\n"
        "movl 0x3c(%ecx), %eax\n"
        "addl $4, %ecx\n"
        "cmpl %eax, -0x40(%ebp)\n" /* meth */
        "je .Lf96d1c_00096fc9\n"
        ".Lf96d1c_00097143:\n"
        "addl $1, %ebx\n" /* line 1844 | i */
        "cmpl %edx, %ebx\n" /* i */
        "jne .Lf96d1c_00097134\n"
        "movl %edx, %ebx\n" /* i */
        "jmp .Lf96d1c_00096fab\n"
        /* } scope */
        /* { scope 2: constValue */
        ".Lf96d1c_00097151:\n"
        "leal 0x45(%esi), %ebx\n" /* line 2074 | opcode */
        "jmp .Lf96d1c_00096f6f\n"
        ".Lf96d1c_00097159:\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movl %esi, %edx\n" /* line 617 */
        "movb %dl, (%eax)\n"
        "jmp .Lf96d1c_00096f9b\n"
        /* } scope */
        /* { scope 2: constValue */
        ".Lf96d1c_00097173:\n"
        "movl $str_0021d8c8, 4(%esp)\n" /* line 1852 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompilePub+52, %edx\n"
        "jmp .Lf96d1c_00096fb7\n"
        /* } scope */
        ".Lf96d1c_00097192:\n"
        "movl imp_scrVarPub, %eax\n" /* line 1996 */
        "cmpb $0, 0xb(%eax)\n"
        "je .Lf96d1c_000971ba\n"
        "movl $1, scrCompilePub+40\n" /* line 2003 */
        ".Lf96d1c_000971a7:\n"
        "movl $1, -0x1c(%ebp)\n" /* line 2006 | type */
        "jmp .Lf96d1c_000970f0\n"
        /* { scope 2: constValue */
        ".Lf96d1c_000971b3:\n"
        "xorl %ebx, %ebx\n" /* line 1846 | i */
        "jmp .Lf96d1c_00096fc9\n"
        /* } scope */
        ".Lf96d1c_000971ba:\n"
        "movl $0, (%esp)\n" /* line 1998 */
        "calll TempMalloc\n"
        "movl %eax, -0x3c(%ebp)\n" /* savedPos */
        "movl $2, scrCompilePub+40\n" /* line 1999 */
        "jmp .Lf96d1c_000971a7\n"
    );
}

/* line 2958 */
static __attribute__((naked))
unsigned int EmitPrimitiveExpressionFieldObject(void)
{
    __asm__ __volatile__ (
        ".Lf971d6_000971d6:\n"
        "pushl %ebp\n" /* line 2958 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %ebx\n" /* expr */
        "movl (%eax), %eax\n" /* line 2960 */
        "subl $0x11, %eax\n"
        "cmpl $0x1d, %eax\n"
        "ja .Lf971d6_00097206\n"
        "jmpl *CorrectSolidDeltas+4808(, %eax, 4)\n"
        "movl 4(%ebx), %esi\n" /* line 2963 | expr */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 1638 */
        "testl %eax, %eax\n" /* line 1639 */
        "je .Lf971d6_00097206\n"
        "movl 4(%eax), %ebx\n" /* line 1641 */
        "testl %ebx, %ebx\n"
        "je .Lf971d6_000972fb\n"
        /* } scope */
        ".Lf971d6_00097206:\n"
        "movl $str_0021d954, 4(%esp)\n" /* line 2988 */
        "movl %edx, (%esp)\n" /* sourcePos */
        "calll CompileError\n"
        ".Lf971d6_00097216:\n"
        "addl $0x1c, %esp\n" /* line 2991 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 4(%ebx), %esi\n" /* line 2971 | expr */
        "movl %ecx, %edx\n" /* block, sourcePos */
        "movl %esi, %eax\n"
        "calll EmitVariableExpression\n"
        "movl 8(%ebx), %ebx\n" /* line 2972 | expr */
        ".Lf971d6_0009722d:\n"
        "xorl %ecx, %ecx\n" /* line 1541 */
        "movl $0xffffffff, %edx\n"
        "movl $0x59, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1545 */
        "movl %ebx, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf971d6_00097216\n"
        "movl 4(%ebx), %esi\n" /* line 2984 | expr */
        "xorl %ecx, %ecx\n" /* line 1316 */
        "xorl %edx, %edx\n"
        "movl $0xe, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 1320 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf971d6_00097216\n"
        "movl 4(%ebx), %esi\n" /* line 2980 | expr */
        "xorl %ecx, %ecx\n" /* line 1306 */
        "xorl %edx, %edx\n"
        "movl $0xd, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 1310 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf971d6_00097216\n"
        "movl 4(%ebx), %esi\n" /* line 2976 | expr */
        "xorl %ecx, %ecx\n" /* line 1296 */
        "xorl %edx, %edx\n"
        "movl $0x26, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 1300 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf971d6_00097216\n"
        "movl 4(%ebx), %esi\n" /* line 2967 | expr */
        "movl (%esi), %eax\n" /* line 2444 */
        "cmpl $0x17, %eax\n"
        "je .Lf971d6_0009731d\n"
        "cmpl $0x18, %eax\n"
        "jne .Lf971d6_00097216\n"
        "movl 0x10(%esi), %eax\n" /* line 2452 */
        "movl 0xc(%esi), %edi\n"
        "movl 8(%esi), %edx\n"
        "movl 4(%esi), %ebx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl %edi, %ecx\n"
        "movl %ebx, %eax\n"
        "calll EmitMethod\n"
        "movl 0x14(%esi), %ebx\n" /* line 2453 */
        "jmp .Lf971d6_0009722d\n"
        /* { scope 1 */
        ".Lf971d6_000972fb:\n"
        "movl (%eax), %eax\n" /* line 2586 */
        "movl 4(%eax), %edx\n"
        "movl (%eax), %eax\n"
        "cmpl $6, (%eax)\n" /* line 2996 */
        "jne .Lf971d6_00097206\n"
        "movl 8(%eax), %edx\n" /* line 2999 | sourcePos */
        "movl 4(%eax), %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2991 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp EmitPrimitiveExpressionFieldObject\n" /* line 2999 */
        /* } scope */
        ".Lf971d6_0009731d:\n"
        "movl 8(%esi), %edx\n" /* line 2447 */
        "movl 4(%esi), %ebx\n"
        "movl %ecx, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %eax\n"
        "calll EmitCall\n"
        "movl 0xc(%esi), %edi\n" /* line 2448 */
        "xorl %ecx, %ecx\n" /* line 1541 */
        "movl $0xffffffff, %edx\n"
        "movl $0x59, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1545 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf971d6_00097216\n"
    );
}

/* line 1579 */
static __attribute__((naked))
unsigned int EmitVariableExpression(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1579 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ecx\n" /* expr */
        "movl %edx, %esi\n" /* block */
        "movl (%eax), %eax\n" /* line 1581 */
        "cmpl $0xf, %eax\n"
        "je .Lf97358_0009740b\n"
        "jle .Lf97358_0009738c\n"
        "cmpl $0x35, %eax\n"
        "je .Lf97358_00097511\n"
        "cmpl $0x4f, %eax\n"
        "je .Lf97358_0009748a\n"
        ".Lf97358_00097384:\n"
        "addl $0x3c, %esp\n" /* line 1603 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf97358_0009738c:\n"
        "cmpl $4, %eax\n" /* line 1581 */
        "je .Lf97358_0009753c\n"
        "cmpl $0xd, %eax\n"
        "jne .Lf97358_00097384\n"
        "movl 0x10(%ecx), %edx\n" /* line 1588 | expr */
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0xc(%ecx), %edi\n" /* expr, value */
        "movl 8(%ecx), %eax\n" /* expr */
        "movl %eax, -0x30(%ebp)\n"
        "movl 4(%ecx), %ebx\n" /* expr, s */
        /* { scope 1 */
        "movl %esi, %ecx\n" /* line 2883 | block, expr */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf97358_000975d1\n"
        /* } scope */
        /* { scope 1 */
        ".Lf97358_000973be:\n"
        "movl %esi, %ecx\n" /* line 2702 | block, expr */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "movl %ebx, %eax\n" /* s */
        "calll EmitOrEvalPrimitiveExpression\n"
        "testb %al, %al\n"
        "jne .Lf97358_000975c4\n"
        /* } scope */
        ".Lf97358_000973d2:\n"
        "xorl %ecx, %ecx\n" /* line 1397 */
        "movl $0xffffffff, %edx\n"
        "movl $0x20, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1398 */
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $1, 4(%esp)\n" /* line 1399 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf97358_00097384\n"
        ".Lf97358_0009740b:\n"
        "movl 0xc(%ecx), %edi\n" /* line 1592 | expr, value */
        "movl 8(%ecx), %eax\n" /* expr */
        "movl %eax, -0x30(%ebp)\n"
        "movl 4(%ecx), %ebx\n" /* expr, s */
        "movl %edx, %ecx\n" /* line 1444 */
        "movl %edi, %edx\n"
        "movl %ebx, %eax\n" /* opcode */
        "calll EmitPrimitiveExpressionFieldObject\n"
        "xorl %ecx, %ecx\n" /* line 1445 */
        "movl $1, %edx\n"
        "movl $0x2a, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1446 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 214 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "cmpl $2, scrCompilePub+40\n" /* line 216 */
        "je .Lf97358_0009758d\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 233 */
        "jne .Lf97358_00097501\n"
        ".Lf97358_0009746e:\n"
        "movl scrCompileGlob, %ebx\n" /* line 236 */
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll SL_TransferToCanonicalString\n"
        "movw %ax, (%ebx)\n"
        "addl $0x3c, %esp\n" /* line 1603 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf97358_0009748a:\n"
        "movl 8(%ecx), %eax\n" /* line 1596 | expr */
        "movl %eax, -0x30(%ebp)\n"
        "movl 4(%ecx), %ebx\n" /* expr, s */
        /* { scope 1 */
        "cmpb $0, scrCompilePub+36\n" /* line 1479 */
        "jne .Lf97358_000975af\n"
        "movl %ebx, (%esp)\n" /* line 1485 | s */
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n" /* s */
        "movzbl (%eax), %eax\n" /* line 1487 */
        "cmpb $0x74, %al\n"
        "je .Lf97358_00097634\n"
        "movsbl %al, %eax\n" /* line 1513 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetClassnumForCharId\n"
        "movl %eax, %esi\n" /* index */
        "testl %eax, %eax\n" /* line 1514 */
        "js .Lf97358_000976b1\n"
        "leal 1(%ebx), %eax\n" /* line 1520 | s */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 1521 */
        "jne .Lf97358_000975f8\n"
        "cmpb $0x30, 1(%ebx)\n" /* s */
        "je .Lf97358_000975f8\n"
        ".Lf97358_000974e9:\n"
        "movl $str_0021d990, 4(%esp)\n" /* line 1523 */
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf97358_00097384\n"
        /* } scope */
        ".Lf97358_00097501:\n"
        "movl -0x30(%ebp), %eax\n" /* line 234 */
        "movl %eax, (%esp)\n"
        "calll SL_AddRefToString\n"
        "jmp .Lf97358_0009746e\n"
        ".Lf97358_00097511:\n"
        "movl $str_0021d9a0, %eax\n" /* line 1600 */
        "cmpb $0, scrCompilePub+36\n"
        "movl $str_0021d9dc, %edx\n" /* "self field can only be used in the script debugger" */
        "cmovnel %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ecx), %eax\n" /* expr */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "addl $0x3c, %esp\n" /* line 1603 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf97358_0009753c:\n"
        "movl 8(%ecx), %eax\n" /* line 1584 | expr */
        "movl %eax, -0x30(%ebp)\n"
        "movl 4(%ecx), %ebx\n" /* expr, s */
        /* { scope 1 */
        "movl %edx, (%esp)\n" /* line 1340 */
        "xorl %ecx, %ecx\n"
        "movl %eax, %edx\n"
        "movl %ebx, %eax\n" /* opcode */
        "calll Scr_FindLocalVarIndex\n"
        "movl %eax, %esi\n" /* index */
        "cmpl $5, %eax\n" /* line 1341 */
        "jle .Lf97358_000975aa\n"
        "movl $0x1e, %ebx\n" /* opcode */
        ".Lf97358_0009755f:\n"
        "xorl %ecx, %ecx\n" /* line 1346 */
        "movl $1, %edx\n"
        "movl %ebx, %eax\n" /* opcode */
        "calll EmitOpcode\n"
        "cmpl $0x1e, %ebx\n" /* line 1348 | opcode */
        "je .Lf97358_000975de\n"
        ".Lf97358_00097572:\n"
        "movl $1, 4(%esp)\n" /* line 1351 */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1603 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf97358_0009758d:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf97358_00097384\n"
        "movl -0x30(%ebp), %edx\n" /* line 206 */
        "movl %edx, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "jmp .Lf97358_00097384\n"
        /* { scope 1 */
        ".Lf97358_000975aa:\n"
        "leal 0x18(%eax), %ebx\n" /* line 1342 | opcode */
        "jmp .Lf97358_0009755f\n"
        /* } scope */
        /* { scope 1 */
        ".Lf97358_000975af:\n"
        "movl $str_0021d964, 4(%esp)\n" /* line 1481 */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf97358_00097384\n"
        /* } scope */
        /* { scope 1 */
        ".Lf97358_000975c4:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2704 | constValue */
        "calll EmitValue\n"
        "jmp .Lf97358_000973d2\n"
        /* } scope */
        /* { scope 1 */
        ".Lf97358_000975d1:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2885 | constValue */
        "calll EmitValue\n"
        "jmp .Lf97358_000973be\n"
        /* } scope */
        /* { scope 1 */
        ".Lf97358_000975de:\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movl %esi, %edx\n" /* line 617 */
        "movb %dl, (%eax)\n"
        "jmp .Lf97358_00097572\n"
        /* } scope */
        /* { scope 1 */
        ".Lf97358_000975f8:\n"
        "xorl %ecx, %ecx\n" /* line 1527 */
        "movl $1, %edx\n"
        "movl $0x81, %eax\n"
        "calll EmitOpcode\n"
        /* { scope 2 */
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %esi, (%eax)\n" /* line 596 */
        /* } scope */
        /* { scope 2 */
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %edi, (%eax)\n" /* line 596 */
        "jmp .Lf97358_00097384\n"
        /* } scope */
        ".Lf97358_00097634:\n"
        "leal 1(%ebx), %eax\n" /* line 1489 | s */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* s */
        "leal -1(%eax), %eax\n" /* line 1490 */
        "cmpl $0xfffc, %eax\n"
        "ja .Lf97358_000974e9\n"
        "movzwl %bx, %esi\n" /* line 1493 | s, index */
        "movl %esi, (%esp)\n" /* index */
        "calll IsVarFree\n"
        "testb %al, %al\n"
        "jne .Lf97358_000974e9\n"
        "movl %esi, (%esp)\n" /* line 1495 | index */
        "calll GetVarType\n"
        "movl %eax, %ecx\n"
        "cmpl $0x17, %eax\n"
        "ja .Lf97358_000974e9\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $s_debugFrameGlob+549248, %eax\n"
        "je .Lf97358_000974e9\n"
        "xorl %ecx, %ecx\n" /* line 1502 */
        "movl $1, %edx\n"
        "movl $0x82, %eax\n"
        "calll EmitOpcode\n"
        "movl $2, (%esp)\n" /* line 602 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw %bx, (%eax)\n" /* line 603 */
        "jmp .Lf97358_00097384\n"
        ".Lf97358_000976b1:\n"
        "movl $str_0021d990, 4(%esp)\n" /* line 1516 */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf97358_00097384\n"
    );
}

/* line 2889 */
static __attribute__((naked))
unsigned int EmitVariableExpressionRef(void)
{
    __asm__ __volatile__ (
        ".Lf976ca_000976ca:\n"
        "pushl %ebp\n" /* line 2889 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ecx\n" /* expr */
        "movl %edx, %esi\n" /* block */
        "movl (%eax), %eax\n" /* line 2891 */
        "cmpl $0xf, %eax\n"
        "je .Lf976ca_00097795\n"
        "jle .Lf976ca_000976fe\n"
        "cmpl $0x35, %eax\n"
        "je .Lf976ca_000977f7\n"
        "cmpl $0x4f, %eax\n"
        "je .Lf976ca_000977f7\n"
        ".Lf976ca_000976f6:\n"
        "addl $0x3c, %esp\n" /* line 2910 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf976ca_000976fe:\n"
        "cmpl $4, %eax\n" /* line 2891 */
        "je .Lf976ca_0009782c\n"
        "cmpl $0xd, %eax\n"
        "jne .Lf976ca_000976f6\n"
        "movl 0x10(%ecx), %eax\n" /* line 2898 | expr */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%ecx), %eax\n" /* expr */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%ecx), %edi\n" /* expr */
        "movl 4(%ecx), %ebx\n" /* expr, index */
        /* { scope 1 */
        "movl %edx, %ecx\n" /* line 2883 */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "movl %edi, %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf976ca_000978c7\n"
        /* } scope */
        ".Lf976ca_00097732:\n"
        "movl (%ebx), %eax\n" /* line 2930 | index */
        "cmpl $0x11, %eax\n"
        "je .Lf976ca_000978d4\n"
        "cmpl $0x23, %eax\n"
        "je .Lf976ca_0009788c\n"
        "movl $str_0021da10, 4(%esp)\n" /* line 2941 */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        ".Lf976ca_00097759:\n"
        "xorl %ecx, %ecx\n" /* line 1405 */
        "movl $0xffffffff, %edx\n"
        "movl $0x23, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1406 */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $1, 4(%esp)\n" /* line 1407 */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf976ca_000976f6\n"
        ".Lf976ca_00097795:\n"
        "movl 0xc(%ecx), %eax\n" /* line 2902 | expr */
        "movl 8(%ecx), %edi\n" /* expr */
        "movl 4(%ecx), %ebx\n" /* expr, index */
        "movl %edx, %ecx\n" /* line 1453 */
        "movl %eax, %edx\n"
        "movl %ebx, %eax\n" /* index */
        "calll EmitPrimitiveExpressionFieldObject\n"
        "xorl %ecx, %ecx\n" /* line 1454 */
        "xorl %edx, %edx\n"
        "movl $0x2e, %eax\n"
        "calll EmitOpcode\n"
        "movl $2, (%esp)\n" /* line 214 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "cmpl $2, scrCompilePub+40\n" /* line 216 */
        "je .Lf976ca_00097872\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 233 */
        "jne .Lf976ca_00097822\n"
        ".Lf976ca_000977de:\n"
        "movl scrCompileGlob, %ebx\n" /* line 236 */
        "movl %edi, (%esp)\n"
        "calll SL_TransferToCanonicalString\n"
        "movw %ax, (%ebx)\n"
        "addl $0x3c, %esp\n" /* line 2910 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf976ca_000977f7:\n"
        "movl $str_0021da10, %eax\n" /* line 2907 */
        "cmpb $0, scrCompilePub+36\n"
        "movl $str_0021da20, %edx\n" /* "$ and self field can only be used in the script debugger" */
        "cmovnel %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ecx), %eax\n" /* expr */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "addl $0x3c, %esp\n" /* line 2910 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf976ca_00097822:\n"
        "movl %edi, (%esp)\n" /* line 234 */
        "calll SL_AddRefToString\n"
        "jmp .Lf976ca_000977de\n"
        ".Lf976ca_0009782c:\n"
        "movl 8(%ecx), %edi\n" /* line 2894 | expr */
        "movl 4(%ecx), %ebx\n" /* expr, index */
        /* { scope 1 */
        "movl %edx, (%esp)\n" /* line 1368 */
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "movl %ebx, %eax\n" /* index */
        "calll Scr_FindLocalVarIndex\n"
        "movl %eax, %ebx\n" /* index */
        "cmpl $1, %eax\n" /* line 1369 */
        "sbbl %eax, %eax\n"
        "addl $0x37, %eax\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "calll EmitOpcode\n"
        "testl %ebx, %ebx\n" /* line 1373 | index */
        "jne .Lf976ca_000978b2\n"
        ".Lf976ca_0009785a:\n"
        "movl $1, 4(%esp)\n" /* line 1375 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2910 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf976ca_00097872:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf976ca_000976f6\n"
        "movl %edi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf976ca_000976f6\n"
        ".Lf976ca_0009788c:\n"
        "movl 4(%ebx), %ebx\n" /* line 2937 | index */
        "xorl %ecx, %ecx\n" /* line 1387 */
        "xorl %edx, %edx\n"
        "movl $0x14, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 1391 */
        "movl %ebx, (%esp)\n" /* index */
        "calll AddOpcodePos\n"
        "jmp .Lf976ca_00097759\n"
        /* { scope 1 */
        ".Lf976ca_000978b2:\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movb %bl, (%eax)\n" /* line 617 */
        "jmp .Lf976ca_0009785a\n"
        /* } scope */
        /* { scope 1 */
        ".Lf976ca_000978c7:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2885 | constValue */
        "calll EmitValue\n"
        "jmp .Lf976ca_00097732\n"
        /* } scope */
        ".Lf976ca_000978d4:\n"
        "movl 4(%ebx), %ebx\n" /* line 2933 | index */
        "movl %esi, %edx\n" /* block */
        "movl %ebx, %eax\n" /* index */
        "calll EmitVariableExpressionRef\n"
        "jmp .Lf976ca_00097759\n"
    );
}

/* line 4456 */
static __attribute__((naked))
unsigned int EmitStatement(scr_block_t *block)
{
    __asm__ __volatile__ (
        ".Lf978e6_000978e6:\n"
        "pushl %ebp\n" /* line 4456 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %ebx\n" /* val */
        "movl %ecx, %esi\n" /* endSourcePos */
        "cmpl $0x4d, (%eax)\n" /* line 4479 */
        "ja .Lf978e6_000979be\n"
        "movl (%eax), %eax\n"
        "jmpl *CorrectSolidDeltas+4928(, %eax, 4)\n"
        ".Lf978e6_00097905:\n"
        "movl 4(%ecx), %eax\n" /* line 3051 */
        "cmpl $0x1f, (%eax)\n" /* line 3082 */
        "jne .Lf978e6_000983ec\n"
        "movl (%edi), %eax\n" /* line 3057 */
        "cmpl $0xf, %eax\n"
        "je .Lf978e6_0009842a\n"
        "jg .Lf978e6_000983f4\n"
        "cmpl $4, %eax\n"
        "je .Lf978e6_000983ec\n"
        "cmpl $0xd, %eax\n"
        "jne .Lf978e6_000979be\n"
        "movl 0x10(%edi), %esi\n" /* line 3063 */
        "movl %esi, -0x38(%ebp)\n"
        "movl 0xc(%edi), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%edi), %esi\n"
        "movl 4(%edi), %ebx\n" /* index */
        /* { scope 1: constValue */
        "leal -0x24(%ebp), %edi\n" /* line 2883 | constValue */
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %edi, %edx\n"
        "movl %esi, %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf978e6_00097960\n"
        "movl %edi, %eax\n" /* line 2885 */
        "calll EmitValue\n"
        /* } scope */
        ".Lf978e6_00097960:\n"
        "movl (%ebx), %eax\n" /* line 2930 | index */
        "cmpl $0x11, %eax\n"
        "je .Lf978e6_000984e3\n"
        "cmpl $0x23, %eax\n"
        "je .Lf978e6_000984bd\n"
        "movl $str_0021da10, 4(%esp)\n" /* line 2941 */
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CompileError\n"
        ".Lf978e6_00097987:\n"
        "xorl %ecx, %ecx\n" /* line 1413 */
        "movl $0xffffffff, %edx\n"
        "movl $0x24, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1414 */
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 1415 */
        "movl -0x34(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        ".Lf978e6_000979be:\n"
        "addl $0x5c, %esp\n" /* line 4589 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 0x10(%ebx), %eax\n" /* line 4482 | val */
        "movl %eax, -0x44(%ebp)\n"
        "movl 0xc(%ebx), %edx\n" /* val, lastStatement */
        "movl %edx, -0x40(%ebp)\n" /* lastStatement */
        "movl 8(%ebx), %ecx\n" /* val */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        "cmpl $6, (%ecx)\n" /* line 3051 */
        "je .Lf978e6_00097905\n"
        "movl %ecx, %eax\n"
        /* { scope 1: constValue */
        ".Lf978e6_000979e6:\n"
        "leal -0x24(%ebp), %ebx\n" /* line 2883 | constValue, index */
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %ebx, %edx\n" /* index */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_000983c6\n"
        /* } scope */
        ".Lf978e6_000979fb:\n"
        "movl 8(%ebp), %edx\n" /* line 3088 | block */
        "movl %edi, %eax\n"
        "calll EmitVariableExpressionRef\n"
        "xorl %ecx, %ecx\n" /* line 752 */
        "movl $0xffffffff, %edx\n"
        "movl $0x39, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 753 */
        "movl -0x40(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_000979be\n"
        "movl 4(%ebx), %edi\n" /* line 4486 | val */
        "movl (%edi), %eax\n" /* line 2429 */
        "cmpl $0x17, %eax\n"
        "je .Lf978e6_000983a9\n"
        "cmpl $0x18, %eax\n"
        "jne .Lf978e6_000979be\n"
        "movl 0x10(%edi), %eax\n" /* line 2436 */
        "movl 0xc(%edi), %ecx\n"
        "movl 8(%edi), %edx\n"
        "movl 4(%edi), %ebx\n" /* index */
        "movl 8(%ebp), %esi\n" /* block */
        "movl %esi, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl %ebx, %eax\n" /* index */
        "calll EmitMethod\n"
        "jmp .Lf978e6_000979be\n"
        "movl 8(%ebx), %eax\n" /* line 4490 | val */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        "movl 8(%ebp), %edx\n" /* line 3107 | block */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf978e6_000982f7\n"
        "movl $3, (%edx)\n" /* line 3108 */
        "movl 8(%ebp), %ecx\n" /* block */
        /* { scope 1: constValue */
        ".Lf978e6_00097a87:\n"
        "leal -0x24(%ebp), %ebx\n" /* line 2883 | constValue, index */
        "movl %ebx, %edx\n" /* index */
        "movl %edi, %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_00098353\n"
        /* } scope */
        ".Lf978e6_00097a9b:\n"
        "xorl %ecx, %ecx\n" /* line 586 */
        "movl $0xffffffff, %edx\n"
        "movl $1, %eax\n"
        ".Lf978e6_00097aa7:\n"
        "calll EmitOpcode\n" /* line 752 */
        "movl $0, 4(%esp)\n" /* line 753 */
        "movl -0x3c(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_000979be\n"
        "movl 0x14(%ebx), %ecx\n" /* line 4506 | val */
        "movl 0x10(%ebx), %eax\n" /* val */
        "movl %eax, -0x44(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* val */
        "movl %eax, -0x40(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* val */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        "leal 0x1c(%ebx), %eax\n" /* val */
        "movl %eax, 0x18(%esp)\n"
        "leal 0x18(%ebx), %eax\n" /* val */
        "movl %eax, 0x14(%esp)\n"
        "movl 8(%ebp), %eax\n" /* block */
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* endSourcePos */
        "movzbl %dl, %eax\n" /* lastStatement */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x44(%ebp), %edx\n" /* lastStatement */
        "movl %edx, (%esp)\n" /* lastStatement */
        "movl -0x40(%ebp), %ecx\n"
        "movl -0x3c(%ebp), %edx\n" /* lastStatement */
        "movl %edi, %eax\n"
        "calll EmitIfElseStatement\n"
        "jmp .Lf978e6_000979be\n"
        "movl 0x10(%ebx), %ecx\n" /* line 4510 | val */
        "movl 0xc(%ebx), %esi\n" /* val, endSourcePos */
        "movl 8(%ebx), %eax\n" /* val */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        "leal 0x14(%ebx), %eax\n" /* val */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* block, lastStatement */
        "movl %edx, 4(%esp)\n" /* lastStatement */
        "movl %ecx, (%esp)\n"
        "movl %esi, %ecx\n" /* endSourcePos */
        "movl -0x3c(%ebp), %edx\n" /* lastStatement */
        "movl %edi, %eax\n"
        "calll EmitWhileStatement\n"
        "jmp .Lf978e6_000979be\n"
        "movl 0xc(%ebx), %eax\n" /* line 4498 | val */
        "movl %eax, -0x40(%ebp)\n"
        "movl 8(%ebx), %edx\n" /* val, lastStatement */
        "movl %edx, -0x3c(%ebp)\n" /* lastStatement */
        "movl 4(%ebx), %edi\n" /* val */
        /* { scope 1: constValue */
        "leal -0x24(%ebp), %ebx\n" /* line 2883 | constValue, index */
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %ebx, %edx\n" /* index */
        "movl %edi, %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_00098347\n"
        /* } scope */
        ".Lf978e6_00097b6f:\n"
        "xorl %ecx, %ecx\n" /* line 3129 */
        "movl $0xffffffff, %edx\n"
        "movl $0x4c, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3130 */
        "movl -0x40(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3131 */
        "movl -0x40(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3132 */
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_000979be\n"
        "movl 0xc(%ebx), %ecx\n" /* line 4502 | val */
        "movl %ecx, -0x40(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* val */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        "leal 0x10(%ebx), %eax\n" /* val */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* endSourcePos */
        "movzbl %dl, %eax\n" /* lastStatement */
        "movl %eax, (%esp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl -0x3c(%ebp), %edx\n" /* lastStatement */
        "movl %edi, %eax\n"
        "calll EmitIfStatement\n"
        "jmp .Lf978e6_000979be\n"
        "movl 4(%ebx), %edi\n" /* line 4494 | val */
        "movl 8(%ebp), %esi\n" /* line 3118 | block */
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf978e6_00097c09\n"
        "movl $3, (%esi)\n" /* line 3119 */
        ".Lf978e6_00097c09:\n"
        "xorl %ecx, %ecx\n" /* line 577 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 3122 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_000979be\n"
        "movl 0x18(%ebx), %eax\n" /* line 4514 | val */
        "movl 0x14(%ebx), %ecx\n" /* val */
        "movl 0x10(%ebx), %esi\n" /* val, endSourcePos */
        "movl %esi, -0x44(%ebp)\n" /* endSourcePos */
        "movl 0xc(%ebx), %edx\n" /* val, lastStatement */
        "movl %edx, -0x40(%ebp)\n" /* lastStatement */
        "movl 8(%ebx), %esi\n" /* val, endSourcePos */
        "movl 4(%ebx), %edi\n" /* val */
        "leal 0x20(%ebx), %edx\n" /* val, lastStatement */
        "movl %edx, 0x14(%esp)\n" /* lastStatement */
        "leal 0x1c(%ebx), %edx\n" /* val, lastStatement */
        "movl %edx, 0x10(%esp)\n" /* lastStatement */
        "movl 8(%ebp), %edx\n" /* block, lastStatement */
        "movl %edx, 0xc(%esp)\n" /* lastStatement */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x44(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl %esi, %edx\n" /* endSourcePos, lastStatement */
        "movl %edi, %eax\n"
        "calll EmitForStatement\n"
        "jmp .Lf978e6_000979be\n"
        "movl 8(%ebx), %esi\n" /* line 4518 | val, endSourcePos */
        "movl 4(%ebx), %edi\n" /* val */
        "movb $1, scrCompileGlob+80\n" /* line 3791 */
        "movl 8(%ebp), %edx\n" /* line 3792 | block */
        "movl %edi, %eax\n"
        "calll EmitVariableExpressionRef\n"
        "movb $0, scrCompileGlob+80\n" /* line 3794 */
        "xorl %ecx, %ecx\n" /* line 3795 */
        "movl $1, %edx\n"
        "movl $0x64, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3796 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "xorl %ecx, %ecx\n" /* line 752 */
        "movl $0xffffffff, %edx\n"
        "movl $0x39, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 753 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_000979be\n"
        "movl 8(%ebx), %eax\n" /* line 4522 | val */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        "movb $1, scrCompileGlob+80\n" /* line 3810 */
        "movl 8(%ebp), %edx\n" /* line 3811 | block */
        "movl %edi, %eax\n"
        "calll EmitVariableExpressionRef\n"
        "movb $0, scrCompileGlob+80\n" /* line 3813 */
        "xorl %ecx, %ecx\n" /* line 3814 */
        "movl $1, %edx\n"
        "movl $0x65, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3815 */
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "xorl %ecx, %ecx\n" /* line 752 */
        "movl $0xffffffff, %edx\n"
        "movl $0x39, %eax\n"
        "jmp .Lf978e6_00097aa7\n"
        "movl 0x10(%ebx), %esi\n" /* line 4526 | val, endSourcePos */
        "movl %esi, -0x44(%ebp)\n" /* endSourcePos */
        "movl 0xc(%ebx), %eax\n" /* val */
        "movl %eax, -0x40(%ebp)\n"
        "movl 8(%ebx), %edx\n" /* val, lastStatement */
        "movl %edx, -0x3c(%ebp)\n" /* lastStatement */
        "movl 4(%ebx), %edi\n" /* val */
        "movb $1, scrCompileGlob+28\n" /* line 2813 */
        "movl 8(%ebp), %edx\n" /* line 2814 | block */
        "movl %edi, %eax\n"
        "calll EmitVariableExpression\n"
        "movb $0, scrCompileGlob+28\n" /* line 2816 */
        /* { scope 1: constValue */
        "leal -0x24(%ebp), %ebx\n" /* line 2883 | constValue, index */
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %ebx, %edx\n" /* index */
        "movl -0x3c(%ebp), %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_0009833b\n"
        /* } scope */
        ".Lf978e6_00097d75:\n"
        "movsbl -0x40(%ebp), %eax\n" /* line 2818 */
        "xorl %ecx, %ecx\n"
        "movl $0xffffffff, %edx\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 2819 */
        "movl -0x44(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl 8(%ebp), %edx\n" /* line 2820 | block */
        "movl %edi, %eax\n"
        "calll EmitVariableExpressionRef\n"
        "xorl %ecx, %ecx\n" /* line 752 */
        "movl $0xffffffff, %edx\n"
        "movl $0x39, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 753 */
        "movl -0x44(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_000979be\n"
        "movl 4(%ebx), %edi\n" /* line 4530 | val */
        "movb %dl, -0x2d(%ebp)\n" /* lastStatement */
        /* { scope 1: constValue */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 4667 */
        "movl 4(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf978e6_000979be\n"
        ".Lf978e6_00097dde:\n"
        "movl 4(%ecx), %ebx\n" /* line 4669 | val */
        "cmpb $0, -0x2d(%ebp)\n" /* line 4670 | lastStatement */
        "je .Lf978e6_000981ce\n"
        "testl %ebx, %ebx\n" /* line 3985 | start_node */
        "je .Lf978e6_00097e12\n"
        "movl imp_scrVarPub, %eax\n" /* line 3987 */
        "cmpb $0, 0xb(%eax)\n"
        "jne .Lf978e6_000981ce\n"
        "movl %ebx, %edx\n" /* start_node */
        ".Lf978e6_00097e00:\n"
        "movl (%edx), %eax\n" /* line 3991 */
        "cmpl $0x2d, (%eax)\n"
        "jne .Lf978e6_000981ce\n"
        "movl 4(%edx), %edx\n" /* line 3993 */
        "testl %edx, %edx\n" /* line 3989 */
        "jne .Lf978e6_00097e00\n"
        ".Lf978e6_00097e12:\n"
        "movl $1, %edx\n" /* line 4670 | lastStatement */
        ".Lf978e6_00097e17:\n"
        "movl (%ecx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %ecx, (%esp)\n"
        "movl %esi, %ecx\n" /* endSourcePos */
        "calll EmitStatement\n"
        "testl %ebx, %ebx\n" /* line 4667 | val */
        "je .Lf978e6_000979be\n"
        "movl %ebx, %ecx\n" /* val */
        "jmp .Lf978e6_00097dde\n"
        /* } scope */
        /* } scope */
        "movl 0x10(%ebx), %eax\n" /* line 4554 | val */
        "movl %eax, -0x44(%ebp)\n"
        "movl 0xc(%ebx), %edx\n" /* val, lastStatement */
        "movl %edx, -0x40(%ebp)\n" /* lastStatement */
        "movl 8(%ebx), %ecx\n" /* val */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        /* { scope 1: constValue */
        "leal -0x24(%ebp), %ebx\n" /* line 2883 | constValue, index */
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %ebx, %edx\n" /* index */
        "movl -0x3c(%ebp), %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_0009836b\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_00097e5f:\n"
        "movl 8(%ebp), %ecx\n" /* line 2702 | block */
        "movl %ebx, %edx\n" /* index */
        "movl %edi, %eax\n"
        "calll EmitOrEvalPrimitiveExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_0009835f\n"
        /* } scope */
        ".Lf978e6_00097e73:\n"
        "xorl %ecx, %ecx\n" /* line 3967 */
        "movl $0xfffffffe, %edx\n"
        "movl $0x7a, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3968 */
        "movl -0x44(%ebp), %esi\n" /* expr_count */
        "movl %esi, (%esp)\n" /* expr_count */
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3969 */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_000979be\n"
        "movl 0xc(%ebx), %ecx\n" /* line 4558 | val */
        "movl %ecx, -0x40(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* val */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* endSourcePos */
        "movzbl %dl, %eax\n" /* lastStatement */
        "movl %eax, (%esp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl -0x3c(%ebp), %edx\n" /* lastStatement */
        "movl %edi, %eax\n"
        "calll EmitSwitchStatement\n"
        "jmp .Lf978e6_000979be\n"
        "movl 0x10(%ebx), %eax\n" /* line 4538 | val */
        "movl %eax, -0x44(%ebp)\n"
        "movl 0xc(%ebx), %edx\n" /* val, lastStatement */
        "movl %edx, -0x40(%ebp)\n" /* lastStatement */
        "movl 8(%ebx), %ecx\n" /* val */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        "movl (%ecx), %eax\n" /* line 3860 */
        "movl 4(%eax), %ebx\n" /* index */
        "movl (%ebx), %eax\n" /* line 3863 | index */
        "movl (%eax), %eax\n"
        /* { scope 1: constValue */
        "leal -0x24(%ebp), %esi\n" /* line 2883 | constValue */
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %esi, %edx\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_0009839d\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_00097f14:\n"
        "movl 8(%ebp), %ecx\n" /* line 2702 | block */
        "movl %esi, %edx\n"
        "movl %edi, %eax\n"
        "calll EmitOrEvalPrimitiveExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_00098391\n"
        /* } scope */
        ".Lf978e6_00097f28:\n"
        "xorl %ecx, %ecx\n" /* line 3866 */
        "movl $0xfffffffe, %edx\n"
        "movl $0x78, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3867 */
        "movl -0x44(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3868 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3869 */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3870 */
        "movl (%ebx), %eax\n" /* index */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        /* { scope 1: constValue */
        "movl 4(%ebx), %edi\n" /* line 3848 | index */
        "testl %edi, %edi\n" /* line 3849 */
        "je .Lf978e6_00097fde\n"
        ".Lf978e6_00097f8b:\n"
        "movl (%edi), %eax\n" /* line 3851 */
        "movl 4(%eax), %esi\n"
        "movl (%eax), %eax\n"
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 1117 | block */
        "movl %edx, (%esp)\n"
        "movl $1, %ecx\n"
        "movl %esi, %edx\n"
        "calll Scr_FindLocalVarIndex\n"
        "movl %eax, %ebx\n" /* index */
        "xorl %ecx, %ecx\n" /* line 1118 */
        "xorl %edx, %edx\n"
        "movl $0x33, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movb %bl, (%eax)\n" /* line 617 */
        "movl $0, 4(%esp)\n" /* line 1123 */
        "movl %esi, (%esp)\n"
        "calll AddOpcodePos\n"
        /* } scope */
        "movl 4(%edi), %edi\n" /* line 3848 */
        "testl %edi, %edi\n" /* line 3849 */
        "jne .Lf978e6_00097f8b\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_00097fde:\n"
        "xorl %ecx, %ecx\n" /* line 3929 */
        "xorl %edx, %edx\n"
        "movl $0x34, %eax\n"
        "calll EmitOpcode\n"
        "jmp .Lf978e6_000979be\n"
        /* } scope */
        "movl 0x10(%ebx), %ecx\n" /* line 4542 | val */
        "movl %ecx, -0x44(%ebp)\n"
        "movl 0xc(%ebx), %esi\n" /* val, endSourcePos */
        "movl %esi, -0x40(%ebp)\n" /* endSourcePos */
        "movl 8(%ebx), %eax\n" /* val */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        /* { scope 1: constValue */
        "movl (%eax), %edx\n" /* line 3898 */
        "movl 4(%edx), %eax\n"
        "movl 4(%eax), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* line 3899 | node */
        "je .Lf978e6_00098320\n"
        "xorl %esi, %esi\n" /* exprCount */
        "jmp .Lf978e6_00098028\n"
        ".Lf978e6_0009801a:\n"
        "addl $1, %esi\n" /* line 3903 | exprCount */
        "movl 4(%ebx), %ebx\n" /* line 3898 | node */
        "testl %ebx, %ebx\n" /* line 3899 | node */
        "je .Lf978e6_0009823b\n"
        ".Lf978e6_00098028:\n"
        "movl (%ebx), %eax\n" /* line 3902 | node */
        "movl (%eax), %eax\n"
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 2883 | block */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf978e6_0009801a\n"
        "leal -0x24(%ebp), %eax\n" /* line 2885 | constValue */
        "calll EmitValue\n"
        "jmp .Lf978e6_0009801a\n"
        /* } scope */
        /* } scope */
        "movl 4(%ebx), %edi\n" /* line 4546 | val */
        "xorl %ecx, %ecx\n" /* line 3138 */
        "xorl %edx, %edx\n"
        "movl $0x4d, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 3139 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3140 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_000979be\n"
        "movl 0x10(%ebx), %ecx\n" /* line 4550 | val */
        "movl %ecx, -0x44(%ebp)\n"
        "movl 0xc(%ebx), %esi\n" /* val, endSourcePos */
        "movl %esi, -0x40(%ebp)\n" /* endSourcePos */
        "movl 8(%ebx), %eax\n" /* val */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%ebx), %edi\n" /* val */
        /* { scope 1: constValue */
        "xorl %ecx, %ecx\n" /* line 3939 */
        "movl $1, %edx\n"
        "movl $0x7b, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 3940 */
        "movl %esi, (%esp)\n" /* expr_count */
        "calll AddOpcodePos\n"
        "movl -0x3c(%ebp), %edx\n" /* line 3945 */
        "movl (%edx), %ebx\n" /* start_node */
        "testl %ebx, %ebx\n" /* start_node */
        "je .Lf978e6_00098319\n"
        "xorl %esi, %esi\n" /* expr_count */
        "jmp .Lf978e6_000980d2\n"
        ".Lf978e6_000980c2:\n"
        "addl $1, %esi\n" /* line 3949 | expr_count */
        "movl 4(%ebx), %eax\n" /* line 3945 | start_node */
        "testl %eax, %eax\n"
        "je .Lf978e6_000981d5\n"
        "movl %eax, %ebx\n" /* start_node */
        ".Lf978e6_000980d2:\n"
        "movl (%ebx), %eax\n" /* line 3948 | start_node */
        "movl (%eax), %eax\n"
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 2883 | block */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf978e6_000980c2\n"
        "leal -0x24(%ebp), %eax\n" /* line 2885 | constValue */
        "calll EmitValue\n"
        "jmp .Lf978e6_000980c2\n"
        /* } scope */
        /* } scope */
        "movl 4(%ebx), %edi\n" /* line 4570 | val */
        "movl 8(%ebp), %edx\n" /* block, lastStatement */
        "movl %edi, %eax\n"
        "calll EmitBreakStatement\n"
        "jmp .Lf978e6_000979be\n"
        "movl 4(%ebx), %edi\n" /* line 4574 | val */
        "movl 8(%ebp), %edx\n" /* block, lastStatement */
        "movl %edi, %eax\n"
        "calll EmitContinueStatement\n"
        "jmp .Lf978e6_000979be\n"
        "movl 4(%ebx), %edi\n" /* line 4582 | val */
        "movl imp_scrVarPub, %eax\n" /* line 4410 */
        "cmpb $0, 0xb(%eax)\n"
        "je .Lf978e6_00098167\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "je .Lf978e6_000983d2\n"
        ".Lf978e6_0009812e:\n"
        "xorl %ecx, %ecx\n" /* line 4438 */
        "xorl %edx, %edx\n"
        "movl $0x85, %eax\n"
        ".Lf978e6_00098137:\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movb $0, (%eax)\n" /* line 617 */
        "jmp .Lf978e6_000979be\n"
        "movl 4(%ebx), %edi\n" /* line 4586 | val */
        "movl imp_scrVarPub, %eax\n" /* line 4410 */
        "cmpb $0, 0xb(%eax)\n"
        "jne .Lf978e6_000982fe\n"
        ".Lf978e6_00098167:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf978e6_000979be\n"
        "movl %edi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf978e6_000979be\n"
        "movl $str_0021da5c, 4(%esp)\n" /* line 4562 */
        "movl 8(%ebx), %eax\n" /* val */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf978e6_000979be\n"
        "movl $str_0021da74, 4(%esp)\n" /* line 4566 */
        "movl 4(%ebx), %eax\n" /* val */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf978e6_000979be\n"
        "movl 8(%ebx), %esi\n" /* line 4534 | val, endSourcePos */
        "movl 4(%ebx), %edi\n" /* val */
        "leal 0xc(%ebx), %eax\n" /* val */
        "movl %eax, (%esp)\n"
        "movl 8(%ebp), %ecx\n" /* block */
        "movl %esi, %edx\n" /* endSourcePos, lastStatement */
        "movl %edi, %eax\n"
        "calll EmitDeveloperStatementList\n"
        "jmp .Lf978e6_000979be\n"
        /* { scope 1: constValue */
        /* { scope 2 */
        ".Lf978e6_000981ce:\n"
        "xorl %edx, %edx\n" /* line 4670 | lastStatement */
        "jmp .Lf978e6_00097e17\n"
        /* } scope */
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_000981d5:\n"
        "negl %esi\n" /* line 3945 | expr_count */
        /* { scope 2 */
        ".Lf978e6_000981d7:\n"
        "movl 8(%ebp), %ecx\n" /* line 2702 | block */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "movl %edi, %eax\n"
        "calll EmitOrEvalPrimitiveExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_0009832e\n"
        /* } scope */
        ".Lf978e6_000981ec:\n"
        "leal -2(%esi), %edx\n" /* line 3955 | expr_count */
        "xorl %ecx, %ecx\n"
        "movl $0x79, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3956 */
        "movl -0x44(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3957 */
        "movl (%ebx), %eax\n" /* start_node */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3958 */
        "movl -0x40(%ebp), %esi\n" /* expr_count */
        "movl %esi, (%esp)\n" /* expr_count */
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_000979be\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_0009823b:\n"
        "movl $0xfffffffe, -0x2c(%ebp)\n" /* line 3900 */
        "subl %esi, -0x2c(%ebp)\n" /* exprCount */
        "movl -0x3c(%ebp), %ecx\n"
        "movl (%ecx), %edx\n"
        ".Lf978e6_0009824a:\n"
        "movl 4(%edx), %ebx\n" /* line 3906 | node */
        "movl (%ebx), %eax\n" /* line 3909 | node */
        "movl (%eax), %eax\n"
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 2883 | block */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_00098384\n"
        /* } scope */
        /* { scope 2 */
        ".Lf978e6_00098264:\n"
        "movl 8(%ebp), %ecx\n" /* line 2702 | block */
        "leal -0x24(%ebp), %edx\n" /* constValue */
        "movl %edi, %eax\n"
        "calll EmitOrEvalPrimitiveExpression\n"
        "testb %al, %al\n"
        "jne .Lf978e6_00098377\n"
        /* } scope */
        ".Lf978e6_00098279:\n"
        "xorl %ecx, %ecx\n" /* line 3912 */
        "movl -0x2c(%ebp), %edx\n"
        "movl $0x77, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3913 */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3914 */
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 3915 */
        "movl -0x40(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll AddOpcodePos\n"
        ".Lf978e6_000982c1:\n"
        "movl $0, 4(%esp)\n" /* line 3916 */
        "movl (%ebx), %eax\n" /* node */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl 4(%ebx), %ebx\n" /* line 3920 | node */
        "testl %ebx, %ebx\n" /* line 3921 | node */
        "jne .Lf978e6_000982c1\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movl %esi, %edx\n" /* line 617 */
        "movb %dl, (%eax)\n"
        "jmp .Lf978e6_00097fde\n"
        ".Lf978e6_000982f7:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf978e6_00097a87\n"
        /* } scope */
        ".Lf978e6_000982fe:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "je .Lf978e6_000983df\n"
        ".Lf978e6_0009830b:\n"
        "xorl %ecx, %ecx\n" /* line 4438 */
        "xorl %edx, %edx\n"
        "movl $0x86, %eax\n"
        "jmp .Lf978e6_00098137\n"
        /* { scope 1: constValue */
        ".Lf978e6_00098319:\n"
        "xorl %esi, %esi\n" /* line 3945 | expr_count */
        "jmp .Lf978e6_000981d7\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_00098320:\n"
        "xorl %esi, %esi\n" /* line 3899 | exprCount */
        "movl $0xfffffffe, -0x2c(%ebp)\n"
        "jmp .Lf978e6_0009824a\n"
        /* } scope */
        /* { scope 1: constValue */
        /* { scope 2 */
        ".Lf978e6_0009832e:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2704 | constValue */
        "calll EmitValue\n"
        "jmp .Lf978e6_000981ec\n"
        /* } scope */
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_0009833b:\n"
        "movl %ebx, %eax\n" /* line 2885 | index */
        "calll EmitValue\n"
        "jmp .Lf978e6_00097d75\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_00098347:\n"
        "movl %ebx, %eax\n" /* index */
        "calll EmitValue\n"
        "jmp .Lf978e6_00097b6f\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_00098353:\n"
        "movl %ebx, %eax\n" /* index */
        "calll EmitValue\n"
        "jmp .Lf978e6_00097a9b\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_0009835f:\n"
        "movl %ebx, %eax\n" /* line 2704 | index */
        "calll EmitValue\n"
        "jmp .Lf978e6_00097e73\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_0009836b:\n"
        "movl %ebx, %eax\n" /* line 2885 | index */
        "calll EmitValue\n"
        "jmp .Lf978e6_00097e5f\n"
        /* } scope */
        /* { scope 1: constValue */
        /* { scope 2 */
        ".Lf978e6_00098377:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2704 | constValue */
        "calll EmitValue\n"
        "jmp .Lf978e6_00098279\n"
        /* } scope */
        /* { scope 2 */
        ".Lf978e6_00098384:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2885 | constValue */
        "calll EmitValue\n"
        "jmp .Lf978e6_00098264\n"
        /* } scope */
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_00098391:\n"
        "movl %esi, %eax\n" /* line 2704 */
        "calll EmitValue\n"
        "jmp .Lf978e6_00097f28\n"
        /* } scope */
        /* { scope 1: constValue */
        ".Lf978e6_0009839d:\n"
        "movl %esi, %eax\n" /* line 2885 */
        "calll EmitValue\n"
        "jmp .Lf978e6_00097f14\n"
        /* } scope */
        ".Lf978e6_000983a9:\n"
        "movl 8(%edi), %edx\n" /* line 2432 */
        "movl 4(%edi), %ebx\n" /* index */
        "movl 8(%ebp), %esi\n" /* block */
        "movl %esi, (%esp)\n"
        "movl $1, %ecx\n"
        "movl %ebx, %eax\n" /* index */
        "calll EmitCall\n"
        "jmp .Lf978e6_000979be\n"
        /* { scope 1: constValue */
        ".Lf978e6_000983c6:\n"
        "movl %ebx, %eax\n" /* line 2885 | index */
        "calll EmitValue\n"
        "jmp .Lf978e6_000979fb\n"
        /* } scope */
        ".Lf978e6_000983d2:\n"
        "movl %edi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf978e6_0009812e\n"
        ".Lf978e6_000983df:\n"
        "movl %edi, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "jmp .Lf978e6_0009830b\n"
        ".Lf978e6_000983ec:\n"
        "movl -0x3c(%ebp), %eax\n"
        "jmp .Lf978e6_000979e6\n"
        ".Lf978e6_000983f4:\n"
        "cmpl $0x35, %eax\n" /* line 3057 */
        "je .Lf978e6_00098402\n"
        "cmpl $0x4f, %eax\n"
        "jne .Lf978e6_000979be\n"
        ".Lf978e6_00098402:\n"
        "movl $str_0021da10, %eax\n" /* line 3072 */
        "cmpb $0, scrCompilePub+36\n"
        "movl $str_0021da20, %edx\n" /* "$ and self field can only be used in the script debugger" */
        "cmovnel %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf978e6_000979be\n"
        ".Lf978e6_0009842a:\n"
        "movl 0xc(%edi), %eax\n" /* line 3067 */
        "movl 8(%edi), %esi\n"
        "movl 4(%edi), %ebx\n" /* index */
        "movl 8(%ebp), %ecx\n" /* line 1461 | block */
        "movl %eax, %edx\n"
        "movl %ebx, %eax\n" /* index */
        "calll EmitPrimitiveExpressionFieldObject\n"
        "xorl %ecx, %ecx\n" /* line 1462 */
        "xorl %edx, %edx\n"
        "movl $0x2f, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 1463 */
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 214 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "cmpl $2, scrCompilePub+40\n" /* line 216 */
        "je .Lf978e6_00098499\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 233 */
        "jne .Lf978e6_000984b3\n"
        ".Lf978e6_00098483:\n"
        "movl scrCompileGlob, %ebx\n" /* line 236 */
        "movl %esi, (%esp)\n"
        "calll SL_TransferToCanonicalString\n"
        "movw %ax, (%ebx)\n"
        "jmp .Lf978e6_000979be\n"
        ".Lf978e6_00098499:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf978e6_000979be\n"
        "movl %esi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf978e6_000979be\n"
        ".Lf978e6_000984b3:\n"
        "movl %esi, (%esp)\n" /* line 234 */
        "calll SL_AddRefToString\n"
        "jmp .Lf978e6_00098483\n"
        ".Lf978e6_000984bd:\n"
        "movl 4(%ebx), %ebx\n" /* line 2937 | index */
        "xorl %ecx, %ecx\n" /* line 1387 */
        "xorl %edx, %edx\n"
        "movl $0x14, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 1391 */
        "movl %ebx, (%esp)\n" /* index */
        "calll AddOpcodePos\n"
        "jmp .Lf978e6_00097987\n"
        ".Lf978e6_000984e3:\n"
        "movl 4(%ebx), %ebx\n" /* line 2933 | index */
        "movl 8(%ebp), %edx\n" /* block */
        "movl %ebx, %eax\n" /* index */
        "calll EmitVariableExpressionRef\n"
        "jmp .Lf978e6_00097987\n"
    );
}

/* line 3144 */
static __attribute__((naked))
unsigned int EmitIfStatement(sval_t stmt, int lastStatement, unsigned int endSourcePos, scr_block_t *block, sval_t *ifStatBlock)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3144 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %edx, -0x44(%ebp)\n"
        "movl %ecx, %edi\n" /* sourcePos */
        "movzbl 8(%ebp), %edx\n" /* lastStatement */
        "movb %dl, -0x45(%ebp)\n" /* lastStatement */
        /* { scope 1: constValue, j */
        /* { scope 2 */
        "leal -0x24(%ebp), %esi\n" /* line 2883 | constValue, outerBlock */
        "movl 0x10(%ebp), %ecx\n" /* block */
        "movl %esi, %edx\n" /* outerBlock */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf984f6_0009873a\n"
        /* } scope */
        ".Lf984f6_00098520:\n"
        "xorl %ecx, %ecx\n" /* line 3151 */
        "movl $0xffffffff, %edx\n"
        "movl $0x5e, %eax\n" /* expr */
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3152 */
        "movl %edi, (%esp)\n" /* sourcePos */
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw $0, (%eax)\n" /* line 610 */
        "movl scrCompileGlob, %ebx\n" /* line 3154 | removeCount */
        "movl %ebx, -0x40(%ebp)\n" /* removeCount, pos */
        "movl $0, (%esp)\n" /* line 3155 */
        "calll TempMalloc\n"
        "movl %eax, -0x3c(%ebp)\n" /* expr, nextPos */
        "movl 0x14(%ebp), %eax\n" /* line 3156 | ifStatBlock, expr */
        "movl (%eax), %edi\n" /* expr, sourcePos */
        "movl %edi, -0x30(%ebp)\n" /* sourcePos */
        "movl 0x10(%ebp), %edx\n" /* block */
        "addl $0x18, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* j */
        /* { scope 2 */
        ".Lf984f6_00098587:\n"
        "movl -0x34(%ebp), %eax\n" /* line 1058 | j */
        "cmpl 8(%edi), %eax\n" /* checksum */
        "jl .Lf984f6_0009859e\n"
        "movl 0x10(%ebp), %edx\n" /* block */
        "movl 4(%edx), %eax\n"
        "cmpl %eax, -0x34(%ebp)\n" /* j */
        "jge .Lf984f6_00098686\n"
        /* } scope */
        ".Lf984f6_0009859e:\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 1060 | removeCount */
        "movl (%ebx), %ebx\n" /* removeCount */
        "movl %ebx, -0x38(%ebp)\n" /* removeCount */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%edi), %esi\n" /* line 764 */
        "movl %esi, %ecx\n"
        "cmpl %esi, -0x34(%ebp)\n" /* j */
        "jge .Lf984f6_00098653\n"
        "movl -0x30(%ebp), %eax\n" /* line 766 */
        "cmpl %ebx, 0x18(%eax)\n"
        "je .Lf984f6_0009867e\n"
        "movl -0x34(%ebp), %ebx\n" /* j */
        "leal 0x18(%edi, %ebx, 4), %edx\n"
        ".Lf984f6_000985c7:\n"
        "addl $1, %ebx\n" /* line 764 */
        "cmpl %esi, %ebx\n"
        "je .Lf984f6_00098653\n"
        "movl 4(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0x38(%ebp)\n"
        "jne .Lf984f6_000985c7\n"
        /* } scope */
        ".Lf984f6_000985dd:\n"
        "testl %ebx, %ebx\n" /* line 1062 | removeCount */
        "js .Lf984f6_00098653\n"
        ".Lf984f6_000985e1:\n"
        "movl 8(%edi), %eax\n" /* line 1068 | block */
        "cmpl %eax, %ebx\n" /* removeCount */
        "jl .Lf984f6_000985ee\n"
        "addl $1, %eax\n" /* line 1070 */
        "movl %eax, 8(%edi)\n" /* block */
        ".Lf984f6_000985ee:\n"
        "cmpl %ebx, -0x34(%ebp)\n" /* line 1073 | removeCount, j */
        "jge .Lf984f6_00098614\n"
        "leal (, %ebx, 4), %eax\n"
        "leal 0x14(%eax, %edi), %ecx\n"
        "leal 0x18(%eax, %edi), %edx\n"
        ".Lf984f6_00098602:\n"
        "subl $1, %ebx\n" /* line 1075 | removeCount */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x34(%ebp)\n" /* line 1073 | removeCount, j */
        "jl .Lf984f6_00098602\n"
        ".Lf984f6_00098614:\n"
        "movl -0x38(%ebp), %edx\n" /* line 1078 */
        "movl -0x30(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "movl -0x34(%ebp), %edx\n" /* line 1079 | j */
        "sarl $3, %edx\n"
        "movl -0x34(%ebp), %ecx\n" /* j */
        "andl $7, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* block, removeCount */
        "movzbl 0x10(%edx, %ebx), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf984f6_00098642\n"
        "movl $1, %eax\n" /* line 1080 */
        "shll %cl, %eax\n"
        "orb %al, 0x10(%edx, %edi)\n"
        ".Lf984f6_00098642:\n"
        "addl $1, -0x34(%ebp)\n" /* line 1058 | j */
        "addl $4, -0x30(%ebp)\n"
        "addl $4, -0x2c(%ebp)\n"
        "jmp .Lf984f6_00098587\n"
        ".Lf984f6_00098653:\n"
        "cmpl $0x3f, %esi\n" /* line 894 | outerBlock */
        "jg .Lf984f6_00098665\n"
        ".Lf984f6_00098658:\n"
        "leal 1(%ecx), %eax\n" /* line 1066 */
        "movl %eax, 0xc(%edi)\n" /* block */
        "movl %esi, %ebx\n" /* outerBlock, removeCount */
        "jmp .Lf984f6_000985e1\n"
        ".Lf984f6_00098665:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%edi), %ecx\n" /* checksum */
        "jmp .Lf984f6_00098658\n"
        /* { scope 3 */
        ".Lf984f6_0009867e:\n"
        "movl -0x34(%ebp), %ebx\n" /* line 766 | j */
        "jmp .Lf984f6_000985dd\n"
        /* } scope */
        ".Lf984f6_00098686:\n"
        "movl %eax, 4(%edi)\n" /* line 1084 | block */
        "movl $0, (%edi)\n" /* line 1085 | block */
        /* } scope */
        "movl 0x14(%ebp), %ebx\n" /* line 3157 | ifStatBlock, removeCount */
        "movl (%ebx), %eax\n" /* removeCount, expr */
        "movzbl -0x45(%ebp), %ebx\n" /* lastStatement, removeCount */
        "movl %eax, (%esp)\n" /* expr */
        "movl 0xc(%ebp), %ecx\n" /* endSourcePos */
        "movl %ebx, %edx\n" /* removeCount */
        "movl -0x44(%ebp), %eax\n" /* expr */
        "calll EmitStatement\n"
        "movl 0x14(%ebp), %eax\n" /* line 3159 | ifStatBlock, expr */
        "movl (%eax), %esi\n" /* expr, outerBlock */
        /* { scope 2 */
        "movl imp_scrVarPub, %edx\n" /* line 868 */
        "movl 0x3c(%edx), %edi\n" /* checksum */
        "testl %ebx, %ebx\n" /* line 870 | removeCount */
        "jne .Lf984f6_0009871a\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl (%esi), %eax\n" /* line 850 */
        "testl %eax, %eax\n"
        "jne .Lf984f6_000986f1\n"
        "movl 4(%esi), %eax\n" /* line 854 */
        "movl %eax, %ebx\n" /* line 856 | removeCount */
        "subl 8(%esi), %ebx\n" /* removeCount */
        "je .Lf984f6_000986f1\n"
        "xorl %ecx, %ecx\n" /* line 858 */
        "xorl %edx, %edx\n"
        "movl $0x17, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movb %bl, (%eax)\n" /* line 617 */
        "movl 8(%esi), %eax\n" /* line 860 */
        "movl %eax, 4(%esi)\n"
        /* } scope */
        /* } scope */
        ".Lf984f6_000986f1:\n"
        "leal 1(%edi), %eax\n" /* line 880 | checksum */
        "movl imp_scrVarPub, %edx\n"
        "movl %eax, 0x3c(%edx)\n"
        /* } scope */
        "movl $0, (%esp)\n" /* line 3160 */
        "calll TempMalloc\n"
        "subl -0x3c(%ebp), %eax\n" /* line 3162 | nextPos, expr */
        "movl -0x40(%ebp), %ebx\n" /* pos, removeCount */
        "movw %ax, (%ebx)\n" /* expr, removeCount */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 3163 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: constValue, j */
        /* { scope 2 */
        ".Lf984f6_0009871a:\n"
        "xorl %ecx, %ecx\n" /* line 577 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 873 */
        "movl 0xc(%ebp), %ebx\n" /* endSourcePos, removeCount */
        "movl %ebx, (%esp)\n" /* removeCount */
        "calll AddOpcodePos\n"
        "jmp .Lf984f6_000986f1\n"
        /* } scope */
        /* { scope 2 */
        ".Lf984f6_0009873a:\n"
        "movl %esi, %eax\n" /* line 2885 | outerBlock */
        "calll EmitValue\n"
        "jmp .Lf984f6_00098520\n"
    );
}

/* line 3174 */
static __attribute__((naked))
unsigned int EmitIfElseStatement(sval_t stmt1, sval_t stmt2, sval_t sourcePos, sval_t elseSourcePos, int lastStatement, unsigned int endSourcePos, scr_block_t *block, sval_t *ifStatBlock, sval_t *elseStatBlock)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3174 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl %edx, -0x80(%ebp)\n"
        "movl %ecx, -0x84(%ebp)\n"
        "movzbl 0x10(%ebp), %edx\n" /* lastStatement */
        "movb %dl, -0x85(%ebp)\n" /* lastStatement */
        /* { scope 1: constValue, j, j, i */
        /* { scope 2 */
        "leal -0x2c(%ebp), %ebx\n" /* line 2883 | constValue, outerBlock */
        "movl 0x18(%ebp), %ecx\n" /* block */
        "movl %ebx, %edx\n" /* outerBlock */
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf98746_00098ce1\n"
        /* } scope */
        ".Lf98746_0009877a:\n"
        "xorl %ecx, %ecx\n" /* line 3188 */
        "movl $0xffffffff, %edx\n"
        "movl $0x5e, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3189 */
        "movl 8(%ebp), %eax\n" /* sourcePos */
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw $0, (%eax)\n" /* line 610 */
        "movl scrCompileGlob, %ebx\n" /* line 3191 | checksum */
        "movl %ebx, -0x78(%ebp)\n" /* checksum, pos1 */
        "movl $0, (%esp)\n" /* line 3192 */
        "calll TempMalloc\n"
        "movl %eax, -0x70(%ebp)\n" /* nextPos1 */
        "movl 0x1c(%ebp), %eax\n" /* line 3194 | ifStatBlock */
        "movl (%eax), %edi\n" /* block */
        "movl %edi, -0x44(%ebp)\n" /* block */
        "movl 0x18(%ebp), %edx\n" /* line 3174 | block */
        "addl $0x18, %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl $0, -0x60(%ebp)\n" /* j */
        /* { scope 2 */
        ".Lf98746_000987e7:\n"
        "movl -0x60(%ebp), %eax\n" /* line 1058 | j */
        "cmpl 8(%edi), %eax\n" /* localVarsCreateCount */
        "jl .Lf98746_000987fe\n"
        "movl 0x18(%ebp), %edx\n" /* block */
        "movl 4(%edx), %eax\n"
        "cmpl %eax, -0x60(%ebp)\n" /* j */
        "jge .Lf98746_000988e6\n"
        /* } scope */
        ".Lf98746_000987fe:\n"
        "movl -0x40(%ebp), %ebx\n" /* line 1060 | outerBlock */
        "movl (%ebx), %ebx\n" /* outerBlock */
        "movl %ebx, -0x64(%ebp)\n" /* outerBlock */
        /* { scope 2 */
        /* { scope 3: removeCount */
        "movl 0xc(%edi), %esi\n" /* line 764 */
        "movl %esi, %ecx\n"
        "cmpl %esi, -0x60(%ebp)\n" /* j */
        "jge .Lf98746_000988b3\n"
        "movl -0x44(%ebp), %eax\n" /* line 766 */
        "cmpl 0x18(%eax), %ebx\n"
        "je .Lf98746_000988de\n"
        "movl -0x60(%ebp), %ebx\n" /* j */
        "leal 0x18(%edi, %ebx, 4), %edx\n"
        ".Lf98746_00098827:\n"
        "addl $1, %ebx\n" /* line 764 */
        "cmpl %esi, %ebx\n"
        "je .Lf98746_000988b3\n"
        "movl 4(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0x64(%ebp)\n"
        "jne .Lf98746_00098827\n"
        /* } scope */
        ".Lf98746_0009883d:\n"
        "testl %ebx, %ebx\n" /* line 1062 | outerBlock */
        "js .Lf98746_000988b3\n"
        ".Lf98746_00098841:\n"
        "movl 8(%edi), %eax\n" /* line 1068 | block */
        "cmpl %eax, %ebx\n" /* outerBlock */
        "jl .Lf98746_0009884e\n"
        "addl $1, %eax\n" /* line 1070 */
        "movl %eax, 8(%edi)\n" /* block */
        ".Lf98746_0009884e:\n"
        "cmpl %ebx, -0x60(%ebp)\n" /* line 1073 | outerBlock, j */
        "jge .Lf98746_00098874\n"
        "leal (, %ebx, 4), %eax\n"
        "leal 0x14(%eax, %edi), %ecx\n"
        "leal 0x18(%eax, %edi), %edx\n"
        ".Lf98746_00098862:\n"
        "subl $1, %ebx\n" /* line 1075 | outerBlock */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x60(%ebp)\n" /* line 1073 | outerBlock, j */
        "jl .Lf98746_00098862\n"
        ".Lf98746_00098874:\n"
        "movl -0x64(%ebp), %edx\n" /* line 1078 */
        "movl -0x44(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "movl -0x60(%ebp), %edx\n" /* line 1079 | j */
        "sarl $3, %edx\n"
        "movl -0x60(%ebp), %ecx\n" /* j */
        "andl $7, %ecx\n"
        "movl 0x18(%ebp), %ebx\n" /* block, outerBlock */
        "movzbl 0x10(%edx, %ebx), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf98746_000988a2\n"
        "movl $1, %eax\n" /* line 1080 */
        "shll %cl, %eax\n"
        "orb %al, 0x10(%edx, %edi)\n"
        ".Lf98746_000988a2:\n"
        "addl $1, -0x60(%ebp)\n" /* line 1058 | j */
        "addl $4, -0x44(%ebp)\n"
        "addl $4, -0x40(%ebp)\n"
        "jmp .Lf98746_000987e7\n"
        ".Lf98746_000988b3:\n"
        "cmpl $0x3f, %esi\n" /* line 894 | checksum */
        "jg .Lf98746_000988c5\n"
        ".Lf98746_000988b8:\n"
        "leal 1(%ecx), %eax\n" /* line 1066 */
        "movl %eax, 0xc(%edi)\n" /* block */
        "movl %esi, %ebx\n" /* checksum, outerBlock */
        "jmp .Lf98746_00098841\n"
        ".Lf98746_000988c5:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%edi), %ecx\n"
        "jmp .Lf98746_000988b8\n"
        /* { scope 3: removeCount */
        ".Lf98746_000988de:\n"
        "movl -0x60(%ebp), %ebx\n" /* line 766 | j */
        "jmp .Lf98746_0009883d\n"
        /* } scope */
        ".Lf98746_000988e6:\n"
        "movl %eax, 4(%edi)\n" /* line 1084 | block */
        "movl $0, (%edi)\n" /* line 1085 | block */
        /* } scope */
        "movl 0x1c(%ebp), %ebx\n" /* line 3195 | ifStatBlock, checksum */
        "movl (%ebx), %eax\n" /* checksum */
        "movzbl -0x85(%ebp), %edx\n" /* lastStatement */
        "movl %edx, -0x7c(%ebp)\n"
        "movl %eax, (%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* endSourcePos */
        "movl -0x80(%ebp), %eax\n"
        "calll EmitStatement\n"
        "movl 0x1c(%ebp), %eax\n" /* line 3196 | ifStatBlock */
        "movl (%eax), %ebx\n" /* checksum */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 850 */
        "testl %eax, %eax\n"
        "jne .Lf98746_00098925\n"
        "movl 4(%ebx), %eax\n" /* line 854 */
        "movl %eax, %esi\n" /* line 856 | removeCount */
        "subl 8(%ebx), %esi\n" /* removeCount */
        "jne .Lf98746_00098ced\n"
        /* } scope */
        ".Lf98746_00098925:\n"
        "movl (%ebx), %eax\n" /* line 3197 | checksum */
        "testl %eax, %eax\n"
        "je .Lf98746_00098c33\n"
        "movl $0, -0x68(%ebp)\n" /* childCount */
        ".Lf98746_00098936:\n"
        "movl imp_scrVarPub, %eax\n" /* line 3203 */
        "movl 0x3c(%eax), %ebx\n" /* checksum */
        "cmpb $0, -0x85(%ebp)\n" /* line 3205 | lastStatement */
        "je .Lf98746_00098bde\n"
        "xorl %ecx, %ecx\n" /* line 577 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll EmitOpcode\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl $0, (%eax)\n" /* line 596 */
        "movl $1, 4(%esp)\n" /* line 3209 */
        "movl 0x14(%ebp), %edx\n" /* endSourcePos */
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, -0x74(%ebp)\n" /* pos2 */
        "movl $0, -0x6c(%ebp)\n" /* nextPos2 */
        ".Lf98746_0009898e:\n"
        "leal 1(%ebx), %edx\n" /* line 3222 | checksum */
        "movl imp_scrVarPub, %eax\n"
        "movl %edx, 0x3c(%eax)\n"
        "movl $0, (%esp)\n" /* line 3224 */
        "calll TempMalloc\n"
        "subl -0x70(%ebp), %eax\n" /* line 3226 | nextPos1 */
        "movl -0x78(%ebp), %ebx\n" /* pos1, checksum */
        "movw %ax, (%ebx)\n" /* checksum */
        "movl 0x20(%ebp), %eax\n" /* line 3228 | elseStatBlock */
        "movl (%eax), %edi\n" /* block */
        "movl %edi, -0x4c(%ebp)\n" /* block */
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl $0, -0x58(%ebp)\n" /* j */
        /* { scope 2 */
        ".Lf98746_000989c3:\n"
        "movl -0x58(%ebp), %eax\n" /* line 1058 | j */
        "cmpl 8(%edi), %eax\n" /* localVarsCreateCount */
        "jl .Lf98746_000989da\n"
        "movl 0x18(%ebp), %edx\n" /* block */
        "movl 4(%edx), %eax\n"
        "cmpl %eax, -0x58(%ebp)\n" /* j */
        "jge .Lf98746_00098ac4\n"
        /* } scope */
        ".Lf98746_000989da:\n"
        "movl -0x48(%ebp), %ebx\n" /* line 1060 | outerBlock */
        "movl (%ebx), %ebx\n" /* outerBlock */
        "movl %ebx, -0x5c(%ebp)\n" /* outerBlock */
        /* { scope 2 */
        /* { scope 3: removeCount */
        "movl 0xc(%edi), %esi\n" /* line 764 */
        "movl %esi, %ecx\n"
        "cmpl %esi, -0x58(%ebp)\n" /* j */
        "jge .Lf98746_00098a91\n"
        "movl %ebx, %eax\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 766 */
        "cmpl %eax, 0x18(%ebx)\n"
        "je .Lf98746_00098abc\n"
        "movl -0x58(%ebp), %ebx\n" /* j */
        "leal 0x18(%edi, %ebx, 4), %edx\n"
        ".Lf98746_00098a05:\n"
        "addl $1, %ebx\n" /* line 764 */
        "cmpl %ebx, %esi\n"
        "je .Lf98746_00098a91\n"
        "movl 4(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl -0x5c(%ebp), %eax\n"
        "jne .Lf98746_00098a05\n"
        /* } scope */
        ".Lf98746_00098a1b:\n"
        "testl %ebx, %ebx\n" /* line 1062 | outerBlock */
        "js .Lf98746_00098a91\n"
        ".Lf98746_00098a1f:\n"
        "movl 8(%edi), %eax\n" /* line 1068 | block */
        "cmpl %eax, %ebx\n" /* outerBlock */
        "jl .Lf98746_00098a2c\n"
        "addl $1, %eax\n" /* line 1070 */
        "movl %eax, 8(%edi)\n" /* block */
        ".Lf98746_00098a2c:\n"
        "cmpl %ebx, -0x58(%ebp)\n" /* line 1073 | outerBlock, j */
        "jge .Lf98746_00098a52\n"
        "leal (, %ebx, 4), %eax\n"
        "leal 0x14(%eax, %edi), %ecx\n"
        "leal 0x18(%eax, %edi), %edx\n"
        ".Lf98746_00098a40:\n"
        "subl $1, %ebx\n" /* line 1075 | outerBlock */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x58(%ebp)\n" /* line 1073 | outerBlock, j */
        "jl .Lf98746_00098a40\n"
        ".Lf98746_00098a52:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 1078 */
        "movl -0x4c(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "movl -0x58(%ebp), %edx\n" /* line 1079 | j */
        "sarl $3, %edx\n"
        "movl -0x58(%ebp), %ecx\n" /* j */
        "andl $7, %ecx\n"
        "movl 0x18(%ebp), %ebx\n" /* block, outerBlock */
        "movzbl 0x10(%edx, %ebx), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf98746_00098a80\n"
        "movl $1, %eax\n" /* line 1080 */
        "shll %cl, %eax\n"
        "orb %al, 0x10(%edx, %edi)\n"
        ".Lf98746_00098a80:\n"
        "addl $1, -0x58(%ebp)\n" /* line 1058 | j */
        "addl $4, -0x4c(%ebp)\n"
        "addl $4, -0x48(%ebp)\n"
        "jmp .Lf98746_000989c3\n"
        ".Lf98746_00098a91:\n"
        "cmpl $0x3f, %esi\n" /* line 894 | checksum */
        "jg .Lf98746_00098aa3\n"
        ".Lf98746_00098a96:\n"
        "leal 1(%ecx), %eax\n" /* line 1066 */
        "movl %eax, 0xc(%edi)\n" /* block */
        "movl %esi, %ebx\n" /* checksum, outerBlock */
        "jmp .Lf98746_00098a1f\n"
        ".Lf98746_00098aa3:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%edi), %ecx\n"
        "jmp .Lf98746_00098a96\n"
        /* { scope 3: removeCount */
        ".Lf98746_00098abc:\n"
        "movl -0x58(%ebp), %ebx\n" /* line 766 | j */
        "jmp .Lf98746_00098a1b\n"
        /* } scope */
        ".Lf98746_00098ac4:\n"
        "movl %eax, 4(%edi)\n" /* line 1084 | block */
        "movl $0, (%edi)\n" /* line 1085 | block */
        /* } scope */
        "movl 0x20(%ebp), %ebx\n" /* line 3229 | elseStatBlock, checksum */
        "movl (%ebx), %eax\n" /* checksum */
        "movl %eax, (%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* endSourcePos */
        "movl -0x7c(%ebp), %edx\n"
        "movl -0x84(%ebp), %eax\n"
        "calll EmitStatement\n"
        "movl 0x20(%ebp), %eax\n" /* line 3230 | elseStatBlock */
        "movl (%eax), %ebx\n" /* checksum */
        /* { scope 2 */
        "movl imp_scrVarPub, %edi\n" /* line 868 */
        "movl 0x3c(%edi), %esi\n" /* checksum */
        "movl -0x7c(%ebp), %eax\n" /* line 870 */
        "testl %eax, %eax\n"
        "jne .Lf98746_00098ca5\n"
        /* { scope 3: removeCount */
        /* { scope 4 */
        "movl (%ebx), %ecx\n" /* line 850 */
        "testl %ecx, %ecx\n"
        "je .Lf98746_00098c42\n"
        /* } scope */
        /* } scope */
        ".Lf98746_00098b09:\n"
        "leal 1(%esi), %eax\n" /* line 880 | checksum */
        "movl %eax, 0x3c(%edi)\n"
        /* } scope */
        "movl 0x20(%ebp), %ebx\n" /* line 3231 | elseStatBlock, checksum */
        "movl (%ebx), %eax\n" /* checksum */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf98746_00098b27\n"
        "movl -0x68(%ebp), %edx\n" /* line 3233 | childCount */
        "movl %eax, -0x20(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 3234 */
        "movl %edx, -0x68(%ebp)\n" /* childCount */
        ".Lf98746_00098b27:\n"
        "cmpb $0, -0x85(%ebp)\n" /* line 3237 | lastStatement */
        "je .Lf98746_00098cc8\n"
        /* { scope 2 */
        ".Lf98746_00098b34:\n"
        "movl -0x68(%ebp), %eax\n" /* line 939 | childCount */
        "testl %eax, %eax\n"
        "je .Lf98746_00098bd3\n"
        "movl -0x20(%ebp), %eax\n" /* line 942 | childBlocks */
        "movl 8(%eax), %edi\n" /* localVarsCreateCount */
        "cmpl $1, -0x68(%ebp)\n" /* line 943 | childCount */
        "jle .Lf98746_00098b64\n"
        "movl $1, %edx\n"
        ".Lf98746_00098b50:\n"
        "movl -0x20(%ebp, %edx, 4), %eax\n" /* line 946 */
        "movl 8(%eax), %eax\n"
        "cmpl %eax, %edi\n" /* localVarsCreateCount */
        "cmovgl %eax, %edi\n" /* localVarsCreateCount */
        "addl $1, %edx\n" /* line 943 */
        "cmpl %edx, -0x68(%ebp)\n" /* childCount */
        "jne .Lf98746_00098b50\n"
        ".Lf98746_00098b64:\n"
        "movl 0x18(%ebp), %eax\n" /* line 952 | block */
        "movl %edi, 4(%eax)\n" /* localVarsCreateCount */
        "testl %edi, %edi\n" /* line 954 | localVarsCreateCount */
        "jle .Lf98746_00098bd3\n"
        "movl $0, -0x50(%ebp)\n" /* i */
        ".Lf98746_00098b75:\n"
        "movl -0x50(%ebp), %ebx\n" /* line 957 | i, outerBlock */
        "sarl $3, %ebx\n" /* outerBlock */
        "movl 0x18(%ebp), %edx\n" /* block */
        "movzbl 0x10(%ebx, %edx), %esi\n" /* outerBlock, checksum */
        "movl -0x50(%ebp), %ecx\n" /* i */
        "andl $7, %ecx\n"
        "movl %esi, %edx\n" /* checksum */
        "movzbl %dl, %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf98746_00098bca\n"
        "movl -0x68(%ebp), %eax\n" /* line 960 | childCount */
        "testl %eax, %eax\n"
        "jle .Lf98746_00098c81\n"
        "movl -0x20(%ebp), %eax\n" /* line 966 | childBlocks */
        "movzbl 0x10(%ebx, %eax), %eax\n" /* outerBlock */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf98746_00098bca\n"
        "xorl %edx, %edx\n" /* line 967 */
        ".Lf98746_00098baf:\n"
        "addl $1, %edx\n" /* line 960 */
        "cmpl %edx, -0x68(%ebp)\n" /* childCount */
        "je .Lf98746_00098c81\n"
        "movl -0x20(%ebp, %edx, 4), %eax\n" /* line 966 */
        "movzbl 0x10(%ebx, %eax), %eax\n" /* outerBlock */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf98746_00098baf\n"
        ".Lf98746_00098bca:\n"
        "addl $1, -0x50(%ebp)\n" /* line 954 | i */
        "cmpl -0x50(%ebp), %edi\n" /* i, localVarsCreateCount */
        "jne .Lf98746_00098b75\n"
        /* } scope */
        /* } scope */
        ".Lf98746_00098bd3:\n"
        "addl $0x8c, %esp\n" /* line 3241 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: constValue, j, j, i */
        ".Lf98746_00098bde:\n"
        "xorl %ecx, %ecx\n" /* line 3215 */
        "xorl %edx, %edx\n"
        "movl $0x62, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 3216 */
        "movl 0xc(%ebp), %eax\n" /* elseSourcePos */
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl $0, (%eax)\n" /* line 596 */
        "movl scrCompileGlob, %edx\n" /* line 3218 */
        "movl %edx, -0x74(%ebp)\n" /* pos2 */
        "movl $0, (%esp)\n" /* line 3219 */
        "calll TempMalloc\n"
        "movl %eax, -0x6c(%ebp)\n" /* nextPos2 */
        "jmp .Lf98746_0009898e\n"
        ".Lf98746_00098c33:\n"
        "movl %ebx, -0x20(%ebp)\n" /* line 3199 | checksum, childBlocks */
        "movl $1, -0x68(%ebp)\n" /* childCount */
        "jmp .Lf98746_00098936\n"
        /* { scope 2 */
        /* { scope 3: removeCount */
        /* { scope 4 */
        ".Lf98746_00098c42:\n"
        "movl 4(%ebx), %eax\n" /* line 854 */
        "subl 8(%ebx), %eax\n" /* line 856 */
        "movl %eax, -0x54(%ebp)\n" /* removeCount */
        "je .Lf98746_00098b09\n"
        "xorl %ecx, %ecx\n" /* line 858 */
        "xorl %edx, %edx\n"
        "movl $0x17, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movzbl -0x54(%ebp), %edx\n" /* line 617 | removeCount */
        "movb %dl, (%eax)\n"
        "movl 8(%ebx), %eax\n" /* line 860 */
        "movl %eax, 4(%ebx)\n"
        "jmp .Lf98746_00098b09\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf98746_00098c81:\n"
        "movl $1, %eax\n" /* line 969 */
        "shll %cl, %eax\n"
        "orl %eax, %esi\n" /* checksum */
        "movl %esi, %eax\n" /* checksum */
        "movl 0x18(%ebp), %edx\n" /* block */
        "movb %al, 0x10(%ebx, %edx)\n" /* outerBlock */
        "addl $1, -0x50(%ebp)\n" /* line 954 | i */
        "cmpl -0x50(%ebp), %edi\n" /* i, localVarsCreateCount */
        "jne .Lf98746_00098b75\n"
        "jmp .Lf98746_00098bd3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf98746_00098ca5:\n"
        "xorl %ecx, %ecx\n" /* line 577 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 873 */
        "movl 0x14(%ebp), %edx\n" /* endSourcePos */
        "movl %edx, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf98746_00098b09\n"
        /* } scope */
        ".Lf98746_00098cc8:\n"
        "movl $0, (%esp)\n" /* line 3238 */
        "calll TempMalloc\n"
        "subl -0x6c(%ebp), %eax\n" /* nextPos2 */
        "movl -0x74(%ebp), %ebx\n" /* pos2, checksum */
        "movl %eax, (%ebx)\n" /* checksum */
        "jmp .Lf98746_00098b34\n"
        /* { scope 2 */
        ".Lf98746_00098ce1:\n"
        "movl %ebx, %eax\n" /* line 2885 | outerBlock */
        "calll EmitValue\n"
        "jmp .Lf98746_0009877a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf98746_00098ced:\n"
        "xorl %ecx, %ecx\n" /* line 858 */
        "xorl %edx, %edx\n"
        "movl $0x17, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movl %esi, %edx\n" /* line 617 */
        "movb %dl, (%eax)\n"
        "movl 8(%ebx), %eax\n" /* line 860 */
        "movl %eax, 4(%ebx)\n"
        "movl 0x1c(%ebp), %eax\n" /* ifStatBlock */
        "movl (%eax), %ebx\n"
        "jmp .Lf98746_00098925\n"
    );
}

/* line 3308 */
static __attribute__((naked))
unsigned int EmitWhileStatement(sval_t expr, sval_t stmt, sval_t sourcePos, sval_t whileSourcePos, scr_block_t *block, sval_t *whileStatBlock)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3308 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %eax, -0x80(%ebp)\n" /* whileSourcePos */
        "movl %edx, -0x84(%ebp)\n"
        "movl %ecx, -0x88(%ebp)\n"
        /* { scope 1: j, i, childCount */
        "movzbl scrCompileGlob+44, %eax\n" /* line 3330 */
        "movb %al, -0x72(%ebp)\n" /* bOldCanBreak */
        "movzbl scrCompileGlob+45, %edx\n" /* line 3331 */
        "movb %dl, -0x71(%ebp)\n" /* bOldCanIgnoreBreak */
        "movl scrCompileGlob+48, %ecx\n" /* line 3332 */
        "movl %ecx, -0x70(%ebp)\n" /* oldBreakStatement */
        "movb $0, scrCompileGlob+44\n" /* line 3333 */
        "movb $0, scrCompileGlob+45\n" /* line 3334 */
        "movzbl scrCompileGlob+52, %ebx\n" /* line 3336 */
        "movb %bl, -0x6a(%ebp)\n" /* bOldCanContinue */
        "movzbl scrCompileGlob+53, %eax\n" /* line 3337 */
        "movb %al, -0x69(%ebp)\n" /* bOldCanIgnoreContinue */
        "movl scrCompileGlob+56, %edx\n" /* line 3338 */
        "movl %edx, -0x68(%ebp)\n" /* oldContinueStatement */
        "movb $0, scrCompileGlob+52\n" /* line 3339 */
        "movb $0, scrCompileGlob+53\n" /* line 3340 */
        "movl 0x10(%ebp), %ecx\n" /* line 3342 | whileStatBlock */
        "movl (%ecx), %edi\n" /* constConditional */
        "movl %edi, -0x30(%ebp)\n" /* constConditional */
        "movl 0xc(%ebp), %ebx\n" /* block */
        "addl $0x18, %ebx\n"
        "movl %ebx, -0x2c(%ebp)\n"
        "movl $0, -0x48(%ebp)\n" /* j */
        /* { scope 2: i, bConstRefCount */
        ".Lf98d20_00098da9:\n"
        "movl -0x48(%ebp), %esi\n" /* line 1058 | j */
        "cmpl 8(%edi), %esi\n" /* stringValue */
        "jl .Lf98d20_00098dbf\n"
        "movl 0xc(%ebp), %edx\n" /* block */
        "movl 4(%edx), %eax\n"
        "cmpl %eax, %esi\n"
        "jge .Lf98d20_00098eaa\n"
        /* } scope */
        ".Lf98d20_00098dbf:\n"
        "movl -0x2c(%ebp), %esi\n" /* line 1060 */
        "movl (%esi), %esi\n"
        "movl %esi, -0x4c(%ebp)\n"
        /* { scope 2: i, bConstRefCount */
        "movl 0xc(%edi), %esi\n" /* line 764 | stringValue */
        "movl %esi, %ecx\n"
        "cmpl %esi, -0x48(%ebp)\n" /* j */
        "jge .Lf98d20_00098e77\n"
        "movl -0x4c(%ebp), %eax\n" /* line 766 */
        "movl -0x30(%ebp), %ebx\n"
        "cmpl 0x18(%ebx), %eax\n"
        "je .Lf98d20_00098ea2\n"
        "movl -0x48(%ebp), %ebx\n" /* j */
        "leal 0x18(%edi, %ebx, 4), %edx\n" /* stringValue */
        ".Lf98d20_00098deb:\n"
        "addl $1, %ebx\n" /* line 764 */
        "cmpl %ebx, %esi\n"
        "je .Lf98d20_00098e77\n"
        "movl 4(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0x4c(%ebp)\n"
        "jne .Lf98d20_00098deb\n"
        ".Lf98d20_00098e01:\n"
        "testl %ebx, %ebx\n" /* line 1062 */
        "js .Lf98d20_00098e77\n"
        ".Lf98d20_00098e05:\n"
        "movl 8(%edi), %eax\n" /* line 1068 | stringValue */
        "cmpl %eax, %ebx\n"
        "jl .Lf98d20_00098e12\n"
        "addl $1, %eax\n" /* line 1070 */
        "movl %eax, 8(%edi)\n" /* stringValue */
        ".Lf98d20_00098e12:\n"
        "cmpl %ebx, -0x48(%ebp)\n" /* line 1073 | j */
        "jge .Lf98d20_00098e38\n"
        "leal (, %ebx, 4), %eax\n"
        "leal 0x14(%eax, %edi), %ecx\n"
        "leal 0x18(%eax, %edi), %edx\n"
        ".Lf98d20_00098e26:\n"
        "subl $1, %ebx\n" /* line 1075 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x48(%ebp)\n" /* line 1073 | j */
        "jl .Lf98d20_00098e26\n"
        ".Lf98d20_00098e38:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 1078 */
        "movl -0x30(%ebp), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "movl -0x48(%ebp), %edx\n" /* line 1079 | j */
        "sarl $3, %edx\n"
        "movl -0x48(%ebp), %ecx\n" /* j */
        "andl $7, %ecx\n"
        "movl 0xc(%ebp), %ebx\n" /* block */
        "movzbl 0x10(%edx, %ebx), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf98d20_00098e66\n"
        "movl $1, %eax\n" /* line 1080 */
        "shll %cl, %eax\n"
        "orb %al, 0x10(%edx, %edi)\n"
        ".Lf98d20_00098e66:\n"
        "addl $1, -0x48(%ebp)\n" /* line 1058 | j */
        "addl $4, -0x30(%ebp)\n"
        "addl $4, -0x2c(%ebp)\n"
        "jmp .Lf98d20_00098da9\n"
        ".Lf98d20_00098e77:\n"
        "cmpl $0x3f, %esi\n" /* line 894 */
        "jg .Lf98d20_00098e89\n"
        ".Lf98d20_00098e7c:\n"
        "leal 1(%ecx), %eax\n" /* line 1066 */
        "movl %eax, 0xc(%edi)\n" /* stringValue */
        "movl %esi, %ebx\n"
        "jmp .Lf98d20_00098e05\n"
        ".Lf98d20_00098e89:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%edi), %ecx\n" /* stringValue */
        "jmp .Lf98d20_00098e7c\n"
        ".Lf98d20_00098ea2:\n"
        "movl -0x48(%ebp), %ebx\n" /* line 766 | j */
        "jmp .Lf98d20_00098e01\n"
        ".Lf98d20_00098eaa:\n"
        "movl %eax, 4(%edi)\n" /* line 1084 | stringValue */
        "movl $0, (%edi)\n" /* line 1085 | stringValue */
        /* } scope */
        "movl 0x10(%ebp), %ecx\n" /* line 3343 | whileStatBlock */
        "movl (%ecx), %esi\n" /* pos2 */
        /* { scope 2: i, bConstRefCount */
        "movl 4(%esi), %ebx\n" /* line 830 */
        "movl %ebx, -0x44(%ebp)\n" /* i */
        "movl 8(%esi), %eax\n"
        "cmpl %eax, %ebx\n"
        "je .Lf98d20_00098ed3\n"
        "jl .Lf98d20_0009925a\n" /* line 833 */
        ".Lf98d20_00098ecb:\n"
        "movl %eax, 4(%esi)\n" /* line 842 */
        "movl 0x10(%ebp), %ebx\n" /* whileStatBlock */
        "movl (%ebx), %esi\n"
        /* } scope */
        ".Lf98d20_00098ed3:\n"
        "movl 4(%esi), %eax\n" /* line 3345 | pos2 */
        "movl 0xc(%ebp), %esi\n" /* block, pos2 */
        "movl %eax, 4(%esi)\n" /* pos2 */
        "movl $0, (%esp)\n" /* line 3347 */
        "calll TempMalloc\n"
        "movl %eax, -0x7c(%ebp)\n" /* pos1 */
        "leal -0x28(%ebp), %ebx\n" /* line 3350 | constValue */
        "movl %esi, %ecx\n" /* pos2 */
        "movl %ebx, %edx\n"
        "movl -0x80(%ebp), %eax\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "je .Lf98d20_00098f14\n"
        "movl -0x24(%ebp), %eax\n" /* line 3352 */
        "subl $5, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf98d20_0009932d\n"
        "movl %ebx, %eax\n" /* line 3361 */
        "calll EmitValue\n"
        ".Lf98d20_00098f14:\n"
        "xorl %edi, %edi\n" /* constConditional */
        ".Lf98d20_00098f16:\n"
        "movl scrCompileGlob+60, %edx\n" /* line 3365 */
        "movl %edx, -0x64(%ebp)\n" /* oldBreakChildBlocks */
        "movl scrCompileGlob+64, %ecx\n" /* line 3366 */
        "movl %ecx, -0x60(%ebp)\n" /* oldBreakChildCount */
        "movl scrCompileGlob+68, %ebx\n" /* line 3367 */
        "movl %ebx, -0x50(%ebp)\n" /* oldBreakBlock */
        "movl scrCompileGlob+72, %esi\n" /* line 3369 | pos2 */
        "movl %esi, -0x58(%ebp)\n" /* pos2, oldContinueChildBlocks */
        "movl scrCompileGlob+76, %eax\n" /* line 3370 */
        "movl %eax, -0x54(%ebp)\n" /* oldContinueChildCount */
        "movl $0, -0x1c(%ebp)\n" /* line 3372 | breakChildCount */
        "movl $0, scrCompileGlob+72\n" /* line 3374 */
        "movl 0x10(%ebp), %edx\n" /* line 3376 | whileStatBlock */
        "movl (%edx), %eax\n"
        "movl %eax, scrCompileGlob+68\n"
        "movl %edi, %ecx\n" /* line 3378 | constConditional */
        "testb %cl, %cl\n"
        "jne .Lf98d20_00099235\n"
        "xorl %ecx, %ecx\n" /* line 3380 */
        "movl $0xffffffff, %edx\n"
        "movl $0x5e, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3381 */
        "movl -0x88(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw $0, (%eax)\n" /* line 610 */
        "movl scrCompileGlob, %esi\n" /* line 3383 | pos2 */
        "movl $0, (%esp)\n" /* line 3384 */
        "calll TempMalloc\n"
        "movl %eax, -0x78(%ebp)\n" /* nextPos2 */
        "movl $0, -0x5c(%ebp)\n" /* breakChildBlocks */
        ".Lf98d20_00098fc0:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 3397 | breakChildBlocks */
        "movl %eax, scrCompileGlob+60\n"
        "movb $1, scrCompileGlob+44\n" /* line 3399 */
        "movl scrCompilePub+40, %eax\n" /* line 3400 */
        "testl %eax, %eax\n"
        "setne %al\n"
        "movb %al, scrCompileGlob+45\n"
        "movl $0, scrCompileGlob+48\n" /* line 3401 */
        "movb $1, scrCompileGlob+52\n" /* line 3403 */
        "movb %al, scrCompileGlob+53\n" /* line 3404 */
        "movl $0, scrCompileGlob+56\n" /* line 3405 */
        "movl 0x10(%ebp), %edx\n" /* line 3407 | whileStatBlock */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "movl -0x84(%ebp), %eax\n"
        "calll EmitStatement\n"
        "movl 0x10(%ebp), %ecx\n" /* line 3409 | whileStatBlock */
        "movl (%ecx), %eax\n"
        "cmpl $3, (%eax)\n"
        "je .Lf98d20_00099027\n"
        "movl $0, (%eax)\n" /* line 3410 */
        ".Lf98d20_00099027:\n"
        "movb $0, scrCompileGlob+44\n" /* line 3412 */
        "movb $0, scrCompileGlob+45\n" /* line 3413 */
        "movb $0, scrCompileGlob+52\n" /* line 3415 */
        "movb $0, scrCompileGlob+53\n" /* line 3416 */
        "movl $0, (%esp)\n" /* line 3032 */
        "calll TempMalloc\n"
        "movl %eax, %ebx\n"
        "movl scrCompileGlob+56, %ecx\n" /* line 3033 */
        "testl %ecx, %ecx\n" /* line 3035 */
        "je .Lf98d20_0009906b\n"
        ".Lf98d20_0009905b:\n"
        "movl (%ecx), %edx\n" /* line 3037 */
        "movl %ebx, %eax\n"
        "subl 4(%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 8(%ecx), %ecx\n" /* line 3038 */
        "testl %ecx, %ecx\n" /* line 3035 */
        "jne .Lf98d20_0009905b\n"
        ".Lf98d20_0009906b:\n"
        "xorl %ecx, %ecx\n" /* line 3420 */
        "xorl %edx, %edx\n"
        "movl $0x63, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3421 */
        "movl 8(%ebp), %eax\n" /* whileSourcePos */
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl -0x84(%ebp), %ebx\n" /* line 3422 */
        "cmpl $0x2c, (%ebx)\n"
        "je .Lf98d20_00099346\n"
        ".Lf98d20_0009909b:\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw $0, (%eax)\n" /* line 610 */
        "movl $0, (%esp)\n" /* line 3426 */
        "calll TempMalloc\n"
        "subl -0x7c(%ebp), %eax\n" /* line 3428 | pos1 */
        "movl scrCompileGlob, %edx\n"
        "movw %ax, (%edx)\n"
        "testl %esi, %esi\n" /* line 3429 | pos2 */
        "je .Lf98d20_000990df\n"
        "movl $0, (%esp)\n" /* line 3431 */
        "calll TempMalloc\n"
        "subl -0x78(%ebp), %eax\n" /* line 3433 | nextPos2 */
        "movw %ax, (%esi)\n" /* pos2 */
        ".Lf98d20_000990df:\n"
        "movl $0, (%esp)\n" /* line 3016 */
        "calll TempMalloc\n"
        "movl %eax, %ebx\n"
        "movl scrCompileGlob+48, %ecx\n" /* line 3017 */
        "testl %ecx, %ecx\n" /* line 3019 */
        "je .Lf98d20_00099107\n"
        ".Lf98d20_000990f7:\n"
        "movl (%ecx), %edx\n" /* line 3021 */
        "movl %ebx, %eax\n"
        "subl 4(%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 8(%ecx), %ecx\n" /* line 3022 */
        "testl %ecx, %ecx\n" /* line 3019 */
        "jne .Lf98d20_000990f7\n"
        ".Lf98d20_00099107:\n"
        "movzbl -0x72(%ebp), %eax\n" /* line 3438 | bOldCanBreak */
        "movb %al, scrCompileGlob+44\n"
        "movzbl -0x71(%ebp), %edx\n" /* line 3439 | bOldCanIgnoreBreak */
        "movb %dl, scrCompileGlob+45\n"
        "movl -0x70(%ebp), %ecx\n" /* line 3440 | oldBreakStatement */
        "movl %ecx, scrCompileGlob+48\n"
        "movzbl -0x6a(%ebp), %ebx\n" /* line 3442 | bOldCanContinue */
        "movb %bl, scrCompileGlob+52\n"
        "movzbl -0x69(%ebp), %eax\n" /* line 3443 | bOldCanIgnoreContinue */
        "movb %al, scrCompileGlob+53\n"
        "movl -0x68(%ebp), %edx\n" /* line 3444 | oldContinueStatement */
        "movl %edx, scrCompileGlob+56\n"
        "movl %edi, %ecx\n" /* line 3446 | constConditional */
        "testb %cl, %cl\n"
        "je .Lf98d20_000991fe\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 3447 | breakChildCount */
        "movl %ebx, -0x3c(%ebp)\n" /* childCount */
        /* { scope 2: i, bConstRefCount */
        /* { scope 3 */
        "testl %ebx, %ebx\n" /* line 939 */
        "je .Lf98d20_000991fe\n"
        "movl -0x5c(%ebp), %esi\n" /* line 942 | breakChildBlocks */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %edi\n" /* stringValue */
        "subl $1, %ebx\n" /* line 943 */
        "jle .Lf98d20_00099181\n"
        "movl $1, %edx\n"
        "movl -0x5c(%ebp), %ecx\n" /* breakChildBlocks */
        ".Lf98d20_0009916e:\n"
        "movl (%ecx, %edx, 4), %eax\n" /* line 946 */
        "movl 8(%eax), %eax\n"
        "cmpl %edi, %eax\n" /* stringValue */
        "cmovll %eax, %edi\n" /* stringValue */
        "addl $1, %edx\n" /* line 943 */
        "cmpl %edx, -0x3c(%ebp)\n" /* childCount */
        "jne .Lf98d20_0009916e\n"
        ".Lf98d20_00099181:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 952 | block */
        "movl %edi, 4(%ebx)\n" /* stringValue */
        "testl %edi, %edi\n" /* line 954 | stringValue */
        "jle .Lf98d20_000991fe\n"
        "movl $0, -0x38(%ebp)\n" /* i */
        ".Lf98d20_00099192:\n"
        "movl -0x38(%ebp), %ebx\n" /* line 957 | i */
        "sarl $3, %ebx\n"
        "movl 0xc(%ebp), %eax\n" /* block */
        "movzbl 0x10(%ebx, %eax), %eax\n"
        "movb %al, -0x99(%ebp)\n"
        "movl -0x38(%ebp), %ecx\n" /* i */
        "andl $7, %ecx\n"
        "movzbl %al, %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf98d20_000991f5\n"
        "movl -0x3c(%ebp), %eax\n" /* line 960 | childCount */
        "testl %eax, %eax\n"
        "jle .Lf98d20_000992f3\n"
        "movl -0x5c(%ebp), %edx\n" /* line 966 | breakChildBlocks */
        "movl (%edx), %eax\n"
        "movzbl 0x10(%ebx, %eax), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf98d20_000991f5\n"
        "xorl %edx, %edx\n" /* line 967 */
        ".Lf98d20_000991d2:\n"
        "addl $1, %edx\n" /* line 960 */
        "cmpl %edx, -0x3c(%ebp)\n" /* childCount */
        "je .Lf98d20_000992f3\n"
        "movl -0x5c(%ebp), %esi\n" /* line 966 | breakChildBlocks */
        "movl (%esi, %edx, 4), %esi\n"
        "movl %esi, -0x8c(%ebp)\n"
        "movzbl 0x10(%ebx, %esi), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf98d20_000991d2\n"
        ".Lf98d20_000991f5:\n"
        "addl $1, -0x38(%ebp)\n" /* line 954 | i */
        "cmpl %edi, -0x38(%ebp)\n" /* stringValue, i */
        "jne .Lf98d20_00099192\n"
        /* } scope */
        /* } scope */
        ".Lf98d20_000991fe:\n"
        "movl -0x64(%ebp), %ecx\n" /* line 3449 | oldBreakChildBlocks */
        "movl %ecx, scrCompileGlob+60\n"
        "movl -0x60(%ebp), %ebx\n" /* line 3450 | oldBreakChildCount */
        "movl %ebx, scrCompileGlob+64\n"
        "movl -0x50(%ebp), %esi\n" /* line 3451 | oldBreakBlock, pos2 */
        "movl %esi, scrCompileGlob+68\n" /* pos2 */
        "movl -0x58(%ebp), %eax\n" /* line 3453 | oldContinueChildBlocks */
        "movl %eax, scrCompileGlob+72\n"
        "movl -0x54(%ebp), %edx\n" /* line 3454 | oldContinueChildCount */
        "movl %edx, scrCompileGlob+76\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 3455 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: j, i, childCount */
        ".Lf98d20_00099235:\n"
        "movl $__mh_execute_header, (%esp)\n" /* line 3393 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, -0x5c(%ebp)\n" /* breakChildBlocks */
        "leal -0x1c(%ebp), %eax\n" /* line 3394 | breakChildCount */
        "movl %eax, scrCompileGlob+64\n"
        "xorl %esi, %esi\n" /* pos2 */
        "movl $0, -0x78(%ebp)\n" /* nextPos2 */
        "jmp .Lf98d20_00098fc0\n"
        /* { scope 2: i, bConstRefCount */
        ".Lf98d20_0009925a:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 833 | i */
        "leal 0x18(%esi, %ecx, 4), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n"
        "jmp .Lf98d20_000992a2\n"
        /* { scope 3 */
        ".Lf98d20_00099266:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 233 */
        "jne .Lf98d20_00099320\n"
        ".Lf98d20_00099273:\n"
        "movl scrCompileGlob, %ebx\n" /* line 236 */
        "movl %edi, (%esp)\n" /* stringValue */
        "calll SL_TransferToCanonicalString\n"
        "movw %ax, (%ebx)\n"
        ".Lf98d20_00099284:\n"
        "movzbl -0x3d(%ebp), %ecx\n" /* line 247 | bConstRefCount */
        "movb %cl, scrCompileGlob+28\n"
        /* } scope */
        "addl $1, -0x44(%ebp)\n" /* line 833 | i */
        "movl 8(%esi), %eax\n"
        "addl $4, -0x34(%ebp)\n"
        "cmpl %eax, -0x44(%ebp)\n" /* i */
        "jge .Lf98d20_00098ecb\n"
        ".Lf98d20_000992a2:\n"
        "xorl %ecx, %ecx\n" /* line 835 */
        "xorl %edx, %edx\n"
        "movl $0x16, %eax\n"
        "calll EmitOpcode\n"
        "movl -0x34(%ebp), %eax\n" /* line 836 */
        "movl (%eax), %edi\n" /* stringValue */
        /* { scope 3 */
        "movzbl scrCompileGlob+28, %edx\n" /* line 244 */
        "movb %dl, -0x3d(%ebp)\n" /* bConstRefCount */
        "movb $1, scrCompileGlob+28\n" /* line 245 */
        "movl $2, (%esp)\n" /* line 214 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "cmpl $2, scrCompilePub+40\n" /* line 216 */
        "jne .Lf98d20_00099266\n"
        /* { scope 4 */
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf98d20_00099284\n"
        "movl %edi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf98d20_00099284\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, bConstRefCount */
        /* { scope 3 */
        ".Lf98d20_000992f3:\n"
        "movl $1, %eax\n" /* line 969 */
        "shll %cl, %eax\n"
        "orb %al, -0x99(%ebp)\n"
        "movzbl -0x99(%ebp), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* block */
        "movb %al, 0x10(%ebx, %edx)\n"
        "addl $1, -0x38(%ebp)\n" /* line 954 | i */
        "cmpl %edi, -0x38(%ebp)\n" /* stringValue, i */
        "jne .Lf98d20_00099192\n"
        "jmp .Lf98d20_000991fe\n"
        /* } scope */
        /* } scope */
        /* { scope 2: i, bConstRefCount */
        /* { scope 3 */
        ".Lf98d20_00099320:\n"
        "movl %edi, (%esp)\n" /* line 234 | stringValue */
        "calll SL_AddRefToString\n"
        "jmp .Lf98d20_00099273\n"
        /* } scope */
        /* } scope */
        ".Lf98d20_0009932d:\n"
        "movl %ebx, (%esp)\n" /* line 3354 */
        "calll Scr_CastBool\n"
        "movl -0x28(%ebp), %eax\n" /* line 3355 | constValue */
        "testl %eax, %eax\n"
        "je .Lf98d20_0009935e\n"
        "movl $1, %edi\n" /* line 3356 | constConditional */
        "jmp .Lf98d20_00098f16\n"
        ".Lf98d20_00099346:\n"
        "movl $1, 4(%esp)\n" /* line 3423 */
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf98d20_0009909b\n"
        ".Lf98d20_0009935e:\n"
        "movl $str_0021da90, 4(%esp)\n" /* line 3356 */
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "movl $1, %edi\n" /* constConditional */
        "jmp .Lf98d20_00098f16\n"
    );
}

/* line 3532 */
static __attribute__((naked))
unsigned int EmitForStatement(sval_t expr, sval_t stmt2, sval_t stmt, sval_t sourcePos, sval_t forSourcePos, scr_block_t *block, sval_t *forStatBlock, sval_t *forStatPostBlock)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3532 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "movl %edx, -0xb8(%ebp)\n"
        "movl %ecx, -0xbc(%ebp)\n"
        /* { scope 1: j, i, j, childCount, ... */
        "movzbl scrCompileGlob+44, %edx\n" /* line 3556 */
        "movb %dl, -0xa6(%ebp)\n" /* bOldCanBreak */
        "movzbl scrCompileGlob+45, %ecx\n" /* line 3557 */
        "movb %cl, -0xa5(%ebp)\n" /* bOldCanIgnoreBreak */
        "movl scrCompileGlob+48, %ebx\n" /* line 3558 */
        "movl %ebx, -0xa4(%ebp)\n" /* oldBreakStatement */
        "movb $0, scrCompileGlob+44\n" /* line 3559 */
        "movb $0, scrCompileGlob+45\n" /* line 3560 */
        "movzbl scrCompileGlob+52, %edx\n" /* line 3562 */
        "movb %dl, -0x9e(%ebp)\n" /* bOldCanContinue */
        "movzbl scrCompileGlob+53, %ecx\n" /* line 3563 */
        "movb %cl, -0x9d(%ebp)\n" /* bOldCanIgnoreContinue */
        "movl scrCompileGlob+56, %ebx\n" /* line 3564 */
        "movl %ebx, -0x9c(%ebp)\n" /* oldContinueStatement */
        "movb $0, scrCompileGlob+52\n" /* line 3565 */
        "movb $0, scrCompileGlob+53\n" /* line 3566 */
        "movl 0x14(%ebp), %esi\n" /* line 3568 | block */
        "movl %esi, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "calll EmitStatement\n"
        "movl 0x18(%ebp), %eax\n" /* line 3570 | forStatBlock, stmt1 */
        "movl (%eax), %edi\n" /* stmt1, block */
        "movl %edi, -0x44(%ebp)\n" /* block */
        "addl $0x18, %esi\n" /* line 3532 */
        "movl %esi, -0x3c(%ebp)\n"
        "movl %esi, -0x40(%ebp)\n"
        "movl $0, -0x74(%ebp)\n" /* j */
        /* { scope 2: i, i, bConstRefCount */
        ".Lf9937e_00099425:\n"
        "movl -0x74(%ebp), %eax\n" /* line 1058 | j */
        "cmpl 8(%edi), %eax\n" /* stringValue */
        "jl .Lf9937e_0009943c\n"
        "movl 0x14(%ebp), %edx\n" /* block */
        "movl 4(%edx), %eax\n"
        "cmpl %eax, -0x74(%ebp)\n" /* j */
        "jge .Lf9937e_00099524\n"
        /* } scope */
        ".Lf9937e_0009943c:\n"
        "movl -0x40(%ebp), %edx\n" /* line 1060 */
        "movl (%edx), %edx\n"
        "movl %edx, -0x78(%ebp)\n"
        /* { scope 2: i, i, bConstRefCount */
        /* { scope 3 */
        "movl 0xc(%edi), %esi\n" /* line 764 | stringValue */
        "movl %esi, %ecx\n"
        "cmpl %esi, -0x74(%ebp)\n" /* j */
        "jge .Lf9937e_000994f1\n"
        "movl -0x44(%ebp), %eax\n" /* line 766 */
        "cmpl 0x18(%eax), %edx\n"
        "je .Lf9937e_0009951c\n"
        "movl -0x74(%ebp), %ebx\n" /* j */
        "leal 0x18(%edi, %ebx, 4), %edx\n" /* stringValue */
        ".Lf9937e_00099465:\n"
        "addl $1, %ebx\n" /* line 764 */
        "cmpl %esi, %ebx\n"
        "je .Lf9937e_000994f1\n"
        "movl 4(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0x78(%ebp)\n"
        "jne .Lf9937e_00099465\n"
        /* } scope */
        ".Lf9937e_0009947b:\n"
        "testl %ebx, %ebx\n" /* line 1062 */
        "js .Lf9937e_000994f1\n"
        ".Lf9937e_0009947f:\n"
        "movl 8(%edi), %eax\n" /* line 1068 | block */
        "cmpl %eax, %ebx\n"
        "jl .Lf9937e_0009948c\n"
        "addl $1, %eax\n" /* line 1070 */
        "movl %eax, 8(%edi)\n" /* block */
        ".Lf9937e_0009948c:\n"
        "cmpl %ebx, -0x74(%ebp)\n" /* line 1073 | j */
        "jge .Lf9937e_000994b2\n"
        "leal (, %ebx, 4), %eax\n"
        "leal 0x14(%eax, %edi), %ecx\n"
        "leal 0x18(%eax, %edi), %edx\n"
        ".Lf9937e_000994a0:\n"
        "subl $1, %ebx\n" /* line 1075 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x74(%ebp)\n" /* line 1073 | j */
        "jl .Lf9937e_000994a0\n"
        ".Lf9937e_000994b2:\n"
        "movl -0x78(%ebp), %ebx\n" /* line 1078 */
        "movl -0x44(%ebp), %ecx\n"
        "movl %ebx, 0x18(%ecx)\n"
        "movl -0x74(%ebp), %edx\n" /* line 1079 | j */
        "sarl $3, %edx\n"
        "movl -0x74(%ebp), %ecx\n" /* j */
        "andl $7, %ecx\n"
        "movl 0x14(%ebp), %esi\n" /* block */
        "movzbl 0x10(%edx, %esi), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf9937e_000994e0\n"
        "movl $1, %eax\n" /* line 1080 */
        "shll %cl, %eax\n"
        "orb %al, 0x10(%edx, %edi)\n"
        ".Lf9937e_000994e0:\n"
        "addl $1, -0x74(%ebp)\n" /* line 1058 | j */
        "addl $4, -0x44(%ebp)\n"
        "addl $4, -0x40(%ebp)\n"
        "jmp .Lf9937e_00099425\n"
        ".Lf9937e_000994f1:\n"
        "cmpl $0x3f, %esi\n" /* line 894 */
        "jg .Lf9937e_00099503\n"
        ".Lf9937e_000994f6:\n"
        "leal 1(%ecx), %eax\n" /* line 1066 */
        "movl %eax, 0xc(%edi)\n" /* block */
        "movl %esi, %ebx\n"
        "jmp .Lf9937e_0009947f\n"
        ".Lf9937e_00099503:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%edi), %ecx\n" /* stringValue */
        "jmp .Lf9937e_000994f6\n"
        /* { scope 3 */
        ".Lf9937e_0009951c:\n"
        "movl -0x74(%ebp), %ebx\n" /* line 766 | j */
        "jmp .Lf9937e_0009947b\n"
        /* } scope */
        ".Lf9937e_00099524:\n"
        "movl %eax, 4(%edi)\n" /* line 1084 | block */
        "movl $0, (%edi)\n" /* line 1085 | block */
        /* } scope */
        "movl 0x18(%ebp), %ecx\n" /* line 3571 | forStatBlock */
        "movl (%ecx), %esi\n"
        /* { scope 2: i, i, bConstRefCount */
        "movl 4(%esi), %ebx\n" /* line 830 */
        "movl %ebx, -0x70(%ebp)\n" /* i */
        "movl 8(%esi), %eax\n"
        "cmpl %eax, %ebx\n"
        "je .Lf9937e_0009954d\n"
        "jl .Lf9937e_00099b8c\n" /* line 833 */
        ".Lf9937e_00099545:\n"
        "movl %eax, 4(%esi)\n" /* line 842 */
        "movl 0x18(%ebp), %ebx\n" /* forStatBlock */
        "movl (%ebx), %esi\n"
        /* } scope */
        ".Lf9937e_0009954d:\n"
        "movl 4(%esi), %eax\n" /* line 3573 | stmt1 */
        "movl 0x14(%ebp), %esi\n" /* block */
        "movl %eax, 4(%esi)\n" /* stmt1 */
        "movl 0x1c(%ebp), %eax\n" /* line 3575 | forStatPostBlock, stmt1 */
        "movl (%eax), %edi\n" /* stmt1, block */
        "movl %edi, -0x50(%ebp)\n" /* block */
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl $0, -0x64(%ebp)\n" /* j */
        /* { scope 2: i, i, bConstRefCount */
        ".Lf9937e_0009956b:\n"
        "movl -0x64(%ebp), %esi\n" /* line 1058 | j */
        "cmpl 8(%edi), %esi\n" /* stringValue */
        "jl .Lf9937e_00099581\n"
        "movl 0x14(%ebp), %edx\n" /* block */
        "movl 4(%edx), %eax\n"
        "cmpl %eax, %esi\n"
        "jge .Lf9937e_0009966c\n"
        /* } scope */
        ".Lf9937e_00099581:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 1060 */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x68(%ebp)\n"
        /* { scope 2: i, i, bConstRefCount */
        "movl 0xc(%edi), %esi\n" /* line 764 | stringValue */
        "movl %esi, %ecx\n"
        "cmpl %esi, -0x64(%ebp)\n" /* j */
        "jge .Lf9937e_00099639\n"
        "movl -0x68(%ebp), %eax\n" /* line 766 */
        "movl -0x50(%ebp), %ebx\n"
        "cmpl 0x18(%ebx), %eax\n"
        "je .Lf9937e_00099664\n"
        "movl -0x64(%ebp), %ebx\n" /* j */
        "leal 0x18(%edi, %ebx, 4), %edx\n" /* stringValue */
        ".Lf9937e_000995ad:\n"
        "addl $1, %ebx\n" /* line 764 */
        "cmpl %ebx, %esi\n"
        "je .Lf9937e_00099639\n"
        "movl 4(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0x68(%ebp)\n"
        "jne .Lf9937e_000995ad\n"
        ".Lf9937e_000995c3:\n"
        "testl %ebx, %ebx\n" /* line 1062 */
        "js .Lf9937e_00099639\n"
        ".Lf9937e_000995c7:\n"
        "movl 8(%edi), %eax\n" /* line 1068 | block */
        "cmpl %eax, %ebx\n"
        "jl .Lf9937e_000995d4\n"
        "addl $1, %eax\n" /* line 1070 */
        "movl %eax, 8(%edi)\n" /* block */
        ".Lf9937e_000995d4:\n"
        "cmpl %ebx, -0x64(%ebp)\n" /* line 1073 | j */
        "jge .Lf9937e_000995fa\n"
        "leal (, %ebx, 4), %eax\n"
        "leal 0x14(%eax, %edi), %ecx\n"
        "leal 0x18(%eax, %edi), %edx\n"
        ".Lf9937e_000995e8:\n"
        "subl $1, %ebx\n" /* line 1075 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x64(%ebp)\n" /* line 1073 | j */
        "jl .Lf9937e_000995e8\n"
        ".Lf9937e_000995fa:\n"
        "movl -0x68(%ebp), %esi\n" /* line 1078 */
        "movl -0x50(%ebp), %ebx\n"
        "movl %esi, 0x18(%ebx)\n"
        "movl -0x64(%ebp), %edx\n" /* line 1079 | j */
        "sarl $3, %edx\n"
        "movl -0x64(%ebp), %ecx\n" /* j */
        "andl $7, %ecx\n"
        "movl 0x14(%ebp), %ebx\n" /* block */
        "movzbl 0x10(%edx, %ebx), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf9937e_00099628\n"
        "movl $1, %eax\n" /* line 1080 */
        "shll %cl, %eax\n"
        "orb %al, 0x10(%edx, %edi)\n"
        ".Lf9937e_00099628:\n"
        "addl $1, -0x64(%ebp)\n" /* line 1058 | j */
        "addl $4, -0x50(%ebp)\n"
        "addl $4, -0x4c(%ebp)\n"
        "jmp .Lf9937e_0009956b\n"
        ".Lf9937e_00099639:\n"
        "cmpl $0x3f, %esi\n" /* line 894 */
        "jg .Lf9937e_0009964b\n"
        ".Lf9937e_0009963e:\n"
        "leal 1(%ecx), %eax\n" /* line 1066 */
        "movl %eax, 0xc(%edi)\n" /* block */
        "movl %esi, %ebx\n"
        "jmp .Lf9937e_000995c7\n"
        ".Lf9937e_0009964b:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%edi), %ecx\n" /* stringValue */
        "jmp .Lf9937e_0009963e\n"
        ".Lf9937e_00099664:\n"
        "movl -0x64(%ebp), %ebx\n" /* line 766 | j */
        "jmp .Lf9937e_000995c3\n"
        ".Lf9937e_0009966c:\n"
        "movl %eax, 4(%edi)\n" /* line 1084 | block */
        "movl $0, (%edi)\n" /* line 1085 | block */
        /* } scope */
        "movl $0, (%esp)\n" /* line 3577 */
        "calll TempMalloc\n"
        "movl %eax, -0xb4(%ebp)\n" /* stmt1, pos1 */
        "movl -0xb8(%ebp), %ecx\n" /* line 3579 */
        "cmpl $0x41, (%ecx)\n"
        "je .Lf9937e_00099c8f\n"
        ".Lf9937e_00099696:\n"
        "movb $1, -0x95(%ebp)\n" /* line 3593 | constConditional */
        ".Lf9937e_0009969d:\n"
        "movl scrCompileGlob+60, %esi\n" /* line 3602 */
        "movl %esi, -0x94(%ebp)\n" /* oldBreakChildBlocks */
        "movl scrCompileGlob+64, %eax\n" /* line 3603 | stmt1 */
        "movl %eax, -0x90(%ebp)\n" /* stmt1, oldBreakChildCount */
        "movl scrCompileGlob+68, %edx\n" /* line 3604 */
        "movl %edx, -0x7c(%ebp)\n" /* oldBreakBlock */
        "movl scrCompileGlob+72, %ecx\n" /* line 3606 */
        "movl %ecx, -0x84(%ebp)\n" /* oldContinueChildBlocks */
        "movl scrCompileGlob+76, %ebx\n" /* line 3607 */
        "movl %ebx, -0x80(%ebp)\n" /* oldContinueChildCount */
        "movl $0, -0x1c(%ebp)\n" /* line 3609 | breakChildCount */
        "movl $0, -0x20(%ebp)\n" /* line 3610 | continueChildCount */
        "movl $__mh_execute_header, (%esp)\n" /* line 3612 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, -0x88(%ebp)\n" /* stmt1, continueChildBlocks */
        "movl %eax, scrCompileGlob+72\n" /* line 3613 | stmt1 */
        "leal -0x20(%ebp), %eax\n" /* line 3614 | continueChildCount, stmt1 */
        "movl %eax, scrCompileGlob+76\n" /* stmt1 */
        "movl 0x18(%ebp), %esi\n" /* line 3616 | forStatBlock */
        "movl (%esi), %eax\n" /* stmt1 */
        "movl %eax, scrCompileGlob+68\n" /* stmt1 */
        "cmpb $0, -0x95(%ebp)\n" /* line 3618 | constConditional */
        "jne .Lf9937e_00099b47\n"
        "xorl %ecx, %ecx\n" /* line 3620 */
        "movl $0xffffffff, %edx\n"
        "movl $0x5e, %eax\n" /* stmt1 */
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3621 */
        "movl 0xc(%ebp), %eax\n" /* sourcePos, stmt1 */
        "movl %eax, (%esp)\n" /* stmt1 */
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw $0, (%eax)\n" /* line 610 */
        "movl scrCompileGlob, %edx\n" /* line 3623 */
        "movl %edx, -0xb0(%ebp)\n" /* pos2 */
        "movl $0, (%esp)\n" /* line 3624 */
        "calll TempMalloc\n"
        "movl %eax, -0xac(%ebp)\n" /* stmt1, nextPos2 */
        "movl $0, -0x8c(%ebp)\n" /* breakChildBlocks */
        ".Lf9937e_00099778:\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 3637 | breakChildBlocks */
        "movl %ecx, scrCompileGlob+60\n"
        "movb $1, scrCompileGlob+44\n" /* line 3639 */
        "movl scrCompilePub+40, %eax\n" /* line 3640 | stmt1 */
        "testl %eax, %eax\n" /* stmt1 */
        "setne %al\n" /* stmt1 */
        "movb %al, scrCompileGlob+45\n" /* stmt1 */
        "movl $0, scrCompileGlob+48\n" /* line 3641 */
        "movb $1, scrCompileGlob+52\n" /* line 3643 */
        "movb %al, scrCompileGlob+53\n" /* line 3644 | stmt1 */
        "movl $0, scrCompileGlob+56\n" /* line 3645 */
        "movl 0x18(%ebp), %ebx\n" /* line 3647 | forStatBlock */
        "movl (%ebx), %eax\n" /* stmt1 */
        "movl %eax, (%esp)\n" /* stmt1 */
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "movl 8(%ebp), %eax\n" /* stmt, stmt1 */
        "calll EmitStatement\n"
        "movl 0x18(%ebp), %esi\n" /* line 3648 | forStatBlock */
        "movl (%esi), %ebx\n" /* block */
        /* { scope 2: i, i, bConstRefCount */
        "movl (%ebx), %eax\n" /* line 3298 */
        "testl %eax, %eax\n"
        "jne .Lf9937e_00099808\n"
        "movl scrCompileGlob+72, %edi\n" /* line 3300 | block */
        "testl %edi, %edi\n" /* block */
        "je .Lf9937e_00099808\n"
        "movl scrCompileGlob+76, %eax\n" /* line 886 */
        "cmpl $0x3ff, (%eax)\n"
        "jg .Lf9937e_00099cd9\n"
        ".Lf9937e_000997f6:\n"
        "movl (%eax), %edx\n" /* line 3303 */
        "movl scrCompileGlob+72, %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n"
        "movl scrCompileGlob+76, %eax\n" /* line 3304 */
        "addl $1, (%eax)\n"
        /* } scope */
        ".Lf9937e_00099808:\n"
        "movb $0, scrCompileGlob+44\n" /* line 3650 */
        "movb $0, scrCompileGlob+45\n" /* line 3651 */
        "movb $0, scrCompileGlob+52\n" /* line 3653 */
        "movb $0, scrCompileGlob+53\n" /* line 3654 */
        "movl $0, (%esp)\n" /* line 3032 */
        "calll TempMalloc\n"
        "movl %eax, %ebx\n"
        "movl scrCompileGlob+56, %ecx\n" /* line 3033 */
        "testl %ecx, %ecx\n" /* line 3035 */
        "je .Lf9937e_0009984c\n"
        ".Lf9937e_0009983c:\n"
        "movl (%ecx), %edx\n" /* line 3037 */
        "movl %ebx, %eax\n"
        "subl 4(%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 8(%ecx), %ecx\n" /* line 3038 */
        "testl %ecx, %ecx\n" /* line 3035 */
        "jne .Lf9937e_0009983c\n"
        ".Lf9937e_0009984c:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 3658 | forStatPostBlock, stmt1 */
        "movl (%eax), %eax\n" /* stmt1 */
        "movl %eax, -0xc0(%ebp)\n" /* stmt1 */
        "movl -0x20(%ebp), %edx\n" /* continueChildCount */
        "movl %edx, -0x60(%ebp)\n" /* childCount */
        /* { scope 2: i, i, bConstRefCount */
        /* { scope 3 */
        "testl %edx, %edx\n" /* line 939 */
        "je .Lf9937e_0009992f\n"
        "movl -0x88(%ebp), %ecx\n" /* line 942 | continueChildBlocks */
        "movl (%ecx), %eax\n"
        "movl 8(%eax), %edi\n" /* stringValue */
        "subl $1, %edx\n" /* line 943 */
        "jle .Lf9937e_00099893\n"
        "movl $1, %edx\n"
        "movl -0x88(%ebp), %ebx\n" /* continueChildBlocks */
        ".Lf9937e_00099880:\n"
        "movl (%ebx, %edx, 4), %eax\n" /* line 946 */
        "movl 8(%eax), %eax\n"
        "cmpl %edi, %eax\n" /* stringValue */
        "cmovll %eax, %edi\n" /* stringValue */
        "addl $1, %edx\n" /* line 943 */
        "cmpl %edx, -0x60(%ebp)\n" /* childCount */
        "jne .Lf9937e_00099880\n"
        ".Lf9937e_00099893:\n"
        "movl -0xc0(%ebp), %esi\n" /* line 952 */
        "movl %edi, 4(%esi)\n" /* stringValue */
        "testl %edi, %edi\n" /* line 954 | stringValue */
        "jle .Lf9937e_00099b7a\n"
        "movl $0, -0x5c(%ebp)\n" /* i */
        ".Lf9937e_000998ab:\n"
        "movl -0x5c(%ebp), %ebx\n" /* line 957 | i */
        "sarl $3, %ebx\n"
        "movl -0xc0(%ebp), %eax\n"
        "movzbl 0x10(%ebx, %eax), %eax\n"
        "movb %al, -0xd9(%ebp)\n"
        "movl -0x5c(%ebp), %ecx\n" /* i */
        "andl $7, %ecx\n"
        "movzbl %al, %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf9937e_00099917\n"
        "movl -0x60(%ebp), %esi\n" /* line 960 | childCount */
        "testl %esi, %esi\n"
        "jle .Lf9937e_00099c52\n"
        "movl -0x88(%ebp), %edx\n" /* line 966 | continueChildBlocks */
        "movl (%edx), %eax\n"
        "movzbl 0x10(%ebx, %eax), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf9937e_00099917\n"
        "xorl %edx, %edx\n" /* line 967 */
        ".Lf9937e_000998f1:\n"
        "addl $1, %edx\n" /* line 960 */
        "cmpl %edx, -0x60(%ebp)\n" /* childCount */
        "je .Lf9937e_00099c52\n"
        "movl -0x88(%ebp), %esi\n" /* line 966 | continueChildBlocks */
        "movl (%esi, %edx, 4), %esi\n"
        "movl %esi, -0xcc(%ebp)\n"
        "movzbl 0x10(%ebx, %esi), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf9937e_000998f1\n"
        ".Lf9937e_00099917:\n"
        "addl $1, -0x5c(%ebp)\n" /* line 954 | i */
        "cmpl %edi, -0x5c(%ebp)\n" /* stringValue, i */
        "jne .Lf9937e_000998ab\n"
        ".Lf9937e_00099920:\n"
        "movl 0x1c(%ebp), %ecx\n" /* forStatPostBlock */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0xc0(%ebp)\n"
        "movl %ecx, %esi\n"
        "jmp .Lf9937e_00099931\n"
        ".Lf9937e_0009992f:\n"
        "movl %eax, %esi\n"
        /* } scope */
        /* } scope */
        ".Lf9937e_00099931:\n"
        "movl %esi, (%esp)\n" /* line 3660 */
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "movl -0xbc(%ebp), %eax\n" /* stmt1 */
        "calll EmitStatement\n"
        "xorl %ecx, %ecx\n" /* line 3661 */
        "xorl %edx, %edx\n"
        "movl $0x63, %eax\n" /* stmt1 */
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 3662 */
        "movl 0x10(%ebp), %eax\n" /* forSourcePos, stmt1 */
        "movl %eax, (%esp)\n" /* stmt1 */
        "calll AddOpcodePos\n"
        "movl 8(%ebp), %eax\n" /* line 3663 | stmt, stmt1 */
        "cmpl $0x2c, (%eax)\n" /* stmt1 */
        "je .Lf9937e_00099cc1\n"
        ".Lf9937e_00099970:\n"
        "movl $2, (%esp)\n" /* line 609 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw $0, (%eax)\n" /* line 610 */
        "movl $0, (%esp)\n" /* line 3667 */
        "calll TempMalloc\n"
        "subl -0xb4(%ebp), %eax\n" /* line 3669 | pos1, stmt1 */
        "movl scrCompileGlob, %edx\n"
        "movw %ax, (%edx)\n" /* stmt1 */
        "movl -0xb0(%ebp), %ecx\n" /* line 3670 | pos2 */
        "testl %ecx, %ecx\n"
        "je .Lf9937e_000999c6\n"
        "movl $0, (%esp)\n" /* line 3672 */
        "calll TempMalloc\n"
        "subl -0xac(%ebp), %eax\n" /* line 3674 | nextPos2, stmt1 */
        "movl -0xb0(%ebp), %ecx\n" /* pos2 */
        "movw %ax, (%ecx)\n" /* stmt1 */
        ".Lf9937e_000999c6:\n"
        "movl $0, (%esp)\n" /* line 3016 */
        "calll TempMalloc\n"
        "movl %eax, %ebx\n"
        "movl scrCompileGlob+48, %ecx\n" /* line 3017 */
        "testl %ecx, %ecx\n" /* line 3019 */
        "je .Lf9937e_000999ee\n"
        ".Lf9937e_000999de:\n"
        "movl (%ecx), %edx\n" /* line 3021 */
        "movl %ebx, %eax\n"
        "subl 4(%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 8(%ecx), %ecx\n" /* line 3022 */
        "testl %ecx, %ecx\n" /* line 3019 */
        "jne .Lf9937e_000999de\n"
        ".Lf9937e_000999ee:\n"
        "movzbl -0xa6(%ebp), %ebx\n" /* line 3679 | bOldCanBreak, block */
        "movb %bl, scrCompileGlob+44\n" /* block */
        "movzbl -0xa5(%ebp), %eax\n" /* line 3680 | bOldCanIgnoreBreak, stmt1 */
        "movb %al, scrCompileGlob+45\n" /* stmt1 */
        "movl -0xa4(%ebp), %edx\n" /* line 3681 | oldBreakStatement */
        "movl %edx, scrCompileGlob+48\n"
        "movzbl -0x9e(%ebp), %ecx\n" /* line 3683 | bOldCanContinue */
        "movb %cl, scrCompileGlob+52\n"
        "movzbl -0x9d(%ebp), %ebx\n" /* line 3684 | bOldCanIgnoreContinue, block */
        "movb %bl, scrCompileGlob+53\n" /* block */
        "movl -0x9c(%ebp), %esi\n" /* line 3685 | oldContinueStatement */
        "movl %esi, scrCompileGlob+56\n"
        "cmpb $0, -0x95(%ebp)\n" /* line 3687 | constConditional */
        "je .Lf9937e_00099b07\n"
        "movl -0x1c(%ebp), %eax\n" /* line 3688 | breakChildCount, stmt1 */
        "movl %eax, -0x58(%ebp)\n" /* stmt1, childCount */
        /* { scope 2: i, i, bConstRefCount */
        /* { scope 3 */
        "testl %eax, %eax\n" /* line 939 */
        "je .Lf9937e_00099b07\n"
        "movl -0x8c(%ebp), %edx\n" /* line 942 | breakChildBlocks */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edi\n" /* stringValue */
        "cmpl $1, -0x58(%ebp)\n" /* line 943 | childCount */
        "jle .Lf9937e_00099a84\n"
        "movl $1, %edx\n"
        "movl -0x8c(%ebp), %ecx\n" /* breakChildBlocks */
        ".Lf9937e_00099a71:\n"
        "movl (%ecx, %edx, 4), %eax\n" /* line 946 */
        "movl 8(%eax), %eax\n"
        "cmpl %edi, %eax\n" /* stringValue */
        "cmovll %eax, %edi\n" /* stringValue */
        "addl $1, %edx\n" /* line 943 */
        "cmpl %edx, -0x58(%ebp)\n" /* childCount */
        "jne .Lf9937e_00099a71\n"
        ".Lf9937e_00099a84:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 952 | block */
        "movl %edi, 4(%ebx)\n" /* stringValue */
        "testl %edi, %edi\n" /* line 954 | stringValue */
        "jle .Lf9937e_00099b07\n"
        "movl $0, -0x54(%ebp)\n" /* i */
        ".Lf9937e_00099a95:\n"
        "movl -0x54(%ebp), %ebx\n" /* line 957 | i */
        "sarl $3, %ebx\n"
        "movl 0x14(%ebp), %eax\n" /* block */
        "movzbl 0x10(%ebx, %eax), %eax\n"
        "movb %al, -0xd9(%ebp)\n"
        "movl -0x54(%ebp), %ecx\n" /* i */
        "andl $7, %ecx\n"
        "movzbl %al, %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf9937e_00099afe\n"
        "movl -0x58(%ebp), %edx\n" /* line 960 | childCount */
        "testl %edx, %edx\n"
        "jle .Lf9937e_00099c25\n"
        "movl -0x8c(%ebp), %edx\n" /* line 966 | breakChildBlocks */
        "movl (%edx), %eax\n"
        "movzbl 0x10(%ebx, %eax), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf9937e_00099afe\n"
        "xorl %edx, %edx\n" /* line 967 */
        ".Lf9937e_00099ad8:\n"
        "addl $1, %edx\n" /* line 960 */
        "cmpl %edx, -0x58(%ebp)\n" /* childCount */
        "je .Lf9937e_00099c25\n"
        "movl -0x8c(%ebp), %esi\n" /* line 966 | breakChildBlocks */
        "movl (%esi, %edx, 4), %esi\n"
        "movl %esi, -0xd0(%ebp)\n"
        "movzbl 0x10(%ebx, %esi), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf9937e_00099ad8\n"
        ".Lf9937e_00099afe:\n"
        "addl $1, -0x54(%ebp)\n" /* line 954 | i */
        "cmpl %edi, -0x54(%ebp)\n" /* stringValue, i */
        "jne .Lf9937e_00099a95\n"
        /* } scope */
        /* } scope */
        ".Lf9937e_00099b07:\n"
        "movl -0x94(%ebp), %ecx\n" /* line 3690 | oldBreakChildBlocks */
        "movl %ecx, scrCompileGlob+60\n"
        "movl -0x90(%ebp), %ebx\n" /* line 3691 | oldBreakChildCount, block */
        "movl %ebx, scrCompileGlob+64\n" /* block */
        "movl -0x7c(%ebp), %esi\n" /* line 3692 | oldBreakBlock */
        "movl %esi, scrCompileGlob+68\n"
        "movl -0x84(%ebp), %eax\n" /* line 3694 | oldContinueChildBlocks, stmt1 */
        "movl %eax, scrCompileGlob+72\n" /* stmt1 */
        "movl -0x80(%ebp), %edx\n" /* line 3695 | oldContinueChildCount */
        "movl %edx, scrCompileGlob+76\n"
        /* } scope */
        "addl $0xec, %esp\n" /* line 3696 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: j, i, j, childCount, ... */
        ".Lf9937e_00099b47:\n"
        "movl $__mh_execute_header, (%esp)\n" /* line 3633 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, -0x8c(%ebp)\n" /* stmt1, breakChildBlocks */
        "leal -0x1c(%ebp), %eax\n" /* line 3634 | breakChildCount, stmt1 */
        "movl %eax, scrCompileGlob+64\n" /* stmt1 */
        "movl $0, -0xb0(%ebp)\n" /* pos2 */
        "movl $0, -0xac(%ebp)\n" /* nextPos2 */
        "jmp .Lf9937e_00099778\n"
        ".Lf9937e_00099b7a:\n"
        "movl 0x1c(%ebp), %ebx\n" /* forStatPostBlock */
        "movl (%ebx), %ebx\n"
        "movl %ebx, -0xc0(%ebp)\n"
        "movl %ebx, %esi\n"
        "jmp .Lf9937e_00099931\n"
        /* { scope 2: i, i, bConstRefCount */
        ".Lf9937e_00099b8c:\n"
        "movl -0x70(%ebp), %ecx\n" /* line 833 | i */
        "leal 0x18(%esi, %ecx, 4), %ecx\n"
        "movl %ecx, -0x48(%ebp)\n"
        "jmp .Lf9937e_00099bd4\n"
        /* { scope 3 */
        ".Lf9937e_00099b98:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 233 */
        "jne .Lf9937e_00099c82\n"
        ".Lf9937e_00099ba5:\n"
        "movl scrCompileGlob, %ebx\n" /* line 236 */
        "movl %edi, (%esp)\n" /* stringValue */
        "calll SL_TransferToCanonicalString\n"
        "movw %ax, (%ebx)\n"
        ".Lf9937e_00099bb6:\n"
        "movzbl -0x69(%ebp), %ecx\n" /* line 247 | bConstRefCount */
        "movb %cl, scrCompileGlob+28\n"
        /* } scope */
        "addl $1, -0x70(%ebp)\n" /* line 833 | i */
        "movl 8(%esi), %eax\n"
        "addl $4, -0x48(%ebp)\n"
        "cmpl %eax, -0x70(%ebp)\n" /* i */
        "jge .Lf9937e_00099545\n"
        ".Lf9937e_00099bd4:\n"
        "xorl %ecx, %ecx\n" /* line 835 */
        "xorl %edx, %edx\n"
        "movl $0x16, %eax\n"
        "calll EmitOpcode\n"
        "movl -0x48(%ebp), %eax\n" /* line 836 */
        "movl (%eax), %edi\n" /* stringValue */
        /* { scope 3 */
        "movzbl scrCompileGlob+28, %edx\n" /* line 244 */
        "movb %dl, -0x69(%ebp)\n" /* bConstRefCount */
        "movb $1, scrCompileGlob+28\n" /* line 245 */
        "movl $2, (%esp)\n" /* line 214 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "cmpl $2, scrCompilePub+40\n" /* line 216 */
        "jne .Lf9937e_00099b98\n"
        /* { scope 4 */
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf9937e_00099bb6\n"
        "movl %edi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf9937e_00099bb6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, bConstRefCount */
        /* { scope 3 */
        ".Lf9937e_00099c25:\n"
        "movl $1, %eax\n" /* line 969 */
        "shll %cl, %eax\n"
        "orb %al, -0xd9(%ebp)\n"
        "movzbl -0xd9(%ebp), %eax\n"
        "movl 0x14(%ebp), %edx\n" /* block */
        "movb %al, 0x10(%ebx, %edx)\n"
        "addl $1, -0x54(%ebp)\n" /* line 954 | i */
        "cmpl %edi, -0x54(%ebp)\n" /* stringValue, i */
        "jne .Lf9937e_00099a95\n"
        "jmp .Lf9937e_00099b07\n"
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, bConstRefCount */
        /* { scope 3 */
        ".Lf9937e_00099c52:\n"
        "movl $1, %eax\n" /* line 969 */
        "shll %cl, %eax\n"
        "orb %al, -0xd9(%ebp)\n"
        "movzbl -0xd9(%ebp), %eax\n"
        "movl -0xc0(%ebp), %edx\n"
        "movb %al, 0x10(%ebx, %edx)\n"
        "addl $1, -0x5c(%ebp)\n" /* line 954 | i */
        "cmpl %edi, -0x5c(%ebp)\n" /* stringValue, i */
        "jne .Lf9937e_000998ab\n"
        "jmp .Lf9937e_00099920\n"
        /* } scope */
        /* } scope */
        /* { scope 2: i, i, bConstRefCount */
        /* { scope 3 */
        ".Lf9937e_00099c82:\n"
        "movl %edi, (%esp)\n" /* line 234 | stringValue */
        "calll SL_AddRefToString\n"
        "jmp .Lf9937e_00099ba5\n"
        /* } scope */
        /* } scope */
        ".Lf9937e_00099c8f:\n"
        "movl 4(%ecx), %eax\n" /* line 3582 | stmt1 */
        "leal -0x2c(%ebp), %ebx\n" /* constValue */
        "movl 0x14(%ebp), %ecx\n" /* block */
        "movl %ebx, %edx\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n" /* stmt1 */
        "je .Lf9937e_00099cb5\n"
        "movl -0x28(%ebp), %eax\n" /* line 3584 | stmt1 */
        "subl $5, %eax\n" /* stmt1 */
        "cmpl $1, %eax\n" /* stmt1 */
        "jbe .Lf9937e_00099cf7\n"
        "movl %ebx, %eax\n" /* line 3593 | stmt1 */
        "calll EmitValue\n"
        ".Lf9937e_00099cb5:\n"
        "movb $0, -0x95(%ebp)\n" /* constConditional */
        "jmp .Lf9937e_0009969d\n"
        ".Lf9937e_00099cc1:\n"
        "movl $1, 4(%esp)\n" /* line 3664 */
        "movl 0xc(%eax), %eax\n" /* stmt1 */
        "movl %eax, (%esp)\n" /* stmt1 */
        "calll AddOpcodePos\n"
        "jmp .Lf9937e_00099970\n"
        /* { scope 2: i, i, bConstRefCount */
        ".Lf9937e_00099cd9:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* line 888 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompileGlob+76, %eax\n"
        "jmp .Lf9937e_000997f6\n"
        /* } scope */
        ".Lf9937e_00099cf7:\n"
        "movl %ebx, (%esp)\n" /* line 3586 */
        "calll Scr_CastBool\n"
        "movl -0x2c(%ebp), %eax\n" /* line 3587 | constValue, stmt1 */
        "testl %eax, %eax\n" /* stmt1 */
        "jne .Lf9937e_00099696\n"
        "movl $str_0021da90, 4(%esp)\n" /* line 3588 */
        "movl 0xc(%ebp), %ebx\n" /* sourcePos */
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "movb $1, -0x95(%ebp)\n" /* constConditional */
        "jmp .Lf9937e_0009969d\n"
    );
}

/* line 4223 */
static __attribute__((naked))
unsigned int EmitSwitchStatement(sval_t sourcePos, int lastStatement, unsigned int endSourcePos, scr_block_t *block)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4223 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %edx, %edi\n" /* stmtlist */
        "movl %ecx, -0x7c(%ebp)\n"
        "movzbl 8(%ebp), %esi\n" /* lastStatement */
        /* { scope 1: constValue, lastStatement */
        "movzbl scrCompileGlob+38, %edx\n" /* line 4237 */
        "movb %dl, -0x75(%ebp)\n" /* bOldCanIgnoreCase */
        "movl scrCompileGlob+40, %ecx\n" /* line 4238 */
        "movl %ecx, -0x74(%ebp)\n" /* oldCaseStatement */
        "movb $0, scrCompileGlob+38\n" /* line 4239 */
        "movzbl scrCompileGlob+44, %ebx\n" /* line 4241 | outerBlock */
        "movb %bl, -0x6e(%ebp)\n" /* outerBlock, bOldCanBreak */
        "movzbl scrCompileGlob+45, %edx\n" /* line 4242 */
        "movb %dl, -0x6d(%ebp)\n" /* bOldCanIgnoreBreak */
        "movl scrCompileGlob+48, %ecx\n" /* line 4243 */
        "movl %ecx, -0x6c(%ebp)\n" /* oldBreakStatement */
        "movb $0, scrCompileGlob+44\n" /* line 4244 */
        "movb $0, scrCompileGlob+45\n" /* line 4245 */
        /* { scope 2: hasDefault, breakChildCount, oldBreakChildBlocks, oldBreakChildCount, ... */
        "leal -0x28(%ebp), %ebx\n" /* line 2883 | constValue */
        "movl 0x10(%ebp), %ecx\n" /* block */
        "movl %ebx, %edx\n"
        "calll EmitOrEvalExpression\n"
        "testb %al, %al\n"
        "jne .Lf99d2a_0009a460\n"
        /* } scope */
        ".Lf99d2a_00099d99:\n"
        "xorl %ecx, %ecx\n" /* line 4248 */
        "movl $0xffffffff, %edx\n"
        "movl $0x7c, %eax\n" /* expr */
        "calll EmitOpcode\n"
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl $0, (%eax)\n" /* line 596 */
        "movl scrCompileGlob, %ebx\n" /* line 4250 | outerBlock */
        "movl %ebx, -0x68(%ebp)\n" /* outerBlock, pos1 */
        "movl $0, (%esp)\n" /* line 4251 */
        "calll TempMalloc\n"
        "movl %eax, -0x60(%ebp)\n" /* expr, nextPos1 */
        "movl scrCompilePub+40, %eax\n" /* line 4253 | expr */
        "testl %eax, %eax\n" /* expr */
        "setne %al\n" /* expr */
        "movb %al, scrCompileGlob+38\n" /* expr */
        "movl $0, scrCompileGlob+40\n" /* line 4254 */
        "movb %al, scrCompileGlob+45\n" /* line 4256 | expr */
        "movl $0, scrCompileGlob+48\n" /* line 4257 */
        "movl %esi, %eax\n" /* line 4259 | caseStatement, expr */
        "movb %al, -0x56(%ebp)\n" /* expr, lastStatement */
        /* { scope 2: hasDefault, breakChildCount, oldBreakChildBlocks, oldBreakChildCount, ... */
        /* { scope 3: j, childCount, childBlocks */
        "movl scrCompileGlob+60, %edx\n" /* line 4045 */
        "movl %edx, -0x54(%ebp)\n" /* oldBreakChildBlocks */
        "movl scrCompileGlob+64, %ecx\n" /* line 4046 */
        "movl %ecx, -0x50(%ebp)\n" /* oldBreakChildCount */
        "movl scrCompileGlob+68, %ebx\n" /* line 4047 */
        "movl %ebx, -0x4c(%ebp)\n" /* oldBreakBlock */
        "movl $0, -0x1c(%ebp)\n" /* line 4049 | breakChildCount */
        "movl $__mh_execute_header, (%esp)\n" /* line 4050 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, -0x3c(%ebp)\n" /* childBlocks */
        "movl %eax, scrCompileGlob+60\n" /* line 4051 */
        "leal -0x1c(%ebp), %eax\n" /* line 4052 | breakChildCount */
        "movl %eax, scrCompileGlob+64\n"
        "movl $0, scrCompileGlob+68\n" /* line 4053 */
        "movl (%edi), %eax\n" /* line 4057 | removeCount */
        "movl 4(%eax), %esi\n" /* node */
        "testl %esi, %esi\n" /* node */
        "je .Lf99d2a_0009a484\n"
        "movb $0, -0x55(%ebp)\n" /* hasDefault */
        "movl 4(%esi), %eax\n" /* line 4059 | node */
        "movl %eax, -0x2c(%ebp)\n"
        "movl (%esi), %ebx\n" /* line 4061 | node */
        "movl (%ebx), %eax\n"
        "subl $0x3d, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf99d2a_00099f10\n"
        ".Lf99d2a_00099e77:\n"
        "movl scrCompileGlob+68, %ecx\n" /* line 4089 */
        "testl %ecx, %ecx\n"
        "je .Lf99d2a_0009a46c\n"
        "cmpb $0, -0x56(%ebp)\n" /* line 4095 | lastStatement */
        "je .Lf99d2a_0009a06d\n"
        "movl -0x2c(%ebp), %edi\n" /* line 3985 | removeCount */
        "testl %edi, %edi\n" /* removeCount */
        "je .Lf99d2a_00099eba\n"
        "movl imp_scrVarPub, %eax\n" /* line 3987 */
        "cmpb $0, 0xb(%eax)\n"
        "jne .Lf99d2a_0009a06d\n"
        "movl -0x2c(%ebp), %edx\n"
        ".Lf99d2a_00099ea8:\n"
        "movl (%edx), %eax\n" /* line 3991 */
        "cmpl $0x2d, (%eax)\n"
        "jne .Lf99d2a_0009a06d\n"
        "movl 4(%edx), %edx\n" /* line 3993 */
        "testl %edx, %edx\n" /* line 3989 */
        "jne .Lf99d2a_00099ea8\n"
        ".Lf99d2a_00099eba:\n"
        "movl $1, %edx\n" /* line 4095 */
        ".Lf99d2a_00099ebf:\n"
        "movl %ecx, (%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* endSourcePos */
        "movl %ebx, %eax\n" /* outerBlock */
        "calll EmitStatement\n"
        "movl scrCompileGlob+68, %eax\n" /* line 4096 */
        "testl %eax, %eax\n"
        "je .Lf99d2a_00099eec\n"
        "movl (%eax), %esi\n" /* node */
        "testl %esi, %esi\n" /* node */
        "je .Lf99d2a_00099eec\n"
        "movl $0, scrCompileGlob+68\n" /* line 4099 */
        "movb $0, scrCompileGlob+44\n" /* line 4102 */
        ".Lf99d2a_00099eec:\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 4057 */
        "testl %ebx, %ebx\n"
        "je .Lf99d2a_0009a0c2\n"
        ".Lf99d2a_00099ef7:\n"
        "movl -0x2c(%ebp), %esi\n" /* node */
        "movl 4(%esi), %eax\n" /* line 4059 | node */
        "movl %eax, -0x2c(%ebp)\n"
        "movl (%esi), %ebx\n" /* line 4061 | node */
        "movl (%ebx), %eax\n"
        "subl $0x3d, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf99d2a_00099e77\n"
        ".Lf99d2a_00099f10:\n"
        "movl scrCompileGlob+68, %eax\n" /* line 4063 */
        "testl %eax, %eax\n"
        "je .Lf99d2a_00099f32\n"
        "movb $0, scrCompileGlob+44\n" /* line 4066 */
        "movl scrCompileGlob+68, %ebx\n" /* line 4067 | outerBlock */
        /* { scope 4: i */
        /* { scope 5 */
        "movl (%ebx), %eax\n" /* line 850 */
        "testl %eax, %eax\n"
        "je .Lf99d2a_0009a29d\n"
        ".Lf99d2a_00099f30:\n"
        "movl (%esi), %ebx\n" /* removeCount */
        /* } scope */
        /* } scope */
        ".Lf99d2a_00099f32:\n"
        "cmpl $0x3d, (%ebx)\n" /* line 4070 | outerBlock */
        "je .Lf99d2a_0009a2df\n"
        ".Lf99d2a_00099f3b:\n"
        "movl 8(%ebx), %eax\n" /* line 4077 | outerBlock */
        "movl %eax, scrCompileGlob+68\n"
        "movl (%esi), %eax\n" /* line 4079 | node */
        "movl 4(%eax), %esi\n" /* node */
        "cmpl $2, scrCompilePub+40\n" /* line 4323 */
        "je .Lf99d2a_00099f85\n"
        "movl $0x10, (%esp)\n" /* line 4329 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %ebx\n" /* expr, pos */
        "movl $0, (%eax)\n" /* line 4330 | expr */
        "movl $0, (%esp)\n" /* line 4332 */
        "calll TempMalloc\n"
        "movl %eax, 4(%ebx)\n" /* expr, pos */
        "movl %esi, 8(%ebx)\n" /* line 4333 | caseStatement, pos */
        "movl scrCompileGlob+40, %eax\n" /* line 4334 | expr */
        "movl %eax, 0xc(%ebx)\n" /* expr, pos */
        "movl %ebx, scrCompileGlob+40\n" /* line 4335 | pos */
        ".Lf99d2a_00099f85:\n"
        "movb $1, -0x55(%ebp)\n" /* hasDefault */
        ".Lf99d2a_00099f89:\n"
        "movl scrCompileGlob+68, %edi\n" /* line 4082 | removeCount */
        "movl %edi, -0x34(%ebp)\n" /* removeCount */
        "movl 0x10(%ebp), %ecx\n" /* block */
        "addl $0x18, %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movl $0, -0x44(%ebp)\n" /* j */
        /* { scope 4: i */
        ".Lf99d2a_00099fa2:\n"
        "movl -0x44(%ebp), %esi\n" /* line 1058 | j, removeCount */
        "cmpl 8(%edi), %esi\n" /* removeCount */
        "jl .Lf99d2a_00099fb8\n"
        "movl 0x10(%ebp), %edx\n" /* block */
        "movl 4(%edx), %eax\n"
        "cmpl %eax, %esi\n" /* removeCount */
        "jge .Lf99d2a_0009a0a7\n"
        /* } scope */
        ".Lf99d2a_00099fb8:\n"
        "movl -0x30(%ebp), %ebx\n" /* line 1060 */
        "movl (%ebx), %ebx\n"
        "movl %ebx, -0x48(%ebp)\n"
        /* { scope 4: i */
        "movl 0xc(%edi), %esi\n" /* line 764 */
        "movl %esi, %ecx\n"
        "cmpl %esi, -0x44(%ebp)\n" /* j */
        "jge .Lf99d2a_0009a074\n"
        "movl -0x34(%ebp), %eax\n" /* line 766 */
        "cmpl 0x18(%eax), %ebx\n"
        "je .Lf99d2a_0009a09f\n"
        "movl -0x44(%ebp), %ebx\n" /* j */
        "leal 0x18(%edi, %ebx, 4), %edx\n"
        ".Lf99d2a_00099fe1:\n"
        "addl $1, %ebx\n" /* line 764 */
        "cmpl %ebx, %esi\n"
        "je .Lf99d2a_0009a074\n"
        "movl 4(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl %eax, -0x48(%ebp)\n"
        "jne .Lf99d2a_00099fe1\n"
        ".Lf99d2a_00099ff7:\n"
        "testl %ebx, %ebx\n" /* line 1062 */
        "js .Lf99d2a_0009a074\n"
        ".Lf99d2a_00099ffb:\n"
        "movl 8(%edi), %eax\n" /* line 1068 | removeCount */
        "cmpl %eax, %ebx\n"
        "jl .Lf99d2a_0009a008\n"
        "addl $1, %eax\n" /* line 1070 */
        "movl %eax, 8(%edi)\n" /* removeCount */
        ".Lf99d2a_0009a008:\n"
        "cmpl %ebx, -0x44(%ebp)\n" /* line 1073 | j */
        "jge .Lf99d2a_0009a02e\n"
        "leal (, %ebx, 4), %eax\n"
        "leal 0x14(%eax, %edi), %ecx\n"
        "leal 0x18(%eax, %edi), %edx\n"
        ".Lf99d2a_0009a01c:\n"
        "subl $1, %ebx\n" /* line 1075 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, -0x44(%ebp)\n" /* line 1073 | j */
        "jl .Lf99d2a_0009a01c\n"
        ".Lf99d2a_0009a02e:\n"
        "movl -0x48(%ebp), %eax\n" /* line 1078 */
        "movl -0x34(%ebp), %esi\n" /* removeCount */
        "movl %eax, 0x18(%esi)\n" /* removeCount */
        "movl -0x44(%ebp), %edx\n" /* line 1079 | j */
        "sarl $3, %edx\n"
        "movl -0x44(%ebp), %ecx\n" /* j */
        "andl $7, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* block */
        "movzbl 0x10(%edx, %ebx), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf99d2a_0009a05c\n"
        "movl $1, %eax\n" /* line 1080 */
        "shll %cl, %eax\n"
        "orb %al, 0x10(%edx, %edi)\n"
        ".Lf99d2a_0009a05c:\n"
        "addl $1, -0x44(%ebp)\n" /* line 1058 | j */
        "addl $4, -0x34(%ebp)\n"
        "addl $4, -0x30(%ebp)\n"
        "jmp .Lf99d2a_00099fa2\n"
        /* } scope */
        ".Lf99d2a_0009a06d:\n"
        "xorl %edx, %edx\n" /* line 4095 */
        "jmp .Lf99d2a_00099ebf\n"
        /* { scope 4: i */
        ".Lf99d2a_0009a074:\n"
        "cmpl $0x3f, %esi\n" /* line 894 | removeCount */
        "jg .Lf99d2a_0009a086\n"
        ".Lf99d2a_0009a079:\n"
        "leal 1(%ecx), %eax\n" /* line 1066 */
        "movl %eax, 0xc(%edi)\n" /* removeCount */
        "movl %esi, %ebx\n" /* removeCount */
        "jmp .Lf99d2a_00099ffb\n"
        ".Lf99d2a_0009a086:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%edi), %ecx\n" /* removeCount */
        "jmp .Lf99d2a_0009a079\n"
        ".Lf99d2a_0009a09f:\n"
        "movl -0x44(%ebp), %ebx\n" /* line 766 | j */
        "jmp .Lf99d2a_00099ff7\n"
        ".Lf99d2a_0009a0a7:\n"
        "movl %eax, 4(%edi)\n" /* line 1084 | removeCount */
        "movl $0, (%edi)\n" /* line 1085 | removeCount */
        /* } scope */
        "movb $1, scrCompileGlob+44\n" /* line 4085 */
        "movl -0x2c(%ebp), %ebx\n" /* line 4057 */
        "testl %ebx, %ebx\n"
        "jne .Lf99d2a_00099ef7\n"
        ".Lf99d2a_0009a0c2:\n"
        "movl scrCompileGlob+68, %ecx\n" /* line 4105 */
        "testl %ecx, %ecx\n"
        "je .Lf99d2a_0009a0e3\n"
        "movb $0, scrCompileGlob+44\n" /* line 4108 */
        "movl scrCompileGlob+68, %ebx\n" /* line 4109 | outerBlock */
        /* { scope 4: i */
        /* { scope 5 */
        "movl (%ebx), %edx\n" /* line 850 */
        "testl %edx, %edx\n"
        "je .Lf99d2a_0009a40a\n"
        /* } scope */
        /* } scope */
        ".Lf99d2a_0009a0e3:\n"
        "cmpb $0, -0x55(%ebp)\n" /* line 4112 | hasDefault */
        "jne .Lf99d2a_0009a318\n"
        ".Lf99d2a_0009a0ed:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 4120 | oldBreakChildBlocks */
        "movl %ecx, scrCompileGlob+60\n"
        "movl -0x50(%ebp), %ebx\n" /* line 4121 | oldBreakChildCount, outerBlock */
        "movl %ebx, scrCompileGlob+64\n" /* outerBlock */
        "movl -0x4c(%ebp), %esi\n" /* line 4122 | oldBreakBlock, node */
        "movl %esi, scrCompileGlob+68\n" /* node */
        /* } scope */
        /* } scope */
        ".Lf99d2a_0009a108:\n"
        "movb $0, scrCompileGlob+38\n" /* line 4261 */
        "movb $0, scrCompileGlob+45\n" /* line 4262 */
        "xorl %ecx, %ecx\n" /* line 4264 */
        "xorl %edx, %edx\n"
        "movl $0x7d, %eax\n" /* expr */
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 4265 */
        "movl -0x7c(%ebp), %eax\n" /* expr */
        "movl %eax, (%esp)\n" /* expr */
        "calll AddOpcodePos\n"
        "movl $2, (%esp)\n" /* line 602 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movw $0, (%eax)\n" /* line 603 */
        "movl scrCompileGlob, %edx\n" /* line 4269 */
        "movl %edx, -0x64(%ebp)\n" /* pos2 */
        "movl %edx, %eax\n" /* line 4270 | expr */
        "subl -0x60(%ebp), %eax\n" /* nextPos1, expr */
        "movl -0x68(%ebp), %ecx\n" /* pos1 */
        "movl %eax, (%ecx)\n" /* expr */
        "movl $0, (%esp)\n" /* line 4272 */
        "calll TempMallocAlignStrict\n"
        "movl %eax, %edi\n" /* expr, pos3 */
        "movl scrCompileGlob+40, %esi\n" /* line 4276 | caseStatement */
        "testl %esi, %esi\n" /* line 4277 | caseStatement */
        "je .Lf99d2a_0009a450\n"
        "movl $0, -0x5c(%ebp)\n" /* num */
        ".Lf99d2a_0009a183:\n"
        "movl (%esi), %ebx\n" /* line 4279 | caseStatement, value */
        /* { scope 2: hasDefault, breakChildCount, oldBreakChildBlocks, oldBreakChildCount, ... */
        "movl $4, (%esp)\n" /* line 595 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %ebx, (%eax)\n" /* line 596 */
        /* } scope */
        "movl 4(%esi), %ebx\n" /* line 4280 | caseStatement, pos */
        /* { scope 2: hasDefault, breakChildCount, oldBreakChildBlocks, oldBreakChildCount, ... */
        "movl $4, (%esp)\n" /* line 637 */
        "calll TempMallocAlign\n"
        "movl %eax, scrCompileGlob\n"
        "movl %ebx, (%eax)\n" /* line 638 */
        /* } scope */
        "movl 0xc(%esi), %esi\n" /* line 4281 | caseStatement */
        "addl $1, -0x5c(%ebp)\n" /* line 4282 | num */
        "testl %esi, %esi\n" /* line 4277 | caseStatement */
        "jne .Lf99d2a_0009a183\n"
        "movl -0x5c(%ebp), %eax\n" /* num, expr */
        "movl -0x5c(%ebp), %edx\n" /* num */
        ".Lf99d2a_0009a1bf:\n"
        "movl -0x64(%ebp), %ebx\n" /* line 4285 | pos2, pos */
        "movw %ax, (%ebx)\n" /* expr, pos */
        "movl $CompareCaseInfo, 0xc(%esp)\n" /* line 4287 */
        "movl $8, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pos3 */
        "calll qsort\n"
        "cmpl $1, -0x5c(%ebp)\n" /* line 4289 | num */
        "jle .Lf99d2a_0009a205\n"
        "movl scrCompileGlob+40, %ebx\n" /* line 4293 | pos */
        "xorl %ecx, %ecx\n"
        "movl -0x5c(%ebp), %esi\n" /* num, caseStatement */
        "subl $1, %esi\n" /* caseStatement */
        ".Lf99d2a_0009a1f5:\n"
        "movl (%edi), %edx\n" /* line 4291 | pos3 */
        "addl $8, %edi\n" /* pos3 */
        "cmpl (%edi), %edx\n" /* pos3 */
        "je .Lf99d2a_0009a268\n"
        ".Lf99d2a_0009a1fe:\n"
        "addl $1, %ecx\n" /* line 4294 */
        "cmpl %ecx, %esi\n" /* line 4289 | caseStatement */
        "jne .Lf99d2a_0009a1f5\n"
        ".Lf99d2a_0009a205:\n"
        "movl $0, (%esp)\n" /* line 3016 */
        "calll TempMalloc\n"
        "movl %eax, %ebx\n"
        "movl scrCompileGlob+48, %ecx\n" /* line 3017 */
        "testl %ecx, %ecx\n" /* line 3019 */
        "je .Lf99d2a_0009a22d\n"
        ".Lf99d2a_0009a21d:\n"
        "movl (%ecx), %edx\n" /* line 3021 */
        "movl %ebx, %eax\n"
        "subl 4(%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 8(%ecx), %ecx\n" /* line 3022 */
        "testl %ecx, %ecx\n" /* line 3019 */
        "jne .Lf99d2a_0009a21d\n"
        ".Lf99d2a_0009a22d:\n"
        "movzbl -0x75(%ebp), %eax\n" /* line 4310 | bOldCanIgnoreCase, expr */
        "movb %al, scrCompileGlob+38\n" /* expr */
        "movl -0x74(%ebp), %edx\n" /* line 4311 | oldCaseStatement */
        "movl %edx, scrCompileGlob+40\n"
        "movzbl -0x6e(%ebp), %ecx\n" /* line 4313 | bOldCanBreak */
        "movb %cl, scrCompileGlob+44\n"
        "movzbl -0x6d(%ebp), %ebx\n" /* line 4314 | bOldCanIgnoreBreak, pos */
        "movb %bl, scrCompileGlob+45\n" /* pos */
        "movl -0x6c(%ebp), %esi\n" /* line 4315 | oldBreakStatement, caseStatement */
        "movl %esi, scrCompileGlob+48\n" /* caseStatement */
        /* } scope */
        "addl $0xac, %esp\n" /* line 4316 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: constValue, lastStatement */
        ".Lf99d2a_0009a268:\n"
        "testl %ebx, %ebx\n" /* line 4294 | pos */
        "je .Lf99d2a_0009a1fe\n"
        "cmpl (%ebx), %edx\n" /* line 4296 | pos */
        "je .Lf99d2a_0009a27f\n"
        "movl %ebx, %eax\n" /* pos, expr */
        ".Lf99d2a_0009a272:\n"
        "movl 0xc(%eax), %eax\n" /* line 4301 | expr */
        "testl %eax, %eax\n" /* line 4294 | expr */
        "je .Lf99d2a_0009a1fe\n"
        "cmpl (%eax), %edx\n" /* line 4296 | expr */
        "jne .Lf99d2a_0009a272\n"
        "movl %eax, %ebx\n" /* expr, pos */
        ".Lf99d2a_0009a27f:\n"
        "movl $str_0021db20, 4(%esp)\n" /* line 4298 */
        "movl 8(%ebx), %eax\n" /* pos, expr */
        "movl %eax, (%esp)\n" /* expr */
        "calll CompileError\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 4316 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: constValue, lastStatement */
        /* { scope 2: hasDefault, breakChildCount, oldBreakChildBlocks, oldBreakChildCount, ... */
        /* { scope 3: j, childCount, childBlocks */
        /* { scope 4: i */
        /* { scope 5 */
        ".Lf99d2a_0009a29d:\n"
        "movl 4(%ebx), %eax\n" /* line 854 */
        "movl %eax, %edi\n" /* line 856 | removeCount */
        "subl 8(%ebx), %edi\n" /* removeCount */
        "je .Lf99d2a_00099f30\n"
        "xorl %ecx, %ecx\n" /* line 858 */
        "xorl %edx, %edx\n"
        "movl $0x17, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movl %edi, %edx\n" /* line 617 */
        "movb %dl, (%eax)\n"
        "movl 8(%ebx), %eax\n" /* line 860 */
        "movl %eax, 4(%ebx)\n"
        "movl (%esi), %ebx\n" /* removeCount */
        /* } scope */
        /* } scope */
        "cmpl $0x3d, (%ebx)\n" /* line 4070 | outerBlock */
        "jne .Lf99d2a_00099f3b\n"
        ".Lf99d2a_0009a2df:\n"
        "movl 0xc(%ebx), %eax\n" /* line 4072 | outerBlock */
        "movl %eax, scrCompileGlob+68\n"
        "movl (%esi), %eax\n" /* line 4073 | node */
        "movl 8(%eax), %edi\n" /* removeCount */
        "movl 4(%eax), %esi\n" /* node */
        "movl (%esi), %eax\n" /* line 4003 | removeCount */
        "cmpl $7, %eax\n"
        "je .Lf99d2a_0009a529\n"
        "cmpl $0xb, %eax\n"
        "je .Lf99d2a_0009a48d\n"
        "movl $str_0021dadc, 4(%esp)\n" /* line 4020 */
        "movl %edi, (%esp)\n" /* removeCount */
        "calll CompileError\n"
        "jmp .Lf99d2a_00099f89\n"
        ".Lf99d2a_0009a318:\n"
        "movl scrCompileGlob+68, %ebx\n" /* line 4114 | outerBlock */
        "testl %ebx, %ebx\n" /* outerBlock */
        "je .Lf99d2a_0009a354\n"
        "movl (%ebx), %eax\n" /* line 3286 */
        "testl %eax, %eax\n"
        "jne .Lf99d2a_0009a354\n"
        "movl scrCompileGlob+60, %eax\n" /* line 3288 */
        "testl %eax, %eax\n"
        "je .Lf99d2a_0009a354\n"
        "movl scrCompileGlob+64, %eax\n" /* line 886 */
        "cmpl $0x3ff, (%eax)\n"
        "jg .Lf99d2a_0009a56e\n"
        ".Lf99d2a_0009a342:\n"
        "movl (%eax), %edx\n" /* line 3291 */
        "movl scrCompileGlob+60, %eax\n"
        "movl %ebx, (%eax, %edx, 4)\n"
        "movl scrCompileGlob+64, %eax\n" /* line 3292 */
        "addl $1, (%eax)\n"
        ".Lf99d2a_0009a354:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 4117 | breakChildCount */
        "movl %ecx, -0x40(%ebp)\n" /* childCount */
        /* { scope 4: i */
        /* { scope 5 */
        "testl %ecx, %ecx\n" /* line 939 */
        "je .Lf99d2a_0009a0ed\n"
        "movl -0x3c(%ebp), %ebx\n" /* line 942 | childBlocks */
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %edi\n" /* removeCount */
        "subl $1, %ecx\n" /* line 943 */
        "jle .Lf99d2a_0009a38a\n"
        "movl $1, %edx\n"
        "movl -0x3c(%ebp), %esi\n" /* childBlocks, removeCount */
        ".Lf99d2a_0009a377:\n"
        "movl (%esi, %edx, 4), %eax\n" /* line 946 | removeCount */
        "movl 8(%eax), %eax\n"
        "cmpl %edi, %eax\n" /* removeCount */
        "cmovll %eax, %edi\n" /* removeCount */
        "addl $1, %edx\n" /* line 943 */
        "cmpl %edx, -0x40(%ebp)\n" /* childCount */
        "jne .Lf99d2a_0009a377\n"
        ".Lf99d2a_0009a38a:\n"
        "movl 0x10(%ebp), %eax\n" /* line 952 | block */
        "movl %edi, 4(%eax)\n" /* removeCount */
        "testl %edi, %edi\n" /* line 954 | removeCount */
        "jle .Lf99d2a_0009a0ed\n"
        "movl $0, -0x38(%ebp)\n" /* i */
        ".Lf99d2a_0009a39f:\n"
        "movl -0x38(%ebp), %ebx\n" /* line 957 | i */
        "sarl $3, %ebx\n"
        "movl 0x10(%ebp), %edx\n" /* block */
        "movzbl 0x10(%ebx, %edx), %edx\n"
        "movb %dl, -0x99(%ebp)\n"
        "movl -0x38(%ebp), %ecx\n" /* i */
        "andl $7, %ecx\n"
        "movzbl %dl, %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf99d2a_0009a3fc\n"
        "movl -0x40(%ebp), %eax\n" /* line 960 | childCount */
        "testl %eax, %eax\n"
        "jle .Lf99d2a_0009a4fc\n"
        "movl -0x3c(%ebp), %esi\n" /* line 966 | childBlocks, removeCount */
        "movl (%esi), %eax\n" /* removeCount */
        "movzbl 0x10(%ebx, %eax), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf99d2a_0009a3fc\n"
        "xorl %edx, %edx\n" /* line 967 */
        ".Lf99d2a_0009a3df:\n"
        "addl $1, %edx\n" /* line 960 */
        "cmpl %edx, -0x40(%ebp)\n" /* childCount */
        "je .Lf99d2a_0009a4fc\n"
        "movl -0x3c(%ebp), %eax\n" /* line 966 | childBlocks */
        "movl (%eax, %edx, 4), %eax\n"
        "movzbl 0x10(%ebx, %eax), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf99d2a_0009a3df\n"
        ".Lf99d2a_0009a3fc:\n"
        "addl $1, -0x38(%ebp)\n" /* line 954 | i */
        "cmpl %edi, -0x38(%ebp)\n" /* removeCount, i */
        "jne .Lf99d2a_0009a39f\n"
        "jmp .Lf99d2a_0009a0ed\n"
        /* } scope */
        /* } scope */
        /* { scope 4: i */
        /* { scope 5 */
        ".Lf99d2a_0009a40a:\n"
        "movl 4(%ebx), %eax\n" /* line 854 */
        "movl %eax, %esi\n" /* line 856 | removeCount */
        "subl 8(%ebx), %esi\n" /* removeCount */
        "je .Lf99d2a_0009a0e3\n"
        "xorl %ecx, %ecx\n" /* line 858 */
        "xorl %edx, %edx\n"
        "movl $0x17, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movl %esi, %edx\n" /* line 617 */
        "movb %dl, (%eax)\n"
        "movl 8(%ebx), %eax\n" /* line 860 */
        "movl %eax, 4(%ebx)\n"
        /* } scope */
        /* } scope */
        "cmpb $0, -0x55(%ebp)\n" /* line 4112 | hasDefault */
        "je .Lf99d2a_0009a0ed\n"
        "jmp .Lf99d2a_0009a318\n"
        /* } scope */
        /* } scope */
        ".Lf99d2a_0009a450:\n"
        "movl $0, -0x5c(%ebp)\n" /* line 4277 | num */
        "xorl %eax, %eax\n" /* expr */
        "xorl %edx, %edx\n"
        "jmp .Lf99d2a_0009a1bf\n"
        /* { scope 2: hasDefault, breakChildCount, oldBreakChildBlocks, oldBreakChildCount, ... */
        ".Lf99d2a_0009a460:\n"
        "movl %ebx, %eax\n" /* line 2885 */
        "calll EmitValue\n"
        "jmp .Lf99d2a_00099d99\n"
        /* } scope */
        /* { scope 2: hasDefault, breakChildCount, oldBreakChildBlocks, oldBreakChildCount, ... */
        /* { scope 3: j, childCount, childBlocks */
        ".Lf99d2a_0009a46c:\n"
        "movl $str_0021db08, 4(%esp)\n" /* line 4091 */
        "movl 0xc(%ebp), %ecx\n" /* endSourcePos */
        "movl %ecx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf99d2a_0009a108\n"
        ".Lf99d2a_0009a484:\n"
        "movb $0, -0x55(%ebp)\n" /* line 4057 | hasDefault */
        "jmp .Lf99d2a_0009a0c2\n"
        ".Lf99d2a_0009a48d:\n"
        "movl 4(%esi), %esi\n" /* line 4015 | removeCount */
        "cmpl $2, scrCompilePub+40\n" /* line 255 */
        "je .Lf99d2a_0009a58c\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 266 */
        "jne .Lf99d2a_0009a5a6\n"
        ".Lf99d2a_0009a4aa:\n"
        "movl $1, 4(%esp)\n" /* line 268 */
        "movl %esi, (%esp)\n"
        "calll SL_TransferRefToUser\n"
        /* { scope 4: i */
        ".Lf99d2a_0009a4ba:\n"
        "cmpl $2, scrCompilePub+40\n" /* line 4323 */
        "je .Lf99d2a_00099f89\n"
        "movl $0x10, (%esp)\n" /* line 4329 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %ebx\n" /* expr, pos */
        "movl %esi, (%eax)\n" /* line 4330 | caseStatement, expr */
        "movl $0, (%esp)\n" /* line 4332 */
        "calll TempMalloc\n"
        "movl %eax, 4(%ebx)\n" /* expr, pos */
        "movl %edi, 8(%ebx)\n" /* line 4333 | pos3, pos */
        "movl scrCompileGlob+40, %eax\n" /* line 4334 | expr */
        "movl %eax, 0xc(%ebx)\n" /* expr, pos */
        "movl %ebx, scrCompileGlob+40\n" /* line 4335 | pos */
        "jmp .Lf99d2a_00099f89\n"
        /* } scope */
        /* { scope 4: i */
        /* { scope 5 */
        ".Lf99d2a_0009a4fc:\n"
        "movl $1, %eax\n" /* line 969 */
        "shll %cl, %eax\n"
        "orb %al, -0x99(%ebp)\n"
        "movzbl -0x99(%ebp), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* block */
        "movb %al, 0x10(%ebx, %edx)\n"
        "addl $1, -0x38(%ebp)\n" /* line 954 | i */
        "cmpl %edi, -0x38(%ebp)\n" /* removeCount, i */
        "jne .Lf99d2a_0009a39f\n"
        "jmp .Lf99d2a_0009a0ed\n"
        /* } scope */
        /* } scope */
        ".Lf99d2a_0009a529:\n"
        "movl 4(%esi), %eax\n" /* line 4006 | removeCount */
        "movl %eax, (%esp)\n"
        "calll IsValidArrayIndex\n"
        "testb %al, %al\n"
        "jne .Lf99d2a_0009a55c\n"
        "movl 4(%esi), %eax\n" /* line 4008 | removeCount */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021dac0, (%esp)\n" /* "case index %d out of range" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* removeCount */
        "calll CompileError\n"
        "jmp .Lf99d2a_00099f89\n"
        ".Lf99d2a_0009a55c:\n"
        "movl 4(%esi), %eax\n" /* line 4011 | removeCount */
        "movl %eax, (%esp)\n"
        "calll GetInternalVariableIndex\n"
        "movl %eax, %esi\n" /* removeCount */
        "jmp .Lf99d2a_0009a4ba\n"
        ".Lf99d2a_0009a56e:\n"
        "movl $str_0021d7d8, 4(%esp)\n" /* line 888 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl scrCompileGlob+64, %eax\n"
        "jmp .Lf99d2a_0009a342\n"
        ".Lf99d2a_0009a58c:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf99d2a_0009a4ba\n"
        "movl %esi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf99d2a_0009a4ba\n"
        ".Lf99d2a_0009a5a6:\n"
        "movl %esi, (%esp)\n" /* line 267 */
        "calll SL_AddRefToString\n"
        "jmp .Lf99d2a_0009a4aa\n"
    );
}

/* line 4779 */
static __attribute__((naked))
unsigned int EmitThreadInternal(sval_t val, sval_t sourcePos, sval_t endSourcePos, scr_block_t *block)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4779 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* endSourcePos */
        "movl %edx, -0x24(%ebp)\n" /* endSourcePos */
        "movl 0xc(%ebp), %ecx\n" /* block */
        "movl %ecx, -0x28(%ebp)\n" /* block */
        "movl %eax, scrCompileGlob+12\n" /* line 4781 | threadId */
        "movl -0x20(%ebp), %eax\n" /* line 4783 | threadId */
        "movl %eax, (%esp)\n" /* threadId */
        "calll AddThreadStartOpcodePos\n"
        "movl $0, scrCompileGlob+16\n" /* line 4785 */
        "movl $0, scrCompileGlob+20\n" /* line 4786 */
        "movl $0, scrCompileGlob+24\n" /* line 4787 */
        "movl -0x1c(%ebp), %edx\n" /* line 4789 */
        "movl 4(%edx), %ebx\n" /* index */
        "cmpl $2, scrCompilePub+40\n" /* line 255 */
        "je .Lf9a5b4_0009a7b4\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 266 */
        "jne .Lf9a5b4_0009a78e\n"
        ".Lf9a5b4_0009a61d:\n"
        "movl $2, 4(%esp)\n" /* line 268 */
        "movl %ebx, (%esp)\n" /* stringValue */
        "calll SL_TransferRefToUser\n"
        ".Lf9a5b4_0009a62d:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 4791 */
        "movl 8(%ecx), %eax\n" /* threadId */
        "movl (%eax), %eax\n" /* line 3824 */
        "movl 4(%eax), %esi\n"
        "testl %esi, %esi\n" /* line 3825 */
        "jne .Lf9a5b4_0009a655\n"
        "jmp .Lf9a5b4_0009a6af\n"
        /* { scope 1 */
        ".Lf9a5b4_0009a63e:\n"
        "movl $0, 4(%esp)\n" /* line 1100 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        /* } scope */
        "movl 4(%esi), %esi\n" /* line 3824 */
        "testl %esi, %esi\n" /* line 3825 */
        "je .Lf9a5b4_0009a6af\n"
        ".Lf9a5b4_0009a655:\n"
        "movl (%esi), %eax\n" /* line 3827 */
        "movl 4(%eax), %edi\n"
        "movl (%eax), %eax\n"
        /* { scope 1 */
        "movl -0x28(%ebp), %edx\n" /* line 1093 | block */
        "movl %edx, (%esp)\n"
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "calll Scr_FindLocalVarIndex\n"
        "movl %eax, %ebx\n" /* index */
        "cmpl $1, %eax\n" /* line 1094 */
        "sbbl %eax, %eax\n"
        "addl $0x32, %eax\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "calll EmitOpcode\n"
        "testl %ebx, %ebx\n" /* line 1098 | index */
        "je .Lf9a5b4_0009a63e\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movb %bl, (%eax)\n" /* line 617 | stringValue */
        "movl $0, 4(%esp)\n" /* line 1100 */
        "movl %edi, (%esp)\n"
        "calll AddOpcodePos\n"
        /* } scope */
        "movl 4(%esi), %esi\n" /* line 3824 */
        "testl %esi, %esi\n" /* line 3825 */
        "jne .Lf9a5b4_0009a655\n"
        ".Lf9a5b4_0009a6af:\n"
        "xorl %ecx, %ecx\n" /* line 4735 */
        "xorl %edx, %edx\n"
        "movl $0x35, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 4736 */
        "movl -0x20(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl -0x1c(%ebp), %edx\n" /* line 4792 */
        "movl 0xc(%edx), %eax\n" /* threadId */
        /* { scope 1 */
        "movl (%eax), %eax\n" /* line 4667 */
        "movl 4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf9a5b4_0009a73f\n"
        "movl imp_scrVarPub, %esi\n"
        ".Lf9a5b4_0009a6e5:\n"
        "movl 4(%edx), %ebx\n" /* line 4669 | index */
        "testl %ebx, %ebx\n" /* line 3985 | index */
        "je .Lf9a5b4_0009a702\n"
        "cmpb $0, 0xb(%esi)\n" /* line 3987 */
        "jne .Lf9a5b4_0009a724\n"
        "movl %ebx, %ecx\n" /* index */
        ".Lf9a5b4_0009a6f4:\n"
        "movl (%ecx), %eax\n" /* line 3991 */
        "cmpl $0x2d, (%eax)\n"
        "jne .Lf9a5b4_0009a724\n"
        "movl 4(%ecx), %ecx\n" /* line 3993 */
        "testl %ecx, %ecx\n" /* line 3989 */
        "jne .Lf9a5b4_0009a6f4\n"
        ".Lf9a5b4_0009a702:\n"
        "movl $1, %ecx\n"
        "movl (%edx), %eax\n" /* line 4670 */
        "movl %ecx, %edx\n"
        "andl $1, %edx\n"
        "movl -0x28(%ebp), %ecx\n" /* block */
        "movl %ecx, (%esp)\n"
        "movl -0x24(%ebp), %ecx\n" /* endSourcePos */
        "calll EmitStatement\n"
        "testl %ebx, %ebx\n" /* line 4667 | index */
        "je .Lf9a5b4_0009a73f\n"
        ".Lf9a5b4_0009a720:\n"
        "movl %ebx, %edx\n" /* index */
        "jmp .Lf9a5b4_0009a6e5\n"
        ".Lf9a5b4_0009a724:\n"
        "xorl %ecx, %ecx\n" /* line 3989 */
        "movl (%edx), %eax\n" /* line 4670 */
        "movl %ecx, %edx\n"
        "andl $1, %edx\n"
        "movl -0x28(%ebp), %ecx\n" /* block */
        "movl %ecx, (%esp)\n"
        "movl -0x24(%ebp), %ecx\n" /* endSourcePos */
        "calll EmitStatement\n"
        "testl %ebx, %ebx\n" /* line 4667 | index */
        "jne .Lf9a5b4_0009a720\n"
        /* } scope */
        ".Lf9a5b4_0009a73f:\n"
        "xorl %ecx, %ecx\n" /* line 577 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, 4(%esp)\n" /* line 4794 */
        "movl -0x24(%ebp), %eax\n" /* endSourcePos, threadId */
        "movl %eax, (%esp)\n" /* threadId */
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 4795 */
        "movl $0xfffffffe, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl scrCompileGlob+24, %eax\n" /* line 4799 | threadId */
        "shll $5, %eax\n" /* threadId */
        "addl scrCompileGlob+20, %eax\n" /* threadId */
        "cmpl $0x7ff, %eax\n" /* threadId */
        "jg .Lf9a5b4_0009a79b\n"
        "addl $0x2c, %esp\n" /* line 4801 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9a5b4_0009a78e:\n"
        "movl %ebx, (%esp)\n" /* line 267 | stringValue */
        "calll SL_AddRefToString\n"
        "jmp .Lf9a5b4_0009a61d\n"
        ".Lf9a5b4_0009a79b:\n"
        "movl $str_0021db3c, 0xc(%ebp)\n" /* line 4800 | block */
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, 8(%ebp)\n" /* endSourcePos */
        "addl $0x2c, %esp\n" /* line 4801 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp CompileError\n" /* line 4800 */
        /* { scope 1 */
        ".Lf9a5b4_0009a7b4:\n"
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf9a5b4_0009a62d\n"
        "movl %ebx, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf9a5b4_0009a62d\n"
    );
}

/* line 4972 */
__attribute__((naked))
unsigned int ScriptCompile(sval_t val, unsigned int fileId, unsigned int scriptId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4972 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        /* { scope 1: pos, emptyValue */
        "movl 0xc(%ebp), %eax\n" /* line 4991 | fileId */
        "movl %eax, scrCompileGlob+8\n"
        "movb $0, scrCompileGlob+28\n" /* line 4992 */
        "movl imp_scrAnimPub, %eax\n" /* line 4993 */
        "movl $0, 0x414(%eax)\n"
        "movl $0, scrCompilePub+40\n" /* line 4994 */
        "movl scrCompilePub+4, %eax\n" /* line 4996 */
        "testl %eax, %eax\n"
        "jne .Lf9a7ce_0009aec2\n"
        "movl $0, -0x68(%ebp)\n" /* precachescriptList */
        "movl -0x68(%ebp), %ecx\n" /* precachescriptList */
        ".Lf9a7ce_0009a819:\n"
        "movl %ecx, scrCompileGlob+84\n" /* line 4997 */
        "testl %ecx, %ecx\n" /* line 4999 */
        "je .Lf9a7ce_0009a831\n"
        "movl scrCompileGlob+88, %eax\n" /* line 5001 */
        "movl %eax, 8(%ecx)\n"
        "movl %ecx, scrCompileGlob+88\n" /* line 5002 */
        ".Lf9a7ce_0009a831:\n"
        "movl 8(%ebp), %ebx\n" /* line 5005 | val, i */
        "movl (%ebx), %eax\n" /* i */
        /* { scope 2: stmttblock */
        "movl (%eax), %eax\n" /* line 4964 */
        "movl 4(%eax), %edi\n" /* node */
        "testl %edi, %edi\n" /* node */
        "jne .Lf9a7ce_0009a898\n"
        "jmp .Lf9a7ce_0009aea7\n"
        ".Lf9a7ce_0009a844:\n"
        "movl 8(%ebx), %ebx\n" /* line 4956 | sourcePos */
        /* { scope 3 */
        "movl %esi, (%esp)\n" /* line 1663 */
        "calll SL_AddRefToString\n"
        /* { scope 4 */
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "je .Lf9a7ce_0009a8d7\n"
        /* } scope */
        ".Lf9a7ce_0009a858:\n"
        "movl scrCompileGlob+84, %eax\n" /* line 1665 */
        "movw %si, (%eax)\n" /* stringValue */
        "movl scrCompileGlob+84, %eax\n" /* line 1666 */
        "movl %ebx, 4(%eax)\n"
        "movl scrCompileGlob+84, %eax\n" /* line 1667 */
        "movb $1, 2(%eax)\n"
        "addl $0xc, scrCompileGlob+84\n" /* line 1668 */
        "movl %esi, 4(%esp)\n" /* line 1669 | stringValue */
        "movl scrCompilePub+12, %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetObjectA\n"
        /* } scope */
        "movl 4(%edi), %edi\n" /* line 4964 | node */
        "testl %edi, %edi\n" /* node */
        "je .Lf9a7ce_0009a8e4\n"
        ".Lf9a7ce_0009a898:\n"
        "movl (%edi), %ebx\n" /* line 4965 | node, sourcePos */
        "movl 4(%ebx), %eax\n" /* line 4954 | node */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, (%esp)\n"
        "calll Scr_CreateCanonicalFilename\n"
        "movl %eax, %esi\n" /* threadId */
        "movl 4(%ebx), %eax\n" /* line 4955 | node, stringValue */
        /* { scope 3 */
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf9a7ce_0009a844\n"
        "movl %eax, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        "movl 8(%ebx), %ebx\n" /* line 4956 | sourcePos */
        /* { scope 3 */
        "movl %esi, (%esp)\n" /* line 1663 */
        "calll SL_AddRefToString\n"
        /* { scope 4 */
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf9a7ce_0009a858\n"
        ".Lf9a7ce_0009a8d7:\n"
        "movl %esi, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf9a7ce_0009a858\n"
        ".Lf9a7ce_0009a8e4:\n"
        "movl 8(%ebp), %eax\n" /* val */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf9a7ce_0009a8e7:\n"
        "movl 4(%eax), %eax\n" /* line 5006 */
        "movl %eax, -0x6c(%ebp)\n"
        /* { scope 2: stmttblock */
        "movb $0, scrCompileGlob+29\n" /* line 4930 */
        "movl (%eax), %eax\n" /* line 4932 */
        "movl 4(%eax), %edi\n" /* node */
        "testl %edi, %edi\n" /* node */
        "jne .Lf9a7ce_0009a918\n"
        "jmp .Lf9a7ce_0009a94a\n"
        ".Lf9a7ce_0009a8ff:\n"
        "cmpl $0x46, %eax\n" /* line 4748 */
        "je .Lf9a7ce_0009a9f6\n"
        "cmpl $0x44, %eax\n"
        "je .Lf9a7ce_0009aa0f\n"
        ".Lf9a7ce_0009a911:\n"
        "movl 4(%edi), %edi\n" /* line 4932 | node */
        "testl %edi, %edi\n" /* node */
        "je .Lf9a7ce_0009a94a\n"
        ".Lf9a7ce_0009a918:\n"
        "movl (%edi), %ecx\n" /* line 4933 | node */
        "movl %ecx, -0x54(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 4748 */
        "cmpl $0x45, %eax\n"
        "jne .Lf9a7ce_0009a8ff\n"
        "cmpb $0, scrCompileGlob+29\n" /* line 4751 */
        "jne .Lf9a7ce_0009ad4f\n"
        "movb $1, scrCompileGlob+29\n" /* line 4756 */
        "movl -0x54(%ebp), %edx\n" /* line 4757 */
        "movl 4(%edx), %eax\n"
        "movl %eax, scrCompileGlob+32\n"
        "movl 4(%edi), %edi\n" /* line 4932 | node */
        "testl %edi, %edi\n" /* node */
        "jne .Lf9a7ce_0009a918\n"
        ".Lf9a7ce_0009a94a:\n"
        "cmpb $0, scrCompileGlob+29\n" /* line 4935 */
        "jne .Lf9a7ce_0009aeda\n"
        ".Lf9a7ce_0009a957:\n"
        "movb $1, scrCompileGlob+36\n" /* line 4938 */
        "movb $1, scrCompileGlob+37\n" /* line 4939 */
        "movl -0x6c(%ebp), %ecx\n" /* line 4942 */
        "movl (%ecx), %eax\n"
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "testl %eax, %eax\n"
        "jne .Lf9a7ce_0009a993\n"
        "jmp .Lf9a7ce_0009aa71\n"
        ".Lf9a7ce_0009a979:\n"
        "cmpl $0x44, %eax\n" /* line 4893 */
        "je .Lf9a7ce_0009ab6e\n"
        ".Lf9a7ce_0009a982:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 4942 */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf9a7ce_0009aa71\n"
        ".Lf9a7ce_0009a993:\n"
        "movl (%eax), %ebx\n" /* line 4943 | node */
        "movl %ebx, -0x54(%ebp)\n" /* node */
        "movl (%ebx), %eax\n" /* line 4893 | node */
        "cmpl $0x45, %eax\n"
        "je .Lf9a7ce_0009aa59\n"
        "jle .Lf9a7ce_0009a979\n"
        "cmpl $0x46, %eax\n"
        "je .Lf9a7ce_0009ab62\n"
        "cmpl $0x47, %eax\n"
        "jne .Lf9a7ce_0009a982\n"
        "cmpb $0, scrCompileGlob+29\n" /* line 4914 */
        "jne .Lf9a7ce_0009ae71\n"
        "movl -0x54(%ebp), %ecx\n" /* line 4919 */
        "movl 0xc(%ecx), %ebx\n" /* node */
        "movl 4(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 4(%esp)\n" /* node */
        "movl %eax, (%esp)\n"
        "calll Scr_UsingTree\n"
        "movl -0x54(%ebp), %ebx\n" /* line 4920 | node */
        "movl 4(%ebx), %eax\n" /* node, stringValue */
        /* { scope 3 */
        "cmpb $0, scrCompileGlob+28\n" /* line 200 */
        "jne .Lf9a7ce_0009a982\n"
        "movl %eax, (%esp)\n" /* line 206 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf9a7ce_0009a982\n"
        /* } scope */
        ".Lf9a7ce_0009a9f6:\n"
        "cmpb $0, scrCompileGlob+29\n" /* line 4761 */
        "je .Lf9a7ce_0009ae8c\n"
        "movb $0, scrCompileGlob+29\n" /* line 4766 */
        "jmp .Lf9a7ce_0009a911\n"
        ".Lf9a7ce_0009aa0f:\n"
        "cmpb $0, scrCompileGlob+29\n" /* line 4770 */
        "jne .Lf9a7ce_0009ad86\n"
        "movl $7, -0x50(%ebp)\n"
        ".Lf9a7ce_0009aa23:\n"
        "movl -0x54(%ebp), %ebx\n" /* line 4771 | node */
        "movl 0x10(%ebx), %esi\n" /* node, threadPtr */
        "movl 4(%ebx), %ebx\n" /* node */
        "movl %ebx, 4(%esp)\n" /* node */
        "movl scrCompileGlob+8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetObjectA\n"
        "movl -0x50(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "movl %esi, %ecx\n" /* threadPtr */
        "movl %ebx, %edx\n" /* node */
        "calll SpecifyThreadPosition\n"
        "jmp .Lf9a7ce_0009a911\n"
        ".Lf9a7ce_0009aa59:\n"
        "movb $1, scrCompileGlob+29\n" /* line 4897 */
        "movl -0x3c(%ebp), %eax\n" /* line 4942 */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "testl %eax, %eax\n"
        "jne .Lf9a7ce_0009a993\n"
        /* } scope */
        ".Lf9a7ce_0009aa71:\n"
        "movl $0, (%esp)\n" /* line 5009 */
        "calll TempMalloc\n"
        "movl imp_scrVarPub, %edx\n"
        "subl 0x48(%edx), %eax\n"
        "movl %eax, scrCompilePub+48\n"
        "calll Hunk_ClearTempMemoryHigh\n" /* line 5011 */
        "movl scrCompilePub+4, %edx\n" /* line 5014 */
        "movl %edx, -0x64(%ebp)\n" /* far_function_count */
        "testl %edx, %edx\n" /* line 5016 */
        "jg .Lf9a7ce_0009aef4\n"
        ".Lf9a7ce_0009aaa1:\n"
        "movl -0x68(%ebp), %eax\n" /* line 5066 | precachescriptList */
        "testl %eax, %eax\n"
        "je .Lf9a7ce_0009aabb\n"
        "movl -0x68(%ebp), %ecx\n" /* line 5069 | precachescriptList */
        "movl 8(%ecx), %eax\n"
        "movl %eax, scrCompileGlob+88\n"
        "movl %ecx, (%esp)\n" /* line 5070 */
        "calll Z_FreeInternal\n"
        /* { scope 2: stmttblock */
        ".Lf9a7ce_0009aabb:\n"
        "movl $0, -0x34(%ebp)\n" /* line 2360 */
        "movl $0, -0x38(%ebp)\n" /* line 2361 | emptyValue */
        "movl 0xc(%ebp), %ebx\n" /* line 2363 | fileId, threadId */
        "movl %ebx, (%esp)\n" /* threadId */
        "calll FindNextSibling\n"
        "movl %eax, %esi\n" /* threadPtr */
        "testl %eax, %eax\n"
        "jne .Lf9a7ce_0009ab33\n"
        /* } scope */
        ".Lf9a7ce_0009aada:\n"
        "movl $6, -0x1c(%ebp)\n" /* line 5076 */
        "leal -0x20(%ebp), %eax\n" /* line 5077 | value */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* scriptId */
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        /* } scope */
        ".Lf9a7ce_0009aaf3:\n"
        "addl $0x8c, %esp\n" /* line 5078 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pos, emptyValue */
        /* { scope 2: stmttblock */
        ".Lf9a7ce_0009aafe:\n"
        "movl %eax, (%esp)\n" /* line 2372 */
        "calll Scr_EvalVariable\n"
        "movl %eax, -0x30(%ebp)\n" /* pos */
        "movl %edx, -0x2c(%ebp)\n"
        "cmpl $0xd, -0x2c(%ebp)\n" /* line 2373 */
        "je .Lf9a7ce_0009aeae\n"
        "movl $1, %ecx\n" /* line 2380 */
        "leal -0x30(%ebp), %edx\n" /* pos */
        "movl %ebx, %eax\n" /* threadId */
        "calll LinkThread\n"
        ".Lf9a7ce_0009ab25:\n"
        "movl %esi, (%esp)\n" /* line 2363 | threadPtr */
        "calll FindNextSibling\n"
        "movl %eax, %esi\n" /* threadPtr */
        "testl %eax, %eax\n"
        "je .Lf9a7ce_0009aada\n"
        ".Lf9a7ce_0009ab33:\n"
        "movl %esi, (%esp)\n" /* line 2365 | threadPtr */
        "calll FindObject\n"
        "movl %eax, %ebx\n" /* threadId */
        "movl $1, 4(%esp)\n" /* line 2368 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 2370 */
        "jne .Lf9a7ce_0009aafe\n"
        "movl $1, %ecx\n" /* line 2384 */
        "leal -0x38(%ebp), %edx\n" /* emptyValue */
        "movl %ebx, %eax\n" /* threadId */
        "calll LinkThread\n"
        "jmp .Lf9a7ce_0009ab25\n"
        /* } scope */
        /* { scope 2: stmttblock */
        ".Lf9a7ce_0009ab62:\n"
        "movb $0, scrCompileGlob+29\n" /* line 4902 */
        "jmp .Lf9a7ce_0009a982\n"
        ".Lf9a7ce_0009ab6e:\n"
        "movl -0x54(%ebp), %eax\n" /* line 4906 */
        "addl $0x18, %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* stmttblock */
        "movl -0x54(%ebp), %edx\n"
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl -0x54(%ebp), %ecx\n"
        "movl 8(%ecx), %ebx\n" /* node */
        /* { scope 3 */
        "movb $0, scrCompileGlob+80\n" /* line 4806 */
        "movl $0x118, (%esp)\n" /* line 4808 */
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl -0x54(%ebp), %edx\n"
        "movl %eax, 0x18(%edx)\n"
        "movl $0, (%eax)\n" /* line 4809 */
        "movl 0x18(%edx), %eax\n" /* line 4810 */
        "movl $0, 4(%eax)\n"
        "movl 0x18(%edx), %eax\n" /* line 4811 */
        "movl $0, 0xc(%eax)\n"
        "movl 0x18(%edx), %eax\n" /* line 4812 */
        "movl $0, 8(%eax)\n"
        "movl 0x18(%edx), %eax\n" /* line 4813 */
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl 0x18(%edx), %edi\n" /* line 4814 | block */
        "movl (%ebx), %ebx\n" /* line 4742 | node */
        /* { scope 4 */
        ".Lf9a7ce_0009abd9:\n"
        "movl 4(%ebx), %ebx\n" /* line 3836 | threadId */
        "testl %ebx, %ebx\n" /* line 3837 | threadId */
        "je .Lf9a7ce_0009ac2f\n"
        ".Lf9a7ce_0009abe0:\n"
        "movl (%ebx), %eax\n" /* line 3839 | threadId */
        "movl (%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        /* { scope 5 */
        /* { scope 6 */
        "movl (%edi), %eax\n" /* line 904 */
        "testl %eax, %eax\n"
        "jne .Lf9a7ce_0009abd9\n"
        "movl 0xc(%edi), %esi\n" /* line 907 */
        "testl %esi, %esi\n"
        "jle .Lf9a7ce_0009ac14\n"
        "movl -0x44(%ebp), %edx\n" /* line 909 */
        "cmpl 0x18(%edi), %edx\n"
        "je .Lf9a7ce_0009abd9\n"
        "movl %edi, %ecx\n"
        "xorl %edx, %edx\n"
        "jmp .Lf9a7ce_0009ac0d\n"
        ".Lf9a7ce_0009ac02:\n"
        "movl 0x1c(%ecx), %eax\n"
        "addl $4, %ecx\n"
        "cmpl %eax, -0x44(%ebp)\n"
        "je .Lf9a7ce_0009abd9\n"
        ".Lf9a7ce_0009ac0d:\n"
        "addl $1, %edx\n" /* line 907 */
        "cmpl %esi, %edx\n"
        "jne .Lf9a7ce_0009ac02\n"
        ".Lf9a7ce_0009ac14:\n"
        "cmpl $0x3f, %esi\n" /* line 894 */
        "jg .Lf9a7ce_0009ad6a\n"
        ".Lf9a7ce_0009ac1d:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 914 */
        "movl %ecx, 0x18(%edi, %esi, 4)\n"
        "addl $1, 0xc(%edi)\n" /* line 918 */
        /* } scope */
        /* } scope */
        "movl 4(%ebx), %ebx\n" /* line 3836 | threadId */
        "testl %ebx, %ebx\n" /* line 3837 | threadId */
        "jne .Lf9a7ce_0009abe0\n"
        /* } scope */
        ".Lf9a7ce_0009ac2f:\n"
        "movl -0x48(%ebp), %ebx\n" /* line 4815 | stmttblock, node */
        "movl (%ebx), %esi\n" /* node, block */
        /* { scope 4 */
        /* { scope 5 */
        "movl -0x4c(%ebp), %edx\n" /* line 4679 */
        "movl (%edx), %eax\n"
        "movl 4(%eax), %ebx\n" /* node */
        "testl %ebx, %ebx\n" /* node */
        "je .Lf9a7ce_0009ac50\n"
        ".Lf9a7ce_0009ac40:\n"
        "movl (%ebx), %eax\n" /* line 4680 | node */
        "movl %esi, %edx\n" /* threadPtr */
        "calll Scr_CalcLocalVarsStatement\n"
        "movl 4(%ebx), %ebx\n" /* line 4679 | node */
        "testl %ebx, %ebx\n" /* node */
        "jne .Lf9a7ce_0009ac40\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf9a7ce_0009ac50:\n"
        "cmpb $0, scrCompileGlob+29\n" /* line 4907 */
        "je .Lf9a7ce_0009ada1\n"
        /* { scope 3 */
        "movl imp_scrVarPub, %ebx\n" /* line 4864 | node */
        "cmpb $0, 0xb(%ebx)\n" /* node */
        "je .Lf9a7ce_0009b0fa\n"
        "movl $1, scrCompilePub+40\n" /* line 4879 */
        "movb $0, scrCompileGlob+38\n" /* line 4821 */
        "movl $0, scrCompileGlob+40\n" /* line 4822 */
        "movb $0, scrCompileGlob+44\n" /* line 4824 */
        "movb $0, scrCompileGlob+45\n" /* line 4825 */
        "movl $0, scrCompileGlob+48\n" /* line 4826 */
        "movb $0, scrCompileGlob+52\n" /* line 4828 */
        "movb $0, scrCompileGlob+53\n" /* line 4829 */
        "movl $0, scrCompileGlob+56\n" /* line 4830 */
        "movl $0, scrCompileGlob+60\n" /* line 4832 */
        "movl $0, scrCompileGlob+72\n" /* line 4833 */
        "cmpb $0, scrCompileGlob+37\n" /* line 4835 */
        "jne .Lf9a7ce_0009b07c\n"
        ".Lf9a7ce_0009acd9:\n"
        "movl -0x54(%ebp), %edx\n" /* line 4882 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl scrCompileGlob+8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, %esi\n" /* begin_pos */
        /* { scope 4 */
        "movl $1, 4(%esp)\n" /* line 2423 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetVariableValueAddress\n"
        "movl %eax, %ebx\n" /* threadId */
        "movl $0, (%esp)\n"
        "calll TempMalloc\n"
        "movl %eax, (%ebx)\n" /* threadId */
        /* } scope */
        "movl -0x48(%ebp), %ecx\n" /* line 4884 | stmttblock */
        "movl (%ecx), %eax\n"
        "movl -0x54(%ebp), %ebx\n" /* node */
        "movl 0x14(%ebx), %edx\n" /* node */
        "movl 0x10(%ebx), %ecx\n" /* node */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl %ebx, %edx\n" /* node */
        "movl %esi, %eax\n" /* threadId */
        "calll EmitThreadInternal\n"
        ".Lf9a7ce_0009ad40:\n"
        "movl $0, scrCompilePub+40\n" /* line 4887 */
        "jmp .Lf9a7ce_0009a982\n"
        /* } scope */
        ".Lf9a7ce_0009ad4f:\n"
        "movl $str_0021db60, 4(%esp)\n" /* line 4753 */
        "movl -0x54(%ebp), %ebx\n" /* node */
        "movl 4(%ebx), %eax\n" /* node */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9a7ce_0009a911\n"
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        /* { scope 6 */
        ".Lf9a7ce_0009ad6a:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%edi), %esi\n"
        "jmp .Lf9a7ce_0009ac1d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf9a7ce_0009ad86:\n"
        "movl imp_scrVarPub, %eax\n" /* line 4770 */
        "cmpb $0, 0xb(%eax)\n"
        "je .Lf9a7ce_0009a911\n"
        "movl $0xc, -0x50(%ebp)\n"
        "jmp .Lf9a7ce_0009aa23\n"
        ".Lf9a7ce_0009ada1:\n"
        "movb $0, scrCompileGlob+38\n" /* line 4821 */
        "movl $0, scrCompileGlob+40\n" /* line 4822 */
        "movb $0, scrCompileGlob+44\n" /* line 4824 */
        "movb $0, scrCompileGlob+45\n" /* line 4825 */
        "movl $0, scrCompileGlob+48\n" /* line 4826 */
        "movb $0, scrCompileGlob+52\n" /* line 4828 */
        "movb $0, scrCompileGlob+53\n" /* line 4829 */
        "movl $0, scrCompileGlob+56\n" /* line 4830 */
        "movl $0, scrCompileGlob+60\n" /* line 4832 */
        "movl $0, scrCompileGlob+72\n" /* line 4833 */
        "cmpb $0, scrCompileGlob+36\n" /* line 4835 */
        "jne .Lf9a7ce_0009b0bb\n"
        ".Lf9a7ce_0009ae03:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 4850 */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl scrCompileGlob+8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, %esi\n" /* block */
        /* { scope 3 */
        "movl $1, 4(%esp)\n" /* line 2423 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetVariableValueAddress\n"
        "movl %eax, %ebx\n" /* threadId */
        "movl $0, (%esp)\n"
        "calll TempMalloc\n"
        "movl %eax, (%ebx)\n" /* threadId */
        /* } scope */
        "movl -0x48(%ebp), %ebx\n" /* line 4852 | stmttblock, node */
        "movl (%ebx), %eax\n" /* node */
        "movl -0x54(%ebp), %ecx\n"
        "movl 0x14(%ecx), %edx\n"
        "movl %ecx, %ebx\n" /* node */
        "movl 0x10(%ecx), %ecx\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl %ebx, %edx\n" /* node */
        "movl %esi, %eax\n" /* threadId */
        "calll EmitThreadInternal\n"
        "jmp .Lf9a7ce_0009a982\n"
        ".Lf9a7ce_0009ae71:\n"
        "movl $str_0021dba4, 4(%esp)\n" /* line 4916 */
        "movl -0x54(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9a7ce_0009a982\n"
        ".Lf9a7ce_0009ae8c:\n"
        "movl $str_0021db74, 4(%esp)\n" /* line 4763 */
        "movl -0x54(%ebp), %ecx\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9a7ce_0009a911\n"
        ".Lf9a7ce_0009aea7:\n"
        "movl %ebx, %eax\n" /* node */
        "jmp .Lf9a7ce_0009a8e7\n"
        /* } scope */
        /* { scope 2: stmttblock */
        ".Lf9a7ce_0009aeae:\n"
        "leal -0x38(%ebp), %eax\n" /* line 2375 | emptyValue */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* threadPtr */
        "calll SetVariableValue\n"
        "jmp .Lf9a7ce_0009ab25\n"
        /* } scope */
        ".Lf9a7ce_0009aec2:\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 4996 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, -0x68(%ebp)\n" /* precachescriptList */
        "movl %eax, %ecx\n"
        "jmp .Lf9a7ce_0009a819\n"
        /* { scope 2: stmttblock */
        ".Lf9a7ce_0009aeda:\n"
        "movl $str_0021db8c, 4(%esp)\n" /* line 4936 */
        "movl scrCompileGlob+32, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9a7ce_0009a957\n"
        /* } scope */
        ".Lf9a7ce_0009aef4:\n"
        "xorl %ebx, %ebx\n" /* line 5016 | i */
        ".Lf9a7ce_0009aef6:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 5018 | i */
        "movl -0x68(%ebp), %ecx\n" /* precachescriptList */
        "leal (%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* precachescript */
        "movzwl (%eax), %edi\n" /* line 5020 | threadPtr */
        "movl %edi, (%esp)\n" /* threadPtr */
        "calll SL_ConvertToString\n"
        "movl %eax, (%esp)\n"
        "calll Scr_LoadScript\n"
        "movl %eax, -0x5c(%ebp)\n" /* includeFileId */
        "testl %eax, %eax\n" /* line 5021 */
        "je .Lf9a7ce_0009b1e4\n"
        "movl %edi, (%esp)\n" /* line 5026 | threadPtr */
        "calll SL_RemoveRefToString\n"
        "movl -0x60(%ebp), %eax\n" /* line 5027 | precachescript */
        "cmpb $0, 2(%eax)\n"
        "jne .Lf9a7ce_0009af3e\n"
        "addl $1, %ebx\n" /* i */
        ".Lf9a7ce_0009af34:\n"
        "cmpl %ebx, -0x64(%ebp)\n" /* line 5016 | i, far_function_count */
        "jg .Lf9a7ce_0009aef6\n"
        "jmp .Lf9a7ce_0009aaa1\n"
        ".Lf9a7ce_0009af3e:\n"
        "addl $1, %ebx\n" /* line 5030 | i */
        "movl %ebx, -0x40(%ebp)\n" /* i */
        "cmpl %ebx, -0x64(%ebp)\n" /* i, far_function_count */
        "jle .Lf9a7ce_0009afa2\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 5032 | i */
        "movl -0x68(%ebp), %ecx\n" /* precachescriptList */
        "leal (%ecx, %eax, 4), %esi\n" /* toThreadId */
        "cmpb $0, 2(%esi)\n" /* line 5033 | toThreadId */
        "je .Lf9a7ce_0009afa2\n"
        "movzwl (%esi), %eax\n" /* line 5035 | toThreadId */
        "cmpl %eax, %edi\n" /* threadPtr */
        "je .Lf9a7ce_0009af84\n"
        "leal 0xc(%esi), %ebx\n" /* line 4972 | threadId, sourcePos */
        "movl %ebx, %edx\n" /* sourcePos */
        "movl -0x40(%ebp), %ecx\n"
        ".Lf9a7ce_0009af67:\n"
        "addl $1, %ecx\n" /* line 5030 */
        "cmpl %ecx, -0x64(%ebp)\n" /* far_function_count */
        "je .Lf9a7ce_0009afa2\n"
        "movl %ebx, %esi\n" /* i, toThreadId */
        "cmpb $0, 2(%edx)\n" /* line 5033 */
        "je .Lf9a7ce_0009afa2\n"
        "movzwl (%edx), %eax\n" /* line 5035 */
        "leal 0xc(%ebx), %ebx\n" /* i */
        "addl $0xc, %edx\n"
        "cmpl %edi, %eax\n" /* threadPtr */
        "jne .Lf9a7ce_0009af67\n"
        ".Lf9a7ce_0009af84:\n"
        "movl $str_0021dbf4, 4(%esp)\n" /* line 5037 */
        "movl 4(%esi), %eax\n" /* toThreadId */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 5078 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pos, emptyValue */
        ".Lf9a7ce_0009afa2:\n"
        "movl -0x60(%ebp), %ebx\n" /* line 5040 | precachescript, i */
        "movb $0, 2(%ebx)\n" /* i */
        "movl -0x5c(%ebp), %eax\n" /* line 5042 | includeFileId */
        "movl %eax, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %edi\n" /* threadPtr */
        "testl %eax, %eax\n"
        "jne .Lf9a7ce_0009b06a\n"
        ".Lf9a7ce_0009afbe:\n"
        "movl -0x40(%ebp), %ebx\n" /* i */
        "jmp .Lf9a7ce_0009af34\n"
        ".Lf9a7ce_0009afc6:\n"
        "movl %edi, (%esp)\n" /* line 5046 | threadPtr */
        "calll FindObject\n"
        "movl $1, 4(%esp)\n" /* line 5048 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, -0x58(%ebp)\n" /* posId */
        "testl %eax, %eax\n" /* line 5049 */
        "je .Lf9a7ce_0009b058\n"
        "movl %eax, (%esp)\n" /* line 5052 */
        "calll Scr_EvalVariable\n"
        "movl %eax, -0x28(%ebp)\n" /* pos */
        "movl %edx, -0x24(%ebp)\n"
        "cmpl $0xd, -0x24(%ebp)\n" /* line 5053 */
        "je .Lf9a7ce_0009b058\n"
        "movl %edi, (%esp)\n" /* line 5058 | threadPtr */
        "calll GetVariableName\n"
        "movzwl %ax, %ebx\n" /* line 5059 | i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl 0xc(%ebp), %edx\n" /* fileId */
        "movl %edx, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetObjectA\n"
        "movl %eax, %esi\n" /* toThreadId */
        "movl -0x60(%ebp), %eax\n" /* line 5060 | precachescript */
        "movl 4(%eax), %ecx\n"
        "movl $0xd, (%esp)\n"
        "movl %ebx, %edx\n" /* i */
        "movl %esi, %eax\n" /* toThreadId */
        "calll SpecifyThreadPosition\n"
        "movl %eax, (%esp)\n" /* line 5061 */
        "calll GetVariableValueAddress\n"
        "movl %eax, %ebx\n" /* i */
        "movl -0x58(%ebp), %edx\n" /* posId */
        "movl %edx, (%esp)\n"
        "calll GetVariableValueAddress\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%ebx)\n" /* i */
        "xorl %ecx, %ecx\n" /* line 5062 */
        "leal -0x28(%ebp), %edx\n" /* pos */
        "movl %esi, %eax\n" /* toThreadId */
        "calll LinkThread\n"
        ".Lf9a7ce_0009b058:\n"
        "movl %edi, (%esp)\n" /* line 5042 | threadPtr */
        "calll FindNextSibling\n"
        "movl %eax, %edi\n" /* threadPtr */
        "testl %eax, %eax\n"
        "je .Lf9a7ce_0009afbe\n"
        ".Lf9a7ce_0009b06a:\n"
        "movl %edi, (%esp)\n" /* line 5044 | threadPtr */
        "calll GetVarType\n"
        "subl $1, %eax\n"
        "jne .Lf9a7ce_0009b058\n"
        "jmp .Lf9a7ce_0009afc6\n"
        /* { scope 2: stmttblock */
        /* { scope 3 */
        ".Lf9a7ce_0009b07c:\n"
        "movb $0, scrCompileGlob+37\n" /* line 4837 */
        "xorl %ecx, %ecx\n" /* line 577 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 4840 */
        "movl $0, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 4841 */
        "movl $0xfffffffe, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf9a7ce_0009acd9\n"
        /* } scope */
        ".Lf9a7ce_0009b0bb:\n"
        "movb $0, scrCompileGlob+36\n" /* line 4837 */
        "xorl %ecx, %ecx\n" /* line 577 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 4840 */
        "movl $0, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 4841 */
        "movl $0xfffffffe, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf9a7ce_0009ae03\n"
        /* { scope 3 */
        ".Lf9a7ce_0009b0fa:\n"
        "movl $0, (%esp)\n" /* line 4866 */
        "calll TempMalloc\n"
        "movl %eax, %esi\n" /* begin_pos */
        "movl 0x3c(%ebx), %edi\n" /* line 4867 | node, savedChecksum */
        "movl $2, scrCompilePub+40\n" /* line 4869 */
        "movb $0, scrCompileGlob+38\n" /* line 4821 */
        "movl $0, scrCompileGlob+40\n" /* line 4822 */
        "movb $0, scrCompileGlob+44\n" /* line 4824 */
        "movb $0, scrCompileGlob+45\n" /* line 4825 */
        "movl $0, scrCompileGlob+48\n" /* line 4826 */
        "movb $0, scrCompileGlob+52\n" /* line 4828 */
        "movb $0, scrCompileGlob+53\n" /* line 4829 */
        "movl $0, scrCompileGlob+56\n" /* line 4830 */
        "movl $0, scrCompileGlob+60\n" /* line 4832 */
        "movl $0, scrCompileGlob+72\n" /* line 4833 */
        "cmpb $0, scrCompileGlob+37\n" /* line 4835 */
        "jne .Lf9a7ce_0009b1a8\n"
        ".Lf9a7ce_0009b173:\n"
        "movl -0x48(%ebp), %eax\n" /* line 4872 | stmttblock */
        "movl (%eax), %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl -0x54(%ebp), %ecx\n"
        "movl 0x14(%ecx), %edx\n"
        "movl 0x10(%ecx), %ecx\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "movl -0x54(%ebp), %edx\n"
        "xorl %eax, %eax\n"
        "calll EmitThreadInternal\n"
        "movl %esi, (%esp)\n" /* line 4874 | begin_pos */
        "calll TempMemorySetPos\n"
        "movl %edi, 0x3c(%ebx)\n" /* line 4875 | savedChecksum, node */
        "jmp .Lf9a7ce_0009ad40\n"
        ".Lf9a7ce_0009b1a8:\n"
        "movb $0, scrCompileGlob+37\n" /* line 4837 */
        "xorl %ecx, %ecx\n" /* line 577 */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "calll EmitOpcode\n"
        "movl $0, 4(%esp)\n" /* line 4840 */
        "movl $0, (%esp)\n"
        "calll AddOpcodePos\n"
        "movl $0, 4(%esp)\n" /* line 4841 */
        "movl $0xfffffffe, (%esp)\n"
        "calll AddOpcodePos\n"
        "jmp .Lf9a7ce_0009b173\n"
        /* } scope */
        /* } scope */
        ".Lf9a7ce_0009b1e4:\n"
        "movl %edi, (%esp)\n" /* line 5023 | threadPtr */
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021dbd8, 4(%esp)\n" /* "Could not find script '%s'" */
        "movl -0x60(%ebp), %edx\n" /* precachescript */
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9a7ce_0009aaf3\n"
    );
}

/* line 4692 */
static __attribute__((naked))
unsigned int EmitDeveloperStatementList(sval_t val, scr_block_t *block, sval_t *devStatBlock)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4692 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %ecx, -0x30(%ebp)\n"
        /* { scope 1 */
        "movl scrCompilePub+40, %ebx\n" /* line 4697 | removeCount */
        "testl %ebx, %ebx\n" /* removeCount */
        "jne .Lf9b20c_0009b40e\n"
        "movl %ecx, %edx\n" /* sourcePos */
        "movl imp_scrVarPub, %eax\n" /* line 4703 */
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* savedChecksum */
        "movl 8(%ebp), %eax\n" /* line 4705 | devStatBlock */
        "movl (%eax), %esi\n"
        "movl %esi, -0x20(%ebp)\n"
        "addl $0x18, %edx\n" /* sourcePos */
        "movl %edx, -0x1c(%ebp)\n" /* sourcePos */
        "xorl %edi, %edi\n" /* savedPos */
        /* { scope 2 */
        ".Lf9b20c_0009b246:\n"
        "cmpl 8(%esi), %edi\n" /* line 1058 | j */
        "jl .Lf9b20c_0009b259\n"
        "movl -0x30(%ebp), %edx\n"
        "movl 4(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* j */
        "jge .Lf9b20c_0009b33c\n"
        /* } scope */
        ".Lf9b20c_0009b259:\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 1060 | removeCount */
        "movl (%ebx), %ebx\n" /* removeCount */
        "movl %ebx, -0x24(%ebp)\n" /* removeCount */
        /* { scope 2 */
        "movl 0xc(%esi), %ebx\n" /* line 764 */
        "movl %ebx, -0x34(%ebp)\n"
        "cmpl %ebx, %edi\n"
        "jge .Lf9b20c_0009b309\n"
        "movl -0x24(%ebp), %edx\n" /* line 766 */
        "movl -0x20(%ebp), %eax\n"
        "cmpl %edx, 0x18(%eax)\n"
        "je .Lf9b20c_0009b335\n"
        "leal 0x18(%esi, %edi, 4), %edx\n"
        "movl %edi, %ecx\n"
        ".Lf9b20c_0009b284:\n"
        "addl $1, %ecx\n" /* line 764 */
        "cmpl %ecx, %ebx\n"
        "je .Lf9b20c_0009b309\n"
        "movl 4(%edx), %eax\n" /* line 766 */
        "addl $4, %edx\n"
        "cmpl -0x24(%ebp), %eax\n"
        "jne .Lf9b20c_0009b284\n"
        ".Lf9b20c_0009b296:\n"
        "testl %ecx, %ecx\n" /* line 1062 */
        "js .Lf9b20c_0009b309\n"
        "movl %ecx, %ebx\n" /* removeCount */
        ".Lf9b20c_0009b29c:\n"
        "movl 8(%esi), %eax\n" /* line 1068 */
        "cmpl %eax, %ebx\n" /* removeCount */
        "jl .Lf9b20c_0009b2a9\n"
        "addl $1, %eax\n" /* line 1070 */
        "movl %eax, 8(%esi)\n"
        ".Lf9b20c_0009b2a9:\n"
        "cmpl %ebx, %edi\n" /* line 1073 | removeCount, j */
        "jge .Lf9b20c_0009b2cd\n"
        "leal (, %ebx, 4), %eax\n"
        "leal 0x14(%eax, %esi), %ecx\n"
        "leal 0x18(%eax, %esi), %edx\n"
        ".Lf9b20c_0009b2bc:\n"
        "subl $1, %ebx\n" /* line 1075 | removeCount */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "subl $4, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ebx, %edi\n" /* line 1073 | removeCount, j */
        "jl .Lf9b20c_0009b2bc\n"
        ".Lf9b20c_0009b2cd:\n"
        "movl -0x24(%ebp), %ebx\n" /* line 1078 | removeCount */
        "movl -0x20(%ebp), %edx\n"
        "movl %ebx, 0x18(%edx)\n" /* removeCount */
        "movl %edi, %edx\n" /* line 1079 | j */
        "sarl $3, %edx\n"
        "movl %edi, %ecx\n" /* j */
        "andl $7, %ecx\n"
        "movl -0x30(%ebp), %ebx\n" /* removeCount */
        "movzbl 0x10(%edx, %ebx), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf9b20c_0009b2f9\n"
        "movl $1, %eax\n" /* line 1080 */
        "shll %cl, %eax\n"
        "orb %al, 0x10(%edx, %esi)\n"
        ".Lf9b20c_0009b2f9:\n"
        "addl $1, %edi\n" /* line 1058 | j */
        "addl $4, -0x20(%ebp)\n"
        "addl $4, -0x1c(%ebp)\n"
        "jmp .Lf9b20c_0009b246\n"
        ".Lf9b20c_0009b309:\n"
        "cmpl $0x3f, %ebx\n" /* line 894 | removeCount */
        "jg .Lf9b20c_0009b319\n"
        "movl -0x34(%ebp), %eax\n"
        ".Lf9b20c_0009b311:\n"
        "addl $1, %eax\n" /* line 1066 */
        "movl %eax, 0xc(%esi)\n"
        "jmp .Lf9b20c_0009b29c\n"
        ".Lf9b20c_0009b319:\n"
        "movl $str_0021d7b8, 4(%esp)\n" /* line 896 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "jmp .Lf9b20c_0009b311\n"
        ".Lf9b20c_0009b335:\n"
        "movl %edi, %ecx\n" /* line 764 */
        "jmp .Lf9b20c_0009b296\n"
        ".Lf9b20c_0009b33c:\n"
        "movl %eax, 4(%esi)\n" /* line 1084 */
        "movl $0, (%esi)\n" /* line 1085 */
        /* } scope */
        "movl imp_scrVarPub, %eax\n" /* line 4707 */
        "cmpb $0, 0xb(%eax)\n"
        "je .Lf9b20c_0009b3ba\n"
        "movl $1, scrCompilePub+40\n" /* line 4719 */
        "movl 8(%ebp), %ebx\n" /* line 4721 | devStatBlock, removeCount */
        "movl (%ebx), %esi\n" /* removeCount, block */
        /* { scope 2 */
        "movl -0x2c(%ebp), %edx\n" /* line 4667 */
        "movl (%edx), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf9b20c_0009b36f\n"
        "jmp .Lf9b20c_0009b389\n"
        ".Lf9b20c_0009b36d:\n"
        "movl %ebx, %eax\n" /* removeCount */
        ".Lf9b20c_0009b36f:\n"
        "movl 4(%eax), %ebx\n" /* line 4669 | removeCount */
        "movl (%eax), %eax\n" /* line 4670 */
        "movl %esi, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "calll EmitStatement\n"
        "testl %ebx, %ebx\n" /* line 4667 | removeCount */
        "jne .Lf9b20c_0009b36d\n"
        "movl 8(%ebp), %ebx\n" /* devStatBlock, removeCount */
        "movl (%ebx), %esi\n" /* removeCount */
        /* } scope */
        /* { scope 2 */
        ".Lf9b20c_0009b389:\n"
        "movl (%esi), %eax\n" /* line 850 */
        "testl %eax, %eax\n"
        "jne .Lf9b20c_0009b39d\n"
        "movl 4(%esi), %eax\n" /* line 854 */
        "movl %eax, %ebx\n" /* line 856 | removeCount */
        "subl 8(%esi), %ebx\n" /* removeCount */
        "jne .Lf9b20c_0009b426\n"
        /* } scope */
        ".Lf9b20c_0009b39d:\n"
        "movl $0, scrCompilePub+40\n" /* line 4726 */
        "movl imp_scrVarPub, %eax\n" /* line 4728 */
        "movl -0x28(%ebp), %edx\n" /* savedChecksum, sourcePos */
        "movl %edx, 0x3c(%eax)\n" /* sourcePos */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 4729 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9b20c_0009b3ba:\n"
        "movl $0, (%esp)\n" /* line 4709 */
        "calll TempMalloc\n"
        "movl %eax, %edi\n" /* savedPos */
        "movl $2, scrCompilePub+40\n" /* line 4711 */
        "movl 8(%ebp), %ebx\n" /* line 4713 | devStatBlock, removeCount */
        "movl (%ebx), %esi\n" /* removeCount, block */
        /* { scope 2 */
        /* { scope 3 */
        "movl -0x2c(%ebp), %edx\n" /* line 4667 */
        "movl (%edx), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf9b20c_0009b3ef\n"
        /* } scope */
        /* } scope */
        "movl %edi, (%esp)\n" /* line 4715 | savedPos */
        "calll TempMemorySetPos\n"
        "jmp .Lf9b20c_0009b39d\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf9b20c_0009b3ed:\n"
        "movl %ebx, %eax\n" /* line 4667 | removeCount */
        ".Lf9b20c_0009b3ef:\n"
        "movl 4(%eax), %ebx\n" /* line 4669 | removeCount */
        "movl (%eax), %eax\n" /* line 4670 */
        "movl %esi, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "calll EmitStatement\n"
        "testl %ebx, %ebx\n" /* line 4667 | removeCount */
        "jne .Lf9b20c_0009b3ed\n"
        /* } scope */
        /* } scope */
        "movl %edi, (%esp)\n" /* line 4715 | savedPos */
        "calll TempMemorySetPos\n"
        "jmp .Lf9b20c_0009b39d\n"
        ".Lf9b20c_0009b40e:\n"
        "movl $str_0021db60, 4(%esp)\n" /* line 4699 */
        "movl %edx, (%esp)\n" /* sourcePos */
        "calll CompileError\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 4729 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf9b20c_0009b426:\n"
        "xorl %ecx, %ecx\n" /* line 858 */
        "xorl %edx, %edx\n"
        "movl $0x17, %eax\n"
        "calll EmitOpcode\n"
        "movl $1, (%esp)\n" /* line 616 */
        "calll TempMalloc\n"
        "movl %eax, scrCompileGlob\n"
        "movb %bl, (%eax)\n" /* line 617 */
        "movl 8(%esi), %eax\n" /* line 860 */
        "movl %eax, 4(%esi)\n"
        "jmp .Lf9b20c_0009b39d\n"
    );
}

