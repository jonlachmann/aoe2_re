// C_global_66451C — global-object class anchored at 0x66451C (skeleton:
// Source/skeleton/game/C_global_66451C_66451C.h).
// This TU carries the 3 byte-verified methods. Only the +0x2008 getter field
// and the +0x267C table are reconstructed; the 0x4308C0 clear loop uses raw
// offsets beyond that table.
#pragma once

#include "Function.hpp"

class C_global_66451C {
public:
    char pad_00[0x2008];
    int field_2008;               // +0x2008
    char pad_200C[0x267C - 0x200C];
    int array_267C[0x40];         // +0x267C

    int Get_42FBC0();
    void Clear_4308C0();
    void Set_432B30(int index, int v);
};
