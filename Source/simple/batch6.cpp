#include "Function.hpp"

class S410680 {
public:
    S410680* Init_410680();
};

class S4373F0 {
public:
    S4373F0* Init_4373F0();
};

class S465B10 {
public:
    S465B10* Init_465B10();
};

class S5B0800 {
public:
    S5B0800* Init_5B0800();
};
MATCH_FUNC(0x5B0800)
S5B0800* S5B0800::Init_5B0800()
{
    int negative = -1;
    *(int*)((char*)this + 4) = negative;
    *(int*)((char*)this + 8) = negative;
    *(int*)((char*)this + 0xc) = negative;
    *(unsigned char*)((char*)this) = 0xff;
    *(int*)((char*)this + 0x10) = 0xbf800000;
    *(int*)((char*)this + 0x14) = 0xbf800000;
    *(int*)((char*)this + 0x18) = 0xbf800000;
    return this;
}

class S5B0820 {
public:
    char pad_00[1];
    S5B0820* Init_5B0820(char* src);
};
MATCH_FUNC(0x5B0820)
S5B0820* S5B0820::Init_5B0820(char* src)
{
    int negative = -1;
    *(int*)((char*)this + 4) = negative;
    *(int*)((char*)this + 8) = negative;
    *(int*)((char*)this + 0xc) = negative;
    *(int*)((char*)this + 0x10) = 0xbf800000;
    *(int*)((char*)this + 0x14) = 0xbf800000;
    *(int*)((char*)this + 0x18) = 0xbf800000;
    *(unsigned char*)((char*)this) = 0xff;
    *(unsigned char*)((char*)this) = *(unsigned char*)src;
    *(int*)((char*)this + 4) = *(int*)(src + 4);
    *(int*)((char*)this + 0xc) = *(int*)(src + 0xc);
    *(int*)((char*)this + 0x10) = *(int*)(src + 0x10);
    *(int*)((char*)this + 0x14) = *(int*)(src + 0x14);
    *(int*)((char*)this + 0x18) = *(int*)(src + 0x18);
    return this;
}

class S5B0870 {
public:
    S5B0870* Init_5B0870();
};
MATCH_FUNC(0x5B0870)
S5B0870* S5B0870::Init_5B0870()
{
    int zero = 0;
    *(int*)((char*)this) = zero;
    *(int*)((char*)this + 4) = -1;
    *(int*)((char*)this + 8) = zero;
    *(int*)((char*)this + 0xc) = zero;
    *(int*)((char*)this + 0x10) = zero;
    *(unsigned char*)((char*)this + 0x14) = zero;
    *(unsigned char*)((char*)this + 0x15) = zero;
    *(int*)((char*)this + 0x18) = zero;
    *(int*)((char*)this + 0x1c) = zero;
    *(int*)((char*)this + 0x20) = zero;
    *(int*)((char*)this + 0x24) = zero;
    *(int*)((char*)this + 0x28) = zero;
    *(int*)((char*)this + 0x2c) = zero;
    *(int*)((char*)this + 0x30) = zero;
    *(int*)((char*)this + 0x34) = zero;
    *(int*)((char*)this + 0x38) = zero;
    *(int*)((char*)this + 0x3c) = zero;
    *(int*)((char*)this + 0x74) = zero;
    *(int*)((char*)this + 0xac) = zero;
    *(unsigned char*)((char*)this + 0x40) = zero;
    *(unsigned char*)((char*)this + 0x78) = zero;
    return this;
}

class S423A70 {
public:
    int field_0;
    int field_4;
    int field_8;
    char pad_0c[0x14 - 0x0c];
    unsigned char field_14;
    char pad_15[0x1c - 0x15];
    int field_1c;
    char pad_20[0x420 - 0x20];
    unsigned char field_420;
    char pad_421[0x524 - 0x421];
    int field_524;
    int field_528;
    int field_52c;
    int field_530;
    char pad_534[0x53c - 0x534];
    int field_53c;
    int field_540;
    char pad_544[0x548 - 0x544];
    int field_548;
    S423A70* Init_423A70();
};

class S469570 {
public:
    S469570* Init_469570();
};

// Inlined-constructor shape: returns this.
class S595DF0 {
public:
    int vtbl_0;
    S595DF0* owner_4;
    int field_8;
    short field_c;
    short field_e;
    float field_10;
    S595DF0* Init_595DF0(S595DF0* owner);
};
MATCH_FUNC(0x595DF0)
S595DF0* S595DF0::Init_595DF0(S595DF0* owner)
{
    owner_4 = owner;
    vtbl_0 = 0x62b024;
    field_8 = 0;
    field_c = 0;
    field_e = 0;
    field_10 = -1.0f;
    return this;
}
