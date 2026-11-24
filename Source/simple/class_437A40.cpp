#include "Function.hpp"

// Family 0x437A40/0x437AA0: a table of 96-byte entries from +0x50 with two dword
// fields (entry+0 -> +0x50, entry+0xC -> +0x5C). Bounded by field_2580.
struct E437A40 {
    int field_0;
    char pad_04[0xc - 0x04];
    int field_c;
    char pad_10[0x60 - 0x10];
};
class S437A40 {
public:
    char pad_00[0x50];
    E437A40 entries[1];
    char pad_b0[0x2580 - 0xb0];
    int field_2580;

    void M_437A40(int i, int v);
    void M_437AA0(int i, int v);
};

MATCH_FUNC(0x437A40)
void S437A40::M_437A40(int i, int v)
{
    if (i >= 0 && i <= field_2580)
        entries[i].field_0 = v;
}

MATCH_FUNC(0x437AA0)
void S437A40::M_437AA0(int i, int v)
{
    if (i >= 0 && i <= field_2580)
        entries[i].field_c = v;
}
