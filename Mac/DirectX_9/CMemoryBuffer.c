/* ASM dump from: CMemoryBuffer.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CMemoryBuffer.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CMemoryBuffer.h"
 */

extern int CMemoryBuffer_sDelayedFreeRequests; /* 0x0 */
extern UINT32 CMemoryBuffer_sMemoryDesignatedForDelayedFree; /* 0x0 */

void CMemoryBuffer_CMemoryBuffer(const CMemoryBuffer * _this, UINT32 Length);
void CMemoryBuffer_Recreate(const CMemoryBuffer * _this);
void ZN13CMemoryBufferD1Ev(void); /* CMemoryBuffer_~CMemoryBuffer */
void ZN13CMemoryBufferD0Ev(void); /* CMemoryBuffer_~CMemoryBuffer */
void CMemoryBuffer_Resize(const CMemoryBuffer * _this, UINT32 Length);
void CMemoryBuffer_FreeLater(const CMemoryBuffer * _this, UINT32 Frames);
void CMemoryBuffer_Update(void);
void CMemoryBuffer_Reset(void);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__D__ZN13CMemoryBuffer20sDelayedFreeRequestsE(void); /* global destructors keyed to CMemoryBuffer_sDelayedFreeRequests */
static void GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(void); /* global constructors keyed to CMemoryBuffer_sDelayedFreeRequests */
void ZNSt10_List_baseIN13CMemoryBuffer11FreeRequestESaIS1_EE8_M_clearEv(void); /* std__List_base<CMemoryBuffer_FreeRequest, std_allocator<CMemoryBuffer_FreeRequest> >__M_clear */

/* line 33 */
__attribute__((naked))
void CMemoryBuffer_CMemoryBuffer(const CMemoryBuffer * _this, UINT32 Length)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 33 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* Length */
        "movl $0x32fd28, (%esi)\n" /* line 36 | this */
        "testl %ebx, %ebx\n" /* Length */
        "jne .Lf204ee_00020528\n"
        "xorl %edx, %edx\n"
        "movl %edx, 4(%esi)\n" /* this */
        "movl %ebx, 0xc(%esi)\n" /* Length, this */
        "xorl %eax, %eax\n"
        "testl %ebx, %ebx\n" /* Length */
        "sete %al\n"
        "movl %eax, 0x10(%esi)\n" /* this */
        "leal 0x1f(%edx), %eax\n" /* line 43 */
        "andl $0xffffffe0, %eax\n"
        "movl %eax, 8(%esi)\n" /* this */
        "addl $0x10, %esp\n" /* line 44 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf204ee_00020528:\n"
        "leal 0x1f(%ebx), %eax\n" /* line 36 | Length */
        "andl $0xffffffe0, %eax\n"
        "addl $0x1f, %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, %edx\n"
        "movl %edx, 4(%esi)\n" /* this */
        "movl %ebx, 0xc(%esi)\n" /* Length, this */
        "xorl %eax, %eax\n"
        "testl %ebx, %ebx\n" /* Length */
        "sete %al\n"
        "movl %eax, 0x10(%esi)\n" /* this */
        "leal 0x1f(%edx), %eax\n" /* line 43 */
        "andl $0xffffffe0, %eax\n"
        "movl %eax, 8(%esi)\n" /* this */
        "addl $0x10, %esp\n" /* line 44 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 71 */
__attribute__((naked))
void CMemoryBuffer_Recreate(const CMemoryBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebx), %eax\n" /* line 76 | this */
        "addl $0x1f, %eax\n"
        "andl $0xffffffe0, %eax\n"
        "addl $0x1f, %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, 4(%ebx)\n" /* this */
        "addl $0x1f, %eax\n" /* line 77 */
        "andl $0xffffffe0, %eax\n"
        "movl %eax, 8(%ebx)\n" /* this */
        "movl $0, 0x10(%ebx)\n" /* line 78 | this */
        "addl $0x14, %esp\n" /* line 79 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 48 */
__attribute__((naked))
void ZN13CMemoryBufferD1Ev(void) /* CMemoryBuffer_~CMemoryBuffer */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32fd28, (%ebx)\n" /* this */
        "movl 0x10(%ebx), %ecx\n" /* line 24 */
        "testl %ecx, %ecx\n"
        "jne .Lf20596_000205bc\n"
        "movl 4(%ebx), %eax\n" /* line 26 */
        "testl %eax, %eax\n"
        "je .Lf20596_000205bc\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lf20596_000205bc:\n"
        "movl $0, 8(%ebx)\n" /* line 28 */
        "movl $0, 4(%ebx)\n"
        "addl $0x14, %esp\n" /* line 51 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 48 */
__attribute__((naked))
void ZN13CMemoryBufferD0Ev(void) /* CMemoryBuffer_~CMemoryBuffer */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x32fd28, (%ebx)\n" /* this */
        "movl 0x10(%ebx), %eax\n" /* line 24 */
        "testl %eax, %eax\n"
        "jne .Lf205d0_000205f6\n"
        "movl 4(%ebx), %eax\n" /* line 26 */
        "testl %eax, %eax\n"
        "je .Lf205d0_000205f6\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lf205d0_000205f6:\n"
        "movl $0, 8(%ebx)\n" /* line 28 */
        "movl $0, 4(%ebx)\n"
        "movl %ebx, 8(%ebp)\n" /* line 51 | this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 56 */
__attribute__((naked))
void CMemoryBuffer_Resize(const CMemoryBuffer * _this, UINT32 Length)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 56 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* Length */
        "movl 0x10(%ebx), %eax\n" /* line 24 */
        "testl %eax, %eax\n"
        "jne .Lf20612_00020636\n"
        "movl 4(%ebx), %eax\n" /* line 26 */
        "testl %eax, %eax\n"
        "je .Lf20612_00020636\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lf20612_00020636:\n"
        "movl $0, 8(%ebx)\n" /* line 28 */
        "movl $0, 4(%ebx)\n"
        "leal 0x1f(%esi), %eax\n" /* line 62 | Length */
        "andl $0xffffffe0, %eax\n"
        "addl $0x1f, %eax\n"
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, 4(%ebx)\n" /* this */
        "addl $0x1f, %eax\n" /* line 63 */
        "andl $0xffffffe0, %eax\n"
        "movl %eax, 8(%ebx)\n" /* this */
        "movl %esi, 0xc(%ebx)\n" /* line 64 | Length, this */
        "movl $0, 0x10(%ebx)\n" /* line 65 | this */
        "addl $0x10, %esp\n" /* line 66 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 84 */
__attribute__((naked))
void CMemoryBuffer_FreeLater(const CMemoryBuffer * _this, UINT32 Frames)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 84 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x10(%ebx), %eax\n" /* line 87 | this */
        "testl %eax, %eax\n"
        "je .Lf20672_0002068d\n"
        "addl $0x1c, %esp\n" /* line 99 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20672_0002068d:\n"
        "movl 0xc(%ebx), %edi\n" /* line 61 */
        "movl 4(%ebx), %esi\n" /* line 89 | this */
        /* { scope 1 */
        "movl $0x14, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %eax, %edx\n" /* line 104 */
        "addl $8, %edx\n"
        "je .Lf20672_000206b2\n"
        "movl 0xc(%ebp), %ecx\n" /* Frames */
        "movl %ecx, 8(%edx)\n"
        "movl %edi, 4(%edx)\n"
        "movl %esi, 8(%eax)\n"
        ".Lf20672_000206b2:\n"
        "movl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, 4(%esp)\n" /* line 1152 */
        "movl %eax, (%esp)\n"
        "calll __ZNSt15_List_node_base4hookEPS_\n"
        /* } scope */
        "movl 0xc(%ebx), %eax\n" /* line 92 | this */
        "addl %eax, __ZN13CMemoryBuffer31sMemoryDesignatedForDelayedFreeE\n"
        "movl $0, 8(%ebx)\n" /* line 96 | this */
        "movl $0, 4(%ebx)\n" /* this */
        "movl $1, 0x10(%ebx)\n" /* line 97 | this */
        "addl $0x1c, %esp\n" /* line 99 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 104 */
__attribute__((naked))
void CMemoryBuffer_Update(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl __ZN13CMemoryBuffer20sDelayedFreeRequestsE, %esi\n" /* line 580 */
        ".Lf206e8_000206f6:\n"
        "cmpl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, %esi\n" /* line 110 */
        "je .Lf206e8_00020740\n"
        /* { scope 1 */
        ".Lf206e8_000206fe:\n"
        "leal 8(%esi), %ebx\n" /* line 131 | fr */
        "movl 8(%ebx), %eax\n" /* line 114 | fr */
        "testl %eax, %eax\n"
        "jne .Lf206e8_00020747\n"
        "movl 8(%esi), %eax\n" /* line 117 */
        "testl %eax, %eax\n"
        "je .Lf206e8_00020717\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lf206e8_00020717:\n"
        "movl __ZN13CMemoryBuffer31sMemoryDesignatedForDelayedFreeE, %eax\n" /* line 118 */
        "subl 4(%ebx), %eax\n" /* fr */
        "movl %eax, __ZN13CMemoryBuffer31sMemoryDesignatedForDelayedFreeE\n"
        "movl (%esi), %ebx\n" /* line 97 */
        "movl %esi, (%esp)\n" /* line 1159 */
        "calll __ZNSt15_List_node_base6unhookEv\n"
        "movl %esi, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "movl %ebx, %esi\n" /* line 120 | fr */
        /* } scope */
        "cmpl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, %esi\n" /* line 110 */
        "jne .Lf206e8_000206fe\n"
        ".Lf206e8_00020740:\n"
        "addl $0x10, %esp\n" /* line 128 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf206e8_00020747:\n"
        "subl $1, %eax\n" /* line 124 */
        "movl %eax, 8(%ebx)\n" /* fr */
        "movl (%esi), %esi\n" /* line 140 */
        "jmp .Lf206e8_000206f6\n"
    );
}

/* line 133 */
__attribute__((naked))
void CMemoryBuffer_Reset(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 133 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "calll glFinish\n" /* line 138 */
        "movl __ZN13CMemoryBuffer20sDelayedFreeRequestsE, %edx\n" /* line 580 */
        "cmpl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, %edx\n" /* line 140 */
        "je .Lf20752_00020798\n"
        "movl %edx, %ebx\n"
        "jmp .Lf20752_00020772\n"
        ".Lf20752_00020770:\n"
        "movl %ebx, %edx\n"
        ".Lf20752_00020772:\n"
        "movl __ZN13CMemoryBuffer31sMemoryDesignatedForDelayedFreeE, %eax\n" /* line 142 */
        "subl 0xc(%edx), %eax\n"
        "movl %eax, __ZN13CMemoryBuffer31sMemoryDesignatedForDelayedFreeE\n"
        "movl 8(%edx), %eax\n" /* line 143 */
        "testl %eax, %eax\n"
        "je .Lf20752_0002078e\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lf20752_0002078e:\n"
        "movl (%ebx), %ebx\n" /* line 140 */
        "cmpl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, %ebx\n"
        "jne .Lf20752_00020770\n"
        ".Lf20752_00020798:\n"
        "movl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, (%esp)\n" /* line 912 */
        "calll ZNSt10_List_baseIN13CMemoryBuffer11FreeRequestESaIS1_EE8_M_clearEv\n"
        "movl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, __ZN13CMemoryBuffer20sDelayedFreeRequestsE\n" /* line 340 */
        "movl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, 0xff2d84\n" /* line 341 */
        "addl $0x14, %esp\n" /* line 148 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 148 */
static __attribute__((naked))
void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 148 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpl $0xffff, %edx\n" /* line 15 */
        "je .Lf207be_000207ce\n"
        ".Lf207be_000207cc:\n"
        "leave\n" /* line 148 */
        "retl\n"
        ".Lf207be_000207ce:\n"
        "cmpl $1, %eax\n" /* line 15 */
        "je .Lf207be_000207e5\n"
        "testl %eax, %eax\n"
        "jne .Lf207be_000207cc\n"
        "movl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, (%esp)\n" /* line 332 */
        "calll ZNSt10_List_baseIN13CMemoryBuffer11FreeRequestESaIS1_EE8_M_clearEv\n"
        "leave\n" /* line 148 */
        "retl\n"
        ".Lf207be_000207e5:\n"
        "movl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, __ZN13CMemoryBuffer20sDelayedFreeRequestsE\n" /* line 340 */
        "movl $__ZN13CMemoryBuffer20sDelayedFreeRequestsE, 0xff2d84\n" /* line 341 */
        "leave\n" /* line 148 */
        "retl\n"
    );
}

/* line 150 */
static __attribute__((naked))
void GLOBAL__D__ZN13CMemoryBuffer20sDelayedFreeRequestsE(void) /* global destructors keyed to CMemoryBuffer_sDelayedFreeRequests */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 150 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 149 */
static __attribute__((naked))
void GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(void) /* global constructors keyed to CMemoryBuffer_sDelayedFreeRequests */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 149 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 69 */
__attribute__((naked))
void ZNSt10_List_baseIN13CMemoryBuffer11FreeRequestESaIS1_EE8_M_clearEv(void) /* std__List_base<CMemoryBuffer_FreeRequest, std_allocator<CMemoryBuffer_FreeRequest> >__M_clear */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 72 | this, __cur */
        "cmpl %eax, %esi\n" /* line 73 | this */
        "jne .Lf2be0f6_002be10b\n"
        "jmp .Lf2be0f6_002be119\n"
        ".Lf2be0f6_002be109:\n"
        "movl %ebx, %eax\n"
        ".Lf2be0f6_002be10b:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "cmpl %ebx, %esi\n" /* line 73 | this */
        "jne .Lf2be0f6_002be109\n"
        /* } scope */
        ".Lf2be0f6_002be119:\n"
        "addl $0x10, %esp\n" /* line 78 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

