#include "Function.hpp"

class S52SetImmBulk {
public:
    void Set_520500();
    void Set_52C120();
};

MATCH_FUNC(0x520500)
void S52SetImmBulk::Set_520500()
{
    *(int*)((char*)this + 0x79c) = 0x0;
}

MATCH_FUNC(0x52C120)
void S52SetImmBulk::Set_52C120()
{
    *(int*)((char*)this + 0x60) = 0x0;
}
