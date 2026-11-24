#include "Function.hpp"

// Family at 0x41CE50: three forwards on the pointer field at +0x1c. Null gives
// -1 (M_41CE50) or 0 (M_41CE60); the arg-taking variant just forwards.
class T5BFBF0 {
public:
    int Other_5BFBF0();
};
class T464FD0 {
public:
    int Other_464FD0();
};
class T464D90 {
public:
    void Other_464D90(int v);
};

class S41CE50 {
public:
    char pad_00[0x1c - 0x00];
    char* field_1c;           // +0x1c

    int M_41CE50();
    int M_41CE60();
    void M_41CE70(int v);
};

MATCH_FUNC(0x41CE50)
int S41CE50::M_41CE50()
{
    if (field_1c == 0)
        return -1;
    return ((T5BFBF0*)field_1c)->Other_5BFBF0();
}

MATCH_FUNC(0x41CE60)
int S41CE50::M_41CE60()
{
    if (field_1c == 0)
        return 0;
    return ((T464FD0*)field_1c)->Other_464FD0();
}

MATCH_FUNC(0x41CE70)
void S41CE50::M_41CE70(int v)
{
    if (field_1c != 0)
        ((T464D90*)field_1c)->Other_464D90(v);
}
