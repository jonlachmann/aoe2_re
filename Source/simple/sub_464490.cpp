#include "Function.hpp"

// sub_464490 (VA 0x464490) - member: tail-calls the entry at field_100 in the
// two tables 0x10c/0x114, -1 when the index is invalid or the flag slot is 0.
class T463260 {
public:
    int Other_463260();
};
class S464490 {
public:
    char pad_00[0x100];
    int index_100;
    char pad_104[0x10c - 0x104];
    T463260** arr_10c;
    char pad_110[0x114 - 0x110];
    int* flags_114;
    int M_464490();
};

MATCH_FUNC(0x464490)
int S464490::M_464490()
{
    int i = index_100;
    if (i <= -1)
        return -1;
    if (flags_114[i] == 0)
        return -1;
    return arr_10c[i]->Other_463260();
}
