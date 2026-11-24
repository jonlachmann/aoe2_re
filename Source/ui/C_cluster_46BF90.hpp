// C_cluster_46BF90 — this-edge cluster; small float array fill.
#pragma once

#include "Function.hpp"

class C_cluster_46BF90 {
public:
    char pad_00[52 * 4];
    int count;                    // 0x0D0
    char pad_D4[232 * 4 - 52 * 4 - 4];
    int* values;                  // 0x3A0

    int FillPositiveInf_472A70();
};
