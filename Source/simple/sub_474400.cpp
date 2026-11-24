#include "Function.hpp"

// sub_474400 (VA 0x474400) - member getter: dword id of the object at +0xf8,
// bounded by its signed word count at +8; 0 for id -1 or out of range.
class S474400 {
public:
    char pad_00[0xf8];
    char* field_f8;
    int M_474400(short id);
};

MATCH_FUNC(0x474400)
int S474400::M_474400(short id)
{
    if (id != -1 && id < *(short*)(field_f8 + 8))
        return (*(int**)(field_f8 + 4))[id];
    return 0;
}
