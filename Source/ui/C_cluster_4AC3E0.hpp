// C_cluster_4AC3E0 — this-edge cluster; bounded record lookup.
#pragma once

#include "Function.hpp"

class C_cluster_4AC3E0 {
public:
    char pad_00[41 * 4];
    int count;                    // 0x0A4
    int* records;                 // 0x0A8, dword stride

    int GetRecord_4AC3E0(__int16 index, int* out);
};
