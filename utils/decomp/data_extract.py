"""Extract global data from Mach-O binary sections into C source files.

Generates:
- data.c:    Initialized globals from __DATA.__data
- bss.c:     Uninitialized globals from BSS/common sections
- strings.c: String constants from __TEXT.__cstring
- rodata.c:  Read-only constants from __TEXT.__const
"""

import os
from .macho_loader import MachOLoader
from .stabs_parser import StabsParser, GlobalVar
from .demangle import demangle_display


class DataExtractor:
    """Extract and emit global data from binary sections."""

    def __init__(self, loader: MachOLoader, stabs: StabsParser):
        self.loader = loader
        self.stabs = stabs
        self._addr_to_global: dict[int, GlobalVar] = {}
        self._sym_addr_map = loader.build_symbol_addr_map()
        self._build_global_map()
        # Cross-section dedup: track names emitted across all data files
        self._cross_section_names: set[str] = set()

    def _dedup_name(self, name: str, addr: int, seen_names: dict) -> str:
        """Deduplicate a variable name within a section and across sections."""
        if name in seen_names or name in self._cross_section_names:
            name = f'{name}_{addr:08x}'
        seen_names[name] = 1
        self._cross_section_names.add(name)
        return name

    def _build_global_map(self):
        """Build address→GlobalVar map for all globals."""
        for g in self.stabs.all_globals:
            if g.addr:
                self._addr_to_global[g.addr] = g

    @staticmethod
    def _linux_name(name: str) -> str:
        """Strip macOS leading underscore for Linux ELF and sanitize."""
        if name.startswith('_') and not name.startswith('__'):
            name = name[1:]
        # Replace non-identifier characters (e.g., '.' in symbol names)
        name = name.replace('.', '_').replace('-', '_').replace('$', '_')
        # Ensure doesn't start with a digit
        if name and name[0].isdigit():
            name = '_' + name
        return name

    # Variable names that are too generic and likely conflict with
    # type names, system functions, or keywords
    _RESERVED_VARNAMES = {
        'index', 'string', 'send', 'time', 'line', 'key', 'name', 'type',
        'count', 'size', 'start', 'end', 'buf', 'buffer', 'data', 'str',
        'color', 'rect', 'token', 'playing', 'range', 'methods', 'version',
    }

    def _name_for_addr(self, addr: int) -> str:
        """Get a symbolic name for an address."""
        g = self._addr_to_global.get(addr)
        if g and g.name:
            n = self._linux_name(demangle_display(g.name) if g.name.startswith('_') else g.name)
            if n in self._RESERVED_VARNAMES:
                return f'{n}_{addr:08x}'
            return n
        name = self._sym_addr_map.get(addr)
        if name:
            n = self._linux_name(name)
            if n in self._RESERVED_VARNAMES:
                return f'{n}_{addr:08x}'
            return n
        return f'data_{addr:08x}'

    def generate_data_c(self) -> str:
        """Generate data.c with initialized globals from __DATA.__data."""
        sect = self.loader.section_by_name.get(('__DATA', '__data'))
        if not sect:
            return '/* No __DATA.__data section found */\n'

        lines = [
            '/* Initialized global data extracted from __DATA.__data */',
            '#include "common_types.h"',
            '',
        ]

        # Collect all globals that fall within __DATA.__data
        data_globals = []
        seen_addrs = set()
        for g in self.stabs.all_globals:
            if g.addr and g.kind in ('global', 'static') and sect.addr <= g.addr < sect.end_addr:
                if g.addr not in seen_addrs:
                    data_globals.append(g)
                    seen_addrs.add(g.addr)
        data_globals.sort(key=lambda g: g.addr)

        # Also add symbol table entries not covered by STABS
        for addr, name in sorted(self._sym_addr_map.items()):
            if sect.addr <= addr < sect.end_addr and addr not in seen_addrs:
                data_globals.append(type('FakeGlobal', (), {
                    'addr': addr, 'name': name, 'kind': 'global',
                    'type_ref': None, 'source_file': ''
                })())
                seen_addrs.add(addr)
        data_globals.sort(key=lambda g: g.addr)

        if not data_globals:
            # Emit the entire section as a byte array
            lines.append(f'/* __DATA.__data: 0x{sect.addr:08x} - 0x{sect.end_addr:08x} ({sect.size} bytes) */')
            lines.append(self._emit_byte_array('__data_section', sect.addr, sect.size))
        else:
            # Emit each global with its byte values
            seen_names = {}  # name → count for deduplication
            for i, g in enumerate(data_globals):
                name = self._name_for_addr(g.addr)
                name = self._dedup_name(name, g.addr, seen_names)
                # Determine size: gap to next global or end of section
                if i + 1 < len(data_globals):
                    size = data_globals[i + 1].addr - g.addr
                else:
                    size = sect.end_addr - g.addr
                size = min(size, sect.end_addr - g.addr)
                if size <= 0:
                    continue

                lines.append(f'/* 0x{g.addr:08x} - {size} bytes */')
                lines.append(self._emit_byte_array(name, g.addr, size))
                lines.append('')

        return '\n'.join(lines)

    def generate_bss_c(self) -> str:
        """Generate bss.c with uninitialized globals."""
        lines = [
            '/* Uninitialized global data (BSS) */',
            '#include "common_types.h"',
            '',
        ]

        bss_globals = []
        seen_addrs = set()
        for g in self.stabs.all_globals:
            if g.addr and g.kind == 'bss' and g.addr not in seen_addrs:
                bss_globals.append(g)
                seen_addrs.add(g.addr)
        bss_globals.sort(key=lambda g: g.addr)

        # Also check __DATA.__bss and __DATA.__common sections
        bss_sect = self.loader.section_by_name.get(('__DATA', '__bss'))
        common_sect = self.loader.section_by_name.get(('__DATA', '__common'))

        for addr, name in sorted(self._sym_addr_map.items()):
            if addr in seen_addrs:
                continue
            in_bss = bss_sect and bss_sect.addr <= addr < bss_sect.end_addr
            in_common = common_sect and common_sect.addr <= addr < common_sect.end_addr
            if in_bss or in_common:
                bss_globals.append(type('FakeGlobal', (), {
                    'addr': addr, 'name': name, 'kind': 'bss',
                    'type_ref': None, 'source_file': ''
                })())
                seen_addrs.add(addr)
        bss_globals.sort(key=lambda g: g.addr)

        if not bss_globals:
            lines.append('/* No BSS globals found */')
        else:
            seen_names = {}  # name → count for deduplication
            for i, g in enumerate(bss_globals):
                name = self._name_for_addr(g.addr)
                name = self._dedup_name(name, g.addr, seen_names)
                # Estimate size
                if i + 1 < len(bss_globals):
                    size = bss_globals[i + 1].addr - g.addr
                else:
                    size = 4  # Default to 4 bytes
                size = max(size, 1)
                if size == 4:
                    lines.append(f'int {name}; /* 0x{g.addr:08x} */')
                else:
                    lines.append(f'unsigned char {name}[{size}]; /* 0x{g.addr:08x} */')

        return '\n'.join(lines)

    def generate_strings_c(self) -> str:
        """Generate strings.c with string constants from __TEXT.__cstring."""
        sect = self.loader.section_by_name.get(('__TEXT', '__cstring'))
        if not sect:
            return '/* No __TEXT.__cstring section found */\n'

        lines = [
            '/* String constants from __TEXT.__cstring */',
            '#include "common_types.h"',
            '',
        ]

        # Walk the cstring section, extracting null-terminated strings
        addr = sect.addr
        end = sect.end_addr
        count = 0
        while addr < end:
            try:
                s = self.loader.read_cstring(addr)
            except (ValueError, IndexError):
                addr += 1
                continue

            if s:
                # Check if this address has a symbol name
                name = self._sym_addr_map.get(addr)
                if name:
                    label = self._linux_name(name)
                else:
                    label = f'str_{addr:08x}'
                # Cross-section dedup
                if label in self._cross_section_names:
                    label = f'{label}_{addr:08x}'
                self._cross_section_names.add(label)

                # Escape the string for C
                escaped = self._escape_c_string(s)
                lines.append(f'const char {label}[] = "{escaped}"; /* 0x{addr:08x} */')
                count += 1
                addr += len(s) + 1  # skip past null terminator
            else:
                addr += 1

        lines.insert(2, f'/* {count} strings extracted */')
        return '\n'.join(lines)

    def generate_rodata_c(self) -> str:
        """Generate rodata.c with read-only constants from __TEXT.__const."""
        sect = self.loader.section_by_name.get(('__TEXT', '__const'))
        if not sect:
            return '/* No __TEXT.__const section found */\n'

        lines = [
            '/* Read-only data from __TEXT.__const */',
            '#include "common_types.h"',
            '',
            f'/* 0x{sect.addr:08x} - 0x{sect.end_addr:08x} ({sect.size} bytes) */',
        ]

        # Collect known symbols in this range
        rodata_syms = []
        for addr, name in sorted(self._sym_addr_map.items()):
            if sect.addr <= addr < sect.end_addr:
                rodata_syms.append((addr, name))

        if not rodata_syms:
            # Emit entire section as one byte array
            lines.append(self._emit_byte_array('__rodata_section', sect.addr, sect.size))
        else:
            # Emit each symbol, deduplicating names
            seen_names = {}
            for i, (addr, name) in enumerate(rodata_syms):
                raw_name = self._linux_name(name)
                label = self._dedup_name(raw_name, addr, seen_names)
                if i + 1 < len(rodata_syms):
                    size = rodata_syms[i + 1][0] - addr
                else:
                    size = sect.end_addr - addr
                size = min(size, sect.end_addr - addr)
                if size <= 0:
                    continue
                # If name was sanitized (dots→underscores), add asm alias
                orig_linux = name[1:] if name.startswith('_') and not name.startswith('__') else name
                asm_attr = ''
                if orig_linux != label and '.' in orig_linux:
                    asm_attr = f' __asm__("{orig_linux}")'
                lines.append(f'/* 0x{addr:08x} */')
                lines.append(self._emit_byte_array(label, addr, size, asm_attr=asm_attr))
                lines.append('')

        return '\n'.join(lines)

    def _emit_byte_array(self, name: str, addr: int, size: int, asm_attr: str = '') -> str:
        """Emit a named byte array with data from the binary."""
        try:
            data = self.loader.read_bytes(addr, size)
        except (ValueError, IndexError):
            return f'unsigned char {name}[{size}]; /* unreadable at 0x{addr:08x} */'

        if size <= 16:
            hex_vals = ', '.join(f'0x{b:02x}' for b in data)
            return f'const unsigned char {name}[{size}]{asm_attr} = {{ {hex_vals} }};'

        lines = [f'const unsigned char {name}[{size}]{asm_attr} = {{']
        for i in range(0, len(data), 16):
            chunk = data[i:i+16]
            hex_vals = ', '.join(f'0x{b:02x}' for b in chunk)
            comma = ',' if i + 16 < len(data) else ''
            # Add ASCII comment
            ascii_repr = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
            lines.append(f'    {hex_vals}{comma} /* {ascii_repr} */')
        lines.append('};')
        return '\n'.join(lines)

    @staticmethod
    def _escape_c_string(s: str) -> str:
        """Escape a string for inclusion in a C string literal."""
        result = []
        for c in s:
            if c == '\\':
                result.append('\\\\')
            elif c == '"':
                result.append('\\"')
            elif c == '\n':
                result.append('\\n')
            elif c == '\r':
                result.append('\\r')
            elif c == '\t':
                result.append('\\t')
            elif c == '\0':
                result.append('\\0')
            elif ord(c) < 32 or ord(c) > 126:
                result.append(f'\\x{ord(c):02x}')
            else:
                result.append(c)
        return ''.join(result)

    def generate_all(self, output_dir: str):
        """Generate all data files."""
        os.makedirs(output_dir, exist_ok=True)

        # Reset cross-section dedup for this generation run
        self._cross_section_names = set()

        files = [
            ('data.c', self.generate_data_c),
            ('bss.c', self.generate_bss_c),
            ('strings.c', self.generate_strings_c),
            ('rodata.c', self.generate_rodata_c),
        ]

        for filename, generator in files:
            path = os.path.join(output_dir, filename)
            content = generator()
            with open(path, 'w') as f:
                f.write(content)
                f.write('\n')
