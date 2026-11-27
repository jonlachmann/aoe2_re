// C_cluster_4A3BB0 — anonymous cluster class for 0x4A3BB0 (ui region).
// The body dispatches slot +0x20 (index 8), so the object carries a vtable at
// +0; data fields begin at +4. Only the offsets proven by the body are listed.
#pragma once

#include "Function.hpp"

class T460Obj {
public:
    virtual void slot_000(int a1);   // +0x00 release/close slot
};

class T4233E0_4233E0 {
public:
    virtual void slot_000();       // vtable 0x61E15C written by the ctor
    char pad_04[0x38 - 0x04];      // allocated size is 0x38

    // Ctor at 0x4233E0; _<addr> in the class name makes the ctor symbol
    // byte-comparable.
    T4233E0_4233E0(int a1, int a2, int a3, char* a4);
};

class C_cluster_4A3BB0 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008(int a1);   // slot +0x20

    char pad_04[0x20 - 0x04];
    int field_20;                  // +0x20 ctor argument
    char pad_24[0x78 - 0x24];
    int field_78;                  // +0x78 slot dispatch gate
    char pad_7c[0x210 - 0x7c];
    void* field_210;               // +0x210 format/source object gate
    char pad_214[0x460 - 0x214];
    void* field_460;               // +0x460 owned 0x38 object
    int field_464;                 // +0x464 count/id

    void M_4A3BB0(int a1);
};
