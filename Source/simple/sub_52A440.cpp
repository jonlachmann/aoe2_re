#include "Function.hpp"

// sub_52A440 (VA 0x52A440, 20 bytes) - member: forwards the arg to the pointer
// at +0x18 (sub_41A820). Null does nothing.
class S52A440;
class T41A820 {
public:
    void Other_41A820(int v);
};
class S52A440 {
public:
    char pad_00[0x18];
    void* field_18;
    void M_52A440(int v);
};

