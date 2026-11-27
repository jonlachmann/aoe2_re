// C_vt6251E4 — the main-menu screen (vtable 0x6251E4, panel_ez family; the
// 0x66EA48 screen-manager calls below go back to the "Main Menu" panel).
// Its 0x4EDC70 tick lives in free_ui.cpp; this TU holds the 0x4EFD70 mode
// switch that swaps the menu's sub-panels by the +0xC24 mode byte.
#pragma once

#include "Function.hpp"

// Child controls of the menu (text/picture panels): slot 5 (+0x14) shows or
// hides, slot 7 (+0x1C) sets the rect, slot 63 (+0xFC) takes a picture id.
class T6251Ctl {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05(int a1);                          // +0x14
    virtual void Vt_06();
    virtual void Vt_07(int a1, int a2, int a3, int a4);  // +0x1C
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
    virtual void Vt_62(int id);                          // +0xF8 set text id
    virtual void Vt_63(int a1, int a2);                  // +0xFC

    void M_4A1E50(int a1, int a2);
    void M_4AF4B0(int a1, int a2, int a3);
    void M_4AF720(int a1, int id);
};

// Menu buttons (pnl_btn): 0x5A67D0 sets the pressed state.
class T6251Btn {
public:
    int Switch_5A67D0(int a1);
};

// Dialog constructed when the game has no player profile (0x828 bytes).
class T44CBD0_44CBD0 {
public:
    virtual void slot_000();
    char pad_04[0x828 - 0x04];
    T44CBD0_44CBD0(void* parent, char* text, int a3, int mode);
};

// "History Screen" (0x810 bytes).
class T4EA260_4EA260 {
public:
    virtual void slot_000();
    char pad_04[0x810 - 0x04];
    T4EA260_4EA260();
};

// "Game Mission Dialog" (0x978 bytes).
class T4E91A0_4E91A0 {
public:
    virtual void slot_000();
    char pad_04[0x978 - 0x04];
    T4E91A0_4E91A0(void* a1, int a2, int a3, int a4);
};

class C_vt6251E4 {
public:
    virtual void Vt_00();
    virtual void Vt_01();
    virtual void Vt_02();
    virtual void Vt_03();
    virtual void Vt_04();
    virtual void Vt_05();
    virtual void Vt_06();
    virtual void Vt_07();
    virtual void Vt_08(int a1);                          // +0x20 redraw
    char pad_04[0x80c - 0x04];
    T6251Btn* field_80c;          // +0x80C button, mode 0
    T6251Btn* field_810;          // +0x810 button, mode 1
    T6251Btn* field_814;          // +0x814 button, mode 2
    T6251Btn* field_818;          // +0x818 button, mode 3 (history)
    T6251Btn* field_81c;          // +0x81C button, mode 4
    T6251Btn* field_820;          // +0x820 button, mode 5 (campaign)
    T6251Btn* field_824;          // +0x824 button
    T6251Btn* field_828;          // +0x828 button, mode 7
    T6251Btn* field_82c;          // +0x82C button, mode 8
    char pad_830[0x854 - 0x830];
    T6251Ctl* field_854[19];      // +0x854 sub-panel controls
    char pad_8a0[0x8d0 - 0x8a0];
    T6251Ctl* field_8d0;          // +0x8D0
    char pad_8d4[0x8d8 - 0x8d4];
    T6251Ctl* field_8d8;          // +0x8D8
    T6251Ctl* field_8dc;          // +0x8DC
    char pad_8e0[0x8e8 - 0x8e0];
    T6251Ctl* field_8e8;          // +0x8E8
    char pad_8ec[0x8f4 - 0x8ec];
    T6251Ctl* field_8f4;          // +0x8F4
    char pad_8f8[0x8fc - 0x8f8];
    T6251Ctl* field_8fc;          // +0x8FC
    char pad_900[0x9a0 - 0x900];
    T6251Ctl* field_9a0;          // +0x9A0
    T6251Ctl* field_9a4;          // +0x9A4
    char pad_9a8[0x9b8 - 0x9a8];
    T6251Ctl* field_9b8;          // +0x9B8
    char pad_9bc[0x9e8 - 0x9bc];
    T6251Ctl* field_9e8;          // +0x9E8
    char pad_9ec[0xc24 - 0x9ec];
    unsigned char field_c24;      // +0xC24 menu mode
    unsigned char field_c25;      // +0xC25

    // panel_ez helpers (this-based)
    char* GetString_4A2180(int id);
    void M_4A5CE0(int a1, int a2, int a3, int a4, int a5);
    void Set_4A64F0();
    void M_4A6520(T6251Btn* btn, int id, int a3);

    // menu-local
    void M_4ECE90();
    void M_4ED310(int a1);
    void M_4ED360(int a1);
    void M_4ED630(int a1);
    void M_4EE2D0();
    void M_4EEC90();
    void M_4EEFC0();
    void M_4EF220();
    void M_4EF780();
    void M_4EFB00();
    void M_4EFCA0();
    void M_4EFD70(int mode);
    void M_4F22F0(T6251Ctl* ctl, int a2);
};
