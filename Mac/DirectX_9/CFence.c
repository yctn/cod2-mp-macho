/* ASM dump from: CFence.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CFence.cpp */

#include "common_types.h"
#include "imports.h"

extern const const GLuint * CFence_sUnusedFenceIDs; /* 0x0 */

void CFence_CFence(const CFence * _this, const void * Start, UINT32 SizeInBytes, UINT32 FrameCount);
void CFence_Shutdown(void);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__D__ZN6CFence15sUnusedFenceIDsE(void); /* global destructors keyed to CFence_sUnusedFenceIDs */
static void GLOBAL__I__ZN6CFence15sUnusedFenceIDsE(void); /* global constructors keyed to CFence_sUnusedFenceIDs */
void ZNSt6vectorImSaImEE5eraseEN9__gnu_cxx17__normal_iteratorIPmS1_EES5_(void); /* std_vector<unsigned long, std_allocator<unsigned long> >_erase */

/* line 19 */
__attribute__((naked))
void CFence_CFence(const CFence * _this, const void * Start, UINT32 SizeInBytes, UINT32 FrameCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 19 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* line 22 | Start */
        "movl %eax, 4(%edi)\n" /* this */
        "movl 0x10(%ebp), %eax\n" /* SizeInBytes */
        "movl %eax, 8(%edi)\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* FrameCount */
        "movl %eax, 0xc(%edi)\n" /* this */
        /* { scope 1: NewFenceID */
        "movl 0xff2d04, %edx\n" /* line 361 */
        "movl %edx, %eax\n" /* line 28 */
        "subl __ZN6CFence15sUnusedFenceIDsE, %eax\n"
        "sarl $2, %eax\n"
        "testl %eax, %eax\n"
        "je .Lf2033c_0002038b\n"
        "movl -4(%edx), %eax\n" /* line 58 | NewFreeID */
        "movl %eax, (%edi)\n" /* line 59 | this */
        "movl %eax, (%esp)\n" /* line 61 */
        "calll glSetFenceAPPLE\n"
        "subl $4, 0xff2d04\n" /* line 625 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 74 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: NewFenceID */
        ".Lf2033c_0002038b:\n"
        "movl $0x100, %ebx\n" /* line 28 */
        "leal -0x1c(%ebp), %esi\n" /* NewFenceID */
        "jmp .Lf2033c_000203b2\n"
        /* { scope 2 */
        ".Lf2033c_00020395:\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf2033c_000203a4\n"
        "movl -0x1c(%ebp), %eax\n" /* NewFenceID */
        "movl %eax, (%edx)\n"
        "movl 0xff2d04, %edx\n"
        ".Lf2033c_000203a4:\n"
        "addl $4, %edx\n" /* line 607 */
        "movl %edx, 0xff2d04\n"
        /* } scope */
        "subl $1, %ebx\n" /* line 32 */
        "je .Lf2033c_000203e9\n"
        /* { scope 2 */
        ".Lf2033c_000203b2:\n"
        "movl %esi, 4(%esp)\n" /* line 36 */
        "movl $1, (%esp)\n"
        "calll glGenFencesAPPLE\n"
        "movl 0xff2d04, %edx\n" /* line 604 */
        "cmpl 0xff2d08, %edx\n"
        "jne .Lf2033c_00020395\n"
        "movl %esi, 8(%esp)\n" /* line 610 */
        "movl %edx, 4(%esp)\n"
        "movl $__ZN6CFence15sUnusedFenceIDsE, (%esp)\n"
        "calll ZNSt6vectorImSaImEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPmS1_EERKm\n"
        /* } scope */
        "subl $1, %ebx\n" /* line 32 */
        "jne .Lf2033c_000203b2\n"
        ".Lf2033c_000203e9:\n"
        "movl 0xff2d04, %edx\n"
        "movl -4(%edx), %eax\n" /* line 58 | NewFreeID */
        "movl %eax, (%edi)\n" /* line 59 | this */
        "movl %eax, (%esp)\n" /* line 61 */
        "calll glSetFenceAPPLE\n"
        "subl $4, 0xff2d04\n" /* line 625 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 74 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 79 */
__attribute__((naked))
void CFence_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 79 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl __ZN6CFence15sUnusedFenceIDsE, %edx\n" /* line 334 */
        "movl %edx, %ebx\n" /* line 84 */
        "movl 0xff2d04, %eax\n" /* line 603 */
        "cmpl %eax, %edx\n" /* line 85 */
        "je .Lf2040c_0002044f\n"
        "leal -0xc(%ebp), %esi\n" /* FenceID */
        /* { scope 1 */
        ".Lf2040c_00020428:\n"
        "movl (%ebx), %eax\n" /* line 87 */
        "movl %eax, -0xc(%ebp)\n" /* FenceID */
        "movl %esi, 4(%esp)\n" /* line 89 */
        "movl $1, (%esp)\n"
        "calll glDeleteFencesAPPLE\n"
        "addl $4, %ebx\n" /* line 623 */
        /* } scope */
        "movl 0xff2d04, %eax\n" /* line 603 */
        "cmpl %eax, %ebx\n" /* line 85 */
        "jne .Lf2040c_00020428\n"
        "movl __ZN6CFence15sUnusedFenceIDsE, %edx\n"
        ".Lf2040c_0002044f:\n"
        "movl %eax, 8(%esp)\n" /* line 749 */
        "movl %edx, 4(%esp)\n"
        "movl $__ZN6CFence15sUnusedFenceIDsE, (%esp)\n"
        "calll ZNSt6vectorImSaImEE5eraseEN9__gnu_cxx17__normal_iteratorIPmS1_EES5_\n"
        "addl $0x20, %esp\n" /* line 103 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 103 */
static __attribute__((naked))
void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 103 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpl $0xffff, %edx\n" /* line 15 */
        "je .Lf2046a_0002047a\n"
        ".Lf2046a_00020478:\n"
        "leave\n" /* line 103 */
        "retl\n"
        ".Lf2046a_0002047a:\n"
        "cmpl $1, %eax\n" /* line 15 */
        "je .Lf2046a_000204aa\n"
        "testl %eax, %eax\n"
        "jne .Lf2046a_00020478\n"
        "movl 0xff2d04, %edx\n" /* line 273 | __priority */
        "movl __ZN6CFence15sUnusedFenceIDsE, %ecx\n"
        "movl %ecx, %eax\n" /* __initialize_p */
        "cmpl %ecx, %edx\n" /* line 173 | __priority */
        "je .Lf2046a_0002049c\n"
        ".Lf2046a_00020495:\n"
        "addl $4, %eax\n" /* __initialize_p */
        "cmpl %eax, %edx\n" /* __initialize_p, __priority */
        "jne .Lf2046a_00020495\n"
        ".Lf2046a_0002049c:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2046a_00020478\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "leave\n" /* line 103 */
        "retl\n"
        ".Lf2046a_000204aa:\n"
        "movl $0, __ZN6CFence15sUnusedFenceIDsE\n" /* line 85 */
        "movl $0, 0xff2d04\n"
        "movl $0, 0xff2d08\n"
        "leave\n" /* line 103 */
        "retl\n"
    );
}

/* line 105 */
static __attribute__((naked))
void GLOBAL__D__ZN6CFence15sUnusedFenceIDsE(void) /* global destructors keyed to CFence_sUnusedFenceIDs */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 105 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 104 */
static __attribute__((naked))
void GLOBAL__I__ZN6CFence15sUnusedFenceIDsE(void) /* global constructors keyed to CFence_sUnusedFenceIDs */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 122 */
__attribute__((naked))
void ZNSt6vectorImSaImEE5eraseEN9__gnu_cxx17__normal_iteratorIPmS1_EES5_(void) /* std_vector<unsigned long, std_allocator<unsigned long> >_erase */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* __first */
        "movl 0x10(%ebp), %esi\n" /* __last */
        "movl 8(%ebp), %eax\n" /* line 352 | this */
        "movl 4(%eax), %ebx\n"
        /* { scope 1 */
        "subl %esi, %ebx\n" /* line 300 | __last */
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* __last */
        "movl %edi, (%esp)\n" /* __first */
        "calll memmove\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 352 | this */
        "movl 4(%eax), %edx\n"
        "leal (%edi, %ebx), %eax\n" /* __first */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2be0a4_002be0df\n"
        ".Lf2be0a4_002be0d8:\n"
        "addl $4, %eax\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 173 */
        "jne .Lf2be0a4_002be0d8\n"
        ".Lf2be0a4_002be0df:\n"
        "subl %edi, %esi\n" /* line 126 | __first, __last */
        "andl $0xfffffffc, %esi\n" /* __last */
        "subl %esi, %edx\n" /* __last */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, 4(%eax)\n"
        "movl %edi, %eax\n" /* line 127 | __first */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

