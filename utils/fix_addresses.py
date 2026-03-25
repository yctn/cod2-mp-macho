#!/usr/bin/env python3
"""Post-process output files to replace raw Mach-O addresses with symbolic names.

Usage:
    python3 fix_addresses.py [--dry-run] [output_dir]

Applies the address map from the emitter to fix raw hex addresses in both
naked ASM and manually converted C code.
"""

import os
import re
import sys
import struct
import bisect

def build_address_map():
    """Build the same address map as AsmEmitter._build_address_map()."""
    from decomp.macho_loader import MachOLoader
    from decomp.stabs_parser import StabsParser
    from decomp.demangle import demangle_display

    loader = MachOLoader('binary.x86')
    stabs = StabsParser(loader)

    addr_map = {}
    func_addrs = set()

    def linux_name(name):
        if name.startswith('__Z'):
            return name[1:]  # C++ mangled: __ZNxxx -> _ZNxxx
        if name.startswith('_') and not name.startswith('__'):
            return name[1:]
        return name

    CONFLICTING = {
        'dprintf', 'printf', 'fprintf', 'sprintf', 'snprintf',
        'vprintf', 'vfprintf', 'vsprintf', 'vsnprintf',
        'malloc', 'free', 'realloc', 'calloc',
        'abort', 'exit', '_exit',
    }

    def safe_func_name(fname):
        return f'game_{fname}' if fname in CONFLICTING else fname

    def is_cpp_only(fname):
        if '~' in fname: return True
        if fname.startswith('global constructors') or fname.startswith('global destructors'): return True
        if 'operator' in fname and any(c in fname for c in '=<>+-*/%&|^!'): return True
        if '<' in fname: return True
        return False

    # 1. Functions
    for f in stabs.all_functions:
        dname = demangle_display(f.name)
        if not is_cpp_only(dname):
            name = safe_func_name(dname)
        else:
            name = linux_name(f.name)
        addr_map[f.addr] = name
        func_addrs.add(f.addr)

    # 2. Globals
    for g in stabs.all_globals:
        if g.addr and g.name:
            addr_map[g.addr] = linux_name(g.name)

    # 3. Symbol table
    sym_map = loader.build_symbol_addr_map()
    for addr, name in sym_map.items():
        if addr not in addr_map:
            addr_map[addr] = linux_name(name)

    # 4. Jump table
    jt = loader.section_by_name.get(('__IMPORT', '__jump_table'))
    if jt and jt.reserved2 > 0:
        stride = jt.reserved2
        for i in range(jt.size // stride):
            addr = jt.addr + i * stride
            name = loader.resolve_jump_table(addr)
            if name:
                addr_map[addr] = linux_name(name)

    # 5. Pointer tables
    for sect_key in [('__IMPORT', '__pointers'),
                     ('__DATA', '__nl_symbol_ptr'),
                     ('__DATA', '__la_sym_ptr2')]:
        sect = loader.section_by_name.get(sect_key)
        if sect:
            for i in range(sect.size // 4):
                addr = sect.addr + i * 4
                name = loader.resolve_pointer_table(addr)
                if name:
                    addr_map[addr] = linux_name(name)

    # 6. Cstring addresses
    cstring_sect = loader.section_by_name.get(('__TEXT', '__cstring'))
    if cstring_sect:
        addr = cstring_sect.addr
        end = cstring_sect.end_addr
        while addr < end:
            if addr not in addr_map:
                try:
                    s = loader.read_cstring(addr)
                    if s is not None:
                        addr_map[addr] = f'str_{addr:08x}'
                        addr += len(s) + 1
                        continue
                except (ValueError, IndexError):
                    pass
            else:
                try:
                    s = loader.read_cstring(addr)
                    if s is not None:
                        addr += len(s) + 1
                        continue
                except (ValueError, IndexError):
                    pass
            addr += 1

    # 7. Literal pools
    for sect_key, prefix, stride in [
        (('__TEXT', '__literal4'), 'lit4', 4),
        (('__TEXT', '__literal8'), 'lit8', 8),
    ]:
        sect = loader.section_by_name.get(sect_key)
        if sect and sect.size > 0:
            for i in range(sect.size // stride):
                addr = sect.addr + i * stride
                if addr not in addr_map:
                    addr_map[addr] = f'{prefix}_{addr:08x}'

    # 8. Import pointers (local symbols via pointer readback)
    # Use imp_ prefix to preserve indirection semantics
    import_ptrs = loader.section_by_name.get(('__IMPORT', '__pointers'))
    if import_ptrs:
        imp_data = loader.read_bytes(import_ptrs.addr, import_ptrs.size)
        for i in range(import_ptrs.size // 4):
            addr = import_ptrs.addr + i * 4
            if addr not in addr_map:
                name = loader.resolve_pointer_table(addr)
                if not name:
                    val = struct.unpack('<I', imp_data[i*4:i*4+4])[0]
                    name = sym_map.get(val)
                if name:
                    linux = linux_name(name)
                    dname = demangle_display(linux)
                    if not is_cpp_only(dname):
                        target = safe_func_name(dname)
                    else:
                        target = linux
                    addr_map[addr] = f'imp_{target}'
                else:
                    addr_map[addr] = f'imp_{addr:08x}'

    return addr_map, func_addrs, loader


def build_nearest_lookup(addr_map, func_addrs, loader):
    """Build sorted address list for nearest-symbol resolution."""
    DATA_SECTIONS = {
        ('__DATA', '__bss'), ('__DATA', '__common'), ('__DATA', '__data'),
        ('__DATA', '__const'), ('__DATA', '__const_coal'),
        ('__TEXT', '__const'), ('__TEXT', '__cstring'),
    }

    sorted_addrs = sorted(addr_map.keys())

    # Pre-check which addrs are in data sections
    data_addrs = set()
    for a in sorted_addrs:
        if a in func_addrs:
            continue
        for sect_key in DATA_SECTIONS:
            sect = loader.section_by_name.get(sect_key)
            if sect and sect.addr <= a < sect.end_addr:
                data_addrs.add(a)
                break

    def resolve_nearest(addr):
        idx = bisect.bisect_right(sorted_addrs, addr) - 1
        if idx < 0:
            return None
        base = sorted_addrs[idx]
        offset = addr - base
        if offset < 0 or offset > 0x100000:
            return None
        if base not in data_addrs:
            return None
        sym = addr_map[base]
        return sym if offset == 0 else f'{sym}+{offset}'

    return resolve_nearest


def process_file(filepath, addr_map, resolve_nearest, func_addrs, dry_run=False):
    """Replace raw hex addresses with symbolic names in a file.

    Uses context-aware replacement:
    - Inside inline asm strings ("...\\n"): full resolution including nearest-symbol+offset
    - In C code: only exact matches, no nearest-symbol (to avoid invalid C expressions)
    """
    with open(filepath, 'r') as f:
        content = f.read()

    original = content
    replacements = 0

    # Process line by line to distinguish ASM vs C context
    lines = content.split('\n')
    new_lines = []

    for line in lines:
        # Detect if this line is inline ASM (contains "...\n" pattern)
        is_asm = '"' in line and '\\n"' in line

        def replace_hex_asm(match):
            """Full resolution for ASM context."""
            nonlocal replacements
            prefix = match.group(1)
            hex_str = match.group(2)
            addr = int(hex_str, 16)
            if addr in addr_map:
                replacements += 1
                return prefix + addr_map[addr]
            nearest = resolve_nearest(addr)
            if nearest:
                replacements += 1
                return prefix + nearest
            return match.group(0)

        def replace_hex_c(match):
            """Exact-match only for C code context.
            Skip function addresses to avoid replacing struct offsets
            that coincidentally match code addresses."""
            nonlocal replacements
            prefix = match.group(1)
            hex_str = match.group(2)
            addr = int(hex_str, 16)
            if addr in addr_map and addr not in func_addrs:
                replacements += 1
                return prefix + addr_map[addr]
            return match.group(0)

        replace_fn = replace_hex_asm if is_asm else replace_hex_c

        # Replace $0xADDR (ASM immediates)
        line = re.sub(r'(\$)(0x[0-9a-fA-F]{4,})', replace_fn, line)

        # Replace bare 0xADDR (5+ hex digits, not preceded by comma/percent/word char)
        line = re.sub(r'(?<![,%\w])()(0x[0-9a-fA-F]{5,})(?![0-9a-fA-F])',
                      replace_fn, line)

        new_lines.append(line)

    content = '\n'.join(new_lines)

    if content != original:
        if dry_run:
            print(f'  {filepath}: {replacements} replacements')
        else:
            with open(filepath, 'w') as f:
                f.write(content)
            print(f'  {filepath}: {replacements} replacements')
        return replacements
    return 0


def main():
    dry_run = '--dry-run' in sys.argv
    output_dir = sys.argv[-1] if len(sys.argv) > 1 and not sys.argv[-1].startswith('-') else 'output'

    print('Building address map...')
    addr_map, func_addrs, loader = build_address_map()
    resolve_nearest = build_nearest_lookup(addr_map, func_addrs, loader)
    print(f'  {len(addr_map)} addresses mapped')

    # Process all .c files in PC/
    pc_dir = os.path.join(output_dir, 'PC')
    total_replacements = 0
    total_files = 0

    for root, dirs, files in os.walk(pc_dir):
        for fn in sorted(files):
            if not fn.endswith('.c'):
                continue
            filepath = os.path.join(root, fn)
            n = process_file(filepath, addr_map, resolve_nearest, func_addrs, dry_run)
            if n > 0:
                total_files += 1
                total_replacements += n

    # Also process data files, bss, rodata, strings at the top level
    for fn in ['bss.c', 'data.c', 'rodata.c', 'strings.c']:
        filepath = os.path.join(output_dir, fn)
        if os.path.exists(filepath):
            n = process_file(filepath, addr_map, resolve_nearest, func_addrs, dry_run)
            if n > 0:
                total_files += 1
                total_replacements += n

    print(f'\n{"[DRY RUN] " if dry_run else ""}Total: {total_replacements} replacements in {total_files} files')


if __name__ == '__main__':
    main()
