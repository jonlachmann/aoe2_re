#include "C_vt620BF8.hpp"

#pragma intrinsic(memset)

extern int Hook_5F8F60(int size);

// 0x473410 — constructor: store the row width and count, clear +0xC/+0x10,
// allocate width*count bytes for +0x14, fill that buffer with the low byte of
// the third argument, allocate count*4 bytes of row pointers for +0x18 and
// point each row at the flat buffer offset i*width. Returns this.
WIP_FUNC(0x473410)
C_vt620BF8* C_vt620BF8::Init_473410(int a1, int a2, int a3)
{
    int size;
    field_4 = a1;
    size = a1 * a2;
    field_8 = a2;
    field_c = 0;
    field_10 = 0;
    *(int*)this = 0x620BF8;
    field_14 = Hook_5F8F60(size);
    memset((void*)field_14, a3 & 0xff, size);
    field_18 = Hook_5F8F60(field_8 * 4);
    if (field_18 != 0)
    {
        for (int i = 0, off = 0; i < field_8; i++, off += field_4)
            ((int*)field_18)[i] = field_14 + off;
    }
    return this;
}

#pragma function(memset)
