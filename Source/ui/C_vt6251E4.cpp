#include "C_vt6251E4.hpp"
#include "matched_mem.h"

extern void* g_6645c4;
extern void __cdecl Free_5F90B0(void* p);

// The 0x6645C4 app's +0x1C game-settings object.
class T4EFD70Game {
public:
    int Get_5BFBF0();
    int M_464E80(char*** names, int* a2);
    void M_464DB0(int idx);
    void M_464FB0(int a1);
    // Inline wrapper: clearing *names inside it is what places the zero store
    // after both argument pushes (as in the original) instead of before them.
    int GetNames(char*** names, int* a2)
    {
        *names = 0;
        return M_464E80(names, a2);
    }
};

// The 0x6645C4 app object as used here.
class T4EFD70App {
public:
    char pad_00[4];
    unsigned char field_4;        // +0x04 current menu mode
    char pad_05[0x1c - 0x05];
    T4EFD70Game* field_1c;        // +0x1C
    char pad_20[0x9e0 - 0x20];
    int field_9e0;                // +0x9E0 profile ready

    int M_41CE60();
    int M_41F0C0(int a1);
    void M_41F5F0();
    int M_41F8A0();
    int M_421A50();
    void M_421AF0(int a1);
    void Hook_421E60();
    void SetByte_5B4550(int a1);
};

// The 0x66EA48 screen manager.
class T4EFD70Screens {
public:
    int M_49F770(char* name, int a2);
    int M_49F960(char* name);
};

#define APP ((T4EFD70App*)g_6645c4)
#define SCREENS ((T4EFD70Screens*)ADDR(0x66ea48))

// 0x4EB4B0 — the menu's constructor ("Main Menu"). It is written as the ctor of a
// separate address-suffixed class over the real base screen (ctor 0x4B9B30,
// dtor 0x4B9B50, which is the EH state-0 unwind action); the panel_ez helpers
// it calls are declared on that base. Registry: HKCR\http\shell\open\command
// gives the browser path (+0xB07) and command line (+0xA08).
#include <stdio.h>

typedef void* HKEY_;
extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(HKEY_ key, const char* sub,
    unsigned long res, char* cls, unsigned long opt, unsigned long sam, void* sa,
    HKEY_* out, unsigned long* disp);
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(HKEY_ key, const char* name,
    unsigned long* res, unsigned long* type, unsigned char* data, unsigned long* cb);
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(HKEY_ key);

extern char g_vt_6251E4;
extern int g_64d4b0;
extern int g_64d4b4;
extern unsigned char g_64d4ac;

struct R6251Rect {
    int x0, y0, x1, y1;
};

// Child panel interface used by the screen (vtable slots used here only).
class T6251Panel {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05(int a1);                                     // +0x14
    virtual void Vt_06(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
                       int a8, int a9, int a10, int a11, int a12, int a13);  // +0x18
    virtual void Vt_07(int x, int y, int w, int h);                 // +0x1C
    virtual void Vt_08();
    virtual void Vt_09();
    virtual void Vt_10();
    virtual void Vt_11();
    virtual void Vt_12();
    virtual void Vt_13();
    virtual void Vt_14();
    virtual void Vt_15();
    virtual void Vt_16();
    virtual void Vt_17();
    virtual void Vt_18();
    virtual void Vt_19();
    virtual void Vt_20();
    virtual void Vt_21();
    virtual void Vt_22();
    virtual void Vt_23();
    virtual void Vt_24();
    virtual void Vt_25();
    virtual void Vt_26();
    virtual void Vt_27();
    virtual void Vt_28();
    virtual void Vt_29();
    virtual void Vt_30();
    virtual void Vt_31();
    virtual void Vt_32();
    virtual void Vt_33();
    virtual void Vt_34();
    virtual void Vt_35();
    virtual void Vt_36();
    virtual void Vt_37();
    virtual void Vt_38();
    virtual void Vt_39();
    virtual void Vt_40();
    virtual void Vt_41();
    virtual void Vt_42();
    virtual void Vt_43();
    virtual void Vt_44();
    virtual void Vt_45();
    virtual void Vt_46();
    virtual void Vt_47();
    virtual void Vt_48();
    virtual void Vt_49();
    virtual void Vt_50();
    virtual void Vt_51();
    virtual void Vt_52();
    virtual void Vt_53();
    virtual void Vt_54();
    virtual void Vt_55();
    virtual void Vt_56();
    virtual void Vt_57();
    virtual void Vt_58();
    virtual void Vt_59();
    virtual void Vt_60();
    virtual void Vt_61();
    virtual void Vt_62(int id);                                     // +0xF8
    virtual void Vt_63();
    virtual void Vt_64();
    virtual void Vt_65();
    virtual void Vt_66();
    virtual void Vt_67(int a1, int a2, int a3, int a4, int a5, int a6, int a7);  // +0x10C

    void M_4A1E50(int a1, short a2);
    void M_4BBA80(int a1, int a2);
    void M_4BBAC0(int a1, unsigned char a2);
    int M_4BD6A0(R6251Rect* r);
    void M_4AF4B0(short a1, int a2, int a3);
    void M_4AF860(int a1);
    void M_4B0EA0(int a1);
    void M_5A6780();
    void M_5A67A0();
    void M_5A67B0(int a1);
    void M_5A6830(int a1);

    char pad_04[0xdc - 4];
    int field_dc;                 // +0xDC
    char pad_e0[0x174 - 0xe0];
    int field_174;                // +0x174

    void Set174(int v) { field_174 = v; }
};

// 0x624-byte button (ctor 0x5A5C50).
class T6251Button : public T6251Panel {
public:
    T6251Button(int a1, void* a2, int a3, int a4, int a5, int a6, void* a7);
    char pad_178[0x624 - 0x178];
};

// 0x244-byte picture (ctor 0x4B7F20). The name buffer and resource/flags the
// 0x4B8040 setter writes live at +0xF8/+0x1FC/+0x200/+0x204/+0x20C/+0x210/
// +0x214 are addressed as raw offsets so this declaration keeps the original
// 0x244-byte tail layout (naming them in the class changed the 4EB4B0 EH frame).
// WIP: the original holds `this` in EBX and the name argument in EBP; this
// translation spills `this` and assigns the source register differently, so
// ours is 272 vs 279 bytes although every store and callee is present.
class T6251Pic : public T6251Panel {
public:
    T6251Pic();
    int M_4B8040(int a1, void* a2, int a3, int a4, int a5, int a6, char* a7,
                 int a8, int a9, int a10);
    int Get_47DA00();
    int Get_5C07A0();
    char pad_178[0x244 - 0x178];
};

// Callees of the picture setter, matched elsewhere and called on this object.
class C_TRIBE_Screen_Options {
public:
    int M_4A0460(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};
class C_pnl_pic {
public:
    void M_4B83D0();
};
class T4B81C0 {
public:
    int M_4B81C0();
};
class T51EB40 {
public:
    char M_51EB40(int a2, int* a3, int* a4);
};



// 0x2584-byte object at +0x9F8 (ctor 0x4378D0).
class T6251Obj9F8 {
public:
    T6251Obj9F8();
    char pad[0x2584];
};

// 0x1C-byte shape at +0xC20 (ctor 0x51E7F0).
class T6251Shape {
public:
    T6251Shape(char* name, int id);
    char pad_00[0x14];
    unsigned char field_14;       // +0x14 loaded
    char pad_15[0x1c - 0x15];
};

struct T6251Pal {
    int f0, f4, f8;
};

class T6251App {
public:
    T6251Pal* Entry_41F6A0(int index);
    int Hook_41F6E0(int a1);
    char* M_41CE60();
    int M_4218A0(int a1);
    void Set9D0_421B60(unsigned char v);
    char pad_00[4];
    unsigned char field_04;       // +0x04
    char pad_05[0x6c - 5];
    int field_6c;                 // +0x6C
};

class T6251Sub1610 {
public:
    void M_423AC0();
};

class T6251Game {
public:
    void Set1C68_4329B0(int v);
    char pad_00[0x1610];
    T6251Sub1610* field_1610;     // +0x1610
};

class T6251Reg {
public:
    char* M_4BE010(int a1, char* name);
};

extern void* g_664520;
extern void* g_66451c;
#define APP6251 ((T6251App*)g_6645c4)
#define GAME6251 ((T6251Game*)g_664520)
#define REG6251 ((T6251Reg*)g_66451c)

// Base screen (ctor 0x4B9B30, dtor 0x4B9B50).
class TScreen6251 {
public:
    TScreen6251(char* name);
    ~TScreen6251();

    int M_4B9B60(int a1, char* a2, int a3, int a4);
    void Set_4A39C0(int a, int b);
    void SetInt_4A39E0(int v);
    void SetF8_4A3410(int a, int b);
    char* GetString_4A2180(int id);
    void GetString_4A2140(int id, char* buf, int len);
    int M_4A4830(void* parent, T6251Panel** out, char* text, int x, int y, int w, int h,
                 int font, int a9, int a10, int a11);
    int M_4A4570(void* parent, T6251Panel** out, int id, int x, int y, int w, int h,
                 int font, int a9, int a10, int a11);
    int M_4A3D40(void* parent, T6251Panel** out, int id, int a4, int a5, int a6, int a7,
                 int a8, int a9, int a10, int a11);
    int M_4A3DE0(void* parent, T6251Panel** out, char* text, int id, int x, int y, int w,
                 int h, int font, int a10, int a11);
    int M_4A4CE0(void* parent, T6251Panel** out, char* text, int len, int a5, int x, int y,
                 int w, int h, int font, int a11, int a12, int a13);
    int M_4A5230(void* parent, T6251Panel** out, int x, int y, int w, int h, int font);
    int M_4A55F0(T6251Panel** out, T6251Panel* list, int w);
    int M_4A5640(void* parent, T6251Panel** out, int a3, int a4, int a5, int x, int y,
                 int w, int h);
    void M_4A66F0(T6251Panel* p);
    void SetInt_4A3900(int v);
    void SetInt_4A6500(T6251Panel* p);
    void Set_4A64F0();
    void M_4A6520(T6251Panel* p, int id, int a3);

    char pad_00[0xc];
    int field_c;                  // +0x0C
    char pad_10[0x20 - 0x10];
    int field_20;                 // +0x20
    char pad_24[0xdc - 0x24];
    int field_dc;                 // +0xDC
    char pad_e0[0x328 - 0xe0];
    unsigned char field_328;      // +0x328
    unsigned char field_329;
    unsigned char field_32a;
    unsigned char field_32b;
    unsigned char field_32c;
    unsigned char field_32d;
    char pad_32e[0x7ec - 0x32e];
};

class C_vt6251E4_4EB4B0 : public TScreen6251 {
public:
    C_vt6251E4_4EB4B0();

    void M_4ECF00();
    void M_4ED000();
    void M_4ED180();
    void M_4ECF80();
    void M_4ED280();
    void M_4ED360(int a1);
    void M_4F0D70();
    void M_4ED630(int a1);
    void M_4EFD70(int a1);
    void M_4EE210();

    int field_7ec;                // +0x7EC
    int field_7f0;
    int field_7f4;
    int field_7f8;
    T6251Panel* field_7fc;        // +0x7FC
    int field_800;
    int field_804;
    int field_808;
    T6251Button* field_80c[9];    // +0x80C
    T6251Panel* field_830[9];     // +0x830
    T6251Panel* field_854[19];    // +0x854
    T6251Panel* field_8a0;        // +0x8A0
    T6251Panel* field_8a4;
    T6251Panel* field_8a8;
    T6251Panel* field_8ac;
    T6251Panel* field_8b0;
    T6251Panel* field_8b4;
    T6251Panel* field_8b8;
    T6251Panel* field_8bc;
    T6251Panel* field_8c0;
    T6251Panel* field_8c4;
    T6251Panel* field_8c8;
    T6251Pic* field_8cc;
    T6251Panel* field_8d0;
    int field_8d4;
    T6251Panel* field_8d8;
    T6251Panel* field_8dc;
    int field_8e0;
    int field_8e4;
    T6251Panel* field_8e8;
    T6251Panel* field_8ec;
    int field_8f0;
    T6251Panel* field_8f4;
    T6251Panel* field_8f8;
    T6251Panel* field_8fc;
    T6251Panel* field_900;
    T6251Panel* field_904;
    T6251Panel* field_908;
    T6251Panel* field_90c;
    T6251Panel* field_910;
    T6251Panel* field_914;
    T6251Panel* field_918;
    T6251Panel* field_91c;
    T6251Panel* field_920;
    T6251Panel* field_924;
    T6251Panel* field_928;
    T6251Panel* field_92c;
    T6251Panel* field_930;
    T6251Panel* field_934;
    T6251Panel* field_938[4];     // +0x938 (optional, paired with +0x948)
    T6251Panel* field_948[4];     // +0x948
    T6251Panel* field_958[3];     // +0x958 (optional, paired with +0x964)
    T6251Panel* field_964[3];     // +0x964
    T6251Panel* field_970;
    T6251Panel* field_974;
    T6251Panel* field_978;
    T6251Panel* field_97c;
    T6251Panel* field_980;
    int field_984;
    T6251Panel* field_988;
    T6251Panel* field_98c;
    T6251Panel* field_990;
    T6251Panel* field_994;
    T6251Panel* field_998;
    T6251Panel* field_99c;
    T6251Panel* field_9a0;
    T6251Panel* field_9a4;
    char pad_9a8[0x9b8 - 0x9a8];
    T6251Panel* field_9b8;        // +0x9B8
    char pad_9bc[0x9e8 - 0x9bc];
    T6251Panel* field_9e8;        // +0x9E8
    T6251Panel* field_9ec;
    T6251Panel* field_9f0;
    int field_9f4;
    T6251Obj9F8* field_9f8;
    int field_9fc;
    int field_a00;
    int field_a04;
    char field_a08[0xff];         // +0xA08 browser command line
    char field_b07[0x105];        // +0xB07 browser path
    int field_c0c;
    char pad_c10[0xc18 - 0xc10];
    int field_c18;
    int field_c1c;
    T6251Shape* field_c20;
    unsigned char field_c24;
    unsigned char field_c25;
    char pad_c26[0xc2c - 0xc26];
    unsigned char field_c2c;
};

// Matched with: the vtable written as the first body statement, field stores in
// binary order, the 0x6645C4 +0x6C argument read into a local first and the
// +0x174 clear through an inline setter (both only fix VC6's register choice
// for later temps), and `rect.x1 - field_c + k` for the two x positions.
MATCH_FUNC(0x4EB4B0)
C_vt6251E4_4EB4B0::C_vt6251E4_4EB4B0() : TScreen6251("Main Menu")
{
    *(void**)this = &g_vt_6251E4;
    field_7ec = 0;
    field_7f0 = 0;
    field_7f4 = 0;
    field_7f8 = 0;
    field_7fc = 0;
    field_800 = 0;
    field_804 = 0;
    field_808 = 0;
    field_c0c = 0;
    field_8a4 = 0;
    field_8a8 = 0;
    field_8ac = 0;
    field_8b0 = 0;
    field_8b4 = 0;
    field_8b8 = 0;
    field_8bc = 0;
    field_8c0 = 0;
    field_8c4 = 0;
    field_8c8 = 0;
    field_8cc = 0;
    field_8d0 = 0;
    field_9f4 = 0;
    field_c2c = 0;
    field_9fc = -10;
    field_c18 = -1;
    field_8e8 = 0;
    field_8ec = 0;
    field_8e0 = 0;
    field_8e4 = 0;
    field_8d4 = 0;
    field_8d8 = 0;
    field_8dc = 0;
    field_8fc = 0;
    field_c20 = 0;
    field_c24 = 0xff;
    field_8f0 = 0;
    field_9b8 = 0;
    field_9e8 = 0;
    field_9ec = 0;
    field_9f0 = 0;
    field_c25 = 0;
    field_c1c = 0;
    field_a00 = 0;
    field_a04 = 0;
    field_900 = 0;
    field_904 = 0;
    field_908 = 0;
    field_90c = 0;
    field_910 = 0;
    field_914 = 0;
    field_918 = 0;
    field_91c = 0;
    field_920 = 0;
    field_924 = 0;
    field_928 = 0;
    field_92c = 0;
    field_8f4 = 0;
    field_930 = 0;
    field_934 = 0;
    field_938[3] = 0;
    field_938[2] = 0;
    field_938[1] = 0;
    field_938[0] = 0;
    field_958[2] = 0;
    field_958[1] = 0;
    field_958[0] = 0;
    field_948[3] = 0;
    field_948[2] = 0;
    field_948[1] = 0;
    field_948[0] = 0;
    field_964[2] = 0;
    field_964[1] = 0;
    field_964[0] = 0;
    field_970 = 0;
    field_974 = 0;
    field_978 = 0;
    field_97c = 0;
    field_980 = 0;
    field_988 = 0;
    field_98c = 0;
    field_8f8 = 0;
    field_9a0 = 0;
    field_9a4 = 0;

    T6251Pal* pal;
    int x;
    HKEY_ key;
    unsigned long type;
    unsigned long cb;
    R6251Rect rect;
    unsigned long disp;
    char text[0x200];
    char data[0x100];
    char line[0x600];
    int i;

    GAME6251->field_1610->M_423AC0();
    for (i = 0; i < 9; i++)
    {
        field_80c[i] = 0;
        field_830[i] = 0;
    }
    for (i = 0; i < 19; i++)
        field_854[i] = 0;

    int a6c = APP6251->field_6c;
    if (!M_4B9B60(a6c, "main", 0xc3a1, 1))
    {
        field_dc = 1;
        return;
    }
    Set_4A39C0(0, 0);
    SetInt_4A39E0(0);
    SetF8_4A3410(800, 600);
    field_9f8 = new T6251Obj9F8();
    pal = APP6251->Entry_41F6A0(6);
    field_c20 = new T6251Shape("main.slp", 0xc437);
    if (!field_c20 || !field_c20->field_14)
    {
        field_dc = 1;
        return;
    }

    sprintf(text, GetString_4A2180(0x3ee), g_64d4b0);
    M_4A4830(this, &field_7fc, text, 0x186, 0x1fb, 0x195, 0x5a, 10, 0, 0, 1);
    M_4A66F0(field_7fc);
    M_4ECF00();
    M_4ED000();
    M_4ED180();
    M_4ECF80();
    M_4ED280();

    if (!M_4A4830(this, &field_9a0, "", 0x1c2, 5, 0x144, 0x35, 0xb, 0, 0, 1))
        return;
    if (!M_4A4830(this, &field_9a4, "", 0x1b5, 0x44, 0x162, 0x18b, 0xb, 0, 0, 1))
        return;
    field_9a0->Vt_67(3, field_328, field_329, field_32a, field_32b, field_32c, field_32d);
    field_9a4->Vt_67(3, field_328, field_329, field_32a, field_32b, field_32c, field_32d);
    field_9a0->M_4A1E50(2, 0);
    field_9a4->M_4A1E50(2, 0);
    field_9a0->Vt_05(0);
    field_9a4->Vt_05(0);

    if (!M_4A3D40(this, &field_8a0, 0x3ea, 0, 0, 0, 0, 0, -1, -1, 0))
        return;
    field_8a0->Vt_06(9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, 0, 0, 0, 0);

    x = APP6251->Hook_41F6E0(0x1c);
    for (i = 0; i < 9; i++)
    {
        field_80c[i] = new T6251Button(field_20, this, x, pal->f0, pal->f4, pal->f8, field_c20);
        if (!field_80c[i] || field_80c[i]->field_dc)
        {
            field_dc = 1;
            return;
        }
        field_80c[i]->M_5A6780();
        field_80c[i]->M_4B0EA0(i + 0x1c);
    }
    for (i = 0; i < 9; i++)
    {
        M_4A4830(this, &field_830[i], "", 0, 0, 0, 0, 0xb, 1, 0, 0);
        M_4A66F0(field_830[i]);
        field_830[i]->M_4A1E50(1, 0);
    }

    field_80c[0]->M_4AF4B0(0, 0, 0);
    field_80c[1]->M_4AF4B0(0, 1, 0);
    field_80c[2]->M_4AF4B0(0, 2, 0);
    field_80c[3]->M_4AF4B0(0, 3, 0);
    field_80c[4]->M_4AF4B0(0, 4, 0);
    field_80c[5]->M_4AF4B0(0, 5, 0);
    field_80c[6]->M_4AF4B0(0, 6, 0);
    field_80c[7]->M_4AF4B0(0, 7, 0);
    field_80c[8]->M_4AF4B0(0, 8, 0);
    field_80c[0]->M_4AF860(x);
    field_80c[1]->M_4AF860(x);
    field_80c[2]->M_4AF860(x);
    field_80c[3]->M_4AF860(x);
    field_80c[4]->M_4AF860(x);
    field_80c[5]->M_4AF860(x);
    field_80c[6]->M_4AF860(x);
    field_80c[7]->M_4AF860(x);
    field_80c[8]->M_4AF860(x);
    field_80c[3]->M_4A1E50(1, 0);
    field_830[3]->M_4A1E50(1, 0);

    field_80c[0]->Vt_07(0x132, 7, 0x7d, 0xc5);
    field_80c[1]->Vt_07(0x102, 0xd6, 0x69, 0x88);
    field_80c[3]->Vt_07(0x64, 0xa1, 0x6d, 0x67);
    field_80c[2]->Vt_07(0xc2, 0x10f, 0x4c, 0x48);
    field_80c[4]->Vt_07(0x86, 0x24, 0x94, 0x5b);
    field_80c[6]->Vt_07(0, 0x215, 0xa2, 0x43);
    field_80c[5]->Vt_07(0, 4, 0x7d, 0xbb);
    field_80c[7]->Vt_07(0x61, 0x158, 0x64, 0x69);
    field_80c[8]->Vt_07(0x10c, 0x16c, 0x4a, 0x46);
    field_80c[0]->M_5A6830(0xa);
    field_80c[1]->M_5A6830(0xe);
    field_80c[3]->M_5A6830(0x1e);
    field_80c[2]->M_5A6830(0x1a);
    field_80c[4]->M_5A6830(0x2a);
    field_80c[6]->M_5A6830(0x2e);
    field_80c[5]->M_5A6830(0x16);
    field_80c[7]->M_5A6830(0x22);
    field_80c[8]->M_5A6830(0x12);
    field_80c[0]->M_5A67B0(0xb);
    field_80c[1]->M_5A67B0(0xf);
    field_80c[3]->M_5A67B0(0x1f);
    field_80c[2]->M_5A67B0(0x1b);
    field_80c[4]->M_5A67B0(0x2b);
    field_80c[6]->M_5A67B0(0x2f);
    field_80c[5]->M_5A67B0(0x17);
    field_80c[7]->M_5A67B0(0x23);
    field_80c[8]->M_5A67B0(0x13);
    field_80c[0]->M_5A67A0();
    field_80c[1]->M_5A67A0();
    field_80c[3]->M_5A67A0();
    field_80c[2]->M_5A67A0();
    field_80c[4]->M_5A67A0();
    field_80c[6]->M_5A67A0();
    field_80c[5]->M_5A67A0();
    field_80c[7]->M_5A67A0();
    field_80c[8]->M_5A67A0();

    field_830[0]->Vt_07(0x119, 0x15, 0xb4, 0x12);
    field_830[1]->Vt_07(0xe2, 0xe0, 0xb4, 0x12);
    field_830[3]->Vt_07(0x44, 0xab, 0xb4, 0x12);
    field_830[2]->Vt_07(0x8e, 0x116, 0xb4, 0x12);
    field_830[6]->Vt_07(0, 0x232, 0xa0, 0x12);
    field_830[5]->Vt_07(0, 0x10, 0x7f, 0x12);
    field_830[7]->Vt_07(0x3c, 0x160, 0xb4, 0x12);
    field_830[8]->Vt_07(0xd7, 0x173, 0xb4, 0x12);
    field_830[0]->Vt_62(0x251c);
    field_830[1]->Vt_62(0x251d);
    field_830[3]->Vt_62(0x2521);
    field_830[2]->Vt_62(0x2520);
    field_830[6]->Vt_62(0x2525);
    field_830[5]->Vt_62(0x251f);
    field_830[7]->Vt_62(0x2522);
    field_830[8]->Vt_62(0x251e);
    field_830[0]->M_4BBAC0(2, 0);
    field_830[1]->M_4BBAC0(2, 0);
    field_830[3]->M_4BBAC0(2, 0);
    field_830[2]->M_4BBAC0(2, 0);
    field_830[4]->M_4BBAC0(2, 0);
    field_830[6]->M_4BBAC0(2, 0);
    field_830[5]->M_4BBAC0(2, 0);
    field_830[7]->M_4BBAC0(2, 0);
    field_830[8]->M_4BBAC0(2, 0);

    SetInt_4A3900(0);
    for (i = 0; i < 19; i++)
    {
        if (!M_4A3DE0(this, &field_854[i], "", 0, 0x1c2, 0x84 + i * 0x32, 0x96, 0x28, 0, 0, 0))
            return;
        if (field_854[i])
            field_854[i]->Vt_05(0);
    }

    if (!M_4A5230(this, &field_8e8, 0x1c8, 0xe1, 0x12c, 0x96, 0xb))
        return;
    if (!M_4A55F0(&field_8ec, field_8e8, 0x14))
        return;
    field_8e8->Vt_05(0);
    field_8e8->Set174(0);
    if (!M_4A5230(this, &field_9e8, 0x1b1, 0x5f, 0x168, 0x46, 0xb))
        return;
    if (!M_4A55F0(&field_9ec, field_9e8, 0x14))
        return;
    field_9e8->Vt_05(0);

    if (APP6251->M_41CE60())
        strcpy(line, APP6251->M_41CE60());
    else
        line[0] = 0;
    if (REG6251->M_4BE010(1, "Default Age Of Empires MP Gamename"))
        strcpy(line, REG6251->M_4BE010(1, "Default Age Of Empires MP Gamename"));
    else
        strcpy(line, "My Game");
    if (!M_4A4CE0(this, &field_9b8, line, 0x28, 0, 0x1c8, 0x52, 0x12c, 0x17, 0xb, 1, 0, 1))
        return;
    field_9b8->Vt_05(0);

    line[0] = 0;
    M_4A4830(this, &field_9f0, line, 0xc8, 0x226, 0x12c, 0x32, 0xb, 1, 0, 0);
    field_9f0->Vt_05(0);
    M_4A4830(this, &field_8f4, "", 0x1e3, 0x1e, 0xf7, 0x12, 0xb, 1, 0, 0);
    M_4A66F0(field_8f4);
    field_8f4->Vt_05(0);
    GetString_4A2140(0x23fb, text, 0x200);
    M_4A4830(this, &field_8d8, text, 0x161, 0x3b, 0x12c, 0x32, 0xb, 1, 0, 0);
    field_8d8->Vt_05(0);
    GetString_4A2140(0x23fc, text, 0x200);
    M_4A4830(this, &field_8dc, text, 0x158, 0x46, 0x12c, 0x32, 0xb, 1, 0, 0);
    field_8dc->Vt_05(0);
    field_8dc->M_4BBA80(0xffffff, 0xffffff);
    M_4A4830(this, &field_8fc, "", 0x1e3, 8, 0xf7, 0x18, 0, 1, 0, 0);
    M_4A66F0(field_8fc);

    if (!M_4A5640(this, &field_904, 0x64, 0xa, 0x14, 0x1c2, 0x10e, 0x14, 0x64))
        return;
    if (!M_4A5640(this, &field_900, 0x64, 0xa, 0x14, 0x214, 0x10e, 0x14, 0x64))
        return;
    if (!M_4A5640(this, &field_908, 0x64, 0xa, 0x14, 0x26b, 0x10e, 0x14, 0x64))
        return;
    M_4A4570(this, &field_918, 0x252b, 0x1c2, 0xe6, 0x6c, 0x28, 0xb, 0, 0, 1);
    M_4A4570(this, &field_920, 0x252c, 0x1dc, 0x10e, 0x50, 0x28, 0xb, 0, 0, 1);
    M_4A4570(this, &field_91c, 0x252d, 0x1dc, 0x14c, 0x50, 0x28, 0xb, 0, 0, 1);
    M_4A4570(this, &field_90c, 0x252a, 0x214, 0xe6, 0x6c, 0x28, 0xb, 0, 0, 1);
    M_4A4570(this, &field_914, 0x252c, 0x22e, 0x10e, 0x50, 0x28, 0xb, 0, 0, 1);
    M_4A4570(this, &field_910, 0x252d, 0x22e, 0x14c, 0x50, 0x28, 0xb, 0, 0, 1);
    M_4A4570(this, &field_924, 0x252e, 0x26e, 0xe6, 0x6c, 0x28, 0xb, 0, 0, 1);
    M_4A4570(this, &field_92c, 0x252f, 0x288, 0x10e, 0x50, 0x28, 0xb, 0, 0, 1);
    M_4A4570(this, &field_928, 0x2530, 0x288, 0x14c, 0x50, 0x28, 0xb, 0, 0, 1);

    M_4A3D40(this, &field_980, 0x2539, 0, 0x1c2, 0xbc, 0xd2, 0x22, 0, 0, 0);
    if (!M_4A5230(this, &field_988, 0x1c2, 0x5b, 0xd2, 0x5a, 0xb))
        return;
    if (!M_4A55F0(&field_98c, field_988, 0x14))
        return;
    field_8e8->Vt_05(0);
    GetString_4A2140(0x23fd, text, 0x200);
    M_4A4830(this, &field_990, text, 0x1cc, 0x46, 0x78, 0x12, 0xb, 0, 0, 0);
    GetString_4A2140(0x23fe, text, 0x200);
    if (!M_4A3DE0(this, &field_994, text, 0, 0x298, 0x5b, 0x6e, 0x1c, 0xb, 0, 0))
        return;
    GetString_4A2140(0x23ff, text, 0x200);
    if (!M_4A3DE0(this, &field_998, text, 0, 0x298, 0x79, 0x6e, 0x1c, 0xb, 0, 0))
        return;
    GetString_4A2140(0x2400, text, 0x200);
    if (!M_4A3DE0(this, &field_99c, text, 0, 0x298, 0x97, 0x6e, 0x1c, 0xb, 0, 0))
        return;
    field_990->Vt_05(0);
    field_994->Vt_05(0);
    field_998->Vt_05(0);
    field_99c->Vt_05(0);
    M_4ED360(0);
    M_4F0D70();

    M_4A4830(this, &field_8a4, "", 0x1b4, 0x49, 0x152, 0x199, 0xa, 0, 0, 0);
    field_8a4->Vt_67(3, field_328, field_329, field_32a, field_32b, field_32c, field_32d);
    M_4A4570(this, &field_8a8, 0x2419, 0x1b8, 0x34, 0x14a, 0x32, 4, 0, 0, 1);
    sprintf(line, GetString_4A2180(0x241a), APP6251->M_4218A0(g_64d4ac));
    M_4A4830(this, &field_8ac, line, 0x1b8, 0x62, 0x14a, 0x12, 0xb, 0, 0, 0);
    GetString_4A2140(0x2424, text, 0x200);
    if (text[0] == 0)
    {
        M_4A4570(this, &field_8b0, 0x241b, 0x1b8, 0x74, 0x14a, 0x14, 0xa, 0, 0, 0);
        if (field_8b0 && field_8b0->M_4BD6A0(&rect))
        {
            field_8cc = new T6251Pic();
            if (field_8cc)
            {
                field_8cc->M_4B8040(field_20, this, rect.x1 - field_c + 6, 0x77, 0xf, 0xe,
                                    "circlep", 0xc4e0, 0, 1);
                sprintf(line, GetString_4A2180(0x241c), g_64d4b0);
                M_4A4830(this, &field_8b4, line,
                         field_8cc->Get_47DA00() - field_c + field_8cc->Get_5C07A0(),
                         0x74, 0x14a, 0x14, 0xa, 0, 0, 0);
            }
        }
    }
    else
    {
        strcpy(text, GetString_4A2180(0x241b));
        strcat(text, GetString_4A2180(0x2424));
        strcat(text, " ");
        sprintf(line, GetString_4A2180(0x241c), g_64d4b0);
        strcat(text, line);
        M_4A4830(this, &field_8b0, text, 0x1b8, 0x96, 0x14a, 0x14, 0xa, 0, 0, 0);
    }
    M_4A4570(this, &field_8b8, 0x241d, 0x1b8, 0x88, 0x14a, 0x14, 0xa, 0, 0, 0);
    sprintf(line, GetString_4A2180(0x2423), g_64d4b4);
    M_4A4830(this, &field_8bc, line, 0x1b8, 0x9c, 0x14a, 0x66, 0xa, 0, 0, 1);
    M_4A4570(this, &field_8c0, 0x241e, 0x1b8, 0x107, 0x5f, 0x14, 0xa, 0, 0, 0);
    if (field_8c0 && field_8c0->M_4BD6A0(&rect))
    {
        char* pid = REG6251->M_4BE010(0, "PID");
        if (!pid)
            pid = "00000-000-0000000-00000";
        sprintf(line, "%s", pid);
        M_4A4830(this, &field_8c4, line, rect.x1 - field_c + 4, 0x107, 0xc8, 0x14, 0xb, 0, 0, 0);
    }
    GetString_4A2140(0x241f, line, 0x600);
    M_4A4830(this, &field_8c8, line, 0x1b8, 0x120, 0x14a, 0xdc, 0xa, 0, 0, 1);
    M_4ED630(0);
    GAME6251->Set1C68_4329B0(0);
    M_4A4570(this, &field_8d0, 0x2544, 0x1cc, 0x78, 0x122, 0xc8, 0xb, 0, 0, 1);
    field_8d0->Vt_67(3, field_328, field_329, field_32a, field_32b, field_32c, field_32d);
    field_8d0->Vt_05(0);

    field_a08[0] = 0;
    field_b07[0] = 0;
    RegCreateKeyExA((HKEY_)0x80000000, "http\\shell\\open\\command", 0, 0, 0, 0xf003f, 0,
                    &key, &disp);
    type = 1;
    cb = 0xff;
    long rc = RegQueryValueExA(key, 0, 0, &type, (unsigned char*)data, &cb);
    if (key)
    {
        RegCloseKey(key);
        key = 0;
    }
    if (rc == 0)
    {
        strncpy(text, data + 1, strlen(data));
        char* q = strchr(text, '"');
        if (q)
        {
            int n = q - text + 1;
            strncpy(field_b07, text, n - 1);
            field_b07[n - 1] = 0;
        }
        char* r = strstr(data, "\"%1");
        if (r)
            *r = 0;
        char* zone = REG6251->M_4BE010(0, "Zone");
        if (zone)
            sprintf(field_a08, "%s %s", data, zone);
        else
            sprintf(field_a08, "%s %s", data, GetString_4A2180(0x2546));
    }

    M_4A4830(this, &field_8f8, "", 0x186, 0x1fa, 0x189, 0x5e, 0xb, 0, 0, 1);
    M_4A66F0(field_8f8);
    field_8f8->Vt_05(0);
    SetInt_4A6500(field_8f8);
    Set_4A64F0();
    M_4A6520(field_80c[0], 0x7918, 0x23);
    M_4A6520(field_80c[1], 0x7919, 0x23);
    M_4A6520(field_80c[3], 0x791d, 0x23);
    M_4A6520(field_80c[2], 0x791c, 0x23);
    M_4A6520(field_80c[4], 0x7920, 0x23);
    M_4A6520(field_80c[6], 0x7921, 0x23);
    M_4A6520(field_80c[5], 0x791b, 0x23);
    M_4A6520(field_80c[7], 0x791e, 0x23);
    M_4A6520(field_80c[8], 0x791a, 0x23);
    APP6251->Set9D0_421B60(0);
    M_4EFD70(APP6251->field_04);
    M_4EE210();
}

// 0x4ED360 — show/hide (slot +0x14) every main-menu child panel with a1, then
// reset the text colour (0x4BBA80: 0xFAFAFA, 0) of the label panels. The
// +0x938/+0x958 rows and +0x980 are optional; +0x990 is recoloured twice.
MATCH_FUNC(0x4ED360)
void C_vt6251E4_4EB4B0::M_4ED360(int a1)
{
    int i;

    field_900->Vt_05(a1);
    field_904->Vt_05(a1);
    field_908->Vt_05(a1);
    field_90c->Vt_05(a1);
    field_910->Vt_05(a1);
    field_914->Vt_05(a1);
    field_918->Vt_05(a1);
    field_91c->Vt_05(a1);
    field_920->Vt_05(a1);
    field_924->Vt_05(a1);
    field_928->Vt_05(a1);
    field_92c->Vt_05(a1);
    field_930->Vt_05(a1);
    field_934->Vt_05(a1);
    for (i = 0; i < 4; i++) {
        if (field_938[i])
            field_938[i]->Vt_05(a1);
        if (field_948[i])
            field_948[i]->Vt_05(a1);
    }
    for (i = 0; i < 3; i++) {
        if (field_958[i])
            field_958[i]->Vt_05(a1);
        if (field_964[i])
            field_964[i]->Vt_05(a1);
    }
    field_970->Vt_05(a1);
    field_974->Vt_05(a1);
    field_978->Vt_05(a1);
    field_97c->Vt_05(a1);
    if (field_980)
        field_980->Vt_05(a1);
    field_990->Vt_05(a1);
    field_988->Vt_05(a1);
    field_994->Vt_05(a1);
    field_998->Vt_05(a1);
    field_99c->Vt_05(a1);

    field_90c->M_4BBA80(0xfafafa, 0);
    field_910->M_4BBA80(0xfafafa, 0);
    field_914->M_4BBA80(0xfafafa, 0);
    field_918->M_4BBA80(0xfafafa, 0);
    field_91c->M_4BBA80(0xfafafa, 0);
    field_920->M_4BBA80(0xfafafa, 0);
    field_924->M_4BBA80(0xfafafa, 0);
    field_928->M_4BBA80(0xfafafa, 0);
    field_92c->M_4BBA80(0xfafafa, 0);
    field_930->M_4BBA80(0xfafafa, 0);
    for (i = 0; i < 4; i++) {
        if (field_938[i])
            field_938[i]->M_4BBA80(0xfafafa, 0);
        if (field_948[i])
            field_948[i]->M_4BBA80(0xfafafa, 0);
    }
    field_970->M_4BBA80(0xfafafa, 0);
    field_978->M_4BBA80(0xfafafa, 0);
    field_990->M_4BBA80(0xfafafa, 0);
    field_990->M_4BBA80(0xfafafa, 0);
}

// 0x4EFCA0 — show the mode-4 sub-panel: the +0x9A4 text gets string 0x2524
// (slot +0xF8), is shown and moved to (0x1B5, 0x27, 0x162, 0x1A4); hide +0x8FC,
// +0x9A0 and +0x8F4; the +0x854 list control is placed at (0x212, 0x22A, 0xF0,
// 0x28), labelled 0x2523, configured, shown and reset; then 0x4ED630(1).
MATCH_FUNC(0x4EFCA0)
void C_vt6251E4::M_4EFCA0()
{
    field_9a4->Vt_62(0x2524);
    field_9a4->Vt_05(1);
    field_9a4->Vt_07(0x1b5, 0x27, 0x162, 0x1a4);
    field_8fc->Vt_05(0);
    field_9a0->Vt_05(0);
    field_8f4->Vt_05(0);
    field_854[0]->Vt_07(0x212, 0x22a, 0xf0, 0x28);
    field_854[0]->M_4AF720(0, 0x2523);
    field_854[0]->M_4AF4B0(0, 0x12, 0);
    field_854[0]->Vt_05(1);
    field_854[0]->M_4A1E50(1, 0);
    M_4ED630(1);
}

// 0x4EFD70 — switch the main menu to mode `mode` (0..8, 0xFF = none). Without
// a player profile (+0x1C getter == -1) modes 0/1/5/7 reset the menu and open
// the 0x44CBD0 dialog instead. Otherwise, when the mode changes: hide every
// sub-panel, reset the nine buttons and their help ids, then per mode press
// the button, build the sub-panel and record the mode (+0xC24 and app +4);
// mode 3 opens the History Screen, mode 5 finds the "cam8" campaign and opens
// the Game Mission Dialog.
// Matched with: if/else-if instead of early returns, `goto done` exits,
// case 5 written last (that puts the shared Vt_08 tail right after case 0),
// the GetNames inline wrapper, and a function defined before it in the TU
// (as the only function in a TU, VC6 copies the EH epilogue into every exit).
MATCH_FUNC(0x4EFD70)
void C_vt6251E4::M_4EFD70(int mode)
{
    if (APP->field_1c->Get_5BFBF0() == -1
        && (mode == 0 || mode == 1 || mode == 5 || mode == 7))
    {
        M_4EFD70(0xff);
        APP->M_41F8A0();
        new T44CBD0_44CBD0(this, GetString_4A2180(0x240f), 1, mode);
    }
    else if (field_c24 != mode)
    {
    field_8fc->Vt_05(0);
    field_9a4->Vt_05(0);
    field_9a4->Vt_07(0x1b5, 0x44, 0x162, 0x18b);
    field_8f4->Vt_05(0);
    int i;
    for (i = 0; i < 19; i++)
        field_854[i]->Vt_05(0);
    M_4ED360(0);
    M_4ED310(0);
    M_4ED630(0);
    field_8d0->Vt_05(0);
    field_8e8->Vt_05(0);
    field_9e8->Vt_05(0);
    field_9b8->Vt_05(0);
    field_8d8->Vt_05(0);
    field_8dc->Vt_05(0);
    M_4F22F0(field_854[0], 0);
    for (i = 4; i < 7; i++)
        M_4F22F0(field_854[i], 0);
    if (mode != 0xff && APP->field_1c->Get_5BFBF0() != -1)
    {
        field_8f4->Vt_63(APP->M_41CE60(), 0);
        field_8f4->Vt_05(1);
    }
    field_80c->Switch_5A67D0(0);
    field_810->Switch_5A67D0(0);
    field_818->Switch_5A67D0(0);
    field_814->Switch_5A67D0(0);
    field_81c->Switch_5A67D0(0);
    field_824->Switch_5A67D0(0);
    field_820->Switch_5A67D0(0);
    field_828->Switch_5A67D0(0);
    field_82c->Switch_5A67D0(0);
    Set_4A64F0();
    M_4A6520(field_80c, 0x7918, 0x23);
    M_4A6520(field_810, 0x7919, 0x23);
    M_4A6520(field_818, 0x791d, 0x23);
    M_4A6520(field_814, 0x791c, 0x23);
    M_4A6520(field_81c, 0x7920, 0x23);
    M_4A6520(field_824, 0x7921, 0x23);
    M_4A6520(field_820, 0x791b, 0x23);
    M_4A6520(field_828, 0x791e, 0x23);
    M_4A6520(field_82c, 0x791a, 0x23);
    if (field_c24 == 1 && mode != 1)
    {
        field_c25 = 0;
        M_4ECE90();
    }
    switch (mode)
    {
    case 0:
        if (APP->field_9e0 == 0)
        {
            if (APP->M_41F0C0(0) == 0)
            {
                M_4A5CE0(0x7d8, 0, 0x1c2, 0x64, 1);
                goto done;
            }
            APP->field_9e0 = 1;
        }
        field_80c->Switch_5A67D0(1);
        M_4EF220();
        field_c24 = 0;
        APP->field_4 = 0;
        break;
    case 1:
        field_810->Switch_5A67D0(1);
        M_4EF780();
        field_c24 = 1;
        APP->field_4 = 1;
        break;
    case 2:
        if (APP->field_9e0 == 0)
        {
            if (APP->M_41F0C0(0) == 0)
            {
                M_4A5CE0(0x7d8, 0, 0x1c2, 0x64, 1);
                goto done;
            }
            APP->field_9e0 = 1;
        }
        field_814->Switch_5A67D0(1);
        M_4EFB00();
        field_c24 = 2;
        APP->field_4 = 2;
        break;
    case 3:
        field_c24 = 0xff;
        APP->field_4 = 0xff;
        field_818->Switch_5A67D0(1);
        APP->Hook_421E60();
        new T4EA260_4EA260;
        SCREENS->M_49F770("History Screen", 0);
        SCREENS->M_49F960("Main Menu");
        goto done;
    case 4:
        field_81c->Switch_5A67D0(1);
        M_4EFCA0();
        field_c24 = 4;
        break;
    case 6:
        M_4EE2D0();
        APP->M_41F5F0();
        field_c24 = 6;
        break;
    case 7:
        field_828->Switch_5A67D0(1);
        field_c24 = 7;
        APP->field_4 = 7;
        M_4EEC90();
        Vt_08(1);
        break;
    case 8:
        field_82c->Switch_5A67D0(1);
        M_4EEFC0();
        field_c24 = 8;
        APP->field_4 = 8;
        break;
    case 5:
    {
        field_c24 = 0xff;
        APP->field_4 = 0xff;
        field_820->Switch_5A67D0(1);
        int found = -1;
        APP->M_421A50();
        int extra;
        char** names;
        int n = APP->field_1c->GetNames(&names, &extra);
        if (n <= 0)
            break;
        for (i = 0; i < n; i++)
        {
            if (strcmp(names[i], "cam8") == 0)
            {
                found = i;
                break;
            }
        }
        for (i = 0; i < n; i++)
            Free_5F90B0(names[i]);
        Free_5F90B0(names);
        if (found == -1)
            break;
        M_4EE2D0();
        APP->M_421AF0(0);
        APP->field_1c->M_464DB0(found);
        APP->field_1c->M_464FB0(8);
        APP->SetByte_5B4550(8);
        APP->Hook_421E60();
        new T4E91A0_4E91A0(ADDR(0x662be0), 0, 0, 0);
        SCREENS->M_49F770("Game Mission Dialog", 0);
        SCREENS->M_49F960("Main Menu");
        goto done;
    }
    }
    Vt_08(1);
    }
done:;
}

// 0x4B8040 sits after 0x4EB4B0 on purpose: defined earlier in the TU, VC6
// drops the constructor's EH-state stores around its call (0x4EB4B0 breaks).
#pragma intrinsic(strcpy)
#pragma intrinsic(strlen)
WIP_FUNC(0x4B8040)
int T6251Pic::M_4B8040(int a1, void* a2, int a3, int a4, int a5, int a6,
                       char* a7, int a8, int a9, int a10)
{
    char* self = (char*)this;
    char* name = self + 0xf8;
    if (a7 != 0)
    {
        strcpy(name, a7);
        name[strlen(a7)] = 0;
    }
    else
        name[0] = 0;

    *(int*)(self + 0x1fc) = a8;
    *(int*)(self + 0x200) = a9;
    *(int*)(self + 0x204) = a10;

    int v16;
    int v17;
    if ((a9 != 0 || a10 != 0) && ((T4B81C0*)this)->M_4B81C0() != 0)
    {
        if (a9 != 0)
        {
            if (*(int*)(self + 0x20c) != 0)
            {
                int v19 = 0;
                ((T51EB40*)(size_t)*(int*)(self + 0x214))->M_51EB40(
                    0, (int*)&a7, &v19);
                v16 = (int)(size_t)a7;
                v17 = v19;
            }
            else
            {
                int v15 = *(int*)(self + 0x210);
                v16 = *(int*)((char*)(size_t)v15 + 20);
                v17 = *(int*)((char*)(size_t)v15 + 24);
            }
        }
        else
        {
            v17 = a6;
            v16 = a5;
        }
        if (*(int*)(self + 0x204) == 0)
            ((C_pnl_pic*)this)->M_4B83D0();
    }
    else
    {
        v17 = a6;
        v16 = a5;
    }

    ((C_TRIBE_Screen_Options*)this)->M_4A0460(
        (int)(size_t)a2, a3, a4, a5, v16, v17, 0);
    return 1;
}
#pragma function(strlen)
#pragma function(strcpy)
