#include "Function.hpp"

// sub_529B40 (VA 0x529B40) - member: two-hop pointer: field_c -> +0x8c object,
// called with the arg.
class T5EA420 {
public:
    void Other_5EA420(int v);
};
class S529B40 {
public:
    char pad_00[0xc];
    char* field_c;
    void M_529B40(int v);
};

MATCH_FUNC(0x529B40)
void S529B40::M_529B40(int v)
{
    ((T5EA420*)*(char**)(field_c + 0x8c))->Other_5EA420(v);
}
