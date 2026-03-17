/* ASM dump from: MacMSS_Sample2.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacMSS_Sample2.cp */

#include "common_types.h"
#include "imports.h"

void CSampleSound_Calculate3DAttributes(const CSampleSound * _this, Float32 *outAzimuth, Float32 *outElevation, Float32 *outDistance);

/* line 41 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void CSampleSound_Calculate3DAttributes(const CSampleSound * _this, Float32 *outAzimuth, Float32 *outElevation, Float32 *outDistance)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 41 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0xf4, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movss 0xbc(%ebx), %xmm0\n" /* line 70 | this */
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss 0xb8(%ebx), %xmm1\n" /* this */
        "movss %xmm1, -0x48(%ebp)\n"
        "movss 0xb4(%ebx), %xmm0\n" /* this */
        "movss %xmm0, -0x44(%ebp)\n"
        "leal -0x14(%ebp), %eax\n" /* line 76 | listenerFace */
        "movl %eax, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetListenerFaceVector\n"
        "leal -0x20(%ebp), %eax\n" /* line 79 | listenerUp */
        "movl %eax, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CSoundEngine_GetListenerUpVector\n"
        "movss -0x10(%ebp), %xmm2\n" /* line 1748 */
        "movss -0x18(%ebp), %xmm1\n"
        "movss -0xc(%ebp), %xmm4\n"
        "movss -0x1c(%ebp), %xmm5\n"
        "movaps %xmm2, %xmm6\n"
        "mulss %xmm1, %xmm6\n"
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "subss %xmm0, %xmm6\n"
        "movss -0x20(%ebp), %xmm3\n" /* line 1749 | listenerUp */
        "movss -0x14(%ebp), %xmm0\n" /* listenerFace */
        "mulss %xmm3, %xmm4\n"
        "mulss %xmm0, %xmm1\n"
        "subss %xmm1, %xmm4\n"
        "mulss %xmm0, %xmm5\n" /* line 1750 */
        "mulss %xmm3, %xmm2\n"
        "subss %xmm2, %xmm5\n"
        /* { scope 2 */
        "movaps %xmm6, %xmm0\n" /* line 26 | InvLengthSquared */
        "mulss %xmm6, %xmm0\n" /* InvLengthSquared */
        "movaps %xmm4, %xmm1\n" /* InvLengthSquared */
        "mulss %xmm4, %xmm1\n" /* InvLengthSquared */
        "addss %xmm1, %xmm0\n" /* InvLengthSquared */
        "movaps %xmm5, %xmm1\n" /* InvLengthSquared */
        "mulss %xmm5, %xmm1\n" /* InvLengthSquared */
        "addss %xmm1, %xmm0\n" /* InvLengthSquared */
        "sqrtss %xmm0, %xmm0\n" /* InvLengthSquared */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f, InvLengthSquared */
        "divss %xmm0, %xmm1\n" /* InvLengthSquared */
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 27 | 0.0f */
        "jne .Lf1e6f90_001e7459\n"
        "jp .Lf1e6f90_001e7459\n"
        "movss %xmm5, -0x40(%ebp)\n"
        "movaps %xmm4, %xmm7\n"
        /* } scope */
        ".Lf1e6f90_001e7078:\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 1710 */
        "mulss %xmm0, %xmm0\n"
        "movss -0x48(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "movl 4(%ebx), %eax\n" /* line 88 | this */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "movss %xmm6, -0xc8(%ebp)\n"
        "movss %xmm7, -0xd8(%ebp)\n"
        "calll CSoundEngine_get_3D_distance_factor\n"
        "fstps -0xdc(%ebp)\n"
        "movss -0xdc(%ebp), %xmm1\n" /* distance */
        "movss -0x68(%ebp), %xmm0\n"
        "mulss %xmm0, %xmm1\n" /* distance */
        "movss 0xdc(%ebx), %xmm0\n" /* line 90 | this */
        "movss %xmm0, -0x30(%ebp)\n"
        "ucomiss %xmm1, %xmm0\n"
        "movss -0xc8(%ebp), %xmm6\n"
        "movss -0xd8(%ebp), %xmm7\n"
        "ja .Lf1e6f90_001e7109\n"
        "ucomiss 0xd8(%ebx), %xmm1\n" /* line 94 | this */
        "ja .Lf1e6f90_001e713f\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movaps %xmm1, %xmm0\n"
        ".Lf1e6f90_001e7109:\n"
        "pxor %xmm1, %xmm1\n" /* line 104 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1e6f90_001e714c\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        ".Lf1e6f90_001e7117:\n"
        "movl 0x14(%ebp), %eax\n" /* line 176 | outDistance */
        "movss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 0xc(%ebp), %eax\n" /* line 177 | outAzimuth */
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 178 | outElevation */
        "movss %xmm1, (%eax)\n"
        /* } scope */
        "addl $0xf4, %esp\n" /* line 179 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e6f90_001e713f:\n"
        "movss 0x2eda18, %xmm1\n" /* line 94 | 10000.0f */
        "movss %xmm1, -0x30(%ebp)\n"
        ".Lf1e6f90_001e714c:\n"
        "movss -0xc(%ebp), %xmm0\n" /* line 108 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss -0x10(%ebp), %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movss -0x14(%ebp), %xmm0\n" /* listenerFace */
        "movss %xmm0, -0x34(%ebp)\n"
        /* { scope 2 */
        /* { scope 3 */
        "mulss %xmm0, %xmm0\n" /* line 26 | InvLengthSquared */
        "mulss %xmm1, %xmm1\n" /* InvLengthSquared */
        "addss %xmm1, %xmm0\n" /* InvLengthSquared */
        "movss -0x3c(%ebp), %xmm1\n" /* InvLengthSquared */
        "mulss %xmm1, %xmm1\n" /* InvLengthSquared */
        "addss %xmm1, %xmm0\n" /* InvLengthSquared */
        "sqrtss %xmm0, %xmm0\n" /* InvLengthSquared */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f, InvLengthSquared */
        "divss %xmm0, %xmm1\n" /* InvLengthSquared */
        "movaps %xmm1, %xmm0\n" /* InvLengthSquared */
        "pxor %xmm1, %xmm1\n" /* line 27 */
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lf1e6f90_001e7472\n"
        "jne .Lf1e6f90_001e7472\n"
        "movss -0x3c(%ebp), %xmm3\n"
        "movss -0x38(%ebp), %xmm1\n"
        /* } scope */
        ".Lf1e6f90_001e71b3:\n"
        "mulss %xmm7, %xmm3\n" /* line 1748 */
        "movss -0x40(%ebp), %xmm0\n"
        "mulss -0x38(%ebp), %xmm0\n"
        "subss %xmm0, %xmm3\n"
        "movss -0x40(%ebp), %xmm2\n" /* line 1749 */
        "mulss -0x34(%ebp), %xmm2\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm6, %xmm1\n" /* line 1750 */
        "movss -0x34(%ebp), %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 1735 */
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movss -0x48(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "movss -0x50(%ebp), %xmm5\n"
        "addss %xmm0, %xmm5\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "addss %xmm0, %xmm5\n"
        "mulss %xmm5, %xmm3\n" /* line 116 */
        "movss -0x44(%ebp), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movaps %xmm0, %xmm3\n"
        "mulss %xmm5, %xmm2\n" /* line 117 */
        "movss -0x48(%ebp), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "mulss %xmm5, %xmm1\n" /* line 118 */
        "movss -0x4c(%ebp), %xmm4\n"
        "subss %xmm1, %xmm4\n"
        /* { scope 3 */
        "movaps %xmm3, %xmm0\n" /* line 26 | InvLengthSquared */
        "mulss %xmm3, %xmm0\n" /* InvLengthSquared */
        "movaps %xmm2, %xmm1\n" /* InvLengthSquared */
        "mulss %xmm2, %xmm1\n" /* InvLengthSquared */
        "addss %xmm1, %xmm0\n" /* InvLengthSquared */
        "movaps %xmm4, %xmm1\n" /* InvLengthSquared */
        "mulss %xmm4, %xmm1\n" /* InvLengthSquared */
        "addss %xmm1, %xmm0\n" /* InvLengthSquared */
        "sqrtss %xmm0, %xmm0\n" /* InvLengthSquared */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f, InvLengthSquared */
        "divss %xmm0, %xmm1\n" /* InvLengthSquared */
        "pxor %xmm0, %xmm0\n" /* line 27 */
        "ucomiss %xmm0, %xmm1\n"
        "jp .Lf1e6f90_001e7289\n"
        "je .Lf1e6f90_001e7295\n"
        ".Lf1e6f90_001e7289:\n"
        "mulss %xmm1, %xmm3\n" /* line 29 */
        "mulss %xmm1, %xmm2\n" /* line 30 */
        "mulss %xmm1, %xmm4\n" /* line 31 */
        /* } scope */
        ".Lf1e6f90_001e7295:\n"
        "mulss %xmm3, %xmm6\n" /* line 121 */
        "mulss %xmm2, %xmm7\n"
        "addss %xmm7, %xmm6\n"
        "movss -0x40(%ebp), %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm6\n"
        "movss %xmm6, (%esp)\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "movss %xmm3, -0x98(%ebp)\n"
        "movss %xmm4, -0xa8(%ebp)\n"
        "movss %xmm5, -0xb8(%ebp)\n"
        "calll acosf\n"
        "fstps -0xdc(%ebp)\n"
        "movss -0xdc(%ebp), %xmm1\n"
        "mulss 0x2ed64c, %xmm1\n" /* 180.0f */
        "divss 0x2ed634, %xmm1\n" /* 3.1415927410125732f */
        "movss %xmm1, (%esp)\n" /* line 122 */
        "movss %xmm1, -0x78(%ebp)\n"
        "calll ___isnanf\n"
        "testl %eax, %eax\n"
        "movss -0x78(%ebp), %xmm1\n"
        "movss -0x88(%ebp), %xmm2\n"
        "movss -0x98(%ebp), %xmm3\n"
        "movss -0xa8(%ebp), %xmm4\n"
        "movss -0xb8(%ebp), %xmm5\n"
        "je .Lf1e6f90_001e7332\n"
        "pxor %xmm1, %xmm1\n"
        ".Lf1e6f90_001e7332:\n"
        "mulss -0x34(%ebp), %xmm3\n" /* line 129 */
        "mulss -0x38(%ebp), %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "mulss -0x3c(%ebp), %xmm4\n"
        "addss %xmm4, %xmm3\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lf1e6f90_001e7502\n"
        ".Lf1e6f90_001e7356:\n"
        "pxor %xmm0, %xmm0\n" /* line 135 */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf1e6f90_001e736c\n"
        "ucomiss 0x2ed65c, %xmm1\n" /* 270.0f */
        "jbe .Lf1e6f90_001e74d2\n"
        ".Lf1e6f90_001e736c:\n"
        "movss 0x2eda5c, %xmm0\n" /* line 141 | 450.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        /* } scope */
        ".Lf1e6f90_001e737d:\n"
        "movss -0x44(%ebp), %xmm1\n" /* line 153 */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf1e6f90_001e73b6\n"
        "jp .Lf1e6f90_001e73b6\n"
        "movss -0x48(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf1e6f90_001e73b6\n"
        "jp .Lf1e6f90_001e73b6\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "je .Lf1e6f90_001e74a0\n"
        ".Lf1e6f90_001e73a7:\n"
        "movss -0x54(%ebp), %xmm5\n"
        "addss -0x50(%ebp), %xmm5\n"
        "addss -0x58(%ebp), %xmm5\n"
        ".Lf1e6f90_001e73b6:\n"
        "movss %xmm5, (%esp)\n" /* line 155 */
        "calll acosf\n"
        "fstps -0xdc(%ebp)\n"
        "movss -0xdc(%ebp), %xmm1\n"
        "mulss 0x2ed64c, %xmm1\n" /* 180.0f */
        "divss 0x2edaa0, %xmm1\n" /* -3.1415927410125732f */
        "addss 0x2ed5f8, %xmm1\n" /* 90.0f */
        "movss %xmm1, (%esp)\n" /* line 156 */
        "movss %xmm1, -0x78(%ebp)\n"
        "calll ___isnanf\n"
        "testl %eax, %eax\n"
        "movss -0x78(%ebp), %xmm1\n"
        "jne .Lf1e6f90_001e74a6\n"
        "ucomiss 0x2ed5f8, %xmm1\n" /* line 161 | 90.0f */
        "ja .Lf1e6f90_001e74ee\n"
        ".Lf1e6f90_001e740f:\n"
        "ucomiss 0x2ed660, %xmm1\n" /* line 165 | -90.0f */
        "jae .Lf1e6f90_001e7117\n"
        "jp .Lf1e6f90_001e7117\n"
        "movss 0x2ed650, %xmm0\n" /* line 167 | -180.0f */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movl 0x14(%ebp), %eax\n" /* line 176 | outDistance */
        "movss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 0xc(%ebp), %eax\n" /* line 177 | outAzimuth */
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 178 | outElevation */
        "movss %xmm1, (%eax)\n"
        /* } scope */
        "addl $0xf4, %esp\n" /* line 179 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1e6f90_001e7459:\n"
        "mulss %xmm1, %xmm6\n" /* line 29 */
        "movaps %xmm4, %xmm7\n" /* line 30 */
        "mulss %xmm1, %xmm7\n"
        "mulss %xmm1, %xmm5\n" /* line 31 */
        "movss %xmm5, -0x40(%ebp)\n"
        "jmp .Lf1e6f90_001e7078\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1e6f90_001e7472:\n"
        "movss -0x34(%ebp), %xmm1\n" /* line 29 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 30 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "mulss -0x3c(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movaps %xmm0, %xmm3\n"
        "jmp .Lf1e6f90_001e71b3\n"
        /* } scope */
        /* } scope */
        ".Lf1e6f90_001e74a0:\n"
        "jp .Lf1e6f90_001e73a7\n" /* line 153 */
        ".Lf1e6f90_001e74a6:\n"
        "pxor %xmm1, %xmm1\n" /* line 156 */
        "movl 0x14(%ebp), %eax\n" /* line 176 | outDistance */
        "movss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 0xc(%ebp), %eax\n" /* line 177 | outAzimuth */
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 178 | outElevation */
        "movss %xmm1, (%eax)\n"
        /* } scope */
        "addl $0xf4, %esp\n" /* line 179 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1e6f90_001e74d2:\n"
        "jp .Lf1e6f90_001e736c\n" /* line 135 */
        "movss 0x2ed5f8, %xmm0\n" /* line 137 | 90.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "jmp .Lf1e6f90_001e737d\n"
        /* } scope */
        ".Lf1e6f90_001e74ee:\n"
        "movss 0x2ed64c, %xmm0\n" /* line 163 | 180.0f */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf1e6f90_001e740f\n"
        /* { scope 2 */
        ".Lf1e6f90_001e7502:\n"
        "movss 0x2ed638, %xmm0\n" /* line 131 | 360.0f */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf1e6f90_001e7356\n"
    );
}
#else
void CSampleSound_Calculate3DAttributes(const CSampleSound * _this, Float32 *outAzimuth, Float32 *outElevation, Float32 *outDistance)
{
}
#endif

