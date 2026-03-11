/* ASM dump from: COpenGLVAO.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/COpenGLVAO.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/COpenGL.h"
 *   #include "Mac/DirectX 9/CVertexArrays.h"
 *   #include "Mac/DirectX 9/COpenGLVertexProgram.h"
 */

typedef struct {
    void **vtable;
    bool mEnabled;
    bool mNeedsValidation;
    unsigned short padding;
    GLint mVSize;
    GLenum mVType;
    GLsizei mStride;
    const void *mpStream;
} CBaseVAImpl;

typedef struct {
    void **vtable;
    GLuint *mpVAOID;
    UINT32 mCode;
    UINT32 mReserved0C;
    CBaseVAImpl mColorArray;
    CBaseVAImpl mSecondaryColorArray;
    CBaseVAImpl mNormalArray;
    CBaseVAImpl mVertexArray;
    CBaseVAImpl mTexCoordArrays[8];
    VertexProgramStreamState mGenericArrays[16];
} COpenGLVAOImpl;

typedef struct {
    UINT16 *current;
    UINT16 *first;
    UINT16 *last;
    UINT16 **node;
} UInt16DequeIterator;

typedef struct {
    UINT16 **map;
    UINT32 mapSize;
    UInt16DequeIterator start;
    UInt16DequeIterator finish;
} UInt16Deque;

typedef struct TriangleNode {
    struct TriangleNode *next;
    struct TriangleNode *prev;
    Tuple triangle;
} TriangleNode;

typedef struct {
    struct COpenGLVAOBindingNode *next;
    struct COpenGLVAOBindingNode *prev;
    GLuint *vaoId;
} COpenGLVAOBindingNode;

void *__Znwm(size_t size);
void __ZdlPv(void *ptr);
void __ZNSt15_List_node_base4hookEPS_(void *node, void *position);
void __ZNSt15_List_node_base6unhookEv(void *node);

UINT32 COpenGLVAO_GetCode(const COpenGLVAO * _this);
bool ZNK10COpenGLVAOeqERKS_(const COpenGLVAO * _this, const COpenGLVAO *v); /* COpenGLVAO_operator== */
void COpenGLVAO_CreateNewBinding(const COpenGLVAO * _this);
UINT32 CalculateScore(const UInt16Deque *FIFO, const Tuple *t);
Tuple ChooseAndRemoveBestTriangle(const UInt16Deque *FIFO, TriangleNode *Triangles);
void COpenGLVAO_COpenGLVAO(const COpenGLVAO * _this);
void ZN10COpenGLVAOD2Ev(void); /* COpenGLVAO_~COpenGLVAO */
void ZN10COpenGLVAOD1Ev(void); /* COpenGLVAO_~COpenGLVAO */
void ZN10COpenGLVAOD0Ev(void); /* COpenGLVAO_~COpenGLVAO */
UINT32 Score(const UINT16 *pSrc, UINT32 NumIndices);
void Optimize(UINT16 *pDst, const UINT16 *pSrc, UINT32 NumIndices);
void ZNSt11_Deque_baseItSaItEED2Ev(void); /* std__Deque_base<unsigned short, std_allocator<unsigned short> >_~_Deque_base */
void ZNSt5dequeItSaItEE17_M_reallocate_mapEmb(void); /* std_deque<unsigned short, std_allocator<unsigned short> >__M_reallocate_map */
void ZNSt5dequeItSaItEE16_M_push_back_auxERKt(void); /* std_deque<unsigned short, std_allocator<unsigned short> >__M_push_back_aux */
void ZNSt5dequeItSaItEE5clearEv(void); /* std_deque<unsigned short, std_allocator<unsigned short> >_clear */
void ZNSt11_Deque_baseItSaItEE17_M_initialize_mapEm(void); /* std__Deque_base<unsigned short, std_allocator<unsigned short> >__M_initialize_map */

UINT32 COpenGLVAO_GetCode(const COpenGLVAO * _this)
{
    return ((const COpenGLVAOImpl *)_this)->mCode;
}

bool ZNK10COpenGLVAOeqERKS_(const COpenGLVAO * _this, const COpenGLVAO *v) /* COpenGLVAO_operator== */
{
    return COpenGLVAO_GetCode(_this) == COpenGLVAO_GetCode(v);
}

void COpenGLVAO_CreateNewBinding(const COpenGLVAO * _this)
{
    COpenGLVAOImpl *vao;
    GLuint *vaoId;
    COpenGLVAOBindingNode *bindingNode;
    void *bindingList;

    vao = (COpenGLVAOImpl *)_this;
    vaoId = (GLuint *)__Znwm(sizeof(*vaoId));
    glGenVertexArraysAPPLE(1, vaoId);

    bindingNode = (COpenGLVAOBindingNode *)__Znwm(sizeof(*bindingNode));
    bindingNode->vaoId = vaoId;
    bindingList = (char *)imp___ZN7COpenGL7sOpenGLE + 0x674;
    __ZNSt15_List_node_base4hookEPS_(bindingNode, bindingList);

    vao->mpVAOID = vaoId;
}

UINT32 CalculateScore(const UInt16Deque *FIFO, const Tuple *t)
{
    const UINT16 *current;
    const UINT16 *blockEnd;
    const UINT16 *finish;
    UINT16 **node;
    unsigned int matches0;
    unsigned int matches1;
    unsigned int matches2;

    current = FIFO->start.current;
    blockEnd = FIFO->start.last;
    node = FIFO->start.node;
    finish = FIFO->finish.current;
    matches0 = 0;
    matches1 = 0;
    matches2 = 0;

    while (current != finish) {
        while (current != blockEnd && current != finish) {
            UINT16 vertex;

            vertex = *current++;
            if (vertex == t->v[0]) {
                matches0 = 1;
            }
            if (vertex == t->v[1]) {
                matches1 = 1;
            }
            if (vertex == t->v[2]) {
                matches2 = 1;
            }
        }

        if (current != finish) {
            ++node;
            current = *node;
            blockEnd = current + 0x100;
        }
    }

    return matches0 + matches1 + matches2;
}

Tuple ChooseAndRemoveBestTriangle(const UInt16Deque *FIFO, TriangleNode *Triangles)
{
    TriangleNode *bestTriangleNode;
    TriangleNode *node;
    Tuple bestTriangle;

    bestTriangleNode = Triangles;
    node = Triangles->next;
    while (node != Triangles) {
        node->triangle.Score = CalculateScore(FIFO, &node->triangle);
        if (bestTriangleNode == Triangles || node->triangle.Score <= bestTriangleNode->triangle.Score) {
            bestTriangleNode = node;
        }
        node = node->next;
    }

    memmove(&bestTriangle, &bestTriangleNode->triangle, sizeof(bestTriangle));
    __ZNSt15_List_node_base6unhookEv(bestTriangleNode);
    __ZdlPv(bestTriangleNode);
    return bestTriangle;
}

/* line 15 */
__attribute__((naked))
void COpenGLVAO_COpenGLVAO(const COpenGLVAO * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 15 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 39 | this */
        "movl $0x332288, (%eax)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "addl $0x10, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* this */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 74 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV11CColorArray, %eax\n"
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x10(%edx)\n"
        /* } scope */
        "addl $0x28, %edx\n" /* line 39 */
        "movl %edx, -0x28(%ebp)\n" /* this */
        /* { scope 1 */
        "movl %edx, (%esp)\n" /* line 85 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV20CSecondaryColorArray, %eax\n"
        "addl $8, %eax\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x28(%ecx)\n"
        /* } scope */
        "addl $0x40, %ecx\n" /* line 39 */
        "movl %ecx, -0x24(%ebp)\n" /* this */
        /* { scope 1 */
        "movl %ecx, (%esp)\n" /* line 95 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV12CNormalArray, %eax\n"
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x40(%edx)\n"
        /* } scope */
        "addl $0x58, %edx\n" /* line 39 */
        "movl %edx, -0x20(%ebp)\n" /* this */
        /* { scope 1 */
        "movl %edx, (%esp)\n" /* line 106 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV12CVertexArray, %eax\n"
        "addl $8, %eax\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x58(%ecx)\n"
        /* } scope */
        "addl $0x70, %ecx\n" /* line 39 */
        "movl %ecx, -0x1c(%ebp)\n" /* this */
        "movl %ecx, %ebx\n"
        "movl $7, %edi\n"
        "movl $6, %esi\n"
        "movl imp___ZTV14CTexCoordArray, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        /* { scope 1 */
        ".Lf112c88_00112d3c:\n"
        "movl %ebx, (%esp)\n" /* line 117 */
        "calll CBaseVA_CBaseVA\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, (%ebx)\n"
        /* } scope */
        "addl $0x18, %ebx\n" /* line 39 */
        "movl %esi, %edi\n"
        "leal -1(%esi), %esi\n"
        "cmpl $-2, %esi\n"
        "jne .Lf112c88_00112d3c\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x130, %eax\n"
        "movl $0x10, %edx\n"
        ".Lf112c88_00112d63:\n"
        "movb $1, (%eax)\n" /* line 38 */
        "movb $0, 1(%eax)\n"
        "movl $4, 4(%eax)\n"
        "movl $0x1406, 8(%eax)\n"
        "movb $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "addl $0x18, %eax\n" /* line 39 */
        "subl $1, %edx\n"
        "jne .Lf112c88_00112d63\n"
        "addl $0x3c, %esp\n" /* line 41 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl imp___ZTV7CBaseVA, %edx\n"
        ".Lf112c88_00112da3:\n"
        "leal 8(%edx), %eax\n" /* line 32 */
        "movl -0x2c(%ebp), %edx\n" /* this */
        "movl %eax, (%edx)\n"
        "movl -0x34(%ebp), %ecx\n" /* line 74 */
        "movl %ecx, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 39 | this */
        "testl %edx, %edx\n"
        "je .Lf112c88_00112e13\n"
        "movl $7, %eax\n"
        "subl %edi, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0x1c(%ebp), %ecx\n" /* this */
        "leal (%ecx, %eax, 8), %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lf112c88_00112e13\n"
        "leal -0x18(%eax), %ebx\n"
        "movl %ebx, %esi\n"
        ".Lf112c88_00112dd9:\n"
        "movl (%esi), %eax\n"
        "movl %ebx, (%esp)\n"
        "calll *(%eax)\n"
        "subl $0x18, %esi\n"
        "cmpl -0x1c(%ebp), %ebx\n" /* this */
        "je .Lf112c88_00112e13\n"
        "subl $0x18, %ebx\n"
        "jmp .Lf112c88_00112dd9\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl imp___ZTV7CBaseVA, %edx\n"
        ".Lf112c88_00112df6:\n"
        "leal 8(%edx), %eax\n" /* line 32 */
        "movl -0x24(%ebp), %ecx\n" /* this */
        "movl %eax, (%ecx)\n"
        ".Lf112c88_00112dfe:\n"
        "leal 8(%edx), %eax\n"
        "movl -0x28(%ebp), %ecx\n" /* this */
        "movl %eax, (%ecx)\n"
        "jmp .Lf112c88_00112da3\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl imp___ZTV7CBaseVA, %edx\n"
        "jmp .Lf112c88_00112dfe\n"
        ".Lf112c88_00112e13:\n"
        "movl imp___ZTV12CVertexArray, %eax\n" /* line 106 */
        "addl $8, %eax\n"
        "movl -0x20(%ebp), %edx\n" /* this */
        "movl %eax, (%edx)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "leal 8(%edx), %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* this */
        "movl %eax, (%ecx)\n"
        "jmp .Lf112c88_00112df6\n"
    );
}

/* overload skip: COpenGLVAO_COpenGLVAO (0x112e30) */

/* line 45 */
__attribute__((naked))
void ZN10COpenGLVAOD2Ev(void) /* COpenGLVAO_~COpenGLVAO */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 45 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x332288, (%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 47 | this */
        "addl $0x70, %eax\n"
        "je .Lf112fd8_0011301f\n"
        "movl 8(%ebp), %esi\n" /* this */
        "addl $0x130, %esi\n"
        "cmpl %esi, %eax\n"
        "je .Lf112fd8_0011301f\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "addl $0x118, %ebx\n"
        "movl $8, %edi\n"
        ".Lf112fd8_0011300d:\n"
        "subl $0x18, %esi\n"
        "movl (%ebx), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "subl $0x18, %ebx\n"
        "subl $1, %edi\n"
        "jne .Lf112fd8_0011300d\n"
        ".Lf112fd8_0011301f:\n"
        "movl imp___ZTV12CVertexArray, %eax\n" /* line 106 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x58(%edx)\n"
        "movl imp___ZTV7CBaseVA, %eax\n" /* line 32 */
        "addl $8, %eax\n"
        "movl %eax, 0x58(%edx)\n"
        "movl %eax, 0x40(%edx)\n"
        "movl %eax, 0x28(%edx)\n"
        "movl %eax, 0x10(%edx)\n"
        "addl $0x1c, %esp\n" /* line 47 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl imp___ZTV12CVertexArray, %edx\n" /* line 106 */
        "addl $8, %edx\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %edx, 0x58(%ecx)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, 0x58(%ecx)\n"
        "movl %edx, 0x40(%ecx)\n"
        "movl %edx, 0x28(%ecx)\n"
        "movl %edx, 0x10(%ecx)\n"
        "movl %eax, (%esp)\n" /* line 74 */
        "calll __Unwind_Resume\n"
        "nop\n"
    );
}

/* line 45 */
__attribute__((naked))
void ZN10COpenGLVAOD1Ev(void) /* COpenGLVAO_~COpenGLVAO */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 45 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x332288, (%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 47 | this */
        "addl $0x70, %eax\n"
        "je .Lf113076_001130bd\n"
        "movl 8(%ebp), %esi\n" /* this */
        "addl $0x130, %esi\n"
        "cmpl %esi, %eax\n"
        "je .Lf113076_001130bd\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "addl $0x118, %ebx\n"
        "movl $8, %edi\n"
        ".Lf113076_001130ab:\n"
        "subl $0x18, %esi\n"
        "movl (%ebx), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "subl $0x18, %ebx\n"
        "subl $1, %edi\n"
        "jne .Lf113076_001130ab\n"
        ".Lf113076_001130bd:\n"
        "movl imp___ZTV12CVertexArray, %eax\n" /* line 106 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x58(%edx)\n"
        "movl imp___ZTV7CBaseVA, %eax\n" /* line 32 */
        "addl $8, %eax\n"
        "movl %eax, 0x58(%edx)\n"
        "movl %eax, 0x40(%edx)\n"
        "movl %eax, 0x28(%edx)\n"
        "movl %eax, 0x10(%edx)\n"
        "addl $0x1c, %esp\n" /* line 47 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl imp___ZTV12CVertexArray, %edx\n" /* line 106 */
        "addl $8, %edx\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %edx, 0x58(%ecx)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, 0x58(%ecx)\n"
        "movl %edx, 0x40(%ecx)\n"
        "movl %edx, 0x28(%ecx)\n"
        "movl %edx, 0x10(%ecx)\n"
        "movl %eax, (%esp)\n" /* line 74 */
        "calll __Unwind_Resume\n"
        "nop\n"
    );
}

/* line 45 */
__attribute__((naked))
void ZN10COpenGLVAOD0Ev(void) /* COpenGLVAO_~COpenGLVAO */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 45 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl $0x332288, (%edi)\n" /* this */
        "movl %edi, %eax\n" /* line 47 | this */
        "addl $0x70, %eax\n"
        "je .Lf113114_00113157\n"
        "leal 0x130(%edi), %esi\n" /* this */
        "cmpl %esi, %eax\n"
        "je .Lf113114_00113157\n"
        "leal 0x118(%edi), %ebx\n" /* this */
        "movl $8, -0x1c(%ebp)\n"
        ".Lf113114_00113144:\n"
        "subl $0x18, %esi\n"
        "movl (%ebx), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "subl $0x18, %ebx\n"
        "subl $1, -0x1c(%ebp)\n"
        "jne .Lf113114_00113144\n"
        ".Lf113114_00113157:\n"
        "movl imp___ZTV12CVertexArray, %eax\n" /* line 106 */
        "addl $8, %eax\n"
        "movl %eax, 0x58(%edi)\n" /* this */
        "movl imp___ZTV7CBaseVA, %eax\n" /* line 32 */
        "addl $8, %eax\n"
        "movl %eax, 0x58(%edi)\n"
        "movl %eax, 0x40(%edi)\n"
        "movl %eax, 0x28(%edi)\n"
        "movl %eax, 0x10(%edi)\n"
        "movl %edi, 8(%ebp)\n" /* line 47 | this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        "movl imp___ZTV12CVertexArray, %edx\n" /* line 106 */
        "addl $8, %edx\n"
        "movl %edx, 0x58(%edi)\n" /* this */
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, 0x58(%edi)\n"
        "movl %edx, 0x40(%edi)\n"
        "movl %edx, 0x28(%edi)\n"
        "movl %edx, 0x10(%edi)\n"
        "movl %eax, (%esp)\n" /* line 74 */
        "calll __Unwind_Resume\n"
        "nop\n"
    );
}

/* line 193 */
__attribute__((naked))
UINT32 Score(const UINT16 *pSrc, UINT32 NumIndices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 193 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1: i */
        "movl $0, -0x40(%ebp)\n" /* line 389 | FIFO */
        "movl $0, -0x3c(%ebp)\n"
        "movl $0, -0x38(%ebp)\n" /* line 127 */
        "movl $0, -0x34(%ebp)\n"
        "movl $0, -0x30(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n"
        "movl $0, -0x24(%ebp)\n"
        "movl $0, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n"
        "movl $0, 4(%esp)\n" /* line 368 */
        "leal -0x40(%ebp), %eax\n" /* FIFO */
        "movl %eax, (%esp)\n"
        "calll ZNSt11_Deque_baseItSaItEE17_M_initialize_mapEm\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %ebx\n" /* line 199 | NumIndices */
        "testl %ebx, %ebx\n"
        "jne .Lf1131b0_0011326a\n"
        "movl $0, -0x58(%ebp)\n" /* Count */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, -0x64(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x28(%ebp), %ebx\n"
        "movl %eax, %ecx\n"
        /* } scope */
        ".Lf1131b0_00113237:\n"
        "movl -0x60(%ebp), %eax\n" /* line 131 */
        ".Lf1131b0_0011323a:\n"
        "cmpl %eax, %ebx\n" /* line 173 */
        "je .Lf1131b0_00113254\n"
        ".Lf1131b0_0011323e:\n"
        "addl $2, %eax\n" /* line 144 */
        "cmpl %eax, %edx\n" /* line 145 */
        "jne .Lf1131b0_0011323a\n"
        "addl $4, %ecx\n" /* line 147 */
        "movl (%ecx), %eax\n" /* line 232 */
        "leal 0x200(%eax), %edx\n" /* line 233 */
        "cmpl %eax, %ebx\n" /* line 173 */
        "jne .Lf1131b0_0011323e\n"
        ".Lf1131b0_00113254:\n"
        "leal -0x40(%ebp), %edx\n" /* line 715 | FIFO */
        "movl %edx, (%esp)\n"
        "calll ZNSt11_Deque_baseItSaItEED2Ev\n"
        /* } scope */
        "movl -0x58(%ebp), %eax\n" /* line 210 | Count */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        /* { scope 2 */
        ".Lf1131b0_0011326a:\n"
        "movl 8(%ebp), %edx\n" /* line 199 | pSrc */
        "movl %edx, -0x4c(%ebp)\n"
        "movl $0, -0x54(%ebp)\n" /* i */
        "movl $0, -0x58(%ebp)\n" /* Count */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, -0x64(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x28(%ebp), %ebx\n"
        "movl %edx, %ecx\n"
        "movl %eax, %edi\n"
        ".Lf1131b0_00113297:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 201 */
        "movzwl (%edx), %edx\n"
        "movw %dx, -0x5a(%ebp)\n"
        "movl -0x60(%ebp), %edx\n" /* line 131 */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movzwl -0x5a(%ebp), %esi\n"
        ".Lf1131b0_001132ae:\n"
        "cmpl %edx, %ebx\n" /* line 181 */
        "je .Lf1131b0_001132d5\n"
        ".Lf1131b0_001132b2:\n"
        "movzwl (%edx), %eax\n" /* line 183 */
        "cmpl %esi, %eax\n"
        "je .Lf1131b0_0011336a\n"
        "addl $2, %edx\n" /* line 144 */
        "cmpl %edx, %ecx\n" /* line 145 */
        "jne .Lf1131b0_001132ae\n"
        "addl $4, %edi\n" /* line 147 */
        "movl (%edi), %eax\n" /* line 232 */
        "leal 0x200(%eax), %ecx\n" /* line 233 */
        "movl %eax, %edx\n"
        "cmpl %edx, %ebx\n" /* line 181 */
        "jne .Lf1131b0_001132b2\n"
        ".Lf1131b0_001132d5:\n"
        "xorl %eax, %eax\n"
        "movzbl %al, %eax\n" /* line 201 */
        "addl %eax, -0x58(%ebp)\n" /* Count */
        "movl -0x50(%ebp), %eax\n" /* line 1041 */
        "subl $2, %eax\n"
        "cmpl %ebx, %eax\n"
        "je .Lf1131b0_00113383\n"
        ".Lf1131b0_001132eb:\n"
        "testl %ebx, %ebx\n" /* line 104 */
        "je .Lf1131b0_0011330b\n"
        "movzwl -0x5a(%ebp), %edx\n"
        "movw %dx, (%ebx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, -0x64(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0x28(%ebp), %ebx\n"
        ".Lf1131b0_0011330b:\n"
        "addl $2, %ebx\n" /* line 1045 */
        "movl %ebx, -0x28(%ebp)\n"
        ".Lf1131b0_00113311:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 203 */
        "subl -0x68(%ebp), %eax\n"
        "sarl $2, %eax\n"
        "shll $8, %eax\n"
        "movl %ebx, %edx\n"
        "subl -0x24(%ebp), %edx\n"
        "sarl $1, %edx\n"
        "leal -0x100(%eax, %edx), %eax\n"
        "movl -0x64(%ebp), %edx\n"
        "subl -0x60(%ebp), %edx\n"
        "sarl $1, %edx\n"
        "addl %edx, %eax\n"
        "cmpl $0xa, %eax\n"
        "jbe .Lf1131b0_0011334f\n"
        "movl -0x64(%ebp), %eax\n" /* line 1062 */
        "subl $2, %eax\n"
        "cmpl %eax, -0x60(%ebp)\n"
        "je .Lf1131b0_001133ba\n"
        "addl $2, -0x60(%ebp)\n" /* line 1066 */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        ".Lf1131b0_0011334f:\n"
        "addl $1, -0x54(%ebp)\n" /* line 199 | i */
        "addl $2, -0x4c(%ebp)\n"
        "movl -0x54(%ebp), %eax\n" /* i */
        "cmpl %eax, 0xc(%ebp)\n" /* NumIndices */
        "je .Lf1131b0_001133af\n"
        "movl -0x64(%ebp), %ecx\n"
        "movl -0x68(%ebp), %edi\n"
        "jmp .Lf1131b0_00113297\n"
        ".Lf1131b0_0011336a:\n"
        "movl $1, %eax\n" /* line 183 */
        "movzbl %al, %eax\n" /* line 201 */
        "addl %eax, -0x58(%ebp)\n" /* Count */
        "movl -0x50(%ebp), %eax\n" /* line 1041 */
        "subl $2, %eax\n"
        "cmpl %ebx, %eax\n"
        "jne .Lf1131b0_001132eb\n"
        ".Lf1131b0_00113383:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 1048 */
        "movl %edx, 4(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* FIFO */
        "movl %eax, (%esp)\n"
        "calll ZNSt5dequeItSaItEE16_M_push_back_auxERKt\n"
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, -0x68(%ebp)\n"
        "movl -0x28(%ebp), %ebx\n"
        "jmp .Lf1131b0_00113311\n"
        ".Lf1131b0_001133af:\n"
        "movl -0x64(%ebp), %edx\n"
        "movl -0x68(%ebp), %ecx\n"
        "jmp .Lf1131b0_00113237\n"
        ".Lf1131b0_001133ba:\n"
        "movl -0x34(%ebp), %eax\n" /* line 94 */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "movl -0x2c(%ebp), %edx\n" /* line 410 */
        "movl %edx, %eax\n"
        "addl $4, %edx\n" /* line 231 */
        "movl %edx, -0x68(%ebp)\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 4(%eax), %eax\n" /* line 232 */
        "movl %eax, -0x34(%ebp)\n"
        "leal 0x200(%eax), %edx\n" /* line 233 */
        "movl %edx, -0x64(%ebp)\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl %eax, -0x60(%ebp)\n" /* line 411 */
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x28(%ebp), %ebx\n"
        "jmp .Lf1131b0_0011334f\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl -0x28(%ebp), %ebx\n" /* line 131 */
        "movl -0x38(%ebp), %eax\n"
        "movl -0x30(%ebp), %ecx\n"
        "movl -0x2c(%ebp), %edx\n"
        ".Lf1131b0_00113401:\n"
        "cmpl %ebx, %eax\n" /* line 173 */
        "je .Lf1131b0_00113421\n"
        "addl $2, %eax\n" /* line 144 */
        "cmpl %eax, %ecx\n" /* line 145 */
        "jne .Lf1131b0_00113401\n"
        "addl $4, %edx\n" /* line 147 */
        "movl (%edx), %eax\n" /* line 232 */
        "leal 0x200(%eax), %ecx\n" /* line 233 */
        "jmp .Lf1131b0_00113401\n"
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
        ".Lf1131b0_00113421:\n"
        "leal -0x40(%ebp), %edx\n" /* line 715 | FIFO */
        "movl %edx, (%esp)\n"
        "calll ZNSt11_Deque_baseItSaItEED2Ev\n"
        "movl %esi, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 213 */
__attribute__((naked))
void Optimize(UINT16 *pDst, const UINT16 *pSrc, UINT32 NumIndices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 213 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        /* { scope 1 */
        "leal -0x20(%ebp), %eax\n" /* line 340 | Triangles */
        "movl %eax, -0x20(%ebp)\n" /* Triangles */
        "movl %eax, -0x1c(%ebp)\n" /* line 341 */
        "movl 0x10(%ebp), %esi\n" /* line 223 | NumIndices */
        "testl %esi, %esi\n"
        "je .Lf113434_001134af\n"
        "movl $0, -0x74(%ebp)\n" /* i */
        "movl 0xc(%ebp), %ebx\n" /* pSrc */
        ".Lf113434_0011345a:\n"
        "movzwl (%ebx), %ecx\n" /* line 213 */
        "movl %ecx, -0x7c(%ebp)\n"
        "movzwl 2(%ebx), %edi\n"
        "movzwl 4(%ebx), %esi\n"
        /* { scope 2 */
        "movl $0x14, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %eax, %edx\n" /* line 104 */
        "addl $8, %edx\n"
        "je .Lf113434_00113491\n"
        "movl $0, 8(%edx)\n"
        "movw %si, 4(%edx)\n"
        "movw %di, 2(%edx)\n"
        "movl -0x7c(%ebp), %edx\n"
        "movw %dx, 8(%eax)\n"
        ".Lf113434_00113491:\n"
        "leal -0x20(%ebp), %ecx\n" /* line 1152 | Triangles */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSt15_List_node_base4hookEPS_\n"
        /* } scope */
        "addl $3, -0x74(%ebp)\n" /* line 223 | i */
        "addl $6, %ebx\n"
        "movl -0x74(%ebp), %eax\n" /* i */
        "cmpl %eax, 0x10(%ebp)\n" /* NumIndices */
        "ja .Lf113434_0011345a\n"
        ".Lf113434_001134af:\n"
        "movl $0xaaaaaaab, %eax\n" /* line 231 */
        "mull 0x10(%ebp)\n" /* NumIndices */
        "movl %edx, %esi\n" /* NumTriangles */
        "shrl $1, %esi\n" /* NumTriangles */
        "movl $0, -0x54(%ebp)\n" /* line 389 | FIFO */
        "movl $0, -0x50(%ebp)\n"
        "movl $0, -0x4c(%ebp)\n" /* line 127 */
        "movl $0, -0x48(%ebp)\n"
        "movl $0, -0x44(%ebp)\n"
        "movl $0, -0x40(%ebp)\n"
        "movl $0, -0x3c(%ebp)\n"
        "movl $0, -0x38(%ebp)\n"
        "movl $0, -0x34(%ebp)\n"
        "movl $0, -0x30(%ebp)\n"
        "movl $0, 4(%esp)\n" /* line 368 */
        "leal -0x54(%ebp), %ecx\n" /* FIFO */
        "movl %ecx, (%esp)\n"
        "calll ZNSt11_Deque_baseItSaItEE17_M_initialize_mapEm\n"
        "movl -0x20(%ebp), %ebx\n" /* line 580 | Triangles */
        "movl 8(%ebx), %eax\n" /* line 237 */
        "movl %eax, -0x2c(%ebp)\n" /* t */
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %ebx, (%esp)\n" /* line 1159 */
        "calll __ZNSt15_List_node_base6unhookEv\n"
        "movl %ebx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 106 | t */
        "movl 8(%ebp), %eax\n" /* pDst */
        "movw %bx, (%eax)\n"
        "movzwl -0x2a(%ebp), %eax\n" /* line 107 */
        "movl 8(%ebp), %edx\n" /* pDst */
        "movw %ax, 2(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 108 */
        "movw %ax, 4(%edx)\n"
        "addl $6, %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 1041 */
        "movl -0x34(%ebp), %edx\n"
        "leal -2(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lf113434_001138ea\n"
        "testl %ecx, %ecx\n" /* line 104 */
        "je .Lf113434_00113578\n"
        "movw %bx, (%ecx)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        ".Lf113434_00113578:\n"
        "addl $2, %ecx\n" /* line 1045 */
        "movl %ecx, -0x3c(%ebp)\n"
        ".Lf113434_0011357e:\n"
        "leal -2(%edx), %eax\n" /* line 1041 */
        "cmpl %eax, %ecx\n"
        "je .Lf113434_001138b6\n"
        "testl %ecx, %ecx\n" /* line 104 */
        "je .Lf113434_0011359a\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, (%ecx)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        ".Lf113434_0011359a:\n"
        "addl $2, %ecx\n" /* line 1045 */
        "movl %ecx, -0x3c(%ebp)\n"
        ".Lf113434_001135a0:\n"
        "leal -2(%edx), %eax\n" /* line 1041 */
        "cmpl %eax, %ecx\n"
        "je .Lf113434_001138d3\n"
        "testl %ecx, %ecx\n" /* line 104 */
        "je .Lf113434_001135b8\n"
        "movl -0x28(%ebp), %eax\n"
        "movw %ax, (%ecx)\n"
        "movl -0x3c(%ebp), %ecx\n"
        ".Lf113434_001135b8:\n"
        "addl $2, %ecx\n" /* line 1045 */
        "movl %ecx, -0x3c(%ebp)\n"
        ".Lf113434_001135be:\n"
        "movl -0x20(%ebp), %edx\n" /* line 580 | Triangles */
        "leal -0x20(%ebp), %ecx\n" /* line 244 | Triangles */
        "cmpl %edx, %ecx\n"
        "je .Lf113434_001135e3\n"
        ".Lf113434_001135c8:\n"
        "movl 8(%edx), %eax\n" /* line 246 */
        "movl %eax, -0x2c(%ebp)\n" /* t */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl (%edx), %edx\n" /* line 140 */
        "leal -0x20(%ebp), %eax\n" /* line 244 | Triangles */
        "cmpl %edx, %eax\n"
        "jne .Lf113434_001135c8\n"
        ".Lf113434_001135e3:\n"
        "subl $1, %esi\n" /* line 253 | NumTriangles */
        "movl %esi, -0x78(%ebp)\n" /* NumTriangles */
        "je .Lf113434_00113774\n"
        "movl $0, -0x6c(%ebp)\n"
        ".Lf113434_001135f6:\n"
        "leal -0x20(%ebp), %edx\n" /* line 255 | Triangles */
        "movl %edx, 8(%esp)\n"
        "leal -0x54(%ebp), %ecx\n" /* FIFO */
        "movl %ecx, 4(%esp)\n"
        "leal -0x68(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ChooseAndRemoveBestTriangle\n"
        "subl $4, %esp\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* t */
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n" /* line 106 | t */
        "movl -0x70(%ebp), %ecx\n"
        "movw %dx, (%ecx)\n"
        "movzwl -0x2a(%ebp), %eax\n" /* line 107 */
        "movw %ax, 2(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 108 */
        "movw %ax, 4(%ecx)\n"
        "addl $6, %ecx\n"
        "movl %ecx, -0x70(%ebp)\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 1041 */
        "movl -0x34(%ebp), %eax\n"
        "subl $2, %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lf113434_001137d7\n"
        "testl %ecx, %ecx\n" /* line 104 */
        "je .Lf113434_0011365d\n"
        "movw %dx, (%ecx)\n"
        "movl -0x3c(%ebp), %ecx\n"
        ".Lf113434_0011365d:\n"
        "addl $2, %ecx\n" /* line 1045 */
        "movl %ecx, -0x3c(%ebp)\n"
        ".Lf113434_00113663:\n"
        "movl -0x44(%ebp), %edi\n" /* line 333 */
        "movl -0x4c(%ebp), %ebx\n"
        "movl -0x40(%ebp), %esi\n" /* line 258 | NumTriangles */
        "movl -0x30(%ebp), %eax\n"
        "subl %esi, %eax\n" /* NumTriangles */
        "sarl $2, %eax\n"
        "shll $8, %eax\n"
        "movl %ecx, %edx\n"
        "subl -0x38(%ebp), %edx\n"
        "sarl $1, %edx\n"
        "leal -0x100(%eax, %edx), %eax\n"
        "movl %edi, %edx\n"
        "subl %ebx, %edx\n"
        "sarl $1, %edx\n"
        "addl %edx, %eax\n"
        "cmpl $0xa, %eax\n"
        "jbe .Lf113434_001136a3\n"
        "leal -2(%edi), %eax\n" /* line 1062 */
        "cmpl %eax, %ebx\n"
        "je .Lf113434_0011382b\n"
        "leal 2(%ebx), %eax\n" /* line 1066 */
        "movl %eax, -0x4c(%ebp)\n"
        ".Lf113434_001136a3:\n"
        "movl -0x34(%ebp), %eax\n" /* line 1041 */
        "subl $2, %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lf113434_0011380e\n"
        "testl %ecx, %ecx\n" /* line 104 */
        "je .Lf113434_001136c2\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movw %ax, (%ecx)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl -0x40(%ebp), %esi\n"
        ".Lf113434_001136c2:\n"
        "addl $2, %ecx\n" /* line 1045 */
        "movl %ecx, -0x3c(%ebp)\n"
        ".Lf113434_001136c8:\n"
        "movl -0x44(%ebp), %edi\n" /* line 333 */
        "movl -0x4c(%ebp), %ebx\n"
        "movl -0x30(%ebp), %eax\n" /* line 263 */
        "subl %esi, %eax\n" /* NumTriangles */
        "sarl $2, %eax\n"
        "shll $8, %eax\n"
        "movl %ecx, %edx\n"
        "subl -0x38(%ebp), %edx\n"
        "sarl $1, %edx\n"
        "leal -0x100(%eax, %edx), %eax\n"
        "movl %edi, %edx\n"
        "subl %ebx, %edx\n"
        "sarl $1, %edx\n"
        "addl %edx, %eax\n"
        "cmpl $0xa, %eax\n"
        "jbe .Lf113434_00113705\n"
        "leal -2(%edi), %eax\n" /* line 1062 */
        "cmpl %eax, %ebx\n"
        "je .Lf113434_0011385b\n"
        "leal 2(%ebx), %eax\n" /* line 1066 */
        "movl %eax, -0x4c(%ebp)\n"
        ".Lf113434_00113705:\n"
        "movl -0x34(%ebp), %eax\n" /* line 1041 */
        "subl $2, %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lf113434_001137f1\n"
        "testl %ecx, %ecx\n" /* line 104 */
        "je .Lf113434_00113723\n"
        "movl -0x28(%ebp), %eax\n"
        "movw %ax, (%ecx)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl -0x40(%ebp), %esi\n"
        ".Lf113434_00113723:\n"
        "addl $2, %ecx\n" /* line 1045 */
        "movl %ecx, -0x3c(%ebp)\n"
        ".Lf113434_00113729:\n"
        "movl -0x44(%ebp), %edi\n" /* line 333 */
        "movl -0x4c(%ebp), %ebx\n"
        "movl -0x30(%ebp), %edx\n" /* line 268 */
        "subl %esi, %edx\n" /* NumTriangles */
        "sarl $2, %edx\n"
        "shll $8, %edx\n"
        "subl -0x38(%ebp), %ecx\n"
        "sarl $1, %ecx\n"
        "leal -0x100(%edx, %ecx), %edx\n"
        "movl %edi, %eax\n"
        "subl %ebx, %eax\n"
        "sarl $1, %eax\n"
        "addl %eax, %edx\n"
        "cmpl $0xa, %edx\n"
        "jbe .Lf113434_00113764\n"
        "leal -2(%edi), %eax\n" /* line 1062 */
        "cmpl %eax, %ebx\n"
        "je .Lf113434_0011388b\n"
        "leal 2(%ebx), %eax\n" /* line 1066 */
        "movl %eax, -0x4c(%ebp)\n"
        ".Lf113434_00113764:\n"
        "addl $1, -0x6c(%ebp)\n" /* line 253 */
        "movl -0x78(%ebp), %eax\n"
        "cmpl %eax, -0x6c(%ebp)\n"
        "jne .Lf113434_001135f6\n"
        ".Lf113434_00113774:\n"
        "leal -0x54(%ebp), %edx\n" /* line 279 | FIFO */
        "movl %edx, (%esp)\n"
        "calll ZNSt5dequeItSaItEE5clearEv\n"
        "movl -0x3c(%ebp), %ebx\n" /* line 131 */
        "movl -0x4c(%ebp), %eax\n"
        "movl -0x44(%ebp), %edx\n"
        "movl -0x40(%ebp), %ecx\n"
        ".Lf113434_0011378b:\n"
        "cmpl %eax, %ebx\n" /* line 173 */
        "je .Lf113434_001137a5\n"
        ".Lf113434_0011378f:\n"
        "addl $2, %eax\n" /* line 144 */
        "cmpl %eax, %edx\n" /* line 145 */
        "jne .Lf113434_0011378b\n"
        "addl $4, %ecx\n" /* line 147 */
        "movl (%ecx), %eax\n" /* line 232 */
        "leal 0x200(%eax), %edx\n" /* line 233 */
        "cmpl %eax, %ebx\n" /* line 173 */
        "jne .Lf113434_0011378f\n"
        ".Lf113434_001137a5:\n"
        "leal -0x54(%ebp), %eax\n" /* line 715 | FIFO */
        "movl %eax, (%esp)\n"
        "calll ZNSt11_Deque_baseItSaItEED2Ev\n"
        "movl -0x20(%ebp), %eax\n" /* line 72 | Triangles */
        "leal -0x20(%ebp), %edx\n" /* line 73 | Triangles */
        "cmpl %eax, %edx\n"
        "jne .Lf113434_001137be\n"
        "jmp .Lf113434_001137cf\n"
        ".Lf113434_001137bc:\n"
        "movl %ebx, %eax\n"
        ".Lf113434_001137be:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "leal -0x20(%ebp), %edx\n" /* line 73 | Triangles */
        "cmpl %ebx, %edx\n"
        "jne .Lf113434_001137bc\n"
        /* } scope */
        ".Lf113434_001137cf:\n"
        "leal -0xc(%ebp), %esp\n" /* line 281 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf113434_001137d7:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 1048 | t */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* FIFO */
        "movl %eax, (%esp)\n"
        "calll ZNSt5dequeItSaItEE16_M_push_back_auxERKt\n"
        "movl -0x3c(%ebp), %ecx\n"
        "jmp .Lf113434_00113663\n"
        ".Lf113434_001137f1:\n"
        "leal -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %ecx\n" /* FIFO */
        "movl %ecx, (%esp)\n"
        "calll ZNSt5dequeItSaItEE16_M_push_back_auxERKt\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl -0x40(%ebp), %esi\n" /* NumTriangles */
        "jmp .Lf113434_00113729\n"
        ".Lf113434_0011380e:\n"
        "leal -0x2a(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %edx\n" /* FIFO */
        "movl %edx, (%esp)\n"
        "calll ZNSt5dequeItSaItEE16_M_push_back_auxERKt\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl -0x40(%ebp), %esi\n" /* NumTriangles */
        "jmp .Lf113434_001136c8\n"
        ".Lf113434_0011382b:\n"
        "movl -0x48(%ebp), %eax\n" /* line 94 */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "movl -0x40(%ebp), %esi\n" /* line 410 | NumTriangles */
        "movl %esi, %eax\n" /* NumTriangles */
        "addl $4, %esi\n" /* line 231 | NumTriangles */
        "movl %esi, -0x40(%ebp)\n" /* NumTriangles */
        "movl 4(%eax), %eax\n" /* line 232 */
        "movl %eax, -0x48(%ebp)\n"
        "leal 0x200(%eax), %edx\n" /* line 233 */
        "movl %edx, -0x44(%ebp)\n"
        "movl %eax, -0x4c(%ebp)\n" /* line 411 */
        "movl -0x3c(%ebp), %ecx\n"
        "jmp .Lf113434_001136a3\n"
        ".Lf113434_0011385b:\n"
        "movl -0x48(%ebp), %eax\n" /* line 94 */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "movl -0x40(%ebp), %esi\n" /* line 410 | NumTriangles */
        "movl %esi, %eax\n" /* NumTriangles */
        "addl $4, %esi\n" /* line 231 | NumTriangles */
        "movl %esi, -0x40(%ebp)\n" /* NumTriangles */
        "movl 4(%eax), %eax\n" /* line 232 */
        "movl %eax, -0x48(%ebp)\n"
        "leal 0x200(%eax), %edx\n" /* line 233 */
        "movl %edx, -0x44(%ebp)\n"
        "movl %eax, -0x4c(%ebp)\n" /* line 411 */
        "movl -0x3c(%ebp), %ecx\n"
        "jmp .Lf113434_00113705\n"
        ".Lf113434_0011388b:\n"
        "movl -0x48(%ebp), %eax\n" /* line 94 */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "movl -0x40(%ebp), %edx\n" /* line 410 */
        "leal 4(%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* line 231 */
        "movl 4(%edx), %eax\n" /* line 232 */
        "movl %eax, -0x48(%ebp)\n"
        "leal 0x200(%eax), %edx\n" /* line 233 */
        "movl %edx, -0x44(%ebp)\n"
        "movl %eax, -0x4c(%ebp)\n" /* line 411 */
        "jmp .Lf113434_00113764\n"
        ".Lf113434_001138b6:\n"
        "leal -0x2a(%ebp), %eax\n" /* line 1048 */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* FIFO */
        "movl %eax, (%esp)\n"
        "calll ZNSt5dequeItSaItEE16_M_push_back_auxERKt\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "jmp .Lf113434_001135a0\n"
        ".Lf113434_001138d3:\n"
        "leal -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %edx\n" /* FIFO */
        "movl %edx, (%esp)\n"
        "calll ZNSt5dequeItSaItEE16_M_push_back_auxERKt\n"
        "jmp .Lf113434_001135be\n"
        ".Lf113434_001138ea:\n"
        "leal -0x2c(%ebp), %eax\n" /* t */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %ecx\n" /* FIFO */
        "movl %ecx, (%esp)\n"
        "calll ZNSt5dequeItSaItEE16_M_push_back_auxERKt\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "jmp .Lf113434_0011357e\n"
        "movl %eax, %esi\n" /* NumTriangles */
        ".Lf113434_00113909:\n"
        "movl -0x20(%ebp), %eax\n" /* line 72 | Triangles */
        "leal -0x20(%ebp), %ecx\n" /* line 73 | Triangles */
        "cmpl %ecx, %eax\n"
        "je .Lf113434_0011394e\n"
        ".Lf113434_00113913:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "leal -0x20(%ebp), %eax\n" /* line 73 | Triangles */
        "cmpl %eax, %ebx\n"
        "je .Lf113434_0011394e\n"
        "movl %ebx, %eax\n"
        "jmp .Lf113434_00113913\n"
        "movl %eax, %esi\n"
        "movl -0x3c(%ebp), %ebx\n" /* line 131 */
        "movl -0x4c(%ebp), %eax\n"
        "movl -0x44(%ebp), %ecx\n"
        "movl -0x40(%ebp), %edx\n"
        ".Lf113434_00113936:\n"
        "cmpl %eax, %ebx\n" /* line 173 */
        "je .Lf113434_00113956\n"
        "addl $2, %eax\n" /* line 144 */
        "cmpl %ecx, %eax\n" /* line 145 */
        "jne .Lf113434_00113936\n"
        "addl $4, %edx\n" /* line 147 */
        "movl (%edx), %eax\n" /* line 232 */
        "leal 0x200(%eax), %ecx\n" /* line 233 */
        "jmp .Lf113434_00113936\n"
        ".Lf113434_0011394e:\n"
        "movl %esi, (%esp)\n" /* line 392 | NumTriangles */
        "calll __Unwind_Resume\n"
        ".Lf113434_00113956:\n"
        "leal -0x54(%ebp), %ecx\n" /* line 715 | FIFO */
        "movl %ecx, (%esp)\n"
        "calll ZNSt11_Deque_baseItSaItEED2Ev\n"
        "jmp .Lf113434_00113909\n"
    );
}

/* line 424 */
__attribute__((naked))
void ZNSt11_Deque_baseItSaItEED2Ev(void) /* std__Deque_base<unsigned short, std_allocator<unsigned short> >_~_Deque_base */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 424 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl (%esi), %eax\n" /* line 426 | this */
        "testl %eax, %eax\n"
        "je .Lf2c04e2_002c0536\n"
        "movl 0x24(%esi), %edi\n" /* line 428 | this, __nfinish */
        "addl $4, %edi\n" /* __nfinish */
        "movl 0x14(%esi), %ebx\n" /* this */
        /* { scope 1 */
        /* { scope 2 */
        "cmpl %ebx, %edi\n" /* line 506 | __n, __nfinish */
        "ja .Lf2c04e2_002c0512\n"
        /* } scope */
        /* } scope */
        ".Lf2c04e2_002c0501:\n"
        "movl (%esi), %eax\n" /* line 94 */
        "movl %eax, 8(%ebp)\n" /* this */
        "addl $0x1c, %esp\n" /* line 430 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n" /* line 94 */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf2c04e2_002c0512:\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "addl $4, %ebx\n" /* line 506 | __n */
        "cmpl %ebx, %edi\n" /* __n, __nfinish */
        "jbe .Lf2c04e2_002c0501\n"
        "movl (%ebx), %eax\n" /* line 94 */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "addl $4, %ebx\n" /* line 506 | __n */
        "cmpl %ebx, %edi\n" /* __n, __nfinish */
        "ja .Lf2c04e2_002c0512\n"
        "jmp .Lf2c04e2_002c0501\n"
        /* } scope */
        /* } scope */
        ".Lf2c04e2_002c0536:\n"
        "addl $0x1c, %esp\n" /* line 430 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 723 */
__attribute__((naked))
void ZNSt5dequeItSaItEE17_M_reallocate_mapEmb(void) /* std_deque<unsigned short, std_allocator<unsigned short> >__M_reallocate_map */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 723 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movzbl 0x10(%ebp), %eax\n" /* __add_at_front */
        "movb %al, -0x21(%ebp)\n" /* __add_at_front */
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 726 | this */
        "movl 0x24(%edx), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x14(%ecx), %edi\n"
        "movl %edx, %eax\n"
        "subl %edi, %eax\n"
        "sarl $2, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* __old_num_nodes */
        "movl 0xc(%ebp), %ecx\n" /* line 727 | __nodes_to_add */
        "movl %eax, %ebx\n" /* __new_num_nodes */
        "addl %ecx, %ebx\n" /* __new_num_nodes */
        "movl 8(%ebp), %esi\n" /* line 730 | this, __result */
        "movl 4(%esi), %edx\n" /* __result */
        "leal (%ebx, %ebx), %eax\n" /* __new_nstart */
        "cmpl %eax, %edx\n"
        "jbe .Lf2c053e_002c05c6\n"
        "subl %ebx, %edx\n" /* line 732 | __new_nstart */
        "shrl $1, %edx\n"
        "movl (%esi), %eax\n" /* __result */
        "leal (%eax, %edx, 4), %eax\n"
        "cmpb $0, -0x21(%ebp)\n" /* __add_at_front */
        "je .Lf2c053e_002c0698\n"
        "leal (, %ecx, 4), %edx\n"
        "leal (%edx, %eax), %ebx\n" /* __new_nstart */
        "cmpl %ebx, %edi\n" /* line 735 | __new_nstart */
        "jbe .Lf2c053e_002c06a5\n"
        /* { scope 2 */
        ".Lf2c053e_002c05a3:\n"
        "movl -0x20(%ebp), %eax\n" /* line 300 */
        "addl $4, %eax\n"
        "subl %edi, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memmove\n"
        "movl -0x1c(%ebp), %eax\n" /* __old_num_nodes */
        "leal (%ebx, %eax, 4), %esi\n"
        "jmp .Lf2c053e_002c064a\n"
        ".Lf2c053e_002c05c6:\n"
        "movl %esi, %eax\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        "addl $4, %eax\n" /* line 425 */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        "movl 8(%ebp), %esi\n" /* line 211 | this */
        "cmpl 4(%esi), %ecx\n"
        "ja .Lf2c053e_002c0682\n"
        /* } scope */
        "addl (%eax), %edx\n" /* line 748 */
        "leal 2(%edx), %esi\n" /* __new_map_size */
        "cmpl $0x3fffffff, %esi\n" /* line 85 */
        "ja .Lf2c053e_002c06da\n"
        ".Lf2c053e_002c05e8:\n"
        "leal (, %esi, 4), %eax\n" /* line 88 */
        "movl %eax, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, %edi\n"
        "movl %esi, %eax\n" /* line 751 | __new_map_size */
        "subl %ebx, %eax\n" /* __new_nstart */
        "shrl $1, %eax\n"
        "leal (%edi, %eax, 4), %edx\n" /* __new_map */
        "cmpb $0, -0x21(%ebp)\n" /* __add_at_front */
        "jne .Lf2c053e_002c06cf\n"
        "xorl %eax, %eax\n"
        ".Lf2c053e_002c060e:\n"
        "leal (%eax, %edx), %ebx\n" /* __new_nstart */
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x14(%edx), %eax\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl 0x24(%edx), %edx\n" /* line 300 */
        "addl $4, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 94 | this */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "movl 8(%ebp), %ecx\n" /* line 758 | this */
        "movl %edi, (%ecx)\n" /* __new_map */
        "movl %esi, 4(%ecx)\n" /* line 759 | __new_map_size */
        "movl -0x1c(%ebp), %eax\n" /* __old_num_nodes */
        "leal (%ebx, %eax, 4), %esi\n" /* __new_nstart, __new_map_size */
        /* } scope */
        ".Lf2c053e_002c064a:\n"
        "movl 8(%ebp), %edx\n" /* line 762 | this */
        "addl $8, %edx\n" /* this */
        /* { scope 2 */
        "movl %ebx, 0xc(%edx)\n" /* line 231 */
        "movl (%ebx), %eax\n" /* line 232 */
        "movl %eax, 4(%edx)\n"
        "addl $0x200, %eax\n" /* line 233 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal -4(%esi), %eax\n" /* line 763 | __new_map_size, __new_node */
        "movl 8(%ebp), %edx\n" /* this */
        "addl $0x18, %edx\n" /* this */
        /* { scope 2 */
        "movl %eax, 0xc(%edx)\n" /* line 231 */
        "movl -4(%esi), %eax\n" /* line 232 */
        "movl %eax, 4(%edx)\n"
        "addl $0x200, %eax\n" /* line 233 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 763 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf2c053e_002c0682:\n"
        "leal 0xc(%ebp), %eax\n" /* line 211 | __nodes_to_add */
        /* } scope */
        "addl (%eax), %edx\n" /* line 748 */
        "leal 2(%edx), %esi\n" /* __new_map_size */
        "cmpl $0x3fffffff, %esi\n" /* line 85 */
        "jbe .Lf2c053e_002c05e8\n"
        "jmp .Lf2c053e_002c06da\n"
        /* } scope */
        ".Lf2c053e_002c0698:\n"
        "xorl %edx, %edx\n" /* line 732 */
        "leal (%edx, %eax), %ebx\n" /* __new_nstart */
        "cmpl %ebx, %edi\n" /* line 735 | __new_nstart */
        "ja .Lf2c053e_002c05a3\n"
        ".Lf2c053e_002c06a5:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 740 | __old_num_nodes */
        "leal (%ebx, %edx, 4), %esi\n" /* __new_nstart, __result */
        /* { scope 2 */
        "movl -0x20(%ebp), %eax\n" /* line 424 */
        "addl $4, %eax\n"
        "subl %edi, %eax\n"
        "andl $0xfffffffc, %eax\n" /* line 425 */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %esi, %ecx\n"
        "subl %eax, %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll memmove\n"
        "jmp .Lf2c053e_002c064a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf2c053e_002c06cf:\n"
        "movl 0xc(%ebp), %eax\n" /* line 751 | __nodes_to_add */
        "shll $2, %eax\n"
        "jmp .Lf2c053e_002c060e\n"
        ".Lf2c053e_002c06da:\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
    );
}

/* line 345 */
__attribute__((naked))
void ZNSt5dequeItSaItEE16_M_push_back_auxERKt(void) /* std_deque<unsigned short, std_allocator<unsigned short> >__M_push_back_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 345 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 347 | __t */
        "movzwl (%eax), %edi\n" /* __t_copy */
        "movl 0x24(%esi), %ebx\n" /* line 1445 | this */
        "movl %ebx, %edx\n"
        "subl (%esi), %edx\n" /* this */
        "sarl $2, %edx\n"
        "movl 4(%esi), %eax\n" /* this */
        "subl %edx, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf2c06e8_002c074f\n"
        ".Lf2c06e8_002c070e:\n"
        "movl $0x200, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %eax, 4(%ebx)\n" /* line 349 */
        "movl 0x18(%esi), %eax\n" /* this */
        "testl %eax, %eax\n" /* line 104 */
        "je .Lf2c06e8_002c0727\n"
        "movw %di, (%eax)\n"
        ".Lf2c06e8_002c0727:\n"
        "movl 0x24(%esi), %ecx\n" /* line 353 | this */
        "leal 4(%ecx), %eax\n" /* __new_node */
        "leal 0x18(%esi), %edx\n" /* this */
        /* { scope 2 */
        "movl %eax, 0xc(%edx)\n" /* line 231 */
        "movl 4(%ecx), %eax\n" /* line 232 */
        "movl %eax, 4(%edx)\n"
        "addl $0x200, %eax\n" /* line 233 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x1c(%esi), %eax\n" /* line 355 | this */
        "movl %eax, 0x18(%esi)\n" /* this */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 360 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c06e8_002c074f:\n"
        "movl $0, 8(%esp)\n" /* line 1447 */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll ZNSt5dequeItSaItEE17_M_reallocate_mapEmb\n"
        "movl 0x24(%esi), %ebx\n" /* this */
        "jmp .Lf2c06e8_002c070e\n"
    );
}

/* line 172 */
__attribute__((naked))
void ZNSt5dequeItSaItEE5clearEv(void) /* std_deque<unsigned short, std_allocator<unsigned short> >_clear */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 172 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1 */
        "movl 0x14(%esi), %ebx\n" /* line 174 | this, __node */
        "addl $4, %ebx\n" /* __node */
        "movl 0x24(%esi), %eax\n" /* this */
        "cmpl %eax, %ebx\n" /* __node */
        "jae .Lf2c076c_002c07a2\n"
        ".Lf2c076c_002c0784:\n"
        "movl (%ebx), %edx\n" /* line 178 | __node */
        "movl $0x100, %eax\n" /* line 173 */
        ".Lf2c076c_002c078b:\n"
        "subl $1, %eax\n"
        "jne .Lf2c076c_002c078b\n"
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "addl $4, %ebx\n" /* line 174 | __node */
        "movl 0x24(%esi), %eax\n" /* this */
        "cmpl %ebx, %eax\n" /* __node */
        "ja .Lf2c076c_002c0784\n"
        /* } scope */
        ".Lf2c076c_002c07a2:\n"
        "cmpl %eax, 0x14(%esi)\n" /* line 183 | this */
        "je .Lf2c076c_002c07f2\n"
        "movl 0x10(%esi), %edx\n" /* line 185 | this, __last */
        "movl 8(%esi), %eax\n" /* this */
        /* { scope 1 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2c076c_002c07b8\n"
        ".Lf2c076c_002c07b1:\n"
        "addl $2, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2c076c_002c07b1\n"
        /* } scope */
        ".Lf2c076c_002c07b8:\n"
        "movl 0x18(%esi), %ecx\n" /* line 188 | this, __last */
        "movl 0x1c(%esi), %edx\n" /* this */
        /* { scope 1 */
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf2c076c_002c07cb\n"
        "movl %edx, %eax\n"
        ".Lf2c076c_002c07c4:\n"
        "addl $2, %eax\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf2c076c_002c07c4\n"
        /* } scope */
        ".Lf2c076c_002c07cb:\n"
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "movl 8(%esi), %edx\n"
        ".Lf2c076c_002c07d6:\n"
        "movl %edx, 0x18(%esi)\n" /* line 198 | this */
        "movl 0xc(%esi), %eax\n" /* this */
        "movl %eax, 0x1c(%esi)\n" /* this */
        "movl 0x10(%esi), %eax\n" /* this */
        "movl %eax, 0x20(%esi)\n" /* this */
        "movl 0x14(%esi), %eax\n" /* this */
        "movl %eax, 0x24(%esi)\n" /* this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2c076c_002c07f2:\n"
        "movl 0x18(%esi), %ecx\n" /* line 194 | this, __last */
        "movl 8(%esi), %edx\n" /* this */
        "movl %edx, %eax\n"
        /* { scope 1 */
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf2c076c_002c07d6\n"
        ".Lf2c076c_002c07fe:\n"
        "addl $2, %eax\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf2c076c_002c07fe\n"
        /* } scope */
        "movl %edx, 0x18(%esi)\n" /* line 198 | this */
        "movl 0xc(%esi), %eax\n" /* this */
        "movl %eax, 0x1c(%esi)\n" /* this */
        "movl 0x10(%esi), %eax\n" /* this */
        "movl %eax, 0x20(%esi)\n" /* this */
        "movl 0x14(%esi), %eax\n" /* this */
        "movl %eax, 0x24(%esi)\n" /* this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 447 */
__attribute__((naked))
void ZNSt11_Deque_baseItSaItEE17_M_initialize_mapEm(void) /* std__Deque_base<unsigned short, std_allocator<unsigned short> >__M_initialize_map */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 447 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 450 | __num_elements */
        "shrl $8, %eax\n"
        "leal 1(%eax), %ebx\n" /* __num_nodes */
        "addl $3, %eax\n" /* line 452 | __b */
        "movl %eax, -0x20(%ebp)\n" /* __b */
        "movl $8, -0x1c(%ebp)\n"
        /* { scope 2 */
        "cmpl $8, %eax\n" /* line 211 */
        "jbe .Lf2c0822_002c08d2\n"
        "leal -0x20(%ebp), %eax\n"
        /* } scope */
        ".Lf2c0822_002c084d:\n"
        "movl (%eax), %eax\n" /* line 452 | __b */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n" /* __b */
        "cmpl $0x3fffffff, %eax\n" /* line 85 */
        "ja .Lf2c0822_002c08f3\n"
        "shll $2, %eax\n" /* line 88 */
        "movl %eax, (%esp)\n"
        "calll __Znwm\n"
        "movl 8(%ebp), %ecx\n" /* line 454 | this */
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %edx\n" /* line 462 */
        "subl %ebx, %edx\n" /* __num_nodes */
        "shrl $1, %edx\n"
        "leal (%eax, %edx, 4), %edi\n" /* __nstart */
        "leal (%edi, %ebx, 4), %esi\n" /* line 463 | __nstart, __nfinish */
        "cmpl %esi, %edi\n" /* line 491 | __nfinish, __nstart */
        "jb .Lf2c0822_002c08da\n"
        ".Lf2c0822_002c0881:\n"
        "movl 8(%ebp), %edx\n" /* line 475 | this */
        "addl $8, %edx\n" /* this */
        /* { scope 2 */
        "movl %edi, 0xc(%edx)\n" /* line 231 */
        "movl (%edi), %eax\n" /* line 232 */
        "movl %eax, 4(%edx)\n"
        "addl $0x200, %eax\n" /* line 233 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal -4(%esi), %eax\n" /* line 476 | __nfinish, __new_node */
        "movl 8(%ebp), %edx\n" /* this */
        "addl $0x18, %edx\n" /* this */
        /* { scope 2 */
        "movl %eax, 0xc(%edx)\n" /* line 231 */
        "movl -4(%esi), %eax\n" /* line 232 */
        "movl %eax, 4(%edx)\n"
        "addl $0x200, %eax\n" /* line 233 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 477 | this */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movzbl 0xc(%ebp), %eax\n" /* line 478 | __num_elements */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x1c(%ecx), %edx\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, 0x18(%ecx)\n"
        /* } scope */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf2c0822_002c08d2:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 211 */
        "jmp .Lf2c0822_002c084d\n"
        /* } scope */
        ".Lf2c0822_002c08da:\n"
        "movl %edi, %ebx\n" /* line 105 */
        ".Lf2c0822_002c08dc:\n"
        "movl $0x200, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %eax, (%ebx)\n" /* line 492 | __num_nodes */
        "addl $4, %ebx\n" /* line 491 | __num_nodes */
        "cmpl %ebx, %esi\n" /* __num_nodes, __nfinish */
        "ja .Lf2c0822_002c08dc\n"
        "jmp .Lf2c0822_002c0881\n"
        ".Lf2c0822_002c08f3:\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
        "movl %eax, (%esp)\n" /* line 494 */
        "calll ___cxa_begin_catch\n"
        "cmpl %ebx, %edi\n" /* line 506 | __num_nodes, __nstart */
        "jb .Lf2c0822_002c0911\n"
        ".Lf2c0822_002c090c:\n"
        "calll ___cxa_rethrow\n" /* line 497 */
        ".Lf2c0822_002c0911:\n"
        "movl (%edi), %eax\n" /* line 94 */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "addl $4, %edi\n" /* line 506 | __nstart */
        "cmpl %edi, %ebx\n" /* __nstart, __num_nodes */
        "ja .Lf2c0822_002c0911\n"
        "jmp .Lf2c0822_002c090c\n"
        "movl %eax, %esi\n" /* __nfinish */
        "calll ___cxa_end_catch\n" /* line 494 */
        "movl %esi, (%esp)\n" /* line 467 | __nfinish */
        "calll ___cxa_begin_catch\n"
        "movl 8(%ebp), %edx\n" /* line 94 | this */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "movl 8(%ebp), %ecx\n" /* line 470 | this */
        "movl $0, (%ecx)\n"
        "movl $0, 4(%ecx)\n" /* line 471 */
        "calll ___cxa_rethrow\n" /* line 472 */
        "movl %eax, %esi\n" /* __nfinish */
        "calll ___cxa_end_catch\n" /* line 467 */
        "movl %esi, (%esp)\n" /* __nfinish */
        "calll __Unwind_Resume\n"
    );
}
