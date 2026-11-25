// C_cluster_520CE0 — cluster anchored at 0x520CE0 (sim region).
// This TU carries the 2 byte-verified WIP searches. Their head fields sit at
// different offsets (+0x80 and +0x7C), so no shared member field is declared.
#pragma once

#include "Function.hpp"

class C_cluster_520CE0 {
public:
    int field_0;                  // +0x00
    void Hook_521580();           // unresolved callee at 0x521580
    void Hook_521500();           // unresolved callee at 0x521500
    int Find_5219B0(int a2);
    int Find_5219E0(int a2);
    void M_5214E0();
    void M_522C30();
    void M_522C50();
};
