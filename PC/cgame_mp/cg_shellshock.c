/* ASM dump from: cg_shellshock.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_shellshock.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

static const char * cg_shock_dvar_names[29]; /* 0x314a80 */
static vec2_t cg_perturbations[131]; /* 0x303480 */

void CG_PerturbCamera(void);
qboolean CG_SaveShellShockDvars(const char *name);
qboolean CG_LoadShellShockDvars(const char *name);
qboolean CG_DrawShellShockSavedScreenBlend(const shellshock_parms_t *parms, int start, int duration);
void CG_SetShellShockParmsFromDvars(shellshock_parms_t *parms);
void CG_UpdateShellShock(const shellshock_parms_t *parms, int start, int duration);

/* line 256 */
__attribute__((naked))
void CG_PerturbCamera(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 256 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 261 */
        "movl (%eax), %ecx\n"
        "pxor %xmm0, %xmm0\n"
        "ucomiss 0x2ccec(%ecx), %xmm0\n"
        "jne .Lf1d453c_001d456a\n"
        "jp .Lf1d453c_001d456a\n"
        "ucomiss 0x2ccf0(%ecx), %xmm0\n"
        "jp .Lf1d453c_001d456a\n"
        "je .Lf1d453c_001d45fe\n"
        ".Lf1d453c_001d456a:\n"
        "movl $0x3f800000, %edx\n" /* line 264 */
        "movl %edx, -0x3c(%ebp)\n" /* rot */
        "movl 0x2ccec(%ecx), %eax\n" /* line 265 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x2ccf0(%ecx), %eax\n" /* line 266 */
        "movl %eax, -0x34(%ebp)\n"
        "movl $0, -0x24(%ebp)\n" /* line 267 */
        "movl $0, -0x20(%ebp)\n" /* line 268 */
        "movl %edx, -0x1c(%ebp)\n" /* line 269 */
        "leal -0x3c(%ebp), %edi\n" /* line 271 | rot */
        "movl %edi, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x30(%ebp), %ebx\n" /* line 272 */
        "movl %ebx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x24(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %ebx, (%esp)\n" /* line 273 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl %esi, 8(%esp)\n" /* line 274 */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Vec3Cross\n"
        "leal -0x60(%ebp), %esi\n" /* line 276 | axis */
        "movl %esi, 4(%esp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %ebx\n"
        "addl $0x28594, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll AxisCopy\n"
        "movl %ebx, 8(%esp)\n" /* line 277 */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MatrixMultiply\n"
        /* } scope */
        ".Lf1d453c_001d45fe:\n"
        "addl $0x6c, %esp\n" /* line 278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 323 */
__attribute__((naked))
qboolean CG_SaveShellShockDvars(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 323 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x10020, %esp\n"
        /* { scope 1 */
        "movl $0x10000, 0xc(%esp)\n" /* line 329 */
        "leal -0x1000c(%ebp), %ebx\n" /* filebuf */
        "movl %ebx, 8(%esp)\n"
        "movl $0x1d, 4(%esp)\n"
        "movl $cg_shock_dvar_names, (%esp)\n"
        "calll Com_SaveDvarsToBuffer\n"
        "testl %eax, %eax\n"
        "jne .Lf1d4606_001d4647\n"
        ".Lf1d4606_001d463b:\n"
        "xorl %eax, %eax\n" /* line 338 */
        /* } scope */
        "addl $0x10020, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d4606_001d4647:\n"
        "movl 8(%ebp), %eax\n" /* line 332 | name */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b798c, (%esp)\n" /* "shock/%s.shock" */
        "calll va\n"
        "movl $1, 8(%esp)\n" /* line 333 */
        "leal -0xc(%ebp), %edx\n" /* fh */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "testl %eax, %eax\n"
        "js .Lf1d4606_001d463b\n"
        "movl -0xc(%ebp), %eax\n" /* line 336 | fh */
        "movl %eax, 8(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_Write\n"
        "movl -0xc(%ebp), %eax\n" /* line 337 | fh */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x10020, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 347 */
__attribute__((naked))
qboolean CG_LoadShellShockDvars(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 347 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 362 | name */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b798c, (%esp)\n" /* "shock/%s.shock" */
        "calll va\n"
        "movl %eax, %edi\n" /* fullpath */
        "movl $0, 8(%esp)\n" /* line 380 */
        "leal -0x1c(%ebp), %ebx\n" /* fh */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %esi\n" /* filesize */
        "testl %eax, %eax\n" /* line 381 */
        "js .Lf1d46b4_001d474e\n"
        ".Lf1d46b4_001d46ef:\n"
        "leal 1(%esi), %eax\n" /* line 392 | filesize */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 393 | fh */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* filesize */
        "movl %ebx, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, (%ebx, %esi)\n" /* line 394 */
        "movl -0x1c(%ebp), %eax\n" /* line 395 | fh */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %edi, 0xc(%esp)\n" /* line 398 | fullpath */
        "movl %ebx, 8(%esp)\n"
        "movl $0x1d, 4(%esp)\n"
        "movl $cg_shock_dvar_names, (%esp)\n"
        "calll Com_LoadDvarsFromBuffer\n"
        "movl %eax, %esi\n" /* filesize */
        "movl %ebx, (%esp)\n" /* line 401 */
        "calll Z_FreeInternal\n"
        /* } scope */
        ".Lf1d46b4_001d4744:\n"
        "movl %esi, %eax\n" /* line 405 | filesize */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d46b4_001d474e:\n"
        "movl %edi, 4(%esp)\n" /* line 383 | fullpath */
        "movl $0x2b799c, (%esp)\n" /* "^1couldn't open '%s'.
" */
        "calll Com_Printf\n"
        "movl $0, 8(%esp)\n" /* line 384 */
        "movl %ebx, 4(%esp)\n"
        "movl $0x2b79b4, (%esp)\n" /* "shock/default.shock" */
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %esi\n" /* filesize */
        "testl %eax, %eax\n" /* line 385 */
        "jns .Lf1d46b4_001d46ef\n"
        "movl $0x2b79c8, (%esp)\n" /* line 387 */
        "calll Com_Printf\n"
        "xorl %esi, %esi\n" /* filesize */
        "jmp .Lf1d46b4_001d4744\n"
    );
}

/* line 286 */
__attribute__((naked))
qboolean CG_DrawShellShockSavedScreenBlend(const shellshock_parms_t *parms, int start, int duration)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 286 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* start */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 291 */
        "je .Lf1d4790_001d47f3\n"
        "movl 0x10(%ebp), %ecx\n" /* duration */
        "testl %ecx, %ecx\n"
        "jle .Lf1d4790_001d47f3\n"
        "movl 0x195f584, %eax\n" /* line 297 */
        "movl (%eax), %ebx\n"
        "movl 0x10(%ebp), %ecx\n" /* duration */
        "leal (%edx, %ecx), %eax\n"
        "subl 0x25bb0(%ebx), %eax\n"
        "testl %eax, %eax\n" /* line 298 */
        "jle .Lf1d4790_001d4847\n"
        "movl 8(%ebp), %esi\n" /* line 304 | parms */
        "movl 0x10(%esi), %edx\n"
        "movl 0xc(%esi), %ecx\n" /* line 305 */
        "cmpl %ecx, %eax\n"
        "jl .Lf1d4790_001d480d\n"
        ".Lf1d4790_001d47ce:\n"
        "movl 0x2ccf4(%ebx), %eax\n" /* line 310 */
        "testl %eax, %eax\n"
        "jne .Lf1d4790_001d483d\n"
        ".Lf1d4790_001d47d8:\n"
        "calll CL_SaveScreen\n" /* line 312 */
        "movl $1, 0x2ccf4(%ebx)\n" /* line 313 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 315 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d4790_001d47f3:\n"
        "movl 0x195f584, %eax\n" /* line 293 */
        "movl (%eax), %eax\n"
        "movl $0, 0x2ccf4(%eax)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1d4790_001d4806:\n"
        "addl $0x20, %esp\n" /* line 315 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d4790_001d480d:\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 428 */
        "cvtsi2ssl %eax, %xmm0\n"
        "cvtsi2ssl %ecx, %xmm2\n"
        "divss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0xc(%ebp)\n"
        "cvttss2si -0xc(%ebp), %edx\n"
        "jmp .Lf1d4790_001d47ce\n"
        ".Lf1d4790_001d483d:\n"
        "movl %edx, (%esp)\n" /* line 311 */
        "calll CL_BlendSavedScreen\n"
        "jmp .Lf1d4790_001d47d8\n"
        ".Lf1d4790_001d4847:\n"
        "movl $0, 0x2ccf4(%ebx)\n" /* line 300 */
        "xorl %eax, %eax\n"
        "jmp .Lf1d4790_001d4806\n"
    );
}

/* line 413 */
__attribute__((naked))
void CG_SetShellShockParmsFromDvars(shellshock_parms_t *parms)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 413 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* parms */
        "movl 0x195f878, %eax\n" /* line 428 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xc(%ebp)\n"
        "cvttss2si -0xc(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* parms */
        "movl 0x195f89c, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x10(%ebp)\n"
        "cvttss2si -0x10(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* parms */
        "movl $0xbb8, (%ebx)\n" /* line 422 | parms */
        "movl 0x195f8b4, %eax\n" /* line 423 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        /* { scope 1 */
        "movss 0x2ed658, %xmm2\n" /* line 45 | 0.0010000000474974513f */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1d4856_001d48f2\n"
        "jb .Lf1d4856_001d4dbd\n"
        ".Lf1d4856_001d48f2:\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        ".Lf1d4856_001d48fa:\n"
        "movss %xmm0, 4(%ebx)\n" /* line 423 | parms */
        "movl 0x195f880, %eax\n" /* line 424 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%ebx)\n" /* parms */
        "movl 0x195f890, %eax\n" /* line 426 */
        "movl (%eax), %eax\n"
        "movzbl 8(%eax), %eax\n"
        "movl %eax, 0x14(%ebx)\n" /* parms */
        "movl 0x195f8a8, %eax\n" /* line 428 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x14(%ebp)\n"
        "cvttss2si -0x14(%ebp), %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* parms */
        "movl 0x195f898, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x18(%ebp)\n"
        "cvttss2si -0x18(%ebp), %eax\n"
        "movl %eax, 0x1c(%ebx)\n" /* parms */
        "movl 0x195f8e4, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "movl %eax, 0x68(%ebx)\n" /* parms */
        "movl 0x195f8c8, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x20(%ebp)\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "movl %eax, 0x6c(%ebx)\n" /* parms */
        "movl 0x195f8b0, %eax\n" /* line 431 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_EnumToString\n"
        "movl $0xf, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x28(%ebx), %eax\n" /* parms */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "movb $0, 0x37(%ebx)\n" /* line 432 | parms */
        "movl 0x195f88c, %eax\n" /* line 433 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* parms */
        "movl 0x195f8e0, %eax\n" /* line 434 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* parms */
        "movl 0x195f8cc, %eax\n" /* line 428 */
        "movl (%eax), %eax\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "mulss 8(%eax), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x24(%ebp)\n"
        "cvttss2si -0x24(%ebp), %eax\n"
        "movl %eax, 0x64(%ebx)\n" /* parms */
        "movl 0x195f8b8, %eax\n" /* line 436 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "pxor %xmm2, %xmm2\n" /* line 45 */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4e44\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4a7e:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x38(%ebx)\n" /* line 436 | parms */
        "movl 0x195f888, %eax\n" /* line 437 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4e38\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4ac3:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x3c(%ebx)\n" /* line 437 | parms */
        "movl 0x195f8bc, %eax\n" /* line 438 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4e2c\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4b08:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x40(%ebx)\n" /* line 438 | parms */
        "movl 0x195f8c0, %eax\n" /* line 439 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4e20\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4b4d:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x4c(%ebx)\n" /* line 439 | parms */
        "movl 0x195f8c4, %eax\n" /* line 440 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4e14\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4b92:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x50(%ebx)\n" /* line 440 | parms */
        "movl 0x195f894, %eax\n" /* line 441 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4e08\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4bd7:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x48(%ebx)\n" /* line 441 | parms */
        "movl 0x195f8d0, %eax\n" /* line 442 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4dfc\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4c1c:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x44(%ebx)\n" /* line 442 | parms */
        "movl 0x195f8a0, %eax\n" /* line 443 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4df0\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4c61:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x54(%ebx)\n" /* line 443 | parms */
        "movl 0x195f8d8, %eax\n" /* line 444 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4de4\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4ca6:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x58(%ebx)\n" /* line 444 | parms */
        "movl 0x195f8a4, %eax\n" /* line 445 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4dd8\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4ceb:\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x5c(%ebx)\n" /* line 445 | parms */
        "movl 0x195f884, %eax\n" /* line 446 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1d4856_001d4dc9\n"
        "movaps %xmm2, %xmm1\n"
        "movss 0x2ed5dc, %xmm3\n" /* -1.0f */
        /* { scope 1 */
        ".Lf1d4856_001d4d30:\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm2, %xmm3\n"
        "andps %xmm3, %xmm4\n"
        "andnps %xmm0, %xmm3\n"
        "orps %xmm4, %xmm3\n"
        /* } scope */
        "movss %xmm3, 0x60(%ebx)\n" /* line 446 | parms */
        "movl 0x195f8ac, %eax\n" /* line 465 */
        "movl (%eax), %eax\n"
        "movzbl 8(%eax), %eax\n"
        "movl %eax, 0x70(%ebx)\n" /* parms */
        "movl 0x195f8d4, %eax\n" /* line 428 */
        "movl (%eax), %eax\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "mulss 8(%eax), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x28(%ebp)\n"
        "cvttss2si -0x28(%ebp), %eax\n"
        "movl %eax, 0x74(%ebx)\n" /* parms */
        "movl 0x195f874, %eax\n" /* line 468 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x7c(%ebx)\n" /* parms */
        "movl 0x195f87c, %eax\n" /* line 469 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x80(%ebx)\n" /* parms */
        "movl 0x195f8dc, %eax\n" /* line 470 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x78(%ebx)\n" /* parms */
        "addl $0x34, %esp\n" /* line 471 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d4856_001d4dbd:\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "divss %xmm1, %xmm0\n"
        "jmp .Lf1d4856_001d48fa\n"
        /* } scope */
        ".Lf1d4856_001d4dc9:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movaps %xmm0, %xmm3\n"
        "jmp .Lf1d4856_001d4d30\n"
        ".Lf1d4856_001d4dd8:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf1d4856_001d4ceb\n"
        ".Lf1d4856_001d4de4:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf1d4856_001d4ca6\n"
        ".Lf1d4856_001d4df0:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf1d4856_001d4c61\n"
        ".Lf1d4856_001d4dfc:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf1d4856_001d4c1c\n"
        ".Lf1d4856_001d4e08:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf1d4856_001d4bd7\n"
        ".Lf1d4856_001d4e14:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf1d4856_001d4b92\n"
        ".Lf1d4856_001d4e20:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf1d4856_001d4b4d\n"
        ".Lf1d4856_001d4e2c:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf1d4856_001d4b08\n"
        ".Lf1d4856_001d4e38:\n"
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "jmp .Lf1d4856_001d4ac3\n"
        ".Lf1d4856_001d4e44:\n"
        "movaps %xmm1, %xmm0\n"
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf1d4856_001d4a7e\n"
    );
}

/* line 706 */
__attribute__((naked))
void CG_UpdateShellShock(const shellshock_parms_t *parms, int start, int duration)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 706 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* start */
        /* { scope 1: fade, channelvolume */
        "movl 0x195f584, %ebx\n" /* line 710 */
        "movl (%ebx), %esi\n" /* pAlias0 */
        "movl 0x25bb0(%esi), %edi\n" /* pAlias0, time */
        "subl %eax, %edi\n" /* time */
        "testl %eax, %eax\n" /* line 711 */
        "je .Lf1d4e54_001d51f4\n"
        "testl %edi, %edi\n" /* time */
        "js .Lf1d4e54_001d51f4\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 551 | parms */
        "movl 0x14(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1d4e54_001d5282\n"
        "movl %eax, %ecx\n"
        "movl 0x1c(%eax), %edx\n" /* line 557 */
        "movl 0x10(%ebp), %eax\n" /* duration */
        "addl 0x64(%ecx), %eax\n"
        "addl %edx, %eax\n"
        "subl %edi, %eax\n"
        "cmpl %eax, %edx\n" /* line 558 */
        "jle .Lf1d4e54_001d5265\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 559 */
        "movss %xmm0, -0x4c(%ebp)\n" /* fade */
        "cvtsi2ssl %edx, %xmm0\n"
        "movss -0x4c(%ebp), %xmm1\n" /* fade */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x4c(%ebp)\n" /* fade */
        ".Lf1d4e54_001d4ec3:\n"
        "pxor %xmm0, %xmm0\n" /* line 564 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1d4e54_001d5372\n"
        "ucomiss %xmm0, %xmm1\n" /* line 567 */
        "jp .Lf1d4e54_001d4edb\n"
        "je .Lf1d4e54_001d5377\n"
        ".Lf1d4e54_001d4edb:\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        ".Lf1d4e54_001d4ee3:\n"
        "movl 8(%ebp), %eax\n" /* parms */
        "movl $1, %edx\n"
        "leal -0x44(%ebp), %ecx\n" /* channelvolume */
        ".Lf1d4e54_001d4eee:\n"
        "movss 0x38(%eax), %xmm0\n" /* line 570 */
        "subss %xmm2, %xmm0\n"
        "mulss -0x4c(%ebp), %xmm0\n" /* fade */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -4(%ecx, %edx, 4)\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $0xc, %edx\n" /* line 569 */
        "jne .Lf1d4e54_001d4eee\n"
        "movl $0, 8(%esp)\n" /* line 571 */
        "movl %ecx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll SND_SetChannelVolumes\n"
        "movl $0, 0x10(%esp)\n" /* line 573 */
        "movss -0x4c(%ebp), %xmm0\n" /* fade */
        "movl 8(%ebp), %eax\n" /* parms */
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x4c(%ebp), %xmm0\n" /* fade */
        "mulss 0x20(%eax), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "addl $0x28, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll SND_SetEnvironmentEffects\n"
        ".Lf1d4e54_001d4f67:\n"
        "movl 8(%ebp), %edx\n" /* line 583 | parms */
        "movl 0x6c(%edx), %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* duration */
        "addl %ecx, %ebx\n"
        "addl 0x68(%edx), %ebx\n"
        "subl %edi, %ebx\n"
        "testl %ebx, %ebx\n" /* line 584 */
        "jle .Lf1d4e54_001d5007\n"
        /* { scope 3 */
        "movl $0x2b7a3c, (%esp)\n" /* line 586 */
        "calll CL_PickSoundAlias\n"
        "movl %eax, %esi\n" /* pAlias0 */
        "movl $0x2b7a4c, (%esp)\n" /* line 587 */
        "calll CL_PickSoundAlias\n"
        "movl %eax, %edx\n" /* pAlias1 */
        "movl 8(%ebp), %ecx\n" /* line 589 | parms */
        "movl 0x68(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d4e54_001d53e9\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 591 */
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 592 */
        "maxss %xmm1, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n" /* fade */
        ".Lf1d4e54_001d4fce:\n"
        "movl $1, 0x18(%esp)\n" /* line 595 */
        "movl $0, 0x14(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x3ff, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pAlias0 */
        "calll SND_PlayBlendedSoundAliases\n"
        "movl 8(%ebp), %eax\n" /* parms */
        "movl 0x6c(%eax), %ecx\n"
        /* } scope */
        ".Lf1d4e54_001d5007:\n"
        "movl 0x195f584, %esi\n" /* line 598 | pAlias0 */
        "movl (%esi), %ebx\n" /* pAlias0 */
        "movl 0x25bb0(%ebx), %edx\n"
        "movl %edx, %eax\n"
        "subl %edi, %eax\n"
        "addl 0x10(%ebp), %eax\n" /* duration */
        "addl %ecx, %eax\n"
        "cmpl %eax, %edx\n" /* line 599 */
        "jge .Lf1d4e54_001d5325\n"
        "movl 0x2cce4(%ebx), %eax\n" /* line 601 */
        "testl %eax, %eax\n"
        "jne .Lf1d4e54_001d545b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d4e54_001d5034:\n"
        "movl 8(%ebp), %edx\n" /* line 628 | parms */
        "movl 0x70(%edx), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf1d4e54_001d52c8\n"
        ".Lf1d4e54_001d5042:\n"
        "movl %edx, %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* line 634 | duration */
        "subl %edi, %ebx\n"
        "movl 0x74(%edx), %eax\n"
        "cmpl %eax, %ebx\n"
        "jge .Lf1d4e54_001d507e\n"
        "testl %ebx, %ebx\n" /* line 638 */
        "jle .Lf1d4e54_001d54cd\n"
        "cvtsi2ssl %ebx, %xmm1\n" /* line 640 */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movss 0x2ed5d0, %xmm2\n" /* line 648 | 1.0f */
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lf1d4e54_001d5413\n"
        "jne .Lf1d4e54_001d5413\n"
        "movl 8(%ebp), %ecx\n" /* parms */
        ".Lf1d4e54_001d507e:\n"
        "movl (%esi), %edx\n" /* line 650 | pAlias0 */
        "movl 0x78(%ecx), %eax\n"
        "movl %eax, 0x2cce8(%edx)\n"
        "movl 0x80(%ecx), %eax\n" /* line 651 */
        "movl %eax, 4(%esp)\n"
        "movl 0x7c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_CapTurnRate\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d4e54_001d509e:\n"
        "testl %ebx, %ebx\n" /* line 679 */
        "jle .Lf1d4e54_001d52ef\n"
        ".Lf1d4e54_001d50a6:\n"
        "movl 8(%ebp), %ecx\n" /* line 686 | parms */
        "movl (%ecx), %eax\n"
        "cmpl %ebx, %eax\n"
        "jg .Lf1d4e54_001d5309\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movss 0x2ed628, %xmm5\n" /* -2.0f */
        ".Lf1d4e54_001d50c3:\n"
        "addss 0x2ed720, %xmm5\n" /* line 689 | 3.0f */
        "mulss %xmm1, %xmm5\n"
        "mulss %xmm1, %xmm5\n"
        "movl 8(%ebp), %eax\n" /* parms */
        "mulss 8(%eax), %xmm5\n"
        "cvtsi2ssl %edi, %xmm4\n" /* line 691 */
        "mulss 4(%eax), %xmm4\n"
        /* { scope 3 */
        "movss %xmm4, (%esp)\n" /* line 443 */
        "movss %xmm4, -0x68(%ebp)\n"
        "movss %xmm5, -0x78(%ebp)\n"
        "calll floorf\n"
        "fstps -0x50(%ebp)\n"
        "cvttss2si -0x50(%ebp), %edx\n"
        /* } scope */
        "cvtsi2ssl %edx, %xmm0\n" /* line 693 */
        "movss -0x68(%ebp), %xmm4\n"
        "subss %xmm0, %xmm4\n"
        "movl 0x10(%ebp), %eax\n" /* line 695 | duration */
        "shll $4, %eax\n"
        "subl 0x10(%ebp), %eax\n" /* duration */
        "movl 0x10(%ebp), %ecx\n" /* duration */
        "leal (%ecx, %eax, 4), %eax\n"
        "addl %eax, %edx\n"
        "andl $0x7f, %edx\n"
        "shll $3, %edx\n"
        "leal cg_perturbations(%edx), %ecx\n"
        "movss 0x10(%ecx), %xmm2\n" /* line 696 | x2 */
        "movss 8(%ecx), %xmm3\n"
        "movss cg_perturbations(%edx), %xmm1\n" /* x0 */
        /* { scope 3 */
        /* { scope 4 */
        "movss 0x18(%ecx), %xmm0\n" /* line 200 */
        "subss %xmm2, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        /* } scope */
        /* } scope */
        "movl 0x195f584, %eax\n" /* line 696 */
        "movl (%eax), %eax\n"
        "subss %xmm1, %xmm2\n" /* x0, x2 */
        "subss %xmm3, %xmm1\n" /* x0 */
        "subss %xmm0, %xmm1\n" /* x0 */
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n" /* x0 */
        "mulss %xmm4, %xmm1\n" /* x0 */
        "addss %xmm1, %xmm2\n" /* x0, x2 */
        "mulss %xmm4, %xmm2\n" /* x2 */
        "addss %xmm2, %xmm3\n" /* x2 */
        "movss -0x78(%ebp), %xmm5\n"
        "mulss %xmm5, %xmm3\n"
        "movss %xmm3, 0x2ccec(%eax)\n"
        "movss 0x14(%ecx), %xmm2\n" /* line 697 | x2 */
        "movss 0xc(%ecx), %xmm3\n"
        "movss 4(%ecx), %xmm1\n" /* x0 */
        /* { scope 3 */
        /* { scope 4 */
        "movss 0x1c(%ecx), %xmm0\n" /* line 200 */
        "subss %xmm2, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        /* } scope */
        /* } scope */
        "subss %xmm1, %xmm2\n" /* line 697 | x0, x2 */
        "subss %xmm3, %xmm1\n" /* x0 */
        "subss %xmm0, %xmm1\n" /* x0 */
        "mulss %xmm4, %xmm0\n" /* t */
        "addss %xmm0, %xmm1\n" /* x0 */
        "mulss %xmm4, %xmm1\n" /* t, x0 */
        "addss %xmm1, %xmm2\n" /* x0, x2 */
        "mulss %xmm2, %xmm4\n" /* x2, t */
        "addss %xmm4, %xmm3\n" /* t */
        "mulss %xmm3, %xmm5\n"
        "movss %xmm5, 0x2ccf0(%eax)\n"
        /* } scope */
        ".Lf1d4e54_001d51d9:\n"
        "xorl %eax, %eax\n" /* line 720 */
        "cmpl 0x10(%ebp), %edi\n" /* duration, time */
        "setl %al\n"
        "movl %eax, (%esp)\n"
        "calll CL_SetUserCmdInShellshock\n" /* line 530 */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 721 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fade, channelvolume */
        ".Lf1d4e54_001d51f4:\n"
        "movl $0, 4(%esp)\n" /* line 481 */
        "movl $3, (%esp)\n"
        "calll SND_DeactivateChannelVolumes\n"
        "movl $0, 4(%esp)\n" /* line 483 */
        "movl $2, (%esp)\n"
        "calll SND_DeactivateEnvironmentEffects\n"
        "movl 0x2cce4(%esi), %ecx\n" /* line 488 */
        "testl %ecx, %ecx\n"
        "jne .Lf1d4e54_001d53a4\n"
        ".Lf1d4e54_001d522a:\n"
        "movl $0x3f800000, 0x2cce8(%esi)\n" /* line 503 */
        "xorl %ebx, %ebx\n" /* line 504 */
        "movl %ebx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_CapTurnRate\n"
        "movl %ebx, 0x2ccec(%esi)\n" /* line 515 */
        "movl %ebx, 0x2ccf0(%esi)\n" /* line 516 */
        "movl $0, (%esp)\n" /* line 530 */
        "calll CL_SetUserCmdInShellshock\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 721 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fade, channelvolume */
        /* { scope 2 */
        ".Lf1d4e54_001d5265:\n"
        "movl 0x18(%ecx), %eax\n" /* line 560 */
        "cmpl %eax, %edi\n"
        "jl .Lf1d4e54_001d53f3\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movss %xmm2, -0x4c(%ebp)\n" /* fade */
        "jmp .Lf1d4e54_001d4ee3\n"
        ".Lf1d4e54_001d5282:\n"
        "movl $0, 4(%esp)\n" /* line 481 */
        "movl $3, (%esp)\n"
        "calll SND_DeactivateChannelVolumes\n"
        "movl $0, 4(%esp)\n" /* line 483 */
        "movl $2, (%esp)\n"
        "calll SND_DeactivateEnvironmentEffects\n"
        "movl 0x2cce4(%esi), %eax\n" /* line 488 */
        "testl %eax, %eax\n"
        "jne .Lf1d4e54_001d5486\n"
        "movl %ebx, %esi\n"
        /* } scope */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 628 | parms */
        "movl 0x70(%edx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf1d4e54_001d5042\n"
        ".Lf1d4e54_001d52c8:\n"
        "movl (%esi), %eax\n" /* line 503 */
        "movl $0x3f800000, 0x2cce8(%eax)\n"
        "xorl %eax, %eax\n" /* line 504 */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_CapTurnRate\n"
        "movl 0x10(%ebp), %ebx\n" /* duration */
        "subl %edi, %ebx\n"
        /* } scope */
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 679 */
        "jg .Lf1d4e54_001d50a6\n"
        ".Lf1d4e54_001d52ef:\n"
        "movl 0x195f584, %eax\n" /* line 515 */
        "movl (%eax), %edx\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x2ccec(%edx)\n"
        "movl %eax, 0x2ccf0(%edx)\n" /* line 516 */
        "jmp .Lf1d4e54_001d51d9\n"
        ".Lf1d4e54_001d5309:\n"
        "cvtsi2ssl %ebx, %xmm1\n" /* line 687 */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm5\n"
        "mulss 0x2ed628, %xmm5\n" /* -2.0f */
        "jmp .Lf1d4e54_001d50c3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d4e54_001d5325:\n"
        "cmpl 0x2cce4(%ebx), %eax\n" /* line 607 */
        "je .Lf1d4e54_001d5034\n"
        "movl %eax, 0x2cce4(%ebx)\n" /* line 609 */
        "movl %edx, %ebx\n" /* line 610 */
        "subl %eax, %ebx\n"
        "movl $0x2b7a64, (%esp)\n" /* "shellshock_end" */
        "calll CL_PickSoundAlias\n"
        "movl $1, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        ".Lf1d4e54_001d5353:\n"
        "movl 0x195ed4c, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x3ff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SND_PlaySoundAlias\n"
        "jmp .Lf1d4e54_001d5034\n"
        ".Lf1d4e54_001d5372:\n"
        "movss %xmm0, -0x4c(%ebp)\n" /* line 573 | fade */
        ".Lf1d4e54_001d5377:\n"
        "movl $0, 4(%esp)\n" /* line 577 */
        "movl $3, (%esp)\n"
        "calll SND_DeactivateChannelVolumes\n"
        "movl $0, 4(%esp)\n" /* line 579 */
        "movl $2, (%esp)\n"
        "calll SND_DeactivateEnvironmentEffects\n"
        "jmp .Lf1d4e54_001d4f67\n"
        /* } scope */
        ".Lf1d4e54_001d53a4:\n"
        "movl $0, 0x2cce4(%esi)\n" /* line 490 */
        "movl $0x2b7a24, (%esp)\n" /* line 491 */
        "calll CL_PickSoundAlias\n"
        "movl $1, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 0x195ed4c, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x3ff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SND_PlaySoundAlias\n"
        "jmp .Lf1d4e54_001d522a\n"
        ".Lf1d4e54_001d53e9:\n"
        "movss -0x4c(%ebp), %xmm0\n" /* fade */
        "jmp .Lf1d4e54_001d4fce\n"
        /* { scope 2 */
        ".Lf1d4e54_001d53f3:\n"
        "cvtsi2ssl %edi, %xmm0\n" /* line 561 */
        "movss %xmm0, -0x4c(%ebp)\n" /* fade */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x4c(%ebp), %xmm1\n" /* fade */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x4c(%ebp)\n" /* fade */
        "jmp .Lf1d4e54_001d4ec3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d4e54_001d5413:\n"
        "movl (%esi), %eax\n" /* line 655 | pAlias0 */
        "movl 8(%ebp), %edx\n" /* parms */
        "movss 0x78(%edx), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 0x2cce8(%eax)\n"
        "movss 0x80(%edx), %xmm0\n" /* line 656 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss 0x7c(%edx), %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll CL_CapTurnRate\n"
        "jmp .Lf1d4e54_001d509e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d4e54_001d545b:\n"
        "movl $0, 0x2cce4(%ebx)\n" /* line 603 */
        "movl $0x2b7a24, (%esp)\n" /* line 604 */
        "calll CL_PickSoundAlias\n"
        "movl $1, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "jmp .Lf1d4e54_001d5353\n"
        ".Lf1d4e54_001d5486:\n"
        "movl $0, 0x2cce4(%esi)\n" /* line 490 */
        "movl $0x2b7a24, (%esp)\n" /* line 491 */
        "calll CL_PickSoundAlias\n"
        "movl $1, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 0x195ed4c, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x3ff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SND_PlaySoundAlias\n"
        "movl %ebx, %esi\n"
        "jmp .Lf1d4e54_001d5034\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d4e54_001d54cd:\n"
        "movl (%esi), %eax\n" /* line 503 */
        "movl $0x3f800000, 0x2cce8(%eax)\n"
        "xorl %eax, %eax\n" /* line 504 */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_CapTurnRate\n"
        "jmp .Lf1d4e54_001d509e\n"
    );
}

