// C_cluster_45F8A0 — gfx cluster anchored at 0x45F8A0.
// 0x45F8A0 gates on two +0x3C/+0x3D mode bytes and two object pointers, then
// dispatches slot +0x18 of the vtable stored at [field_24].
#pragma once

#include "Function.hpp"

typedef void (__stdcall *T45F8Slot18)(void* a1, int a2, int a3, int a4,
                                     void* a5);

class C_cluster_45F8A0 {
public:
    char pad_00[0x1c];            // +0x00..+0x1C
    void* field_1c;               // +0x1C guard pointer
    char pad_20[0x24 - 0x20];     // +0x20..+0x24
    void* field_24;               // +0x24 object with vtable at +0x00
    char pad_28[0x3c - 0x28];     // +0x28..+0x3C
    unsigned char field_3c;       // +0x3C mode byte
    unsigned char field_3d;       // +0x3D mode byte
    char pad_3e[0xb8 - 0x3e];     // +0x3E..+0xB8
    unsigned char slot_b8;        // +0xB8 subobject base passed to the callee

    void M_45F8A0();
};
