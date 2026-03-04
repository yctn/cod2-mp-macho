/* ASM dump from: CDirect3DVertexBuffer.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DVertexBuffer.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DVertexBuffer.h"
 *   #include "Mac/DirectX 9/COpenGL.h"
 */

ULONG CDirect3DVertexBuffer_AddRef(const CDirect3DVertexBuffer * _this);
HRESULT CDirect3DVertexBuffer_QueryInterface(const CDirect3DVertexBuffer * _this, const IID *iid, void * *ppvObj);
ULONG CDirect3DVertexBuffer_Release(const CDirect3DVertexBuffer * _this);
HRESULT CDirect3DVertexBuffer_Unlock(const CDirect3DVertexBuffer * _this);
HRESULT CDirect3DVertexBuffer_GetDesc(const CDirect3DVertexBuffer * _this, void (*pDesc)());
void ZN16CStaticCacheInfoD0Ev(void); /* CStaticCacheInfo_~CStaticCacheInfo */
void CStaticCacheInfo_Flush(const CStaticCacheInfo * _this, void (*pStart)(), void (*pEnd)());
void CDirect3DVertexBuffer_WaitFence(const CDirect3DVertexBuffer * _this, const void * pStart, UINT32 SizeInBytes);
HRESULT CDirect3DVertexBuffer_Lock(const CDirect3DVertexBuffer * _this, UINT OffsetToLock, UINT SizeToLock, void * *ppbDat, DWORD Flags);
void ZN21CDirect3DVertexBufferD0Ev(void); /* CDirect3DVertexBuffer_~CDirect3DVertexBuffer */
void ZN21CDirect3DVertexBufferD1Ev(void); /* CDirect3DVertexBuffer_~CDirect3DVertexBuffer */
void ZN21CDirect3DVertexBufferD2Ev(void); /* CDirect3DVertexBuffer_~CDirect3DVertexBuffer */
void CDirect3DVertexBuffer_SetFence(const CDirect3DVertexBuffer * _this, const void * pStart, UINT32 SizeInBytes, const CDirect3DVertexBuffer * _this_3);
void CDirect3DVertexBuffer_CDirect3DVertexBuffer(const CDirect3DVertexBuffer * _this, UINT32 Length, DWORD Usage, D3DPOOL Pool);
void ZN16CStaticCacheInfoD2Ev(void); /* CStaticCacheInfo_~CStaticCacheInfo */
void ZN16CStaticCacheInfoD1Ev(void); /* CStaticCacheInfo_~CStaticCacheInfo */
void ZN15CCacheInfoBlockD1Ev(void); /* CCacheInfoBlock_~CCacheInfoBlock */
void ZN15CCacheInfoBlockD0Ev(void); /* CCacheInfoBlock_~CCacheInfoBlock */
HRESULT CDirect3DVertexBuffer_GetDevice(const CDirect3DVertexBuffer * _this, IDirect3DDevice9 * *ppDevice);
HRESULT CDirect3DVertexBuffer_SetPrivateData(const CDirect3DVertexBuffer * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags);
HRESULT CDirect3DVertexBuffer_GetPrivateData(const CDirect3DVertexBuffer * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData);
HRESULT CDirect3DVertexBuffer_FreePrivateData(const CDirect3DVertexBuffer * _this, const GUID *refguid);
DWORD CDirect3DVertexBuffer_SetPriority(const CDirect3DVertexBuffer * _this, DWORD PriorityNew);
DWORD CDirect3DVertexBuffer_GetPriority(const CDirect3DVertexBuffer * _this);
void CDirect3DVertexBuffer_PreLoad(const CDirect3DVertexBuffer * _this);
D3DRESOURCETYPE CDirect3DVertexBuffer_GetType(const CDirect3DVertexBuffer * _this);
void ZNSt4listIP6CFenceSaIS1_EE5eraseESt14_List_iteratorIS1_E(void); /* std_list<CFence*, std_allocator<CFence*> >_erase */
void ZNSt6vectorI15CCacheInfoBlockSaIS0_EEC1Em(void); /* std_vector<CCacheInfoBlock, std_allocator<CCacheInfoBlock> >_vector */
void ZNSt6vectorImSaImEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPmS1_EERKm(void); /* std_vector<unsigned long, std_allocator<unsigned long> >__M_insert_aux */

/* line 144 */
__attribute__((naked))
ULONG CDirect3DVertexBuffer_AddRef(const CDirect3DVertexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 144 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n" /* line 146 */
        "addl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "popl %ebp\n" /* line 147 */
        "retl\n"
    );
}

/* line 133 */
__attribute__((naked))
HRESULT CDirect3DVertexBuffer_QueryInterface(const CDirect3DVertexBuffer * _this, const IID *iid, void * *ppvObj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 133 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 135 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 136 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 139 */
        "leave\n"
        "retl\n"
    );
}

/* line 152 */
__attribute__((naked))
ULONG CDirect3DVertexBuffer_Release(const CDirect3DVertexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 152 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %ebx\n" /* line 154 */
        "subl $1, %ebx\n"
        "movl %ebx, 4(%edx)\n"
        "testl %ebx, %ebx\n" /* line 156 */
        "jne .Lf1f284_0001f2a3\n"
        "movl (%edx), %eax\n" /* line 158 */
        "movl %edx, (%esp)\n"
        "calll *0x3c(%eax)\n"
        ".Lf1f284_0001f2a3:\n"
        "movl %ebx, %eax\n" /* line 162 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 251 */
__attribute__((naked))
HRESULT CDirect3DVertexBuffer_Unlock(const CDirect3DVertexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 251 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 254 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 259 */
__attribute__((naked))
HRESULT CDirect3DVertexBuffer_GetDesc(const CDirect3DVertexBuffer * _this, void (*pDesc)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 259 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* pDesc */
        "movl $0, (%edx)\n" /* line 264 */
        "movl $6, 4(%edx)\n" /* line 265 */
        "movl 0x20(%ecx), %eax\n" /* line 266 */
        "movl %eax, 8(%edx)\n"
        "movl $0, 0xc(%edx)\n" /* line 267 */
        "movl 8(%ecx), %eax\n" /* line 268 */
        "movl %eax, 0x10(%edx)\n"
        "movl $0, 0x14(%edx)\n" /* line 269 */
        "xorl %eax, %eax\n" /* line 272 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 29 */
__attribute__((naked))
void ZN16CStaticCacheInfoD0Ev(void) /* CStaticCacheInfo_~CStaticCacheInfo */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl $vtbl_CStaticCacheInfo, (%edi)\n" /* this */
        "leal 0x10(%edi), %eax\n" /* line 31 | this */
        "movl %eax, -0x1c(%ebp)\n" /* this */
        /* { scope 1 */
        "movl 4(%eax), %esi\n" /* line 273 | __last */
        "movl 0x10(%edi), %ebx\n" /* this, __p */
        /* { scope 2 */
        "cmpl %ebx, %esi\n" /* line 173 */
        "je .Lf1f2e8_0001f338\n"
        /* { scope 3 */
        ".Lf1f2e8_0001f30a:\n"
        "movl (%ebx), %eax\n" /* line 107 */
        "movl %ebx, (%esp)\n"
        "calll *(%eax)\n"
        /* } scope */
        "addl $8, %ebx\n" /* line 173 */
        "cmpl %ebx, %esi\n"
        "jne .Lf1f2e8_0001f30a\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        /* } scope */
        ".Lf1f2e8_0001f31b:\n"
        "movl (%edx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1f2e8_0001f329\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf1f2e8_0001f329:\n"
        "movl %edi, 8(%ebp)\n" /* line 31 | this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        ".Lf1f2e8_0001f338:\n"
        "movl %eax, %edx\n"
        "jmp .Lf1f2e8_0001f31b\n"
        "movl %eax, %ebx\n"
        /* { scope 1 */
        "movl -0x1c(%ebp), %edx\n" /* line 109 | this */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1f2e8_0001f34f\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        ".Lf1f2e8_0001f34f:\n"
        "movl %ebx, (%esp)\n" /* line 109 */
        "calll __Unwind_Resume\n"
    );
}

/* line 51 */
__attribute__((naked))
void CStaticCacheInfo_Flush(const CStaticCacheInfo * _this, void (*pStart)(), void (*pEnd)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 53 | this */
        "movl 8(%edx), %eax\n"
        "subl %eax, 0xc(%ebp)\n" /* line 56 | pStart */
        "shrl $0xa, 0xc(%ebp)\n" /* pStart */
        "movl 0x10(%ebp), %edx\n" /* line 57 | pEnd */
        "subl %eax, %edx\n" /* EndBlock */
        "js .Lf1f35a_0001f41e\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1f35a_0001f37f:\n"
        "mulss lit4_002ed60c, %xmm0\n" /* 0.0009765625f */
        "movss %xmm0, (%esp)\n"
        "calll ceilf\n"
        "fnstcw -0x1a(%ebp)\n"
        "movzwl -0x1a(%ebp), %eax\n" /* EndBlock */
        "movb $0xc, %ah\n" /* EndBlock */
        "movw %ax, -0x1c(%ebp)\n" /* EndBlock */
        "fldcw -0x1c(%ebp)\n"
        "fistpll -0x28(%ebp)\n"
        "fldcw -0x1a(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* EndBlock */
        "cmpl %eax, 0xc(%ebp)\n" /* line 60 | pStart */
        "jae .Lf1f35a_0001f416\n"
        "movl 0xc(%ebp), %ebx\n" /* pStart */
        "shll $3, %ebx\n"
        "movl 0xc(%ebp), %esi\n" /* pStart */
        "shll $0xa, %esi\n"
        "xorl %edi, %edi\n"
        "subl 0xc(%ebp), %eax\n" /* pStart */
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf1f35a_0001f3d6\n"
        ".Lf1f35a_0001f3c5:\n"
        "addl $1, %edi\n" /* line 45 */
        "addl $8, %ebx\n"
        "addl $0x400, %esi\n"
        "cmpl %edi, -0x2c(%ebp)\n" /* line 60 */
        "je .Lf1f35a_0001f416\n"
        ".Lf1f35a_0001f3d6:\n"
        "movl %ebx, %eax\n" /* line 654 */
        "movl 8(%ebp), %edx\n" /* this */
        "addl 0x10(%edx), %eax\n"
        "cmpb $0, 4(%eax)\n" /* line 62 */
        "je .Lf1f35a_0001f3c5\n"
        "movl %esi, %eax\n" /* line 64 */
        "addl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x400, (%esp)\n"
        "calll glFlushVertexArrayRangeAPPLE\n"
        "movl %ebx, %eax\n" /* line 654 */
        "movl 8(%ebp), %edx\n" /* this */
        "addl 0x10(%edx), %eax\n"
        "movb $0, 4(%eax)\n" /* line 45 */
        "addl $1, %edi\n"
        "addl $8, %ebx\n"
        "addl $0x400, %esi\n"
        "cmpl %edi, -0x2c(%ebp)\n" /* line 60 */
        "jne .Lf1f35a_0001f3d6\n"
        /* } scope */
        ".Lf1f35a_0001f416:\n"
        "addl $0x3c, %esp\n" /* line 68 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f35a_0001f41e:\n"
        "movl %edx, %eax\n" /* line 57 | EndBlock */
        "shrl $1, %eax\n" /* EndBlock */
        "andl $1, %edx\n"
        "orl %edx, %eax\n" /* EndBlock */
        "cvtsi2ssl %eax, %xmm0\n" /* EndBlock */
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1f35a_0001f37f\n"
    );
}

/* line 279 */
__attribute__((naked))
void CDirect3DVertexBuffer_WaitFence(const CDirect3DVertexBuffer * _this, const void * pStart, UINT32 SizeInBytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 279 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        /* { scope 1 */
        "movl imp___ZN7COpenGL11sFrameCountE, %eax\n" /* line 668 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* CurrentTime */
        "leal 0x30(%edx), %edi\n" /* line 289 */
        "movl 0x30(%edx), %esi\n" /* line 580 */
        ".Lf1f434_0001f450:\n"
        "cmpl %esi, %edi\n" /* line 289 */
        "je .Lf1f434_0001f49f\n"
        /* { scope 2 */
        ".Lf1f434_0001f454:\n"
        "movl 8(%esi), %ebx\n" /* line 291 | Fence */
        "movl -0x1c(%ebp), %eax\n" /* line 293 | CurrentTime */
        "subl 0xc(%ebx), %eax\n" /* Fence */
        "cmpl $1, %eax\n"
        "jbe .Lf1f434_0001f4a7\n"
        /* { scope 3 */
        ".Lf1f434_0001f462:\n"
        "testl %ebx, %ebx\n" /* line 330 | pFence */
        "je .Lf1f434_0001f48d\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %ecx\n" /* line 604 */
        "movl 4(%ecx), %edx\n"
        "cmpl 8(%ecx), %edx\n"
        "je .Lf1f434_0001f4c1\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf1f434_0001f47f\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %edx\n"
        ".Lf1f434_0001f47f:\n"
        "leal 4(%edx), %eax\n" /* line 607 */
        "movl %eax, 4(%ecx)\n"
        ".Lf1f434_0001f485:\n"
        "movl %ebx, (%esp)\n" /* line 330 | pFence */
        "calll __ZdlPv\n"
        ".Lf1f434_0001f48d:\n"
        "movl %esi, 4(%esp)\n" /* line 331 */
        "movl %edi, (%esp)\n"
        "calll ZNSt4listIP6CFenceSaIS1_EE5eraseESt14_List_iteratorIS1_E\n"
        "movl %eax, %esi\n"
        /* } scope */
        /* } scope */
        "cmpl %esi, %edi\n" /* line 289 */
        "jne .Lf1f434_0001f454\n"
        /* } scope */
        ".Lf1f434_0001f49f:\n"
        "addl $0x2c, %esp\n" /* line 335 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f434_0001f4a7:\n"
        "movl 0xc(%ebp), %eax\n" /* line 310 | pStart */
        "addl 0x10(%ebp), %eax\n" /* SizeInBytes */
        "cmpl 4(%ebx), %eax\n" /* Fence */
        "jbe .Lf1f434_0001f4bd\n"
        "movl 4(%ebx), %eax\n" /* Fence */
        "addl 8(%ebx), %eax\n" /* Fence */
        "cmpl %eax, 0xc(%ebp)\n" /* pStart */
        "jb .Lf1f434_0001f4d3\n"
        ".Lf1f434_0001f4bd:\n"
        "movl (%esi), %esi\n" /* line 140 */
        "jmp .Lf1f434_0001f450\n"
        /* { scope 3 */
        ".Lf1f434_0001f4c1:\n"
        "movl %ebx, 8(%esp)\n" /* line 610 | pFence */
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll ZNSt6vectorImSaImEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPmS1_EERKm\n"
        "jmp .Lf1f434_0001f485\n"
        ".Lf1f434_0001f4d3:\n"
        "movl (%ebx), %eax\n" /* line 318 | Fence */
        "movl %eax, (%esp)\n"
        "calll glFinishFenceAPPLE\n"
        "movl 8(%esi), %ebx\n" /* line 329 | pFence */
        "jmp .Lf1f434_0001f462\n"
    );
}

/* line 172 */
__attribute__((naked))
HRESULT CDirect3DVertexBuffer_Lock(const CDirect3DVertexBuffer * _this, UINT OffsetToLock, UINT SizeToLock, void * *ppbDat, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 172 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* OffsetToLock */
        "movl 0x10(%ebp), %eax\n" /* SizeToLock, ppbDat */
        "movb $1, 0x2c(%edi)\n" /* line 125 */
        "testl %eax, %eax\n" /* line 183 */
        "je .Lf1f4e2_0001f52d\n"
        "movl %eax, %edx\n"
        "movl %edx, 0x28(%edi)\n" /* this */
        "testb $2, 0x21(%edi)\n" /* line 189 | this */
        "je .Lf1f4e2_0001f539\n"
        ".Lf1f4e2_0001f507:\n"
        "testl $0x2000, 0x18(%ebp)\n" /* line 193 | Flags */
        "jne .Lf1f4e2_0001f563\n"
        "testb $1, 0x18(%ebp)\n" /* line 211 | Flags */
        "jne .Lf1f4e2_0001f595\n"
        ".Lf1f4e2_0001f516:\n"
        "addl 0x14(%edi), %esi\n" /* line 218 | this, OffsetToLock */
        "movl %esi, 0x24(%edi)\n" /* OffsetToLock, this */
        "movl %esi, %edx\n" /* OffsetToLock */
        "movl 0x14(%ebp), %eax\n" /* line 243 | ppbDat */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n" /* line 246 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f4e2_0001f52d:\n"
        "movl 8(%edi), %edx\n" /* line 183 | this */
        "movl %edx, 0x28(%edi)\n" /* this */
        "testb $2, 0x21(%edi)\n" /* line 189 | this */
        "jne .Lf1f4e2_0001f507\n"
        ".Lf1f4e2_0001f539:\n"
        "movl %esi, %eax\n" /* line 238 | OffsetToLock */
        "addl 0x14(%edi), %eax\n" /* this */
        "movl %eax, 0x24(%edi)\n" /* this */
        "movl %edx, 8(%esp)\n" /* line 240 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* this */
        "calll CDirect3DVertexBuffer_WaitFence\n"
        "movl 0x24(%edi), %edx\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* line 243 | ppbDat */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n" /* line 246 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f4e2_0001f563:\n"
        "leal 0xc(%edi), %ebx\n" /* line 203 | this */
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CMemoryBuffer_FreeLater\n"
        "movl %ebx, (%esp)\n" /* line 204 */
        "calll CMemoryBuffer_Recreate\n"
        "addl 8(%ebx), %esi\n" /* line 206 | OffsetToLock */
        "movl %esi, 0x24(%edi)\n" /* OffsetToLock, this */
        "movl %esi, %edx\n" /* OffsetToLock */
        "movl 0x14(%ebp), %eax\n" /* line 243 | ppbDat */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n" /* line 246 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f4e2_0001f595:\n"
        "movl 0x38(%edi), %eax\n" /* line 214 | this */
        "movl %eax, -0x30(%ebp)\n" /* this */
        /* { scope 1 */
        /* { scope 2: i */
        "movl %esi, %eax\n" /* line 38 */
        "shrl $0xa, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* i */
        "addl %esi, %edx\n" /* line 39 */
        "js .Lf1f4e2_0001f609\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf1f4e2_0001f5ab:\n"
        "mulss lit4_002ed60c, %xmm0\n" /* 0.0009765625f */
        "movss %xmm0, (%esp)\n"
        "calll ceilf\n"
        "fnstcw -0x1a(%ebp)\n"
        "movzwl -0x1a(%ebp), %eax\n" /* EndBlock */
        "movb $0xc, %ah\n" /* EndBlock */
        "movw %ax, -0x1c(%ebp)\n" /* EndBlock */
        "fldcw -0x1c(%ebp)\n"
        "fistpll -0x28(%ebp)\n"
        "fldcw -0x1a(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* EndBlock */
        /* { scope 3 */
        "cmpl %eax, -0x2c(%ebp)\n" /* line 42 | i */
        "jae .Lf1f4e2_0001f516\n"
        "movl -0x2c(%ebp), %ecx\n" /* i */
        "shll $3, %ecx\n"
        "xorl %ebx, %ebx\n"
        "subl -0x2c(%ebp), %eax\n" /* i */
        "movl %eax, -0x3c(%ebp)\n"
        ".Lf1f4e2_0001f5ed:\n"
        "movl -0x30(%ebp), %edx\n" /* line 654 | this */
        "movl 0x10(%edx), %eax\n"
        "addl %ecx, %eax\n"
        "movb $1, 4(%eax)\n" /* line 45 */
        "addl $1, %ebx\n"
        "addl $8, %ecx\n"
        "cmpl -0x3c(%ebp), %ebx\n" /* line 42 */
        "jne .Lf1f4e2_0001f5ed\n"
        "jmp .Lf1f4e2_0001f516\n"
        /* } scope */
        ".Lf1f4e2_0001f609:\n"
        "movl %edx, %eax\n" /* line 39 | EndBlock */
        "shrl $1, %eax\n" /* EndBlock */
        "andl $1, %edx\n"
        "orl %edx, %eax\n" /* EndBlock */
        "cvtsi2ssl %eax, %xmm0\n" /* EndBlock */
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1f4e2_0001f5ab\n"
    );
}

/* line 102 */
__attribute__((naked))
void ZN21CDirect3DVertexBufferD0Ev(void) /* CDirect3DVertexBuffer_~CDirect3DVertexBuffer */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl $vtbl_CDirect3DVertexBuffer, (%edi)\n" /* this */
        "movl 0x38(%edi), %edx\n" /* line 106 | this */
        "testl %edx, %edx\n"
        "je .Lf1f61c_0001f646\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "leal 0xc(%edi), %edx\n" /* this */
        "movl %edx, -0x24(%ebp)\n"
        "leal 0x30(%edi), %esi\n" /* this */
        "calll *4(%eax)\n"
        ".Lf1f61c_0001f646:\n"
        "testb $2, 0x21(%edi)\n" /* line 109 | this */
        "je .Lf1f61c_0001f6fd\n"
        "leal 0xc(%edi), %eax\n" /* this */
        "movl %eax, -0x24(%ebp)\n"
        ".Lf1f61c_0001f656:\n"
        "leal 0x30(%edi), %esi\n" /* line 117 | this */
        "movl 0x30(%edi), %ebx\n" /* line 580 | this */
        "cmpl %esi, %ebx\n" /* line 117 */
        "je .Lf1f61c_0001f6ac\n"
        ".Lf1f61c_0001f660:\n"
        "movl 8(%ebx), %edx\n" /* line 119 */
        "movl %edx, -0x20(%ebp)\n" /* this */
        "testl %edx, %edx\n" /* line 120 */
        "je .Lf1f61c_0001f6a6\n"
        /* { scope 1 */
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %ecx\n" /* line 604 */
        "movl 4(%ecx), %edx\n"
        "cmpl 8(%ecx), %edx\n"
        "je .Lf1f61c_0001f728\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf1f61c_0001f71d\n"
        "movl -0x20(%ebp), %ecx\n" /* this */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %eax\n"
        "movl 4(%eax), %edx\n"
        "movl %eax, %ecx\n"
        ".Lf1f61c_0001f695:\n"
        "addl $4, %edx\n" /* line 607 */
        "movl %edx, 4(%ecx)\n"
        /* } scope */
        ".Lf1f61c_0001f69b:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 120 | this */
        "movl %ecx, (%esp)\n"
        "calll __ZdlPv\n"
        ".Lf1f61c_0001f6a6:\n"
        "movl (%ebx), %ebx\n" /* line 140 */
        "cmpl %esi, %ebx\n" /* line 117 */
        "jne .Lf1f61c_0001f660\n"
        /* { scope 1 */
        ".Lf1f61c_0001f6ac:\n"
        "movl (%esi), %eax\n" /* line 72 */
        "movl %eax, %edx\n" /* line 73 */
        "cmpl %eax, %esi\n"
        "jne .Lf1f61c_0001f6b8\n"
        "jmp .Lf1f61c_0001f6c8\n"
        ".Lf1f61c_0001f6b6:\n"
        "movl %ebx, %edx\n"
        ".Lf1f61c_0001f6b8:\n"
        "movl (%edx), %ebx\n" /* line 76 */
        /* { scope 2 */
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 73 */
        "cmpl %esi, %ebx\n"
        "jne .Lf1f61c_0001f6b6\n"
        /* } scope */
        ".Lf1f61c_0001f6c8:\n"
        "movl %eax, (%esi)\n" /* line 340 */
        "movl %eax, 4(%esi)\n" /* line 341 */
        /* { scope 1 */
        "cmpl %esi, %eax\n" /* line 73 */
        "jne .Lf1f61c_0001f6d5\n"
        "jmp .Lf1f61c_0001f6e3\n"
        ".Lf1f61c_0001f6d3:\n"
        "movl %ebx, %eax\n"
        ".Lf1f61c_0001f6d5:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "cmpl %esi, %ebx\n" /* line 73 */
        "jne .Lf1f61c_0001f6d3\n"
        /* } scope */
        ".Lf1f61c_0001f6e3:\n"
        "movl -0x24(%ebp), %ecx\n" /* line 124 */
        "movl %ecx, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl %edi, 8(%ebp)\n" /* this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        ".Lf1f61c_0001f6fd:\n"
        "leal 0xc(%edi), %ecx\n" /* line 112 | this */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "leal 0x30(%edi), %esi\n" /* this */
        "calll CVAOPacket_ReleaseBuffer\n"
        "jmp .Lf1f61c_0001f656\n"
        ".Lf1f61c_0001f71d:\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %ecx\n"
        "jmp .Lf1f61c_0001f695\n"
        /* { scope 1 */
        ".Lf1f61c_0001f728:\n"
        "movl -0x20(%ebp), %eax\n" /* line 610 | this */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorImSaImEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPmS1_EERKm\n"
        "jmp .Lf1f61c_0001f69b\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* } scope */
        "movl 0x30(%edi), %eax\n" /* line 72 */
        "cmpl %esi, %eax\n" /* line 73 */
        "je .Lf1f61c_0001f762\n"
        ".Lf1f61c_0001f750:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "cmpl %esi, %ebx\n" /* line 73 */
        "je .Lf1f61c_0001f762\n"
        "movl %ebx, %eax\n"
        "jmp .Lf1f61c_0001f750\n"
        ".Lf1f61c_0001f762:\n"
        "movl -0x24(%ebp), %eax\n" /* line 124 */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll __Unwind_Resume\n"
        "nop\n"
    );
}

/* line 102 */
__attribute__((naked))
void ZN21CDirect3DVertexBufferD1Ev(void) /* CDirect3DVertexBuffer_~CDirect3DVertexBuffer */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DVertexBuffer, (%ebx)\n" /* this */
        "movl 0x38(%ebx), %edx\n" /* line 106 | this */
        "testl %edx, %edx\n"
        "je .Lf1f77a_0001f7a4\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "leal 0xc(%ebx), %edx\n" /* this */
        "movl %edx, -0x20(%ebp)\n"
        "leal 0x30(%ebx), %esi\n" /* this */
        "calll *4(%eax)\n"
        ".Lf1f77a_0001f7a4:\n"
        "testb $2, 0x21(%ebx)\n" /* line 109 | this */
        "je .Lf1f77a_0001f853\n"
        "leal 0xc(%ebx), %eax\n" /* this */
        "movl %eax, -0x20(%ebp)\n"
        ".Lf1f77a_0001f7b4:\n"
        "leal 0x30(%ebx), %esi\n" /* line 117 | this */
        "movl 0x30(%ebx), %edi\n" /* line 580 | this */
        "cmpl %esi, %edi\n" /* line 117 */
        "je .Lf1f77a_0001f80a\n"
        ".Lf1f77a_0001f7be:\n"
        "movl 8(%edi), %edx\n" /* line 119 */
        "movl %edx, -0x1c(%ebp)\n" /* this */
        "testl %edx, %edx\n" /* line 120 */
        "je .Lf1f77a_0001f804\n"
        /* { scope 1 */
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %ecx\n" /* line 604 */
        "movl 4(%ecx), %edx\n"
        "cmpl 8(%ecx), %edx\n"
        "je .Lf1f77a_0001f87e\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf1f77a_0001f873\n"
        "movl -0x1c(%ebp), %ecx\n" /* this */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %eax\n"
        "movl 4(%eax), %edx\n"
        "movl %eax, %ecx\n"
        ".Lf1f77a_0001f7f3:\n"
        "addl $4, %edx\n" /* line 607 */
        "movl %edx, 4(%ecx)\n"
        /* } scope */
        ".Lf1f77a_0001f7f9:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 120 | this */
        "movl %ecx, (%esp)\n"
        "calll __ZdlPv\n"
        ".Lf1f77a_0001f804:\n"
        "movl (%edi), %edi\n" /* line 140 */
        "cmpl %esi, %edi\n" /* line 117 */
        "jne .Lf1f77a_0001f7be\n"
        /* { scope 1 */
        ".Lf1f77a_0001f80a:\n"
        "movl (%esi), %eax\n" /* line 72 */
        "movl %eax, %edx\n" /* line 73 */
        "cmpl %eax, %esi\n"
        "jne .Lf1f77a_0001f816\n"
        "jmp .Lf1f77a_0001f826\n"
        ".Lf1f77a_0001f814:\n"
        "movl %ebx, %edx\n"
        ".Lf1f77a_0001f816:\n"
        "movl (%edx), %ebx\n" /* line 76 */
        /* { scope 2 */
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 73 */
        "cmpl %esi, %ebx\n"
        "jne .Lf1f77a_0001f814\n"
        /* } scope */
        ".Lf1f77a_0001f826:\n"
        "movl %eax, (%esi)\n" /* line 340 */
        "movl %eax, 4(%esi)\n" /* line 341 */
        /* { scope 1 */
        "cmpl %esi, %eax\n" /* line 73 */
        "jne .Lf1f77a_0001f833\n"
        "jmp .Lf1f77a_0001f841\n"
        ".Lf1f77a_0001f831:\n"
        "movl %ebx, %eax\n"
        ".Lf1f77a_0001f833:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "cmpl %esi, %ebx\n" /* line 73 */
        "jne .Lf1f77a_0001f831\n"
        /* } scope */
        ".Lf1f77a_0001f841:\n"
        "movl -0x20(%ebp), %edx\n" /* line 124 */
        "movl %edx, 8(%ebp)\n" /* this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp ZN13CMemoryBufferD1Ev\n"
        ".Lf1f77a_0001f853:\n"
        "leal 0xc(%ebx), %ecx\n" /* line 112 | this */
        "movl %ecx, -0x20(%ebp)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "leal 0x30(%ebx), %esi\n" /* this */
        "calll CVAOPacket_ReleaseBuffer\n"
        "jmp .Lf1f77a_0001f7b4\n"
        ".Lf1f77a_0001f873:\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %ecx\n"
        "jmp .Lf1f77a_0001f7f3\n"
        /* { scope 1 */
        ".Lf1f77a_0001f87e:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 610 | this */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorImSaImEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPmS1_EERKm\n"
        "jmp .Lf1f77a_0001f7f9\n"
        "movl %eax, %edi\n"
        /* } scope */
        "movl 0x30(%ebx), %eax\n" /* line 72 */
        "cmpl %esi, %eax\n" /* line 73 */
        "je .Lf1f77a_0001f8b7\n"
        ".Lf1f77a_0001f8a5:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "cmpl %esi, %ebx\n" /* line 73 */
        "je .Lf1f77a_0001f8b7\n"
        "movl %ebx, %eax\n"
        "jmp .Lf1f77a_0001f8a5\n"
        ".Lf1f77a_0001f8b7:\n"
        "movl -0x20(%ebp), %eax\n" /* line 124 */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl %edi, (%esp)\n"
        "calll __Unwind_Resume\n"
        "nop\n"
    );
}

/* line 102 */
__attribute__((naked))
void ZN21CDirect3DVertexBufferD2Ev(void) /* CDirect3DVertexBuffer_~CDirect3DVertexBuffer */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DVertexBuffer, (%ebx)\n" /* this */
        "movl 0x38(%ebx), %edx\n" /* line 106 | this */
        "testl %edx, %edx\n"
        "je .Lf1f8cc_0001f8f6\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "leal 0xc(%ebx), %edx\n" /* this */
        "movl %edx, -0x20(%ebp)\n"
        "leal 0x30(%ebx), %esi\n" /* this */
        "calll *4(%eax)\n"
        ".Lf1f8cc_0001f8f6:\n"
        "testb $2, 0x21(%ebx)\n" /* line 109 | this */
        "je .Lf1f8cc_0001f9a5\n"
        "leal 0xc(%ebx), %eax\n" /* this */
        "movl %eax, -0x20(%ebp)\n"
        ".Lf1f8cc_0001f906:\n"
        "leal 0x30(%ebx), %esi\n" /* line 117 | this */
        "movl 0x30(%ebx), %edi\n" /* line 580 | this */
        "cmpl %esi, %edi\n" /* line 117 */
        "je .Lf1f8cc_0001f95c\n"
        ".Lf1f8cc_0001f910:\n"
        "movl 8(%edi), %edx\n" /* line 119 */
        "movl %edx, -0x1c(%ebp)\n" /* this */
        "testl %edx, %edx\n" /* line 120 */
        "je .Lf1f8cc_0001f956\n"
        /* { scope 1 */
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %ecx\n" /* line 604 */
        "movl 4(%ecx), %edx\n"
        "cmpl 8(%ecx), %edx\n"
        "je .Lf1f8cc_0001f9d0\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf1f8cc_0001f9c5\n"
        "movl -0x1c(%ebp), %ecx\n" /* this */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %eax\n"
        "movl 4(%eax), %edx\n"
        "movl %eax, %ecx\n"
        ".Lf1f8cc_0001f945:\n"
        "addl $4, %edx\n" /* line 607 */
        "movl %edx, 4(%ecx)\n"
        /* } scope */
        ".Lf1f8cc_0001f94b:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 120 | this */
        "movl %ecx, (%esp)\n"
        "calll __ZdlPv\n"
        ".Lf1f8cc_0001f956:\n"
        "movl (%edi), %edi\n" /* line 140 */
        "cmpl %esi, %edi\n" /* line 117 */
        "jne .Lf1f8cc_0001f910\n"
        /* { scope 1 */
        ".Lf1f8cc_0001f95c:\n"
        "movl (%esi), %eax\n" /* line 72 */
        "movl %eax, %edx\n" /* line 73 */
        "cmpl %eax, %esi\n"
        "jne .Lf1f8cc_0001f968\n"
        "jmp .Lf1f8cc_0001f978\n"
        ".Lf1f8cc_0001f966:\n"
        "movl %ebx, %edx\n"
        ".Lf1f8cc_0001f968:\n"
        "movl (%edx), %ebx\n" /* line 76 */
        /* { scope 2 */
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 73 */
        "cmpl %esi, %ebx\n"
        "jne .Lf1f8cc_0001f966\n"
        /* } scope */
        ".Lf1f8cc_0001f978:\n"
        "movl %eax, (%esi)\n" /* line 340 */
        "movl %eax, 4(%esi)\n" /* line 341 */
        /* { scope 1 */
        "cmpl %esi, %eax\n" /* line 73 */
        "jne .Lf1f8cc_0001f985\n"
        "jmp .Lf1f8cc_0001f993\n"
        ".Lf1f8cc_0001f983:\n"
        "movl %ebx, %eax\n"
        ".Lf1f8cc_0001f985:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "cmpl %esi, %ebx\n" /* line 73 */
        "jne .Lf1f8cc_0001f983\n"
        /* } scope */
        ".Lf1f8cc_0001f993:\n"
        "movl -0x20(%ebp), %edx\n" /* line 124 */
        "movl %edx, 8(%ebp)\n" /* this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp ZN13CMemoryBufferD1Ev\n"
        ".Lf1f8cc_0001f9a5:\n"
        "leal 0xc(%ebx), %ecx\n" /* line 112 | this */
        "movl %ecx, -0x20(%ebp)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "leal 0x30(%ebx), %esi\n" /* this */
        "calll CVAOPacket_ReleaseBuffer\n"
        "jmp .Lf1f8cc_0001f906\n"
        ".Lf1f8cc_0001f9c5:\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %ecx\n"
        "jmp .Lf1f8cc_0001f945\n"
        /* { scope 1 */
        ".Lf1f8cc_0001f9d0:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 610 | this */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorImSaImEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPmS1_EERKm\n"
        "jmp .Lf1f8cc_0001f94b\n"
        "movl %eax, %edi\n"
        /* } scope */
        "movl 0x30(%ebx), %eax\n" /* line 72 */
        "cmpl %esi, %eax\n" /* line 73 */
        "je .Lf1f8cc_0001fa09\n"
        ".Lf1f8cc_0001f9f7:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "cmpl %esi, %ebx\n" /* line 73 */
        "je .Lf1f8cc_0001fa09\n"
        "movl %ebx, %eax\n"
        "jmp .Lf1f8cc_0001f9f7\n"
        ".Lf1f8cc_0001fa09:\n"
        "movl -0x20(%ebp), %eax\n" /* line 124 */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl %edi, (%esp)\n"
        "calll __Unwind_Resume\n"
        "nop\n"
    );
}

/* line 340 */
__attribute__((naked))
void CDirect3DVertexBuffer_SetFence(const CDirect3DVertexBuffer * _this, const void * pStart, UINT32 SizeInBytes, const CDirect3DVertexBuffer * _this_3)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 340 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* pStart */
        "movl %eax, -0x24(%ebp)\n" /* pStart */
        "movl 0x10(%ebp), %eax\n" /* SizeInBytes */
        "movl %eax, -0x28(%ebp)\n" /* SizeInBytes */
        /* { scope 1 */
        "movl imp___ZN7COpenGL11sFrameCountE, %eax\n" /* line 668 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* CurrentTime */
        "leal 0x30(%edx), %eax\n" /* line 349 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x30(%edx), %esi\n" /* line 580 */
        "movl imp___ZN6CFence15sUnusedFenceIDsE, %edi\n"
        "cmpl %esi, -0x1c(%ebp)\n" /* line 349 */
        "je .Lf1fa1e_0001faa5\n"
        /* { scope 2 */
        ".Lf1fa1e_0001fa54:\n"
        "movl 8(%esi), %ebx\n" /* line 351 | Fence */
        "movl -0x20(%ebp), %eax\n" /* line 353 | CurrentTime */
        "subl 0xc(%ebx), %eax\n" /* Fence */
        "cmpl $1, %eax\n"
        "jbe 0x1faf6\n"
        "testl %ebx, %ebx\n" /* line 362 | Fence */
        "je .Lf1fa1e_0001fa8f\n"
        "movl 4(%edi), %edx\n" /* line 604 */
        "cmpl 8(%edi), %edx\n"
        "je 0x1fb56\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf1fa1e_0001fa81\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %edx\n"
        ".Lf1fa1e_0001fa81:\n"
        "leal 4(%edx), %eax\n" /* line 607 */
        "movl %eax, 4(%edi)\n"
        "movl %ebx, (%esp)\n" /* line 362 | Fence */
        "calll __ZdlPv\n"
        ".Lf1fa1e_0001fa8f:\n"
        "movl %esi, 4(%esp)\n" /* line 363 */
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll ZNSt4listIP6CFenceSaIS1_EE5eraseESt14_List_iteratorIS1_E\n"
        "movl %eax, %esi\n"
        /* } scope */
        "cmpl %esi, -0x1c(%ebp)\n" /* line 349 */
        "jne .Lf1fa1e_0001fa54\n"
        ".Lf1fa1e_0001faa5:\n"
        "movl $0x10, (%esp)\n" /* line 389 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl -0x20(%ebp), %eax\n" /* CurrentTime */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* SizeInBytes */
        "movl %edx, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* pStart */
    );
}

/* line 78 */
__attribute__((naked))
void CDirect3DVertexBuffer_CDirect3DVertexBuffer(const CDirect3DVertexBuffer * _this, UINT32 Length, DWORD Usage, D3DPOOL Pool)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 78 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* Length */
        "movl 0x10(%ebp), %ebx\n" /* Usage */
        "movl $vtbl_CDirect3DVertexBuffer, (%edi)\n" /* line 88 | this */
        "movl $0, 4(%edi)\n" /* this */
        "movl %esi, 8(%edi)\n" /* Length, this */
        "leal 0xc(%edi), %eax\n" /* this */
        "movl %eax, -0x34(%ebp)\n"
        "movl %esi, 4(%esp)\n" /* Length */
        "movl %eax, (%esp)\n"
        "calll CMemoryBuffer_CMemoryBuffer\n"
        "movl %ebx, 0x20(%edi)\n" /* Usage, this */
        "movl $0, 0x24(%edi)\n" /* this */
        "movl $0, 0x28(%edi)\n" /* this */
        "movb $0, 0x2c(%edi)\n" /* this */
        "leal 0x30(%edi), %edx\n" /* this */
        "movl %edx, -0x30(%ebp)\n" /* this */
        /* { scope 1 */
        "movl %edx, 0x30(%edi)\n" /* line 340 | this */
        "movl %edx, 4(%edx)\n" /* line 341 */
        /* } scope */
        "movl $0, 0x38(%edi)\n" /* line 88 | this */
        "andl $0x400000, %ebx\n" /* line 92 | Usage */
        "jne .Lf1fb96_0001fc06\n"
        "addl $1, 4(%edi)\n" /* line 146 | this */
        "addl $0x3c, %esp\n" /* line 98 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fb96_0001fc06:\n"
        "movl -0x34(%ebp), %eax\n" /* line 94 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* pBuffer */
        "movl $0x1c, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 1 */
        "movl $vtbl_CStaticCacheInfo, (%eax)\n" /* line 23 */
        "movl %esi, 4(%eax)\n"
        "movl -0x2c(%ebp), %edx\n" /* pBuffer */
        "movl %edx, 8(%eax)\n"
        "testl %esi, %esi\n"
        "js .Lf1fb96_0001fc80\n"
        "cvtsi2ssl %esi, %xmm0\n"
        ".Lf1fb96_0001fc34:\n"
        "mulss lit4_002ed60c, %xmm0\n" /* 0.0009765625f */
        "movss %xmm0, (%esp)\n"
        "calll ceilf\n"
        "fnstcw -0x1a(%ebp)\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x1c(%ebp)\n"
        "fldcw -0x1c(%ebp)\n"
        "fistpll -0x28(%ebp)\n"
        "fldcw -0x1a(%ebp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x10(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZNSt6vectorI15CCacheInfoBlockSaIS0_EEC1Em\n"
        /* } scope */
        "movl %ebx, 0x38(%edi)\n" /* line 94 | this */
        "addl $1, 4(%edi)\n" /* line 146 | this */
        "addl $0x3c, %esp\n" /* line 98 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1fb96_0001fc80:\n"
        "movl %esi, %eax\n" /* line 23 */
        "shrl $1, %eax\n"
        "andl $1, %esi\n"
        "orl %esi, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf1fb96_0001fc34\n"
        "movl %eax, %esi\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fb96_0001fc95:\n"
        "movl -0x30(%ebp), %edx\n" /* line 72 | this */
        "movl (%edx), %eax\n"
        "cmpl %eax, %edx\n" /* line 73 */
        "je .Lf1fb96_0001fcbd\n"
        ".Lf1fb96_0001fc9e:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "cmpl %ebx, -0x30(%ebp)\n" /* line 73 | this */
        "je .Lf1fb96_0001fcbd\n"
        "movl %ebx, %eax\n"
        "jmp .Lf1fb96_0001fc9e\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 94 | this */
        "calll __ZdlPv\n"
        "jmp .Lf1fb96_0001fc95\n"
        ".Lf1fb96_0001fcbd:\n"
        "movl -0x34(%ebp), %eax\n" /* line 98 */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl %esi, (%esp)\n" /* Length */
        "calll __Unwind_Resume\n"
    );
}

/* overload skip: CDirect3DVertexBuffer_CDirect3DVertexBuffer (0x1fcd0) */

/* line 29 */
__attribute__((naked))
void ZN16CStaticCacheInfoD2Ev(void) /* CStaticCacheInfo_~CStaticCacheInfo */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CStaticCacheInfo, (%eax)\n"
        "leal 0x10(%eax), %edi\n" /* line 31 | this */
        /* { scope 1 */
        "movl 4(%edi), %esi\n" /* line 273 | this, __last */
        "movl 0x10(%eax), %ebx\n" /* __p */
        /* { scope 2 */
        "cmpl %ebx, %esi\n" /* line 173 */
        "je .Lf1fe0a_0001fe37\n"
        /* { scope 3 */
        ".Lf1fe0a_0001fe29:\n"
        "movl (%ebx), %eax\n" /* line 107 */
        "movl %ebx, (%esp)\n"
        "calll *(%eax)\n"
        /* } scope */
        "addl $8, %ebx\n" /* line 173 */
        "cmpl %ebx, %esi\n"
        "jne .Lf1fe0a_0001fe29\n"
        /* } scope */
        ".Lf1fe0a_0001fe37:\n"
        "movl (%edi), %eax\n" /* line 109 | this */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1fe0a_0001fe4c\n"
        /* { scope 2 */
        "movl %eax, 8(%ebp)\n" /* line 94 | this */
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 31 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp __ZdlPv\n" /* line 94 */
        /* } scope */
        /* } scope */
        ".Lf1fe0a_0001fe4c:\n"
        "addl $0x1c, %esp\n" /* line 31 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        /* { scope 1 */
        "movl (%edi), %eax\n" /* line 109 | this */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1fe0a_0001fe64\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        ".Lf1fe0a_0001fe64:\n"
        "movl %ebx, (%esp)\n" /* line 109 */
        "calll __Unwind_Resume\n"
    );
}

/* line 29 */
__attribute__((naked))
void ZN16CStaticCacheInfoD1Ev(void) /* CStaticCacheInfo_~CStaticCacheInfo */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CStaticCacheInfo, (%eax)\n"
        "leal 0x10(%eax), %edi\n" /* line 31 | this */
        /* { scope 1 */
        "movl 4(%edi), %esi\n" /* line 273 | this, __last */
        "movl 0x10(%eax), %ebx\n" /* __p */
        /* { scope 2 */
        "cmpl %ebx, %esi\n" /* line 173 */
        "je .Lf1fe6c_0001fe99\n"
        /* { scope 3 */
        ".Lf1fe6c_0001fe8b:\n"
        "movl (%ebx), %eax\n" /* line 107 */
        "movl %ebx, (%esp)\n"
        "calll *(%eax)\n"
        /* } scope */
        "addl $8, %ebx\n" /* line 173 */
        "cmpl %ebx, %esi\n"
        "jne .Lf1fe6c_0001fe8b\n"
        /* } scope */
        ".Lf1fe6c_0001fe99:\n"
        "movl (%edi), %eax\n" /* line 109 | this */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1fe6c_0001feae\n"
        /* { scope 2 */
        "movl %eax, 8(%ebp)\n" /* line 94 | this */
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 31 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp __ZdlPv\n" /* line 94 */
        /* } scope */
        /* } scope */
        ".Lf1fe6c_0001feae:\n"
        "addl $0x1c, %esp\n" /* line 31 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        /* { scope 1 */
        "movl (%edi), %eax\n" /* line 109 | this */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1fe6c_0001fec6\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        ".Lf1fe6c_0001fec6:\n"
        "movl %ebx, (%esp)\n" /* line 109 */
        "calll __Unwind_Resume\n"
    );
}

/* line 39 */
__attribute__((naked))
void ZN15CCacheInfoBlockD1Ev(void) /* CCacheInfoBlock_~CCacheInfoBlock */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "movl imp___ZTV15CCacheInfoBlock, %edx\n"
        "addl $8, %edx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, (%eax)\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 39 */
__attribute__((naked))
void ZN15CCacheInfoBlockD0Ev(void) /* CCacheInfoBlock_~CCacheInfoBlock */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl imp___ZTV15CCacheInfoBlock, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl %edx, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 106 */
__attribute__((naked))
HRESULT CDirect3DVertexBuffer_GetDevice(const CDirect3DVertexBuffer * _this, IDirect3DDevice9 * *ppDevice)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 107 */
__attribute__((naked))
HRESULT CDirect3DVertexBuffer_SetPrivateData(const CDirect3DVertexBuffer * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 107 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 108 */
__attribute__((naked))
HRESULT CDirect3DVertexBuffer_GetPrivateData(const CDirect3DVertexBuffer * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 108 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 109 */
__attribute__((naked))
HRESULT CDirect3DVertexBuffer_FreePrivateData(const CDirect3DVertexBuffer * _this, const GUID *refguid)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 109 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 110 */
__attribute__((naked))
DWORD CDirect3DVertexBuffer_SetPriority(const CDirect3DVertexBuffer * _this, DWORD PriorityNew)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 110 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 111 */
__attribute__((naked))
DWORD CDirect3DVertexBuffer_GetPriority(const CDirect3DVertexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 111 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 112 */
__attribute__((naked))
void CDirect3DVertexBuffer_PreLoad(const CDirect3DVertexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 112 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 113 */
__attribute__((naked))
D3DRESOURCETYPE CDirect3DVertexBuffer_GetType(const CDirect3DVertexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 113 */
        "movl %esp, %ebp\n"
        "movl $6, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 95 */
__attribute__((naked))
void ZNSt4listIP6CFenceSaIS1_EE5eraseESt14_List_iteratorIS1_E(void) /* std_list<CFence*, std_allocator<CFence*> >_erase */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* __position */
        "movl (%ebx), %esi\n" /* line 97 | __position */
        "movl %ebx, (%esp)\n" /* line 1159 | __position */
        "calll __ZNSt15_List_node_base6unhookEv\n"
        "movl %ebx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "movl %esi, %eax\n" /* line 99 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 216 */
__attribute__((naked))
void ZNSt6vectorI15CCacheInfoBlockSaIS0_EEC1Em(void) /* std_vector<CCacheInfoBlock, std_allocator<CCacheInfoBlock> >_vector */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 216 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* __n */
        "movl $0, (%ebx)\n" /* line 85 */
        "movl $0, 4(%ebx)\n"
        "movl $0, 8(%ebx)\n"
        "cmpl $0x1fffffff, %edi\n"
        "ja .Lf2bdec4_002bdf40\n"
        "leal (, %edi, 8), %esi\n" /* line 88 */
        "movl %esi, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, %edx\n"
        "movl %eax, (%ebx)\n" /* line 103 */
        "movl %eax, 4(%ebx)\n" /* line 104 */
        "leal (%esi, %eax), %eax\n" /* line 105 */
        "movl %eax, 8(%ebx)\n"
        "movl %edx, %eax\n" /* line 219 */
        /* { scope 1 */
        "testl %edi, %edi\n" /* line 193 */
        "je .Lf2bdec4_002bdf32\n"
        "xorl %edx, %edx\n"
        "movl imp___ZTV15CCacheInfoBlock, %ecx\n"
        "addl $8, %ecx\n"
        /* { scope 2 */
        ".Lf2bdec4_002bdf1c:\n"
        "testl %eax, %eax\n" /* line 81 */
        "je .Lf2bdec4_002bdf26\n"
        "movl %ecx, (%eax)\n" /* line 41 */
        "movb $1, 4(%eax)\n" /* line 42 */
        /* } scope */
        ".Lf2bdec4_002bdf26:\n"
        "addl $8, %eax\n" /* line 193 */
        "addl $1, %edx\n"
        "cmpl %edx, %edi\n"
        "jne .Lf2bdec4_002bdf1c\n"
        "movl (%ebx), %edx\n"
        /* } scope */
        ".Lf2bdec4_002bdf32:\n"
        "leal (%esi, %edx), %eax\n" /* line 221 */
        "movl %eax, 4(%ebx)\n" /* this */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bdec4_002bdf40:\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
    );
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorImSaImEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPmS1_EERKm(void) /* std_vector<unsigned long, std_allocator<unsigned long> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 4(%edi), %edx\n" /* line 251 | this */
        "cmpl 8(%edi), %edx\n" /* this */
        "je .Lf2bdf4e_002bdfa6\n"
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf2bdf4e_002bdf6e\n"
        "movl -4(%edx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %edx\n"
        ".Lf2bdf4e_002bdf6e:\n"
        "movl %edx, %eax\n" /* line 255 */
        "addl $4, %edx\n"
        "movl %edx, 4(%edi)\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 256 | __x */
        "movl (%edx), %ebx\n" /* __x_copy */
        "leal -4(%eax), %edx\n" /* line 257 */
        /* { scope 2 */
        "subl 0xc(%ebp), %edx\n" /* line 424 | __position */
        "andl $0xfffffffc, %edx\n" /* line 425 */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* __position */
        "movl %ecx, 4(%esp)\n"
        "subl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 260 | __position */
        "movl %ebx, (%eax)\n" /* __x_copy */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bdf4e_002bdfa6:\n"
        "movl %edx, %eax\n" /* line 759 */
        "subl (%edi), %eax\n" /* this */
        "sarl $2, %eax\n"
        "cmpl $0x3fffffff, %eax\n" /* line 265 */
        "je .Lf2bdf4e_002be074\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2bdf4e_002be052\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2bdf4e_002bdfc5:\n"
        "shll $2, %edx\n" /* line 88 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl (%edi), %eax\n" /* line 279 | this */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%ebp), %ebx\n" /* line 300 | __position, __x_copy */
        "subl %eax, %ebx\n" /* __x_copy */
        "movl %ebx, 8(%esp)\n" /* __x_copy */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        /* } scope */
        "movl -0x20(%ebp), %edx\n" /* line 104 */
        "addl %ebx, %edx\n"
        "je .Lf2bdf4e_002bdffe\n"
        "movl 0x10(%ebp), %ecx\n" /* __x */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        ".Lf2bdf4e_002bdffe:\n"
        "leal 4(%edx), %esi\n" /* line 286 */
        "movl 4(%edi), %ebx\n" /* line 603 | this, __x_copy */
        /* { scope 2 */
        /* { scope 3 */
        "subl 0xc(%ebp), %ebx\n" /* line 300 | __position, __x_copy */
        "movl %ebx, 8(%esp)\n" /* __x_copy */
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memmove\n"
        "addl %esi, %ebx\n" /* line 354 | __x_copy */
        /* } scope */
        /* } scope */
        "movl 4(%edi), %edx\n" /* line 352 | this */
        "movl (%edi), %ecx\n" /* line 334 | this */
        "movl %ecx, %eax\n"
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf2bdf4e_002be02e\n"
        ".Lf2bdf4e_002be027:\n"
        "addl $4, %eax\n" /* line 623 */
        "cmpl %edx, %eax\n" /* line 173 */
        "jne .Lf2bdf4e_002be027\n"
        ".Lf2bdf4e_002be02e:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bdf4e_002be03a\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bdf4e_002be03a:\n"
        "movl -0x20(%ebp), %edx\n" /* line 302 */
        "movl %edx, (%edi)\n" /* this */
        "movl %ebx, 4(%edi)\n" /* line 303 | __x_copy, this */
        "movl %edx, %eax\n" /* line 304 */
        "addl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%edi)\n" /* this */
        /* } scope */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bdf4e_002be052:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2bdf4e_002be06a\n"
        "cmpl $0x3fffffff, %edx\n" /* line 85 */
        "jbe .Lf2bdf4e_002bdfc5\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2bdf4e_002be06a:\n"
        "movl $0x3fffffff, %edx\n" /* line 272 */
        "jmp .Lf2bdf4e_002bdfc5\n"
        ".Lf2bdf4e_002be074:\n"
        "movl $0x215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}

