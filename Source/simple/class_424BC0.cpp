#include "Function.hpp"

class S424BC0 {
public:
    int field_0;
    int field_4;
    S424BC0* Init_424BC0(int v);
};

MATCH_FUNC(0x424BC0)
S424BC0* S424BC0::Init_424BC0(int v)
{
    field_0 = v;
    field_4 = 0;
    return this;
}

class S4260C0 {
public:
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    S4260C0* Clear_4260C0();
};

MATCH_FUNC(0x4260C0)
S4260C0* S4260C0::Clear_4260C0()
{
    field_0 = 0;
    field_4 = 0;
    field_8 = 0;
    field_c = 0;
    field_10 = 0;
    return this;
}

class S5B08F0 {
public:
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    S5B08F0* Fill_5B08F0();
};

MATCH_FUNC(0x5B08F0)
S5B08F0* S5B08F0::Fill_5B08F0()
{
    field_0 = -1;
    field_4 = -1;
    field_8 = -1;
    field_c = -1;
    field_10 = -1;
    return this;
}
