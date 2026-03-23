/* ASM dump from: scr_compiler.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_compiler.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/script/scr_variable.h"
 */

extern struct scrCompilePub_t scrCompilePub; /* 0x0 */
extern void Z_FreeInternal(void *ptr);
extern unsigned int FindVariable(unsigned int parentId, unsigned int value);
extern int Scr_EvalVariable(unsigned int id);
extern int GetVariableValueAddress(unsigned int id);
extern int GetVarType(unsigned int id);
extern void CompileError2(int codePos, const char *msg);
extern unsigned char scrCompileGlob[];
extern void DumpCompiledObject(const char *label, unsigned int compiledObj);
static const char str_dbg_before_lt[] = "before-LinkThread";

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
static unsigned int LinkThread(unsigned int threadId, VariableUnion (*pos)[16]) {
    /* Note: in native code, ecx=allowFarCall is a hidden register param.
       In the Emscripten path this function is not called, so allowFarCall is unused. */
    unsigned int varId;
    int count, i;
    int allowFarCall = 0;

    varId = FindVariable(threadId, 0);
    if (!varId)
        return 0;

    count = Scr_EvalVariable(varId);
    if (count <= 0)
        return 0;

    for (i = 0; i < count; i++) {
        unsigned int valueId = FindVariable(threadId, i + 2);
        int *value = (int *)GetVariableValueAddress(valueId);
        int type = GetVarType(valueId);
        int posType = ((int *)pos)[1];

        if (posType == 0xc) {
            if (type == 7) {
                CompileError2(*value, (const char *)"normal script cannot reference a function in a /# ... #/ comment");
                continue;
            }
        } else {
            if (!posType) {
                CompileError2(*value, (const char *)"unknown function");
                continue;
            }
            if (!allowFarCall) {
                int *target = (int *)*value;
                if (*target == 1) {
                    CompileError2(*value, (const char *)"unknown function");
                    continue;
                }
            }
        }

        *(int *)*value = *(int *)pos;
    }
    return 0;
}
