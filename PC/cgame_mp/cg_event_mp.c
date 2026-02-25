/* ASM dump from: cg_event_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_event_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

void CG_EntityEvent(centity_t *cent, int event);
void CG_CheckEvents(centity_t *cent);

/* line 346 */
__attribute__((naked))
void CG_EntityEvent(centity_t *cent, int event)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 346 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xfc, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* event */
        /* { scope 1: iconWidth, iconShader, targetName, attackerName, ... */
        "testl %edi, %edi\n" /* line 361 | event */
        "jne .Lf1e1f7c_001e1fab\n"
        "movl 0x195f964, %eax\n" /* line 363 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1e1f7c_001e20c1\n"
        /* } scope */
        ".Lf1e1f7c_001e1fa0:\n"
        "addl $0xfc, %esp\n" /* line 862 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iconWidth, iconShader, targetName, attackerName, ... */
        ".Lf1e1f7c_001e1fab:\n"
        "movl 8(%ebp), %eax\n" /* line 368 | cent */
        "addl $0x1ec, %eax\n"
        "movl %eax, -0xc8(%ebp)\n" /* position */
        "movl 8(%ebp), %esi\n" /* line 370 | cent, es */
        "addl $0xf0, %esi\n" /* es */
        "movl 0xa0(%esi), %edx\n" /* line 371 | es */
        "movl %edx, -0xcc(%ebp)\n" /* eventParm */
        "movl 0x195f584, %eax\n" /* line 372 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "jne .Lf1e1f7c_001e2099\n"
        ".Lf1e1f7c_001e1fe5:\n"
        "movb $0, -0xcd(%ebp)\n"
        "movb $0, -0xa9(%ebp)\n"
        ".Lf1e1f7c_001e1ff3:\n"
        "movl 0x195f964, %ebx\n" /* line 374 | clientNum */
        "movl (%ebx), %eax\n" /* clientNum */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1e1f7c_001e21e3\n"
        ".Lf1e1f7c_001e2005:\n"
        "movl 0x90(%esi), %ebx\n" /* line 383 | es, clientNum */
        "cmpl $0x40, %ebx\n" /* line 384 | clientNum */
        "movl $0, %eax\n"
        "cmovael %eax, %ebx\n" /* clientNum */
        "movl 0xc8(%esi), %ecx\n" /* line 387 | es */
        "testl %ecx, %ecx\n"
        "jne .Lf1e1f7c_001e21d6\n"
        ".Lf1e1f7c_001e2024:\n"
        "leal -1(%edi), %edx\n" /* line 389 | event */
        "cmpl $0x16, %edx\n"
        "ja .Lf1e1f7c_001e20d8\n"
        "movl 0x195f960, %eax\n" /* line 391 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1e1f7c_001e2066\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 393 */
        "je .Lf1e1f7c_001e229f\n"
        "movl 0x195f5c4, %eax\n" /* line 394 */
        "movl (%eax), %eax\n"
        "movl 0xbf14(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        ".Lf1e1f7c_001e2066:\n"
        "movl (%esi), %edx\n" /* line 398 | es, entNum */
        /* { scope 2: forward, up */
        "cmpb $0, -0xa9(%ebp)\n" /* line 268 */
        "jne .Lf1e1f7c_001e21b2\n"
        "movl 0x195f5c4, %eax\n" /* line 278 */
        "movl (%eax), %eax\n"
        "movl 0xc198(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        /* } scope */
        /* } scope */
        "addl $0xfc, %esp\n" /* line 862 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iconWidth, iconShader, targetName, attackerName, ... */
        ".Lf1e1f7c_001e2099:\n"
        "movl 8(%ebp), %ecx\n" /* line 372 | cent */
        "movl 0xf0(%ecx), %eax\n"
        "cmpl 0xd8(%edx), %eax\n"
        "jne .Lf1e1f7c_001e1fe5\n"
        "movb $1, -0xcd(%ebp)\n"
        "movb $1, -0xa9(%ebp)\n"
        "jmp .Lf1e1f7c_001e1ff3\n"
        ".Lf1e1f7c_001e20c1:\n"
        "movl $0x2b83c8, (%esp)\n" /* line 364 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0xfc, %esp\n" /* line 862 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iconWidth, iconShader, targetName, attackerName, ... */
        ".Lf1e1f7c_001e20d8:\n"
        "leal -0x18(%edi), %edx\n" /* line 401 | event */
        "cmpl $0x16, %edx\n"
        "jbe .Lf1e1f7c_001e214f\n"
        "leal -0x2f(%edi), %edx\n" /* line 413 | event */
        "cmpl $0x16, %edx\n"
        "ja .Lf1e1f7c_001e2222\n"
        "movl 0x195f960, %eax\n" /* line 415 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1e1f7c_001e2122\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 417 */
        "je .Lf1e1f7c_001e236f\n"
        "movl 0x195f5c4, %eax\n" /* line 418 */
        "movl (%eax), %eax\n"
        "movl 0xc084(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        ".Lf1e1f7c_001e2122:\n"
        "movl (%esi), %edx\n" /* line 422 | es, entNum */
        /* { scope 2: forward, up */
        "cmpb $0, -0xa9(%ebp)\n" /* line 268 */
        "jne .Lf1e1f7c_001e22de\n"
        "movl 0x195f5c4, %eax\n" /* line 280 */
        "movl (%eax), %eax\n"
        "movl 0xc1a0(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        ".Lf1e1f7c_001e214f:\n"
        "movl 0x195f960, %eax\n" /* line 403 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1e1f7c_001e2185\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 405 */
        "jne .Lf1e1f7c_001e22fc\n"
        "movl 0x195f5c4, %eax\n" /* line 408 */
        "movl (%eax), %eax\n"
        "movl 0xbf70(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        ".Lf1e1f7c_001e2185:\n"
        "movl (%esi), %edx\n" /* line 410 | es, entNum */
        /* { scope 2: forward, up */
        "cmpb $0, -0xa9(%ebp)\n" /* line 268 */
        "je .Lf1e1f7c_001e22c0\n"
        "movl 0x195f5c4, %eax\n" /* line 273 */
        "movl (%eax), %eax\n"
        "movl 0xc1a4(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        /* { scope 2: forward, up */
        ".Lf1e1f7c_001e21b2:\n"
        "movl 0x195f5c4, %eax\n" /* line 271 */
        "movl (%eax), %eax\n"
        "movl 0xc19c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        /* } scope */
        /* } scope */
        "addl $0xfc, %esp\n" /* line 862 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: iconWidth, iconShader, targetName, attackerName, ... */
        ".Lf1e1f7c_001e21d6:\n"
        "movl %ecx, (%esp)\n" /* line 387 */
        "calll BG_GetWeaponDef\n"
        "jmp .Lf1e1f7c_001e2024\n"
        ".Lf1e1f7c_001e21e3:\n"
        "movl %edi, 8(%esp)\n" /* line 375 | event */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b83e4, (%esp)\n" /* "ent:%3i  event:%3i " */
        "calll Com_Printf\n"
        "movl (%ebx), %eax\n" /* line 380 | clientNum */
        "cmpb $0, 8(%eax)\n"
        "je .Lf1e1f7c_001e2005\n"
        "movl 0x195f95c, %eax\n" /* line 381 */
        "movl (%eax, %edi, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b83f8, (%esp)\n" /* "CG_EntityEvent:%s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e1f7c_001e2005\n"
        ".Lf1e1f7c_001e2222:\n"
        "leal -0x46(%edi), %edx\n" /* line 425 | event */
        "cmpl $0x16, %edx\n"
        "jbe .Lf1e1f7c_001e231d\n"
        "leal -0x5d(%edi), %edx\n" /* line 434 | event */
        "cmpl $0x16, %edx\n"
        "ja .Lf1e1f7c_001e23cf\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 436 */
        "je .Lf1e1f7c_001e3270\n"
        "movl 0x195f5c4, %eax\n" /* line 437 */
        "movl (%eax), %eax\n"
        "movl 0xc13c(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        ".Lf1e1f7c_001e2263:\n"
        "movl 0x195f584, %eax\n" /* line 440 */
        "movl (%eax), %edx\n"
        "cmpl 0x25c90(%edx), %ebx\n" /* clientNum */
        "jne .Lf1e1f7c_001e1fa0\n"
        "cvtsi2ssl -0xcc(%ebp), %xmm0\n" /* line 443 | eventParm */
        "pxor %xmm1, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x284d8(%edx)\n"
        "movl 0x25bb0(%edx), %eax\n" /* line 444 */
        "movl %eax, 0x284dc(%edx)\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e229f:\n"
        "movl 0x195f5c4, %eax\n" /* line 396 */
        "movl (%eax), %eax\n"
        "movl 0xbeb8(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e2066\n"
        /* { scope 2: forward, up */
        ".Lf1e1f7c_001e22c0:\n"
        "movl 0x195f5c4, %eax\n" /* line 280 */
        "movl (%eax), %eax\n"
        "movl 0xc1a0(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        /* { scope 2: forward, up */
        ".Lf1e1f7c_001e22de:\n"
        "movl 0x195f5c4, %eax\n" /* line 273 */
        "movl (%eax), %eax\n"
        "movl 0xc1a4(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        ".Lf1e1f7c_001e22fc:\n"
        "movl 0x195f5c4, %eax\n" /* line 406 */
        "movl (%eax), %eax\n"
        "movl 0xbfcc(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e2185\n"
        ".Lf1e1f7c_001e231d:\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 427 */
        "je .Lf1e1f7c_001e23ae\n"
        "movl 0x195f5c4, %eax\n" /* line 428 */
        "movl (%eax), %eax\n"
        "movl 0xbf14(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        ".Lf1e1f7c_001e2346:\n"
        "movl (%esi), %edx\n" /* line 431 | es, entNum */
        /* { scope 2: forward, up */
        "cmpb $0, -0xa9(%ebp)\n" /* line 268 */
        "je .Lf1e1f7c_001e2390\n"
        "movl 0x195f5c4, %eax\n" /* line 271 */
        "movl (%eax), %eax\n"
        "movl 0xc19c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        ".Lf1e1f7c_001e236f:\n"
        "movl 0x195f5c4, %eax\n" /* line 420 */
        "movl (%eax), %eax\n"
        "movl 0xc028(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e2122\n"
        /* { scope 2: forward, up */
        ".Lf1e1f7c_001e2390:\n"
        "movl 0x195f5c4, %eax\n" /* line 278 */
        "movl (%eax), %eax\n"
        "movl 0xc198(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        ".Lf1e1f7c_001e23ae:\n"
        "movl 0x195f5c4, %eax\n" /* line 430 */
        "movl (%eax), %eax\n"
        "movl 0xbeb8(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e2346\n"
        ".Lf1e1f7c_001e23cf:\n"
        "leal -0x74(%edi), %edx\n" /* line 448 | event */
        "cmpl $0x16, %edx\n"
        "ja .Lf1e1f7c_001e24ce\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 450 */
        "je .Lf1e1f7c_001e3291\n"
        "movl 0x195f5c4, %eax\n" /* line 451 */
        "movl (%eax), %eax\n"
        "movl 0xc13c(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        ".Lf1e1f7c_001e2404:\n"
        "movl 0x195f5c4, %eax\n" /* line 454 */
        "movl (%eax), %eax\n"
        "movl 0xbc88(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "movl 0x195f584, %edx\n" /* line 455 */
        "movl (%edx), %ecx\n"
        "cmpl 0x25c90(%ecx), %ebx\n" /* clientNum */
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl 0x195ee10, %eax\n" /* line 457 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "cvtsi2ssl -0xcc(%ebp), %xmm2\n" /* eventParm */
        "mulss 0x2ed738, %xmm2\n" /* 0.009999999776482582f */
        "movl 0x195ede4, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "ucomiss 0x2ed79c, %xmm2\n" /* line 460 | 12.0f */
        "jp .Lf1e1f7c_001e2476\n"
        "jbe .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e2476:\n"
        "subss 0x2ed79c, %xmm2\n" /* line 463 | 12.0f */
        "divss 0x2ed7a0, %xmm2\n" /* 26.0f */
        "movss 0x2ed608, %xmm0\n" /* 4.0f */
        "mulss %xmm0, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "cvttss2si %xmm2, %eax\n"
        "cmpl $0x18, %eax\n" /* line 464 */
        "jle .Lf1e1f7c_001e32b2\n"
        "movss 0x2ed8b8, %xmm1\n" /* 24.0f */
        ".Lf1e1f7c_001e24ab:\n"
        "pxor %xmm0, %xmm0\n" /* line 470 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x284d8(%ecx)\n"
        "movl (%edx), %edx\n" /* line 471 */
        "movl 0x25bb0(%edx), %eax\n"
        "movl %eax, 0x284dc(%edx)\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e24ce:\n"
        "leal -0x8b(%edi), %eax\n" /* line 477 | event */
        "cmpl $0x3b, %eax\n"
        "ja .Lf1e1f7c_001e24e0\n"
        "jmpl *0x303be0(, %eax, 4)\n"
        ".Lf1e1f7c_001e24e0:\n"
        "movl 0x195f95c, %eax\n" /* line 859 */
        "movl (%eax, %edi, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2b84e8, 4(%esp)\n" /* "Unknown event: '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f584, %eax\n" /* line 799 */
        "movl (%eax), %eax\n"
        "movl $1, 0x2bee8(%eax)\n"
        "leal -0x28(%ebp), %edi\n" /* line 803 | dir, event */
        "movl %edi, 4(%esp)\n" /* event */
        "movl 0xa0(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll ByteToDir\n"
        "movl 0x195f5c4, %eax\n" /* line 804 */
        "movl (%eax), %ebx\n" /* index */
        "movl 0x88(%esi), %eax\n" /* es */
        "movl 0xbd48(%ebx, %eax, 4), %eax\n" /* index */
        "movl %eax, 8(%esp)\n"
        "movl -0xc8(%ebp), %eax\n" /* position */
        "movl %eax, 4(%esp)\n"
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "movl 0xc200(%ebx), %eax\n" /* line 805 | index */
        "movl 4(%eax), %edx\n"
        "movl 0x88(%esi), %eax\n" /* es */
        "movl 0x398(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e2589\n"
        "movl %edi, 8(%esp)\n" /* line 806 | event */
        "movl -0xc8(%ebp), %edx\n" /* position */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FX_PlayEffect\n"
        ".Lf1e1f7c_001e2589:\n"
        "movl 0xc8(%esi), %ecx\n" /* line 808 | es */
        "movl 0x195f5c8, %eax\n"
        "movl (%eax), %ebx\n" /* index */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x164(%ebx, %eax, 4), %eax\n" /* index */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e25c6\n"
        "movl %edi, 8(%esp)\n" /* line 809 | event */
        "movl -0xc8(%ebp), %ecx\n" /* position */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FX_PlayEffect\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        ".Lf1e1f7c_001e25c6:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 810 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x168(%ebx, %eax, 4), %eax\n" /* index */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e25f4\n"
        "movl %eax, 8(%esp)\n" /* line 811 */
        "movl -0xc8(%ebp), %eax\n" /* position */
        "movl %eax, 4(%esp)\n"
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        ".Lf1e1f7c_001e25f4:\n"
        "movl 0x195f584, %eax\n" /* line 812 */
        "movl (%eax), %eax\n"
        "movl $0, 0x2bee8(%eax)\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f5c4, %eax\n" /* line 484 */
        "movl (%eax), %eax\n"
        "movl 0xc1a8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f584, %eax\n" /* line 489 */
        "movl (%eax), %eax\n"
        "cmpl 0x25c90(%eax), %ebx\n" /* clientNum */
        "jne .Lf1e1f7c_001e3437\n"
        "movl 0x195ecb4, %eax\n" /* line 492 */
        "movl (%eax), %eax\n"
        "movl 0xc(%eax), %ebx\n" /* clientNum */
        "testl %ebx, %ebx\n" /* clientNum */
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl $0, 8(%eax)\n" /* line 493 */
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f584, %eax\n" /* line 498 */
        "movl (%eax), %eax\n"
        "cmpl 0x25c90(%eax), %ebx\n" /* clientNum */
        "jne .Lf1e1f7c_001e345b\n"
        "movl 0x195ecb4, %eax\n" /* line 501 */
        "movl (%eax), %eax\n"
        "movl 0xc(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl $1, 8(%eax)\n" /* line 502 */
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f584, %eax\n" /* line 507 */
        "movl (%eax), %eax\n"
        "cmpl 0x25c90(%eax), %ebx\n" /* clientNum */
        "jne .Lf1e1f7c_001e3531\n"
        "movl 0x195ecb4, %eax\n" /* line 510 */
        "movl (%eax), %eax\n"
        "movl 0xc(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl $2, 8(%eax)\n" /* line 511 */
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f584, %eax\n" /* line 620 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl (%esi), %eax\n" /* es */
        "cmpl 0xd8(%edx), %eax\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl $4, (%esp)\n" /* line 622 */
        "calll CG_MenuShowNotify\n"
        "calll CG_SwitchOffHandCmd\n" /* line 623 */
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        "movl 0xa0(%esi), %ebx\n" /* line 552 | es, index */
        "testl %ebx, %ebx\n" /* line 553 | index */
        "jle .Lf1e1f7c_001e1fa0\n"
        "movl 0x195edac, %eax\n"
        "cmpl (%eax), %ebx\n" /* index */
        "jge .Lf1e1f7c_001e1fa0\n"
        "leal (%ebx, %ebx, 8), %eax\n" /* line 556 | index */
        "movl 0x195f5d0, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "cmpl $0x90, %edi\n" /* line 558 | event */
        "je .Lf1e1f7c_001e34f7\n"
        "cmpl $0x91, %edi\n" /* line 560 | event */
        "jne .Lf1e1f7c_001e2746\n"
        "movl 0x20(%eax), %eax\n" /* line 561 */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        ".Lf1e1f7c_001e2746:\n"
        "movl 0x195f584, %eax\n" /* line 564 */
        "movl (%eax), %edi\n" /* event */
        "movl 0x24(%edi), %edx\n" /* event */
        "testl $0xc00000, 0x18(%edx)\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl (%esi), %eax\n" /* es */
        "cmpl 0xd8(%edx), %eax\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        /* { scope 3 */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 237 | itemid */
        "leal (%ebx, %eax, 2), %eax\n" /* itemid */
        "shll $2, %eax\n"
        "addl 0x195eda8, %eax\n"
        "movl 0x20(%eax), %ebx\n" /* itemid */
        "cmpl $1, 0x1c(%eax)\n" /* line 240 */
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl %ebx, (%esp)\n" /* line 242 | itemid */
        "calll BG_GetWeaponDef\n"
        "cmpl $9, 0x7c(%eax)\n" /* line 244 */
        "je .Lf1e1f7c_001e1fa0\n"
        "movl 0x84(%eax), %eax\n" /* line 247 */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e3555\n"
        "movl 0x2be70(%edi), %eax\n" /* line 249 | attacker */
        "testl %eax, %eax\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl %ebx, (%esp)\n" /* line 250 | itemid */
        "calll CG_SetEquippedOffHand\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        /* } scope */
        "movl 0xc8(%esi), %eax\n" /* line 613 | es */
        "movl %eax, (%esp)\n"
        "calll BG_WeaponIsClipOnly\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e347f\n"
        ".Lf1e1f7c_001e27d8:\n"
        "movl 0x195f584, %eax\n" /* line 615 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl (%esi), %eax\n" /* es */
        "cmpl 0xd8(%edx), %eax\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "calll CG_OutOfAmmoChange\n" /* line 616 */
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        "movl 0x195f584, %edx\n" /* line 520 */
        "movl (%edx), %esi\n" /* es */
        "cmpl 0x25c90(%esi), %ebx\n" /* es, clientNum */
        "jne .Lf1e1f7c_001e350d\n"
        "movl 8(%esi), %eax\n" /* line 523 | es */
        "testl %eax, %eax\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f788, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f78c, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl 0x25bb0(%esi), %ecx\n" /* line 528 | es */
        "subl 0x284d4(%esi), %ecx\n" /* es */
        "pxor %xmm2, %xmm2\n" /* line 529 */
        "cmpl $0x63, %ecx\n"
        "jg .Lf1e1f7c_001e2880\n"
        "movl $0x64, %eax\n" /* line 530 */
        "subl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "mulss 0x284d0(%esi), %xmm2\n" /* es */
        "divss 0x2ed798, %xmm2\n" /* 100.0f */
        "mulss 0x2ed7b8, %xmm2\n" /* 0.8999999761581421f */
        ".Lf1e1f7c_001e2880:\n"
        "movl -0xcc(%ebp), %eax\n" /* line 536 | eventParm */
        "addl $-0x80, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, 0x284d0(%esi)\n" /* es */
        "movl (%edx), %ecx\n" /* line 537 */
        "movss 0x284d0(%ecx), %xmm0\n"
        "ucomiss 0x2ed8b8, %xmm0\n" /* 24.0f */
        "jbe .Lf1e1f7c_001e336e\n"
        "movl $0x41c00000, 0x284d0(%ecx)\n" /* line 538 */
        ".Lf1e1f7c_001e28ba:\n"
        "movl (%edx), %edx\n" /* line 542 */
        "movl 0x25bb0(%edx), %eax\n"
        "movl %eax, 0x284d4(%edx)\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        "cmpb $0, -0xcd(%ebp)\n" /* line 576 */
        "je .Lf1e1f7c_001e33fc\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x195f5c8, %ebx\n" /* index */
        "movl (%ebx), %edx\n" /* index */
        "leal (%edx, %eax, 4), %edx\n"
        "movl 0xfc(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e33df\n"
        "movl %eax, 4(%esp)\n" /* line 577 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f584, %eax\n" /* line 629 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl (%esi), %eax\n" /* es */
        "cmpl 0xd8(%edx), %eax\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl $0, (%esp)\n" /* line 630 */
        "calll CL_SetADS\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 587 */
        "je .Lf1e1f7c_001e34bc\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x195f5c8, %ebx\n" /* index */
        "movl (%ebx), %edx\n" /* index */
        "leal (%edx, %eax, 4), %edx\n"
        "movl 0x104(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e349f\n"
        "movl %eax, 4(%esp)\n" /* line 588 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "leal -0x28(%ebp), %edi\n" /* line 781 | dir, event */
        "movl %edi, 4(%esp)\n" /* event */
        "movl 0xa0(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll ByteToDir\n"
        "movl 0xc8(%esi), %ecx\n" /* line 783 | es */
        "movl 0x195f5c8, %eax\n"
        "movl (%eax), %ebx\n" /* index */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x164(%ebx, %eax, 4), %eax\n" /* index */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e2a1b\n"
        "movl 0x54(%esi), %eax\n" /* line 786 | es */
        "movl %eax, (%esp)\n"
        "calll FX_WarpTime\n"
        "movl %edi, 8(%esp)\n" /* line 787 | event */
        "movl -0xc8(%ebp), %edx\n" /* position */
        "movl %edx, 4(%esp)\n"
        "movl 0xc8(%esi), %edx\n" /* es */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x164(%ebx, %eax, 4), %eax\n" /* index */
        "movl %eax, (%esp)\n"
        "calll FX_PlayEffect\n"
        "movl 0x195f584, %eax\n" /* line 789 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_WarpTime\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        ".Lf1e1f7c_001e2a1b:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 791 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x168(%ebx, %eax, 4), %edx\n" /* index */
        "testl %edx, %edx\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "testb $1, 0xa(%esi)\n" /* line 793 | es */
        "je .Lf1e1f7c_001e2a52\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x54(%esi), %eax\n" /* es */
        "cmpl $0x31, %eax\n"
        "jg .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e2a52:\n"
        "movl %edx, 8(%esp)\n" /* line 794 */
        "movl -0xc8(%ebp), %ecx\n" /* position */
        "movl %ecx, 4(%esp)\n"
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        "leal 0x3c(%esi), %ecx\n" /* line 219 */
        /* } scope */
        /* { scope 2: forward, up */
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 292 | cent */
        "movl 0x190(%eax), %edx\n"
        "leal -1(%edx), %eax\n" /* line 293 */
        "cmpl $0x3e, %eax\n"
        "jbe .Lf1e1f7c_001e3391\n"
        "movl %edx, 4(%esp)\n" /* line 295 */
        "movl $0x2abd90, (%esp)\n" /* "ERROR: CG_PlayFx called with invalid effect id %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        /* } scope */
        "cmpb $0, -0xcd(%ebp)\n" /* line 598 */
        "je .Lf1e1f7c_001e32fc\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "movl 0x195f5c8, %ebx\n" /* index */
        "movl (%ebx), %edx\n" /* index */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x10c(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e3308\n"
        "movl %eax, 4(%esp)\n" /* line 599 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl $0, 8(%esp)\n" /* line 651 */
        "movl $0xb0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll CG_FireWeapon\n"
        "movl $1, 8(%esp)\n" /* line 652 */
        "movl $0xb0, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cent */
        "movl %edx, (%esp)\n"
        "calll CG_FireWeapon\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl $2, 8(%esp)\n" /* line 656 */
        "movl $0xb1, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cent */
        "movl %ecx, (%esp)\n"
        "calll CG_FireWeapon\n"
        "movl $3, 8(%esp)\n" /* line 657 */
        "movl $0xb1, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll CG_FireWeapon\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl $0xa2, 4(%esp)\n" /* line 692 */
        "movl %esi, (%esp)\n" /* es */
        "calll CG_EjectWeaponBrass\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0xc8(%esi), %edx\n" /* line 696 | es */
        "movl 0x195f5c8, %eax\n"
        "movl (%eax), %ecx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0xec(%ecx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 697 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0xa0(%esi), %eax\n" /* line 704 | es */
        "movl %eax, 8(%esp)\n"
        "movl $0xa5, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* es */
        "calll CG_PrepOffHand\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0xa0(%esi), %eax\n" /* line 708 | es */
        "movl %eax, 8(%esp)\n"
        "movl $0xa6, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cent */
        "movl %ecx, (%esp)\n"
        "calll CG_UseOffHand\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 712 */
        "je .Lf1e1f7c_001e1fa0\n"
        "movl 0xa0(%esi), %eax\n" /* line 713 | es */
        "movl %eax, (%esp)\n"
        "calll CG_SetEquippedOffHand\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f5c4, %eax\n" /* line 724 */
        "movl (%eax), %eax\n"
        "movl 0xc1b8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x74(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f5c4, %eax\n" /* line 728 */
        "movl (%eax), %eax\n"
        "movl 0xc1bc(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0xc8(%ebp), %eax\n" /* position */
        "movl %eax, 4(%esp)\n"
        "movl 0x74(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        "movl $0x42c80000, 0xc(%esp)\n" /* line 664 */
        "movl -0xc8(%ebp), %edx\n" /* position */
        "movl %edx, 8(%esp)\n"
        "movl $0x64, 4(%esp)\n"
        "movl $0x3d4ccccd, (%esp)\n"
        "calll CG_StartShakeCamera\n"
        "movl $0, 8(%esp)\n" /* line 665 */
        "movl $0xaf, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cent */
        "movl %ecx, (%esp)\n"
        "calll CG_FireWeapon\n"
        "movl -0xcc(%ebp), %eax\n" /* line 667 | eventParm */
        "shll $4, %eax\n"
        "addl -0xcc(%ebp), %eax\n" /* eventParm */
        "movl -0xcc(%ebp), %edx\n" /* eventParm */
        "leal (%edx, %eax, 8), %eax\n"
        "movl 0x195f5cc, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %edx\n"
        "cmpb $0, 0x1e0(%edx)\n" /* line 668 */
        "je .Lf1e1f7c_001e1fa0\n"
        "cmpl $1, 0xf4(%edx)\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "movl 0x5a0(%eax), %eax\n"
        "movl 8(%ebp), %ecx\n" /* cent */
        "cmpl 0xf0(%ecx), %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl $0x32, 8(%esp)\n" /* line 669 */
        "movl -0xc8(%ebp), %eax\n" /* position */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_CompassAddWeaponPingInfo\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        "movl 0xc8(%esi), %edx\n" /* line 646 | es */
        "movl 0x195f5c8, %eax\n"
        "movl (%eax), %ecx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x11c(%ecx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 647 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0xc8(%esi), %edx\n" /* line 674 | es */
        "movl 0x195f5c8, %eax\n"
        "movl (%eax), %ecx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0xd8(%ecx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 675 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl $0, 8(%esp)\n" /* line 681 */
        "movl %edi, 4(%esp)\n" /* event */
        "movl 8(%ebp), %edx\n" /* cent */
        "movl %edx, (%esp)\n"
        "calll CG_FireWeapon\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 685 */
        "je .Lf1e1f7c_001e3335\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "movl 0x195f5c8, %ebx\n" /* index */
        "movl (%ebx), %edx\n" /* index */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0xf4(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e3341\n"
        "movl %eax, 4(%esp)\n" /* line 686 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0xc8(%esi), %edx\n" /* line 634 | es */
        "movl 0x195f5c8, %eax\n"
        "movl (%eax), %ecx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x118(%ecx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 635 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0xc8(%esi), %edx\n" /* line 640 | es */
        "movl 0x195f5c8, %eax\n"
        "movl (%eax), %ecx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x120(%ecx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 641 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "cmpb $0, -0xcd(%ebp)\n" /* line 605 */
        "je .Lf1e1f7c_001e32c3\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "movl 0x195f5c8, %ebx\n" /* index */
        "movl (%ebx), %edx\n" /* index */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x114(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e32cf\n"
        "movl %eax, 4(%esp)\n" /* line 606 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        "movl 0xa0(%esi), %eax\n" /* line 317 */
        "addl $0x38e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl 0x195f5c4, %edx\n" /* line 323 */
        "movl (%edx), %ebx\n" /* fx */
        "movsbl (%eax), %edx\n"
        "movsbl 1(%eax), %ecx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "movl 0x5f80(%ebx, %edx, 4), %ebx\n" /* fx */
        "movl 8(%ebp), %ecx\n" /* line 325 | cent */
        "movl 0xf0(%ecx), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* attackerColor */
        "movl $0, 4(%esp)\n" /* line 326 */
        "addl $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_GetString\n"
        "movw %ax, -0x1a(%ebp)\n" /* tagName */
        "movzwl %ax, %eax\n" /* line 327 */
        "movl %eax, 4(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* attackerColor */
        "movl %eax, (%esp)\n"
        "calll FX_GetBoneIndex\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl $0, 4(%esp)\n" /* line 328 */
        "leal -0x1a(%ebp), %eax\n" /* tagName */
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl -0x50(%ebp), %eax\n" /* line 329 */
        "testl %eax, %eax\n"
        "js .Lf1e1f7c_001e1fa0\n"
        "leal -0x54(%ebp), %eax\n" /* line 332 | attackerColor */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl -0xc8(%ebp), %eax\n" /* position */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* fx */
        "calll FX_PlayEntityEffect\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        "movl 0x6c(%esi), %eax\n" /* line 837 | es */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xc8(%ebp), %edx\n" /* position */
        "movl %edx, 8(%esp)\n"
        "movl 0x54(%esi), %eax\n" /* es */
        "movl %eax, 4(%esp)\n"
        "movl 0x68(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_StartShakeCamera\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "leal -0x28(%ebp), %ebx\n" /* line 747 | dir, index */
        "movl %ebx, 4(%esp)\n" /* index */
        "movl 0xa0(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll ByteToDir\n"
        "leal -0x34(%ebp), %eax\n" /* line 748 | reflect */
        "movl %eax, 4(%esp)\n"
        "movl 0xd8(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll ByteToDir\n"
        "movl %edi, 0x14(%esp)\n" /* line 749 | event */
        "movl 0x88(%esi), %eax\n" /* es */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x34(%ebp), %edx\n" /* reflect */
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* index */
        "movl -0xc8(%ebp), %ecx\n" /* position */
        "movl %ecx, 4(%esp)\n"
        "movl 0x74(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_BulletHitEvent\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl %edi, 0xc(%esp)\n" /* line 754 | event */
        "movl 0x88(%esi), %eax\n" /* es */
        "movl %eax, 8(%esp)\n"
        "movl -0xc8(%ebp), %eax\n" /* position */
        "movl %eax, 4(%esp)\n"
        "movl 0x74(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_BulletHitClientEvent\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "leal -0x28(%ebp), %edi\n" /* line 759 | dir, event */
        "movl %edi, 4(%esp)\n" /* event */
        "movl 0xa0(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll ByteToDir\n"
        "movl 0x195f5c4, %eax\n" /* line 760 */
        "movl (%eax), %ebx\n" /* index */
        "movl 0x88(%esi), %eax\n" /* es */
        "movl 0xbc90(%ebx, %eax, 4), %eax\n" /* index */
        "movl %eax, 8(%esp)\n"
        "movl -0xc8(%ebp), %edx\n" /* position */
        "movl %edx, 4(%esp)\n"
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "movl 0xc200(%ebx), %eax\n" /* line 761 | index */
        "movl 4(%eax), %edx\n"
        "movl 0x88(%esi), %eax\n" /* es */
        "movl 0x2e0(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %edi, 8(%esp)\n" /* line 762 | event */
        "movl -0xc8(%ebp), %ecx\n" /* position */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FX_PlayEffect\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "leal -0x28(%ebp), %edi\n" /* line 767 | dir, event */
        "movl %edi, 4(%esp)\n" /* event */
        "movl 0xa0(%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll ByteToDir\n"
        "movl 0x195f5c4, %eax\n" /* line 768 */
        "movl (%eax), %ebx\n" /* index */
        "movl 0x88(%esi), %eax\n" /* es */
        "movl 0xbcec(%ebx, %eax, 4), %eax\n" /* index */
        "movl %eax, 8(%esp)\n"
        "movl -0xc8(%ebp), %eax\n" /* position */
        "movl %eax, 4(%esp)\n"
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "movl 0xc200(%ebx), %eax\n" /* line 770 | index */
        "movl 4(%eax), %edx\n"
        "movl 0x88(%esi), %eax\n" /* es */
        "movl 0x33c(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e30df\n"
        "movl %edi, 8(%esp)\n" /* line 771 | event */
        "movl -0xc8(%ebp), %edx\n" /* position */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FX_PlayEffect\n"
        ".Lf1e1f7c_001e30df:\n"
        "movl 0xc8(%esi), %ecx\n" /* line 773 | es */
        "movl 0x195f5c8, %eax\n"
        "movl (%eax), %ebx\n" /* index */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x164(%ebx, %eax, 4), %eax\n" /* index */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e311c\n"
        "movl %edi, 8(%esp)\n" /* line 774 | event */
        "movl -0xc8(%ebp), %ecx\n" /* position */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FX_PlayEffect\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        ".Lf1e1f7c_001e311c:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 776 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x168(%ebx, %eax, 4), %eax\n" /* index */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 8(%esp)\n" /* line 777 */
        "movl -0xc8(%ebp), %eax\n" /* position */
        "movl %eax, 4(%esp)\n"
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0xa0(%esi), %eax\n" /* line 816 | es */
        "addl $0x24e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x18(%esi), %eax\n" /* es */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundAliasByName\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movl 0xa0(%esi), %eax\n" /* line 819 | es */
        "addl $0x24e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x18(%esi), %eax\n" /* es */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlaySoundAliasAsMasterByName\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, -0x28(%ebp)\n" /* dir */
        "movl %eax, -0x24(%ebp)\n" /* line 192 */
        "movl $0x3f800000, -0x20(%ebp)\n" /* line 193 */
        "movl 0x195f5c4, %eax\n" /* line 733 */
        "movl (%eax), %ebx\n" /* index */
        "movl 0xbcec(%ebx), %eax\n" /* index */
        "movl %eax, 8(%esp)\n"
        "movl -0xc8(%ebp), %edx\n" /* position */
        "movl %edx, 4(%esp)\n"
        "movl $0x3fe, (%esp)\n"
        "calll CG_PlaySoundAlias\n"
        "movl 0xc200(%ebx), %eax\n" /* line 734 | index */
        "movl 4(%eax), %eax\n"
        "movl 0x33c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "leal -0x28(%ebp), %eax\n" /* line 735 | dir */
        "movl %eax, 8(%esp)\n"
        "movl -0xc8(%ebp), %ecx\n" /* position */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FX_PlayEffect\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        "movl $0x3f800000, %eax\n" /* line 40 */
        "movl %eax, -0x54(%ebp)\n" /* attackerColor */
        "movl %eax, -0x50(%ebp)\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl %eax, -0x64(%ebp)\n" /* line 41 | victimColor */
        "movl %eax, -0x60(%ebp)\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl %eax, -0x44(%ebp)\n" /* line 42 | iconColor */
        "movl %eax, -0x40(%ebp)\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x74(%esi), %edx\n" /* line 50 */
        "movl %edx, -0xb0(%ebp)\n" /* target */
        "movl 0x78(%esi), %edi\n" /* line 51 | attacker */
        "movl 0xa0(%esi), %eax\n" /* line 87 */
        "testb %al, %al\n"
        "jns .Lf1e1f7c_001e3938\n"
        "andb $0x7f, %al\n" /* line 116 */
        "subl $7, %eax\n"
        "cmpl $5, %eax\n"
        "ja .Lf1e1f7c_001e3912\n"
        "jmpl *0x303cd0(, %eax, 4)\n"
        /* } scope */
        ".Lf1e1f7c_001e3270:\n"
        "movl 0x195f5c4, %eax\n" /* line 439 */
        "movl (%eax), %eax\n"
        "movl 0xc0e0(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e2263\n"
        ".Lf1e1f7c_001e3291:\n"
        "movl 0x195f5c4, %eax\n" /* line 453 */
        "movl (%eax), %eax\n"
        "movl 0xc0e0(%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e2404\n"
        ".Lf1e1f7c_001e32b2:\n"
        "testl %eax, %eax\n" /* line 467 */
        "jle .Lf1e1f7c_001e1fa0\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "jmp .Lf1e1f7c_001e24ab\n"
        ".Lf1e1f7c_001e32c3:\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "movl 0x195f5c8, %ebx\n" /* clientNum */
        ".Lf1e1f7c_001e32cf:\n"
        "movl (%ebx), %edx\n" /* line 607 | index */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x110(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 608 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e32fc:\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "movl 0x195f5c8, %ebx\n" /* index */
        ".Lf1e1f7c_001e3308:\n"
        "movl (%ebx), %edx\n" /* line 600 | index */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0x108(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 601 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e3335:\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "movl 0x195f5c8, %ebx\n" /* index */
        ".Lf1e1f7c_001e3341:\n"
        "movl (%ebx), %edx\n" /* line 687 | index */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl 0xf0(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 688 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        ".Lf1e1f7c_001e336e:\n"
        "ucomiss 0x2eda74, %xmm0\n" /* line 539 | -16.0f */
        "jae .Lf1e1f7c_001e28ba\n"
        "jp .Lf1e1f7c_001e28ba\n"
        "movl $0xc1800000, %eax\n" /* line 540 */
        "movl %eax, 0x284d0(%ecx)\n"
        "jmp .Lf1e1f7c_001e28ba\n"
        /* } scope */
        /* { scope 2: forward, up */
        /* { scope 3 */
        ".Lf1e1f7c_001e3391:\n"
        "movl 0x195f5c4, %eax\n" /* line 298 */
        "movl (%eax), %eax\n"
        "movl 0x67c0(%eax, %edx, 4), %edi\n" /* fx */
        "leal -0x44(%ebp), %edx\n" /* line 300 | iconColor */
        "movl %edx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "leal -0x54(%ebp), %ebx\n" /* attackerColor, itemid */
        "movl %ebx, 4(%esp)\n" /* itemid */
        "movl %ecx, (%esp)\n"
        "calll AngleVectors\n"
        "leal -0x44(%ebp), %ecx\n" /* line 301 | iconColor */
        "movl %ecx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* itemid */
        "movl -0xc8(%ebp), %eax\n" /* position */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* fx */
        "calll FX_PlayEffect\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        /* } scope */
        ".Lf1e1f7c_001e33df:\n"
        "movl 0x104(%edx), %eax\n" /* line 578 */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e3408\n"
        "movl %eax, 4(%esp)\n" /* line 579 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e33fc:\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "movl 0x195f5c8, %ebx\n" /* index */
        ".Lf1e1f7c_001e3408:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 580 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl (%ebx), %edx\n" /* index */
        "leal (%edx, %eax, 4), %edx\n"
        "movl 0xf8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e39cf\n"
        "movl %eax, 4(%esp)\n" /* line 581 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e3437:\n"
        "movl %ebx, 8(%esp)\n" /* line 489 | clientNum */
        "movl 0x195f95c, %eax\n"
        "movl 0x230(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b840c, (%esp)\n" /* "Event %s just for client %i was sent to other clients
" */
        "calll Com_DPrintf\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e345b:\n"
        "movl %ebx, 8(%esp)\n" /* line 498 | clientNum */
        "movl 0x195f95c, %eax\n"
        "movl 0x234(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b840c, (%esp)\n" /* "Event %s just for client %i was sent to other clients
" */
        "calll Com_DPrintf\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e347f:\n"
        "movl 0x195f5c4, %eax\n" /* line 614 */
        "movl (%eax), %eax\n"
        "movl 0xbc84(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e27d8\n"
        ".Lf1e1f7c_001e349f:\n"
        "movl 0xfc(%edx), %eax\n" /* line 589 */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e34c8\n"
        "movl %eax, 4(%esp)\n" /* line 590 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        ".Lf1e1f7c_001e34bc:\n"
        "movl 0xc8(%esi), %ecx\n" /* es */
        "movl 0x195f5c8, %ebx\n" /* index */
        ".Lf1e1f7c_001e34c8:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 591 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl (%ebx), %edx\n" /* index */
        "leal (%edx, %eax, 4), %edx\n"
        "movl 0x100(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e3570\n"
        "movl %eax, 4(%esp)\n" /* line 592 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        ".Lf1e1f7c_001e34f7:\n"
        "movl 0x1c(%eax), %eax\n" /* line 559 */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e2746\n"
        /* } scope */
        /* { scope 2: forward, up */
        ".Lf1e1f7c_001e350d:\n"
        "movl %ebx, 8(%esp)\n" /* line 520 | clientNum */
        "movl 0x195f95c, %eax\n"
        "movl 0x23c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b840c, (%esp)\n" /* "Event %s just for client %i was sent to other clients
" */
        "calll Com_DPrintf\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        ".Lf1e1f7c_001e3531:\n"
        "movl %ebx, 8(%esp)\n" /* line 507 | clientNum */
        "movl 0x195f95c, %eax\n"
        "movl 0x238(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b840c, (%esp)\n" /* "Event %s just for client %i was sent to other clients
" */
        "calll Com_DPrintf\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        /* { scope 3 */
        ".Lf1e1f7c_001e3555:\n"
        "movl 0x2be50(%edi), %eax\n" /* line 254 | attacker */
        "testl %eax, %eax\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl %ebx, (%esp)\n" /* line 255 | itemid */
        "calll CG_SelectWeaponIndex\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* } scope */
        /* } scope */
        ".Lf1e1f7c_001e3570:\n"
        "movl 0xf8(%edx), %eax\n" /* line 593 */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 594 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        "movss 0x2eda90, %xmm0\n" /* line 129 | 1.399999976158142f */
        "movss %xmm0, -0xc4(%ebp)\n" /* iconWidth */
        "movl $0x2a761c, -0xc0(%ebp)\n" /* iconShader */
        "movb $0, -0xb1(%ebp)\n" /* iconHorzFlip */
        ".Lf1e1f7c_001e35b2:\n"
        "cmpl $0x3f, -0xb0(%ebp)\n" /* line 144 | target */
        "ja .Lf1e1f7c_001e38f9\n"
        ".Lf1e1f7c_001e35bf:\n"
        "movl -0xb0(%ebp), %edx\n" /* line 146 | target */
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "movl -0xb0(%ebp), %ecx\n" /* target */
        "leal (%ecx, %edx, 2), %edx\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %ebx\n"
        "leal 0xe0900(%ebx, %edx, 8), %eax\n"
        "leal 0x14(%eax), %edx\n"
        "movl %edx, -0xbc(%ebp)\n" /* victimCI */
        "movl 0x14(%eax), %edx\n" /* line 147 */
        "testl %edx, %edx\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl $0x20, 8(%esp)\n" /* line 150 */
        "addl $0x20, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0xa8(%ebp), %ecx\n" /* targetName */
        "movl %ecx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x2b3b48, 8(%esp)\n" /* line 151 */
        "movl $0x22, 4(%esp)\n"
        "leal -0xa8(%ebp), %eax\n" /* targetName */
        "movl %eax, (%esp)\n"
        "calll I_strncat\n"
        "leal -0x64(%ebp), %edx\n" /* line 152 | victimColor */
        "movl %edx, 4(%esp)\n"
        "movl -0xbc(%ebp), %ecx\n" /* victimCI */
        "movl 0x30(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_DrawScoreboard_GetTeamColor\n"
        "movl 4(%ebx), %edx\n" /* line 155 */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0xe0914(%ebx, %eax, 8), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "cmpl $0x3f, %edi\n" /* line 158 | attacker */
        "jbe .Lf1e1f7c_001e3850\n"
        "movb $0, -0x86(%ebp)\n" /* line 162 | attackerName */
        "movl $0x3fe, %edi\n" /* attacker */
        "movl $0, -0xb8(%ebp)\n" /* attackerCI */
        ".Lf1e1f7c_001e368b:\n"
        "cmpl -0xb0(%ebp), %edi\n" /* line 178 | target, attacker */
        "je .Lf1e1f7c_001e3819\n"
        "movl 0x195f584, %edx\n" /* line 183 */
        "movl (%edx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "movl 0xd8(%eax), %eax\n"
        "cmpl %eax, %edi\n" /* attacker */
        "je .Lf1e1f7c_001e37e4\n"
        "cmpl %eax, -0xb0(%ebp)\n" /* line 199 | target */
        "je .Lf1e1f7c_001e374f\n"
        ".Lf1e1f7c_001e36bc:\n"
        "movl (%edx), %eax\n" /* line 217 */
        "movl 0x2cd14(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movzbl -0xb1(%ebp), %eax\n" /* line 219 | iconHorzFlip */
        "movl %eax, 0x20(%esp)\n"
        "leal -0x44(%ebp), %eax\n" /* iconColor */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0x3fb33333, 0x18(%esp)\n"
        "movss -0xc4(%ebp), %xmm0\n" /* iconWidth */
        "movss %xmm0, 0x14(%esp)\n"
        "movl -0xc0(%ebp), %eax\n" /* iconShader */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x64(%ebp), %edx\n" /* victimColor */
        "movl %edx, 0xc(%esp)\n"
        "leal -0xa8(%ebp), %ecx\n" /* targetName */
        "movl %ecx, 8(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* attackerColor */
        "movl %eax, 4(%esp)\n"
        "leal -0x86(%ebp), %eax\n" /* attackerName */
        "movl %eax, (%esp)\n"
        "calll CL_DeathMessagePrint\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        "movss 0x2eda90, %xmm0\n" /* line 125 | 1.399999976158142f */
        "movss %xmm0, -0xc4(%ebp)\n" /* iconWidth */
        "movl $0x2a760c, -0xc0(%ebp)\n" /* iconShader */
        "movb $0, -0xb1(%ebp)\n" /* iconHorzFlip */
        "jmp .Lf1e1f7c_001e35b2\n"
        ".Lf1e1f7c_001e374f:\n"
        "movl -0xb8(%ebp), %ebx\n" /* line 199 | attackerCI */
        "testl %ebx, %ebx\n"
        "je .Lf1e1f7c_001e36bc\n"
        "movl -0xb8(%ebp), %edx\n" /* line 201 | attackerCI */
        "movl 0x30(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e3775\n"
        "movl -0xbc(%ebp), %ecx\n" /* victimCI */
        "cmpl 0x30(%ecx), %eax\n"
        "je .Lf1e1f7c_001e37c2\n"
        ".Lf1e1f7c_001e3775:\n"
        "leal -0x86(%ebp), %eax\n" /* line 204 | attackerName */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b84d0, (%esp)\n" /* "CGAME_YOUWEREKILLED%s" */
        "calll va\n"
        "movl %eax, %edx\n"
        ".Lf1e1f7c_001e378d:\n"
        "movl 0x195f584, %ebx\n" /* line 205 */
        "movl (%ebx), %eax\n"
        "movl 0x2cd14(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1e1f7c_001e1fa0\n"
        "movl $1, 8(%esp)\n" /* line 210 */
        "movl $0x4119999a, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_PriorityCenterPrint\n"
        "movl %ebx, %edx\n"
        "jmp .Lf1e1f7c_001e36bc\n"
        ".Lf1e1f7c_001e37c2:\n"
        "movl $0x2b8468, 8(%esp)\n" /* line 202 */
        "leal -0x86(%ebp), %eax\n" /* attackerName */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b84ac, (%esp)\n" /* "CGAME_YOUWEREKILLED^1&&2^7 %s%s" */
        "calll va\n"
        "movl %eax, %edx\n"
        "jmp .Lf1e1f7c_001e378d\n"
        ".Lf1e1f7c_001e37e4:\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 185 | attackerCI */
        "movl 0x30(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e37fc\n"
        "movl -0xbc(%ebp), %edx\n" /* victimCI */
        "cmpl 0x30(%edx), %eax\n"
        "je .Lf1e1f7c_001e382b\n"
        ".Lf1e1f7c_001e37fc:\n"
        "leal -0xa8(%ebp), %eax\n" /* line 188 | targetName */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8498, (%esp)\n" /* "CGAME_YOUKILLED%s" */
        "calll va\n"
        "movl %eax, %edx\n"
        "jmp .Lf1e1f7c_001e378d\n"
        ".Lf1e1f7c_001e3819:\n"
        "movb $0, -0x86(%ebp)\n" /* line 180 | attackerName */
        "movl 0x195f584, %edx\n"
        "jmp .Lf1e1f7c_001e36bc\n"
        ".Lf1e1f7c_001e382b:\n"
        "movl $0x2b8468, 8(%esp)\n" /* line 186 */
        "leal -0xa8(%ebp), %ecx\n" /* targetName */
        "movl %ecx, 4(%esp)\n"
        "movl $0x2b8478, (%esp)\n" /* "CGAME_YOUKILLED^1&&2^7 %s%s" */
        "calll va\n"
        "movl %eax, %edx\n"
        "jmp .Lf1e1f7c_001e378d\n"
        ".Lf1e1f7c_001e3850:\n"
        "leal (%edi, %edi, 4), %edx\n" /* line 166 | attacker */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edi, %eax, 2), %eax\n" /* attacker */
        "leal 0xe0900(%ebx, %eax, 8), %eax\n"
        "leal 0x14(%eax), %edx\n"
        "movl %edx, -0xb8(%ebp)\n" /* attackerCI */
        "movl 0x14(%eax), %esi\n" /* line 167 */
        "testl %esi, %esi\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl $0x20, 8(%esp)\n" /* line 169 */
        "addl $0x20, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x86(%ebp), %esi\n" /* attackerName */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x2b3b48, 8(%esp)\n" /* line 170 */
        "movl $0x22, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        "leal -0x54(%ebp), %eax\n" /* line 171 | attackerColor */
        "movl %eax, 4(%esp)\n"
        "movl -0xb8(%ebp), %ecx\n" /* attackerCI */
        "movl 0x30(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_DrawScoreboard_GetTeamColor\n"
        "movl 0x24(%ebx), %eax\n" /* line 174 */
        "movl -0xb0(%ebp), %edx\n" /* target */
        "cmpl 0xd8(%eax), %edx\n"
        "jne .Lf1e1f7c_001e368b\n"
        "movl $0x20, 8(%esp)\n" /* line 175 */
        "movl %esi, 4(%esp)\n"
        "leal 0x2b54c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf1e1f7c_001e368b\n"
        ".Lf1e1f7c_001e38f9:\n"
        "movl $0x2b8444, 4(%esp)\n" /* line 145 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1e1f7c_001e35bf\n"
        ".Lf1e1f7c_001e3912:\n"
        "movss 0x2eda90, %xmm0\n" /* line 100 | 1.399999976158142f */
        "movss %xmm0, -0xc4(%ebp)\n" /* iconWidth */
        "movl $0x2a763c, -0xc0(%ebp)\n" /* iconShader */
        "movb $0, -0xb1(%ebp)\n" /* iconHorzFlip */
        "jmp .Lf1e1f7c_001e35b2\n"
        ".Lf1e1f7c_001e3938:\n"
        "movl %eax, (%esp)\n" /* line 99 */
        "calll BG_GetWeaponDef\n"
        "movl 0x34c(%eax), %edx\n" /* line 100 */
        "cmpb $0, (%edx)\n"
        "je .Lf1e1f7c_001e3912\n"
        "movl %edx, -0xc0(%ebp)\n" /* line 102 | iconShader */
        "movl 0x350(%eax), %ebx\n" /* line 103 */
        "testl %ebx, %ebx\n"
        "je .Lf1e1f7c_001e3a16\n"
        "movss 0x2eda94, %xmm0\n" /* 2.799999952316284f */
        "movss %xmm0, -0xc4(%ebp)\n" /* iconWidth */
        ".Lf1e1f7c_001e396f:\n"
        "movl 0x354(%eax), %ecx\n" /* line 105 */
        "testl %ecx, %ecx\n"
        "setne -0xb1(%ebp)\n" /* iconHorzFlip */
        "jmp .Lf1e1f7c_001e35b2\n"
        "movss 0x2eda90, %xmm0\n" /* line 121 | 1.399999976158142f */
        "movss %xmm0, -0xc4(%ebp)\n" /* iconWidth */
        "movl $0x2a89d8, -0xc0(%ebp)\n" /* iconShader */
        "movb $0, -0xb1(%ebp)\n" /* iconHorzFlip */
        "jmp .Lf1e1f7c_001e35b2\n"
        "movss 0x2eda90, %xmm0\n" /* line 105 | 1.399999976158142f */
        "movss %xmm0, -0xc4(%ebp)\n" /* iconWidth */
        "movl $0x2a75fc, -0xc0(%ebp)\n" /* iconShader */
        "movb $0, -0xb1(%ebp)\n" /* iconHorzFlip */
        "jmp .Lf1e1f7c_001e35b2\n"
        /* } scope */
        ".Lf1e1f7c_001e39cf:\n"
        "movl 0x100(%edx), %eax\n" /* line 582 */
        "testl %eax, %eax\n"
        "je .Lf1e1f7c_001e1fa0\n"
        "movl %eax, 4(%esp)\n" /* line 583 */
        "movl (%esi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll CG_PlayEntitySoundAlias\n"
        "jmp .Lf1e1f7c_001e1fa0\n"
        /* { scope 2: forward, up */
        "movss 0x2eda90, %xmm0\n" /* line 116 | 1.399999976158142f */
        "movss %xmm0, -0xc4(%ebp)\n" /* iconWidth */
        "movl $0x2a762c, -0xc0(%ebp)\n" /* iconShader */
        "movb $0, -0xb1(%ebp)\n" /* iconHorzFlip */
        "jmp .Lf1e1f7c_001e35b2\n"
        ".Lf1e1f7c_001e3a16:\n"
        "movss 0x2eda90, %xmm0\n" /* line 103 | 1.399999976158142f */
        "movss %xmm0, -0xc4(%ebp)\n" /* iconWidth */
        "jmp .Lf1e1f7c_001e396f\n"
    );
}

/* line 871 */
__attribute__((naked))
void CG_CheckEvents(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 871 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* cent */
        /* { scope 1 */
        "cmpl $0xa, 0xf4(%ebx)\n" /* line 877 | cent */
        "jle .Lf1e3a2c_001e3a53\n"
        "movl 0x1e4(%ebx), %esi\n" /* line 879 | cent, i */
        "testl %esi, %esi\n" /* i */
        "je .Lf1e3a2c_001e3a98\n"
        /* } scope */
        ".Lf1e3a2c_001e3a4b:\n"
        "addl $0x1c, %esp\n" /* line 926 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e3a2c_001e3a53:\n"
        "movl 0x194(%ebx), %edx\n" /* line 891 | cent */
        "testl %edx, %edx\n"
        "je .Lf1e3a2c_001e3a86\n"
        "movl 0x1e4(%ebx), %eax\n" /* line 897 | cent */
        "cmpl %eax, %edx\n"
        "jl .Lf1e3a2c_001e3ada\n"
        "movl %edx, %ecx\n" /* line 901 */
        "subl %eax, %ecx\n"
        "cmpl $4, %ecx\n"
        "jg .Lf1e3a2c_001e3ac7\n"
        ".Lf1e3a2c_001e3a70:\n"
        "cmpl %edx, 0x1e4(%ebx)\n" /* line 906 | cent */
        "jl .Lf1e3a2c_001e3af0\n"
        ".Lf1e3a2c_001e3a78:\n"
        "movl %edx, 0x1e4(%ebx)\n" /* line 908 | cent */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 926 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e3a2c_001e3a86:\n"
        "movl $0, 0x1e4(%ebx)\n" /* line 893 | cent */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 926 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e3a2c_001e3a98:\n"
        "movl $1, 0x1e4(%ebx)\n" /* line 881 | cent */
        "movl %ebx, (%esp)\n" /* line 884 | cent */
        "calll CG_CalcEntityLerpPositions\n"
        "movl 0xf4(%ebx), %eax\n" /* line 885 | cent */
        "subl $0xa, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cent */
        "calll CG_EntityEvent\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 926 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e3a2c_001e3ac7:\n"
        "leal -4(%edx), %eax\n" /* line 903 */
        "movl %eax, 0x1e4(%ebx)\n" /* cent */
        "cmpl %edx, 0x1e4(%ebx)\n" /* line 906 | cent */
        "jge .Lf1e3a2c_001e3a78\n"
        "jmp .Lf1e3a2c_001e3af0\n"
        ".Lf1e3a2c_001e3ada:\n"
        "subl $0x100, %eax\n" /* line 899 */
        "movl %eax, 0x1e4(%ebx)\n" /* cent */
        "movl %edx, %ecx\n" /* line 901 */
        "subl %eax, %ecx\n"
        "cmpl $4, %ecx\n"
        "jle .Lf1e3a2c_001e3a70\n"
        "jmp .Lf1e3a2c_001e3ac7\n"
        ".Lf1e3a2c_001e3af0:\n"
        "movl %ebx, (%esp)\n" /* line 913 | cent */
        "calll CG_CalcEntityLerpPositions\n"
        "movzbl 0x190(%ebx), %edi\n" /* line 916 | cent, oldEventParm */
        "movl 0x1e4(%ebx), %esi\n" /* line 917 | cent, i */
        "cmpl 0x194(%ebx), %esi\n" /* cent, i */
        "je .Lf1e3a2c_001e3b3d\n"
        ".Lf1e3a2c_001e3b0d:\n"
        "movl %esi, %eax\n" /* line 919 | i */
        "andl $3, %eax\n"
        "movl 0x198(%ebx, %eax, 4), %edx\n" /* cent */
        "movl 0x1a8(%ebx, %eax, 4), %eax\n" /* line 921 | cent */
        "movl %eax, 0x190(%ebx)\n" /* cent */
        "movl %edx, 4(%esp)\n" /* line 922 */
        "movl %ebx, (%esp)\n" /* cent */
        "calll CG_EntityEvent\n"
        "addl $1, %esi\n" /* line 917 | i */
        "cmpl 0x194(%ebx), %esi\n" /* cent, i */
        "jne .Lf1e3a2c_001e3b0d\n"
        ".Lf1e3a2c_001e3b3d:\n"
        "movl %edi, %edx\n" /* line 924 | oldEventParm */
        "movzbl %dl, %eax\n"
        "movl %eax, 0x190(%ebx)\n" /* cent */
        "movl 0x194(%ebx), %eax\n" /* line 925 | cent */
        "movl %eax, 0x1e4(%ebx)\n" /* cent */
        "jmp .Lf1e3a2c_001e3a4b\n"
    );
}

