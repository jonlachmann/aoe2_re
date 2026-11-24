#include "Function.hpp"

// The 0x560660 trio (VA 0x560660/680/6A0, 20 bytes each): compare a word at
// +0x16 of the pointer held at the argument's +8 against three type markers,
// returning int 1/0. The arg arrives on the stack (stdcall, ret 4).
struct S5606 {
    char pad_00[8];
    char* field_8;
};
MATCH_FUNC(0x560660)
int __stdcall sub_560660(int* p)
{
    char* q = ((S5606*)p)->field_8;
    return *(unsigned short*)(q + 0x16) == 0x1B;
}

MATCH_FUNC(0x560680)
int __stdcall sub_560680(int* p)
{
    char* q = ((S5606*)p)->field_8;
    return *(unsigned short*)(q + 0x16) == 0x27;
}

MATCH_FUNC(0x5606A0)
int __stdcall sub_5606A0(int* p)
{
    char* q = ((S5606*)p)->field_8;
    return *(unsigned short*)(q + 0x16) == 4;
}
