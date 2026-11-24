#include "Function.hpp"

class S4118C0 {
public:
    char pad_00[0xc];
    int array_c[(0x6c - 0xc) / 4];
    int count_6c;
    int Get_4118C0(int index);
};

MATCH_FUNC(0x4118C0)
int S4118C0::Get_4118C0(int index)
{
    if (index < 0 || index >= count_6c)
        return -1;
    return array_c[index];
}
