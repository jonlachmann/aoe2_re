// C_cluster_585FF0 — cluster anchored at 0x585FF0 (sim region).
// This TU carries the 5-byte tail-jump thunk into the thiscall target at
// 0x411F80. The target is a placeholder until its class TU carries the body.
#pragma once

#include "Function.hpp"

class T411F80 {
public:
    void Init_411F80();
};

class C_cluster_585FF0 {
public:
    void M_585FF0();
};
