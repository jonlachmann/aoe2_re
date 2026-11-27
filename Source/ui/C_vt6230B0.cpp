#include "C_vt6230B0.hpp"

// Callee identities for the rectangle layout: the origin setter is the matched
// 4A0630 on the screen-options base, and the rectangle fixup is the matched
// 4B8A80 on the picture shape this object shares.
class C_TRIBE_Screen_Options {
public:
    void M_4A0630(int a1, int a2, int a3, int a4);
};
class C_pnl_pic {
public:
    void M_4B8A80();
};

// 0x4B8910 — recompute the scrollbar rectangles after forwarding the four
// origin/size words to 4A0630. Mode +0x1B8 == 1 lays the vertical arrangement
// (origin +0x10/+0x18, extent +0x0C/+0x14) across +0x128..+0x1B4; any other mode
// lays the horizontal arrangement. The matched 4B8A80 then derives the final
// rectangle edges; its eax is the width/height just stored, so the return
// mirrors that value. Returns the resulting rectangle dimension. WIP: the
// original forwards the four args from the already-loaded stack copies and
// keeps the computed edges in ecx/edx without a post-call re-test; ours reloads
// the mode to pick the returned dimension, so 400 vs 366 bytes.
WIP_FUNC(0x4B8910)
int C_vt6230B0::Hook_4B8910(int a2, int a3, int a4, int a5)
{
    ((C_TRIBE_Screen_Options*)this)->M_4A0630(a2, a3, a4, a5);
    if (field_1b8 == 1)
    {
        int v6 = field_10;
        int v7 = field_18;
        int v8 = v6 + 2;
        int v9 = v7 + v6 - 5;
        int v10 = field_c;
        int v11 = field_14 - v7;
        field_16c = v8;
        field_17c = v8;
        int v12 = v10 + 2;
        int v13 = v10 + v11 + 2;
        field_168 = v12;
        field_178 = v13;
        int v14 = v12 + v7 - 5;
        field_18c = v8;
        field_19c = v8;
        field_1ac = v8;
        field_13c = v14 + 1;
        field_138 = v14 + 1;
        field_174 = v9;
        field_170 = v14;
        field_184 = v9;
        field_180 = v13 + v7 - 5;
        field_194 = v9;
        field_1a4 = v9;
        field_1b4 = v9;
        field_140 = v13 - v7 + 4;
    }
    else
    {
        int v16 = field_14;
        int v17 = field_10;
        int v18 = field_18 - v16;
        int v19 = field_c + 2;
        int v20 = v17 + 2;
        field_168 = v19;
        int v21 = v17 + v18 + 2;
        field_16c = v20;
        field_17c = v21;
        int v22 = v16 + v20 - 5;
        int v23 = v16 + v19 - 5;
        field_178 = v19;
        field_188 = v19;
        field_198 = v19;
        field_1a8 = v19;
        field_130 = v21 - v16 + 4;
        field_170 = v23;
        field_174 = v22;
        field_180 = v23;
        field_184 = v21 + v16 - 5;
        field_190 = v23;
        field_1a0 = v23;
        field_1b0 = v23;
        field_12c = v22 + 1;
        field_128 = v22 + 1;
    }
    ((C_pnl_pic*)this)->M_4B8A80();
    return field_1b8 == 1 ? field_178 - 1 : field_17c - 1;
}

MATCH_FUNC(0x4B9D20)
C_vt6230B0* C_vt6230B0::Init_4B9D20()
{
    this->Hook_4B8730();
    field_1c8 = 1;
    field_1cc = 0;
    *(void**)this = (void*)0x6230b0;
    return this;
}

MATCH_FUNC(0x4B9E00)
void C_vt6230B0::slot03_4B9E00(int a1, int a2, int a3, int a4)
{
    this->Hook_4B8910(a1, a2, a3, a4);
}
