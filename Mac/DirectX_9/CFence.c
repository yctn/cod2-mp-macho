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
void __ZdlPv(void *ptr);

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
static void __static_initialization_and_destruction_0(int __initialize_p, int __priority);
static void GLOBAL__D__ZN6CFence15sUnusedFenceIDsE(void); /* global destructors keyed to CFence_sUnusedFenceIDs */
static void GLOBAL__I__ZN6CFence15sUnusedFenceIDsE(void); /* global constructors keyed to CFence_sUnusedFenceIDs */
GLuint *ZNSt6vectorImSaImEE5eraseEN9__gnu_cxx17__normal_iteratorIPmS1_EES5_(CFenceUnusedIdsVector *vec, GLuint *first, GLuint *last); /* std_vector<unsigned long, std_allocator<unsigned long> >_erase */

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

static void __static_initialization_and_destruction_0(int __initialize_p, int __priority)
{
    if (__priority != 0xffff) {
        return;
    }

    if (__initialize_p == 1) {
        CFence_sUnusedFenceIDs.begin = NULL;
        CFence_sUnusedFenceIDs.end = NULL;
        CFence_sUnusedFenceIDs.capacity = NULL;
        return;
    }

    if (__initialize_p != 0) {
        return;
    }

    if (CFence_sUnusedFenceIDs.begin) {
        __ZdlPv(CFence_sUnusedFenceIDs.begin);
    }
}

/* line 105 */
void GLOBAL__D__ZN6CFence15sUnusedFenceIDsE(void) /* global destructors keyed to CFence_sUnusedFenceIDs */
{
    __static_initialization_and_destruction_0(0, 0xffff);
}

/* line 104 */
void GLOBAL__I__ZN6CFence15sUnusedFenceIDsE(void) /* global constructors keyed to CFence_sUnusedFenceIDs */
{
    __static_initialization_and_destruction_0(1, 0xffff);
}

/* line 122 */
GLuint *ZNSt6vectorImSaImEE5eraseEN9__gnu_cxx17__normal_iteratorIPmS1_EES5_(CFenceUnusedIdsVector *vec, GLuint *first, GLuint *last) /* std_vector<unsigned long, std_allocator<unsigned long> >_erase */
{
    memmove(first, last, (size_t)((char *)vec->end - (char *)last));
    vec->end -= (last - first);
    return first;
}
