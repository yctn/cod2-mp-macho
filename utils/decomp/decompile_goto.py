"""Expression-propagating C decompiler: translates x86 instructions to C.

Core principle: registers are temporary expression holders, NOT C variables.
Only emit a C statement when there's a visible side effect:
- Store to a named variable (STABS local/param via [ebp+/-N])
- Store to a global (named via address lookup)
- Function call (with resolved args from [esp+N] slots)
- Return (substitute eax expression)
- Conditional branch (substitute comparison operands)
"""

from typing import Optional
from .disasm import DisassembledFunction, Instruction
from .stabs_parser import (
    StabsParser, Function, StabsType, TypeRef, RangeType, PointerType,
    ConstType, VolatileType,
)
from .type_system import TypeResolver, REGISTER_NAMES
from .cfg import BasicBlock, CFGBuilder, JUMP_TO_COND, JUMP_TO_COND_INVERSE
from .demangle import demangle_display

from capstone.x86 import (
    X86_OP_REG, X86_OP_IMM, X86_OP_MEM,
    X86_REG_EAX, X86_REG_ECX, X86_REG_EDX, X86_REG_EBX,
    X86_REG_ESP, X86_REG_EBP, X86_REG_ESI, X86_REG_EDI,
    X86_REG_AX, X86_REG_CX, X86_REG_DX, X86_REG_BX,
    X86_REG_AL, X86_REG_CL, X86_REG_DL, X86_REG_BL,
    X86_REG_AH, X86_REG_CH, X86_REG_DH, X86_REG_BH,
    X86_REG_XMM0, X86_REG_XMM1, X86_REG_XMM2, X86_REG_XMM3,
    X86_REG_XMM4, X86_REG_XMM5, X86_REG_XMM6, X86_REG_XMM7,
    X86_INS_MOV, X86_INS_LEA, X86_INS_ADD, X86_INS_SUB,
    X86_INS_AND, X86_INS_OR, X86_INS_XOR, X86_INS_SHL,
    X86_INS_SHR, X86_INS_SAR, X86_INS_NOT, X86_INS_NEG,
    X86_INS_INC, X86_INS_DEC, X86_INS_IMUL, X86_INS_MUL,
    X86_INS_IDIV, X86_INS_DIV, X86_INS_CDQ,
    X86_INS_CMP, X86_INS_TEST,
    X86_INS_PUSH, X86_INS_POP,
    X86_INS_CALL, X86_INS_RET, X86_INS_JMP, X86_INS_NOP,
    X86_INS_MOVSX, X86_INS_MOVZX, X86_INS_MOVSXD,
    X86_INS_CMOVE, X86_INS_CMOVNE, X86_INS_CMOVG, X86_INS_CMOVGE,
    X86_INS_CMOVL, X86_INS_CMOVLE, X86_INS_CMOVA, X86_INS_CMOVAE,
    X86_INS_CMOVB, X86_INS_CMOVBE,
    X86_INS_SETE, X86_INS_SETNE, X86_INS_SETG, X86_INS_SETGE,
    X86_INS_SETL, X86_INS_SETLE, X86_INS_SETA, X86_INS_SETAE,
    X86_INS_SETB, X86_INS_SETBE,
    X86_INS_FLD, X86_INS_FSTP, X86_INS_FILD, X86_INS_FISTP,
    X86_INS_FADD, X86_INS_FSUB, X86_INS_FMUL, X86_INS_FDIV,
    X86_INS_FCOM, X86_INS_FUCOM, X86_INS_FNSTSW,
    X86_INS_FLDZ, X86_INS_FLD1, X86_INS_FCHS,
    # String operations
    X86_INS_CLD, X86_INS_STD,
    X86_INS_MOVSB, X86_INS_MOVSD, X86_INS_STOSB, X86_INS_STOSD,
    X86_INS_SCASB, X86_INS_CMPSB,
    # SSE scalar
    X86_INS_MOVSS, X86_INS_MOVAPS, X86_INS_MOVUPS,
    X86_INS_ADDSS, X86_INS_ADDSD, X86_INS_SUBSS, X86_INS_SUBSD,
    X86_INS_MULSS, X86_INS_MULSD, X86_INS_DIVSS, X86_INS_DIVSD,
    X86_INS_XORPS, X86_INS_XORPD, X86_INS_PXOR,
    X86_INS_CVTSI2SS, X86_INS_CVTSI2SD,
    X86_INS_CVTTSS2SI, X86_INS_CVTTSD2SI,
    X86_INS_COMISS, X86_INS_COMISD, X86_INS_UCOMISS, X86_INS_UCOMISD,
    # Misc
    X86_INS_SAHF, X86_INS_BSWAP, X86_INS_XCHG,
    X86_INS_FNSTCW, X86_INS_FLDCW,
)

# Map capstone register IDs to 32-bit register names
REG32_MAP = {
    X86_REG_EAX: 'eax', X86_REG_ECX: 'ecx', X86_REG_EDX: 'edx',
    X86_REG_EBX: 'ebx', X86_REG_ESP: 'esp', X86_REG_EBP: 'ebp',
    X86_REG_ESI: 'esi', X86_REG_EDI: 'edi',
}
REG16_MAP = {
    X86_REG_AX: 'ax', X86_REG_CX: 'cx', X86_REG_DX: 'dx', X86_REG_BX: 'bx',
}
REG8L_MAP = {
    X86_REG_AL: 'al', X86_REG_CL: 'cl', X86_REG_DL: 'dl', X86_REG_BL: 'bl',
}
REG8H_MAP = {
    X86_REG_AH: 'ah', X86_REG_CH: 'ch', X86_REG_DH: 'dh', X86_REG_BH: 'bh',
}
REG_TO_32 = {}
for r in (X86_REG_EAX, X86_REG_AX, X86_REG_AL, X86_REG_AH): REG_TO_32[r] = 'eax'
for r in (X86_REG_ECX, X86_REG_CX, X86_REG_CL, X86_REG_CH): REG_TO_32[r] = 'ecx'
for r in (X86_REG_EDX, X86_REG_DX, X86_REG_DL, X86_REG_DH): REG_TO_32[r] = 'edx'
for r in (X86_REG_EBX, X86_REG_BX, X86_REG_BL, X86_REG_BH): REG_TO_32[r] = 'ebx'
REG_TO_32[X86_REG_ESI] = 'esi'
REG_TO_32[X86_REG_EDI] = 'edi'
REG_TO_32[X86_REG_ESP] = 'esp'
REG_TO_32[X86_REG_EBP] = 'ebp'

# XMM register map
XMM_REG_MAP = {
    X86_REG_XMM0: 'xmm0', X86_REG_XMM1: 'xmm1', X86_REG_XMM2: 'xmm2',
    X86_REG_XMM3: 'xmm3', X86_REG_XMM4: 'xmm4', X86_REG_XMM5: 'xmm5',
    X86_REG_XMM6: 'xmm6', X86_REG_XMM7: 'xmm7',
}
XMM_REG_IDS = set(XMM_REG_MAP.keys())

# SETcc to condition string
SETCC_TO_COND = {
    X86_INS_SETE: '==', X86_INS_SETNE: '!=',
    X86_INS_SETG: '>', X86_INS_SETGE: '>=',
    X86_INS_SETL: '<', X86_INS_SETLE: '<=',
    X86_INS_SETA: '>', X86_INS_SETAE: '>=',
    X86_INS_SETB: '<', X86_INS_SETBE: '<=',
}

CMOVCC_TO_COND = {
    X86_INS_CMOVE: '==', X86_INS_CMOVNE: '!=',
    X86_INS_CMOVG: '>', X86_INS_CMOVGE: '>=',
    X86_INS_CMOVL: '<', X86_INS_CMOVLE: '<=',
    X86_INS_CMOVA: '>', X86_INS_CMOVAE: '>=',
    X86_INS_CMOVB: '<', X86_INS_CMOVBE: '<=',
}

# DWARF register number to capstone register
DWARF_TO_REG = {
    0: 'eax', 1: 'ecx', 2: 'edx', 3: 'ebx',
    4: 'esp', 5: 'ebp', 6: 'esi', 7: 'edi',
}

# Arithmetic ops
ARITH_OPS = {
    X86_INS_ADD: '+', X86_INS_SUB: '-',
    X86_INS_AND: '&', X86_INS_OR: '|', X86_INS_XOR: '^',
    X86_INS_SHL: '<<', X86_INS_SHR: '>>', X86_INS_SAR: '>>',
}


class ExprState:
    """Tracks expression propagation state during decompilation.

    Registers hold C expressions that propagate forward, not emitted until
    a side-effecting operation (store, call, return, branch).
    """

    def __init__(self, var_map: dict, var_types: dict, globals_map: dict,
                 dfunc: DisassembledFunction, jump_targets: set,
                 types: TypeResolver):
        self.var_map = var_map          # (location_key) -> variable name
        self.var_types = var_types      # variable name -> StabsType
        self.globals_map = globals_map  # address -> global variable name
        self.dfunc = dfunc
        self.jump_targets = jump_targets
        self.types = types
        self.regs: dict[str, str] = {}        # reg_name -> C expression
        self.xmm_regs: dict[str, str] = {}   # xmm_name -> C expression
        self.esp_args: dict[int, str] = {}    # esp_offset -> C expression
        self.push_stack: list[str] = []       # fallback push-based args
        self.last_cmp: Optional[tuple] = None # (lhs_expr, rhs_expr, cmp_type)
        self.fpu_stack: list[str] = []        # FPU expression stack
        self.func_is_void = False             # heuristic for void return

    def get_reg(self, reg_name: str) -> str:
        """Get the current expression for a register."""
        return self.regs.get(reg_name, reg_name)

    def set_reg(self, reg_name: str, expr: str):
        """Set a register to hold an expression (no output)."""
        self.regs[reg_name] = expr

    def invalidate_caller_saved(self):
        """After a call, caller-saved regs (ecx, edx) lose their expressions."""
        for r in ('ecx', 'edx'):
            self.regs.pop(r, None)


class GotoDecompiler:
    """Translates disassembled x86 functions to C code using expression propagation."""

    def __init__(self, stabs: StabsParser, types: TypeResolver,
                 loader=None):
        self.stabs = stabs
        self.types = types
        self.loader = loader
        self._globals_map: Optional[dict] = None
        self._sorted_globals: list[tuple] = []

    def _build_globals_map(self) -> dict[int, str]:
        """Build address -> global variable name map."""
        if self._globals_map is not None:
            return self._globals_map

        gmap = {}
        # From STABS globals (N_STSYM, N_LCSYM with addresses)
        for gv in self.stabs.all_globals:
            if gv.addr != 0 and gv.name:
                gmap[gv.addr] = gv.name
        # From symbol table for remaining addresses
        if self.loader:
            sym_map = self.loader.build_symbol_addr_map()
            for addr, name in sym_map.items():
                if addr not in gmap:
                    gmap[addr] = name
        # Match N_GSYM (addr=0) by name via symbol table
        if self.loader:
            sym_map = self.loader.build_symbol_addr_map()
            name_to_addr = {}
            for addr, name in sym_map.items():
                sname = name
                if sname.startswith('_') and not sname.startswith('__'):
                    sname = sname[1:]
                name_to_addr[sname] = addr
                name_to_addr[name] = addr
            for gv in self.stabs.all_globals:
                if gv.addr == 0 and gv.name:
                    addr = name_to_addr.get(gv.name)
                    if addr and addr not in gmap:
                        gmap[addr] = gv.name

        self._globals_map = gmap
        self._sorted_globals = sorted(gmap.items())  # [(addr, name), ...]
        return gmap

    def _find_global_at_offset(self, addr: int, state: ExprState) -> Optional[tuple]:
        """Find global variable containing addr, return (name, offset) or None."""
        import bisect
        if not self._sorted_globals:
            return None
        addrs = [a for a, _ in self._sorted_globals]
        idx = bisect.bisect_right(addrs, addr) - 1
        if idx < 0:
            return None
        base_addr, name = self._sorted_globals[idx]
        offset = addr - base_addr
        if offset == 0 or offset > 4096:  # offset==0 means exact match (handled elsewhere), >4096 too far
            return None
        return (name, offset)

    def decompile(self, dfunc: DisassembledFunction,
                  blocks: list[BasicBlock]) -> str:
        """Decompile a function to goto-based C code."""
        func = dfunc.func
        lines = []

        # Generate function signature
        if func.return_type:
            ret_type = self.types.type_to_c(func.return_type, '', cu=func.cu).strip()
        else:
            ret_type = 'int'
        params = []
        for p in func.params:
            ptype = self.types.type_to_c(p.type_ref, p.name, cu=func.cu)
            params.append(ptype)
        params_str = ', '.join(params) if params else 'void'

        fname = demangle_display(func.name)

        lines.append(f'{ret_type} {fname}({params_str})')
        lines.append('{')

        # Declare local variables
        declared = set()
        # Parameter names are already declared in the signature
        param_names = {p.name for p in func.params if p.name}
        declared.update(param_names)
        has_local_decls = False

        for lv in func.locals:
            vname = lv.name
            if vname and vname not in declared:
                vtype = self.types.type_to_c(lv.type_ref, vname, cu=func.cu)
                lines.append(f'    {vtype};')
                declared.add(vname)
                has_local_decls = True

        # Declare register variables (skip if name matches a parameter)
        for rv in func.reg_vars:
            vname = rv.name
            if vname and vname not in declared:
                vtype = self.types.type_to_c(rv.type_ref, vname, cu=func.cu)
                lines.append(f'    {vtype};')
                declared.add(vname)
                has_local_decls = True

        # Declare scratch registers (expression cap may flush to these)
        scratch_regs = [r for r in ('eax', 'ecx', 'edx', 'ebx', 'esi', 'edi')
                        if r not in declared]
        if scratch_regs:
            lines.append(f'    int {", ".join(scratch_regs)};')
            has_local_decls = True

        if has_local_decls:
            lines.append('')

        # Build variable and type maps
        var_map = self._build_var_map(func)
        var_types = self._build_var_types(func)
        globals_map = self._build_globals_map()

        # Compute jump targets for labels
        jump_targets = set()
        for inst in dfunc.instructions:
            if inst.jump_target is not None:
                jump_targets.add(inst.jump_target)

        # Track state
        state = ExprState(var_map, var_types, globals_map, dfunc,
                          jump_targets, self.types)

        # Initialize regs for register variables so the expression system
        # knows their starting value (e.g., regs['eax'] = 'dvar').
        # Later instructions (calls, movs) will overwrite with runtime state.
        for key, name in var_map.items():
            if key[0] == 'reg':
                state.regs[key[1]] = name

        # Detect void functions from return type
        state.func_is_void = (ret_type == 'void')

        # Emit code for each instruction
        for inst in dfunc.instructions:
            # Emit label if this is a jump target
            if inst.addr in jump_targets:
                lines.append(f'L_{inst.addr:x}:')

            # Translate instruction
            c_lines = self._process(inst, state)
            for cl in c_lines:
                lines.append(f'    {cl}')

            # Cap expression size to prevent exponential growth in
            # large straight-line code (e.g. MD4Transform, CRC routines)
            for reg_name, expr in list(state.regs.items()):
                if len(expr) > 200:
                    lines.append(f'    {reg_name} = {expr};')
                    state.regs[reg_name] = reg_name

        lines.append('}')
        return '\n'.join(lines)

    def _build_var_map(self, func: Function) -> dict:
        """Build maps from stack/register locations to variable names."""
        var_map = {}
        # Parameters: positive EBP offsets
        for p in func.params:
            var_map[('ebp', p.stack_offset)] = p.name
        # Locals: negative EBP offsets (stored as unsigned, convert)
        for lv in func.locals:
            offset = lv.ebp_offset
            if offset > 0x7FFFFFFF:
                offset = offset - 0x100000000
            var_map[('ebp', offset)] = lv.name
        # Register variables
        for rv in func.reg_vars:
            reg_name = DWARF_TO_REG.get(rv.register)
            if reg_name:
                var_map[('reg', reg_name)] = rv.name
        return var_map

    def _build_var_types(self, func: Function) -> dict[str, StabsType]:
        """Build variable name -> StabsType map for struct field resolution."""
        vt = {}
        for p in func.params:
            if p.name:
                vt[p.name] = p.type_ref
        for lv in func.locals:
            if lv.name:
                vt[lv.name] = lv.type_ref
        for rv in func.reg_vars:
            if rv.name:
                vt[rv.name] = rv.type_ref
        # Include CU globals for global struct/array type resolution
        if func.cu:
            for gv in func.cu.globals:
                if gv.name and gv.name not in vt:
                    vt[gv.name] = gv.type_ref
        # Include all STABS globals
        for gv in self.stabs.all_globals:
            if gv.name and gv.name not in vt:
                vt[gv.name] = gv.type_ref
        return vt

    def _process(self, inst: Instruction, state: ExprState) -> list[str]:
        """Process a single instruction. Returns list of C statements to emit."""
        iid = inst.insn_id

        # Skip NOP
        if iid == X86_INS_NOP:
            return []

        # Skip prologue/epilogue
        if self._is_prologue_epilogue(inst, state):
            return []

        # CDQ (sign-extend eax to edx:eax) - just mark edx
        if iid == X86_INS_CDQ:
            # edx gets the sign extension of eax, needed for idiv
            state.set_reg('edx', f'({state.get_reg("eax")} >> 31)')
            return []

        # Call instruction
        if inst.is_call:
            return self._process_call(inst, state)

        # Return
        if inst.is_ret:
            return self._process_ret(inst, state)

        # Conditional jump
        if inst.is_conditional_jump and inst.jump_target:
            cond = self._make_condition(inst, state)
            return [f'if ({cond}) goto L_{inst.jump_target:x};']

        # Unconditional jump
        if inst.is_unconditional_jump and inst.jump_target:
            return [f'goto L_{inst.jump_target:x};']

        # MOV / MOVSX / MOVZX
        if iid in (X86_INS_MOV, X86_INS_MOVSX, X86_INS_MOVZX, X86_INS_MOVSXD):
            return self._process_mov(inst, iid, state)

        # LEA
        if iid == X86_INS_LEA and len(inst.operands) == 2:
            return self._process_lea(inst, state)

        # Arithmetic: ADD, SUB, AND, OR, XOR, SHL, SHR, SAR
        if iid in ARITH_OPS and len(inst.operands) == 2:
            return self._process_arith(inst, iid, state)

        # IMUL
        if iid == X86_INS_IMUL:
            return self._process_imul(inst, state)

        # DIV/IDIV
        if iid in (X86_INS_DIV, X86_INS_IDIV) and len(inst.operands) == 1:
            divisor = self._resolve_src(inst.operands[0], inst, state)
            eax_expr = state.get_reg('eax')
            state.set_reg('eax', f'({eax_expr} / {divisor})')
            state.set_reg('edx', f'({eax_expr} % {divisor})')
            return []

        # Unary: NOT, NEG
        if iid == X86_INS_NOT and len(inst.operands) == 1:
            return self._process_unary(inst, '~', state)
        if iid == X86_INS_NEG and len(inst.operands) == 1:
            return self._process_unary_neg(inst, state)

        # INC / DEC
        if iid == X86_INS_INC and len(inst.operands) == 1:
            return self._process_inc_dec(inst, '++', '+', state)
        if iid == X86_INS_DEC and len(inst.operands) == 1:
            return self._process_inc_dec(inst, '--', '-', state)

        # CMP/TEST - tracked for condition generation, no output
        if iid in (X86_INS_CMP, X86_INS_TEST) and len(inst.operands) == 2:
            lhs = self._resolve_src(inst.operands[0], inst, state)
            rhs = self._resolve_src(inst.operands[1], inst, state)
            state.last_cmp = (lhs, rhs, iid)
            return []

        # PUSH (for call arg tracking - fallback for non-esp calling convention)
        if iid == X86_INS_PUSH and inst.operands:
            # Skip prologue pushes
            op = inst.operands[0]
            if op.type == X86_OP_REG and op.reg in (X86_REG_EBP, X86_REG_EBX, X86_REG_ESI, X86_REG_EDI):
                if inst.addr < state.dfunc.func.addr + 6:
                    return []
            src = self._resolve_src(op, inst, state)
            state.push_stack.append(src)
            return []

        # POP - epilogue pops handled above, other pops tracked
        if iid == X86_INS_POP and inst.operands:
            op = inst.operands[0]
            if op.type == X86_OP_REG:
                reg = REG_TO_32.get(op.reg)
                if reg in ('ebp', 'ebx', 'esi', 'edi'):
                    return []  # Epilogue pop
            return []

        # SETcc
        if iid in SETCC_TO_COND and len(inst.operands) == 1:
            cond = self._make_setcc_condition(iid, state)
            return self._process_dst_assign(inst.operands[0], inst, cond, state)

        # CMOVcc
        if iid in CMOVCC_TO_COND and len(inst.operands) == 2:
            dst_expr = self._resolve_dst_name(inst.operands[0], inst, state)
            src = self._resolve_src(inst.operands[1], inst, state)
            cond = self._make_setcc_condition(iid, state)
            if dst_expr:
                return [f'if ({cond}) {dst_expr} = {src};']
            # Register-only cmov: update expression silently
            if inst.operands[0].type == X86_OP_REG:
                reg = REG_TO_32.get(inst.operands[0].reg)
                if reg:
                    old = state.get_reg(reg)
                    state.set_reg(reg, f'(({cond}) ? {src} : {old})')
            return []

        # FPU instructions
        fpu_result = self._process_fpu(inst, iid, state)
        if fpu_result is not None:
            return fpu_result

        # SSE instructions
        sse_result = self._process_sse(inst, iid, state)
        if sse_result is not None:
            return sse_result

        # String operations (CLD, REP MOVSB/STOSB, SCASB, etc.)
        string_result = self._process_string_ops(inst, iid, state)
        if string_result is not None:
            return string_result

        # Silent skip: flag/control word ops
        if iid in (X86_INS_SAHF, X86_INS_FNSTCW, X86_INS_FLDCW):
            return []

        # BSWAP
        if iid == X86_INS_BSWAP and len(inst.operands) == 1:
            op = inst.operands[0]
            if op.type == X86_OP_REG:
                reg = REG_TO_32.get(op.reg)
                if reg:
                    old = state.get_reg(reg)
                    state.set_reg(reg, f'__builtin_bswap32({old})')
                    var = state.var_map.get(('reg', reg))
                    if var:
                        return [f'{var} = __builtin_bswap32({old});']
                    return []
            return []

        # XCHG
        if iid == X86_INS_XCHG and len(inst.operands) == 2:
            return self._process_xchg(inst, state)

        # Default: emit as comment
        return [f'/* {inst.mnemonic} {inst.op_str} */']

    # ---------------------------------------------------------------
    # Instruction processors
    # ---------------------------------------------------------------

    def _is_prologue_epilogue(self, inst: Instruction, state: ExprState) -> bool:
        """Check if instruction is part of function prologue/epilogue."""
        iid = inst.insn_id
        # push ebp / push callee-saved (early in function)
        if iid == X86_INS_PUSH and inst.operands and inst.operands[0].type == X86_OP_REG:
            reg = inst.operands[0].reg
            if reg in (X86_REG_EBP, X86_REG_EBX, X86_REG_ESI, X86_REG_EDI):
                if inst.addr < state.dfunc.func.addr + 6:
                    return True
        # pop callee-saved
        if iid == X86_INS_POP and inst.operands and inst.operands[0].type == X86_OP_REG:
            reg = inst.operands[0].reg
            if reg in (X86_REG_EBP, X86_REG_EBX, X86_REG_ESI, X86_REG_EDI):
                return True
        # mov ebp, esp
        if iid == X86_INS_MOV and len(inst.operands) == 2:
            if (inst.operands[0].type == X86_OP_REG and inst.operands[0].reg == X86_REG_EBP and
                    inst.operands[1].type == X86_OP_REG and inst.operands[1].reg == X86_REG_ESP):
                return True
        # sub esp, N / add esp, N (stack frame setup/teardown)
        if iid in (X86_INS_SUB, X86_INS_ADD) and len(inst.operands) == 2:
            if inst.operands[0].type == X86_OP_REG and inst.operands[0].reg == X86_REG_ESP:
                return True
        # leave
        if inst.mnemonic == 'leave':
            return True
        return False

    def _process_mov(self, inst: Instruction, iid: int, state: ExprState) -> list[str]:
        """Process MOV/MOVSX/MOVZX instruction."""
        if len(inst.operands) != 2:
            return []

        dst_op = inst.operands[0]
        src_op = inst.operands[1]
        src_expr = self._resolve_src(src_op, inst, state)

        # Apply cast for sign/zero extension
        if iid == X86_INS_MOVSX or iid == X86_INS_MOVSXD:
            src_expr = f'(int){src_expr}'
        elif iid == X86_INS_MOVZX:
            src_expr = f'(unsigned){src_expr}'

        # DST is register → propagate silently
        if dst_op.type == X86_OP_REG:
            reg = REG_TO_32.get(dst_op.reg)
            if reg and reg not in ('esp', 'ebp'):
                # Check if register is a named variable
                var = state.var_map.get(('reg', reg))
                if var:
                    state.set_reg(reg, src_expr)
                    if var != src_expr:  # Suppress self-assignment
                        return [f'{var} = {src_expr};']
                    return []
                state.set_reg(reg, src_expr)
                return []  # Silent propagation
            return []

        # DST is memory → check what kind
        if dst_op.type == X86_OP_MEM:
            return self._process_mem_store(dst_op, inst, src_expr, state)

        return []

    def _process_lea(self, inst: Instruction, state: ExprState) -> list[str]:
        """Process LEA instruction - address computation."""
        dst_op = inst.operands[0]
        src_op = inst.operands[1]
        addr_expr = self._resolve_lea(src_op, inst, state)

        if dst_op.type == X86_OP_REG:
            reg = REG_TO_32.get(dst_op.reg)
            if reg and reg not in ('esp', 'ebp'):
                var = state.var_map.get(('reg', reg))
                if var:
                    state.set_reg(reg, addr_expr)
                    if var != addr_expr:  # Suppress self-assignment
                        return [f'{var} = {addr_expr};']
                    return []
                state.set_reg(reg, addr_expr)
                return []  # Silent propagation
        return []

    def _process_arith(self, inst: Instruction, iid: int, state: ExprState) -> list[str]:
        """Process arithmetic instruction (ADD, SUB, AND, OR, XOR, SHL, SHR, SAR)."""
        op_str = ARITH_OPS[iid]
        dst_op = inst.operands[0]
        src_expr = self._resolve_src(inst.operands[1], inst, state)

        # DST is register → update expression silently
        if dst_op.type == X86_OP_REG:
            reg = REG_TO_32.get(dst_op.reg)
            if reg and reg not in ('esp', 'ebp'):
                old_expr = state.get_reg(reg)
                new_expr = f'({old_expr} {op_str} {src_expr})'
                # Check for register variable
                var = state.var_map.get(('reg', reg))
                if var:
                    state.set_reg(reg, new_expr)
                    if src_expr != '0':  # Suppress no-op arith (var += 0)
                        return [f'{var} {op_str}= {src_expr};']
                    return []
                state.set_reg(reg, new_expr)
                return []  # Silent propagation

        # DST is memory [ebp+/-N] → named variable
        if dst_op.type == X86_OP_MEM:
            dst_name = self._resolve_mem_dst_name(dst_op, inst, state)
            if dst_name:
                return [f'{dst_name} {op_str}= {src_expr};']

        return [f'/* {inst.mnemonic} {inst.op_str} */']

    def _process_imul(self, inst: Instruction, state: ExprState) -> list[str]:
        """Process IMUL instruction (1, 2, or 3 operands)."""
        if len(inst.operands) == 3:
            s1 = self._resolve_src(inst.operands[1], inst, state)
            s2 = self._resolve_src(inst.operands[2], inst, state)
            expr = f'({s1} * {s2})'
            if inst.operands[0].type == X86_OP_REG:
                reg = REG_TO_32.get(inst.operands[0].reg)
                if reg:
                    var = state.var_map.get(('reg', reg))
                    if var:
                        state.set_reg(reg, expr)
                        return [f'{var} = {expr};']
                    state.set_reg(reg, expr)
            return []
        elif len(inst.operands) == 2:
            dst_reg = REG_TO_32.get(inst.operands[0].reg) if inst.operands[0].type == X86_OP_REG else None
            src = self._resolve_src(inst.operands[1], inst, state)
            if dst_reg:
                old = state.get_reg(dst_reg)
                state.set_reg(dst_reg, f'({old} * {src})')
            return []
        elif len(inst.operands) == 1:
            src = self._resolve_src(inst.operands[0], inst, state)
            eax_expr = state.get_reg('eax')
            state.set_reg('eax', f'({eax_expr} * {src})')
            return []
        return []

    def _process_unary(self, inst: Instruction, op: str, state: ExprState) -> list[str]:
        """Process unary NOT instruction."""
        operand = inst.operands[0]
        if operand.type == X86_OP_REG:
            reg = REG_TO_32.get(operand.reg)
            if reg:
                old = state.get_reg(reg)
                state.set_reg(reg, f'{op}{old}')
                var = state.var_map.get(('reg', reg))
                if var:
                    return [f'{var} = {op}{old};']
                return []
        elif operand.type == X86_OP_MEM:
            dst_name = self._resolve_mem_dst_name(operand, inst, state)
            if dst_name:
                return [f'{dst_name} = {op}{dst_name};']
        return [f'/* {inst.mnemonic} {inst.op_str} */']

    def _process_unary_neg(self, inst: Instruction, state: ExprState) -> list[str]:
        """Process NEG instruction."""
        operand = inst.operands[0]
        if operand.type == X86_OP_REG:
            reg = REG_TO_32.get(operand.reg)
            if reg:
                old = state.get_reg(reg)
                state.set_reg(reg, f'-({old})')
                var = state.var_map.get(('reg', reg))
                if var:
                    return [f'{var} = -({old});']
                return []
        elif operand.type == X86_OP_MEM:
            dst_name = self._resolve_mem_dst_name(operand, inst, state)
            if dst_name:
                return [f'{dst_name} = -({dst_name});']
        return [f'/* {inst.mnemonic} {inst.op_str} */']

    def _process_inc_dec(self, inst: Instruction, post_op: str, arith_op: str,
                         state: ExprState) -> list[str]:
        """Process INC/DEC instruction."""
        operand = inst.operands[0]
        if operand.type == X86_OP_REG:
            reg = REG_TO_32.get(operand.reg)
            if reg:
                old = state.get_reg(reg)
                state.set_reg(reg, f'({old} {arith_op} 1)')
                var = state.var_map.get(('reg', reg))
                if var:
                    return [f'{var}{post_op};']
                return []
        elif operand.type == X86_OP_MEM:
            dst_name = self._resolve_mem_dst_name(operand, inst, state)
            if dst_name:
                return [f'{dst_name}{post_op};']
        return [f'/* {inst.mnemonic} {inst.op_str} */']

    def _process_call(self, inst: Instruction, state: ExprState) -> list[str]:
        """Process CALL instruction with expression propagation."""
        target = inst.call_target
        if not target:
            if inst.call_addr:
                target = f'sub_{inst.call_addr:x}'
            else:
                target = 'unknown_func'

        display_name = demangle_display(target)

        # Gather arguments: prefer esp-based args, fall back to push stack
        args = self._gather_call_args(target, state)
        args_str = ', '.join(args)

        call_expr = f'{display_name}({args_str})'

        # Track return value in eax
        state.set_reg('eax', call_expr)
        state.invalidate_caller_saved()
        # Clear arg accumulation
        state.esp_args.clear()
        state.push_stack.clear()

        return [f'{call_expr};']

    def _gather_call_args(self, target: str, state: ExprState) -> list[str]:
        """Gather call arguments from esp_args or push_stack."""
        # Look up expected param count from STABS
        target_func = self.stabs.get_function_by_name(target)
        nargs = len(target_func.params) if target_func else None

        # Try esp-based args first (GCC puts args via mov [esp+N], src)
        if state.esp_args:
            max_offset = max(state.esp_args.keys())
            if nargs is None:
                nargs = max_offset // 4 + 1
            args = []
            for i in range(nargs):
                offset = i * 4
                expr = state.esp_args.get(offset)
                if expr is not None:
                    args.append(expr)
                else:
                    break  # Stop at first gap
            if args:
                return args

        # Fall back to push stack
        if state.push_stack:
            if nargs is None:
                nargs = len(state.push_stack)
            args = []
            for _ in range(min(nargs, len(state.push_stack))):
                if state.push_stack:
                    args.append(state.push_stack.pop())
            return list(reversed(args))

        # No args found
        if nargs and nargs > 0:
            return []
        return []

    def _process_ret(self, inst: Instruction, state: ExprState) -> list[str]:
        """Process RET instruction with expression propagation."""
        if state.func_is_void:
            return ['return;']
        eax_expr = state.get_reg('eax')
        # If eax holds a meaningful expression (not just 'eax'), use it
        if eax_expr and eax_expr != 'eax':
            return [f'return {eax_expr};']
        return ['return;']

    def _process_mem_store(self, dst_op, inst: Instruction, src_expr: str,
                           state: ExprState) -> list[str]:
        """Handle store to memory: emit assignment to named variable/global."""
        mem = dst_op.mem
        base = mem.base
        index = mem.index
        disp = mem.disp

        # [ebp+/-N]: stack variable
        if base == X86_REG_EBP and index == 0:
            var = state.var_map.get(('ebp', disp))
            if var:
                return [f'{var} = {src_expr};']
            if disp > 0:
                return [f'arg_{disp:x} = {src_expr};']
            elif disp < 0:
                return [f'local_{(-disp):x} = {src_expr};']
            return [f'*(ebp + {disp}) = {src_expr};']

        # [esp+N]: call argument accumulation
        if base == X86_REG_ESP and index == 0:
            # This is a call arg being placed on the stack
            offset = disp if disp >= 0 else 0
            state.esp_args[offset] = src_expr
            return []  # Silent - args emitted at CALL

        # Absolute address [disp]: global variable
        if base == 0 and index == 0 and disp != 0:
            addr = disp
            name = state.globals_map.get(addr)
            if name:
                clean = demangle_display(name) if name.startswith('_') else name
                return [f'{clean} = {src_expr};']
            # Check called_functions map
            name = state.dfunc.called_functions.get(addr)
            if name:
                clean = demangle_display(name)
                return [f'{clean} = {src_expr};']
            # Check if address is within a known global (struct field store)
            result = self._find_global_at_offset(addr, state)
            if result:
                gname, offset = result
                clean = demangle_display(gname) if gname.startswith('_') else gname
                var_type = state.var_types.get(gname)
                if var_type:
                    cu = state.dfunc.func.cu
                    field = self.types.get_struct_field_at_offset(var_type, offset, cu=cu)
                    if field:
                        fname, _ = field
                        return [f'{clean}.{fname} = {src_expr};']
                return [f'*((char *){clean} + 0x{offset:x}) = {src_expr};']
            return [f'*(int *)0x{addr:x} = {src_expr};']

        # [base+disp] where base is a register with a typed pointer (including offset 0)
        if base and base != X86_REG_ESP and index == 0:
            field_result = self._resolve_struct_field_store(base, disp, state)
            if field_result:
                return [f'{field_result} = {src_expr};']

        # [index*scale + disp] → global array store
        if base == 0 and index != 0 and disp != 0:
            gname = state.globals_map.get(disp)
            if gname:
                clean = demangle_display(gname) if gname.startswith('_') else gname
                idx_expr = self._resolve_reg(index, state)
                return [f'{clean}[{idx_expr}] = {src_expr};']

        # General memory store
        dst_expr = self._resolve_mem_expr(dst_op, inst, state)
        return [f'{dst_expr} = {src_expr};']

    def _process_dst_assign(self, dst_op, inst: Instruction, value_expr: str,
                            state: ExprState) -> list[str]:
        """Assign value_expr to destination operand, emitting if needed."""
        if dst_op.type == X86_OP_REG:
            reg = REG_TO_32.get(dst_op.reg)
            if reg:
                var = state.var_map.get(('reg', reg))
                if var:
                    state.set_reg(reg, value_expr)
                    return [f'{var} = {value_expr};']
                state.set_reg(reg, value_expr)
                return []
        elif dst_op.type == X86_OP_MEM:
            dst_name = self._resolve_mem_dst_name(dst_op, inst, state)
            if dst_name:
                return [f'{dst_name} = {value_expr};']
        return []

    def _process_fpu(self, inst: Instruction, iid: int, state: ExprState) -> Optional[list[str]]:
        """Process FPU instructions. Returns None if not an FPU instruction."""
        if iid in (X86_INS_FLD, X86_INS_FILD) and inst.operands:
            src = self._resolve_src(inst.operands[0], inst, state)
            if iid == X86_INS_FILD:
                src = f'(double){src}'
            state.fpu_stack.append(src)
            return []
        if iid == X86_INS_FLDZ:
            state.fpu_stack.append('0.0')
            return []
        if iid == X86_INS_FLD1:
            state.fpu_stack.append('1.0')
            return []
        if iid in (X86_INS_FSTP, X86_INS_FISTP) and inst.operands:
            val = state.fpu_stack.pop() if state.fpu_stack else 'fpu_top'
            if iid == X86_INS_FISTP:
                val = f'(int){val}'
            dst_name = self._resolve_mem_dst_name(inst.operands[0], inst, state)
            if dst_name:
                return [f'{dst_name} = {val};']
            dst = self._resolve_mem_expr(inst.operands[0], inst, state)
            return [f'{dst} = {val};']
        if iid in (X86_INS_FADD, X86_INS_FSUB, X86_INS_FMUL, X86_INS_FDIV):
            op_map = {X86_INS_FADD: '+', X86_INS_FSUB: '-',
                      X86_INS_FMUL: '*', X86_INS_FDIV: '/'}
            op = op_map[iid]
            if inst.operands:
                src = self._resolve_src(inst.operands[-1], inst, state)
                if state.fpu_stack:
                    top = state.fpu_stack[-1]
                    state.fpu_stack[-1] = f'({top} {op} {src})'
            return []
        if iid == X86_INS_FCHS:
            if state.fpu_stack:
                top = state.fpu_stack[-1]
                state.fpu_stack[-1] = f'-({top})'
            return []
        if iid in (X86_INS_FCOM, X86_INS_FUCOM, X86_INS_FNSTSW):
            return []  # Tracking happens via FNSTSW->TEST pattern
        return None  # Not an FPU instruction

    def _process_sse(self, inst: Instruction, iid: int, state: ExprState) -> Optional[list[str]]:
        """Process SSE instructions. Returns None if not an SSE instruction."""
        ops = inst.operands

        # Helper: check if an operand is an XMM register
        def _is_xmm(op):
            return op.type == X86_OP_REG and op.reg in XMM_REG_IDS

        def _xmm_name(op):
            return XMM_REG_MAP.get(op.reg)

        def _get_xmm(name):
            return state.xmm_regs.get(name, name)

        # XORPS/XORPD/PXOR xmm, xmm (same reg) → zero
        if iid in (X86_INS_XORPS, X86_INS_XORPD, X86_INS_PXOR) and len(ops) == 2:
            if _is_xmm(ops[0]) and _is_xmm(ops[1]):
                d = _xmm_name(ops[0])
                s = _xmm_name(ops[1])
                if d and s and d == s:
                    state.xmm_regs[d] = '0.0'
                    return []
                # Different regs: bitwise XOR (unusual, treat as zero-like)
                if d:
                    state.xmm_regs[d] = '0.0'
                return []
            return None  # Not xmm operands, not an SSE instruction

        # MOVSS / MOVSD (SSE scalar, not string movsd)
        # Capstone uses same ID for string movsd and SSE movsd — distinguish by XMM operands
        if iid == X86_INS_MOVSD and len(ops) == 2 and (_is_xmm(ops[0]) or _is_xmm(ops[1])):
            return self._process_sse_mov(inst, ops, state, 'double')
        if iid == X86_INS_MOVSS and len(ops) == 2:
            return self._process_sse_mov(inst, ops, state, 'float')

        # MOVAPS / MOVUPS (SSE packed move, often used for scalar too)
        if iid in (X86_INS_MOVAPS, X86_INS_MOVUPS) and len(ops) == 2:
            if _is_xmm(ops[0]) and _is_xmm(ops[1]):
                d = _xmm_name(ops[0])
                s = _xmm_name(ops[1])
                if d and s:
                    state.xmm_regs[d] = _get_xmm(s)
                return []
            if _is_xmm(ops[0]):
                d = _xmm_name(ops[0])
                src = self._resolve_src(ops[1], inst, state)
                if d:
                    state.xmm_regs[d] = src
                return []
            if _is_xmm(ops[1]):
                s = _xmm_name(ops[1])
                src_expr = _get_xmm(s) if s else 'xmm?'
                dst_name = self._resolve_mem_dst_name(ops[0], inst, state)
                if dst_name:
                    return [f'{dst_name} = {src_expr};']
                dst = self._resolve_mem_expr(ops[0], inst, state)
                return [f'{dst} = {src_expr};']
            return None

        # SSE arithmetic: ADDSS/ADDSD/SUBSS/SUBSD/MULSS/MULSD/DIVSS/DIVSD
        sse_arith = {
            X86_INS_ADDSS: '+', X86_INS_ADDSD: '+',
            X86_INS_SUBSS: '-', X86_INS_SUBSD: '-',
            X86_INS_MULSS: '*', X86_INS_MULSD: '*',
            X86_INS_DIVSS: '/', X86_INS_DIVSD: '/',
        }
        if iid in sse_arith and len(ops) == 2:
            op_str = sse_arith[iid]
            if _is_xmm(ops[0]):
                d = _xmm_name(ops[0])
                if _is_xmm(ops[1]):
                    s = _xmm_name(ops[1])
                    src = _get_xmm(s) if s else 'xmm?'
                else:
                    src = self._resolve_src(ops[1], inst, state)
                if d:
                    old = _get_xmm(d)
                    state.xmm_regs[d] = f'({old} {op_str} {src})'
                return []
            return None

        # CVTSI2SS / CVTSI2SD: int → float/double
        if iid in (X86_INS_CVTSI2SS, X86_INS_CVTSI2SD) and len(ops) == 2:
            if _is_xmm(ops[0]):
                d = _xmm_name(ops[0])
                src = self._resolve_src(ops[1], inst, state)
                cast = 'float' if iid == X86_INS_CVTSI2SS else 'double'
                if d:
                    state.xmm_regs[d] = f'({cast}){src}'
                return []
            return None

        # CVTTSS2SI / CVTTSD2SI: float/double → int (truncate)
        if iid in (X86_INS_CVTTSS2SI, X86_INS_CVTTSD2SI) and len(ops) == 2:
            if ops[0].type == X86_OP_REG and ops[0].reg in REG_TO_32:
                reg = REG_TO_32[ops[0].reg]
                if _is_xmm(ops[1]):
                    s = _xmm_name(ops[1])
                    src = _get_xmm(s) if s else 'xmm?'
                else:
                    src = self._resolve_src(ops[1], inst, state)
                state.set_reg(reg, f'(int){src}')
                var = state.var_map.get(('reg', reg))
                if var:
                    return [f'{var} = (int){src};']
                return []
            return None

        # COMISS / COMISD / UCOMISS / UCOMISD: SSE compare → set last_cmp
        if iid in (X86_INS_COMISS, X86_INS_COMISD,
                   X86_INS_UCOMISS, X86_INS_UCOMISD) and len(ops) == 2:
            if _is_xmm(ops[0]):
                d = _xmm_name(ops[0])
                lhs = _get_xmm(d) if d else 'xmm?'
                if _is_xmm(ops[1]):
                    s = _xmm_name(ops[1])
                    rhs = _get_xmm(s) if s else 'xmm?'
                else:
                    rhs = self._resolve_src(ops[1], inst, state)
                state.last_cmp = (lhs, rhs, 'float_cmp')
                return []
            return None

        return None  # Not an SSE instruction

    def _process_sse_mov(self, inst: Instruction, ops, state: ExprState,
                         fp_type: str) -> list[str]:
        """Process MOVSS/MOVSD (SSE scalar move)."""
        def _is_xmm(op):
            return op.type == X86_OP_REG and op.reg in XMM_REG_IDS

        def _xmm_name(op):
            return XMM_REG_MAP.get(op.reg)

        def _get_xmm(name):
            return state.xmm_regs.get(name, name)

        dst, src = ops[0], ops[1]

        # xmm ← xmm
        if _is_xmm(dst) and _is_xmm(src):
            d = _xmm_name(dst)
            s = _xmm_name(src)
            if d and s:
                state.xmm_regs[d] = _get_xmm(s)
            return []

        # xmm ← mem: load
        if _is_xmm(dst):
            d = _xmm_name(dst)
            src_expr = self._resolve_src(src, inst, state)
            if d:
                state.xmm_regs[d] = src_expr
            return []

        # mem ← xmm: store (emit assignment)
        if _is_xmm(src):
            s = _xmm_name(src)
            val = _get_xmm(s) if s else 'xmm?'
            dst_name = self._resolve_mem_dst_name(dst, inst, state)
            if dst_name:
                return [f'{dst_name} = {val};']
            dst_expr = self._resolve_mem_expr(dst, inst, state)
            return [f'{dst_expr} = {val};']

        return []

    def _process_string_ops(self, inst: Instruction, iid: int,
                             state: ExprState) -> Optional[list[str]]:
        """Process string operations (CLD, REP MOVSB/STOSB, SCASB, etc.)."""
        # CLD / STD: direction flag management — skip silently
        if iid in (X86_INS_CLD, X86_INS_STD):
            return []

        # Check for REP prefix in mnemonic
        mnem = inst.mnemonic.lower()
        has_rep = mnem.startswith('rep ')
        has_repne = mnem.startswith('repne ') or mnem.startswith('repnz ')

        # REP MOVSB / REP MOVSD: memcpy(edi, esi, ecx)
        if iid in (X86_INS_MOVSB, X86_INS_MOVSD) and not self._has_xmm_operands(inst):
            edi = state.get_reg('edi')
            esi = state.get_reg('esi')
            ecx = state.get_reg('ecx')
            if has_rep:
                if iid == X86_INS_MOVSD:
                    return [f'memcpy({edi}, {esi}, {ecx} * 4);']
                return [f'memcpy({edi}, {esi}, {ecx});']
            # Single movsb/movsd without rep
            if iid == X86_INS_MOVSD:
                return [f'*(int *){edi} = *(int *){esi};']
            return [f'*(char *){edi} = *(char *){esi};']

        # REP STOSB / REP STOSD: memset(edi, eax, ecx)
        if iid in (X86_INS_STOSB, X86_INS_STOSD):
            edi = state.get_reg('edi')
            eax = state.get_reg('eax')
            ecx = state.get_reg('ecx')
            if has_rep:
                if iid == X86_INS_STOSD:
                    return [f'memset({edi}, {eax}, {ecx} * 4);']
                return [f'memset({edi}, {eax}, {ecx});']
            # Single stosb/stosd
            if iid == X86_INS_STOSD:
                return [f'*(int *){edi} = {eax};']
            return [f'*(char *){edi} = {eax};']

        # SCASB / REPNE SCASB: string scan (often strlen pattern)
        if iid == X86_INS_SCASB:
            edi = state.get_reg('edi')
            if has_repne:
                return [f'/* strlen-like scan at {edi} */']
            return [f'/* scasb at {edi} */']

        # CMPSB
        if iid == X86_INS_CMPSB:
            edi = state.get_reg('edi')
            esi = state.get_reg('esi')
            if has_rep or has_repne:
                return [f'/* memcmp({edi}, {esi}) */']
            return [f'/* cmpsb {edi}, {esi} */']

        return None  # Not a string operation

    def _has_xmm_operands(self, inst: Instruction) -> bool:
        """Check if any operand is an XMM register (to disambiguate MOVSD)."""
        for op in inst.operands:
            if op.type == X86_OP_REG and op.reg in XMM_REG_IDS:
                return True
        return False

    def _process_xchg(self, inst: Instruction, state: ExprState) -> list[str]:
        """Process XCHG instruction — swap two operands."""
        ops = inst.operands
        if ops[0].type == X86_OP_REG and ops[1].type == X86_OP_REG:
            r0 = REG_TO_32.get(ops[0].reg)
            r1 = REG_TO_32.get(ops[1].reg)
            if r0 and r1:
                e0 = state.get_reg(r0)
                e1 = state.get_reg(r1)
                state.set_reg(r0, e1)
                state.set_reg(r1, e0)
                # Emit if either is a named variable
                v0 = state.var_map.get(('reg', r0))
                v1 = state.var_map.get(('reg', r1))
                stmts = []
                if v0:
                    stmts.append(f'{v0} = {e1};')
                if v1:
                    stmts.append(f'{v1} = {e0};')
                return stmts
        return [f'/* {inst.mnemonic} {inst.op_str} */']

    # ---------------------------------------------------------------
    # Expression resolution
    # ---------------------------------------------------------------

    def _resolve_src(self, op, inst: Instruction, state: ExprState) -> str:
        """Resolve a source operand to a C expression using propagated values."""
        if op.type == X86_OP_REG:
            return self._resolve_reg(op.reg, state)

        if op.type == X86_OP_IMM:
            return self._resolve_imm(op.imm, inst, state)

        if op.type == X86_OP_MEM:
            return self._resolve_mem_src(op, inst, state)

        return '??'

    def _resolve_reg(self, reg_id: int, state: ExprState) -> str:
        """Resolve register to its propagated expression or variable name."""
        # Check XMM registers
        xmm = XMM_REG_MAP.get(reg_id)
        if xmm:
            return state.xmm_regs.get(xmm, xmm)

        reg32 = REG_TO_32.get(reg_id)
        if not reg32:
            return f'reg{reg_id}'

        # Propagated expression takes priority (tracks actual runtime state).
        # After a call, eax holds the return value, not the original variable.
        reg_expr = state.regs.get(reg32)
        if reg_expr is not None:
            return reg_expr

        # Fall back to STABS register variable mapping (initial value)
        var = state.var_map.get(('reg', reg32))
        if var:
            return var

        return reg32

    def _resolve_imm(self, val: int, inst: Instruction, state: ExprState = None) -> str:
        """Resolve an immediate value."""
        # Check for string reference
        if inst.string_ref is not None:
            escaped = inst.string_ref.replace('\\', '\\\\').replace('"', '\\"')
            escaped = escaped.replace('\n', '\\n').replace('\t', '\\t')
            return f'"{escaped}"'
        if val < 0:
            return str(val)
        if val > 0xFFFF:
            # Check if it's a known global
            if state and state.globals_map:
                name = state.globals_map.get(val)
                if name:
                    return demangle_display(name)
            return f'0x{val:x}'
        return str(val)

    def _resolve_mem_src(self, op, inst: Instruction, state: ExprState) -> str:
        """Resolve a memory source operand to a C expression."""
        mem = op.mem
        base = mem.base
        index = mem.index
        disp = mem.disp

        # [ebp+/-N]: stack variable
        if base == X86_REG_EBP and index == 0:
            var = state.var_map.get(('ebp', disp))
            if var:
                return var
            if disp > 0:
                return f'arg_{disp:x}'
            elif disp < 0:
                return f'local_{(-disp):x}'
            return '*(ebp)'

        # Absolute address [disp]
        if base == 0 and index == 0 and disp != 0:
            addr = disp
            # Check for string
            if inst.string_ref is not None:
                escaped = inst.string_ref.replace('\\', '\\\\').replace('"', '\\"')
                escaped = escaped.replace('\n', '\\n').replace('\t', '\\t')
                return f'"{escaped}"'
            # Check for global variable
            name = state.globals_map.get(addr)
            if name:
                return demangle_display(name) if name.startswith('_') else name
            # Check called_functions
            name = state.dfunc.called_functions.get(addr)
            if name:
                return demangle_display(name)
            # Check if address is within a known global (struct field access)
            result = self._find_global_at_offset(addr, state)
            if result:
                gname, offset = result
                clean = demangle_display(gname) if gname.startswith('_') else gname
                var_type = state.var_types.get(gname)
                if var_type:
                    cu = state.dfunc.func.cu
                    field = self.types.get_struct_field_at_offset(var_type, offset, cu=cu)
                    if field:
                        fname, _ = field
                        return f'{clean}.{fname}'
                # Fallback: show named offset
                return f'*((char *){clean} + 0x{offset:x})'
            return f'*(int *)0x{addr:x}'

        # [base+disp] with typed pointer → struct field access (including offset 0)
        if base and base not in (0, X86_REG_ESP) and index == 0:
            field_result = self._resolve_struct_field_load(base, disp, state)
            if field_result:
                return field_result

        # [esp+N]: reading from esp - might be a previously stored arg
        if base == X86_REG_ESP and index == 0:
            arg = state.esp_args.get(disp)
            if arg:
                return arg

        # [index*scale + disp] → global array indexing
        if base == 0 and index != 0 and disp != 0:
            gname = state.globals_map.get(disp)
            if gname:
                clean = demangle_display(gname) if gname.startswith('_') else gname
                idx_expr = self._resolve_reg(index, state)
                return f'{clean}[{idx_expr}]'

        # [base + index*scale + disp] → global array indexing via base register
        if base != 0 and index != 0 and disp == 0:
            base_expr = self._resolve_reg(base, state)
            # Check if base resolves to a global address
            if base_expr.startswith('0x') or base_expr.isdigit():
                try:
                    addr = int(base_expr, 0)
                    gname = state.globals_map.get(addr)
                    if gname:
                        clean = demangle_display(gname) if gname.startswith('_') else gname
                        idx_expr = self._resolve_reg(index, state)
                        return f'{clean}[{idx_expr}]'
                except ValueError:
                    pass

        # General memory access
        return self._resolve_mem_expr(op, inst, state)

    def _resolve_mem_expr(self, op, inst: Instruction, state: ExprState) -> str:
        """Fallback: resolve memory operand to a generic expression."""
        mem = op.mem
        base = mem.base
        index = mem.index
        scale = mem.scale
        disp = mem.disp

        # [index*scale + disp] → global array indexing
        if base == 0 and index != 0 and disp != 0:
            gname = state.globals_map.get(disp)
            if gname:
                clean = demangle_display(gname) if gname.startswith('_') else gname
                idx_expr = self._resolve_reg(index, state)
                return f'{clean}[{idx_expr}]'

        # [base + index*scale + 0] → local pointer array indexing
        if base and base != 0 and index and index != 0 and disp == 0:
            base_name = self._resolve_reg(base, state)
            idx_name = self._resolve_reg(index, state)
            # Check if base is a named variable (not a complex expression)
            if not any(c in base_name for c in '()+*& '):
                if scale > 1:
                    return f'{base_name}[{idx_name}]'
                else:
                    return f'*({base_name} + {idx_name})'

        parts = []
        base_name = ''
        if base and base != 0:
            base_name = self._resolve_reg(base, state)
            parts.append(base_name)

        if index and index != 0:
            idx_name = self._resolve_reg(index, state)
            if scale > 1:
                parts.append(f'{idx_name} * {scale}')
            else:
                parts.append(idx_name)

        if parts:
            expr = ' + '.join(parts)
            if disp > 0:
                return f'*({expr} + 0x{disp:x})'
            elif disp < 0:
                return f'*({expr} - 0x{-disp:x})'
            return f'*({expr})'

        if disp:
            return f'*(int *)0x{disp:x}'
        return '*(int *)0'

    def _resolve_mem_dst_name(self, op, inst: Instruction, state: ExprState) -> Optional[str]:
        """Try to resolve a memory destination to a named variable. Returns None if unnamed."""
        mem = op.mem
        base = mem.base
        index = mem.index
        disp = mem.disp

        # [ebp+/-N]: stack variable
        if base == X86_REG_EBP and index == 0:
            var = state.var_map.get(('ebp', disp))
            if var:
                return var
            if disp > 0:
                return f'arg_{disp:x}'
            elif disp < 0:
                return f'local_{(-disp):x}'

        # Absolute address
        if base == 0 and index == 0 and disp != 0:
            name = state.globals_map.get(disp)
            if name:
                return demangle_display(name) if name.startswith('_') else name
            name = state.dfunc.called_functions.get(disp)
            if name:
                return demangle_display(name)
            # Check if address is within a known global (struct field)
            result = self._find_global_at_offset(disp, state)
            if result:
                gname, offset = result
                clean = demangle_display(gname) if gname.startswith('_') else gname
                var_type = state.var_types.get(gname)
                if var_type:
                    cu = state.dfunc.func.cu
                    field = self.types.get_struct_field_at_offset(var_type, offset, cu=cu)
                    if field:
                        fname, _ = field
                        return f'{clean}.{fname}'
                return f'*((char *){clean} + 0x{offset:x})'

        # [base+disp] struct field (including offset 0)
        if base and base not in (0, X86_REG_ESP) and index == 0:
            field_result = self._resolve_struct_field_store(base, disp, state)
            if field_result:
                return field_result

        # [index*scale + disp] → global array store
        if base == 0 and index != 0 and disp != 0:
            gname = state.globals_map.get(disp)
            if gname:
                clean = demangle_display(gname) if gname.startswith('_') else gname
                idx_expr = self._resolve_reg(index, state)
                return f'{clean}[{idx_expr}]'

        return None

    def _resolve_dst_name(self, op, inst: Instruction, state: ExprState) -> Optional[str]:
        """Resolve a destination operand to a variable name if possible."""
        if op.type == X86_OP_REG:
            reg = REG_TO_32.get(op.reg)
            if reg:
                var = state.var_map.get(('reg', reg))
                if var:
                    return var
        elif op.type == X86_OP_MEM:
            return self._resolve_mem_dst_name(op, inst, state)
        return None

    def _resolve_lea(self, op, inst: Instruction, state: ExprState) -> str:
        """Resolve LEA source (address computation, not dereference)."""
        mem = op.mem
        base = mem.base
        index = mem.index
        scale = mem.scale
        disp = mem.disp

        # LEA reg, [ebp+/-N] → address of stack variable
        if base == X86_REG_EBP and index == 0:
            var = state.var_map.get(('ebp', disp))
            if var:
                return f'&{var}'
            if disp < 0:
                return f'&local_{(-disp):x}'
            return f'(ebp + {disp})'

        # LEA [base+disp] → &struct->field (address of struct field)
        if base and base not in (0, X86_REG_ESP, X86_REG_EBP) and index == 0:
            field_result = self._resolve_struct_field_load(base, disp, state)
            if field_result:
                # Cancel &* patterns: &*(expr) → expr, &*var → var
                if field_result.startswith('*(') and field_result.endswith(')'):
                    return field_result[2:-1]  # Strip *( and )
                if field_result.startswith('*'):
                    return field_result[1:]    # Strip *
                return f'&{field_result}'

        # LEA with absolute displacement and no base → address constant
        if base == 0 and index == 0:
            if disp:
                name = state.globals_map.get(disp)
                if name:
                    return f'&{demangle_display(name) if name.startswith("_") else name}'
                # Check if it's a string
                if inst.string_ref is not None:
                    escaped = inst.string_ref.replace('\\', '\\\\').replace('"', '\\"')
                    escaped = escaped.replace('\n', '\\n').replace('\t', '\\t')
                    return f'"{escaped}"'
                return f'0x{disp:x}'
            return '0'

        parts = []
        if base and base != 0:
            bname = self._resolve_reg(base, state)
            parts.append(bname)
        if index and index != 0:
            iname = self._resolve_reg(index, state)
            if scale > 1:
                parts.append(f'{iname} * {scale}')
            else:
                parts.append(iname)
        expr = ' + '.join(parts) if parts else ''
        if disp > 0:
            if expr:
                # Check if it's a string address
                if inst.string_ref is not None:
                    escaped = inst.string_ref.replace('\\', '\\\\').replace('"', '\\"')
                    escaped = escaped.replace('\n', '\\n').replace('\t', '\\t')
                    return f'"{escaped}"'
                return f'{expr} + 0x{disp:x}'
            return f'0x{disp:x}'
        elif disp < 0:
            if expr:
                return f'{expr} - 0x{-disp:x}'
            return f'-0x{-disp:x}'
        return expr or '0'

    # ---------------------------------------------------------------
    # Struct field resolution
    # ---------------------------------------------------------------

    def _resolve_struct_field_load(self, base_reg: int, disp: int,
                                    state: ExprState) -> Optional[str]:
        """Try to resolve [base+disp] as a struct field load. Returns expression or None."""
        reg32 = REG_TO_32.get(base_reg)
        if not reg32:
            return None

        # Find what variable is in this register
        var_name = state.var_map.get(('reg', reg32))
        if not var_name:
            # Check if register holds a variable reference
            expr = state.get_reg(reg32)
            if expr != reg32 and not any(c in expr for c in '()+*&'):
                var_name = expr

        if not var_name:
            return None

        var_type = state.var_types.get(var_name)
        if not var_type:
            return None

        # Resolve RangeType aliases (register var type may be an alias)
        cu = state.dfunc.func.cu if state.dfunc.func else None
        actual_type = var_type
        if isinstance(var_type, RangeType) and var_type.low == '' and var_type.high == '':
            base_key = var_type.base
            if cu and base_key in cu.type_map:
                actual_type = cu.type_map[base_key]
            elif base_key in self.stabs.all_types:
                actual_type = self.stabs.all_types[base_key]

        # Try to find struct field at offset (CU-aware)
        field = self.types.get_struct_field_at_offset(actual_type, disp, cu=cu)
        if field:
            fname, ftype = field
            # Determine if pointer dereference or direct access
            resolved = self.stabs.resolve_type(actual_type)
            if isinstance(resolved, PointerType):
                return f'{var_name}->{fname}'
            return f'{var_name}.{fname}'

        # No field found - use offset notation
        resolved = self.stabs.resolve_type(actual_type)
        if isinstance(resolved, PointerType):
            if disp == 0:
                return f'*{var_name}'
            return f'*(({var_name}) + 0x{disp:x})'
        return None

    def _resolve_struct_field_store(self, base_reg: int, disp: int,
                                     state: ExprState) -> Optional[str]:
        """Try to resolve [base+disp] as a struct field for store. Returns lvalue or None."""
        return self._resolve_struct_field_load(base_reg, disp, state)

    # ---------------------------------------------------------------
    # Condition generation
    # ---------------------------------------------------------------

    def _make_condition(self, inst: Instruction, state: ExprState) -> str:
        """Generate C condition expression for a conditional jump."""
        if state.last_cmp:
            lhs, rhs, cmp_type = state.last_cmp
            op = JUMP_TO_COND.get(inst.insn_id, '!=')
            if cmp_type == X86_INS_TEST:
                if lhs == rhs:
                    return f'{lhs} {op} 0'
                return f'({lhs} & {rhs}) {op} 0'
            return f'{lhs} {op} {rhs}'
        return f'cond /* {inst.mnemonic} */'

    def _make_setcc_condition(self, iid: int, state: ExprState) -> str:
        """Generate condition for SETcc/CMOVcc instructions."""
        cond_map = {**SETCC_TO_COND, **CMOVCC_TO_COND}
        op = cond_map.get(iid, '!=')
        if state.last_cmp:
            lhs, rhs, cmp_type = state.last_cmp
            if cmp_type == X86_INS_TEST:
                if lhs == rhs:
                    return f'{lhs} {op} 0'
                return f'({lhs} & {rhs}) {op} 0'
            return f'{lhs} {op} {rhs}'
        return f'cond_{op}'


# Keep DecompState as an alias for backward compatibility with structure.py
DecompState = ExprState
