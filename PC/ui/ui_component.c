/* Converted to C from ASM: ui_component.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui/ui_component.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern UI_Component_data_t UI_Component_g; /* 0x195af20 */
extern byte *ui_globals_195ecac;  /* 0x195ecac */
extern byte *ui_vtable_195eca8;   /* 0x195eca8 */
extern byte *ui_maxclients_195ecc0; /* 0x195ecc0 */

inflate_huft UI_Component_Init(void);

/* line 31 */
inflate_huft UI_Component_Init(void)
{
    byte *globals;
    byte *vtable;
    MaterialHandle mat;

    globals = *(byte **)&ui_globals_195ecac;

    /* Check if initialized */
    if (*(int *)(globals + 0x110) == 0)
        return *(inflate_huft *)&globals; /* early return, value unused */

    /* Clear component data */
    memset(&UI_Component_g, 0, 0xac);

    /* Set screen dimensions from globals */
    UI_Component_g.screenWidth = (float)*(int *)(globals + 0x2a0a64);
    UI_Component_g.screenHeight = (float)*(int *)(globals + 0x2a0a68);

    /* Set default sizes */
    UI_Component_g.charWidth = 8.0f;
    UI_Component_g.charHeight = 16.0f;
    UI_Component_g.scrollBarSize = 16.0f;

    /* Check if clients exist */
    {
        int *ptr = *(int **)&ui_maxclients_195ecc0;
        int maxClients = *(int *)(*(int *)ptr + 8);
        if (maxClients == 0)
            return *(inflate_huft *)&globals;
    }

    /* Register UI materials */
    vtable = *(byte **)&ui_vtable_195eca8;
    {
        typedef MaterialHandle (*RegisterMaterialFn)(const char *, int, int);
        RegisterMaterialFn registerMat = *(RegisterMaterialFn *)(vtable + 0x10);

        UI_Component_g.cursor = registerMat("ui/assets/3_cursor3", 0x30, 1);
        UI_Component_g.filledCircle = registerMat("ui/assets/sliderbutt_1", 0x30, 1);
    }
}
