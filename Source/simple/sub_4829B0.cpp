#include "Function.hpp"

// sub_4829B0 (VA 0x4829B0) - stdcall: pushes node's +0x18 onto b's front,
// stores b as the new +0x18 head, and increments +0x28.
struct S4829B0 {
    char pad_00[0x18];
    void* field_18;
    char pad_1C[0x28 - 0x1C];
    int field_28;
};
MATCH_FUNC(0x4829B0)
extern "C" void __stdcall sub_4829B0(S4829B0* node, void** head)
{
    *head = node->field_18;
    node->field_18 = head;
    node->field_28++;
}
