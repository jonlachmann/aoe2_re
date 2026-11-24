#include "Function.hpp"

// sub_465BB0 (VA 0x465BB0) - member: index of the first 0x48-stride entry at
// +0xc whose +0 dword equals the arg; -1 when the count at +4 is <= 0 or none.
struct E465BB0 {
    int field_0;
    char pad_04[0x48 - 0x04];
};
class S465BB0 {
public:
    char pad_00[4];
    int count_4;
    char pad_08[0xc - 0x08];
    E465BB0* arr_c;
    int M_465BB0(int v);
};

MATCH_FUNC(0x465BB0)
int S465BB0::M_465BB0(int v)
{
    for (int i = 0; i < count_4; i++)
        if (arr_c[i].field_0 == v)
            return i;
    return -1;
}
