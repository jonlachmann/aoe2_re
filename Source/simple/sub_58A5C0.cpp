#include "Function.hpp"

// sub_58A5C0 (VA 0x58A5C0, 0x11 bytes) - stdcall: whether the word at p+6 is 7.
class S58A5C0 {
public:
    bool M_58A5C0(int x);
};

MATCH_FUNC(0x58A5C0)
extern "C" bool __stdcall sub_58A5C0(char* p)
{
    return *(short*)(p + 6) == 7;
}
