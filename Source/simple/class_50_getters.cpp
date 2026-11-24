#include "Function.hpp"

class S50GetBulk {
public:
    int Get_501950();
};

MATCH_FUNC(0x501950)
int S50GetBulk::Get_501950()
{
    return *(int*)((char*)this + 0xafc);
}
