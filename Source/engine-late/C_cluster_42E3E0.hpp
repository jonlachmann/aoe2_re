// C_cluster_42E3E0 — cluster anchored at 0x42E3E0 (engine-late region).
// This TU carries the 6-byte global function-pointer thunk at 0x5ECE44. The
// target pointer lives in runtime data at 0x61C01C.
#pragma once

#include "Function.hpp"

typedef void (*FpThunk)();

class C_cluster_42E3E0 {
public:
    void M_5ECE44();
};
