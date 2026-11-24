#include "Function.hpp"

// sub_432040 (VA 0x432040, 0x14 bytes) - member: 0 when field_10e8 is set,
// otherwise field_10e4.
class S432040 {
public:
    int M_432040();
};

MATCH_FUNC(0x432040)
int S432040::M_432040()
{
    if (*(int*)((char*)this + 0x10e8) != 0)
        return 0;
    return *(int*)((char*)this + 0x10e4);
}
