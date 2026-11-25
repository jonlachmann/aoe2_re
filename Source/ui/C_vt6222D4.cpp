#include "C_vt6222D4.hpp"

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
    *(int*)((char*)this + 0x0) = 0x6222d4;
}
