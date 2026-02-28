/* ASM dump from: r_font.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_font.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern int I_stricmp(const char *s1, const char *s2);
extern int R_Error(int code, const char *fmt, ...);
extern FontHandle R_LoadFont(const char *fontName, int imageTrack);
extern void R_AddCmdDrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor);
extern void R_AddCmdDrawStretchPic(float x, float y, float w, float h, float s0, float t0, float s1, float t1, const vec_t *color, MaterialHandle material);
extern unsigned char ColorIndex(int c);
extern MaterialHandle Material_RegisterHandle(const char *name, int lightmapIndex, int imageTrack);
extern refimport_t *ri; /* imp_ri */

static int registeredFontCount; /* registeredFontCount */
static Font * registeredFont[16]; /* registeredFont */

const Glyph * R_GetCharacterGlyph(FontHandle font, unsigned int letter);
FontHandle R_RegisterFont(const char *fontName, int imageTrack);
int R_DuplicateFont(FontHandle fontCopy, const char *name);
int R_InitFonts(void);
int R_ShutdownFonts(void);
float R_NormalizedTextScale(FontHandle font, float scale);
int R_TextHeight(FontHandle font);
int R_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style);
static const short int * __attribute__((regparm(3))) R_GetConsoleString(const short int *string, int *limit, char *text, vec_t *color, Bool *foundIcon);
static const short int * __attribute__((regparm(3))) R_GetConsoleIcon(const short int *string, int *maxChars, float *iconWidth, float *iconHeight, MaterialHandle *iconMaterial, vec_t *color, Bool *iconHorzFlip);
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
FontHandle R_RegisterFont(const char *fontName, int imageTrack)
{
    int fontIndex;
    FontHandle font;

    for (fontIndex = 0; fontIndex < registeredFontCount; fontIndex++) {
        if (I_stricmp(fontName, *(const char **)registeredFont[fontIndex]) == 0) {
            return registeredFont[fontIndex];
        }
    }

    if (registeredFontCount > 15) {
        R_Error(1, (const char *)str_00225884);
        return 0;
    }

    font = R_LoadFont(fontName, imageTrack);
    if (!font) {
        R_Error(1, (const char *)str_002258b8, fontName);
    }

    registeredFont[registeredFontCount] = font;
    registeredFontCount++;

    return font;
}

/* line 100 */
int R_DuplicateFont(FontHandle fontCopy, const char *name)
{
    int fontIndex;
    FontHandle existing;
    FontHandle newFont;
    char *nameCopy;
    const char *oldName;
    typedef void *(*AllocFunc)(int);
    AllocFunc alloc = *(AllocFunc *)((byte *)*(int *)imp_ri + 0xc);

    for (fontIndex = 0; fontIndex < registeredFontCount; fontIndex++) {
        existing = registeredFont[fontIndex];
        if (I_stricmp(name, *(const char **)existing) == 0) {
            /* Found existing font with same name - copy data, preserve name ptr */
            oldName = *(const char **)existing;
            memcpy(existing, fontCopy, 0x14);
            *(const char **)existing = oldName;
            return 0;
        }
    }

    if (registeredFontCount > 15) {
        return R_Error(1, (const char *)str_002258e8);
    }

    newFont = alloc(0x14);
    memcpy(newFont, fontCopy, 0x14);

    nameCopy = (char *)alloc(strlen(name) + 1);
    strcpy(nameCopy, name);
    *(const char **)newFont = nameCopy;

    registeredFont[fontIndex] = newFont;
    registeredFontCount++;

    return 0;
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
int R_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style)
{
    R_AddCmdDrawTextWithCursor(text, maxChars, font, x, y, xScale, yScale, color, style, -1, 0);
}

/* line 218 */
static __attribute__((regparm(3)))
const short int * R_GetConsoleString(const short int *string, int *limit, char *text, vec_t *color, Bool *foundIcon)
{
    int currentColor;
    int markedEnd;
    const short int *stringEndPos;
    int i;
    int pos;
    unsigned short entry;
    unsigned char ch;
    unsigned char type;

    if (*limit > 0x3ff) {
        *limit = 0x3ff;
    }

    text[0] = '\0';
    currentColor = (int)ColorIndex(0x37);
    *foundIcon = 0;

    if (*limit <= 0) {
        markedEnd = -1;
        stringEndPos = 0;
        i = 0;
        pos = 0;
        goto finish;
    }

    stringEndPos = string;
    markedEnd = -1;
    i = 0;
    pos = 0;

    for (i = 0; i < *limit; i++) {
        stringEndPos = &string[i];
        entry = *(const unsigned short *)&string[i];
        ch = (unsigned char)entry;
        type = (unsigned char)(entry >> 8);

        if (type == currentColor) {
            /* same color - just write character */
            text[pos] = ch;
            if (ch == 0x20) {
                if (markedEnd == -1) {
                    markedEnd = pos;
                }
                pos++;
                continue;
            }
            markedEnd = -1;
            pos++;
            continue;
        }

        if (type == 0x0d || type == 0x10 || type == 0x11 || type == 0x12) {
            *foundIcon = 1;
            markedEnd = -1;
            pos = pos; /* keep pos for null-termination */
            goto finish;
        }

        if (type == 0x0a) {
            if (color) {
                color[0] = (float)(unsigned int)ch * 0.003921568859368563f;
            }
            continue;
        }

        if (type == 0x0b) {
            if (color) {
                color[1] = (float)(unsigned int)ch * 0.003921568859368563f;
            }
            continue;
        }

        if (type == 0x0c) {
            if (color) {
                color[2] = (float)(unsigned int)ch * 0.003921568859368563f;
            }
            continue;
        }

        /* different color - emit color code */
        text[pos] = '^';
        text[pos + 1] = (char)(type + 0x30);
        pos += 2;
        currentColor = type;
        stringEndPos = &string[i];

        /* write character */
        entry = *(const unsigned short *)&string[i];
        ch = (unsigned char)entry;
        text[pos] = ch;
        if (ch == 0x20) {
            if (markedEnd == -1) {
                markedEnd = pos;
            }
            pos++;
            continue;
        }
        markedEnd = -1;
        pos++;
    }

    /* loop completed - consumed all chars */
    stringEndPos = 0;

finish:
    text[pos] = '\0';
    if (markedEnd >= 0) {
        text[markedEnd] = '\0';
    }
    *limit -= i;
    return stringEndPos;
}

/* line 303 */
static __attribute__((naked)) __attribute__((regparm(3)))
const short int * R_GetConsoleIcon(const short int *string, int *maxChars, float *iconWidth, float *iconHeight, MaterialHandle *iconMaterial, vec_t *color, Bool *iconHorzFlip)
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
        "movss lit4_002ed878, %xmm1\n" /* 0.03125f */
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
        "movl imp_ri, %eax\n"
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
        "movss lit4_002ed878, %xmm1\n" /* 0.03125f */
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
        "jmpl *gridBasisDirs+128(, %eax, 4)\n"
        ".Lfed016_000ed196:\n"
        "xorl %ebx, %ebx\n" /* line 324 | i */
        ".Lfed016_000ed198:\n"
        "movzwl (%edi, %ebx, 2), %eax\n" /* line 326 | string */
        "movzbl %al, %edx\n" /* line 327 */
        "movzbl %ah, %eax\n" /* line 329 */
        "subl $0xd, %eax\n"
        "cmpl $6, %eax\n"
        "ja .Lfed016_000ed1fa\n"
        "jmpl *gridBasisDirs+156(, %eax, 4)\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 337 */
        "mulss lit4_002ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %eax\n" /* color */
        "movss %xmm0, 4(%eax)\n"
        ".Lfed016_000ed1c5:\n"
        "addl $1, %ebx\n" /* line 324 | i */
        "cmpl (%esi), %ebx\n" /* maxChars, i */
        "jl .Lfed016_000ed17d\n"
        "jmp .Lfed016_000ed088\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 341 */
        "mulss lit4_002ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %edx\n" /* color */
        "movss %xmm0, 8(%edx)\n"
        "jmp .Lfed016_000ed1c5\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 333 */
        "mulss lit4_002ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %eax\n" /* color */
        "movss %xmm0, (%eax)\n"
        ".Lfed016_000ed1fa:\n"
        "addl $1, %ebx\n" /* line 324 | i */
        "cmpl (%esi), %ebx\n" /* maxChars, i */
        "jl .Lfed016_000ed198\n"
        "jmp .Lfed016_000ed088\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 337 */
        "mulss lit4_002ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %edx\n" /* color */
        "movss %xmm0, 4(%edx)\n"
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 341 */
        "mulss lit4_002ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %eax\n" /* color */
        "movss %xmm0, 8(%eax)\n"
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 345 */
        "mulss lit4_002ed878, %xmm0\n" /* 0.03125f */
        "mulss (%ecx), %xmm0\n" /* iconWidth */
        "movss %xmm0, (%ecx)\n" /* iconWidth */
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 349 */
        "mulss lit4_002ed878, %xmm0\n" /* 0.03125f */
        "mulss (%ecx), %xmm0\n" /* iconWidth */
        "movss %xmm0, (%ecx)\n" /* iconWidth */
        "movl 0x14(%ebp), %edx\n" /* line 351 | iconHorzFlip */
        "movb $1, (%edx)\n"
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 355 */
        "mulss lit4_002ed878, %xmm0\n" /* 0.03125f */
        "movl 8(%ebp), %eax\n" /* iconHeight */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "jmp .Lfed016_000ed1fa\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 333 */
        "mulss lit4_002ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "movl 0x10(%ebp), %edx\n" /* color */
        "movss %xmm0, (%edx)\n"
        "jmp .Lfed016_000ed1c5\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 349 */
        "mulss lit4_002ed878, %xmm0\n" /* 0.03125f */
        "mulss (%ecx), %xmm0\n" /* iconWidth */
        "movss %xmm0, (%ecx)\n" /* iconWidth */
        "jmp .Lfed016_000ed1c5\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 355 */
        "mulss lit4_002ed878, %xmm0\n" /* 0.03125f */
        "movl 8(%ebp), %eax\n" /* iconHeight */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "jmp .Lfed016_000ed1c5\n"
    );
}

/* line 160 */
int R_TextWidth(const char *text, int maxChars, FontHandle font)
{
    int lineWidth;
    int maxWidth;
    int count;
    unsigned int letter;
    const Glyph *glyph;

    if (maxChars > 0) {
        /* use provided maxChars */
    } else {
        maxChars = 0x7fffffff;
    }

    lineWidth = 0;
    maxWidth = 0;
    count = 0;

    while (*text && count <= maxChars) {
        letter = ri->SEH_ReadCharFromString(&text, 0);
        if (letter == '\n') {
            lineWidth = 0;
            continue;
        }
        if (letter == '^') {
            if (text && *text != '^' && *text > '/' && *text <= '9') {
                text++;
                continue;
            }
        }
        glyph = R_GetCharacterGlyph(font, letter);
        lineWidth += glyph->dx;
        if (lineWidth > maxWidth) {
            maxWidth = lineWidth;
        }
        count++;
    }

    return maxWidth;
}

/* line 378 */
int R_ConsoleTextWidth(const short int *string, int maxChars, FontHandle font)
{
    const short int *stringRemaining;
    float width;
    char convertedString[1024];
    Bool iconWasFound;
    float iconWidth;
    float iconHeight;
    MaterialHandle iconMaterial;

    if (!string) {
        return 0;
    }

    stringRemaining = string;
    width = 0.0f;

    while (stringRemaining) {
        stringRemaining = R_GetConsoleString(stringRemaining, &maxChars, convertedString, NULL, &iconWasFound);
        width += (float)R_TextWidth(convertedString, maxChars, font);

        if (iconWasFound) {
            stringRemaining = R_GetConsoleIcon(stringRemaining, &maxChars, &iconWidth, &iconHeight, &iconMaterial, NULL, NULL);
            width += iconWidth;
        }
    }

    return (int)width;
}

/* line 417 */
int R_DrawConsoleText(const short int *string, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style)
{
    const short int *stringRemaining;
    float xOfs;
    char convertedString[1024];
    Bool iconWasFound;
    vec4_t curColor;
    float iconWidth;
    float iconHeight;
    MaterialHandle iconMaterial;
    Bool iconHorzFlip;
    float fontPixelHeight;
    float scaledW;
    float scaledH;
    float iconY;
    float iconX;
    int textWidth;

    curColor[0] = color[0];
    curColor[1] = color[1];
    curColor[2] = color[2];
    curColor[3] = color[3];

    if (!string) {
        return 0;
    }

    stringRemaining = string;
    xOfs = 0.0f;

    while (stringRemaining) {
        stringRemaining = R_GetConsoleString(stringRemaining, &maxChars, convertedString, curColor, &iconWasFound);

        if (convertedString[0] != '\0') {
            R_AddCmdDrawTextWithCursor(convertedString, 0x7fffffff, font, x + xOfs, y, xScale, yScale, curColor, style, -1, 0);
        }

        if (!iconWasFound) {
            continue;
        }

        /* compute text width of the converted string to advance xOfs */
        textWidth = R_TextWidth(convertedString, maxChars, font);
        xOfs += (float)textWidth * xScale;

        /* process icon */
        stringRemaining = R_GetConsoleIcon(stringRemaining, &maxChars, &iconWidth, &iconHeight, &iconMaterial, curColor, &iconHorzFlip);

        fontPixelHeight = (float)font->pixelHeight;
        scaledW = xScale * fontPixelHeight * iconWidth;
        iconWidth = scaledW;
        scaledH = yScale * fontPixelHeight * iconHeight;
        iconHeight = scaledH;
        iconY = y + (yScale * fontPixelHeight * 0.800000011920929f + scaledH) * -0.5f;
        iconX = x + xOfs;

        if (iconHorzFlip) {
            R_AddCmdDrawStretchPic(iconX, iconY, scaledW, scaledH, 1.0f, 0.0f, 0.0f, 1.0f, curColor, iconMaterial);
        } else {
            R_AddCmdDrawStretchPic(iconX, iconY, scaledW, scaledH, 0.0f, 0.0f, 1.0f, 1.0f, curColor, iconMaterial);
        }

        xOfs += scaledW;
    }

    return 0;
}

