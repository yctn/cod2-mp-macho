/* ASM dump from: scr_memorytree.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_memorytree.cpp */

#include "common_types.h"
#include "imports.h"

extern struct scrMemTreePub_t scrMemTreePub; /* 0x0 */
static struct scrMemTreeGlob_t scrMemTreeGlob; /* 0x3f6700 */

unsigned int Scr_GetStringUsage(void);
byte * MT_InitForceAlloc(void);
static unsigned int MT_AddMemoryNode(int newNode);
unsigned int MT_Init(void);
static int MT_GetSubTreeSize(void);
unsigned int MT_DumpTree(void);
short unsigned int MT_AllocIndex(int numBytes, int type);
unsigned int * MT_Alloc(int numBytes, int type);
unsigned int MT_ForceAllocIndex(byte *allocBits, unsigned int nodeNum, int numBytes);
int MT_Realloc(int oldNumBytes, int newNumbytes);
unsigned int MT_Free(unsigned int *p, int numBytes);
unsigned int MT_FreeIndex(unsigned int nodeNum, int numBytes);
unsigned int MT_FinishForceAlloc(byte *allocBits);

/* line 218 */
__attribute__((naked))
unsigned int Scr_GetStringUsage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 218 */
        "movl %esp, %ebp\n"
        "movl 0x476a28, %eax\n"
        "popl %ebp\n" /* line 221 */
        "retl\n"
    );
}

/* line 755 */
__attribute__((naked))
byte * MT_InitForceAlloc(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 755 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, 0x476a24\n" /* line 757 */
        "movl $0, 0x476a28\n" /* line 758 */
        "movl $0x2000, (%esp)\n" /* line 765 */
        "calll Z_VirtualAllocInternal\n"
        "leave\n" /* line 766 */
        "retl\n"
    );
}

/* line 287 */
static __attribute__((naked))
unsigned int MT_AddMemoryNode(int newNode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 287 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x28, %esp\n"
        "movl %eax, -0x34(%ebp)\n"
        /* { scope 1: num */
        "leal 0x80300(%edx, %edx), %edx\n" /* line 298 | size */
        "leal scrMemTreeGlob(%edx), %eax\n" /* size */
        "movl %eax, -0x20(%ebp)\n"
        "movzwl scrMemTreeGlob(%edx), %eax\n" /* line 299 | size */
        "movzwl %ax, %edx\n" /* size */
        "movl %edx, -0x30(%ebp)\n" /* size, node */
        "testw %ax, %ax\n" /* line 301 */
        "je .Lf44942_00044a74\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl $0x10000, %ecx\n" /* line 268 */
        "subl -0x34(%ebp), %ecx\n"
        "movl %ecx, -0x10(%ebp)\n" /* num */
        "movzbl -0x10(%ebp), %esi\n" /* line 275 | num */
        "movl %esi, %eax\n"
        "movzbl %al, %ebx\n"
        "movzbl -0xf(%ebp), %edi\n" /* line 276 */
        "movzbl 0x476800(%ebx), %eax\n" /* line 278 */
        "movzbl 0x476800(%edi), %edx\n"
        "addl %edx, %eax\n"
        "movl %ecx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ebx), %ecx\n" /* line 280 */
        "movl %esi, %eax\n" /* line 281 */
        "testb %al, %al\n"
        "je .Lf44942_00044a9c\n"
        ".Lf44942_000449b1:\n"
        "movl $1, %eax\n" /* line 283 */
        "shll %cl, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* newScore */
        "movl $0, -0x28(%ebp)\n" /* nodeNum */
        "movl $0x10000, -0x24(%ebp)\n" /* level */
        "jmp .Lf44942_000449f1\n"
        /* } scope */
        /* } scope */
        ".Lf44942_000449ce:\n"
        "movl -0x30(%ebp), %edx\n" /* line 349 | node, size */
        "leal scrMemTreeGlob(, %edx, 8), %edx\n" /* size */
        "movl %edx, -0x20(%ebp)\n" /* size */
        "movl -0x24(%ebp), %ecx\n" /* line 350 | level */
        "subl %ecx, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* nodeNum */
        "movzwl (%edx), %eax\n" /* line 357 | size */
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x30(%ebp)\n" /* node */
        "testw %ax, %ax\n" /* line 307 */
        "je .Lf44942_00044a70\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf44942_000449f1:\n"
        "movl $0x10000, %ecx\n" /* line 268 */
        "subl -0x30(%ebp), %ecx\n" /* node */
        "movl %ecx, -0x10(%ebp)\n" /* num */
        "movzbl -0x10(%ebp), %esi\n" /* line 275 | num */
        "movl %esi, %edx\n"
        "movzbl %dl, %ebx\n"
        "movzbl -0xf(%ebp), %edi\n" /* line 276 */
        "movzbl 0x476800(%ebx), %eax\n" /* line 278 */
        "movzbl 0x476800(%edi), %edx\n"
        "addl %edx, %eax\n"
        "movl %ecx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ebx), %ecx\n" /* line 280 */
        "movl %esi, %eax\n" /* line 281 */
        "testb %al, %al\n"
        "jne .Lf44942_00044a33\n"
        "movzbl 0x476700(%edi), %eax\n" /* line 282 */
        "addl %eax, %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf44942_00044a33:\n"
        "movl $1, %eax\n" /* line 314 */
        "shll %cl, %eax\n"
        "leal (%edx, %eax), %eax\n" /* size */
        "cmpl %eax, -0x2c(%ebp)\n" /* newScore */
        "jg .Lf44942_00044aaa\n"
        "sarl -0x24(%ebp)\n" /* line 345 | level */
        "movl -0x28(%ebp), %eax\n" /* line 347 | nodeNum */
        "cmpl %eax, -0x34(%ebp)\n"
        "jl .Lf44942_000449ce\n"
        "movl -0x30(%ebp), %esi\n" /* line 354 | node */
        "leal 0x3f6702(, %esi, 8), %esi\n"
        "movl %esi, -0x20(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* line 355 | level */
        "addl %eax, -0x28(%ebp)\n" /* nodeNum */
        "movl %esi, %edx\n" /* size */
        "movzwl (%edx), %eax\n" /* line 357 | size */
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x30(%ebp)\n" /* node */
        "testw %ax, %ax\n" /* line 307 */
        "jne .Lf44942_000449f1\n"
        ".Lf44942_00044a70:\n"
        "movl %edx, %esi\n" /* size */
        "jmp .Lf44942_00044a77\n"
        ".Lf44942_00044a74:\n"
        "movl -0x20(%ebp), %esi\n"
        ".Lf44942_00044a77:\n"
        "movl -0x34(%ebp), %eax\n" /* line 361 */
        "movw %ax, (%esi)\n"
        "movl -0x34(%ebp), %edx\n" /* line 362 | size */
        "movw $0, scrMemTreeGlob(, %edx, 8)\n"
        "movw $0, 0x3f6702(, %edx, 8)\n" /* line 363 */
        /* } scope */
        ".Lf44942_00044a94:\n"
        "addl $0x28, %esp\n" /* line 364 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: num */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf44942_00044a9c:\n"
        "movzbl 0x476700(%edi), %eax\n" /* line 282 */
        "addl %eax, %ecx\n"
        "jmp .Lf44942_000449b1\n"
        /* } scope */
        /* } scope */
        ".Lf44942_00044aaa:\n"
        "movl -0x34(%ebp), %esi\n" /* line 321 */
        "movl -0x20(%ebp), %ecx\n"
        "movw %si, (%ecx)\n"
        "movl -0x30(%ebp), %ecx\n" /* line 322 | node */
        "movl scrMemTreeGlob(, %ecx, 8), %eax\n"
        "movl 0x3f6704(, %ecx, 8), %edx\n" /* size */
        "movl -0x34(%ebp), %esi\n"
        "movl %eax, scrMemTreeGlob(, %esi, 8)\n"
        "movl %edx, 0x3f6704(, %esi, 8)\n" /* size */
        "testl %ecx, %ecx\n" /* line 324 */
        "jne .Lf44942_00044b27\n"
        "jmp .Lf44942_00044a94\n"
        ".Lf44942_00044adb:\n"
        "movl -0x34(%ebp), %esi\n" /* line 331 */
        "leal scrMemTreeGlob(, %esi, 8), %eax\n"
        "movl -0x24(%ebp), %edx\n" /* line 332 | level, size */
        "subl %edx, %ecx\n" /* size */
        "movl %ecx, -0x28(%ebp)\n" /* nodeNum */
        ".Lf44942_00044aed:\n"
        "movzwl (%eax), %ecx\n" /* line 341 */
        "movzwl %cx, %ebx\n"
        "movl -0x30(%ebp), %edx\n" /* line 321 | node, size */
        "movw %dx, (%eax)\n" /* size */
        "movl scrMemTreeGlob(, %ebx, 8), %eax\n" /* line 322 */
        "movl 0x3f6704(, %ebx, 8), %edx\n" /* size */
        "movl -0x30(%ebp), %esi\n" /* node */
        "movl %eax, scrMemTreeGlob(, %esi, 8)\n"
        "movl %edx, 0x3f6704(, %esi, 8)\n" /* size */
        "testw %cx, %cx\n" /* line 324 */
        "je .Lf44942_00044a94\n"
        "movl %esi, -0x34(%ebp)\n" /* line 314 */
        "movl %ebx, -0x30(%ebp)\n" /* node */
        ".Lf44942_00044b27:\n"
        "sarl -0x24(%ebp)\n" /* line 327 | level */
        "movl -0x28(%ebp), %ecx\n" /* line 329 | nodeNum */
        "cmpl %ecx, -0x30(%ebp)\n" /* node */
        "jl .Lf44942_00044adb\n"
        "movl -0x34(%ebp), %ecx\n" /* line 336 */
        "leal 0x3f6702(, %ecx, 8), %eax\n"
        "movl -0x24(%ebp), %esi\n" /* line 337 | level */
        "addl %esi, -0x28(%ebp)\n" /* nodeNum */
        "jmp .Lf44942_00044aed\n"
    );
}

/* line 519 */
__attribute__((naked))
unsigned int MT_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 519 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl $0x3f6700, scrMemTreePub\n" /* line 525 */
        "xorl %eax, %eax\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl $scrMemTreeGlob, %esi\n"
        ".Lf44b44_00044b5c:\n"
        "movb %al, 0x80100(%esi)\n" /* line 240 */
        "testb %bl, %bl\n" /* line 243 */
        "jne .Lf44b44_00044bb0\n"
        ".Lf44b44_00044b66:\n"
        "movl $8, %eax\n"
        "movb %al, 0x80000(%esi)\n" /* line 245 */
        "testl %ebx, %ebx\n" /* line 249 */
        "jne .Lf44b44_00044bd4\n"
        ".Lf44b44_00044b75:\n"
        "xorl %eax, %eax\n"
        "movb %al, 0x80200(%esi)\n" /* line 254 */
        "addl $1, %ebx\n" /* line 230 */
        "addl $1, %esi\n"
        "cmpl $0x100, %ebx\n"
        "je .Lf44b44_00044bf5\n"
        ".Lf44b44_00044b8b:\n"
        "xorl %eax, %eax\n"
        "testl %ebx, %ebx\n" /* line 234 */
        "je .Lf44b44_00044b5c\n"
        "movl %ebx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf44b44_00044b95:\n"
        "movl %edx, %eax\n" /* line 236 */
        "andl $1, %eax\n"
        "cmpl $1, %eax\n" /* line 237 */
        "sbbl $-1, %ecx\n"
        "sarl $1, %edx\n" /* line 234 */
        "jne .Lf44b44_00044b95\n"
        "movl %ecx, %eax\n"
        "movb %al, 0x80100(%esi)\n" /* line 240 */
        "testb %bl, %bl\n" /* line 243 */
        "je .Lf44b44_00044b66\n"
        ".Lf44b44_00044bb0:\n"
        "movl $8, %ecx\n"
        "movl $1, %edx\n"
        ".Lf44b44_00044bba:\n"
        "subl $1, %ecx\n" /* line 244 */
        "movl %edx, %eax\n" /* line 243 */
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "testl %eax, %ebx\n"
        "jne .Lf44b44_00044bba\n"
        "movl %ecx, %eax\n"
        "movb %al, 0x80000(%esi)\n" /* line 245 */
        "testl %ebx, %ebx\n" /* line 249 */
        "je .Lf44b44_00044b75\n"
        ".Lf44b44_00044bd4:\n"
        "movl %ebx, %eax\n"
        "xorl %edx, %edx\n"
        ".Lf44b44_00044bd8:\n"
        "addl $1, %edx\n" /* line 251 */
        "sarl $1, %eax\n" /* line 249 */
        "jne .Lf44b44_00044bd8\n"
        "movl %edx, %eax\n"
        "movb %al, 0x80200(%esi)\n" /* line 254 */
        "addl $1, %ebx\n" /* line 230 */
        "addl $1, %esi\n"
        "cmpl $0x100, %ebx\n"
        "jne .Lf44b44_00044b8b\n"
        ".Lf44b44_00044bf5:\n"
        "movl $scrMemTreeGlob, %eax\n"
        "movl $0x3f6722, %edx\n"
        ".Lf44b44_00044bff:\n"
        "movw $0, 0x80300(%eax)\n" /* line 530 */
        "addl $2, %eax\n"
        "cmpl %eax, %edx\n" /* line 529 */
        "jne .Lf44b44_00044bff\n"
        "movw $0, scrMemTreeGlob\n" /* line 532 */
        "movw $0, 0x3f6702\n" /* line 533 */
        "xorl %ebx, %ebx\n" /* i */
        "movl $1, %esi\n"
        ".Lf44b44_00044c28:\n"
        "movl %esi, %eax\n" /* line 537 */
        "movl %ebx, %ecx\n" /* i */
        "shll %cl, %eax\n"
        "movl %ebx, %edx\n" /* i */
        "calll MT_AddMemoryNode\n"
        "addl $1, %ebx\n" /* line 536 | i */
        "cmpl $0x10, %ebx\n" /* i */
        "jne .Lf44b44_00044c28\n"
        "movl $0, 0x476a24\n" /* line 539 */
        "movl $0, 0x476a28\n" /* line 540 */
        /* } scope */
        "popl %ebx\n" /* line 546 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 125 */
static __attribute__((naked))
int MT_GetSubTreeSize(void)
{
    __asm__ __volatile__ (
        ".Lf44c56_00044c56:\n"
        "pushl %ebp\n" /* line 125 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 129 | nodeNum */
        "je .Lf44c56_00044d74\n"
        "shll $3, %eax\n" /* line 132 | nodeNum */
        "leal scrMemTreeGlob(%eax), %edx\n" /* nodeNum */
        "movl %edx, -0x28(%ebp)\n" /* node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 | nodeNum */
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 2 */
        /* { scope 3 */
        "testw %ax, %ax\n" /* line 129 | nodeNum */
        "je .Lf44c56_00044d51\n"
        "leal (, %edx, 8), %eax\n" /* line 132 | nodeNum */
        "leal scrMemTreeGlob(%eax), %edi\n" /* nodeNum, node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 | nodeNum */
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 4 */
        /* { scope 5 */
        "testw %ax, %ax\n" /* line 129 | nodeNum */
        "jne .Lf44c56_00044de4\n"
        "movl $0, -0x24(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf44c56_00044cad:\n"
        "movzwl 2(%edi), %eax\n" /* line 133 | node, nodeNum */
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 4 */
        /* { scope 5 */
        "testw %ax, %ax\n" /* line 129 | nodeNum */
        "jne .Lf44c56_00044db7\n"
        "xorl %eax, %eax\n" /* nodeNum */
        /* } scope */
        /* } scope */
        ".Lf44c56_00044cbf:\n"
        "movl -0x24(%ebp), %edx\n" /* line 133 | nodeNum */
        "leal 1(%edx, %eax), %eax\n" /* nodeNum */
        "movl %eax, -0x2c(%ebp)\n" /* nodeNum */
        /* } scope */
        /* } scope */
        "movl -0x28(%ebp), %edx\n" /* node, nodeNum */
        "movzwl 2(%edx), %eax\n" /* nodeNum */
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 2 */
        /* { scope 3 */
        "testw %ax, %ax\n" /* line 129 | nodeNum */
        "je .Lf44c56_00044d6b\n"
        ".Lf44c56_00044cdc:\n"
        "leal (, %edx, 8), %eax\n" /* line 132 | nodeNum */
        "leal scrMemTreeGlob(%eax), %edi\n" /* nodeNum, node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 | nodeNum */
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 4 */
        /* { scope 5 */
        "testw %ax, %ax\n" /* line 129 | nodeNum */
        "jne .Lf44c56_00044d87\n"
        "movl $0, -0x20(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf44c56_00044d03:\n"
        "movzwl 2(%edi), %eax\n" /* line 133 | node, nodeNum */
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 4 */
        /* { scope 5 */
        "testw %ax, %ax\n" /* line 129 | nodeNum */
        "je .Lf44c56_00044d7c\n"
        "leal (, %edx, 8), %eax\n" /* line 132 | nodeNum */
        "leal scrMemTreeGlob(%eax), %edi\n" /* nodeNum, node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 | nodeNum */
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 6 */
        /* { scope 7 */
        "testw %ax, %ax\n" /* line 129 | nodeNum */
        "jne .Lf44c56_00044e41\n"
        "movl $0, -0x1c(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf44c56_00044d36:\n"
        "movzwl 2(%edi), %eax\n" /* line 133 | node, nodeNum */
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 6 */
        /* { scope 7 */
        "testw %ax, %ax\n" /* line 129 | nodeNum */
        "jne .Lf44c56_00044e14\n"
        "xorl %eax, %eax\n" /* nodeNum */
        /* } scope */
        /* } scope */
        ".Lf44c56_00044d48:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 133 | nodeNum */
        "leal 1(%edx, %eax), %eax\n" /* nodeNum */
        "jmp .Lf44c56_00044d7e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf44c56_00044d51:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 129 */
        /* } scope */
        /* } scope */
        "movl -0x28(%ebp), %edx\n" /* line 133 | node, nodeNum */
        "movzwl 2(%edx), %eax\n" /* nodeNum */
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 2 */
        /* { scope 3 */
        "testw %ax, %ax\n" /* line 129 | nodeNum */
        "jne .Lf44c56_00044cdc\n"
        ".Lf44c56_00044d6b:\n"
        "xorl %eax, %eax\n" /* nodeNum */
        /* } scope */
        /* } scope */
        ".Lf44c56_00044d6d:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 133 | nodeNum */
        "leal 1(%edx, %eax), %eax\n" /* nodeNum */
        /* } scope */
        ".Lf44c56_00044d74:\n"
        "addl $0x2c, %esp\n" /* line 134 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf44c56_00044d7c:\n"
        "xorl %eax, %eax\n" /* line 129 | nodeNum */
        /* } scope */
        /* } scope */
        ".Lf44c56_00044d7e:\n"
        "movl -0x20(%ebp), %edx\n" /* line 133 | nodeNum */
        "leal 1(%edx, %eax), %eax\n" /* nodeNum */
        "jmp .Lf44c56_00044d6d\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lf44c56_00044d87:\n"
        "leal (, %edx, 8), %eax\n" /* line 132 | nodeNum */
        "leal scrMemTreeGlob(%eax), %ebx\n" /* nodeNum, node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 | nodeNum */
        "calll MT_GetSubTreeSize\n"
        "movl %eax, %esi\n" /* nodeNum */
        "movzwl 2(%ebx), %eax\n" /* node, nodeNum */
        "calll MT_GetSubTreeSize\n"
        "leal 1(%esi, %eax), %eax\n" /* nodeNum */
        "movl %eax, -0x20(%ebp)\n" /* nodeNum */
        "jmp .Lf44c56_00044d03\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf44c56_00044db7:\n"
        "leal (, %edx, 8), %eax\n" /* line 132 | nodeNum */
        "leal scrMemTreeGlob(%eax), %ebx\n" /* nodeNum, node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 | nodeNum */
        "calll MT_GetSubTreeSize\n"
        "movl %eax, %esi\n" /* nodeNum */
        "movzwl 2(%ebx), %eax\n" /* node, nodeNum */
        "calll MT_GetSubTreeSize\n"
        "leal 1(%esi, %eax), %eax\n" /* nodeNum */
        "jmp .Lf44c56_00044cbf\n"
        /* } scope */
        /* } scope */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf44c56_00044de4:\n"
        "leal (, %edx, 8), %eax\n" /* line 132 | nodeNum */
        "leal scrMemTreeGlob(%eax), %ebx\n" /* nodeNum, node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 | nodeNum */
        "calll MT_GetSubTreeSize\n"
        "movl %eax, %esi\n" /* nodeNum */
        "movzwl 2(%ebx), %eax\n" /* node, nodeNum */
        "calll MT_GetSubTreeSize\n"
        "leal 1(%esi, %eax), %eax\n" /* nodeNum */
        "movl %eax, -0x24(%ebp)\n" /* nodeNum */
        "jmp .Lf44c56_00044cad\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf44c56_00044e14:\n"
        "leal (, %edx, 8), %eax\n" /* line 132 | nodeNum */
        "leal scrMemTreeGlob(%eax), %ebx\n" /* nodeNum, node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 | nodeNum */
        "calll MT_GetSubTreeSize\n"
        "movl %eax, %esi\n" /* nodeNum */
        "movzwl 2(%ebx), %eax\n" /* node, nodeNum */
        "calll MT_GetSubTreeSize\n"
        "leal 1(%esi, %eax), %eax\n" /* nodeNum */
        "jmp .Lf44c56_00044d48\n"
        /* } scope */
        /* } scope */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf44c56_00044e41:\n"
        "leal (, %edx, 8), %eax\n" /* line 132 | nodeNum */
        "leal scrMemTreeGlob(%eax), %ebx\n" /* nodeNum, node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 | nodeNum */
        "calll MT_GetSubTreeSize\n"
        "movl %eax, %esi\n" /* nodeNum */
        "movzwl 2(%ebx), %eax\n" /* node, nodeNum */
        "calll MT_GetSubTreeSize\n"
        "leal 1(%esi, %eax), %eax\n" /* nodeNum */
        "movl %eax, -0x1c(%ebp)\n" /* nodeNum */
        "jmp .Lf44c56_00044d36\n"
    );
}

/* line 150 */
__attribute__((naked))
unsigned int MT_DumpTree(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 150 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl $0x217c60, (%esp)\n" /* line 188 */
        "calll Com_Printf\n"
        "xorl %edi, %edi\n" /* size */
        "movl $scrMemTreeGlob, -0x1c(%ebp)\n"
        "jmp .Lf44e72_00044ec7\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf44e72_00044e92:\n"
        "xorl %edx, %edx\n" /* line 129 */
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf44e72_00044e96:\n"
        "movl %eax, 0x10(%esp)\n" /* line 197 */
        "movl $1, %eax\n"
        "movl %edi, %ecx\n" /* size */
        "shll %cl, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* size */
        "movl $0x217c84, (%esp)\n" /* "%d subtree has %d * %d = %d free buckets
" */
        "calll Com_Printf\n"
        "addl $1, %edi\n" /* line 192 | size */
        "addl $2, -0x1c(%ebp)\n"
        "cmpl $0x11, %edi\n" /* size */
        "je .Lf44e72_00044f09\n"
        ".Lf44e72_00044ec7:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 194 | nodeNum */
        "movzwl 0x80300(%edx), %eax\n"
        "movzwl %ax, %edx\n" /* nodeNum */
        /* { scope 2 */
        /* { scope 3 */
        "testw %ax, %ax\n" /* line 129 */
        "je .Lf44e72_00044e92\n"
        "leal (, %edx, 8), %eax\n" /* line 132 */
        "leal scrMemTreeGlob(%eax), %ebx\n" /* node */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 133 */
        "calll MT_GetSubTreeSize\n"
        "movl %eax, %esi\n"
        "movzwl 2(%ebx), %eax\n" /* node */
        "calll MT_GetSubTreeSize\n"
        "leal 1(%esi, %eax), %edx\n"
        "movl %edx, %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "jmp .Lf44e72_00044e96\n"
        /* } scope */
        /* } scope */
        ".Lf44e72_00044f09:\n"
        "movl $0x217c60, (%esp)\n" /* line 200 */
        "calll Com_Printf\n"
        "movl $0x217c60, (%esp)\n" /* line 207 */
        "calll Com_Printf\n"
        "movl 0x476a24, %eax\n" /* line 209 */
        "movl %eax, 8(%esp)\n"
        "movl 0x476a28, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x217cb0, (%esp)\n" /* "total memory alloc buckets: %d (%d instances)
" */
        "calll Com_Printf\n"
        "movl $0xffff, %eax\n" /* line 210 */
        "subl 0x476a28, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x217ce0, (%esp)\n" /* "total memory free buckets: %d
" */
        "calll Com_Printf\n"
        "movl $0x217c60, (%esp)\n" /* line 212 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 215 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 578 */
__attribute__((naked))
short unsigned int MT_AllocIndex(int numBytes, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 578 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* numBytes */
        /* { scope 1: parentNode, prevScore, oldNodeValue */
        /* { scope 2: num */
        "cmpl $0xffff, %ebx\n" /* line 567 */
        "jg .Lf44f6e_0004521c\n"
        "movl %ebx, %eax\n" /* line 569 */
        "addl $7, %eax\n"
        "js .Lf44f6e_0004529a\n"
        ".Lf44f6e_00044f94:\n"
        "sarl $3, %eax\n"
        "subl $1, %eax\n"
        "cmpl $0xff, %eax\n" /* line 570 */
        "jg .Lf44f6e_00044fe7\n"
        "movzbl 0x476900(%eax), %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* size */
        /* } scope */
        "cmpl $0x10, -0x58(%ebp)\n" /* line 594 | size */
        "jle .Lf44f6e_00044ffd\n"
        ".Lf44f6e_00044fb1:\n"
        "calll MT_DumpTree\n" /* line 552 */
        "movl %ebx, 8(%esp)\n" /* line 553 */
        "movl $0x217d8c, 4(%esp)\n" /* "MT_AllocIndex" */
        "movl $0x217d24, (%esp)\n" /* "%s: failed memory allocation of %d bytes for script usage
" */
        "calll Com_Printf\n"
        "movl $0x217d60, (%esp)\n" /* line 554 */
        "calll Scr_TerminalError\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: parentNode, prevScore, oldNodeValue */
        /* { scope 2: num */
        ".Lf44f6e_00044fe7:\n"
        "sarl $8, %eax\n" /* line 570 */
        "movzbl 0x476900(%eax), %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* size */
        /* } scope */
        "cmpl $0x10, -0x58(%ebp)\n" /* line 594 | size */
        "jg .Lf44f6e_00044fb1\n"
        ".Lf44f6e_00044ffd:\n"
        "movl -0x58(%ebp), %edx\n" /* line 596 | size */
        "movzwl 0x476a00(%edx, %edx), %eax\n"
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* nodeNum */
        "testw %ax, %ax\n" /* line 597 */
        "je .Lf44f6e_00045266\n"
        ".Lf44f6e_00045017:\n"
        "movl %edx, -0x54(%ebp)\n" /* line 598 | newSize */
        "movl %edx, %ebx\n" /* numBytes */
        /* { scope 2: num */
        ".Lf44f6e_0004501c:\n"
        "leal 0x476a00(%ebx, %ebx), %ebx\n" /* line 468 */
        "movl %ebx, -0x50(%ebp)\n" /* parentNode */
        "movl -0x54(%ebp), %edx\n" /* line 471 | newSize */
        "movzwl 0x476a00(%edx, %edx), %eax\n"
        "movl scrMemTreeGlob(, %eax, 8), %ecx\n"
        "movl 0x3f6704(, %eax, 8), %ebx\n"
        "movl %ecx, -0x68(%ebp)\n" /* oldNodeValue */
        "movl %ebx, -0x64(%ebp)\n"
        "movl %ebx, -0x30(%ebp)\n"
        "shrl $0x10, %ecx\n"
        "movw %cx, -0x48(%ebp)\n"
        "movl -0x68(%ebp), %ebx\n" /* oldNodeValue */
        "movw %bx, -0x32(%ebp)\n"
        "jmp .Lf44f6e_000450cd\n"
        ".Lf44f6e_00045058:\n"
        "movzwl -0x48(%ebp), %esi\n" /* line 476 | oldNode */
        "movl %esi, %edi\n" /* oldNode */
        "movl -0x50(%ebp), %eax\n" /* line 477 | parentNode */
        "movw %si, (%eax)\n" /* oldNode */
        "cmpw $0, -0x48(%ebp)\n" /* line 479 */
        "je .Lf44f6e_000451cc\n"
        "leal 0x3f6702(, %esi, 8), %edx\n" /* line 482 */
        "movl %edx, -0x50(%ebp)\n" /* parentNode */
        ".Lf44f6e_00045079:\n"
        "movl -0x30(%ebp), %ebx\n" /* line 512 */
        "movl %ebx, -0x64(%ebp)\n"
        "shll $0x10, %edi\n"
        "andl $0xffff, -0x68(%ebp)\n" /* oldNodeValue */
        "orl %edi, -0x68(%ebp)\n" /* oldNodeValue */
        "movzwl -0x32(%ebp), %eax\n"
        "movw %ax, -0x68(%ebp)\n" /* oldNodeValue */
        "movl -0x68(%ebp), %eax\n" /* oldNodeValue */
        "movl -0x64(%ebp), %edx\n"
        "movl scrMemTreeGlob(, %esi, 8), %ecx\n" /* line 513 */
        "movl 0x3f6704(, %esi, 8), %ebx\n"
        "movl %ecx, -0x68(%ebp)\n" /* oldNodeValue */
        "movl %ebx, -0x64(%ebp)\n"
        "movl %ebx, -0x30(%ebp)\n"
        "shrl $0x10, %ecx\n"
        "movw %cx, -0x48(%ebp)\n"
        "movl -0x68(%ebp), %ebx\n" /* oldNodeValue */
        "movw %bx, -0x32(%ebp)\n"
        "movl %eax, scrMemTreeGlob(, %esi, 8)\n" /* line 514 */
        "movl %edx, 0x3f6704(, %esi, 8)\n"
        ".Lf44f6e_000450cd:\n"
        "cmpw $0, -0x32(%ebp)\n" /* line 474 */
        "je .Lf44f6e_00045058\n"
        "cmpw $0, -0x48(%ebp)\n" /* line 484 */
        "jne .Lf44f6e_000450f3\n"
        "movzwl -0x32(%ebp), %esi\n" /* line 486 | oldNode */
        "movl -0x50(%ebp), %ecx\n" /* line 487 | parentNode */
        "movw %si, (%ecx)\n" /* oldNode */
        "leal scrMemTreeGlob(, %esi, 8), %ebx\n" /* line 488 */
        "movl %ebx, -0x50(%ebp)\n" /* parentNode */
        "xorl %edi, %edi\n"
        "jmp .Lf44f6e_00045079\n"
        ".Lf44f6e_000450f3:\n"
        "movzwl -0x32(%ebp), %esi\n" /* line 492 | oldNode */
        /* { scope 3 */
        /* { scope 4 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %esi, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %edi\n" /* line 276 */
        "movzbl 0x476800(%ecx), %eax\n" /* line 278 */
        "movzbl 0x476800(%edi), %edx\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf44f6e_00045133\n"
        "movzbl 0x476700(%edi), %eax\n" /* line 282 */
        "addl %eax, %ecx\n"
        ".Lf44f6e_00045133:\n"
        "movl $1, -0x6c(%ebp)\n" /* line 283 */
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* prevScore */
        /* } scope */
        /* } scope */
        "movzwl -0x48(%ebp), %edi\n" /* line 493 */
        /* { scope 3 */
        /* { scope 4 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %edi, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %eax\n" /* line 276 */
        "movl %eax, -0x2c(%ebp)\n"
        "movzbl 0x476800(%ecx), %edx\n" /* line 278 */
        "movl %edx, -0x7c(%ebp)\n"
        "movzbl 0x476800(%eax), %edx\n"
        "movl -0x7c(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf44f6e_00045192\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 282 */
        "movzbl 0x476700(%ebx), %eax\n"
        "addl %eax, %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf44f6e_00045192:\n"
        "shll %cl, -0x6c(%ebp)\n" /* line 496 */
        "movl -0x6c(%ebp), %ecx\n"
        "leal (%edx, %ecx), %eax\n"
        "cmpl %eax, -0x4c(%ebp)\n" /* prevScore */
        "jge .Lf44f6e_000451b7\n"
        "movl -0x50(%ebp), %ebx\n" /* line 499 | parentNode */
        "movw %di, (%ebx)\n"
        "leal 0x3f6702(, %edi, 8), %eax\n" /* line 500 */
        "movl %eax, -0x50(%ebp)\n" /* parentNode */
        "movl %edi, %esi\n" /* oldNode */
        "jmp .Lf44f6e_00045079\n"
        ".Lf44f6e_000451b7:\n"
        "movl -0x50(%ebp), %edx\n" /* line 505 | parentNode */
        "movw %si, (%edx)\n" /* oldNode */
        "leal scrMemTreeGlob(, %esi, 8), %ecx\n" /* line 506 */
        "movl %ecx, -0x50(%ebp)\n" /* parentNode */
        "jmp .Lf44f6e_00045079\n"
        /* } scope */
        ".Lf44f6e_000451cc:\n"
        "movl -0x58(%ebp), %edx\n" /* line 600 | size */
        "cmpl %edx, -0x54(%ebp)\n" /* newSize */
        "je .Lf44f6e_000451f5\n"
        "movl %edx, %esi\n" /* oldNode */
        /* { scope 2: num */
        "movl -0x54(%ebp), %ebx\n" /* line 472 | newSize */
        "movl $1, %edi\n"
        /* } scope */
        ".Lf44f6e_000451de:\n"
        "subl $1, %ebx\n" /* line 602 | numBytes */
        "movl %edi, %eax\n" /* line 603 */
        "movl %ebx, %ecx\n" /* numBytes */
        "shll %cl, %eax\n"
        "addl -0x5c(%ebp), %eax\n" /* nodeNum */
        "movl %ebx, %edx\n" /* numBytes */
        "calll MT_AddMemoryNode\n"
        "cmpl %esi, %ebx\n" /* line 600 | oldNode, numBytes */
        "jne .Lf44f6e_000451de\n"
        ".Lf44f6e_000451f5:\n"
        "addl $1, 0x476a24\n" /* line 607 */
        "movl $1, %eax\n" /* line 608 */
        "movzbl -0x58(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "addl %eax, 0x476a28\n"
        "movzwl -0x5c(%ebp), %eax\n" /* line 623 | nodeNum */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: parentNode, prevScore, oldNodeValue */
        /* { scope 2: num */
        ".Lf44f6e_0004521c:\n"
        "calll MT_DumpTree\n" /* line 552 */
        "movl %ebx, 8(%esp)\n" /* line 553 */
        "movl $0x217d00, 4(%esp)\n" /* "MT_GetSize: max allocation exceeded" */
        "movl $0x217d24, (%esp)\n" /* "%s: failed memory allocation of %d bytes for script usage
" */
        "calll Com_Printf\n"
        "movl $0x217d60, (%esp)\n" /* line 554 */
        "calll Scr_TerminalError\n"
        "movl $0, -0x58(%ebp)\n" /* size */
        /* } scope */
        "movl -0x58(%ebp), %edx\n" /* line 596 | size */
        "movzwl 0x476a00(%edx, %edx), %eax\n"
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* nodeNum */
        "testw %ax, %ax\n" /* line 597 */
        "jne .Lf44f6e_00045017\n"
        ".Lf44f6e_00045266:\n"
        "movl %edx, %eax\n"
        "leal 0x476a00(%edx, %edx), %edx\n" /* line 598 */
        "movl %eax, -0x54(%ebp)\n" /* newSize */
        ".Lf44f6e_00045272:\n"
        "addl $1, -0x54(%ebp)\n" /* line 594 | newSize */
        "cmpl $0x11, -0x54(%ebp)\n" /* newSize */
        "je .Lf44f6e_00044fb1\n"
        "movzwl 2(%edx), %eax\n" /* line 596 */
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* nodeNum */
        "addl $2, %edx\n"
        "testw %ax, %ax\n" /* line 597 */
        "je .Lf44f6e_00045272\n"
        "movl -0x54(%ebp), %ebx\n" /* newSize, numBytes */
        "jmp .Lf44f6e_0004501c\n"
        /* { scope 2: num */
        ".Lf44f6e_0004529a:\n"
        "leal 0xe(%ebx), %eax\n" /* line 569 */
        "jmp .Lf44f6e_00044f94\n"
    );
}

/* line 733 */
__attribute__((naked))
unsigned int * MT_Alloc(int numBytes, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 733 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 735 | type */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* numBytes */
        "movl %eax, (%esp)\n"
        "calll MT_AllocIndex\n"
        "movzwl %ax, %eax\n"
        "leal scrMemTreeGlob(, %eax, 8), %eax\n"
        "leave\n" /* line 736 */
        "retl\n"
    );
}

/* line 769 */
__attribute__((naked))
unsigned int MT_ForceAllocIndex(byte *allocBits, unsigned int nodeNum, int numBytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 769 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* allocBits */
        "movl 0x10(%ebp), %ebx\n" /* numBytes */
        /* { scope 1 */
        "cmpl $0xffff, %ebx\n" /* line 567 */
        "jg .Lf452c6_00045355\n"
        "movl %ebx, %eax\n" /* line 569 */
        "addl $7, %eax\n"
        "js .Lf452c6_00045388\n"
        ".Lf452c6_000452e8:\n"
        "sarl $3, %eax\n"
        "subl $1, %eax\n"
        "cmpl $0xff, %eax\n" /* line 570 */
        "jg .Lf452c6_0004533f\n"
        "movzbl 0x476900(%eax), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        /* } scope */
        ".Lf452c6_00045303:\n"
        "addl $1, 0x476a24\n" /* line 778 */
        "addl %eax, 0x476a28\n" /* line 780 */
        "testl %eax, %eax\n" /* line 789 */
        "je .Lf452c6_00045337\n"
        "movl 0xc(%ebp), %edx\n" /* nodeNum */
        "leal (%edx, %eax), %ebx\n" /* numBytes */
        ".Lf452c6_0004531a:\n"
        "movl %edx, %eax\n" /* line 791 */
        "shrl $3, %eax\n"
        "movl %edx, %ecx\n"
        "andl $7, %ecx\n"
        "movl $1, %esi\n"
        "shll %cl, %esi\n"
        "movl %esi, %ecx\n"
        "orb %cl, (%edi, %eax)\n" /* allocBits */
        "addl $1, %edx\n" /* line 792 */
        "cmpl %edx, %ebx\n" /* line 789 | numBytes */
        "jne .Lf452c6_0004531a\n"
        ".Lf452c6_00045337:\n"
        "addl $0x1c, %esp\n" /* line 795 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf452c6_0004533f:\n"
        "sarl $8, %eax\n" /* line 570 */
        "movzbl 0x476900(%eax), %ecx\n"
        "addl $8, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "jmp .Lf452c6_00045303\n"
        ".Lf452c6_00045355:\n"
        "calll MT_DumpTree\n" /* line 552 */
        "movl %ebx, 8(%esp)\n" /* line 553 */
        "movl $0x217d00, 4(%esp)\n" /* "MT_GetSize: max allocation exceeded" */
        "movl $0x217d24, (%esp)\n" /* "%s: failed memory allocation of %d bytes for script usage
" */
        "calll Com_Printf\n"
        "movl $0x217d60, (%esp)\n" /* line 554 */
        "calll Scr_TerminalError\n"
        "movl $1, %eax\n"
        "jmp .Lf452c6_00045303\n"
        ".Lf452c6_00045388:\n"
        "leal 0xe(%ebx), %eax\n" /* line 569 */
        "jmp .Lf452c6_000452e8\n"
    );
}

/* line 813 */
__attribute__((naked))
int MT_Realloc(int oldNumBytes, int newNumbytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 813 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* oldNumBytes */
        "movl 0xc(%ebp), %esi\n" /* newNumbytes */
        /* { scope 1 */
        "cmpl $0xffff, %ebx\n" /* line 567 */
        "jg .Lf45390_0004546a\n"
        "movl %ebx, %eax\n" /* line 569 */
        "addl $7, %eax\n"
        "js .Lf45390_000454a2\n"
        ".Lf45390_000453b5:\n"
        "sarl $3, %eax\n"
        "subl $1, %eax\n"
        "cmpl $0xff, %eax\n" /* line 570 */
        "jg .Lf45390_000453ff\n"
        "movzbl 0x476900(%eax), %ebx\n"
        /* } scope */
        /* { scope 1 */
        ".Lf45390_000453c9:\n"
        "cmpl $0xffff, %esi\n" /* line 567 */
        "jg .Lf45390_00045414\n"
        ".Lf45390_000453d1:\n"
        "movl %esi, %eax\n" /* line 569 */
        "addl $7, %eax\n"
        "js .Lf45390_0004549a\n"
        ".Lf45390_000453dc:\n"
        "sarl $3, %eax\n"
        "subl $1, %eax\n"
        "cmpl $0xff, %eax\n" /* line 570 */
        "jg .Lf45390_0004544e\n"
        "movzbl 0x476900(%eax), %eax\n"
        "cmpl %eax, %ebx\n" /* line 554 */
        "setge %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf45390_000453ff:\n"
        "sarl $8, %eax\n" /* line 570 */
        "movzbl 0x476900(%eax), %eax\n"
        "leal 8(%eax), %ebx\n"
        /* } scope */
        /* { scope 1 */
        "cmpl $0xffff, %esi\n" /* line 567 */
        "jle .Lf45390_000453d1\n"
        ".Lf45390_00045414:\n"
        "calll MT_DumpTree\n" /* line 552 */
        "movl %esi, 8(%esp)\n" /* line 553 */
        "movl $0x217d00, 4(%esp)\n" /* "MT_GetSize: max allocation exceeded" */
        "movl $0x217d24, (%esp)\n" /* "%s: failed memory allocation of %d bytes for script usage
" */
        "calll Com_Printf\n"
        "movl $0x217d60, (%esp)\n" /* line 554 */
        "calll Scr_TerminalError\n"
        "xorl %eax, %eax\n"
        "cmpl %eax, %ebx\n"
        "setge %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf45390_0004544e:\n"
        "sarl $8, %eax\n" /* line 570 */
        "movzbl 0x476900(%eax), %eax\n"
        "addl $8, %eax\n"
        "cmpl %eax, %ebx\n" /* line 554 */
        "setge %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf45390_0004546a:\n"
        "calll MT_DumpTree\n" /* line 552 */
        "movl %ebx, 8(%esp)\n" /* line 553 */
        "movl $0x217d00, 4(%esp)\n" /* "MT_GetSize: max allocation exceeded" */
        "movl $0x217d24, (%esp)\n" /* "%s: failed memory allocation of %d bytes for script usage
" */
        "calll Com_Printf\n"
        "movl $0x217d60, (%esp)\n" /* line 554 */
        "calll Scr_TerminalError\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf45390_000453c9\n"
        /* } scope */
        /* { scope 1 */
        ".Lf45390_0004549a:\n"
        "leal 0xe(%esi), %eax\n" /* line 569 */
        "jmp .Lf45390_000453dc\n"
        /* } scope */
        /* { scope 1 */
        ".Lf45390_000454a2:\n"
        "leal 0xe(%ebx), %eax\n"
        "jmp .Lf45390_000453b5\n"
    );
}

/* line 739 */
__attribute__((naked))
unsigned int MT_Free(unsigned int *p, int numBytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 739 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* numBytes */
        "subl $scrMemTreeGlob, 8(%ebp)\n" /* line 747 | p */
        "sarl $3, 8(%ebp)\n" /* p */
        /* { scope 1: lowBit */
        /* { scope 2: size */
        /* { scope 3: parentNode, prevScore, oldNodeValue */
        "cmpl $0xffff, %ebx\n" /* line 567 | nodeNum */
        "jg .Lf454aa_000455d9\n"
        "movl %ebx, %eax\n" /* line 569 | nodeNum */
        "addl $7, %eax\n"
        "js .Lf454aa_000457e0\n"
        ".Lf454aa_000454d8:\n"
        "sarl $3, %eax\n"
        "subl $1, %eax\n"
        "cmpl $0xff, %eax\n" /* line 570 */
        "jg .Lf454aa_00045590\n"
        "movzbl 0x476900(%eax), %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* size */
        "movl $1, -0x58(%ebp)\n" /* lowBit */
        "movl %eax, %ecx\n"
        "shll %cl, -0x58(%ebp)\n" /* lowBit */
        /* } scope */
        ".Lf454aa_000454ff:\n"
        "subl $1, 0x476a24\n" /* line 648 */
        "movl -0x58(%ebp), %ebx\n" /* line 649 | lowBit, nodeNum */
        "subl %ebx, 0x476a28\n" /* nodeNum */
        "cmpl $0x10, -0x54(%ebp)\n" /* line 665 | size */
        "je .Lf454aa_000455c6\n"
        ".Lf454aa_00045519:\n"
        "movl %ebx, %edx\n" /* nodeNum */
        ".Lf454aa_0004551b:\n"
        "xorl 8(%ebp), %edx\n" /* p */
        /* { scope 3: parentNode, prevScore, oldNodeValue */
        /* { scope 4: num */
        "movl -0x54(%ebp), %ecx\n" /* line 383 | size */
        "leal 0x80300(%ecx, %ecx), %eax\n"
        "leal scrMemTreeGlob(%eax), %ebx\n" /* nodeNum */
        "movl %ebx, -0x50(%ebp)\n" /* nodeNum, parentNode */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 384 */
        "movzwl %ax, %ecx\n"
        "testw %ax, %ax\n" /* line 386 */
        "je .Lf454aa_000455c6\n"
        "cmpl %ecx, %edx\n" /* line 388 */
        "je .Lf454aa_00045615\n"
        "testl %edx, %edx\n" /* line 436 */
        "je .Lf454aa_000455c6\n"
        "xorl %ebx, %ebx\n" /* nodeNum */
        "movl $0x10000, %esi\n" /* level */
        "jmp .Lf454aa_0004557c\n"
        ".Lf454aa_00045559:\n"
        "leal scrMemTreeGlob(, %ecx, 8), %ecx\n" /* line 442 */
        "movl %ecx, -0x50(%ebp)\n" /* parentNode */
        "subl %esi, %ebx\n" /* line 443 | level, nodeNum */
        ".Lf454aa_00045565:\n"
        "movzwl (%ecx), %eax\n" /* line 450 */
        "movzwl %ax, %ecx\n"
        "testw %ax, %ax\n" /* line 386 */
        "je .Lf454aa_000455c6\n"
        "cmpl %ecx, %edx\n" /* line 388 */
        "je .Lf454aa_00045615\n"
        "cmpl %edx, %ebx\n" /* line 436 | nodeNum */
        "je .Lf454aa_000455c6\n"
        ".Lf454aa_0004557c:\n"
        "sarl $1, %esi\n" /* line 439 | level */
        "cmpl %edx, %ebx\n" /* line 440 | nodeNum */
        "jg .Lf454aa_00045559\n"
        "leal 0x3f6702(, %ecx, 8), %ecx\n" /* line 447 */
        "movl %ecx, -0x50(%ebp)\n" /* parentNode */
        "addl %esi, %ebx\n" /* line 448 | level, nodeNum */
        "jmp .Lf454aa_00045565\n"
        /* } scope */
        /* } scope */
        /* { scope 3: parentNode, prevScore, oldNodeValue */
        ".Lf454aa_00045590:\n"
        "sarl $8, %eax\n" /* line 570 */
        "movzbl 0x476900(%eax), %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* size */
        "movl $1, -0x58(%ebp)\n" /* lowBit */
        "movl %eax, %ecx\n"
        "shll %cl, -0x58(%ebp)\n" /* lowBit */
        /* } scope */
        "subl $1, 0x476a24\n" /* line 648 */
        "movl -0x58(%ebp), %ebx\n" /* line 649 | lowBit, nodeNum */
        "subl %ebx, 0x476a28\n" /* nodeNum */
        "cmpl $0x10, -0x54(%ebp)\n" /* line 665 | size */
        "jne .Lf454aa_00045519\n"
        ".Lf454aa_000455c6:\n"
        "movl -0x54(%ebp), %edx\n" /* line 667 | size */
        "movl 8(%ebp), %eax\n" /* p */
        "calll MT_AddMemoryNode\n"
        /* } scope */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 752 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lowBit */
        /* { scope 2: size */
        /* { scope 3: parentNode, prevScore, oldNodeValue */
        ".Lf454aa_000455d9:\n"
        "calll MT_DumpTree\n" /* line 552 */
        "movl %ebx, 8(%esp)\n" /* line 553 | nodeNum */
        "movl $0x217d00, 4(%esp)\n" /* "MT_GetSize: max allocation exceeded" */
        "movl $0x217d24, (%esp)\n" /* "%s: failed memory allocation of %d bytes for script usage
" */
        "calll Com_Printf\n"
        "movl $0x217d60, (%esp)\n" /* line 554 */
        "calll Scr_TerminalError\n"
        "movl $0, -0x54(%ebp)\n" /* size */
        "movl $1, -0x58(%ebp)\n" /* lowBit */
        "jmp .Lf454aa_000454ff\n"
        /* } scope */
        /* { scope 3: parentNode, prevScore, oldNodeValue */
        /* { scope 4: num */
        ".Lf454aa_00045615:\n"
        "movl scrMemTreeGlob(, %edx, 8), %ecx\n" /* line 390 */
        "movl 0x3f6704(, %edx, 8), %ebx\n" /* nodeNum */
        "movl %ecx, -0x60(%ebp)\n" /* oldNodeValue */
        "movl %ebx, -0x5c(%ebp)\n" /* nodeNum */
        "movl %ebx, -0x30(%ebp)\n" /* nodeNum */
        "shrl $0x10, %ecx\n"
        "movw %cx, -0x48(%ebp)\n"
        "movl -0x60(%ebp), %ebx\n" /* oldNodeValue, nodeNum */
        "movw %bx, -0x32(%ebp)\n" /* nodeNum */
        "jmp .Lf454aa_000456b1\n"
        ".Lf454aa_0004563c:\n"
        "movzwl -0x48(%ebp), %esi\n" /* line 395 | level */
        "movl %esi, %edi\n" /* level */
        "movl -0x50(%ebp), %eax\n" /* line 396 | parentNode */
        "movw %si, (%eax)\n" /* level */
        "cmpw $0, -0x48(%ebp)\n" /* line 397 */
        "je .Lf454aa_000457b3\n"
        "leal 0x3f6702(, %esi, 8), %ecx\n" /* line 400 */
        "movl %ecx, -0x50(%ebp)\n" /* parentNode */
        ".Lf454aa_0004565d:\n"
        "movl -0x30(%ebp), %eax\n" /* line 430 */
        "movl %eax, -0x5c(%ebp)\n"
        "shll $0x10, %edi\n"
        "andl $0xffff, -0x60(%ebp)\n" /* oldNodeValue */
        "orl %edi, -0x60(%ebp)\n" /* oldNodeValue */
        "movzwl -0x32(%ebp), %ecx\n"
        "movw %cx, -0x60(%ebp)\n" /* oldNodeValue */
        "movl -0x60(%ebp), %eax\n" /* oldNodeValue */
        "movl -0x5c(%ebp), %edx\n"
        "movl scrMemTreeGlob(, %esi, 8), %ecx\n" /* line 431 */
        "movl 0x3f6704(, %esi, 8), %ebx\n" /* nodeNum */
        "movl %ecx, -0x60(%ebp)\n" /* oldNodeValue */
        "movl %ebx, -0x5c(%ebp)\n" /* nodeNum */
        "movl %ebx, -0x30(%ebp)\n" /* nodeNum */
        "shrl $0x10, %ecx\n"
        "movw %cx, -0x48(%ebp)\n"
        "movl -0x60(%ebp), %ebx\n" /* oldNodeValue, nodeNum */
        "movw %bx, -0x32(%ebp)\n" /* nodeNum */
        "movl %eax, scrMemTreeGlob(, %esi, 8)\n" /* line 432 */
        "movl %edx, 0x3f6704(, %esi, 8)\n"
        ".Lf454aa_000456b1:\n"
        "cmpw $0, -0x32(%ebp)\n" /* line 393 */
        "je .Lf454aa_0004563c\n"
        "cmpw $0, -0x48(%ebp)\n" /* line 402 */
        "jne .Lf454aa_000456d7\n"
        "movzwl -0x32(%ebp), %esi\n" /* line 404 | level */
        "movl -0x50(%ebp), %ebx\n" /* line 405 | parentNode, nodeNum */
        "movw %si, (%ebx)\n" /* level, nodeNum */
        "leal scrMemTreeGlob(, %esi, 8), %eax\n" /* line 406 */
        "movl %eax, -0x50(%ebp)\n" /* parentNode */
        "xorl %edi, %edi\n"
        "jmp .Lf454aa_0004565d\n"
        ".Lf454aa_000456d7:\n"
        "movzwl -0x32(%ebp), %esi\n" /* line 410 | level */
        /* { scope 5 */
        /* { scope 6 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %esi, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %edi\n" /* line 276 */
        "movzbl 0x476800(%ecx), %eax\n" /* line 278 */
        "movzbl 0x476800(%edi), %edx\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf454aa_00045717\n"
        "movzbl 0x476700(%edi), %eax\n" /* line 282 */
        "addl %eax, %ecx\n"
        ".Lf454aa_00045717:\n"
        "movl $1, -0x64(%ebp)\n" /* line 283 */
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* prevScore */
        /* } scope */
        /* } scope */
        "movzwl -0x48(%ebp), %edi\n" /* line 411 */
        /* { scope 5 */
        /* { scope 6 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %edi, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %eax\n" /* line 276 */
        "movl %eax, -0x2c(%ebp)\n"
        "movzbl 0x476800(%ecx), %eax\n" /* line 278 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movzbl 0x476800(%eax), %edx\n"
        "movl -0x6c(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf454aa_00045779\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 282 */
        "movzbl 0x476700(%ebx), %eax\n"
        "addl %eax, %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf454aa_00045779:\n"
        "shll %cl, -0x64(%ebp)\n" /* line 414 */
        "movl -0x64(%ebp), %ecx\n"
        "leal (%edx, %ecx), %eax\n"
        "cmpl %eax, -0x4c(%ebp)\n" /* prevScore */
        "jge .Lf454aa_0004579e\n"
        "movl -0x50(%ebp), %ebx\n" /* line 417 | parentNode, nodeNum */
        "movw %di, (%ebx)\n" /* nodeNum */
        "leal 0x3f6702(, %edi, 8), %eax\n" /* line 418 */
        "movl %eax, -0x50(%ebp)\n" /* parentNode */
        "movl %edi, %esi\n" /* level */
        "jmp .Lf454aa_0004565d\n"
        ".Lf454aa_0004579e:\n"
        "movl -0x50(%ebp), %ecx\n" /* line 423 | parentNode */
        "movw %si, (%ecx)\n" /* level */
        "leal scrMemTreeGlob(, %esi, 8), %ebx\n" /* line 424 | nodeNum */
        "movl %ebx, -0x50(%ebp)\n" /* nodeNum, parentNode */
        "jmp .Lf454aa_0004565d\n"
        /* } scope */
        /* } scope */
        ".Lf454aa_000457b3:\n"
        "notl -0x58(%ebp)\n" /* line 673 | lowBit */
        "movl -0x58(%ebp), %ebx\n" /* lowBit, nodeNum */
        "andl %ebx, 8(%ebp)\n" /* nodeNum, p */
        "addl $1, -0x54(%ebp)\n" /* line 674 | size */
        "movl $1, -0x58(%ebp)\n" /* line 661 | lowBit */
        "movzbl -0x54(%ebp), %ecx\n" /* size */
        "shll %cl, -0x58(%ebp)\n" /* lowBit */
        "cmpl $0x10, -0x54(%ebp)\n" /* line 665 | size */
        "je .Lf454aa_000455c6\n"
        "movl -0x58(%ebp), %edx\n" /* lowBit */
        "jmp .Lf454aa_0004551b\n"
        /* { scope 3: parentNode, prevScore, oldNodeValue */
        ".Lf454aa_000457e0:\n"
        "leal 0xe(%ebx), %eax\n" /* line 569 | nodeNum */
        "jmp .Lf454aa_000454d8\n"
    );
}

/* line 636 */
__attribute__((naked))
unsigned int MT_FreeIndex(unsigned int nodeNum, int numBytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 636 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* numBytes */
        /* { scope 1 */
        /* { scope 2: parentNode, prevScore, oldNodeValue */
        "cmpl $0xffff, %ebx\n" /* line 567 | nodeNum */
        "jg .Lf457e8_0004590d\n"
        "movl %ebx, %eax\n" /* line 569 | nodeNum */
        "addl $7, %eax\n"
        "js .Lf457e8_00045b11\n"
        ".Lf457e8_0004580b:\n"
        "sarl $3, %eax\n"
        "subl $1, %eax\n"
        "cmpl $0xff, %eax\n" /* line 570 */
        "jg .Lf457e8_000458c4\n"
        "movzbl 0x476900(%eax), %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* size */
        "movl $1, -0x58(%ebp)\n" /* lowBit */
        "movl %eax, %ecx\n"
        "shll %cl, -0x58(%ebp)\n" /* lowBit */
        /* } scope */
        ".Lf457e8_00045832:\n"
        "subl $1, 0x476a24\n" /* line 648 */
        "movl -0x58(%ebp), %ebx\n" /* line 649 | lowBit, numBytes */
        "subl %ebx, 0x476a28\n" /* numBytes */
        "cmpl $0x10, -0x54(%ebp)\n" /* line 665 | size */
        "je .Lf457e8_000458fa\n"
        ".Lf457e8_0004584c:\n"
        "movl 8(%ebp), %edx\n" /* nodeNum */
        "xorl -0x58(%ebp), %edx\n" /* lowBit */
        /* { scope 2: parentNode, prevScore, oldNodeValue */
        /* { scope 3: num */
        "movl -0x54(%ebp), %ecx\n" /* line 383 | size */
        "leal 0x80300(%ecx, %ecx), %eax\n"
        "leal scrMemTreeGlob(%eax), %ebx\n" /* nodeNum */
        "movl %ebx, -0x50(%ebp)\n" /* nodeNum, parentNode */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 384 */
        "movzwl %ax, %ecx\n"
        "testw %ax, %ax\n" /* line 386 */
        "je .Lf457e8_000458fa\n"
        "cmpl %ecx, %edx\n" /* line 388 */
        "je .Lf457e8_00045949\n"
        "testl %edx, %edx\n" /* line 436 */
        "je .Lf457e8_000458fa\n"
        "xorl %ebx, %ebx\n" /* nodeNum */
        "movl $0x10000, %esi\n" /* level */
        "jmp .Lf457e8_000458b0\n"
        ".Lf457e8_0004588d:\n"
        "leal scrMemTreeGlob(, %ecx, 8), %ecx\n" /* line 442 */
        "movl %ecx, -0x50(%ebp)\n" /* parentNode */
        "subl %esi, %ebx\n" /* line 443 | level, nodeNum */
        ".Lf457e8_00045899:\n"
        "movzwl (%ecx), %eax\n" /* line 450 */
        "movzwl %ax, %ecx\n"
        "testw %ax, %ax\n" /* line 386 */
        "je .Lf457e8_000458fa\n"
        "cmpl %ecx, %edx\n" /* line 388 */
        "je .Lf457e8_00045949\n"
        "cmpl %edx, %ebx\n" /* line 436 | nodeNum */
        "je .Lf457e8_000458fa\n"
        ".Lf457e8_000458b0:\n"
        "sarl $1, %esi\n" /* line 439 | level */
        "cmpl %edx, %ebx\n" /* line 440 | nodeNum */
        "jg .Lf457e8_0004588d\n"
        "leal 0x3f6702(, %ecx, 8), %ecx\n" /* line 447 */
        "movl %ecx, -0x50(%ebp)\n" /* parentNode */
        "addl %esi, %ebx\n" /* line 448 | level, nodeNum */
        "jmp .Lf457e8_00045899\n"
        /* } scope */
        /* } scope */
        /* { scope 2: parentNode, prevScore, oldNodeValue */
        ".Lf457e8_000458c4:\n"
        "sarl $8, %eax\n" /* line 570 */
        "movzbl 0x476900(%eax), %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* size */
        "movl $1, -0x58(%ebp)\n" /* lowBit */
        "movl %eax, %ecx\n"
        "shll %cl, -0x58(%ebp)\n" /* lowBit */
        /* } scope */
        "subl $1, 0x476a24\n" /* line 648 */
        "movl -0x58(%ebp), %ebx\n" /* line 649 | lowBit, numBytes */
        "subl %ebx, 0x476a28\n" /* numBytes */
        "cmpl $0x10, -0x54(%ebp)\n" /* line 665 | size */
        "jne .Lf457e8_0004584c\n"
        ".Lf457e8_000458fa:\n"
        "movl -0x54(%ebp), %edx\n" /* line 667 | size */
        "movl 8(%ebp), %eax\n" /* nodeNum */
        "calll MT_AddMemoryNode\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 676 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: parentNode, prevScore, oldNodeValue */
        ".Lf457e8_0004590d:\n"
        "calll MT_DumpTree\n" /* line 552 */
        "movl %ebx, 8(%esp)\n" /* line 553 | nodeNum */
        "movl $0x217d00, 4(%esp)\n" /* "MT_GetSize: max allocation exceeded" */
        "movl $0x217d24, (%esp)\n" /* "%s: failed memory allocation of %d bytes for script usage
" */
        "calll Com_Printf\n"
        "movl $0x217d60, (%esp)\n" /* line 554 */
        "calll Scr_TerminalError\n"
        "movl $0, -0x54(%ebp)\n" /* size */
        "movl $1, -0x58(%ebp)\n" /* lowBit */
        "jmp .Lf457e8_00045832\n"
        /* } scope */
        /* { scope 2: parentNode, prevScore, oldNodeValue */
        /* { scope 3: num */
        ".Lf457e8_00045949:\n"
        "movl scrMemTreeGlob(, %edx, 8), %ecx\n" /* line 390 */
        "movl 0x3f6704(, %edx, 8), %ebx\n" /* nodeNum */
        "movl %ecx, -0x60(%ebp)\n" /* oldNodeValue */
        "movl %ebx, -0x5c(%ebp)\n" /* nodeNum */
        "movl %ebx, -0x30(%ebp)\n" /* nodeNum */
        "shrl $0x10, %ecx\n"
        "movw %cx, -0x48(%ebp)\n"
        "movl -0x60(%ebp), %ebx\n" /* oldNodeValue, nodeNum */
        "movw %bx, -0x32(%ebp)\n" /* nodeNum */
        "jmp .Lf457e8_000459e5\n"
        ".Lf457e8_00045970:\n"
        "movzwl -0x48(%ebp), %esi\n" /* line 395 | level */
        "movl %esi, %edi\n" /* level */
        "movl -0x50(%ebp), %eax\n" /* line 396 | parentNode */
        "movw %si, (%eax)\n" /* level */
        "cmpw $0, -0x48(%ebp)\n" /* line 397 */
        "je .Lf457e8_00045ae7\n"
        "leal 0x3f6702(, %esi, 8), %ecx\n" /* line 400 */
        "movl %ecx, -0x50(%ebp)\n" /* parentNode */
        ".Lf457e8_00045991:\n"
        "movl -0x30(%ebp), %eax\n" /* line 430 */
        "movl %eax, -0x5c(%ebp)\n"
        "shll $0x10, %edi\n"
        "andl $0xffff, -0x60(%ebp)\n" /* oldNodeValue */
        "orl %edi, -0x60(%ebp)\n" /* oldNodeValue */
        "movzwl -0x32(%ebp), %ecx\n"
        "movw %cx, -0x60(%ebp)\n" /* oldNodeValue */
        "movl -0x60(%ebp), %eax\n" /* oldNodeValue */
        "movl -0x5c(%ebp), %edx\n"
        "movl scrMemTreeGlob(, %esi, 8), %ecx\n" /* line 431 */
        "movl 0x3f6704(, %esi, 8), %ebx\n" /* nodeNum */
        "movl %ecx, -0x60(%ebp)\n" /* oldNodeValue */
        "movl %ebx, -0x5c(%ebp)\n" /* nodeNum */
        "movl %ebx, -0x30(%ebp)\n" /* nodeNum */
        "shrl $0x10, %ecx\n"
        "movw %cx, -0x48(%ebp)\n"
        "movl -0x60(%ebp), %ebx\n" /* oldNodeValue, nodeNum */
        "movw %bx, -0x32(%ebp)\n" /* nodeNum */
        "movl %eax, scrMemTreeGlob(, %esi, 8)\n" /* line 432 */
        "movl %edx, 0x3f6704(, %esi, 8)\n"
        ".Lf457e8_000459e5:\n"
        "cmpw $0, -0x32(%ebp)\n" /* line 393 */
        "je .Lf457e8_00045970\n"
        "cmpw $0, -0x48(%ebp)\n" /* line 402 */
        "jne .Lf457e8_00045a0b\n"
        "movzwl -0x32(%ebp), %esi\n" /* line 404 | level */
        "movl -0x50(%ebp), %ebx\n" /* line 405 | parentNode, nodeNum */
        "movw %si, (%ebx)\n" /* level, nodeNum */
        "leal scrMemTreeGlob(, %esi, 8), %eax\n" /* line 406 */
        "movl %eax, -0x50(%ebp)\n" /* parentNode */
        "xorl %edi, %edi\n"
        "jmp .Lf457e8_00045991\n"
        ".Lf457e8_00045a0b:\n"
        "movzwl -0x32(%ebp), %esi\n" /* line 410 | level */
        /* { scope 4 */
        /* { scope 5 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %esi, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %edi\n" /* line 276 */
        "movzbl 0x476800(%ecx), %eax\n" /* line 278 */
        "movzbl 0x476800(%edi), %edx\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf457e8_00045a4b\n"
        "movzbl 0x476700(%edi), %eax\n" /* line 282 */
        "addl %eax, %ecx\n"
        ".Lf457e8_00045a4b:\n"
        "movl $1, -0x64(%ebp)\n" /* line 283 */
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* prevScore */
        /* } scope */
        /* } scope */
        "movzwl -0x48(%ebp), %edi\n" /* line 411 */
        /* { scope 4 */
        /* { scope 5 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %edi, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %eax\n" /* line 276 */
        "movl %eax, -0x2c(%ebp)\n"
        "movzbl 0x476800(%ecx), %eax\n" /* line 278 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movzbl 0x476800(%eax), %edx\n"
        "movl -0x6c(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf457e8_00045aad\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 282 */
        "movzbl 0x476700(%ebx), %eax\n"
        "addl %eax, %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf457e8_00045aad:\n"
        "shll %cl, -0x64(%ebp)\n" /* line 414 */
        "movl -0x64(%ebp), %ecx\n"
        "leal (%edx, %ecx), %eax\n"
        "cmpl %eax, -0x4c(%ebp)\n" /* prevScore */
        "jge .Lf457e8_00045ad2\n"
        "movl -0x50(%ebp), %ebx\n" /* line 417 | parentNode, nodeNum */
        "movw %di, (%ebx)\n" /* nodeNum */
        "leal 0x3f6702(, %edi, 8), %eax\n" /* line 418 */
        "movl %eax, -0x50(%ebp)\n" /* parentNode */
        "movl %edi, %esi\n" /* level */
        "jmp .Lf457e8_00045991\n"
        ".Lf457e8_00045ad2:\n"
        "movl -0x50(%ebp), %ecx\n" /* line 423 | parentNode */
        "movw %si, (%ecx)\n" /* level */
        "leal scrMemTreeGlob(, %esi, 8), %ebx\n" /* line 424 | nodeNum */
        "movl %ebx, -0x50(%ebp)\n" /* nodeNum, parentNode */
        "jmp .Lf457e8_00045991\n"
        /* } scope */
        /* } scope */
        ".Lf457e8_00045ae7:\n"
        "notl -0x58(%ebp)\n" /* line 673 | lowBit */
        "movl -0x58(%ebp), %ebx\n" /* lowBit, numBytes */
        "andl %ebx, 8(%ebp)\n" /* numBytes, nodeNum */
        "addl $1, -0x54(%ebp)\n" /* line 674 | size */
        "movl $1, -0x58(%ebp)\n" /* line 661 | lowBit */
        "movzbl -0x54(%ebp), %ecx\n" /* size */
        "shll %cl, -0x58(%ebp)\n" /* lowBit */
        "cmpl $0x10, -0x54(%ebp)\n" /* line 665 | size */
        "jne .Lf457e8_0004584c\n"
        "jmp .Lf457e8_000458fa\n"
        /* { scope 2: parentNode, prevScore, oldNodeValue */
        ".Lf457e8_00045b11:\n"
        "leal 0xe(%ebx), %eax\n" /* line 569 | nodeNum */
        "jmp .Lf457e8_0004580b\n"
    );
}

/* line 798 */
__attribute__((naked))
unsigned int MT_FinishForceAlloc(byte *allocBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 798 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl $1, -0x9c(%ebp)\n" /* nodeIndex */
        /* { scope 1: lowBit */
        ".Lf45b1a_00045b30:\n"
        "movl -0x9c(%ebp), %eax\n" /* line 804 | nodeIndex */
        "sarl $3, %eax\n"
        "movl 8(%ebp), %edx\n" /* allocBits */
        "movzbl (%edx, %eax), %eax\n"
        "movl -0x9c(%ebp), %ecx\n" /* nodeIndex */
        "andl $7, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf45b1a_00045c23\n"
        "movl -0x9c(%ebp), %ecx\n" /* line 805 | nodeIndex */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl $0, -0x94(%ebp)\n" /* size */
        "movl $0x80300, %edi\n"
        /* { scope 2: size, size, oldNode */
        ".Lf45b1a_00045b6b:\n"
        "movl $1, %esi\n" /* line 694 | level */
        "movzbl -0x94(%ebp), %ecx\n" /* size */
        "shll %cl, %esi\n" /* level */
        /* { scope 3: parentNode, prevScore, oldNodeValue, parentNode, ... */
        /* { scope 4: num */
        "leal scrMemTreeGlob(%edi), %ebx\n" /* line 383 | level */
        "movl %ebx, -0x90(%ebp)\n" /* level, parentNode */
        "movzwl scrMemTreeGlob(%edi), %eax\n" /* line 384 */
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 386 */
        "je .Lf45b1a_00045bf6\n"
        "cmpl -0x2c(%ebp), %edx\n" /* line 388 */
        "je .Lf45b1a_00045c50\n"
        "movl -0x2c(%ebp), %eax\n" /* line 436 */
        "testl %eax, %eax\n"
        "je .Lf45b1a_00045bf6\n"
        "xorl %ecx, %ecx\n"
        "movl $0x10000, %ebx\n" /* level */
        "jmp .Lf45b1a_00045bd5\n"
        ".Lf45b1a_00045bad:\n"
        "leal scrMemTreeGlob(, %edx, 8), %edx\n" /* line 442 */
        "movl %edx, -0x90(%ebp)\n" /* parentNode */
        "subl %ebx, %ecx\n" /* line 443 | level */
        "movzwl (%edx), %eax\n" /* line 450 */
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 386 */
        "je .Lf45b1a_00045bf6\n"
        ".Lf45b1a_00045bc7:\n"
        "cmpl %edx, -0x2c(%ebp)\n" /* line 388 */
        "je .Lf45b1a_00045c50\n"
        "cmpl -0x2c(%ebp), %ecx\n" /* line 436 */
        "je .Lf45b1a_00045bf6\n"
        ".Lf45b1a_00045bd5:\n"
        "sarl $1, %ebx\n" /* line 439 | level */
        "cmpl -0x2c(%ebp), %ecx\n" /* line 440 */
        "jg .Lf45b1a_00045bad\n"
        "leal 0x3f6702(, %edx, 8), %edx\n" /* line 447 */
        "movl %edx, -0x90(%ebp)\n" /* parentNode */
        "addl %ebx, %ecx\n" /* line 448 | level */
        "movzwl (%edx), %eax\n" /* line 450 */
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 386 */
        "jne .Lf45b1a_00045bc7\n"
        /* } scope */
        /* } scope */
        ".Lf45b1a_00045bf6:\n"
        "cmpl $0x10, -0x94(%ebp)\n" /* line 704 | size */
        "je .Lf45b1a_00045e73\n"
        "movl %esi, %eax\n" /* line 707 | oldNode */
        "notl %eax\n"
        "andl %eax, -0x2c(%ebp)\n"
        "addl $1, -0x94(%ebp)\n" /* line 708 | size */
        "addl $2, %edi\n"
        "jmp .Lf45b1a_00045b6b\n"
        ".Lf45b1a_00045c19:\n"
        "movl %ebx, %edx\n" /* level */
        ".Lf45b1a_00045c1b:\n"
        "movl -0x30(%ebp), %eax\n" /* line 723 */
        "calll MT_AddMemoryNode\n"
        /* } scope */
        ".Lf45b1a_00045c23:\n"
        "addl $1, -0x9c(%ebp)\n" /* line 802 | nodeIndex */
        "cmpl $0x10000, -0x9c(%ebp)\n" /* nodeIndex */
        "jne .Lf45b1a_00045b30\n"
        ".Lf45b1a_00045c3a:\n"
        "movl 8(%ebp), %ebx\n" /* line 809 | allocBits, level */
        "movl %ebx, (%esp)\n" /* level */
        "calll Z_VirtualFreeInternal\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 810 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lowBit */
        /* { scope 2: size, size, oldNode */
        /* { scope 3: parentNode, prevScore, oldNodeValue, parentNode, ... */
        /* { scope 4: num */
        ".Lf45b1a_00045c50:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 390 */
        "movl scrMemTreeGlob(, %edx, 8), %eax\n"
        "movl 0x3f6704(, %edx, 8), %edx\n"
        "movl %eax, -0xa8(%ebp)\n" /* oldNodeValue */
        "movl %edx, -0xa4(%ebp)\n"
        "movl %edx, -0x60(%ebp)\n"
        "shrl $0x10, %eax\n"
        "movw %ax, -0x78(%ebp)\n"
        "movl -0xa8(%ebp), %ecx\n" /* oldNodeValue */
        "movw %cx, -0x62(%ebp)\n"
        "jmp .Lf45b1a_00045d1c\n"
        ".Lf45b1a_00045c86:\n"
        "movzwl -0x78(%ebp), %esi\n" /* line 395 | level */
        "movl %esi, %edi\n" /* level */
        "movl -0x90(%ebp), %ebx\n" /* line 396 | parentNode, level */
        "movw %si, (%ebx)\n" /* level */
        "cmpw $0, -0x78(%ebp)\n" /* line 397 */
        "je .Lf45b1a_00045e49\n"
        "leal 0x3f6702(, %esi, 8), %eax\n" /* line 400 */
        "movl %eax, -0x90(%ebp)\n" /* parentNode */
        ".Lf45b1a_00045cad:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 430 */
        "movl %ecx, -0xa4(%ebp)\n"
        "shll $0x10, %edi\n"
        "andl $0xffff, -0xa8(%ebp)\n" /* oldNodeValue */
        "orl %edi, -0xa8(%ebp)\n" /* oldNodeValue */
        "movzwl -0x62(%ebp), %ebx\n" /* level */
        "movw %bx, -0xa8(%ebp)\n" /* level, oldNodeValue */
        "movl -0xa8(%ebp), %eax\n" /* oldNodeValue */
        "movl -0xa4(%ebp), %edx\n"
        "movl scrMemTreeGlob(, %esi, 8), %ecx\n" /* line 431 */
        "movl 0x3f6704(, %esi, 8), %ebx\n" /* level */
        "movl %ecx, -0xa8(%ebp)\n" /* oldNodeValue */
        "movl %ebx, -0xa4(%ebp)\n" /* level */
        "movl %ebx, -0x60(%ebp)\n" /* level */
        "shrl $0x10, %ecx\n"
        "movw %cx, -0x78(%ebp)\n"
        "movl -0xa8(%ebp), %ebx\n" /* oldNodeValue, level */
        "movw %bx, -0x62(%ebp)\n" /* level */
        "movl %eax, scrMemTreeGlob(, %esi, 8)\n" /* line 432 */
        "movl %edx, 0x3f6704(, %esi, 8)\n"
        ".Lf45b1a_00045d1c:\n"
        "cmpw $0, -0x62(%ebp)\n" /* line 393 */
        "je .Lf45b1a_00045c86\n"
        "cmpw $0, -0x78(%ebp)\n" /* line 402 */
        "jne .Lf45b1a_00045d4f\n"
        "movzwl -0x62(%ebp), %esi\n" /* line 404 | level */
        "movl -0x90(%ebp), %edx\n" /* line 405 | parentNode */
        "movw %si, (%edx)\n" /* level */
        "leal scrMemTreeGlob(, %esi, 8), %ecx\n" /* line 406 */
        "movl %ecx, -0x90(%ebp)\n" /* parentNode */
        "xorl %edi, %edi\n"
        "jmp .Lf45b1a_00045cad\n"
        ".Lf45b1a_00045d4f:\n"
        "movzwl -0x62(%ebp), %esi\n" /* line 410 | level */
        /* { scope 5 */
        /* { scope 6 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %esi, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %edi\n" /* line 276 */
        "movzbl 0x476800(%ecx), %eax\n" /* line 278 */
        "movzbl 0x476800(%edi), %edx\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf45b1a_00045d8f\n"
        "movzbl 0x476700(%edi), %eax\n" /* line 282 */
        "addl %eax, %ecx\n"
        ".Lf45b1a_00045d8f:\n"
        "movl $1, -0xb4(%ebp)\n" /* line 283 */
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x8c(%ebp)\n" /* prevScore */
        /* } scope */
        /* } scope */
        "movzwl -0x78(%ebp), %edi\n" /* line 411 */
        /* { scope 5 */
        /* { scope 6 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %edi, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %eax\n" /* line 276 */
        "movl %eax, -0x5c(%ebp)\n"
        "movzbl 0x476800(%ecx), %edx\n" /* line 278 */
        "movl %edx, -0xbc(%ebp)\n"
        "movzbl 0x476800(%eax), %edx\n"
        "movl -0xbc(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf45b1a_00045dfa\n"
        "movl -0x5c(%ebp), %ebx\n" /* line 282 */
        "movzbl 0x476700(%ebx), %eax\n"
        "addl %eax, %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf45b1a_00045dfa:\n"
        "shll %cl, -0xb4(%ebp)\n" /* line 414 */
        "movl -0xb4(%ebp), %ecx\n"
        "leal (%edx, %ecx), %eax\n"
        "cmpl %eax, -0x8c(%ebp)\n" /* prevScore */
        "jge .Lf45b1a_00045e2e\n"
        "movl -0x90(%ebp), %ebx\n" /* line 417 | parentNode, level */
        "movw %di, (%ebx)\n" /* level */
        "leal 0x3f6702(, %edi, 8), %esi\n" /* line 418 | level */
        "movl %esi, -0x90(%ebp)\n" /* level, parentNode */
        "movl %edi, %esi\n" /* level */
        "jmp .Lf45b1a_00045cad\n"
        ".Lf45b1a_00045e2e:\n"
        "movl -0x90(%ebp), %eax\n" /* line 423 | parentNode */
        "movw %si, (%eax)\n" /* level */
        "leal scrMemTreeGlob(, %esi, 8), %edx\n" /* line 424 */
        "movl %edx, -0x90(%ebp)\n" /* parentNode */
        "jmp .Lf45b1a_00045cad\n"
        /* } scope */
        /* } scope */
        ".Lf45b1a_00045e49:\n"
        "movl -0x94(%ebp), %edx\n" /* line 700 | size */
        "movl -0x2c(%ebp), %eax\n"
        "calll MT_AddMemoryNode\n"
        /* } scope */
        "addl $1, -0x9c(%ebp)\n" /* line 802 | nodeIndex */
        "cmpl $0x10000, -0x9c(%ebp)\n" /* nodeIndex */
        "jne .Lf45b1a_00045b30\n"
        "jmp .Lf45b1a_00045c3a\n"
        /* { scope 2: size, size, oldNode */
        ".Lf45b1a_00045e73:\n"
        "movl -0x9c(%ebp), %ecx\n" /* line 691 | nodeIndex */
        "movl %ecx, -0x30(%ebp)\n"
        "movl $1, -0x98(%ebp)\n" /* lowBit */
        "movl $0, -0x88(%ebp)\n" /* size */
        ".Lf45b1a_00045e90:\n"
        "movl -0x98(%ebp), %edx\n" /* line 721 | lowBit */
        "xorl -0x30(%ebp), %edx\n"
        /* { scope 3: parentNode, prevScore, oldNodeValue, parentNode, ... */
        /* { scope 4: num */
        "movl -0x88(%ebp), %ebx\n" /* line 383 | size, level */
        "leal 0x80300(%ebx, %ebx), %eax\n" /* level */
        "leal scrMemTreeGlob(%eax), %esi\n" /* level */
        "movl %esi, -0x80(%ebp)\n" /* level, parentNode */
        "movzwl scrMemTreeGlob(%eax), %eax\n" /* line 384 */
        "movzwl %ax, %ecx\n"
        "testw %ax, %ax\n" /* line 386 */
        "je .Lf45b1a_00045c19\n"
        "cmpl %ecx, %edx\n" /* line 388 */
        "je .Lf45b1a_00045f1a\n"
        "testl %edx, %edx\n" /* line 436 */
        "je .Lf45b1a_00045f0f\n"
        "xorl %ebx, %ebx\n" /* level */
        "movl $0x10000, %esi\n" /* level */
        "jmp .Lf45b1a_00045ef2\n"
        ".Lf45b1a_00045ed3:\n"
        "leal scrMemTreeGlob(, %ecx, 8), %ecx\n" /* line 442 */
        "movl %ecx, -0x80(%ebp)\n" /* parentNode */
        "subl %esi, %ebx\n" /* line 443 | level */
        "movzwl (%ecx), %eax\n" /* line 450 */
        "movzwl %ax, %ecx\n"
        "testw %ax, %ax\n" /* line 386 */
        "je .Lf45b1a_00045f0f\n"
        ".Lf45b1a_00045eea:\n"
        "cmpl %ecx, %edx\n" /* line 388 */
        "je .Lf45b1a_00045f1a\n"
        "cmpl %edx, %ebx\n" /* line 436 | level */
        "je .Lf45b1a_00045f0f\n"
        ".Lf45b1a_00045ef2:\n"
        "sarl $1, %esi\n" /* line 439 | level */
        "cmpl %edx, %ebx\n" /* line 440 | level */
        "jg .Lf45b1a_00045ed3\n"
        "leal 0x3f6702(, %ecx, 8), %ecx\n" /* line 447 */
        "movl %ecx, -0x80(%ebp)\n" /* parentNode */
        "addl %esi, %ebx\n" /* line 448 | level */
        "movzwl (%ecx), %eax\n" /* line 450 */
        "movzwl %ax, %ecx\n"
        "testw %ax, %ax\n" /* line 386 */
        "jne .Lf45b1a_00045eea\n"
        ".Lf45b1a_00045f0f:\n"
        "movl -0x88(%ebp), %edx\n" /* size */
        "jmp .Lf45b1a_00045c1b\n"
        ".Lf45b1a_00045f1a:\n"
        "movl scrMemTreeGlob(, %edx, 8), %ecx\n" /* line 390 */
        "movl 0x3f6704(, %edx, 8), %ebx\n" /* level */
        "movl %ecx, -0xb0(%ebp)\n" /* oldNodeValue */
        "movl %ebx, -0xac(%ebp)\n" /* level */
        "movl %ebx, -0x38(%ebp)\n" /* level */
        "shrl $0x10, %ecx\n"
        "movw %cx, -0x58(%ebp)\n"
        "movl -0xb0(%ebp), %ebx\n" /* oldNodeValue, level */
        "movw %bx, -0x3a(%ebp)\n" /* level */
        "jmp .Lf45b1a_00045ff5\n"
        ".Lf45b1a_00045f4d:\n"
        "movzwl -0x58(%ebp), %esi\n" /* line 395 | level */
        "movl %esi, -0x84(%ebp)\n" /* level, oldNode */
        "movl %esi, %edi\n" /* level */
        "movl -0x80(%ebp), %eax\n" /* line 396 | parentNode */
        "movw %si, (%eax)\n" /* level */
        "cmpw $0, -0x58(%ebp)\n" /* line 397 */
        "je .Lf45b1a_0004611f\n"
        "movl -0x84(%ebp), %edx\n" /* line 400 | oldNode */
        "leal 0x3f6702(, %edx, 8), %edx\n"
        "movl %edx, -0x80(%ebp)\n" /* parentNode */
        ".Lf45b1a_00045f7a:\n"
        "movl -0x38(%ebp), %ebx\n" /* line 430 | level */
        "movl %ebx, -0xac(%ebp)\n" /* level */
        "shll $0x10, %edi\n"
        "andl $0xffff, -0xb0(%ebp)\n" /* oldNodeValue */
        "orl %edi, -0xb0(%ebp)\n" /* oldNodeValue */
        "movzwl -0x3a(%ebp), %esi\n" /* level */
        "movw %si, -0xb0(%ebp)\n" /* level, oldNodeValue */
        "movl -0xb0(%ebp), %eax\n" /* oldNodeValue */
        "movl -0xac(%ebp), %edx\n"
        "movl -0x84(%ebp), %ebx\n" /* line 431 | oldNode, level */
        "movl scrMemTreeGlob(, %ebx, 8), %ecx\n"
        "movl 0x3f6704(, %ebx, 8), %ebx\n" /* level */
        "movl %ecx, -0xb0(%ebp)\n" /* oldNodeValue */
        "movl %ebx, -0xac(%ebp)\n" /* level */
        "movl %ebx, -0x38(%ebp)\n" /* level */
        "shrl $0x10, %ecx\n"
        "movw %cx, -0x58(%ebp)\n"
        "movl -0xb0(%ebp), %esi\n" /* oldNodeValue, level */
        "movw %si, -0x3a(%ebp)\n" /* level */
        "movl -0x84(%ebp), %ecx\n" /* line 432 | oldNode */
        "movl %eax, scrMemTreeGlob(, %ecx, 8)\n"
        "movl %edx, 0x3f6704(, %ecx, 8)\n"
        ".Lf45b1a_00045ff5:\n"
        "cmpw $0, -0x3a(%ebp)\n" /* line 393 */
        "je .Lf45b1a_00045f4d\n"
        "cmpw $0, -0x58(%ebp)\n" /* line 402 */
        "jne .Lf45b1a_0004602e\n"
        "movzwl -0x3a(%ebp), %ecx\n" /* line 404 */
        "movl %ecx, -0x84(%ebp)\n" /* oldNode */
        "movl -0x80(%ebp), %ebx\n" /* line 405 | parentNode, level */
        "movw %cx, (%ebx)\n" /* level */
        "movl -0x84(%ebp), %esi\n" /* line 406 | oldNode, level */
        "leal scrMemTreeGlob(, %esi, 8), %esi\n" /* level */
        "movl %esi, -0x80(%ebp)\n" /* level, parentNode */
        "xorl %edi, %edi\n"
        "jmp .Lf45b1a_00045f7a\n"
        ".Lf45b1a_0004602e:\n"
        "movzwl -0x3a(%ebp), %eax\n" /* line 410 */
        "movl %eax, -0x84(%ebp)\n" /* oldNode */
        /* { scope 5 */
        /* { scope 6 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %eax, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %edi\n" /* line 276 */
        "movzbl 0x476800(%ecx), %eax\n" /* line 278 */
        "movzbl 0x476800(%edi), %edx\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf45b1a_00046074\n"
        "movzbl 0x476700(%edi), %eax\n" /* line 282 */
        "addl %eax, %ecx\n"
        ".Lf45b1a_00046074:\n"
        "movl $1, -0xb8(%ebp)\n" /* line 283 */
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x7c(%ebp)\n" /* prevScore */
        /* } scope */
        /* } scope */
        "movzwl -0x58(%ebp), %edi\n" /* line 411 */
        /* { scope 5 */
        /* { scope 6 */
        "movl $0x10000, %ebx\n" /* line 268 */
        "subl %edi, %ebx\n"
        "movl %ebx, -0x1c(%ebp)\n" /* num */
        "movzbl -0x1c(%ebp), %ecx\n" /* line 275 | num */
        "movzbl -0x1b(%ebp), %edx\n" /* line 276 */
        "movl %edx, -0x34(%ebp)\n"
        "movzbl 0x476800(%ecx), %eax\n" /* line 278 */
        "movl %edx, %esi\n"
        "movzbl 0x476800(%edx), %edx\n"
        "addl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movzbl 0x476700(%ecx), %ecx\n" /* line 280 */
        "cmpb $0, -0x1c(%ebp)\n" /* line 281 | num */
        "jne .Lf45b1a_000460cf\n"
        "movzbl 0x476700(%esi), %eax\n" /* line 282 */
        "addl %eax, %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf45b1a_000460cf:\n"
        "shll %cl, -0xb8(%ebp)\n" /* line 414 */
        "movl -0xb8(%ebp), %ecx\n"
        "leal (%edx, %ecx), %eax\n"
        "cmpl %eax, -0x7c(%ebp)\n" /* prevScore */
        "jge .Lf45b1a_000460fe\n"
        "movl -0x80(%ebp), %ebx\n" /* line 417 | parentNode, level */
        "movw %di, (%ebx)\n" /* level */
        "leal 0x3f6702(, %edi, 8), %esi\n" /* line 418 | level */
        "movl %esi, -0x80(%ebp)\n" /* level, parentNode */
        "movl %edi, -0x84(%ebp)\n" /* oldNode */
        "jmp .Lf45b1a_00045f7a\n"
        ".Lf45b1a_000460fe:\n"
        "movl -0x84(%ebp), %edx\n" /* line 423 | oldNode */
        "movl -0x80(%ebp), %eax\n" /* parentNode */
        "movw %dx, (%eax)\n"
        "movl -0x84(%ebp), %ecx\n" /* line 424 | oldNode */
        "leal scrMemTreeGlob(, %ecx, 8), %ecx\n"
        "movl %ecx, -0x80(%ebp)\n" /* parentNode */
        "jmp .Lf45b1a_00045f7a\n"
        /* } scope */
        /* } scope */
        ".Lf45b1a_0004611f:\n"
        "notl -0x98(%ebp)\n" /* line 727 | lowBit */
        "movl -0x98(%ebp), %esi\n" /* lowBit, oldNode */
        "andl %esi, -0x30(%ebp)\n" /* oldNode */
        "addl $1, -0x88(%ebp)\n" /* line 728 | size */
        "movl $1, -0x98(%ebp)\n" /* line 717 | lowBit */
        "movzbl -0x88(%ebp), %ecx\n" /* size */
        "shll %cl, -0x98(%ebp)\n" /* lowBit */
        "cmpl $0x10, -0x88(%ebp)\n" /* line 721 | size */
        "jne .Lf45b1a_00045e90\n"
        "movl -0x88(%ebp), %edx\n" /* size */
        "jmp .Lf45b1a_00045c1b\n"
    );
}

