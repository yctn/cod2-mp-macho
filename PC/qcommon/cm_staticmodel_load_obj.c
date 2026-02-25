/* ASM dump from: cm_staticmodel_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_staticmodel_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

void CM_LoadStaticModels(void);

/* line 85 */
__attribute__((naked))
void CM_LoadStaticModels(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 85 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x17c, %esp\n"
        /* { scope 1 */
        "movl 0x195eda4, %eax\n" /* line 93 */
        "movl 0x98(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* ptr */
        "movl $0, 4(%eax)\n" /* line 97 */
        "movl $0, 8(%eax)\n" /* line 98 */
        "leal -0x1c(%ebp), %edi\n" /* ptr */
        ".Lf77ea4_00077ecf:\n"
        "movl %edi, (%esp)\n" /* line 103 */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 104 | ptr */
        "testl %ebx, %ebx\n"
        "je .Lf77ea4_00077fc8\n"
        ".Lf77ea4_00077ee2:\n"
        "cmpb $0x7b, (%eax)\n"
        "jne .Lf77ea4_00077fc8\n"
        "movb $0, -0xa4(%ebp)\n" /* line 107 | modelName */
        "movl $0, -0x13c(%ebp)\n" /* bMiscModel */
        "leal -0xe4(%ebp), %ebx\n" /* key */
        "leal -0x124(%ebp), %esi\n" /* value */
        ".Lf77ea4_00077f08:\n"
        "movl %edi, (%esp)\n" /* line 114 */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 115 | ptr */
        "testl %ecx, %ecx\n"
        "je .Lf77ea4_00077f88\n"
        ".Lf77ea4_00077f17:\n"
        "cmpb $0x7d, (%eax)\n"
        "je .Lf77ea4_00077f88\n"
        "movl %eax, 4(%esp)\n" /* line 117 */
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "movl %edi, (%esp)\n" /* line 120 */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %edx\n" /* line 121 | ptr */
        "testl %edx, %edx\n"
        "je .Lf77ea4_00077f88\n"
        "movl %eax, 4(%esp)\n" /* line 123 */
        "movl %esi, (%esp)\n"
        "calll strcpy\n"
        "movl $0x21c208, 4(%esp)\n" /* line 126 */
        "movl %ebx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_00077fe0\n"
        "movl $0x21c214, 4(%esp)\n" /* line 128 */
        "movl %esi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_00077f08\n"
        "movl $1, -0x13c(%ebp)\n" /* bMiscModel */
        "movl %edi, (%esp)\n" /* line 114 */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 115 | ptr */
        "testl %ecx, %ecx\n"
        "jne .Lf77ea4_00077f17\n"
        ".Lf77ea4_00077f88:\n"
        "movl -0x13c(%ebp), %ecx\n" /* line 138 | bMiscModel */
        "testl %ecx, %ecx\n"
        "je .Lf77ea4_00077ecf\n"
        "leal -0xa4(%ebp), %eax\n" /* modelName */
        "movl %eax, (%esp)\n"
        "calll Com_ValidXModelName\n"
        "testb %al, %al\n"
        "je .Lf77ea4_00077ecf\n"
        "movl 0x195eda4, %eax\n" /* line 139 */
        "addl $1, 4(%eax)\n"
        "movl %edi, (%esp)\n" /* line 103 */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 104 | ptr */
        "testl %ebx, %ebx\n"
        "jne .Lf77ea4_00077ee2\n"
        ".Lf77ea4_00077fc8:\n"
        "movl 0x195eda4, %ebx\n" /* line 142 */
        "movl 4(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_0007800f\n"
        /* } scope */
        ".Lf77ea4_00077fd5:\n"
        "addl $0x17c, %esp\n" /* line 219 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf77ea4_00077fe0:\n"
        "movl $0x21593c, 4(%esp)\n" /* line 131 */
        "movl %ebx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_00077f08\n"
        "movl %esi, 4(%esp)\n" /* line 133 */
        "leal -0xa4(%ebp), %eax\n" /* modelName */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lf77ea4_00077f08\n"
        ".Lf77ea4_0007800f:\n"
        "movl $0x19, 8(%esp)\n" /* line 145 */
        "movl $0x21c220, 4(%esp)\n" /* "CM_CreateStaticModel" */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl %eax, 8(%ebx)\n"
        "movl 0x98(%ebx), %eax\n" /* line 147 */
        "movl %eax, -0x1c(%ebp)\n" /* ptr */
        "movl %ebx, -0x14c(%ebp)\n"
        "movl $0, -0x150(%ebp)\n"
        "leal -0xe4(%ebp), %ebx\n" /* key */
        "leal -0x124(%ebp), %esi\n" /* value */
        ".Lf77ea4_00078055:\n"
        "movl %edi, (%esp)\n" /* line 155 */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %edx\n" /* line 156 | ptr */
        "testl %edx, %edx\n"
        "je .Lf77ea4_00077fd5\n"
        "cmpb $0x7b, (%eax)\n"
        "jne .Lf77ea4_00077fd5\n"
        "movb $0, -0xa4(%ebp)\n" /* line 159 | modelName */
        "xorl %eax, %eax\n" /* line 160 */
        "movl %eax, -0x20(%ebp)\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, -0x28(%ebp)\n" /* origin */
        "movl %eax, -0x2c(%ebp)\n" /* line 161 */
        "movl %eax, -0x30(%ebp)\n"
        "movl %eax, -0x34(%ebp)\n" /* angles */
        "movl $0x3f800000, %eax\n" /* line 162 */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, -0x40(%ebp)\n" /* scale */
        "movl $0, -0x12c(%ebp)\n"
        ".Lf77ea4_000780a4:\n"
        "movl %edi, (%esp)\n" /* line 169 */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 170 | ptr */
        "testl %ecx, %ecx\n"
        "je .Lf77ea4_00078124\n"
        ".Lf77ea4_000780b3:\n"
        "cmpb $0x7d, (%eax)\n"
        "je .Lf77ea4_00078124\n"
        "movl %eax, 4(%esp)\n" /* line 172 */
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "movl %edi, (%esp)\n" /* line 175 */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %edx\n" /* line 176 | ptr */
        "testl %edx, %edx\n"
        "je .Lf77ea4_00078124\n"
        "movl %eax, 4(%esp)\n" /* line 178 */
        "movl %esi, (%esp)\n"
        "calll strcpy\n"
        "movl $0x21c208, 4(%esp)\n" /* line 181 */
        "movl %ebx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_0007832b\n"
        "movl $0x21c214, 4(%esp)\n" /* line 183 */
        "movl %esi, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_000780a4\n"
        "movl $1, -0x12c(%ebp)\n"
        "movl %edi, (%esp)\n" /* line 169 */
        "calll Com_Parse\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 170 | ptr */
        "testl %ecx, %ecx\n"
        "jne .Lf77ea4_000780b3\n"
        ".Lf77ea4_00078124:\n"
        "movl -0x12c(%ebp), %eax\n" /* line 209 */
        "testl %eax, %eax\n"
        "je .Lf77ea4_00078055\n"
        "leal -0xa4(%ebp), %eax\n" /* modelName */
        "movl %eax, (%esp)\n"
        "calll Com_ValidXModelName\n"
        "testb %al, %al\n"
        "je .Lf77ea4_00078055\n"
        "movl -0x150(%ebp), %eax\n" /* line 211 */
        "movl -0x14c(%ebp), %ecx\n"
        "addl 8(%ecx), %eax\n"
        "movl %eax, -0x138(%ebp)\n" /* staticModel */
        /* { scope 2: staticModel */
        "cmpb $0, -0x9d(%ebp)\n" /* line 57 */
        "je .Lf77ea4_00078461\n"
        "pxor %xmm0, %xmm0\n" /* line 60 */
        "ucomiss -0x40(%ebp), %xmm0\n" /* scale */
        "je .Lf77ea4_00078483\n"
        ".Lf77ea4_00078178:\n"
        "ucomiss -0x3c(%ebp), %xmm0\n" /* line 63 */
        "je .Lf77ea4_000784c1\n"
        ".Lf77ea4_00078182:\n"
        "ucomiss -0x38(%ebp), %xmm0\n" /* line 66 */
        "je .Lf77ea4_000784f3\n"
        ".Lf77ea4_0007818c:\n"
        "leal -0x9d(%ebp), %edx\n" /* line 69 */
        "movl %edx, (%esp)\n"
        "calll CM_XModelPrecache\n"
        "testl %eax, %eax\n" /* line 70 */
        "je .Lf77ea4_00078452\n"
        "movl -0x138(%ebp), %edx\n" /* line 73 | staticModel */
        "movl %eax, 4(%edx)\n"
        /* { scope 3: axis */
        /* { scope 4 */
        "movl -0x138(%ebp), %edx\n" /* line 23 | staticModel, to */
        "addl $8, %edx\n" /* to */
        /* { scope 5 */
        "movl -0x28(%ebp), %eax\n" /* line 199 | origin */
        "movl -0x138(%ebp), %ecx\n" /* staticModel */
        "movl %eax, 8(%ecx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal -0x64(%ebp), %eax\n" /* line 26 | axis */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* angles */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 27 | scale */
        /* { scope 5 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x64(%ebp), %xmm1\n" /* axis */
        "movss %xmm1, -0x64(%ebp)\n" /* axis */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x60(%ebp), %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n"
        "mulss -0x5c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x5c(%ebp)\n"
        /* } scope */
        "movss -0x3c(%ebp), %xmm0\n" /* line 28 | scale */
        /* { scope 5 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x58(%ebp), %xmm1\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x54(%ebp), %xmm1\n"
        "movss %xmm1, -0x54(%ebp)\n"
        "mulss -0x50(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x50(%ebp)\n"
        /* } scope */
        "movss -0x38(%ebp), %xmm0\n" /* line 29 | scale */
        /* { scope 5 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x4c(%ebp), %xmm1\n"
        "movss %xmm1, -0x4c(%ebp)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x48(%ebp), %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "mulss -0x44(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x44(%ebp)\n"
        /* } scope */
        "movl -0x138(%ebp), %eax\n" /* line 30 | staticModel */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x64(%ebp), %edx\n" /* axis */
        "movl %edx, (%esp)\n"
        "calll MatrixInverse\n"
        "movl -0x138(%ebp), %ecx\n" /* line 32 | staticModel */
        "addl $0x44, %ecx\n"
        "movl %ecx, -0x134(%ebp)\n"
        "movl -0x138(%ebp), %eax\n" /* staticModel */
        "addl $0x38, %eax\n"
        "movl %eax, -0x130(%ebp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x64(%ebp), %edx\n" /* axis */
        "movl %edx, 4(%esp)\n"
        "movl -0x138(%ebp), %ecx\n" /* staticModel */
        "movl 4(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XModelGetStaticBounds\n"
        "testl %eax, %eax\n"
        "je .Lf77ea4_0007831f\n"
        "movl -0x138(%ebp), %eax\n" /* line 240 | staticModel */
        "movss 0x38(%eax), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, 0x38(%eax)\n"
        "movl -0x130(%ebp), %edx\n" /* line 241 */
        "movss 4(%edx), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movss 8(%edx), %xmm0\n" /* line 242 */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movss 0x44(%eax), %xmm0\n" /* line 240 */
        "addss -0x28(%ebp), %xmm0\n" /* origin */
        "movss %xmm0, 0x44(%eax)\n"
        "movl -0x134(%ebp), %ecx\n" /* line 241 */
        "movss 4(%ecx), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss 8(%ecx), %xmm0\n" /* line 242 */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf77ea4_0007831f:\n"
        "addl $0x50, -0x150(%ebp)\n" /* line 212 */
        "jmp .Lf77ea4_00078055\n"
        ".Lf77ea4_0007832b:\n"
        "movl $0x21593c, 4(%esp)\n" /* line 186 */
        "movl %ebx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_00078356\n"
        "movl %esi, 4(%esp)\n" /* line 188 */
        "leal -0xa4(%ebp), %eax\n" /* modelName */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lf77ea4_000780a4\n"
        ".Lf77ea4_00078356:\n"
        "movl $0x21a570, 4(%esp)\n" /* line 190 */
        "movl %ebx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_00078394\n"
        "leal -0x20(%ebp), %eax\n" /* line 192 */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl $0x21c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %esi, (%esp)\n"
        "calll sscanf\n"
        "jmp .Lf77ea4_000780a4\n"
        ".Lf77ea4_00078394:\n"
        "movl $0x21a53c, 4(%esp)\n" /* line 194 */
        "movl %ebx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_000783d2\n"
        "leal -0x2c(%ebp), %eax\n" /* line 196 */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* angles */
        "movl %edx, 8(%esp)\n"
        "movl $0x21c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %esi, (%esp)\n"
        "calll sscanf\n"
        "jmp .Lf77ea4_000780a4\n"
        ".Lf77ea4_000783d2:\n"
        "movl $0x21c244, 4(%esp)\n" /* line 198 */
        "movl %ebx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_00078410\n"
        "leal -0x40(%ebp), %eax\n" /* line 200 | scale */
        "leal -0x38(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal -0x3c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x21c238, 4(%esp)\n" /* "%f %f %f" */
        "movl %esi, (%esp)\n"
        "calll sscanf\n"
        "jmp .Lf77ea4_000780a4\n"
        ".Lf77ea4_00078410:\n"
        "movl $0x21c254, 4(%esp)\n" /* line 202 */
        "movl %ebx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf77ea4_000780a4\n"
        "movl %esi, (%esp)\n" /* line 204 */
        "calll atof\n"
        "fstpl -0x148(%ebp)\n"
        "cvtsd2ss -0x148(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss %xmm0, -0x40(%ebp)\n" /* scale */
        "jmp .Lf77ea4_000780a4\n"
        ".Lf77ea4_00078452:\n"
        "movl -0x14c(%ebp), %ecx\n" /* line 214 */
        "subl $1, 4(%ecx)\n"
        "jmp .Lf77ea4_00078055\n"
        /* { scope 2: staticModel */
        ".Lf77ea4_00078461:\n"
        "movl $0x21c260, 4(%esp)\n" /* line 58 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "pxor %xmm0, %xmm0\n" /* line 60 */
        "ucomiss -0x40(%ebp), %xmm0\n" /* scale */
        "jne .Lf77ea4_00078178\n"
        ".Lf77ea4_00078483:\n"
        "jp .Lf77ea4_00078178\n"
        "leal -0x9d(%ebp), %edx\n" /* line 61 */
        "movl %edx, 8(%esp)\n"
        "movl $0x21c27c, 4(%esp)\n" /* "Static model [%s] has x scale of 0.0
" */
        "movl $1, (%esp)\n"
        "movss %xmm0, -0x168(%ebp)\n"
        "calll Com_Error\n"
        "movss -0x168(%ebp), %xmm0\n"
        "ucomiss -0x3c(%ebp), %xmm0\n" /* line 63 */
        "jne .Lf77ea4_00078182\n"
        ".Lf77ea4_000784c1:\n"
        "jp .Lf77ea4_00078182\n"
        "leal -0x9d(%ebp), %ecx\n" /* line 64 */
        "movl %ecx, 8(%esp)\n"
        "movl $0x21c2a4, 4(%esp)\n" /* "Static model [%s] has y scale of 0.0
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss -0x38(%ebp), %xmm0\n" /* line 66 */
        "jne .Lf77ea4_0007818c\n"
        ".Lf77ea4_000784f3:\n"
        "jp .Lf77ea4_0007818c\n"
        "leal -0x9d(%ebp), %eax\n" /* line 67 */
        "movl %eax, 8(%esp)\n"
        "movl $0x21c2cc, 4(%esp)\n" /* "Static model [%s] has z scale of 0.0
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf77ea4_0007818c\n"
    );
}

