#include "Function.hpp"

class S51GetBulk {
public:
    unsigned char Get_514400();
};

MATCH_FUNC(0x514400)
unsigned char S51GetBulk::Get_514400()
{
    return *(unsigned char*)((char*)this + 0x900);
}
