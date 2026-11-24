#include "Function.hpp"

// sub_4BD400 (VA 0x4BD400) - member: index of the +0xf8 list node whose +8
// dword equals the arg (following +0x24), or -1.
class S4BD400 {
public:
    char pad_00[0xf8];
    char* list_f8;
    int M_4BD400(int v);
};

MATCH_FUNC(0x4BD400)
int S4BD400::M_4BD400(int v)
{
    char* n = list_f8;
    int i = 0;
    while (n != 0) {
        if (*(int*)(n + 8) == v)
            return i;
        n = *(char**)(n + 0x24);
        i++;
    }
    return -1;
}
