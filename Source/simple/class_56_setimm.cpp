#include "Function.hpp"

class S56SetImmBulk {
public:
    void Set_56CB50();
};

MATCH_FUNC(0x56CB50)
void S56SetImmBulk::Set_56CB50()
{
    *(int*)((char*)this + 0x0) = 0x629b70;
}
