// C_global_66451C — global-object class anchored at 0x66451C (skeleton:
// Source/skeleton/game/C_global_66451C_66451C.h).
// This TU carries the 3 byte-verified methods. Only the +0x2008 getter field
// and the +0x267C table are reconstructed; the 0x4308C0 clear loop uses raw
// offsets beyond that table.
#pragma once

#include "Function.hpp"

class C_global_66451C {
public:
    char pad_00[0x17e4];
    int field_17e4;               // +0x17E4
    char pad_17e8[0x17f8 - 0x17e8];
    int field_17f8;               // +0x17F8
    char pad_17fc[0x1a50 - 0x17fc];
    int field_1a50;               // +0x1A50
    char pad_1a54[0x1a64 - 0x1a54];
    int array_1a64[10];           // +0x1A64
    char pad_1a8c[0x1adc - 0x1a8c];
    int array_1adc[10];           // +0x1ADC
    int array_1b04[10];           // +0x1B04
    char pad_1b2c[0x1b7c - 0x1b2c];
    int field_1b7c;               // +0x1B7C
    int array_1b80[10];           // +0x1B80
    char pad_1ba8[0x1bac - 0x1ba8];
    int field_1bac;               // +0x1BAC
    char pad_1bb0[0x1bb4 - 0x1bb0];
    int field_1bb4;               // +0x1BB4
    int field_1bb8;               // +0x1BB8
    char pad_1bbc[0x2008 - 0x1bbc];
    int field_2008;               // +0x2008
    char pad_200C[0x267C - 0x200C];
    int array_267C[0x40];         // +0x267C

    void Hook_4308C0();           // resolved sibling body at 0x4308C0
    int Get_42FBC0();
    void Clear_4308C0();
    void Set_432B30(int index, int v);
    void Init_42FD20();
    void Init_42FD60();
};
