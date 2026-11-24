#include "Function.hpp"

// sub_416D20 (VA 0x416D20) - member: when field_34 is not -1, snapshots
// 34/38 into 58/5c, resets 34/38 to -1 and the three floats at 3c/40/44 to -1.0.
class S416D20 {
public:
    char pad_00[0x34];
    int field_34;
    int field_38;
    float field_3c;
    float field_40;
    float field_44;
    char pad_48[0x58 - 0x48];
    int field_58;
    int field_5c;
    void M_416D20();
};

MATCH_FUNC(0x416D20)
void S416D20::M_416D20()
{
    if (field_34 == -1)
        return;
    field_58 = field_34;
    field_5c = field_38;
    field_34 = -1;
    field_38 = -1;
    field_3c = -1.0f;
    field_40 = -1.0f;
    field_44 = -1.0f;
}
