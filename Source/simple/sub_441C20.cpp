#include "Function.hpp"

MATCH_FUNC(0x441C20)
void Fill_441C20(int* dest, int value, unsigned int count)
{
    if (count != 0) {
        for (; count != 0; --count)
            *dest++ = value;
    }
}
