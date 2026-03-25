"""Inline assembly emitter: produces naked C functions with AT&T asm bodies.

Each function is emitted as __attribute__((naked)) with __asm__ __volatile__()
containing the original x86 instructions in AT&T syntax. All addresses are
resolved to symbolic names so the output actually links.
"""

import gc
import os
import re
import struct
from typing import Optional

from .macho_loader import MachOLoader
from .stabs_parser import StabsParser, CompilationUnit, Function, GlobalVar
from .type_system import TypeResolver, REGISTER_NAMES
from .disasm import Disassembler, DisassembledFunction, Instruction
from .demangle import demangle_display, get_demangler

try:
    from capstone.x86 import (
        X86_OP_REG, X86_OP_MEM,
        X86_REG_EAX, X86_REG_ECX, X86_REG_EDX, X86_REG_EBX,
        X86_REG_ESP, X86_REG_EBP, X86_REG_ESI, X86_REG_EDI,
        X86_REG_AX, X86_REG_CX, X86_REG_DX, X86_REG_BX,
        X86_REG_SP, X86_REG_BP, X86_REG_SI, X86_REG_DI,
        X86_REG_AL, X86_REG_CL, X86_REG_DL, X86_REG_BL,
        X86_REG_AH, X86_REG_CH, X86_REG_DH, X86_REG_BH,
        X86_REG_XMM0, X86_REG_XMM1, X86_REG_XMM2, X86_REG_XMM3,
        X86_REG_XMM4, X86_REG_XMM5, X86_REG_XMM6, X86_REG_XMM7,
    )
    _HAS_CAPSTONE_DETAIL = True
except ImportError:
    _HAS_CAPSTONE_DETAIL = False

# Map DWARF register numbers (from N_RSYM) to capstone register IDs.
# STABS/DWARF i386: 0-7=GPR, 12-19=x87 st(N), 21-28=xmm0-xmm7
if _HAS_CAPSTONE_DETAIL:
    _DWARF_TO_CS_REG = {
        0: X86_REG_EAX, 1: X86_REG_ECX, 2: X86_REG_EDX, 3: X86_REG_EBX,
        4: X86_REG_ESP, 5: X86_REG_EBP, 6: X86_REG_ESI, 7: X86_REG_EDI,
        21: X86_REG_XMM0, 22: X86_REG_XMM1, 23: X86_REG_XMM2, 24: X86_REG_XMM3,
        25: X86_REG_XMM4, 26: X86_REG_XMM5, 27: X86_REG_XMM6, 28: X86_REG_XMM7,
    }
    # Map capstone register ID to its parent (for sub-register matching)
    _CS_REG_PARENT = {}
    for _parent, _subs in [
        (X86_REG_EAX, [X86_REG_AX, X86_REG_AL, X86_REG_AH]),
        (X86_REG_ECX, [X86_REG_CX, X86_REG_CL, X86_REG_CH]),
        (X86_REG_EDX, [X86_REG_DX, X86_REG_DL, X86_REG_DH]),
        (X86_REG_EBX, [X86_REG_BX, X86_REG_BL, X86_REG_BH]),
        (X86_REG_ESP, [X86_REG_SP]),
        (X86_REG_EBP, [X86_REG_BP]),
        (X86_REG_ESI, [X86_REG_SI]),
        (X86_REG_EDI, [X86_REG_DI]),
    ]:
        _CS_REG_PARENT[_parent] = _parent
        for _sub in _subs:
            _CS_REG_PARENT[_sub] = _parent
    # XMM registers are their own parents (no sub-registers)
    for _xmm in (X86_REG_XMM0, X86_REG_XMM1, X86_REG_XMM2, X86_REG_XMM3,
                  X86_REG_XMM4, X86_REG_XMM5, X86_REG_XMM6, X86_REG_XMM7):
        _CS_REG_PARENT[_xmm] = _xmm

    # Callee-saved registers (survive function calls — reliable for live ranges)
    _CALLEE_SAVED = {X86_REG_EBX, X86_REG_ESI, X86_REG_EDI}
    # Caller-saved registers (clobbered by calls — only annotate at assignment)
    _CALLER_SAVED = {X86_REG_EAX, X86_REG_ECX, X86_REG_EDX,
                     X86_REG_XMM0, X86_REG_XMM1, X86_REG_XMM2, X86_REG_XMM3,
                     X86_REG_XMM4, X86_REG_XMM5, X86_REG_XMM6, X86_REG_XMM7}


# Base path to strip from source file paths
SOURCE_PREFIX = '/Users/kevin/Development/i5works/COD2/Project/'
ALT_PREFIX = '/SourceCache/'

# PIC thunk patterns to detect and nop out
PIC_THUNK_PATTERNS = {
    'get_pc_thunk.bx', 'get_pc_thunk.cx', 'get_pc_thunk.dx',
    'get_pc_thunk.ax',
}

# Instructions that reference code addresses (branches/calls)
BRANCH_MNEMONICS = {
    'call', 'jmp', 'je', 'jne', 'jz', 'jnz', 'jg', 'jge', 'jl', 'jle',
    'ja', 'jae', 'jb', 'jbe', 'js', 'jns', 'jo', 'jno', 'jp', 'jnp',
    'jcxz', 'jecxz', 'loop', 'loope', 'loopne',
}


class AsmEmitter:
    """Generates compilable C files with naked inline asm functions."""

    def __init__(self, loader: MachOLoader, stabs: StabsParser,
                 disasm: Disassembler, types: TypeResolver):
        self.loader = loader
        self.stabs = stabs
        self.disasm = disasm
        self.types = types
        self._addr_map: dict[int, str] = {}
        self._func_addrs: set[int] = set()
        self._literal_map: dict[int, str] = {}  # addr -> "1.0f" or "3.14159"
        self._build_address_map()
        self._build_literal_map()
        # Sorted addresses for nearest-symbol binary search
        self._sorted_addrs = sorted(self._addr_map.keys())

    def _build_address_map(self):
        """Build unified address→symbol name map from all sources."""
        # 1. STABS functions — use demangled name to match emitted definitions
        for f in self.stabs.all_functions:
            dname = demangle_display(f.name)
            if not self._is_cpp_only(dname):
                name = self._safe_func_name(dname)
            else:
                name = self._linux_name(f.name)
            self._addr_map[f.addr] = name
            self._func_addrs.add(f.addr)

        # 2. STABS globals
        for g in self.stabs.all_globals:
            if g.addr and g.name:
                name = self._linux_name(g.name)
                self._addr_map[g.addr] = name

        # 3. Symbol table (non-STABS, non-zero-value symbols)
        sym_map = self.loader.build_symbol_addr_map()
        for addr, name in sym_map.items():
            if addr not in self._addr_map:
                self._addr_map[addr] = self._linux_name(name)

        # 4. Jump table entries (imported functions)
        jt = self.loader.section_by_name.get(('__IMPORT', '__jump_table'))
        if jt and jt.reserved2 > 0:
            stride = jt.reserved2
            for i in range(jt.size // stride):
                addr = jt.addr + i * stride
                name = self.loader.resolve_jump_table(addr)
                if name:
                    self._addr_map[addr] = self._linux_name(name)

        # 5. Pointer table entries
        for sect_key in [('__IMPORT', '__pointers'),
                         ('__DATA', '__nl_symbol_ptr'),
                         ('__DATA', '__la_sym_ptr2')]:
            sect = self.loader.section_by_name.get(sect_key)
            if sect:
                for i in range(sect.size // 4):
                    addr = sect.addr + i * 4
                    name = self.loader.resolve_pointer_table(addr)
                    if name:
                        self._addr_map[addr] = self._linux_name(name)

        # 6. All cstring addresses — so $0xADDR immediates get resolved to str_XXXXXXXX
        cstring_sect = self.loader.section_by_name.get(('__TEXT', '__cstring'))
        if cstring_sect:
            addr = cstring_sect.addr
            end = cstring_sect.end_addr
            while addr < end:
                if addr not in self._addr_map:
                    try:
                        s = self.loader.read_cstring(addr)
                        if s is not None:
                            self._addr_map[addr] = f'str_{addr:08x}'
                            addr += len(s) + 1
                            continue
                    except (ValueError, IndexError):
                        pass
                else:
                    # Already mapped; skip past string
                    try:
                        s = self.loader.read_cstring(addr)
                        if s is not None:
                            addr += len(s) + 1
                            continue
                    except (ValueError, IndexError):
                        pass
                addr += 1

        # 7. Float/double literal pool addresses → lit4_XXXXXXXX / lit8_XXXXXXXX
        lit4 = self.loader.section_by_name.get(('__TEXT', '__literal4'))
        if lit4 and lit4.size > 0:
            for i in range(lit4.size // 4):
                addr = lit4.addr + i * 4
                if addr not in self._addr_map:
                    self._addr_map[addr] = f'lit4_{addr:08x}'

        lit8 = self.loader.section_by_name.get(('__TEXT', '__literal8'))
        if lit8 and lit8.size > 0:
            for i in range(lit8.size // 8):
                addr = lit8.addr + i * 8
                if addr not in self._addr_map:
                    self._addr_map[addr] = f'lit8_{addr:08x}'

        # 8. Import pointer table (__IMPORT,__pointers)
        # These are pointer slots: code does "movl SLOT, %eax" then "movl (%eax), ..."
        # to access the target symbol. On Linux, we create wrapper pointer vars
        # (imp_SYMBOL) that point to the actual symbol, preserving the indirection.
        self._import_targets = {}  # imp_name -> target_name
        import_ptrs = self.loader.section_by_name.get(('__IMPORT', '__pointers'))
        if import_ptrs:
            imp_data = self.loader.read_bytes(import_ptrs.addr, import_ptrs.size)
            for i in range(import_ptrs.size // 4):
                addr = import_ptrs.addr + i * 4
                if addr not in self._addr_map:
                    name = self.loader.resolve_pointer_table(addr)
                    if not name:
                        # Local symbol — read pointer value and resolve
                        val = struct.unpack('<I', imp_data[i*4:i*4+4])[0]
                        name = sym_map.get(val)
                    if name:
                        # Use the same name resolution as function emission:
                        # strip Mach-O prefix first, then demangle
                        linux = self._linux_name(name)
                        dname = demangle_display(linux)
                        if not self._is_cpp_only(dname):
                            target = self._safe_func_name(dname)
                        else:
                            target = linux
                        imp_name = f'imp_{target}'
                        self._addr_map[addr] = imp_name
                        self._import_targets[imp_name] = target
                    else:
                        self._addr_map[addr] = f'imp_{addr:08x}'

        # 9. Rodata section (__TEXT,__const) — addr→label for known rodata entries
        rodata_sect = self.loader.section_by_name.get(('__TEXT', '__const'))
        if rodata_sect:
            if rodata_sect.addr not in self._addr_map:
                self._addr_map[rodata_sect.addr] = f'rodata_{rodata_sect.addr:08x}'

        # 10. Data section (__DATA,__data)
        data_sect = self.loader.section_by_name.get(('__DATA', '__data'))
        if data_sect:
            if data_sect.addr not in self._addr_map:
                self._addr_map[data_sect.addr] = f'data_{data_sect.addr:08x}'

        # 11. BSS section (__DATA,__bss)
        bss_sect = self.loader.section_by_name.get(('__DATA', '__bss'))
        if bss_sect:
            if bss_sect.addr not in self._addr_map:
                self._addr_map[bss_sect.addr] = f'bss_{bss_sect.addr:08x}'

    def _build_literal_map(self):
        """Build address→formatted value map for float/double literal pools."""
        # __TEXT,__literal4 — single-precision floats
        lit4 = self.loader.section_by_name.get(('__TEXT', '__literal4'))
        if lit4 and lit4.size > 0:
            data = self.loader.read_bytes(lit4.addr, lit4.size)
            for i in range(lit4.size // 4):
                addr = lit4.addr + i * 4
                val = struct.unpack('<f', data[i*4:i*4+4])[0]
                self._literal_map[addr] = self._format_float(val)

        # __TEXT,__literal8 — double-precision floats
        lit8 = self.loader.section_by_name.get(('__TEXT', '__literal8'))
        if lit8 and lit8.size > 0:
            data = self.loader.read_bytes(lit8.addr, lit8.size)
            for i in range(lit8.size // 8):
                addr = lit8.addr + i * 8
                val = struct.unpack('<d', data[i*8:i*8+8])[0]
                self._literal_map[addr] = self._format_double(val)

    # Sections where nearest-symbol+offset resolution is valid
    # (not valid for code section where offsets would be function-internal)
    _DATA_SECTIONS = {
        ('__DATA', '__bss'), ('__DATA', '__common'), ('__DATA', '__data'),
        ('__DATA', '__const'), ('__DATA', '__const_coal'),
        ('__TEXT', '__const'), ('__TEXT', '__cstring'),
    }
    # BSS/common sections: uninitialized data where $sym+offset immediates
    # are almost always false positives (bitmask constants in BSS address range)
    _BSS_SECTIONS = {
        ('__DATA', '__bss'), ('__DATA', '__common'),
    }

    def _resolve_nearest(self, addr: int, exclude_bss: bool = False) -> Optional[str]:
        """Resolve an address to nearest_symbol+offset if within a data section.

        Returns 'symbol+offset' or 'symbol' (if offset=0), or None.
        Max offset of 0x100000 (1MB) to avoid false positives.
        If exclude_bss=True, skip BSS/common sections (used for $ immediates
        where the value is likely a constant, not an address into BSS).
        """
        import bisect
        idx = bisect.bisect_right(self._sorted_addrs, addr) - 1
        if idx < 0:
            return None
        base_addr = self._sorted_addrs[idx]
        offset = addr - base_addr
        if offset < 0 or offset > 0x100000:
            return None
        # Don't resolve to function+offset (that's not meaningful data)
        if base_addr in self._func_addrs:
            return None
        # Verify the base address is in a data section
        in_data = False
        in_bss = False
        for sect_key in self._DATA_SECTIONS:
            sect = self.loader.section_by_name.get(sect_key)
            if sect and sect.addr <= base_addr < sect.end_addr:
                in_data = True
                if sect_key in self._BSS_SECTIONS:
                    in_bss = True
                break
        if not in_data:
            return None
        # For $ immediates, skip BSS+offset — these are almost always
        # bitmask/flag constants that happen to fall in BSS address range
        if exclude_bss and in_bss and offset > 0:
            return None
        sym = self._addr_map[base_addr]
        if offset == 0:
            return sym
        return f'{sym}+{offset}'

    @staticmethod
    def _format_float(val: float) -> str:
        """Format a float constant for annotation."""
        if val == int(val) and abs(val) < 1e7:
            return f'{int(val)}.0f'
        return f'{val}f'

    @staticmethod
    def _format_double(val: float) -> str:
        """Format a double constant for annotation."""
        if val == int(val) and abs(val) < 1e15:
            return f'{int(val)}.0'
        return f'{val}'

    @staticmethod
    def _linux_name(name: str) -> str:
        """Strip macOS leading underscore for Linux ELF symbols.
        Double underscores (__) are preserved EXCEPT for C++ mangled names
        (__Z...) where the first _ is the Mach-O prefix."""
        if name.startswith('__Z'):
            # C++ mangled: __ZNxxx -> _ZNxxx (strip Mach-O prefix)
            return name[1:]
        if name.startswith('_') and not name.startswith('__'):
            return name[1:]
        return name

    def _is_pic_thunk_call(self, inst: Instruction) -> bool:
        """Check if instruction is a call to a PIC thunk."""
        if not inst.is_call:
            return False
        if inst.call_target:
            for pat in PIC_THUNK_PATTERNS:
                if pat in inst.call_target:
                    return True
        if inst.call_addr and inst.call_addr in self._addr_map:
            name = self._addr_map[inst.call_addr]
            for pat in PIC_THUNK_PATTERNS:
                if pat in name:
                    return True
        return False

    def _resolve_operand_addresses(self, inst: Instruction, op_str: str,
                                   func_start: int, func_end: int) -> str:
        """Transform operand string to use symbolic names instead of raw addresses.

        Handles:
        - call/jmp to function addresses → symbolic name
        - conditional branches to intra-function addresses → local labels
        - memory references to globals → symbolic name
        - PIC-relative [%ebx+offset] → resolved via data_ref
        """
        result = op_str

        # Handle branch/call targets (direct immediate operands like $0x12345 or 0x12345)
        mnemonic = inst.mnemonic.split()[0] if inst.mnemonic else ''
        if mnemonic in BRANCH_MNEMONICS or mnemonic == 'calll':
            # AT&T call/jmp uses bare address or *%reg for indirect
            # Match hex address like 0x12345 (not prefixed with $)
            addr_match = re.match(r'^(0x[0-9a-fA-F]+)$', result.strip())
            if addr_match:
                addr = int(addr_match.group(1), 16)
                resolved = self._resolve_code_addr(addr, func_start, func_end)
                if resolved:
                    return resolved

        # Handle memory operand addresses - absolute addressing like 0x12345 or 0x12345(%reg)
        # Replace absolute addresses in memory operands with symbolic names
        result = self._resolve_mem_operands(inst, result, func_start, func_end)

        return result

    def _resolve_code_addr(self, addr: int, func_start: int, func_end: int) -> Optional[str]:
        """Resolve a code address to a symbol name or local label."""
        # Check if it's a known function/symbol
        if addr in self._addr_map:
            return self._addr_map[addr]
        # If within current function, use local label
        # Include func_start in label to avoid collisions between functions in the same CU
        if func_start <= addr < func_end:
            return f'.Lf{func_start:x}_{addr:08x}'
        # Try disassembler's resolve
        name = self.disasm.resolve_name(addr)
        if name:
            return self._linux_name(name)
        return None

    def _resolve_mem_operands(self, inst: Instruction, op_str: str,
                              func_start: int, func_end: int) -> str:
        """Resolve memory operand addresses to symbolic names."""
        # If the instruction has a data_ref, try to resolve it
        if inst.data_ref and inst.data_ref in self._addr_map:
            sym_name = self._addr_map[inst.data_ref]
            # Replace the raw address with the symbolic name
            # Match patterns like: 0xADDR, 0xADDR(%reg), 0xADDR(,%reg,N)
            hex_addr = f'0x{inst.data_ref:x}'
            if hex_addr in op_str:
                op_str = op_str.replace(hex_addr, sym_name)
                return op_str
            # Also try without 0x prefix for negative displacements
            # and with different formatting
            hex_addr_upper = f'0x{inst.data_ref:X}'
            if hex_addr_upper in op_str:
                op_str = op_str.replace(hex_addr_upper, sym_name)
                return op_str

            # PIC-relative: 0xOFFSET(%ebx) where data_ref = pic_base + offset
            # The offset in the operand doesn't match data_ref, so replace the
            # entire displacement(%ebx) with absolute sym_name addressing
            pic_match = re.search(r'(-?0x[0-9a-fA-F]+)\(%ebx\)', op_str)
            if pic_match:
                if inst.mnemonic.startswith('lea'):
                    # lea: loading the address itself → replace entire operand
                    op_str = op_str.replace(pic_match.group(0), sym_name)
                else:
                    # mov/cmp/etc: memory access → replace with absolute addressing
                    op_str = op_str.replace(pic_match.group(0), sym_name)
                return op_str

        # Instructions where $ immediates are always numeric constants, never addresses.
        # Bitwise ops use bitmasks; imul uses magic constants for division optimization.
        # _resolve_nearest would wrongly map e.g. $0x00FFFFFF → $g_effectVisArray+4351
        _CONST_IMM_MNEMONICS = frozenset({
            'andl', 'andw', 'andb',
            'orl', 'orw', 'orb',
            'xorl', 'xorw', 'xorb',
            'testl', 'testw', 'testb',
            'imull', 'imulw',
            'btl', 'btw', 'btsl', 'btsw', 'btrl', 'btrw', 'btcl', 'btcw',
        })
        mnem = inst.mnemonic
        skip_nearest_for_imm = mnem in _CONST_IMM_MNEMONICS

        # Match bare absolute addresses in operands: $0x12345 (immediate) or 0x12345 (memory)
        def replace_addr(match):
            prefix = match.group(1)  # '$' or empty
            addr_str = match.group(2)
            addr = int(addr_str, 16)
            if addr in self._addr_map:
                return prefix + self._addr_map[addr]
            # Try nearest-symbol+offset for data section addresses
            # Skip for $ immediates on bitwise/test/imul instructions where
            # the immediate is always a numeric constant, not an address
            if prefix == '$' and skip_nearest_for_imm:
                return match.group(0)
            # For $ immediates, exclude BSS/common — constants like $0x00FFFFFF
            # often fall within large BSS arrays but are bitmask/flag values
            is_imm = (prefix == '$')
            nearest = self._resolve_nearest(addr, exclude_bss=is_imm)
            if nearest:
                return prefix + nearest
            return match.group(0)

        # $0xADDR (immediate address reference)
        op_str = re.sub(r'(\$)(0x[0-9a-fA-F]{4,})', replace_addr, op_str)
        # Bare 0xADDR as memory operand (not part of displacement like 0x4(%ebp))
        # Only match if it looks like an absolute address (>0x1000) and not a small displacement
        # Lookbehind includes $ to avoid re-matching hex digits inside $0xADDR
        op_str = re.sub(r'(?<![,%\w$])()(0x[0-9a-fA-F]{5,})(?![0-9a-fA-F])', replace_addr, op_str)

        return op_str

    def _format_instruction(self, inst: Instruction, func_start: int,
                            func_end: int) -> Optional[str]:
        """Format a single instruction as an inline asm string.

        Returns None if the instruction should be skipped (e.g., PIC thunk calls).
        """
        # Skip PIC thunk calls - not needed with -fno-pie
        if self._is_pic_thunk_call(inst):
            return None

        mnemonic = inst.mnemonic
        op_str = inst.op_str

        # Resolve symbolic addresses in operands
        op_str = self._resolve_operand_addresses(inst, op_str, func_start, func_end)

        # Keep single % for registers — we use basic asm (no operand sections),
        # so AT&T register syntax (%eax, %ebp etc.) is passed through as-is.

        # Build the asm line
        if op_str:
            asm_line = f'{mnemonic} {op_str}'
        else:
            asm_line = mnemonic

        return asm_line

    def _build_var_maps(self, func: Function) -> tuple[dict, dict]:
        """Build variable annotation maps for a function.

        Returns (stack_map, reg_ranges):
          stack_map: ebp_offset (int) -> variable name (str)
          reg_ranges: capstone parent reg id -> list of (start_line, end_line, name)
            where end_line is the next reassignment line (or 999999 for last range)
        """
        stack_map = {}  # ebp_offset -> name

        # Parameters: positive EBP offsets (ebp+8, ebp+12, ...)
        for p in func.params:
            if p.stack_offset not in stack_map:
                stack_map[p.stack_offset] = p.name

        # Local variables: negative EBP offsets stored as unsigned 32-bit
        seen_locals = set()
        for lv in func.locals:
            offset = lv.ebp_offset
            if offset > 0x7fffffff:
                offset = offset - 0x100000000
            if offset not in stack_map and offset not in seen_locals:
                stack_map[offset] = lv.name
                seen_locals.add(offset)

        # Register variables: build live ranges per register
        # Each entry: (start_line, end_line, name, is_param)
        reg_ranges = {}
        if _HAS_CAPSTONE_DETAIL:
            # Group by capstone register, deduplicate, sort by line
            by_reg = {}
            for rv in func.reg_vars:
                cs_reg = _DWARF_TO_CS_REG.get(rv.register)
                if cs_reg is not None:
                    by_reg.setdefault(cs_reg, []).append(
                        (rv.line, rv.name, rv.is_param))

            for reg, entries in by_reg.items():
                # Deduplicate and sort
                unique = sorted(set(entries))
                # Build ranges: each assignment ends at the next assignment to same reg
                ranges = []
                for idx, (line, name, is_p) in enumerate(unique):
                    if idx + 1 < len(unique):
                        end_line = unique[idx + 1][0]
                    else:
                        end_line = 999999
                    ranges.append((line, end_line, name, is_p))
                reg_ranges[reg] = ranges

        return stack_map, reg_ranges

    def _reg_var_at_line(self, reg_ranges: dict, cs_parent_reg: int,
                         source_line: int) -> Optional[tuple]:
        """Look up which variable is in a register at a given source line.

        Returns (name, is_param) or None.
        """
        ranges = reg_ranges.get(cs_parent_reg)
        if not ranges:
            return None
        for start, end, name, is_param in ranges:
            if start <= source_line < end:
                return (name, is_param)
        return None

    def _annotate_instruction(self, inst: Instruction, stack_map: dict,
                              reg_ranges: dict, source_line: int) -> Optional[str]:
        """Generate a variable annotation comment for an instruction.

        Annotates:
        - EBP-relative memory accesses with param/local names (always)
        - Callee-saved register operands (ebx, esi, edi) within their live range
        - Caller-saved register operands only at the exact assignment line
        - XMM register operands within their live range
        - Float/double literal pool references with their values
        """
        if not _HAS_CAPSTONE_DETAIL or not inst.operands:
            # Still check for literal even without capstone detail
            if inst.data_ref and inst.data_ref in self._literal_map:
                return self._literal_map[inst.data_ref]
            return None

        # Skip prologue/epilogue boilerplate (push/pop/ret/leave)
        if inst.mnemonic in ('pushl', 'popl', 'push', 'pop', 'retl', 'ret',
                             'leave', 'nop'):
            return None

        annotations = []
        seen = set()

        # Float/double literal pool reference
        if inst.data_ref and inst.data_ref in self._literal_map:
            annotations.append(self._literal_map[inst.data_ref])

        for op in inst.operands:
            if op.type == X86_OP_MEM:
                base = _CS_REG_PARENT.get(op.mem.base)
                if base == X86_REG_EBP and op.mem.index == 0:
                    # Stack variable (param or local)
                    name = stack_map.get(op.mem.disp)
                    if name and name not in seen:
                        annotations.append(name)
                        seen.add(name)
                elif base and base != X86_REG_ESP:
                    # Memory access via register — annotate the base register
                    result = self._reg_var_at_line(reg_ranges, base, source_line)
                    if result:
                        name, is_param = result
                        if name not in seen and (base in _CALLEE_SAVED or is_param):
                            annotations.append(name)
                            seen.add(name)

            elif op.type == X86_OP_REG:
                parent = _CS_REG_PARENT.get(op.reg)
                if not parent:
                    continue
                result = self._reg_var_at_line(reg_ranges, parent, source_line)
                if not result:
                    continue
                name, is_param = result
                if name in seen:
                    continue
                # Register parameters: annotate throughout range (compiler chose this)
                # Callee-saved: annotate throughout live range
                if is_param or parent in _CALLEE_SAVED:
                    annotations.append(name)
                    seen.add(name)
                # Caller-saved: only at the assignment line to avoid noise
                elif parent in _CALLER_SAVED and source_line == self._reg_assign_line(
                        reg_ranges, parent, source_line):
                    annotations.append(name)
                    seen.add(name)

        return ', '.join(annotations) if annotations else None

    @staticmethod
    def _reg_assign_line(reg_ranges: dict, cs_parent_reg: int,
                         source_line: int) -> int:
        """Return the start_line of the range containing source_line, or -1."""
        ranges = reg_ranges.get(cs_parent_reg)
        if not ranges:
            return -1
        for start, end, name, is_param in ranges:
            if start <= source_line < end:
                return start
        return -1

    def emit_function_asm(self, func: Function) -> str:
        """Produce a naked C function with inline asm body."""
        dfunc = self.disasm.disassemble_function(func)
        if not dfunc.instructions:
            return f'/* {func.name}: no instructions */\n'

        func_end = func.addr + func.size
        fname = demangle_display(func.name)
        is_cpp = self._is_cpp_only(fname)
        static_prefix = 'static ' if func.is_static else ''

        if is_cpp:
            # Use mangled name as C identifier for C++-only functions
            cname = self._linux_name(func.name)
            proto = f'void {cname}(void) /* {fname} */'
        else:
            proto = self._make_func_prototype(func)

        lines = []
        lines.append(f'{static_prefix}__attribute__((naked))')
        lines.append(f'{proto}')
        lines.append('{')
        lines.append('    __asm__ __volatile__ (')

        # Collect all jump targets within this function for local labels
        local_targets = set()
        for inst in dfunc.instructions:
            if inst.jump_target and func.addr <= inst.jump_target < func_end:
                local_targets.add(inst.jump_target)
            # Also check call targets that are intra-function (rare but possible)
            if inst.call_addr and func.addr <= inst.call_addr < func_end:
                local_targets.add(inst.call_addr)

        # Map targets that don't correspond to instruction addresses to the
        # next instruction address (handles disassembly gaps/alignment)
        inst_addrs = {inst.addr for inst in dfunc.instructions}
        label_at_addr = {}  # instruction addr → list of labels to emit before it
        for target in sorted(local_targets):
            if target in inst_addrs:
                label_at_addr.setdefault(target, []).append(target)
            else:
                # Find next instruction at or after target
                for inst in dfunc.instructions:
                    if inst.addr >= target:
                        label_at_addr.setdefault(inst.addr, []).append(target)
                        break

        # Build variable annotation maps
        stack_map, reg_ranges = self._build_var_maps(func)

        # Build scope bracket lookup: addr -> list of ScopeBracket
        scope_at_addr = {}
        for sb in func.scope_brackets:
            scope_at_addr.setdefault(sb.addr, []).append(sb)

        # Build scope-local variable map: (scope_depth, ebp_offset) -> name
        # for variables declared inside inner scopes
        scope_locals = {}
        seen_scope = set()
        for lv in func.locals:
            if lv.scope_depth > 0:
                offset = lv.ebp_offset
                if offset > 0x7fffffff:
                    offset = offset - 0x100000000
                key = (lv.scope_depth, offset)
                if key not in seen_scope:
                    scope_locals[key] = lv.name
                    seen_scope.add(key)

        # Emit instructions
        prev_line = 0
        cur_source_line = func.start_line
        cur_scope_depth = 0
        for inst in dfunc.instructions:
            # Emit scope brackets before this instruction
            for sb in scope_at_addr.get(inst.addr, []):
                if sb.is_open:
                    cur_scope_depth = sb.depth
                    # Collect variables declared at this scope depth
                    scope_vars = [name for (d, _), name in scope_locals.items()
                                  if d == sb.depth]
                    if scope_vars:
                        var_list = ', '.join(scope_vars[:4])
                        if len(scope_vars) > 4:
                            var_list += ', ...'
                        lines.append(f'        /* {{ scope {sb.depth}: {var_list} */')
                    else:
                        lines.append(f'        /* {{ scope {sb.depth} */')
                else:
                    cur_scope_depth = sb.depth
                    lines.append(f'        /* }} scope */')

            # Emit local labels if this address has pending labels
            for label_target in label_at_addr.get(inst.addr, []):
                label = f'.Lf{func.addr:x}_{label_target:08x}'
                lines.append(f'        "{label}:\\n"')

            # Format instruction
            asm_line = self._format_instruction(inst, func.addr, func_end)
            if asm_line is None:
                # Skipped instruction (e.g. PIC thunk) - emit as nop
                lines.append(f'        "nop\\n" /* PIC thunk - removed */')
                continue

            # Track source line for register variable lookup
            if inst.source_line:
                cur_source_line = inst.source_line

            # Build comment parts
            comment_parts = []
            if inst.source_line and inst.source_line != prev_line:
                comment_parts.append(f'line {inst.source_line}')
                prev_line = inst.source_line

            # Variable annotation
            var_ann = self._annotate_instruction(inst, stack_map, reg_ranges,
                                                 cur_source_line)
            if var_ann:
                comment_parts.append(var_ann)

            if not comment_parts and inst.string_ref:
                s = inst.string_ref[:60].replace('*/', '* /')
                comment_parts.append(f'"{s}"')

            comment = ''
            if comment_parts:
                comment = f' /* {" | ".join(comment_parts)} */'

            lines.append(f'        "{asm_line}\\n"{comment}')

        lines.append('    );')
        lines.append('}')

        return '\n'.join(lines)

    @staticmethod
    def _is_cpp_only(fname: str) -> bool:
        """Check if a demangled function name contains C++-only syntax
        that cannot be expressed as valid C.

        These functions are emitted with their mangled name instead of
        being skipped, so they remain callable from asm code.
        """
        if '~' in fname:  # destructors
            return True
        if fname.startswith('global constructors') or fname.startswith('global destructors'):
            return True
        if 'operator' in fname and any(c in fname for c in '=<>+-*/%&|^!'):
            return True
        if '<' in fname:  # template instantiations
            return True
        return False

    # POSIX/libc function names that conflict when redeclared with different types
    _CONFLICTING_FUNC_NAMES = {
        'dprintf', 'printf', 'fprintf', 'sprintf', 'snprintf',
        'vprintf', 'vfprintf', 'vsprintf', 'vsnprintf',
        'malloc', 'free', 'realloc', 'calloc',
        'abort', 'exit', '_exit',
    }

    def _safe_func_name(self, fname: str) -> str:
        """Rename functions that conflict with POSIX/libc names."""
        if fname in self._CONFLICTING_FUNC_NAMES:
            return f'game_{fname}'
        return fname

    def _make_func_prototype(self, func: Function) -> str:
        """Generate a function prototype from STABS info."""
        import re as _re
        if func.return_type:
            ret_type = self.types.type_to_c(func.return_type, '', cu=func.cu).strip()
        else:
            ret_type = 'int'
        # Fix garbled return types (e.g., pointer-to-array from CU pollution)
        if _re.search(r'\(\*\)\[\d+\]', ret_type) or ret_type.count('(*)') > 1:
            ret_type = 'int'
        params = []
        used_names = set()
        for p in func.params:
            # Rename C++ 'this' keyword to '_this' for C compatibility
            pname = p.name if p.name != 'this' else '_this'
            # Deduplicate parameter names (e.g., two '_this' from overloads)
            if pname in used_names:
                pname = f'{pname}_{len(used_names)}'
            used_names.add(pname)
            ptype = self.types.type_to_c(p.type_ref, pname, cu=func.cu)
            # Fix "const const" from C++ const-qualified pointer params
            ptype = ptype.replace('const const', 'const')
            # Fix garbled types: pointer-to-array rendering in params
            if _re.search(r'\(\*\)\[\d+\]', ptype):
                ptype = f'void *{pname}'
            # Fix anonymous unions with unnamed fields (e.g., "union { int; PVOID Pointer; }")
            # These are invalid in C — replace with void *
            if _re.search(r'union\s*\{[^}]*;\s*\w+\s+\w+;\s*\}', ptype):
                ptype = f'void *{pname}'
            params.append(ptype)
        params_str = ', '.join(params) if params else 'void'
        fname = self._safe_func_name(demangle_display(func.name))
        return f'{ret_type} {fname}({params_str})'

    def _make_relative_path(self, source_file: str) -> Optional[str]:
        """Convert absolute source path to relative output path."""
        if not source_file:
            return None
        if source_file.startswith(SOURCE_PREFIX):
            rel = source_file[len(SOURCE_PREFIX):]
        elif source_file.startswith(ALT_PREFIX):
            rel = source_file[len(ALT_PREFIX):]
        else:
            name = source_file.split('/')[-1]
            if name:
                rel = name
            else:
                return None
        # Sanitize spaces in path components (e.g., "DirectX 9" → "DirectX_9")
        rel = rel.replace(' ', '_')
        return rel

    def emit_compilation_unit(self, cu: CompilationUnit, output_dir: str):
        """Emit a single compilation unit as a .c file with naked asm functions."""
        rel_path = self._make_relative_path(cu.source_file)
        if not rel_path:
            return

        # Map extensions
        if rel_path.endswith('.cp'):
            rel_path = rel_path[:-3] + '.c'
        elif rel_path.endswith('.cpp'):
            rel_path = rel_path[:-4] + '.c'
        elif not rel_path.endswith('.c') and not rel_path.endswith('.s'):
            rel_path = rel_path + '.c'

        output_path = os.path.join(output_dir, rel_path)
        os.makedirs(os.path.dirname(output_path), exist_ok=True)

        lines = self._generate_file_content(cu)

        with open(output_path, 'w') as f:
            f.write('\n'.join(lines))
            f.write('\n')

    def _generate_file_content(self, cu: CompilationUnit) -> list[str]:
        """Generate the content of a .c file with naked asm functions."""
        lines = []

        # File header
        orig_name = cu.source_file.split('/')[-1]
        lines.append(f'/* ASM dump from: {orig_name} */')
        lines.append(f'/* Original path: {cu.source_file} */')
        lines.append('')
        lines.append('#include "common_types.h"')
        lines.append('#include "imports.h"')

        # Document original includes from N_BINCL data
        game_includes = [h for h in cu.include_files if not h.startswith('/')]
        if game_includes:
            lines.append('')
            lines.append('/* Original includes (from N_BINCL debug info):')
            for h in game_includes:
                lines.append(f' *   #include "{h}"')
            lines.append(' */')
        lines.append('')

        # Variable names that conflict with system headers or C++ types
        _conflicting_varnames = {
            'index', 'string', 'send', 'time', 'div', 'link', 'stat',
            'signal', 'alarm', 'wait', 'read', 'write', 'open', 'close',
        }

        def _safe_varname(vn, addr):
            if vn in _conflicting_varnames:
                return f'{vn}_{addr:08x}'
            return vn

        # Deduplicate globals by (name, addr) to avoid redefinition errors
        seen_globals = set()  # (name, addr) pairs
        seen_global_names = {}  # name → addr for type conflict detection

        # Track unknown types that need local placeholders
        _unknown_types = set()

        def _fixup_type_decl(gtype, vname):
            """Fix unresolvable types in variable declarations."""
            # Detect C++ template types like vector_UINT32_std
            # that aren't in common_types.h
            _type_part = gtype.replace('extern ', '').replace('static ', '').strip()
            _type_part = _type_part.replace(vname, '').strip().rstrip(';').strip()
            if _type_part and re.match(r'^[a-zA-Z_]\w*$', _type_part):
                # Simple single-word type — check if it looks like a C++ template mangling
                if '_std' in _type_part or 'vector_' in _type_part:
                    if _type_part not in _unknown_types:
                        _unknown_types.add(_type_part)
                        lines.append(f'typedef int {_type_part}; /* C++ template placeholder */')
            return gtype

        # Extern declarations for global variables
        for gv in cu.globals:
            if gv.kind == 'global' and gv.name:
                vname = demangle_display(gv.name) if gv.name.startswith('_') else gv.name
                vname = _safe_varname(vname, gv.addr)
                key = (vname, gv.addr)
                if key in seen_globals:
                    continue
                # If same name at different address already declared, suffix
                if vname in seen_global_names and seen_global_names[vname] != gv.addr:
                    vname = f'{vname}_{gv.addr:08x}'
                    key = (vname, gv.addr)
                seen_globals.add(key)
                seen_global_names[vname] = gv.addr
                gtype = self.types.type_to_c(gv.type_ref, vname, cu=cu)
                gtype = _fixup_type_decl(gtype, vname)
                lines.append(f'extern {gtype}; /* 0x{gv.addr:x} */')

        # Static variable declarations
        for gv in cu.globals:
            if gv.kind in ('static', 'bss'):
                vname = demangle_display(gv.name) if gv.name.startswith('_') else gv.name
                vname = _safe_varname(vname, gv.addr)
                key = (vname, gv.addr)
                if key in seen_globals:
                    continue
                # If same name at different address already declared, suffix
                if vname in seen_global_names and seen_global_names[vname] != gv.addr:
                    vname = f'{vname}_{gv.addr:08x}'
                    key = (vname, gv.addr)
                seen_globals.add(key)
                seen_global_names[vname] = gv.addr
                gtype = self.types.type_to_c(gv.type_ref, vname, cu=cu)
                lines.append(f'static {gtype}; /* 0x{gv.addr:x} */')

        if cu.globals:
            lines.append('')

        # Forward declarations for functions
        sorted_funcs = sorted(cu.functions, key=lambda f: f.addr)
        emitted_func_names = set()  # Track to skip C++ overloaded duplicates
        for func in sorted_funcs:
            if func.size == 0:
                continue
            fname = demangle_display(func.name)
            is_cpp = self._is_cpp_only(fname)
            if is_cpp:
                # Emit C++ functions with mangled name so they're callable from asm
                cname = self._linux_name(func.name)
            else:
                cname = self._safe_func_name(fname)
            static_prefix = 'static ' if func.is_static else ''
            if cname in emitted_func_names:
                continue
            emitted_func_names.add(cname)
            if is_cpp:
                lines.append(f'{static_prefix}void {cname}(void); /* {fname} */')
            else:
                decl = self._make_func_prototype(func)
                lines.append(f'{static_prefix}{decl};')
        if sorted_funcs:
            lines.append('')

        # Function definitions with inline asm
        emitted_def_names = set()
        for func in sorted_funcs:
            if func.size == 0:
                lines.append(f'/* {func.name}: size=0, skipped */')
                lines.append('')
                continue

            fname = demangle_display(func.name)
            is_cpp = self._is_cpp_only(fname)
            if is_cpp:
                cname = self._linux_name(func.name)
            else:
                cname = self._safe_func_name(fname)

            if cname in emitted_def_names:
                lines.append(f'/* overload skip: {fname} (0x{func.addr:x}) */')
                lines.append('')
                continue
            emitted_def_names.add(cname)

            try:
                code = self.emit_function_asm(func)
                if func.start_line:
                    lines.append(f'/* line {func.start_line} */')
                lines.append(code)
                lines.append('')
            except Exception as e:
                lines.append(f'/* Error emitting {func.name}: {e} */')
                lines.append('')

        return lines

    def emit_function(self, func: Function) -> str:
        """Emit a single function as naked asm (for --function mode)."""
        return self.emit_function_asm(func)

    def emit_all(self, output_dir: str, progress_callback=None):
        """Emit all compilation units as .c files with inline asm."""
        os.makedirs(output_dir, exist_ok=True)

        # Generate common types header (monolithic — still the primary mechanism)
        types_header = self.types.generate_common_types_header()
        types_path = os.path.join(output_dir, 'common_types.h')
        with open(types_path, 'w') as f:
            f.write(types_header)

        # Generate per-header files alongside (supplementary)
        from .header_reconstruct import HeaderReconstructor
        hr = HeaderReconstructor(self.stabs, self.types)
        hr.generate_headers(output_dir)

        total = len(self.stabs.compilation_units)
        for idx, cu in enumerate(self.stabs.compilation_units):
            if not cu.functions:
                continue
            if progress_callback:
                progress_callback(idx, total, cu.source_file)
            self.emit_compilation_unit(cu, output_dir)
            # Periodic GC
            if idx % 20 == 0:
                get_demangler()._cache.clear()
                gc.collect()

        # Generate import pointer wrapper stubs
        if self._import_targets:
            self._emit_import_pointers(output_dir)

    def _emit_import_pointers(self, output_dir: str):
        """Generate import_pointers.c with wrapper pointer variables.

        On Mac, the __IMPORT.__pointers section contains pointer slots that
        the code loads via 'movl SLOT, %eax' to get the address of a global.
        On Linux, we create equivalent pointer variables.
        """
        path = os.path.join(output_dir, 'import_pointers.S')
        lines = ['/* Auto-generated import pointer wrappers */',
                 '/* Each imp_X is a 4-byte pointer to the target symbol */',
                 '.data',
                 '']

        for imp_name, target in sorted(self._import_targets.items()):
            lines.append(f'.globl {imp_name}')
            lines.append(f'{imp_name}: .long {target}')

        lines.append('')
        with open(path, 'w') as f:
            f.write('\n'.join(lines))

    def emit_file_by_name(self, filename: str, output_dir: str) -> bool:
        """Emit a specific source file by name pattern."""
        for cu in self.stabs.compilation_units:
            if filename in cu.source_file:
                self.emit_compilation_unit(cu, output_dir)
                return True
        return False
