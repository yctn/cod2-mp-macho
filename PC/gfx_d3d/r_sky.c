/* ASM dump from: r_sky.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_sky.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern const dvar_t *r_sunsprite_shader; /* 0x0 */
extern const dvar_t *r_sunsprite_size; /* 0x0 */
extern const dvar_t *r_sunflare_shader; /* 0x0 */
extern const dvar_t *r_sunflare_min_size; /* 0x0 */
extern const dvar_t *r_sunflare_min_angle; /* 0x0 */
extern const dvar_t *r_sunflare_max_size; /* 0x0 */
extern const dvar_t *r_sunflare_max_angle; /* 0x0 */
extern const dvar_t *r_sunflare_max_alpha; /* 0x0 */
extern const dvar_t *r_sunflare_fadein; /* 0x0 */
extern const dvar_t *r_sunflare_fadeout; /* 0x0 */
extern const dvar_t *r_sunblind_min_angle; /* 0x0 */
extern const dvar_t *r_sunblind_max_angle; /* 0x0 */
extern const dvar_t *r_sunblind_max_darken; /* 0x0 */
extern const dvar_t *r_sunblind_fadein; /* 0x0 */
extern const dvar_t *r_sunblind_fadeout; /* 0x0 */
extern const dvar_t *r_sunglare_min_angle; /* 0x0 */
extern const dvar_t *r_sunglare_max_angle; /* 0x0 */
extern const dvar_t *r_sunglare_max_lighten; /* 0x0 */
extern const dvar_t *r_sunglare_fadein; /* 0x0 */
extern const dvar_t *r_sunglare_fadeout; /* 0x0 */
extern const char * s_sundvars[21]; /* 0x0 */
extern const dvar_t *r_sun_fx_position; /* 0x0 */

int R_GetSundvarsSize(void);
int R_RegisterSunDvars(void);
int R_Cmd_LoadSun(void);
int R_Cmd_SaveSun(void);
int R_FlushSun(void);
int R_SetSunFromDvars(sunflare_t *sun);

/* line 66 */
__attribute__((naked))
int R_GetSundvarsSize(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 66 */
        "movl %esp, %ebp\n"
        "movl $0x15, %eax\n" /* line 69 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 72 */
__attribute__((naked))
int R_RegisterSunDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 72 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $0x2000, 8(%esp)\n" /* line 74 */
        "movl $0x2265c8, 4(%esp)\n" /* "sun" */
        "movl $0x226400, (%esp)\n" /* "r_sunsprite_shader" */
        "calll Dvar_RegisterString\n"
        "movl %eax, r_sunsprite_shader\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 75 */
        "movl $0x447a0000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x41800000, 4(%esp)\n"
        "movl $0x226414, (%esp)\n" /* "r_sunsprite_size" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunsprite_size\n"
        "movl $0x2000, 8(%esp)\n" /* line 77 */
        "movl $0x2265cc, 4(%esp)\n" /* "sun_flare" */
        "movl $0x226428, (%esp)\n" /* "r_sunflare_shader" */
        "calll Dvar_RegisterString\n"
        "movl %eax, r_sunflare_shader\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 78 */
        "movl $0x461c4000, %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x22643c, (%esp)\n" /* "r_sunflare_min_size" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunflare_min_size\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 79 */
        "movl $0x42b40000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x42340000, 4(%esp)\n"
        "movl $0x226450, (%esp)\n" /* "r_sunflare_min_angle" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunflare_min_angle\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 80 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x451c4000, 4(%esp)\n"
        "movl $0x226468, (%esp)\n" /* "r_sunflare_max_size" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunflare_max_size\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 81 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40000000, 4(%esp)\n"
        "movl $0x22647c, (%esp)\n" /* "r_sunflare_max_angle" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunflare_max_angle\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 82 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x226494, (%esp)\n" /* "r_sunflare_max_alpha" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunflare_max_alpha\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 83 */
        "movl $0x42700000, %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x2264ac, (%esp)\n" /* "r_sunflare_fadein" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunflare_fadein\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 84 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x2264c0, (%esp)\n" /* "r_sunflare_fadeout" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunflare_fadeout\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 86 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x41f00000, 4(%esp)\n"
        "movl $0x2264d4, (%esp)\n" /* "r_sunblind_min_angle" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunblind_min_angle\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 87 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $0x2264ec, (%esp)\n" /* "r_sunblind_max_angle" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunblind_max_angle\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 88 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f400000, 4(%esp)\n"
        "movl $0x226504, (%esp)\n" /* "r_sunblind_max_darken" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunblind_max_darken\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 89 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f000000, 4(%esp)\n"
        "movl $0x22651c, (%esp)\n" /* "r_sunblind_fadein" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunblind_fadein\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 90 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40400000, 4(%esp)\n"
        "movl $0x226530, (%esp)\n" /* "r_sunblind_fadeout" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunblind_fadeout\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 92 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x41f00000, 4(%esp)\n"
        "movl $0x226544, (%esp)\n" /* "r_sunglare_min_angle" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunglare_min_angle\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 93 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $0x22655c, (%esp)\n" /* "r_sunglare_max_angle" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunglare_max_angle\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 94 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f400000, 4(%esp)\n"
        "movl $0x226574, (%esp)\n" /* "r_sunglare_max_lighten" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunglare_max_lighten\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 95 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f000000, 4(%esp)\n"
        "movl $0x22658c, (%esp)\n" /* "r_sunglare_fadein" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunglare_fadein\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 96 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40400000, 4(%esp)\n"
        "movl $0x2265a0, (%esp)\n" /* "r_sunglare_fadeout" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, r_sunglare_fadeout\n"
        "movl $0x2000, 0x18(%esp)\n" /* line 98 */
        "movl $0x43b40000, 0x14(%esp)\n"
        "movl $0xc3b40000, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2265b4, (%esp)\n" /* "r_sun_fx_position" */
        "calll Dvar_RegisterVec3\n"
        "movl %eax, r_sun_fx_position\n"
        "addl $0x2c, %esp\n" /* line 99 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 142 */
__attribute__((naked))
int R_Cmd_LoadSun(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 142 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0x195eee0, %esi\n" /* line 144 */
        "calll *0x100(%esi)\n"
        "cmpl $2, %eax\n"
        "je .Lff697a_000f69ab\n"
        "movl $0x2265d8, 4(%esp)\n" /* line 146 */
        "movl $0, (%esp)\n"
        "calll *(%esi)\n"
        ".Lff697a_000f69a4:\n"
        "addl $0x10, %esp\n" /* line 164 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff697a_000f69ab:\n"
        "movl 0x195ef54, %eax\n" /* line 150 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lff697a_000f69ed\n"
        "movl 0x195eebc, %eax\n" /* line 156 */
        "movl 0x109c(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lff697a_000f6a05\n"
        "movl $1, (%esp)\n" /* line 163 */
        "calll *0x104(%esi)\n"
        "leal 0x160(%ebx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll R_LoadSunThroughDvars\n"
        "addl $0x10, %esp\n" /* line 164 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff697a_000f69ed:\n"
        "movl $0x22661c, 4(%esp)\n" /* line 152 */
        "movl $0, (%esp)\n"
        "calll *(%esi)\n"
        "addl $0x10, %esp\n" /* line 164 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff697a_000f6a05:\n"
        "movl $0x22664c, 4(%esp)\n" /* line 158 */
        "movl $0, (%esp)\n"
        "calll *(%esi)\n"
        "jmp .Lff697a_000f69a4\n"
    );
}

/* line 178 */
__attribute__((naked))
int R_Cmd_SaveSun(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 178 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        "movl 0x195eee0, %ebx\n" /* line 180 */
        "calll *0x100(%ebx)\n"
        "cmpl $2, %eax\n"
        "je .Lff6a18_000f6a51\n"
        "movl $0x22667c, 4(%esp)\n" /* line 182 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        ".Lff6a18_000f6a46:\n"
        "addl $0x202c, %esp\n" /* line 187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff6a18_000f6a51:\n"
        "movl $1, (%esp)\n" /* line 186 */
        "calll *0x104(%ebx)\n"
        "movl %eax, -0x201c(%ebp)\n"
        /* { scope 1 */
        "movl $0x2000, 0xc(%esp)\n" /* line 173 */
        "leal -0x2018(%ebp), %esi\n" /* szFileBuffer */
        "movl %esi, 8(%esp)\n"
        "movl $0x15, 4(%esp)\n"
        "movl $s_sundvars, (%esp)\n"
        "calll *0x10c(%ebx)\n"
        "testl %eax, %eax\n"
        "je .Lff6a18_000f6a46\n"
        "movl 0x140(%ebx), %ebx\n" /* line 174 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n"
        "movl -0x201c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2266c0, (%esp)\n" /* "sun/%s.sun" */
        "calll va\n"
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *%ebx\n"
        /* } scope */
        "addl $0x202c, %esp\n" /* line 187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 190 */
__attribute__((naked))
int R_FlushSun(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 190 */
        "movl %esp, %ebp\n"
        "xorl %edx, %edx\n"
        "movl 0x195f088, %eax\n"
        /* { scope 1 */
        ".Lff6ad4_000f6ade:\n"
        "movl $0, 4(%eax)\n" /* line 198 */
        "movl $0, 8(%eax)\n" /* line 199 */
        "movl $0, (%eax)\n" /* line 200 */
        "movl $0, 0x20(%eax)\n" /* line 201 */
        "movl $0, 0x1c(%eax)\n" /* line 202 */
        "movl $0, 0xc(%eax)\n" /* line 203 */
        "movl $0, 0x18(%eax)\n" /* line 204 */
        "addl $1, %edx\n" /* line 195 */
        "addl $0x30, %eax\n"
        "cmpl $4, %edx\n"
        "jne .Lff6ad4_000f6ade\n"
        /* } scope */
        "popl %ebp\n" /* line 206 */
        "retl\n"
    );
}

/* line 102 */
__attribute__((naked))
int R_SetSunFromDvars(sunflare_t *sun)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x64, %esp\n"
        "movl 8(%ebp), %ebx\n" /* sun */
        "movl $6, 8(%esp)\n" /* line 106 */
        "movl $0, 4(%esp)\n"
        "movl r_sunsprite_shader, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Material_RegisterHandle\n"
        "movl %eax, 4(%ebx)\n" /* sun */
        "movl r_sunsprite_size, %eax\n" /* line 108 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* sun */
        "movl $6, 8(%esp)\n" /* line 110 */
        "movl $0, 4(%esp)\n"
        "movl r_sunflare_shader, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Material_RegisterHandle\n"
        "movl %eax, 8(%ebx)\n" /* sun */
        "movl r_sunflare_min_size, %eax\n" /* line 112 */
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0x10(%ebx)\n" /* sun */
        "movl r_sunflare_min_angle, %eax\n" /* line 113 */
        "cvtss2sd 8(%eax), %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, 0x14(%ebx)\n" /* sun */
        "movl r_sunflare_max_size, %eax\n" /* line 114 */
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0x18(%ebx)\n" /* sun */
        "movl r_sunflare_max_angle, %eax\n" /* line 115 */
        "cvtss2sd 8(%eax), %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x18(%ebp)\n"
        "cvtsd2ss -0x18(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%ebx)\n" /* sun */
        "movl r_sunflare_max_alpha, %eax\n" /* line 116 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* sun */
        "movl r_sunflare_fadein, %eax\n" /* line 428 */
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* sun */
        "movl r_sunflare_fadeout, %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x20(%ebp)\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "movl %eax, 0x28(%ebx)\n" /* sun */
        "movl r_sunblind_min_angle, %eax\n" /* line 120 */
        "cvtss2sd 8(%eax), %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x28(%ebp)\n"
        "cvtsd2ss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 0x2c(%ebx)\n" /* sun */
        "movl r_sunblind_max_angle, %eax\n" /* line 121 */
        "cvtss2sd 8(%eax), %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x30(%ebp)\n"
        "cvtsd2ss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, 0x30(%ebx)\n" /* sun */
        "movl r_sunblind_max_darken, %eax\n" /* line 122 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x34(%ebx)\n" /* sun */
        "movl r_sunblind_fadein, %eax\n" /* line 428 */
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x34(%ebp)\n"
        "cvttss2si -0x34(%ebp), %eax\n"
        "movl %eax, 0x38(%ebx)\n" /* sun */
        "movl r_sunblind_fadeout, %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x38(%ebp)\n"
        "cvttss2si -0x38(%ebp), %eax\n"
        "movl %eax, 0x3c(%ebx)\n" /* sun */
        "movl r_sunglare_min_angle, %eax\n" /* line 126 */
        "cvtss2sd 8(%eax), %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x40(%ebp)\n"
        "cvtsd2ss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, 0x40(%ebx)\n" /* sun */
        "movl r_sunglare_max_angle, %eax\n" /* line 127 */
        "cvtss2sd 8(%eax), %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x48(%ebp)\n"
        "cvtsd2ss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 0x44(%ebx)\n" /* sun */
        "movl r_sunglare_max_lighten, %eax\n" /* line 128 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x48(%ebx)\n" /* sun */
        "movl r_sunglare_fadein, %eax\n" /* line 428 */
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x4c(%ebp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "movl %eax, 0x4c(%ebx)\n" /* sun */
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "movl r_sunglare_fadeout, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x50(%ebp)\n"
        "cvttss2si -0x50(%ebp), %eax\n"
        "movl %eax, 0x50(%ebx)\n" /* sun */
        "movl $0, 0xc(%esp)\n" /* line 132 */
        "movl $0, 8(%esp)\n"
        "leal 0x54(%ebx), %eax\n" /* sun */
        "movl %eax, 4(%esp)\n"
        "movl r_sun_fx_position, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "movb $1, (%ebx)\n" /* line 134 | sun */
        "addl $0x64, %esp\n" /* line 135 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

