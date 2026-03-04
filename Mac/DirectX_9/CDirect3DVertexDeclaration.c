/* ASM dump from: CDirect3DVertexDeclaration.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DVertexDeclaration.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DVertexDeclaration.h"
 */

ULONG CDirect3DVertexDeclaration_AddRef(const CDirect3DVertexDeclaration * _this);
void ZN26CDirect3DVertexDeclarationD1Ev(void); /* CDirect3DVertexDeclaration_~CDirect3DVertexDeclaration */
void ZN26CDirect3DVertexDeclarationD0Ev(void); /* CDirect3DVertexDeclaration_~CDirect3DVertexDeclaration */
HRESULT CDirect3DVertexDeclaration_QueryInterface(const CDirect3DVertexDeclaration * _this, const IID *iid, HRESULT (*ppvObj)());
ULONG CDirect3DVertexDeclaration_Release(const CDirect3DVertexDeclaration * _this);
HRESULT CDirect3DVertexDeclaration_GetDeclaration(const CDirect3DVertexDeclaration * _this, LONG (*pElement)(), UINT *pNumElements);
jpeg_alloc CDirect3DVertexDeclaration_GetShaderDeclaration(const CDirect3DVertexDeclaration * _this, const UINT32 * pTokenStream);
jpeg_alloc CDirect3DVertexDeclaration_CDirect3DVertexDeclaration(const CDirect3DVertexDeclaration * _this, const D3DVERTEXELEMENT9 * pVertexElements);
HRESULT CDirect3DVertexDeclaration_GetDevice(const CDirect3DVertexDeclaration * _this, IDirect3DDevice9 * *ppDevice);

/* line 82 */
__attribute__((naked))
ULONG CDirect3DVertexDeclaration_AddRef(const CDirect3DVertexDeclaration * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 82 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n" /* line 84 */
        "addl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "popl %ebp\n" /* line 85 */
        "retl\n"
    );
}

/* line 60 */
__attribute__((naked))
void ZN26CDirect3DVertexDeclarationD1Ev(void) /* CDirect3DVertexDeclaration_~CDirect3DVertexDeclaration */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DVertexDeclaration, (%eax)\n"
        "movl 0xc(%eax), %eax\n" /* line 62 */
        "testl %eax, %eax\n"
        "je .Lf1fee4_0001ff00\n"
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 63 */
        "jmp __ZdaPv\n" /* line 62 */
        ".Lf1fee4_0001ff00:\n"
        "popl %ebp\n" /* line 63 */
        "retl\n"
    );
}

/* line 60 */
__attribute__((naked))
void ZN26CDirect3DVertexDeclarationD0Ev(void) /* CDirect3DVertexDeclaration_~CDirect3DVertexDeclaration */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DVertexDeclaration, (%ebx)\n" /* this */
        "movl 0xc(%ebx), %eax\n" /* line 62 | this */
        "testl %eax, %eax\n"
        "je .Lf1ff02_0001ff21\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lf1ff02_0001ff21:\n"
        "movl %ebx, 8(%ebp)\n" /* line 63 | this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 71 */
__attribute__((naked))
HRESULT CDirect3DVertexDeclaration_QueryInterface(const CDirect3DVertexDeclaration * _this, const IID *iid, HRESULT (*ppvObj)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 73 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 74 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 77 */
        "leave\n"
        "retl\n"
    );
}

/* line 90 */
__attribute__((naked))
ULONG CDirect3DVertexDeclaration_Release(const CDirect3DVertexDeclaration * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %ebx\n" /* line 92 */
        "subl $1, %ebx\n"
        "movl %ebx, 4(%edx)\n"
        "testl %ebx, %ebx\n" /* line 94 */
        "jne .Lf1ff48_0001ff67\n"
        "movl (%edx), %eax\n" /* line 96 */
        "movl %edx, (%esp)\n"
        "calll *0x18(%eax)\n"
        ".Lf1ff48_0001ff67:\n"
        "movl %ebx, %eax\n" /* line 99 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 104 */
__attribute__((naked))
HRESULT CDirect3DVertexDeclaration_GetDeclaration(const CDirect3DVertexDeclaration * _this, LONG (*pElement)(), UINT *pNumElements)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edi\n" /* this */
        /* { scope 1 */
        "movl 8(%edi), %edx\n" /* line 106 | this */
        "testl %edx, %edx\n"
        "je .Lf1ff70_0001ffa1\n"
        "movl 0xc(%ebp), %ebx\n" /* pElement */
        "xorl %esi, %esi\n" /* i */
        ".Lf1ff70_0001ff85:\n"
        "movl 0xc(%edi), %ecx\n" /* line 108 | this */
        "movl (%ebx), %eax\n"
        "movl 4(%ebx), %edx\n"
        "movl %eax, (%ecx, %esi, 8)\n"
        "movl %edx, 4(%ecx, %esi, 8)\n"
        "addl $1, %esi\n" /* line 106 | i */
        "movl 8(%edi), %edx\n" /* this */
        "addl $8, %ebx\n"
        "cmpl %edx, %esi\n" /* i */
        "jb .Lf1ff70_0001ff85\n"
        /* } scope */
        ".Lf1ff70_0001ffa1:\n"
        "movl 0x10(%ebp), %eax\n" /* line 111 | pNumElements */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n" /* line 114 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 119 */
__attribute__((naked))
jpeg_alloc CDirect3DVertexDeclaration_GetShaderDeclaration(const CDirect3DVertexDeclaration * _this, const UINT32 * pTokenStream)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 119 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $1, %eax\n"
        "leal -0x28(%ebp), %edx\n" /* IsUsed */
        /* { scope 1 */
        ".Lf1ffae_0001ffbf:\n"
        "movb $0, -1(%eax, %edx)\n" /* line 132 */
        "addl $1, %eax\n"
        "cmpl $0x11, %eax\n" /* line 130 */
        "jne .Lf1ffae_0001ffbf\n"
        "movl 8(%ebp), %eax\n" /* line 135 | this */
        "cmpl $1, 8(%eax)\n"
        "je .Lf1ffae_00020187\n"
        "xorl %edi, %edi\n" /* CurrentOffset */
        "movl $0xffffffff, -0x30(%ebp)\n" /* LastStream */
        "movl $0, -0x2c(%ebp)\n" /* i */
        "xorl %ecx, %ecx\n"
        "movl 8(%ebp), %edx\n" /* this */
        /* { scope 2 */
        ".Lf1ffae_0001ffee:\n"
        "movl 0xc(%edx), %eax\n" /* line 137 */
        "movl -0x2c(%ebp), %edx\n" /* i */
        "leal (%eax, %edx, 8), %ebx\n" /* Element */
        "movzwl (%ebx), %eax\n" /* line 141 | Element */
        "cmpl %eax, -0x30(%ebp)\n" /* LastStream */
        "setne %dl\n"
        "movl %edx, %esi\n" /* EmitStreamToken */
        "testb %dl, %dl\n" /* line 142 */
        "je .Lf1ffae_0002000b\n"
        "movl %eax, -0x30(%ebp)\n" /* LastStream */
        "xorl %edi, %edi\n" /* CurrentOffset */
        ".Lf1ffae_0002000b:\n"
        "movzwl 2(%ebx), %eax\n" /* line 150 | Element */
        "cmpl %eax, %edi\n" /* CurrentOffset */
        "je .Lf1ffae_00020050\n"
        /* { scope 3 */
        "movl %eax, %edx\n" /* line 153 | AmountToSkip */
        "subl %edi, %edx\n" /* CurrentOffset, AmountToSkip */
        "cmpl $0xf, %edx\n" /* line 155 */
        "jbe .Lf1ffae_00020036\n"
        "movl 0xc(%ebp), %edi\n" /* pTokenStream, CurrentOffset */
        "leal (%edi, %ecx, 4), %eax\n" /* CurrentOffset */
        ".Lf1ffae_00020022:\n"
        "movl $0x500f0000, (%eax)\n" /* line 158 */
        "addl $1, %ecx\n"
        "subl $0xf, %edx\n" /* line 159 */
        "addl $4, %eax\n"
        "cmpl $0xf, %edx\n" /* line 155 */
        "ja .Lf1ffae_00020022\n"
        ".Lf1ffae_00020036:\n"
        "testl %edx, %edx\n" /* line 161 */
        "je .Lf1ffae_0002004c\n"
        "shll $0x10, %edx\n" /* line 164 */
        "orl $0x50000000, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* pTokenStream */
        "movl %edx, (%eax, %ecx, 4)\n"
        "addl $1, %ecx\n"
        ".Lf1ffae_0002004c:\n"
        "movzwl 2(%ebx), %edi\n" /* line 166 | Element, CurrentOffset */
        /* } scope */
        ".Lf1ffae_00020050:\n"
        "movl %esi, %edx\n" /* line 169 | EmitStreamToken */
        "testb %dl, %dl\n"
        "je .Lf1ffae_00020067\n"
        "movzwl (%ebx), %eax\n" /* line 172 | Element */
        "orl $0x20000000, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* pTokenStream */
        "movl %eax, (%edx, %ecx, 4)\n"
        "addl $1, %ecx\n"
        ".Lf1ffae_00020067:\n"
        "movzbl 4(%ebx), %eax\n" /* line 177 | Element */
        "cmpl $7, %eax\n"
        "ja .Lf1ffae_0002007a\n"
        "jmpl *.Ljt_2ef7e0(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ef7e0:\n"
        ".long .Lf1ffae_00020077\n"
        ".long .Lf1ffae_000200ea\n"
        ".long .Lf1ffae_000200f4\n"
        ".long .Lf1ffae_00020101\n"
        ".long .Lf1ffae_0002010e\n"
        ".long .Lf1ffae_0002011b\n"
        ".long .Lf1ffae_00020128\n"
        ".long .Lf1ffae_00020135\n"
        ".popsection\n"
        ".Lf1ffae_00020077:\n"
        "addl $4, %edi\n" /* line 181 | CurrentOffset */
        ".Lf1ffae_0002007a:\n"
        "xorl %esi, %esi\n" /* EmitStreamToken */
        ".Lf1ffae_0002007c:\n"
        "movzbl 6(%ebx), %edx\n" /* line 216 | Element */
        "movzbl %dl, %eax\n"
        "cmpl $0xa, %eax\n"
        "ja .Lf1ffae_0002008f\n"
        "jmpl *.Ljt_2ef800(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ef800:\n"
        ".long .Lf1ffae_00020094\n"
        ".long .Lf1ffae_00020142\n"
        ".long .Lf1ffae_0002014c\n"
        ".long .Lf1ffae_00020153\n"
        ".long .Lf1ffae_0002015d\n"
        ".long .Lf1ffae_00020167\n"
        ".long .Lf1ffae_00020173\n"
        ".long .Lf1ffae_0002008f\n"
        ".long .Lf1ffae_0002008f\n"
        ".long .Lf1ffae_00020094\n"
        ".long .Lf1ffae_0002017d\n"
        ".popsection\n"
        ".Lf1ffae_0002008f:\n"
        "cmpb $2, %dl\n" /* line 265 */
        "je .Lf1ffae_000200da\n"
        ".Lf1ffae_00020094:\n"
        "xorl %eax, %eax\n"
        ".Lf1ffae_00020096:\n"
        "movb $1, -0x28(%ebp, %eax)\n" /* line 272 */
        ".Lf1ffae_0002009b:\n"
        "orl %esi, %eax\n" /* line 275 | EmitStreamToken */
        "orl $0x40000000, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* pTokenStream */
        "movl %eax, (%edx, %ecx, 4)\n"
        "addl $1, %ecx\n"
        /* } scope */
        "addl $1, -0x2c(%ebp)\n" /* line 135 | i */
        "movl 8(%ebp), %edx\n" /* this */
        "movl 8(%edx), %eax\n"
        "subl $1, %eax\n"
        "cmpl -0x2c(%ebp), %eax\n" /* i */
        "ja .Lf1ffae_0001ffee\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xc(%ebp), %edi\n" /* line 278 | pTokenStream, CurrentOffset */
        "movl $0xffffffff, (%eax, %edi)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 279 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1ffae_000200da:\n"
        "xorl %eax, %eax\n" /* line 265 */
        ".Lf1ffae_000200dc:\n"
        "cmpb $0, -0x28(%ebp, %eax)\n"
        "je .Lf1ffae_00020096\n"
        "movl $6, %eax\n"
        "jmp .Lf1ffae_0002009b\n"
        ".Lf1ffae_000200ea:\n"
        "addl $8, %edi\n" /* line 185 | CurrentOffset */
        "movl $0x10000, %esi\n" /* EmitStreamToken */
        "jmp .Lf1ffae_0002007c\n"
        ".Lf1ffae_000200f4:\n"
        "addl $0xc, %edi\n" /* line 189 | CurrentOffset */
        "movl $0x20000, %esi\n" /* EmitStreamToken */
        "jmp .Lf1ffae_0002007c\n"
        ".Lf1ffae_00020101:\n"
        "addl $0x10, %edi\n" /* line 193 | CurrentOffset */
        "movl $0x30000, %esi\n" /* EmitStreamToken */
        "jmp .Lf1ffae_0002007c\n"
        ".Lf1ffae_0002010e:\n"
        "addl $4, %edi\n" /* line 197 | CurrentOffset */
        "movl $0x40000, %esi\n" /* EmitStreamToken */
        "jmp .Lf1ffae_0002007c\n"
        ".Lf1ffae_0002011b:\n"
        "addl $4, %edi\n" /* line 201 | CurrentOffset */
        "movl $0x50000, %esi\n" /* EmitStreamToken */
        "jmp .Lf1ffae_0002007c\n"
        ".Lf1ffae_00020128:\n"
        "addl $4, %edi\n" /* line 205 | CurrentOffset */
        "movl $0x60000, %esi\n" /* EmitStreamToken */
        "jmp .Lf1ffae_0002007c\n"
        ".Lf1ffae_00020135:\n"
        "addl $8, %edi\n" /* line 209 | CurrentOffset */
        "movl $0x70000, %esi\n" /* EmitStreamToken */
        "jmp .Lf1ffae_0002007c\n"
        ".Lf1ffae_00020142:\n"
        "movl $1, %eax\n" /* line 216 */
        "jmp .Lf1ffae_00020096\n"
        ".Lf1ffae_0002014c:\n"
        "movl $2, %eax\n"
        "jmp .Lf1ffae_000200dc\n"
        ".Lf1ffae_00020153:\n"
        "movl $3, %eax\n" /* line 223 */
        "jmp .Lf1ffae_00020096\n"
        ".Lf1ffae_0002015d:\n"
        "movl $4, %eax\n" /* line 229 */
        "jmp .Lf1ffae_00020096\n"
        ".Lf1ffae_00020167:\n"
        "movzbl 7(%ebx), %eax\n" /* line 234 | Element */
        "addl $8, %eax\n"
        "jmp .Lf1ffae_00020096\n"
        ".Lf1ffae_00020173:\n"
        "movl $7, %eax\n" /* line 235 */
        "jmp .Lf1ffae_00020096\n"
        ".Lf1ffae_0002017d:\n"
        "movl $5, %eax\n" /* line 216 */
        "jmp .Lf1ffae_00020096\n"
        /* } scope */
        ".Lf1ffae_00020187:\n"
        "xorl %eax, %eax\n" /* line 135 */
        "movl 0xc(%ebp), %edi\n" /* line 278 | pTokenStream, CurrentOffset */
        "movl $0xffffffff, (%eax, %edi)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 279 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 38 */
__attribute__((naked))
jpeg_alloc CDirect3DVertexDeclaration_CDirect3DVertexDeclaration(const CDirect3DVertexDeclaration * _this, const D3DVERTEXELEMENT9 * pVertexElements)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* pVertexElements */
        "movl $vtbl_CDirect3DVertexDeclaration, (%edi)\n" /* line 41 | this */
        "movl $0, 8(%edi)\n" /* this */
        "movl $0, 0xc(%edi)\n" /* this */
        "movl $1, 4(%edi)\n" /* line 84 | this */
        "movl %ebx, %edx\n" /* pVertexElements */
        "xorl %eax, %eax\n"
        "jmp .Lf2019c_000201d2\n"
        /* { scope 1 */
        ".Lf2019c_000201cc:\n"
        "addl $1, %eax\n" /* line 23 */
        "addl $8, %edx\n"
        ".Lf2019c_000201d2:\n"
        "cmpw $0xff, (%edx)\n" /* line 27 */
        "jne .Lf2019c_000201cc\n"
        "cmpw $0, 2(%edx)\n"
        "jne .Lf2019c_000201cc\n"
        "cmpw $0x11, 4(%edx)\n"
        "jne .Lf2019c_000201cc\n"
        "cmpw $0, 6(%edx)\n"
        "jne .Lf2019c_000201cc\n"
        "addl $1, %eax\n" /* line 33 */
        /* } scope */
        "movl %eax, 8(%edi)\n" /* line 48 | this */
        "shll $3, %eax\n" /* line 51 */
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, 0xc(%edi)\n" /* this */
        /* { scope 1 */
        "movl 8(%edi), %eax\n" /* line 52 | this */
        "testl %eax, %eax\n"
        "je .Lf2019c_00020225\n"
        "xorl %esi, %esi\n" /* i */
        ".Lf2019c_0002020b:\n"
        "movl 0xc(%edi), %ecx\n" /* line 54 | this */
        "movl (%ebx), %eax\n" /* pVertexElements */
        "movl 4(%ebx), %edx\n" /* pVertexElements */
        "movl %eax, (%ecx, %esi, 8)\n"
        "movl %edx, 4(%ecx, %esi, 8)\n"
        "addl $1, %esi\n" /* line 52 | i */
        "addl $8, %ebx\n" /* pVertexElements */
        "cmpl %esi, 8(%edi)\n" /* i, this */
        "ja .Lf2019c_0002020b\n"
        /* } scope */
        ".Lf2019c_00020225:\n"
        "addl $0x1c, %esp\n" /* line 56 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 39 */
__attribute__((naked))
HRESULT CDirect3DVertexDeclaration_GetDevice(const CDirect3DVertexDeclaration * _this, IDirect3DDevice9 * *ppDevice)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

