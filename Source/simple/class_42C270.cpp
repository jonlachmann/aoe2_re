#include "Function.hpp"

class S42C270 {
public:
    char pad_00[0x13c0];
    void Clear_42C270();
};

MATCH_FUNC(0x42C270)
void S42C270::Clear_42C270()
{
    for (int i = 0; i < 9; ++i)
        ((int*)this)[(0x13c0 / 4) + i] = 0;
}
