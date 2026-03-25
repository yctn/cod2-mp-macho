/* Converted from stubs/final_stubs.S */
#include "common_types.h"

/* __ZZ29Material_TechniqueTypeForNamePKcE5C.359 — dot in name, using safe alias */
const char *Material_TechniqueNames[] = {
    "\"depth prepass\"",
    "\"sky\"",
    "\"build floatz\"",
    "\"unlit no fog\"",
    "\"unlit linear fog\"",
    "\"unlit exp fog\"",
    "\"lightmap no fog\"",
    "\"lightmap linear fog\"",
    "\"lightmap exp fog\"",
    "\"lightprobe no fog\"",
    "\"lightprobe linear fog\"",
    "\"lightprobe exp fog\"",
    "\"lightprobe smodel no fog\"",
    "\"lightprobe smodel linear fog\"",
    "\"lightprobe smodel exp fog\"",
    "\"lightprobe smodel cached no fog\"",
    "\"lightprobe smodel cached linear fog\"",
    "\"lightprobe smodel cached exp fog\"",
    "\"pointlight no fog\"",
    "\"pointlight linear fog\"",
    "\"pointlight exp fog\"",
    "\"emissive no fog\"",
    "\"emissive linear fog\"",
    "\"emissive exp fog\"",
    "\"emissive feathered no fog\"",
    "\"emissive feathered linear fog\"",
    "\"emissive feathered exp fog\"",
    "\"fakelight normal\"",
    "\"fakelight view\"",
    "\"solid wireframe\"",
    "\"shaded wireframe\"",
    "\"shadowcookie caster\"",
    "\"shadowcookie receiver\"",
    "\"debug bumpmap\""
};

/* Alias for s_techniqueTypeNames used by r_material_load_obj.c.
 * Must be an array (not pointer) so memcpy copies from array data. */
extern const char * const s_techniqueTypeNames[] __attribute__((alias("Material_TechniqueNames")));

/* Preserve the original linker symbol name without colliding with the typedef. */
char material_tech_string[1024] __asm__("string") = {0};
