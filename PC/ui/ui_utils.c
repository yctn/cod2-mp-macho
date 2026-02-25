/* ASM dump from: ui_utils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui/ui_utils.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/ui/ui_utils.h"
 */

static const char *staticNULL; /* 0x3131a0 */
static stringDef_t * g_strHandle[2048]; /* 0xf2f680 */

void Window_SetStaticFlags(Window *w, const int flags);
qboolean Item_EnableShowViaDvar(const itemDef_t *item, int flag);
qboolean Item_IsEditFieldDef(itemDef_t *item);
listBoxDef_t * Item_GetListBoxDef(itemDef_t *item);
multiDef_t * Item_GetMultiDef(itemDef_t *item);
void * UI_Alloc(int size, int alignment);
void String_Init(void);
qboolean Int_Parse(const char * *p, int *i);
qboolean Float_Parse(const char * *p, float *f);
void Window_SetOffsetTime(Window *w, int offsetTime);
void Window_SetRect(Window *w, const UiRectangle *rect);
void Window_SetRectClient(Window *w, const UiRectangle *rectClient);
void Window_SetRectEffects0(Window *w, const UiRectangle *rectEffects0);
void Window_SetRectEffects1(Window *w, const UiRectangle *rectEffects1);
void Window_SetDynamicFlags(Window *w, const int flags);
void Menu_SetCursorItem(menuDef_t *menu, int cursorItem);
void Item_SetTextRect(itemDef_t *item, const rectDef_t *textRect);
void Item_SetCursorPos(itemDef_t *item, int cursorPos);
int Item_GetCursorPosOffset(const itemDef_t *item, const char *text, int delta);
void ListBox_SetCursorPos(listBoxDef_t *listBox, int cursorPos);
void ListBox_SetStartPos(listBoxDef_t *listBox, int startPos);
void ListBox_SetEndPos(listBoxDef_t *listBox, int endPos);
Bool ListBox_HasValidCursorPos(const listBoxDef_t *listBox);
void Window_AddDynamicFlags(Window *w, const int newFlags);
void Window_RemoveDynamicFlags(Window *w, const int newFlags);
editFieldDef_t * Item_GetEditFieldDef(itemDef_t *item);
const char * String_Alloc(const char *p);
void Item_SetScreenCoords(itemDef_t *item, float x, float y, int horzAlign, int vertAlign);
void Menu_UpdatePosition(menuDef_t *menu);
qboolean Rect_Parse(const char * *p, rectDef_t *r);

/* line 155 */
__attribute__((naked))
void Window_SetStaticFlags(Window *w, const int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 155 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 159 | flags */
        "movl 8(%ebp), %eax\n" /* w */
        "movl %edx, 0xe4(%eax)\n"
        "popl %ebp\n" /* line 160 */
        "retl\n"
    );
}

/* line 260 */
__attribute__((naked))
qboolean Item_EnableShowViaDvar(const itemDef_t *item, int flag)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 260 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x82c, %esp\n"
        "movl 8(%ebp), %esi\n" /* item */
        /* { scope 1: val */
        "leal -0x41c(%ebp), %ebx\n" /* line 266 | script */
        "movl $0x400, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memset\n"
        "testl %esi, %esi\n" /* line 267 | item */
        "je .Lf18fd72_0018fe35\n"
        "movl 0x2cc(%esi), %eax\n" /* item */
        "testl %eax, %eax\n"
        "je .Lf18fd72_0018fe35\n"
        "cmpb $0, (%eax)\n"
        "je .Lf18fd72_0018fe35\n"
        "movl 0x2c4(%esi), %eax\n" /* item */
        "testl %eax, %eax\n"
        "je .Lf18fd72_0018fe35\n"
        "cmpb $0, (%eax)\n"
        "je .Lf18fd72_0018fe35\n"
        "movl %eax, (%esp)\n" /* line 269 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, %edi\n" /* testValue */
        "movl 0x2cc(%esi), %eax\n" /* line 271 | item */
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncat\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 272 | p */
        "leal -0x81c(%ebp), %ebx\n" /* val */
        /* { scope 2 */
        ".Lf18fd72_0018fdf6:\n"
        "movl $0x400, 8(%esp)\n" /* line 278 */
        "movl %ebx, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* p */
        "movl %eax, (%esp)\n"
        "calll String_Parse\n"
        "testl %eax, %eax\n"
        "je .Lf18fd72_0018fe7d\n"
        ".Lf18fd72_0018fe11:\n"
        "cmpb $0x3b, -0x81c(%ebp)\n" /* line 283 | val */
        "je .Lf18fd72_0018fe59\n"
        ".Lf18fd72_0018fe1a:\n"
        "movl 0xc(%ebp), %eax\n" /* line 289 | flag */
        "testl %eax, 0x2d0(%esi)\n" /* item */
        "je .Lf18fd72_0018fe45\n"
        "movl %ebx, 4(%esp)\n" /* line 291 */
        "movl %edi, (%esp)\n" /* testValue */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf18fd72_0018fdf6\n"
        ".Lf18fd72_0018fe35:\n"
        "movl $1, %eax\n" /* line 299 */
        /* } scope */
        /* } scope */
        ".Lf18fd72_0018fe3a:\n"
        "addl $0x82c, %esp\n" /* line 308 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: val */
        /* { scope 2 */
        ".Lf18fd72_0018fe45:\n"
        "movl %ebx, 4(%esp)\n" /* line 299 */
        "movl %edi, (%esp)\n" /* testValue */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf18fd72_0018fdf6\n"
        "xorl %eax, %eax\n"
        "jmp .Lf18fd72_0018fe3a\n"
        ".Lf18fd72_0018fe59:\n"
        "cmpb $0, -0x81b(%ebp)\n" /* line 283 */
        "jne .Lf18fd72_0018fe1a\n"
        "movl $0x400, 8(%esp)\n" /* line 278 */
        "movl %ebx, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* p */
        "movl %eax, (%esp)\n"
        "calll String_Parse\n"
        "testl %eax, %eax\n"
        "jne .Lf18fd72_0018fe11\n"
        ".Lf18fd72_0018fe7d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 280 | flag */
        "testl %eax, 0x2d0(%esi)\n" /* item */
        "je .Lf18fd72_0018fe35\n"
        "xorl %eax, %eax\n" /* line 299 */
        "jmp .Lf18fd72_0018fe3a\n"
    );
}

/* line 515 */
__attribute__((naked))
qboolean Item_IsEditFieldDef(itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 515 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* item */
        "cmpl $0x12, 0x274(%eax)\n" /* line 517 */
        "ja .Lf18fe8c_0018feaf\n"
        "movl 0x274(%eax), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x74e11, %eax\n"
        "jne .Lf18fe8c_0018feb3\n"
        ".Lf18fe8c_0018feaf:\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n" /* line 533 */
        "retl\n"
        ".Lf18fe8c_0018feb3:\n"
        "movl $1, %eax\n" /* line 517 */
        "popl %ebp\n" /* line 533 */
        "retl\n"
    );
}

/* line 536 */
__attribute__((naked))
listBoxDef_t * Item_GetListBoxDef(itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 536 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* item */
        "cmpl $6, 0x274(%eax)\n" /* line 538 */
        "jne .Lf18feba_0018fed4\n"
        "movl 0x2ec(%eax), %eax\n" /* line 539 */
        "leave\n" /* line 542 */
        "retl\n"
        ".Lf18feba_0018fed4:\n"
        "movl $0x2b004c, (%esp)\n" /* line 540 */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 542 */
        "retl\n"
    );
}

/* line 554 */
__attribute__((naked))
multiDef_t * Item_GetMultiDef(itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 554 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* item */
        "movl 0x2ec(%eax), %eax\n" /* item */
        "popl %ebp\n" /* line 559 */
        "retl\n"
    );
}

/* line 591 */
__attribute__((naked))
void * UI_Alloc(int size, int alignment)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 591 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 594 */
        "jmp Hunk_AllocAlignInternal\n" /* line 593 */
    );
}

/* line 602 */
__attribute__((naked))
void String_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 602 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2000, 8(%esp)\n" /* line 604 */
        "movl $0, 4(%esp)\n"
        "movl $g_strHandle, (%esp)\n"
        "calll memset\n"
        "leave\n" /* line 605 */
        "retl\n"
    );
}

/* line 674 */
__attribute__((naked))
qboolean Int_Parse(const char * *p, int *i)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 674 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 678 | p */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "testl %eax, %eax\n" /* line 680 */
        "je .Lf18ff20_0018ff3a\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf18ff20_0018ff3e\n"
        ".Lf18ff20_0018ff3a:\n"
        "xorl %eax, %eax\n" /* line 683 */
        /* } scope */
        "leave\n" /* line 687 */
        "retl\n"
        /* { scope 1 */
        ".Lf18ff20_0018ff3e:\n"
        "movl %eax, (%esp)\n" /* line 682 */
        "calll atoi\n"
        "movl 0xc(%ebp), %edx\n" /* i */
        "movl %eax, (%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        "leave\n" /* line 687 */
        "retl\n"
    );
}

/* line 695 */
__attribute__((naked))
qboolean Float_Parse(const char * *p, float *f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 695 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 699 | p */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "testl %eax, %eax\n" /* line 700 */
        "je .Lf18ff52_0018ff6c\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf18ff52_0018ff70\n"
        ".Lf18ff52_0018ff6c:\n"
        "xorl %eax, %eax\n" /* line 703 */
        /* } scope */
        "leave\n" /* line 707 */
        "retl\n"
        /* { scope 1 */
        ".Lf18ff52_0018ff70:\n"
        "movl %eax, (%esp)\n" /* line 702 */
        "calll atof\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* f */
        "movss %xmm0, (%eax)\n"
        "movl $1, %eax\n"
        /* } scope */
        "leave\n" /* line 707 */
        "retl\n"
    );
}

/* line 41 */
__attribute__((naked))
void Window_SetOffsetTime(Window *w, int offsetTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 41 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 44 | offsetTime */
        "movl 8(%ebp), %eax\n" /* w */
        "movl %edx, 0x1b8(%eax)\n"
        "popl %ebp\n" /* line 50 */
        "retl\n"
    );
}

/* line 53 */
__attribute__((naked))
void Window_SetRect(Window *w, const UiRectangle *rect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 53 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* w */
        "movl 0xc(%ebp), %edx\n" /* rect */
        "movl (%edx), %eax\n" /* line 60 */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "popl %ebp\n" /* line 66 */
        "retl\n"
    );
}

/* line 69 */
__attribute__((naked))
void Window_SetRectClient(Window *w, const UiRectangle *rectClient)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* w */
        "movl 0xc(%ebp), %edx\n" /* rectClient */
        "leal 0x60(%ebx), %ecx\n" /* line 76 | w */
        "movl (%edx), %eax\n"
        "movl %eax, 0x60(%ebx)\n" /* w */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "popl %ebx\n" /* line 82 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 85 */
__attribute__((naked))
void Window_SetRectEffects0(Window *w, const UiRectangle *rectEffects0)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 85 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* w */
        "movl 0xc(%ebp), %edx\n" /* rectEffects0 */
        "leal 0xf8(%ebx), %ecx\n" /* line 92 | w */
        "movl (%edx), %eax\n"
        "movl %eax, 0xf8(%ebx)\n" /* w */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "popl %ebx\n" /* line 98 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 101 */
__attribute__((naked))
void Window_SetRectEffects1(Window *w, const UiRectangle *rectEffects1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 101 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* w */
        "movl 0xc(%ebp), %edx\n" /* rectEffects1 */
        "leal 0x158(%ebx), %ecx\n" /* line 108 | w */
        "movl (%edx), %eax\n"
        "movl %eax, 0x158(%ebx)\n" /* w */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "popl %ebx\n" /* line 114 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 117 */
__attribute__((naked))
void Window_SetDynamicFlags(Window *w, const int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 117 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 122 | flags */
        "movl 8(%ebp), %eax\n" /* w */
        "movl %edx, 0xe8(%eax)\n"
        "popl %ebp\n" /* line 128 */
        "retl\n"
    );
}

/* line 163 */
__attribute__((naked))
void Menu_SetCursorItem(menuDef_t *menu, int cursorItem)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 163 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 167 | cursorItem */
        "movl 8(%ebp), %eax\n" /* menu */
        "movl %edx, 0x220(%eax)\n"
        "popl %ebp\n" /* line 173 */
        "retl\n"
    );
}

/* line 312 */
__attribute__((naked))
void Item_SetTextRect(itemDef_t *item, const rectDef_t *textRect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 312 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %edx\n" /* textRect */
        "leal 0x210(%ebx), %ecx\n" /* line 319 | item */
        "movl (%edx), %eax\n"
        "movl %eax, 0x210(%ebx)\n" /* item */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "popl %ebx\n" /* line 325 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 328 */
__attribute__((naked))
void Item_SetCursorPos(itemDef_t *item, int cursorPos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 328 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 332 | cursorPos */
        "movl 8(%ebp), %eax\n" /* item */
        "movl %edx, 0x2dc(%eax)\n"
        "popl %ebp\n" /* line 338 */
        "retl\n"
    );
}

/* line 342 */
__attribute__((naked))
int Item_GetCursorPosOffset(const itemDef_t *item, const char *text, int delta)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 342 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %esi\n" /* text */
        "movl 0x10(%ebp), %ebx\n" /* delta */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 106 | item */
        "movl 0x2dc(%eax), %eax\n"
        "testl %ebx, %ebx\n" /* line 347 | delta */
        "jg .Lf1900e6_0019010f\n"
        "jmp .Lf1900e6_00190150\n"
        ".Lf1900e6_00190100:\n"
        "cmpb $0, (%edx)\n" /* line 369 */
        "je .Lf1900e6_00190175\n"
        "testl %ebx, %ebx\n" /* delta */
        "je .Lf1900e6_00190175\n"
        "addl $1, %eax\n" /* line 372 */
        "subl $1, %ebx\n" /* line 373 | delta */
        ".Lf1900e6_0019010f:\n"
        "movl %eax, %edx\n" /* line 366 */
        "addl %esi, %edx\n" /* text */
        "je .Lf1900e6_00190100\n"
        "cmpb $0x5e, (%edx)\n"
        "jne .Lf1900e6_00190100\n"
        "movzbl 1(%edx), %ecx\n"
        "testb %cl, %cl\n"
        "je .Lf1900e6_00190100\n"
        "cmpb $0x5e, %cl\n"
        "je .Lf1900e6_00190100\n"
        "cmpb $0x2f, %cl\n"
        "jle .Lf1900e6_00190100\n"
        "cmpb $0x39, %cl\n"
        "jg .Lf1900e6_00190100\n"
        "addl $2, %eax\n" /* line 367 */
        "jmp .Lf1900e6_0019010f\n"
        ".Lf1900e6_00190136:\n"
        "movzbl -1(%edx), %edx\n" /* line 351 */
        "testb %dl, %dl\n"
        "je .Lf1900e6_0019016b\n"
        "cmpb $0x5e, %dl\n"
        "je .Lf1900e6_0019016b\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lf1900e6_0019016b\n"
        "cmpb $0x39, %dl\n"
        "jg .Lf1900e6_0019016b\n"
        "subl $2, %eax\n" /* line 353 */
        ".Lf1900e6_00190150:\n"
        "testl %eax, %eax\n" /* line 349 */
        "je .Lf1900e6_00190175\n"
        ".Lf1900e6_00190154:\n"
        "testl %ebx, %ebx\n" /* delta */
        "je .Lf1900e6_00190175\n"
        "cmpl $1, %eax\n" /* line 351 */
        "jle .Lf1900e6_0019016b\n"
        "leal (%esi, %eax), %edx\n" /* text */
        "cmpl $2, %edx\n"
        "je .Lf1900e6_0019016b\n"
        "cmpb $0x5e, -2(%edx)\n"
        "je .Lf1900e6_00190136\n"
        ".Lf1900e6_0019016b:\n"
        "subl $1, %eax\n" /* line 357 */
        "addl $1, %ebx\n" /* line 358 | delta */
        "testl %eax, %eax\n" /* line 349 */
        "jne .Lf1900e6_00190154\n"
        /* } scope */
        ".Lf1900e6_00190175:\n"
        "popl %ebx\n" /* line 377 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 380 */
__attribute__((naked))
void ListBox_SetCursorPos(listBoxDef_t *listBox, int cursorPos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 380 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 384 | cursorPos */
        "movl 8(%ebp), %eax\n" /* listBox */
        "movl %edx, 0x24(%eax)\n"
        "popl %ebp\n" /* line 390 */
        "retl\n"
    );
}

/* line 393 */
__attribute__((naked))
void ListBox_SetStartPos(listBoxDef_t *listBox, int startPos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 393 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 397 | startPos */
        "movl 8(%ebp), %eax\n" /* listBox */
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 403 */
        "retl\n"
    );
}

/* line 406 */
__attribute__((naked))
void ListBox_SetEndPos(listBoxDef_t *listBox, int endPos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 406 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 410 | endPos */
        "movl 8(%ebp), %eax\n" /* listBox */
        "movl %edx, 0x10(%eax)\n"
        "popl %ebp\n" /* line 416 */
        "retl\n"
    );
}

/* line 419 */
__attribute__((naked))
Bool ListBox_HasValidCursorPos(const listBoxDef_t *listBox)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 419 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* listBox */
        /* { scope 1 */
        "movl 0x24(%eax), %edx\n" /* line 113 */
        "cmpl 0x10(%eax), %edx\n" /* line 427 */
        "jge .Lf1901a4_001901b6\n"
        "cmpl (%eax), %edx\n" /* line 431 */
        "jge .Lf1901a4_001901ba\n"
        ".Lf1901a4_001901b6:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 435 */
        "retl\n"
        /* { scope 1 */
        ".Lf1901a4_001901ba:\n"
        "movl $1, %eax\n" /* line 431 */
        /* } scope */
        "popl %ebp\n" /* line 435 */
        "retl\n"
    );
}

/* line 131 */
__attribute__((naked))
void Window_AddDynamicFlags(Window *w, const int newFlags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 131 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* w */
        "movl 0xc(%ebp), %eax\n" /* line 122 | newFlags */
        "orl %eax, 0xe8(%edx)\n"
        "popl %ebp\n" /* line 137 */
        "retl\n"
    );
}

/* line 140 */
__attribute__((naked))
void Window_RemoveDynamicFlags(Window *w, const int newFlags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 140 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* w */
        "movl 0xc(%ebp), %eax\n" /* newFlags */
        /* { scope 1 */
        "movl 0xe8(%ecx), %edx\n" /* line 80 */
        "testb $4, %al\n" /* line 147 */
        "je .Lf1901d6_001901ec\n"
        "orl $2, %eax\n" /* line 148 */
        ".Lf1901d6_001901ec:\n"
        "notl %eax\n" /* line 122 */
        "andl %eax, %edx\n"
        "movl %edx, 0xe8(%ecx)\n"
        /* } scope */
        "popl %ebp\n" /* line 151 */
        "retl\n"
    );
}

/* line 545 */
__attribute__((naked))
editFieldDef_t * Item_GetEditFieldDef(itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 545 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* item */
        "cmpl $0x12, 0x274(%edx)\n" /* line 517 */
        "ja .Lf1901f8_00190226\n"
        "movl 0x274(%edx), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x74e11, %eax\n"
        "je .Lf1901f8_00190226\n"
        "movl 0x2ec(%edx), %eax\n" /* line 548 */
        "leave\n" /* line 551 */
        "retl\n"
        ".Lf1901f8_00190226:\n"
        "movl $0x2b0080, (%esp)\n" /* line 549 */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 551 */
        "retl\n"
    );
}

/* line 608 */
__attribute__((naked))
const char * String_Alloc(const char *p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 608 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* p */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 618 | p */
        "je .Lf190236_00190334\n"
        "movzbl (%esi), %eax\n" /* line 623 | p */
        "testb %al, %al\n"
        "je .Lf190236_00190324\n"
        "xorl %ebx, %ebx\n" /* line 625 | hash */
        "movl $0x77, %edi\n" /* s */
        /* { scope 2 */
        ".Lf190236_0019025c:\n"
        "movsbl %al, %eax\n" /* line 577 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "imull %edi, %eax\n" /* line 578 */
        "addl %eax, %ebx\n" /* hash */
        "movzbl -0x76(%esi, %edi), %eax\n" /* line 575 */
        "addl $1, %edi\n"
        "testb %al, %al\n"
        "jne .Lf190236_0019025c\n"
        "andl $0x7ff, %ebx\n" /* line 581 | hash */
        "movl %ebx, -0x1c(%ebp)\n" /* hash */
        /* } scope */
        "movl g_strHandle(, %ebx, 4), %edi\n" /* line 630 | s */
        "testl %edi, %edi\n" /* line 631 | s */
        "je .Lf190236_001902a9\n"
        ".Lf190236_0019028c:\n"
        "movl 4(%edi), %ebx\n" /* line 634 | s, hash */
        "movl %ebx, 4(%esp)\n" /* hash */
        "movl %esi, (%esp)\n" /* p */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf190236_0019032a\n"
        "movl (%edi), %edi\n" /* line 638 | s */
        "testl %edi, %edi\n" /* line 631 | s */
        "jne .Lf190236_0019028c\n"
        ".Lf190236_001902a9:\n"
        "movl $1, 4(%esp)\n" /* line 593 */
        "cld\n" /* line 641 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* p, s */
        "repne scasb %es:(%edi), %al\n" /* s */
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %edi\n" /* s */
        "movl %esi, 4(%esp)\n" /* line 644 | p */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x1c(%ebp), %edx\n" /* line 646 | hash */
        "movl g_strHandle(, %edx, 4), %ebx\n" /* hash */
        "testl %ebx, %ebx\n" /* line 648 | hash */
        "je .Lf190236_001902f5\n"
        "movl (%ebx), %eax\n" /* hash */
        "testl %eax, %eax\n"
        "jne .Lf190236_001902ef\n"
        "jmp .Lf190236_001902f5\n"
        ".Lf190236_001902eb:\n"
        "movl %eax, %ebx\n" /* hash */
        "movl %edx, %eax\n"
        ".Lf190236_001902ef:\n"
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf190236_001902eb\n"
        ".Lf190236_001902f5:\n"
        "movl $4, 4(%esp)\n" /* line 593 */
        "movl $8, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl $0, (%eax)\n" /* line 655 */
        "movl %edi, 4(%eax)\n" /* line 656 | s */
        "testl %ebx, %ebx\n" /* line 657 | hash */
        "je .Lf190236_00190340\n"
        "movl %eax, (%ebx)\n" /* line 659 | hash */
        "movl %edi, %ebx\n" /* line 665 | s, hash */
        /* } scope */
        ".Lf190236_0019031a:\n"
        "movl %ebx, %eax\n" /* line 666 | hash */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf190236_00190324:\n"
        "movl staticNULL, %ebx\n" /* line 625 | hash */
        /* } scope */
        ".Lf190236_0019032a:\n"
        "movl %ebx, %eax\n" /* line 666 | hash */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf190236_00190334:\n"
        "xorl %ebx, %ebx\n" /* line 618 | hash */
        /* } scope */
        "movl %ebx, %eax\n" /* line 666 | hash */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf190236_00190340:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 663 | hash */
        "movl %eax, g_strHandle(, %edx, 4)\n"
        "movl %edi, %ebx\n" /* line 665 | s, hash */
        "jmp .Lf190236_0019031a\n"
    );
}

/* line 440 */
__attribute__((naked))
void Item_SetScreenCoords(itemDef_t *item, float x, float y, int horzAlign, int vertAlign)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 440 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movss 0xc(%ebp), %xmm1\n" /* x */
        "movss 0x10(%ebp), %xmm2\n" /* y */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 448 | item */
        "je .Lf19034e_00190423\n"
        "movl 0xd4(%ebx), %esi\n" /* line 453 | item */
        "testl %esi, %esi\n"
        "jne .Lf19034e_00190447\n"
        ".Lf19034e_0019037a:\n"
        "leal 0x60(%ebx), %edx\n" /* line 60 */
        "movl 0x10(%ebx), %eax\n" /* line 462 | item */
        "movl %eax, -0x18(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* item */
        "movl %eax, -0x14(%ebp)\n"
        "addss 0x60(%ebx), %xmm1\n" /* line 463 | item */
        "movss %xmm1, -0x28(%ebp)\n" /* newRect */
        "addss 4(%edx), %xmm2\n" /* line 464 */
        "movss %xmm2, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 465 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%edx), %eax\n" /* line 466 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x10(%edx), %eax\n" /* line 467 */
        "testl %eax, %eax\n"
        "je .Lf19034e_0019042b\n"
        ".Lf19034e_001903b0:\n"
        "movl %eax, -0x18(%ebp)\n" /* line 474 */
        "movl 0x14(%edx), %eax\n" /* line 475 */
        "movl %eax, -0x14(%ebp)\n"
        ".Lf19034e_001903b9:\n"
        "movl -0x28(%ebp), %eax\n" /* line 60 | newRect */
        "movl %eax, (%ebx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl -0x18(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl -0x14(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl 0x210(%ebx), %eax\n" /* line 480 | item */
        "movl %eax, -0x28(%ebp)\n" /* newRect */
        "movl 0x214(%ebx), %ecx\n" /* item */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x220(%ebx), %edi\n" /* item */
        "movl %edi, -0x18(%ebp)\n"
        "movl 0x224(%ebx), %esi\n" /* item */
        "movl %esi, -0x14(%ebp)\n"
        "xorl %eax, %eax\n" /* line 482 */
        "movl %eax, -0x20(%ebp)\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 483 */
        "leal 0x210(%ebx), %edx\n" /* line 319 */
        "movl %ecx, 4(%edx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl %edi, 0x10(%edx)\n"
        "movl %esi, 0x14(%edx)\n"
        /* } scope */
        ".Lf19034e_00190423:\n"
        "addl $0x24, %esp\n" /* line 485 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19034e_0019042b:\n"
        "movl 0x14(%edx), %ecx\n" /* line 467 */
        "testl %ecx, %ecx\n"
        "jne .Lf19034e_001903b0\n"
        "movl 0x14(%ebp), %eax\n" /* line 469 | horzAlign */
        "movl %eax, -0x18(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 470 | vertAlign */
        "movl %eax, -0x14(%ebp)\n"
        "jmp .Lf19034e_001903b9\n"
        ".Lf19034e_00190447:\n"
        "movss 0xe0(%ebx), %xmm0\n" /* line 455 | item */
        "addss %xmm0, %xmm1\n"
        "addss %xmm0, %xmm2\n" /* line 456 */
        "jmp .Lf19034e_0019037a\n"
    );
}

/* line 488 */
__attribute__((naked))
void Menu_UpdatePosition(menuDef_t *menu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 488 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %ebx\n" /* menu */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 494 | menu */
        "je .Lf19045c_00190492\n"
        "movss (%ebx), %xmm0\n" /* line 500 | menu */
        "movss %xmm0, -0x10(%ebp)\n" /* x */
        "movss 4(%ebx), %xmm1\n" /* line 501 | menu */
        "movss %xmm1, -0xc(%ebp)\n" /* y */
        "movl 0xd4(%ebx), %eax\n" /* line 502 | menu */
        "testl %eax, %eax\n"
        "jne .Lf19045c_00190499\n"
        "movl 0x218(%ebx), %eax\n" /* line 508 | menu */
        "testl %eax, %eax\n"
        "jg .Lf19045c_001904c1\n"
        /* } scope */
        ".Lf19045c_00190492:\n"
        "addl $0x30, %esp\n" /* line 512 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19045c_00190499:\n"
        "movaps %xmm0, %xmm1\n"
        /* { scope 1 */
        "movss 0xe0(%ebx), %xmm0\n" /* line 504 | menu */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n" /* x */
        "addss -0xc(%ebp), %xmm0\n" /* line 505 | y */
        "movss %xmm0, -0xc(%ebp)\n" /* y */
        "movl 0x218(%ebx), %eax\n" /* line 508 | menu */
        "testl %eax, %eax\n"
        "jle .Lf19045c_00190492\n"
        ".Lf19045c_001904c1:\n"
        "xorl %esi, %esi\n" /* i */
        ".Lf19045c_001904c3:\n"
        "movl 0x14(%ebx), %eax\n" /* line 510 | menu */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* menu */
        "movl %eax, 0xc(%esp)\n"
        "movss -0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x10(%ebp), %xmm1\n" /* x */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x27c(%ebx), %eax\n" /* menu */
        "movl (%eax, %esi, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Item_SetScreenCoords\n"
        "addl $1, %esi\n" /* line 508 | i */
        "cmpl 0x218(%ebx), %esi\n" /* menu, i */
        "jl .Lf19045c_001904c3\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 512 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 715 */
__attribute__((naked))
qboolean Rect_Parse(const char * *p, rectDef_t *r)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 715 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* p */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 699 */
        "calll Com_ParseOnLine\n"
        "testl %eax, %eax\n" /* line 700 */
        "je .Lf19050a_00190525\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf19050a_0019052d\n"
        /* } scope */
        /* { scope 1 */
        ".Lf19050a_00190525:\n"
        "xorl %eax, %eax\n" /* line 702 */
        /* } scope */
        ".Lf19050a_00190527:\n"
        "addl $0x34, %esp\n" /* line 731 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19050a_0019052d:\n"
        "movl %eax, (%esp)\n" /* line 702 */
        "calll atof\n"
        "fstpl -0x28(%ebp)\n"
        "cvtsd2ss -0x28(%ebp), %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* r */
        "movss %xmm0, (%eax)\n"
        /* } scope */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 699 */
        "calll Com_ParseOnLine\n"
        "testl %eax, %eax\n" /* line 700 */
        "je .Lf19050a_00190525\n"
        "cmpb $0, (%eax)\n"
        "je .Lf19050a_00190525\n"
        "movl %eax, (%esp)\n" /* line 702 */
        "calll atof\n"
        "fstpl -0x20(%ebp)\n"
        "cvtsd2ss -0x20(%ebp), %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* r */
        "movss %xmm0, 4(%eax)\n"
        /* } scope */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 699 */
        "calll Com_ParseOnLine\n"
        "testl %eax, %eax\n" /* line 700 */
        "je .Lf19050a_00190525\n"
        "cmpb $0, (%eax)\n"
        "je .Lf19050a_00190525\n"
        "movl %eax, (%esp)\n" /* line 702 */
        "calll atof\n"
        "fstpl -0x18(%ebp)\n"
        "cvtsd2ss -0x18(%ebp), %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* r */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 699 */
        "calll Com_ParseOnLine\n"
        "testl %eax, %eax\n" /* line 700 */
        "je .Lf19050a_00190525\n"
        "cmpb $0, (%eax)\n"
        "je .Lf19050a_00190525\n"
        "movl %eax, (%esp)\n" /* line 702 */
        "calll atof\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* r */
        "movss %xmm0, 0xc(%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lf19050a_00190527\n"
    );
}

