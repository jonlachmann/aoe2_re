#include "Function.hpp"

// sub_4A6A90 (VA 0x4A6A90) - member: walks the +4 list to its tail, then when
// the arg is 1 decrements field_2c.
class S4A6A90 {
public:
    char pad_00[4];
    char* list_4;
    char pad_08[0x2c - 0x08];
    int field_2c;
    void M_4A6A90(int v);
};

WIP_FUNC(0x4A6A90)
void S4A6A90::M_4A6A90(int v)
{
    char* p = list_4;
    while (p != 0)
        p = *(char**)(p + 4);
    int vv = v;
    int old = field_2c;
    if (vv == 1)
        field_2c = old - 1;
}