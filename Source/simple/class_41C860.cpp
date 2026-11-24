#include "Function.hpp"

// Family at 0x41C860: a table of 32-byte entries starting at +0x554. The
// three dword getters and the setter all index the same entry array:
//   entry+0x00 -> this+0x554 (M_41C8C0)
//   entry+0x04 -> this+0x558 (M_41C880)
//   entry+0x14 -> this+0x568 (M_41C8A0, written by M_41C860)
struct Entry32_554 {
    int field_0;              // +0x00
    int field_4;              // +0x04
    char pad_08[0x14 - 0x08];
    int field_14;             // +0x14
    char pad_18[0x20 - 0x18];
};

class S41C860 {
public:
    char pad_00[0x554];
    Entry32_554 entries[1];   // +0x554

    int M_41C8C0(int index);
    int M_41C880(int index);
    int M_41C8A0(int index);
    void M_41C860(int index, int value);
};

MATCH_FUNC(0x41C8C0)
int S41C860::M_41C8C0(int index)
{
    return entries[index].field_0;
}

MATCH_FUNC(0x41C880)
int S41C860::M_41C880(int index)
{
    return entries[index].field_4;
}

MATCH_FUNC(0x41C8A0)
int S41C860::M_41C8A0(int index)
{
    return entries[index].field_14;
}

MATCH_FUNC(0x41C860)
void S41C860::M_41C860(int index, int value)
{
    entries[index].field_14 = value;
}
