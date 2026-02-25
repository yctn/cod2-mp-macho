/* ASM dump from: r_utils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_utils.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

int R_HashAssetName(const char *name);
int R_HashString(const char *string);
int R_CullPointAndRadius(const vec_t *pt, float radius, const DpvsPlane *clipPlanes, int clipPlaneCount);
double R_ConvertColorToBytes(const vec_t *colorFloat, byte *colorBytes);
qboolean R_PickMaterial(const vec_t *org, const vec_t *dir, char *name, char *surfaceFlags, char *contents, int charLimit);
Bool R_ValidXModelName(const char *name);
float FresnelTerm(float n0, float n1, float cosIncidentAngle);

/* line 26 */
__attribute__((naked))
int R_HashAssetName(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 26 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* name */
        /* { scope 1 */
        "movzbl (%ebx), %eax\n" /* line 35 | name */
        "testb %al, %al\n"
        "je .Lff5de8_000f5e16\n"
        "movl $0x77, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lff5de8_000f5dfd:\n"
        "movsbl %al, %eax\n" /* line 40 */
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "addl $1, %edx\n" /* line 42 */
        "movzbl -0x77(%ebx, %edx), %eax\n" /* line 35 | name */
        "testb %al, %al\n"
        "jne .Lff5de8_000f5dfd\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 46 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lff5de8_000f5e16:\n"
        "xorl %ecx, %ecx\n" /* line 35 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 46 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 49 */
__attribute__((naked))
int R_HashString(const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 49 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* string */
        /* { scope 1 */
        "movzbl (%ebx), %eax\n" /* line 58 | string */
        "testb %al, %al\n"
        "je .Lff5e1e_000f5e4e\n"
        "movl $0x77, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lff5e1e_000f5e33:\n"
        "orb $0x20, %al\n" /* line 60 */
        "movsbl %al, %eax\n"
        "imull %edx, %eax\n"
        "addl %eax, %ecx\n"
        "addl $1, %edx\n" /* line 62 */
        "movzbl -0x77(%ebx, %edx), %eax\n" /* line 58 | string */
        "testb %al, %al\n"
        "jne .Lff5e1e_000f5e33\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 66 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lff5e1e_000f5e4e:\n"
        "xorl %ecx, %ecx\n" /* line 58 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 66 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 90 */
__attribute__((naked))
int R_CullPointAndRadius(const vec_t *pt, float radius, const DpvsPlane *clipPlanes, int clipPlaneCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* pt */
        "movl 0x10(%ebp), %edx\n" /* clipPlanes */
        "movl 0x14(%ebp), %ebx\n" /* clipPlaneCount */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 96 | clipPlaneCount */
        "jle .Lff5e56_000f5ef6\n"
        "movss (%eax), %xmm5\n" /* line 304 */
        "movss 4(%eax), %xmm4\n"
        "movss 8(%eax), %xmm3\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 99 | radius */
        "movaps %xmm0, %xmm2\n"
        "xorps 0x2f2bc0, %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss (%edx), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 4(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 8(%edx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss 0xc(%edx), %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lff5e56_000f5eee\n"
        "leal 0x14(%edx), %eax\n"
        "movl %eax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lff5e56_000f5eb8:\n"
        "addl $1, %edx\n" /* line 96 */
        "cmpl %edx, %ebx\n" /* clipPlaneCount */
        "je .Lff5e56_000f5ef6\n"
        "movaps %xmm5, %xmm0\n" /* line 98 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss 0xc(%ecx), %xmm0\n"
        "addl $0x14, %eax\n"
        "addl $0x14, %ecx\n"
        "ucomiss %xmm0, %xmm2\n" /* line 99 */
        "jbe .Lff5e56_000f5eb8\n"
        ".Lff5e56_000f5eee:\n"
        "movl $2, %eax\n" /* line 96 */
        /* } scope */
        "popl %ebx\n" /* line 103 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lff5e56_000f5ef6:\n"
        "xorl %eax, %eax\n" /* line 96 */
        /* } scope */
        "popl %ebx\n" /* line 103 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 106 */
__attribute__((naked))
double R_ConvertColorToBytes(const vec_t *colorFloat, byte *colorBytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* colorFloat */
        "movl 0xc(%ebp), %ecx\n" /* colorBytes */
        "testl %edx, %edx\n" /* line 108 */
        "je .Lff5efc_000f5f4d\n"
        "movss 0x2ed5d4, %xmm0\n" /* line 121 | 255.0f */
        "movss 0xc(%edx), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movb %al, (%ecx)\n"
        "movss (%edx), %xmm1\n" /* line 122 */
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 1(%ecx)\n"
        "movss 4(%edx), %xmm1\n" /* line 123 */
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 2(%ecx)\n"
        "mulss 8(%edx), %xmm0\n" /* line 124 */
        "cvttss2si %xmm0, %eax\n"
        "movb %al, 3(%ecx)\n"
        "popl %ebp\n" /* line 133 */
        "retl\n"
        ".Lff5efc_000f5f4d:\n"
        "movl $0xffffffff, (%ecx)\n" /* line 110 */
        "popl %ebp\n" /* line 133 */
        "retl\n"
    );
}

/* line 154 */
__attribute__((naked))
qboolean R_PickMaterial(const vec_t *org, const vec_t *dir, char *name, char *surfaceFlags, char *contents, int charLimit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 154 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %edx\n" /* org */
        "movl 0xc(%ebp), %eax\n" /* dir */
        /* { scope 1 */
        "movss 0x2ed864, %xmm1\n" /* line 288 | 262144.0f */
        "movss (%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* end */
        "movss 4(%eax), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movl $0xf83fff7, 0x18(%esp)\n" /* line 165 */
        "movl $0, 0x14(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x158(%eax)\n"
        "cmpw $0, -0x26(%ebp)\n" /* line 167 */
        "jne .Lff5f56_000f61c7\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss -0x48(%ebp), %xmm0\n" /* trace */
        "jp .Lff5f56_000f5ff8\n"
        "je .Lff5f56_000f61c7\n"
        ".Lff5f56_000f5ff8:\n"
        "movl -0x30(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff5f56_000f61c7\n"
        "movl %eax, 4(%esp)\n" /* line 170 */
        "movl 0x10(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl 0x14(%ebp), %edx\n" /* line 172 | surfaceFlags */
        "movb $0, (%edx)\n"
        "movl %edx, %eax\n" /* line 173 */
        "addl 0x1c(%ebp), %eax\n" /* charLimit */
        "leal -1(%eax), %ecx\n"
        "movl %ecx, -0x60(%ebp)\n"
        "movb $0, -1(%eax)\n"
        "movl 0x18(%ebp), %eax\n" /* line 175 | contents */
        "movb $0, (%eax)\n"
        "movl 0x1c(%ebp), %eax\n" /* line 176 | charLimit */
        "addl 0x18(%ebp), %eax\n" /* contents */
        "leal -1(%eax), %edx\n"
        "movl %edx, -0x5c(%ebp)\n"
        "movb $0, -1(%eax)\n"
        "movl -0x38(%ebp), %eax\n" /* line 180 */
        "andl $0x1f00000, %eax\n"
        "shrl $0x14, %eax\n"
        "subl $1, %eax\n"
        "cmpl $0x15, %eax\n"
        "ja .Lff5f56_000f61d1\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 181 | charLimit */
        "movl %ecx, 8(%esp)\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0x195f1f4, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* surfaceFlags */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        ".Lff5f56_000f6076:\n"
        "movl -0x60(%ebp), %eax\n" /* line 184 */
        "cmpb $0, (%eax)\n"
        "jne .Lff5f56_000f61c7\n"
        "cld\n" /* line 186 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0x14(%ebp), %edi\n" /* surfaceFlags */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x58(%ebp)\n" /* surfaceFlagsLen */
        "testb $1, -0x34(%ebp)\n" /* line 188 */
        "je .Lff5f56_000f61f0\n"
        "movl 0x1c(%ebp), %edx\n" /* line 189 | charLimit */
        "movl %edx, 8(%esp)\n"
        "movl $0x225b2c, 4(%esp)\n" /* "solid" */
        "movl 0x18(%ebp), %ecx\n" /* contents */
        "movl %ecx, (%esp)\n"
        "calll strncpy\n"
        ".Lff5f56_000f60bb:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 192 */
        "cmpb $0, (%ecx)\n"
        "jne .Lff5f56_000f61c7\n"
        "cld\n" /* line 194 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0x18(%ebp), %edi\n" /* contents */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x54(%ebp)\n" /* contentsLen */
        "movl 0x195f1f4, %eax\n" /* line 196 */
        "movl 0x1b8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lff5f56_000f620f\n"
        "movl %eax, %ebx\n"
        "jmp .Lff5f56_000f610f\n"
        ".Lff5f56_000f60f3:\n"
        "movl 0x1c4(%ebx), %eax\n" /* line 208 */
        "testl %eax, -0x34(%ebp)\n"
        "jne .Lff5f56_000f6175\n"
        ".Lff5f56_000f60fe:\n"
        "movl 0x1cc(%ebx), %eax\n" /* line 196 */
        "addl $0x14, %ebx\n"
        "testl %eax, %eax\n"
        "je .Lff5f56_000f620f\n"
        ".Lff5f56_000f610f:\n"
        "movl 0x1c0(%ebx), %eax\n" /* line 198 */
        "testl %eax, -0x38(%ebp)\n"
        "je .Lff5f56_000f60f3\n"
        "movl 0x14(%ebp), %eax\n" /* line 200 | surfaceFlags */
        "movl -0x58(%ebp), %edx\n" /* surfaceFlagsLen */
        "movb $0x20, (%eax, %edx)\n"
        "movl %edx, %esi\n" /* line 201 */
        "addl $1, %esi\n"
        "addl %esi, %eax\n" /* line 202 */
        "movl %eax, -0x50(%ebp)\n"
        "movl 0x1c(%ebp), %eax\n" /* charLimit */
        "subl %esi, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x1b8(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x50(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll strncpy\n"
        "movl -0x60(%ebp), %eax\n" /* line 203 */
        "cmpb $0, (%eax)\n"
        "jne .Lff5f56_000f61c7\n"
        "cld\n" /* line 205 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x50(%ebp), %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %esi), %ecx\n"
        "movl %ecx, -0x58(%ebp)\n" /* surfaceFlagsLen */
        "movl 0x1c4(%ebx), %eax\n" /* line 208 */
        "testl %eax, -0x34(%ebp)\n"
        "je .Lff5f56_000f60fe\n"
        ".Lff5f56_000f6175:\n"
        "movl 0x18(%ebp), %edx\n" /* line 210 | contents */
        "movl -0x54(%ebp), %ecx\n" /* contentsLen */
        "movb $0x20, (%edx, %ecx)\n"
        "movl %ecx, %esi\n" /* line 211 */
        "addl $1, %esi\n"
        "addl %esi, %edx\n" /* line 212 */
        "movl %edx, -0x4c(%ebp)\n"
        "movl 0x1c(%ebp), %eax\n" /* charLimit */
        "subl %esi, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x1b8(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strncpy\n"
        "movl -0x5c(%ebp), %eax\n" /* line 213 */
        "cmpb $0, (%eax)\n"
        "jne .Lff5f56_000f61c7\n"
        "cld\n" /* line 215 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x4c(%ebp), %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %esi), %ecx\n"
        "movl %ecx, -0x54(%ebp)\n" /* contentsLen */
        "jmp .Lff5f56_000f60fe\n"
        ".Lff5f56_000f61c7:\n"
        "xorl %eax, %eax\n" /* line 196 */
        /* } scope */
        ".Lff5f56_000f61c9:\n"
        "addl $0x7c, %esp\n" /* line 220 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lff5f56_000f61d1:\n"
        "movl 0x1c(%ebp), %edx\n" /* line 183 | charLimit */
        "movl %edx, 8(%esp)\n"
        "movl $0x225b20, 4(%esp)\n" /* "^1default^7" */
        "movl 0x14(%ebp), %ecx\n" /* surfaceFlags */
        "movl %ecx, (%esp)\n"
        "calll strncpy\n"
        "jmp .Lff5f56_000f6076\n"
        ".Lff5f56_000f61f0:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 191 | charLimit */
        "movl %eax, 8(%esp)\n"
        "movl $0x225b34, 4(%esp)\n" /* "^3nonsolid^7" */
        "movl 0x18(%ebp), %edx\n" /* contents */
        "movl %edx, (%esp)\n"
        "calll strncpy\n"
        "jmp .Lff5f56_000f60bb\n"
        ".Lff5f56_000f620f:\n"
        "movl $1, %eax\n" /* line 196 */
        "jmp .Lff5f56_000f61c9\n"
    );
}

/* line 223 */
__attribute__((naked))
Bool R_ValidXModelName(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 223 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        "cld\n" /* line 225 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* name */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x3f, %ecx\n"
        "jbe .Lff6216_000f6240\n"
        ".Lff6216_000f6237:\n"
        "xorl %eax, %eax\n" /* line 227 */
        ".Lff6216_000f6239:\n"
        "addl $0x10, %esp\n" /* line 228 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff6216_000f6240:\n"
        "movl $6, 8(%esp)\n" /* line 227 */
        "movl $0x217dc8, 4(%esp)\n" /* "xmodel" */
        "movl %ebx, (%esp)\n" /* name */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lff6216_000f6237\n"
        "cmpb $0x2f, 6(%ebx)\n" /* name */
        "jne .Lff6216_000f6237\n"
        "movb $1, %al\n"
        "jmp .Lff6216_000f6239\n"
    );
}

/* line 231 */
__attribute__((naked))
float FresnelTerm(float n0, float n1, float cosIncidentAngle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 231 */
        "movl %esp, %ebp\n"
        "subl $0x78, %esp\n"
        "movss 0x10(%ebp), %xmm0\n" /* cosIncidentAngle */
        /* { scope 1 */
        "andps 0x2f2bd0, %xmm0\n" /* line 247 */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll acos\n"
        "fstpl -0x10(%ebp)\n" /* incidentAngle */
        "movss 8(%ebp), %xmm0\n" /* line 248 | n0 */
        "divss 0xc(%ebp), %xmm0\n" /* n1 */
        "cvtss2sd %xmm0, %xmm1\n"
        "movsd %xmm1, -0x28(%ebp)\n"
        "movsd -0x10(%ebp), %xmm0\n" /* incidentAngle */
        "movsd %xmm0, (%esp)\n"
        "calll sin\n"
        "fstpl -0x60(%ebp)\n"
        "movsd -0x60(%ebp), %xmm1\n"
        "mulsd -0x28(%ebp), %xmm1\n"
        "movsd 0x307c10, %xmm0\n" /* line 250 | 1.0 */
        "ucomisd %xmm0, %xmm1\n"
        "jbe .Lff6266_000f63a2\n"
        ".Lff6266_000f62ca:\n"
        "movsd %xmm0, (%esp)\n" /* line 255 */
        "calll asin\n"
        "fstpl -0x60(%ebp)\n"
        "movsd -0x60(%ebp), %xmm0\n"
        "movsd -0x10(%ebp), %xmm1\n" /* line 257 | incidentAngle */
        "addsd %xmm0, %xmm1\n"
        "movsd %xmm1, -0x20(%ebp)\n"
        "movsd -0x10(%ebp), %xmm1\n" /* line 260 | incidentAngle */
        "subsd %xmm0, %xmm1\n"
        "movsd %xmm1, -0x18(%ebp)\n"
        "movsd %xmm1, (%esp)\n"
        "calll sin\n"
        "fstpl -0x30(%ebp)\n"
        "movsd -0x20(%ebp), %xmm0\n" /* line 257 */
        "movsd %xmm0, (%esp)\n"
        "calll sin\n"
        "fstpl -0x38(%ebp)\n"
        "movsd -0x30(%ebp), %xmm1\n"
        "divsd -0x38(%ebp), %xmm1\n"
        "movsd %xmm1, -0x30(%ebp)\n"
        "movsd -0x18(%ebp), %xmm0\n" /* line 266 */
        "movsd %xmm0, (%esp)\n"
        "calll tan\n"
        "fstpl -0x60(%ebp)\n"
        "movsd -0x60(%ebp), %xmm0\n"
        "movsd -0x20(%ebp), %xmm1\n" /* line 263 */
        "movsd %xmm1, (%esp)\n"
        "movsd %xmm0, -0x58(%ebp)\n"
        "calll tan\n"
        "fstpl -0x40(%ebp)\n"
        "movsd -0x58(%ebp), %xmm0\n"
        "divsd -0x40(%ebp), %xmm0\n"
        "movsd -0x30(%ebp), %xmm1\n" /* line 269 */
        "mulsd %xmm1, %xmm1\n"
        "mulsd %xmm0, %xmm0\n"
        "addsd %xmm1, %xmm0\n"
        "movsd %xmm0, -0x30(%ebp)\n"
        "mulsd 0x307ce0, %xmm0\n" /* 0.5 */
        "cvtsd2ss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 270 | 0.0f */
        "jb .Lff6266_000f63b3\n"
        ".Lff6266_000f6389:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 272 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        /* } scope */
        "movss %xmm1, -0x64(%ebp)\n" /* line 275 */
        "flds -0x64(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lff6266_000f63a2:\n"
        "movsd 0x307c78, %xmm0\n" /* line 252 | -1.0 */
        "maxsd %xmm1, %xmm0\n"
        "jmp .Lff6266_000f62ca\n"
        ".Lff6266_000f63b3:\n"
        "jp .Lff6266_000f6389\n" /* line 270 */
        "pxor %xmm1, %xmm1\n"
        /* } scope */
        "movss %xmm1, -0x64(%ebp)\n" /* line 275 */
        "flds -0x64(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

