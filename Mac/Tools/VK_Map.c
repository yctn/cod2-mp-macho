/* Converted to C from ASM: VK_Map.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/VK_Map.cp */

#include "common_types.h"
#include "imports.h"

extern UInt8 sFrench_ISO_VK_Map[128]; /* 0x0 */
extern UInt8 sGerman_ISO_VK_Map[128]; /* 0x0 */
static UInt8 *sCachedVKMap; /* 0x334c80 */
static UInt8 sANSI_VK_Map[128]; /* 0x3081c0 */

extern SInt32 MacResources_GetLanguageCode(void);

UInt8 TranslateKeyCodeToVK(UInt32 inKeyCode)
{
    if (!sCachedVKMap) {
        int lang = MacResources_GetLanguageCode();
        if (lang == 1) {
            sCachedVKMap = sFrench_ISO_VK_Map;
        } else {
            if (MacResources_GetLanguageCode() == 2)
                sCachedVKMap = sGerman_ISO_VK_Map;
            else
                sCachedVKMap = sANSI_VK_Map;
        }
    }
    return sCachedVKMap[inKeyCode];
}
