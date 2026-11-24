#include "Function.hpp"

class S421Accessors {
public:
    char pad_00[0x924];
    float field_924;
    unsigned char field_928;
    char gap_929[0x9a9 - 0x929];
    unsigned char field_9a9;
    unsigned char field_9aa;
    unsigned char field_9ab;
    unsigned char field_9ac;
    unsigned char field_9ad;
    unsigned char field_9ae;
    unsigned char field_9af;
    unsigned char field_9b0;
    unsigned char field_9b1;
    unsigned char field_9b2;
    unsigned char field_9b3;
    unsigned char field_9b4;
    unsigned char array_9b5[0x9be - 0x9b5];
    unsigned char field_9be;
    unsigned char field_9bf;
    unsigned char array_9c0[0x9d0 - 0x9c0];
    unsigned char field_9d0;
    char gap_9d1[0x9d4 - 0x9d1];
    int field_9d4;
    int field_9d8;
    char pad_dc[0xb44 - 0x9dc];
    int field_b44;
    char pad_b48[0x1094 - 0xb48];
    unsigned char field_1094;

    void Set9BF_421710(unsigned char v);
    void Set9AE_421B40(unsigned char v);
    void Set9B0_421B50(unsigned char v);
    void Set9D0_421B60(unsigned char v);
    void Set9B1_421B70(unsigned char v);
    void Set9B2_421B80(unsigned char v);
    void Set9B3_421B90(unsigned char v);
    void Clear9B4_421BA0(unsigned char unused);
    void SetBit_421BB0(int index, unsigned char v);
    void Set9BE_421C20(unsigned char v);
    void Set1094_421C50(unsigned char v);
    void SetB44_421720(int v);
    int GetB44_421730();
    unsigned char Get9BF_421740();
    float Get924_421750();
    int Get928_421760();
    bool IsZero928_421770();
    int Get9D4_421780();
    int Get9D8_421790();
    char* Ptr9A9_4217A0();
    int Get9A9_4217B0();
    int Get9AA_4217C0();
    int Get9AB_4217D0();
    int Get9AC_4217E0();
    int Get9AD_4217F0();
    int Get9AE_421800();
    int Get9B0_421810();
    int Get9D0_421820();
    int Get9B1_421830();
    int Get9B2_421840();
    int Get9B4_421850();
    unsigned char GetIndexed9B5_4219D0(int index);
    int Get9BE_4219E0();
    int Get9B3_4219F0();
    int GetIndexed9C0_421A00(int index);
    unsigned char Get1094_421A20();
    unsigned char Get9AF_421A30();
    void Set928_421A60(unsigned char v);
    void Set924Raw_421A70(int v);
    void Set9D4_421AB0(int v);
    void Set9D8_421AC0(int v);
};

MATCH_FUNC(0x421710)
void S421Accessors::Set9BF_421710(unsigned char v) { field_9bf = v; }

MATCH_FUNC(0x421720)
void S421Accessors::SetB44_421720(int v) { field_b44 = v; }

MATCH_FUNC(0x421730)
int S421Accessors::GetB44_421730() { return field_b44; }

MATCH_FUNC(0x421740)
unsigned char S421Accessors::Get9BF_421740() { return field_9bf; }

MATCH_FUNC(0x421750)
float S421Accessors::Get924_421750() { return field_924; }

MATCH_FUNC(0x421760)
int S421Accessors::Get928_421760() { return field_928; }

MATCH_FUNC(0x421770)
bool S421Accessors::IsZero928_421770() { return field_928 == 0; }

MATCH_FUNC(0x421780)
int S421Accessors::Get9D4_421780() { return field_9d4; }

MATCH_FUNC(0x421790)
int S421Accessors::Get9D8_421790() { return field_9d8; }

MATCH_FUNC(0x4217A0)
char* S421Accessors::Ptr9A9_4217A0() { return (char*)this + 0x929; }

MATCH_FUNC(0x4217B0)
int S421Accessors::Get9A9_4217B0() { return field_9a9; }

MATCH_FUNC(0x4217C0)
int S421Accessors::Get9AA_4217C0() { return field_9aa; }

MATCH_FUNC(0x4217D0)
int S421Accessors::Get9AB_4217D0() { return field_9ab; }

MATCH_FUNC(0x4217E0)
int S421Accessors::Get9AC_4217E0() { return field_9ac; }

MATCH_FUNC(0x4217F0)
int S421Accessors::Get9AD_4217F0() { return field_9ad; }

MATCH_FUNC(0x421800)
int S421Accessors::Get9AE_421800() { return field_9ae; }

MATCH_FUNC(0x421810)
int S421Accessors::Get9B0_421810() { return field_9b0; }

MATCH_FUNC(0x421820)
int S421Accessors::Get9D0_421820() { return field_9d0; }

MATCH_FUNC(0x421830)
int S421Accessors::Get9B1_421830() { return field_9b1; }

MATCH_FUNC(0x421840)
int S421Accessors::Get9B2_421840() { return field_9b2; }

MATCH_FUNC(0x421850)
int S421Accessors::Get9B4_421850() { return field_9b4; }

MATCH_FUNC(0x4219D0)
unsigned char S421Accessors::GetIndexed9B5_4219D0(int index) { return array_9b5[index]; }

MATCH_FUNC(0x4219E0)
int S421Accessors::Get9BE_4219E0() { return field_9be; }

MATCH_FUNC(0x4219F0)
int S421Accessors::Get9B3_4219F0() { return field_9b3; }

MATCH_FUNC(0x421A00)
int S421Accessors::GetIndexed9C0_421A00(int index)
{
    if (index >= 9)
        return 1;
    return array_9c0[index];
}

MATCH_FUNC(0x421A20)
unsigned char S421Accessors::Get1094_421A20() { return field_1094; }

MATCH_FUNC(0x421A30)
unsigned char S421Accessors::Get9AF_421A30() { return field_9af; }

MATCH_FUNC(0x421A60)
void S421Accessors::Set928_421A60(unsigned char v) { field_928 = v; }

MATCH_FUNC(0x421A70)
void S421Accessors::Set924Raw_421A70(int v) { *(int*)((char*)this + 0x924) = v; }

MATCH_FUNC(0x421AB0)
void S421Accessors::Set9D4_421AB0(int v) { field_9d4 = v; }

MATCH_FUNC(0x421AC0)
void S421Accessors::Set9D8_421AC0(int v) { field_9d8 = v; }

extern unsigned char g_6642f0;

MATCH_FUNC(0x421A40)
char* ClearGlobal_421A40()
{
    g_6642f0 = 0;
    return (char*)&g_6642f0;
}

MATCH_FUNC(0x421B40)
void S421Accessors::Set9AE_421B40(unsigned char v) { field_9ae = v; }

MATCH_FUNC(0x421B50)
void S421Accessors::Set9B0_421B50(unsigned char v) { field_9b0 = v; }

MATCH_FUNC(0x421B60)
void S421Accessors::Set9D0_421B60(unsigned char v) { field_9d0 = v; }

MATCH_FUNC(0x421B70)
void S421Accessors::Set9B1_421B70(unsigned char v) { field_9b1 = v; }

MATCH_FUNC(0x421B80)
void S421Accessors::Set9B2_421B80(unsigned char v) { field_9b2 = v; }

MATCH_FUNC(0x421B90)
void S421Accessors::Set9B3_421B90(unsigned char v) { field_9b3 = v; }

MATCH_FUNC(0x421BA0)
void S421Accessors::Clear9B4_421BA0(unsigned char unused) { (void)unused; field_9b4 = 0; }

MATCH_FUNC(0x421BB0)
void S421Accessors::SetBit_421BB0(int index, unsigned char v)
{
    unsigned char* p = (unsigned char*)this + 0x9b5 + index;
    *p = (*p & 0xfe) | v;
}

MATCH_FUNC(0x421C20)
void S421Accessors::Set9BE_421C20(unsigned char v) { field_9be = v; }

MATCH_FUNC(0x421C50)
void S421Accessors::Set1094_421C50(unsigned char v) { field_1094 = v; }
