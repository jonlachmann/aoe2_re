#include "Function.hpp"

class S5C1480 {
public:
    char pad_00[0x488c];
    void Init_5C1480();
};

MATCH_FUNC(0x5C1480)
void S5C1480::Init_5C1480()
{
    for (int i = 0; i < 0x100; ++i)
        ((int*)this)[(0x488c / 4) + i] = 3;
}
