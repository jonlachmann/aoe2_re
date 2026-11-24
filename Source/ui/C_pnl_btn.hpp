// C_pnl_btn — recovered panel-button class (skeleton: Source/skeleton/ui/
// C_pnl_btn_<vtable>.h). This TU carries the 3 byte-verified methods. Only the
// virtual slot used by 0x4AF8D0 (+0x20) is declared; fields start at +4.
#pragma once

#include "Function.hpp"

class C_pnl_btn {
public:
    virtual void slot_00();
    virtual void slot_01();
    virtual void slot_02();
    virtual void slot_03();
    virtual void slot_04();
    virtual void slot_05();
    virtual void slot_06();
    virtual void slot_07();
    virtual void Vat_20(int v);

    char pad_04[0x154 - 4];
    int field_154;                // +0x154
    char pad_158[0x202 - 0x158];
    short field_202;              // +0x202

    void M_4AF8D0(short v);
    void M_4B0EE0();
    int M_5C6880(int a, int b, int c, int d);
};
