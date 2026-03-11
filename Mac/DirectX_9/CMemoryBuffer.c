/* ASM dump from: CMemoryBuffer.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CMemoryBuffer.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CMemoryBuffer.h"
 */

extern int CMemoryBuffer_sDelayedFreeRequests __asm__("__ZN13CMemoryBuffer20sDelayedFreeRequestsE"); /* 0x0 */
extern UINT32 CMemoryBuffer_sMemoryDesignatedForDelayedFree __asm__("__ZN13CMemoryBuffer31sMemoryDesignatedForDelayedFreeE"); /* 0x0 */

typedef struct {
    int vptr;
    byte *allocation;
    byte *data;
    UINT32 length;
    int freedLater;
} CMemoryBufferImpl;

typedef struct CMemoryBufferFreeRequestNode {
    struct CMemoryBufferFreeRequestNode *next;
    struct CMemoryBufferFreeRequestNode *prev;
    byte *allocation;
    UINT32 length;
    UINT32 frames;
} CMemoryBufferFreeRequestNode;

void *__Znwm(unsigned int size);
void __ZdlPv(void *ptr);
void __ZdaPv(void *ptr);
extern void *vtbl_CMemoryBuffer[];

static byte *CMemoryBuffer_AlignAllocation(byte *allocation)
{
    return (byte *)(((unsigned int)(allocation + 31)) & ~31U);
}

static CMemoryBufferFreeRequestNode *CMemoryBuffer_GetDelayedFreeHead(void)
{
    return (CMemoryBufferFreeRequestNode *)&CMemoryBuffer_sDelayedFreeRequests;
}

static void CMemoryBuffer_EnsureDelayedFreeListInitialized(void)
{
    CMemoryBufferFreeRequestNode *head = CMemoryBuffer_GetDelayedFreeHead();

    if (head->next == NULL || head->prev == NULL) {
        head->next = head;
        head->prev = head;
    }
}

void CMemoryBuffer_CMemoryBuffer(const CMemoryBuffer * _this, UINT32 Length);
void CMemoryBuffer_Recreate(const CMemoryBuffer * _this);
void ZN13CMemoryBufferD1Ev(const CMemoryBuffer * _this); /* CMemoryBuffer_~CMemoryBuffer */
void ZN13CMemoryBufferD0Ev(const CMemoryBuffer * _this); /* CMemoryBuffer_~CMemoryBuffer */
void CMemoryBuffer_Resize(const CMemoryBuffer * _this, UINT32 Length);
void CMemoryBuffer_FreeLater(const CMemoryBuffer * _this, UINT32 Frames);
void CMemoryBuffer_Update(void);
void CMemoryBuffer_Reset(void);
static void __static_initialization_and_destruction_0(int __initialize_p, int __priority);
static void GLOBAL__D__ZN13CMemoryBuffer20sDelayedFreeRequestsE(void); /* global destructors keyed to CMemoryBuffer_sDelayedFreeRequests */
static void GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(void); /* global constructors keyed to CMemoryBuffer_sDelayedFreeRequests */
void ZNSt10_List_baseIN13CMemoryBuffer11FreeRequestESaIS1_EE8_M_clearEv(CMemoryBufferFreeRequestNode *head); /* std__List_base<CMemoryBuffer_FreeRequest, std_allocator<CMemoryBuffer_FreeRequest> >__M_clear */

/* line 33 */
void CMemoryBuffer_CMemoryBuffer(const CMemoryBuffer * _this, UINT32 Length)
{
    CMemoryBufferImpl *buffer;
    byte *allocation;

    buffer = (CMemoryBufferImpl *)_this;
    buffer->vptr = (int)vtbl_CMemoryBuffer;
    buffer->length = Length;
    buffer->freedLater = Length == 0;

    if (Length) {
        allocation = (byte *)__Znam(((Length + 31) & ~31U) + 31);
        buffer->allocation = allocation;
        buffer->data = CMemoryBuffer_AlignAllocation(allocation);
    } else {
        buffer->allocation = NULL;
        buffer->data = NULL;
    }
}

/* line 71 */
void CMemoryBuffer_Recreate(const CMemoryBuffer * _this)
{
    CMemoryBufferImpl *buffer;

    buffer = (CMemoryBufferImpl *)_this;
    buffer->allocation = (byte *)__Znam(((buffer->length + 31) & ~31U) + 31);
    buffer->data = CMemoryBuffer_AlignAllocation(buffer->allocation);
    buffer->freedLater = 0;
}

/* line 48 */
void ZN13CMemoryBufferD1Ev(const CMemoryBuffer * _this) /* CMemoryBuffer_~CMemoryBuffer */
{
    CMemoryBufferImpl *buffer;

    buffer = (CMemoryBufferImpl *)_this;
    buffer->vptr = (int)vtbl_CMemoryBuffer;

    if (!buffer->freedLater && buffer->allocation) {
        __ZdaPv(buffer->allocation);
    }

    buffer->data = NULL;
    buffer->allocation = NULL;
}

/* line 48 */
void ZN13CMemoryBufferD0Ev(const CMemoryBuffer * _this) /* CMemoryBuffer_~CMemoryBuffer */
{
    ZN13CMemoryBufferD1Ev(_this);
    __ZdlPv((void *)_this);
}

/* line 56 */
void CMemoryBuffer_Resize(const CMemoryBuffer * _this, UINT32 Length)
{
    CMemoryBufferImpl *buffer;

    buffer = (CMemoryBufferImpl *)_this;
    if (!buffer->freedLater && buffer->allocation) {
        __ZdaPv(buffer->allocation);
    }

    buffer->data = NULL;
    buffer->allocation = NULL;
    buffer->allocation = (byte *)__Znam(((Length + 31) & ~31U) + 31);
    buffer->data = CMemoryBuffer_AlignAllocation(buffer->allocation);
    buffer->length = Length;
    buffer->freedLater = 0;
}

/* line 84 */
void CMemoryBuffer_FreeLater(const CMemoryBuffer * _this, UINT32 Frames)
{
    CMemoryBufferImpl *buffer;
    CMemoryBufferFreeRequestNode *head;
    CMemoryBufferFreeRequestNode *node;

    buffer = (CMemoryBufferImpl *)_this;
    if (buffer->freedLater) {
        return;
    }

    CMemoryBuffer_EnsureDelayedFreeListInitialized();
    head = CMemoryBuffer_GetDelayedFreeHead();

    node = (CMemoryBufferFreeRequestNode *)__Znwm(sizeof(*node));
    if (node) {
        node->allocation = buffer->allocation;
        node->length = buffer->length;
        node->frames = Frames;

        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
    }

    CMemoryBuffer_sMemoryDesignatedForDelayedFree += buffer->length;
    buffer->data = NULL;
    buffer->allocation = NULL;
    buffer->freedLater = 1;
}

/* line 104 */
void CMemoryBuffer_Update(void)
{
    CMemoryBufferFreeRequestNode *head;
    CMemoryBufferFreeRequestNode *node;
    CMemoryBufferFreeRequestNode *next;

    CMemoryBuffer_EnsureDelayedFreeListInitialized();
    head = CMemoryBuffer_GetDelayedFreeHead();

    for (node = head->next; node != head; node = next) {
        next = node->next;

        if (node->frames) {
            --node->frames;
            continue;
        }

        if (node->allocation) {
            __ZdaPv(node->allocation);
        }

        CMemoryBuffer_sMemoryDesignatedForDelayedFree -= node->length;

        node->prev->next = node->next;
        node->next->prev = node->prev;
        __ZdlPv(node);
    }
}

/* line 133 */
void CMemoryBuffer_Reset(void)
{
    CMemoryBufferFreeRequestNode *head;
    CMemoryBufferFreeRequestNode *node;
    CMemoryBufferFreeRequestNode *next;

    glFinish();

    CMemoryBuffer_EnsureDelayedFreeListInitialized();
    head = CMemoryBuffer_GetDelayedFreeHead();

    for (node = head->next; node != head; node = next) {
        next = node->next;
        CMemoryBuffer_sMemoryDesignatedForDelayedFree -= node->length;

        if (node->allocation) {
            __ZdaPv(node->allocation);
        }

        __ZdlPv(node);
    }

    head->next = head;
    head->prev = head;
}

/* line 148 */
static void __static_initialization_and_destruction_0(int __initialize_p, int __priority)
{
    CMemoryBufferFreeRequestNode *head;

    if (__priority != 0xffff) {
        return;
    }

    head = CMemoryBuffer_GetDelayedFreeHead();

    if (__initialize_p == 1) {
        head->next = head;
        head->prev = head;
        return;
    }

    if (__initialize_p == 0) {
        ZNSt10_List_baseIN13CMemoryBuffer11FreeRequestESaIS1_EE8_M_clearEv(head);
    }
}

/* line 150 */
void GLOBAL__D__ZN13CMemoryBuffer20sDelayedFreeRequestsE(void) /* global destructors keyed to CMemoryBuffer_sDelayedFreeRequests */
{
    __static_initialization_and_destruction_0(0, 0xffff);
}

/* line 149 */
void GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE(void) /* global constructors keyed to CMemoryBuffer_sDelayedFreeRequests */
{
    __static_initialization_and_destruction_0(1, 0xffff);
}

/* line 69 */
void ZNSt10_List_baseIN13CMemoryBuffer11FreeRequestESaIS1_EE8_M_clearEv(CMemoryBufferFreeRequestNode *head) /* std__List_base<CMemoryBuffer_FreeRequest, std_allocator<CMemoryBuffer_FreeRequest> >__M_clear */
{
    CMemoryBufferFreeRequestNode *node;
    CMemoryBufferFreeRequestNode *next;

    node = head->next;
    while (node != head) {
        next = node->next;
        __ZdlPv(node);
        node = next;
    }
}
