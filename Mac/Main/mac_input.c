/* Converted to C from ASM: mac_input.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_input.cpp */
/* Linux replacement: SDL2 input handling */

/* SDL2 must come first to avoid __m128 typedef conflict */
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string.h>

/* Prevent common_types.h from redefining __m128 */
#define __m128 __m128_cod2
#include "common_types.h"
#undef __m128
#include "imports.h"

extern void Sys_QueEvent(int time, sysEventType_t type, int value, int value2, int ptrLength, void *ptr);
extern int Sys_Milliseconds(void);
extern void CL_MouseEvent(int dx, int dy);

/* Engine key codes (from keynames table in data.S) */
#define K_TAB         0x09
#define K_ENTER       0x0d
#define K_ESCAPE      0x1b
#define K_SPACE       0x20
#define K_BACKSPACE   0x7f
#define K_CAPSLOCK    0x97
#define K_UPARROW     0x9a
#define K_DOWNARROW   0x9b
#define K_LEFTARROW   0x9c
#define K_RIGHTARROW  0x9d
#define K_ALT         0x9e
#define K_CTRL        0x9f
#define K_SHIFT       0xa0
#define K_INS         0xa1
#define K_DEL         0xa2
#define K_PGDN        0xa3
#define K_PGUP        0xa4
#define K_HOME        0xa5
#define K_END         0xa6
#define K_F1          0xa7
#define K_MOUSE1      0xc8
#define K_MOUSE2      0xc9
#define K_MOUSE3      0xca
#define K_MOUSE4      0xcb
#define K_MOUSE5      0xcc
#define K_MWHEELDOWN  0xcd
#define K_MWHEELUP    0xce

static int mouse_active;

static int sdl_key_to_engine(SDL_Keycode sym)
{
    /* Printable ASCII characters map directly */
    if (sym >= SDLK_a && sym <= SDLK_z)
        return sym; /* a-z = 97-122 */
    if (sym >= SDLK_0 && sym <= SDLK_9)
        return sym; /* 0-9 = 48-57 */

    switch (sym) {
    case SDLK_TAB:       return K_TAB;
    case SDLK_RETURN:    return K_ENTER;
    case SDLK_ESCAPE:    return K_ESCAPE;
    case SDLK_SPACE:     return K_SPACE;
    case SDLK_BACKSPACE: return K_BACKSPACE;
    case SDLK_UP:        return K_UPARROW;
    case SDLK_DOWN:      return K_DOWNARROW;
    case SDLK_LEFT:      return K_LEFTARROW;
    case SDLK_RIGHT:     return K_RIGHTARROW;
    case SDLK_LALT:
    case SDLK_RALT:      return K_ALT;
    case SDLK_LCTRL:
    case SDLK_RCTRL:     return K_CTRL;
    case SDLK_LSHIFT:
    case SDLK_RSHIFT:    return K_SHIFT;
    case SDLK_CAPSLOCK:  return K_CAPSLOCK;
    case SDLK_INSERT:    return K_INS;
    case SDLK_DELETE:    return K_DEL;
    case SDLK_PAGEDOWN:  return K_PGDN;
    case SDLK_PAGEUP:    return K_PGUP;
    case SDLK_HOME:      return K_HOME;
    case SDLK_END:       return K_END;
    case SDLK_F1:  return K_F1;
    case SDLK_F2:  return K_F1 + 1;
    case SDLK_F3:  return K_F1 + 2;
    case SDLK_F4:  return K_F1 + 3;
    case SDLK_F5:  return K_F1 + 4;
    case SDLK_F6:  return K_F1 + 5;
    case SDLK_F7:  return K_F1 + 6;
    case SDLK_F8:  return K_F1 + 7;
    case SDLK_F9:  return K_F1 + 8;
    case SDLK_F10: return K_F1 + 9;
    case SDLK_F11: return K_F1 + 10;
    case SDLK_F12: return K_F1 + 11;
    /* Punctuation that maps to ASCII */
    case SDLK_MINUS:        return '-';
    case SDLK_EQUALS:       return '=';
    case SDLK_LEFTBRACKET:  return '[';
    case SDLK_RIGHTBRACKET: return ']';
    case SDLK_BACKSLASH:    return '\\';
    case SDLK_SEMICOLON:    return ';';
    case SDLK_QUOTE:        return '\'';
    case SDLK_BACKQUOTE:    return '`';
    case SDLK_COMMA:        return ',';
    case SDLK_PERIOD:       return '.';
    case SDLK_SLASH:        return '/';
    default:
        return 0; /* unknown key */
    }
}

void IN_Init(void)
{
    int ret;
    mouse_active = 1;
    /* Hide OS cursor, use relative mode so game cursor tracks from (0,0) */
    SDL_ShowCursor(SDL_DISABLE);
    ret = SDL_SetRelativeMouseMode(SDL_TRUE);
    if (ret != 0) {
        fprintf(stderr, "[IN_Init] SDL_SetRelativeMouseMode FAILED: %s\n", SDL_GetError());
    } else {
        fprintf(stderr, "[IN_Init] SDL_SetRelativeMouseMode OK\n");
    }
}

void IN_Shutdown(void)
{
    mouse_active = 0;
    SDL_SetRelativeMouseMode(SDL_FALSE);
}

void IN_Frame(void)
{
    SDL_Event ev;

    while (SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_QUIT:
            exit(0);
            break;

        case SDL_KEYDOWN:
        case SDL_KEYUP:
            {
                int key = sdl_key_to_engine(ev.key.keysym.sym);
                if (key) {
                    Sys_QueEvent(0, (sysEventType_t)1,
                                 key,
                                 ev.type == SDL_KEYDOWN ? 1 : 0,
                                 0, NULL);
                }
                /* SDL_TEXTINPUT doesn't fire for control keys, so generate
                   SE_CHAR events manually for keys that Field_CharEvent needs */
                if (ev.type == SDL_KEYDOWN) {
                    int ch = 0;
                    switch (ev.key.keysym.sym) {
                    case SDLK_BACKSPACE: ch = 8; break;   /* ctrl-H */
                    case SDLK_RETURN:    ch = 13; break;   /* enter */
                    case SDLK_KP_ENTER:  ch = 13; break;
                    default: break;
                    }
                    if (ch) {
                        Sys_QueEvent(0, (sysEventType_t)2, ch, 0, 0, NULL);
                    }
                }
            }
            break;

        case SDL_MOUSEMOTION:
            if (mouse_active) {
                CL_MouseEvent(ev.motion.xrel, ev.motion.yrel);
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            {
                int key = 0;
                switch (ev.button.button) {
                case SDL_BUTTON_LEFT:   key = K_MOUSE1; break;
                case SDL_BUTTON_RIGHT:  key = K_MOUSE2; break;
                case SDL_BUTTON_MIDDLE: key = K_MOUSE3; break;
                case SDL_BUTTON_X1:     key = K_MOUSE4; break;
                case SDL_BUTTON_X2:     key = K_MOUSE5; break;
                }
                if (key) {
                    Sys_QueEvent(0, (sysEventType_t)1,
                                 key,
                                 ev.type == SDL_MOUSEBUTTONDOWN ? 1 : 0,
                                 0, NULL);
                }
            }
            break;

        case SDL_MOUSEWHEEL:
            if (ev.wheel.y > 0) {
                Sys_QueEvent(0, (sysEventType_t)1, K_MWHEELUP, 1, 0, NULL);
                Sys_QueEvent(0, (sysEventType_t)1, K_MWHEELUP, 0, 0, NULL);
            } else if (ev.wheel.y < 0) {
                Sys_QueEvent(0, (sysEventType_t)1, K_MWHEELDOWN, 1, 0, NULL);
                Sys_QueEvent(0, (sysEventType_t)1, K_MWHEELDOWN, 0, 0, NULL);
            }
            break;

        case SDL_TEXTINPUT:
            {
                int i;
                for (i = 0; ev.text.text[i]; i++) {
                    unsigned char c = (unsigned char)ev.text.text[i];
                    if (c < 128) { /* ASCII only */
                        Sys_QueEvent(0, (sysEventType_t)2, c, 0, 0, NULL);
                    }
                }
            }
            break;
        }
    }
}

/* Mac C++ engine stubs - not used on Linux */
void CCallOfDutyEngine_DoMouseMoved(const void *_this, int inDelta, int inPoint, unsigned int inModifiers)
{
}

void CCallOfDutyEngine_DoMouseWheel(const void *_this, int inDelta, int inPoint, unsigned int inModifiers)
{
}

void CCallOfDutyEngine_DoKeyDown(const void *_this, int inCharCode, unsigned int inKeyCode)
{
}

void CCallOfDutyEngine_DoKeyUp(const void *_this, int inCharCode, unsigned int inKeyCode)
{
}

void CCallOfDutyEngine_DoTextInput(const void *_this, int inUniChar)
{
}

void CCallOfDutyEngine_DoMouseDown(const void *_this, int inButton, int inPoint, unsigned int inModifiers, unsigned int inClickCount)
{
}

void CCallOfDutyEngine_DoMouseUp(const void *_this, int inButton, int inPoint)
{
}
