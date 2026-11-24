#include "Function.hpp"

class S4308C0 {
public:
    char pad_00[0x3860];
    void Clear_4308C0();
};

MATCH_FUNC(0x4308C0)
void S4308C0::Clear_4308C0()
{
    for (int i = 0; i < 8; ++i)
        ((unsigned char*)this)[0x3860 + i * 0x20c] = 0;
}
