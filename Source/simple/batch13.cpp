#include "Function.hpp"

class S40A0D0 {
public:
    S40A0D0* Ref_40A0D0();
};
MATCH_FUNC(0x40A0D0)
S40A0D0* S40A0D0::Ref_40A0D0()
{
    return (S40A0D0*)((char*)this + 0x10);
}

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
MATCH_FUNC(0x46A900)
S46A900* S46A900::Ref_46A900()
{
    return (S46A900*)((char*)this + 4);
}

class S46A940 {
public:
    S46A940* Ref_46A940();
};
MATCH_FUNC(0x46A940)
S46A940* S46A940::Ref_46A940()
{
    return (S46A940*)((char*)this + 0x10);
}

class S46A950 {
public:
    S46A950* Ref_46A950();
};
MATCH_FUNC(0x46A950)
S46A950* S46A950::Ref_46A950()
{
    return (S46A950*)((char*)this + 0x1c);
}

class S46A960 {
public:
    S46A960* Ref_46A960();
};
MATCH_FUNC(0x46A960)
S46A960* S46A960::Ref_46A960()
{
    return (S46A960*)((char*)this + 0x28);
}

class S46A970 {
public:
    S46A970* Ref_46A970();
};
MATCH_FUNC(0x46A970)
S46A970* S46A970::Ref_46A970()
{
    return (S46A970*)((char*)this + 0x64);
}

class S46AA10 {
public:
    S46AA10* Ref_46AA10();
};
MATCH_FUNC(0x46AA10)
S46AA10* S46AA10::Ref_46AA10()
{
    return (S46AA10*)((char*)this + 0x70);
}

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
MATCH_FUNC(0x46A980)
void S46A980::Copy_46A980(Three46* src)
{
    field_64 = *src;
}

class S46AA20 {
public:
    char pad_00[0x70];
    Three46 field_70;
    void Copy_46AA20(Three46* src);
};
MATCH_FUNC(0x46AA20)
void S46AA20::Copy_46AA20(Three46* src)
{
    field_70 = *src;
}

MATCH_FUNC(0x5F3FB0)
void Build_5F3FB0(int* out, int a, int b)
{
    out[0] = a;
    out[1] = a + b;
    out[3] = a;
    out[2] = a;
}
