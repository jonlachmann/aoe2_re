#include "Function.hpp"

// sub_4D3C10 (VA 0x4D3C10) - member: clears field_c7c then tail-calls
// Sub_4A2280 on this.
class S4D3C10 {
public:
    char pad_00[0xc7c];
    int field_c7c;
    void M_4D3C10();
    void Sub_4A2280();
};

