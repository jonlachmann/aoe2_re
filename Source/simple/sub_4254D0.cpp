#include "Function.hpp"

// sub_4254D0 (VA 0x4254D0, 0x15 bytes) - member: field_1528 defaults to 1.
class S4254D0 {
public:
    void M_4254D0();
};

MATCH_FUNC(0x4254D0)
void S4254D0::M_4254D0()
{
    if (*(int*)((char*)this + 0x1528) == 0)
        *(int*)((char*)this + 0x1528) = 1;
}
