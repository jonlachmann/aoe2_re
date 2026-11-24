#include "Function.hpp"

class S59A3B0 {
public:
    int Wrap_59A3B0(int value);
};

MATCH_FUNC(0x59A3B0)
int S59A3B0::Wrap_59A3B0(int value)
{
    value += 2;
    if (value >= 4)
        value -= 4;
    return value;
}
