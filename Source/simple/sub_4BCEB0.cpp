#include "Function.hpp"

// sub_4BCEB0 (VA 0x4BCEB0) - member: stores the word arg at +0x104, then
// calls Other_4BBD30(1) on this.
class S4BCEB0 {
public:
    char pad_00[0x104];
    short field_104;
    int Other_4BBD30(int v);
    void M_4BCEB0(short v);
};

MATCH_FUNC(0x4BCEB0)
void S4BCEB0::M_4BCEB0(short v)
{
    field_104 = v;
    Other_4BBD30(1);
}
