/* ASM dump from: D3DXTex.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/D3DXTex.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 */

extern int g_NumShadowCookies; /* 0x0 */
typedef int vector_UINT32_std; /* C++ template placeholder */
extern vector_UINT32_std g_ShadowCookieMemory; /* 0x0 */

void ViewSingleTexture(GLuint TextureID, IDirect3DDevice9 *pDevice, LPCVOID pSrcData, UINT SrcDataSize, IDirect3DCubeTexture9 * *ppCubeTexture, IDirect3DDevice9 *pDevice_5, LPCVOID pSrcData_6, UINT SrcDataSize_7, IDirect3DTexture9 * *ppTexture);
void ShowShadowCookies(void);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__D_g_NumShadowCookies(void); /* global destructors keyed to g_NumShadowCookies */
static void GLOBAL__I_g_NumShadowCookies(void); /* global constructors keyed to g_NumShadowCookies */

/* line 457 */
__attribute__((naked))
void ViewSingleTexture(GLuint TextureID, IDirect3DDevice9 *pDevice, LPCVOID pSrcData, UINT SrcDataSize, IDirect3DCubeTexture9 * *ppCubeTexture, IDirect3DDevice9 *pDevice_5, LPCVOID pSrcData_6, UINT SrcDataSize_7, IDirect3DTexture9 * *ppTexture)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 457 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x23c, %esp\n"
        /* { scope 1 */
        "movl $0xfffff, (%esp)\n" /* line 462 */
        "calll glPushAttrib\n"
        "movl $0xffffffff, (%esp)\n" /* line 463 */
        "calll glPushClientAttrib\n"
        "movl $0x8620, (%esp)\n" /* line 465 */
        "calll glDisable\n"
        "calll MacDisplay_GetCardType\n" /* line 179 */
        "cmpl $2, %eax\n" /* line 466 */
        "je .Lf247ea_00024c8c\n"
        "calll MacDisplay_GetCardType\n" /* line 178 */
        "subl $1, %eax\n" /* line 471 */
        "je .Lf247ea_00024ca9\n"
        ".Lf247ea_00024836:\n"
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n" /* line 475 */
        "cmpl $0xffff01ff, %eax\n"
        "ja .Lf247ea_00024a8c\n"
        ".Lf247ea_00024846:\n"
        "movl $0x1700, (%esp)\n" /* line 480 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 481 */
        "calll glLoadIdentity\n" /* line 482 */
        "movl $0x1701, (%esp)\n" /* line 483 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 484 */
        "calll glLoadIdentity\n" /* line 485 */
        "movsd 0x307c20, %xmm0\n" /* line 486 | 1.5 */
        "movsd %xmm0, 0x18(%esp)\n"
        "pxor %xmm1, %xmm1\n"
        "movsd %xmm1, 0x10(%esp)\n"
        "movsd %xmm0, 8(%esp)\n"
        "movsd %xmm1, (%esp)\n"
        "calll gluOrtho2D\n"
        "movl $0xb50, (%esp)\n" /* line 488 */
        "calll glDisable\n"
        "movl $0xbe2, (%esp)\n" /* line 489 */
        "calll glDisable\n"
        "movl $0xbc0, (%esp)\n" /* line 490 */
        "calll glDisable\n"
        "movl $0xb71, (%esp)\n" /* line 491 */
        "calll glDisable\n"
        "movl $0xbd0, (%esp)\n" /* line 492 */
        "calll glDisable\n"
        "movl $1, 0xc(%esp)\n" /* line 493 */
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glColorMask\n"
        "movl $0x405, (%esp)\n" /* line 494 */
        "calll glDrawBuffer\n"
        "movl $1, (%esp)\n" /* line 495 */
        "calll glDepthMask\n"
        "movl $0xb44, (%esp)\n" /* line 496 */
        "calll glDisable\n"
        "movl $0xb60, (%esp)\n" /* line 497 */
        "calll glDisable\n"
        "leal -0x1c(%ebp), %eax\n" /* line 502 | NumTexUnits */
        "movl %eax, 4(%esp)\n"
        "movl $0x84e2, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl $0x1702, (%esp)\n" /* line 504 */
        "calll glMatrixMode\n"
        /* { scope 2 */
        "movl -0x1c(%ebp), %eax\n" /* line 505 | NumTexUnits */
        "subl $1, %eax\n"
        "js .Lf247ea_0002498f\n"
        "movl %eax, %ebx\n" /* i */
        "movl $0xffffffff, %edi\n"
        "shll $6, %eax\n"
        "leal -0x21c(%ebp, %eax), %esi\n"
        ".Lf247ea_00024962:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 507 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl %esi, 4(%esp)\n" /* line 508 */
        "movl $0xba8, (%esp)\n"
        "calll glGetFloatv\n"
        "calll glLoadIdentity\n" /* line 509 */
        "subl $1, %ebx\n" /* line 505 | i */
        "subl $0x40, %esi\n"
        "cmpl %edi, %ebx\n" /* i */
        "jne .Lf247ea_00024962\n"
        /* } scope */
        ".Lf247ea_0002498f:\n"
        "movl $0xb90, (%esp)\n" /* line 511 */
        "calll glDisable\n"
        /* { scope 2 */
        "movl -0x1c(%ebp), %edx\n" /* line 515 | NumTexUnits */
        "testl %edx, %edx\n"
        "jg .Lf247ea_00024ac8\n"
        /* } scope */
        ".Lf247ea_000249a6:\n"
        "movl $7, (%esp)\n" /* line 569 */
        "calll glBegin\n"
        "movl $0x3f800000, %esi\n" /* line 570 */
        "movl %esi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll glColor4f\n"
        "xorl %ebx, %ebx\n" /* line 585 | i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %ebx, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movl %ebx, 8(%esp)\n" /* line 586 | i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %ebx, (%esp)\n" /* i */
        "calll glVertex3f\n"
        "movl %ebx, 4(%esp)\n" /* line 588 | i */
        "movl %esi, (%esp)\n"
        "calll glTexCoord2f\n"
        "movl %ebx, 8(%esp)\n" /* line 589 | i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %esi, (%esp)\n"
        "calll glVertex3f\n"
        "movl %esi, 4(%esp)\n" /* line 591 */
        "movl %esi, (%esp)\n"
        "calll glTexCoord2f\n"
        "movl %ebx, 8(%esp)\n" /* line 592 | i */
        "movl %esi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll glVertex3f\n"
        "movl %esi, 4(%esp)\n" /* line 594 */
        "movl %ebx, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movl %ebx, 8(%esp)\n" /* line 595 | i */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll glVertex3f\n"
        "calll glEnd\n" /* line 597 */
        "movl $0x1702, (%esp)\n" /* line 600 */
        "calll glMatrixMode\n"
        /* { scope 2 */
        "movl -0x1c(%ebp), %eax\n" /* line 601 | NumTexUnits */
        "testl %eax, %eax\n"
        "jg .Lf247ea_00024a9d\n"
        /* } scope */
        ".Lf247ea_00024a55:\n"
        "movl $0x1701, (%esp)\n" /* line 607 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 608 */
        "movl $0x1700, (%esp)\n" /* line 609 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 610 */
        "calll glPopClientAttrib\n" /* line 612 */
        "calll glPopAttrib\n" /* line 613 */
        /* } scope */
        "addl $0x23c, %esp\n" /* line 614 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf247ea_00024a8c:\n"
        "movl $0x8804, (%esp)\n" /* line 477 */
        "calll glDisable\n"
        "jmp .Lf247ea_00024846\n"
        /* { scope 2 */
        ".Lf247ea_00024a9d:\n"
        "xorl %ebx, %ebx\n" /* line 601 | i */
        "leal -0x21c(%ebp), %esi\n" /* Matrices */
        ".Lf247ea_00024aa5:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 603 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl %esi, (%esp)\n" /* line 604 */
        "calll glLoadMatrixf\n"
        "addl $1, %ebx\n" /* line 601 | i */
        "addl $0x40, %esi\n"
        "cmpl -0x1c(%ebp), %ebx\n" /* NumTexUnits, i */
        "jl .Lf247ea_00024aa5\n"
        "jmp .Lf247ea_00024a55\n"
        /* } scope */
        /* { scope 2 */
        ".Lf247ea_00024ac8:\n"
        "xorl %ebx, %ebx\n" /* line 515 | i */
        "jmp .Lf247ea_00024bfe\n"
        ".Lf247ea_00024acf:\n"
        "movl 8(%ebp), %eax\n" /* line 531 | TextureID */
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl $0xde1, (%esp)\n" /* line 532 */
        "calll glEnable\n"
        "movl $0x84f5, (%esp)\n" /* line 533 */
        "calll glDisable\n"
        "movl $0x806f, (%esp)\n" /* line 535 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 536 */
        "calll glDisable\n"
        "movl $0x1e01, 8(%esp)\n" /* line 537 */
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1e01, 8(%esp)\n" /* line 538 */
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 539 */
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x300, 8(%esp)\n" /* line 540 */
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 541 */
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x302, 8(%esp)\n" /* line 542 */
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 543 */
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 544 */
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        ".Lf247ea_00024bf2:\n"
        "addl $1, %ebx\n" /* line 515 | i */
        "cmpl -0x1c(%ebp), %ebx\n" /* NumTexUnits, i */
        "jge .Lf247ea_000249a6\n"
        ".Lf247ea_00024bfe:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 517 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl $0xc60, (%esp)\n" /* line 519 */
        "calll glDisable\n"
        "movl $0xc61, (%esp)\n" /* line 520 */
        "calll glDisable\n"
        "movl $0xc62, (%esp)\n" /* line 521 */
        "calll glDisable\n"
        "movl $0xc63, (%esp)\n" /* line 522 */
        "calll glDisable\n"
        "testl %ebx, %ebx\n" /* line 524 | i */
        "je .Lf247ea_00024acf\n"
        "movl 8(%ebp), %eax\n" /* line 555 | TextureID */
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl $0xde1, (%esp)\n" /* line 556 */
        "calll glDisable\n"
        "movl $0x84f5, (%esp)\n" /* line 557 */
        "calll glDisable\n"
        "movl $0x806f, (%esp)\n" /* line 558 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 559 */
        "calll glDisable\n"
        "jmp .Lf247ea_00024bf2\n"
        /* } scope */
        ".Lf247ea_00024c8c:\n"
        "movl $0x86de, (%esp)\n" /* line 468 */
        "calll glDisable\n"
        "movl $0x8522, (%esp)\n" /* line 469 */
        "calll glDisable\n"
        "jmp .Lf247ea_00024836\n"
        ".Lf247ea_00024ca9:\n"
        "movl $0x8200, (%esp)\n" /* line 473 */
        "calll glDisable\n"
        "jmp .Lf247ea_00024836\n"
        /* } scope */
        /* } scope */
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x26c, %esp\n"
        "movl $0xfffff, (%esp)\n"
        "calll glPushAttrib\n"
        "movl $0x8620, (%esp)\n"
        "calll glDisable\n"
        "calll MacDisplay_GetCardType\n"
        "cmpl $2, %eax\n"
        "je 0x252e1\n"
        "calll MacDisplay_GetCardType\n"
        "subl $1, %eax\n"
        "je 0x252fe\n"
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n"
        "cmpl $0xffff01ff, %eax\n"
        "ja 0x252d0\n"
        "movl $0x1700, (%esp)\n"
        "calll glMatrixMode\n"
        "calll glPushMatrix\n"
        "calll glLoadIdentity\n"
        "movl $0x1701, (%esp)\n"
        "calll glMatrixMode\n"
        "calll glPushMatrix\n"
        "calll glLoadIdentity\n"
        "pxor %xmm0, %xmm0\n"
        "movsd %xmm0, 0x18(%esp)\n"
        "movsd 0x307c10, %xmm1\n" /* 1.0 */
        "movsd %xmm1, 0x10(%esp)\n"
        "movsd %xmm1, 8(%esp)\n"
        "movsd %xmm0, (%esp)\n"
        "calll gluOrtho2D\n"
        "movl $0xb50, (%esp)\n"
        "calll glDisable\n"
        "movl $0xbe2, (%esp)\n"
        "calll glDisable\n"
        "movl $0xbc0, (%esp)\n"
        "calll glDisable\n"
        "movl $0xb71, (%esp)\n"
        "calll glDisable\n"
        "movl $0xbd0, (%esp)\n"
        "calll glDisable\n"
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glColorMask\n"
        "movl $0x405, (%esp)\n"
        "calll glDrawBuffer\n"
        "movl $1, (%esp)\n"
        "calll glDepthMask\n"
        "movl $0xb44, (%esp)\n"
        "calll glDisable\n"
        "movl $0xb60, (%esp)\n"
        "calll glDisable\n"
        "leal -0x1c(%ebp), %eax\n" /* NumTexUnits */
        "movl %eax, 4(%esp)\n"
        "movl $0x84e2, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl $0x1702, (%esp)\n"
        "calll glMatrixMode\n"
        "movl -0x1c(%ebp), %eax\n" /* NumTexUnits */
    );
}

/* line 238 */
__attribute__((naked))
void ShowShadowCookies(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 238 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x26c, %esp\n"
        /* { scope 1 */
        "movl $0xfffff, (%esp)\n" /* line 243 */
        "calll glPushAttrib\n"
        "movl $0x8620, (%esp)\n" /* line 245 */
        "calll glDisable\n"
        "calll MacDisplay_GetCardType\n" /* line 179 */
        "cmpl $2, %eax\n" /* line 246 */
        "je .Lf24cba_000252e1\n"
        "calll MacDisplay_GetCardType\n" /* line 178 */
        "subl $1, %eax\n" /* line 251 */
        "je .Lf24cba_000252fe\n"
        ".Lf24cba_00024cfa:\n"
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n" /* line 255 */
        "cmpl $0xffff01ff, %eax\n"
        "ja .Lf24cba_000252d0\n"
        ".Lf24cba_00024d0a:\n"
        "movl $0x1700, (%esp)\n" /* line 260 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 261 */
        "calll glLoadIdentity\n" /* line 262 */
        "movl $0x1701, (%esp)\n" /* line 263 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 264 */
        "calll glLoadIdentity\n" /* line 265 */
        "pxor %xmm0, %xmm0\n" /* line 266 */
        "movsd %xmm0, 0x18(%esp)\n"
        "movsd 0x307c10, %xmm1\n" /* 1.0 */
        "movsd %xmm1, 0x10(%esp)\n"
        "movsd %xmm1, 8(%esp)\n"
        "movsd %xmm0, (%esp)\n"
        "calll gluOrtho2D\n"
        "movl $0xb50, (%esp)\n" /* line 268 */
        "calll glDisable\n"
        "movl $0xbe2, (%esp)\n" /* line 269 */
        "calll glDisable\n"
        "movl $0xbc0, (%esp)\n" /* line 270 */
        "calll glDisable\n"
        "movl $0xb71, (%esp)\n" /* line 271 */
        "calll glDisable\n"
        "movl $0xbd0, (%esp)\n" /* line 272 */
        "calll glDisable\n"
        "movl $1, 0xc(%esp)\n" /* line 273 */
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glColorMask\n"
        "movl $0x405, (%esp)\n" /* line 274 */
        "calll glDrawBuffer\n"
        "movl $1, (%esp)\n" /* line 275 */
        "calll glDepthMask\n"
        "movl $0xb44, (%esp)\n" /* line 276 */
        "calll glDisable\n"
        "movl $0xb60, (%esp)\n" /* line 277 */
        "calll glDisable\n"
        "leal -0x1c(%ebp), %eax\n" /* line 282 | NumTexUnits */
        "movl %eax, 4(%esp)\n"
        "movl $0x84e2, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl $0x1702, (%esp)\n" /* line 284 */
        "calll glMatrixMode\n"
        /* { scope 2: XOffset, YOffset */
        "movl -0x1c(%ebp), %eax\n" /* line 285 | NumTexUnits */
        "subl $1, %eax\n"
        "js .Lf24cba_00024e53\n"
        "movl %eax, %ebx\n" /* i */
        "movl $0xffffffff, %edi\n"
        "shll $6, %eax\n"
        "leal -0x21c(%ebp, %eax), %esi\n"
        ".Lf24cba_00024e26:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 287 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl %esi, 4(%esp)\n" /* line 288 */
        "movl $0xba8, (%esp)\n"
        "calll glGetFloatv\n"
        "calll glLoadIdentity\n" /* line 289 */
        "subl $1, %ebx\n" /* line 285 | i */
        "subl $0x40, %esi\n"
        "cmpl %edi, %ebx\n" /* i */
        "jne .Lf24cba_00024e26\n"
        /* } scope */
        ".Lf24cba_00024e53:\n"
        "movl $0xb90, (%esp)\n" /* line 291 */
        "calll glDisable\n"
        /* { scope 2: XOffset, YOffset */
        "movl g_NumShadowCookies, %eax\n" /* line 293 */
        "testl %eax, %eax\n"
        "je .Lf24cba_00025226\n"
        "xorl %edi, %edi\n" /* Display */
        "movl $0, -0x22c(%ebp)\n"
        "jmp .Lf24cba_0002502c\n"
        /* { scope 3 */
        ".Lf24cba_00024e7d:\n"
        "movl %edi, %eax\n" /* line 365 | Display */
        "andl $7, %eax\n"
        "js .Lf24cba_0002528c\n"
        "cvtsi2ssl %eax, %xmm0\n"
        ".Lf24cba_00024e8c:\n"
        "movss 0x2ed610, %xmm1\n" /* 0.125f */
        "mulss %xmm1, %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x234(%ebp)\n" /* XOffset */
        "movl %edi, %edx\n" /* line 366 | Display */
        "shrl $3, %edx\n"
        "js .Lf24cba_00025275\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf24cba_00024eb7:\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x230(%ebp)\n" /* YOffset */
        "movl $7, (%esp)\n" /* line 372 */
        "calll glBegin\n"
        "movl $0x3f800000, %eax\n" /* line 373 */
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glColor4f\n"
        "movl $0, 4(%esp)\n" /* line 375 */
        "movl $0, (%esp)\n"
        "calll glTexCoord2f\n"
        "movl $0, 8(%esp)\n" /* line 376 */
        "movss -0x230(%ebp), %xmm0\n" /* YOffset */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x234(%ebp), %xmm0\n" /* XOffset */
        "movss %xmm0, (%esp)\n"
        "calll glVertex3f\n"
        "movl $0, 4(%esp)\n" /* line 378 */
        "movl $0x44800000, %esi\n" /* i */
        "movl %esi, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movss 0x2ed614, %xmm0\n" /* line 379 | 0.09375f */
        "addss -0x234(%ebp), %xmm0\n" /* XOffset */
        "movss %xmm0, -0x23c(%ebp)\n"
        "movl $0, 8(%esp)\n"
        "movss -0x230(%ebp), %xmm0\n" /* YOffset */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x23c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll glVertex3f\n"
        "movl $0x44400000, %ebx\n" /* line 381 | i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %esi, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movss -0x230(%ebp), %xmm0\n" /* line 382 | YOffset */
        "movss %xmm0, -0x238(%ebp)\n"
        "movss 0x2ed614, %xmm0\n" /* 0.09375f */
        "addss -0x238(%ebp), %xmm0\n"
        "movss %xmm0, -0x238(%ebp)\n"
        "movl $0, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x23c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll glVertex3f\n"
        "movl %ebx, 4(%esp)\n" /* line 384 | i */
        "movl $0, (%esp)\n"
        "calll glTexCoord2f\n"
        "movl $0, 8(%esp)\n" /* line 385 */
        "movss -0x238(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x234(%ebp), %xmm0\n" /* XOffset */
        "movss %xmm0, (%esp)\n"
        "calll glVertex3f\n"
        "calll glEnd\n" /* line 386 */
        /* } scope */
        "addl $1, %edi\n" /* line 293 | Display */
        "addl $0xc00000, -0x22c(%ebp)\n"
        "cmpl g_NumShadowCookies, %edi\n" /* Display */
        "jae .Lf24cba_00025226\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf24cba_0002502c:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 295 | NumTexUnits */
        "testl %eax, %eax\n"
        "jle .Lf24cba_00024e7d\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf24cba_00025157\n"
        ".Lf24cba_0002503e:\n"
        "movl $0xde1, (%esp)\n" /* line 333 */
        "calll glEnable\n"
        "movl $0x84f5, (%esp)\n" /* line 334 */
        "calll glEnable\n"
        "movl $0x806f, (%esp)\n" /* line 335 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 336 */
        "calll glDisable\n"
        "movl $0x1e01, 8(%esp)\n" /* line 337 */
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1e01, 8(%esp)\n" /* line 338 */
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 339 */
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x300, 8(%esp)\n" /* line 340 */
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 341 */
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x302, 8(%esp)\n" /* line 342 */
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x3f800000, %ebx\n" /* line 343 | i */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movl %ebx, 8(%esp)\n" /* line 344 | i */
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        ".Lf24cba_0002514b:\n"
        "addl $1, %esi\n" /* line 295 | i */
        "cmpl -0x1c(%ebp), %esi\n" /* NumTexUnits, i */
        "jge .Lf24cba_00024e7d\n"
        ".Lf24cba_00025157:\n"
        "leal 0x84c0(%esi), %eax\n" /* line 297 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl $0xc60, (%esp)\n" /* line 299 */
        "calll glDisable\n"
        "movl $0xc61, (%esp)\n" /* line 300 */
        "calll glDisable\n"
        "movl $0xc62, (%esp)\n" /* line 301 */
        "calll glDisable\n"
        "movl $0xc63, (%esp)\n" /* line 302 */
        "calll glDisable\n"
        "movl -0x22c(%ebp), %eax\n" /* line 654 */
        "addl g_ShadowCookieMemory, %eax\n"
        "movl %eax, 0x20(%esp)\n" /* line 316 */
        "movl $0x1401, 0x1c(%esp)\n"
        "movl $0x1908, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x300, 0x10(%esp)\n"
        "movl $0x400, 0xc(%esp)\n"
        "movl $0x1908, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x84f5, (%esp)\n"
        "calll glTexImage2D\n"
        "testl %esi, %esi\n" /* line 331 | i */
        "je .Lf24cba_0002503e\n"
        "movl $0xde1, (%esp)\n" /* line 355 */
        "calll glDisable\n"
        "movl $0x84f5, (%esp)\n" /* line 356 */
        "calll glDisable\n"
        "movl $0x806f, (%esp)\n" /* line 357 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 358 */
        "calll glDisable\n"
        "jmp .Lf24cba_0002514b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf24cba_00025226:\n"
        "movl $0x1702, (%esp)\n" /* line 389 */
        "calll glMatrixMode\n"
        /* { scope 2: XOffset, YOffset */
        "movl -0x1c(%ebp), %eax\n" /* line 390 | NumTexUnits */
        "testl %eax, %eax\n"
        "jg .Lf24cba_000252a2\n"
        /* } scope */
        ".Lf24cba_00025239:\n"
        "movl $0x1701, (%esp)\n" /* line 396 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 397 */
        "movl $0x1700, (%esp)\n" /* line 398 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 399 */
        "calll glPopAttrib\n" /* line 401 */
        "movl $0, g_NumShadowCookies\n" /* line 403 */
        /* } scope */
        "addl $0x26c, %esp\n" /* line 404 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: XOffset, YOffset */
        /* { scope 3 */
        ".Lf24cba_00025275:\n"
        "movl %edi, %eax\n" /* line 366 | Display */
        "shrl $4, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf24cba_00024eb7\n"
        ".Lf24cba_0002528c:\n"
        "shrl $1, %eax\n" /* line 365 */
        "movl %edi, %edx\n" /* Display */
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf24cba_00024e8c\n"
        /* } scope */
        /* } scope */
        /* { scope 2: XOffset, YOffset */
        ".Lf24cba_000252a2:\n"
        "xorl %ebx, %ebx\n" /* line 390 | i */
        "leal -0x21c(%ebp), %esi\n" /* Matrices, i */
        ".Lf24cba_000252aa:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 392 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl %esi, (%esp)\n" /* line 393 | i */
        "calll glLoadMatrixf\n"
        "addl $1, %ebx\n" /* line 390 | i */
        "addl $0x40, %esi\n" /* i */
        "cmpl -0x1c(%ebp), %ebx\n" /* NumTexUnits, i */
        "jl .Lf24cba_000252aa\n"
        "jmp .Lf24cba_00025239\n"
        /* } scope */
        ".Lf24cba_000252d0:\n"
        "movl $0x8804, (%esp)\n" /* line 257 */
        "calll glDisable\n"
        "jmp .Lf24cba_00024d0a\n"
        ".Lf24cba_000252e1:\n"
        "movl $0x86de, (%esp)\n" /* line 248 */
        "calll glDisable\n"
        "movl $0x8522, (%esp)\n" /* line 249 */
        "calll glDisable\n"
        "jmp .Lf24cba_00024cfa\n"
        ".Lf24cba_000252fe:\n"
        "movl $0x8200, (%esp)\n" /* line 253 */
        "calll glDisable\n"
        "jmp .Lf24cba_00024cfa\n"
    );
}

/* line 2507 */
static __attribute__((naked))
void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2507 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpl $0xffff, %edx\n" /* line 235 */
        "je .Lf25310_00025320\n"
        ".Lf25310_0002531e:\n"
        "leave\n" /* line 2507 */
        "retl\n"
        ".Lf25310_00025320:\n"
        "cmpl $1, %eax\n" /* line 235 */
        "je .Lf25310_00025350\n"
        "testl %eax, %eax\n"
        "jne .Lf25310_0002531e\n"
        "movl 0xff3e04, %edx\n" /* line 273 */
        "movl g_ShadowCookieMemory, %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf25310_00025342\n"
        ".Lf25310_0002533b:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf25310_0002533b\n"
        ".Lf25310_00025342:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf25310_0002531e\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "leave\n" /* line 2507 */
        "retl\n"
        ".Lf25310_00025350:\n"
        "movl $0, g_ShadowCookieMemory\n" /* line 85 */
        "movl $0, 0xff3e04\n"
        "movl $0, 0xff3e08\n"
        "leave\n" /* line 2507 */
        "retl\n"
    );
}

/* line 2509 */
static __attribute__((naked))
void GLOBAL__D_g_NumShadowCookies(void) /* global destructors keyed to g_NumShadowCookies */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2509 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 2508 */
static __attribute__((naked))
void GLOBAL__I_g_NumShadowCookies(void) /* global constructors keyed to g_NumShadowCookies */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2508 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

