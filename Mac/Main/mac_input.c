/* Converted to C from ASM: mac_input.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_input.cpp */
/* Linux replacement: SDL2 input handling */

/* SDL2 must come first to avoid __m128 typedef conflict */
#include <SDL2/SDL.h>

/* Prevent common_types.h from redefining __m128 */
#define __m128 __m128_cod2
#include "common_types.h"
#undef __m128
#include "imports.h"

extern void Sys_QueEvent(int time, sysEventType_t type, int value, int value2, int ptrLength, void *ptr);
extern int Sys_Milliseconds(void);
extern void CL_MouseEvent(int dx, int dy);

static int mouse_active;

void IN_Init(void)
{
    mouse_active = 1;
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

void IN_Shutdown(void)
{
    mouse_active = 0;
    SDL_SetRelativeMouseMode(SDL_FALSE);
}

void IN_Frame(void)
{
    /* Poll SDL events and queue them for the engine */
    SDL_Event ev;

    while (SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_QUIT:
            Sys_QueEvent(0, (sysEventType_t)0, 0, 0, 0, NULL);
            break;

        case SDL_KEYDOWN:
        case SDL_KEYUP:
            Sys_QueEvent(0, (sysEventType_t)1,
                         ev.key.keysym.scancode,
                         ev.type == SDL_KEYDOWN ? 1 : 0,
                         0, NULL);
            break;

        case SDL_MOUSEMOTION:
            if (mouse_active) {
                CL_MouseEvent(ev.motion.xrel, ev.motion.yrel);
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            {
                int button = 0;
                switch (ev.button.button) {
                case SDL_BUTTON_LEFT:   button = 1; break;
                case SDL_BUTTON_RIGHT:  button = 2; break;
                case SDL_BUTTON_MIDDLE: button = 3; break;
                }
                Sys_QueEvent(0, (sysEventType_t)1,
                             0x100 + button,
                             ev.type == SDL_MOUSEBUTTONDOWN ? 1 : 0,
                             0, NULL);
            }
            break;

        case SDL_MOUSEWHEEL:
            if (ev.wheel.y > 0) {
                Sys_QueEvent(0, (sysEventType_t)1, 0x104, 1, 0, NULL);
                Sys_QueEvent(0, (sysEventType_t)1, 0x104, 0, 0, NULL);
            } else if (ev.wheel.y < 0) {
                Sys_QueEvent(0, (sysEventType_t)1, 0x105, 1, 0, NULL);
                Sys_QueEvent(0, (sysEventType_t)1, 0x105, 0, 0, NULL);
            }
            break;

        case SDL_TEXTINPUT:
            /* Queue text input as character events */
            {
                int i;
                for (i = 0; ev.text.text[i]; i++) {
                    Sys_QueEvent(0, (sysEventType_t)2, ev.text.text[i], 0, 0, NULL);
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
