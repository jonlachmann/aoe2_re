#include "Function.hpp"
class S428AE0 {
public:
    char pad_00[0x13bc];
    int Get_428AE0(int index);
};
class S431CD0 {
public:
    char pad_00[0x1bf0];
    int Get_431CD0(int index);
};
class S4334F0 {
public:
    char pad_00[0x46bc];
    int Get_4334F0(int index);
};
class S4CED70 {
public:
    char pad_00[0x1010];
    int Get_4CED70(int index);
};
class S5508F0 {
public:
    char pad_00[0x5c4];
    int Get_5508F0(int index);
};
class S567BC0 {
public:
    char pad_00[0x1ff4];
    int Get_567BC0(int index);
};
class S567BD0 {
public:
    char pad_00[0x2014];
    int Get_567BD0(int index);
};
class S567BE0 {
public:
    char pad_00[0x2034];
    int Get_567BE0(int index);
};
class S5C1A20 {
public:
    char pad_00[0x4c8c];
    int Get_5C1A20(int index);
};
class S5C1A30 {
public:
    char pad_00[0x51d8];
    int Get_5C1A30(int index);
};
class S5C1A40 {
public:
    char pad_00[0x51e4];
    int Get_5C1A40(int index);
};
class S5E68C0 {
public:
    char pad_00[0xd4];
    int Get_5E68C0(int index);
};
MATCH_FUNC(0x5508F0)
int S5508F0::Get_5508F0(int index)
{
    return *(int*)((char*)this + 0x5c4 + index * 4);
}
MATCH_FUNC(0x567BC0)
int S567BC0::Get_567BC0(int index)
{
    return *(int*)((char*)this + 0x1ff4 + index * 4);
}
MATCH_FUNC(0x567BD0)
int S567BD0::Get_567BD0(int index)
{
    return *(int*)((char*)this + 0x2014 + index * 4);
}
MATCH_FUNC(0x567BE0)
int S567BE0::Get_567BE0(int index)
{
    return *(int*)((char*)this + 0x2034 + index * 4);
}
MATCH_FUNC(0x5C1A20)
int S5C1A20::Get_5C1A20(int index)
{
    return *(int*)((char*)this + 0x4c8c + index * 4);
}
MATCH_FUNC(0x5C1A30)
int S5C1A30::Get_5C1A30(int index)
{
    return *(int*)((char*)this + 0x51d8 + index * 4);
}
MATCH_FUNC(0x5C1A40)
int S5C1A40::Get_5C1A40(int index)
{
    return *(int*)((char*)this + 0x51e4 + index * 4);
}
