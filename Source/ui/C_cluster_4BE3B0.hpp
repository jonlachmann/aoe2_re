// C_cluster_4BE3B0 — linked list lookup anchored at 0x4BE3B0 (ui).
// The 0x73FACC global heads a node list; each node carries a key pair and a
// record whose +0x38 count and +0x40 entry table (stride 0x0C) are scanned to
// find an entry whose keys match the two int arguments.
#pragma once

#include "Function.hpp"

class T4BE3B0Node;

// Entry in a node's record at +0x40, 0x0C bytes each: key at +0x00, a relative
// offset into the record at +0x04 and a sub-entry count at +0x08.
class T4BE3B0Entry {
public:
    int field_0;                  // +0x00
    int field_4;                  // +0x04 offset from the record
    int field_8;                  // +0x08 sub-entry count
    T4BE3B0Entry* next_c;         // +0x0C
};

class T4BE3B0Record {
public:
    char pad_00[0x38];
    int field_38;                 // +0x38 entry count
    char pad_3c[4];
    T4BE3B0Entry* field_40;       // +0x40 entry table
};

class T4BE3B0Node {
public:
    int field_0;                  // +0x00 output key
    int field_4;                  // +0x04 output key
    T4BE3B0Record* field_8;       // +0x08 record
    T4BE3B0Node* next_c;          // +0x0C next node
};

int __cdecl sub_4BE3B0(int a1, int a2, int* a3, int* a4, int* a5, int* a6);
