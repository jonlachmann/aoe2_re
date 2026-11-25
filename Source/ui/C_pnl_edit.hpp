// C_pnl_edit — recovered panel-edit class (skeleton: Source/skeleton/ui/
// C_pnl_edit_622934.h). This TU carries the single byte-verified empty body
// (0x4378C0); the original is a plain entry point, so it stays static.
#pragma once

#include "Function.hpp"

class C_pnl_edit {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot02_4A0750(int a1, int a2, int a3, int a4);

    char pad_04[0x6c - 4];
    int field_6c;                 // +0x6C
    char pad_70[0xf8 - 0x70];
    void* field_f8;               // +0xF8
    char pad_fc[0x108 - 0xfc];
    int field_108;                // +0x108

    void Hook_4A07A0(int a1);     // unresolved shared slot body at 0x4A07A0
    static void M_4378C0();
    void M_5ED9F4();
    void M_5ED9FA();
    void M_4B32F0(int a1);
};
