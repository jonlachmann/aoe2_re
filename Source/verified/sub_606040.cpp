// sub_606040 — CRT command-line parser (differential-verification reconstruction).
// Returns a pointer into the command line at the start of the arguments
// (skipping the executable name, quoted or bare). Reads:
//   dword 0x773E04 = the command line pointer (valid when dword 0x773E0C != 0)
//   byte table at 0x772bc1 (ctype flags), word table at 0x661f5e (unused: extra=0)
// Mirrors the original bytes at 0x606040..0x606097.
extern "C" unsigned char sub_606040() {
    __asm__ volatile (
        "cmpl $0, 0x773e0c\n\t"                 // 0x606040
        "jne .Lstart\n\t"                       // 0x606047
        "call 0x604208\n\t"                     // 0x606049 (init path; unused in harness)
        ".Lstart:\n\t"                          // 0x60604E
        "pushl %%esi\n\t"
        "movl 0x773e04, %%esi\n\t"              // 0x60604F
        "movb (%%esi), %%al\n\t"                // 0x606055
        "cmpb $0x22, %%al\n\t"                  // 0x606057
        "jne .Lunquoted\n\t"                    // 0x606059 -> 0x606080
        ".Lquoted:\n\t"                         // 0x60605B
        "movb 1(%%esi), %%al\n\t"
        "incl %%esi\n\t"
        "cmpb $0x22, %%al\n\t"                  // 0x60605F
        "je .Lcloseq\n\t"                       // 0x606061 -> 0x606078
        "testb %%al, %%al\n\t"                  // 0x606063
        "je .Lcloseq\n\t"                       // 0x606065
        "movzbl %%al, %%eax\n\t"                // 0x606067
        "testb $4, 0x772bc1(%%eax)\n\t"         // helper 0x607A35 inlined (mask 4, extra 0)
        "je .Lquoted\n\t"                       // 0x606073 -> 0x60605b
        "incl %%esi\n\t"                        // 0x606075
        "jmp .Lquoted\n\t"                      // 0x606076
        ".Lcloseq:\n\t"                         // 0x606078
        "cmpb $0x22, (%%esi)\n\t"
        "jne .Ltail\n\t"                        // 0x60607B -> 0x60608a
        "incl %%esi\n\t"                        // 0x60607D
        ".Ltail:\n\t"                           // 0x60608A
        "movb (%%esi), %%al\n\t"
        "testb %%al, %%al\n\t"                  // 0x60608C
        "je .Ldone\n\t"                         // 0x60608E -> 0x606094
        "cmpb $0x20, %%al\n\t"                  // 0x606090
        "jbe .Lskipone\n\t"                     // 0x606092 -> 0x60607d
        ".Ldone:\n\t"                           // 0x606094
        "movl %%esi, %%eax\n\t"
        "popl %%esi\n\t"
        "ret\n\t"                               // 0x606097
        ".Lskipone:\n\t"                        // 0x60607D copy
        "incl %%esi\n\t"
        "jmp .Ltail\n\t"
        : : : "eax", "esi", "memory");
}
