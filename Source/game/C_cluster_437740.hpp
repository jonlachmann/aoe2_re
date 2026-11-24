// C_cluster_437740 — this-edge cluster; bounded record array.
#pragma once

#include "Function.hpp"

class C_cluster_437740 {
public:
    char pad_00[8];
    unsigned count;               // 0x08
    char pad_0C[0x114 - 0x0C];
    int* records;                 // 0x114, stride 36 bytes

    int MarkRecord_437740(unsigned index);
};
