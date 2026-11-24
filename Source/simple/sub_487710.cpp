#include "Function.hpp"

// sub_487710 (VA 0x487710) - member: appends node at the tail of the +4 list.
// The object is itself the head node: the walk starts at `this`, and the
// empty-list store `[ecx+4]` is the same `p->next = node` with p == this.
class S487710 {
public:
    char pad_00[4];
    S487710* field_4;
    void Append_487710(S487710* node);
};

MATCH_FUNC(0x487710)
void S487710::Append_487710(S487710* node)
{
    S487710* p = this;
    while (p->field_4)
        p = p->field_4;
    p->field_4 = node;
}
