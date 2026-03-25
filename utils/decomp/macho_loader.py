"""Mach-O i386 binary parser for COD2 decompilation."""

import struct
from dataclasses import dataclass, field
from typing import Optional


# Mach-O constants
MH_MAGIC = 0xFEEDFACE
CPU_TYPE_I386 = 7

LC_SEGMENT = 1
LC_SYMTAB = 2
LC_UNIXTHREAD = 5
LC_DYSYMTAB = 11
LC_LOAD_DYLIB = 12
LC_LOAD_DYLINKER = 14

# Section types
S_SYMBOL_STUBS = 0x8
S_LAZY_SYMBOL_POINTERS = 0x7
S_NON_LAZY_SYMBOL_POINTERS = 0x6

# nlist n_type masks
N_STAB = 0xe0
N_EXT = 0x01
N_TYPE = 0x0e
N_UNDF = 0x0
N_ABS = 0x2
N_SECT = 0xe
N_INDR = 0xa

# STABS types
N_GSYM = 0x20
N_FUN = 0x24
N_STSYM = 0x26
N_LCSYM = 0x28
N_BNSYM = 0x2e
N_OPT = 0x3c
N_RSYM = 0x40
N_SLINE = 0x44
N_ENSYM = 0x4e
N_SO = 0x60
N_SOL = 0x64
N_LSYM = 0x80
N_BINCL = 0x84
N_PSYM = 0xa0
N_EINCL = 0xa4
N_LBRAC = 0xc0
N_RBRAC = 0xe0
N_EXCL = 0xc4
N_BCOMM = 0x1e
N_ECOMM = 0x3e

INDIRECT_SYMBOL_LOCAL = 0x80000000
INDIRECT_SYMBOL_ABS = 0x40000000


@dataclass
class Section:
    sectname: str
    segname: str
    addr: int
    size: int
    offset: int
    align: int
    reloff: int
    nreloc: int
    flags: int
    reserved1: int
    reserved2: int

    @property
    def end_addr(self):
        return self.addr + self.size

    @property
    def sect_type(self):
        return self.flags & 0xff


@dataclass
class Segment:
    segname: str
    vmaddr: int
    vmsize: int
    fileoff: int
    filesize: int
    maxprot: int
    initprot: int
    nsects: int
    flags: int
    sections: list = field(default_factory=list)

    @property
    def end_addr(self):
        return self.vmaddr + self.vmsize


@dataclass
class NList:
    n_strx: int
    n_type: int
    n_sect: int
    n_desc: int
    n_value: int

    @property
    def is_stab(self):
        return bool(self.n_type & N_STAB)

    @property
    def is_external(self):
        return bool(self.n_type & N_EXT)

    @property
    def type_field(self):
        return self.n_type & N_TYPE


@dataclass
class Dylib:
    name: str
    timestamp: int
    current_version: int
    compat_version: int


class MachOLoader:
    def __init__(self, path: str):
        with open(path, 'rb') as f:
            self.data = f.read()

        self.segments: list[Segment] = []
        self.sections: list[Section] = []
        self.section_by_name: dict[tuple[str, str], Section] = {}
        self.dylibs: list[Dylib] = []
        self.symbols: list[NList] = []
        self.strtab: bytes = b''
        self.entry_point: int = 0

        # DYSYMTAB info
        self.ilocalsym = 0
        self.nlocalsym = 0
        self.iextdefsym = 0
        self.nextdefsym = 0
        self.iundefsym = 0
        self.nundefsym = 0
        self.indirect_syms: list[int] = []

        self._parse()

    def _parse(self):
        magic, cputype, cpusub, filetype, ncmds, sizeofcmds, flags = \
            struct.unpack_from('<IIIIIII', self.data, 0)
        assert magic == MH_MAGIC, f"Not a 32-bit Mach-O: 0x{magic:08x}"
        assert cputype == CPU_TYPE_I386, f"Not i386: {cputype}"

        offset = 28  # past header
        for _ in range(ncmds):
            cmd, cmdsize = struct.unpack_from('<II', self.data, offset)
            self._parse_load_command(cmd, offset, cmdsize)
            offset += cmdsize

    def _parse_load_command(self, cmd, offset, cmdsize):
        if cmd == LC_SEGMENT:
            self._parse_segment(offset)
        elif cmd == LC_SYMTAB:
            self._parse_symtab(offset)
        elif cmd == LC_DYSYMTAB:
            self._parse_dysymtab(offset)
        elif cmd == LC_UNIXTHREAD:
            self._parse_unixthread(offset)
        elif cmd == LC_LOAD_DYLIB:
            self._parse_dylib(offset, cmdsize)

    def _parse_segment(self, offset):
        segname = self.data[offset+8:offset+24].split(b'\x00')[0].decode()
        vmaddr, vmsize, fileoff, filesize, maxprot, initprot, nsects, flags = \
            struct.unpack_from('<IIIIIIII', self.data, offset + 24)

        seg = Segment(segname, vmaddr, vmsize, fileoff, filesize,
                      maxprot, initprot, nsects, flags)

        sect_offset = offset + 56
        for _ in range(nsects):
            sect = self._parse_section(sect_offset)
            seg.sections.append(sect)
            self.sections.append(sect)
            self.section_by_name[(sect.segname, sect.sectname)] = sect
            sect_offset += 68

        self.segments.append(seg)

    def _parse_section(self, offset):
        sectname = self.data[offset:offset+16].split(b'\x00')[0].decode()
        segname = self.data[offset+16:offset+32].split(b'\x00')[0].decode()
        addr, size, foff, align, reloff, nreloc, flags, r1, r2 = \
            struct.unpack_from('<IIIIIIIII', self.data, offset + 32)
        return Section(sectname, segname, addr, size, foff, align,
                       reloff, nreloc, flags, r1, r2)

    def _parse_symtab(self, offset):
        symoff, nsyms, stroff, strsize = struct.unpack_from('<IIII', self.data, offset + 8)
        self.strtab = self.data[stroff:stroff + strsize]
        for i in range(nsyms):
            off = symoff + i * 12
            n_strx, n_type, n_sect, n_desc, n_value = \
                struct.unpack_from('<IBBHI', self.data, off)
            self.symbols.append(NList(n_strx, n_type, n_sect, n_desc, n_value))

    def _parse_dysymtab(self, offset):
        vals = struct.unpack_from('<' + 'I' * 18, self.data, offset + 8)
        self.ilocalsym = vals[0]
        self.nlocalsym = vals[1]
        self.iextdefsym = vals[2]
        self.nextdefsym = vals[3]
        self.iundefsym = vals[4]
        self.nundefsym = vals[5]
        indirectsymoff = vals[12]
        nindirectsyms = vals[13]
        for i in range(nindirectsyms):
            val = struct.unpack_from('<I', self.data, indirectsymoff + i * 4)[0]
            self.indirect_syms.append(val)

    def _parse_unixthread(self, offset):
        # i386 thread state: flavor(4) + count(4) + 16 regs
        # EIP is register 10 in the i386_thread_state
        regs = struct.unpack_from('<' + 'I' * 16, self.data, offset + 16)
        self.entry_point = regs[10]

    def _parse_dylib(self, offset, cmdsize):
        name_offset = struct.unpack_from('<I', self.data, offset + 8)[0]
        timestamp, cur_ver, compat_ver = struct.unpack_from('<III', self.data, offset + 12)
        name_bytes = self.data[offset + name_offset:offset + cmdsize]
        name = name_bytes.split(b'\x00')[0].decode()
        self.dylibs.append(Dylib(name, timestamp, cur_ver, compat_ver))

    def get_string(self, strx: int) -> str:
        if strx == 0 or strx >= len(self.strtab):
            return ''
        end = self.strtab.index(b'\x00', strx)
        return self.strtab[strx:end].decode('ascii', errors='replace')

    def read_bytes(self, addr: int, size: int) -> bytes:
        for seg in self.segments:
            if seg.vmaddr <= addr < seg.end_addr:
                file_offset = seg.fileoff + (addr - seg.vmaddr)
                return self.data[file_offset:file_offset + size]
        raise ValueError(f"Address 0x{addr:x} not in any segment")

    def read_u32(self, addr: int) -> int:
        return struct.unpack('<I', self.read_bytes(addr, 4))[0]

    def read_cstring(self, addr: int) -> str:
        result = bytearray()
        for seg in self.segments:
            if seg.vmaddr <= addr < seg.end_addr:
                file_offset = seg.fileoff + (addr - seg.vmaddr)
                i = file_offset
                while i < len(self.data) and self.data[i] != 0:
                    result.append(self.data[i])
                    i += 1
                return result.decode('ascii', errors='replace')
        return ''

    def addr_to_section(self, addr: int) -> Optional[Section]:
        for sect in self.sections:
            if sect.addr <= addr < sect.end_addr:
                return sect
        return None

    def addr_to_segment(self, addr: int) -> Optional[Segment]:
        for seg in self.segments:
            if seg.vmaddr <= addr < seg.end_addr:
                return seg
        return None

    def resolve_jump_table(self, addr: int) -> Optional[str]:
        jt = self.section_by_name.get(('__IMPORT', '__jump_table'))
        if jt is None:
            return None
        if not (jt.addr <= addr < jt.end_addr):
            return None
        entry_size = jt.reserved2  # 5 bytes per stub
        if entry_size == 0:
            return None
        idx = (addr - jt.addr) // entry_size
        indirect_idx = jt.reserved1 + idx
        if indirect_idx >= len(self.indirect_syms):
            return None
        sym_idx = self.indirect_syms[indirect_idx]
        if sym_idx & (INDIRECT_SYMBOL_LOCAL | INDIRECT_SYMBOL_ABS):
            return None
        if sym_idx >= len(self.symbols):
            return None
        return self.get_string(self.symbols[sym_idx].n_strx)

    def resolve_pointer_table(self, addr: int) -> Optional[str]:
        for sect_key in [('__IMPORT', '__pointers'),
                         ('__DATA', '__nl_symbol_ptr'),
                         ('__DATA', '__la_sym_ptr2')]:
            sect = self.section_by_name.get(sect_key)
            if sect is None:
                continue
            if not (sect.addr <= addr < sect.end_addr):
                continue
            idx = (addr - sect.addr) // 4
            indirect_idx = sect.reserved1 + idx
            if indirect_idx >= len(self.indirect_syms):
                return None
            sym_idx = self.indirect_syms[indirect_idx]
            if sym_idx & (INDIRECT_SYMBOL_LOCAL | INDIRECT_SYMBOL_ABS):
                return None
            if sym_idx >= len(self.symbols):
                return None
            return self.get_string(self.symbols[sym_idx].n_strx)
        return None

    def get_import_symbols(self) -> list[tuple[str, int]]:
        result = []
        for i in range(self.iundefsym, self.iundefsym + self.nundefsym):
            sym = self.symbols[i]
            name = self.get_string(sym.n_strx)
            result.append((name, i))
        return result

    def build_symbol_addr_map(self) -> dict[int, str]:
        if hasattr(self, '_symbol_addr_map_cache'):
            return self._symbol_addr_map_cache
        addr_map = {}
        for sym in self.symbols:
            if not sym.is_stab and sym.n_value != 0:
                name = self.get_string(sym.n_strx)
                if name:
                    addr_map[sym.n_value] = name
        self._symbol_addr_map_cache = addr_map
        return addr_map

    def is_in_cstring(self, addr: int) -> bool:
        sect = self.section_by_name.get(('__TEXT', '__cstring'))
        if sect is None:
            return False
        return sect.addr <= addr < sect.end_addr

    def is_in_text(self, addr: int) -> bool:
        sect = self.section_by_name.get(('__TEXT', '__text'))
        if sect is None:
            return False
        return sect.addr <= addr < sect.end_addr

    def is_in_jump_table(self, addr: int) -> bool:
        jt = self.section_by_name.get(('__IMPORT', '__jump_table'))
        if jt is None:
            return False
        return jt.addr <= addr < jt.end_addr
