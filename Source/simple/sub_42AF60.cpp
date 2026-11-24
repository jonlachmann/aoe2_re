#include "Function.hpp"

// sub_42AF60 (VA 0x42AF60) - member: zeroes slot[arg] in each of the 0x1f6
// 0x38-byte rows of the table at +0x1dd8.
struct S42AF60Row {
    char pad_00[0x10];
    int slot_10[(0x38 - 0x10) / 4];
};

class S42AF60 {
public:
    char pad_00[0x1dd8];
    S42AF60Row* rows_1dd8;
    void M_42AF60(int arg);
};

