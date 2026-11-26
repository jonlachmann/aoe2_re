#include "C_vt6222D4.hpp"
#include "matched_mem.h"

#pragma intrinsic(memset)

// The global object at 0x66FA50 is a C_vt6222D4 instance (0x4A8240 writes its
// vtable pointer 0x6222D4 and its own fields). 0x4A76E0 constructs it with five
// constant arguments.
MATCH_FUNC(0x4A76E0)
void sub_4A76E0()
{
    ((C_vt6222D4*)0x66fa50)->Hook_4A8240(0xff, 0xff, 0, 0, 0);
}

// 0x4A8240 — five-argument constructor. It stores a3 at +0xCE848, writes the
// vtable pointer and the -1/0 field block, runs the 0x4A8320 initializer with
// (a1,a2,a4,a5), seeds the +0xCE83C/-840/-844 sentinels and fills the
// 0x66F64C..0x66FA4C 256-entry table with the scaled float sequence.
// WIP: ours 160 vs 161. The body is semantically complete; the only miss is
// register allocation in the scalar loop (VC6 assigns the counter to ebx/ecx
// instead of the original edx, and moves the table-pointer init one statement
// early). Four source variants did not recover the original allocation.
WIP_FUNC(0x4A8240)
C_vt6222D4* C_vt6222D4::Hook_4A8240(int a1, int a2, int a3, int a4, int a5)
{
    field_ce848 = a3;
    vtbl_00 = 0x6222d4;
    field_04 = -1;
    field_08 = -1;
    field_ce62c = 0;
    field_ce630 = 0;
    field_0c = 0;
    field_10 = 0;
    this->M_4A8320(a1, a2, a4, a5);
    field_ce83c = -1;
    field_ce840 = -1;
    field_ce844 = -1;
    int* dst = (int*)ADDR(0x66f64c);
    for (int i = 0; i < 0x100; i++)
    {
        *dst = (int)((float)i * *(float*)ADDR(0x6222d0)
            * *(float*)ADDR(0x6201ec) + *(float*)ADDR(0x61c588));
        dst++;
    }
    return this;
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
