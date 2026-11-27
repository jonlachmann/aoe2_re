#include "C_vt621F6C.hpp"

// 0x4A0270 — default constructor of the 0x621F6C base object. Zero every
// scalar in the binary store order, set +0x38 = 2, +0x6C/+0x7C/+0x80/+0x88 = 1,
// +0xC0 = 0xFA, install the vtable word 0x621F6C at +0, then set
// +0xE8/+0xEC = -1 and return this. The +0x90..+0x9C block and the +0xF0..+0xF6
// bytes are stored out of numeric order (as observed).
MATCH_FUNC(0x4A0270)
C_vt621F6C_4A0270::C_vt621F6C_4A0270()
{
    field_04 = 0;
    field_08 = 0;
    field_0c = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    field_20 = 0;
    field_34 = 0;
    field_38 = 2;
    field_3c = 0;
    field_40 = 0;
    field_44 = 0;
    field_48 = 0;
    field_4c = 0;
    field_50 = 0;
    field_54 = 0;
    field_58 = 0;
    field_5c = 0;
    field_60 = 0;
    field_64 = 0;
    field_68 = 0;
    field_6c = 1;
    field_70 = 0;
    field_74 = 0;
    field_78 = 0;
    field_7c = 1;
    field_80 = 1;
    field_88 = 1;
    field_8c = 0;
    field_a0 = 0;
    field_a4 = 0;
    field_a8 = 0;
    field_ac = 0;
    field_b0 = 0;
    field_b4 = 0;
    field_b8 = 0;
    field_bc = 0;
    field_c4 = 0;
    field_c8 = 0;
    field_cc = 0;
    field_d0 = 0;
    field_d4 = 0;
    field_d8 = 0;
    field_dc = 0;
    field_e0 = 0;
    field_e4 = 0;
    field_f0 = 0;
    field_f1 = 0;
    field_f2 = 0;
    field_f3 = 0;
    field_f4 = 0;
    field_f5 = 0;
    field_f6 = 0;
    field_90 = 0;
    field_94 = 0;
    field_98 = 0;
    field_9c = 0;
    field_c0 = 0xfa;
    field_00 = 0x621f6c;
    field_e8 = -1;
    field_ec = -1;
}

// 0x4B9F70 — C_pnl_txt constructor. Call the base ctor at 0x4A0270 (installing
// the 0x621F6C base vtable), zero the +0xF8..+0x1A4 extension in the observed
// order, then install the C_pnl_txt vtable 0x623318 at +0 and set +0xF2 = 1.
MATCH_FUNC(0x4B9F70)
C_pnl_txt_4B9F70::C_pnl_txt_4B9F70()
{
    field_f8 = 0;
    field_fc = 0;
    field_fe = 0;
    field_100 = 0;
    field_102 = 0;
    field_104 = 0;
    field_106 = 0;
    field_118 = 0;
    field_11c = 0;
    field_120 = 0;
    field_124 = 0;
    field_128 = 7;
    field_12c = 0;
    field_130 = 2;
    field_134 = 2;
    field_138 = 0xffffff;
    field_13c = 0;
    field_140 = 0xffff;
    field_144 = 0;
    field_148 = 0;
    field_14c = 0;
    field_150 = 0;
    field_154 = 0;
    field_158 = 0;
    field_15c = 0;
    field_160 = 0;
    field_162 = 0;
    field_164 = 0;
    field_16c = 0;
    field_170 = 0;
    field_174 = 0;
    field_178 = 0;
    field_17c = 0;
    field_180 = 0;
    field_184 = 0;
    field_188 = 0;
    field_18c = 0;
    field_18d = 0;
    field_18e = 0;
    field_18f = 0;
    field_190 = 0;
    field_191 = 0;
    field_194 = 0;
    field_198 = 0;
    field_19c = 0;
    field_1a4 = 0;
    field_80 = 0;
    field_108 = 0;
    field_10c = 0;
    field_110 = 0;
    field_114 = 0;
    field_168 = 0xff;
    field_00 = 0x623318;
    field_f2 = 1;
}

// Minimal owners of the callees reached at the end of the ctor. Both bodies are
// already matched elsewhere (0x4A2070, 0x49F650); only the mangled symbols are
// needed here so the relocatable calls resolve.
class C_TRIBE_Screen_Options {
public:
    void M_4A2070(char* a1);
};
class C_cluster_49F630 {
public:
    int M_49F650(void* key, int a2, int a3);
};

// 0x4A00E0 — one-argument constructor of the 0x621F6C base object. Same
// zero-init sequence and defaults as the default ctor, but also clears +0x84,
// installs the vtable at +0, calls M_4A2070(a1) on this object, sets
// +0xE8/+0xEC = -1 and +0xF7 = 0, then, when the +0x1C name pointer is
// non-empty, inserts this object into the 0x66EA48 list through 0x49F650.
MATCH_FUNC(0x4A00E0)
C_vt621F6C_4A00E0::C_vt621F6C_4A00E0(char* a1)
{
    field_04 = 0;
    field_08 = 0;
    field_0c = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    field_20 = 0;
    field_34 = 0;
    field_38 = 2;
    field_3c = 0;
    field_40 = 0;
    field_44 = 0;
    field_48 = 0;
    field_4c = 0;
    field_50 = 0;
    field_54 = 0;
    field_58 = 0;
    field_5c = 0;
    field_60 = 0;
    field_64 = 0;
    field_68 = 0;
    field_6c = 1;
    field_70 = 0;
    field_74 = 0;
    field_78 = 0;
    field_7c = 1;
    field_80 = 1;
    field_84 = 0;
    field_88 = 1;
    field_8c = 0;
    field_a0 = 0;
    field_a4 = 0;
    field_a8 = 0;
    field_ac = 0;
    field_b0 = 0;
    field_b4 = 0;
    field_b8 = 0;
    field_bc = 0;
    field_c0 = 0xfa;
    field_c4 = 0;
    field_c8 = 0;
    field_cc = 0;
    field_d0 = 0;
    field_d4 = 0;
    field_d8 = 0;
    field_dc = 0;
    field_e0 = 0;
    field_e4 = 0;
    field_f0 = 0;
    field_f1 = 0;
    field_f2 = 0;
    field_f3 = 0;
    field_f4 = 0;
    field_f5 = 0;
    field_f6 = 0;
    field_00 = 0x621f6c;
    field_90 = 0;
    field_94 = 0;
    field_98 = 0;
    field_9c = 0;
    ((C_TRIBE_Screen_Options*)this)->M_4A2070(a1);
    field_e8 = -1;
    field_ec = -1;
    field_f7 = 0;
    if (field_1c != 0 && *(char*)field_1c != 0)
        ((C_cluster_49F630*)0x66ea48)->M_49F650((void*)this, 0, 0);
}
