#include "Function.hpp"

// sub_423810 (VA 0x423810) - member: fills 0x80 bytes at +0x194 (stdcall
// helper 0x6087EC) and returns that buffer pointer.
extern "C" void __stdcall sub_6087EC(char* buf, int len);
class S423810 {
public:
    char* M_423810();
};

MATCH_FUNC(0x423810)
char* S423810::M_423810()
{
    char* p = (char*)this + 0x194;
    sub_6087EC(p, 0x80);
    return p;
}
