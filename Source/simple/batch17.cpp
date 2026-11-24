#include "Function.hpp"

class S5CF950 {
public:
    char pad_00[0x28a];
    int Set_5CF950(int x, int y);
};
MATCH_FUNC(0x5CF950)
int S5CF950::Set_5CF950(int x, int y)
{
    if (x < 1 || x >= 9 || y < 1 || y > 5)
        return 0;
    *(unsigned char*)((char*)this + 0x28a + x) = (unsigned char)y;
    return 1;
}

class S5C1360 {
public:
    char pad_00[0x4ccc];
    int field_4ccc;
    int Set_5C1360(int value);
};
WIP_FUNC(0x5C1360)
int S5C1360::Set_5C1360(int value)
{
    if (value < 0)
        return field_4ccc = 0;
    if (value > 1)
        value = 1;
    return field_4ccc = value;
}

class S5C1410 {
public:
    char pad_00[0x4cd4];
    int field_4cd4;
    int Set_5C1410(int value);
};

class S4BF6B0 {
public:
    void Set_4BF6B0(int* out);
};

class S5A3810 {
public:
    char pad_00[0x40];
    void Sub_5A3810(int index, float value);
};
MATCH_FUNC(0x5A3810)
void S5A3810::Sub_5A3810(int index, float value)
{
    unsigned idx = index & 0xff;
    float* p = (float*)((char*)this + 0x40 + idx * 4);
    *p -= value;
}

class S5A3760 {
public:
    char pad_00[0x40];
    void Add_5A3760(int index, float value);
};
MATCH_FUNC(0x5A3760)
void S5A3760::Add_5A3760(int index, float value)
{
    unsigned idx = index & 0xff;
    float* p = (float*)((char*)this + 0x40 + idx * 4);
    float t = value;
    t += *p;
    *p = t;
}

class T567BC0 {
public:
    int Get_567BC0(int index);
};
class S56ABD0 {
public:
    char pad_00[0x1658];
    void Wrap_56ABD0(int arg);
};

class T567BD0 {
public:
    int Get_567BD0(int index);
};
class S56ABF0 {
public:
    char pad_00[0x1658];
    void Wrap_56ABF0(int arg);
};

class T579640 {
public:
    int Get_579640(int index);
};
class S56ABB0 {
public:
    char pad_00[0x40e4];
    void Wrap_56ABB0(int arg);
};

class T579600 {
public:
    int Get_579600(int index);
};
class S56BC40 {
public:
    char pad_00[0x40e4];
    void Wrap_56BC40(int arg);
};
MATCH_FUNC(0x56BC40)
void S56BC40::Wrap_56BC40(int arg)
{
    ((T579600*)((char*)this + 0x40e4))->Get_579600(arg);
}
