/* ASM dump from: scr_const_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/scr_const_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern struct scr_const_t scr_const; /* 0x0 */

extern unsigned int GScr_AllocString(const char *s);
extern void Com_Printf(const char *fmt, ...);

void GScr_LoadConsts(void);

/* line 11 */
void GScr_LoadConsts(void)
{
    scr_const._ = GScr_AllocString("");                              /* line 13 */
    scr_const.allies = GScr_AllocString("allies");                   /* line 14 */
    scr_const.axis = GScr_AllocString("axis");                       /* line 15 */
    scr_const.current = GScr_AllocString("current");                 /* line 16 */
    scr_const.damage = GScr_AllocString("damage");                   /* line 17 */
    scr_const.death = GScr_AllocString("death");                     /* line 18 */
    scr_const.dlight = GScr_AllocString("dlight");                   /* line 19 */
    scr_const.done = GScr_AllocString("done");                       /* line 20 */
    scr_const.empty = GScr_AllocString("empty");                     /* line 21 */
    scr_const.entity = GScr_AllocString("entity");                   /* line 22 */
    scr_const.failed = GScr_AllocString("failed");                   /* line 23 */
    scr_const.fraction = GScr_AllocString("fraction");               /* line 24 */
    scr_const.goal = GScr_AllocString("goal");                       /* line 25 */
    scr_const.grenade = GScr_AllocString("grenade");                 /* line 26 */
    scr_const.info_notnull = GScr_AllocString("info_notnull");       /* line 27 */
    scr_const.invisible = GScr_AllocString("invisible");             /* line 28 */
    scr_const.key1 = GScr_AllocString("key1");                       /* line 29 */
    scr_const.key2 = GScr_AllocString("key2");                       /* line 30 */
    scr_const.killanimscript = GScr_AllocString("killanimscript");   /* line 31 */
    scr_const.left = GScr_AllocString("left");                       /* line 32 */
    scr_const.movedone = GScr_AllocString("movedone");               /* line 33 */
    scr_const.noclass = GScr_AllocString("noclass");                 /* line 34 */
    scr_const.normal = GScr_AllocString("normal");                   /* line 35 */
    scr_const.pistol = GScr_AllocString("pistol");                   /* line 36 */
    scr_const.plane_waypoint = GScr_AllocString("plane_waypoint");   /* line 37 */
    scr_const.player = GScr_AllocString("player");                   /* line 38 */
    scr_const.position = GScr_AllocString("position");               /* line 39 */
    scr_const.primary = GScr_AllocString("primary");                 /* line 40 */
    scr_const.primaryb = GScr_AllocString("primaryb");               /* line 41 */
    scr_const.prone = GScr_AllocString("prone");                     /* line 42 */
    scr_const.right = GScr_AllocString("right");                     /* line 43 */
    scr_const.rocket = GScr_AllocString("rocket");                   /* line 44 */
    scr_const.rotatedone = GScr_AllocString("rotatedone");           /* line 45 */
    scr_const.script_brushmodel = GScr_AllocString("script_brushmodel"); /* line 46 */
    scr_const.script_model = GScr_AllocString("script_model");       /* line 47 */
    scr_const.script_origin = GScr_AllocString("script_origin");     /* line 48 */
    scr_const.spectator = GScr_AllocString("spectator");             /* line 49 */
    scr_const.stand = GScr_AllocString("stand");                     /* line 50 */
    scr_const.surfacetype = GScr_AllocString("surfacetype");         /* line 51 */
    scr_const.target_script_trigger = GScr_AllocString("target_script_trigger"); /* line 52 */
    scr_const.tempEntity = GScr_AllocString("tempEntity");           /* line 53 */
    scr_const.touch = GScr_AllocString("touch");                     /* line 54 */
    scr_const.trigger = GScr_AllocString("trigger");                 /* line 55 */
    scr_const.trigger_use = GScr_AllocString("trigger_use");         /* line 56 */
    scr_const.trigger_use_touch = GScr_AllocString("trigger_use_touch"); /* line 57 */
    scr_const.trigger_damage = GScr_AllocString("trigger_damage");   /* line 58 */
    scr_const.trigger_lookat = GScr_AllocString("trigger_lookat");   /* line 59 */
    scr_const.truck_cam = GScr_AllocString("truck_cam");             /* line 60 */
    scr_const.worldspawn = GScr_AllocString("worldspawn");           /* line 61 */
    scr_const.binocular_enter = GScr_AllocString("binocular_enter"); /* line 62 */
    scr_const.binocular_exit = GScr_AllocString("binocular_exit");   /* line 63 */
    scr_const.binocular_fire = GScr_AllocString("binocular_fire");   /* line 64 */
    scr_const.binocular_release = GScr_AllocString("binocular_release"); /* line 65 */
    scr_const.binocular_drop = GScr_AllocString("binocular_drop");   /* line 66 */
    scr_const.begin = GScr_AllocString("begin");                     /* line 69 */
    {
        extern unsigned char imp_scr_const_raw[] __asm__("imp_scr_const");
        Com_Printf("[GScr_LoadConsts] &scr_const=%p imp_scr_const=%p begin=%u menuresponse=%u\n",
            (void*)&scr_const, *(void**)imp_scr_const_raw, (unsigned)scr_const.begin, (unsigned)scr_const.menuresponse);
    }
    scr_const.intermission = GScr_AllocString("intermission");       /* line 70 */
    scr_const.menuresponse = GScr_AllocString("menuresponse");       /* line 71 */
    scr_const.playing = GScr_AllocString("playing");                 /* line 72 */
    scr_const.none = GScr_AllocString("none");                       /* line 73 */
    scr_const.dead = GScr_AllocString("dead");                       /* line 74 */
    scr_const.auto_change = GScr_AllocString("auto_change");         /* line 75 */
    scr_const.manual_change = GScr_AllocString("manual_change");     /* line 76 */
    scr_const.freelook = GScr_AllocString("freelook");               /* line 77 */
    scr_const.call_vote = GScr_AllocString("call_vote");             /* line 79 */
    scr_const.vote = GScr_AllocString("vote");                       /* line 80 */
    scr_const.snd_enveffectsprio_level = GScr_AllocString("snd_enveffectsprio_level"); /* line 82 */
    scr_const.snd_enveffectsprio_shellshock = GScr_AllocString("snd_enveffectsprio_shellshock"); /* line 83 */
    scr_const.snd_channelvolprio_holdbreath = GScr_AllocString("snd_channelvolprio_holdbreath"); /* line 84 */
    scr_const.snd_channelvolprio_pain = GScr_AllocString("snd_channelvolprio_pain"); /* line 85 */
    scr_const.snd_channelvolprio_shellshock = GScr_AllocString("snd_channelvolprio_shellshock"); /* line 86 */
    scr_const.tag_flash = GScr_AllocString("tag_flash");             /* line 88 */
    scr_const.tag_flash_11 = GScr_AllocString("tag_flash_11");       /* line 89 */
    scr_const.tag_flash_2 = GScr_AllocString("tag_flash_2");         /* line 90 */
    scr_const.tag_flash_22 = GScr_AllocString("tag_flash_22");       /* line 91 */
    scr_const.tag_brass = GScr_AllocString("tag_brass");             /* line 92 */
    scr_const.j_head = GScr_AllocString("j_head");                   /* line 93 */
    scr_const.tag_weapon = GScr_AllocString("tag_weapon");           /* line 94 */
    scr_const.tag_player = GScr_AllocString("tag_player");           /* line 95 */
    scr_const.tag_camera = GScr_AllocString("tag_camera");           /* line 96 */
    scr_const.tag_aim = GScr_AllocString("tag_aim");                 /* line 97 */
    scr_const.tag_aim_animated = GScr_AllocString("tag_aim_animated"); /* line 98 */
    scr_const.tag_origin = GScr_AllocString("tag_origin");           /* line 99 */
    scr_const.tag_butt = GScr_AllocString("tag_butt");               /* line 100 */
    scr_const.tag_weapon_right = GScr_AllocString("tag_weapon_right"); /* line 101 */
    scr_const.back_low = GScr_AllocString("back_low");               /* line 102 */
    scr_const.back_mid = GScr_AllocString("back_mid");               /* line 103 */
    scr_const.back_up = GScr_AllocString("back_up");                 /* line 104 */
    scr_const.neck = GScr_AllocString("neck");                       /* line 105 */
    scr_const.head = GScr_AllocString("head");                       /* line 106 */
    scr_const.pelvis = GScr_AllocString("pelvis");                   /* line 107 */
}
