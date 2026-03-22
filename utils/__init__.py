"""Compatibility package for the moved toolchain utilities.

This keeps ``python3 -m utils.decomp...`` working from the project root
after the real package moved under ``toolchain/utils``.
"""

from pathlib import Path

_HERE = Path(__file__).resolve().parent
_TOOLCHAIN_UTILS = _HERE.parent / 'toolchain' / 'utils'

if _TOOLCHAIN_UTILS.is_dir():
    __path__.append(str(_TOOLCHAIN_UTILS))
