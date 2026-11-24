#!/usr/bin/env python3
"""Quick PE triage for aoe2_re: headers, sections, imports, exports, string hints."""
import os
import sys
import pefile

def main(path):
    pe = pefile.PE(path)
    fh = pe.FILE_HEADER
    print(f"Machine: {hex(fh.Machine)}  Timestamp: {hex(fh.TimeDateStamp)}")
    oh = pe.OPTIONAL_HEADER
    print(f"ImageBase: {hex(oh.ImageBase)}  EntryPoint: {hex(oh.AddressOfEntryPoint)}")
    print("\nSections:")
    for s in pe.sections:
        print(f"  {s.Name.decode().strip(chr(0)):<12} VA {hex(s.VirtualAddress):<10} "
              f"VSize {hex(s.Misc_VirtualSize):<10} RawSize {hex(s.SizeOfRawData)}")
    if hasattr(pe, "DIRECTORY_ENTRY_EXPORT"):
        print("\nExports:")
        for e in pe.DIRECTORY_ENTRY_EXPORT.symbols:
            print(f"  {e.name}")
    print("\nImports:")
    for entry in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
        print(f"  {entry.dll.decode()}")
        for imp in entry.imports:
            name = imp.name.decode() if imp.name else f"ord{imp.ordinal}"
            print(f"    {hex(imp.address)}  {name}")

if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1
         else os.environ.get("AOE_BIN") or "reference/AOE2.EXE")