/* ASM dump from: g_mover_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_mover_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern char * hintStrings[6]; /* 0x0 */
static pushed_t pushed[1024]; /* 0xfdf780 */
static pushed_t *pushed_p; /* 0xfe7780 */

bitread_perm_state use_trigger_use(gentity_t *ent, gentity_t *other, gentity_t *activator);
static bitread_perm_state trigger_use_shared(void);
bitread_perm_state trigger_use(gentity_t *ent);
bitread_perm_state trigger_use_touch(gentity_t *ent);
qboolean G_TryPushingEntity(gentity_t *check, gentity_t *pusher, vec_t *move, vec_t *amove);
bitread_perm_state G_MoverTeam(gentity_t *ent);
bitread_perm_state G_RunMover(gentity_t *ent);

/* line 522 */
__attribute__((naked))
bitread_perm_state use_trigger_use(gentity_t *ent, gentity_t *other, gentity_t *activator)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 522 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 524 */
        "retl\n"
    );
}

/* line 527 */
static __attribute__((naked))
bitread_perm_state trigger_use_shared(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 527 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl %eax, %edi\n" /* ent */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 535 */
        "calll SV_SetBrushModel\n"
        "movl %edi, (%esp)\n" /* line 536 | ent */
        "calll SV_LinkEntity\n"
        "movl $0x3ff, 0x1b4(%edi)\n" /* line 538 | ent */
        "movl $0, 0xc(%edi)\n" /* line 539 | ent */
        "leal 0x18(%edi), %ecx\n" /* line 540 | ent, to */
        "leal 0x138(%edi), %edx\n" /* ent, from */
        /* { scope 2 */
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x18(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0x200000, 0x11c(%edi)\n" /* line 542 | ent */
        "movb $1, 0xf2(%edi)\n" /* line 544 | ent */
        "movb $0x12, 0x166(%edi)\n" /* line 546 | ent */
        "movl $2, 0xdc(%edi)\n" /* line 549 | ent */
        "leal -0x1c(%ebp), %eax\n" /* line 552 | cursorhint */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2b57a4, (%esp)\n" /* "cursorhint" */
        "calll G_SpawnString\n"
        "testl %eax, %eax\n"
        "jne .Lf1b8274_001b83b5\n"
        ".Lf1b8274_001b8306:\n"
        "movl $0xff, 0xd8(%edi)\n" /* line 570 | ent */
        "leal -0x1c(%ebp), %eax\n" /* line 571 | cursorhint */
        "movl %eax, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2b57b0, (%esp)\n" /* "hintstring" */
        "calll G_SpawnString\n"
        "testl %eax, %eax\n"
        "jne .Lf1b8274_001b833a\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b8274_001b833a:\n"
        "xorl %esi, %esi\n" /* line 571 | i */
        "jmp .Lf1b8274_001b8367\n"
        ".Lf1b8274_001b833e:\n"
        "leal -0x41c(%ebp), %eax\n" /* line 583 | szConfigString */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* cursorhint */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1b8274_001b840b\n"
        "addl $1, %esi\n" /* line 574 | i */
        "cmpl $0x20, %esi\n" /* i */
        "je .Lf1b8274_001b8421\n"
        ".Lf1b8274_001b8367:\n"
        "leal 0x4fe(%esi), %ebx\n" /* line 571 | i */
        "movl $0x400, 8(%esp)\n" /* line 576 */
        "leal -0x41c(%ebp), %edx\n" /* szConfigString */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "cmpb $0, -0x41c(%ebp)\n" /* line 577 | szConfigString */
        "jne .Lf1b8274_001b833e\n"
        "movl -0x1c(%ebp), %eax\n" /* line 579 | cursorhint */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl %esi, %edx\n" /* line 580 | i */
        "movzbl %dl, %eax\n"
        "movl %eax, 0xd8(%edi)\n" /* ent */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b8274_001b83b5:\n"
        "movl $0x2b2be0, 4(%esp)\n" /* line 554 */
        "movl -0x1c(%ebp), %eax\n" /* cursorhint */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1b8274_001b83fc\n"
        "movl $1, %esi\n" /* line 555 | i */
        "movl $hintStrings, %ebx\n"
        ".Lf1b8274_001b83d6:\n"
        "movl 4(%ebx), %eax\n" /* line 560 */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* cursorhint */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1b8274_001b8448\n"
        "addl $1, %esi\n" /* line 558 | i */
        "addl $4, %ebx\n"
        "cmpl $6, %esi\n" /* i */
        "jne .Lf1b8274_001b83d6\n"
        "jmp .Lf1b8274_001b8306\n"
        ".Lf1b8274_001b83fc:\n"
        "movl $0xffffffff, 0xdc(%edi)\n" /* line 555 | ent */
        "jmp .Lf1b8274_001b8306\n"
        ".Lf1b8274_001b840b:\n"
        "movl %esi, %edx\n" /* line 585 | i */
        "movzbl %dl, %eax\n"
        "movl %eax, 0xd8(%edi)\n" /* ent */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b8274_001b8421:\n"
        "movl $0x20, 8(%esp)\n" /* line 591 */
        "movl $0x2b57bc, 4(%esp)\n" /* "Too many different hintstring key values on trigger_use ent" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x42c, %esp\n" /* line 593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b8274_001b8448:\n"
        "movl %esi, 0xdc(%edi)\n" /* line 562 | i, ent */
        "jmp .Lf1b8274_001b8306\n"
    );
}

/* line 596 */
__attribute__((naked))
bitread_perm_state trigger_use(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 596 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "popl %ebp\n" /* line 599 */
        "jmp trigger_use_shared\n" /* line 598 */
    );
}

/* line 602 */
__attribute__((naked))
bitread_perm_state trigger_use_touch(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 602 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "popl %ebp\n" /* line 605 */
        "jmp trigger_use_shared\n" /* line 604 */
    );
}

/* line 154 */
__attribute__((naked))
qboolean G_TryPushingEntity(gentity_t *check, gentity_t *pusher, vec_t *move, vec_t *amove)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 154 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "movl 8(%ebp), %edi\n" /* check */
        "movl 0x10(%ebp), %eax\n" /* move */
        /* { scope 1: tr */
        "leal 0x138(%edi), %edx\n" /* line 163 | check */
        "movl %edx, -0xd8(%ebp)\n"
        "movss 0x138(%edi), %xmm0\n" /* line 240 | check */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* vOrigin */
        "movss 4(%edx), %xmm0\n" /* line 241 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 242 */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 100 */
        "leal -0x48(%ebp), %edx\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* transpose */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* amove */
        "movl %edx, (%esp)\n"
        "calll AngleVectors\n"
        "movss 0x303230, %xmm0\n" /* line 224 */
        "movss -0x48(%ebp), %xmm1\n"
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movss -0x44(%ebp), %xmm1\n" /* line 225 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss -0x40(%ebp), %xmm1\n" /* line 226 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        "xorl %esi, %esi\n" /* i */
        "leal -0x9c(%ebp), %eax\n" /* matrix */
        ".Lf1b846c_001b8510:\n"
        "leal -0x54(%ebp, %esi, 4), %ecx\n"
        "movl %eax, %edx\n"
        "leal 0xc(%eax), %ebx\n"
        /* { scope 2 */
        ".Lf1b846c_001b8519:\n"
        "movl (%ecx), %eax\n" /* line 120 */
        "movl %eax, (%edx)\n"
        "addl $0xc, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %edx, %ebx\n" /* line 118 */
        "jne .Lf1b846c_001b8519\n"
        "addl $1, %esi\n" /* line 116 | i */
        "cmpl $3, %esi\n" /* i */
        "je .Lf1b846c_001b8533\n"
        "movl %ebx, %eax\n"
        "jmp .Lf1b846c_001b8510\n"
        ".Lf1b846c_001b8533:\n"
        "movl 0xc(%ebp), %eax\n" /* pusher */
        "addl $0x138, %eax\n"
        /* } scope */
        /* { scope 2 */
        "movss -0x24(%ebp), %xmm5\n" /* line 248 | vOrigin */
        "movl 0xc(%ebp), %edx\n" /* pusher */
        "subss 0x138(%edx), %xmm5\n"
        "movss -0x20(%ebp), %xmm4\n" /* line 249 */
        "subss 4(%eax), %xmm4\n"
        "movss -0x1c(%ebp), %xmm6\n" /* line 250 */
        "subss 8(%eax), %xmm6\n"
        /* } scope */
        "movaps %xmm5, %xmm3\n" /* line 138 */
        "mulss -0x9c(%ebp), %xmm3\n" /* matrix */
        "movaps %xmm4, %xmm0\n"
        "mulss -0x98(%ebp), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movaps %xmm6, %xmm0\n"
        "mulss -0x94(%ebp), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, -0x30(%ebp)\n" /* org2 */
        "movaps %xmm5, %xmm2\n" /* line 139 */
        "mulss -0x90(%ebp), %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss -0x8c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm6, %xmm0\n"
        "mulss -0x88(%ebp), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x2c(%ebp)\n"
        "movaps %xmm5, %xmm0\n" /* line 304 */
        "mulss -0x84(%ebp), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0x80(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss -0x7c(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* line 140 */
        "subss %xmm4, %xmm2\n" /* line 249 */
        "subss %xmm5, %xmm3\n" /* line 240 */
        "addss -0x24(%ebp), %xmm3\n" /* vOrigin */
        "movss %xmm3, -0x24(%ebp)\n" /* vOrigin */
        "addss -0x20(%ebp), %xmm2\n" /* line 241 */
        "movss %xmm2, -0x20(%ebp)\n"
        "subss %xmm6, %xmm0\n" /* line 242 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* { scope 2 */
        "movl 0x184(%edi), %eax\n" /* line 65 */
        "testl %eax, %eax\n"
        "jne .Lf1b846c_001b8952\n"
        "movw $0x811, %ax\n"
        ".Lf1b846c_001b861f:\n"
        "cmpl $4, 4(%edi)\n" /* line 81 */
        "je .Lf1b846c_001b8b10\n"
        "movl %eax, 0x18(%esp)\n" /* line 84 */
        "movl (%edi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* vOrigin */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x110(%edi), %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "leal 0x104(%edi), %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %edx\n" /* tr */
        "movl %edx, (%esp)\n"
        "calll G_TraceCapsule\n"
        ".Lf1b846c_001b865d:\n"
        "cmpw $0, -0x56(%ebp)\n" /* line 86 */
        "je .Lf1b846c_001b895f\n"
        /* } scope */
        "movzwl -0x5c(%ebp), %edx\n" /* line 175 */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl 0x195f688, %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1b846c_001b895f\n"
        "cvtss2sd 0x110(%edi), %xmm3\n" /* line 193 | check */
        "movsd 0x307ce0, %xmm4\n" /* 0.5 */
        "movapd %xmm3, %xmm0\n"
        "mulsd %xmm4, %xmm0\n"
        "ucomisd 0x307d68, %xmm0\n" /* 4.0 */
        "jbe .Lf1b846c_001b8a9e\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 199 | vOrigin */
        "movss %xmm1, -0xac(%ebp)\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, -0xb0(%ebp)\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 201 */
        "movss %xmm1, -0xb4(%ebp)\n"
        "ucomisd 0x307c80, %xmm0\n" /* line 196 | 0.0 */
        "jbe .Lf1b846c_001b8a9e\n"
        "pxor %xmm6, %xmm6\n"
        "movaps %xmm6, %xmm2\n"
        "movss 0x2ed608, %xmm7\n" /* 4.0f */
        ".Lf1b846c_001b86f3:\n"
        "movaps %xmm6, %xmm0\n" /* line 198 */
        "xorps 0x303230, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n" /* fz */
        "ucomiss %xmm0, %xmm6\n"
        "jb .Lf1b846c_001b8a84\n"
        "movaps %xmm6, %xmm1\n"
        "addss %xmm6, %xmm1\n"
        "movss %xmm1, -0xcc(%ebp)\n"
        ".Lf1b846c_001b871d:\n"
        "movapd %xmm3, %xmm0\n" /* line 200 */
        "mulsd %xmm4, %xmm0\n"
        "ucomisd 0x307d68, %xmm0\n" /* 4.0 */
        "jbe .Lf1b846c_001b8a5c\n"
        "movaps %xmm7, %xmm5\n"
        ".Lf1b846c_001b8736:\n"
        "movaps %xmm5, %xmm0\n" /* line 202 */
        "xorps 0x303230, %xmm0\n"
        "movss %xmm0, -0xc8(%ebp)\n" /* fx */
        "ucomiss %xmm0, %xmm5\n"
        "jb .Lf1b846c_001b8a3e\n"
        "movaps %xmm5, %xmm1\n"
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, -0xd0(%ebp)\n"
        ".Lf1b846c_001b8760:\n"
        "movapd %xmm3, %xmm0\n" /* line 204 */
        "mulsd %xmm4, %xmm0\n"
        "ucomisd 0x307d68, %xmm0\n" /* 4.0 */
        "jbe .Lf1b846c_001b8a1d\n"
        "movaps %xmm7, %xmm2\n"
        ".Lf1b846c_001b8779:\n"
        "movaps %xmm2, %xmm0\n" /* line 206 */
        "xorps 0x303230, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n" /* fy */
        "ucomiss %xmm0, %xmm2\n"
        "jb .Lf1b846c_001b8a03\n"
        "movss -0xc8(%ebp), %xmm1\n" /* fx */
        "addss -0xac(%ebp), %xmm1\n"
        "movss %xmm1, -0xbc(%ebp)\n"
        "movss -0xc0(%ebp), %xmm0\n" /* fz */
        "addss -0xb4(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "movaps %xmm2, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0xd4(%ebp)\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf1b846c_001b8892\n"
        /* { scope 2 */
        ".Lf1b846c_001b87db:\n"
        "movw $0x811, %ax\n" /* line 65 */
        ".Lf1b846c_001b87df:\n"
        "cmpl $4, 4(%edi)\n" /* line 81 */
        "je .Lf1b846c_001b8b71\n"
        "movl %eax, 0x18(%esp)\n" /* line 84 */
        "movl (%edi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* org2 */
        "movl %edx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x78(%ebp), %edx\n" /* tr */
        "movl %edx, (%esp)\n"
        "movss %xmm2, -0xe8(%ebp)\n"
        "movss %xmm5, -0xf8(%ebp)\n"
        "movss %xmm6, -0x108(%ebp)\n"
        "calll G_TraceCapsule\n"
        "movss -0x108(%ebp), %xmm6\n"
        "movss -0xf8(%ebp), %xmm5\n"
        "movss -0xe8(%ebp), %xmm2\n"
        ".Lf1b846c_001b8841:\n"
        "cmpw $0, -0x56(%ebp)\n" /* line 86 */
        "je .Lf1b846c_001b88d4\n"
        /* } scope */
        "movzwl -0x5c(%ebp), %edx\n" /* line 214 */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl 0x195f688, %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1b846c_001b88d4\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 206 | fy */
        "addss -0xd4(%ebp), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n" /* fy */
        "ucomiss %xmm0, %xmm2\n"
        "jb .Lf1b846c_001b89eb\n"
        "movss -0xb8(%ebp), %xmm1\n"
        ".Lf1b846c_001b8892:\n"
        "movss -0xbc(%ebp), %xmm0\n" /* line 240 */
        "movss %xmm0, -0x30(%ebp)\n" /* org2 */
        "movss -0xc4(%ebp), %xmm0\n" /* line 241 | fy */
        "addss -0xb0(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss %xmm1, -0x28(%ebp)\n" /* line 242 */
        /* { scope 2 */
        "movl 0x184(%edi), %eax\n" /* line 65 */
        "testl %eax, %eax\n"
        "je .Lf1b846c_001b87db\n"
        "testb $4, 0x11f(%edi)\n" /* line 67 */
        "je .Lf1b846c_001b87df\n"
        /* } scope */
        ".Lf1b846c_001b88d4:\n"
        "movl 0x7c(%edi), %eax\n" /* line 217 | check */
        "movl 0xc(%ebp), %edx\n" /* pusher */
        "cmpl (%edx), %eax\n"
        "je .Lf1b846c_001b88e5\n"
        "movl $0x3ff, 0x7c(%edi)\n" /* line 218 | check */
        ".Lf1b846c_001b88e5:\n"
        "movl -0x30(%ebp), %ebx\n" /* line 199 | org2 */
        "movl -0xd8(%ebp), %eax\n"
        "movl %ebx, (%eax)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 200 */
        "movl %ecx, 4(%eax)\n"
        "movl -0x28(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%eax)\n"
        "leal 0x18(%edi), %eax\n" /* line 221 | check, to */
        /* { scope 2 */
        "movl %ebx, 0x18(%edi)\n" /* line 199 | check */
        "movl %ecx, 4(%eax)\n" /* line 200 */
        "movl %edx, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl 0x158(%edi), %edx\n" /* line 222 | check */
        "testl %edx, %edx\n"
        "je .Lf1b846c_001b89d4\n"
        "movl 0x14(%ebp), %eax\n" /* line 224 | amove */
        "movss 4(%eax), %xmm0\n"
        "mulss 0x2ed644, %xmm0\n" /* 182.04444885253906f */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x58(%edx)\n"
        "movl 0x158(%edi), %edx\n" /* line 225 | check */
        "leal 0x14(%edx), %ecx\n" /* to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | org2 */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "jmp .Lf1b846c_001b89d4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1b846c_001b8952:\n"
        "testb $4, 0x11f(%edi)\n" /* line 67 */
        "je .Lf1b846c_001b861f\n"
        /* } scope */
        ".Lf1b846c_001b895f:\n"
        "movl 0x7c(%edi), %eax\n" /* line 178 | check */
        "movl 0xc(%ebp), %edx\n" /* pusher */
        "cmpl (%edx), %eax\n"
        "je .Lf1b846c_001b8970\n"
        "movl $0x3ff, 0x7c(%edi)\n" /* line 179 | check */
        ".Lf1b846c_001b8970:\n"
        "movl -0x24(%ebp), %ebx\n" /* line 199 | vOrigin */
        "movl -0xd8(%ebp), %eax\n"
        "movl %ebx, (%eax)\n"
        "movl -0x20(%ebp), %ecx\n" /* line 200 */
        "movl %ecx, 4(%eax)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%eax)\n"
        "leal 0x18(%edi), %eax\n" /* line 182 | check, to */
        /* { scope 2 */
        "movl %ebx, 0x18(%edi)\n" /* line 199 | check */
        "movl %ecx, 4(%eax)\n" /* line 200 */
        "movl %edx, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl 0x158(%edi), %edx\n" /* line 183 | check */
        "testl %edx, %edx\n"
        "je .Lf1b846c_001b89d4\n"
        "movss 0x2ed644, %xmm0\n" /* line 185 | 182.04444885253906f */
        "movl 0x14(%ebp), %eax\n" /* amove */
        "mulss 4(%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x58(%edx)\n"
        "movl 0x158(%edi), %edx\n" /* line 186 | check */
        "leal 0x14(%edx), %ecx\n" /* to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | vOrigin */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lf1b846c_001b89d4:\n"
        "addl $0x20, pushed_p\n" /* line 227 */
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1b846c_001b89e0:\n"
        "addl $0x11c, %esp\n" /* line 253 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b846c_001b89eb:\n"
        "cvtss2sd 0x110(%edi), %xmm3\n" /* check */
        "movsd 0x307ce0, %xmm4\n" /* 0.5 */
        "movss 0x2ed608, %xmm7\n" /* 4.0f */
        /* { scope 1: tr */
        ".Lf1b846c_001b8a03:\n"
        "addss %xmm7, %xmm2\n" /* line 204 */
        "movapd %xmm3, %xmm1\n"
        "mulsd %xmm4, %xmm1\n"
        "cvtss2sd %xmm2, %xmm0\n"
        "ucomisd %xmm0, %xmm1\n"
        "ja .Lf1b846c_001b8779\n"
        ".Lf1b846c_001b8a1d:\n"
        "movss -0xc8(%ebp), %xmm1\n" /* line 202 | fx */
        "addss -0xd0(%ebp), %xmm1\n"
        "movss %xmm1, -0xc8(%ebp)\n" /* fx */
        "ucomiss %xmm1, %xmm5\n"
        "jae .Lf1b846c_001b8760\n"
        ".Lf1b846c_001b8a3e:\n"
        "addss %xmm7, %xmm5\n" /* line 200 */
        "movapd %xmm3, %xmm1\n"
        "mulsd %xmm4, %xmm1\n"
        "cvtss2sd %xmm5, %xmm0\n"
        "ucomisd %xmm0, %xmm1\n"
        "ja .Lf1b846c_001b8736\n"
        "pxor %xmm2, %xmm2\n"
        ".Lf1b846c_001b8a5c:\n"
        "movss -0xc0(%ebp), %xmm0\n" /* line 235 | fz */
        "ucomiss %xmm2, %xmm0\n"
        "jp .Lf1b846c_001b8a6b\n"
        "je .Lf1b846c_001b8a84\n"
        ".Lf1b846c_001b8a6b:\n"
        "addss -0xcc(%ebp), %xmm0\n" /* line 198 */
        "movss %xmm0, -0xc0(%ebp)\n" /* fz */
        "ucomiss %xmm0, %xmm6\n"
        "jae .Lf1b846c_001b871d\n"
        ".Lf1b846c_001b8a84:\n"
        "addss %xmm7, %xmm6\n" /* line 196 */
        "movapd %xmm3, %xmm1\n"
        "mulsd %xmm4, %xmm1\n"
        "cvtss2sd %xmm6, %xmm0\n"
        "ucomisd %xmm0, %xmm1\n"
        "ja .Lf1b846c_001b86f3\n"
        /* { scope 2 */
        ".Lf1b846c_001b8a9e:\n"
        "movl 0x184(%edi), %eax\n" /* line 65 */
        "testl %eax, %eax\n"
        "jne .Lf1b846c_001b8b4d\n"
        "movw $0x811, %ax\n"
        ".Lf1b846c_001b8ab0:\n"
        "cmpl $4, 4(%edi)\n" /* line 81 */
        "je .Lf1b846c_001b8bd2\n"
        "movl %eax, 0x18(%esp)\n" /* line 84 */
        "movl (%edi), %eax\n"
        ".Lf1b846c_001b8ac0:\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0xd8(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %edx\n" /* tr */
        "movl %edx, (%esp)\n"
        "calll G_TraceCapsule\n"
        "cmpw $0, -0x56(%ebp)\n" /* line 86 */
        "je .Lf1b846c_001b8b5a\n"
        /* } scope */
        "movzwl -0x5c(%ebp), %edx\n" /* line 245 */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl 0x195f688, %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1b846c_001b8b5a\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1b846c_001b89e0\n"
        /* { scope 2 */
        ".Lf1b846c_001b8b10:\n"
        "movl %eax, 0x18(%esp)\n" /* line 82 */
        "movl 0x150(%edi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* vOrigin */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x110(%edi), %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "leal 0x104(%edi), %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "jmp .Lf1b846c_001b865d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1b846c_001b8b4d:\n"
        "testb $4, 0x11f(%edi)\n" /* line 67 */
        "je .Lf1b846c_001b8ab0\n"
        /* } scope */
        ".Lf1b846c_001b8b5a:\n"
        "movl $0x3ff, 0x7c(%edi)\n" /* line 247 | check */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 253 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tr */
        /* { scope 2 */
        ".Lf1b846c_001b8b71:\n"
        "movl %eax, 0x18(%esp)\n" /* line 82 */
        "movl 0x150(%edi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* org2 */
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0xe8(%ebp)\n"
        "movss %xmm5, -0xf8(%ebp)\n"
        "movss %xmm6, -0x108(%ebp)\n"
        "calll G_TraceCapsule\n"
        "movss -0xe8(%ebp), %xmm2\n"
        "movss -0xf8(%ebp), %xmm5\n"
        "movss -0x108(%ebp), %xmm6\n"
        "jmp .Lf1b846c_001b8841\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1b846c_001b8bd2:\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x150(%edi), %eax\n"
        "jmp .Lf1b846c_001b8ac0\n"
    );
}

/* line 417 */
__attribute__((naked))
bitread_perm_state G_MoverTeam(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 417 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x212c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1: e, mins, maxs, entityList, ... */
        "movl $0xfdf780, pushed_p\n" /* line 434 */
        "leal 0xc(%edi), %eax\n" /* line 437 | ent */
        "movl %eax, -0x20f8(%ebp)\n"
        "leal -0x3c(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f6a0, %ebx\n" /* p */
        "movl 0x1ec(%ebx), %eax\n" /* p */
        "movl %eax, 4(%esp)\n"
        "movl -0x20f8(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "leal 0x30(%edi), %ecx\n" /* line 438 | ent */
        "movl %ecx, -0x20f4(%ebp)\n"
        "leal -0x48(%ebp), %eax\n" /* angles */
        "movl %eax, 8(%esp)\n"
        "movl 0x1ec(%ebx), %eax\n" /* p */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "leal 0x138(%edi), %eax\n" /* line 439 | ent */
        "movl %eax, -0x20f0(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 248 | origin */
        "subss 0x138(%edi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* move */
        "leal 0x13c(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x20e4(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "subss 0x13c(%edi), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "leal 0x140(%edi), %ecx\n" /* line 250 */
        "movl %ecx, -0x20e0(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n"
        "subss 0x140(%edi), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal 0x144(%edi), %eax\n" /* line 440 | ent */
        "movl %eax, -0x20ec(%ebp)\n"
        "movss -0x48(%ebp), %xmm0\n" /* line 248 | angles */
        "subss 0x144(%edi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* amove */
        "leal 0x148(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x20dc(%ebp)\n"
        "movss -0x44(%ebp), %xmm0\n"
        "subss 0x148(%edi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "leal 0x14c(%edi), %ecx\n" /* line 250 */
        "movl %ecx, -0x20d8(%ebp)\n"
        "movss -0x40(%ebp), %xmm0\n"
        "subss 0x14c(%edi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* { scope 2 */
        "pxor %xmm2, %xmm2\n" /* line 285 */
        "ucomiss 0x144(%edi), %xmm2\n"
        "jne .Lf1b8be2_001b8d1b\n"
        "jp .Lf1b8be2_001b8d1b\n"
        "ucomiss 0x148(%edi), %xmm2\n"
        "je .Lf1b8be2_001b93af\n"
        ".Lf1b8be2_001b8d1b:\n"
        "leal 0x110(%edi), %eax\n" /* line 287 */
        "movl %eax, 4(%esp)\n"
        "leal 0x104(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RadiusFromBounds\n"
        "fstps -0x20fc(%ebp)\n"
        "movss -0x20fc(%ebp), %xmm4\n"
        "movl %edi, %edx\n"
        "movl $1, %ecx\n"
        "leal -0x60(%ebp), %esi\n" /* maxs */
        "leal -0x78(%ebp), %ebx\n" /* totalMaxs */
        ".Lf1b8be2_001b8d4e:\n"
        "movss 0x138(%edx), %xmm2\n" /* line 290 */
        "movaps %xmm2, %xmm3\n"
        "subss %xmm4, %xmm3\n"
        "leal (, %ecx, 4), %eax\n"
        "movss -0x28(%ebp, %eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x58(%ebp, %eax)\n"
        "addss %xmm4, %xmm2\n" /* line 291 */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -4(%esi, %eax)\n"
        "movss %xmm3, -0x70(%ebp, %eax)\n" /* line 292 */
        "movaps %xmm4, %xmm0\n" /* line 293 */
        "addss 0x138(%edx), %xmm0\n"
        "movss %xmm0, -4(%ebx, %eax)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $4, %ecx\n" /* line 288 */
        "jne .Lf1b8be2_001b8d4e\n"
        "pxor %xmm2, %xmm2\n"
        /* { scope 3: tr */
        ".Lf1b8be2_001b8dab:\n"
        "movl $1, %edx\n" /* line 201 */
        /* } scope */
        ".Lf1b8be2_001b8db0:\n"
        "leal (, %edx, 4), %eax\n" /* line 308 */
        "movss -0x28(%ebp, %eax), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf1b8be2_001b939a\n"
        "leal (%ebx, %eax), %eax\n" /* line 417 | to */
        "addss -4(%eax), %xmm0\n" /* line 309 */
        "movss %xmm0, -4(%eax)\n"
        ".Lf1b8be2_001b8dd3:\n"
        "addl $1, %edx\n" /* line 311 */
        "cmpl $4, %edx\n" /* line 306 */
        "jne .Lf1b8be2_001b8db0\n"
        "movl %edi, (%esp)\n" /* line 315 */
        "calll SV_UnlinkEntity\n"
        "movl $0x2000180, 0x10(%esp)\n" /* line 317 */
        "movl $0x400, 0xc(%esp)\n"
        "leal -0x109c(%ebp), %esi\n" /* entityList */
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* totalMins */
        "movl %eax, (%esp)\n"
        "calll CM_AreaEntities\n"
        "movl %eax, -0x20b8(%ebp)\n" /* listedEntities */
        "movl -0x20f0(%ebp), %edx\n" /* line 240 */
        "movss (%edx), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* move */
        "movss %xmm0, (%edx)\n"
        "movl -0x20e4(%ebp), %ecx\n" /* line 241 */
        "movss (%ecx), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movl -0x20e0(%ebp), %eax\n" /* line 242 */
        "movss (%eax), %xmm0\n"
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movl -0x20ec(%ebp), %edx\n" /* line 240 */
        "movss (%edx), %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n" /* amove */
        "movss %xmm0, (%edx)\n"
        "movl -0x20dc(%ebp), %ecx\n" /* line 241 */
        "movss (%ecx), %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movl -0x20d8(%ebp), %eax\n" /* line 242 */
        "movss (%eax), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movl %edi, (%esp)\n" /* line 322 */
        "calll SV_LinkEntity\n"
        "movl -0x20b8(%ebp), %ebx\n" /* line 326 | listedEntities */
        "testl %ebx, %ebx\n"
        "jle .Lf1b8be2_001b9149\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 340 | maxs */
        "movss %xmm0, -0x20d4(%ebp)\n"
        "movss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, -0x20d0(%ebp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "movss %xmm0, -0x20cc(%ebp)\n"
        "movss -0x54(%ebp), %xmm0\n" /* mins */
        "movss %xmm0, -0x20c8(%ebp)\n"
        "movss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, -0x20c4(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, -0x20c0(%ebp)\n"
        "movl $0, -0x20bc(%ebp)\n" /* e */
        "movl $0, -0x20b4(%ebp)\n" /* moveEntities */
        ".Lf1b8be2_001b8f00:\n"
        "movl (%esi), %ecx\n" /* line 328 */
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl 0x195f688, %edx\n"
        "movl 4(%edx), %ebx\n" /* line 331 */
        "leal -3(%ebx), %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf1b8be2_001b8f30\n"
        "cmpl $1, %ebx\n"
        "je .Lf1b8be2_001b8f30\n"
        "cmpb $0, 0x160(%edx)\n"
        "je .Lf1b8be2_001b8f72\n"
        ".Lf1b8be2_001b8f30:\n"
        "movl 0x7c(%edx), %eax\n" /* line 337 */
        "cmpl (%edi), %eax\n"
        "je .Lf1b8be2_001b9363\n"
        "movss 0x120(%edx), %xmm0\n" /* line 340 */
        "ucomiss -0x20d4(%ebp), %xmm0\n"
        "jae .Lf1b8be2_001b8f72\n"
        "movss 0x124(%edx), %xmm0\n"
        "ucomiss -0x20d0(%ebp), %xmm0\n"
        "jae .Lf1b8be2_001b8f72\n"
        "movss 0x128(%edx), %xmm0\n"
        "ucomiss -0x20cc(%ebp), %xmm0\n"
        "jb .Lf1b8be2_001b92a1\n"
        ".Lf1b8be2_001b8f72:\n"
        "addl $1, -0x20bc(%ebp)\n" /* line 326 | e */
        "addl $4, %esi\n"
        "movl -0x20bc(%ebp), %edx\n" /* e */
        "cmpl %edx, -0x20b8(%ebp)\n" /* listedEntities */
        "jne .Lf1b8be2_001b8f00\n"
        ".Lf1b8be2_001b8f8e:\n"
        "movl -0x20b4(%ebp), %ecx\n" /* line 355 | moveEntities */
        "testl %ecx, %ecx\n"
        "jle .Lf1b8be2_001b9149\n"
        "xorl %ebx, %ebx\n"
        ".Lf1b8be2_001b8f9e:\n"
        "movl -0x209c(%ebp, %ebx, 4), %edx\n" /* line 358 */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl 0x195f688, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_UnlinkEntity\n"
        "addl $1, %ebx\n" /* line 355 */
        "cmpl -0x20b4(%ebp), %ebx\n" /* moveEntities */
        "jne .Lf1b8be2_001b8f9e\n"
        "movl $0, -0x20ac(%ebp)\n"
        "movl $0, -0x20e8(%ebp)\n" /* obstacle */
        "movb $1, -0x20ad(%ebp)\n" /* success */
        "jmp .Lf1b8be2_001b902e\n"
        ".Lf1b8be2_001b8fea:\n"
        "cmpl $3, 4(%esi)\n" /* line 382 */
        "je .Lf1b8be2_001b909e\n"
        "cmpl $4, 0xc(%edi)\n" /* line 389 */
        "je .Lf1b8be2_001b94b6\n"
        "cmpl $4, 0x30(%edi)\n"
        "je .Lf1b8be2_001b94b6\n"
        "movl %esi, -0x20e8(%ebp)\n" /* obstacle */
        "movb $0, -0x20ad(%ebp)\n" /* success */
        ".Lf1b8be2_001b9015:\n"
        "addl $1, -0x20ac(%ebp)\n" /* line 361 */
        "movl -0x20b4(%ebp), %ecx\n" /* moveEntities */
        "cmpl %ecx, -0x20ac(%ebp)\n"
        "je .Lf1b8be2_001b90bf\n"
        ".Lf1b8be2_001b902e:\n"
        "movl -0x20ac(%ebp), %ecx\n" /* line 363 */
        "movl -0x209c(%ebp, %ecx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %esi\n"
        "subl %eax, %esi\n"
        "shll $4, %esi\n"
        "addl 0x195f688, %esi\n"
        "movl pushed_p, %edx\n" /* line 366 */
        "movl %esi, (%edx)\n"
        "leal 4(%edx), %ebx\n" /* line 367 | to */
        "leal 0x138(%esi), %ecx\n" /* from */
        /* { scope 3: tr */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, 4(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 368 */
        "movl %eax, 0x1c(%edx)\n"
        "leal -0x30(%ebp), %eax\n" /* line 371 | amove */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* move */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_TryPushingEntity\n"
        "testl %eax, %eax\n"
        "je .Lf1b8be2_001b8fea\n"
        ".Lf1b8be2_001b909e:\n"
        "movl %esi, (%esp)\n" /* line 384 */
        "calll SV_LinkEntity\n"
        "addl $1, -0x20ac(%ebp)\n" /* line 361 */
        "movl -0x20b4(%ebp), %ecx\n" /* moveEntities */
        "cmpl %ecx, -0x20ac(%ebp)\n"
        "jne .Lf1b8be2_001b902e\n"
        ".Lf1b8be2_001b90bf:\n"
        "xorl %ebx, %ebx\n"
        ".Lf1b8be2_001b90c1:\n"
        "movl -0x209c(%ebp, %ebx, 4), %edx\n" /* line 405 */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl 0x195f688, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_LinkEntity\n"
        "addl $1, %ebx\n" /* line 402 | to */
        "cmpl -0x20b4(%ebp), %ebx\n" /* moveEntities, to */
        "jne .Lf1b8be2_001b90c1\n"
        /* } scope */
        "cmpb $0, -0x20ad(%ebp)\n" /* line 442 | success */
        "je .Lf1b8be2_001b9163\n"
        ".Lf1b8be2_001b90f9:\n"
        "movl 0xc(%edi), %edx\n" /* line 481 | ent */
        "testl %edx, %edx\n"
        "jne .Lf1b8be2_001b9476\n"
        ".Lf1b8be2_001b9104:\n"
        "movl 0x30(%edi), %eax\n" /* line 492 | ent */
        "testl %eax, %eax\n"
        "je .Lf1b8be2_001b913e\n"
        "movl 0x34(%edi), %eax\n" /* line 494 | ent */
        "addl 0x38(%edi), %eax\n" /* ent */
        "movl 0x195f6a0, %edx\n"
        "cmpl %eax, 0x1ec(%edx)\n"
        "jl .Lf1b8be2_001b913e\n"
        "movzbl 0x166(%edi), %eax\n" /* line 496 | ent */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 497 */
        "je .Lf1b8be2_001b913e\n"
        "movl %edi, (%esp)\n" /* line 472 | ent */
        "calll *%eax\n"
        /* } scope */
        ".Lf1b8be2_001b913e:\n"
        "addl $0x212c, %esp\n" /* line 501 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: e, mins, maxs, entityList, ... */
        /* { scope 2 */
        ".Lf1b8be2_001b9149:\n"
        "movl $0, -0x20e8(%ebp)\n" /* line 402 | obstacle */
        "movb $1, -0x20ad(%ebp)\n" /* success */
        /* } scope */
        "cmpb $0, -0x20ad(%ebp)\n" /* line 442 | success */
        "jne .Lf1b8be2_001b90f9\n"
        ".Lf1b8be2_001b9163:\n"
        "movl pushed_p, %ebx\n" /* line 447 | p */
        "subl $0x20, %ebx\n" /* p */
        "cmpl $pushed, %ebx\n" /* p */
        "jb .Lf1b8be2_001b91ff\n"
        ".Lf1b8be2_001b9178:\n"
        "movl (%ebx), %esi\n" /* line 449 | p, check */
        "leal 0x138(%esi), %edx\n" /* line 451 | check, to */
        /* { scope 2 */
        "movl 4(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x138(%esi)\n"
        "movl 8(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x18(%esi), %edx\n" /* line 452 | check, to */
        /* { scope 2 */
        "movl 4(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x18(%esi)\n"
        "movl 8(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x158(%esi), %edx\n" /* line 453 | check */
        "testl %edx, %edx\n"
        "je .Lf1b8be2_001b91e8\n"
        "movss 0x1c(%ebx), %xmm0\n" /* line 455 | p */
        "mulss 0x2ed644, %xmm0\n" /* 182.04444885253906f */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "subl %eax, 0x58(%edx)\n"
        "movl 0x158(%esi), %edx\n" /* line 456 | check */
        "leal 0x14(%edx), %ecx\n" /* to */
        /* { scope 2 */
        "movl 4(%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x14(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lf1b8be2_001b91e8:\n"
        "movl %esi, (%esp)\n" /* line 459 | check */
        "calll SV_LinkEntity\n"
        "subl $0x20, %ebx\n" /* line 447 | p */
        "cmpl $pushed, %ebx\n" /* p */
        "jae .Lf1b8be2_001b9178\n"
        ".Lf1b8be2_001b91ff:\n"
        "movl 0x195f6a0, %ebx\n" /* line 463 | p */
        "movl 0x1ec(%ebx), %eax\n" /* p */
        "subl 0x1f0(%ebx), %eax\n" /* p */
        "addl %eax, 0x10(%edi)\n" /* ent */
        "movl 0x1ec(%ebx), %eax\n" /* line 464 | p */
        "subl 0x1f0(%ebx), %eax\n" /* p */
        "addl %eax, 0x34(%edi)\n" /* ent */
        "movl -0x20f0(%ebp), %eax\n" /* line 465 */
        "movl %eax, 8(%esp)\n"
        "movl 0x1ec(%ebx), %eax\n" /* p */
        "movl %eax, 4(%esp)\n"
        "movl -0x20f8(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl -0x20ec(%ebp), %ecx\n" /* line 466 */
        "movl %ecx, 8(%esp)\n"
        "movl 0x1ec(%ebx), %eax\n" /* p */
        "movl %eax, 4(%esp)\n"
        "movl -0x20f4(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "movl %edi, (%esp)\n" /* line 467 | ent */
        "calll SV_LinkEntity\n"
        "movzbl 0x166(%edi), %eax\n" /* line 470 | ent */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 471 */
        "je .Lf1b8be2_001b913e\n"
        "movl -0x20e8(%ebp), %edx\n" /* line 472 | obstacle */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll *%eax\n"
        "jmp .Lf1b8be2_001b913e\n"
        /* { scope 2 */
        ".Lf1b8be2_001b92a1:\n"
        "movss -0x20c8(%ebp), %xmm0\n" /* line 340 */
        "ucomiss 0x12c(%edx), %xmm0\n"
        "jae .Lf1b8be2_001b8f72\n"
        "movss -0x20c4(%ebp), %xmm0\n"
        "ucomiss 0x130(%edx), %xmm0\n"
        "jae .Lf1b8be2_001b8f72\n"
        "movss -0x20c0(%ebp), %xmm0\n"
        "ucomiss 0x134(%edx), %xmm0\n"
        "jae .Lf1b8be2_001b8f72\n"
        "leal 0x138(%edx), %ecx\n" /* line 347 | vOrigin */
        /* { scope 3: tr */
        /* { scope 4 */
        "movl 0x184(%edx), %eax\n" /* line 65 */
        "testl %eax, %eax\n"
        "jne .Lf1b8be2_001b9503\n"
        "movw $0x811, %ax\n"
        ".Lf1b8be2_001b92f8:\n"
        "cmpl $4, %ebx\n" /* line 81 */
        "je .Lf1b8be2_001b9517\n"
        "movl %eax, 0x18(%esp)\n" /* line 84 */
        "movl (%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "leal 0x110(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal 0x104(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x9c(%ebp), %edx\n" /* tr */
        "movl %edx, (%esp)\n"
        "calll G_TraceCapsule\n"
        ".Lf1b8be2_001b9335:\n"
        "cmpw $0, -0x7a(%ebp)\n" /* line 86 */
        "je .Lf1b8be2_001b9510\n"
        "movzwl -0x80(%ebp), %eax\n" /* line 87 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl 0x195f688, %edx\n"
        /* } scope */
        /* } scope */
        ".Lf1b8be2_001b9359:\n"
        "cmpl %edi, %edx\n" /* line 347 | ent */
        "jne .Lf1b8be2_001b8f72\n"
        "movl (%esi), %ecx\n" /* vOrigin */
        ".Lf1b8be2_001b9363:\n"
        "movl -0x20b4(%ebp), %eax\n" /* line 351 | moveEntities */
        "movl %ecx, -0x209c(%ebp, %eax, 4)\n"
        "addl $1, %eax\n"
        "movl %eax, -0x20b4(%ebp)\n" /* moveEntities */
        "addl $1, -0x20bc(%ebp)\n" /* line 326 | e */
        "addl $4, %esi\n"
        "movl -0x20bc(%ebp), %edx\n" /* e */
        "cmpl %edx, -0x20b8(%ebp)\n" /* listedEntities */
        "jne .Lf1b8be2_001b8f00\n"
        "jmp .Lf1b8be2_001b8f8e\n"
        ".Lf1b8be2_001b939a:\n"
        "leal -0x6c(%ebp), %ecx\n" /* line 417 | totalMins */
        "leal (%ecx, %eax), %eax\n"
        "addss -4(%eax), %xmm0\n" /* line 311 */
        "movss %xmm0, -4(%eax)\n"
        "jmp .Lf1b8be2_001b8dd3\n"
        ".Lf1b8be2_001b93af:\n"
        "jp .Lf1b8be2_001b8d1b\n" /* line 285 */
        "ucomiss 0x14c(%edi), %xmm2\n"
        "jne .Lf1b8be2_001b8d1b\n"
        "jp .Lf1b8be2_001b8d1b\n"
        "ucomiss -0x30(%ebp), %xmm2\n" /* amove */
        "jne .Lf1b8be2_001b8d1b\n"
        "jp .Lf1b8be2_001b8d1b\n"
        "ucomiss -0x2c(%ebp), %xmm2\n"
        "jne .Lf1b8be2_001b8d1b\n"
        "jp .Lf1b8be2_001b8d1b\n"
        "ucomiss %xmm2, %xmm0\n"
        "jp .Lf1b8be2_001b8d1b\n"
        "jne .Lf1b8be2_001b8d1b\n"
        "movl %edi, %edx\n" /* line 288 */
        "movl $1, %ecx\n"
        "leal -0x60(%ebp), %esi\n" /* maxs */
        ".Lf1b8be2_001b9401:\n"
        "leal (, %ecx, 4), %eax\n" /* line 300 */
        "movss -0x28(%ebp, %eax), %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "addss 0x120(%edx), %xmm1\n"
        "movss %xmm1, -0x58(%ebp, %eax)\n"
        "addss 0x12c(%edx), %xmm0\n" /* line 301 */
        "movss %xmm0, -4(%esi, %eax)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $4, %ecx\n" /* line 298 */
        "jne .Lf1b8be2_001b9401\n"
        "leal 0x120(%edi), %edx\n"
        /* { scope 3: tr */
        "movl 0x120(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x6c(%ebp)\n" /* totalMins */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x68(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x64(%ebp)\n"
        "leal 0x12c(%edi), %edx\n"
        /* } scope */
        /* { scope 3: tr */
        "movl 0x12c(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x78(%ebp)\n" /* totalMaxs */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x70(%ebp)\n"
        "leal -0x78(%ebp), %ebx\n" /* totalMaxs */
        "jmp .Lf1b8be2_001b8dab\n"
        /* } scope */
        /* } scope */
        ".Lf1b8be2_001b9476:\n"
        "movl 0x10(%edi), %eax\n" /* line 483 | ent */
        "addl 0x14(%edi), %eax\n" /* ent */
        "movl 0x195f6a0, %edx\n"
        "cmpl %eax, 0x1ec(%edx)\n"
        "jl .Lf1b8be2_001b9104\n"
        "movzbl 0x166(%edi), %eax\n" /* line 485 | ent */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n" /* line 486 */
        "je .Lf1b8be2_001b9104\n"
        "movl %edi, (%esp)\n" /* line 487 | ent */
        "calll *%eax\n"
        "jmp .Lf1b8be2_001b9104\n"
        /* { scope 2 */
        ".Lf1b8be2_001b94b6:\n"
        "movl $0, 0x24(%esp)\n" /* line 391 */
        "movl $0, 0x20(%esp)\n"
        "movl $9, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0x1869f, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll G_Damage\n"
        "jmp .Lf1b8be2_001b9015\n"
        /* { scope 3: tr */
        /* { scope 4 */
        ".Lf1b8be2_001b9503:\n"
        "testb $4, 0x11f(%edx)\n" /* line 67 */
        "je .Lf1b8be2_001b92f8\n"
        ".Lf1b8be2_001b9510:\n"
        "xorl %edx, %edx\n" /* line 87 */
        "jmp .Lf1b8be2_001b9359\n"
        ".Lf1b8be2_001b9517:\n"
        "movl %eax, 0x18(%esp)\n" /* line 82 */
        "movl 0x150(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "leal 0x110(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal 0x104(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x9c(%ebp), %eax\n" /* tr */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "jmp .Lf1b8be2_001b9335\n"
    );
}

/* line 510 */
__attribute__((naked))
bitread_perm_state G_RunMover(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 510 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        "movl 0x208(%ebx), %eax\n" /* line 512 | ent */
        "testl %eax, %eax\n"
        "je .Lf1b9554_001b957d\n"
        "movl %ebx, (%esp)\n" /* line 513 | ent */
        "calll G_GeneralLink\n"
        ".Lf1b9554_001b9570:\n"
        "movl %ebx, 8(%ebp)\n" /* line 518 | ent */
        "addl $0x14, %esp\n" /* line 519 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp G_RunThink\n" /* line 518 */
        ".Lf1b9554_001b957d:\n"
        "movl 0xc(%ebx), %eax\n" /* line 514 | ent */
        "testl %eax, %eax\n"
        "jne .Lf1b9554_001b958b\n"
        "movl 0x30(%ebx), %eax\n" /* ent */
        "testl %eax, %eax\n"
        "je .Lf1b9554_001b9570\n"
        ".Lf1b9554_001b958b:\n"
        "movl %ebx, (%esp)\n" /* line 515 | ent */
        "calll G_MoverTeam\n"
        "movl %ebx, 8(%ebp)\n" /* line 518 | ent */
        "addl $0x14, %esp\n" /* line 519 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp G_RunThink\n" /* line 518 */
    );
}

