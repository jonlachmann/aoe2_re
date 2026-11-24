#include "Function.hpp"

// sub_40E270 (VA 0x40E270) - member: element index of the pointer array at
// +8, bounded by the signed word count at +6; out of range returns the global
// object 0x662BE4.
extern char g_662BE4;
class S40E270 {
public:
    char pad_00[6];
    short count_6;
    char** items_8;
    char* M_40E270(int index);
};

MATCH_FUNC(0x40E270)
char* S40E270::M_40E270(int index)
{
    if (index < 0 || index >= count_6)
        return (char*)&g_662BE4;
    return items_8[index];
}
