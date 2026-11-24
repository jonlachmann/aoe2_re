// C_cluster_46E2D0 — cluster anchored at 0x46E2D0 (gfx region).
// This TU carries the single byte-verified pointer rewrite. The original is a
// plain __stdcall entry point taking an explicit pointer, so it stays static.
#pragma once

#include "Function.hpp"

struct S472420 {
    char pad_00[0x4E];
    unsigned char field_4E;       // +0x4E
    char pad_4F[0x1C4 - 0x4F];
    void* field_1C4;              // +0x1C4
};

class C_cluster_46E2D0 {
public:
    static S472420* __stdcall M_472420(S472420* p);
};
