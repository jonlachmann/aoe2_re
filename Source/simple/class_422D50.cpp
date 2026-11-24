#include "Function.hpp"

// Family 0x422D*: three int arrays in one object:
//   +0x04 : 10 entries (indices 1..9 used by the setters/getters)
//   +0x2C : 10 entries (indices 1..9)
//   +0x54 : 51 entries (indices 0..0x32)
// Setters check i in [1,9]; getters check [0,9] / [0,0x32] and return 0 out of
// range.
class S422D50 {
public:
    char pad_00[4];
    int arr_04[10];           // +0x04
    int arr_2c[10];           // +0x2C
    int arr_54[51];           // +0x54

    void M_422D50(int i, int v);
    void M_422D90(int i, int v);
    int M_422D70(int i);
    int M_422DB0(int i);
    int M_422CE0(int i);
};

MATCH_FUNC(0x422D50)
void S422D50::M_422D50(int i, int v)
{
    if (i > 0 && i <= 9)
        arr_04[i] = v;
}

MATCH_FUNC(0x422D90)
void S422D50::M_422D90(int i, int v)
{
    if (i > 0 && i <= 9)
        arr_2c[i] = v;
}

MATCH_FUNC(0x422D70)
int S422D50::M_422D70(int i)
{
    if (i >= 0 && i <= 9)
        return arr_04[i];
    return 0;
}

MATCH_FUNC(0x422DB0)
int S422D50::M_422DB0(int i)
{
    if (i >= 0 && i <= 9)
        return arr_2c[i];
    return 0;
}

MATCH_FUNC(0x422CE0)
int S422D50::M_422CE0(int i)
{
    if (i >= 0 && i <= 0x32)
        return arr_54[i];
    return 0;
}
