/* ASM dump from: scr_animtree.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_animtree.cpp */

#include "common_types.h"
#include "imports.h"

extern struct scrAnimPub_t scrAnimPub; /* 0x0 */
static struct scrAnimGlob_t scrAnimGlob; /* scrAnimGlob */
extern const char * propertyNames[3]; /* propertyNames */

extern void * Hunk_AllocAlignInternal(int size, int align);

void SetAnimCheck(int bAnimCheck);
static void * Hunk_AllocXAnimTreePrecache(int size);
static int Scr_GetAnimTreeSize(void);
static void ConnectScriptToAnim(int index, unsigned int name, int treeIndex);
struct XAnim_s * Scr_GetAnims(int index);
static int Scr_CreateAnimationTree(unsigned int names, struct XAnim_s *anims, unsigned int childIndex, const char *parentName, unsigned int parentIndex, unsigned int filename, int treeIndex);
static void Scr_PrecacheAnimationTree(void);
static unsigned int Scr_UsingTreeInternal(int *index);
void Scr_UsingTree(const char *filename, unsigned int sourcePos);
struct scr_animtree_t Scr_FindAnimTree(const char *filename);
void Scr_FindAnim(const char *filename, const char *animName, scr_anim_t *anim, int user);
void Scr_EmitAnimation(char *pos, unsigned int animName, unsigned int sourcePos);
static Bool AnimTreeParseInternal(unsigned int parentNode, unsigned int names, Bool bIncludeParent, int bLoop, int bComplete);
void Scr_LoadAnimTreeAtIndex(int index, Alloc_t Alloc, int user);

/* external function declarations */
extern unsigned int FindNextSibling(unsigned int id);
extern unsigned int GetVariableName(unsigned int id);
extern int GetVarType(unsigned int id);
extern unsigned int FindObject(unsigned int varId);
extern unsigned int FindVariable(unsigned int parent, unsigned int name);
extern unsigned int GetNewVariable(unsigned int parent, unsigned int name);
extern unsigned int GetVariable(unsigned int parent, unsigned int name);
extern unsigned int GetObjectA(unsigned int varId);
extern unsigned int GetArray(unsigned int id);
extern unsigned int GetArraySize(unsigned int id);
extern unsigned int GetArrayVariable(unsigned int parentId, unsigned int unsignedValue);
extern unsigned int FindArrayVariable(unsigned int parentId, int intValue);
extern void RemoveVariable(unsigned int parentId, unsigned int unsignedValue);
extern void RemoveRefToObject(unsigned int objId);
extern void * GetVariableValueAddress(unsigned int id);
extern void SetVariableValue(unsigned int id, void *value);
extern void SL_RemoveRefToString(unsigned int stringValue);
extern const char *SL_ConvertToString(unsigned int stringValue);
extern unsigned int SL_GetLowercaseString_(const char *str, unsigned int user, int type);
extern unsigned int SL_GetString_(const char *str, unsigned int user, int type);
extern unsigned int Scr_CreateCanonicalFilename(const char *filename);
extern int Scr_EvalVariable(unsigned int varId);
extern int Scr_IsInOpcodeMemory(const char *pos);
extern Bool Scr_IsIdentifier(const char *token);
extern int Scr_AllocArray(void);
extern void *XAnimCreateAnims(const char *debugName, int size, Alloc_t Alloc);
extern void XAnimBlend(void *anims, unsigned int animIndex, const char *name, unsigned int children, unsigned int num, unsigned int flags);
extern void XAnimPrecache(const char *name, Alloc_t Alloc);
extern void XAnimCreate(void *anims, unsigned int animIndex, const char *name);
extern void XAnimSetupSyncNodes(void *anims);
extern byte *Scr_AddSourceBuffer(const char *filename, const char *extFilename, byte *oldFilename, int flag);
extern void Com_BeginParseSession(const char *name);
extern void Com_EndParseSession(void);
extern const char *Com_Parse(const char **buf);
extern const char *Com_ParseOnLine(const char **buf);
extern const char *Com_GetLastTokenPos(void);
extern void Hunk_ClearTempMemoryHigh(void);
extern int I_stricmp(const char *s1, const char *s2);
extern char *va(const char *format, ...);
extern void CompileError(unsigned int sourcePos, const char *msg);
extern void CompileError2(const char *codePos, const char *msg);
extern void Com_Error(int code, const char *fmt, ...);
extern int sprintf(char *buf, const char *fmt, ...);

/* string literals referenced from asm */
extern const char str_0021dd88[];  /* "duplicate animation '%s' in 'animtrees/%s.atr'" */
extern const char str_0021ddb8[];
extern const char str_0021d930[];
extern const char str_00216058[];  /* "%s" */
extern const char str_0021de10[];
extern const char str_0021ddcc[];
extern const char str_0021dde0[];
extern const char str_0021de04[];
extern const char str_0021de28[];
extern const char str_0021de60[];
extern const char str_0021de7c[];
extern const char str_0021de04[];
extern const char str_0021dea4[];
extern const char str_0021debc[];
extern const char str_0021ded8[]; /* "animtrees/%s.atr" */
extern const char str_0021deec[];
extern const char str_0021df00[]; /* "unknown anim tree '%s'" */
extern const char str_0021df18[]; /* "root" */
extern const char str_0021df20[]; /* "animation '%s' not defined in anim tree '%s'" */
extern const char str_00217870[];
extern const char str_00217a74[]; /* "void_loop" */
extern const char str_0021cdd0[];

extern void *imp_scrVarPub;
extern void *imp_scrParserPub;

/* line 60 */
void SetAnimCheck(int bAnimCheck)
{
    scrAnimGlob.bAnimCheck = bAnimCheck;
}

/* line 315 */
static void * Hunk_AllocXAnimTreePrecache(int size)
{
    return Hunk_AllocAlignInternal(size, 4);
}

/* line 322 */
/* Scr_GetAnimTreeSize: called with parentNode in eax, traverses siblings */
static int Scr_GetAnimTreeSize(void)
{
    int result;
    __asm__ __volatile__ (
        ".Lf9c3ba_0009c3ba:\n"
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf9c3ba_0009c3db\n"
        "xorl %esi, %esi\n"
        "movl %esi, %eax\n"
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp .Lscr_getanimtreesize_done\n"
        ".Lf9c3ba_0009c3db:\n"
        "xorl %esi, %esi\n"
        "jmp .Lf9c3ba_0009c3ed\n"
        ".Lf9c3ba_0009c3df:\n"
        "movl %ebx, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "je .Lf9c3ba_0009c41a\n"
        ".Lf9c3ba_0009c3ed:\n"
        "movl %ebx, (%esp)\n"
        "calll GetVariableName\n"
        "cmpl $0xffff, %eax\n"
        "ja .Lf9c3ba_0009c3df\n"
        "movl %ebx, (%esp)\n"
        "calll GetVarType\n"
        "subl $1, %eax\n"
        "je .Lf9c3ba_0009c429\n"
        "addl $1, %esi\n"
        "movl %ebx, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf9c3ba_0009c3ed\n"
        ".Lf9c3ba_0009c41a:\n"
        "cmpl $1, %esi\n"
        "sbbl $-1, %esi\n"
        "movl %esi, %eax\n"
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp .Lscr_getanimtreesize_done\n"
        ".Lf9c3ba_0009c429:\n"
        "movl %ebx, (%esp)\n"
        "calll FindObject\n"
        "calll Scr_GetAnimTreeSize\n"
        "addl %eax, %esi\n"
        "jmp .Lf9c3ba_0009c3df\n"
        ".Lscr_getanimtreesize_done:\n"
        "movl %%eax, %0\n"
        : "=r"(result)
        :
        : "eax", "ebx", "ecx", "edx", "esi", "memory"
    );
    return result;
}

/* line 352 */
static void ConnectScriptToAnim(int index, unsigned int name, int treeIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %ecx, %ebx\n"
        "movl 8(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf9c43a_0009c463\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9c43a_0009c463:\n"
        "movl %eax, (%esp)\n"
        "calll GetVariableValueAddress\n"
        "movl %eax, %esi\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf9c43a_0009c49e\n"
        ".Lf9c43a_0009c473:\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl 0xc(%ebp), %ebx\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf9c43a_0009c483\n"
        "jmp .Lf9c43a_0009c490\n"
        ".Lf9c43a_0009c481:\n"
        "movl %ecx, %eax\n"
        ".Lf9c43a_0009c483:\n"
        "movl (%eax), %ecx\n"
        "movw %bx, 2(%eax)\n"
        "movw %dx, (%eax)\n"
        "testl %ecx, %ecx\n"
        "jne .Lf9c43a_0009c481\n"
        ".Lf9c43a_0009c490:\n"
        "movl $0, (%esi)\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9c43a_0009c49e:\n"
        "movl %ebx, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n"
        "movl %edi, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021dd88, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf9c43a_0009c473\n"
        :
        : "a"(index), "d"(/* index passed via stack, this arg is eax */ 0), "c"(treeIndex)
        : "ebx", "esi", "edi", "memory"
    );
}

/* line 396 */
struct XAnim_s * Scr_GetAnims(int index)
{
    return *(struct XAnim_s **)(0x114e22c + index * 4);
}

/* line 407 */
static int Scr_CreateAnimationTree(unsigned int names, struct XAnim_s *anims, unsigned int childIndex, const char *parentName, unsigned int parentIndex, unsigned int filename, int treeIndex)
{
    int result;
    __asm__ __volatile__ (
        ".Lf9c4de_0009c4de:\n"
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %edi\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf9c4de_0009c59c\n"
        "xorl %esi, %esi\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FindArrayVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf9c4de_0009c5d4\n"
        ".Lf9c4de_0009c51b:\n"
        "xorl %ebx, %ebx\n"
        ".Lf9c4de_0009c51d:\n"
        "movl imp_scrVarPub, %eax\n"
        "movl 0x3c(%eax), %edx\n"
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "addl 0x10(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "addl 8(%ebp), %edx\n"
        "movl %edx, %ecx\n"
        "shll $5, %ecx\n"
        "subl %edx, %ecx\n"
        "addl %esi, %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%ebx, %eax), %eax\n"
        "movl imp_scrVarPub, %edx\n"
        "movl %eax, 0x3c(%edx)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl 8(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimBlend\n"
        "addl 8(%ebp), %esi\n"
        "movl %esi, -0x1c(%ebp)\n"
        "movl %edi, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n"
        "jne .Lf9c4de_0009c5e4\n"
        ".Lf9c4de_0009c591:\n"
        "movl -0x1c(%ebp), %eax\n"
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp .Lscr_createanimtree_done\n"
        ".Lf9c4de_0009c59c:\n"
        "xorl %esi, %esi\n"
        ".Lf9c4de_0009c59e:\n"
        "movl %ebx, (%esp)\n"
        "calll GetVariableName\n"
        "cmpl $0x10000, %eax\n"
        "adcl $0, %esi\n"
        "movl %ebx, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf9c4de_0009c59e\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FindArrayVariable\n"
        "testl %eax, %eax\n"
        "je .Lf9c4de_0009c51b\n"
        ".Lf9c4de_0009c5d4:\n"
        "movl %eax, (%esp)\n"
        "calll GetVariableValueAddress\n"
        "movzwl (%eax), %ebx\n"
        "jmp .Lf9c4de_0009c51d\n"
        ".Lf9c4de_0009c5e4:\n"
        "movl 8(%ebp), %edi\n"
        "movl imp_scrVarPub, %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "jmp .Lf9c4de_0009c600\n"
        ".Lf9c4de_0009c5f2:\n"
        "movl %esi, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n"
        "je .Lf9c4de_0009c591\n"
        ".Lf9c4de_0009c600:\n"
        "movl %esi, (%esp)\n"
        "calll GetVariableName\n"
        "movl %eax, %ebx\n"
        "cmpl $0xffff, %eax\n"
        "ja .Lf9c4de_0009c5f2\n"
        "movl 0x18(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movzwl %bx, %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x14(%ebp), %ecx\n"
        "movl %edi, %edx\n"
        "movl -0x20(%ebp), %eax\n"
        "calll ConnectScriptToAnim\n"
        "movl %esi, (%esp)\n"
        "calll GetVarType\n"
        "subl $1, %eax\n"
        "je .Lf9c4de_0009c66e\n"
        "movl -0x28(%ebp), %edx\n"
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal (%edi, %edx), %edx\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %edx, 0x3c(%eax)\n"
        "movl %ebx, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll XAnimCreate\n"
        "addl $1, %edi\n"
        "jmp .Lf9c4de_0009c5f2\n"
        ".Lf9c4de_0009c66e:\n"
        "movl %ebx, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n"
        "calll FindObject\n"
        "movl 0x18(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x14(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl -0x20(%ebp), %edx\n"
        "calll Scr_CreateAnimationTree\n"
        "movl %eax, -0x1c(%ebp)\n"
        "addl $1, %edi\n"
        "jmp .Lf9c4de_0009c5f2\n"
        ".Lscr_createanimtree_done:\n"
        "movl %%eax, %0\n"
        : "=r"(result)
        : "a"(names), "d"(anims), "c"(childIndex)
        : "ebx", "esi", "edi", "memory"
    );
    return result;
}

/* line 498 */
static void Scr_PrecacheAnimationTree(void)
{
    __asm__ __volatile__ (
        ".Lf9c6b2_0009c6b2:\n"
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf9c6b2_0009c702\n"
        ".Lf9c6b2_0009c6c8:\n"
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9c6b2_0009c6cf:\n"
        "movl %ebx, (%esp)\n"
        "calll GetVarType\n"
        "subl $1, %eax\n"
        "je .Lf9c6b2_0009c715\n"
        "movl %esi, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl $Hunk_AllocXAnimTreePrecache, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimPrecache\n"
        ".Lf9c6b2_0009c6f4:\n"
        "movl %ebx, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "je .Lf9c6b2_0009c6c8\n"
        ".Lf9c6b2_0009c702:\n"
        "movl %ebx, (%esp)\n"
        "calll GetVariableName\n"
        "movl %eax, %esi\n"
        "cmpl $0xffff, %eax\n"
        "ja .Lf9c6b2_0009c6f4\n"
        "jmp .Lf9c6b2_0009c6cf\n"
        ".Lf9c6b2_0009c715:\n"
        "movl %ebx, (%esp)\n"
        "calll FindObject\n"
        "calll Scr_PrecacheAnimationTree\n"
        "jmp .Lf9c6b2_0009c6f4\n"
        :
        :
        : "eax", "ebx", "ecx", "edx", "esi", "memory"
    );
}

/* line 521 */
static unsigned int Scr_UsingTreeInternal(int *index)
{
    unsigned int result;
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl %ecx, %esi\n"
        "movl %eax, (%esp)\n"
        "calll Scr_CreateCanonicalFilename\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %eax, 4(%esp)\n"
        "movl scrAnimPub, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf9c724_0009c7cb\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl scrAnimPub, %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetNewVariable\n"
        "movl %eax, %ebx\n"
        "movl %eax, (%esp)\n"
        "calll GetObjectA\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl scrAnimPub+1036(, %esi, 4), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, scrAnimPub+1036(, %esi, 4)\n"
        "shll $7, %esi\n"
        "leal (%esi, %edx), %eax\n"
        "movw %bx, scrAnimGlob+8(%eax, %eax)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        ".Lf9c724_0009c799:\n"
        "movl $0, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl %eax, %ebx\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl %ebx, %eax\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp .Lscr_usingtreeinternal_done\n"
        ".Lf9c724_0009c7cb:\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl $0, (%eax)\n"
        "movl %esi, %eax\n"
        "shll $8, %eax\n"
        "leal scrAnimGlob+8(%eax), %edi\n"
        "movl scrAnimPub+1036(, %esi, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf9c724_0009c799\n"
        "movzwl 2(%edi), %eax\n"
        "cmpl %eax, %ebx\n"
        "je .Lf9c724_0009c818\n"
        "movl $1, %edx\n"
        ".Lf9c724_0009c802:\n"
        "addl $1, %edx\n"
        "cmpl %ecx, %edx\n"
        "jg .Lf9c724_0009c799\n"
        "movzwl (%edi, %edx, 2), %eax\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf9c724_0009c802\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "jmp .Lf9c724_0009c799\n"
        ".Lf9c724_0009c818:\n"
        "movl $1, %edx\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "jmp .Lf9c724_0009c799\n"
        ".Lscr_usingtreeinternal_done:\n"
        "movl %%eax, %0\n"
        : "=r"(result)
        : "a"(/* filename passed via eax - handled by caller convention */ 0), "d"(index), "c"(/* user */ 0)
        : "ebx", "esi", "edi", "memory"
    );
    return result;
}

/* line 573 */
void Scr_UsingTree(const char *filename, unsigned int sourcePos)
{
    if (!Scr_IsIdentifier(filename)) {
        CompileError(sourcePos, str_0021ddb8);
        return;
    }
    {
        int index;
        scrAnimPub.animTreeNames = Scr_UsingTreeInternal(&index);
    }
}

/* line 698 */
struct scr_animtree_t Scr_FindAnimTree(const char *filename)
{
    struct scr_animtree_t result;
    unsigned int filenameId;
    unsigned int fileId;

    filenameId = Scr_CreateCanonicalFilename(filename);
    fileId = FindVariable(scrAnimPub.animtrees, filenameId);
    SL_RemoveRefToString(filenameId);

    result.anims = 0;
    if (!fileId)
        return result;

    GetVariableName(fileId);
    fileId = FindObject(fileId);
    if (!FindVariable(fileId, 1))
        return result;

    result.anims = (struct XAnim_s *)(uintptr_t)Scr_EvalVariable(FindVariable(fileId, 1));
    return result;
}

/* line 738 */
void Scr_FindAnim(const char *filename, const char *animName, scr_anim_t *anim, int user)
{
    unsigned int name;
    int idx;
    unsigned int names;
    unsigned int varId;

    name = SL_GetLowercaseString_(animName, 4, 0);
    names = Scr_UsingTreeInternal(&idx);

    varId = FindVariable(names, name);
    if (varId) {
        void *addr = GetVariableValueAddress(varId);
        unsigned int *vaddr = (unsigned int *)addr;
        anim->index = (unsigned short)*vaddr;
        *vaddr = (unsigned int)(uintptr_t)anim;
    } else {
        varId = GetNewVariable(names, name);
        anim->index = 0;
        {
            unsigned int tempType = 7;
            unsigned int tempVal = (unsigned int)(uintptr_t)anim;
            /* SetVariableValue expects a VariableValue struct */
            unsigned int tv[2];
            tv[0] = tempVal;
            tv[1] = tempType;
            SetVariableValue(varId, tv);
        }
    }

    SL_RemoveRefToString(name);
}

/* line 164 */
void Scr_EmitAnimation(char *pos, unsigned int animName, unsigned int sourcePos)
{
    unsigned int names = scrAnimPub.animTreeNames;
    unsigned int varId;

    if (!names) {
        CompileError(sourcePos, str_0021d930);
        return;
    }

    varId = FindVariable(names, animName);
    if (varId) {
        void *addr = GetVariableValueAddress(varId);
        unsigned int *vaddr = (unsigned int *)addr;
        *(unsigned int *)pos = *vaddr;
        *vaddr = (unsigned int)(uintptr_t)pos;
    } else {
        varId = GetNewVariable(names, animName);
        *(unsigned int *)pos = 0;
        {
            unsigned int tv[2];
            tv[0] = (unsigned int)(uintptr_t)pos;
            tv[1] = 7;
            SetVariableValue(varId, tv);
        }
    }
}

/* line 179 */
static Bool AnimTreeParseInternal(unsigned int parentNode, unsigned int names, Bool bIncludeParent, int bLoop, int bComplete)
{
    Bool result;
    __asm__ __volatile__ (
        ".Lf9ca0e_0009ca0e:\n"
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %edx, -0x40(%ebp)\n"
        "movb %cl, -0x41(%ebp)\n"
        "movzbl 8(%ebp), %eax\n"
        "movb %al, -0x42(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x43(%ebp)\n"
        "movl $6, -0x1c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl $0, -0x38(%ebp)\n"
        "movl $0, -0x34(%ebp)\n"
        "movb $0, -0x2d(%ebp)\n"
        ".Lf9ca0e_0009ca4e:\n"
        "movl $scrAnimGlob+4, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n"
        "movl scrAnimGlob+4, %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf9ca0e_0009cb0b\n"
        ".Lf9ca0e_0009ca6a:\n"
        "movl %eax, (%esp)\n"
        "calll Scr_IsIdentifier\n"
        "testb %al, %al\n"
        "je .Lf9ca0e_0009cc28\n"
        "cmpb $0, -0x2d(%ebp)\n"
        "jne .Lf9ca0e_0009cdcc\n"
        ".Lf9ca0e_0009ca84:\n"
        "movl $4, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SL_GetLowercaseString_\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf9ca0e_0009cd9d\n"
        ".Lf9ca0e_0009cab6:\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, -0x38(%ebp)\n"
        "cmpb $0, -0x43(%ebp)\n"
        "je .Lf9ca0e_0009cb2e\n"
        ".Lf9ca0e_0009cad1:\n"
        "movb $0, -0x2d(%ebp)\n"
        "movl $scrAnimGlob+4, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %esi\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf9ca0e_0009cb65\n"
        ".Lf9ca0e_0009cae8:\n"
        "movl $0, -0x34(%ebp)\n"
        "movl $scrAnimGlob+4, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n"
        "movl scrAnimGlob+4, %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf9ca0e_0009ca6a\n"
        ".Lf9ca0e_0009cb0b:\n"
        "movl $1, %esi\n"
        ".Lf9ca0e_0009cb10:\n"
        "cmpb $0, -0x2d(%ebp)\n"
        "jne .Lf9ca0e_0009cfae\n"
        ".Lf9ca0e_0009cb1a:\n"
        "cmpb $0, -0x41(%ebp)\n"
        "jne .Lf9ca0e_0009cf32\n"
        ".Lf9ca0e_0009cb24:\n"
        "movl %esi, %eax\n"
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp .Lanimtreeparseintern_done\n"
        ".Lf9ca0e_0009cb2e:\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf9ca0e_0009cad1\n"
        "movl scrAnimGlob+520, %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf9ca0e_0009cad1\n"
        "movb $1, -0x2d(%ebp)\n"
        "movl $scrAnimGlob+4, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %esi\n"
        "cmpb $0, (%eax)\n"
        "je .Lf9ca0e_0009cae8\n"
        ".Lf9ca0e_0009cb65:\n"
        "movl %eax, (%esp)\n"
        "calll Scr_IsIdentifier\n"
        "testb %al, %al\n"
        "jne .Lf9ca0e_0009cefa\n"
        ".Lf9ca0e_0009cb75:\n"
        "cmpb $0x3a, (%esi)\n"
        "jne .Lf9ca0e_0009cde3\n"
        "cmpb $0, 1(%esi)\n"
        "jne .Lf9ca0e_0009cde3\n"
        ".Lf9ca0e_0009cb88:\n"
        "movl $0, -0x34(%ebp)\n"
        ".Lf9ca0e_0009cb8f:\n"
        "movl $scrAnimGlob+4, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %edi\n"
        "cmpb $0, (%eax)\n"
        "je .Lf9ca0e_0009cc07\n"
        ".Lf9ca0e_0009cba2:\n"
        "xorl %esi, %esi\n"
        "movl $propertyNames, %ebx\n"
        ".Lf9ca0e_0009cba9:\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf9ca0e_0009ce12\n"
        "addl $1, %esi\n"
        "addl $4, %ebx\n"
        "cmpl $3, %esi\n"
        "jne .Lf9ca0e_0009cba9\n"
        ".Lf9ca0e_0009cbca:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021de10, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "movl $scrAnimGlob+4, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %edi\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf9ca0e_0009cba2\n"
        ".Lf9ca0e_0009cc07:\n"
        "movl $scrAnimGlob+4, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n"
        "cmpb $0x7b, (%eax)\n"
        "jne .Lf9ca0e_0009ce35\n"
        "cmpb $0, 1(%eax)\n"
        "jne .Lf9ca0e_0009ce35\n"
        ".Lf9ca0e_0009cc28:\n"
        "movzbl (%esi), %eax\n"
        "cmpb $0x7b, %al\n"
        "je .Lf9ca0e_0009cc66\n"
        "cmpb $0x7d, %al\n"
        "je .Lf9ca0e_0009cf8b\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021de04, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009ca4e\n"
        ".Lf9ca0e_0009cc66:\n"
        "cmpb $0, 1(%esi)\n"
        "jne .Lf9ca0e_0009cec2\n"
        ".Lf9ca0e_0009cc70:\n"
        "movl $scrAnimGlob+4, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf9ca0e_0009ce93\n"
        ".Lf9ca0e_0009cc85:\n"
        "movl -0x38(%ebp), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf9ca0e_0009ce64\n"
        ".Lf9ca0e_0009cc90:\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl %eax, %esi\n"
        "cmpb $0, -0x43(%ebp)\n"
        "jne .Lf9ca0e_0009ccaf\n"
        "testb $8, -0x34(%ebp)\n"
        "je .Lf9ca0e_0009cd1c\n"
        "cmpb $0, -0x2d(%ebp)\n"
        "jne .Lf9ca0e_0009cd1c\n"
        ".Lf9ca0e_0009ccaf:\n"
        "movl $1, %eax\n"
        "xorb $1, -0x2d(%ebp)\n"
        "movzbl -0x2d(%ebp), %ecx\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "andl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %esi, %eax\n"
        "calll AnimTreeParseInternal\n"
        "testb %al, %al\n"
        "jne .Lf9ca0e_0009cd41\n"
        ".Lf9ca0e_0009ccd7:\n"
        "movl %esi, (%esp)\n"
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "je .Lf9ca0e_0009cd7b\n"
        ".Lf9ca0e_0009cce7:\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll GetArrayVariable\n"
        "leal -0x20(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        "movl $0, -0x38(%ebp)\n"
        "movb $0, -0x2d(%ebp)\n"
        "jmp .Lf9ca0e_0009ca4e\n"
        ".Lf9ca0e_0009cd1c:\n"
        "xorl %eax, %eax\n"
        "xorb $1, -0x2d(%ebp)\n"
        "movzbl -0x2d(%ebp), %ecx\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "andl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %esi, %eax\n"
        "calll AnimTreeParseInternal\n"
        "testb %al, %al\n"
        "je .Lf9ca0e_0009ccd7\n"
        ".Lf9ca0e_0009cd41:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021dea4, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "movl %esi, (%esp)\n"
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "jne .Lf9ca0e_0009cce7\n"
        ".Lf9ca0e_0009cd7b:\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "movl $0, -0x38(%ebp)\n"
        "movb $0, -0x2d(%ebp)\n"
        "jmp .Lf9ca0e_0009ca4e\n"
        ".Lf9ca0e_0009cd9d:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021ddcc, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cab6\n"
        ".Lf9ca0e_0009cdcc:\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "jmp .Lf9ca0e_0009ca84\n"
        ".Lf9ca0e_0009cde3:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021de04, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cb88\n"
        ".Lf9ca0e_0009ce12:\n"
        "cmpl $1, %esi\n"
        "je .Lf9ca0e_0009cef1\n"
        "cmpl $2, %esi\n"
        "je .Lf9ca0e_0009cf29\n"
        "testl %esi, %esi\n"
        "jne .Lf9ca0e_0009cbca\n"
        "orl $1, -0x34(%ebp)\n"
        "jmp .Lf9ca0e_0009cb8f\n"
        ".Lf9ca0e_0009ce35:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021de28, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cc28\n"
        ".Lf9ca0e_0009ce64:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021de7c, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cc90\n"
        ".Lf9ca0e_0009ce93:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021de60, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cc85\n"
        ".Lf9ca0e_0009cec2:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021de04, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cc70\n"
        ".Lf9ca0e_0009cef1:\n"
        "orl $2, -0x34(%ebp)\n"
        "jmp .Lf9ca0e_0009cb8f\n"
        ".Lf9ca0e_0009cefa:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021dde0, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cb75\n"
        ".Lf9ca0e_0009cf29:\n"
        "orl $8, -0x34(%ebp)\n"
        "jmp .Lf9ca0e_0009cb8f\n"
        ".Lf9ca0e_0009cf32:\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "jne .Lf9ca0e_0009cb24\n"
        "cmpb $0, -0x42(%ebp)\n"
        "je .Lf9ca0e_0009cfc5\n"
        "movl $str_00217a74, %eax\n"
        ".Lf9ca0e_0009cf50:\n"
        "movl $4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SL_GetString_\n"
        "movl %eax, %ebx\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %ebx, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl %esi, %eax\n"
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp .Lanimtreeparseintern_done\n"
        ".Lf9ca0e_0009cf8b:\n"
        "cmpb $0, 1(%esi)\n"
        "jne .Lf9ca0e_0009cffd\n"
        ".Lf9ca0e_0009cf91:\n"
        "movl $scrAnimGlob+4, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf9ca0e_0009cfcc\n"
        "xorl %esi, %esi\n"
        "cmpb $0, -0x2d(%ebp)\n"
        "je .Lf9ca0e_0009cb1a\n"
        ".Lf9ca0e_0009cfae:\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "jmp .Lf9ca0e_0009cb1a\n"
        ".Lf9ca0e_0009cfc5:\n"
        "movl $str_00217870, %eax\n"
        "jmp .Lf9ca0e_0009cf50\n"
        ".Lf9ca0e_0009cfcc:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021debc, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "xorl %esi, %esi\n"
        "jmp .Lf9ca0e_0009cb10\n"
        ".Lf9ca0e_0009cffd:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021de04, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cf91\n"
        ".Lanimtreeparseintern_done:\n"
        "movb %%al, %0\n"
        : "=r"(result)
        : "a"(parentNode), "d"(names), "c"(bIncludeParent)
        : "ebx", "esi", "edi", "memory"
    );
    return result;
}

/* line 618 */
void Scr_LoadAnimTreeAtIndex(int index, Alloc_t Alloc, int user)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 0x10(%ebp), %eax\n"
        "shll $7, %eax\n"
        "movl 8(%ebp), %edx\n"
        "leal (%eax, %edx), %esi\n"
        "movzwl scrAnimGlob+8(%esi, %esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll GetVariableName\n"
        "movzwl %ax, %eax\n"
        "movl %eax, -0x84(%ebp)\n"
        "movl %ebx, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, -0x80(%ebp)\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "je .Lf9d02c_0009d087\n"
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9d02c_0009d087:\n"
        "movl $0, 4(%esp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf9d02c_0009d0b4\n"
        "movl $0, scrAnimPub+12(, %esi, 4)\n"
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9d02c_0009d0b4:\n"
        "movl %eax, (%esp)\n"
        "calll FindObject\n"
        "movl %eax, -0x6c(%ebp)\n"
        "calll Scr_AllocArray\n"
        "movl %eax, %edi\n"
        "movl %eax, scrAnimPub+4\n"
        "movl -0x84(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0021ded8, 4(%esp)\n"
        "leal -0x60(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl imp_scrParserPub, %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_AddSourceBuffer\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n"
        "je .Lf9d02c_0009d390\n"
        "movl imp_scrParserPub, %edx\n"
        "movl 8(%edx), %edx\n"
        "movl %edx, -0x7c(%ebp)\n"
        "movl imp_scrParserPub, %eax\n"
        "movl %esi, 8(%eax)\n"
        "movl $str_0021deec, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "movl %ebx, scrAnimGlob+4\n"
        "movl %ebx, scrAnimGlob\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $1, %ecx\n"
        "movl -0x6c(%ebp), %edx\n"
        "movl %edi, %eax\n"
        "calll AnimTreeParseInternal\n"
        "testb %al, %al\n"
        "je .Lf9d02c_0009d3c3\n"
        ".Lf9d02c_0009d177:\n"
        "calll Com_EndParseSession\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl imp_scrParserPub, %edx\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x78(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "calll Hunk_ClearTempMemoryHigh\n"
        "movl %edi, (%esp)\n"
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "je .Lf9d02c_0009d390\n"
        ".Lf9d02c_0009d1a3:\n"
        "movl scrAnimPub+4, %eax\n"
        "calll Scr_GetAnimTreeSize\n"
        "movl %eax, %ebx\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimCreateAnims\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl $4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_0021df18, (%esp)\n"
        "calll SL_GetString_\n"
        "movl %eax, %ebx\n"
        "movl 8(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl -0x84(%ebp), %ecx\n"
        "xorl %edx, %edx\n"
        "movl -0x6c(%ebp), %eax\n"
        "calll ConnectScriptToAnim\n"
        "movl %ebx, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl scrAnimPub+4, %eax\n"
        "calll Scr_PrecacheAnimationTree\n"
        "movl 8(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_0021df18, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "movl -0x70(%ebp), %ecx\n"
        "movl -0x6c(%ebp), %edx\n"
        "movl scrAnimPub+4, %eax\n"
        "calll Scr_CreateAnimationTree\n"
        "movl -0x6c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n"
        "jne .Lf9d02c_0009d315\n"
        ".Lf9d02c_0009d26a:\n"
        "movl $0, 4(%esp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "movl scrAnimPub+4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl $0, scrAnimPub+4\n"
        "movl $7, -0x1c(%ebp)\n"
        "movl -0x70(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl $1, 4(%esp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "leal -0x20(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        "movl -0x70(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll XAnimSetupSyncNodes\n"
        "shll $7, 0x10(%ebp)\n"
        "movl 0x10(%ebp), %eax\n"
        "addl 8(%ebp), %eax\n"
        "movl -0x70(%ebp), %edx\n"
        "movl %edx, scrAnimPub+12(, %eax, 4)\n"
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9d02c_0009d2ed:\n"
        "movl %ebx, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "movl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CompileError2\n"
        ".Lf9d02c_0009d303:\n"
        "movl %esi, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n"
        "je .Lf9d02c_0009d26a\n"
        ".Lf9d02c_0009d315:\n"
        "movl %esi, (%esp)\n"
        "calll GetVariableName\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl %esi, (%esp)\n"
        "calll GetVariableValueAddress\n"
        "movl %eax, %edi\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf9d02c_0009d303\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021df20, (%esp)\n"
        "calll va\n"
        "movl %eax, %ebx\n"
        "movl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_IsInOpcodeMemory\n"
        "testl %eax, %eax\n"
        "jne .Lf9d02c_0009d2ed\n"
        "movl %ebx, 8(%esp)\n"
        "movl $str_0021cdd0, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf9d02c_0009d303\n"
        ".Lf9d02c_0009d390:\n"
        "movl -0x84(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021df00, (%esp)\n"
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf9d02c_0009d1a3\n"
        ".Lf9d02c_0009d3c3:\n"
        "calll Com_GetLastTokenPos\n"
        "movl %eax, %ebx\n"
        "calll Com_EndParseSession\n"
        "movl $str_0021de04, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n"
        "subl scrAnimGlob, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CompileError\n"
        "jmp .Lf9d02c_0009d177\n"
        :
        :
        : "eax", "ebx", "ecx", "edx", "esi", "edi", "memory"
    );
}
