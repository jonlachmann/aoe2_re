# Ghidra headless post-script: decompile functions at addresses given as script args.
# Usage: analyzeHeadless ... -postScript decomp.py <addr> [addr...]
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
af = currentProgram.getAddressFactory().getDefaultAddressSpace()
di = DecompInterface()
di.openProgram(currentProgram)
monitor = ConsoleTaskMonitor()
out = []
for a in args:
    addr = af.getAddress(a)
    func = getFunctionAt(addr)
    if func is None:
        # disassemble and create function
        disassemble(addr)
        from ghidra.program.model.symbol import SourceType
        func = createFunction(addr, None)
    if func is None:
        out.append("// no function at %s" % a)
        continue
    res = di.decompileFunction(func, 120, monitor)
    if res.decompileCompleted():
        out.append("// ==== %s ====" % a)
        out.append(res.getDecompiledFunction().getC())
    else:
        out.append("// decompile failed at %s" % a)
print("\n".join(out))
