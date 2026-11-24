#include "Function.hpp"

class S5A67B0 {
public:
    char pad_00[0x600];
    int field_600;
    char pad_604[0x620 - 0x604];
    int field_620;
    void Set_5A67B0(int v);
};

MATCH_FUNC(0x5A67B0)
void S5A67B0::Set_5A67B0(int v)
{
    if (v < 0)
        v = field_600;
    field_620 = v;
}
