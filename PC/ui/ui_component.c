/* Converted to C from ASM: ui_component.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui/ui_component.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern UI_Component_data_t UI_Component_g; /* __ZN12UI_Component1gE */
extern void *imp_cls;
extern void *imp_re;
extern refexport_t re; /* imp_re */
extern void *imp_com_developer;

void UI_Component_Init(void);

/* line 31 */
void UI_Component_Init(void)
{
    byte *globals;
    byte *developerDvar;

    globals = (byte *)imp_cls;

    /* Check if initialized */
    if (!((clientStatic_t *)globals)->uiStarted)
        return;

    /* Clear component data */
    memset(&UI_Component_g, 0, 0xac);

    /* Set screen dimensions from globals */
    UI_Component_g.screenWidth = (float)*(int *)(globals + 0x2a0a64);
    UI_Component_g.screenHeight = (float)*(int *)(globals + 0x2a0a68);

    /* Set default sizes */
    UI_Component_g.charWidth = 8.0f;
    UI_Component_g.charHeight = 16.0f;
    UI_Component_g.scrollBarSize = 16.0f;

    /* This component layer is only active when developer mode is enabled. */
    {
        developerDvar = *(byte **)imp_com_developer;
        if (*(int *)(developerDvar + 8) == 0)
            return;
    }

    /* Register UI materials */
    UI_Component_g.cursor = re.RegisterMaterial("ui/assets/3_cursor3", 0x30, 1);
    UI_Component_g.filledCircle = re.RegisterMaterial("ui/assets/sliderbutt_1", 0x30, 1);
}
