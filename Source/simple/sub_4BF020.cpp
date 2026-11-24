#include "Function.hpp"

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime();

class S4BF020 {
public:
    char pad_00[0x2a4];
    unsigned long field_2a4;
    int Elapsed_4BF020();
};

MATCH_FUNC(0x4BF020)
int S4BF020::Elapsed_4BF020()
{
    return timeGetTime() - field_2a4;
}
