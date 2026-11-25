// C_cluster_4AF360 — ui cluster anchored at 0x4AF360. This TU carries the
// byte-verified two-table setter (0x4AF4D0): int table +0x158, short table
// +0x17C, and the shared self-refresh slot +0x20.
#pragma once

#include "Function.hpp"

class C_cluster_4AF360 {
public:
    virtual void slot_00();
    virtual void slot_01();
    virtual void slot_02();
    virtual void slot_03();
    virtual void slot_04();
    virtual void slot_05();
    virtual void slot_06();
    virtual void slot_07();
    virtual void Vt_20(int v);

    char pad_04[0x158 - 4];
    int array_158[9];             // +0x158, int values
    short array_17c[32];          // +0x17C, short flags

    void M_4AF4D0(short index, int value, short flag);
};
