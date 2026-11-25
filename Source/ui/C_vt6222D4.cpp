#include "C_vt6222D4.hpp"

#pragma intrinsic(memset)

// The global object at 0x66FA50 is a C_vt6222D4 instance (0x4A8240 writes its
// vtable pointer 0x6222D4 and its own fields). 0x4A76E0 constructs it with five
// constant arguments.
MATCH_FUNC(0x4A76E0)
void sub_4A76E0()
{
    ((C_vt6222D4*)0x66fa50)->Hook_4A8240(0xff, 0xff, 0, 0, 0);
}

MATCH_FUNC(0x4A8310)
void C_vt6222D4::SetVt_4A8310()
{
    vtbl_00 = 0x6222d4;
}

// 0x4A8320 — initializer: store the passed extent/step pair, derive +4/+8 from
// the optional subobject (a3), then clear the three regions and set the tail.
MATCH_FUNC(0x4A8320)
bool C_vt6222D4::M_4A8320(int a1, int a2, int a3, int a4)
{
    field_0c = a3;
    field_10 = a4;

    int value;
    if (a3)
    {
        field_04 = *(int*)(a3 + 8);
        value = *(int*)(a3 + 0xc);
        field_08 = value;
    }
    else
    {
        int head = a1;
        value = a2;
        field_04 = head;
        field_08 = value;
    }

    memset(region_14, 0xff, 0xfe01);
    memset(region_fe18, 0xff, 0x3f804);
    memset(region_4f61c, 0xff, 0x7f010);

    field_ce62c = 0;
    field_ce630 = 0;
    field_ce634 = 0xf0;
    field_ce638 = 0;
    return true;
}
