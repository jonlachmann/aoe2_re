#include "Function.hpp"

class S56GetBulk {
public:
    char* Get_56F2D0();
};

MATCH_FUNC(0x56F2D0)
char* S56GetBulk::Get_56F2D0()
{
    return (char*)this + 0xf8;
}
