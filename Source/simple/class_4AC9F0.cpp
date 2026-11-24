#include "Function.hpp"

class S4AC9Sub {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3(int v);
};

class S4AC9F0 {
public:
    char pad_00[0x84];
    S4AC9Sub* field_84;
    void Call_4AC9F0(int v);
};

MATCH_FUNC(0x4AC9F0)
void S4AC9F0::Call_4AC9F0(int v)
{
    field_84->V3(v);
}
