#include "Function.hpp"

// sub_465900 (VA 0x465900, 16 bytes) - member: zero four dwords at +0..+0xC
// (a small object's clear/ctor). No calls.
class S465900 {
public:
    int a_0;
    int b_4;
    int c_8;
    int d_C;
    S465900* M_465900();
};

MATCH_FUNC(0x465900)
S465900* S465900::M_465900()
{
    S465900* p = this;
    int z = 0;
    p->a_0 = z;
    p->b_4 = z;
    p->c_8 = z;
    p->d_C = z;
    return p;
}
