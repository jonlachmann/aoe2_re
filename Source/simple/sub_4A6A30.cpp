#include "Function.hpp"

// sub_4A6A30 (VA 0x4A6A30) - member: last node of the +4 list (0 when empty).
// The object is itself the list's head node, so the walk starts at `this`.
class S4A6A30 {
public:
    char pad_00[4];
    S4A6A30* list_4;
    S4A6A30* M_4A6A30();
};

MATCH_FUNC(0x4A6A30)
S4A6A30* S4A6A30::M_4A6A30()
{
    S4A6A30* p = this;
    if (!p->list_4)
        return 0;
    while (p->list_4)
        p = p->list_4;
    return p;
}
