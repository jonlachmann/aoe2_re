#include "Function.hpp"

// sub_42C290 (VA 0x42C290, 0x10 bytes) - member: field_12d4 <- result of the
// method at 0x42D0D0 (called on this).
class S42C290 {
public:
    int Method_42D0D0();
    char pad_00[0x12d4];
    int field_12d4;           // +0x12d4

    void M_42C290();
};

MATCH_FUNC(0x42C290)
void S42C290::M_42C290()
{
    field_12d4 = Method_42D0D0();
}
