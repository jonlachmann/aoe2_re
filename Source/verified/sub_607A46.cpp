// sub_607A46 — CRT _isctype-style table test (differential-verification reconstruction).
// Original ABI (cdecl): int sub_607A46(unsigned char c, unsigned extra_mask, unsigned mask)
// Reads the byte table at 0x772bc1 and the word table at 0x661f5e (absolute).
extern "C" int sub_607A46() {
    __asm__ volatile (
        "movzbl 4(%%esp), %%eax\n\t"            // 0x607A46: movzx eax, byte ptr [esp+4]
        "movb 12(%%esp), %%cl\n\t"              // 0x607A4B: mov cl, byte ptr [esp+0xc]
        "testb %%cl, 0x772bc1(%%eax)\n\t"       // 0x607A4F: test byte ptr [eax+0x772bc1], cl
        "jne 2f\n\t"                            // 0x607A55: jne 0x607a73
        "cmpl $0, 8(%%esp)\n\t"                 // 0x607A57: cmp dword ptr [esp+8], 0
        "je 1f\n\t"                             // 0x607A5C: je 0x607a6c
        "movzwl 0x661f5e(,%%eax,2), %%eax\n\t"  // 0x607A5E: movzx eax, word ptr [eax*2+0x661f5e]
        "andl 8(%%esp), %%eax\n\t"              // 0x607A66: and eax, [esp+8]
        "jmp 3f\n\t"                            // 0x607A6A: jmp
        "1:\n\t"                                // 0x607A6C: xor eax, eax
        "xorl %%eax, %%eax\n\t"
        "3:\n\t"                                // 0x607A6E: test eax, eax
        "testl %%eax, %%eax\n\t"
        "jne 2f\n\t"                            // 0x607A70: jne
        "xorl %%eax, %%eax\n\t"                 // 0x607A72: (return 0 — eax already 0)
        "ret\n\t"                               // 0x607A72: ret
        "2:\n\t"                                // 0x607A73: push 1; pop eax; ret
        "pushl $1\n\t"
        "popl %%eax\n\t"
        "ret\n\t"
        : : : "eax", "ecx", "memory");
}
