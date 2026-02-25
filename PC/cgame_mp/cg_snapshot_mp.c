/* ASM dump from: cg_snapshot_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_snapshot_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

static void CG_ResetEntity(void);
void CG_SetNextSnap(snapshot_t *snap);
void CG_SetInitialSnapshot(snapshot_t *snap);
void CG_ProcessSnapshots(void);

/* line 47 */
static __attribute__((naked))
void CG_ResetEntity(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 47 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ebx\n" /* cent */
        /* { scope 1: attachIndex, attachIndex */
        "leal 0x204(%eax), %eax\n" /* line 54 | v */
        /* { scope 2 */
        "movl $0, 0x204(%ebx)\n" /* line 183 | cent */
        "movl $0, 4(%eax)\n" /* line 184 */
        "movl $0, 8(%eax)\n" /* line 185 */
        /* } scope */
        "leal 0xf0(%ebx), %eax\n" /* line 56 | cent */
        "movl $0xf0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cent */
        "calll memcpy\n"
        "movb $0, 0x1e3(%ebx)\n" /* line 58 | cent */
        "movb $0, 0x1e1(%ebx)\n" /* line 59 | cent */
        "leal 0x1ec(%ebx), %eax\n" /* line 61 | cent */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %esi\n"
        "movl 0x25bb0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0xfc(%ebx), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "leal 0x1f8(%ebx), %edi\n" /* line 62 | cent */
        "movl %edi, 8(%esp)\n"
        "movl 0x25bb0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x120(%ebx), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl 0xf4(%ebx), %eax\n" /* line 64 | cent */
        "cmpl $1, %eax\n"
        "je .Lf1dc43c_001dc50f\n"
        "jle .Lf1dc43c_001dc688\n"
        "cmpl $2, %eax\n"
        "je .Lf1dc43c_001dc592\n"
        "cmpl $4, %eax\n"
        "je .Lf1dc43c_001dc690\n"
        ".Lf1dc43c_001dc4fb:\n"
        "movl 0x194(%ebx), %eax\n" /* line 117 | cent */
        "movl %eax, 0x1e4(%ebx)\n" /* cent */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 120 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: attachIndex, attachIndex */
        ".Lf1dc43c_001dc50f:\n"
        "movl 0x194(%ebx), %eax\n" /* line 73 | cent */
        "movl %eax, 0x1e4(%ebx)\n" /* cent */
        "movl 0x180(%ebx), %edx\n" /* line 75 | cent */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0900(%esi, %eax, 8), %eax\n"
        "leal 0x14(%eax), %ecx\n"
        "movl 0x15c(%ebx), %edx\n" /* line 76 | cent */
        "movl %edx, 0x3e0(%ecx)\n"
        "movl 0x1c4(%ebx), %edx\n" /* line 77 | cent */
        "movl %edx, 0x3e4(%ecx)\n"
        "leal 0x3fc(%eax), %ecx\n" /* line 78 | to */
        /* { scope 2 */
        "movl 0x1f8(%ebx), %edx\n" /* line 199 | cent */
        "movl %edx, 0x3fc(%eax)\n"
        "movl 4(%edi), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0, 0x1f8(%ebx)\n" /* line 79 | cent */
        "movl $0, 0x200(%ebx)\n" /* line 80 | cent */
        "movl %ebx, (%esp)\n" /* line 81 | cent */
        "calll CG_ResetPlayerEntity\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 120 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: attachIndex, attachIndex */
        ".Lf1dc43c_001dc592:\n"
        "movl 0x180(%ebx), %edx\n" /* line 88 | cent */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0914(%esi, %eax, 8), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* ci */
        "movl 0xf0(%ebx), %edx\n" /* line 89 | cent */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0x195f5c4, %edx\n"
        "movl (%edx), %edx\n"
        "leal -0x6bf0(%edx, %eax, 8), %esi\n"
        "leal 4(%esi), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* corpseInfo */
        "movl 0x4a4(%eax), %edx\n" /* line 90 */
        "movl %edx, -0x24(%ebp)\n" /* pXAnimTree */
        "testb $8, 0xfa(%ebx)\n" /* line 92 | cent */
        "je .Lf1dc43c_001dc6a2\n"
        "movl %eax, %edx\n"
        /* { scope 2 */
        "movl $0x4b8, 8(%esp)\n" /* line 20 */
        "movl -0x2c(%ebp), %eax\n" /* ci */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x28(%ebp), %edi\n" /* corpseInfo */
        "movl $0, -0x20(%ebp)\n" /* attachIndex */
        "addl $0x204, %esi\n"
        ".Lf1dc43c_001dc616:\n"
        "movl $0x2b7f68, 4(%esp)\n" /* line 27 */
        "movl %esi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1dc43c_001dc638\n"
        "movb $0, 0x80(%edi)\n" /* line 29 */
        "movb $0, 0x200(%edi)\n" /* line 30 */
        ".Lf1dc43c_001dc638:\n"
        "addl $1, -0x20(%ebp)\n" /* line 25 | attachIndex */
        "addl $0x40, %esi\n"
        "addl $0x40, %edi\n"
        "cmpl $6, -0x20(%ebp)\n" /* attachIndex */
        "jne .Lf1dc43c_001dc616\n"
        /* } scope */
        "movl -0x24(%ebp), %edx\n" /* line 95 | pXAnimTree */
        "movl -0x28(%ebp), %eax\n" /* corpseInfo */
        "movl %edx, 0x4a4(%eax)\n"
        "movl %edx, 4(%esp)\n" /* line 96 */
        "movl -0x2c(%ebp), %edx\n" /* ci */
        "movl 0x4a4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimCloneAnimTree\n"
        "movl $0, 0x1e4(%ebx)\n" /* line 98 | cent */
        ".Lf1dc43c_001dc673:\n"
        "movl -0x28(%ebp), %eax\n" /* line 112 | corpseInfo */
        "movl $1, 0x3f8(%eax)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 120 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: attachIndex, attachIndex */
        ".Lf1dc43c_001dc688:\n"
        "testl %eax, %eax\n" /* line 64 */
        "jne .Lf1dc43c_001dc4fb\n"
        ".Lf1dc43c_001dc690:\n"
        "movl $0, 0x1e4(%ebx)\n" /* line 69 | cent */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 120 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: attachIndex, attachIndex */
        ".Lf1dc43c_001dc6a2:\n"
        "cmpb $0, 0x40(%eax)\n" /* line 103 */
        "je .Lf1dc43c_001dc72f\n"
        "movl 8(%eax), %eax\n"
        "movl -0x2c(%ebp), %edx\n" /* ci */
        "cmpl 8(%edx), %eax\n"
        "je .Lf1dc43c_001dc71e\n"
        "movl %edx, %eax\n"
        /* { scope 2 */
        ".Lf1dc43c_001dc6b9:\n"
        "movl $0x4b8, 8(%esp)\n" /* line 20 */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* corpseInfo */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x28(%ebp), %edi\n" /* corpseInfo */
        "movl $0, -0x1c(%ebp)\n" /* attachIndex */
        "addl $0x204, %esi\n"
        ".Lf1dc43c_001dc6e0:\n"
        "movl $0x2b7f68, 4(%esp)\n" /* line 27 */
        "movl %esi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1dc43c_001dc702\n"
        "movb $0, 0x80(%edi)\n" /* line 29 */
        "movb $0, 0x200(%edi)\n" /* line 30 */
        ".Lf1dc43c_001dc702:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 25 | attachIndex */
        "addl $0x40, %esi\n"
        "addl $0x40, %edi\n"
        "cmpl $6, -0x1c(%ebp)\n" /* attachIndex */
        "jne .Lf1dc43c_001dc6e0\n"
        /* } scope */
        "movl -0x24(%ebp), %edx\n" /* line 106 | pXAnimTree */
        "movl -0x28(%ebp), %eax\n" /* corpseInfo */
        "movl %edx, 0x4a4(%eax)\n"
        ".Lf1dc43c_001dc71e:\n"
        "movl 0x194(%ebx), %eax\n" /* line 109 | cent */
        "movl %eax, 0x1e4(%ebx)\n" /* cent */
        "jmp .Lf1dc43c_001dc673\n"
        ".Lf1dc43c_001dc72f:\n"
        "movl -0x2c(%ebp), %eax\n" /* ci */
        "jmp .Lf1dc43c_001dc6b9\n"
    );
}

/* line 297 */
__attribute__((naked))
void CG_SetNextSnap(snapshot_t *snap)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 297 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        /* { scope 1 */
        "leal -0x418(%ebp), %eax\n" /* line 314 | centInPrevSnapshot */
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0x195f584, %esi\n" /* line 316 | entnum */
        "movl (%esi), %eax\n" /* entnum */
        "movl 0x24(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1dc734_001dc7f3\n"
        "movl 0x26b4(%ecx), %eax\n" /* line 319 */
        "testl %eax, %eax\n"
        "jle .Lf1dc734_001dca21\n"
        "xorl %ebx, %ebx\n" /* tagName */
        "movl 0x195f5cc, %edi\n"
        ".Lf1dc734_001dc787:\n"
        "movl %ebx, %edx\n" /* line 322 | tagName */
        "shll $4, %edx\n"
        "movl %ebx, %eax\n" /* tagName */
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x26bc(%eax, %ecx), %edx\n"
        "movl (%edi), %ecx\n" /* line 325 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movb $0, 0x1e0(%ecx, %eax, 4)\n"
        "movb $1, -0x418(%ebp, %edx)\n" /* line 326 */
        "addl $1, %ebx\n" /* line 319 | tagName */
        "movl (%esi), %eax\n" /* entnum */
        "movl 0x24(%eax), %ecx\n"
        "cmpl 0x26b4(%ecx), %ebx\n" /* tagName */
        "jl .Lf1dc734_001dc787\n"
        ".Lf1dc734_001dc7c6:\n"
        "movl 0xd8(%ecx), %ebx\n" /* line 329 | tagName */
        "movl %ebx, %eax\n" /* line 330 | tagName */
        "shll $4, %eax\n"
        "addl %ebx, %eax\n" /* tagName */
        "leal (%ebx, %eax, 8), %eax\n" /* tagName */
        "movl (%edi), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "cmpb $0, 0x1e0(%eax)\n"
        "je .Lf1dc734_001dc7f3\n"
        "movb $0, 0x1e0(%eax)\n" /* line 332 */
        "movb $1, -0x418(%ebp, %ebx)\n" /* line 333 */
        ".Lf1dc734_001dc7f3:\n"
        "movl (%esi), %eax\n" /* line 337 | entnum */
        "movl 8(%ebp), %edx\n" /* snap */
        "movl %edx, 0x24(%eax)\n"
        "testl %edx, %edx\n" /* line 339 */
        "je .Lf1dc734_001dcdf8\n"
        "movl $0, (%esp)\n" /* line 347 */
        "calll CL_ResetSkeletonCache\n"
        "calll CG_SetFrameInterpolation\n" /* line 349 */
        "movl 8(%ebp), %ecx\n" /* line 351 | snap */
        "movl 0x12dbc(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_ExecuteNewServerCommands\n"
        "calll CG_CheckOpenWaitingScriptMenu\n" /* line 355 */
        "movl 8(%ebp), %eax\n" /* line 361 | snap */
        "movl 0x26b8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf1dc734_001dca2c\n"
        "movl %eax, %edx\n"
        ".Lf1dc734_001dc83d:\n"
        "movl 0x195f584, %eax\n" /* line 412 */
        "movl (%eax), %ebx\n" /* tagName */
        "movl 0x144(%edx), %eax\n"
        "movl %eax, 0x2bddc(%ebx)\n" /* tagName */
        "movl 0x148(%edx), %eax\n" /* line 413 */
        "movl %eax, 0x2bde0(%ebx)\n" /* tagName */
        "movl 0xd8(%edx), %esi\n" /* line 415 | entnum */
        "testl $0xc00000, 0x18(%edx)\n" /* line 417 */
        "jne .Lf1dc734_001dcd3a\n"
        "movl 0x25bbc(%ebx), %ecx\n" /* line 439 | tagName */
        "testl %ecx, %ecx\n"
        "jne .Lf1dc734_001dcf1e\n"
        "movl 0x20(%ebx), %edx\n" /* tagName */
        "movl 8(%ebp), %ecx\n" /* snap */
        "movl 0x14c(%ecx), %eax\n"
        "cmpl 0x14c(%edx), %eax\n"
        "je .Lf1dc734_001dcf52\n"
        "movl %ecx, %eax\n"
        ".Lf1dc734_001dc897:\n"
        "addl $0xc, %edx\n" /* line 441 */
        "addl $0xc, %eax\n"
        "movl $0x26a8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "calll CG_Respawn\n" /* line 442 */
        ".Lf1dc734_001dc8b6:\n"
        "movl 8(%ebp), %eax\n" /* line 446 | snap */
        "movl 0x26b4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1dc734_001dc952\n"
        "movl $0, -0x41c(%ebp)\n"
        "movl %eax, %edi\n"
        "addl $0x26b0, %edi\n"
        ".Lf1dc734_001dc8d9:\n"
        "leal 0xc(%edi), %edx\n" /* line 448 */
        "movl 0xc(%edi), %ebx\n" /* line 449 | tagName */
        "movl %ebx, %eax\n" /* line 450 | tagName */
        "shll $4, %eax\n"
        "addl %ebx, %eax\n" /* tagName */
        "leal (%ebx, %eax, 8), %eax\n" /* tagName */
        "leal (, %eax, 4), %esi\n" /* entnum */
        "movl 0x195f5cc, %ecx\n"
        "addl (%ecx), %esi\n" /* entnum */
        "leal 0xf0(%esi), %eax\n" /* line 451 | entnum */
        "movl $0xf0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movb $1, 0x1e0(%esi)\n" /* line 453 | entnum */
        "cmpb $0, -0x418(%ebp, %ebx)\n" /* line 457 */
        "je .Lf1dc734_001dc92d\n"
        "movl 8(%esi), %eax\n" /* entnum */
        "xorl 0x14(%edi), %eax\n"
        "testb $2, %al\n"
        "je .Lf1dc734_001dc934\n"
        ".Lf1dc734_001dc92d:\n"
        "movl %esi, %eax\n" /* line 458 | entnum */
        "calll CG_ResetEntity\n"
        ".Lf1dc734_001dc934:\n"
        "addl $1, -0x41c(%ebp)\n" /* line 446 */
        "addl $0xf0, %edi\n"
        "movl -0x41c(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* snap */
        "cmpl %edx, 0x26b4(%eax)\n"
        "jg .Lf1dc734_001dc8d9\n"
        ".Lf1dc734_001dc952:\n"
        "movl %eax, %ecx\n"
        "movl 0x26b8(%eax), %eax\n" /* line 461 */
        "testl %eax, %eax\n"
        "jg .Lf1dc734_001dccfb\n"
        "movl %ecx, %edx\n"
        ".Lf1dc734_001dc964:\n"
        "movl 0xf0(%edx), %eax\n" /* line 465 */
        "testl %eax, %eax\n"
        "jle .Lf1dc734_001dc983\n"
        "addl $0x14e, %eax\n" /* line 467 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n" /* line 469 */
        "calll CG_UpdateHandViewmodels\n"
        ".Lf1dc734_001dc983:\n"
        "calll CG_BuildSolidList\n" /* line 473 */
        "movl 0x195f584, %eax\n" /* line 183 */
        "movl (%eax), %ebx\n"
        "movl 0x2cd14(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1dc734_001dc9b4\n"
        "movl 0x24(%ebx), %eax\n"
        "movl 0x7b0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1dc734_001dcf29\n"
        ".Lf1dc734_001dc9aa:\n"
        "movl 0x2cd14(%ebx), %eax\n" /* line 194 */
        "testl %eax, %eax\n"
        "je .Lf1dc734_001dc9c5\n"
        ".Lf1dc734_001dc9b4:\n"
        "movl 0x24(%ebx), %eax\n"
        "movl 0x7b0(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf1dc734_001dce08\n"
        ".Lf1dc734_001dc9c5:\n"
        "movl 8(%ebp), %edx\n" /* line 477 | snap */
        "movl 0x26b4(%edx), %ebx\n" /* tagName */
        "testl %ebx, %ebx\n" /* tagName */
        "jg .Lf1dc734_001dccbb\n"
        ".Lf1dc734_001dc9d6:\n"
        "movl 0x195f584, %eax\n" /* line 487 */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1dc734_001dc9fe\n"
        "movl 0x24(%edx), %eax\n"
        "testb $0x40, 0x1a(%eax)\n"
        "jne .Lf1dc734_001dc9fe\n"
        "movl 0x195f788, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1dc734_001dcddd\n"
        ".Lf1dc734_001dc9fe:\n"
        "movl 0x20(%edx), %eax\n" /* line 488 */
        "addl $0xc, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%edx), %eax\n"
        "addl $0xc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_TransitionPlayerState\n"
        /* } scope */
        ".Lf1dc734_001dca16:\n"
        "addl $0x44c, %esp\n" /* line 499 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1dc734_001dca21:\n"
        "movl 0x195f5cc, %edi\n"
        "jmp .Lf1dc734_001dc7c6\n"
        /* { scope 1 */
        ".Lf1dc734_001dca2c:\n"
        "movl $0, -0x420(%ebp)\n" /* line 361 */
        "addl $0x116b0, %eax\n"
        "movl %eax, -0x43c(%ebp)\n"
        "movl %eax, %edi\n"
        "movl %eax, %edx\n"
        ".Lf1dc734_001dca45:\n"
        "addl $0xc, %edi\n" /* line 363 */
        "movl 0xc(%edx), %eax\n" /* line 368 */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "leal 0xe0900(, %edx, 8), %edx\n"
        "movl 0x195f584, %ecx\n"
        "addl (%ecx), %edx\n"
        "leal 0x14(%edx), %eax\n"
        "movl %eax, -0x430(%ebp)\n" /* ci */
        "movl 0x14(%edx), %edx\n" /* line 369 */
        "testl %edx, %edx\n"
        "je .Lf1dc734_001dcc4c\n"
        "movl 0x2c(%eax), %eax\n"
        ".Lf1dc734_001dca7e:\n"
        "movl -0x430(%ebp), %edx\n" /* ci */
        "movl %eax, 0x30(%edx)\n"
        "movl $1, (%edx)\n" /* line 370 */
        "movl $1, 4(%edx)\n" /* line 371 */
        "movl -0x43c(%ebp), %ecx\n" /* line 372 */
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0x10(%ecx), %eax\n" /* line 373 */
        "movl %eax, 0x2c(%edx)\n"
        "leal 0x3c(%edi), %esi\n" /* line 380 | entnum */
        "movl %edx, %ebx\n" /* tagName */
        "addl $0xc, %ebx\n" /* tagName */
        "movl %esi, 4(%esp)\n" /* entnum */
        "movl %ebx, (%esp)\n" /* tagName */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1dc734_001dcae2\n"
        "movl -0x430(%ebp), %eax\n" /* line 382 | ci */
        "cmpb $0, 0xc(%eax)\n"
        "jne .Lf1dc734_001dcc83\n"
        ".Lf1dc734_001dcace:\n"
        "movl $0x20, 8(%esp)\n" /* line 384 */
        "movl %esi, 4(%esp)\n" /* entnum */
        "movl %ebx, (%esp)\n" /* tagName */
        "calll I_strncpyz\n"
        ".Lf1dc734_001dcae2:\n"
        "movl -0x43c(%ebp), %edx\n" /* line 387 */
        "movl 0x14(%edx), %eax\n"
        "addl $0x14e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n" /* tagName */
        "movl -0x430(%ebp), %esi\n" /* line 388 | ci, entnum */
        "addl $0x40, %esi\n" /* entnum */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* entnum */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1dc734_001dcc5a\n"
        ".Lf1dc734_001dcb17:\n"
        "movl %edi, %esi\n" /* line 391 | entnum */
        "movl $0, -0x42c(%ebp)\n" /* i */
        "movl -0x430(%ebp), %eax\n" /* ci */
        "addl $0x200, %eax\n"
        "movl %eax, -0x438(%ebp)\n"
        "movl -0x430(%ebp), %edi\n" /* ci */
        "subl $-0x80, %edi\n"
        "jmp .Lf1dc734_001dcb86\n"
        ".Lf1dc734_001dcb3f:\n"
        "movl 0x24(%esi), %eax\n" /* line 403 | entnum */
        "addl $0x6e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n" /* tagName */
        "movl %eax, 4(%esp)\n" /* line 404 */
        "movl -0x438(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1dc734_001dcbd1\n"
        "addl $1, -0x42c(%ebp)\n" /* line 394 | i */
        "addl $0x40, %edi\n"
        "addl $0x40, -0x438(%ebp)\n"
        "addl $4, %esi\n" /* entnum */
        "cmpl $6, -0x42c(%ebp)\n" /* i */
        "je .Lf1dc734_001dcc1c\n"
        ".Lf1dc734_001dcb86:\n"
        "movl 0xc(%esi), %eax\n" /* line 396 | entnum */
        "addl $0x14e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n" /* tagName */
        "movl %eax, 4(%esp)\n" /* line 397 */
        "movl %edi, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1dc734_001dcb3f\n"
        "movl $0x40, 8(%esp)\n" /* line 399 */
        "movl %ebx, 4(%esp)\n" /* tagName */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x430(%ebp), %edx\n" /* line 400 | ci */
        "movl $1, 0x3f8(%edx)\n"
        "jmp .Lf1dc734_001dcb3f\n"
        ".Lf1dc734_001dcbd1:\n"
        "movl $0x40, 8(%esp)\n" /* line 406 */
        "movl %ebx, 4(%esp)\n" /* tagName */
        "movl -0x438(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x430(%ebp), %edx\n" /* line 407 | ci */
        "movl $1, 0x3f8(%edx)\n"
        "addl $1, -0x42c(%ebp)\n" /* line 394 | i */
        "addl $0x40, %edi\n"
        "addl $0x40, -0x438(%ebp)\n"
        "addl $4, %esi\n" /* entnum */
        "cmpl $6, -0x42c(%ebp)\n" /* i */
        "jne .Lf1dc734_001dcb86\n"
        ".Lf1dc734_001dcc1c:\n"
        "addl $1, -0x420(%ebp)\n" /* line 361 */
        "addl $0x5c, -0x43c(%ebp)\n"
        "movl -0x420(%ebp), %eax\n"
        "movl 8(%ebp), %ecx\n" /* snap */
        "cmpl %eax, 0x26b8(%ecx)\n"
        "jle .Lf1dc734_001dccb4\n"
        "movl -0x43c(%ebp), %edi\n"
        "movl -0x43c(%ebp), %edx\n"
        "jmp .Lf1dc734_001dca45\n"
        ".Lf1dc734_001dcc4c:\n"
        "movl -0x43c(%ebp), %ecx\n" /* line 369 */
        "movl 0x10(%ecx), %eax\n"
        "jmp .Lf1dc734_001dca7e\n"
        ".Lf1dc734_001dcc5a:\n"
        "movl $0x40, 8(%esp)\n" /* line 390 */
        "movl %ebx, 4(%esp)\n" /* tagName */
        "movl %esi, (%esp)\n" /* entnum */
        "calll I_strncpyz\n"
        "movl -0x430(%ebp), %ecx\n" /* line 391 | ci */
        "movl $1, 0x3f8(%ecx)\n"
        "jmp .Lf1dc734_001dcb17\n"
        ".Lf1dc734_001dcc83:\n"
        "movl $0x2b7f74, (%esp)\n" /* line 383 */
        "calll UI_SafeTranslateString\n"
        "movl %esi, 0xc(%esp)\n" /* entnum */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* tagName */
        "movl $0x2b7f88, (%esp)\n" /* "%s^7 %s %s" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll CG_GameMessage\n"
        "jmp .Lf1dc734_001dcace\n"
        ".Lf1dc734_001dccb4:\n"
        "movl %ecx, %edx\n"
        "jmp .Lf1dc734_001dc83d\n"
        ".Lf1dc734_001dccbb:\n"
        "movl %edx, %ebx\n" /* line 477 | tagName */
        "xorl %esi, %esi\n" /* entnum */
        "movl 0x195f5cc, %edi\n"
        ".Lf1dc734_001dccc5:\n"
        "movl 0x26bc(%ebx), %edx\n" /* line 480 | tagName */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "addl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_CheckEvents\n"
        "addl $1, %esi\n" /* line 477 | entnum */
        "addl $0xf0, %ebx\n" /* tagName */
        "movl 8(%ebp), %ecx\n" /* snap */
        "cmpl 0x26b4(%ecx), %esi\n" /* entnum */
        "jl .Lf1dc734_001dccc5\n"
        "jmp .Lf1dc734_001dc9d6\n"
        ".Lf1dc734_001dccfb:\n"
        "movl %ecx, %ebx\n" /* line 461 | tagName */
        "xorl %esi, %esi\n" /* entnum */
        "movl 0x195f5cc, %edi\n"
        ".Lf1dc734_001dcd05:\n"
        "movl 0x116bc(%ebx), %edx\n" /* line 462 | tagName */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "addl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_UpdatePlayerDObj\n"
        "addl $1, %esi\n" /* line 461 | entnum */
        "addl $0x5c, %ebx\n" /* tagName */
        "movl 8(%ebp), %eax\n" /* snap */
        "cmpl 0x26b8(%eax), %esi\n" /* entnum */
        "jl .Lf1dc734_001dcd05\n"
        "movl %eax, %edx\n"
        "jmp .Lf1dc734_001dc964\n"
        ".Lf1dc734_001dcd3a:\n"
        "movl %esi, %eax\n" /* line 419 | entnum */
        "shll $4, %eax\n"
        "addl %esi, %eax\n" /* entnum */
        "leal (%esi, %eax, 8), %eax\n" /* entnum */
        "movl 0x195f5cc, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n"
        "movzwl %si, %eax\n" /* line 420 | entnum */
        "movl %eax, 0xf0(%edi)\n"
        "movl $0, 0xc(%esp)\n" /* line 421 */
        "movl $0, 8(%esp)\n"
        "leal 0xf0(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* snap */
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x434(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "calll BG_PlayerStateToEntityState\n"
        "movb $1, 0x1e0(%edi)\n" /* line 422 */
        "movl 0x25bbc(%ebx), %eax\n" /* line 424 | tagName */
        "testl %eax, %eax\n"
        "jne .Lf1dc734_001dcdf3\n"
        "movl 0x20(%ebx), %edx\n" /* tagName */
        "movl 8(%ebp), %ecx\n" /* snap */
        "movl 0x14c(%ecx), %eax\n"
        "cmpl 0x14c(%edx), %eax\n"
        "je .Lf1dc734_001dcf66\n"
        ".Lf1dc734_001dcdaf:\n"
        "leal 0xc(%edx), %eax\n" /* line 426 */
        "movl $0x26a8, 8(%esp)\n"
        "movl -0x434(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl %edi, %eax\n" /* line 427 */
        "calll CG_ResetEntity\n"
        "calll CG_Respawn\n" /* line 428 */
        "jmp .Lf1dc734_001dc8b6\n"
        ".Lf1dc734_001dcddd:\n"
        "movl 0x195f78c, %eax\n" /* line 487 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1dc734_001dc9fe\n"
        "jmp .Lf1dc734_001dca16\n"
        ".Lf1dc734_001dcdf3:\n"
        "movl 0x20(%ebx), %edx\n" /* tagName */
        "jmp .Lf1dc734_001dcdaf\n"
        ".Lf1dc734_001dcdf8:\n"
        "calll CG_ClearSolidList\n" /* line 341 */
        /* } scope */
        "addl $0x44c, %esp\n" /* line 499 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1dc734_001dce08:\n"
        "movl $0, 0x2cd14(%ebx)\n" /* line 197 */
        "movl 0x195f584, %eax\n" /* line 200 */
        "movl (%eax), %ebx\n"
        "movl 0x25bb0(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_PlaySmokeGrenadesAtTime\n"
        "movl 0x24(%ebx), %eax\n" /* line 202 */
        "movl 0x26b4(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf1dc734_001dc9c5\n"
        "xorl %ebx, %ebx\n"
        "xorl %esi, %esi\n"
        "jmp .Lf1dc734_001dce5d\n"
        ".Lf1dc734_001dce3e:\n"
        "addl $1, %ebx\n"
        "addl $0xf0, %esi\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "cmpl 0x26b4(%eax), %ebx\n"
        "jge .Lf1dc734_001dc9c5\n"
        ".Lf1dc734_001dce5d:\n"
        "movl 0x26bc(%esi, %eax), %eax\n" /* line 204 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %eax, %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "movl 0x195f5cc, %eax\n"
        "addl (%eax), %edx\n"
        "cmpl $2, 0xf4(%edx)\n" /* line 206 */
        "jne .Lf1dc734_001dce3e\n"
        "movl 0xf0(%edx), %edx\n" /* line 211 */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0x195f5c4, %ecx\n"
        "movl (%ecx), %edx\n"
        "leal -0x6bec(%edx, %eax, 8), %eax\n"
        "movl 0x4a4(%eax), %edx\n" /* line 212 */
        "movl %edx, -0x424(%ebp)\n"
        "movl 0x390(%eax), %edi\n" /* line 214 */
        "andl $0xfffffdff, %edi\n"
        "movl %edx, (%esp)\n" /* line 215 */
        "calll XAnimGetAnims\n"
        "movl %eax, -0x428(%ebp)\n"
        "testl %edi, %edi\n" /* line 216 */
        "je .Lf1dc734_001dce3e\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll XAnimIsLooped\n"
        "testb %al, %al\n"
        "jne .Lf1dc734_001dce3e\n"
        "movl %edi, 4(%esp)\n"
        "movl -0x428(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll XAnimGetNumChildren\n"
        "testl %eax, %eax\n"
        "jne .Lf1dc734_001dce3e\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 218 */
        "movl %edi, 4(%esp)\n"
        "movl -0x424(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XAnimSetTime\n"
        "jmp .Lf1dc734_001dce3e\n"
        ".Lf1dc734_001dcf1e:\n"
        "movl 0x20(%ebx), %edx\n"
        "movl 8(%ebp), %eax\n" /* snap */
        "jmp .Lf1dc734_001dc897\n"
        ".Lf1dc734_001dcf29:\n"
        "movl $1, 0x2cd14(%ebx)\n" /* line 185 */
        "movl $0, (%esp)\n" /* line 188 */
        "calll CG_SetEquippedOffHand\n"
        "movl 0x25bb0(%ebx), %eax\n" /* line 191 */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySmokeGrenadesAtTime\n"
        "jmp .Lf1dc734_001dc9aa\n"
        ".Lf1dc734_001dcf52:\n"
        "cmpl 0xd8(%edx), %esi\n" /* line 439 | entnum */
        "je .Lf1dc734_001dc8b6\n"
        "movl 8(%ebp), %eax\n" /* snap */
        "jmp .Lf1dc734_001dc897\n"
        ".Lf1dc734_001dcf66:\n"
        "cmpl 0xd8(%edx), %esi\n" /* line 424 | entnum */
        "jne .Lf1dc734_001dcdaf\n"
        "cmpb $0, -0x418(%ebp, %esi)\n" /* line 430 */
        "je .Lf1dc734_001dcf8d\n"
        "movl 8(%edi), %eax\n"
        "xorl 0xf8(%edi), %eax\n"
        "testb $2, %al\n"
        "je .Lf1dc734_001dc8b6\n"
        ".Lf1dc734_001dcf8d:\n"
        "leal 0xc(%edx), %eax\n" /* line 432 */
        "movl $0x26a8, 8(%esp)\n"
        "movl -0x434(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl %edi, %eax\n" /* line 433 */
        "calll CG_ResetEntity\n"
        "leal 0x284c4(%ebx), %edx\n" /* line 434 | tagName, v */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, 0x284c4(%ebx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "jmp .Lf1dc734_001dc8b6\n"
    );
}

/* line 129 */
__attribute__((naked))
void CG_SetInitialSnapshot(snapshot_t *snap)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 129 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* snap */
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 137 */
        "calll CG_SetNextSnap\n"
        "movl 0x195f584, %eax\n" /* line 141 */
        "movl (%eax), %esi\n"
        "movl %ebx, 0x20(%esi)\n" /* snap */
        "movl %ebx, 0x24(%esi)\n" /* line 142 | snap */
        "movl 8(%ebx), %eax\n" /* line 144 | snap */
        "movl %eax, 0x25bb0(%esi)\n"
        "movl %eax, 0xe08f4(%esi)\n" /* line 145 */
        "movl %eax, 0x25bb4(%esi)\n" /* line 146 */
        "leal 0x20(%ebx), %edx\n" /* snap */
        /* { scope 2 */
        "movl 0x20(%ebx), %eax\n" /* line 199 | snap */
        "movl %eax, -0x24(%ebp)\n" /* clientViewOrigin */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 201 */
        /* } scope */
        "addss 0x104(%ebx), %xmm0\n" /* line 149 | snap */
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x48(%ebp), %edi\n" /* line 151 | clientViewAxis */
        "movl %edi, 4(%esp)\n"
        "leal 0xf4(%ebx), %eax\n" /* snap */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl %edi, 8(%esp)\n" /* line 152 */
        "leal -0x24(%ebp), %eax\n" /* clientViewOrigin */
        "movl %eax, 4(%esp)\n"
        "movl 0xd8(%ebx), %eax\n" /* snap */
        "movl %eax, (%esp)\n"
        "calll SND_SetListener\n"
        "movl $0, 4(%esp)\n" /* line 159 */
        "movl $0x3f800000, (%esp)\n"
        "calll SND_FadeAllSounds\n"
        "calll CG_Respawn\n" /* line 161 */
        "movl 0x25bb0(%esi), %eax\n" /* line 164 */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySmokeGrenadesAtTime\n"
        "calll CG_InitView\n" /* line 166 */
        "movl $0, 0x24(%esi)\n" /* line 168 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 169 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 581 */
__attribute__((naked))
void CG_ProcessSnapshots(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 581 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 587 */
        "movl (%eax), %ebx\n" /* snap */
        "leal 0x1c(%ebx), %eax\n" /* snap */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* n */
        "movl %eax, (%esp)\n"
        "calll CL_GetCurrentSnapshotNumber\n"
        "movl -0x1c(%ebp), %eax\n" /* line 588 | n */
        "cmpl %eax, 0x18(%ebx)\n" /* snap */
        "je .Lf1dd08e_001dd0c1\n"
        "jg .Lf1dd08e_001dd16e\n" /* line 590 */
        ".Lf1dd08e_001dd0be:\n"
        "movl %eax, 0x18(%ebx)\n" /* line 595 | snap */
        ".Lf1dd08e_001dd0c1:\n"
        "movl 0x195f584, %eax\n" /* line 598 */
        "movl %eax, -0x38(%ebp)\n"
        "movl (%eax), %edx\n"
        "movl 0x1c(%edx), %eax\n"
        "movl %eax, 0xe08f8(%edx)\n"
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl %edx, %eax\n"
        ".Lf1dd08e_001dd0df:\n"
        "movl (%eax), %edi\n" /* line 603 */
        "movl 0x20(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1dd08e_001dd34e\n"
        "movl 0x18(%edi), %ecx\n" /* line 517 */
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %ebx\n"
        "movl 0x5e9c(%ebx), %edx\n"
        "leal 0x3e8(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jg .Lf1dd08e_001dd1a8\n"
        ".Lf1dd08e_001dd10a:\n"
        "movl %ebx, %esi\n" /* line 522 */
        "movl %edx, %ecx\n"
        "movl %edi, %edx\n"
        "cmpl 0x18(%edi), %ecx\n"
        "jge .Lf1dd08e_001dd166\n"
        ".Lf1dd08e_001dd115:\n"
        "leal 0x28(%edx), %ebx\n" /* line 525 */
        "leal 0x12de8(%edx), %eax\n" /* line 527 */
        "cmpl %ebx, 0x20(%edx)\n"
        "cmovel %eax, %ebx\n"
        "leal 1(%ecx), %eax\n" /* line 535 */
        "movl %eax, 0x5e9c(%esi)\n"
        "movl %ebx, 4(%esp)\n" /* line 536 */
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %esi\n"
        "movl 0x5e9c(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetSnapshot\n"
        "testl %eax, %eax\n" /* line 539 */
        "jne .Lf1dd08e_001dd18a\n"
        "movl $0, (%esp)\n" /* line 551 */
        "calll CG_AddLagometerSnapshotInfo\n"
        "movl 0x5e9c(%esi), %ecx\n" /* line 522 */
        "movl -0x48(%ebp), %eax\n"
        "movl (%eax), %edx\n"
        "cmpl 0x18(%edx), %ecx\n"
        "jl .Lf1dd08e_001dd115\n"
        /* } scope */
        ".Lf1dd08e_001dd166:\n"
        "addl $0x5c, %esp\n" /* line 686 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1dd08e_001dd16e:\n"
        "movl $0x2b7f94, 4(%esp)\n" /* line 593 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x1c(%ebp), %eax\n" /* n */
        "jmp .Lf1dd08e_001dd0be\n"
        ".Lf1dd08e_001dd18a:\n"
        "movl %ebx, (%esp)\n" /* line 541 */
        "calll CG_AddLagometerSnapshotInfo\n"
        "testl %ebx, %ebx\n" /* line 606 | snap */
        "je .Lf1dd08e_001dd166\n"
        "testb $2, (%ebx)\n" /* line 614 | snap */
        "je .Lf1dd08e_001dd1c7\n"
        "movl 0x195f584, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "jmp .Lf1dd08e_001dd0df\n"
        ".Lf1dd08e_001dd1a8:\n"
        "movl %edx, 8(%esp)\n" /* line 519 */
        "movl %ecx, 4(%esp)\n"
        "movl $0x2b7fc4, (%esp)\n" /* "WARNING: CG_ReadNextSnapshot: way out of range, %i > %i
" */
        "calll Com_Printf\n"
        "movl 0x5e9c(%ebx), %edx\n"
        "jmp .Lf1dd08e_001dd10a\n"
        ".Lf1dd08e_001dd1c7:\n"
        "movl %ebx, (%esp)\n" /* line 616 | snap */
        "calll CG_SetInitialSnapshot\n"
        "movl %ebx, (%esp)\n" /* line 617 | snap */
        "calll CG_SetNextSnap\n"
        "movl 0x195f584, %edx\n" /* line 244 */
        "movl %edx, -0x38(%ebp)\n"
        "movl (%edx), %ebx\n"
        "movl 0x20(%ebx), %eax\n"
        "movl 0x26b8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf1dd08e_001dd282\n"
        "movl $0, -0x30(%ebp)\n"
        "movl $0x116b0, -0x44(%ebp)\n"
        "jmp .Lf1dd08e_001dd225\n"
        ".Lf1dd08e_001dd203:\n"
        "movl $0, 4(%esi)\n" /* line 250 */
        "movl -0x38(%ebp), %edx\n"
        ".Lf1dd08e_001dd20d:\n"
        "addl $1, -0x30(%ebp)\n" /* line 244 */
        "addl $0x5c, -0x44(%ebp)\n"
        "movl (%edx), %ebx\n"
        "movl 0x20(%ebx), %eax\n"
        "movl -0x30(%ebp), %edx\n"
        "cmpl 0x26b8(%eax), %edx\n"
        "jge .Lf1dd08e_001dd282\n"
        ".Lf1dd08e_001dd225:\n"
        "movl -0x44(%ebp), %edx\n" /* line 246 */
        "leal (%eax, %edx), %edi\n"
        "movl 0xc(%edi), %eax\n" /* line 247 */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "leal 0xe0914(%ebx, %edx, 8), %esi\n"
        "movl 4(%esi), %ecx\n" /* line 248 */
        "testl %ecx, %ecx\n"
        "jne .Lf1dd08e_001dd203\n"
        "movl 0x4a4(%esi), %ebx\n" /* line 253 */
        "movl $0x4b8, 8(%esp)\n" /* line 254 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memset\n"
        "movl %ebx, 0x4a4(%esi)\n" /* line 255 */
        "movl 0xc(%edi), %eax\n" /* line 256 */
        "movl %eax, (%esp)\n"
        "calll CG_SafeDObjFree\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf1dd08e_001dd20d\n"
        ".Lf1dd08e_001dd282:\n"
        "movl 0x24(%ebx), %eax\n" /* line 271 */
        "movl %eax, 0x20(%ebx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 273 */
        "movl (%eax), %ebx\n"
        "movl 0x24(%ebx), %eax\n"
        "testl $0xc00000, 0x18(%eax)\n"
        "je .Lf1dd08e_001dd2d1\n"
        "movl 0xd8(%eax), %edx\n" /* line 275 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 0x195f5cc, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0xf0(%eax), %edx\n" /* line 276 */
        "movl $0xf0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x24(%ebx), %eax\n"
        ".Lf1dd08e_001dd2d1:\n"
        "movl 0x26b4(%eax), %edx\n" /* line 279 */
        "testl %edx, %edx\n"
        "jle .Lf1dd08e_001dd33e\n"
        "xorl %esi, %esi\n"
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "xorl %ebx, %ebx\n"
        ".Lf1dd08e_001dd2e8:\n"
        "movl 0x26bc(%ebx, %eax), %edx\n" /* line 281 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "movl 0x195f5cc, %edx\n"
        "addl (%edx), %eax\n"
        "leal 0xf0(%eax), %edx\n" /* line 283 */
        "movl $0xf0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %esi\n" /* line 279 */
        "addl $0xf0, %ebx\n"
        "movl -0x38(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "cmpl 0x26b4(%eax), %esi\n"
        "jl .Lf1dd08e_001dd2e8\n"
        "movl %edx, %eax\n"
        "jmp .Lf1dd08e_001dd0df\n"
        ".Lf1dd08e_001dd33e:\n"
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf1dd08e_001dd0df\n"
        ".Lf1dd08e_001dd34e:\n"
        "calll CG_SetFrameInterpolation\n" /* line 633 */
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl %edx, %eax\n"
        ".Lf1dd08e_001dd35e:\n"
        "movl (%eax), %ebx\n" /* line 641 | snap */
        "movl 0x24(%ebx), %eax\n" /* snap */
        "cmpl 0x20(%ebx), %eax\n" /* snap */
        "je .Lf1dd08e_001dd373\n"
        "movl 0xc(%ebx), %edi\n" /* snap */
        "testl %edi, %edi\n"
        "je .Lf1dd08e_001dd41d\n"
        ".Lf1dd08e_001dd373:\n"
        "movl 0x18(%ebx), %ecx\n" /* line 517 */
        "movl 0x195f5c4, %edi\n"
        "movl (%edi), %esi\n"
        "movl 0x5e9c(%esi), %edx\n"
        "leal 0x3e8(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jg .Lf1dd08e_001dd5e9\n"
        ".Lf1dd08e_001dd392:\n"
        "movl %edx, %ecx\n" /* line 522 */
        "movl %ebx, %edx\n"
        "cmpl %ecx, 0x18(%ebx)\n"
        "jle .Lf1dd08e_001dd789\n"
        ".Lf1dd08e_001dd39f:\n"
        "leal 0x28(%edx), %ebx\n" /* line 525 */
        "leal 0x12de8(%edx), %eax\n" /* line 527 */
        "cmpl %ebx, 0x20(%edx)\n"
        "cmovel %eax, %ebx\n"
        "leal 1(%ecx), %eax\n" /* line 535 */
        "movl %eax, 0x5e9c(%esi)\n"
        "movl %ebx, 4(%esp)\n" /* line 536 */
        "movl (%edi), %esi\n"
        "movl 0x5e9c(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetSnapshot\n"
        "testl %eax, %eax\n" /* line 539 */
        "jne .Lf1dd08e_001dd5a2\n"
        "movl $0, (%esp)\n" /* line 551 */
        "calll CG_AddLagometerSnapshotInfo\n"
        "movl 0x5e9c(%esi), %ecx\n" /* line 522 */
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl (%edx), %edx\n"
        "cmpl %ecx, 0x18(%edx)\n"
        "jg .Lf1dd08e_001dd39f\n"
        "movl -0x38(%ebp), %eax\n"
        ".Lf1dd08e_001dd3f8:\n"
        "movl (%eax), %edx\n" /* line 678 */
        "movl 0x20(%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpl %eax, 0x25bb0(%edx)\n"
        "jns .Lf1dd08e_001dd166\n"
        "movl %eax, 0x25bb0(%edx)\n" /* line 681 */
        "movl %eax, 0xe08f4(%edx)\n" /* line 682 */
        "jmp .Lf1dd08e_001dd166\n"
        ".Lf1dd08e_001dd41d:\n"
        "movl -0x38(%ebp), %eax\n"
        ".Lf1dd08e_001dd420:\n"
        "movl (%eax), %ebx\n" /* line 668 | snap */
        "movl 0x25bb0(%ebx), %ecx\n" /* snap */
        "movl 0x20(%ebx), %edx\n" /* snap */
        "cmpl 8(%edx), %ecx\n"
        "js .Lf1dd08e_001dd43c\n"
        "movl 0x24(%ebx), %eax\n" /* snap */
        "cmpl 8(%eax), %ecx\n"
        "js .Lf1dd08e_001dd166\n"
        ".Lf1dd08e_001dd43c:\n"
        "movl 0x26b8(%edx), %esi\n" /* line 244 */
        "testl %esi, %esi\n"
        "jle .Lf1dd08e_001dd4d6\n"
        "xorl %edi, %edi\n"
        "jmp .Lf1dd08e_001dd468\n"
        ".Lf1dd08e_001dd44e:\n"
        "movl $0, 4(%esi)\n" /* line 250 */
        "movl -0x38(%ebp), %edx\n"
        ".Lf1dd08e_001dd458:\n"
        "addl $1, %edi\n" /* line 244 */
        "movl (%edx), %ebx\n"
        "movl 0x20(%ebx), %edx\n"
        "cmpl 0x26b8(%edx), %edi\n"
        "jge .Lf1dd08e_001dd4d6\n"
        ".Lf1dd08e_001dd468:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 246 */
        "shll $3, %eax\n"
        "subl %edi, %eax\n"
        "leal 0x116b0(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 0xc(%eax), %edx\n" /* line 247 */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0914(%ebx, %eax, 8), %esi\n"
        "movl 4(%esi), %eax\n" /* line 248 */
        "testl %eax, %eax\n"
        "jne .Lf1dd08e_001dd44e\n"
        "movl 0x4a4(%esi), %ebx\n" /* line 253 */
        "movl $0x4b8, 8(%esp)\n" /* line 254 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memset\n"
        "movl %ebx, 0x4a4(%esi)\n" /* line 255 */
        "movl -0x34(%ebp), %edx\n" /* line 256 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_SafeDObjFree\n"
        "movl 0x195f584, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf1dd08e_001dd458\n"
        ".Lf1dd08e_001dd4d6:\n"
        "movl 0x24(%ebx), %eax\n" /* line 271 */
        "movl %eax, 0x20(%ebx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 273 */
        "movl (%eax), %ebx\n"
        "movl 0x24(%ebx), %eax\n"
        "testl $0xc00000, 0x18(%eax)\n"
        "je .Lf1dd08e_001dd525\n"
        "movl 0xd8(%eax), %edx\n" /* line 275 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 0x195f5cc, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0xf0(%eax), %edx\n" /* line 276 */
        "movl $0xf0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x24(%ebx), %eax\n"
        ".Lf1dd08e_001dd525:\n"
        "movl 0x26b4(%eax), %edi\n" /* line 279 */
        "testl %edi, %edi\n"
        "jle .Lf1dd08e_001dd592\n"
        "xorl %esi, %esi\n"
        "movl 0x195f5cc, %edi\n"
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "xorl %ebx, %ebx\n"
        ".Lf1dd08e_001dd542:\n"
        "movl 0x26bc(%ebx, %eax), %edx\n" /* line 281 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "addl (%edi), %eax\n"
        "leal 0xf0(%eax), %edx\n" /* line 283 */
        "movl $0xf0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %esi\n" /* line 279 */
        "addl $0xf0, %ebx\n"
        "movl -0x38(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "cmpl 0x26b4(%eax), %esi\n"
        "jl .Lf1dd08e_001dd542\n"
        "movl %edx, %eax\n"
        "jmp .Lf1dd08e_001dd35e\n"
        ".Lf1dd08e_001dd592:\n"
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf1dd08e_001dd35e\n"
        ".Lf1dd08e_001dd5a2:\n"
        "movl %ebx, (%esp)\n" /* line 541 */
        "calll CG_AddLagometerSnapshotInfo\n"
        "testl %ebx, %ebx\n" /* line 647 | snap */
        "je .Lf1dd08e_001dd7af\n"
        "movl 0x195f584, %edi\n" /* line 653 */
        "movl (%edi), %esi\n"
        "movl 0x24(%esi), %edx\n"
        "movl (%ebx), %eax\n" /* snap */
        "xorl (%edx), %eax\n"
        "testb $4, %al\n"
        "jne .Lf1dd08e_001dd608\n"
        "movl 8(%edx), %eax\n" /* line 661 */
        "cmpl %eax, 8(%ebx)\n" /* snap */
        "js .Lf1dd08e_001dd796\n"
        ".Lf1dd08e_001dd5d1:\n"
        "movl %ebx, (%esp)\n" /* line 664 | snap */
        "calll CG_SetNextSnap\n"
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf1dd08e_001dd420\n"
        ".Lf1dd08e_001dd5e9:\n"
        "movl %edx, 8(%esp)\n" /* line 519 */
        "movl %ecx, 4(%esp)\n"
        "movl $0x2b7fc4, (%esp)\n" /* "WARNING: CG_ReadNextSnapshot: way out of range, %i > %i
" */
        "calll Com_Printf\n"
        "movl 0x5e9c(%esi), %edx\n"
        "jmp .Lf1dd08e_001dd392\n"
        ".Lf1dd08e_001dd608:\n"
        "movl %ebx, (%esp)\n" /* line 655 | snap */
        "calll CG_SetInitialSnapshot\n"
        "movl %ebx, (%esp)\n" /* line 656 | snap */
        "calll CG_SetNextSnap\n"
        "movl %esi, %ebx\n" /* line 244 */
        "movl 0x20(%esi), %eax\n"
        "movl 0x26b8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf1dd08e_001dd6b8\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl %edi, -0x3c(%ebp)\n"
        "movl $0x116b0, -0x40(%ebp)\n"
        "jmp .Lf1dd08e_001dd663\n"
        ".Lf1dd08e_001dd63e:\n"
        "movl $0, 4(%esi)\n" /* line 250 */
        ".Lf1dd08e_001dd645:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 244 */
        "addl $0x5c, -0x40(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl (%eax), %ebx\n"
        "movl 0x20(%ebx), %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "cmpl 0x26b8(%eax), %edx\n"
        "jge .Lf1dd08e_001dd6c0\n"
        ".Lf1dd08e_001dd663:\n"
        "movl -0x40(%ebp), %edx\n" /* line 246 */
        "leal (%eax, %edx), %edi\n"
        "movl 0xc(%edi), %eax\n" /* line 247 */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "leal 0xe0914(%ebx, %edx, 8), %esi\n"
        "movl 4(%esi), %ecx\n" /* line 248 */
        "testl %ecx, %ecx\n"
        "jne .Lf1dd08e_001dd63e\n"
        "movl 0x4a4(%esi), %ebx\n" /* line 253 */
        "movl $0x4b8, 8(%esp)\n" /* line 254 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memset\n"
        "movl %ebx, 0x4a4(%esi)\n" /* line 255 */
        "movl 0xc(%edi), %eax\n" /* line 256 */
        "movl %eax, (%esp)\n"
        "calll CG_SafeDObjFree\n"
        "jmp .Lf1dd08e_001dd645\n"
        ".Lf1dd08e_001dd6b8:\n"
        "movl 0x195f584, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        ".Lf1dd08e_001dd6c0:\n"
        "movl 0x24(%ebx), %eax\n" /* line 271 */
        "movl %eax, 0x20(%ebx)\n"
        "movl -0x38(%ebp), %edx\n" /* line 273 */
        "movl (%edx), %ebx\n"
        "movl 0x24(%ebx), %eax\n"
        "testl $0xc00000, 0x18(%eax)\n"
        "je .Lf1dd08e_001dd70f\n"
        "movl 0xd8(%eax), %edx\n" /* line 275 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 0x195f5cc, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0xf0(%eax), %edx\n" /* line 276 */
        "movl $0xf0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x24(%ebx), %eax\n"
        ".Lf1dd08e_001dd70f:\n"
        "movl 0x26b4(%eax), %edx\n" /* line 279 */
        "testl %edx, %edx\n"
        "jle .Lf1dd08e_001dd77c\n"
        "xorl %ebx, %ebx\n"
        "movl 0x195f5cc, %edi\n"
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "xorl %esi, %esi\n"
        ".Lf1dd08e_001dd72c:\n"
        "movl 0x26bc(%esi, %eax), %edx\n" /* line 281 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "addl (%edi), %eax\n"
        "leal 0xf0(%eax), %edx\n" /* line 283 */
        "movl $0xf0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %ebx\n" /* line 279 */
        "addl $0xf0, %esi\n"
        "movl -0x38(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "cmpl 0x26b4(%eax), %ebx\n"
        "jl .Lf1dd08e_001dd72c\n"
        "movl %edx, %eax\n"
        "jmp .Lf1dd08e_001dd35e\n"
        ".Lf1dd08e_001dd77c:\n"
        "movl 0x195f584, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "jmp .Lf1dd08e_001dd35e\n"
        ".Lf1dd08e_001dd789:\n"
        "movl 0x195f584, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "jmp .Lf1dd08e_001dd3f8\n"
        ".Lf1dd08e_001dd796:\n"
        "movl $0x2b8000, 4(%esp)\n" /* line 662 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1dd08e_001dd5d1\n"
        ".Lf1dd08e_001dd7af:\n"
        "movl 0x195f584, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf1dd08e_001dd3f8\n"
    );
}

