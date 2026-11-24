#!/usr/bin/env python3
"""Extract x86 disassembly of a function address range from the local reference exe."""
import os
import sys
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

TARGET = os.environ.get("AOE_BIN") or "reference/AOE2.EXE"
IMAGE_BASE = 0x400000

def main(path, va, size=0x80):
    va = int(va, 16) if isinstance(va, str) else va
    pe = pefile.PE(TARGET)
    rva = va - pe.OPTIONAL_HEADER.ImageBase
    data = pe.get_data(rva, size)
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = False
    for ins in md.disasm(data, va):
        print(f"0x{ins.address:08x}  {ins.bytes.hex():<20} {ins.mnemonic} {ins.op_str}")

if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2], int(sys.argv[3], 16) if len(sys.argv) > 3 else 0x80)