#include "Function.hpp"

// sub_411AF0 (VA 0x411AF0) - member: writes -1 into entry (b + 10*a) of an
// int table that starts one entry before +0x00 (-0x28 bytes).
class S411AF0 {
public:
    void M_411AF0(int a, int b);
};

MATCH_FUNC(0x411AF0)
void S411AF0::M_411AF0(int a, int b)
{
    int idx = b + a * 10;
    *(int*)((char*)this + idx * 4 - 0x28) = -1;
}
