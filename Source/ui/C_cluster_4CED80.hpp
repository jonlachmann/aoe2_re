// C_cluster_4CED80 — cluster anchored at 0x4CED80 (ui region). Its matched
// methods also include sim-address members 0x5C1410/0x5C1A00.
// Partial layout: the 0x1BAC record table runs to +0x4CD4, so the raw +0x1930
// and +0x19B0 index bases of the two ui getters sit inside it.
#pragma once

#include "Function.hpp"

class C_cluster_4CED80 {
public:
    char pad_00[0x1BAC];
    int records[0x3128 / 4];      // 0x1BAC .. 0x4CD4
    int field_4CD4;               // +0x4CD4 count

    int Get_4CED80(int index);
    int Get_4CEDC0(int index);
    int Set_5C1410(int value);
    int Get_5C1A00(int a2);
};
