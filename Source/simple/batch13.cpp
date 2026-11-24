#include "Function.hpp"

class S40A0D0 {
public:
    S40A0D0* Ref_40A0D0();
};

class S4228E0 {
public:
    S4228E0* Ref_4228E0();
};
MATCH_FUNC(0x4228E0)
S4228E0* S4228E0::Ref_4228E0()
{
    return (S4228E0*)((char*)this + 4);
}

class S46A900 {
public:
    S46A900* Ref_46A900();
};

class S46A940 {
public:
    S46A940* Ref_46A940();
};

class S46A950 {
public:
    S46A950* Ref_46A950();
};

class S46A960 {
public:
    S46A960* Ref_46A960();
};

class S46A970 {
public:
    S46A970* Ref_46A970();
};

class S46AA10 {
public:
    S46AA10* Ref_46AA10();
};

extern int* g_6645c4;
MATCH_FUNC(0x439610)
int* Ref_439610()
{
    return (int*)((char*)*(int**)((char*)g_6645c4 + 0x24) + 0xc3f);
}

struct Three46 {
    int a;
    int b;
    int c;
};

class S46A980 {
public:
    char pad_00[0x64];
    Three46 field_64;
    void Copy_46A980(Three46* src);
};

class S46AA20 {
public:
    char pad_00[0x70];
    Three46 field_70;
    void Copy_46AA20(Three46* src);
};

