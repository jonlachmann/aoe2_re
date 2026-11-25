// C_cluster_5200F0 — this-edge cluster; scattered state reset.
#pragma once

#include "Function.hpp"

class C_cluster_5200F0 {
public:
    char pad_00[4];
    unsigned char flag_04;        // +4
    unsigned char flag_05;        // +5
    char pad_06[8 - 6];
    int field_08;                 // +8
    int field_0C;                 // +12
    int field_10;                 // +16
    int field_14;                 // +20
    int field_18;                 // +24
    int field_1C;                 // +28
    unsigned char flag_20;        // +32
    char pad_21[292 - 33];
    int field_124;                // +292
    int field_128;                // +296
    char pad_12C[1948 - 300];
    int field_79C;                // +1948

    void Hook_520170(int a1, int a2);   // unresolved callee at 0x520170
    int Reset_520130();
    C_cluster_5200F0* M_5200F0(int a1, int a2);
};
