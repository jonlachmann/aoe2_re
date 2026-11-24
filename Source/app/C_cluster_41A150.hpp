// C_cluster_41A150 — cluster anchored at 0x41A150 (app region).
// This TU carries the 5-byte tail-jump thunk into the thiscall constructor at
// 0x526980 (which writes vtable 0x627094). The target is a placeholder until
// that constructor's class TU is recovered.
#pragma once

#include "Function.hpp"

class T526980 {
public:
    void Init_526980();
};

class C_cluster_41A150 {
public:
    void M_41A150();
};
