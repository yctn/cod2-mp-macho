/* ASM dump from: r_font.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_font.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

static int registeredFontCount; /* 0xc96d00 */
static Font * registeredFont[16]; /* 0xc96d20 */

const Glyph * R_GetCharacterGlyph(FontHandle font, unsigned int letter);
FontHandle R_RegisterFont(const char *fontName, int imageTrack);
int R_DuplicateFont(FontHandle fontCopy, const char *name);
int R_InitFonts(void);
int R_ShutdownFonts(void);
float R_NormalizedTextScale(FontHandle font, float scale);
int R_TextHeight(FontHandle font);
int R_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style);
static const short int * R_GetConsoleString(int *limit, char *text, vec_t *color, Bool *foundIcon);
static const short int * R_GetConsoleIcon(float *iconHeight, MaterialHandle *iconMaterial, vec_t *color, Bool *iconHorzFlip);
int R_TextWidth(const char *text, int maxChars, FontHandle font);
int R_ConsoleTextWidth(const short int *string, int maxChars, FontHandle font);
int R_DrawConsoleText(const short int *string, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style);

/* line 17 */
const Glyph * R_GetCharacterGlyph(FontHandle font, unsigned int letter)
{
    Glyph *glyphs = *(Glyph **)((byte *)font + 0x10);
    int numGlyphs, top, bot, mid;

    /* Fast path for printable ASCII (0x20..0x7F) */
    if (letter - 0x20 <= 0x5F)
        return &glyphs[letter - 0x20];

    /* Binary search through extended glyphs */
    numGlyphs = *(int *)((byte *)font + 8);
    top = numGlyphs - 1;
    bot = 0x60;

    if (top <= 0x5F)
        return &glyphs[14]; /* fallback glyph (period) */

    mid = (numGlyphs + 0x5F - 1) / 2;
    if (*(unsigned short *)&glyphs[mid] == letter)
        return (const Glyph *)&glyphs[mid];

    while (top >= bot) {
        mid = (top + bot) / 2;
        if (*(unsigned short *)&glyphs[mid] == letter)
            return (const Glyph *)&glyphs[mid];
        if (letter > *(unsigned short *)&glyphs[mid])
            bot = mid + 1;
        else
            top = mid - 1;
    }

    return &glyphs[14]; /* fallback glyph */
}

/* line 57 */
__attribute__((naked))
FontHandle R_RegisterFont(const char *fontName, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 57 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* fontName */
        /* { scope 1 */
        "movl registeredFontCount, %eax\n" /* line 64 */
        "testl %eax, %eax\n"
        "jg .Lfecbda_000ecc27\n"
        ".Lfecbda_000ecbef:\n"
        "cmpl $0xf, %eax\n" /* line 70 */
        "jg .Lfecbda_000ecc5c\n"
        "movl 0xc(%ebp), %eax\n" /* line 76 | imageTrack */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* fontName */
        "calll R_LoadFont\n"
        "movl %eax, %ebx\n" /* font */
        "testl %eax, %eax\n" /* line 77 */
        "je .Lfecbda_000ecc74\n"
        ".Lfecbda_000ecc09:\n"
        "movl registeredFontCount, %eax\n" /* line 80 */
        "movl %ebx, registeredFont(, %eax, 4)\n" /* font */
        "addl $1, %eax\n" /* line 81 */
        "movl %eax, registeredFontCount\n"
        /* } scope */
        ".Lfecbda_000ecc1d:\n"
        "movl %ebx, %eax\n" /* line 83 | font */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfecbda_000ecc27:\n"
        "xorl %esi, %esi\n" /* line 64 | fontIndex */
        "movl $registeredFont, %ebx\n" /* font */
        "jmp .Lfecbda_000ecc3f\n"
        ".Lfecbda_000ecc30:\n"
        "addl $1, %esi\n" /* fontIndex */
        "movl registeredFontCount, %eax\n"
        "addl $4, %ebx\n" /* font */
        "cmpl %esi, %eax\n" /* fontIndex */
        "jle .Lfecbda_000ecbef\n"
        ".Lfecbda_000ecc3f:\n"
        "movl (%ebx), %eax\n" /* line 66 | font */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* fontName */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfecbda_000ecc30\n"
        "movl registeredFont(, %esi, 4), %ebx\n" /* line 67 | font */
        "jmp .Lfecbda_000ecc1d\n"
        ".Lfecbda_000ecc5c:\n"
        "movl $0x225884, 4(%esp)\n" /* line 72 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "xorl %ebx, %ebx\n" /* font */
        "jmp .Lfecbda_000ecc1d\n"
        ".Lfecbda_000ecc74:\n"
        "movl %edi, 8(%esp)\n" /* line 78 | fontName */
        "movl $0x2258b8, 4(%esp)\n" /* "R_RegisterFont: Error while reading font '%s'" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfecbda_000ecc09\n"
    );
}

/* line 100 */
__attribute__((naked))
int R_DuplicateFont(FontHandle fontCopy, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 100 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* fontCopy */
        "movl 0xc(%ebp), %eax\n" /* name */
        "movl %eax, -0x20(%ebp)\n" /* name */
        /* { scope 1 */
        "movl registeredFontCount, %eax\n" /* line 109 */
        "testl %eax, %eax\n"
        "jg .Lfecc92_000ecd46\n"
        "movl $0, -0x1c(%ebp)\n" /* fontIndex */
        ".Lfecc92_000eccb8:\n"
        "cmpl $0xf, %eax\n" /* line 120 */
        "jg .Lfecc92_000ecd2c\n"
        "movl 0x195eee0, %esi\n" /* line 126 */
        "movl $0x14, (%esp)\n"
        "calll *0xc(%esi)\n"
        "movl %eax, %ebx\n"
        "movl (%edi), %eax\n" /* line 127 | fontCopy */
        "movl %eax, (%ebx)\n"
        "movl 4(%edi), %eax\n" /* fontCopy */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edi), %eax\n" /* fontCopy */
        "movl %eax, 8(%ebx)\n"
        "movl 0xc(%edi), %eax\n" /* fontCopy */
        "movl %eax, 0xc(%ebx)\n"
        "movl 0x10(%edi), %eax\n" /* fontCopy */
        "movl %eax, 0x10(%ebx)\n"
        "cld\n" /* line 129 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x20(%ebp), %edi\n" /* name, fontCopy */
        "repne scasb %es:(%edi), %al\n" /* fontCopy */
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll *0xc(%esi)\n"
        "movl %eax, %esi\n"
        "movl -0x20(%ebp), %eax\n" /* line 130 | name */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll strcpy\n"
        "movl %esi, (%ebx)\n" /* line 131 */
        "movl -0x1c(%ebp), %eax\n" /* line 133 | fontIndex */
        "movl %ebx, registeredFont(, %eax, 4)\n"
        "addl $1, registeredFontCount\n" /* line 134 */
        /* } scope */
        ".Lfecc92_000ecd24:\n"
        "addl $0x2c, %esp\n" /* line 135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfecc92_000ecd2c:\n"
        "movl $0x2258e8, 0xc(%ebp)\n" /* line 122 | name */
        "movl $1, 8(%ebp)\n" /* fontCopy */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp R_Error\n" /* line 122 */
        ".Lfecc92_000ecd46:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 109 | fontIndex */
        "movl $registeredFont, %esi\n"
        "jmp .Lfecc92_000ecd69\n"
        ".Lfecc92_000ecd54:\n"
        "addl $1, -0x1c(%ebp)\n" /* fontIndex */
        "movl registeredFontCount, %eax\n"
        "addl $4, %esi\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* fontIndex */
        "jge .Lfecc92_000eccb8\n"
        ".Lfecc92_000ecd69:\n"
        "movl (%esi), %ebx\n" /* line 111 */
        "movl (%ebx), %eax\n" /* line 112 */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfecc92_000ecd54\n"
        "movl (%ebx), %edx\n" /* line 114 */
        "movl (%edi), %eax\n" /* line 115 | fontCopy */
        "movl %eax, (%ebx)\n"
        "movl 4(%edi), %eax\n" /* fontCopy */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edi), %eax\n" /* fontCopy */
        "movl %eax, 8(%ebx)\n"
        "movl 0xc(%edi), %eax\n" /* fontCopy */
        "movl %eax, 0xc(%ebx)\n"
        "movl 0x10(%edi), %eax\n" /* fontCopy */
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, (%ebx)\n" /* line 116 */
        "jmp .Lfecc92_000ecd24\n"
    );
}

/* line 138 */
int R_InitFonts(void)
{
}

/* line 144 */
int R_ShutdownFonts(void)
{
    registeredFontCount = 0;
}

/* line 152 */
float R_NormalizedTextScale(FontHandle font, float scale)
{
    return 48.0f * scale / (float)*(int *)((byte *)font + 4);
}

/* line 202 */
int R_TextHeight(FontHandle font)
{
    return *(int *)((byte *)font + 4);
}

/* line 209 */
__attribute__((naked))
int R_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 209 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl $0, 0x28(%esp)\n" /* line 211 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* style */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* color */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* yScale */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* xScale */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* y */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* x */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* maxChars */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll R_AddCmdDrawTextWithCursor\n"
        "leave\n" /* line 212 */
        "retl\n"
    );
}

/* line 218 */
static __attribute__((naked))
const short int * R_GetConsoleString(int *limit, char *text, vec_t *color, Bool *foundIcon)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 218 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %ebx\n" /* string */
        "movl %edx, -0x4c(%ebp)\n"
        "movl %ecx, -0x28(%ebp)\n"
        /* { scope 1 */
        "cmpl $0x3ff, (%edx)\n" /* line 232 */
        "jle .Lfece4a_000ecfc2\n"
        "movl $0x3ff, (%edx)\n" /* line 233 */
        "movl -0x28(%ebp), %eax\n"
        ".Lfece4a_000ece70:\n"
        "movb $0, (%eax)\n" /* line 236 */
        "movl $0x37, (%esp)\n" /* line 237 */
        "calll ColorIndex\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* currentColor */
        "movl 0xc(%ebp), %edx\n" /* line 239 | foundIcon */
        "movb $0, (%edx)\n"
        "movl -0x4c(%ebp), %esi\n" /* line 241 */
        "movl (%esi), %edi\n"
        "testl %edi, %edi\n"
        "jg .Lfece4a_000ececd\n"
        "movl $0xffffffff, -0x1c(%ebp)\n" /* markedEnd */
        "xorl %ebx, %ebx\n" /* stringEndPos */
        "movl $0, -0x24(%ebp)\n" /* i */
        "xorl %eax, %eax\n"
        ".Lfece4a_000ecea6:\n"
        "movl -0x28(%ebp), %edx\n" /* line 294 */
        "movb $0, (%edx, %eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 295 | markedEnd */
        "testl %eax, %eax\n"
        "js .Lfece4a_000ecebb\n"
        "movl -0x1c(%ebp), %esi\n" /* line 296 | markedEnd */
        "movb $0, (%edx, %esi)\n"
        ".Lfece4a_000ecebb:\n"
        "movl -0x24(%ebp), %eax\n" /* line 298 | i */
        "movl -0x4c(%ebp), %edi\n"
        "subl %eax, (%edi)\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 300 | stringEndPos */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfece4a_000ececd:\n"
        "movl %ebx, %ecx\n" /* line 241 | stringEndPos */
        "movl $0xffffffff, -0x1c(%ebp)\n" /* markedEnd */
        "movl $0, -0x24(%ebp)\n" /* i */
        "movl $0, -0x3c(%ebp)\n" /* pos */
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        ".Lfece4a_000eceec:\n"
        "movl %ecx, %ebx\n" /* stringEndPos */
        "movzwl (%ecx), %eax\n" /* line 243 */
        "movzbl %ah, %edx\n"
        "cmpl %edx, -0x20(%ebp)\n" /* line 245 | currentColor */
        "je .Lfece4a_000ed00d\n"
        "cmpl $0xd, %edx\n" /* line 248 */
        "je .Lfece4a_000ecff8\n"
        "cmpl $0x10, %edx\n"
        "je .Lfece4a_000ecff8\n"
        "cmpl $0x11, %edx\n"
        "je .Lfece4a_000ecff8\n"
        "cmpl $0x12, %edx\n"
        "je .Lfece4a_000ecff8\n"
        "cmpl $0xa, %edx\n" /* line 256 */
        "je .Lfece4a_000ecf8b\n"
        "cmpl $0xb, %edx\n" /* line 262 */
        "je .Lfece4a_000ecfa6\n"
        "cmpl $0xc, %edx\n" /* line 268 */
        "je .Lfece4a_000ecfc9\n"
        "movl -0x28(%ebp), %esi\n" /* line 277 */
        "movl -0x3c(%ebp), %edi\n" /* pos */
        "movb $0x5e, (%esi, %edi)\n"
        "leal 0x30(%edx), %eax\n" /* line 278 */
        "movb %al, 1(%edi, %esi)\n"
        "addl $2, %edi\n"
        "movl %edi, -0x3c(%ebp)\n" /* pos */
        "movl %edx, -0x20(%ebp)\n" /* currentColor */
        "movzwl (%ecx), %eax\n"
        "movl %edi, %ebx\n" /* stringEndPos */
        ".Lfece4a_000ecf53:\n"
        "movl -0x28(%ebp), %edx\n" /* line 280 */
        "movb %al, (%edx, %ebx)\n"
        "cmpb $0x20, %al\n" /* line 281 */
        "je .Lfece4a_000ecfe5\n"
        "movl $0xffffffff, -0x1c(%ebp)\n" /* markedEnd */
        ".Lfece4a_000ecf68:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 288 | pos */
        ".Lfece4a_000ecf6c:\n"
        "addl $1, -0x24(%ebp)\n" /* line 241 | i */
        "addl $2, %ecx\n"
        "movl -0x24(%ebp), %eax\n" /* i */
        "movl -0x4c(%ebp), %edi\n"
        "cmpl %eax, (%edi)\n"
        "jg .Lfece4a_000eceec\n"
        "movl -0x3c(%ebp), %eax\n" /* pos */
        "xorl %ebx, %ebx\n" /* stringEndPos */
        "jmp .Lfece4a_000ecea6\n"
        ".Lfece4a_000ecf8b:\n"
        "movl 8(%ebp), %esi\n" /* line 258 | color */
        "testl %esi, %esi\n"
        "je .Lfece4a_000ecf6c\n"
        "movzbl %al, %eax\n" /* line 259 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movl 8(%ebp), %eax\n" /* color */
        "movss %xmm0, (%eax)\n"
        "jmp .Lfece4a_000ecf6c\n"
        ".Lfece4a_000ecfa6:\n"
        "movl 8(%ebp), %ebx\n" /* line 264 | color, stringEndPos */
        "testl %ebx, %ebx\n" /* stringEndPos */
        "je .Lfece4a_000ecf6c\n"
        "movzbl %al, %eax\n" /* line 265 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movl 8(%ebp), %edx\n" /* color */
        "movss %xmm0, 4(%edx)\n"
        "jmp .Lfece4a_000ecf6c\n"
        ".Lfece4a_000ecfc2:\n"
        "movl %ecx, %eax\n"
        "jmp .Lfece4a_000ece70\n"
        ".Lfece4a_000ecfc9:\n"
        "movl 8(%ebp), %edx\n" /* line 270 | color */
        "testl %edx, %edx\n"
        "je .Lfece4a_000ecf6c\n"
        "movzbl %al, %eax\n" /* line 271 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movl 8(%ebp), %ebx\n" /* color, stringEndPos */
        "movss %xmm0, 8(%ebx)\n" /* stringEndPos */
        "jmp .Lfece4a_000ecf6c\n"
        ".Lfece4a_000ecfe5:\n"
        "cmpl $-1, -0x1c(%ebp)\n" /* line 283 | markedEnd */
        "movl -0x3c(%ebp), %esi\n" /* pos */
        "cmovnel -0x1c(%ebp), %esi\n" /* markedEnd */
        "movl %esi, -0x1c(%ebp)\n" /* markedEnd */
        "jmp .Lfece4a_000ecf68\n"
        ".Lfece4a_000ecff8:\n"
        "movl 0xc(%ebp), %edi\n" /* line 252 | foundIcon */
        "movb $1, (%edi)\n"
        "movl -0x3c(%ebp), %eax\n" /* pos */
        "movl $0xffffffff, -0x1c(%ebp)\n" /* markedEnd */
        "jmp .Lfece4a_000ecea6\n"
        ".Lfece4a_000ed00d:\n"
        "movl -0x3c(%ebp), %ebx\n" /* pos, stringEndPos */
        "jmp .Lfece4a_000ecf53\n"
    );
}

/* line 303 */
static __attribute__((naked))
const short int * R_GetConsoleIcon(float *iconHeight, MaterialHandle *iconMaterial, vec_t *color, Bool *iconHorzFlip)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 303 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %edi\n" /* string */
        "movl %edx, %esi\n" /* maxChars */
        /* { scope 1 */
        "movl $0x3f800000, %eax\n" /* line 318 */
        "movl %eax, (%ecx)\n" /* iconWidth */
        "movl 8(%ebp), %edx\n" /* line 319 | iconHeight */
        "movl %eax, (%edx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 320 | iconMaterial */
        "movl $0, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 321 | iconHorzFlip */
        "testl %eax, %eax\n"
        "je .Lfed016_000ed045\n"
        "movl 0x14(%ebp), %edx\n" /* line 322 | iconHorzFlip */
        "movb $0, (%edx)\n"
        ".Lfed016_000ed045:\n"
        "movl (%esi), %eax\n" /* line 324 | maxChars */
        "testl %eax, %eax\n"
        "jle .Lfed016_000ed088\n"
        "movl 0x10(%ebp), %eax\n" /* color */
        "testl %eax, %eax\n"
        "jne .Lfed016_000ed174\n"
        "movl 0x14(%ebp), %eax\n" /* line 351 | iconHorzFlip */
        "testl %eax, %eax\n"
        "jne .Lfed016_000ed101\n"
        "xorl %ebx, %ebx\n" /* i */
        "movss 0x2ed878, %xmm1\n" /* 0.03125f */
        ".Lfed016_000ed06b:\n"
        "movzwl (%edi, %ebx, 2), %eax\n" /* line 326 | string */
        "movzbl %al, %edx\n" /* line 327 */
        "movzbl %ah, %eax\n" /* line 329 */
        "cmpl $0x11, %eax\n"
        "je .Lfed016_000ed0ae\n"
        "jg .Lfed016_000ed092\n"
        "cmpl $0x10, %eax\n"
        "je .Lfed016_000ed09c\n"
        ".Lfed016_000ed081:\n"
        "addl $1, %ebx\n" /* line 324 | i */
        "cmpl (%esi), %ebx\n" /* maxChars, i */
        "jl .Lfed016_000ed06b\n"
        ".Lfed016_000ed088:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 374 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfed016_000ed092:\n"
        "cmpl $0x12, %eax\n" /* line 329 */
        "je .Lfed016_000ed0c3\n"
        "cmpl $0x13, %eax\n"
        "jne .Lfed016_000ed081\n"
        ".Lfed016_000ed09c:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 349 */
        "mulss %xmm1, %xmm0\n"
        "mulss (%ecx), %xmm0\n" /* iconWidth */
        "movss %xmm0, (%ecx)\n" /* iconWidth */
        "jmp .Lfed016_000ed081\n"
        ".Lfed016_000ed0ae:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 355 */
        "mulss %xmm1, %xmm0\n"
        "movl 8(%ebp), %eax\n" /* iconHeight */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "jmp .Lfed016_000ed081\n"
        ".Lfed016_000ed0c3:\n"
        "addl $1, %ebx\n" /* line 359 | i */
        "movzbl %dl, %eax\n" /* line 361 */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x218(%eax)\n"
        "movl $7, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Material_RegisterHandle\n"
        "movl 0xc(%ebp), %edx\n" /* iconMaterial */
        "movl %eax, (%edx)\n"
        "subl %ebx, (%esi)\n" /* line 363 | i, maxChars */
        "leal (%edi, %ebx, 2), %eax\n" /* line 364 | string */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 374 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfed016_000ed101:\n"
        "xorl %ebx, %ebx\n" /* line 324 | i */
        "movss 0x2ed878, %xmm1\n" /* 0.03125f */
        ".Lfed016_000ed10b:\n"
        "movzwl (%edi, %ebx, 2), %eax\n" /* line 326 | string */
        "movzbl %al, %edx\n" /* line 327 */
        "movzbl %ah, %eax\n" /* line 329 */
        "cmpl $0x11, %eax\n"
        "je .Lfed016_000ed15f\n"
        "jg .Lfed016_000ed13d\n"
        "cmpl $0x10, %eax\n"
        "jne .Lfed016_000ed131\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 345 */
        "mulss %xmm1, %xmm0\n"
        "mulss (%ecx), %xmm0\n" /* iconWidth */
        "movss %xmm0, (%ecx)\n" /* iconWidth */
        ".Lfed016_000ed131:\n"
        "addl $1, %ebx\n" /* line 324 | i */
        "cmpl (%esi), %ebx\n" /* maxChars, i */
        "jl .Lfed016_000ed10b\n"
        "jmp .Lfed016_000ed088\n"
        ".Lfed016_000ed13d:\n"
        "cmpl $0x12, %eax\n" /* line 329 */
        "je .Lfed016_000ed0c3\n"
        "cmpl $0x13, %eax\n"
        "jne .Lfed016_000ed131\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 349 */
        "mulss %xmm1, %xmm0\n"
        "mulss (%ecx), %xmm0\n" /* iconWidth */
        "movss %xmm0, (%ecx)\n" /* iconWidth */
        "movl 0x14(%ebp), %edx\n" /* line 351 | iconHorzFlip */
        "movb $1, (%edx)\n"
        "jmp .Lfed016_000ed131\n"
        ".Lfed016_000ed15f:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 355 */
        "mulss %xmm1, %xmm0\n"
        "movl 8(%ebp), %eax\n" /* iconHeight */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "jmp .Lfed016_000ed131\n"
        ".Lfed016_000ed174:\n"
        "movl 0x14(%ebp), %eax\n" /* line 349 | iconHorzFlip */
        "testl %eax, %eax\n"
        "jne .Lfed016_000ed196\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lfed016_000ed17d:\n"
        "movzwl (%edi, %ebx, 2), %eax\n" /* line 326 | string */
        "movzbl %al, %edx\n" /* line 327 */
        "movzbl %ah, %eax\n" /* line 329 */
        "subl $0xd, %eax\n"
        "cmpl $6, %eax\n"
        "ja .Lfed016_000ed1c5\n"
        "jmpl *0x2f2a80(, %eax, 4)\n"
        ".Lfed016_000ed196:\n"
        "xorl %ebx, %ebx\n" /* line 324 | i */
        ".Lfed016_000ed198:\n"
        "movzwl (%edi, %ebx, 2), %eax\n" /* line 326 | string */
        "movzbl %al, %edx\n" /* line 327 */
        "movzbl %ah, %eax\n" /* line 329 */
        "subl $0xd, %eax\n"
        "cmpl $6, %eax\n"
        "ja .Lfed016_000ed1fa\n"
        "jmpl *0x2f2a9c(, %eax, 4)\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 337 */
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %eax\n" /* color */
        "movss %xmm0, 4(%eax)\n"
        ".Lfed016_000ed1c5:\n"
        "addl $1, %ebx\n" /* line 324 | i */
        "cmpl (%esi), %ebx\n" /* maxChars, i */
        "jl .Lfed016_000ed17d\n"
        "jmp .Lfed016_000ed088\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 341 */
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %edx\n" /* color */
        "movss %xmm0, 8(%edx)\n"
        "jmp .Lfed016_000ed1c5\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 333 */
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %eax\n" /* color */
        "movss %xmm0, (%eax)\n"
        ".Lfed016_000ed1fa:\n"
        "addl $1, %ebx\n" /* line 324 | i */
        "cmpl (%esi), %ebx\n" /* maxChars, i */
        "jl .Lfed016_000ed198\n"
        "jmp .Lfed016_000ed088\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 337 */
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %edx\n" /* color */
        "movss %xmm0, 4(%edx)\n"
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 341 */
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %eax\n" /* color */
        "movss %xmm0, 8(%eax)\n"
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 345 */
        "mulss 0x2ed878, %xmm0\n" /* 0.03125f */
        "mulss (%ecx), %xmm0\n" /* iconWidth */
        "movss %xmm0, (%ecx)\n" /* iconWidth */
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 349 */
        "mulss 0x2ed878, %xmm0\n" /* 0.03125f */
        "mulss (%ecx), %xmm0\n" /* iconWidth */
        "movss %xmm0, (%ecx)\n" /* iconWidth */
        "movl 0x14(%ebp), %edx\n" /* line 351 | iconHorzFlip */
        "movb $1, (%edx)\n"
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 355 */
        "mulss 0x2ed878, %xmm0\n" /* 0.03125f */
        "movl 8(%ebp), %eax\n" /* iconHeight */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 333 */
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %edx\n" /* color */
        "movss %xmm0, (%edx)\n"
        "jmp .Lfed016_000ed1c5\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 349 */
        "mulss 0x2ed878, %xmm0\n" /* 0.03125f */
        "mulss (%ecx), %xmm0\n" /* iconWidth */
        "movss %xmm0, (%ecx)\n" /* iconWidth */
        "jmp .Lfed016_000ed1c5\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 355 */
        "mulss 0x2ed878, %xmm0\n" /* 0.03125f */
        "movl 8(%ebp), %eax\n" /* iconHeight */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "jmp .Lfed016_000ed1c5\n"
    );
}

/* line 160 */
__attribute__((naked))
int R_TextWidth(const char *text, int maxChars, FontHandle font)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 160 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 173 | maxChars */
        "testl %eax, %eax\n"
        "movl $0x7fffffff, %eax\n"
        "cmovgl 0xc(%ebp), %eax\n" /* maxChars */
        "movl %eax, 0xc(%ebp)\n" /* maxChars */
        "movl $0, -0x20(%ebp)\n" /* lineWidth */
        "movl $0, -0x1c(%ebp)\n" /* maxWidth */
        "movl $0, -0x24(%ebp)\n" /* count */
        "movl 8(%ebp), %eax\n" /* text */
        "movl %eax, -0x28(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lfed2ce_000ed305:\n"
        "cmpb $0, (%ecx)\n" /* line 177 */
        "je .Lfed2ce_000ed377\n"
        ".Lfed2ce_000ed30a:\n"
        "movl -0x24(%ebp), %eax\n" /* count */
        "cmpl %eax, 0xc(%ebp)\n" /* maxChars */
        "jle .Lfed2ce_000ed377\n"
        "movl $0, 4(%esp)\n" /* line 179 */
        "leal 8(%ebp), %edx\n" /* text */
        "movl %edx, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x118(%eax)\n"
        "movl %eax, %ebx\n" /* letter */
        "cmpl $0xa, %eax\n" /* line 180 */
        "je .Lfed2ce_000ed39f\n"
        "cmpl $0x5e, %eax\n" /* line 184 */
        "je .Lfed2ce_000ed3b1\n"
        "movl 8(%ebp), %ecx\n" /* text */
        "movl %ecx, -0x28(%ebp)\n"
        /* { scope 2 */
        ".Lfed2ce_000ed33d:\n"
        "leal -0x20(%ebx), %eax\n" /* line 23 */
        "cmpl $0x5f, %eax\n"
        "ja .Lfed2ce_000ed382\n"
        "leal (%ebx, %ebx, 2), %edx\n" /* line 26 */
        "movl 0x10(%ebp), %ecx\n" /* font */
        "movl 0x10(%ecx), %eax\n"
        "leal -0x300(%eax, %edx, 8), %eax\n"
        /* } scope */
        ".Lfed2ce_000ed355:\n"
        "movzbl 4(%eax), %eax\n" /* line 191 */
        "addl %eax, -0x20(%ebp)\n" /* lineWidth */
        "movl -0x1c(%ebp), %eax\n" /* line 192 | maxWidth */
        "cmpl %eax, -0x20(%ebp)\n" /* lineWidth */
        "movl -0x20(%ebp), %edx\n" /* lineWidth */
        "cmovlel %eax, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* maxWidth */
        "addl $1, -0x24(%ebp)\n" /* line 194 | count */
        "movl -0x28(%ebp), %ecx\n"
        "cmpb $0, (%ecx)\n" /* line 177 */
        "jne .Lfed2ce_000ed30a\n"
        /* } scope */
        ".Lfed2ce_000ed377:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 199 | maxWidth */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfed2ce_000ed382:\n"
        "movl 0x10(%ebp), %edx\n" /* line 29 | font */
        "movl 8(%edx), %eax\n"
        "leal -1(%eax), %edi\n" /* top */
        "cmpl $0x5f, %edi\n" /* line 31 | top */
        "jg .Lfed2ce_000ed3e8\n"
        "movl 0x10(%edx), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl %ecx, %eax\n"
        ".Lfed2ce_000ed398:\n"
        "addl $0x150, %eax\n" /* line 41 */
        "jmp .Lfed2ce_000ed355\n"
        /* } scope */
        ".Lfed2ce_000ed39f:\n"
        "movl $0, -0x20(%ebp)\n" /* line 180 | lineWidth */
        "movl 8(%ebp), %ecx\n" /* text */
        "movl %ecx, -0x28(%ebp)\n"
        "jmp .Lfed2ce_000ed305\n"
        ".Lfed2ce_000ed3b1:\n"
        "movl 8(%ebp), %eax\n" /* line 184 | text */
        "movl %eax, -0x28(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lfed2ce_000ed33d\n"
        "movl %eax, %edx\n"
        "movzbl (%eax), %eax\n"
        "cmpb $0x5e, %al\n"
        "je .Lfed2ce_000ed33d\n"
        "cmpb $0x2f, %al\n"
        "jle .Lfed2ce_000ed33d\n"
        "cmpb $0x39, %al\n"
        "jg .Lfed2ce_000ed33d\n"
        "addl $1, %edx\n" /* line 187 */
        "movl %edx, -0x28(%ebp)\n"
        "movl %edx, 8(%ebp)\n" /* text */
        "movl %edx, %ecx\n"
        "jmp .Lfed2ce_000ed305\n"
        ".Lfed2ce_000ed3e8:\n"
        "movl %edx, %ecx\n"
        /* { scope 2 */
        "addl $0x5f, %eax\n" /* line 33 */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "movl 0x10(%ecx), %ecx\n" /* line 34 */
        "movl %ecx, -0x2c(%ebp)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movzwl (%eax), %ecx\n"
        "cmpl %ecx, %ebx\n"
        "je .Lfed2ce_000ed355\n"
        "movl $0x60, %esi\n" /* bot */
        "jmp .Lfed2ce_000ed43b\n"
        ".Lfed2ce_000ed414:\n"
        "leal 1(%edx), %esi\n" /* line 37 | bot */
        "cmpl %esi, %edi\n" /* line 31 | bot, top */
        "jl .Lfed2ce_000ed446\n"
        ".Lfed2ce_000ed41b:\n"
        "leal (%edi, %esi), %eax\n" /* line 33 | top */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 34 */
        "movl -0x2c(%ebp), %ecx\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movzwl (%eax), %ecx\n"
        "cmpl %ecx, %ebx\n"
        "je .Lfed2ce_000ed355\n"
        ".Lfed2ce_000ed43b:\n"
        "cmpl %ecx, %ebx\n" /* line 36 */
        "ja .Lfed2ce_000ed414\n"
        "leal -1(%edx), %edi\n" /* line 39 | top */
        "cmpl %esi, %edi\n" /* line 31 | bot, top */
        "jge .Lfed2ce_000ed41b\n"
        ".Lfed2ce_000ed446:\n"
        "movl -0x2c(%ebp), %eax\n"
        "jmp .Lfed2ce_000ed398\n"
    );
}

/* line 378 */
__attribute__((naked))
int R_ConsoleTextWidth(const short int *string, int maxChars, FontHandle font)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 378 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        "movl 8(%ebp), %eax\n" /* string */
        /* { scope 1: maxChars, text */
        "testl %eax, %eax\n" /* line 390 */
        "je .Lfed44e_000ed5bf\n"
        "movl %eax, -0x44c(%ebp)\n" /* stringRemaining */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x450(%ebp)\n" /* width */
        ".Lfed44e_000ed477:\n"
        "leal -0x19(%ebp), %eax\n" /* line 392 | iconWasFound */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "leal -0x42c(%ebp), %ecx\n" /* convertedString */
        "leal 0xc(%ebp), %edx\n" /* maxChars */
        "movl -0x44c(%ebp), %eax\n" /* stringRemaining */
        "calll R_GetConsoleString\n"
        "movl %eax, -0x44c(%ebp)\n" /* stringRemaining */
        "movl 0xc(%ebp), %edx\n" /* line 394 | maxChars */
        "leal -0x42c(%ebp), %ecx\n" /* convertedString */
        "movl %ecx, -0x458(%ebp)\n"
        "movl %ecx, -0x2c(%ebp)\n" /* text */
        /* { scope 2: count, lineWidth */
        /* { scope 3 */
        "testl %edx, %edx\n" /* line 173 */
        "movl $0x7fffffff, %eax\n"
        "cmovgl %edx, %eax\n"
        "movl %eax, -0x448(%ebp)\n" /* maxChars */
        "movl $0, -0x440(%ebp)\n" /* lineWidth */
        "movl $0, -0x43c(%ebp)\n"
        "movl $0, -0x444(%ebp)\n" /* count */
        ".Lfed44e_000ed4df:\n"
        "cmpb $0, (%ecx)\n" /* line 177 */
        "je .Lfed44e_000ed587\n"
        ".Lfed44e_000ed4e8:\n"
        "movl -0x444(%ebp), %eax\n" /* count */
        "cmpl %eax, -0x448(%ebp)\n" /* maxChars */
        "jle .Lfed44e_000ed587\n"
        "movl $0, 4(%esp)\n" /* line 179 */
        "leal -0x2c(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x118(%eax)\n"
        "movl %eax, %ebx\n"
        "cmpl $0xa, %eax\n" /* line 180 */
        "je .Lfed44e_000ed5ed\n"
        "cmpl $0x5e, %eax\n" /* line 184 */
        "je .Lfed44e_000ed607\n"
        "movl -0x2c(%ebp), %ecx\n" /* text */
        "movl %ecx, -0x458(%ebp)\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lfed44e_000ed530:\n"
        "leal -0x20(%ebx), %eax\n" /* line 23 */
        "cmpl $0x5f, %eax\n"
        "ja .Lfed44e_000ed5ca\n"
        "leal (%ebx, %ebx, 2), %edx\n" /* line 26 */
        "movl 0x10(%ebp), %ecx\n" /* font */
        "movl 0x10(%ecx), %eax\n"
        "leal -0x300(%eax, %edx, 8), %eax\n"
        /* } scope */
        /* } scope */
        ".Lfed44e_000ed54c:\n"
        "movzbl 4(%eax), %eax\n" /* line 191 */
        "addl %eax, -0x440(%ebp)\n" /* lineWidth */
        "movl -0x43c(%ebp), %eax\n" /* line 192 */
        "cmpl %eax, -0x440(%ebp)\n" /* lineWidth */
        "movl -0x440(%ebp), %edx\n" /* lineWidth */
        "cmovlel %eax, %edx\n"
        "movl %edx, -0x43c(%ebp)\n"
        "addl $1, -0x444(%ebp)\n" /* line 194 | count */
        "movl -0x458(%ebp), %ecx\n"
        "cmpb $0, (%ecx)\n" /* line 177 */
        "jne .Lfed44e_000ed4e8\n"
        /* } scope */
        /* } scope */
        ".Lfed44e_000ed587:\n"
        "cvtsi2ssl -0x43c(%ebp), %xmm0\n" /* line 394 */
        "addss -0x450(%ebp), %xmm0\n" /* width */
        "movss %xmm0, -0x450(%ebp)\n" /* width */
        "cmpb $0, -0x19(%ebp)\n" /* line 396 | iconWasFound */
        "jne .Lfed44e_000ed6bc\n"
        ".Lfed44e_000ed5a9:\n"
        "movl -0x44c(%ebp), %edx\n" /* line 390 | stringRemaining */
        "testl %edx, %edx\n"
        "jne .Lfed44e_000ed477\n"
        "cvttss2si -0x450(%ebp), %eax\n" /* width */
        /* } scope */
        ".Lfed44e_000ed5bf:\n"
        "addl $0x45c, %esp\n" /* line 404 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: maxChars, text */
        /* { scope 2: count, lineWidth */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lfed44e_000ed5ca:\n"
        "movl 0x10(%ebp), %edx\n" /* line 29 | font */
        "movl 8(%edx), %eax\n"
        "leal -1(%eax), %edi\n" /* top */
        "cmpl $0x5f, %edi\n" /* line 31 | top */
        "jg .Lfed44e_000ed646\n"
        "movl 0x10(%edx), %ecx\n"
        "movl %ecx, -0x454(%ebp)\n"
        "movl %ecx, %eax\n"
        ".Lfed44e_000ed5e3:\n"
        "addl $0x150, %eax\n" /* line 41 */
        "jmp .Lfed44e_000ed54c\n"
        /* } scope */
        /* } scope */
        ".Lfed44e_000ed5ed:\n"
        "movl $0, -0x440(%ebp)\n" /* line 180 | lineWidth */
        "movl -0x2c(%ebp), %eax\n" /* text */
        "movl %eax, -0x458(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lfed44e_000ed4df\n"
        ".Lfed44e_000ed607:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 184 | text */
        "movl %edx, -0x458(%ebp)\n"
        "testl %edx, %edx\n"
        "je .Lfed44e_000ed530\n"
        "movzbl (%edx), %eax\n"
        "cmpb $0x5e, %al\n"
        "je .Lfed44e_000ed530\n"
        "cmpb $0x2f, %al\n"
        "jle .Lfed44e_000ed530\n"
        "cmpb $0x39, %al\n"
        "jg .Lfed44e_000ed530\n"
        "addl $1, %edx\n" /* line 187 */
        "movl %edx, -0x458(%ebp)\n"
        "movl %edx, -0x2c(%ebp)\n" /* text */
        "movl %edx, %ecx\n"
        "jmp .Lfed44e_000ed4df\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lfed44e_000ed646:\n"
        "addl $0x5f, %eax\n" /* line 33 */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* line 34 | font */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x454(%ebp)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "movl -0x454(%ebp), %ecx\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movzwl (%eax), %ecx\n"
        "cmpl %ecx, %ebx\n"
        "je .Lfed44e_000ed54c\n"
        "movl $0x60, %esi\n" /* bot */
        "jmp .Lfed44e_000ed6a6\n"
        ".Lfed44e_000ed67c:\n"
        "leal 1(%edx), %esi\n" /* line 37 | bot */
        "cmpl %esi, %edi\n" /* line 31 | bot, top */
        "jl .Lfed44e_000ed6b1\n"
        ".Lfed44e_000ed683:\n"
        "leal (%edi, %esi), %eax\n" /* line 33 | top */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 34 */
        "movl -0x454(%ebp), %ecx\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movzwl (%eax), %ecx\n"
        "cmpl %ecx, %ebx\n"
        "je .Lfed44e_000ed54c\n"
        ".Lfed44e_000ed6a6:\n"
        "cmpl %ecx, %ebx\n" /* line 36 */
        "ja .Lfed44e_000ed67c\n"
        "leal -1(%edx), %edi\n" /* line 39 | top */
        "cmpl %esi, %edi\n" /* line 31 | bot, top */
        "jge .Lfed44e_000ed683\n"
        ".Lfed44e_000ed6b1:\n"
        "movl -0x454(%ebp), %eax\n"
        "jmp .Lfed44e_000ed5e3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfed44e_000ed6bc:\n"
        "movl $0, 0xc(%esp)\n" /* line 398 */
        "movl $0, 8(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* iconMaterial */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* iconHeight */
        "movl %eax, (%esp)\n"
        "leal -0x20(%ebp), %ecx\n" /* iconWidth */
        "leal 0xc(%ebp), %edx\n" /* maxChars */
        "movl -0x44c(%ebp), %eax\n" /* stringRemaining */
        "calll R_GetConsoleIcon\n"
        "movl %eax, -0x44c(%ebp)\n" /* stringRemaining */
        "movss -0x450(%ebp), %xmm0\n" /* line 399 | width */
        "addss -0x20(%ebp), %xmm0\n" /* iconWidth */
        "movss %xmm0, -0x450(%ebp)\n" /* width */
        "jmp .Lfed44e_000ed5a9\n"
    );
}

/* line 417 */
__attribute__((naked))
int R_DrawConsoleText(const short int *string, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 417 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x48c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* string */
        "movl 0x24(%ebp), %edx\n" /* color */
        /* { scope 1: maxChars, text */
        "movl (%edx), %eax\n" /* line 456 */
        "movl %eax, -0x3c(%ebp)\n" /* curColor */
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, -0x30(%ebp)\n"
        "testl %ecx, %ecx\n" /* line 433 */
        "je .Lfed70a_000eda1f\n"
        "movl %ecx, -0x45c(%ebp)\n" /* stringRemaining */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x460(%ebp)\n" /* xOfs */
        "jmp .Lfed70a_000ed767\n"
        ".Lfed70a_000ed74f:\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 445 | iconWasFound */
        "jne .Lfed70a_000ed923\n"
        ".Lfed70a_000ed759:\n"
        "movl -0x45c(%ebp), %ecx\n" /* line 433 | stringRemaining */
        "testl %ecx, %ecx\n"
        "je .Lfed70a_000eda1f\n"
        ".Lfed70a_000ed767:\n"
        "leal -0x19(%ebp), %eax\n" /* line 435 | iconWasFound */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* curColor */
        "movl %edx, (%esp)\n"
        "leal -0x43c(%ebp), %ecx\n" /* convertedString */
        "leal 0xc(%ebp), %edx\n" /* maxChars */
        "movl -0x45c(%ebp), %eax\n" /* stringRemaining */
        "calll R_GetConsoleString\n"
        "movl %eax, -0x45c(%ebp)\n" /* stringRemaining */
        "cmpb $0, -0x43c(%ebp)\n" /* line 437 | convertedString */
        "je .Lfed70a_000ed74f\n"
        "movl $0, 0x28(%esp)\n" /* line 211 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl 0x28(%ebp), %ecx\n" /* style */
        "movl %ecx, 0x20(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* curColor */
        "movl %eax, 0x1c(%esp)\n"
        "movss 0x20(%ebp), %xmm0\n" /* yScale */
        "movss %xmm0, 0x18(%esp)\n"
        "movss 0x1c(%ebp), %xmm0\n" /* xScale */
        "movss %xmm0, 0x14(%esp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x460(%ebp), %xmm0\n" /* xOfs */
        "addss 0x14(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "leal -0x43c(%ebp), %edx\n" /* convertedString */
        "movl %edx, (%esp)\n"
        "calll R_AddCmdDrawTextWithCursor\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 441 | iconWasFound */
        "je .Lfed70a_000ed759\n"
        "movl 0xc(%ebp), %ecx\n" /* line 442 | maxChars */
        "leal -0x43c(%ebp), %eax\n" /* convertedString */
        "movl %eax, -0x468(%ebp)\n"
        "movl %eax, -0x24(%ebp)\n" /* text */
        /* { scope 2: count, lineWidth */
        /* { scope 3 */
        "testl %ecx, %ecx\n" /* line 173 */
        "movl $0x7fffffff, %eax\n"
        "cmovgl %ecx, %eax\n"
        "movl %eax, -0x458(%ebp)\n" /* maxChars */
        "movl $0, -0x450(%ebp)\n" /* lineWidth */
        "movl $0, -0x44c(%ebp)\n"
        "movl $0, -0x454(%ebp)\n" /* count */
        "movl -0x468(%ebp), %edx\n"
        ".Lfed70a_000ed856:\n"
        "cmpb $0, (%edx)\n" /* line 177 */
        "je .Lfed70a_000ed8fc\n"
        ".Lfed70a_000ed85f:\n"
        "movl -0x454(%ebp), %ecx\n" /* count */
        "cmpl %ecx, -0x458(%ebp)\n" /* maxChars */
        "jle .Lfed70a_000ed8fc\n"
        "movl $0, 4(%esp)\n" /* line 179 */
        "leal -0x24(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x118(%eax)\n"
        "movl %eax, %ebx\n"
        "cmpl $0xa, %eax\n" /* line 180 */
        "je .Lfed70a_000eda4d\n"
        "cmpl $0x5e, %eax\n" /* line 184 */
        "je .Lfed70a_000eda65\n"
        "movl -0x24(%ebp), %eax\n" /* text */
        "movl %eax, -0x468(%ebp)\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lfed70a_000ed8a7:\n"
        "leal -0x20(%ebx), %eax\n" /* line 23 */
        "cmpl $0x5f, %eax\n"
        "ja .Lfed70a_000eda2a\n"
        "leal (%ebx, %ebx, 2), %edx\n" /* line 26 */
        "movl 0x10(%ebp), %ecx\n" /* font */
        "movl 0x10(%ecx), %eax\n"
        "leal -0x300(%eax, %edx, 8), %eax\n"
        /* } scope */
        /* } scope */
        ".Lfed70a_000ed8c3:\n"
        "movzbl 4(%eax), %eax\n" /* line 191 */
        "addl %eax, -0x450(%ebp)\n" /* lineWidth */
        "movl -0x450(%ebp), %eax\n" /* line 192 | lineWidth */
        "cmpl %eax, -0x44c(%ebp)\n"
        "cmovgel -0x44c(%ebp), %eax\n"
        "movl %eax, -0x44c(%ebp)\n"
        "addl $1, -0x454(%ebp)\n" /* line 194 | count */
        "movl -0x468(%ebp), %edx\n"
        "cmpb $0, (%edx)\n" /* line 177 */
        "jne .Lfed70a_000ed85f\n"
        /* } scope */
        /* } scope */
        ".Lfed70a_000ed8fc:\n"
        "cvtsi2ssl -0x44c(%ebp), %xmm0\n" /* line 442 */
        "mulss 0x1c(%ebp), %xmm0\n" /* xScale */
        "addss -0x460(%ebp), %xmm0\n" /* xOfs */
        "movss %xmm0, -0x460(%ebp)\n" /* xOfs */
        "cmpb $0, -0x19(%ebp)\n" /* line 445 | iconWasFound */
        "je .Lfed70a_000ed759\n"
        ".Lfed70a_000ed923:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 447 | iconHorzFlip */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* curColor */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* iconMaterial */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* iconHeight */
        "movl %eax, (%esp)\n"
        "leal -0x2c(%ebp), %ecx\n" /* iconWidth */
        "leal 0xc(%ebp), %edx\n" /* maxChars */
        "movl -0x45c(%ebp), %eax\n" /* stringRemaining */
        "calll R_GetConsoleIcon\n"
        "movl %eax, -0x45c(%ebp)\n" /* stringRemaining */
        "movl 0x10(%ebp), %edx\n" /* line 448 | font */
        "cvtsi2ssl 4(%edx), %xmm0\n"
        "movss 0x1c(%ebp), %xmm2\n" /* xScale */
        "mulss %xmm0, %xmm2\n"
        "mulss -0x2c(%ebp), %xmm2\n" /* iconWidth */
        "movss %xmm2, -0x2c(%ebp)\n" /* iconWidth */
        "mulss 0x20(%ebp), %xmm0\n" /* line 449 | yScale */
        "movaps %xmm0, %xmm1\n"
        "mulss -0x28(%ebp), %xmm1\n" /* iconHeight */
        "movss %xmm1, -0x28(%ebp)\n" /* iconHeight */
        "mulss 0x2ed7f0, %xmm0\n" /* line 450 | 0.800000011920929f */
        "addss %xmm1, %xmm0\n"
        "mulss 0x2ed63c, %xmm0\n" /* -0.5f */
        "addss 0x18(%ebp), %xmm0\n" /* y */
        "movl -0x20(%ebp), %eax\n" /* line 451 | iconMaterial, material */
        "movss 0x14(%ebp), %xmm3\n" /* x */
        "addss -0x460(%ebp), %xmm3\n" /* xOfs, x */
        /* { scope 2: count, lineWidth */
        "cmpb $0, -0x1a(%ebp)\n" /* line 409 | iconHorzFlip */
        "je .Lfed70a_000edb1a\n"
        "movl %eax, 0x24(%esp)\n" /* line 410 */
        "leal -0x3c(%ebp), %ecx\n" /* curColor */
        "movl %ecx, 0x20(%esp)\n"
        "movl $0x3f800000, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        ".Lfed70a_000ed9e0:\n"
        "movss %xmm1, 0xc(%esp)\n" /* line 412 */
        "movss %xmm2, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm3, (%esp)\n"
        "calll R_AddCmdDrawStretchPic\n"
        /* } scope */
        "movss -0x460(%ebp), %xmm0\n" /* line 452 | xOfs */
        "addss -0x2c(%ebp), %xmm0\n" /* iconWidth */
        "movss %xmm0, -0x460(%ebp)\n" /* xOfs */
        "movl -0x45c(%ebp), %ecx\n" /* line 433 | stringRemaining */
        "testl %ecx, %ecx\n"
        "jne .Lfed70a_000ed767\n"
        /* } scope */
        ".Lfed70a_000eda1f:\n"
        "addl $0x48c, %esp\n" /* line 455 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: maxChars, text */
        /* { scope 2: count, lineWidth */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lfed70a_000eda2a:\n"
        "movl 0x10(%ebp), %edx\n" /* line 29 | font */
        "movl 8(%edx), %eax\n"
        "leal -1(%eax), %edi\n" /* top */
        "cmpl $0x5f, %edi\n" /* line 31 | top */
        "jg .Lfed70a_000edaa4\n"
        "movl 0x10(%edx), %ecx\n"
        "movl %ecx, -0x464(%ebp)\n"
        "movl %ecx, %eax\n"
        ".Lfed70a_000eda43:\n"
        "addl $0x150, %eax\n" /* line 41 */
        "jmp .Lfed70a_000ed8c3\n"
        /* } scope */
        /* } scope */
        ".Lfed70a_000eda4d:\n"
        "movl $0, -0x450(%ebp)\n" /* line 180 | lineWidth */
        "movl -0x24(%ebp), %edx\n" /* text */
        "movl %edx, -0x468(%ebp)\n"
        "jmp .Lfed70a_000ed856\n"
        ".Lfed70a_000eda65:\n"
        "movl -0x24(%ebp), %ecx\n" /* line 184 | text */
        "movl %ecx, -0x468(%ebp)\n"
        "testl %ecx, %ecx\n"
        "je .Lfed70a_000ed8a7\n"
        "movzbl (%ecx), %eax\n"
        "cmpb $0x5e, %al\n"
        "je .Lfed70a_000ed8a7\n"
        "cmpb $0x2f, %al\n"
        "jle .Lfed70a_000ed8a7\n"
        "cmpb $0x39, %al\n"
        "jg .Lfed70a_000ed8a7\n"
        "addl $1, %ecx\n" /* line 187 */
        "movl %ecx, -0x468(%ebp)\n"
        "movl %ecx, -0x24(%ebp)\n" /* text */
        "movl %ecx, %edx\n"
        "jmp .Lfed70a_000ed856\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lfed70a_000edaa4:\n"
        "addl $0x5f, %eax\n" /* line 33 */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* line 34 | font */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x464(%ebp)\n"
        "leal (%edx, %edx, 2), %eax\n"
        "movl -0x464(%ebp), %ecx\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movzwl (%eax), %ecx\n"
        "cmpl %ecx, %ebx\n"
        "je .Lfed70a_000ed8c3\n"
        "movl $0x60, %esi\n" /* bot */
        "jmp .Lfed70a_000edb04\n"
        ".Lfed70a_000edada:\n"
        "leal 1(%edx), %esi\n" /* line 37 | bot */
        "cmpl %esi, %edi\n" /* line 31 | bot, top */
        "jl .Lfed70a_000edb0f\n"
        ".Lfed70a_000edae1:\n"
        "leal (%edi, %esi), %eax\n" /* line 33 | top */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 34 */
        "movl -0x464(%ebp), %ecx\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movzwl (%eax), %ecx\n"
        "cmpl %ebx, %ecx\n"
        "je .Lfed70a_000ed8c3\n"
        ".Lfed70a_000edb04:\n"
        "cmpl %ecx, %ebx\n" /* line 36 */
        "ja .Lfed70a_000edada\n"
        "leal -1(%edx), %edi\n" /* line 39 | top */
        "cmpl %esi, %edi\n" /* line 31 | bot, top */
        "jge .Lfed70a_000edae1\n"
        ".Lfed70a_000edb0f:\n"
        "movl -0x464(%ebp), %eax\n"
        "jmp .Lfed70a_000eda43\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: count, lineWidth */
        ".Lfed70a_000edb1a:\n"
        "movl %eax, 0x24(%esp)\n" /* line 412 */
        "leal -0x3c(%ebp), %eax\n" /* curColor */
        "movl %eax, 0x20(%esp)\n"
        "movl $0x3f800000, 0x1c(%esp)\n"
        "movl $0x3f800000, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "jmp .Lfed70a_000ed9e0\n"
    );
}

