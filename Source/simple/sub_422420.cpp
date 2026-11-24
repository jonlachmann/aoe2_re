#include "Function.hpp"

class S422420Global {
public:
    void Mark_4A00B0();
};

class S422420 {
public:
    char pad_00[0x420];
    int field_420;
    void Mark_422420();
};

MATCH_FUNC(0x422420)
void S422420::Mark_422420()
{
    field_420 = 1;
    ((S422420Global*)0x66ea48)->Mark_4A00B0();
}
