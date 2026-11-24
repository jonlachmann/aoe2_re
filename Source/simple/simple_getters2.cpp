#include "Function.hpp"
class S41B660 {
public:
    char pad_00[0x23];
    char Get_41B660();
};
class S4CF6F0 {
public:
    char pad_00[0xc];
    char Get_4CF6F0();
};
class S52BC80 {
public:
    char pad_00[0x76];
    char Get_52BC80();
};
class S5BFBC0 {
public:
    char pad_00[0x5];
    char Get_5BFBC0();
};
class S5BFC00 {
public:
    char pad_00[0x4];
    char Get_5BFC00();
};
class S5E68D0 {
public:
    char pad_00[0x29];
    char Get_5E68D0();
};
class S40A140 {
public:
    char pad_00[0x68];
    int Get_40A140();
};
class S40A310 {
public:
    char pad_00[0x74];
    int Get_40A310();
};
class S40B630 {
public:
    char pad_00[0x78];
    int Get_40B630();
};
class S40B640 {
public:
    char pad_00[0x7c];
    int Get_40B640();
};
class S412BD0 {
public:
    char pad_00[0x28];
    int Get_412BD0();
};
class S412C00 {
public:
    char pad_00[0x34];
    int Get_412C00();
};
class S412C10 {
public:
    char pad_00[0x38];
    int Get_412C10();
};
class S412C20 {
public:
    char pad_00[0x5c];
    int Get_412C20();
};
class S41C8F0 {
public:
    char pad_00[0x60];
    int Get_41C8F0();
};
class S440720 {
public:
    char pad_00[0x1c];
    int Get_440720();
};
class S47D9F0 {
public:
    char pad_00[0x8];
    int Get_47D9F0();
};
class S47DA00 {
public:
    char pad_00[0xc];
    int Get_47DA00();
};
class S48F970 {
public:
    char pad_00[0x4];
    int Get_48F970();
};
class S49F620 {
public:
    char pad_00[0x10];
    int Get_49F620();
};
class S4A2060 {
public:
    char pad_00[0x1c];
    int Get_4A2060();
};
class S52BDA0 {
public:
    char pad_00[0x6c];
    int Get_52BDA0();
};
class S5BF820 {
public:
    char pad_00[0x30];
    int Get_5BF820();
};
class S5BFA50 {
public:
    char pad_00[0x2c];
    int Get_5BFA50();
};
class S5BFBF0 {
public:
    int Get_5BFBF0();
};
class S5C05A0 {
public:
    char pad_00[0x18];
    int Get_5C05A0();
};
class S5C07A0 {
public:
    char pad_00[0x14];
    int Get_5C07A0();
};
class S409F40 {
public:
    char pad_00[0x0];
    int Get_409F40();
};
class S4107E0 {
public:
    char pad_00[0xc];
    int Get_4107E0();
};
class S520400 {
public:
    char pad_00[0x4];
    int Get_520400();
};
class S5BB0D0 {
public:
    char pad_00[0x122e];
    int Get_5BB0D0();
};
class S5BB0E0 {
public:
    char pad_00[0x122f];
    int Get_5BB0E0();
};
class S5BB0F0 {
public:
    char pad_00[0x1230];
    int Get_5BB0F0();
};
class S5BB100 {
public:
    char pad_00[0x1231];
    int Get_5BB100();
};
class S5BB130 {
public:
    char pad_00[0x123c];
    int Get_5BB130();
};
MATCH_FUNC(0x4CF6F0)
char S4CF6F0::Get_4CF6F0()
{
    return *(char*)((char*)this + 0xc);
}
MATCH_FUNC(0x5BFBC0)
char S5BFBC0::Get_5BFBC0()
{
    return *(char*)((char*)this + 0x5);
}
MATCH_FUNC(0x5BFC00)
char S5BFC00::Get_5BFC00()
{
    return *(char*)((char*)this + 0x4);
}
MATCH_FUNC(0x440720)
int S440720::Get_440720()
{
    return *(int*)((char*)this + 0x1c);
}
MATCH_FUNC(0x47D9F0)
int S47D9F0::Get_47D9F0()
{
    return *(int*)((char*)this + 0x8);
}
MATCH_FUNC(0x49F620)
int S49F620::Get_49F620()
{
    return *(int*)((char*)this + 0x10);
}
MATCH_FUNC(0x4A2060)
int S4A2060::Get_4A2060()
{
    return *(int*)((char*)this + 0x1c);
}
MATCH_FUNC(0x52BDA0)
int S52BDA0::Get_52BDA0()
{
    return *(int*)((char*)this + 0x6c);
}
MATCH_FUNC(0x5BF820)
int S5BF820::Get_5BF820()
{
    return *(int*)((char*)this + 0x30);
}
MATCH_FUNC(0x5BFA50)
int S5BFA50::Get_5BFA50()
{
    return *(int*)((char*)this + 0x2c);
}
MATCH_FUNC(0x5BFBF0)
int S5BFBF0::Get_5BFBF0()
{
    return *(int*)((char*)this + 0x0);
}
MATCH_FUNC(0x5C05A0)
int S5C05A0::Get_5C05A0()
{
    return *(int*)((char*)this + 0x18);
}
MATCH_FUNC(0x5C07A0)
int S5C07A0::Get_5C07A0()
{
    return *(int*)((char*)this + 0x14);
}
MATCH_FUNC(0x520400)
int S520400::Get_520400()
{
    return *(unsigned char*)((char*)this + 0x4);
}
MATCH_FUNC(0x5BB0D0)
int S5BB0D0::Get_5BB0D0()
{
    return *(unsigned char*)((char*)this + 0x122e);
}
MATCH_FUNC(0x5BB0E0)
int S5BB0E0::Get_5BB0E0()
{
    return *(unsigned char*)((char*)this + 0x122f);
}
MATCH_FUNC(0x5BB0F0)
int S5BB0F0::Get_5BB0F0()
{
    return *(unsigned char*)((char*)this + 0x1230);
}
MATCH_FUNC(0x5BB100)
int S5BB100::Get_5BB100()
{
    return *(unsigned char*)((char*)this + 0x1231);
}
MATCH_FUNC(0x5BB130)
int S5BB130::Get_5BB130()
{
    return *(unsigned char*)((char*)this + 0x123c);
}
