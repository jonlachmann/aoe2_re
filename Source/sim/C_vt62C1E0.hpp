// C_vt62C1E0 — vtable class 0x62C1E0 (basegame; skeleton: Source/skeleton/
// sim/C_vt62C1E0_62C1E0.h holds all 87 slots and lifted methods).
// This TU carries the 48 byte-verified methods. The layout is partial: the
// +0x430/+0x149c/+0x19b8 forwarding bytes of 0x5B5C50 stay raw to avoid
// overlapping the accessor block; fields below cover the rest the methods use.
#pragma once

#include "Function.hpp"

// Subobject at [this+0x149c] used by 0x5B5C50.
class T4DF8F0 {
public:
    void M_4DF8F0(char* a, char* b);
};

class C_vt62C1E0 {
public:
    char pad_00[0x24];
    void* field_24;               // +0x24 basegame object
    void* field_28;               // +0x28 window handle
    char pad_2c[0x6c - 0x2c];
    int field_6c;                 // +0x6C
    char pad_70[0x74 - 0x70];
    int field_74;                 // +0x74
    char pad_78[0x1d8 - 0x78];    // +0x78..+0x1D8
    int field_1d8;                // +0x1D8
    char pad_1dc[0x1f4 - 0x1dc];  // +0x1DC..+0x1F4
    int field_1f4;                // +0x1F4
    int field_1f8;                // +0x1F8
    int field_1fc;                // +0x1FC
    char pad_200[0x924 - 0x200];
    float field_924;              // +0x924
    unsigned char field_928;      // +0x928
    char pad_929[0x9A9 - 0x929];
    unsigned char field_9A9;      // +0x9A9
    unsigned char field_9AA;      // +0x9AA
    unsigned char field_9AB;      // +0x9AB
    unsigned char field_9AC;      // +0x9AC
    unsigned char field_9AD;      // +0x9AD
    unsigned char field_9AE;      // +0x9AE
    char pad_9AF[0x9B1 - 0x9AF];
    unsigned char field_9B1;      // +0x9B1
    char pad_9B2[0x9BE - 0x9B2];
    unsigned char field_9BE;      // +0x9BE
    char pad_9BF[0x9C9 - 0x9BF];
    unsigned char field_9C9;      // +0x9C9
    unsigned char field_9CA;      // +0x9CA
    char pad_9CB[0x9D4 - 0x9CB];
    int field_9D4;                // +0x9D4
    int field_9D8;                // +0x9D8
    char pad_9DC[0x1090 - 0x9DC];
    int field_1090;               // +0x1090
    char pad_1094[0x11C0 - 0x1094];
    int field_11C0;               // +0x11C0
    int field_11C4;               // +0x11C4
    int field_11C8;               // +0x11C8
    int field_11CC;               // +0x11CC
    int field_11D0;               // +0x11D0
    int field_11D4;               // +0x11D4
    int field_11D8;               // +0x11D8
    int field_11DC;               // +0x11DC
    int field_11E0;               // +0x11E0
    int field_11E4;               // +0x11E4
    int field_11E8;               // +0x11E8
    unsigned char array_11EC[0xC]; // +0x11EC
    int array_11F8[0xB];          // +0x11F8
    char pad_1224[0x1460 - 0x1224]; // +0x1224..+0x1460
    void* field_1460;             // +0x1460
    char pad_1464[8];             // +0x1464..+0x146C
    int field_146c;               // +0x146C
    char pad_1470[0x149C - 0x1470]; // +0x1470..+0x149C
    void* field_149c;             // +0x149C
    char pad_14a0[0x1ADC - 0x14a0]; // +0x14A0..+0x1ADC
    unsigned char field_1ADC;     // +0x1ADC
    char pad_1ADD[0x1AE0 - 0x1ADD];
    int field_1AE0;               // +0x1AE0

    float Get924_421750();
    int Get928_421760();
    int Get9D4_421780();
    char* Ptr9A9_4217A0();
    int Get9A9_4217B0();
    int Get9AA_4217C0();
    void Set928_421A60(unsigned char v);
    void Set9D4_421AB0(int v);
    void Set9D8_421AC0(int v);
    void M_421AD0(int v);
    void M_421B10(unsigned char a, unsigned char b, unsigned char c);
    void Set9AE_421B40(unsigned char v);
    void Hook_420BE0(int a1, int a2, int a3, int a4);
    int M_5BB8A0(int a1, int a2, int a3, int a4);
    void M_5BCA10(int a1, int a2);
    void Set9B1_421B70(unsigned char v);
    void Set9BE_421C20(unsigned char v);
    void SetC9_421CF0();
    void SetCA_421D00();
    void ClearC9_421D30();
    void ClearCA_421D40();
    void ConditionC9_421D70(unsigned char v);
    void ConditionCA_421D90(unsigned char v);
    int Get_422320();
    void Hook_5BAD80(int a1);     // unresolved callee at 0x5BAD80
    void M_5BAEE0(char* src);     // inline strcpy into +0x1240
    void Wrap_5B5C50();
    int Get_5BAD50();
    void SetInt_5BAD60(int v);
    int Get_5BAD70();
    int Get_5BAEA0();
    char* Get_5BAEB0();
    void SetInt_5BAF20(int v);
    void SetInt_5BAF40(int v);
    void M_421A80(char* src);     // 0x80-byte copy into +0x929, terminator +0x9A8
    void M_41FA40(int a1);
    void M_5BAEC0(int a1);
    void Set_5BAF70(int a, int b);
    void SetByte_5BAFA0(int index, unsigned char v);
    void SetInt_5BAFD0(int index, int v);
    int Set_5BB000(int a2, int a3);
    void SetByte2_5BB040(int index, unsigned char v);
    void SetByte_5BB170(unsigned char v);
    void SetByte_5BB180(unsigned char v);
    void SetByte_5BB190(unsigned char v);
    void SetByte_5BB1A0(unsigned char v);
    void SetInt_5BB1B0(int v);
    void SetInt_5BB1C0(int v);
    void SetByte_5BB1D0(unsigned char v);
    void SetByte_5BB1E0(unsigned char v);
    void SetByte_5BB1F0(unsigned char v);
    void SetByte_5BB200(unsigned char v);
    void SetByte_5BB210(unsigned char v);
    void SetInt_5BB220(int v);
    unsigned char* Clear_5BB230();
    void Set_5BC4D0(int a, int b, int c, int d);
    void M_5BB080(int a1, char* a2);
    void M_5BC500();
};
