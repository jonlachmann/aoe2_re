#include "Function.hpp"

// sub_4238D0 (VA 0x4238D0) - member: pointer to entry index (160-byte stride)
// of the table based at +0x220; out of range/null returns global 0x64DB20.
extern char g_64DB20;
class S4238D0 {
public:
    char pad_00[0x218];
    unsigned int count_218;
    char pad_21c[0x220 - 0x21c];
    char* base_220;
    char* M_4238D0(int i);
};

WIP_FUNC(0x4238D0)
char* S4238D0::M_4238D0(int i)
{
    char* p = base_220 + i * 160;
    if (p == 0 || (unsigned)i > count_218)
        return (char*)&g_64DB20;
    return p;
}
