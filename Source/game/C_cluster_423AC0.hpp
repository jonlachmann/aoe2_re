// C_cluster_423AC0 — game cluster anchored at 0x423AC0. This TU carries the
// byte-verified reset pair 0x4241B0/0x4242F0 and their shared caller 0x423AC0.
// Fields +0x00/+0x04/+0x08/+0x14/+0x524/+0x544 are proven across those bodies.
#pragma once

#include "Function.hpp"

class C_cluster_423AC0 {
public:
    int field_0;                  // +0x00
    int field_4;                  // +0x04
    int field_8;                  // +0x08
    char pad_c[0x14 - 0xc];
    unsigned char field_14;       // +0x14
    char pad_15[0x524 - 0x15];
    int field_524;                // +0x524
    char pad_528[0x544 - 0x528];
    int field_544;                // +0x544

    void M_4241B0();
    void M_4242F0();
    void M_423AC0();
};
