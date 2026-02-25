/* ASM dump from: CVAOPacket.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CVAOPacket.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CVAOPacket.h"
 *   #include "Mac/DirectX 9/COpenGLVAO.h"
 *   #include "Mac/DirectX 9/COpenGLVertexProgram.h"
 *   #include "Mac/DirectX 9/CVertexArrays.h"
 */

extern VAOStatus CVAOPacket_sVAOStatus; /* 0x0 */
extern UINT32 CVAOPacket_sCurrentPacket; /* 0x0 */
extern CVAOPacket CVAOPacket_sGenericPacket[1]; /* 0x0 */
extern VAOSet CVAOPacket_sAllPackets; /* 0x0 */

void CVAOPacket_CVAOPacket(const CVAOPacket * _this);
void ZN10CVAOPacketD2Ev(void); /* CVAOPacket_~CVAOPacket */
void ZN10CVAOPacketD1Ev(void); /* CVAOPacket_~CVAOPacket */
void ZN10CVAOPacketD0Ev(void); /* CVAOPacket_~CVAOPacket */
void CVAOPacket_SetVAO(const CVAOPacket * _this, int bIsCached);
void CVAOPacket_SetGenericVAO(int IsFixedFunction, int ForceValidation);
void CVAOPacket_InitializeGenericVAO(void);
void CVAOPacket_ReleaseBuffer(const void * p, UINT32 Length);
bool CVAOPacket_IsCached(CVAOPacket *v);
void CVAOPacket_Cache(CVAOPacket *v);
void CVAOPacket_Shutdown(void);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__D__ZN10CVAOPacket10sVAOStatusE(void); /* global destructors keyed to CVAOPacket_sVAOStatus */
static void GLOBAL__I__ZN10CVAOPacket10sVAOStatusE(void); /* global constructors keyed to CVAOPacket_sVAOStatus */
bool CVAOPacket_IsFixedFunction(const CVAOPacket * _this);
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE11lower_boundERS1_(void); /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >_lower_bound */
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE11upper_boundERS1_(void); /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >_upper_bound */
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE9_M_insertEPSt18_Rb_tree_node_baseSB_RKS3_(void); /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >__M_insert */
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE12insert_equalERKS3_(void); /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >_insert_equal */
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE8_M_eraseEPSt13_Rb_tree_nodeIS3_E(void); /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >__M_erase */

/* line 29 */
__attribute__((naked))
void CVAOPacket_CVAOPacket(const CVAOPacket * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll COpenGLVAO_COpenGLVAO\n"
        "movl $0x3322a8, (%ebx)\n" /* this */
        "addl $0x14, %esp\n" /* line 31 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 35 */
__attribute__((naked))
void ZN10CVAOPacketD2Ev(void) /* CVAOPacket_~CVAOPacket */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 35 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x3322a8, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 37 | this */
        "popl %ebp\n"
        "jmp ZN10COpenGLVAOD2Ev\n"
    );
}

/* line 35 */
__attribute__((naked))
void ZN10CVAOPacketD1Ev(void) /* CVAOPacket_~CVAOPacket */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 35 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x3322a8, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 37 | this */
        "popl %ebp\n"
        "jmp ZN10COpenGLVAOD2Ev\n"
    );
}

/* line 35 */
__attribute__((naked))
void ZN10CVAOPacketD0Ev(void) /* CVAOPacket_~CVAOPacket */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 35 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x3322a8, (%ebx)\n" /* this */
        "movl %ebx, (%esp)\n" /* line 37 | this */
        "calll ZN10COpenGLVAOD2Ev\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 163 */
__attribute__((naked))
void CVAOPacket_SetVAO(const CVAOPacket * _this, int bIsCached)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 163 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $1, 0xc(%ebp)\n" /* line 167 | bIsCached */
        "sbbl %eax, %eax\n" /* s */
        "addl $3, %eax\n" /* s */
        /* { scope 1 */
        "movl %eax, __ZN10CVAOPacket10sVAOStatusE\n" /* line 51 */
        /* } scope */
        "movl (%ebx), %eax\n" /* line 168 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *8(%eax)\n"
        "movl $0, 0xc(%esp)\n"
        "movzbl %al, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* this */
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetVAO\n"
        "addl $0x14, %esp\n" /* line 169 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 190 */
__attribute__((naked))
void CVAOPacket_SetGenericVAO(int IsFixedFunction, int ForceValidation)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 190 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, __ZN10CVAOPacket10sVAOStatusE\n" /* line 51 */
        "movzbl 0xc(%ebp), %eax\n" /* line 197 | ForceValidation */
        "movl %eax, 0xc(%esp)\n"
        "movzbl 8(%ebp), %eax\n" /* IsFixedFunction */
        "movl %eax, 8(%esp)\n"
        "movl __ZN10CVAOPacket14sCurrentPacketE, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "addl $__ZN10CVAOPacket14sGenericPacketE, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetVAO\n"
        "movl __ZN10CVAOPacket14sCurrentPacketE, %edx\n" /* line 198 */
        "addl $1, %edx\n"
        "xorl %eax, %eax\n" /* line 201 */
        "cmpl $1, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl %eax, __ZN10CVAOPacket14sCurrentPacketE\n"
        "leave\n" /* line 203 */
        "retl\n"
    );
}

/* line 174 */
__attribute__((naked))
void CVAOPacket_InitializeGenericVAO(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 174 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $0, 0x1218c84\n" /* line 64 */
        "movl $0, 0x1218c88\n" /* line 72 */
        "movl $0, 0x1218c8c\n" /* line 73 */
        "movl $0x1218c90, (%esp)\n" /* line 75 */
        "calll CBaseVA_Reset\n"
        "movl $0x1218ca8, (%esp)\n" /* line 76 */
        "calll CBaseVA_Reset\n"
        "movl $0x1218cc0, (%esp)\n" /* line 77 */
        "calll CBaseVA_Reset\n"
        "movl $0x1218cd8, (%esp)\n" /* line 78 */
        "calll CBaseVA_Reset\n"
        "xorl %esi, %esi\n"
        "movl $0x1218cf0, %ebx\n"
        ".Lf113cb4_00113d11:\n"
        "movl %ebx, (%esp)\n" /* line 83 */
        "calll CBaseVA_Reset\n"
        "addl $1, %esi\n" /* line 81 */
        "addl $0x18, %ebx\n"
        "cmpl $8, %esi\n"
        "jne .Lf113cb4_00113d11\n"
        "xorl %edx, %edx\n"
        "movl $0x130, %eax\n"
        ".Lf113cb4_00113d2b:\n"
        "movb $1, __ZN10CVAOPacket14sGenericPacketE(%eax)\n" /* line 95 */
        "movb $0, 0x1218c81(%eax)\n" /* line 44 */
        "movl $4, 0x1218c84(%eax)\n" /* line 45 */
        "movl $0x1406, 0x1218c88(%eax)\n" /* line 46 */
        "movb $0, 0x1218c8c(%eax)\n" /* line 47 */
        "movl $0, 0x1218c90(%eax)\n" /* line 48 */
        "movl $0, 0x1218c94(%eax)\n" /* line 49 */
        "addl $1, %edx\n" /* line 88 */
        "addl $0x18, %eax\n"
        "cmpl $0x10, %edx\n"
        "jne .Lf113cb4_00113d2b\n"
        /* } scope */
        "movl $__ZN10CVAOPacket14sGenericPacketE, (%esp)\n" /* line 181 */
        "calll COpenGLVAO_CreateNewBinding\n"
        "movl $1, __ZN10CVAOPacket10sVAOStatusE\n" /* line 51 */
        "movl $1, 0xc(%esp)\n" /* line 197 */
        "movl $1, 8(%esp)\n"
        "movl __ZN10CVAOPacket14sCurrentPacketE, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "addl $__ZN10CVAOPacket14sGenericPacketE, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetVAO\n"
        "movl __ZN10CVAOPacket14sCurrentPacketE, %edx\n" /* line 198 */
        "addl $1, %edx\n"
        "xorl %eax, %eax\n" /* line 201 */
        "cmpl $1, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl %eax, __ZN10CVAOPacket14sCurrentPacketE\n"
        "movl $0x85bf, 4(%esp)\n" /* line 183 */
        "movl $0x851f, (%esp)\n"
        "calll glVertexArrayParameteriAPPLE\n"
        "addl $0x10, %esp\n" /* line 185 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 219 */
__attribute__((naked))
void CVAOPacket_ReleaseBuffer(const void * p, UINT32 Length)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 219 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* p */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 229 | Length */
        "addl %edi, %eax\n" /* p */
        "movl %eax, -0x1c(%ebp)\n" /* pEnd */
        "movl 0x1218f3c, %esi\n" /* line 582 */
        /* { scope 2 */
        ".Lf113df2_00113e0c:\n"
        "movl $0x1218f34, %eax\n" /* line 231 */
        "cmpl %esi, %eax\n"
        "je .Lf113df2_00113e55\n"
        /* { scope 3 */
        ".Lf113df2_00113e15:\n"
        "leal 0x14(%esi), %ebx\n" /* line 233 | Packet */
        "movl 0x6c(%ebx), %eax\n" /* line 237 | Packet, PacketStart */
        "cmpl %edi, %eax\n" /* line 238 | p */
        "jb .Lf113df2_00113e24\n"
        "cmpl -0x1c(%ebp), %eax\n" /* pEnd */
        "jb .Lf113df2_00113e5d\n"
        ".Lf113df2_00113e24:\n"
        "xorl %ecx, %ecx\n"
        "leal 0x158(%esi), %edx\n"
        /* { scope 4 */
        ".Lf113df2_00113e2c:\n"
        "movl (%edx), %eax\n" /* line 246 */
        "cmpl %eax, %edi\n" /* line 247 | p */
        "ja .Lf113df2_00113e37\n"
        "cmpl -0x1c(%ebp), %eax\n" /* pEnd */
        "jb .Lf113df2_00113e5d\n"
        ".Lf113df2_00113e37:\n"
        "addl $1, %ecx\n" /* line 244 | j */
        "addl $0x18, %edx\n"
        "cmpl $0x10, %ecx\n" /* j */
        "jne .Lf113df2_00113e2c\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 181 */
        "calll __ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl $0x1218f34, %eax\n" /* line 231 */
        "cmpl %esi, %eax\n"
        "jne .Lf113df2_00113e15\n"
        /* } scope */
        /* } scope */
        ".Lf113df2_00113e55:\n"
        "addl $0x2c, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf113df2_00113e5d:\n"
        "movl 0x195f24c, %ecx\n" /* line 286 */
        "movl 4(%ebx), %edx\n" /* Packet */
        "movl (%ecx), %eax\n"
        "cmpl (%edx), %eax\n"
        "je .Lf113df2_00113ec8\n"
        ".Lf113df2_00113e6c:\n"
        "movl %edx, 4(%esp)\n" /* line 290 */
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseVAOBinding\n"
        "movl $0, 4(%ebx)\n" /* line 292 | Packet */
        "movl %esi, %ebx\n" /* line 188 */
        "movl %esi, (%esp)\n" /* line 189 */
        "calll __ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base\n"
        "movl %eax, %esi\n"
        "movl $0x1218f34, 4(%esp)\n" /* line 994 */
        "movl %ebx, (%esp)\n" /* __p */
        "calll __ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_\n"
        "movl %eax, %ebx\n" /* __p */
        "leal 0x14(%eax), %eax\n" /* line 69 | this */
        /* { scope 4 */
        "movl $0x3322a8, 0x14(%ebx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 4 */
        "movl %ebx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "subl $1, 0x1218f44\n" /* line 996 */
        "jmp .Lf113df2_00113e0c\n"
        ".Lf113df2_00113ec8:\n"
        "movl $0xffffffff, (%ecx)\n" /* line 288 */
        "movl 4(%ebx), %edx\n" /* Packet */
        "jmp .Lf113df2_00113e6c\n"
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
    );
}

/* line 42 */
__attribute__((naked))
bool CVAOPacket_IsCached(CVAOPacket *v)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 42 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1: TheContents */
        "movl 8(%ebp), %eax\n" /* line 48 | v */
        "movl %eax, (%esp)\n"
        "calll COpenGLVAO_GetCode\n"
        "movl %eax, -0x1c(%ebp)\n" /* Code */
        "leal -0x1c(%ebp), %edi\n" /* line 1220 | Code */
        "movl %edi, 4(%esp)\n"
        "movl $__ZN10CVAOPacket11sAllPacketsE, (%esp)\n"
        "calll ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE11upper_boundERS1_\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $__ZN10CVAOPacket11sAllPacketsE, (%esp)\n"
        "calll ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE11lower_boundERS1_\n"
        "movl -0x30(%ebp), %esi\n" /* line 85 */
        "movl %esi, %ebx\n" /* line 54 */
        "cmpl %eax, %esi\n" /* line 56 */
        "je .Lf113edc_00113f51\n"
        "movl %eax, %edi\n"
        "movl %eax, %esi\n"
        "jmp .Lf113edc_00113f2a\n"
        ".Lf113edc_00113f28:\n"
        "movl %eax, %edi\n" /* line 64 */
        /* { scope 2 */
        ".Lf113edc_00113f2a:\n"
        "leal 0x14(%edi), %edx\n" /* line 66 */
        "movl %edx, -0x2c(%ebp)\n" /* TheContents */
        "movl 8(%ebp), %eax\n" /* line 47 | v */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ZNK10COpenGLVAOeqERKS_\n"
        "testb %al, %al\n" /* line 70 */
        "jne .Lf113edc_00113f5b\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 181 */
        "calll __ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base\n"
        "movl %eax, %esi\n"
        "cmpl %ebx, %eax\n" /* line 64 */
        "jne .Lf113edc_00113f28\n"
        ".Lf113edc_00113f51:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 115 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: TheContents */
        /* { scope 2 */
        ".Lf113edc_00113f5b:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 73 | TheContents */
        "movl 4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf113edc_00113f51\n"
        "movl 8(%ebp), %edx\n" /* line 79 | v */
        "movl %eax, 4(%edx)\n"
        "leal 0x24(%edi), %edx\n" /* line 74 */
        "movl 8(%ebp), %ecx\n" /* v, this */
        "addl $0x10, %ecx\n" /* this */
        /* { scope 3 */
        "movzbl 4(%edx), %eax\n" /* line 19 */
        "movb %al, 4(%ecx)\n"
        "movzbl 5(%edx), %eax\n"
        "movb %al, 5(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        "leal 0x3c(%edi), %edx\n" /* line 85 */
        "movl 8(%ebp), %ecx\n" /* v, this */
        "addl $0x28, %ecx\n" /* this */
        /* { scope 3 */
        "movzbl 4(%edx), %eax\n" /* line 19 */
        "movb %al, 4(%ecx)\n"
        "movzbl 5(%edx), %eax\n"
        "movb %al, 5(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        "leal 0x54(%edi), %edx\n" /* line 95 */
        "movl 8(%ebp), %ecx\n" /* v, this */
        "addl $0x40, %ecx\n" /* this */
        /* { scope 3 */
        "movzbl 4(%edx), %eax\n" /* line 19 */
        "movb %al, 4(%ecx)\n"
        "movzbl 5(%edx), %eax\n"
        "movb %al, 5(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        "leal 0x6c(%edi), %edx\n" /* line 106 */
        "movl 8(%ebp), %ecx\n" /* v, this */
        "addl $0x58, %ecx\n" /* this */
        /* { scope 3 */
        "movzbl 4(%edx), %eax\n" /* line 19 */
        "movb %al, 4(%ecx)\n"
        "movzbl 5(%edx), %eax\n"
        "movb %al, 5(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "xorl %ebx, %ebx\n"
        "movl 8(%ebp), %ecx\n" /* v */
        "addl $0x84, %ecx\n"
        "leal 0x98(%edi), %edx\n"
        /* } scope */
        /* { scope 3 */
        ".Lf113edc_00114038:\n"
        "movzbl -0x10(%edx), %eax\n"
        "movb %al, -0x10(%ecx)\n"
        "movzbl -0xf(%edx), %eax\n"
        "movb %al, -0xf(%ecx)\n"
        "movl -0xc(%edx), %eax\n"
        "movl %eax, -0xc(%ecx)\n"
        "movl -8(%edx), %eax\n"
        "movl %eax, -8(%ecx)\n"
        "movl -4(%edx), %eax\n"
        "movl %eax, -4(%ecx)\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "addl $1, %ebx\n" /* line 92 | j */
        "addl $0x18, %edx\n"
        "addl $0x18, %ecx\n"
        "cmpl $8, %ebx\n" /* j */
        "jne .Lf113edc_00114038\n"
        "movl -0x2c(%ebp), %ecx\n" /* TheContents */
        "movl 8(%ebp), %edx\n" /* v */
        "movb $0x10, %bl\n" /* j */
        /* } scope */
        ".Lf113edc_00114072:\n"
        "movl 0x130(%ecx), %eax\n" /* line 101 */
        "movl %eax, 0x130(%edx)\n"
        "movl 0x134(%ecx), %eax\n"
        "movl %eax, 0x134(%edx)\n"
        "movl 0x138(%ecx), %eax\n"
        "movl %eax, 0x138(%edx)\n"
        "movl 0x13c(%ecx), %eax\n"
        "movl %eax, 0x13c(%edx)\n"
        "movl 0x140(%ecx), %eax\n"
        "movl %eax, 0x140(%edx)\n"
        "movl 0x144(%ecx), %eax\n"
        "movl %eax, 0x144(%edx)\n"
        "addl $0x18, %ecx\n"
        "addl $0x18, %edx\n"
        "subl $1, %ebx\n" /* line 99 | j */
        "jne .Lf113edc_00114072\n"
        "movl $0x1218f34, 4(%esp)\n" /* line 994 */
        "movl %esi, (%esp)\n"
        "calll __ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_\n"
        "movl %eax, %ebx\n" /* __p */
        "leal 0x14(%eax), %eax\n" /* line 69 | this */
        /* { scope 3 */
        "movl $0x3322a8, 0x14(%ebx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 3 */
        "movl %ebx, (%esp)\n" /* line 94 | j */
        "calll __ZdlPv\n"
        /* } scope */
        "subl $1, 0x1218f44\n" /* line 996 */
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 115 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: TheContents */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
    );
}

/* line 121 */
__attribute__((naked))
void CVAOPacket_Cache(CVAOPacket *v)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 121 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x58c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* v */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 155 | v */
        "calll COpenGLVAO_GetCode\n"
        "movl %eax, -0x580(%ebp)\n" /* line 85 | NewPacket */
        "movl %ebx, 4(%esp)\n"
        "leal -0x57c(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll CVAOPacket_CVAOPacket\n"
        "movl -0x580(%ebp), %eax\n" /* line 90 | NewPacket */
        "movl %eax, -0x2cc(%ebp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x2cc(%ebp), %ebx\n"
        "leal -0x2c8(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll CVAOPacket_CVAOPacket\n"
        "movl %ebx, 4(%esp)\n" /* line 348 | v */
        "movl $__ZN10CVAOPacket11sAllPacketsE, (%esp)\n"
        "calll ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE12insert_equalERKS3_\n"
        "movl $0x3322a8, -0x2c8(%ebp)\n" /* line 35 */
        "movl %esi, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        "movl $0x3322a8, -0x57c(%ebp)\n" /* line 35 */
        "movl %edi, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        "addl $0x58c, %esp\n" /* line 158 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* v */
        /* { scope 1 */
        "movl $0x3322a8, -0x2c8(%ebp)\n" /* line 35 */
        "movl %esi, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        ".Lf11410e_001141b4:\n"
        "movl $0x3322a8, -0x57c(%ebp)\n" /* line 35 */
        "movl %edi, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        "movl %ebx, (%esp)\n" /* line 69 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "jmp .Lf11410e_001141b4\n"
    );
}

/* line 208 */
__attribute__((naked))
void CVAOPacket_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 208 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0x1218f38, %ebx\n" /* line 462 */
        "testl %ebx, %ebx\n" /* line 1054 */
        "jne .Lf1141d2_001141e8\n"
        "jmp .Lf1141d2_0011421c\n"
        ".Lf1141d2_001141e6:\n"
        "movl %esi, %ebx\n"
        ".Lf1141d2_001141e8:\n"
        "movl 0xc(%ebx), %eax\n" /* line 1056 */
        "movl %eax, 4(%esp)\n"
        "movl $__ZN10CVAOPacket11sAllPacketsE, (%esp)\n"
        "calll ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE8_M_eraseEPSt13_Rb_tree_nodeIS3_E\n"
        "movl 8(%ebx), %esi\n" /* line 489 */
        "leal 0x14(%ebx), %eax\n" /* line 69 */
        "movl $0x3322a8, 0x14(%ebx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        "movl %ebx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "testl %esi, %esi\n" /* line 1054 */
        "jne .Lf1141d2_001141e6\n"
        ".Lf1141d2_0011421c:\n"
        "movl $0x1218f34, 0x1218f3c\n" /* line 667 */
        "movl $0, 0x1218f38\n" /* line 668 */
        "movl $0x1218f34, 0x1218f40\n" /* line 669 */
        "movl $0, 0x1218f44\n" /* line 670 */
        "movl $0, __ZN10CVAOPacket10sVAOStatusE\n" /* line 51 */
        "addl $0x10, %esp\n" /* line 214 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
    );
}

/* line 300 */
static __attribute__((naked))
void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 300 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "cmpl $0xffff, %edx\n" /* line 19 */
        "je .Lf11425e_00114275\n"
        ".Lf11425e_0011426e:\n"
        "addl $0x10, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf11425e_00114275:\n"
        "cmpl $1, %eax\n" /* line 19 */
        "je .Lf11425e_001142d5\n"
        "testl %eax, %eax\n" /* line 21 */
        "jne .Lf11425e_0011426e\n"
        "movl $__ZN10CVAOPacket14sGenericPacketE, (%esp)\n"
        "movl __ZN10CVAOPacket14sGenericPacketE, %eax\n"
        "calll *(%eax)\n"
        "movl 0x1218f38, %ebx\n" /* line 462 */
        "testl %ebx, %ebx\n" /* line 1054 */
        "jne .Lf11425e_0011429a\n"
        "jmp .Lf11425e_0011426e\n"
        ".Lf11425e_00114298:\n"
        "movl %esi, %ebx\n"
        ".Lf11425e_0011429a:\n"
        "movl 0xc(%ebx), %eax\n" /* line 1056 | __initialize_p */
        "movl %eax, 4(%esp)\n" /* __initialize_p */
        "movl $__ZN10CVAOPacket11sAllPacketsE, (%esp)\n"
        "calll ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE8_M_eraseEPSt13_Rb_tree_nodeIS3_E\n"
        "movl 8(%ebx), %esi\n" /* line 489 */
        "leal 0x14(%ebx), %eax\n" /* line 69 */
        "movl $0x3322a8, 0x14(%ebx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        "movl %ebx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "testl %esi, %esi\n" /* line 1054 */
        "jne .Lf11425e_00114298\n"
        "addl $0x10, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf11425e_001142d5:\n"
        "movl $0, 0x1218f44\n" /* line 404 */
        "movl $0, 0x1218f34\n" /* line 406 */
        "movl $0, 0x1218f38\n" /* line 407 */
        "movl $0x1218f34, 0x1218f3c\n" /* line 408 */
        "movl $0x1218f34, 0x1218f40\n" /* line 409 */
        "movl $__ZN10CVAOPacket14sGenericPacketE, (%esp)\n" /* line 29 */
        "calll COpenGLVAO_COpenGLVAO\n"
        "movl $0x3322a8, __ZN10CVAOPacket14sGenericPacketE\n"
        "addl $0x10, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf11425e_00114324:\n"
        "movl %eax, (%esp)\n" /* line 397 | __initialize_p */
        "calll __Unwind_Resume\n"
        "jmp .Lf11425e_00114324\n"
        "jmp .Lf11425e_00114324\n"
    );
}

/* line 302 */
static __attribute__((naked))
void GLOBAL__D__ZN10CVAOPacket10sVAOStatusE(void) /* global destructors keyed to CVAOPacket_sVAOStatus */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 302 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 301 */
static __attribute__((naked))
void GLOBAL__I__ZN10CVAOPacket10sVAOStatusE(void) /* global constructors keyed to CVAOPacket_sVAOStatus */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 301 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 59 */
__attribute__((naked))
bool CVAOPacket_IsFixedFunction(const CVAOPacket * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 59 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1144 */
__attribute__((naked))
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE11lower_boundERS1_(void) /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >_lower_bound */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1144 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        /* { scope 1 */
        "movl 8(%eax), %ecx\n" /* line 462 */
        "leal 4(%eax), %ebx\n" /* line 473 */
        "testl %ecx, %ecx\n" /* line 1149 */
        "je .Lf2c096e_002c099d\n"
        "movl 0xc(%ebp), %edx\n" /* line 227 | __k */
        "movl (%edx), %eax\n"
        "jmp .Lf2c096e_002c0991\n"
        ".Lf2c096e_002c0986:\n"
        "movl 8(%ecx), %edx\n" /* line 489 */
        "movl %ecx, %ebx\n"
        "testl %edx, %edx\n" /* line 1149 */
        "je .Lf2c096e_002c099d\n"
        ".Lf2c096e_002c098f:\n"
        "movl %edx, %ecx\n"
        ".Lf2c096e_002c0991:\n"
        "cmpl %eax, 0x10(%ecx)\n" /* line 1150 */
        "jae .Lf2c096e_002c0986\n"
        "movl 0xc(%ecx), %edx\n" /* line 497 */
        "testl %edx, %edx\n" /* line 1149 */
        "jne .Lf2c096e_002c098f\n"
        /* } scope */
        ".Lf2c096e_002c099d:\n"
        "movl %ebx, %eax\n" /* line 1155 | __y */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1180 */
__attribute__((naked))
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE11upper_boundERS1_(void) /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >_upper_bound */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1180 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        /* { scope 1 */
        "movl 8(%eax), %ecx\n" /* line 462 */
        "leal 4(%eax), %ebx\n" /* line 473 */
        "testl %ecx, %ecx\n" /* line 1185 */
        "je .Lf2c09a2_002c09d1\n"
        "movl 0xc(%ebp), %edx\n" /* line 227 | __k */
        "movl (%edx), %eax\n"
        "jmp .Lf2c09a2_002c09c5\n"
        ".Lf2c09a2_002c09ba:\n"
        "movl 8(%ecx), %edx\n" /* line 489 */
        "movl %ecx, %ebx\n"
        "testl %edx, %edx\n" /* line 1185 */
        "je .Lf2c09a2_002c09d1\n"
        ".Lf2c09a2_002c09c3:\n"
        "movl %edx, %ecx\n"
        ".Lf2c09a2_002c09c5:\n"
        "cmpl 0x10(%ecx), %eax\n" /* line 1186 */
        "jb .Lf2c09a2_002c09ba\n"
        "movl 0xc(%ecx), %edx\n" /* line 497 */
        "testl %edx, %edx\n" /* line 1185 */
        "jne .Lf2c09a2_002c09c3\n"
        /* } scope */
        ".Lf2c09a2_002c09d1:\n"
        "movl %ebx, %eax\n" /* line 1191 | __y */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* overload skip: CVAOPacket_CVAOPacket (0x2c09d6) */

/* line 787 */
__attribute__((naked))
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE9_M_insertEPSt18_Rb_tree_node_baseSB_RKS3_(void) /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >__M_insert */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 787 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0x14(%ebp), %esi\n" /* __v */
        /* { scope 1 */
        "movl $0x2c4, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n"
        "movl (%esi), %eax\n" /* line 69 */
        "movl %eax, 0x10(%ebx)\n"
        "leal 4(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x14(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CVAOPacket_CVAOPacket\n"
        "movl 0xc(%ebp), %eax\n" /* line 792 | __x */
        "testl %eax, %eax\n"
        "je .Lf2c0ba8_002c0c10\n"
        "leal 4(%edi), %edx\n" /* this */
        ".Lf2c0ba8_002c0be6:\n"
        "movl $1, %eax\n"
        ".Lf2c0ba8_002c0beb:\n"
        "movl %edx, 0xc(%esp)\n" /* line 796 */
        "movl 0x10(%ebp), %edx\n" /* __p */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* __z */
        "movl %eax, (%esp)\n"
        "calll __ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_\n"
        "addl $1, 0x14(%edi)\n" /* line 798 | this */
        /* } scope */
        "movl %ebx, %eax\n" /* line 799 | __z */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c0ba8_002c0c10:\n"
        "leal 4(%edi), %edx\n" /* line 792 | this */
        "cmpl %edx, 0x10(%ebp)\n" /* __p */
        "je .Lf2c0ba8_002c0be6\n"
        "movl (%esi), %eax\n" /* __v */
        "movl 0x10(%ebp), %ecx\n" /* __p */
        "cmpl 0x10(%ecx), %eax\n"
        "jb .Lf2c0ba8_002c0be6\n"
        "xorl %eax, %eax\n"
        "jmp .Lf2c0ba8_002c0beb\n"
    );
}

/* line 806 */
__attribute__((naked))
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE12insert_equalERKS3_(void) /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >_insert_equal */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 806 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* __v */
        /* { scope 1 */
        "movl 8(%ebx), %edx\n" /* line 462 */
        "leal 4(%ebx), %eax\n" /* line 473 */
        "testl %edx, %edx\n" /* line 810 */
        "je .Lf2c0c26_002c0c59\n"
        "movl (%esi), %ecx\n" /* line 227 */
        "jmp .Lf2c0c26_002c0c4b\n"
        ".Lf2c0c26_002c0c42:\n"
        "movl 8(%edx), %eax\n" /* line 489 */
        "testl %eax, %eax\n" /* line 810 */
        "je .Lf2c0c26_002c0c57\n"
        ".Lf2c0c26_002c0c49:\n"
        "movl %eax, %edx\n"
        ".Lf2c0c26_002c0c4b:\n"
        "cmpl 0x10(%edx), %ecx\n" /* line 813 */
        "jb .Lf2c0c26_002c0c42\n"
        "movl 0xc(%edx), %eax\n" /* line 497 */
        "testl %eax, %eax\n" /* line 810 */
        "jne .Lf2c0c26_002c0c49\n"
        ".Lf2c0c26_002c0c57:\n"
        "movl %edx, %eax\n"
        ".Lf2c0c26_002c0c59:\n"
        "movl %esi, 0xc(%esp)\n" /* line 816 | __v */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE9_M_insertEPSt18_Rb_tree_node_baseSB_RKS3_\n"
        /* } scope */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1051 */
__attribute__((naked))
void ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE8_M_eraseEPSt13_Rb_tree_nodeIS3_E(void) /* std__Rb_tree<unsigned int, std_pair<unsigned int const, CVAOPacket>, std__Select1st<std_pair<unsigned int const, CVAOPacket> >, std_less<unsigned int>, std_allocator<std_pair<unsigned int const, CVAOPacket> > >__M_erase */
{
    __asm__ __volatile__ (
        ".Lf2c0c78_002c0c78:\n"
        "pushl %ebp\n" /* line 1051 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* line 1054 | __x */
        "testl %edx, %edx\n"
        "je .Lf2c0c78_002c0ed0\n"
        /* { scope 1: __p, __p, __p, __p, ... */
        ".Lf2c0c78_002c0c8c:\n"
        "movl 0xc(%ebp), %eax\n" /* line 497 | __x */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* __p */
        "testl %eax, %eax\n" /* line 1054 */
        "je .Lf2c0c78_002c0e9a\n"
        ".Lf2c0c78_002c0c9d:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 497 | __p */
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* __p */
        "testl %edx, %edx\n" /* line 1054 */
        "je .Lf2c0c78_002c0e69\n"
        ".Lf2c0c78_002c0cae:\n"
        "movl -0x20(%ebp), %eax\n" /* line 497 | __p */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* __p */
        "testl %eax, %eax\n" /* line 1054 */
        "je .Lf2c0c78_002c0e34\n"
        ".Lf2c0c78_002c0cbf:\n"
        "movl -0x24(%ebp), %edx\n" /* line 497 | __p */
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* __p */
        "testl %edx, %edx\n" /* line 1054 */
        "je .Lf2c0c78_002c0e03\n"
        ".Lf2c0c78_002c0cd0:\n"
        "movl -0x28(%ebp), %eax\n" /* line 497 | __p */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* __p */
        "testl %eax, %eax\n" /* line 1054 */
        "je .Lf2c0c78_002c0dc4\n"
        "movl %eax, %edx\n"
        ".Lf2c0c78_002c0ce3:\n"
        "movl 0xc(%edx), %edx\n" /* line 497 */
        "movl %edx, -0x30(%ebp)\n" /* __p */
        "testl %edx, %edx\n" /* line 1054 */
        "je .Lf2c0c78_002c0d91\n"
        "movl %edx, %eax\n"
        ".Lf2c0c78_002c0cf3:\n"
        "movl 0xc(%eax), %edi\n" /* line 497 | __p */
        "testl %edi, %edi\n" /* line 1054 | __p */
        "je .Lf2c0c78_002c0d60\n"
        ".Lf2c0c78_002c0cfa:\n"
        "movl 0xc(%edi), %ebx\n" /* line 497 | __p */
        "testl %ebx, %ebx\n" /* line 1054 | __p */
        "jne .Lf2c0c78_002c0d05\n"
        "jmp .Lf2c0c78_002c0d38\n"
        ".Lf2c0c78_002c0d03:\n"
        "movl %esi, %ebx\n" /* __p */
        ".Lf2c0c78_002c0d05:\n"
        "movl 0xc(%ebx), %eax\n" /* line 1056 | __p */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZNSt8_Rb_treeIjSt4pairIKj10CVAOPacketESt10_Select1stIS3_ESt4lessIjESaIS3_EE8_M_eraseEPSt13_Rb_tree_nodeIS3_E\n"
        "movl 8(%ebx), %esi\n" /* line 489 | __p */
        "leal 0x14(%ebx), %eax\n" /* line 69 | this */
        /* { scope 2 */
        "movl $0x3322a8, 0x14(%ebx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 2 */
        "movl %ebx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 1054 */
        "jne .Lf2c0c78_002c0d03\n"
        ".Lf2c0c78_002c0d38:\n"
        "movl 8(%edi), %ebx\n" /* line 489 | __p */
        "leal 0x14(%edi), %eax\n" /* line 69 | this */
        /* { scope 2 */
        "movl $0x3322a8, 0x14(%edi)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 2 */
        "movl %edi, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1054 | __p */
        "je .Lf2c0c78_002c0d5d\n"
        "movl %ebx, %edi\n" /* __p */
        "jmp .Lf2c0c78_002c0cfa\n"
        ".Lf2c0c78_002c0d5d:\n"
        "movl -0x30(%ebp), %eax\n" /* __p */
        ".Lf2c0c78_002c0d60:\n"
        "movl 8(%eax), %ebx\n" /* line 489 | __p */
        "addl $0x14, %eax\n" /* line 69 | this */
        /* { scope 2 */
        "movl -0x30(%ebp), %edx\n" /* line 35 | __p */
        "movl $0x3322a8, 0x14(%edx)\n"
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 94 | __p */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1054 | __p */
        "je .Lf2c0c78_002c0d91\n"
        "movl %ebx, -0x30(%ebp)\n" /* __p */
        "movl %ebx, %eax\n" /* __p */
        "jmp .Lf2c0c78_002c0cf3\n"
        ".Lf2c0c78_002c0d91:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 489 | __p */
        "movl 8(%edx), %ebx\n" /* __p */
        "movl %edx, %eax\n" /* line 69 | this */
        "addl $0x14, %eax\n" /* this */
        /* { scope 2 */
        "movl $0x3322a8, 0x14(%edx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 2 */
        "movl -0x2c(%ebp), %eax\n" /* line 94 | __p */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1054 | __p */
        "je .Lf2c0c78_002c0dc4\n"
        "movl %ebx, -0x2c(%ebp)\n" /* __p */
        "movl %ebx, %edx\n" /* __p */
        "jmp .Lf2c0c78_002c0ce3\n"
        ".Lf2c0c78_002c0dc4:\n"
        "movl -0x28(%ebp), %edx\n" /* line 489 | __p */
        "movl 8(%edx), %ebx\n" /* __p */
        "movl %edx, %eax\n" /* line 69 | this */
        "addl $0x14, %eax\n" /* this */
        /* { scope 2 */
        "movl $0x3322a8, 0x14(%edx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 2 */
        "movl -0x28(%ebp), %eax\n" /* line 94 | __p */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1054 | __p */
        "je .Lf2c0c78_002c0e03\n"
        "movl %ebx, -0x28(%ebp)\n" /* __p */
        "jmp .Lf2c0c78_002c0cd0\n"
        ".Lf2c0c78_002c0df5:\n"
        "movl %eax, (%esp)\n" /* line 105 */
        "calll __Unwind_Resume\n"
        "jmp .Lf2c0c78_002c0df5\n"
        "jmp .Lf2c0c78_002c0df5\n"
        "jmp .Lf2c0c78_002c0df5\n"
        ".Lf2c0c78_002c0e03:\n"
        "movl -0x24(%ebp), %edx\n" /* line 489 | __p */
        "movl 8(%edx), %ebx\n" /* __p */
        "movl %edx, %eax\n" /* line 69 | this */
        "addl $0x14, %eax\n" /* this */
        /* { scope 2 */
        "movl $0x3322a8, 0x14(%edx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 94 | __p */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1054 | __p */
        "je .Lf2c0c78_002c0e34\n"
        "movl %ebx, -0x24(%ebp)\n" /* __p */
        "jmp .Lf2c0c78_002c0cbf\n"
        ".Lf2c0c78_002c0e34:\n"
        "movl -0x20(%ebp), %edx\n" /* line 489 | __p */
        "movl 8(%edx), %ebx\n" /* __p */
        "movl %edx, %eax\n" /* line 69 | this */
        "addl $0x14, %eax\n" /* this */
        /* { scope 2 */
        "movl $0x3322a8, 0x14(%edx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 2 */
        "movl -0x20(%ebp), %eax\n" /* line 94 | __p */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1054 | __p */
        "je .Lf2c0c78_002c0e69\n"
        "movl %ebx, -0x20(%ebp)\n" /* __p */
        "jmp .Lf2c0c78_002c0cae\n"
        "jmp .Lf2c0c78_002c0df5\n"
        "jmp .Lf2c0c78_002c0df5\n"
        ".Lf2c0c78_002c0e69:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 489 | __p */
        "movl 8(%edx), %ebx\n" /* __p */
        "movl %edx, %eax\n" /* line 69 | this */
        "addl $0x14, %eax\n" /* this */
        /* { scope 2 */
        "movl $0x3322a8, 0x14(%edx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        /* { scope 2 */
        "movl -0x1c(%ebp), %eax\n" /* line 94 | __p */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1054 | __p */
        "je .Lf2c0c78_002c0e9a\n"
        "movl %ebx, -0x1c(%ebp)\n" /* __p */
        "jmp .Lf2c0c78_002c0c9d\n"
        ".Lf2c0c78_002c0e9a:\n"
        "movl 0xc(%ebp), %edx\n" /* line 489 | __x */
        "movl 8(%edx), %ebx\n" /* __p */
        "movl %edx, %eax\n" /* line 69 | this */
        "addl $0x14, %eax\n" /* this */
        /* { scope 2 */
        "movl $0x3322a8, 0x14(%edx)\n" /* line 35 */
        "movl %eax, (%esp)\n" /* line 37 */
        "calll ZN10COpenGLVAOD2Ev\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 94 | __x */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1054 | __p */
        "je .Lf2c0c78_002c0ed0\n"
        "movl %ebx, 0xc(%ebp)\n" /* __p, __x */
        "jmp .Lf2c0c78_002c0c8c\n"
        "jmp .Lf2c0c78_002c0df5\n"
        ".Lf2c0c78_002c0ed0:\n"
        "addl $0x3c, %esp\n" /* line 1059 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "jmp .Lf2c0c78_002c0df5\n"
    );
}

