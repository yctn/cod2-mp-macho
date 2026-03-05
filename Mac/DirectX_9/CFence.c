/* ASM dump from: CFence.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CFence.cpp */

#include "common_types.h"
#include "imports.h"

typedef struct {
    GLuint *begin;
    GLuint *end;
    GLuint *capacity;
} CFenceUnusedIdsVector;

typedef struct {
    GLuint id;
    const void *start;
    UINT32 sizeInBytes;
    UINT32 frameCount;
} CFenceImpl;

extern CFenceUnusedIdsVector CFence_sUnusedFenceIDs __asm__("__ZN6CFence15sUnusedFenceIDsE"); /* 0x0 */

void *__Znam(unsigned int size);
void __ZdaPv(void *ptr);

static void CFence_EnsureUnusedIdCapacity(unsigned int additional)
{
    unsigned int size;
    unsigned int capacity;
    unsigned int newCapacity;
    GLuint *newIds;

    size = (unsigned int)(CFence_sUnusedFenceIDs.end - CFence_sUnusedFenceIDs.begin);
    capacity = (unsigned int)(CFence_sUnusedFenceIDs.capacity - CFence_sUnusedFenceIDs.begin);

    if (capacity - size >= additional) {
        return;
    }

    newCapacity = capacity ? capacity : 256;
    while (newCapacity < size + additional) {
        newCapacity *= 2;
    }

    newIds = (GLuint *)__Znam(newCapacity * sizeof(GLuint));
    if (CFence_sUnusedFenceIDs.begin) {
        memcpy(newIds, CFence_sUnusedFenceIDs.begin, size * sizeof(GLuint));
        __ZdaPv(CFence_sUnusedFenceIDs.begin);
    }

    CFence_sUnusedFenceIDs.begin = newIds;
    CFence_sUnusedFenceIDs.end = newIds + size;
    CFence_sUnusedFenceIDs.capacity = newIds + newCapacity;
}

void CFence_CFence(const CFence * _this, const void * Start, UINT32 SizeInBytes, UINT32 FrameCount);
void CFence_Shutdown(void);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__D__ZN6CFence15sUnusedFenceIDsE(void); /* global destructors keyed to CFence_sUnusedFenceIDs */
static void GLOBAL__I__ZN6CFence15sUnusedFenceIDsE(void); /* global constructors keyed to CFence_sUnusedFenceIDs */
void ZNSt6vectorImSaImEE5eraseEN9__gnu_cxx17__normal_iteratorIPmS1_EES5_(void); /* std_vector<unsigned long, std_allocator<unsigned long> >_erase */

/* line 19 */
void CFence_CFence(const CFence * _this, const void * Start, UINT32 SizeInBytes, UINT32 FrameCount)
{
    CFenceImpl *fence;
    unsigned int i;

    fence = (CFenceImpl *)_this;
    fence->start = Start;
    fence->sizeInBytes = SizeInBytes;
    fence->frameCount = FrameCount;

    if (CFence_sUnusedFenceIDs.end == CFence_sUnusedFenceIDs.begin) {
        CFence_EnsureUnusedIdCapacity(256);

        for (i = 0; i < 256; ++i) {
            GLuint newFenceId;

            glGenFencesAPPLE(1, &newFenceId);
            *CFence_sUnusedFenceIDs.end++ = newFenceId;
        }
    }

    fence->id = *--CFence_sUnusedFenceIDs.end;
    glSetFenceAPPLE(fence->id);
}

/* line 79 */
void CFence_Shutdown(void)
{
    GLuint *id;

    for (id = CFence_sUnusedFenceIDs.begin; id != CFence_sUnusedFenceIDs.end; ++id) {
        glDeleteFencesAPPLE(1, id);
    }

    if (CFence_sUnusedFenceIDs.begin) {
        __ZdaPv(CFence_sUnusedFenceIDs.begin);
    }

    CFence_sUnusedFenceIDs.begin = NULL;
    CFence_sUnusedFenceIDs.end = NULL;
    CFence_sUnusedFenceIDs.capacity = NULL;
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
