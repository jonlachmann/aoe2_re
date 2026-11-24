#include "Function.hpp"

// Family 0x456790/0x4567C0: two arrays of 96 dwords at +0x908 and +0xb60. Each
// method finds the first slot that is <= 0 and writes the arg there.
class S456790 {
public:
    char pad_00[0x908];
    int arr_908[96];          // +0x908
    char pad_a88[0xb60 - 0xa88];
    int arr_b60[96];          // +0xb60

    void M_456790(int v);
    void M_4567C0(int v);
};

MATCH_FUNC(0x456790)
void S456790::M_456790(int v)
{
    for (int i = 0; i < 0x96; i++)
        if (arr_b60[i] <= 0) {
            arr_b60[i] = v;
            return;
        }
}

MATCH_FUNC(0x4567C0)
void S456790::M_4567C0(int v)
{
    for (int i = 0; i < 0x96; i++)
        if (arr_908[i] <= 0) {
            arr_908[i] = v;
            return;
        }
}
