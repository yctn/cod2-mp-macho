/* ASM dump from: scr_animtree.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_animtree.cpp */

#include "common_types.h"
#include "imports.h"

extern struct scrAnimPub_t scrAnimPub; /* 0x0 */
static struct scrAnimGlob_t scrAnimGlob; /* scrAnimGlob */
static const char * propertyNames[3]; /* propertyNames */

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

/* line 60 */
void SetAnimCheck(int bAnimCheck)
{
    *(int *)((char *)&scrAnimGlob + 520) = bAnimCheck;
}

/* line 315 */
static void * Hunk_AllocXAnimTreePrecache(int size)
{
    return Hunk_AllocAlignInternal(size, 4);
}

/* line 322 */
static __attribute__((naked))
int Scr_GetAnimTreeSize(void)
{
    __asm__ __volatile__ (
        ".Lf9c3ba_0009c3ba:\n"
        "pushl %ebp\n" /* line 322 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 329 */
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n" /* node */
        "testl %eax, %eax\n"
        "jne .Lf9c3ba_0009c3db\n"
        "xorl %esi, %esi\n" /* size */
        /* } scope */
        "movl %esi, %eax\n" /* line 349 | size */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c3ba_0009c3db:\n"
        "xorl %esi, %esi\n" /* line 329 | size */
        "jmp .Lf9c3ba_0009c3ed\n"
        ".Lf9c3ba_0009c3df:\n"
        "movl %ebx, (%esp)\n" /* node */
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n" /* node */
        "testl %eax, %eax\n"
        "je .Lf9c3ba_0009c41a\n"
        ".Lf9c3ba_0009c3ed:\n"
        "movl %ebx, (%esp)\n" /* line 331 | node */
        "calll GetVariableName\n"
        "cmpl $0xffff, %eax\n" /* line 332 */
        "ja .Lf9c3ba_0009c3df\n"
        "movl %ebx, (%esp)\n" /* line 334 | node */
        "calll GetVarType\n"
        "subl $1, %eax\n"
        "je .Lf9c3ba_0009c429\n"
        "addl $1, %esi\n" /* line 340 | size */
        "movl %ebx, (%esp)\n" /* line 329 | node */
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n" /* node */
        "testl %eax, %eax\n"
        "jne .Lf9c3ba_0009c3ed\n"
        ".Lf9c3ba_0009c41a:\n"
        "cmpl $1, %esi\n" /* line 346 | size */
        "sbbl $-1, %esi\n" /* size */
        /* } scope */
        "movl %esi, %eax\n" /* line 349 | size */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c3ba_0009c429:\n"
        "movl %ebx, (%esp)\n" /* line 336 | node */
        "calll FindObject\n"
        "calll Scr_GetAnimTreeSize\n"
        "addl %eax, %esi\n" /* size */
        "jmp .Lf9c3ba_0009c3df\n"
    );
}

/* line 352 */
static __attribute__((naked))
void ConnectScriptToAnim(int index, unsigned int name, int treeIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 352 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %ecx, %ebx\n" /* filename */
        "movl 8(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "movl %edi, 4(%esp)\n" /* line 360 | name */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 361 */
        "jne .Lf9c43a_0009c463\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 378 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c43a_0009c463:\n"
        "movl %eax, (%esp)\n" /* line 364 */
        "calll GetVariableValueAddress\n"
        "movl %eax, %esi\n" /* value */
        "movl (%eax), %eax\n" /* line 365 */
        "testl %eax, %eax\n"
        "je .Lf9c43a_0009c49e\n"
        ".Lf9c43a_0009c473:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 368 */
        "movl 0xc(%ebp), %ebx\n" /* line 369 | treeIndex, filename */
        "movl (%esi), %eax\n" /* line 371 | value */
        "testl %eax, %eax\n"
        "jne .Lf9c43a_0009c483\n"
        "jmp .Lf9c43a_0009c490\n"
        ".Lf9c43a_0009c481:\n"
        "movl %ecx, %eax\n"
        ".Lf9c43a_0009c483:\n"
        "movl (%eax), %ecx\n" /* line 373 */
        "movw %bx, 2(%eax)\n" /* line 374 | filename */
        "movw %dx, (%eax)\n"
        "testl %ecx, %ecx\n" /* line 371 */
        "jne .Lf9c43a_0009c481\n"
        ".Lf9c43a_0009c490:\n"
        "movl $0, (%esi)\n" /* line 377 | value */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 378 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c43a_0009c49e:\n"
        "movl %ebx, (%esp)\n" /* line 366 | filename */
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n" /* filename */
        "movl %edi, (%esp)\n" /* name */
        "calll SL_ConvertToString\n"
        "movl %ebx, 0xc(%esp)\n" /* filename */
        "movl %eax, 8(%esp)\n"
        "movl $str_0021dd88, 4(%esp)\n" /* "duplicate animation '%s' in 'animtrees/%s.atr'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf9c43a_0009c473\n"
    );
}

/* line 396 */
struct XAnim_s * Scr_GetAnims(int index)
{
    return *(struct XAnim_s **)(0x114e22c + index * 4);
}

/* line 407 */
static __attribute__((naked))
int Scr_CreateAnimationTree(unsigned int names, struct XAnim_s *anims, unsigned int childIndex, const char *parentName, unsigned int parentIndex, unsigned int filename, int treeIndex)
{
    __asm__ __volatile__ (
        ".Lf9c4de_0009c4de:\n"
        "pushl %ebp\n" /* line 407 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %edi\n" /* parentName, parentNode */
        "movl %edx, -0x20(%ebp)\n"
        "movl %ecx, -0x24(%ebp)\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 416 */
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n" /* name */
        "testl %eax, %eax\n"
        "jne .Lf9c4de_0009c59c\n"
        "xorl %esi, %esi\n" /* size */
        "movl $0, 4(%esp)\n" /* line 424 */
        "movl %edi, (%esp)\n" /* parentNode */
        "calll FindArrayVariable\n"
        "testl %eax, %eax\n" /* line 425 */
        "jne .Lf9c4de_0009c5d4\n"
        ".Lf9c4de_0009c51b:\n"
        "xorl %ebx, %ebx\n" /* name */
        ".Lf9c4de_0009c51d:\n"
        "movl imp_scrVarPub, %eax\n" /* line 439 */
        "movl 0x3c(%eax), %edx\n"
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "addl 0x10(%ebp), %eax\n" /* parentIndex */
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "addl 8(%ebp), %edx\n" /* childIndex */
        "movl %edx, %ecx\n"
        "shll $5, %ecx\n"
        "subl %edx, %ecx\n"
        "addl %esi, %ecx\n" /* size */
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%ebx, %eax), %eax\n" /* name */
        "movl imp_scrVarPub, %edx\n"
        "movl %eax, 0x3c(%edx)\n"
        "movl %ebx, 0x14(%esp)\n" /* line 440 | name */
        "movl %esi, 0x10(%esp)\n" /* size */
        "movl 8(%ebp), %eax\n" /* childIndex */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* parentName */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* parentIndex */
        "movl %edx, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimBlend\n"
        "addl 8(%ebp), %esi\n" /* line 443 | childIndex, size */
        "movl %esi, -0x1c(%ebp)\n" /* size */
        "movl %edi, (%esp)\n" /* line 445 | parentNode */
        "calll FindNextSibling\n"
        "movl %eax, %esi\n" /* size */
        "testl %eax, %eax\n"
        "jne .Lf9c4de_0009c5e4\n"
        /* } scope */
        ".Lf9c4de_0009c591:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 469 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c4de_0009c59c:\n"
        "xorl %esi, %esi\n" /* line 416 | size */
        ".Lf9c4de_0009c59e:\n"
        "movl %ebx, (%esp)\n" /* line 418 | name */
        "calll GetVariableName\n"
        "cmpl $0x10000, %eax\n" /* line 421 */
        "adcl $0, %esi\n" /* size */
        "movl %ebx, (%esp)\n" /* line 416 | name */
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n" /* name */
        "testl %eax, %eax\n"
        "jne .Lf9c4de_0009c59e\n"
        "movl $0, 4(%esp)\n" /* line 424 */
        "movl %edi, (%esp)\n" /* parentNode */
        "calll FindArrayVariable\n"
        "testl %eax, %eax\n" /* line 425 */
        "je .Lf9c4de_0009c51b\n"
        ".Lf9c4de_0009c5d4:\n"
        "movl %eax, (%esp)\n"
        "calll GetVariableValueAddress\n"
        "movzwl (%eax), %ebx\n" /* name */
        "jmp .Lf9c4de_0009c51d\n"
        ".Lf9c4de_0009c5e4:\n"
        "movl 8(%ebp), %edi\n" /* line 445 | childIndex, parentNode */
        "movl imp_scrVarPub, %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "jmp .Lf9c4de_0009c600\n"
        ".Lf9c4de_0009c5f2:\n"
        "movl %esi, (%esp)\n" /* size */
        "calll FindNextSibling\n"
        "movl %eax, %esi\n" /* size */
        "testl %eax, %eax\n"
        "je .Lf9c4de_0009c591\n"
        ".Lf9c4de_0009c600:\n"
        "movl %esi, (%esp)\n" /* line 447 | size */
        "calll GetVariableName\n"
        "movl %eax, %ebx\n" /* name */
        "cmpl $0xffff, %eax\n" /* line 448 */
        "ja .Lf9c4de_0009c5f2\n"
        "movl 0x18(%ebp), %eax\n" /* line 451 | treeIndex */
        "movl %eax, 4(%esp)\n"
        "movzwl %bx, %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* filename */
        "movl %edi, %edx\n" /* parentNode */
        "movl -0x20(%ebp), %eax\n"
        "calll ConnectScriptToAnim\n"
        "movl %esi, (%esp)\n" /* line 453 | size */
        "calll GetVarType\n"
        "subl $1, %eax\n"
        "je .Lf9c4de_0009c66e\n"
        "movl -0x28(%ebp), %edx\n" /* line 462 */
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal (%edi, %edx), %edx\n" /* parentNode */
        "movl -0x28(%ebp), %eax\n"
        "movl %edx, 0x3c(%eax)\n"
        "movl %ebx, (%esp)\n" /* line 463 | name */
        "calll SL_ConvertToString\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* parentNode */
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll XAnimCreate\n"
        "addl $1, %edi\n" /* line 465 | parentNode */
        "jmp .Lf9c4de_0009c5f2\n"
        ".Lf9c4de_0009c66e:\n"
        "movl %ebx, (%esp)\n" /* line 455 | name */
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n" /* name */
        "movl %esi, (%esp)\n" /* size */
        "calll FindObject\n"
        "movl 0x18(%ebp), %edx\n" /* treeIndex */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* filename */
        "movl %edx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* parentNode */
        "movl %ebx, 4(%esp)\n" /* name */
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl -0x20(%ebp), %edx\n"
        "calll Scr_CreateAnimationTree\n"
        "movl %eax, -0x1c(%ebp)\n"
        "addl $1, %edi\n" /* line 465 | parentNode */
        "jmp .Lf9c4de_0009c5f2\n"
    );
}

/* line 498 */
static __attribute__((naked))
void Scr_PrecacheAnimationTree(void)
{
    __asm__ __volatile__ (
        ".Lf9c6b2_0009c6b2:\n"
        "pushl %ebp\n" /* line 498 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 503 | parentNode */
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n" /* parentNode, node */
        "testl %eax, %eax\n" /* parentNode */
        "jne .Lf9c6b2_0009c702\n"
        /* } scope */
        ".Lf9c6b2_0009c6c8:\n"
        "addl $0x10, %esp\n" /* line 517 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c6b2_0009c6cf:\n"
        "movl %ebx, (%esp)\n" /* line 508 | node */
        "calll GetVarType\n"
        "subl $1, %eax\n" /* parentNode */
        "je .Lf9c6b2_0009c715\n"
        "movl %esi, (%esp)\n" /* line 514 | name */
        "calll SL_ConvertToString\n"
        "movl $Hunk_AllocXAnimTreePrecache, 4(%esp)\n"
        "movl %eax, (%esp)\n" /* parentNode */
        "calll XAnimPrecache\n"
        ".Lf9c6b2_0009c6f4:\n"
        "movl %ebx, (%esp)\n" /* line 503 | node */
        "calll FindNextSibling\n"
        "movl %eax, %ebx\n" /* parentNode, node */
        "testl %eax, %eax\n" /* parentNode */
        "je .Lf9c6b2_0009c6c8\n"
        ".Lf9c6b2_0009c702:\n"
        "movl %ebx, (%esp)\n" /* line 505 | node */
        "calll GetVariableName\n"
        "movl %eax, %esi\n" /* parentNode, name */
        "cmpl $0xffff, %eax\n" /* line 506 | parentNode */
        "ja .Lf9c6b2_0009c6f4\n"
        "jmp .Lf9c6b2_0009c6cf\n"
        ".Lf9c6b2_0009c715:\n"
        "movl %ebx, (%esp)\n" /* line 510 | node */
        "calll FindObject\n"
        "calll Scr_PrecacheAnimationTree\n"
        "jmp .Lf9c6b2_0009c6f4\n"
    );
}

/* line 521 */
static __attribute__((naked))
unsigned int Scr_UsingTreeInternal(int *index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 521 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl %ecx, %esi\n" /* user */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 533 | filename */
        "calll Scr_CreateCanonicalFilename\n"
        "movl %eax, -0x20(%ebp)\n" /* filename, name */
        "movl %eax, 4(%esp)\n" /* line 535 | filename */
        "movl scrAnimPub, %eax\n" /* filename */
        "movl %eax, (%esp)\n" /* filename */
        "calll FindVariable\n"
        "movl %eax, %ebx\n" /* filename, id */
        "testl %eax, %eax\n" /* line 536 | filename */
        "jne .Lf9c724_0009c7cb\n"
        "movl -0x20(%ebp), %eax\n" /* line 538 | name, filename */
        "movl %eax, 4(%esp)\n" /* filename */
        "movl scrAnimPub, %eax\n" /* filename */
        "movl %eax, (%esp)\n" /* filename */
        "calll GetNewVariable\n"
        "movl %eax, %ebx\n" /* filename, id */
        "movl %eax, (%esp)\n" /* line 539 | filename */
        "calll GetObjectA\n"
        "movl %eax, -0x1c(%ebp)\n" /* filename, fileId */
        "movl scrAnimPub+1036(, %esi, 4), %edx\n" /* line 541 */
        "addl $1, %edx\n"
        "movl %edx, scrAnimPub+1036(, %esi, 4)\n"
        "shll $7, %esi\n" /* line 543 | user */
        "leal (%esi, %edx), %eax\n" /* user, filename */
        "movw %bx, scrAnimGlob+8(%eax, %eax)\n" /* id, filename */
        "movl -0x24(%ebp), %eax\n" /* line 545 | filename */
        "movl %edx, (%eax)\n" /* filename */
        ".Lf9c724_0009c799:\n"
        "movl $0, 4(%esp)\n" /* line 566 */
        "movl -0x1c(%ebp), %eax\n" /* fileId, filename */
        "movl %eax, (%esp)\n" /* filename */
        "calll GetVariable\n"
        "movl %eax, (%esp)\n" /* filename */
        "calll GetArray\n"
        "movl %eax, %ebx\n" /* filename, id */
        "movl -0x20(%ebp), %eax\n" /* line 567 | name, filename */
        "movl %eax, (%esp)\n" /* filename */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 570 | id, filename */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c724_0009c7cb:\n"
        "movl %eax, (%esp)\n" /* line 549 | filename */
        "calll FindObject\n"
        "movl %eax, -0x1c(%ebp)\n" /* filename, fileId */
        "movl -0x24(%ebp), %eax\n" /* line 551 | filename */
        "movl $0, (%eax)\n" /* filename */
        "movl %esi, %eax\n" /* line 552 | user, filename */
        "shll $8, %eax\n" /* filename */
        "leal scrAnimGlob+8(%eax), %edi\n" /* filename, using_xanim_lookup */
        "movl scrAnimPub+1036(, %esi, 4), %ecx\n" /* line 553 */
        "testl %ecx, %ecx\n"
        "jle .Lf9c724_0009c799\n"
        "movzwl 2(%edi), %eax\n" /* line 555 | using_xanim_lookup, filename */
        "cmpl %eax, %ebx\n" /* filename, id */
        "je .Lf9c724_0009c818\n"
        "movl $1, %edx\n"
        ".Lf9c724_0009c802:\n"
        "addl $1, %edx\n" /* line 553 */
        "cmpl %ecx, %edx\n"
        "jg .Lf9c724_0009c799\n"
        "movzwl (%edi, %edx, 2), %eax\n" /* line 555 | using_xanim_lookup, filename */
        "cmpl %eax, %ebx\n" /* filename, id */
        "jne .Lf9c724_0009c802\n"
        "movl -0x24(%ebp), %eax\n" /* line 557 | filename */
        "movl %edx, (%eax)\n" /* filename */
        "jmp .Lf9c724_0009c799\n"
        ".Lf9c724_0009c818:\n"
        "movl $1, %edx\n" /* line 555 */
        "movl -0x24(%ebp), %eax\n" /* line 557 | filename */
        "movl %edx, (%eax)\n" /* filename */
        "jmp .Lf9c724_0009c799\n"
    );
}

/* line 573 */
__attribute__((naked))
void Scr_UsingTree(const char *filename, unsigned int sourcePos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 573 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* filename */
        "movl 0xc(%ebp), %esi\n" /* sourcePos */
        "movl %ebx, (%esp)\n" /* line 575 | filename */
        "calll Scr_IsIdentifier\n"
        "testb %al, %al\n"
        "jne .Lf9c828_0009c857\n"
        "movl $str_0021ddb8, 0xc(%ebp)\n" /* line 577 | sourcePos */
        "movl %esi, 8(%ebp)\n" /* sourcePos, filename */
        "addl $0x10, %esp\n" /* line 582 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp CompileError\n" /* line 577 */
        ".Lf9c828_0009c857:\n"
        "movl $1, %ecx\n" /* line 581 */
        "movl $scrAnimPub+1044, %edx\n"
        "movl %ebx, %eax\n" /* filename */
        "calll Scr_UsingTreeInternal\n"
        "movl %eax, scrAnimPub+8\n"
        "addl $0x10, %esp\n" /* line 582 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 698 */
__attribute__((naked))
struct scr_animtree_t Scr_FindAnimTree(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 698 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 708 | filename */
        "movl %eax, (%esp)\n"
        "calll Scr_CreateCanonicalFilename\n"
        "movl %eax, %ebx\n" /* filenameId */
        "movl %eax, 4(%esp)\n" /* line 709 */
        "movl scrAnimPub, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, %esi\n" /* fileId */
        "movl %ebx, (%esp)\n" /* line 710 | filenameId */
        "calll SL_RemoveRefToString\n"
        "testl %esi, %esi\n" /* line 714 | fileId */
        "jne .Lf9c874_0009c8b1\n"
        ".Lf9c874_0009c8a8:\n"
        "xorl %eax, %eax\n" /* line 732 */
        /* } scope */
        ".Lf9c874_0009c8aa:\n"
        "addl $0x10, %esp\n" /* line 733 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c874_0009c8b1:\n"
        "movl %esi, (%esp)\n" /* line 719 | fileId */
        "calll GetVariableName\n"
        "movl %esi, (%esp)\n" /* line 721 | fileId */
        "calll FindObject\n"
        "movl $1, 4(%esp)\n" /* line 724 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 725 */
        "je .Lf9c874_0009c8a8\n"
        "movl %eax, (%esp)\n" /* line 728 */
        "calll Scr_EvalVariable\n"
        "jmp .Lf9c874_0009c8aa\n"
    );
}

/* line 738 */
__attribute__((naked))
void Scr_FindAnim(const char *filename, const char *animName, scr_anim_t *anim, int user)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 738 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* anim */
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 743 */
        "movl $0, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* animName */
        "movl %eax, (%esp)\n"
        "calll SL_GetLowercaseString_\n"
        "movl %eax, %esi\n" /* name */
        "leal -0x1c(%ebp), %edx\n" /* line 744 | index */
        "movl 0x14(%ebp), %ecx\n" /* user */
        "movl 8(%ebp), %eax\n" /* filename */
        "calll Scr_UsingTreeInternal\n"
        "movl %eax, %ebx\n" /* names */
        /* { scope 2: tempValue */
        /* { scope 3 */
        "movl %esi, 4(%esp)\n" /* line 145 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 146 */
        "jne .Lf9c8e0_0009c964\n"
        "movl %esi, 4(%esp)\n" /* line 148 */
        "movl %ebx, (%esp)\n"
        "calll GetNewVariable\n"
        "movl $0, (%edi)\n" /* line 150 */
        "movl $7, -0x20(%ebp)\n" /* line 152 */
        "movl %edi, -0x24(%ebp)\n" /* line 153 | tempValue */
        "leal -0x24(%ebp), %edx\n" /* line 154 | tempValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        /* } scope */
        /* } scope */
        "movl %esi, (%esp)\n" /* line 745 | name */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 746 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: tempValue */
        /* { scope 3 */
        ".Lf9c8e0_0009c964:\n"
        "movl %eax, (%esp)\n" /* line 158 */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %edx\n" /* line 159 */
        "movl %edx, (%edi)\n"
        "movl %edi, (%eax)\n" /* line 160 */
        /* } scope */
        /* } scope */
        "movl %esi, (%esp)\n" /* line 745 | name */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 746 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 164 */
__attribute__((naked))
void Scr_EmitAnimation(char *pos, unsigned int animName, unsigned int sourcePos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 164 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* pos */
        "movl scrAnimPub+8, %ebx\n" /* line 166 */
        "testl %ebx, %ebx\n"
        "jne .Lf9c982_0009c9b1\n"
        "movl $str_0021d930, 4(%esp)\n" /* line 168 */
        "movl 0x10(%ebp), %eax\n" /* sourcePos */
        "movl %eax, (%esp)\n"
        "calll CompileError\n"
        "addl $0x20, %esp\n" /* line 173 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c982_0009c9b1:\n"
        "movl 0xc(%ebp), %eax\n" /* line 145 | animName */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 146 */
        "je .Lf9c982_0009c9d9\n"
        "movl %eax, (%esp)\n" /* line 158 */
        "calll GetVariableValueAddress\n"
        "movl (%eax), %edx\n" /* line 159 */
        "movl %edx, (%esi)\n"
        "movl %esi, (%eax)\n" /* line 160 */
        /* } scope */
        "addl $0x20, %esp\n" /* line 173 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9c982_0009c9d9:\n"
        "movl 0xc(%ebp), %eax\n" /* line 148 | animName */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll GetNewVariable\n"
        "movl $0, (%esi)\n" /* line 150 */
        "movl $7, -0xc(%ebp)\n" /* line 152 */
        "movl %esi, -0x10(%ebp)\n" /* line 153 | tempValue */
        "leal -0x10(%ebp), %edx\n" /* line 154 | tempValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 173 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 179 */
static __attribute__((naked))
Bool AnimTreeParseInternal(unsigned int parentNode, unsigned int names, Bool bIncludeParent, int bLoop, int bComplete)
{
    __asm__ __volatile__ (
        ".Lf9ca0e_0009ca0e:\n"
        "pushl %ebp\n" /* line 179 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %edx, -0x40(%ebp)\n"
        "movb %cl, -0x41(%ebp)\n"
        "movzbl 8(%ebp), %eax\n" /* bLoop */
        "movb %al, -0x42(%ebp)\n" /* bLoop */
        "movzbl 0xc(%ebp), %eax\n" /* bComplete */
        "movb %al, -0x43(%ebp)\n" /* bComplete */
        /* { scope 1 */
        "movl $6, -0x1c(%ebp)\n" /* line 190 */
        "movl $0, -0x2c(%ebp)\n"
        "movl $0, -0x38(%ebp)\n" /* currentAnim */
        "movl $0, -0x34(%ebp)\n" /* flags */
        "movb $0, -0x2d(%ebp)\n" /* bIgnore */
        ".Lf9ca0e_0009ca4e:\n"
        "movl $scrAnimGlob+4, (%esp)\n" /* line 199 */
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* currentAnimArray */
        "movl scrAnimGlob+4, %ebx\n" /* line 200 | animName */
        "testl %ebx, %ebx\n" /* animName */
        "je .Lf9ca0e_0009cb0b\n"
        ".Lf9ca0e_0009ca6a:\n"
        "movl %eax, (%esp)\n" /* line 206 */
        "calll Scr_IsIdentifier\n"
        "testb %al, %al\n"
        "je .Lf9ca0e_0009cc28\n"
        "cmpb $0, -0x2d(%ebp)\n" /* line 208 | bIgnore */
        "jne .Lf9ca0e_0009cdcc\n"
        ".Lf9ca0e_0009ca84:\n"
        "movl $4, 8(%esp)\n" /* line 211 */
        "movl $2, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* currentAnimArray */
        "calll SL_GetLowercaseString_\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, 4(%esp)\n" /* line 213 */
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf9ca0e_0009cd9d\n"
        ".Lf9ca0e_0009cab6:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 216 */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, -0x38(%ebp)\n" /* currentAnim */
        "cmpb $0, -0x43(%ebp)\n" /* line 217 | bComplete */
        "je .Lf9ca0e_0009cb2e\n"
        ".Lf9ca0e_0009cad1:\n"
        "movb $0, -0x2d(%ebp)\n" /* bIgnore */
        "movl $scrAnimGlob+4, (%esp)\n" /* line 220 */
        "calll Com_ParseOnLine\n"
        "movl %eax, %esi\n" /* currentAnimArray */
        "cmpb $0, (%eax)\n" /* line 221 */
        "jne .Lf9ca0e_0009cb65\n"
        ".Lf9ca0e_0009cae8:\n"
        "movl $0, -0x34(%ebp)\n" /* line 190 | flags */
        "movl $scrAnimGlob+4, (%esp)\n" /* line 199 */
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* currentAnimArray */
        "movl scrAnimGlob+4, %ebx\n" /* line 200 | animName */
        "testl %ebx, %ebx\n" /* animName */
        "jne .Lf9ca0e_0009ca6a\n"
        /* { scope 2 */
        ".Lf9ca0e_0009cb0b:\n"
        "movl $1, %esi\n" /* line 72 */
        /* } scope */
        ".Lf9ca0e_0009cb10:\n"
        "cmpb $0, -0x2d(%ebp)\n" /* line 284 | bIgnore */
        "jne .Lf9ca0e_0009cfae\n"
        ".Lf9ca0e_0009cb1a:\n"
        "cmpb $0, -0x41(%ebp)\n" /* line 287 */
        "jne .Lf9ca0e_0009cf32\n"
        /* } scope */
        ".Lf9ca0e_0009cb24:\n"
        "movl %esi, %eax\n" /* line 295 | currentAnimArray */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9ca0e_0009cb2e:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 217 */
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "jne .Lf9ca0e_0009cad1\n"
        "movl scrAnimGlob+520, %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf9ca0e_0009cad1\n"
        "movb $1, -0x2d(%ebp)\n" /* bIgnore */
        "movl $scrAnimGlob+4, (%esp)\n" /* line 220 */
        "calll Com_ParseOnLine\n"
        "movl %eax, %esi\n" /* currentAnimArray */
        "cmpb $0, (%eax)\n" /* line 221 */
        "je .Lf9ca0e_0009cae8\n"
        ".Lf9ca0e_0009cb65:\n"
        "movl %eax, (%esp)\n" /* line 224 */
        "calll Scr_IsIdentifier\n"
        "testb %al, %al\n"
        "jne .Lf9ca0e_0009cefa\n"
        ".Lf9ca0e_0009cb75:\n"
        "cmpb $0x3a, (%esi)\n" /* line 227 | currentAnimArray */
        "jne .Lf9ca0e_0009cde3\n"
        "cmpb $0, 1(%esi)\n" /* currentAnimArray */
        "jne .Lf9ca0e_0009cde3\n"
        /* { scope 2 */
        ".Lf9ca0e_0009cb88:\n"
        "movl $0, -0x34(%ebp)\n" /* line 72 | flags */
        /* } scope */
        ".Lf9ca0e_0009cb8f:\n"
        "movl $scrAnimGlob+4, (%esp)\n" /* line 103 */
        "calll Com_ParseOnLine\n"
        "movl %eax, %edi\n"
        "cmpb $0, (%eax)\n" /* line 104 */
        "je .Lf9ca0e_0009cc07\n"
        ".Lf9ca0e_0009cba2:\n"
        "xorl %esi, %esi\n" /* line 105 */
        "movl $propertyNames, %ebx\n" /* pos */
        ".Lf9ca0e_0009cba9:\n"
        "movl (%ebx), %eax\n" /* line 109 | pos */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf9ca0e_0009ce12\n"
        "addl $1, %esi\n" /* line 107 */
        "addl $4, %ebx\n" /* pos */
        "cmpl $3, %esi\n"
        "jne .Lf9ca0e_0009cba9\n"
        ".Lf9ca0e_0009cbca:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021de10, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "movl $scrAnimGlob+4, (%esp)\n" /* line 103 */
        "calll Com_ParseOnLine\n"
        "movl %eax, %edi\n"
        "cmpb $0, (%eax)\n" /* line 104 */
        "jne .Lf9ca0e_0009cba2\n"
        ".Lf9ca0e_0009cc07:\n"
        "movl $scrAnimGlob+4, (%esp)\n" /* line 231 */
        "calll Com_Parse\n"
        "movl %eax, %esi\n" /* currentAnimArray */
        "cmpb $0x7b, (%eax)\n" /* line 232 */
        "jne .Lf9ca0e_0009ce35\n"
        "cmpb $0, 1(%eax)\n"
        "jne .Lf9ca0e_0009ce35\n"
        ".Lf9ca0e_0009cc28:\n"
        "movzbl (%esi), %eax\n" /* line 236 | currentAnimArray */
        "cmpb $0x7b, %al\n"
        "je .Lf9ca0e_0009cc66\n"
        "cmpb $0x7d, %al\n" /* line 268 */
        "je .Lf9ca0e_0009cf8b\n"
        /* { scope 2 */
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021de04, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009ca4e\n"
        /* } scope */
        ".Lf9ca0e_0009cc66:\n"
        "cmpb $0, 1(%esi)\n" /* line 238 | currentAnimArray */
        "jne .Lf9ca0e_0009cec2\n"
        ".Lf9ca0e_0009cc70:\n"
        "movl $scrAnimGlob+4, (%esp)\n" /* line 241 */
        "calll Com_ParseOnLine\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf9ca0e_0009ce93\n"
        ".Lf9ca0e_0009cc85:\n"
        "movl -0x38(%ebp), %edx\n" /* line 244 | currentAnim */
        "testl %edx, %edx\n"
        "je .Lf9ca0e_0009ce64\n"
        ".Lf9ca0e_0009cc90:\n"
        "movl -0x38(%ebp), %eax\n" /* line 247 | currentAnim */
        "movl %eax, (%esp)\n"
        "calll GetArray\n"
        "movl %eax, %esi\n" /* currentAnimArray */
        "cmpb $0, -0x43(%ebp)\n" /* line 248 | bComplete */
        "jne .Lf9ca0e_0009ccaf\n"
        "testb $8, -0x34(%ebp)\n" /* flags */
        "je .Lf9ca0e_0009cd1c\n"
        "cmpb $0, -0x2d(%ebp)\n" /* bIgnore */
        "jne .Lf9ca0e_0009cd1c\n"
        ".Lf9ca0e_0009ccaf:\n"
        "movl $1, %eax\n"
        "xorb $1, -0x2d(%ebp)\n" /* bIgnore */
        "movzbl -0x2d(%ebp), %ecx\n" /* bIgnore */
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* flags */
        "andl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %esi, %eax\n" /* currentAnimArray */
        "calll AnimTreeParseInternal\n"
        "testb %al, %al\n"
        "jne .Lf9ca0e_0009cd41\n"
        ".Lf9ca0e_0009ccd7:\n"
        "movl %esi, (%esp)\n" /* line 251 | currentAnimArray */
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "je .Lf9ca0e_0009cd7b\n"
        ".Lf9ca0e_0009cce7:\n"
        "movl -0x34(%ebp), %eax\n" /* line 253 | flags */
        "movl %eax, -0x20(%ebp)\n" /* tempValue */
        "movl $0, 4(%esp)\n" /* line 254 */
        "movl %esi, (%esp)\n" /* currentAnimArray */
        "calll GetArrayVariable\n"
        "leal -0x20(%ebp), %edx\n" /* tempValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        "movl $0, -0x38(%ebp)\n" /* currentAnim */
        "movb $0, -0x2d(%ebp)\n" /* bIgnore */
        "jmp .Lf9ca0e_0009ca4e\n"
        ".Lf9ca0e_0009cd1c:\n"
        "xorl %eax, %eax\n" /* line 248 */
        "xorb $1, -0x2d(%ebp)\n" /* bIgnore */
        "movzbl -0x2d(%ebp), %ecx\n" /* bIgnore */
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* flags */
        "andl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %esi, %eax\n" /* currentAnimArray */
        "calll AnimTreeParseInternal\n"
        "testb %al, %al\n"
        "je .Lf9ca0e_0009ccd7\n"
        /* { scope 2 */
        ".Lf9ca0e_0009cd41:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021dea4, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 251 | currentAnimArray */
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "jne .Lf9ca0e_0009cce7\n"
        ".Lf9ca0e_0009cd7b:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 260 */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "movl $0, -0x38(%ebp)\n" /* currentAnim */
        "movb $0, -0x2d(%ebp)\n" /* bIgnore */
        "jmp .Lf9ca0e_0009ca4e\n"
        /* { scope 2 */
        ".Lf9ca0e_0009cd9d:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021ddcc, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cab6\n"
        /* } scope */
        ".Lf9ca0e_0009cdcc:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 209 */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "jmp .Lf9ca0e_0009ca84\n"
        /* { scope 2 */
        ".Lf9ca0e_0009cde3:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021de04, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cb88\n"
        /* } scope */
        ".Lf9ca0e_0009ce12:\n"
        "cmpl $1, %esi\n" /* line 113 */
        "je .Lf9ca0e_0009cef1\n"
        "cmpl $2, %esi\n"
        "je .Lf9ca0e_0009cf29\n"
        "testl %esi, %esi\n"
        "jne .Lf9ca0e_0009cbca\n"
        "orl $1, -0x34(%ebp)\n" /* line 116 | flags */
        "jmp .Lf9ca0e_0009cb8f\n"
        /* { scope 2 */
        ".Lf9ca0e_0009ce35:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021de28, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cc28\n"
        /* } scope */
        /* { scope 2 */
        ".Lf9ca0e_0009ce64:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021de7c, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cc90\n"
        /* } scope */
        /* { scope 2 */
        ".Lf9ca0e_0009ce93:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021de60, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cc85\n"
        /* } scope */
        /* { scope 2 */
        ".Lf9ca0e_0009cec2:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021de04, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cc70\n"
        /* } scope */
        ".Lf9ca0e_0009cef1:\n"
        "orl $2, -0x34(%ebp)\n" /* line 120 | flags */
        "jmp .Lf9ca0e_0009cb8f\n"
        /* { scope 2 */
        ".Lf9ca0e_0009cefa:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021dde0, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cb75\n"
        /* } scope */
        ".Lf9ca0e_0009cf29:\n"
        "orl $8, -0x34(%ebp)\n" /* line 124 | flags */
        "jmp .Lf9ca0e_0009cb8f\n"
        ".Lf9ca0e_0009cf32:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 287 */
        "movl %eax, (%esp)\n"
        "calll GetArraySize\n"
        "testl %eax, %eax\n"
        "jne .Lf9ca0e_0009cb24\n"
        "cmpb $0, -0x42(%ebp)\n" /* line 289 | bLoop */
        "je .Lf9ca0e_0009cfc5\n"
        "movl $str_00217a74, %eax\n" /* "void_loop" */
        ".Lf9ca0e_0009cf50:\n"
        "movl $4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SL_GetString_\n"
        "movl %eax, %ebx\n" /* animName */
        "movl %eax, 4(%esp)\n" /* line 290 */
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %ebx, (%esp)\n" /* line 291 | animName */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 295 | currentAnimArray */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9ca0e_0009cf8b:\n"
        "cmpb $0, 1(%esi)\n" /* line 270 | currentAnimArray */
        "jne .Lf9ca0e_0009cffd\n"
        ".Lf9ca0e_0009cf91:\n"
        "movl $scrAnimGlob+4, (%esp)\n" /* line 273 */
        "calll Com_ParseOnLine\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf9ca0e_0009cfcc\n"
        "xorl %esi, %esi\n" /* currentAnimArray */
        "cmpb $0, -0x2d(%ebp)\n" /* line 284 | bIgnore */
        "je .Lf9ca0e_0009cb1a\n"
        ".Lf9ca0e_0009cfae:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 285 */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "jmp .Lf9ca0e_0009cb1a\n"
        ".Lf9ca0e_0009cfc5:\n"
        "movl $str_00217870, %eax\n" /* line 289 */
        "jmp .Lf9ca0e_0009cf50\n"
        /* { scope 2 */
        ".Lf9ca0e_0009cfcc:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021debc, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "xorl %esi, %esi\n"
        "jmp .Lf9ca0e_0009cb10\n"
        /* } scope */
        /* { scope 2 */
        ".Lf9ca0e_0009cffd:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021de04, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9ca0e_0009cf91\n"
    );
}

/* line 618 */
__attribute__((naked))
void Scr_LoadAnimTreeAtIndex(int index, Alloc_t Alloc, int user)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 618 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1: name */
        "movl 0x10(%ebp), %eax\n" /* line 630 | user */
        "shll $7, %eax\n"
        "movl 8(%ebp), %edx\n" /* index */
        "leal (%eax, %edx), %esi\n" /* animId */
        "movzwl scrAnimGlob+8(%esi, %esi), %ebx\n" /* animId, id */
        "movl %ebx, (%esp)\n" /* line 638 | id */
        "calll GetVariableName\n"
        "movzwl %ax, %eax\n"
        "movl %eax, -0x84(%ebp)\n" /* filenameId */
        "movl %ebx, (%esp)\n" /* line 640 | id */
        "calll FindObject\n"
        "movl %eax, -0x80(%ebp)\n" /* fileId */
        "movl $1, 4(%esp)\n" /* line 643 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "je .Lf9d02c_0009d087\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 695 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: name */
        ".Lf9d02c_0009d087:\n"
        "movl $0, 4(%esp)\n" /* line 648 */
        "movl -0x80(%ebp), %eax\n" /* fileId */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 649 */
        "jne .Lf9d02c_0009d0b4\n"
        "movl $0, scrAnimPub+12(, %esi, 4)\n" /* line 651 */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 695 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: name */
        ".Lf9d02c_0009d0b4:\n"
        "movl %eax, (%esp)\n" /* line 654 */
        "calll FindObject\n"
        "movl %eax, -0x6c(%ebp)\n"
        "calll Scr_AllocArray\n" /* line 658 */
        "movl %eax, %edi\n" /* value */
        "movl %eax, scrAnimPub+4\n"
        "movl -0x84(%ebp), %edx\n" /* line 660 | filenameId */
        "movl %edx, (%esp)\n"
        "calll SL_ConvertToString\n"
        /* { scope 2: extFilename, oldFilename, oldSourceBuf */
        /* { scope 3 */
        "movl %eax, 8(%esp)\n" /* line 594 */
        "movl $str_0021ded8, 4(%esp)\n" /* "animtrees/%s.atr" */
        "leal -0x60(%ebp), %esi\n" /* extFilename, animId */
        "movl %esi, (%esp)\n" /* animId */
        "calll sprintf\n"
        "movl imp_scrParserPub, %eax\n" /* line 596 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x78(%ebp)\n" /* oldSourceBuf */
        "movl $1, 0xc(%esp)\n" /* line 597 */
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* animId */
        "movl $0, (%esp)\n"
        "calll Scr_AddSourceBuffer\n"
        "movl %eax, %ebx\n" /* sourceBuffer */
        "testl %eax, %eax\n" /* line 598 */
        "je .Lf9d02c_0009d390\n"
        "movl imp_scrParserPub, %edx\n" /* line 601 */
        "movl 8(%edx), %edx\n"
        "movl %edx, -0x7c(%ebp)\n" /* oldFilename */
        "movl imp_scrParserPub, %eax\n" /* line 602 */
        "movl %esi, 8(%eax)\n" /* animId */
        "movl $str_0021deec, (%esp)\n" /* line 302 */
        "calll Com_BeginParseSession\n"
        "movl %ebx, scrAnimGlob+4\n" /* line 304 | pos */
        "movl %ebx, scrAnimGlob\n" /* pos */
        "movl $0, 4(%esp)\n" /* line 305 */
        "movl $0, (%esp)\n"
        "movl $1, %ecx\n"
        "movl -0x6c(%ebp), %edx\n"
        "movl %edi, %eax\n"
        "calll AnimTreeParseInternal\n"
        "testb %al, %al\n"
        "je .Lf9d02c_0009d3c3\n"
        ".Lf9d02c_0009d177:\n"
        "calll Com_EndParseSession\n" /* line 308 */
        "movl -0x7c(%ebp), %eax\n" /* line 605 | oldFilename */
        "movl imp_scrParserPub, %edx\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x78(%ebp), %eax\n" /* line 606 | oldSourceBuf */
        "movl %eax, 0xc(%edx)\n"
        "calll Hunk_ClearTempMemoryHigh\n" /* line 608 */
        "movl %edi, (%esp)\n" /* line 610 | value */
        "calll GetArraySize\n"
        /* } scope */
        /* } scope */
        "testl %eax, %eax\n" /* line 660 | filename */
        "je .Lf9d02c_0009d390\n"
        ".Lf9d02c_0009d1a3:\n"
        "movl scrAnimPub+4, %eax\n" /* line 666 */
        "calll Scr_GetAnimTreeSize\n"
        "movl %eax, %ebx\n" /* id */
        "movl -0x84(%ebp), %eax\n" /* line 669 | filenameId */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl 0xc(%ebp), %edx\n" /* Alloc */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* id */
        "movl %eax, (%esp)\n"
        "calll XAnimCreateAnims\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl $4, 8(%esp)\n" /* line 671 */
        "movl $0, 4(%esp)\n"
        "movl $str_0021df18, (%esp)\n" /* "root" */
        "calll SL_GetString_\n"
        "movl %eax, %ebx\n" /* id */
        "movl 8(%ebp), %eax\n" /* line 672 | index */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* id */
        "movl -0x84(%ebp), %ecx\n" /* filenameId */
        "xorl %edx, %edx\n"
        "movl -0x6c(%ebp), %eax\n"
        "calll ConnectScriptToAnim\n"
        "movl %ebx, (%esp)\n" /* line 673 | id */
        "calll SL_RemoveRefToString\n"
        "movl scrAnimPub+4, %eax\n" /* line 676 */
        "calll Scr_PrecacheAnimationTree\n"
        "movl 8(%ebp), %edx\n" /* line 679 | index */
        "movl %edx, 0x10(%esp)\n"
        "movl -0x84(%ebp), %eax\n" /* filenameId */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_0021df18, 4(%esp)\n" /* "root" */
        "movl $1, (%esp)\n"
        "movl -0x70(%ebp), %ecx\n"
        "movl -0x6c(%ebp), %edx\n"
        "movl scrAnimPub+4, %eax\n"
        "calll Scr_CreateAnimationTree\n"
        /* { scope 2: extFilename, oldFilename, oldSourceBuf */
        "movl -0x6c(%ebp), %edx\n" /* line 479 */
        "movl %edx, (%esp)\n"
        "calll FindNextSibling\n"
        "movl %eax, %esi\n" /* animId */
        "testl %eax, %eax\n"
        "jne .Lf9d02c_0009d315\n"
        /* } scope */
        ".Lf9d02c_0009d26a:\n"
        "movl $0, 4(%esp)\n" /* line 684 */
        "movl -0x80(%ebp), %eax\n" /* fileId */
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "movl scrAnimPub+4, %eax\n" /* line 685 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl $0, scrAnimPub+4\n" /* line 686 */
        "movl $7, -0x1c(%ebp)\n" /* line 688 */
        "movl -0x70(%ebp), %edx\n" /* line 689 */
        "movl %edx, -0x20(%ebp)\n" /* tempValue */
        "movl $1, 4(%esp)\n" /* line 690 */
        "movl -0x80(%ebp), %eax\n" /* fileId */
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "leal -0x20(%ebp), %edx\n" /* tempValue */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableValue\n"
        "movl -0x70(%ebp), %edx\n" /* line 692 */
        "movl %edx, (%esp)\n"
        "calll XAnimSetupSyncNodes\n"
        "shll $7, 0x10(%ebp)\n" /* line 694 | user */
        "movl 0x10(%ebp), %eax\n" /* user */
        "addl 8(%ebp), %eax\n" /* index */
        "movl -0x70(%ebp), %edx\n"
        "movl %edx, scrAnimPub+12(, %eax, 4)\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 695 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: name */
        /* { scope 2: extFilename, oldFilename, oldSourceBuf */
        ".Lf9d02c_0009d2ed:\n"
        "movl %ebx, 8(%esp)\n" /* line 490 | msg */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "movl (%edi), %eax\n" /* value */
        "movl %eax, (%esp)\n"
        "calll CompileError2\n"
        ".Lf9d02c_0009d303:\n"
        "movl %esi, (%esp)\n" /* line 479 | animId */
        "calll FindNextSibling\n"
        "movl %eax, %esi\n" /* animId */
        "testl %eax, %eax\n"
        "je .Lf9d02c_0009d26a\n"
        ".Lf9d02c_0009d315:\n"
        "movl %esi, (%esp)\n" /* line 481 | animId */
        "calll GetVariableName\n"
        "movl %eax, -0x74(%ebp)\n" /* name */
        "movl %esi, (%esp)\n" /* line 484 | animId */
        "calll GetVariableValueAddress\n"
        "movl %eax, %edi\n" /* value */
        "movl (%eax), %eax\n" /* line 485 */
        "testl %eax, %eax\n"
        "je .Lf9d02c_0009d303\n"
        "movl -0x84(%ebp), %eax\n" /* line 488 | filenameId */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n" /* msg */
        "movl -0x74(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %ebx, 8(%esp)\n" /* msg */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021df20, (%esp)\n" /* "animation '%s' not defined in anim tree '%s'" */
        "calll va\n"
        "movl %eax, %ebx\n" /* msg */
        "movl (%edi), %eax\n" /* line 489 | value */
        "movl %eax, (%esp)\n"
        "calll Scr_IsInOpcodeMemory\n"
        "testl %eax, %eax\n"
        "jne .Lf9d02c_0009d2ed\n"
        "movl %ebx, 8(%esp)\n" /* line 492 | msg */
        "movl $str_0021cdd0, 4(%esp)\n" /* "%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf9d02c_0009d303\n"
        /* } scope */
        ".Lf9d02c_0009d390:\n"
        "movl -0x84(%ebp), %edx\n" /* line 661 | filenameId */
        "movl %edx, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021df00, (%esp)\n" /* "unknown anim tree '%s'" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf9d02c_0009d1a3\n"
        /* { scope 2: extFilename, oldFilename, oldSourceBuf */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf9d02c_0009d3c3:\n"
        "calll Com_GetLastTokenPos\n" /* line 70 */
        "movl %eax, %ebx\n" /* pos */
        "calll Com_EndParseSession\n" /* line 71 */
        "movl $str_0021de04, 8(%esp)\n" /* line 72 */
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "subl scrAnimGlob, %ebx\n" /* pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll CompileError\n"
        "jmp .Lf9d02c_0009d177\n"
    );
}

