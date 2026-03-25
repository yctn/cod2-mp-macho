"""Control flow structuring: convert goto-based code to if/while/for/switch."""

from typing import Optional
from .cfg import BasicBlock, CFGBuilder, JUMP_TO_COND, JUMP_TO_COND_INVERSE
from .disasm import DisassembledFunction, Instruction
from .decompile_goto import GotoDecompiler, ExprState, REG32_MAP, REG_TO_32, DWARF_TO_REG
from .stabs_parser import StabsParser, Function
from .type_system import TypeResolver
from .demangle import demangle_display

from capstone.x86 import (
    X86_INS_CMP, X86_INS_TEST, X86_OP_REG, X86_OP_IMM,
)


class StructuredDecompiler:
    """Produces structured C code from CFG and goto-based decompilation."""

    def __init__(self, stabs: StabsParser, types: TypeResolver,
                 goto_decompiler: GotoDecompiler):
        self.stabs = stabs
        self.types = types
        self.goto = goto_decompiler

    def decompile(self, dfunc: DisassembledFunction,
                  blocks: list[BasicBlock]) -> str:
        """Decompile function with structured control flow."""
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

        # Declare variables (skip names already declared as parameters)
        declared = set()
        param_names = {p.name for p in func.params if p.name}
        declared.update(param_names)
        has_local_decls = False

        for lv in func.locals:
            if lv.name and lv.name not in declared:
                vtype = self.types.type_to_c(lv.type_ref, lv.name, cu=func.cu)
                lines.append(f'    {vtype};')
                declared.add(lv.name)
                has_local_decls = True
        for rv in func.reg_vars:
            if rv.name and rv.name not in declared:
                vtype = self.types.type_to_c(rv.type_ref, rv.name, cu=func.cu)
                lines.append(f'    {vtype};')
                declared.add(rv.name)
                has_local_decls = True

        # Declare scratch registers (expression cap may flush to these)
        scratch_regs = [r for r in ('eax', 'ecx', 'edx', 'ebx', 'esi', 'edi')
                        if r not in declared]
        if scratch_regs:
            lines.append(f'    int {", ".join(scratch_regs)};')
            has_local_decls = True

        if has_local_decls:
            lines.append('')

        # Build variable map, type map, and globals map for ExprState
        var_map = self.goto._build_var_map(func)
        var_types = self.goto._build_var_types(func)
        globals_map = self.goto._build_globals_map()
        jump_targets = set()
        for inst in dfunc.instructions:
            if inst.jump_target is not None:
                jump_targets.add(inst.jump_target)
        state = ExprState(var_map, var_types, globals_map, dfunc,
                          jump_targets, self.types)

        # Initialize regs for register variables (same as goto mode)
        for key, name in var_map.items():
            if key[0] == 'reg':
                state.regs[key[1]] = name

        # Structure the blocks
        if blocks:
            block_map = {bb.start_addr: bb for bb in blocks}
            visited = set()
            self._emit_block(blocks[0], blocks, block_map, visited,
                             state, lines, indent=1)

        lines.append('}')
        return '\n'.join(lines)

    def _emit_block(self, bb: BasicBlock, all_blocks: list[BasicBlock],
                    block_map: dict, visited: set, state: ExprState,
                    lines: list[str], indent: int):
        """Recursively emit structured code for a basic block and its successors."""
        if id(bb) in visited:
            # Already visited - emit goto
            lines.append(f'{"    " * indent}goto L_{bb.start_addr:x};')
            return
        visited.add(id(bb))

        pad = "    " * indent

        # Check if this is a loop header
        if bb.is_loop_header and bb.loop_body:
            self._emit_loop(bb, all_blocks, block_map, visited, state, lines, indent)
            return

        # Emit instructions for this block (except the terminator)
        self._emit_block_body(bb, state, lines, indent)

        # Handle successors
        if not bb.instructions:
            return

        last = bb.instructions[-1]

        if last.is_ret:
            pass  # Return already emitted in block body

        elif last.is_conditional_jump and len(bb.successors) == 2:
            self._emit_if_else(bb, all_blocks, block_map, visited, state, lines, indent)

        elif last.is_unconditional_jump:
            if last.jump_target and last.jump_target in block_map:
                target = block_map[last.jump_target]
                if id(target) not in visited:
                    self._emit_block(target, all_blocks, block_map, visited,
                                     state, lines, indent)
                else:
                    lines.append(f'{pad}goto L_{last.jump_target:x};')

        elif len(bb.successors) == 1:
            # Fall-through
            succ = bb.successors[0]
            if id(succ) not in visited:
                self._emit_block(succ, all_blocks, block_map, visited,
                                 state, lines, indent)
            elif succ.start_addr in state.jump_targets:
                lines.append(f'{pad}goto L_{succ.start_addr:x};')

    def _emit_block_body(self, bb: BasicBlock, state: ExprState,
                         lines: list[str], indent: int):
        """Emit the body of a basic block (instructions as C statements)."""
        pad = "    " * indent
        for inst in bb.instructions:
            # Skip the terminator jump/branch - handled by control flow
            if inst.is_conditional_jump or inst.is_unconditional_jump:
                continue

            c_lines = self.goto._process(inst, state)
            for cl in c_lines:
                if cl:
                    lines.append(f'{pad}{cl}')

            # Cap expression size to prevent exponential growth
            # (same as goto mode cap in GotoDecompiler.decompile)
            for reg_name, expr in list(state.regs.items()):
                if len(expr) > 200:
                    lines.append(f'{pad}{reg_name} = {expr};')
                    state.regs[reg_name] = reg_name

    def _emit_if_else(self, bb: BasicBlock, all_blocks: list[BasicBlock],
                      block_map: dict, visited: set, state: ExprState,
                      lines: list[str], indent: int):
        """Emit if/else structure."""
        pad = "    " * indent
        last = bb.instructions[-1]

        # Successors: [0] = jump target (true), [1] = fall-through (false)
        true_bb = bb.successors[0]
        false_bb = bb.successors[1]

        # Generate condition (inverted - jump on true, fall through on false)
        cond = self._make_block_condition(bb, state, inverted=True)

        # Detect both-return pattern (no successors + last inst is ret)
        true_returns = (len(true_bb.successors) == 0 and true_bb.instructions and
                        true_bb.instructions[-1].is_ret)
        false_returns = (len(false_bb.successors) == 0 and false_bb.instructions and
                         false_bb.instructions[-1].is_ret)

        if true_returns and false_returns:
            # Both branches return — clean if/else
            lines.append(f'{pad}if ({cond}) {{')
            visited.add(id(false_bb))
            self._emit_block_body(false_bb, state, lines, indent + 1)
            lines.append(f'{pad}}} else {{')
            visited.add(id(true_bb))
            self._emit_block_body(true_bb, state, lines, indent + 1)
            lines.append(f'{pad}}}')
            return

        if true_returns and not false_returns and id(false_bb) not in visited:
            # Jump target returns — emit return as early guard, continue with main path
            inv_cond = self._make_block_condition(bb, state, inverted=False)
            lines.append(f'{pad}if ({inv_cond}) {{')
            visited.add(id(true_bb))
            self._emit_block_body(true_bb, state, lines, indent + 1)
            lines.append(f'{pad}}}')
            self._emit_block(false_bb, all_blocks, block_map, visited,
                             state, lines, indent)
            return

        if false_returns and not true_returns and id(true_bb) not in visited:
            # Inverted: fall-through returns, jump target continues
            inv_cond = self._make_block_condition(bb, state, inverted=False)
            lines.append(f'{pad}if ({inv_cond}) {{')
            visited.add(id(true_bb))
            self._emit_block_body(true_bb, state, lines, indent + 1)
            lines.append(f'{pad}}}')
            self._emit_block(false_bb, all_blocks, block_map, visited,
                             state, lines, indent)
            return

        # Check if one branch immediately merges (simple if without else)
        true_single = (len(true_bb.successors) == 1 and
                       true_bb.successors[0] is false_bb and
                       id(true_bb) not in visited)
        false_single = (len(false_bb.successors) == 1 and
                        false_bb.successors[0] is true_bb and
                        id(false_bb) not in visited)

        if false_single and not true_single:
            # if (cond) { true_block; } then continue with the other
            lines.append(f'{pad}if ({cond}) {{')
            visited.add(id(false_bb))
            self._emit_block_body(false_bb, state, lines, indent + 1)
            lines.append(f'{pad}}}')
            if id(true_bb) not in visited:
                self._emit_block(true_bb, all_blocks, block_map, visited,
                                 state, lines, indent)
        elif true_single:
            # if (!cond) { false_block; } then continue
            inv_cond = self._make_block_condition(bb, state, inverted=False)
            lines.append(f'{pad}if ({inv_cond}) {{')
            visited.add(id(true_bb))
            self._emit_block_body(true_bb, state, lines, indent + 1)
            lines.append(f'{pad}}}')
            if id(false_bb) not in visited:
                self._emit_block(false_bb, all_blocks, block_map, visited,
                                 state, lines, indent)
        else:
            # Full if/else
            lines.append(f'{pad}if ({cond}) {{')
            self._emit_block(false_bb, all_blocks, block_map, visited,
                             state, lines, indent + 1)
            lines.append(f'{pad}}} else {{')
            self._emit_block(true_bb, all_blocks, block_map, visited,
                             state, lines, indent + 1)
            lines.append(f'{pad}}}')

    def _emit_loop(self, header: BasicBlock, all_blocks: list[BasicBlock],
                   block_map: dict, visited: set, state: ExprState,
                   lines: list[str], indent: int):
        """Emit loop structure."""
        pad = "    " * indent

        # Determine loop type
        last = header.instructions[-1] if header.instructions else None

        if last and last.is_conditional_jump and len(header.successors) == 2:
            # Check if this is a proper while (condition at header exits loop)
            exit_bb = None
            body_bb = None

            for succ in header.successors:
                if header.loop_body and id(succ) in header.loop_body:
                    body_bb = succ
                else:
                    exit_bb = succ

            if exit_bb and body_bb:
                # True while loop: one successor exits, one stays in loop
                cond = self._make_block_condition(header, state, inverted=True)

                # Emit block body (non-terminator instructions)
                self._emit_block_body(header, state, lines, indent)

                lines.append(f'{pad}while ({cond}) {{')

                # Emit loop body
                body_visited = set(visited)
                if body_bb and id(body_bb) not in visited:
                    self._emit_block(body_bb, all_blocks, block_map, body_visited,
                                     state, lines, indent + 1)
                visited.update(body_visited)

                lines.append(f'{pad}}}')

                # Continue with exit
                if exit_bb and id(exit_bb) not in visited:
                    self._emit_block(exit_bb, all_blocks, block_map, visited,
                                     state, lines, indent)
            else:
                # Both successors in loop body → inner conditional, use while(1)
                self._emit_block_body(header, state, lines, indent)
                lines.append(f'{pad}while (1) {{')

                for succ in header.successors:
                    if id(succ) not in visited:
                        self._emit_block(succ, all_blocks, block_map, visited,
                                         state, lines, indent + 1)

                lines.append(f'{pad}}}')
        else:
            # Do-while or generic loop - use while(1) with break
            self._emit_block_body(header, state, lines, indent)
            lines.append(f'{pad}while (1) {{')

            # Emit body blocks
            for succ in header.successors:
                if id(succ) not in visited:
                    self._emit_block(succ, all_blocks, block_map, visited,
                                     state, lines, indent + 1)

            lines.append(f'{pad}}}')

    def _make_block_condition(self, bb: BasicBlock, state: ExprState,
                              inverted: bool = False) -> str:
        """Generate condition from the CMP+Jcc at end of a basic block."""
        if not bb.instructions:
            return '1'

        last = bb.instructions[-1]
        if not last.is_conditional_jump:
            return '1'

        # Find CMP/TEST before the jump and resolve through expression state
        cmp_inst = None
        for inst in reversed(bb.instructions[:-1]):
            if inst.insn_id in (X86_INS_CMP, X86_INS_TEST):
                cmp_inst = inst
                break

        if cmp_inst and len(cmp_inst.operands) == 2:
            lhs = self.goto._resolve_src(cmp_inst.operands[0], cmp_inst, state)
            rhs = self.goto._resolve_src(cmp_inst.operands[1], cmp_inst, state)

            if inverted:
                op = JUMP_TO_COND_INVERSE.get(last.insn_id, '==')
            else:
                op = JUMP_TO_COND.get(last.insn_id, '!=')

            if cmp_inst.insn_id == X86_INS_TEST:
                if lhs == rhs:
                    return f'{lhs} {op} 0'
                return f'({lhs} & {rhs}) {op} 0'
            return f'{lhs} {op} {rhs}'

        # Fallback to state
        if state.last_cmp:
            lhs, rhs, cmp_type = state.last_cmp
            if inverted:
                op = JUMP_TO_COND_INVERSE.get(last.insn_id, '==')
            else:
                op = JUMP_TO_COND.get(last.insn_id, '!=')
            return f'{lhs} {op} {rhs}'

        return f'/* {last.mnemonic} */ 1'
