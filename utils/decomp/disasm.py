"""Capstone-based disassembly engine for i386 Mach-O binaries."""

import bisect
from dataclasses import dataclass, field
from typing import Optional

from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_JUMP, CS_GRP_CALL, CS_GRP_RET, CS_OPT_SYNTAX_ATT
from capstone.x86 import (
    X86_OP_REG, X86_OP_IMM, X86_OP_MEM,
    X86_REG_EBX, X86_REG_EBP, X86_REG_ESP, X86_REG_EIP,
    X86_INS_CALL, X86_INS_JMP, X86_INS_RET,
    X86_INS_JA, X86_INS_JAE, X86_INS_JB, X86_INS_JBE,
    X86_INS_JE, X86_INS_JNE, X86_INS_JG, X86_INS_JGE,
    X86_INS_JL, X86_INS_JLE, X86_INS_JS, X86_INS_JNS,
    X86_INS_JO, X86_INS_JNO, X86_INS_JP, X86_INS_JNP,
    X86_INS_JCXZ, X86_INS_JECXZ,
    X86_INS_MOV, X86_INS_LEA, X86_INS_ADD, X86_INS_SUB,
    X86_INS_CMP, X86_INS_TEST, X86_INS_PUSH, X86_INS_POP,
    X86_INS_NOP,
)

from .macho_loader import MachOLoader
from .stabs_parser import StabsParser, Function, SourceLine


COND_JUMPS = {
    X86_INS_JA, X86_INS_JAE, X86_INS_JB, X86_INS_JBE,
    X86_INS_JE, X86_INS_JNE, X86_INS_JG, X86_INS_JGE,
    X86_INS_JL, X86_INS_JLE, X86_INS_JS, X86_INS_JNS,
    X86_INS_JO, X86_INS_JNO, X86_INS_JP, X86_INS_JNP,
    X86_INS_JCXZ, X86_INS_JECXZ,
}

# GCC2 PIC thunk pattern: call to get EIP into a register
PIC_THUNK_NAMES = {
    '__i686.get_pc_thunk.bx',
    '___i686.get_pc_thunk.bx',
    '_i686.get_pc_thunk.bx',
}


@dataclass
class Instruction:
    addr: int
    size: int
    mnemonic: str
    op_str: str
    bytes: bytes
    insn_id: int
    operands: list  # Capstone operand objects
    groups: list
    source_line: int = 0
    # Analysis results
    call_target: Optional[str] = None
    call_addr: Optional[int] = None
    jump_target: Optional[int] = None
    string_ref: Optional[str] = None
    data_ref: Optional[int] = None
    is_conditional_jump: bool = False
    is_unconditional_jump: bool = False
    is_call: bool = False
    is_ret: bool = False


@dataclass
class DisassembledFunction:
    func: Function
    instructions: list[Instruction] = field(default_factory=list)
    referenced_strings: dict[int, str] = field(default_factory=dict)
    called_functions: dict[int, str] = field(default_factory=dict)


class Disassembler:
    def __init__(self, loader: MachOLoader, stabs: StabsParser, att_syntax: bool = False):
        self.loader = loader
        self.stabs = stabs
        self.cs = Cs(CS_ARCH_X86, CS_MODE_32)
        self.cs.detail = True
        if att_syntax:
            self.cs.syntax = CS_OPT_SYNTAX_ATT

        # Build lookup tables
        self._func_addr_map: dict[int, str] = {}
        for f in stabs.all_functions:
            self._func_addr_map[f.addr] = f.name
        self._sym_addr_map = loader.build_symbol_addr_map()

        # PIC base tracking
        self._pic_thunk_addrs: set[int] = set()
        self._find_pic_thunks()

    def _find_pic_thunks(self):
        """Find addresses of PIC thunk functions."""
        for f in self.stabs.all_functions:
            if any(f.name.endswith(t) or f.name == t
                   for t in ('get_pc_thunk.bx', 'get_pc_thunk.cx',
                             'get_pc_thunk.dx')):
                self._pic_thunk_addrs.add(f.addr)
        # Also check symbol table
        for addr, name in self._sym_addr_map.items():
            if 'get_pc_thunk' in name:
                self._pic_thunk_addrs.add(addr)

    def disassemble_function(self, func: Function) -> DisassembledFunction:
        """Disassemble a single function."""
        result = DisassembledFunction(func=func)

        if func.size == 0:
            return result

        try:
            code = self.loader.read_bytes(func.addr, func.size)
        except (ValueError, IndexError):
            return result

        # Build line map for binary search
        line_addrs = sorted(func.line_map, key=lambda x: x.addr)
        line_addr_list = [sl.addr for sl in line_addrs]

        # PIC base tracking
        pic_base_reg = None
        pic_base_value = None

        for insn in self.cs.disasm(code, func.addr):
            inst = Instruction(
                addr=insn.address,
                size=insn.size,
                mnemonic=insn.mnemonic,
                op_str=insn.op_str,
                bytes=bytes(insn.bytes),
                insn_id=insn.id,
                operands=list(insn.operands),
                groups=list(insn.groups),
            )

            # Map to source line
            idx = bisect.bisect_right(line_addr_list, insn.address) - 1
            if idx >= 0:
                inst.source_line = line_addrs[idx].line

            # Classify instruction
            if CS_GRP_RET in insn.groups:
                inst.is_ret = True
            elif CS_GRP_CALL in insn.groups:
                inst.is_call = True
                self._resolve_call(inst, insn, result)
                # Track PIC base
                if inst.call_addr and inst.call_addr in self._pic_thunk_addrs:
                    pic_base_reg = X86_REG_EBX
                    pic_base_value = insn.address + insn.size
            elif insn.id in COND_JUMPS:
                inst.is_conditional_jump = True
                if insn.operands and insn.operands[0].type == X86_OP_IMM:
                    inst.jump_target = insn.operands[0].imm
            elif insn.id == X86_INS_JMP:
                inst.is_unconditional_jump = True
                if insn.operands and insn.operands[0].type == X86_OP_IMM:
                    inst.jump_target = insn.operands[0].imm

            # Resolve data references (PIC-relative and absolute)
            self._resolve_data_refs(inst, insn, pic_base_reg, pic_base_value, result)

            result.instructions.append(inst)

        return result

    def _resolve_call(self, inst: Instruction, insn, result: DisassembledFunction):
        """Resolve call target to function name."""
        if not insn.operands:
            return
        op = insn.operands[0]
        if op.type == X86_OP_IMM:
            target = op.imm
            inst.call_addr = target
            # Check jump table first
            name = self.loader.resolve_jump_table(target)
            if name:
                inst.call_target = name
                result.called_functions[target] = name
                return
            # Check known functions
            name = self._func_addr_map.get(target)
            if name:
                inst.call_target = name
                result.called_functions[target] = name
                return
            # Check symbol table
            name = self._sym_addr_map.get(target)
            if name:
                inst.call_target = name
                result.called_functions[target] = name
                return
        elif op.type == X86_OP_MEM:
            # Indirect call through pointer table
            if op.mem.base == 0 and op.mem.index == 0:
                addr = op.mem.disp
                name = self.loader.resolve_pointer_table(addr)
                if name:
                    inst.call_target = name
                    inst.call_addr = addr
                    result.called_functions[addr] = name

    def _resolve_data_refs(self, inst: Instruction, insn,
                           pic_base_reg, pic_base_value,
                           result: DisassembledFunction):
        """Resolve memory references to strings, globals, etc."""
        for op in insn.operands:
            if op.type == X86_OP_MEM:
                addr = None
                # PIC-relative: [ebx + offset]
                if (pic_base_reg and pic_base_value and
                        op.mem.base == pic_base_reg and op.mem.index == 0):
                    addr = pic_base_value + op.mem.disp
                # Absolute address: [disp] with no base/index
                elif op.mem.base == 0 and op.mem.index == 0 and op.mem.disp != 0:
                    addr = op.mem.disp

                if addr and addr > 0:
                    inst.data_ref = addr
                    if self.loader.is_in_cstring(addr):
                        try:
                            s = self.loader.read_cstring(addr)
                            inst.string_ref = s
                            result.referenced_strings[addr] = s
                        except (ValueError, IndexError):
                            pass
            elif op.type == X86_OP_IMM and not inst.is_call and not inst.is_conditional_jump and not inst.is_unconditional_jump:
                # Immediate that looks like an address
                addr = op.imm
                if addr > 0x1000 and self.loader.is_in_cstring(addr):
                    try:
                        s = self.loader.read_cstring(addr)
                        if s is not None:
                            inst.string_ref = s
                            inst.data_ref = addr
                            result.referenced_strings[addr] = s
                    except (ValueError, IndexError):
                        pass

    def disassemble_all(self) -> dict[int, DisassembledFunction]:
        """Disassemble all functions."""
        results = {}
        for func in self.stabs.all_functions:
            if func.size > 0:
                results[func.addr] = self.disassemble_function(func)
        return results

    def resolve_name(self, addr: int) -> Optional[str]:
        """Resolve an address to a symbol name."""
        name = self.loader.resolve_jump_table(addr)
        if name:
            return name
        name = self._func_addr_map.get(addr)
        if name:
            return name
        name = self._sym_addr_map.get(addr)
        if name:
            return name
        name = self.loader.resolve_pointer_table(addr)
        if name:
            return name
        return None
