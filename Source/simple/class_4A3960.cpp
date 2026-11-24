#include "Function.hpp"

class S4A3960 {
public:
    char pad_00[0x330];
    int field_330;
    int field_334;
    int field_338;
    int field_33c;
    int field_340;
    int field_344;
    int field_348;
    int field_34c;
    void Set_4A3960(int a, int b);
    void Set_4A3980(int a, int b);
    void Set_4A39A0(int a, int b);
    void Set_4A39C0(int a, int b);
};

MATCH_FUNC(0x4A3960)
void S4A3960::Set_4A3960(int a, int b)
{
    field_330 = a;
    field_334 = b;
}

MATCH_FUNC(0x4A3980)
void S4A3960::Set_4A3980(int a, int b)
{
    field_338 = a;
    field_33c = b;
}

MATCH_FUNC(0x4A39A0)
void S4A3960::Set_4A39A0(int a, int b)
{
    field_340 = a;
    field_344 = b;
}

MATCH_FUNC(0x4A39C0)
void S4A3960::Set_4A39C0(int a, int b)
{
    field_348 = a;
    field_34c = b;
}
