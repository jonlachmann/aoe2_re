#include "Function.hpp"

// Family at 0x464FD0/0x464FF0: one accessor class over an object array. field_0
// is the index, +8 is the array of object pointers; the two methods differ only
// in the null (negative-index) result and the tail-called virtual.
class T43FAB0 {
public:
    char* Other_43FAB0();
};
class T464290 {
public:
    int Other_464290();
};

class S464FD0 {
public:
    int index_0;              // +0x00
    char pad_04[0x08 - 0x04];
    char** items_8;           // +0x08

    char* M_464FD0();
    int M_464FF0();
};

MATCH_FUNC(0x464FD0)
char* S464FD0::M_464FD0()
{
    if (index_0 < 0)
        return 0;
    return ((T43FAB0*)items_8[index_0])->Other_43FAB0();
}

MATCH_FUNC(0x464FF0)
int S464FD0::M_464FF0()
{
    if (index_0 < 0)
        return -1;
    return ((T464290*)items_8[index_0])->Other_464290();
}
