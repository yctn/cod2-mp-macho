#!/usr/bin/env python3
"""
Convert raw pointer offset patterns to proper struct field access
in PC/win32/snd_driver.c and PC/win32/cinematics.c.

Key insight: imp_g_snd is a void** that holds a snd_local_t*.
'sndGlob = *(byte **)imp_g_snd' gives a pointer to the start of snd_local_t.
'ch = sndGlob + index * 80' is NOT &chaninfo[index], but a raw stride pointer.
chaninfo[i] starts at sndGlob + 0x334 + i * 80 = ch + 0x334.
"""

import re
import sys

SND_FILE = '/home/user/work/output/PC/win32/snd_driver.c'
CIN_FILE = '/home/user/work/output/PC/win32/cinematics.c'

# ====================================================================
# snd_channel_info_t layout (80 bytes per entry)
# chaninfo[i] base = sndGlob + 0x334 + i*80
# In code: ch = sndGlob + i*80, so chaninfo[i] = ch + 0x334
# ====================================================================
# Offset from 'ch' -> (c_type, field_name)
CH_FIELDS = {
    0x334: ('int',                'entnum'),
    0x338: ('int',                'entchannel'),
    0x33c: ('int',                'startDelay'),
    0x340: ('int',                'looptime'),
    0x344: ('int',                'endtime'),
    0x348: ('float',              'basevolume'),
    0x34c: ('int',                'baserate'),
    0x350: ('float',              'pitch'),
    0x354: ('int',                'srcChannelCount'),
    0x358: ('const snd_alias_t *','pAlias0'),
    0x35c: ('const snd_alias_t *','pAlias1'),
    0x360: ('float',              'lerp'),
    0x364: ('float',              'org[0]'),
    0x37c: ('Bool',               'paused'),
    0x37d: ('Bool',               'master'),
    0x380: ('snd_alias_system_t', 'system'),
}

# ====================================================================
# snd_local_t layout
# sndGlob -> start of snd_local_t
# ====================================================================
# Offset from 'sndGlob' -> (c_type, field_name)
SND_FIELDS = {
    0x0:    ('Bool',   'Initialized2d'),
    0x1:    ('Bool',   'Initialized3d'),
    0x2:    ('Bool',   'paused'),
    0x4:    ('int',    'playback_rate'),
    0x8:    ('int',    'playback_bits'),
    0xc:    ('int',    'playback_channels'),
    0x10:   ('float',  'timescale'),
    0x14:   ('int',    'pausetime'),
    0x18:   ('int',    'cpu'),
    0x24:   ('float',  'volume'),
    0x254:  ('snd_channelvolgroup *', 'channelvol'),
    0x270:  ('int',    'ambient_track'),
    0x274:  ('float',  'slaveLerp'),
    0x2d8:  ('snd_enveffect *', 'effect'),
    0x13c4: ('int',    'max_2D_channels'),
    0x13c8: ('int',    'max_3D_channels'),
    0x13cc: ('int',    'max_stream_channels'),
}

# ====================================================================
# snd_alias_t field offsets
# ====================================================================
ALIAS_FIELDS = {
    0x00: ('const char *',  'pszAliasName'),
    0x04: ('const char *',  'pszSubtitle'),
    0x08: ('const char *',  'pszSecondaryAliasName'),
    0x0c: ('SoundFile *',   'soundFile'),
    0x10: ('int',           'iSequence'),
    0x14: ('float',         'fVolMin'),
    0x18: ('float',         'fVolMax'),
    0x1c: ('float',         'fPitchMin'),
    0x20: ('float',         'fPitchMax'),
    0x24: ('float',         'fDistMin'),
    0x28: ('float',         'fDistMax'),
    0x2c: ('int',           'flags'),
    0x30: ('float',         'fSlavePercentage'),
    0x34: ('float',         'fProbability'),
    0x38: ('float',         'fLfePercentage'),
    0x3c: ('int',           'startDelay'),
    0x40: ('SndCurve *',    'volumeFalloffCurve'),
}

# ====================================================================
# MssSound / loaded sound offsets (from SND_LoadSoundFile, SND_StartAlias2DSample)
# These are MssSound fields accessed via 'sound = (byte*)Com_GetSoundFileMem(pAlias0)'
# ====================================================================
MSS_FIELDS = {
    0x00: ('int',    'format'),
    0x04: ('void *', 'dataPtr'),
    0x08: ('int',    'datasize'),
    0x0c: ('int',    'rate'),
    0x10: ('int',    'bits'),
    0x14: ('int',    'channels'),
    0x18: ('int',    'samples'),
    0x1c: ('int',    'blockSize'),
    0x20: ('void *', 'loopPtr'),
}

# ====================================================================
# SoundFile fields (accessed via soundFile ptr)
# struct SoundFile { const char *soundName(0); MssSound *fileMem(4); byte isStreamFound(8); type(0xc); }
# ====================================================================
SOUNDFILE_FIELDS = {
    0x0: ('const char *', 'soundName'),
    0x4: ('struct MssSound *', 'fileMem'),
    0x8: ('byte', 'isStreamFound'),
    0xc: ('snd_alias_type_t', 'type'),
}


def apply_replacements(content, replacements):
    """Apply list of (old, new) string replacements to content. Returns (new_content, count)."""
    count = 0
    for old, new in replacements:
        n = content.count(old)
        if n > 0:
            content = content.replace(old, new)
            count += n
    return content, count


def convert_snd_driver(content):
    """Convert raw offset patterns in snd_driver.c."""
    replacements = []
    total = 0

    # ----------------------------------------------------------------
    # 1. Convert ch-relative field accesses
    # ch = sndGlob + index * 80 (or i * 80)
    # chaninfo[index] = ch + 0x334
    # ----------------------------------------------------------------

    # These are the 'ch' variable accesses that use specific offsets
    # For each offset, generate the replacement based on field name
    for off, (ctype, fname) in CH_FIELDS.items():
        hex_off = f'0x{off:x}'
        # Convert *(Bool *)(ch + 0xNNN) to g->chaninfo[i].field pattern
        # We can't use g directly since different functions use different index vars
        # Instead we convert ch+off to a proper cast, leaving variable names intact
        # The key is: the 'ch' var already has the index baked in via ch = sndGlob + idx*80
        # So we need: *(type*)(ch + off) -> ((snd_channel_info_t*)((byte*)ch + 0x334))->field
        # OR simpler: just use a helper macro or cast

        # Actually the cleanest approach: since 'ch' is a local byte* computed as
        # sndGlob + idx*80, we can convert ch + 0xNNN to:
        # &((snd_local_t*)sndGlob)->chaninfo[idx].field
        # But we don't have idx in scope here easily.

        # Best approach: use typed struct access via g pointer where we add
        # snd_local_t *g = (snd_local_t *)(*(byte**)imp_g_snd);
        # But variable names vary (index, i, etc.)

        # PRACTICAL approach: convert to inline struct cast
        # *(type *)(ch + 0x33c) -> ((snd_channel_info_t *)((byte *)ch + 0x334))->startDelay
        pass

    # ----------------------------------------------------------------
    # Practical approach: Do direct substitutions for each known pattern
    # ----------------------------------------------------------------

    # ---- chaninfo field accesses via 'ch' variable ----
    # ch + 0x334 = &chaninfo[i] (entnum at +0)
    # ch + 0x33c = &chaninfo[i].startDelay
    # etc.

    # Access via 'ch' pointer - convert to struct member access
    # Use inline cast: ((snd_channel_info_t *)((byte *)ch + 0x334))->field
    # Abbreviated: CI(ch)->field where CI is a macro-like expression
    # For readability, let's use: CHANINFO(ch)->field

    # Actually, simplest that builds: add typedef/macro at top and use it

    # For now, let's just do direct textual replacements that are correct C:

    ch_replacements = []

    # Bool accesses (single byte)
    ch_replacements += [
        # paused - Bool (byte)
        ('*(byte *)(ch + 0x37c)', '((snd_channel_info_t *)((byte *)ch + 0x334))->paused'),
        ('*(byte *)(ch + 0x37c)', '((snd_channel_info_t *)((byte *)ch + 0x334))->paused'),
        # master - Bool (byte)
        ('*(byte *)(ch + 0x37d)', '((snd_channel_info_t *)((byte *)ch + 0x334))->master'),
        # int fields
        ('*(int *)(ch + 0x334)', '((snd_channel_info_t *)((byte *)ch + 0x334))->entnum'),
        ('*(int *)(ch + 0x33c)', '((snd_channel_info_t *)((byte *)ch + 0x334))->startDelay'),
        ('*(int *)(ch + 0x340)', '((snd_channel_info_t *)((byte *)ch + 0x334))->looptime'),
        ('*(int *)(ch + 0x344)', '((snd_channel_info_t *)((byte *)ch + 0x334))->endtime'),
        ('*(float *)(ch + 0x348)', '((snd_channel_info_t *)((byte *)ch + 0x334))->basevolume'),
        ('*(int *)&(ch + 0x348)', '(int)((snd_channel_info_t *)((byte *)ch + 0x334))->basevolume'),
        ('*(float *)(ch + 0x350)', '((snd_channel_info_t *)((byte *)ch + 0x334))->pitch'),
        ('*(int *)(ch + 0x354)', '((snd_channel_info_t *)((byte *)ch + 0x334))->srcChannelCount'),
        ('*(void **)(ch + 0x358)', '((snd_channel_info_t *)((byte *)ch + 0x334))->pAlias0'),
        ('*(void **)(ch + 0x35c)', '((snd_channel_info_t *)((byte *)ch + 0x334))->pAlias1'),
        ('*(float *)(ch + 0x360)', '((snd_channel_info_t *)((byte *)ch + 0x334))->lerp'),
        ('*(int *)(ch + 0x380)', '((snd_channel_info_t *)((byte *)ch + 0x334))->system'),
    ]

    # ---- index/i-based sndGlob accesses ----
    # sndGlob + i * 80 + 0xNNN or sndGlob + index * 80 + 0xNNN
    # These are the same as ch + offset where ch = sndGlob + idx*80

    def add_idx_repl(idx_var, off, field_expr):
        """Generate replacements for sndGlob + idx*80 + off accesses."""
        hex_off = f'0x{off:x}'
        base = f'sndGlob + {idx_var} * 80 + {hex_off}'
        ch_expr = f'((snd_channel_info_t *)((byte *)sndGlob + {idx_var} * 80 + 0x334))->{field_expr}'
        return base, ch_expr

    idx_replacements = []
    for idx_var in ['index', 'i']:
        # chaninfo via sndGlob + idx * 80 + offset
        idx_replacements += [
            (f'sndGlob + {idx_var} * 80 + 0x330',
             f'(byte *)(&((snd_local_t *)sndGlob)->chaninfo[{idx_var}]) - 4'),  # looptime? No...
            # Actually 0x330 is looptime of snd_local_t (NOT chaninfo)
            # sndGlob + 0x330 = g->looptime
            # sndGlob + idx*80 + 0x330 = for idx=0 = sndGlob+0x330 = looptime
            # but for idx>0, this would go past looptime into chaninfo!
            # This is used as 'delayBase = sndGlob + i * 80 + 0x330'
            # and then delayBase + 0xc = delayBase + 12 = sndGlob + i*80 + 0x33c = chaninfo[i].startDelay
            # So 0x330 is the start of chaninfo relative to the stride view:
            # chaninfo[i].startDelay = sndGlob + 0x334 + i*80 + 8 = sndGlob + i*80 + 0x33c
            # delayBase = sndGlob + i*80 + 0x330
            # delayBase + 0xc = sndGlob + i*80 + 0x33c = chaninfo[i].startDelay ✓
            # Actually for i=0: delayBase = sndGlob + 0x330
            #   sndGlob + 0x330 = g->looptime
            #   delayBase + 0xc = sndGlob + 0x33c = g->chaninfo[0].startDelay
            # But delayBase is just a pointer into the struct, it doesn't have to align to a named field
            # It's used to compute delayBase + 0xc which IS chaninfo[i].startDelay
        ]

    # ---- sndGlob field accesses (non-indexed) ----
    sndglob_replacements = [
        # Note: these are patterns where sndGlob is used directly (not indexed)
        ('*(byte *)sndGlob', '((snd_local_t *)sndGlob)->Initialized2d'),
        ('*(byte *)(sndGlob + 1)', '((snd_local_t *)sndGlob)->Initialized3d'),
        ('*(byte *)(sndGlob + 2)', '((snd_local_t *)sndGlob)->paused'),
        ('*(byte *)(sndGlob)', '((snd_local_t *)sndGlob)->Initialized2d'),
        ('*(int *)(sndGlob + 4)', '((snd_local_t *)sndGlob)->playback_rate'),
        ('*(int *)(sndGlob + 8)', '((snd_local_t *)sndGlob)->playback_bits'),
        ('*(int *)(sndGlob + 0xc)', '((snd_local_t *)sndGlob)->playback_channels'),
        ('*(float *)(sndGlob + 0x10)', '((snd_local_t *)sndGlob)->timescale'),
        ('*(float *)(sndGlob + 0x24)', '((snd_local_t *)sndGlob)->volume'),
        ('*(float **)(sndGlob + 0x254)', '(float *)((snd_local_t *)sndGlob)->channelvol'),
        ('*(float *)(sndGlob + 0x274)', '((snd_local_t *)sndGlob)->slaveLerp'),
        ('*(byte **)(sndGlob + 0x2d8)', '(byte *)((snd_local_t *)sndGlob)->effect'),
        ('*(int *)(sndGlob + 0x13c4)', '((snd_local_t *)sndGlob)->max_2D_channels'),
        ('*(int *)(sndGlob + 0x13c8)', '((snd_local_t *)sndGlob)->max_3D_channels'),
        ('*(int *)(sndGlob + 0x13cc)', '((snd_local_t *)sndGlob)->max_stream_channels'),
        # Special: *(byte *)(sndGlob + 2)
        ('*(byte *)(sndGlob + 2)', '((snd_local_t *)sndGlob)->paused'),
    ]

    # imp_g_snd-based accesses (without local sndGlob variable)
    imp_replacements = [
        ('*(byte *)(*(byte **)imp_g_snd + 0x24)', '((snd_local_t *)*(snd_local_t **)imp_g_snd)->volume'),
        ('*(float *)(*(byte **)imp_g_snd + 0x24)', '((snd_local_t *)*(snd_local_t **)imp_g_snd)->volume'),
        ('*(float *)(*(byte **)imp_g_snd + 0x10)', '((snd_local_t *)*(snd_local_t **)imp_g_snd)->timescale'),
        ('*(int *)(*(byte **)imp_g_snd + index * 80 + 0x354)', '((snd_local_t *)*(snd_local_t **)imp_g_snd)->chaninfo[index].srcChannelCount'),
    ]

    # ---- snd_alias_t field accesses ----
    # pAlias0, pAlias1, pAlias, pA are all const snd_alias_t*
    alias_var_replacements = []
    for alias_var in ['pAlias0', 'pAlias1', 'pAlias', 'pA']:
        for off, (ctype, fname) in ALIAS_FIELDS.items():
            hex_off = f'0x{off:x}'
            if fname == 'flags':
                # flags is accessed as int
                alias_var_replacements += [
                    (f'*(int *)((byte *){alias_var} + {hex_off})', f'{alias_var}->{fname}'),
                    (f'*(byte *)((byte *){alias_var} + {hex_off})', f'(byte)({alias_var}->{fname})'),
                ]
            elif ctype == 'float':
                alias_var_replacements += [
                    (f'*(float *)((byte *){alias_var} + {hex_off})', f'{alias_var}->{fname}'),
                    (f'*(int *)((byte *){alias_var} + {hex_off})', f'*(int *)&{alias_var}->{fname}'),
                ]
            elif ctype in ('int',):
                alias_var_replacements += [
                    (f'*(int *)((byte *){alias_var} + {hex_off})', f'{alias_var}->{fname}'),
                ]
            elif 'SndCurve' in ctype:
                alias_var_replacements += [
                    (f'*(void **)((byte *){alias_var} + {hex_off})', f'{alias_var}->{fname}'),
                ]
            elif 'char *' in ctype:
                alias_var_replacements += [
                    (f'*(void **)((byte *){alias_var} + {hex_off})', f'(void *){alias_var}->{fname}'),
                    (f'*(const char **)((byte *){alias_var} + {hex_off})', f'{alias_var}->{fname}'),
                ]
            elif ctype.startswith('const '):
                alias_var_replacements += [
                    (f'*(void **)((byte *){alias_var} + {hex_off})', f'(void *){alias_var}->{fname}'),
                ]
            else:
                alias_var_replacements += [
                    (f'*(void **)((byte *){alias_var} + {hex_off})', f'(void *){alias_var}->{fname}'),
                ]

    # ---- dvar field accesses ----
    # dvar->current is at +8 (after name(4) + flags(2) + type(1) + modified(1))
    dvar_replacements = [
        # *(byte *)((byte *)mss_q3fs + 8) -> mss_q3fs->current.enabled
        ('*(byte *)((byte *)mss_q3fs + 8)', 'mss_q3fs->current.enabled'),
        # *(const char **)((byte *)mss_3d_provider + 8) -> mss_3d_provider->current.string
        ('*(const char **)((byte *)mss_3d_provider + 8)', 'mss_3d_provider->current.string'),
        # imp_snd_* dvars accessed via double dereference
        ('*(int *)((byte *)(*(byte **)imp_snd_khz) + 8)', '((dvar_t *)*(void **)imp_snd_khz)->current.integer'),
        ('*(int *)((byte *)(*(byte **)imp_snd_bits) + 8)', '((dvar_t *)*(void **)imp_snd_bits)->current.integer'),
        ('*(byte *)((byte *)(*(byte **)imp_snd_stereo) + 8)', '((dvar_t *)*(void **)imp_snd_stereo)->current.enabled'),
        # snd_enableReverb
        ('*(byte *)((byte *)(*(byte **)imp_snd_enableReverb) + 8)',
         '((dvar_t *)*(void **)imp_snd_enableReverb)->current.enabled'),
        # nextmap dvar (used in cinematics.c)
        ('*(char **)((char *)*(void **)imp_nextmap + 8)',
         '((dvar_t *)*(void **)imp_nextmap)->current.string'),
    ]

    # ---- effect->wetlevel access ----
    effect_replacements = [
        ('*(float *)(*(byte **)(sndGlob + 0x2d8) + 0x10)',
         '((snd_local_t *)sndGlob)->effect->wetlevel'),
        ('*(float *)(*(byte **)(channels + 0x2d8) + 0x10)',
         '((snd_local_t *)channels)->effect->wetlevel'),
        # Also the form with imp_g_snd
        ('*(float *)(*(byte **)(*(byte **)imp_g_snd + 0x2d8) + 0x10)',
         '((snd_local_t *)*(snd_local_t **)imp_g_snd)->effect->wetlevel'),
    ]

    # ---- pauseSettings access ----
    # *(byte *)(sndGlob + 0x2e7 + channel) -> g->pauseSettings[channel]
    # *(byte *)(sndGlob + 2) -> g->paused (already above)
    pause_replacements = [
        ('*(byte *)(sndGlob + 0x2e7 + channel)', '((snd_local_t *)sndGlob)->pauseSettings[channel]'),
    ]

    # ---- snd_local_t accessed via imp_g_snd byte* directly ----
    impg_replacements = [
        # *(byte *)(sndGlob + 2) == 0 check for paused
        ('*(byte *)(sndGlob + 2)', '((snd_local_t *)sndGlob)->paused'),
        # *(byte *)(sndGlob + 1)
        ('*(byte *)(sndGlob + 1)', '((snd_local_t *)sndGlob)->Initialized3d'),
        # *(byte *)sndGlob
        ('*(byte *)sndGlob', '((snd_local_t *)sndGlob)->Initialized2d'),
    ]

    # ---- Listener access ----
    # listeners[0] starts at sndGlob + 0x2f4
    # listenerOrigin = sndGlob + 0x2f0 + listenerIdx * 56 + 4 = &listeners[listenerIdx].orient.origin
    # right = sndGlob + 0x2f0 + listenerIdx * 56 + 0x10 = listeners[listenerIdx].orient.axis[0]
    # up = sndGlob + 0x2fc + listenerIdx * 56 + 0x10 = listeners[listenerIdx].orient.axis[1]
    # forward = sndGlob + 0x308 + listenerIdx * 56 + 0x10 = listeners[listenerIdx].orient.axis[2]
    # dist = Vec3Distance(org, sndGlob + 0x2f4 + listenerIdx * 56) = listeners[listenerIdx].orient.origin
    listener_replacements = [
        # listenerOrigin
        ('(float *)(sndGlob + 0x2f0 + listenerIdx * 56 + 4)',
         '((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.origin'),
        # axis[0] = right
        ('(float *)(sndGlob + 0x2f0 + listenerIdx * 56 + 0x10)',
         '((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.axis[0]'),
        # axis[1] = up (note different base: 0x2fc = 0x2f0 + 0xc = 0x2f0 + sizeof(vec3_t))
        ('(float *)(sndGlob + 0x2fc + listenerIdx * 56 + 0x10)',
         '((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.axis[1]'),
        # axis[2] = forward
        ('(float *)(sndGlob + 0x308 + listenerIdx * 56 + 0x10)',
         '((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.axis[2]'),
        # origin for dist calculation (at sndGlob + 0x2f4 + listenerIdx * 56)
        ('(float *)(sndGlob + 0x2f4 + listenerIdx * 56)',
         '((snd_local_t *)sndGlob)->listeners[listenerIdx].orient.origin'),
    ]

    # ---- chanBase patterns ----
    # chanBase = sndGlob + i * 80 + 0x350  (or index * 80 + 0x350)
    # chanBase = ch + 0x350 - 0x350 + 0x350... actually chanBase points to chaninfo.pitch
    # chaninfo[i].pitch = sndGlob + 0x334 + i*80 + 0x1c = sndGlob + i*80 + 0x350
    # So chanBase[0] = pitch, chanBase[4] = srcChannelCount, chanBase[8] = pAlias0, chanBase[0xc] = pAlias1, chanBase[0x10] = lerp
    # But code uses chanBase + 4 for srcChannelCount and chanBase + 8 for pAlias0
    # chanBase offsets from chaninfo.pitch:
    #   chanBase + 0 = pitch (+0x1c in chaninfo)
    #   chanBase + 4 = srcChannelCount (+0x20)
    #   chanBase + 8 = pAlias0 (+0x24)
    #   chanBase + 0xc = pAlias1 (+0x28)
    #   chanBase + 0x10 = lerp (+0x2c)
    # But the code uses chanBase as pointing to sndGlob + i*80 + 0x350
    # which equals chaninfo[i] base (0x334) + 0x1c (pitch field)
    chanbase_replacements = [
        # These use 'chanBase + N' where chanBase = sndGlob + i*80 + 0x350
        # chanBase + 0x10 = lerp (chaninfo.lerp = chaninfo_base + 0x2c = sndGlob + i*80 + 0x360)
        # Actually: sndGlob + i*80 + 0x350 + 0x10 = sndGlob + i*80 + 0x360 = chaninfo[i].lerp
        # chanBase + 4 = srcChannelCount (sndGlob + i*80 + 0x354)
        # chanBase + 8 = pAlias0 (sndGlob + i*80 + 0x358)
        # chanBase + 0xc = pAlias1 (sndGlob + i*80 + 0x35c)
        # For 'chanBase' we need to know which 'i' it came from...
        # This is complex. Let's leave these for later or handle by index.
    ]

    # ---- delayBase patterns ----
    # delayBase = sndGlob + i * 80 + 0x330
    # delayBase + 0xc = sndGlob + i*80 + 0x33c = chaninfo[i].startDelay
    # delayBase is set near the usage so we can convert the usage directly

    # ---- SoundFile (soundFile pointer) accesses ----
    soundfile_replacements = [
        ('*(void **)((byte *)soundFile + 4)', 'soundFile->fileMem'),
        ('*(void **)((byte *)pSoundFile + 4)', 'pSoundFile->fileMem'),
        # The SND_GetSoundFileSize uses: *(int *)((byte *)pSoundFile + 8) + 0x24
        # pSoundFile->fileMem at +4, then +8 = isStreamFound? No...
        # Actually in SND_GetSoundFileSize: pSoundFile is a void* (const void*)
        # It's accessing the MssSound size from the SoundFile... hmm.
        # SoundFile: {soundName(0), fileMem(4), isStreamFound(8), type(0xc)}
        # *(int *)((byte *)pSoundFile + 8) would be wrong for isStreamFound (Bool/byte)
        # Let me check the SND_GetSoundFileSize function:
        # return *(int *)((byte *)pSoundFile + 8) + 0x24;
        # pSoundFile is 'const void *' and it's a SoundFile*
        # But SoundFile::isStreamFound is a byte, not int...
        # Actually pSoundFile might be pointing to MssSound directly?
        # MssSound at +4 would give: *(int*)(sound + 8) = sound->datasize
        # But pSoundFile is passed as a SoundFile*...
        # Actually checking SND_GetSoundFileSize comment: from snd_local line 1569
        # The function seems to compute the size of the sound data
        # If pSoundFile is actually a pointer to MssSound (not SoundFile), then:
        # *(int*)((byte*)sound + 8) = datasize, and +0x24 = sizeof header
        # This is used in the context where soundFile->fileMem would be the MssSound*
        # Leave this for manual review.
    ]

    # Collect all replacements
    all_replacements = (
        ch_replacements +
        sndglob_replacements +
        imp_replacements +
        alias_var_replacements +
        dvar_replacements +
        effect_replacements +
        pause_replacements +
        impg_replacements +
        listener_replacements
    )

    # Apply
    content, count = apply_replacements(content, all_replacements)
    total += count

    return content, total


def convert_chanbase_and_delaybase(content):
    """
    Convert chanBase and delayBase patterns more carefully.
    chanBase = sndGlob + i * 80 + 0x350  -> points to chaninfo[i].pitch
    delayBase = sndGlob + i * 80 + 0x330 -> points 4 bytes before chaninfo[i]

    We need to convert the subsequent accesses.
    """
    replacements = []

    # chanBase is set as: chanBase = sndGlob + i * 80 + 0x350
    # Then accessed as:
    #   *(int *)(chanBase + 4)  = chaninfo[i].srcChannelCount
    #   *(void **)(chanBase + 8) = chaninfo[i].pAlias0
    #   *(void **)(chanBase + 0xc) = chaninfo[i].pAlias1
    #   *(float *)(chanBase + 0x10) = chaninfo[i].lerp
    # But 'i' is not in chanBase's local context...
    # The code has: chanBase = sndGlob + i * 80 + 0x350
    # So we can compute: chaninfo_base = chanBase - 0x350 + 0x334 = chanBase - 0x1c
    # OR just use the fact that chanBase = &chaninfo[i].pitch
    # chanBase[0] = pitch, chanBase[4] = srcChannelCount, etc.

    replacements += [
        # chanBase is cast as pointing to pitch field of chaninfo[i]
        ('*(int *)(chanBase + 4)', '((snd_channel_info_t *)((byte *)chanBase - 0x1c))->srcChannelCount'),
        ('*(void **)(chanBase + 8)', '(void *)((snd_channel_info_t *)((byte *)chanBase - 0x1c))->pAlias0'),
        ('*(void **)(chanBase + 0xc)', '(void *)((snd_channel_info_t *)((byte *)chanBase - 0x1c))->pAlias1'),
        ('*(float *)(chanBase + 0x10)', '((snd_channel_info_t *)((byte *)chanBase - 0x1c))->lerp'),
    ]

    # delayBase = sndGlob + i * 80 + 0x330
    # delayBase + 0xc = chaninfo[i].startDelay
    # chaninfo_base = delayBase - 0x330 + 0x334 = delayBase + 4
    replacements += [
        ('*(int *)(delayBase + 0xc)', '((snd_channel_info_t *)((byte *)delayBase + 4))->startDelay'),
        ('*(int *)(delayBase + 0xc)', '((snd_channel_info_t *)((byte *)delayBase + 4))->startDelay'),
    ]

    content, count = apply_replacements(content, replacements)
    return content, count


def convert_indexed_sndglob(content):
    """
    Convert sndGlob + idx * 80 + offset patterns.
    """
    replacements = []

    for idx_var in ['index', 'i']:
        # 0x350 = chaninfo[i].pitch (float)
        replacements += [
            (f'sndGlob + {idx_var} * 80 + 0x350',
             f'(byte *)&((snd_local_t *)sndGlob)->chaninfo[{idx_var}].pitch'),
        ]
        # 0x360 = chaninfo[i].org (float[3])
        replacements += [
            (f'(float *)(sndGlob + {idx_var} * 80 + 0x364)',
             f'((snd_local_t *)sndGlob)->chaninfo[{idx_var}].org'),
            (f'sndGlob + {idx_var} * 80 + 0x364',
             f'(byte *)((snd_local_t *)sndGlob)->chaninfo[{idx_var}].org'),
        ]
        # 0x360 = chaninfo[i].lerp address (orgBase patterns)
        replacements += [
            (f'sndGlob + {idx_var} * 80 + 0x360',
             f'(byte *)&((snd_local_t *)sndGlob)->chaninfo[{idx_var}].lerp'),
        ]
        # 0x358 = chaninfo[i].pAlias0
        replacements += [
            (f'*(void **)(*(byte **)(sndGlob + {idx_var} * 80 + 0x358) + 0x2c)',
             f'((snd_local_t *)sndGlob)->chaninfo[{idx_var}].pAlias0->flags'),
        ]
        # 0x354 = chaninfo[i].srcChannelCount
        replacements += [
            (f'*(int *)(sndGlob + {idx_var} * 80 + 0x354)',
             f'((snd_local_t *)sndGlob)->chaninfo[{idx_var}].srcChannelCount'),
        ]
        # 0x37d = chaninfo[i].master
        replacements += [
            (f'*(byte *)(sndGlob + {idx_var} * 80 + 0x37d)',
             f'((snd_local_t *)sndGlob)->chaninfo[{idx_var}].master'),
        ]
        # 0x330 = delayBase pointer
        # sndGlob + i*80 + 0x330 is the start of what becomes delayBase
        # We handle this via delayBase pattern above
        # BUT let's also convert the direct form of delayBase accesses:
        replacements += [
            (f'*(int *)(sndGlob + {idx_var} * 80 + 0x33c)',
             f'((snd_local_t *)sndGlob)->chaninfo[{idx_var}].startDelay'),
        ]

    content, count = apply_replacements(content, replacements)
    return content, count


def convert_sndglob_init_pattern(content):
    """
    Convert *(byte *)sndGlob = 1 and similar initialization patterns.
    """
    replacements = [
        # SND_InitDriver: set Initialized2d
        ('*(byte *)sndGlob = 1', '((snd_local_t *)sndGlob)->Initialized2d = 1'),
        # *(byte *)(sndGlob + 1) = 1 -> Initialized3d = 1
        ('*(byte *)(sndGlob + 1) = 1', '((snd_local_t *)sndGlob)->Initialized3d = 1'),
    ]
    content, count = apply_replacements(content, replacements)
    return content, count


def main_snd_driver():
    with open(SND_FILE) as f:
        content = f.read()

    original = content
    total = 0

    # Apply all conversion passes
    content, n = convert_snd_driver(content)
    total += n
    print(f"  Pass 1 (main patterns): {n}")

    content, n = convert_chanbase_and_delaybase(content)
    total += n
    print(f"  Pass 2 (chanBase/delayBase): {n}")

    content, n = convert_indexed_sndglob(content)
    total += n
    print(f"  Pass 3 (indexed sndGlob): {n}")

    content, n = convert_sndglob_init_pattern(content)
    total += n
    print(f"  Pass 4 (init patterns): {n}")

    print(f"  Total: {total}")

    if total > 0:
        with open(SND_FILE, 'w') as f:
            f.write(content)
        print(f"  Written: {SND_FILE}")
    else:
        print("  No changes made")

    return total


def main_cinematics():
    with open(CIN_FILE) as f:
        content = f.read()

    total = 0

    # The 12 offsets in cinematics.c:
    # 1. *(byte **)imp_g_snd -> snd_local_t check
    # 2. *(void **)imp_nextmap + 8 -> dvar current string
    # 3. imp_cls + 0x110 -> clientStatic_t field
    # 4. imp_cl_inGameVideo access
    # 5. cls + 0x2a0a* accesses
    # 6. imp_re + 0x148 -> rendererCallback

    replacements = [
        # snd global check: sndGlob != NULL && *sndGlob != 0 -> Initialized2d check
        ('*(byte **)imp_g_snd', '(byte *)*(snd_local_t **)imp_g_snd'),

        # dvar nextmap
        ('*(char **)((char *)*(void **)imp_nextmap + 8)',
         '((dvar_t *)*(void **)imp_nextmap)->current.string'),

        # cl_inGameVideo - it's a dvar_t** (pointer to dvar_t*)
        # (*(char **)imp_cl_inGameVideo)[0] + 8 -> first dvar's current.enabled
        # (*(char **)imp_cl_inGameVideo)[8] -> at byte 8 from the array start
        # Actually imp_cl_inGameVideo is a void* to a dvar_t*
        # *(char **)imp_cl_inGameVideo = dvar_t* (the inGameVideo dvar)
        # [0] + 8 = ((byte*)inGameVideo_dvar) + 8 = inGameVideo_dvar->current.enabled
        # [8] = ((byte*)inGameVideo_dvar) + 8 -> same as above?
        # Let's check: (*(char **)imp_cl_inGameVideo)[0] is the first byte of the dvar pointer
        # No wait: (*(char **)imp_cl_inGameVideo) is a char* pointing to the dvar
        # [0] = first char/byte
        # [0] + 8 = first char + 8 bytes = 8th position? That's pointer arithmetic on char
        # So (*(char **)imp_cl_inGameVideo)[0] is a char, and +8 would be wrong
        # More likely: imp_cl_inGameVideo is a pointer to a dvar_t** or something
        # Let's look at the actual code:
        # if (!*(byte *)((*(char **)imp_cl_inGameVideo)[0] + 8))
        # This is: imp_cl_inGameVideo is a void* containing address of something
        # *(char **)imp_cl_inGameVideo = dereference as char** -> get char* -> array of char*
        # [0] = first char* in the array
        # (char*)([0]) + 8 = 8 bytes into that char*
        # *(byte *)(...) = byte at that location
        # So imp_cl_inGameVideo is really a char*** or dvar_t**[]
        # The value at [0] is a dvar_t* and +8 is its current.enabled
        # Leave as-is since this is complex

        # cls + 0x2a0a74 -> screenAspect in clientStatic_t
        # These are large offsets suggesting cls points to beginning of a large struct
        # We don't have the clientStatic_t definition handy; leave as-is
    ]

    content, count = apply_replacements(content, replacements)
    total += count
    print(f"  cinematics.c conversions: {count}")

    if total > 0:
        with open(CIN_FILE, 'w') as f:
            f.write(content)
        print(f"  Written: {CIN_FILE}")

    return total


if __name__ == '__main__':
    print("Converting snd_driver.c...")
    n1 = main_snd_driver()

    print("\nConverting cinematics.c...")
    n2 = main_cinematics()

    print(f"\nTotal: {n1 + n2} conversions")
