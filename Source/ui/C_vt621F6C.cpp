#include "C_vt621F6C.hpp"
#include "matched_mem.h"

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

// Minimal owner of the 0x4A2AC0 setup method (the full 0x622060 class is still
// lifted); only the mangled symbol is needed so the relocatable call matches.
class C_vt622060 {
public:
    void M_4A2AC0();
    int M_4A3430(char* Str, int FileHandle);
    int M_4A35A0(char* Str, int FileHandle);
};

// The 0x51E7F0 0x1C-byte entry object reached by the allocation path. Only the
// layout and the ctor/dtor symbols are needed here; the original ctor and the
// matched destructor 0x51EAE0 live in their own TUs.
class T4B83D0Obj214 {
public:
    int field_00;
    int field_04;
    void* field_08;
    void* field_0c;
    char pad_10[0x18 - 0x10];
    int field_18;
    void M_51EAE0();
};

class T51E7F0Entry {
public:
    int field_0;
    int field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    unsigned char field_14;
    char pad_15[0x18 - 0x15];
    int field_18;
    T51E7F0Entry(char* a1, int a2);
    ~T51E7F0Entry();
};

extern int __cdecl sub_5FF460(char* a1, char* a2);
extern char* __cdecl sub_5FEE50(char* a1, int a2);
extern int __cdecl sub_5FCE14(char* dst, char* fmt, ...);
extern void __cdecl sub_5F90B0(int a1);

// 0x4A2370 — one-argument constructor of the 0x622060-vtable object. Forward
// a1 to the base constructor at 0x4A00E0 (which installs the 0x621F6C base
// vtable), install the derived vtable word 0x622060 at +0, then run the
// 0x4A2AC0 setup on this object and return this.
MATCH_FUNC(0x4A2370)
C_vt622060_4A2370::C_vt622060_4A2370(char* a1)
    : C_vt621F6C_4A00E0(a1)
{
    *(int*)((char*)this + 0) = 0x622060;
    ((C_vt622060*)this)->M_4A2AC0();
}

// 0x4A2AC0 — initialize the 0x622060 object's extension fields. No calls and
// no arguments; the stores follow the binary order exactly, including the
// split -1/0 defaults at +0x204/+0x318/+0x458, the 0xFFFFFF triple block, the
// +0x328..+0x32D byte range, the +0x350 = 2 default and the late +0x464/+0x480/
// +0x488/+0x490/+0x494/+0x7E0/+0x48C zeroing.
MATCH_FUNC(0x4A2AC0)
void C_vt622060::M_4A2AC0()
{
    *(int*)((char*)this + 0xf8) = 0x280;
    *(int*)((char*)this + 0xfc) = 0x1e0;
    *(unsigned char*)((char*)this + 0x100) = 0;
    *(int*)((char*)this + 0x204) = -1;
    *(int*)((char*)this + 0x208) = 0;
    *(int*)((char*)this + 0x20c) = 0;
    *(int*)((char*)this + 0x210) = 0;
    *(unsigned char*)((char*)this + 0x214) = 0;
    *(int*)((char*)this + 0x318) = -1;
    *(int*)((char*)this + 0x31c) = 0;
    *(int*)((char*)this + 0x320) = 0;
    *(int*)((char*)this + 0x324) = 0;
    *(unsigned char*)((char*)this + 0x328) = 0;
    *(unsigned char*)((char*)this + 0x329) = 0;
    *(unsigned char*)((char*)this + 0x32a) = 0;
    *(unsigned char*)((char*)this + 0x32b) = 0;
    *(unsigned char*)((char*)this + 0x32c) = 0;
    *(unsigned char*)((char*)this + 0x32d) = 0;
    *(int*)((char*)this + 0x330) = 0xffffff;
    *(int*)((char*)this + 0x334) = 0;
    *(int*)((char*)this + 0x338) = 0xffff;
    *(int*)((char*)this + 0x33c) = 0;
    *(int*)((char*)this + 0x340) = 0xffffff;
    *(int*)((char*)this + 0x344) = 0;
    *(int*)((char*)this + 0x348) = 0xffffff;
    *(int*)((char*)this + 0x34c) = 0;
    *(int*)((char*)this + 0x350) = 2;
    *(unsigned char*)((char*)this + 0x354) = 0;
    *(int*)((char*)this + 0x458) = -1;
    *(int*)((char*)this + 0x45c) = 0;
    *(int*)((char*)this + 0x460) = 0;
    *(unsigned char*)((char*)this + 0x468) = 0;
    *(unsigned char*)((char*)this + 0x469) = 0;
    *(int*)((char*)this + 0x46c) = 0;
    *(unsigned char*)((char*)this + 0x470) = 0;
    *(int*)((char*)this + 0x474) = 0;
    *(int*)((char*)this + 0x478) = 0;
    *(int*)((char*)this + 0x47c) = 0;
    *(int*)((char*)this + 0x464) = 0;
    *(int*)((char*)this + 0x480) = 0;
    *(int*)((char*)this + 0x488) = 0;
    *(int*)((char*)this + 0x490) = 0;
    *(int*)((char*)this + 0x494) = 0;
    *(int*)((char*)this + 0x7e0) = 0;
    *(int*)((char*)this + 0x48c) = 0;
}

// 0x4A3430 — load the object's +0x208 entry. Release any old entry (0x51EAE0
// then 0x5F90B0), seed the 0x104-byte name buffer, and, when a1 names a
// non-empty entry containing "none", build "%s" or "%s.shp" and allocate a
// 0x1C entry with (Buffer, FileHandle). Otherwise, when FileHandle != -1,
// allocate the entry from the empty default name and FileHandle. Store the new
// entry at +0x208; if it has not been marked valid at +0x14, delete it and
// clear the field. Return whether the field is still non-null.
MATCH_FUNC(0x4A3430)
int C_vt622060::M_4A3430(char* Str, int FileHandle)
{
    char Buffer[260];
    T51E7F0Entry* old = *(T51E7F0Entry**)((char*)this + 0x208);
    if (old != 0)
    {
        old->~T51E7F0Entry();
        sub_5F90B0((int)old);
        *(void**)((char*)this + 0x208) = 0;
    }
    if (Str != 0 && *Str != 0 && sub_5FF460(Str, (char*)ADDR(0x653520)) != 0)
    {
        if (sub_5FEE50(Str, '.') == 0)
            sub_5FCE14(Buffer, "%s.shp", Str);
        else
            sub_5FCE14(Buffer, "%s", Str);
        *(T51E7F0Entry**)((char*)this + 0x208) =
            new T51E7F0Entry(Buffer, FileHandle);
    }
    else if (FileHandle != -1)
    {
        *(T51E7F0Entry**)((char*)this + 0x208) =
            new T51E7F0Entry((char*)ADDR(0x662be0), FileHandle);
    }
    if (*(T51E7F0Entry**)((char*)this + 0x208) != 0 &&
        (*(T51E7F0Entry**)((char*)this + 0x208))->field_14 == 0)
    {
        delete *(T51E7F0Entry**)((char*)this + 0x208);
        *(void**)((char*)this + 0x208) = 0;
    }
    return *(int*)((char*)this + 0x208) != 0;
}

// 0x4A35A0 — sibling of 0x4A3430 for the +0x20C entry. Same release/load/build/
// allocate/validate sequence; the only difference is the entry field offset.
MATCH_FUNC(0x4A35A0)
int C_vt622060::M_4A35A0(char* Str, int FileHandle)
{
    char Buffer[260];
    T51E7F0Entry* old = *(T51E7F0Entry**)((char*)this + 0x20c);
    if (old != 0)
    {
        old->~T51E7F0Entry();
        sub_5F90B0((int)old);
        *(void**)((char*)this + 0x20c) = 0;
    }
    if (Str != 0 && *Str != 0 && sub_5FF460(Str, (char*)ADDR(0x653520)) != 0)
    {
        if (sub_5FEE50(Str, '.') == 0)
            sub_5FCE14(Buffer, "%s.shp", Str);
        else
            sub_5FCE14(Buffer, "%s", Str);
        *(T51E7F0Entry**)((char*)this + 0x20c) =
            new T51E7F0Entry(Buffer, FileHandle);
    }
    else if (FileHandle != -1)
    {
        *(T51E7F0Entry**)((char*)this + 0x20c) =
            new T51E7F0Entry((char*)ADDR(0x662be0), FileHandle);
    }
    if (*(T51E7F0Entry**)((char*)this + 0x20c) != 0 &&
        (*(T51E7F0Entry**)((char*)this + 0x20c))->field_14 == 0)
    {
        delete *(T51E7F0Entry**)((char*)this + 0x20c);
        *(void**)((char*)this + 0x20c) = 0;
    }
    return *(int*)((char*)this + 0x20c) != 0;
}
