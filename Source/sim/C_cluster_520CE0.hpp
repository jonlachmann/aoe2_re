// C_cluster_520CE0 — cluster anchored at 0x520CE0 (sim region).
// This TU carries the 2 byte-verified WIP searches. Their head fields sit at
// different offsets (+0x80 and +0x7C), so no shared member field is declared.
#pragma once

#include "Function.hpp"

class C_cluster_520CE0 {
public:
    int Find_5219B0(int a2);
    int Find_5219E0(int a2);
};
