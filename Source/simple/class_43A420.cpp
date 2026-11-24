#include "Function.hpp"

class S43A420Tail {
public:
    int field_0;
    int field_4;
    unsigned char field_8;
};

class S43A420 {
public:
    char pad_00[0x28];
    unsigned short field_28;
    int field_2c;
    char pad_30[0xd0 - 0x30];
    S43A420Tail tail_d0;
    void Init_43A420();
};

WIP_FUNC(0x43A420)
void S43A420::Init_43A420()
{
    field_28 = 0;
    field_2c = 0;
    S43A420Tail* tail = (S43A420Tail*)((char*)this + 0xd0);
    tail->field_0 = 0;
    tail->field_4 = 0;
    tail->field_8 = 0;
}
