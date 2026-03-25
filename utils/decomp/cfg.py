"""Control flow graph builder for disassembled functions."""

from dataclasses import dataclass, field
from typing import Optional
from .disasm import DisassembledFunction, Instruction
from .macho_loader import MachOLoader

from capstone.x86 import (
    X86_INS_CMP, X86_INS_JMP, X86_OP_MEM, X86_OP_REG, X86_OP_IMM,
    X86_REG_INVALID,
    X86_INS_JA, X86_INS_JAE, X86_INS_JB, X86_INS_JBE,
    X86_INS_JE, X86_INS_JNE, X86_INS_JG, X86_INS_JGE,
    X86_INS_JL, X86_INS_JLE,
)


# Condition code inversions for if/else
CONDITION_INVERSE = {
    X86_INS_JA: X86_INS_JBE,
    X86_INS_JAE: X86_INS_JB,
    X86_INS_JB: X86_INS_JAE,
    X86_INS_JBE: X86_INS_JA,
    X86_INS_JE: X86_INS_JNE,
    X86_INS_JNE: X86_INS_JE,
    X86_INS_JG: X86_INS_JLE,
    X86_INS_JGE: X86_INS_JL,
    X86_INS_JL: X86_INS_JGE,
    X86_INS_JLE: X86_INS_JG,
}

# Map jump instructions to C comparison operators
JUMP_TO_COND = {
    X86_INS_JE: '==',
    X86_INS_JNE: '!=',
    X86_INS_JG: '>',
    X86_INS_JGE: '>=',
    X86_INS_JL: '<',
    X86_INS_JLE: '<=',
    X86_INS_JA: '>',   # unsigned
    X86_INS_JAE: '>=',  # unsigned
    X86_INS_JB: '<',   # unsigned
    X86_INS_JBE: '<=',  # unsigned
}

JUMP_TO_COND_INVERSE = {
    X86_INS_JE: '!=',
    X86_INS_JNE: '==',
    X86_INS_JG: '<=',
    X86_INS_JGE: '<',
    X86_INS_JL: '>=',
    X86_INS_JLE: '>',
    X86_INS_JA: '<=',
    X86_INS_JAE: '<',
    X86_INS_JB: '>=',
    X86_INS_JBE: '>',
}


@dataclass
class BasicBlock:
    start_addr: int
    end_addr: int  # address after last instruction
    instructions: list[Instruction] = field(default_factory=list)
    successors: list['BasicBlock'] = field(default_factory=list)
    predecessors: list['BasicBlock'] = field(default_factory=list)
    # Analysis results
    dominator: Optional['BasicBlock'] = None
    is_loop_header: bool = False
    loop_body: Optional[set] = None
    # Switch info
    switch_var: Optional[str] = None
    switch_cases: Optional[dict] = None  # value -> target block
    switch_default: Optional['BasicBlock'] = None


@dataclass
class SwitchInfo:
    cmp_value: int
    default_target: int
    table_addr: int
    case_targets: list[int]


class CFGBuilder:
    def __init__(self, loader: MachOLoader):
        self.loader = loader

    def build_cfg(self, dfunc: DisassembledFunction) -> list[BasicBlock]:
        """Build control flow graph for a disassembled function."""
        instructions = dfunc.instructions
        if not instructions:
            return []

        func_start = dfunc.func.addr
        func_end = func_start + dfunc.func.size

        # Step 1: Find all basic block leaders (split points)
        leaders = {instructions[0].addr}  # First instruction is always a leader

        for inst in instructions:
            if inst.is_conditional_jump and inst.jump_target is not None:
                leaders.add(inst.jump_target)
                # Instruction after conditional jump is also a leader
                next_addr = inst.addr + inst.size
                leaders.add(next_addr)
            elif inst.is_unconditional_jump and inst.jump_target is not None:
                leaders.add(inst.jump_target)
                next_addr = inst.addr + inst.size
                if next_addr < func_end:
                    leaders.add(next_addr)
            elif inst.is_ret:
                next_addr = inst.addr + inst.size
                if next_addr < func_end:
                    leaders.add(next_addr)
            elif inst.is_call:
                # Don't split on calls normally, but the next instruction
                # after a noreturn call could be a leader
                pass

        # Step 2: Create basic blocks
        sorted_leaders = sorted(leaders)
        addr_to_block: dict[int, BasicBlock] = {}
        blocks: list[BasicBlock] = []

        # Build instruction address map
        inst_map: dict[int, int] = {}  # addr -> index
        for idx, inst in enumerate(instructions):
            inst_map[inst.addr] = idx

        for leader_addr in sorted_leaders:
            if leader_addr not in inst_map:
                continue
            start_idx = inst_map[leader_addr]
            bb = BasicBlock(start_addr=leader_addr, end_addr=leader_addr)
            addr_to_block[leader_addr] = bb
            blocks.append(bb)

            # Add instructions until next leader or end
            for j in range(start_idx, len(instructions)):
                inst = instructions[j]
                if j > start_idx and inst.addr in leaders:
                    break
                bb.instructions.append(inst)
                bb.end_addr = inst.addr + inst.size

        # Step 3: Add edges
        for bb in blocks:
            if not bb.instructions:
                continue
            last = bb.instructions[-1]

            if last.is_ret:
                pass  # No successors
            elif last.is_conditional_jump:
                # True branch (jump target)
                if last.jump_target and last.jump_target in addr_to_block:
                    target_bb = addr_to_block[last.jump_target]
                    bb.successors.append(target_bb)
                    target_bb.predecessors.append(bb)
                # Fall-through
                fallthrough_addr = last.addr + last.size
                if fallthrough_addr in addr_to_block:
                    fall_bb = addr_to_block[fallthrough_addr]
                    bb.successors.append(fall_bb)
                    fall_bb.predecessors.append(bb)
            elif last.is_unconditional_jump:
                if last.jump_target and last.jump_target in addr_to_block:
                    target_bb = addr_to_block[last.jump_target]
                    bb.successors.append(target_bb)
                    target_bb.predecessors.append(bb)
                # Check for switch/jump table
                elif self._is_indirect_jump(last):
                    switch = self._detect_switch(bb, instructions, addr_to_block)
                    if switch:
                        for target in switch.case_targets:
                            if target in addr_to_block:
                                target_bb = addr_to_block[target]
                                bb.successors.append(target_bb)
                                target_bb.predecessors.append(bb)
                        if switch.default_target in addr_to_block:
                            bb.switch_default = addr_to_block[switch.default_target]
            else:
                # Fall through to next block
                fallthrough_addr = last.addr + last.size
                if fallthrough_addr in addr_to_block:
                    fall_bb = addr_to_block[fallthrough_addr]
                    bb.successors.append(fall_bb)
                    fall_bb.predecessors.append(bb)

        # Step 4: Compute dominators
        if blocks:
            self._compute_dominators(blocks)
            self._detect_loops(blocks)

        return blocks

    def _is_indirect_jump(self, inst: Instruction) -> bool:
        """Check if instruction is an indirect jump (e.g., jmp [table + reg*4])."""
        if not inst.is_unconditional_jump:
            return False
        if inst.operands and inst.operands[0].type == X86_OP_MEM:
            return True
        if inst.operands and inst.operands[0].type == X86_OP_REG:
            return True
        return False

    def _detect_switch(self, bb: BasicBlock, all_instructions: list[Instruction],
                       addr_to_block: dict[int, BasicBlock]) -> Optional[SwitchInfo]:
        """Detect switch table pattern: cmp reg, N; ja default; jmp [table+reg*4]."""
        instrs = bb.instructions
        if len(instrs) < 1:
            return None

        last = instrs[-1]
        if not self._is_indirect_jump(last):
            return None

        # Look for jmp [base + reg*4] pattern
        if last.operands and last.operands[0].type == X86_OP_MEM:
            mem = last.operands[0].mem
            if mem.scale == 4 and mem.disp != 0:
                table_addr = mem.disp
                # Look backwards for cmp + ja (bounds check)
                cmp_value = None
                default_target = None
                for pred in bb.predecessors:
                    if not pred.instructions:
                        continue
                    plast = pred.instructions[-1]
                    if plast.is_conditional_jump and plast.jump_target:
                        # Found the bounds check
                        default_target = plast.jump_target
                        # Look for cmp before it
                        for pi in reversed(pred.instructions[:-1]):
                            if pi.insn_id == X86_INS_CMP:
                                for op in pi.operands:
                                    if op.type == X86_OP_IMM:
                                        cmp_value = op.imm
                                        break
                                break

                if cmp_value is not None:
                    # Read jump table entries
                    case_targets = []
                    for i in range(cmp_value + 1):
                        try:
                            target = self.loader.read_u32(table_addr + i * 4)
                            case_targets.append(target)
                        except (ValueError, IndexError):
                            break
                    if case_targets:
                        return SwitchInfo(cmp_value, default_target or 0,
                                          table_addr, case_targets)
        return None

    def _compute_dominators(self, blocks: list[BasicBlock]):
        """Compute immediate dominators using iterative algorithm (Cooper-Harvey-Kennedy)."""
        if not blocks:
            return

        entry = blocks[0]
        # Initialize: entry dominates itself, all others undefined
        entry.dominator = entry

        # Build reverse postorder
        rpo = self._reverse_postorder(entry, blocks)
        rpo_index = {id(bb): i for i, bb in enumerate(rpo)}

        changed = True
        while changed:
            changed = False
            for bb in rpo[1:]:  # Skip entry
                new_idom = None
                for pred in bb.predecessors:
                    if pred.dominator is None:
                        continue
                    if new_idom is None:
                        new_idom = pred
                    else:
                        new_idom = self._intersect(new_idom, pred, rpo_index)
                if new_idom and new_idom != bb.dominator:
                    bb.dominator = new_idom
                    changed = True

    def _intersect(self, b1: BasicBlock, b2: BasicBlock,
                   rpo_index: dict) -> BasicBlock:
        """Find common dominator of two blocks."""
        finger1, finger2 = b1, b2
        while finger1 is not finger2:
            while rpo_index.get(id(finger1), 0) > rpo_index.get(id(finger2), 0):
                if finger1.dominator is None or finger1.dominator is finger1:
                    return finger1
                finger1 = finger1.dominator
            while rpo_index.get(id(finger2), 0) > rpo_index.get(id(finger1), 0):
                if finger2.dominator is None or finger2.dominator is finger2:
                    return finger2
                finger2 = finger2.dominator
        return finger1

    def _reverse_postorder(self, entry: BasicBlock,
                            all_blocks: list[BasicBlock]) -> list[BasicBlock]:
        """Compute reverse postorder traversal."""
        visited = set()
        postorder = []

        def dfs(bb):
            if id(bb) in visited:
                return
            visited.add(id(bb))
            for succ in bb.successors:
                dfs(succ)
            postorder.append(bb)

        dfs(entry)
        # Add unreachable blocks
        for bb in all_blocks:
            if id(bb) not in visited:
                postorder.append(bb)

        return list(reversed(postorder))

    def _detect_loops(self, blocks: list[BasicBlock]):
        """Detect natural loops via back edges."""
        for bb in blocks:
            for succ in bb.successors:
                if self._dominates(succ, bb, blocks):
                    # Back edge: bb -> succ, succ is loop header
                    succ.is_loop_header = True
                    body = self._find_loop_body(succ, bb)
                    succ.loop_body = body

    def _dominates(self, a: BasicBlock, b: BasicBlock,
                    blocks: list[BasicBlock]) -> bool:
        """Check if block a dominates block b."""
        current = b
        visited = set()
        while current is not None:
            if current == a:
                return True
            if id(current) in visited:
                return False
            visited.add(id(current))
            if current.dominator == current:
                return current == a
            current = current.dominator
        return False

    def _find_loop_body(self, header: BasicBlock,
                         tail: BasicBlock) -> set:
        """Find all blocks in a natural loop given header and tail (back edge source)."""
        body = {id(header), id(tail)}
        worklist = [tail]
        while worklist:
            bb = worklist.pop()
            for pred in bb.predecessors:
                if id(pred) not in body:
                    body.add(id(pred))
                    worklist.append(pred)
        return body
