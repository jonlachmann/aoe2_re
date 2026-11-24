#include "Function.hpp"

// Family at 0x48F470/0x48F520: float getters off the object at +0x110, with the
// global constant float 0x61C584 as the null fallback.
extern float g_61C584;
class S48F470 {
public:
    char pad_00[0x110];
    char* field_110;          // +0x110

    float M_48F470();
    float M_48F520();
};

