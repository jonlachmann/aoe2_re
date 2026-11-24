#include "Function.hpp"

// Family at 0x4A69F0/0x4A6A10: a linked list with its head at +4. Both walk the
// list; one reports the last node's +0x14 dword (default -1), the other the last
// node's +0x10 dword (default this+0x10).
class S4A69F0 {
public:
    char pad_00[4];
    char* list_4;             // +0x04
    char pad_08[0x10 - 0x08];
    int field_10;             // +0x10
    int field_14;             // +0x14

    int M_4A69F0();
    int M_4A6A10();
};

MATCH_FUNC(0x4A69F0)
int S4A69F0::M_4A69F0()
{
    int r = -1;
    char* p = list_4;
    while (p != 0) {
        r = *(int*)(p + 0x14);
        p = *(char**)(p + 4);
    }
    return r;
}

MATCH_FUNC(0x4A6A10)
int S4A69F0::M_4A6A10()
{
    char* p = list_4;
    int r = field_10;
    while (p != 0) {
        r = *(int*)(p + 0x10);
        p = *(char**)(p + 4);
    }
    return r;
}
