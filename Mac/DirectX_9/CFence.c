/* Clean CFence implementation for Linux/Emscripten */
/* Replaces Mac Apple GL fence extension with no-ops */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CFence.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

/*
 * On Mac, CFence used glGenFencesAPPLE/glSetFenceAPPLE/glTestFenceAPPLE
 * for GPU synchronization. On Linux/Emscripten, these are not available
 * and not needed — all fence operations are no-ops.
 */

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

/* Global: the original used __asm__ label for the mangled name.
 * We define it here as a regular C global and provide the mangled alias
 * via the asm name attribute. */
CFenceUnusedIdsVector CFence_sUnusedFenceIDs = { NULL, NULL, NULL };

/* Forward declarations */
void CFence_CFence(const CFence * _this, const void * Start, UINT32 SizeInBytes, UINT32 FrameCount);
void CFence_Shutdown(void);
GLuint *ZNSt6vectorImSaImEE5eraseEN9__gnu_cxx17__normal_iteratorIPmS1_EES5_(CFenceUnusedIdsVector *vec, GLuint *first, GLuint *last);

/* --- CFence constructor (no-op) --- */

void CFence_CFence(const CFence * _this, const void * Start, UINT32 SizeInBytes, UINT32 FrameCount)
{
    CFenceImpl *fence;

    fence = (CFenceImpl *)_this;
    fence->start = Start;
    fence->sizeInBytes = SizeInBytes;
    fence->frameCount = FrameCount;
    fence->id = 0;
    /* Original: allocated fence IDs from pool, called glSetFenceAPPLE. No-op on Linux/WASM. */
}

/* --- CFence shutdown (no-op) --- */

void CFence_Shutdown(void)
{
    /* Original: iterated all unused fence IDs calling glDeleteFencesAPPLE, then freed vector.
     * No-op — no GL fence resources to clean up. */
    if (CFence_sUnusedFenceIDs.begin) {
        free(CFence_sUnusedFenceIDs.begin);
    }
    CFence_sUnusedFenceIDs.begin = NULL;
    CFence_sUnusedFenceIDs.end = NULL;
    CFence_sUnusedFenceIDs.capacity = NULL;
}

/* --- Global constructors/destructors --- */

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

    if (__initialize_p == 0) {
        if (CFence_sUnusedFenceIDs.begin) {
            free(CFence_sUnusedFenceIDs.begin);
            CFence_sUnusedFenceIDs.begin = NULL;
        }
    }
}

void GLOBAL__D__ZN6CFence15sUnusedFenceIDsE(void)
{
    __static_initialization_and_destruction_0(0, 0xffff);
}

void GLOBAL__I__ZN6CFence15sUnusedFenceIDsE(void)
{
    __static_initialization_and_destruction_0(1, 0xffff);
}

/* --- std::vector erase (utility used by other code) --- */

GLuint *ZNSt6vectorImSaImEE5eraseEN9__gnu_cxx17__normal_iteratorIPmS1_EES5_(CFenceUnusedIdsVector *vec, GLuint *first, GLuint *last)
{
    memmove(first, last, (size_t)((char *)vec->end - (char *)last));
    vec->end -= (last - first);
    return first;
}
