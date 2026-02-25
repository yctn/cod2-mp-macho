/* ASM dump from: rb_light.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_light.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static vec3_t gridBasisDirs[8]; /* 0x2f2a00 */
static int s_vc_log; /* 0xc96c80 */

void RB_SaveLightVisHistory(void);
int RB_DeriveEntityLights(vec4_t *colorForDir, float sunVisibility, const Material *material, D3DLIGHT9 *lights, int maxLights);
void RB_ShowLightVisCachePoints(const vec_t *viewOrigin, const DpvsPlane *clipPlanes, int clipPlaneCount);
float RB_GetLightingAtPoint(const GfxLightGrid *lightGrid, const vec_t *samplePos, vec4_t *colorForDir);
void RB_SetupEntityLighting(const GfxEntity *ent, GfxEntityLighting *lighting);
void RB_InitLightVisHistory(const char *bspName);

/* line 817 */
__attribute__((naked))
void RB_SaveLightVisHistory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 817 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl s_vc_log, %eax\n" /* line 821 */
        "testl %eax, %eax\n"
        "je .Lfeb284_000eb334\n"
        "movl 0x195eebc, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfeb284_000eb334\n"
        "leal -0x58(%ebp), %ebx\n" /* line 759 | filename */
        "movl %ebx, 4(%esp)\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_StripExtension\n"
        "xorl %esi, %esi\n" /* line 760 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "movl %esi, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl $4, %ecx\n"
        "cmpl $0x3f, %ecx\n"
        "ja .Lfeb284_000eb33c\n"
        ".Lfeb284_000eb2d6:\n"
        "cld\n" /* line 762 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "movl %esi, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x6972672e, (%ecx)\n"
        "movw $0x64, 4(%ecx)\n"
        "movl 0xc96c84, %eax\n" /* line 826 */
        "leal (%eax, %eax, 2), %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl s_vc_log, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_WriteFile\n"
        "movl s_vc_log, %eax\n" /* line 828 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $0, s_vc_log\n" /* line 829 */
        "movl $0, 0xc96c84\n"
        /* } scope */
        ".Lfeb284_000eb334:\n"
        "addl $0x5c, %esp\n" /* line 830 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfeb284_000eb33c:\n"
        "movl %ebx, 8(%esp)\n" /* line 761 */
        "movl $0x225854, 4(%esp)\n" /* "light grid log filename '%s.grid' is too long
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfeb284_000eb2d6\n"
    );
}

/* line 745 */
__attribute__((naked))
int RB_DeriveEntityLights(vec4_t *colorForDir, float sunVisibility, const Material *material, D3DLIGHT9 *lights, int maxLights)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 745 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        /* { scope 1: errorDirAvg */
        "movl 0x10(%ebp), %eax\n" /* line 657 | material */
        "movl 0x38(%eax), %eax\n"
        "movl 0x40(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 659 */
        "je .Lfeb356_000eb4ae\n"
        /* } scope */
        "cmpb $0, 0xe(%eax)\n" /* line 747 */
        "je .Lfeb356_000eb4ae\n"
        /* { scope 1: errorDirAvg */
        "movl 0x18(%ebp), %edx\n" /* line 696 | maxLights */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* lights */
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movl 8(%ebp), %ecx\n" /* colorForDir */
        "leal 0x20(%ecx), %eax\n"
        "leal 0x40(%ecx), %edx\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm3\n"
        "movaps %xmm4, %xmm1\n"
        "movl %edx, %ebx\n"
        ".Lfeb356_000eb3b5:\n"
        "addss (%ecx), %xmm1\n" /* line 553 */
        "addss (%eax), %xmm3\n" /* line 554 */
        "addss (%edx), %xmm4\n" /* line 555 */
        "addl $4, %ecx\n"
        "addl $4, %eax\n"
        "addl $4, %edx\n"
        "cmpl %eax, %ebx\n" /* line 551 */
        "jne .Lfeb356_000eb3b5\n"
        "movl 0x14(%ebp), %eax\n" /* line 674 | lights */
        "movl $3, (%eax)\n"
        "movss 0x2ed610, %xmm0\n" /* line 675 | 0.125f */
        "mulss %xmm0, %xmm1\n"
        "movss 0x2ed5d8, %xmm2\n" /* 0.5f */
        "mulss %xmm2, %xmm1\n"
        "movss %xmm1, 0x24(%eax)\n"
        "mulss %xmm0, %xmm3\n" /* line 676 */
        "mulss %xmm2, %xmm3\n"
        "movss %xmm3, 0x28(%eax)\n"
        "mulss %xmm0, %xmm4\n" /* line 677 */
        "mulss %xmm2, %xmm4\n"
        "movss %xmm4, 0x2c(%eax)\n"
        "movl $0x3f800000, %ebx\n" /* line 683 */
        "movl %ebx, 0x48(%eax)\n"
        "movl 0x195eebc, %eax\n" /* line 704 */
        "movl 0x109c(%eax), %eax\n"
        "leal 0xd4(%eax), %ecx\n" /* start */
        "leal 0xc8(%eax), %edx\n" /* dir */
        /* { scope 2 */
        "movss 0xc(%ebp), %xmm0\n" /* line 288 | sunVisibility */
        "mulss 0xc8(%eax), %xmm0\n"
        "addss 0xd4(%eax), %xmm0\n"
        "movss 0xc(%ebp), %xmm1\n" /* line 289 | sunVisibility */
        "mulss 4(%edx), %xmm1\n"
        "addss 4(%ecx), %xmm1\n"
        "movss 0xc(%ebp), %xmm3\n" /* line 290 | sunVisibility */
        "mulss 8(%edx), %xmm3\n"
        "movss %xmm3, 0xc(%ebp)\n" /* sunVisibility */
        "addss 8(%ecx), %xmm3\n"
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 705 | lights, light */
        "addl $0x68, %eax\n" /* light */
        /* { scope 2 */
        "movl 0x14(%ebp), %edx\n" /* line 674 | lights */
        "movl $3, 0x68(%edx)\n"
        "mulss %xmm2, %xmm0\n" /* line 675 */
        "movss %xmm0, 0x24(%eax)\n"
        "mulss %xmm2, %xmm1\n" /* line 676 */
        "movss %xmm1, 0x28(%eax)\n"
        "mulss %xmm3, %xmm2\n" /* line 677 */
        "movss %xmm2, 0x2c(%eax)\n"
        "movl %ebx, 0x48(%eax)\n" /* line 683 */
        "movl $2, -0xa0(%ebp)\n" /* lightCount */
        /* } scope */
        /* } scope */
        "movl -0xa0(%ebp), %eax\n" /* line 751 | lightCount */
        "addl $0xbc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: errorDirAvg */
        ".Lfeb356_000eb4ae:\n"
        "movl 0x18(%ebp), %edx\n" /* line 720 | maxLights */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* lights */
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movl 8(%ebp), %ecx\n" /* colorForDir */
        "leal 0x20(%ecx), %ebx\n"
        "leal 0x40(%ecx), %edx\n"
        "leal -0x84(%ebp), %edi\n" /* errorInDir */
        ".Lfeb356_000eb4e0:\n"
        "movl (%ecx), %eax\n" /* line 534 */
        "movl %eax, (%edi)\n"
        "movl (%ebx), %eax\n" /* line 535 */
        "movl %eax, 4(%edi)\n"
        "movl (%edx), %eax\n" /* line 536 */
        "movl %eax, 8(%edi)\n"
        "addl $4, %ecx\n"
        "addl $0xc, %edi\n"
        "addl $4, %ebx\n"
        "addl $4, %edx\n"
        "leal -0x24(%ebp), %eax\n" /* line 532 | errorDirAvg */
        "cmpl %eax, %edi\n"
        "jne .Lfeb356_000eb4e0\n"
        "movl 0x14(%ebp), %edx\n" /* lights */
        "movl %edx, -0x90(%ebp)\n"
        "movl $0, -0x8c(%ebp)\n"
        "movl -0x8c(%ebp), %ecx\n"
        ".Lfeb356_000eb51a:\n"
        "addl $1, %ecx\n" /* line 724 */
        "movl %ecx, -0xa0(%ebp)\n" /* lightCount */
        "cmpl %ecx, 0x18(%ebp)\n" /* maxLights */
        "jle .Lfeb356_000eb99c\n"
        /* { scope 2 */
        "movl $0, -0x24(%ebp)\n" /* line 183 | errorDirAvg */
        "movl $0, -0x20(%ebp)\n" /* line 184 */
        "movl $0, -0x1c(%ebp)\n" /* line 185 */
        "movl 0x195f184, %eax\n" /* line 304 */
        "movss (%eax), %xmm6\n"
        "movss 4(%eax), %xmm5\n"
        "movss 8(%eax), %xmm4\n"
        "pxor %xmm7, %xmm7\n"
        "xorl %ecx, %ecx\n"
        "leal -0x84(%ebp), %edx\n" /* errorInDir */
        "movss 0x2f2a60, %xmm3\n"
        "xorl %eax, %eax\n"
        ".Lfeb356_000eb56a:\n"
        "movaps %xmm6, %xmm2\n"
        "mulss (%edx), %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        /* { scope 3 */
        "movaps %xmm2, %xmm1\n" /* line 54 */
        "andps %xmm3, %xmm1\n"
        /* } scope */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss gridBasisDirs(%eax), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* errorDirAvg */
        "movss %xmm0, -0x24(%ebp)\n" /* errorDirAvg */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x2f2a04(%eax), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 0x2f2a08(%eax), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        /* } scope */
        "mulss %xmm2, %xmm2\n" /* line 580 */
        "addss %xmm2, %xmm7\n"
        "addl $1, %ecx\n" /* line 576 */
        "addl $0xc, %eax\n"
        "addl $0xc, %edx\n"
        "cmpl $8, %ecx\n"
        "jne .Lfeb356_000eb56a\n"
        "ucomiss 0x2ed870, %xmm7\n" /* line 582 | 0.0007999999797903001f */
        "jp .Lfeb356_000eb610\n"
        "jae .Lfeb356_000eb610\n"
        ".Lfeb356_000eb5ec:\n"
        "xorl %eax, %eax\n" /* line 643 */
        ".Lfeb356_000eb5ee:\n"
        "addl $0x68, -0x90(%ebp)\n"
        /* } scope */
        "testb %al, %al\n" /* line 724 */
        "je .Lfeb356_000eb99c\n"
        ".Lfeb356_000eb5fd:\n"
        "movl -0xa0(%ebp), %edx\n" /* lightCount */
        "movl %edx, -0x8c(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lfeb356_000eb51a\n"
        /* { scope 2 */
        ".Lfeb356_000eb610:\n"
        "leal -0x24(%ebp), %eax\n" /* line 586 | errorDirAvg */
        "movl %eax, (%esp)\n"
        "movss %xmm7, -0xb8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x24(%ebp), %xmm5\n" /* line 304 | errorDirAvg */
        "movss -0x20(%ebp), %xmm4\n"
        "movss -0x1c(%ebp), %xmm3\n"
        "xorl %ecx, %ecx\n"
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movaps %xmm0, %xmm2\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "leal -0x84(%ebp), %edx\n" /* errorInDir */
        "movss 0x2ed738, %xmm6\n" /* 0.009999999776482582f */
        "xorl %eax, %eax\n"
        "movss -0xb8(%ebp), %xmm7\n"
        ".Lfeb356_000eb66d:\n"
        "movaps %xmm5, %xmm1\n"
        "mulss gridBasisDirs(%eax), %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 0x2f2a04(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 0x2f2a08(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss %xmm1, %xmm6\n" /* line 592 */
        "jae .Lfeb356_000eb6e6\n"
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss (%edx), %xmm0\n"
        "addss -0x94(%ebp), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%edx), %xmm0\n"
        "addss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 290 */
        "mulss 8(%edx), %xmm0\n"
        "addss -0x9c(%ebp), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        /* } scope */
        "addss %xmm1, %xmm2\n" /* line 595 */
        ".Lfeb356_000eb6e6:\n"
        "addl $1, %ecx\n" /* line 589 */
        "addl $0xc, %eax\n"
        "addl $0xc, %edx\n"
        "cmpl $8, %ecx\n"
        "jne .Lfeb356_000eb66d\n"
        "pxor %xmm1, %xmm1\n" /* line 599 */
        "ucomiss %xmm1, %xmm2\n"
        "jp .Lfeb356_000eb703\n"
        "je .Lfeb356_000eb747\n"
        ".Lfeb356_000eb703:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 600 | 1.0f, scale */
        "divss %xmm2, %xmm0\n" /* scale */
        /* { scope 3 */
        "movss -0x94(%ebp), %xmm3\n" /* line 272 */
        "mulss %xmm0, %xmm3\n"
        "movss %xmm3, -0x94(%ebp)\n"
        "movss -0x98(%ebp), %xmm1\n" /* line 273 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "mulss -0x9c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x9c(%ebp)\n"
        ".Lfeb356_000eb747:\n"
        "leal -0x7c(%ebp), %ecx\n"
        "leal -0x80(%ebp), %esi\n"
        "xorl %ebx, %ebx\n"
        "pxor %xmm6, %xmm6\n"
        "pxor %xmm3, %xmm3\n"
        "pxor %xmm2, %xmm2\n"
        "leal -0x84(%ebp), %eax\n" /* errorInDir */
        "movss 0x2f2a70, %xmm4\n"
        "xorl %edx, %edx\n"
        /* } scope */
        ".Lfeb356_000eb76b:\n"
        "movss gridBasisDirs(%edx), %xmm1\n" /* line 304 */
        "mulss -0x24(%ebp), %xmm1\n" /* errorDirAvg */
        "movss 0x2f2a04(%edx), %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x2f2a08(%edx), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 605 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lfeb356_000eb7e7\n"
        "movaps %xmm1, %xmm0\n" /* line 606 | scale */
        "xorps %xmm4, %xmm0\n" /* scale */
        /* { scope 3 */
        "movss -0x94(%ebp), %xmm1\n" /* line 288 */
        "mulss %xmm0, %xmm1\n"
        "addss -8(%ecx), %xmm1\n"
        "movss %xmm1, -8(%ecx)\n"
        "movss -0x98(%ebp), %xmm1\n" /* line 289 */
        "mulss %xmm0, %xmm1\n"
        "addss 4(%eax), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss -0x9c(%ebp), %xmm0\n" /* line 290 */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        ".Lfeb356_000eb7e7:\n"
        "addss (%eax), %xmm2\n" /* line 240 */
        "addss (%esi), %xmm3\n" /* line 241 */
        "addss (%ecx), %xmm6\n" /* line 242 */
        "addl $1, %ebx\n" /* line 602 */
        "addl $0xc, %edx\n"
        "addl $0xc, %ecx\n"
        "addl $0xc, %esi\n"
        "addl $0xc, %eax\n"
        "cmpl $8, %ebx\n"
        "jne .Lfeb356_000eb76b\n"
        "movss 0x2ed610, %xmm0\n" /* line 272 | 0.125f */
        "movaps %xmm2, %xmm4\n"
        "mulss %xmm0, %xmm4\n"
        "movaps %xmm3, %xmm5\n" /* line 273 */
        "mulss %xmm0, %xmm5\n"
        "movaps %xmm0, %xmm3\n" /* line 274 */
        "mulss %xmm6, %xmm3\n"
        "pxor %xmm2, %xmm2\n"
        "leal -0x84(%ebp), %eax\n" /* errorInDir */
        "movl %eax, %edx\n"
        "movl 0x195f184, %ecx\n"
        "movss (%ecx), %xmm0\n"
        "movss %xmm0, -0xa4(%ebp)\n"
        "movss 4(%ecx), %xmm6\n"
        ".Lfeb356_000eb84b:\n"
        "movss (%eax), %xmm0\n" /* line 614 */
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movss 4(%eax), %xmm0\n" /* line 615 */
        "subss %xmm5, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%eax), %xmm0\n" /* line 616 */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "movss -0xa4(%ebp), %xmm1\n" /* line 304 */
        "mulss (%edx), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm1, %xmm1\n" /* line 618 */
        "addss %xmm1, %xmm2\n"
        "addl $0xc, %eax\n"
        "addl $0xc, %edx\n"
        "cmpl %edi, %eax\n" /* line 612 */
        "jne .Lfeb356_000eb84b\n"
        "movaps %xmm7, %xmm0\n" /* line 620 */
        "subss %xmm2, %xmm0\n"
        "ucomiss 0x2ed874, %xmm0\n" /* 0.020000001415610313f */
        "jp .Lfeb356_000eb8c2\n"
        "jb .Lfeb356_000eb5ec\n"
        ".Lfeb356_000eb8c2:\n"
        "movl -0x90(%ebp), %eax\n" /* line 623 */
        "movl $3, (%eax)\n"
        "mulss 0x2ed5d8, %xmm4\n" /* line 624 | 0.5f */
        "movss %xmm4, 0x24(%eax)\n"
        "mulss 0x2ed5d8, %xmm5\n" /* line 625 | 0.5f */
        "movss %xmm5, 0x28(%eax)\n"
        "mulss 0x2ed5d8, %xmm3\n" /* line 626 | 0.5f */
        "movss %xmm3, 0x2c(%eax)\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 627 | 0.5f */
        "mulss -0x94(%ebp), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 0x2ed5d8, %xmm1\n" /* line 628 | 0.5f */
        "mulss -0x98(%ebp), %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        "movss 0x2ed5d8, %xmm3\n" /* line 629 | 0.5f */
        "mulss -0x9c(%ebp), %xmm3\n"
        "movss %xmm3, 0xc(%eax)\n"
        "movss -0x24(%ebp), %xmm2\n" /* line 316 | errorDirAvg */
        "movss -0x20(%ebp), %xmm3\n"
        "movss -0x1c(%ebp), %xmm4\n"
        "movaps %xmm2, %xmm0\n" /* line 631 */
        "mulss %xmm2, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0x2ed66c, %xmm0\n" /* 1.0000001111620804e-06f */
        "jae .Lfeb356_000ebab6\n"
        "jp .Lfeb356_000ebab6\n"
        "movl $0, 0x40(%eax)\n" /* line 635 */
        "movl $0, 0x44(%eax)\n" /* line 636 */
        "movl $0x3f800000, 0x48(%eax)\n" /* line 637 */
        "movl $1, %eax\n"
        "addl $0x68, -0x90(%ebp)\n" /* line 643 */
        /* } scope */
        "testb %al, %al\n" /* line 724 */
        "jne .Lfeb356_000eb5fd\n"
        ".Lfeb356_000eb99c:\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 729 */
        "leal (%ecx, %ecx, 2), %edx\n"
        "leal (%ecx, %edx, 4), %edx\n"
        "movl 0x14(%ebp), %eax\n" /* lights */
        "leal (%eax, %edx, 8), %edx\n"
        "movl $3, (%edx)\n"
        "movl 0x195eebc, %ecx\n" /* line 730 */
        "movl 0x109c(%ecx), %eax\n"
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss 0xd4(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x24(%edx)\n"
        "movl 0x109c(%ecx), %eax\n" /* line 731 */
        "movss 0xd8(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x28(%edx)\n"
        "movl 0x109c(%ecx), %eax\n" /* line 732 */
        "movss 0xdc(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x2c(%edx)\n"
        "movl 0x109c(%ecx), %eax\n" /* line 733 */
        "movss 0xc(%ebp), %xmm0\n" /* sunVisibility */
        "mulss 0xc8(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movl 0x109c(%ecx), %eax\n" /* line 734 */
        "movss 0xc(%ebp), %xmm0\n" /* sunVisibility */
        "mulss 0xcc(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movl 0x109c(%ecx), %eax\n" /* line 735 */
        "movss 0xc(%ebp), %xmm0\n" /* sunVisibility */
        "mulss 0xd0(%eax), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%edx)\n"
        "movl 0x109c(%ecx), %eax\n" /* line 736 */
        "movss 0x2f2a70, %xmm1\n"
        "movss 0xb8(%eax), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, 0x40(%edx)\n"
        "movl 0x109c(%ecx), %eax\n" /* line 737 */
        "movss 0xbc(%eax), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, 0x44(%edx)\n"
        "movl 0x109c(%ecx), %eax\n" /* line 738 */
        "movss 0xc0(%eax), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, 0x48(%edx)\n"
        /* } scope */
        "movl -0xa0(%ebp), %eax\n" /* line 751 | lightCount */
        "addl $0xbc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: errorDirAvg */
        /* { scope 2 */
        ".Lfeb356_000ebab6:\n"
        "movss 0x2f2a70, %xmm0\n" /* line 641 */
        "xorps %xmm0, %xmm2\n"
        "movl -0x90(%ebp), %eax\n"
        "movss %xmm2, 0x40(%eax)\n"
        "xorps %xmm0, %xmm3\n" /* line 642 */
        "movss %xmm3, 0x44(%eax)\n"
        "xorps %xmm0, %xmm4\n" /* line 643 */
        "movss %xmm4, 0x48(%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lfeb356_000eb5ee\n"
    );
}

/* line 201 */
__attribute__((naked))
void RB_ShowLightVisCachePoints(const vec_t *viewOrigin, const DpvsPlane *clipPlanes, int clipPlaneCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 201 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* viewOrigin */
        /* { scope 1: top */
        "movl s_vc_log, %esi\n" /* line 215 */
        "testl %esi, %esi\n"
        "je .Lfebae6_000ebda0\n"
        "movl 0x195f194, %eax\n" /* line 218 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* spread */
        "testl %eax, %eax\n" /* line 219 */
        "jle .Lfebae6_000ebda0\n"
        "movss (%ebx), %xmm0\n" /* line 428 | viewOrigin */
        "addss 0x2ed688, %xmm0\n" /* 131072.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x58(%ebp)\n"
        "cvttss2si -0x58(%ebp), %eax\n"
        "sarl $5, %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* x */
        "movss 4(%ebx), %xmm0\n" /* viewOrigin */
        "addss 0x2ed688, %xmm0\n" /* 131072.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x5c(%ebp)\n"
        "cvttss2si -0x5c(%ebp), %edx\n"
        "sarl $5, %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* y */
        "movss 0x2ed688, %xmm0\n" /* line 443 | 131072.0f */
        "addss 8(%ebx), %xmm0\n" /* viewOrigin */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x60(%ebp)\n"
        "cvttss2si -0x60(%ebp), %edx\n"
        "sarl $6, %edx\n"
        "movl -0x50(%ebp), %eax\n" /* line 226 | x */
        "shll $5, %eax\n"
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* origin */
        "movl -0x4c(%ebp), %eax\n" /* line 227 | y */
        "shll $5, %eax\n"
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movl %edx, %eax\n" /* line 228 */
        "shll $6, %eax\n"
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 236 | spread */
        "negl %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "subl $1, %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl $0xffffffff, -0x40(%ebp)\n" /* dz */
        ".Lfebae6_000ebbe3:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 233 */
        "testl %ecx, %ecx\n"
        "js .Lfebae6_000ebd8e\n"
        "movl -0x30(%ebp), %eax\n"
        "shll $6, %eax\n"
        "cmpl $0x80000, %eax\n"
        "jg .Lfebae6_000ebd8e\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 236 | viewOrigin */
        "cmpl %ebx, -0x3c(%ebp)\n" /* viewOrigin, spread */
        "jl .Lfebae6_000ebd8e\n"
        "movl -0x4c(%ebp), %edx\n" /* y */
        "addl %ebx, %edx\n" /* viewOrigin */
        "movl %edx, -0x34(%ebp)\n"
        "movl %ebx, -0x44(%ebp)\n" /* viewOrigin, dy */
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n"
        ".Lfebae6_000ebc24:\n"
        "movl -0x34(%ebp), %edx\n" /* line 239 */
        "testl %edx, %edx\n"
        "js .Lfebae6_000ebd7a\n"
        "movl -0x34(%ebp), %eax\n"
        "shll $5, %eax\n"
        "cmpl $0x80000, %eax\n"
        "jg .Lfebae6_000ebd7a\n"
        "movl -0x50(%ebp), %edi\n" /* x */
        "addl -0x2c(%ebp), %edi\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* dx */
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        ".Lfebae6_000ebc5a:\n"
        "testl %edi, %edi\n" /* line 245 */
        "js .Lfebae6_000ebd67\n"
        "movl %edi, %eax\n"
        "shll $5, %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "cmpl $0x80000, %eax\n"
        "jg .Lfebae6_000ebd67\n"
        /* { scope 2 */
        "movl 0xc96c84, %edx\n" /* line 169 */
        "subl $1, %edx\n"
        "movl %edx, -0x6c(%ebp)\n" /* top */
        "js .Lfebae6_000ebce2\n"
        "movl s_vc_log, %ecx\n" /* line 172 */
        "movl %ecx, -0x38(%ebp)\n"
        "xorl %esi, %esi\n"
        "movl %ecx, %ebx\n"
        ".Lfebae6_000ebc90:\n"
        "movl -0x6c(%ebp), %edx\n" /* line 171 | top */
        "addl %esi, %edx\n"
        "sarl $1, %edx\n"
        "leal (%edx, %edx, 2), %ecx\n" /* line 172 */
        "leal (%ebx, %ecx, 2), %ecx\n"
        "movzwl (%ecx), %eax\n"
        "movl %edi, %ebx\n" /* line 173 */
        "subl %eax, %ebx\n"
        "movl %ebx, %eax\n"
        "jne .Lfebae6_000ebcc6\n"
        "movzwl 2(%ecx), %eax\n" /* line 175 */
        "movl -0x34(%ebp), %ebx\n" /* line 176 */
        "subl %eax, %ebx\n"
        "movl %ebx, %eax\n"
        "jne .Lfebae6_000ebcc6\n"
        "movzwl 4(%ecx), %eax\n" /* line 178 */
        "movl -0x30(%ebp), %ecx\n" /* line 179 */
        "subl %eax, %ecx\n"
        "movl %ecx, %eax\n"
        "je .Lfebae6_000ebdb2\n"
        ".Lfebae6_000ebcc6:\n"
        "testl %eax, %eax\n" /* line 184 */
        "js .Lfebae6_000ebcd7\n"
        "leal 1(%edx), %esi\n" /* line 187 */
        "cmpl %esi, -0x6c(%ebp)\n" /* line 169 | top */
        "jl .Lfebae6_000ebce2\n"
        ".Lfebae6_000ebcd2:\n"
        "movl -0x38(%ebp), %ebx\n"
        "jmp .Lfebae6_000ebc90\n"
        ".Lfebae6_000ebcd7:\n"
        "subl $1, %edx\n" /* line 185 */
        "movl %edx, -0x6c(%ebp)\n" /* top */
        "cmpl %esi, -0x6c(%ebp)\n" /* line 169 | top */
        "jge .Lfebae6_000ebcd2\n"
        /* } scope */
        ".Lfebae6_000ebce2:\n"
        "movl -0x54(%ebp), %eax\n" /* line 251 */
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* origin */
        "movss -0x64(%ebp), %xmm0\n" /* line 252 */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x68(%ebp), %xmm0\n" /* line 253 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* line 254 | clipPlaneCount */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* clipPlanes */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* origin */
        "movl %ecx, (%esp)\n"
        "calll R_CullPointAndRadius\n"
        "cmpl $2, %eax\n"
        "je .Lfebae6_000ebd67\n"
        "cmpl $1, -0x40(%ebp)\n" /* line 257 | dz */
        "jbe .Lfebae6_000ebdab\n"
        "movl 0x195ed98, %eax\n"
        ".Lfebae6_000ebd38:\n"
        "movl $0x217ff8, 0x10(%esp)\n" /* "." */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %ebx\n" /* origin, viewOrigin */
        "movl %ebx, 4(%esp)\n" /* viewOrigin */
        "movl 0x195f188, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugString\n"
        ".Lfebae6_000ebd67:\n"
        "addl $1, -0x48(%ebp)\n" /* line 242 | dx */
        "addl $1, %edi\n"
        "movl -0x48(%ebp), %eax\n" /* dx */
        "cmpl %eax, -0x3c(%ebp)\n" /* spread */
        "jge .Lfebae6_000ebc5a\n"
        ".Lfebae6_000ebd7a:\n"
        "addl $1, -0x44(%ebp)\n" /* line 236 | dy */
        "addl $1, -0x34(%ebp)\n"
        "movl -0x44(%ebp), %edx\n" /* dy */
        "cmpl %edx, -0x3c(%ebp)\n" /* spread */
        "jge .Lfebae6_000ebc24\n"
        ".Lfebae6_000ebd8e:\n"
        "addl $1, -0x40(%ebp)\n" /* line 230 | dz */
        "addl $1, -0x30(%ebp)\n"
        "cmpl $2, -0x40(%ebp)\n" /* dz */
        "jne .Lfebae6_000ebbe3\n"
        /* } scope */
        ".Lfebae6_000ebda0:\n"
        "addl $0x8c, %esp\n" /* line 261 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: top */
        ".Lfebae6_000ebdab:\n"
        "movl 0x195ed60, %eax\n" /* line 257 */
        "jmp .Lfebae6_000ebd38\n"
        ".Lfebae6_000ebdb2:\n"
        "testl %edx, %edx\n" /* line 248 */
        "jns .Lfebae6_000ebd67\n"
        "jmp .Lfebae6_000ebce2\n"
    );
}

/* line 412 */
__attribute__((naked))
float RB_GetLightingAtPoint(const GfxLightGrid *lightGrid, const vec_t *samplePos, vec4_t *colorForDir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 412 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        /* { scope 1: boxMins, boxMaxs */
        "movss 0x2ed688, %xmm3\n" /* line 433 | 131072.0f */
        "movl 0xc(%ebp), %eax\n" /* samplePos */
        "movss (%eax), %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, (%esp)\n" /* line 443 */
        "movss %xmm0, -0xe8(%ebp)\n"
        "movss %xmm3, -0x108(%ebp)\n"
        "calll floorf\n"
        "fstps -0xb8(%ebp)\n"
        "cvttss2si -0xb8(%ebp), %edx\n"
        "sarl $5, %edx\n"
        "movl %edx, -0x98(%ebp)\n" /* x0 */
        "movss 0x2ed878, %xmm2\n" /* line 434 | 0.03125f */
        "movss -0xe8(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 435 | 1.0f */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n" /* weight */
        "movl 0xc(%ebp), %eax\n" /* line 437 | samplePos */
        "addl $4, %eax\n"
        "movl %eax, -0xb4(%ebp)\n"
        "movss -0x108(%ebp), %xmm3\n"
        "movl 0xc(%ebp), %edx\n" /* samplePos */
        "movss 4(%edx), %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, -0x84(%ebp)\n"
        "movss %xmm0, (%esp)\n" /* line 443 */
        "movss %xmm2, -0xf8(%ebp)\n"
        "calll floorf\n"
        "fstps -0xbc(%ebp)\n"
        "cvttss2si -0xbc(%ebp), %eax\n"
        "sarl $5, %eax\n"
        "movl %eax, -0x94(%ebp)\n" /* y0 */
        "movss -0xf8(%ebp), %xmm2\n" /* line 438 */
        "mulss -0x84(%ebp), %xmm2\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movss %xmm2, -0x54(%ebp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 439 | 1.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 441 | samplePos */
        "addl $8, %edx\n"
        "movl %edx, -0xb0(%ebp)\n"
        "movss -0x108(%ebp), %xmm3\n"
        "movl 0xc(%ebp), %ecx\n" /* samplePos */
        "addss 8(%ecx), %xmm3\n"
        "movss %xmm3, (%esp)\n" /* line 443 */
        "movss %xmm3, -0x108(%ebp)\n"
        "calll floorf\n"
        "fstps -0xc0(%ebp)\n"
        "cvttss2si -0xc0(%ebp), %edi\n" /* z */
        "sarl $6, %edi\n" /* z */
        "movl %edi, -0x90(%ebp)\n" /* z, z0 */
        "movss -0x108(%ebp), %xmm3\n" /* line 442 */
        "mulss 0x2ed790, %xmm3\n" /* 0.015625f */
        "cvtsi2ssl %edi, %xmm0\n" /* z */
        "subss %xmm0, %xmm3\n"
        "movss %xmm3, -0x4c(%ebp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 443 | 1.0f */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movl 0x195f190, %eax\n" /* line 447 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfebdbc_000ec54a\n"
        ".Lfebdbc_000ebf41:\n"
        "movl $0x60, 8(%esp)\n" /* line 454 */
        "movl $0, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* colorForDir */
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n" /* maxWeight */
        "movl $0, -0x9c(%ebp)\n" /* cornerIndex */
        "movss %xmm0, -0x88(%ebp)\n" /* sunWeight */
        ".Lfebdbc_000ebf7a:\n"
        "movl -0x9c(%ebp), %eax\n" /* line 460 | cornerIndex */
        "andl $1, %eax\n"
        "movl %eax, -0xac(%ebp)\n"
        "movl -0x98(%ebp), %edx\n" /* x0 */
        "addl %eax, %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        "movl -0x9c(%ebp), %ecx\n" /* line 461 | cornerIndex */
        "sarl $1, %ecx\n"
        "andl $1, %ecx\n"
        "movl %ecx, -0xa8(%ebp)\n"
        "movl -0x94(%ebp), %edi\n" /* y0, z */
        "addl %ecx, %edi\n" /* z */
        "movl %edi, -0x70(%ebp)\n" /* z */
        "movl -0x9c(%ebp), %eax\n" /* line 462 | cornerIndex */
        "sarl $2, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, -0xa4(%ebp)\n"
        "movl -0x90(%ebp), %edx\n" /* z0 */
        "addl %eax, %edx\n"
        "movl %edx, -0x74(%ebp)\n"
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        "movl 0x195f18c, %eax\n" /* line 329 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfebdbc_000ec2d2\n"
        /* { scope 3: boxMins, boxMaxs */
        "movl 0xc96c84, %ecx\n" /* line 167 */
        "movl %ecx, -0x11c(%ebp)\n"
        "movl %ecx, %ebx\n" /* line 169 | top */
        "subl $1, %ebx\n" /* top */
        "js .Lfebdbc_000ec042\n"
        "movl s_vc_log, %edi\n" /* line 172 */
        "movl %edi, -0x80(%ebp)\n"
        "xorl %esi, %esi\n"
        ".Lfebdbc_000ebffd:\n"
        "leal (%ebx, %esi), %ecx\n" /* line 171 | top */
        "sarl $1, %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 172 */
        "leal (%edi, %eax, 2), %edx\n"
        "movzwl (%edx), %eax\n"
        "movl -0x6c(%ebp), %edi\n" /* line 173 */
        "subl %eax, %edi\n"
        "movl %edi, %eax\n"
        "jne .Lfebdbc_000ec02e\n"
        "movzwl 2(%edx), %eax\n" /* line 175 */
        "movl -0x70(%ebp), %edi\n" /* line 176 */
        "subl %eax, %edi\n"
        "movl %edi, %eax\n"
        "jne .Lfebdbc_000ec02e\n"
        "movzwl 4(%edx), %eax\n" /* line 178 */
        "movl -0x74(%ebp), %edx\n" /* line 179 */
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "je .Lfebdbc_000ec054\n"
        ".Lfebdbc_000ec02e:\n"
        "testl %eax, %eax\n" /* line 184 */
        "js .Lfebdbc_000ec2d9\n"
        "leal 1(%ecx), %esi\n" /* line 187 */
        "cmpl %esi, %ebx\n" /* line 169 | top */
        "jl .Lfebdbc_000ec044\n"
        "movl -0x80(%ebp), %edi\n"
        "jmp .Lfebdbc_000ebffd\n"
        ".Lfebdbc_000ec042:\n"
        "xorl %esi, %esi\n"
        /* { scope 4 */
        ".Lfebdbc_000ec044:\n"
        "cmpl $0x3fffff, -0x11c(%ebp)\n" /* line 148 */
        "jle .Lfebdbc_000ec24c\n"
        ".Lfebdbc_000ec054:\n"
        "movl -0x70(%ebp), %eax\n"
        /* } scope */
        /* } scope */
        /* { scope 3: boxMins, boxMaxs */
        ".Lfebdbc_000ec057:\n"
        "movl -0x6c(%ebp), %ebx\n" /* line 270 | top */
        "andl $0xfffffffc, %ebx\n" /* top */
        "shll $0x13, %ebx\n" /* top */
        "andl $0xfffffffc, %eax\n" /* line 271 */
        "shll $8, %eax\n"
        "orl %eax, %ebx\n" /* top */
        "movl -0x74(%ebp), %eax\n" /* line 272 */
        "sarl $2, %eax\n"
        "orl %eax, %ebx\n" /* top */
        "movzbl -0x6c(%ebp), %edx\n" /* line 279 */
        "shlb $6, %dl\n"
        "movl -0x70(%ebp), %eax\n"
        "andl $3, %eax\n"
        "shll $4, %eax\n"
        "orb %al, %dl\n"
        "movl -0x74(%ebp), %eax\n"
        "andl $3, %eax\n"
        "shll $2, %eax\n"
        "orb %al, %dl\n"
        "movl 8(%ebp), %edi\n" /* line 298 | lightGrid, bot */
        "movl (%edi), %esi\n" /* bot, pos */
        "subl $1, %esi\n" /* pos */
        "js .Lfebdbc_000ec0f1\n"
        "movl 4(%edi), %eax\n" /* line 301 | bot */
        "movl %eax, -0xd0(%ebp)\n"
        "xorl %edi, %edi\n" /* bot */
        "movzbl %dl, %edx\n"
        "movl %edx, -0xc8(%ebp)\n"
        ".Lfebdbc_000ec0ab:\n"
        "leal (%edi, %esi), %edx\n" /* line 300 | bot */
        "sarl $1, %edx\n"
        "leal (, %edx, 8), %ecx\n" /* line 301 */
        "movl %ecx, -0xc4(%ebp)\n"
        "movl -0xd0(%ebp), %ecx\n"
        "addl -0xc4(%ebp), %ecx\n"
        "movl (%ecx), %eax\n"
        "subl %ebx, %eax\n" /* line 302 | top */
        "jne .Lfebdbc_000ec0e2\n"
        "movzbl 4(%ecx), %eax\n" /* line 304 */
        "subl -0xc8(%ebp), %eax\n"
        "andl $0xfffffffe, %eax\n" /* line 305 */
        "je .Lfebdbc_000ec2ec\n"
        ".Lfebdbc_000ec0e2:\n"
        "testl %eax, %eax\n" /* line 312 */
        "js .Lfebdbc_000ec2ae\n"
        "leal -1(%edx), %esi\n" /* line 315 | pos */
        "cmpl %esi, %edi\n" /* line 298 | pos, bot */
        "jle .Lfebdbc_000ec0ab\n"
        /* } scope */
        /* } scope */
        ".Lfebdbc_000ec0f1:\n"
        "addl $1, -0x9c(%ebp)\n" /* line 458 | cornerIndex */
        "cmpl $8, -0x9c(%ebp)\n" /* cornerIndex */
        "jne .Lfebdbc_000ebf7a\n"
        ".Lfebdbc_000ec105:\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 475 | maxWeight */
        "ucomiss 0x2ed710, %xmm0\n" /* 0.9800000190734863f */
        "jae .Lfebdbc_000ec23b\n"
        "jp .Lfebdbc_000ec23b\n"
        "pxor %xmm2, %xmm2\n" /* line 477 */
        "ucomiss %xmm2, %xmm0\n"
        "jne .Lfebdbc_000ec426\n"
        "jp .Lfebdbc_000ec426\n"
        "movss -0x5c(%ebp), %xmm0\n" /* line 479 */
        "xorl %eax, %eax\n"
        "ucomiss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "seta %al\n"
        "movl -0x98(%ebp), %ecx\n" /* x0 */
        "leal (%eax, %ecx), %edx\n"
        "movss -0x54(%ebp), %xmm0\n" /* line 480 */
        "xorl %eax, %eax\n"
        "ucomiss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "seta %al\n"
        "movl -0x94(%ebp), %edi\n" /* y0, z */
        "leal (%eax, %edi), %esi\n" /* y */
        "movss -0x4c(%ebp), %xmm0\n" /* line 481 */
        "xorl %eax, %eax\n"
        "ucomiss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "seta %al\n"
        "movl -0x90(%ebp), %ecx\n" /* z0 */
        "leal (%eax, %ecx), %edi\n" /* z */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        "movl 0x195eebc, %eax\n" /* line 390 */
        "movl 0x109c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfebdbc_000ec49d\n"
        "movl 0x195f180, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfebdbc_000ec49d\n"
        /* } scope */
        ".Lfebdbc_000ec1a5:\n"
        "movl 0x10(%ebp), %eax\n" /* line 447 | colorForDir */
        "movl $0, (%eax)\n"
        "movl $0x3f800000, %edx\n" /* line 448 */
        "movl %edx, 4(%eax)\n"
        "movl $0, 8(%eax)\n" /* line 449 */
        "movl %edx, 0xc(%eax)\n" /* line 450 */
        "movl 0x10(%ebp), %eax\n" /* line 373 | colorForDir, v */
        "addl $0x10, %eax\n" /* v */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        "movl 0x10(%ebp), %ecx\n" /* line 447 | colorForDir */
        "movl $0, 0x10(%ecx)\n"
        "movl %edx, 4(%eax)\n" /* line 448 */
        "movl $0, 8(%eax)\n" /* line 449 */
        "movl %edx, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 374 | v */
        "addl $0x20, %eax\n" /* v */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        "movl $0, 0x20(%ecx)\n" /* line 447 */
        "movl $0, 4(%eax)\n" /* line 448 */
        "movl %edx, 8(%eax)\n" /* line 449 */
        "movl %edx, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 375 | v */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        "movl $0, 0x30(%ecx)\n" /* line 447 */
        "movl $0, 4(%eax)\n" /* line 448 */
        "movl %edx, 8(%eax)\n" /* line 449 */
        "movl %edx, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 376 | v */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        "movl $0, 0x40(%ecx)\n" /* line 447 */
        "movl $0, 4(%eax)\n" /* line 448 */
        "movl $0, 8(%eax)\n" /* line 449 */
        "movl $0, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 377 | v */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        "movl %edx, 0x50(%ecx)\n" /* line 447 */
        "movl %edx, 4(%eax)\n" /* line 448 */
        "movl %edx, 8(%eax)\n" /* line 449 */
        "movl %edx, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        /* } scope */
        ".Lfebdbc_000ec23b:\n"
        "flds -0x88(%ebp)\n" /* line 495 | sunWeight */
        "addl $0x13c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: boxMins, boxMaxs */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        /* { scope 3: boxMins, boxMaxs */
        /* { scope 4 */
        ".Lfebdbc_000ec24c:\n"
        "leal (%esi, %esi, 2), %ebx\n" /* line 151 */
        "addl %ebx, %ebx\n"
        "subl %esi, -0x11c(%ebp)\n"
        "movl -0x11c(%ebp), %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl s_vc_log, %eax\n"
        "addl %ebx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "addl $6, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        "movl s_vc_log, %eax\n" /* line 152 */
        "movl -0x6c(%ebp), %edi\n"
        "movw %di, (%ebx, %eax)\n"
        "movl s_vc_log, %eax\n" /* line 153 */
        "movl -0x70(%ebp), %edx\n"
        "movw %dx, 2(%ebx, %eax)\n"
        "movl s_vc_log, %eax\n" /* line 154 */
        "movl -0x74(%ebp), %ecx\n"
        "movw %cx, 4(%ebx, %eax)\n"
        "addl $1, 0xc96c84\n" /* line 155 */
        "jmp .Lfebdbc_000ec054\n"
        /* } scope */
        /* } scope */
        /* { scope 3: boxMins, boxMaxs */
        ".Lfebdbc_000ec2ae:\n"
        "leal 1(%edx), %edi\n" /* line 313 | bot */
        "cmpl %esi, %edi\n" /* line 298 | pos, bot */
        "jle .Lfebdbc_000ec0ab\n"
        /* } scope */
        /* } scope */
        "addl $1, -0x9c(%ebp)\n" /* line 458 | cornerIndex */
        "cmpl $8, -0x9c(%ebp)\n" /* cornerIndex */
        "jne .Lfebdbc_000ebf7a\n"
        "jmp .Lfebdbc_000ec105\n"
        ".Lfebdbc_000ec2d2:\n"
        "movl %edi, %eax\n" /* z */
        "jmp .Lfebdbc_000ec057\n"
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        /* { scope 3: boxMins, boxMaxs */
        ".Lfebdbc_000ec2d9:\n"
        "leal -1(%ecx), %ebx\n" /* line 185 | top */
        "cmpl %esi, %ebx\n" /* line 169 | top */
        "jl .Lfebdbc_000ec044\n"
        "movl -0x80(%ebp), %edi\n"
        "jmp .Lfebdbc_000ebffd\n"
        /* } scope */
        ".Lfebdbc_000ec2ec:\n"
        "shll $5, -0x6c(%ebp)\n" /* line 336 */
        "movl -0x6c(%ebp), %eax\n"
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "shll $5, -0x70(%ebp)\n" /* line 337 */
        "movl -0x70(%ebp), %eax\n"
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm3\n"
        "shll $6, -0x74(%ebp)\n" /* line 338 */
        "movl -0x74(%ebp), %eax\n"
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm4\n"
        "movl -0xc4(%ebp), %ebx\n" /* line 339 | top */
        /* { scope 3: boxMins, boxMaxs */
        "movl 8(%ebp), %edi\n" /* line 116 | lightGrid */
        "movl 4(%edi), %edi\n"
        "movl %edi, -0xd0(%ebp)\n"
        "movzbl 5(%edi, %ebx), %eax\n"
        "movzbl -0x9c(%ebp), %ecx\n" /* cornerIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lfebdbc_000ec65b\n"
        "movl 0x195f190, %eax\n" /* line 119 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfebdbc_000ec7f4\n"
        /* } scope */
        /* } scope */
        ".Lfebdbc_000ec355:\n"
        "movl 8(%ebp), %ecx\n" /* line 464 | lightGrid */
        "addl 4(%ecx), %ebx\n" /* top */
        "movl %ebx, -0xa0(%ebp)\n" /* top, gridPoint */
        "je .Lfebdbc_000ec0f1\n"
        "movl -0xac(%ebp), %edi\n" /* line 467 | z */
        "movss -0x60(%ebp, %edi, 4), %xmm2\n"
        "movl -0xa8(%ebp), %eax\n"
        "mulss -0x58(%ebp, %eax, 4), %xmm2\n"
        "movl -0xa4(%ebp), %edx\n"
        "mulss -0x50(%ebp, %edx, 4), %xmm2\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 468 | maxWeight */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n" /* maxWeight */
        "movzwl 6(%ebx), %eax\n" /* line 469 | top */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0xc(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %edi\n" /* z */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        /* { scope 3: boxMins, boxMaxs */
        "movaps %xmm2, %xmm1\n" /* line 351 */
        "mulss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %eax\n" /* colorForDir */
        "xorl %esi, %esi\n" /* channelIndex */
        ".Lfebdbc_000ec3bc:\n"
        "movl %eax, %edx\n"
        "leal (%edi, %esi, 8), %ecx\n" /* bot */
        "leal 0x20(%eax), %ebx\n" /* top */
        ".Lfebdbc_000ec3c4:\n"
        "movzbl (%ecx), %eax\n" /* line 355 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl %edx, %ebx\n" /* line 354 | top */
        "jne .Lfebdbc_000ec3c4\n"
        "addl $1, %esi\n" /* line 352 | channelIndex */
        "cmpl $3, %esi\n" /* channelIndex */
        "je .Lfebdbc_000ec3ed\n"
        "movl %ebx, %eax\n" /* top */
        "jmp .Lfebdbc_000ec3bc\n"
        /* } scope */
        /* } scope */
        ".Lfebdbc_000ec3ed:\n"
        "movl -0xa0(%ebp), %ecx\n" /* line 470 | gridPoint */
        "testb $1, 4(%ecx)\n"
        "je .Lfebdbc_000ec0f1\n"
        "addss -0x88(%ebp), %xmm2\n" /* line 471 | sunWeight */
        "movss %xmm2, -0x88(%ebp)\n" /* sunWeight */
        "addl $1, -0x9c(%ebp)\n" /* line 458 | cornerIndex */
        "cmpl $8, -0x9c(%ebp)\n" /* cornerIndex */
        "jne .Lfebdbc_000ebf7a\n"
        "jmp .Lfebdbc_000ec105\n"
        ".Lfebdbc_000ec426:\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 487 | 1.0f */
        "divss -0x8c(%ebp), %xmm1\n" /* maxWeight */
        "movss -0x88(%ebp), %xmm0\n" /* sunWeight */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x88(%ebp)\n" /* sunWeight */
        "movl 0x10(%ebp), %eax\n" /* colorForDir */
        "movl $6, %edx\n"
        ".Lfebdbc_000ec452:\n"
        "movaps %xmm1, %xmm0\n" /* line 519 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 520 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 521 */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 522 */
        "mulss 0xc(%eax), %xmm0\n"
        "movss %xmm0, 0xc(%eax)\n"
        "addl $0x10, %eax\n"
        "subl $1, %edx\n" /* line 364 */
        "jne .Lfebdbc_000ec452\n"
        /* } scope */
        "flds -0x88(%ebp)\n" /* line 495 | sunWeight */
        "addl $0x13c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: boxMins, boxMaxs */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        ".Lfebdbc_000ec49d:\n"
        "movl 8(%ebp), %eax\n" /* line 394 | lightGrid */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfebdbc_000ec1a5\n"
        /* { scope 3: boxMins, boxMaxs */
        "movl %edx, %ebx\n" /* line 270 | top */
        "andl $0xfffffffc, %ebx\n" /* top */
        "shll $0x13, %ebx\n" /* top */
        "movl %esi, %eax\n" /* line 271 | pos */
        "andl $0xfffffffc, %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %ebx\n" /* top */
        "movl %edi, %eax\n" /* line 272 */
        "sarl $2, %eax\n"
        "orl %eax, %ebx\n" /* top */
        "shlb $6, %dl\n" /* line 279 */
        "andl $3, %esi\n" /* pos */
        "shll $4, %esi\n" /* pos */
        "orl %esi, %edx\n" /* pos */
        "andl $3, %edi\n"
        "leal (, %edi, 4), %eax\n"
        "orb %al, %dl\n"
        "movl %ecx, %esi\n" /* line 298 | pos */
        "subl $1, %esi\n" /* pos */
        "js .Lfebdbc_000ec8fb\n"
        "movl 8(%ebp), %ecx\n" /* line 301 | lightGrid */
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0xd0(%ebp)\n"
        "movl $0, -0x7c(%ebp)\n" /* bot */
        "movzbl %dl, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "jmp .Lfebdbc_000ec515\n"
        ".Lfebdbc_000ec503:\n"
        "leal -1(%edx), %esi\n" /* line 315 | pos */
        ".Lfebdbc_000ec506:\n"
        "cmpl %esi, -0x7c(%ebp)\n" /* line 298 | pos, bot */
        "jg .Lfebdbc_000ec907\n"
        "movl -0xd0(%ebp), %ecx\n"
        ".Lfebdbc_000ec515:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 300 | bot */
        "addl %esi, %edx\n" /* pos */
        "sarl $1, %edx\n"
        "leal (, %edx, 8), %edi\n" /* line 301 | bot */
        "addl %edi, %ecx\n" /* bot */
        "movl (%ecx), %eax\n"
        "subl %ebx, %eax\n" /* line 302 | top */
        "jne .Lfebdbc_000ec53e\n"
        "movzbl 4(%ecx), %eax\n" /* line 304 */
        "subl -0xcc(%ebp), %eax\n"
        "andl $0xfffffffe, %eax\n" /* line 305 */
        "je .Lfebdbc_000ec90e\n"
        ".Lfebdbc_000ec53e:\n"
        "testl %eax, %eax\n" /* line 312 */
        "jns .Lfebdbc_000ec503\n"
        "addl $1, %edx\n" /* line 313 */
        "movl %edx, -0x7c(%ebp)\n" /* bot */
        "jmp .Lfebdbc_000ec506\n"
        /* } scope */
        /* } scope */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        ".Lfebdbc_000ec54a:\n"
        "movl -0x98(%ebp), %eax\n" /* line 90 | x0 */
        "shll $5, %eax\n"
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm3\n"
        "movl -0x94(%ebp), %eax\n" /* line 91 | y0 */
        "shll $5, %eax\n"
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "movl %edi, %eax\n" /* line 92 */
        "shll $6, %eax\n"
        "subl $0x20000, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm3, -0x3c(%ebp)\n" /* line 191 | boxMins */
        "movss %xmm2, -0x38(%ebp)\n" /* line 192 */
        "movss %xmm0, -0x34(%ebp)\n" /* line 193 */
        "movss 0x2ed830, %xmm1\n" /* line 191 | 32.0f */
        "addss %xmm1, %xmm3\n"
        "movss %xmm3, -0x24(%ebp)\n" /* traceDir */
        "addss %xmm1, %xmm2\n" /* line 192 */
        "movss %xmm2, -0x20(%ebp)\n"
        "addss 0x2ed78c, %xmm0\n" /* line 193 | 64.0f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0x195ed2c, %eax\n" /* line 95 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %ebx\n" /* traceDir */
        "movl %ebx, 8(%esp)\n"
        "leal -0x3c(%ebp), %esi\n" /* boxMins */
        "movl %esi, 4(%esp)\n"
        "movl 0x195f188, %edi\n"
        "movl (%edi), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugBox\n"
        /* } scope */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        "movl 0xc(%ebp), %eax\n" /* line 248 | samplePos */
        "movss (%eax), %xmm4\n"
        "movss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "movaps %xmm4, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* traceDir */
        "movss 4(%eax), %xmm2\n" /* line 249 */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 250 */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "addss %xmm3, %xmm4\n" /* line 240 */
        "movss %xmm4, -0x3c(%ebp)\n" /* boxMins */
        "addss %xmm3, %xmm2\n" /* line 241 */
        "movss %xmm2, -0x38(%ebp)\n"
        "addss %xmm3, %xmm1\n" /* line 242 */
        "movss %xmm1, -0x34(%ebp)\n"
        "movl 0x195ed78, %eax\n" /* line 80 */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl (%edi), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugBox\n"
        "jmp .Lfebdbc_000ebf41\n"
        /* } scope */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        /* { scope 3: boxMins, boxMaxs */
        ".Lfebdbc_000ec65b:\n"
        "movl 0xc(%ebp), %edi\n" /* line 248 | samplePos */
        "movss (%edi), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* traceDir */
        "movl -0xb4(%ebp), %eax\n" /* line 249 */
        "movss (%eax), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movl -0xb0(%ebp), %edx\n" /* line 250 */
        "movss (%edx), %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 126 | traceDir */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0xf8(%ebp)\n"
        "movss %xmm3, -0x108(%ebp)\n"
        "movss %xmm4, -0x118(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss 0x2ed738, %xmm1\n" /* line 288 | 0.009999999776482582f */
        "movss -0x24(%ebp), %xmm0\n" /* traceDir */
        "mulss %xmm1, %xmm0\n"
        "movss -0xf8(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* nudgedGridPos */
        "movss -0x20(%ebp), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "movss -0x108(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 290 */
        "movss -0x118(%ebp), %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movl $0x2001, 0x18(%esp)\n" /* line 128 */
        "movl $0, 0x14(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* nudgedGridPos */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CM_BoxSightTrace\n"
        "testl %eax, %eax\n"
        "movss -0xf8(%ebp), %xmm2\n"
        "movss -0x108(%ebp), %xmm3\n"
        "movss -0x118(%ebp), %xmm4\n"
        "je .Lfebdbc_000ec87b\n"
        "movl 0x195f190, %eax\n" /* line 138 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfebdbc_000ec0f1\n"
        /* { scope 4 */
        "movaps %xmm2, %xmm0\n" /* line 191 */
        "subss 0x2ed808, %xmm0\n" /* 1.100000023841858f */
        "movss %xmm0, -0x48(%ebp)\n" /* boxMins */
        "movaps %xmm3, %xmm0\n" /* line 192 */
        "subss 0x2ed808, %xmm0\n" /* 1.100000023841858f */
        "movss %xmm0, -0x44(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 193 */
        "subss 0x2ed808, %xmm0\n" /* 1.100000023841858f */
        "movss %xmm0, -0x40(%ebp)\n"
        "addss 0x2ed808, %xmm2\n" /* line 191 | 1.100000023841858f */
        "movss %xmm2, -0x3c(%ebp)\n" /* boxMins */
        "addss 0x2ed808, %xmm3\n" /* line 192 | 1.100000023841858f */
        "movss %xmm3, -0x38(%ebp)\n"
        "addss 0x2ed808, %xmm4\n" /* line 193 | 1.100000023841858f */
        "movss %xmm4, -0x34(%ebp)\n"
        "movl 0x195ed58, %eax\n" /* line 106 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* boxMins */
        "movl %eax, 8(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* boxMins */
        "movl %eax, 4(%esp)\n"
        "movl 0x195f188, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugBox\n"
        "jmp .Lfebdbc_000ec0f1\n"
        /* } scope */
        /* { scope 4 */
        ".Lfebdbc_000ec7f4:\n"
        "movaps %xmm2, %xmm0\n" /* line 191 */
        "subss 0x2ed7b8, %xmm0\n" /* 0.8999999761581421f */
        "movss %xmm0, -0x3c(%ebp)\n" /* boxMins */
        "movaps %xmm3, %xmm0\n" /* line 192 */
        "subss 0x2ed7b8, %xmm0\n" /* 0.8999999761581421f */
        "movss %xmm0, -0x38(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 193 */
        "subss 0x2ed7b8, %xmm0\n" /* 0.8999999761581421f */
        "movss %xmm0, -0x34(%ebp)\n"
        "addss 0x2ed7b8, %xmm2\n" /* line 191 | 0.8999999761581421f */
        "movss %xmm2, -0x48(%ebp)\n" /* boxMins */
        "addss 0x2ed7b8, %xmm3\n" /* line 192 | 0.8999999761581421f */
        "movss %xmm3, -0x44(%ebp)\n"
        "addss 0x2ed7b8, %xmm4\n" /* line 193 | 0.8999999761581421f */
        "movss %xmm4, -0x40(%ebp)\n"
        "movl 0x195ed60, %eax\n" /* line 106 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* boxMins */
        "movl %eax, 8(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* boxMins */
        /* } scope */
        /* { scope 4 */
        ".Lfebdbc_000ec85e:\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195f188, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddDebugBox\n"
        "jmp .Lfebdbc_000ec355\n"
        /* } scope */
        ".Lfebdbc_000ec87b:\n"
        "movl 0x195f190, %eax\n" /* line 131 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfebdbc_000ec355\n"
        /* { scope 4 */
        "movaps %xmm2, %xmm0\n" /* line 191 */
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x48(%ebp)\n" /* boxMins */
        "movaps %xmm3, %xmm0\n" /* line 192 */
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x44(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 193 */
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x40(%ebp)\n"
        "addss 0x2ed5d0, %xmm2\n" /* line 191 | 1.0f */
        "movss %xmm2, -0x3c(%ebp)\n" /* boxMins */
        "addss 0x2ed5d0, %xmm3\n" /* line 192 | 1.0f */
        "movss %xmm3, -0x38(%ebp)\n"
        "addss 0x2ed5d0, %xmm4\n" /* line 193 | 1.0f */
        "movss %xmm4, -0x34(%ebp)\n"
        "movl 0x195ed98, %eax\n" /* line 106 */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* boxMins */
        "movl %eax, 8(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* boxMins */
        "jmp .Lfebdbc_000ec85e\n"
        ".Lfebdbc_000ec8fb:\n"
        "movl 8(%ebp), %edi\n" /* lightGrid */
        "movl 4(%edi), %edi\n"
        "movl %edi, -0xd0(%ebp)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: traceDir, nudgedGridPos, bot, gridColors */
        /* { scope 3: boxMins, boxMaxs */
        ".Lfebdbc_000ec907:\n"
        "leal (, %esi, 8), %edi\n" /* line 298 | bot */
        /* } scope */
        ".Lfebdbc_000ec90e:\n"
        "movl -0xd0(%ebp), %edx\n" /* line 399 */
        "movzwl 6(%edx, %edi), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 8(%ebp), %ecx\n" /* lightGrid */
        "movl 0xc(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, -0x78(%ebp)\n" /* gridColors */
        "movl 0x10(%ebp), %eax\n" /* colorForDir */
        "xorl %esi, %esi\n" /* sampleIndex */
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        ".Lfebdbc_000ec935:\n"
        "movl %eax, %edx\n"
        "movl -0x78(%ebp), %eax\n" /* gridColors */
        "leal (%eax, %esi, 8), %ecx\n"
        "leal 0x20(%edx), %ebx\n" /* top */
        /* { scope 3: boxMins, boxMaxs */
        /* { scope 4 */
        ".Lfebdbc_000ec940:\n"
        "movzbl (%ecx), %eax\n" /* line 355 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl %ebx, %edx\n" /* line 354 | top */
        "jne .Lfebdbc_000ec940\n"
        "addl $1, %esi\n" /* line 352 | channelIndex */
        "cmpl $3, %esi\n" /* channelIndex */
        "je .Lfebdbc_000ec969\n"
        "movl %edx, %eax\n"
        "jmp .Lfebdbc_000ec935\n"
        /* } scope */
        /* } scope */
        ".Lfebdbc_000ec969:\n"
        "movl 8(%ebp), %edx\n" /* line 403 | lightGrid */
        "movl 4(%edx), %eax\n"
        "testb $1, 4(%eax, %edi)\n"
        "je .Lfebdbc_000ec98b\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x88(%ebp)\n" /* sunWeight */
        "jmp .Lfebdbc_000ec23b\n"
        ".Lfebdbc_000ec98b:\n"
        "movss %xmm2, -0x88(%ebp)\n" /* sunWeight */
        "jmp .Lfebdbc_000ec23b\n"
    );
}

/* line 499 */
__attribute__((naked))
void RB_SetupEntityLighting(const GfxEntity *ent, GfxEntityLighting *lighting)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 499 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl 0xc(%ebp), %ebx\n" /* lighting */
        /* { scope 1 */
        "movl 0x195f0c8, %eax\n" /* line 506 */
        "movl 0x3b4(%eax), %eax\n"
        "movl %eax, (%ebx)\n" /* lighting */
        "cmpb $0, 4(%ecx)\n" /* line 508 */
        "jns .Lfec998_000ec9fc\n"
        "leal 8(%ecx), %edx\n" /* line 510 | from */
        /* { scope 2 */
        "movl 8(%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n" /* lightOrigin */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        /* } scope */
        ".Lfec998_000ec9cd:\n"
        "leal 8(%ebx), %eax\n" /* line 518 | lighting */
        "movl %eax, 8(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* lightOrigin */
        "movl %eax, 4(%esp)\n"
        "movl 0x195eebc, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "addl $0x11c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_GetLightingAtPoint\n"
        "fstps 4(%ebx)\n" /* lighting */
        /* } scope */
        "addl $0x24, %esp\n" /* line 519 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfec998_000ec9fc:\n"
        "leal 0x3c(%ecx), %edx\n" /* line 514 | from */
        /* { scope 2 */
        "movl 0x3c(%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n" /* lightOrigin */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        /* } scope */
        "movss 0x2ed608, %xmm0\n" /* line 515 | 4.0f */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "jmp .Lfec998_000ec9cd\n"
    );
}

/* line 779 */
__attribute__((naked))
void RB_InitLightVisHistory(const char *bspName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 779 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl $0, s_vc_log\n" /* line 785 */
        "movl $0, 0xc96c84\n" /* line 786 */
        "movl 0x195f18c, %edi\n" /* line 788 */
        "movl (%edi), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfeca20_000eca54\n"
        /* } scope */
        ".Lfeca20_000eca4c:\n"
        "addl $0x6c, %esp\n" /* line 814 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfeca20_000eca54:\n"
        "movl $0x1800000, (%esp)\n" /* line 791 */
        "calll Z_MallocInternal\n"
        "movl %eax, s_vc_log\n"
        "movl (%edi), %eax\n" /* line 792 */
        "cmpl $2, 8(%eax)\n"
        "jne .Lfeca20_000eca4c\n"
        "leal -0x5c(%ebp), %ebx\n" /* line 759 | filename */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* bspName */
        "movl %eax, (%esp)\n"
        "calll Com_StripExtension\n"
        "xorl %esi, %esi\n" /* line 760 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "movl %esi, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl $4, %ecx\n"
        "cmpl $0x3f, %ecx\n"
        "ja .Lfeca20_000ecb2b\n"
        ".Lfeca20_000eca9b:\n"
        "cld\n" /* line 762 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "movl %esi, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl $0x6972672e, (%ecx)\n"
        "movw $0x64, 4(%ecx)\n"
        "leal -0x1c(%ebp), %eax\n" /* line 796 | buffer */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_ReadFile\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 797 */
        "js .Lfeca20_000eca4c\n"
        "movl $0xaaaaaaab, %esi\n" /* line 800 */
        "mull %esi\n"
        "shrl $2, %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lfeca20_000ecb18\n"
        "movl $0x1800000, %ebx\n" /* line 802 */
        "cmpl $0x1800001, %ecx\n"
        "cmovbl %ecx, %ebx\n"
        "movl %ebx, 8(%esp)\n" /* line 806 */
        "movl -0x1c(%ebp), %eax\n" /* buffer */
        "movl %eax, 4(%esp)\n"
        "movl s_vc_log, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl %ebx, %eax\n" /* line 809 */
        "mull %esi\n"
        "shrl $2, %edx\n"
        "movl %edx, 0xc96c84\n"
        ".Lfeca20_000ecb18:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 813 | buffer */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 814 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfeca20_000ecb2b:\n"
        "movl %ebx, 8(%esp)\n" /* line 761 */
        "movl $0x225854, 4(%esp)\n" /* "light grid log filename '%s.grid' is too long
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfeca20_000eca9b\n"
    );
}

