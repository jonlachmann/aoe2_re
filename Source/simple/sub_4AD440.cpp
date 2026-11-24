#include "Function.hpp"

// sub_4AD440 (VA 0x4AD440, 0xD bytes) - member: byte at
// ((char*)field_D4)[index].
class S4AD440 {
public:
    char M_4AD440(int index);
};

MATCH_FUNC(0x4AD440)
char S4AD440::M_4AD440(int index)
{
    char* base = *(char**)((char*)this + 0xd4);
    return base[index];
}
