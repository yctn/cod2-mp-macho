/* ASM dump from: scr_const_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/scr_const_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern struct scr_const_t scr_const; /* 0x0 */

void GScr_LoadConsts(void);

/* line 11 */
__attribute__((naked))
void GScr_LoadConsts(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 11 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2157b8, (%esp)\n" /* line 13 */
        "calll GScr_AllocString\n"
        "movw %ax, scr_const\n"
        "movl $0x2b6b9c, (%esp)\n" /* line 14 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b082\n"
        "movl $0x2b6ba4, (%esp)\n" /* line 15 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b084\n"
        "movl $0x225108, (%esp)\n" /* line 16 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b086\n"
        "movl $0x22096c, (%esp)\n" /* line 17 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b088\n"
        "movl $0x2b6bac, (%esp)\n" /* line 18 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b08a\n"
        "movl $0x2b6bb4, (%esp)\n" /* line 19 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b08c\n"
        "movl $0x2b6bbc, (%esp)\n" /* line 20 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b08e\n"
        "movl $0x2b6bc4, (%esp)\n" /* line 21 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b090\n"
        "movl $0x21d304, (%esp)\n" /* line 22 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b092\n"
        "movl $0x2b6bcc, (%esp)\n" /* line 23 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b094\n"
        "movl $0x2b6bd4, (%esp)\n" /* line 24 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b096\n"
        "movl $0x2b6be0, (%esp)\n" /* line 25 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b098\n"
        "movl $0x221b68, (%esp)\n" /* line 26 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b09a\n"
        "movl $0x2b3290, (%esp)\n" /* line 27 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b09c\n"
        "movl $0x2b6be8, (%esp)\n" /* line 28 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b09e\n"
        "movl $0x2b6bf4, (%esp)\n" /* line 29 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0a0\n"
        "movl $0x2b6bfc, (%esp)\n" /* line 30 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0a2\n"
        "movl $0x2b6c04, (%esp)\n" /* line 31 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0a4\n"
        "movl $0x227904, (%esp)\n" /* line 32 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0a6\n"
        "movl $0x2b6c14, (%esp)\n" /* line 33 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0a8\n"
        "movl $0x2b6c20, (%esp)\n" /* line 34 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0aa\n"
        "movl $0x222fb0, (%esp)\n" /* line 35 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0ac\n"
        "movl $0x221be8, (%esp)\n" /* line 36 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0ae\n"
        "movl $0x2b6c28, (%esp)\n" /* line 37 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0b0\n"
        "movl $0x2b6c38, (%esp)\n" /* line 38 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0b2\n"
        "movl $0x2278d0, (%esp)\n" /* line 39 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0b4\n"
        "movl $0x221b90, (%esp)\n" /* line 40 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0b6\n"
        "movl $0x221b98, (%esp)\n" /* line 41 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0b8\n"
        "movl $0x221b88, (%esp)\n" /* line 42 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0ba\n"
        "movl $0x2b4d28, (%esp)\n" /* line 43 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0bc\n"
        "movl $0x221b70, (%esp)\n" /* line 44 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0be\n"
        "movl $0x2b6c40, (%esp)\n" /* line 45 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0c0\n"
        "movl $0x2b3360, (%esp)\n" /* line 46 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0c2\n"
        "movl $0x2b3374, (%esp)\n" /* line 47 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0c4\n"
        "movl $0x2b3384, (%esp)\n" /* line 48 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0c6\n"
        "movl $0x2b6c4c, (%esp)\n" /* line 49 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0c8\n"
        "movl $0x221b78, (%esp)\n" /* line 50 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0ca\n"
        "movl $0x2b6c58, (%esp)\n" /* line 51 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0cc\n"
        "movl $0x2b6c64, (%esp)\n" /* line 52 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0ce\n"
        "movl $0x2b6c7c, (%esp)\n" /* line 53 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0d0\n"
        "movl $0x2b6c88, (%esp)\n" /* line 54 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0d2\n"
        "movl $0x2b6c90, (%esp)\n" /* line 55 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0d4\n"
        "movl $0x2b3320, (%esp)\n" /* line 56 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0d6\n"
        "movl $0x2b332c, (%esp)\n" /* line 57 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0d8\n"
        "movl $0x2b3340, (%esp)\n" /* line 58 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0da\n"
        "movl $0x2b3350, (%esp)\n" /* line 59 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0dc\n"
        "movl $0x2b6c98, (%esp)\n" /* line 60 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0de\n"
        "movl $0x2b347c, (%esp)\n" /* line 61 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0e0\n"
        "movl $0x2b6ca4, (%esp)\n" /* line 62 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0e2\n"
        "movl $0x2b6cb4, (%esp)\n" /* line 63 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0e4\n"
        "movl $0x2b6cc4, (%esp)\n" /* line 64 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0e6\n"
        "movl $0x2b6cd4, (%esp)\n" /* line 65 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0e8\n"
        "movl $0x2b6ce8, (%esp)\n" /* line 66 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0ea\n"
        "movl $0x2b6cf8, (%esp)\n" /* line 69 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0ec\n"
        "movl $0x2b6d00, (%esp)\n" /* line 70 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0ee\n"
        "movl $0x2b6d10, (%esp)\n" /* line 71 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0f0\n"
        "movl $0x2b6d20, (%esp)\n" /* line 72 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0f2\n"
        "movl $0x218298, (%esp)\n" /* line 73 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0f4\n"
        "movl $0x2b6d28, (%esp)\n" /* line 74 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0f6\n"
        "movl $0x2b6d30, (%esp)\n" /* line 75 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0f8\n"
        "movl $0x2b6d3c, (%esp)\n" /* line 76 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0fa\n"
        "movl $0x2b6d4c, (%esp)\n" /* line 77 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0fc\n"
        "movl $0x2b6d58, (%esp)\n" /* line 79 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b0fe\n"
        "movl $0x2b3c60, (%esp)\n" /* line 80 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b100\n"
        "movl $0x2b6d64, (%esp)\n" /* line 82 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b102\n"
        "movl $0x2b6d80, (%esp)\n" /* line 83 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b104\n"
        "movl $0x2b6da0, (%esp)\n" /* line 84 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b106\n"
        "movl $0x2b6dc0, (%esp)\n" /* line 85 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b108\n"
        "movl $0x2b6dd8, (%esp)\n" /* line 86 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b10a\n"
        "movl $0x2b5a20, (%esp)\n" /* line 88 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b10c\n"
        "movl $0x2b6df8, (%esp)\n" /* line 89 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b10e\n"
        "movl $0x2b6e08, (%esp)\n" /* line 90 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b110\n"
        "movl $0x2b6e14, (%esp)\n" /* line 91 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b112\n"
        "movl $0x2b6e24, (%esp)\n" /* line 92 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b114\n"
        "movl $0x2b6e30, (%esp)\n" /* line 93 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b116\n"
        "movl $0x2b6e38, (%esp)\n" /* line 94 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b118\n"
        "movl $0x2b6e44, (%esp)\n" /* line 95 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b11a\n"
        "movl $0x2b6e50, (%esp)\n" /* line 96 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b11c\n"
        "movl $0x2b6e5c, (%esp)\n" /* line 97 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b11e\n"
        "movl $0x2b6e64, (%esp)\n" /* line 98 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b120\n"
        "movl $0x2b6e78, (%esp)\n" /* line 99 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b122\n"
        "movl $0x2b6e84, (%esp)\n" /* line 100 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b124\n"
        "movl $0x2a895c, (%esp)\n" /* line 101 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b126\n"
        "movl $0x2b6e90, (%esp)\n" /* line 102 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b128\n"
        "movl $0x2b6e9c, (%esp)\n" /* line 103 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b12a\n"
        "movl $0x2b6ea8, (%esp)\n" /* line 104 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b12c\n"
        "movl $0x2b65e0, (%esp)\n" /* line 105 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b12e\n"
        "movl $0x2b65d8, (%esp)\n" /* line 106 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b130\n"
        "movl $0x2b6eb0, (%esp)\n" /* line 107 */
        "calll GScr_AllocString\n"
        "movw %ax, 0x195b132\n"
        "leave\n" /* line 115 */
        "retl\n"
    );
}

