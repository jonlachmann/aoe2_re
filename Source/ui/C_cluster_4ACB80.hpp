// C_cluster_4ACB80 — cluster anchored at 0x4ACB80 (ui region).
// This TU carries the 2 byte-verified methods. The flag at +0xA2 and the
// pointer at +0xD4 are reconstructed; virtual slot +0x04 is needed by the flag
// setter, so two placeholder slots precede the data.
#pragma once

#include "Function.hpp"

class C_cluster_4ACB80 {
public:
    virtual void V0();
    virtual void V1(int v);

    char pad_04[0xA2 - 4];
    unsigned char field_A2;       // +0xA2
    char pad_A3[0xD4 - 0xA3];
    void* field_D4;               // +0xD4, byte table base

    void SetOne_4ACB80();
    char M_4AD440(int index);
};
