#include "C_tpnl_btn.hpp"

extern int (__stdcall *g_61C3C8)();

// 0x5A6680 — periodic button update: bail unless both +0x5FC and +0x5FE are
// set, compare the elapsed timestamp against +0x60C, roll the +0x608 counter
// into +0x2F0 (resetting everything once it reaches 20), notify the button
// through slot +0x20 with 2, then store the new timestamp in +0x610.
MATCH_FUNC(0x5A6680)
int C_tpnl_btn::M_5A6680()
{
    if (field_5fc == 0)
        return 0;
    if (field_5fe == 0)
        return 0;
    int (__stdcall *now)() = g_61C3C8;
    if ((unsigned int)(now() - field_610) <= field_60c)
        return 0;
    field_2f0 = field_600 + field_608;
    field_608++;
    if (field_608 >= 0x14)
    {
        field_608 = 0;
        field_5fe = 0;
        field_2f0 = field_600;
    }
    slot_008(2);
    field_610 = now();
    return 0;
}
