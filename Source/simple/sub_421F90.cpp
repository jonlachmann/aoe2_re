#include "Function.hpp"

// sub_421F90 (VA 0x421F90) - member: stores the arg in global 0x65E3C0 and
// as a word at [field_24 + 0x8f8].
extern int g_65E3C0;
class S421F90 {
public:
    char pad_00[0x24];
    char* field_24;
    void M_421F90(int v);
};

MATCH_FUNC(0x421F90)
void S421F90::M_421F90(int v)
{
    g_65E3C0 = v;
    *(short*)(field_24 + 0x8f8) = v;
}
