#include "Function.hpp"

// sub_4B4550 (VA 0x4B4550, 0x14 bytes) - member: forward the +0x164 handle to
// ImmGetOpenStatus; a null handle gives 0.
extern "C" int __stdcall ImmGetOpenStatus(void*);

class S4B4550 {
public:
    char pad_00[0x164];
    void* handle_164;
    int M_4B4550();
};

