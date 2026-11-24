#include "Function.hpp"

class S4CE4C0 {
public:
    char pad_00[0x13dc];
    unsigned char array_13dc[0x40];
    void Set_4CE4C0(int index, unsigned char v);
};

MATCH_FUNC(0x4CE4C0)
void S4CE4C0::Set_4CE4C0(int index, unsigned char v)
{
    array_13dc[index] = v;
}
