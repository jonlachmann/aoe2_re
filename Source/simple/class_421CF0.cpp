#include "Function.hpp"

class S421CF0 {
public:
    char pad_00[0x9c9];
    unsigned char field_9c9;
    unsigned char field_9ca;
    char gap_9cb[0x9cc - 0x9cb];
    int field_9cc;
    char pad_9d0[0x108c - 0x9d0];
    int field_108c;

    void SetC9_421CF0();
    void SetCA_421D00();
    float Get108C_421D10();
    float Get9CC_421D20();
    void ClearC9_421D30();
    void ClearCA_421D40();
    unsigned char GetC9_421D50();
    unsigned char GetCA_421D60();
    void Set9CC_421CD0(int v);
    void Set108C_421CE0(int v);
    void ConditionC9_421D70(unsigned char v);
    void ConditionCA_421D90(unsigned char v);
};

MATCH_FUNC(0x421CD0)
void S421CF0::Set9CC_421CD0(int v) { field_9cc = v; }

MATCH_FUNC(0x421CE0)
void S421CF0::Set108C_421CE0(int v) { field_108c = v; }

MATCH_FUNC(0x421D10)
float S421CF0::Get108C_421D10() { return *(float*)&field_108c; }

MATCH_FUNC(0x421D20)
float S421CF0::Get9CC_421D20() { return *(float*)&field_9cc; }

MATCH_FUNC(0x421D50)
unsigned char S421CF0::GetC9_421D50() { return field_9c9; }

MATCH_FUNC(0x421D60)
unsigned char S421CF0::GetCA_421D60() { return field_9ca; }

