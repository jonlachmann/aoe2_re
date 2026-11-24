// sub_5FE370 — MSVC CRT _chkstk (probe-and-allocate variant measured at 0x5FE370):
// probes pages downward from the caller's frame and lands esp at (entry_esp - eax + 4),
// restoring ecx/eax from the stack. Reconstruction for differential verification.
extern "C" void sub_5FE370() {
    __asm__ volatile (
        "pushl %%ecx\n\t"            // 0x5FE370: push ecx
        "cmpl $0x1000, %%eax\n\t"    // 0x5FE371: cmp eax, 0x1000
        "leal 8(%%esp), %%ecx\n\t"   // 0x5FE376: lea ecx, [esp+8]
        "jb 1f\n\t"                  // 0x5FE37A: jb
        "2:\n\t"                     // 0x5FE37C: probe loop
        "subl $0x1000, %%ecx\n\t"
        "subl $0x1000, %%eax\n\t"
        "testl %%eax, (%%ecx)\n\t"
        "cmpl $0x1000, %%eax\n\t"
        "jae 2b\n\t"
        "1:\n\t"                     // 0x5FE390
        "subl %%eax, %%ecx\n\t"
        "movl %%esp, %%eax\n\t"
        "testl %%eax, (%%ecx)\n\t"
        "movl %%ecx, %%esp\n\t"
        "movl (%%eax), %%ecx\n\t"
        "movl 4(%%eax), %%eax\n\t"
        "pushl %%eax\n\t"
        "ret\n\t"
        : : : "eax", "ecx", "memory");
}
